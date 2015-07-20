#ifndef FastSimulation_TrackingRecHitProducer_FastTrackerRecHitMatcher_h
#define FastSimulation_TrackingRecHitProducer_FastTrackerRecHitMatcher_h

#include <utility>
#include "DataFormats/GeometryVector/interface/LocalVector.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "Geometry/TrackerGeometryBuilder/interface/GluedGeomDet.h"
#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHitFwd.h"

//class GluedGeomDet;
//class GeomDet;
//class GeomDetUnit;

class FastTrackerRecHitMatcher {
    public:

    typedef std::pair<LocalPoint,LocalPoint>                   StripPosition; 

    FastTrackerRecHitMatcher() {}
    ~FastTrackerRecHitMatcher() {}

    FastMatchedTrackerRecHit match( const FastSingleTrackerRecHit *monoRH,
				    const FastSingleTrackerRecHit *stereoRH,
				    const GluedGeomDet* gluedDet,
				    LocalVector& trackdirection) const;
  
  
    StripPosition project(const GeomDetUnit *det,
			  const GluedGeomDet* glueddet,
			  const StripPosition& strip,
			  const LocalVector& trackdirection) const;
  
    FastProjectedTrackerRecHit projectOnly( const FastSingleTrackerRecHit *monoRH,
					  const GeomDet * monoDet,
					  const GluedGeomDet* gluedDet,
					  LocalVector& ldir) const;
  
};

#endif
