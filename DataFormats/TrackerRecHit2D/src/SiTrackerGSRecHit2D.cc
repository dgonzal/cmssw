#include "DataFormats/TrackerRecHit2D/interface/SiTrackerGSRecHit2D.h"


SiTrackerGSRecHit2D::SiTrackerGSRecHit2D( const LocalPoint& pos, const LocalError& err,
					  GeomDet const & idet,
					  const int Id               ,
					  const int simtrackId1      ,
					  const int simtrackId2      ,
					  const uint32_t eeId        ,
					  const int pixelMultiplicityX = -1,
					  const int pixelMultiplicityY = -1 
					   ): 
  GSSiTrackerRecHit2DLocalPos(pos,err,idet) ,
  Id_(Id) ,
  simtrackId1_(simtrackId1) ,
  simtrackId2_(simtrackId2) ,
  eeId_(eeId) ,
  pixelMultiplicityAlpha_(pixelMultiplicityX), 
  pixelMultiplicityBeta_(pixelMultiplicityY){}

bool SiTrackerGSRecHit2D::sharesInput( const TrackingRecHit* other, 
					       SharedInputType what) const
{
  const SiTrackerGSRecHit2D * otherCasted = dynamic_cast<const SiTrackerGSRecHit2D*>(other);
  if(!otherCasted)
    return false;
  else
    return Id_ == otherCasted->Id_;
}
