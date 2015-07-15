#ifndef FastProjectedTrackerRecHit_H
#define FastProjectedTrackerRecHit_H

#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/ProjectedSiStripRecHit2D.h"

class FastProjectedTrackerRecHit : public FastTrackerRecHit {

    public :
          
    FastProjectedTrackerRecHit() {};
    
    ~FastProjectedTrackerRecHit() {};
    
    FastProjectedTrackerRecHit( const LocalPoint& pos, 
				const LocalError& err, 
				GeomDet const & idet,
				FastTrackerRecHit const & originalHit) 
	: FastTrackerRecHit(pos, err, idet, 
			    ProjectedSiStripRecHit2D::isMono(idet,*originalHit.det()) 
			    ? fastTrackerRecHitType::siStripProjectedMono2D 
			    : fastTrackerRecHitType::siStripProjectedStereo2D )
	, originalHit_(originalHit)
    {}
    
    virtual bool sharesInput (const TrackingRecHit* other, SharedInputType what) const {return originalHit_.sharesInput(other,what);}
    const FastTrackerRecHit & originalHit() const {return originalHit_;}
    virtual FastTrackerRecHit * clone() const {FastProjectedTrackerRecHit * p =  new FastProjectedTrackerRecHit( * this); p->load(); return p;}

    private:

    FastTrackerRecHit originalHit_;

};

#endif
