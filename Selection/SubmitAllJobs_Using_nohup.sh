RunFH=1

if [ $# -eq 1 ]
  then
    echo "One arguments supplied"
    RunFH=0
fi

if [ ${RunFH} -eq 1 ]
  then
    echo "Running for fully-hadronic.."
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M250.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M250.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1000.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M1000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-3000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M3000.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M3000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M500.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M500.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-800_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M800.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M800.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1500.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M1500.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M2000.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M2000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M2500.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M2500.log &
fi

if [ ${RunFH} -eq 0 ]
  then
    echo "Running for SL-hadronic.."
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-1000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M1000.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M1000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M250.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M250.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-1500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M1500.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M1500.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-3000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M3000.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M3000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-2000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M2000.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M2000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M500.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M500.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-2500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M2500.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M2500.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-800_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M800.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M800.log &
fi

# python CutFlow.py
