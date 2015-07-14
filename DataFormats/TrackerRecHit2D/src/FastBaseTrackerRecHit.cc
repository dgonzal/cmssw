#include "DataFormats/TrackerRecHit2D/interface/FastBaseTrackerRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/OmniClusterRef.h"

namespace {
    const OmniClusterRef nullRef;
}

OmniClusterRef const & FastBaseTrackerRecHit::firstClusterRef() const { return nullRef;}
