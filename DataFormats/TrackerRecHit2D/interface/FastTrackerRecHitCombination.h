#ifndef FastTrackerRecHitCollection_H
#define FastTrackerRecHitCollection_H

#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHitFwd.h"
#include "vector"
#include "DataFormats/Common/interface/OwnVector.h"

typedef edm::OwnVector<FastTrackerRecHit> FastTrackerRecHitCombination;
typedef std::vector<FastTrackerRecHitCombination> FastTrackerRecHitCombinations;

typedef edm::OwnVector<FastSingleTrackerRecHit> FastSingleTrackerRecHitCombination;
typedef std::vector<FastSingleTrackerRecHitCombination> FastSingleTrackerRecHitCombinations;

#endif
