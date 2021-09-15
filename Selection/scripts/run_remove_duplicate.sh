#!/bin/bash

cmssw_tar=${1}
era=${2}
ntuples=${3}
files=${@:4}

source /cvmfs/cms.cern.ch/cmsset_default.sh
tar -xf ${cmssw_tar}
rm ${cmssw_tar}
cd ${cmssw_tar%.tgz}/src/
scramv1 b ProjectRename
eval `scram runtime -sh`

echo "First doing the hadd of input list of root files"
rm Data.root
hadd Data.root ${files}
echo "Removing duplicate events now"
RemoveDuplicateEvents Data.root noDuplicate.root
hadd Data_noDup.root noDuplicate.root
rootcp Data.root:/TotalEvents Data_noDup.root:/
rm noDuplicate.root
rm Data.root
mv Data_noDup.root Data_noDup_${era}.root

xrdcp -f Data_noDup_${era}.root root://cmseos.fnal.gov/${ntuples}/Data_noDup_${era}.root

exit
