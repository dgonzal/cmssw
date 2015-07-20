#ifndef FastMatchedTrackerRecHit_H
#define FastMatchedTrackerRecHit_H

#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/FastSingleTrackerRecHit.h"

class FastMatchedTrackerRecHit : public FastTrackerRecHit{
    
    public:
    
    FastMatchedTrackerRecHit()
	: stereoHitFirst_(false)
	{}
    
    ~FastMatchedTrackerRecHit() {}
    
    FastMatchedTrackerRecHit( const LocalPoint & pos, 
			      const LocalError & err,
			      const GeomDet & idet,
			      const FastSingleTrackerRecHit & rMono, 
			      const FastSingleTrackerRecHit & rStereo,
			      bool stereoHitFirst = false) 
	: FastTrackerRecHit(pos,err,idet,fastTrackerRecHitType::siStripMatched2D)
	, stereoHitFirst_(stereoHitFirst)
	, componentMono_(rMono) 
	, componentStereo_(rStereo)
    {};

    virtual FastMatchedTrackerRecHit * clone() const {FastMatchedTrackerRecHit * p =  new FastMatchedTrackerRecHit( * this); p->load(); return p;}


    void setHitCombinationId(int32_t hitCombinationId) {
	FastTrackerRecHit::setHitCombinationId(hitCombinationId);
	componentMono_.setHitCombinationId(hitCombinationId);
	componentStereo_.setHitCombinationId(hitCombinationId);
    }

    size_t                       nIds()                    const { return 2;}
    int32_t                      id(size_t i = 0)          const { return i==0 ? monoHit().id() : stereoHit().id(); }
    
    size_t                       nSimTrackIds()            const { return componentMono_.nSimTrackIds() + componentStereo_.nSimTrackIds();}                             ///< see addSimTrackId(int32_t simTrackId)
    int32_t                      simTrackId(size_t i)      const { 
	if(i < componentMono_.nSimTrackIds()) 
	    return componentMono_.simTrackId(i);
	i-=componentMono_.nSimTrackIds();
	return componentStereo_.simTrackId(i);
    }
    int32_t                      simTrackEventId(size_t i) const { 
	if(i < componentMono_.nSimTrackIds()) 
	    return componentMono_.simTrackEventId(i);
	i-=componentMono_.nSimTrackIds();
	return componentStereo_.simTrackEventId(i);
    }
    
    const FastTrackerRecHit &   monoHit()                const { return componentMono_;}
    const FastTrackerRecHit &   stereoHit()              const { return componentStereo_;}
    const FastTrackerRecHit &   firstHit()               const { return stereoHitFirst_ ? componentStereo_ : componentMono_;}
    const FastTrackerRecHit &   secondHit()              const { return stereoHitFirst_ ? componentMono_ : componentStereo_;}
    

    void setStereoLayerFirst(bool stereoHitFirst = true){stereoHitFirst_ = stereoHitFirst;}
    void setEventId(int32_t eventId){componentMono_.setEventId(eventId);componentStereo_.setEventId(eventId);}

    bool sharesInput(const TrackingRecHit* other, SharedInputType what) const;


    private:
  
    bool stereoHitFirst_;
    FastSingleTrackerRecHit componentMono_;
    FastSingleTrackerRecHit componentStereo_;
};

#endif
