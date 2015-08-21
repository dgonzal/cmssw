import FWCore.ParameterSet.Config as cms

from Validation.RecoTrack.TrackValidation_cff import *

###must be commented in normal running
###multiTrackValidator.outputFile='validationPlots.root'

tracksValidationStandalone.remove(trackValidatorFromPVStandalone)
tracksValidationStandalone.remove(trackValidatorFromPVAllTPStandalone)
tracksValidationStandalone.remove(trackValidatorAllTPEfficStandalone)
