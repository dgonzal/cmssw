#ifndef FastSiStripRecHit2D_H
#define FastSiStripRecHit2D_H

#include "DataFormats/TrackerRecHit2D/interface/FastTrackerSingleRecHit.h"

class FastSiStripRecHit2D : public FastTrackerSingleRecHit {
    
    public:
    
    FastSiStripRecHit2D()  {};
    
    ~FastSiStripRecHit2D() {};
    
    FastSiStripRecHit2D( const LocalPoint & pos,
			 const LocalError & err,
			 const GeomDet & idet)
	: FastTrackerSingleRecHit(pos,err,idet,trackerHitRTTI::fastSingle)
	{};
    
    virtual FastSiStripRecHit2D * clone() const {FastSiStripRecHit2D * p = new FastSiStripRecHit2D( * this); p->load(); return p;}

    virtual int dimension() const GCC11_OVERRIDE {return 2;}
    
    virtual void getKfComponents( KfComponentsHolder & holder ) const GCC11_OVERRIDE { getKfComponents2D(holder); }
    
};

#endif
