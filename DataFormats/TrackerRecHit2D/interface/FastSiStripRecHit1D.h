#ifndef FastSiStripRecHit1D_H
#define FastSiStripRecHit1D_H

#include "DataFormats/TrackerRecHit2D/interface/FastBaseTrackerRecHit.h"

class FastSiStripRecHit1D : public FastBaseTrackerRecHit {
  
    public:
    
    FastSiStripRecHit1D()  {}
    
    ~FastSiStripRecHit1D() {}
    
    FastSiStripRecHit1D( const LocalPoint & pos,
			 const LocalError & err,
			 const GeomDet & idet)
	: FastBaseTrackerRecHit (pos,err,idet,trackerHitRTTI::fastSingle)
	{}
    
    virtual FastSiStripRecHit1D * clone() const {FastSiStripRecHit1D * p = new FastSiStripRecHit1D( * this); p->load(); return p;}
    
    virtual int dimension() const GCC11_OVERRIDE {return 1;}

    virtual void getKfComponents( KfComponentsHolder & holder ) const GCC11_OVERRIDE {getKfComponents1D(holder);}

};

#endif
