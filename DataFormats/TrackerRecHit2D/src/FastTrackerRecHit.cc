#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/OmniClusterRef.h"

namespace {
    const OmniClusterRef nullRef;
}

OmniClusterRef const & FastTrackerRecHit::firstClusterRef() const { return nullRef;}

bool FastTrackerRecHit::sharesInput( const TrackingRecHit* other, 
				     SharedInputType what) const
{
    if(!trackerHitRTTI::isFast(*other) )
	return false;
    
    const FastTrackerRecHit * otherCast = static_cast<const FastTrackerRecHit *>(other);
    if(what==all)
	return(this->sameId(otherCast,0) && this->sameId(otherCast,1));
    else
	return this->sameId(otherCast,0) || (this->nIds() > 1 && this->sameId(otherCast,1));
}
