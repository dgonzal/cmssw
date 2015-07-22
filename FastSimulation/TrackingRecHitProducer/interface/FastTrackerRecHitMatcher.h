#ifndef FastSimulation_TrackingRecHitProducer_FastTrackerRecHitMatcher_h
#define FastSimulation_TrackingRecHitProducer_FastTrackerRecHitMatcher_h

#include <utility>
#include "DataFormats/GeometryVector/interface/LocalVector.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "Geometry/TrackerGeometryBuilder/interface/GluedGeomDet.h"
#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHitFwd.h"
#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHitCombination.h"
#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"

class TrackerGeometry;

class FastTrackerRecHitMatcher {

    public:


    FastTrackerRecHitMatcher() {}
    ~FastTrackerRecHitMatcher() {}


    void match(  const FastSingleTrackerRecHitCombination & recHits, 
		 const edm::PSimHitContainer & simHits,
		 const TrackerGeometry & geometry,
		 FastTrackerRecHitCombination & matchedRecHits);

    private:
	       
    typedef std::pair<LocalPoint,LocalPoint>                   StripPosition; 

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
