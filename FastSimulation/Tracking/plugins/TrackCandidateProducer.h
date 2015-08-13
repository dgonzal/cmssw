#ifndef FastSimulation_Tracking_TrackCandidateProducer_h
#define FastSimulation_Tracking_TrackCandidateProducer_h

#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "DataFormats/TrackCandidate/interface/TrackCandidateCollection.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHitCollection.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "SimDataFormats/Vertex/interface/SimVertexContainer.h"

#include "TrackingTools/PatternTools/interface/Trajectory.h"
#include "TrackingTools/PatternTools/interface/TrajTrackAssociation.h"

#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"
#include "FastSimDataFormats/FastTrackingInfo/interface/FastTrajectorySeedInfo.h"
#include "FastSimulation/Tracking/interface/FastTrackerRecHitSplitter.h"

class TrackCandidateProducer : public edm::stream::EDProducer <>
{
 public:
  
  explicit TrackCandidateProducer(const edm::ParameterSet& conf);
  
  virtual ~TrackCandidateProducer(){;}
  
  virtual void produce(edm::Event& e, const edm::EventSetup& es) override;
  
 private:

  unsigned int minNumberOfCrossedLayers;
  unsigned int maxNumberOfCrossedLayers;

  bool rejectOverlaps;
  bool splitHits;
  bool hitMasks_exists;

  FastTrackerRecHitSplitter hitSplitter;
 
  // tokens & labels
  edm::EDGetTokenT<FastTrajectorySeedInfoCollection> fastSeedInfosToken;
  edm::EDGetTokenT<edm::SimVertexContainer> simVertexToken;
  edm::EDGetTokenT<std::vector<bool> > hitMasksToken;
  std::string propagatorLabel;
  
};

#endif
