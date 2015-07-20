#ifndef FastProjectedTrackerRecHit_H
#define FastProjectedTrackerRecHit_H

#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/FastSingleTrackerRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/ProjectedSiStripRecHit2D.h"

class FastProjectedTrackerRecHit : public FastTrackerRecHit {

    public :
          
    FastProjectedTrackerRecHit() {};
    
    ~FastProjectedTrackerRecHit() {};
    
    FastProjectedTrackerRecHit( const LocalPoint& pos, 
				const LocalError& err, 
				GeomDet const & idet,
				FastSingleTrackerRecHit const & originalHit) 
	: FastTrackerRecHit(pos, err, idet, 
			    ProjectedSiStripRecHit2D::isMono(idet,*originalHit.det()) 
			    ? fastTrackerRecHitType::siStripProjectedMono2D 
			    : fastTrackerRecHitType::siStripProjectedStereo2D )
	, originalHit_(originalHit)
    {}
    
    bool sharesInput (const TrackingRecHit* other, SharedInputType what) const {return originalHit_.sharesInput(other,what);}
    const FastTrackerRecHit & originalHit() const {return originalHit_;}
    virtual FastProjectedTrackerRecHit * clone() const {FastProjectedTrackerRecHit * p =  new FastProjectedTrackerRecHit( * this); p->load(); return p;}
    size_t                       nIds()                    const { return 1;}
    int32_t                      id(size_t i = 0)          const { return originalHit().id(i);}
    size_t                       nSimTrackIds()            const { return originalHit_.nSimTrackIds();}                             ///< see addSimTrackId(int32_t simTrackId)
    int32_t                      simTrackId(size_t i)      const { return originalHit_.simTrackId(i);}                              ///< see addSimTrackId(int32_t simTrackId)
    int32_t                      simTrackEventId(size_t i) const { return originalHit_.simTrackEventId(i);;}                        ///< see addSimTrackId(int32_t simTrackId)
    
    private:

    FastSingleTrackerRecHit originalHit_;
    
};

#endif
