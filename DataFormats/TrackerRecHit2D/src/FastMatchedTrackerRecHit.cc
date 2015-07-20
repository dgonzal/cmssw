#include "DataFormats/TrackerRecHit2D/interface/FastMatchedTrackerRecHit.h"

bool FastMatchedTrackerRecHit::sharesInput( const TrackingRecHit * other,
				     SharedInputType what) const
{
    if (what==all)
	return (this->monoHit().sharesInput(other,what) && this->stereoHit().sharesInput(other,what));
    else
	return (this->monoHit().sharesInput(other,what) || this->stereoHit().sharesInput(other,what));
}
