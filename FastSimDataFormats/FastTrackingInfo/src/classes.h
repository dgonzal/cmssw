#ifndef FASTSIMDATAFORMATS_FASTTRACKINGINFO_CLASSES_H
#define FASTSIMDATAFORMATS_FASTTRACKINGINFO_CLASSES_H

#include "FastSimDataFormats/FastTrackingInfo/interface/FastTrackerRecHitCombinationInfo.h"
#include "FastSimDataFormats/FastTrackingInfo/interface/FastTrajectorySeedInfo.h"

namespace FastSimDataFormats_FastTrackingInfo {
    struct dictionary {

	FastTrackerRecHitCombinationInfo fastTrackerRecHitCombinationInfo;
	FastTrackerRecHitCombinationInfoCollection fastTrackerRecHitCombinationInfoCollection;
	edm::Wrapper<FastTrackerRecHitCombinationInfoCollection> fastTrackerRecHitCombinationInfoCollectionWrapper;

	FastTrajectorySeedInfo fastTrajectorySeedInfo;
	FastTrajectorySeedInfoCollection fastTrajectorySeedInfoCollection;
	edm::Wrapper<FastTrajectorySeedInfoCollection> fastTrajectorySeedInfoCollectionWrapper;
	
    };
}

#endif
