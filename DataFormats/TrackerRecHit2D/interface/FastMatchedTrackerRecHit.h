#ifndef FastMatchedTrackerRecHit_H
#define FastMatchedTrackerRecHit_H

#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHit.h"

class FastMatchedTrackerRecHit : public FastTrackerRecHit{
    
    public:
    
    FastMatchedTrackerRecHit()
	: stereoHitFirst_(false)
	{}
    
    ~FastMatchedTrackerRecHit() {}
    
    FastMatchedTrackerRecHit( const LocalPoint & pos, 
			      const LocalError & err,
			      const GeomDet & idet,
			      const FastTrackerRecHit & rMono, 
			      const FastTrackerRecHit & rStereo,
			      bool stereoHitFirst = false) 
	: FastTrackerRecHit(pos,err,idet,fastTrackerRecHitType::siStripMatched2D)
	, stereoHitFirst_(stereoHitFirst)
	, componentMono_(rMono) 
	, componentStereo_(rStereo)
    {};

    virtual FastMatchedTrackerRecHit * clone() const {FastMatchedTrackerRecHit * p =  new FastMatchedTrackerRecHit( * this); p->load(); return p;}

    const FastTrackerRecHit &   monoHit()                const { return componentMono_;}
    const FastTrackerRecHit &   stereoHit()              const { return componentStereo_;}
    const FastTrackerRecHit &   firstHit()               const { return stereoHitFirst_ ? componentStereo_ : componentMono_;}
    const FastTrackerRecHit &   secondHit()              const { return stereoHitFirst_ ? componentMono_ : componentStereo_;}
    void setStereoLayerFirst(bool stereoHitFirst = true){stereoHitFirst_ = stereoHitFirst;}

    bool sharesInput(const TrackingRecHit* other, SharedInputType what) const;


    private:
  
    bool stereoHitFirst_;
    FastTrackerRecHit componentMono_;
    FastTrackerRecHit componentStereo_;
};

#endif
