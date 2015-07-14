#include "DataFormats/TrackerRecHit2D/interface/FastTrackerSingleRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/FastProjectedSiStripRecHit2D.h"
#include "DataFormats/TrackerRecHit2D/interface/FastSiStripMatchedRecHit2D.h"

bool FastTrackerSingleRecHit::sharesInput( const TrackingRecHit* other, 
					   SharedInputType what) const
{
    if(!sameDetModule(*other)) return false;

    if (trackerHitRTTI::isFastProjected(*other) ) {
	return sharesInput(&static_cast<FastProjectedSiStripRecHit2D const &>(*other).originalHit(),what);
    }

    if(trackerHitRTTI::isFastSingleType(*other)){
	const FastTrackerSingleRecHit & otherCast = static_cast<const FastTrackerSingleRecHit&>(*other);
	return hasEqualOrigin(otherCast);
    } 
    
    if (trackerHitRTTI::isFastMatched(*other) ) {
	return static_cast<FastSiStripMatchedRecHit2D const &>(*other).sharesInput(this,what);
    }

    return false;
}
