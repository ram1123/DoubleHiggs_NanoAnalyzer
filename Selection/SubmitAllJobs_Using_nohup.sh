WhichSamples=${1}

# if [ $# -eq 1 ]
#   then
#     echo "One arguments supplied"
#     WhichSamples=0
# fi



if [ ${WhichSamples} -eq 1 ]
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
    nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH1_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH1.root 1 2017  7 0 1 >& GluGluToHHTo2G4Q_node-cHHH1.log &
fi

if [ ${WhichSamples} -eq 0 ]
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

if [ ${WhichSamples} -eq 2 ]
  then
    echo "Running for all fully-hadronic samples..."
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1000.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1500.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1500.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M2000.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M2000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M2500.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M2500.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M250.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M250.log &
    echo "To prevent too many background jobs, sleeping for 2 mins"
    ps -f
    sleep 2m
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-3000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M3000.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M3000.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M500.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M500.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-800_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M800.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M800.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1250.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1250.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-600_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M600.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M600.log &
    echo "To prevent too many background jobs, sleeping for 2 mins"
    ps -f
    sleep 2m
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1750_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1750.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1750.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-260_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M260.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M260.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-270_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M270.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M270.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-280_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M280.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M280.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-300_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M300.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M300.log &
    echo "To prevent too many background jobs, sleeping for 2 mins"
    ps -f
    sleep 2m
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-320_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M320.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M320.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-350_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M350.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M350.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-400_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M400.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M400.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-450_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M450.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M450.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-550_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M550.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M550.log &
    echo "To prevent too many background jobs, sleeping for 2 mins"
    ps -f
    sleep 2m
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-650_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M650.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M650.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-700_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M700.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M700.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-750_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M750.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M750.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-850_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M850.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M850.log &
    nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-900_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M900.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M900.log &
    nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH1_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH1.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH1.log &
    ps -f

fi
# python CutFlow.py
