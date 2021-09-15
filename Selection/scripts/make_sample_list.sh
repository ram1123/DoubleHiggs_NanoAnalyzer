#!/bin/bash
shopt -s expand_aliases
shopt -s extglob

# args
eos_dir=${1}
list_dir=${2}
year=${3}
n_split=${4:-10}

alias eosfind="eos root://cmseos.fnal.gov find"
listOfSamples=$(eosfind -d ${eos_dir} | cut -d"=" -f2-)

echo "Making \"${list_dir}/${year}\" directory for txt files"
mkdir -p ${list_dir}/${year}

for sample in ${listOfSamples}
do
  sampleName=$(echo $sample | sed "s|$eos_dir||" | sed 's/\///g')
  [[ -z $sampleName ]] && continue
  echo $sampleName
  rm -v ${list_dir}/${year}/${sampleName}*.txt
  write=$(eosfind -name *.root ${sample} > ${list_dir}/${year}/${sampleName}.txt)
done

for sample in $(ls ${list_dir}/${year}/!(*Run${year}*.txt));
  do
  split_samples.sh $sample ${sample/.txt/_} ${n_split} true
done
exit
