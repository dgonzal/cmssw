#include "FastSimulation/Tracking/plugins/TrackCandidateProducer.h"

#include <memory>

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/OwnVector.h"
#include "DataFormats/TrackerRecHit2D/interface/SiTrackerGSRecHit2D.h" 
#include "DataFormats/TrackerRecHit2D/interface/SiTrackerGSMatchedRecHit2D.h" 
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/TrackExtraFwd.h"

#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/Records/interface/TrackerTopologyRcd.h"

#include "FastSimulation/Tracking/interface/TrajectorySeedHitCandidate.h"

#include <vector>

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "MagneticField/Engine/interface/MagneticField.h"

#include "SimDataFormats/Track/interface/SimTrack.h"

#include "TrackingTools/TrajectoryState/interface/TrajectoryStateOnSurface.h"
#include "TrackingTools/TrajectoryState/interface/FreeTrajectoryState.h"
#include "TrackingTools/GeomPropagators/interface/Propagator.h"
#include "TrackingTools/Records/interface/TrackingComponentsRecord.h"
#include "TrackingTools/MaterialEffects/interface/PropagatorWithMaterial.h"
#include "TrackingTools/TrajectoryState/interface/TrajectoryStateTransform.h"

TrackCandidateProducer::TrackCandidateProducer(const edm::ParameterSet& conf) 
{  
    
  // products
  produces<TrackCandidateCollection>();
  
  // input tags
  edm::InputTag seedProducerLabel = conf.getParameter<edm::InputTag>("src");
  edm::InputTag simTkProducerLabel = conf.getParameter<edm::InputTag>("SimTracks");

  // Reject overlapping hits?
  rejectOverlaps = conf.getParameter<bool>("OverlapCleaning");

  // Split hits ?
  splitHits = conf.getParameter<bool>("SplitHits");

  // consumes
  seedCollectionToken = consumes<TrajectorySeedCollection>(seedProducerLabel);
  recHitCombinationsToken = consumes<FastTMatchedRecHit2DCombinations>(seedProducerLabel);
  simVtxCollectionToken = consumes<edm::SimVertexContainer>(simTkProducerLabel);
  simTkCollectionToken = consumes<edm::SimTrackContainer>(simTkProducerLabel);
}
  
 
void 
TrackCandidateProducer::beginRun(edm::Run const&, const edm::EventSetup & es) {
}

void 
TrackCandidateProducer::produce(edm::Event& e, const edm::EventSetup& es) {        

  //services
  edm::ESHandle<MagneticField>          magField;
  es.get<IdealMagneticFieldRecord>().get(magField);

  edm::ESHandle<TrackerGeometry>        geometry;
  es.get<TrackerDigiGeometryRecord>().get(geometry);

  edm::ESHandle<TrackerTopology> tTopo;
  es.get<IdealGeometryRecord>().get(tTopo);

  // TODO: get the propagator from the event setup
  thePropagator = std::make_shared<PropagatorWithMaterial>(alongMomentum,0.105,magField.product());
  
  // the source
  edm::Handle<TrajectorySeedCollection> theSeedCollection;
  e.getByToken(seedCollectionToken,theSeedCollection);
  edm::Handle<FastTMatchedRecHit2DCombinations> theRecHitCombinations;
  e.getByToken(recHitCombinationsToken, theRecHitCombinations);

  // SimTracks, SimVertices
  edm::Handle<edm::SimVertexContainer> theSimVtxCollection;
  e.getByToken(simVtxCollectionToken,theSimVtxCollection);
  edm::Handle<edm::SimTrackContainer> theSimTkCollection;
  e.getByToken(simTkCollectionToken,theSimTkCollection);

  // The produced objects
  std::auto_ptr<TrackCandidateCollection> output(new TrackCandidateCollection);    
      
  // Produce a trackcandidate for each given seed
  for (unsigned seednr = 0; seednr < theSeedCollection->size(); ++seednr){

    // a reference to the RecHitCombination from which the seed was produced
    const FastTMatchedRecHit2DCombination & theRecHitCombination = theRecHitCombinations->at(seednr);

    // get the list of hits from which to produce the TrackCandidate
    std::vector<TrajectorySeedHitCandidate> theTrackerRecHits;
    TrajectorySeedHitCandidate _recHit;
    for (const auto & recHit : theRecHitCombination){

      _recHit = TrajectorySeedHitCandidate(recHit.get(),geometry.product(),tTopo.product());
    
      if ( !rejectOverlaps ||                                                       // if we don't care about multiple hits on same layer
	   theTrackerRecHits.size() == 0 ||                                         //    or if there is no privious hit
	   _recHit.subDetId()    != theTrackerRecHits.back().subDetId() ||          //    or if the previous hit was not on the same layer
	   _recHit.layerNumber() != theTrackerRecHits.back().layerNumber() ) {  
	theTrackerRecHits.push_back(_recHit);                                       //    push back the hit
      }
      else if ( _recHit.localError() < theTrackerRecHits.back().localError() ) {    // else, if the previous hit was less precise, 
	theTrackerRecHits.back() = _recHit;                                         // 	  replace it with the current hit
      }
    }
    
    // convert TrajectorySeedHitCandidate to TrackingRecHit 
    edm::OwnVector<TrackingRecHit> recHits;
    unsigned nTrackerHits = theTrackerRecHits.size();
    recHits.reserve(nTrackerHits); 
    for ( const auto & _recHit : theTrackerRecHits ) {
      // unmatch hits if requested
      if(splitHits &&  _recHit.matchedHit()->isMatched()){
	// we assume the hits are matched in the correct order...
	recHits.push_back(_recHit.matchedHit()->monoHit()->clone());
	recHits.push_back(_recHit.matchedHit()->stereoHit()->clone());
      }
      else{
	recHits.push_back(_recHit.hit()->clone());
      }
    }
    
    // calculate initial parameters for the trajectory based on truth information
    const SimTrack & simTk = theSimTkCollection->at(theRecHitCombination[0].get()->simtrackId1());
    const SimVertex & simVtx = theSimVtxCollection->at(simTk.vertIndex());
    GlobalPoint position(simVtx.position().x(), simVtx.position().y(), simVtx.position().z());
    GlobalVector momentum( simTk.momentum().x(), simTk.momentum().y(), simTk.momentum().z());
    float        charge   = simTk.charge();
    GlobalTrajectoryParameters initialParams(position,momentum,(int)charge,magField.product());

    // set large initial errors
    AlgebraicSymMatrix55 errorMatrix= AlgebraicMatrixID();    
    CurvilinearTrajectoryError initialError(errorMatrix);

    // -> initial state
    FreeTrajectoryState initialFTS(initialParams, initialError);      

    // and fit
    const GeomDet* initialLayer = geometry->idToDet(recHits.front().geographicalId());  
    const TrajectoryStateOnSurface initialTSOS = thePropagator->propagate(initialFTS,initialLayer->surface()) ;
    if (!initialTSOS.isValid()) continue;       
    PTrajectoryStateOnDet PTSOD = trajectoryStateTransform::persistentState(initialTSOS,recHits.front().geographicalId().rawId()); 
    
    // add a new track candidate to the list
    output->push_back(TrackCandidate(recHits,theSeedCollection->at(seednr),PTSOD,edm::RefToBase<TrajectorySeed>(edm::Ref<TrajectorySeedCollection>(theSeedCollection,seednr))));
  }

  // Save the track candidates
  e.put(output);
}
