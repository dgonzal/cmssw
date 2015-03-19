import FWCore.ParameterSet.Config as cms

# the actual digi sequence
from Configuration.StandardSequences.Digi_cff import *

simMuonCSCDigis.InputCollection = 'MuonSimHitsMuonCSCHits'
simMuonDTDigis.InputCollection = 'MuonSimHitsMuonDTHits'
simMuonRPCDigis.InputCollection = 'MuonSimHitsMuonRPCHits'
calDigi.remove(castorDigiSequence)

# extend it with some digi2raw
from Configuration.StandardSequences.DigiToRaw_cff import ecalPacker,esDigiToRaw,hcalRawData,rawDataCollector
for _entry in [cms.InputTag("SiStripDigiToRaw"), cms.InputTag("castorRawData"),cms.InputTag("siPixelRawData")]:
    rawDataCollector.RawCollectionList.remove(_entry)

# extend it with some raw2digi
from Configuration.StandardSequences.RawToDigi_cff import ecalPreshowerDigis,ecalDigis,hcalDigis

calDigiToRawToDigi = cms.Sequence(ecalPacker+esDigiToRaw+hcalRawData+rawDataCollector+ecalPreshowerDigis+ecalDigis+hcalDigis)
doAllDigi.replace(calDigi,calDigi+calDigiToRawToDigi)

# aliases for muons, to emulate digi2raw raw2digi
muonDTDigis = cms.EDAlias(
    mix = cms.VPSet(
        cms.PSet(type = cms.string("DTLayerIdDTDigiMuonDigiCollection"))
        )
    )
muonRPCDigis = cms.EDAlias(
    mix = cms.VPSet(
        cms.PSet(type = cms.string("RPCDetIdRPCDigiMuonDigiCollection"))
        )
    )

muonCSCDigis = cms.EDAlias(
    mix = cms.VPSet(
        cms.PSet(
            type = cms.string("CSCDetIdCSCWireDigiMuonDigiCollection"),
            fromProductInstance = cms.string("MuonCSCWireDigisDM"),
            ),
        cms.PSet(
            type = cms.string("CSCDetIdCSCStripDigiMuonDigiCollection"),
            fromProductInstance = cms.string("MuonCSCStripDigisDM"),
            )
        )
    )

from FastSimulation.Tracking.GeneralTracksAlias_cfi import generalTracksAliasInfo
generalTracks = cms.EDAlias(**{generalTracksAliasInfo.key.value():generalTracksAliasInfo.value})

# TODO: understand whether this digi2raw+raw2digi is useful
