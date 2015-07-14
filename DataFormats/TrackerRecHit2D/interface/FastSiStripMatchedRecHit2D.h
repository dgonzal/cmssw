#ifndef FastSiStripMatchedRecHit2D_H
#define FastSiStripMatchedRecHit2D_H

#include "DataFormats/TrackerRecHit2D/interface/FastSiStripRecHit2D.h"

class FastSiStripMatchedRecHit2D : public FastBaseTrackerRecHit{
    
    public:
    
    FastSiStripMatchedRecHit2D()
	: stereoHitFirst_(false)
	{}
    
    ~FastSiStripMatchedRecHit2D() {}
    
    FastSiStripMatchedRecHit2D( const LocalPoint & pos, 
				const LocalError & err,
				const GeomDet & idet,
				const FastSiStripRecHit2D & rMono, 
				const FastSiStripRecHit2D & rStereo,
				bool stereoHitFirst = false) 
	: FastBaseTrackerRecHit(pos,err,idet,trackerHitRTTI::fastMatch)
	, stereoHitFirst_(stereoHitFirst)
	, componentMono_(rMono) 
	, componentStereo_(rStereo)
    {};

    virtual FastSiStripMatchedRecHit2D * clone() const {FastSiStripMatchedRecHit2D * p =  new FastSiStripMatchedRecHit2D( * this); p->load(); return p;}

    const FastSiStripRecHit2D &   monoHit()                const { return componentMono_;}
    const FastSiStripRecHit2D &   stereoHit()              const { return componentStereo_;}
    const FastSiStripRecHit2D &   firstHit()               const { return stereoHitFirst_ ? componentStereo_ : componentMono_;}
    const FastSiStripRecHit2D &   secondHit()              const { return stereoHitFirst_ ? componentMono_ : componentStereo_;}
    void setStereoLayerFirst(bool stereoHitFirst = true){stereoHitFirst_ = stereoHitFirst;}

    virtual int dimension() const {return 2;}
    virtual void getKfComponents( KfComponentsHolder & holder ) const { getKfComponents2D(holder); }

    bool sharesInput(const TrackingRecHit* other, SharedInputType what) const;


    private:
  
    bool stereoHitFirst_;
    FastSiStripRecHit2D componentMono_;
    FastSiStripRecHit2D componentStereo_;
};

#endif
