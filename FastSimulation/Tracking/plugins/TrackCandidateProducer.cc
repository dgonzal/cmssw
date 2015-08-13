#include "FastSimulation/Tracking/plugins/TrackCandidateProducer.h"
#include <memory>

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/OwnVector.h"
#include "DataFormats/TrackCandidate/interface/TrackCandidateCollection.h"
#include "DataFormats/TrajectorySeed/interface/TrajectorySeedCollection.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/TrackExtraFwd.h"

#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/Records/interface/TrackerTopologyRcd.h"

#include "FastSimulation/Tracking/interface/TrajectorySeedHitCandidate.h"
#include "FastSimulation/Tracking/interface/HitMaskHelper.h"

#include "TrackingTools/TrajectoryState/interface/TrajectoryStateTransform.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "MagneticField/Engine/interface/MagneticField.h"

#include "SimDataFormats/Track/interface/SimTrack.h"
#include "TrackingTools/TrajectoryState/interface/TrajectoryStateOnSurface.h"
#include "TrackingTools/TrajectoryState/interface/FreeTrajectoryState.h"
#include "TrackingTools/GeomPropagators/interface/Propagator.h"
#include "TrackingTools/Records/interface/TrackingComponentsRecord.h"

//Propagator withMaterial
#include "TrackingTools/MaterialEffects/interface/PropagatorWithMaterial.h"

TrackCandidateProducer::TrackCandidateProducer(const edm::ParameterSet& conf) :
    hitSplitter()
{  
  // products
  produces<TrackCandidateCollection>();
  
  // general parameters
  minNumberOfCrossedLayers = conf.getParameter<unsigned int>("MinNumberOfCrossedLayers");
  rejectOverlaps = conf.getParameter<bool>("OverlapCleaning");
  splitHits = conf.getParameter<bool>("SplitHits");

  // input tags, labels, tokens
  hitMasks_exists = conf.exists("hitMasks");
  if (hitMasks_exists){
    hitMasksToken = consumes<std::vector<bool> >(conf.getParameter<edm::InputTag>("hitMasks"));
  }

  simVertexToken = consumes<edm::SimVertexContainer>(conf.getParameter<edm::InputTag>("simTracks"));

  fastSeedInfosToken = consumes<FastTrajectorySeedInfoCollection>(conf.getParameter<edm::InputTag>("src"));
  
  propagatorLabel = conf.getParameter<std::string>("propagator");
}
  
void 
TrackCandidateProducer::produce(edm::Event& e, const edm::EventSetup& es) {        

  // get services
  edm::ESHandle<MagneticField>          magneticField;
  es.get<IdealMagneticFieldRecord>().get(magneticField);

  edm::ESHandle<TrackerGeometry>        trackerGeometry;
  es.get<TrackerDigiGeometryRecord>().get(trackerGeometry);

  edm::ESHandle<TrackerTopology>        trackerTopology;
  es.get<TrackerTopologyRcd>().get(trackerTopology);

  edm::ESHandle<Propagator>             propagator;
  es.get<TrackingComponentsRecord>().get(propagatorLabel,propagator);
    
  // get products
  edm::Handle<FastTrajectorySeedInfoCollection> fastSeedInfos;
  e.getByToken(fastSeedInfosToken,fastSeedInfos);

  edm::Handle<edm::SimVertexContainer> simVertices;
  e.getByToken(simVertexToken,simVertices);

  std::unique_ptr<HitMaskHelper> hitMaskHelper;
  if (hitMasks_exists == true){
      edm::Handle<std::vector<bool> > hitMasks;
      e.getByToken(hitMasksToken,hitMasks);
      hitMaskHelper.reset(new HitMaskHelper(hitMasks.product()));
  }
  
  // output collection
  std::auto_ptr<TrackCandidateCollection> output(new TrackCandidateCollection);    

  // loop over the seeds
  for (const auto & fastSeedInfo : *fastSeedInfos){
    
    // the seed
    const auto & seed = *fastSeedInfo.trajectorySeed;

    // select hits, store as TrajectorySeedHitCandidates
    std::vector<TrajectorySeedHitCandidate> recHitCandidates;
    TrajectorySeedHitCandidate recHitCandidate;
    unsigned numberOfCrossedLayers = 0;      
    for (const auto & _hit : *fastSeedInfo.recHitCombination) {

	// apply hit maksing
	if(hitMaskHelper){
	    if(hitMaskHelper->mask(_hit.get()))
		continue;
	}

	// create hit candidate
	recHitCandidate = TrajectorySeedHitCandidate(_hit.get(),trackerGeometry.product(),trackerTopology.product());

	// count number of crossed layers
      if ( recHitCandidates.size() == 0 || !recHitCandidate.isOnTheSameLayer(recHitCandidates.back()) ) {
	++numberOfCrossedLayers;
      }

      // hit selection
      //         - always select first hit
      if(        recHitCandidates.size() == 0 ) {
	  recHitCandidates.push_back(recHitCandidate);
      }
      //         - in case of *no* verlap rejection: select all hits
      else if(   !rejectOverlaps) {
	  recHitCandidates.push_back(recHitCandidate);
      }
      //         - in case of overlap rejection: 
      //              - select hit if it is not on same layer as previous hit
      else if(   recHitCandidate.subDetId()    != recHitCandidates.back().subDetId() ||
	         recHitCandidate.layerNumber() != recHitCandidates.back().layerNumber() ) {
	  recHitCandidates.push_back(recHitCandidate);
      }
      //         - in case of overlap rejection and hit is on same layer as previous hit 
      //              - replace previous hit with current hit if it has better precision
      else if (  recHitCandidate.localError() < recHitCandidates.back().localError() ){
	  recHitCandidates.back() = recHitCandidate;
      }
    }

    // TODO: verify it makes sense to have this selection
    if ( numberOfCrossedLayers < minNumberOfCrossedLayers ) {
      continue;
    }

    // Convert TrajectorySeedHitCandidate to TrackingRecHit and split hits
    edm::OwnVector<TrackingRecHit> trackRecHits;
    for ( unsigned index = 0; index<recHitCandidates.size(); ++index ) {
	if(splitHits)
	    hitSplitter.split(*recHitCandidates[index].hit(),trackRecHits);
	else
	    trackRecHits.push_back(recHitCandidates[index].hit()->clone());
    }

    // reverse order if needed
    if (seed.direction()==oppositeToMomentum){
      std::reverse(recHitCandidates.begin(),recHitCandidates.end());
    }
    
    // trajectory state at simvertex
    const auto & simTrack = fastSeedInfo.simTrack;
    int vertexIndex = simTrack->vertIndex();
    GlobalPoint  position(simVertices->at(vertexIndex).position().x(),
			  simVertices->at(vertexIndex).position().y(),
			  simVertices->at(vertexIndex).position().z());
    GlobalVector momentum( simTrack->momentum().x() , 
			   simTrack->momentum().y() , 
			   simTrack->momentum().z() );
    float        charge   = simTrack->charge();
    GlobalTrajectoryParameters initialParams(position,momentum,(int)charge,magneticField.product());
    AlgebraicSymMatrix55 errorMatrix= AlgebraicMatrixID();    
    CurvilinearTrajectoryError initialError(errorMatrix);
    FreeTrajectoryState initialFTS(initialParams, initialError);      

    // trajectory state at first hit
    const GeomDet* initialLayer = trackerGeometry->idToDet(trackRecHits.front().geographicalId());
    const TrajectoryStateOnSurface initialTSOS = propagator->propagate(initialFTS,initialLayer->surface()) ;
    if (!initialTSOS.isValid()) continue; 
    PTrajectoryStateOnDet PTSOD = trajectoryStateTransform::persistentState(initialTSOS,trackRecHits.front().geographicalId().rawId()); 

    // the track candidate
    output->push_back(TrackCandidate(trackRecHits,seed,PTSOD,edm::RefToBase<TrajectorySeed>(fastSeedInfo.trajectorySeed)));

  }
  
  e.put(output);
}
