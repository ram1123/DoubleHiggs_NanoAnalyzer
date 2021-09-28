import os
import argparse

parser = argparse.ArgumentParser(description='')

parser.add_argument('--WhichSamples', type=int, required=True)
parser.add_argument('--InputTxtFilePath', type=str, default="InputSampleTextFiles")
# parser.add_argument('--InputTxtFile', type=int, required=True)

args = parser.parse_args()

InputTextFileList = [
    "GluGluToRadionToHHTo2G4Q_M-250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-260_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-270_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-280_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-300_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-320_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-350_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-400_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-450_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-550_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-600_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-650_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-700_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-750_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-800_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-850_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-900_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-1000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-1250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-1500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-1750_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-2000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-2500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt",
    "GluGluToRadionToHHTo2G4Q_M-3000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt"
]

OutPutFileNameReplacement = ["_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
                             "_TuneCP5_PSWeights_13TeV-powheg-pythia8","-"]


if (args.WhichSamples == 0):
    os.system('echo "Running for SL-hadronic.."')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-1000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M1000.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M1000.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M250.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M250.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-1500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M1500.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M1500.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-3000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M3000.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M3000.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-2000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M2000.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M2000.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M500.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M500.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-2500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M2500.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M2500.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G2Qlnu_M-800_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G2Qlnu_M800.root  1 2017 7 0 1 >& GluGluToRadionToHHTo2G2Qlnu_M800.log &')

if (args.WhichSamples == 1):
    os.system('echo "Running for fully-hadronic.."')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M250.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M250.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1000.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M1000.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-3000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M3000.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M3000.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M500.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M500.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-800_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M800.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M800.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1500.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M1500.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M2000.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M2000.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M2500.root 1 2017  7 0 1 >& GluGluToRadionToHHTo2G4Q_M2500.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH1_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH1.root 1 2017  7 0 1 >& GluGluToHHTo2G4Q_node-cHHH1.log &')

if (args.WhichSamples == 2):
    os.system('echo "Running for all fully-hadronic samples..."')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M250.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M250.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-260_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M260.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M260.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-270_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M270.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M270.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-280_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M280.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M280.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-300_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M300.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M300.log &')
    os.system('ps -f')
    os.system('echo "To prevent too many background jobs, sleeping for 2 mins"')
    os.system('sleep 2m')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-320_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M320.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M320.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-350_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M350.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M350.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-400_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M400.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M400.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-450_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M450.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M450.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M500.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M500.log &')
    os.system('ps -f')
    os.system('echo "To prevent too many background jobs, sleeping for 2 mins"')
    os.system('sleep 2m')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-550_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M550.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M550.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-600_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M600.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M600.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-650_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M650.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M650.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-700_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M700.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M700.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-750_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M750.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M750.log &')
    os.system('ps -f')
    os.system('echo "To prevent too many background jobs, sleeping for 2 mins"')
    os.system('sleep 2m')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-800_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M800.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M800.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-850_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M850.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M850.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-900_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M900.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M900.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1000.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1000.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1250_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1250.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1250.log &')
    os.system('ps -f')
    os.system('echo "To prevent too many background jobs, sleeping for 2 mins"')
    os.system('sleep 2m')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1500.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1500.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-1750_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M1750.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M1750.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M2000.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M2000.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-2500_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M2500.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M2500.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToRadionToHHTo2G4Q_M-3000_narrow_TuneCP5_PSWeights_13TeV-madgraph-pythia8.txt GluGluToRadionToHHTo2G4Q_M3000.root 1 2017 7 0 1 &> GluGluToRadionToHHTo2G4Q_M3000.log &')
    os.system('ps -f')
    os.system('echo "To prevent too many background jobs, sleeping for 2 mins"')
    os.system('sleep 2m')
    os.system('echo "Running for SM fully-hadronic samples.."')
    os.system('nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH0_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH0.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH0.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH2p45_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH2p45.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH2p45.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH1_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH1.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH1.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH5_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH5.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH5.log &')
    os.system('ps -f')
    os.system('sleep 2m')
    os.system('ps -f')

if (args.WhichSamples == 3):
    os.system('echo "Running for SM fully-hadronic samples.."')
    os.system('nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH0_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH0.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH0.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH2p45_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH2p45.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH2p45.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH1_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH1.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH1.log &')
    os.system('nohup Selection InputSampleTextFiles/GluGluToHHTo2G4Q_node_cHHH5_TuneCP5_PSWeights_13TeV-powheg-pythia8.txt GluGluToHHTo2G4Q_node-cHHH5.root 1 2017 7 0 1 &> GluGluToHHTo2G4Q_node_cHHH5.log &')

if (args.WhichSamples == 4):
    os.system('echo "Running a test job.."')
    # Selection InputSampleTextFiles/inputFiles.txt test.root 1 2017 7 0 1
    os.system('Selection DB64186F-0685-E445-ACF2-0C039BFD6301.root test.root 1 2017 7 0 0')
