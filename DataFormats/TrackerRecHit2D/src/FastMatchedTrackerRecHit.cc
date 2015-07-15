#include "DataFormats/TrackerRecHit2D/interface/FastMatchedTrackerRecHit.h"

bool FastMatchedTrackerRecHit::sharesInput( const TrackingRecHit * other,
				     SharedInputType what) const
{
    if (what==all && (geographicalId() != other->geographicalId())) return false;
 
    if (!sameDetModule(*other)) return false;

    if (!trackerHitRTTI::isFast(*other)) return false;

    const FastTrackerRecHit * otherCast = static_cast<const FastTrackerRecHit*>(other);
    
    if (what==all){
	return this->hasEqualOrigin(*otherCast);
    }
    
    return (this->monoHit().sharesInput(otherCast,what) || this->stereoHit().sharesInput(otherCast,what));
}
