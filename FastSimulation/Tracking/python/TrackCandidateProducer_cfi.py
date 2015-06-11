import FWCore.ParameterSet.Config as cms

trackCandidateProducer = cms.EDProducer(
    "TrackCandidateProducer",
    
    # the seed collection
    src = cms.InputTag("globalPixelSeeds"),
    
    # Reject overlapping hits?
    OverlapCleaning = cms.bool(False),
    
    # Split matched hits? 
    SplitHits = cms.bool(True),

    # the propagator
    Propagator = cms.string("PropagatorWithMaterial"),

    SimTracks = cms.InputTag('famosSimHits'),
    )


