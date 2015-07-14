#ifndef FastProjectedSiStripRecHit2D_H
#define FastProjectedSiStripRecHit2D_H

#include "DataFormats/TrackerRecHit2D/interface/FastSiStripRecHit2D.h"
#include "DataFormats/TrackerRecHit2D/interface/ProjectedSiStripRecHit2D.h"

class FastProjectedSiStripRecHit2D : public FastTrackerSingleRecHit {

    public :
          
    FastProjectedSiStripRecHit2D() {};
    
    ~FastProjectedSiStripRecHit2D() {};
    
    FastProjectedSiStripRecHit2D( const LocalPoint& pos, 
				  const LocalError& err, 
				  GeomDet const & idet,
				  FastSiStripRecHit2D const & originalHit) 
	: FastTrackerSingleRecHit(pos, err, idet, 
				  ProjectedSiStripRecHit2D::isMono(idet,*originalHit.det()) ? trackerHitRTTI::fastProjMono: trackerHitRTTI::fastProjStereo)
	, originalHit_(originalHit)
    {}
    
    virtual int dimension() const {return 2;}
    virtual void getKfComponents( KfComponentsHolder & holder ) const { getKfComponents2D(holder); }
    virtual bool sharesInput (const TrackingRecHit* other, SharedInputType what) const {return originalHit_.sharesInput(other,what);}
    const FastSiStripRecHit2D & originalHit() const {return originalHit_;}
    virtual FastProjectedSiStripRecHit2D * clone() const {FastProjectedSiStripRecHit2D * p =  new FastProjectedSiStripRecHit2D( * this); p->load(); return p;}

    private:

    FastSiStripRecHit2D originalHit_;

};

#endif
