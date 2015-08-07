#ifndef FASTSIMDATAFORMATS_FASTTRACKINGINFO_FASTTRACKERRECHITCOMBINATIONINFO
#define FASTSIMDATAFORMATS_FASTTRACKINGINFO_FASTTRACKERRECHITCOMBINATIONINFO

#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "DataFormats/TrackerRecHit2D/interface/FastTrackerRecHitCollection.h"

class FastTrackerRecHitCombinationInfo{
    public:
    
    FastTrackerRecHitCombinationInfo(){;}

    ~FastTrackerRecHitCombinationInfo(){;}

    FastTrackerRecHitCombinationInfo(FastTrackerRecHitCombinationRef _recHitCombination,SimTrackRef _simTrack)
	: recHitCombination(_recHitCombination)
	, simTrack(_simTrack) {;}

    FastTrackerRecHitCombinationRef recHitCombination;
    
    SimTrackRef simTrack;
};

typedef std::vector<FastTrackerRecHitCombinationInfo> FastTrackerRecHitCombinationInfoCollection;

#endif
