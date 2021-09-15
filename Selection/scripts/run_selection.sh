#!/bin/bash

cmssw_tar=${1}
input_txt=${2}
year=${3}
nano_ver=${4}
eos_output_dir=${5}

#determine output name from input txt
output=$(basename ${input_txt%.txt}).root

#determine is it MC or data from Runs TTree
#see code after scram setup
#default
isMC=1

source /cvmfs/cms.cern.ch/cmsset_default.sh
tar -xf ${cmssw_tar}
rm ${cmssw_tar}
cd ${cmssw_tar%.tgz}/src/VVjjSemileptonic/Selection/
cp ${_CONDOR_SCRATCH_DIR}/${input_txt} .
scramv1 b ProjectRename
eval `scram runtime -sh`

#get isMC
testfile=root://cmseos.fnal.gov/$(head -n 1 ${input_txt})
testbranch="genEventSumw"
[[ ${nano_ver} == 6 ]] && testbranch="genEventSumw_"
[[ ${nano_ver} == 7 ]] && testbranch="genEventSumw"
isMC=$(python -c "import ROOT;
f = ROOT.TFile.Open('$testfile');
t = f.Get('Runs');
print(int(t.GetBranchStatus('$testbranch')))")

echo "====> isMC is $isMC"

Selection ${input_txt} ${output} ${isMC} ${year} ${nano_ver}

echo "====> Output root file : "
ls ${output}

echo "====> copying output root file to eos ..." 

xrdfs root://cmseos.fnal.gov/ mkdir -p ${eos_output_dir}
xrdcp -f ${output} root://cmseos.fnal.gov/${eos_output_dir}/

cd ${_CONDOR_SCRATCH_DIR}
rm -rf *

exit
