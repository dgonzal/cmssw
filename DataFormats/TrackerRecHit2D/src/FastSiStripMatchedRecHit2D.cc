#include "DataFormats/TrackerRecHit2D/interface/FastSiStripMatchedRecHit2D.h"
#include "DataFormats/TrackerRecHit2D/interface/FastProjectedSiStripRecHit2D.h"

bool FastSiStripMatchedRecHit2D::sharesInput( const TrackingRecHit * other,
					      SharedInputType what) const
{
    if (what==all && (geographicalId() != other->geographicalId())) return false;
 
    if (!sameDetModule(*other)) return false;

    if (what==all){
	const FastBaseTrackerRecHit * otherCast = static_cast<const FastBaseTrackerRecHit*>(other);
	return this->hasEqualOrigin(*otherCast);
    }

    if (trackerHitRTTI::isFastMatched(*other) ) {
	const FastSiStripMatchedRecHit2D * otherMatched = static_cast<const FastSiStripMatchedRecHit2D*>(other);
	return this->monoHit().hasEqualOrigin(otherMatched->monoHit()) || this->stereoHit().hasEqualOrigin(otherMatched->stereoHit());
    }

    if (trackerHitRTTI::isFastProjected(*other) ) {
	return this->sharesInput(&(static_cast<FastProjectedSiStripRecHit2D const &>(*other).originalHit()),what);
    }
    
    if (trackerHitRTTI::isFastSingle(*other) ) {
	const FastBaseTrackerRecHit * otherSingle = static_cast<const FastBaseTrackerRecHit*>(other);
	return this->monoHit().hasEqualOrigin(*otherSingle) || this->stereoHit().hasEqualOrigin(*otherSingle);
    }
    
    return false;
}


    
