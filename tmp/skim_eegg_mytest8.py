import os
import sys
import basf2 as b2
import modularAnalysis as ma
import variables.collections as vc
import variables.utils as vu
import vertex as vx
from variables import variables as va
import b2biiConversion as b2bii
import flavorTagger as ft

# LoadParticle Library
from stdCharged import stdE, stdMu, stdPi
from stdPhotons import stdPhotons
from beamparameters import add_beamparameters


path = b2.create_path()


Jpsi_daughter = "ee"
eta_daughter = "gg"

runningtype = sys.argv[1]

OutputPrefix = "SKIM_"+Jpsi_daughter+eta_daughter
OutputExtension = ".root"
OutputFileName = OutputPrefix+OutputExtension

file_index = sys.argv[2]
OutputFileName = OutputPrefix+"_"+file_index+OutputExtension
ma.inputMdstList("default", "", path=path)

B_s0tupleList = vc.deltae_mbc

# ==================SKIM Start ===============================
stdE("good", path=path)
stdPhotons("loose", path=path)
ma.fillParticleList('gamma:bremsinput', cut='E < 1.0', path=path)
#ma.matchMCTruth(list_name='gamma:bremsinput', path=path)

ma.applyCuts("gamma:loose", "[ E > 0.05 ]", path=path)

# Bremstranlung photons
ma.correctBremsBelle(outputListName='e+:corrected',
                     inputListName='e+:good',
                     gammaListName='gamma:bremsinput',
                     multiplePhotons=True,
                     minimumEnergy=0.05,
                     angleThreshold=0.05,
                     writeOut=False,
                     path=path)

# Reconstruct Decay [ J/psi eta ]
ma.reconstructDecay('eta:gg -> gamma:loose gamma:loose',
                    '0.5 < M < 0.57', path=path)

ma.reconstructDecay('J/psi:ee -> e+:corrected e-:corrected',
                    '2.94 < M < 3.2', path=path)

# Reconstruct Decay [ B_s0 ]
ma.reconstructDecay('B_s0:jpsieta -> J/psi:ee eta:gg ','Mbc > 5.25 and abs(deltaE)< 0.4', path=path)
ma.matchMCTruth("B_s0:jpsieta",path=path)

# ===============Variables list
B_s0_List = B_s0tupleList

# Store the variables
ma.variablesToNtuple("B_s0:jpsieta", B_s0_List, filename=OutputFileName, path=path)

b2.process(path)
print(b2.statistics)
