import FWCore.ParameterSet.Config as cms

fastTrackerRecHitCombinations = cms.EDProducer(
    "FastTrackerRecHitCombiner",
    simHits = cms.InputTag("famosSimHits","TrackerHits"),
    simTracks = cms.InputTag("famosSimHits"),
    simHit2RecHitMap = cms.InputTag("siTrackerGaussianSmearingRecHits","simHit2RecHitMap")
    )
