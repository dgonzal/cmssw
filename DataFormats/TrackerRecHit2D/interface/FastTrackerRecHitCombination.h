#ifndef FastTrackerRecHitCollection_H
#define FastTrackerRecHitCollection_H

#include "DataFormats/TrackerRecHit2D/interface/FastBaseTrackerRecHit.h"
#include "vector"
#include "DataFormats/Common/interface/OwnVector.h"

typedef edm::OwnVector<FastBaseTrackerRecHit> FastTrackerRecHitCombination;
typedef std::vector<FastTrackerRecHitCombination> FastTrackerRecHitCombinations;

#endif
