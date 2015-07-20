#include "DataFormats/TrackerRecHit2D/interface/FastSingleTrackerRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/OmniClusterRef.h"

bool FastSingleTrackerRecHit::sharesInput( const TrackingRecHit* other, 
					   SharedInputType what) const
{
    if(!sameDetModule(*other)) return false;
    
    if(!trackerHitRTTI::isFast(*other) )
	return false;
    
    if(trackerHitRTTI::isSingle(*other))
	return sharesInput(static_cast<const FastSingleTrackerRecHit *>(other));
    else if (trackerHitRTTI::isMatched(*other) || trackerHitRTTI::isProjected(*other))
	return other->sharesInput(this,what);
    else
	return false;
}
