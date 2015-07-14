#ifndef FastSiPixelRecHit_H
#define FastSiPixelRecHit_H

#include "DataFormats/TrackerRecHit2D/interface/FastTrackerSingleRecHit.h"

class FastSiPixelRecHit : public FastTrackerSingleRecHit {
    
    public:
    
    FastSiPixelRecHit()  {};
    
    ~FastSiPixelRecHit() {};
    
    FastSiPixelRecHit( const LocalPoint & pos,
			 const LocalError & err,
			 const GeomDet & idet)
	: FastTrackerSingleRecHit(pos,err,idet,trackerHitRTTI::fastSingle)
	{};
    
    virtual FastSiPixelRecHit * clone() const {FastSiPixelRecHit * p = new FastSiPixelRecHit( * this); p->load(); return p;}

    virtual int dimension() const GCC11_OVERRIDE {return 2;}
    
    virtual void getKfComponents( KfComponentsHolder & holder ) const GCC11_OVERRIDE { getKfComponents2D(holder); }

    virtual bool isPixel() const {return true;}
    
};

#endif
