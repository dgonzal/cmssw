#ifndef FASTSIMDATAFORMATS_FASTTRACKINGINFO_FASTTRAJECTORYSEEDINFO
#define FASTSIMDATAFORMATS_FASTTRACKINGINFO_FASTTRAJECTORYSEEDINFO

#include "DataFormats/TrajectorySeed/interface/TrajectorySeedCollection.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHitCollection.h"

typedef edm::Ref<TrajectorySeedCollection> TrajectorySeedRef;

class FastTrajectorySeedInfo{
    public:
    
    FastTrajectorySeedInfo(){;}

    ~FastTrajectorySeedInfo(){;}

    FastTrajectorySeedInfo(TrajectorySeedRef _trajectorySeed,FastTrackerRecHitCombinationRef _recHitCombination,SimTrackRef _simTrack)
	: trajectorySeed(_trajectorySeed)
	, recHitCombination(_recHitCombination)
	, simTrack(_simTrack) {;}

    TrajectorySeedRef trajectorySeed;

    FastTrackerRecHitCombinationRef recHitCombination;
    
    SimTrackRef simTrack;
};

typedef std::vector<FastTrajectorySeedInfo> FastTrajectorySeedInfoCollection;

#endif
