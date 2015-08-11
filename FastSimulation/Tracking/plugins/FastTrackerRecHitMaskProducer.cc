// system includes                                                                                                                                
#include <memory>

// framework stuff
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"

// data formats
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHitCollection.h"

class FastTrackerRecHitMaskProducer : public edm::stream::EDProducer <>
{
    public:

    explicit FastTrackerRecHitMaskProducer(const edm::ParameterSet& conf);

    virtual ~FastTrackerRecHitMaskProducer() {}

    virtual void produce(edm::Event& e, const edm::EventSetup& es) override;


    private:

    // tokens
    edm::EDGetTokenT<reco::TrackCollection>  tracksToken_;
    edm::EDGetTokenT<FastTrackerRecHitCollection>  recHitsToken_;
    edm::EDGetTokenT<std::vector<bool> > oldHitMasksToken_;
    edm::EDGetTokenT<edm::ValueMap<int> > trkQualsToken_;

    // other data members
    bool oldHitMasks_exists_;
    bool overRideTrkQuals_;
    bool filterTracks_;
    reco::TrackBase::TrackQuality trackQuality_;

};

FastTrackerRecHitMaskProducer::FastTrackerRecHitMaskProducer(const edm::ParameterSet& conf) 
{
    // products                                                                                                     
    produces<std::vector<bool> >();

    // flags
    oldHitMasks_exists_ = conf.exists("oldHitMasks");
    overRideTrkQuals_ = conf.exists("overrideTrkQuals");
    filterTracks_ = conf.exists("TrackQuality");
    
    // consumes                                                                                                                   
    tracksToken_ = consumes<reco::TrackCollection>(conf.getParameter<edm::InputTag>("trackCollection"));
    recHitsToken_ = consumes<FastTrackerRecHitCollection>(conf.getParameter<edm::InputTag>("recHits"));
    if (oldHitMasks_exists_){
	oldHitMasksToken_ = consumes<std::vector<bool> >(conf.getParameter<edm::InputTag>("oldHitMasks"));
    }

    // track quality token
    if(  overRideTrkQuals_ ){
	edm::InputTag trkQualsTag = conf.getParameter<edm::InputTag>("overrideTrkQuals");
	if(trkQualsTag == edm::InputTag(""))
	    overRideTrkQuals_ = false;
	else
	    trkQualsToken_ = consumes<edm::ValueMap<int> >(trkQualsTag);
    }

    // required track quality
    trackQuality_=reco::TrackBase::undefQuality;
    if (filterTracks_){
	std::string trackQualityStr = conf.getParameter<std::string>("TrackQuality");
	if ( !trackQualityStr.empty() ) {
	    trackQuality_=reco::TrackBase::qualityByName(trackQualityStr);
	}
	else { 
	    filterTracks_ = false;
	}
    }
}

void FastTrackerRecHitMaskProducer::produce(edm::Event& e, const edm::EventSetup& es)
{
    // input
    edm::Handle<reco::TrackCollection> tracks;
    e.getByToken(tracksToken_,tracks);

    edm::Handle<FastTrackerRecHitCollection> recHits;
    e.getByToken(recHitsToken_,recHits);

    edm::Handle<edm::ValueMap<int> > quals;
    if ( overRideTrkQuals_ ) {
	e.getByToken(trkQualsToken_,quals);
    }

    edm::Handle<std::vector<bool> > oldHitMasks;
    if (oldHitMasks_exists_ == true){
	e.getByToken(oldHitMasksToken_,oldHitMasks);
    }
    
    // the product
    std::unique_ptr<std::vector<bool> > hitMasks(new std::vector<bool>());

    // use the old hit masks as a starting point
    if(oldHitMasks_exists_){
	hitMasks->insert(hitMasks->begin(),oldHitMasks->begin(),oldHitMasks->end());
    }
    
    // increase the size of the hit mask vector to the size of the recHits vector
    if(recHits->size() > hitMasks->size()){
	hitMasks->resize(recHits->size(),false);
    }

    // loop over tracks and mask hits of selected tracks
    for (size_t i = 0 ; i!=tracks->size();++i) {

	// get the track
	const reco::Track & track = (*tracks)[i];

	// filter if requested
	if (filterTracks_) {
	    reco::TrackRef trackRef(tracks,i);
	    bool goodTk = true;
	    
	    if ( overRideTrkQuals_ ) {
		int qual= (*quals)[trackRef];
		if ( qual < 0 ){
		    goodTk=false;
		}
		else
		    goodTk = ( qual & (1<<trackQuality_))>>trackQuality_;
	    }
	    else {
		goodTk=(track.quality(trackQuality_));
	    }
	    if ( !goodTk) continue;
	}
      
      
	// Loop over the recHits
	// todo: implement the minimum number of measurements criterium
	// see http://cmslxr.fnal.gov/lxr/source/RecoLocalTracker/SubCollectionProducers/src/TrackClusterRemover.cc#0166
	for (auto hitIt = track.recHitsBegin() ;  hitIt != track.recHitsEnd(); ++hitIt) {

	    if(!(*hitIt)->isValid())
		continue;

	    // check whether hit is FastSim hit
	    if(!(trackerHitRTTI::isFast(**hitIt)))
		continue;
	    
	    const FastTrackerRecHit & hit = static_cast<const FastTrackerRecHit &>(*(*hitIt));
	    
	    for(unsigned id_index = 0;id_index < hit.nIds();id_index++){
		(*hitMasks)[unsigned(hit.id(id_index))] = true;
	    }
	}
	
    }
    
    e.put(std::move(hitMasks));

}

DEFINE_FWK_MODULE(FastTrackerRecHitMaskProducer);
