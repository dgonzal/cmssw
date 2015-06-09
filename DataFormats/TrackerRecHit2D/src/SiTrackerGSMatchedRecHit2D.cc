#include "DataFormats/TrackerRecHit2D/interface/SiTrackerGSMatchedRecHit2D.h"

SiTrackerGSMatchedRecHit2D::SiTrackerGSMatchedRecHit2D( const LocalPoint& pos, const LocalError& err,
							GeomDet const & idet,
							const int Id,
							const int simtrackId1,
							const int simtrackId2,
							const uint32_t eeId,
							const int pixelMultiplicityX = -1,
							const int pixelMultiplicityY = -1, 
							const bool isMatched = false,
							const SiTrackerGSRecHit2D* rMono = 0 , 
							const SiTrackerGSRecHit2D* rStereo= 0 ):
  GSSiTrackerRecHit2DLocalPos(pos,err,idet) ,
  Id_(Id),
  simtrackId1_(simtrackId1) ,
  simtrackId2_(simtrackId2) ,
  eeId_(eeId) ,
  pixelMultiplicityAlpha_(pixelMultiplicityX), 
  pixelMultiplicityBeta_(pixelMultiplicityY), 
  isMatched_(isMatched), 
  componentMono_(*rMono), 
  componentStereo_(*rStereo)
{}

SiTrackerGSMatchedRecHit2D::SiTrackerGSMatchedRecHit2D( const LocalPoint& pos, const LocalError& err,
							GeomDet const & idet,
							const int Id,
							const int simtrackId1,
							const int simtrackId2,
							const uint32_t eeId,
							const int pixelMultiplicityX = -1,
							const int pixelMultiplicityY = -1):
  GSSiTrackerRecHit2DLocalPos(pos,err,idet) ,
  Id_(Id),
  simtrackId1_(simtrackId1) , 
  simtrackId2_(simtrackId2) ,
  eeId_(eeId) ,
  pixelMultiplicityAlpha_(pixelMultiplicityX), 
  pixelMultiplicityBeta_(pixelMultiplicityY), 
  isMatched_(0), 
  componentMono_(), 
  componentStereo_()
{}



bool SiTrackerGSMatchedRecHit2D::sharesInput( const TrackingRecHit* other, 
					      SharedInputType what) const
 {
   const SiTrackerGSMatchedRecHit2D * otherCasted = dynamic_cast<const SiTrackerGSMatchedRecHit2D*>(other);
   if(!otherCasted)
     return false;
   else
     return Id_ == otherCasted->Id_ && eeId_ == otherCasted->eeId_;
 }
 
