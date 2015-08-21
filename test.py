import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

process = cms.Process('VALIDATION',eras.fastsim)
process.load("Validation.RecoTrack.TrackValidation_cff")
