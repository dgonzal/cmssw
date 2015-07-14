#ifndef FastTrackerSingleRecHit_H
#define FastTrackerSingleRecHit_H

#include "DataFormats/TrackerRecHit2D/interface/FastBaseTrackerRecHit.h"

class FastTrackerSingleRecHit : public FastBaseTrackerRecHit { 

    public:
    
    FastTrackerSingleRecHit(){};
    
    FastTrackerSingleRecHit(const LocalPoint& p, const LocalError& e,
			    GeomDet const & idet,trackerHitRTTI::RTTI rt = trackerHitRTTI::fastSingle)
	: FastBaseTrackerRecHit(p,e,idet,rt)
	{};
    
    bool sharesInput(const TrackingRecHit* other, SharedInputType what) const;
};
    
#endif
