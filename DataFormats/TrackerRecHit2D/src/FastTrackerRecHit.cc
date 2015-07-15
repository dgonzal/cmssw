#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/OmniClusterRef.h"

namespace {
    const OmniClusterRef nullRef;
}

OmniClusterRef const & FastTrackerRecHit::firstClusterRef() const { return nullRef;}

bool FastTrackerRecHit::sharesInput( const TrackingRecHit* other, 
				     SharedInputType what) const
{
    if(!sameDetModule(*other)) return false;
    
    if(!trackerHitRTTI::isFast(*other) )
	return false;

    const FastTrackerRecHit * otherCast = static_cast<const FastTrackerRecHit *>(other);
    if (trackerHitRTTI::isFastMatched(*other) || trackerHitRTTI::isFastProjected(*other)){
	return other->sharesInput(this,what);
    }
    
    return hasEqualOrigin(*otherCast);
}
