#ifndef FastTrackerRecHitCollection_H
#define FastTrackerRecHitCollection_H

#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHit.h"
#include "vector"
#include "DataFormats/Common/interface/OwnVector.h"

typedef edm::OwnVector<FastTrackerRecHit> FastTrackerRecHitCombination;
typedef std::vector<FastTrackerRecHitCombination> FastTrackerRecHitCombinations;

#endif
