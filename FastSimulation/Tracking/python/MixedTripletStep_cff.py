import FWCore.ParameterSet.Config as cms

# import the full tracking equivalent of this file
import RecoTracker.IterativeTracking.MixedTripletStep_cff

# fast tracking mask producer
import FastSimulation.Tracking.FastTrackerRecHitMaskProducer_cfi
mixedTripletStepMasks = FastSimulation.Tracking.FastTrackerRecHitMaskProducer_cfi.maskProducerFromClusterRemover(RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepClusters)
mixedTripletStepMasks.oldHitRemovalInfo = cms.InputTag("pixelPairStepMasks")

# trajectory seeds
import FastSimulation.Tracking.TrajectorySeedProducer_cfi
mixedTripletStepSeedsA = FastSimulation.Tracking.TrajectorySeedProducer_cfi.trajectorySeedProducer.clone(
    simTrackSelection = FastSimulation.Tracking.TrajectorySeedProducer_cfi.trajectorySeedProducer.simTrackSelection.clone(
        pTMin = 0.15,
        maxD0 = 10.0,
        maxZ0 = 30
        ),
    minLayersCrossed = 3,
    hitMasks = cms.InputTag("mixedTripletStepMasks"),
    ptMin =  RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepSeedsA.RegionFactoryPSet.RegionPSet.ptMin,
    originRadius = RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepSeedsA.RegionFactoryPSet.RegionPSet.originRadius,
    originHalfLength = RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepSeedsA.RegionFactoryPSet.RegionPSet.originHalfLength,
    layerList = RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepSeedLayersA.layerList.value()
)

###
import FastSimulation.Tracking.TrajectorySeedProducer_cfi
mixedTripletStepSeedsB = FastSimulation.Tracking.TrajectorySeedProducer_cfi.trajectorySeedProducer.clone(
    simTrackSelection = FastSimulation.Tracking.TrajectorySeedProducer_cfi.trajectorySeedProducer.simTrackSelection.clone(
        pTMin = 0.15,
        maxD0 = 10.0,
        maxZ0 = 30
        ),
    minLayersCrossed = 3,
    hitMasks = cms.InputTag("mixedTripletStepMasks"),
    ptMin =  RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepSeedsB.RegionFactoryPSet.RegionPSet.ptMin,
    originRadius = RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepSeedsB.RegionFactoryPSet.RegionPSet.originRadius,
    originHalfLength = RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepSeedsB.RegionFactoryPSet.RegionPSet.originHalfLength,
    layerList = RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepSeedLayersB.layerList.value()
)

mixedTripletStepSeeds = cms.EDProducer(
    "FastSeedCombiner",
    seedCollections = RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepSeeds.seedCollections
)

#track candidates
import FastSimulation.Tracking.TrackCandidateProducer_cfi
mixedTripletStepTrackCandidates = FastSimulation.Tracking.TrackCandidateProducer_cfi.trackCandidateProducer.clone(
    src = cms.InputTag("mixedTripletStepSeeds"),
    MinNumberOfCrossedLayers = 3,
    hitMasks = cms.InputTag("mixedTripletStepMasks"),
)

# tracks
mixedTripletStepTracks = RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepTracks.clone(
    TTRHBuilder = 'WithoutRefit',
    Fitter = 'KFFittingSmootherThird',
    Propagator = 'PropagatorWithMaterial'
)

# final selection
mixedTripletStepClassifier1 = RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepClassifier1.clone()
mixedTripletStepClassifier1.vertices = "firstStepPrimaryVerticesBeforeMixing"
mixedTripletStepClassifier2 = RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStepClassifier2.clone()
mixedTripletStepClassifier2.vertices = "firstStepPrimaryVerticesBeforeMixing"

mixedTripletStep = RecoTracker.IterativeTracking.MixedTripletStep_cff.mixedTripletStep.clone()

# Final sequence 
MixedTripletStep =  cms.Sequence(mixedTripletStepMasks
                                 +mixedTripletStepSeedsA
                                 +mixedTripletStepSeedsB
                                 +mixedTripletStepSeeds
                                 +mixedTripletStepTrackCandidates
                                 +mixedTripletStepTracks
                                 +mixedTripletStepClassifier1*mixedTripletStepClassifier2
                                 +mixedTripletStep                                 
                             )
