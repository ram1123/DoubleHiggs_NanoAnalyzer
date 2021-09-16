# find /eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/ResonantAna/nanoAOD_skim/v1Ntuple_nLep0/GluGluToRadionToHHTo2G4Q_M-250_narrow*/*/ -name "*.root" > inputFiles_M250.txt
# find /eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/ResonantAna/nanoAOD_skim/v1Ntuple_nLep0/GluGluToRadionToHHTo2G4Q_M-500_narrow*/*/ -name "*.root" > inputFiles_M500.txt
# find /eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/ResonantAna/nanoAOD_skim/v1Ntuple_nLep0/GluGluToRadionToHHTo2G4Q_M-800_narrow*/*/ -name "*.root" > inputFiles_M800.txt
# find /eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/ResonantAna/nanoAOD_skim/v1Ntuple_nLep0/GluGluToRadionToHHTo2G4Q_M-1000_narrow*/*/ -name "*.root" > inputFiles_M1000.txt
# find /eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/ResonantAna/nanoAOD_skim/v1Ntuple_nLep0/GluGluToRadionToHHTo2G4Q_M-1500_narrow*/*/ -name "*.root" > inputFiles_M1500.txt
# find /eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/ResonantAna/nanoAOD_skim/v1Ntuple_nLep0/GluGluToRadionToHHTo2G4Q_M-2000_narrow*/*/ -name "*.root" > inputFiles_M2000.txt
# find /eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/ResonantAna/nanoAOD_skim/v1Ntuple_nLep0/GluGluToRadionToHHTo2G4Q_M-2500_narrow*/*/ -name "*.root" > inputFiles_M2500.txt
# find /eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/ResonantAna/nanoAOD_skim/v1Ntuple_nLep0/GluGluToRadionToHHTo2G4Q_M-3000_narrow*/*/ -name "*.root" > inputFiles_M3000.txt


Selection inputFiles_M250.txt  output_M250.root 1 2017  7 0
Selection inputFiles_M500.txt  output_M500.root 1 2017  7 0
Selection inputFiles_M800.txt  output_M800.root 1 2017  7 0
Selection inputFiles_M1000.txt  output_M1000.root 1 2017  7 0
Selection inputFiles_M1500.txt  output_M1500.root 1 2017  7 0
Selection inputFiles_M2000.txt  output_M2000.root 1 2017  7 0
Selection inputFiles_M2500.txt  output_M2500.root 1 2017  7 0
Selection inputFiles_M3000.txt  output_M3000.root 1 2017  7 0