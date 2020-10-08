# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2020-10-07 14:03:36
# @Last Modified by:   ramkrishna
# @Last Modified time: 2020-10-07 18:31:41

import subprocess
import os
import sys

sys.path.append("Utils/python_utils/.")

from color_style import style

InputFilePath = "/eos/uscms/store/user/rasharma/double-higgs/nanoAOD_skim/Run2016_v7_06Oct2020"
OutputFilePath = "/eos/uscms/store/user/rasharma/double-higgs/ReducedNtuples"

if InputFilePath[-1] == "/":
  StringToChange = InputFilePath.split("/")[-2]
else:
  StringToChange = InputFilePath.split("/")[-1]

condor_file_name = 'submit_condor_jobs_lnujj_'+StringToChange


import fileList
test = fileList.FileHelper(InputFilePath,OutputFilePath)

test.list_files()

print test.AllSubDirectoryLists
print len(test.AllSubDirectoryLists)
# print test.ListOfAllInputRootFiles
print len(test.ListOfAllInputRootFiles)

print "====: output:"
test.GetOutPutFileList()
# print test.ListOfAllOutputRootFiles
print len(test.ListOfAllOutputRootFiles)

test.CreateSameHirarcyDirsSameAsListFiles()

# Create log files
import infoCreaterGit
SumamryOfCurrentSubmission = raw_input("\n\nWrite summary for current job submission: ")
infoLogFiles = infoCreaterGit.BasicInfoCreater('summary.dat',SumamryOfCurrentSubmission)
infoLogFiles.GenerateGitPatchAndLog()

# Get CMSSW directory path and name
cmsswDirPath = os.environ['CMSSW_BASE']
CMSSWRel = cmsswDirPath.split("/")[-1]

# Create directories for storing log files and output files at EOS.
import fileshelper
dirsToCreate = fileshelper.FileHelper('condor_logs/'+StringToChange, os.path.join(OutputFilePath,StringToChange))
output_log_path = dirsToCreate.CreateLogDirWithDate()
dirName = dirsToCreate.dirName


# create tarball of present working CMSSW base directory
os.system('rm -f CMSSW*.tgz')
storeDir = os.path.join(OutputFilePath,StringToChange)
import makeTarFile
makeTarFile.make_tarfile(cmsswDirPath, CMSSWRel+".tgz")
print "copying the "+CMSSWRel+".tgz  file to eos path: "+storeDir+"\n"
os.system('xrdcp -f ' + CMSSWRel+".tgz" + ' root://cmseos.fnal.gov/'+storeDir+'/' + CMSSWRel+".tgz")


outjdl_file = open(condor_file_name+".jdl","w")
outjdl_file.write("Executable = "+condor_file_name+".sh\n")
outjdl_file.write("Universe = vanilla\n")
outjdl_file.write("Notification = ERROR\n")
outjdl_file.write("Should_Transfer_Files = YES\n")
outjdl_file.write("WhenToTransferOutput = ON_EXIT\n")
# outjdl_file.write("Transfer_Input_Files = "+Transfer_Input_Files + ",  " + post_proc_to_run+"\n")
outjdl_file.write("x509userproxy = $ENV(X509_USER_PROXY)\n")

ExternalCounter = 0
isMC = 1
for count,files in enumerate(test.ListOfAllInputRootFiles):
    # if "DoubleEG" in files:
    #     continue
    # if "SinglePhoton" in files:
    #     continue
    # print count,files
    if "DoubleEG" in files:
        isMC = 0
    elif "SinglePhoton" in files:
        isMC = 0
    else:
        isMC = 1
    # if ExternalCounter > 5:  continue
    LogFileName = files.replace(InputFilePath,"")
    if LogFileName[0] == "/":
        LogFileName = LogFileName.split("/")[1]
    else:
        LogFileName = LogFileName.split("/")[0]
    print LogFileName
    outjdl_file.write("Output = "+output_log_path+"/"+LogFileName+"_$(Cluster)_$(Process).stdout\n")
    outjdl_file.write("Error  = "+output_log_path+"/"+LogFileName+"_$(Cluster)_$(Process).stdout\n")
    outjdl_file.write("Log  = "+output_log_path+"/"+LogFileName+"_$(Cluster)_$(Process).log\n")
    outjdl_file.write("Arguments = "+files.replace("/eos/uscms","")+" output.root "+" "+str(isMC) +" 2017  0  " + test.ListOfAllOutputRootFiles[count].replace("/eos/uscms","")+ " \n")
    outjdl_file.write("Queue \n")
    ExternalCounter += 1

outjdl_file.close();


command = "Selection "

outScript = open(condor_file_name+".sh","w");
outScript.write('#!/bin/bash');
outScript.write("\n"+'echo "Starting job on " `date`');
outScript.write("\n"+'echo "Running on: `uname -a`"');
outScript.write("\n"+'echo "System software: `cat /etc/redhat-release`"');
outScript.write("\n"+'source /cvmfs/cms.cern.ch/cmsset_default.sh');
outScript.write("\n"+'echo "copy cmssw tar file from store area"');
outScript.write("\n"+'xrdcp -s root://cmseos.fnal.gov/'+storeDir.replace("/eos/uscms","")+os.sep+CMSSWRel +'.tgz  .');
outScript.write("\n"+'tar -xf '+ CMSSWRel +'.tgz' );
outScript.write("\n"+'rm '+ CMSSWRel +'.tgz' );
outScript.write("\n"+'cd ' + CMSSWRel + '/src/DoubleHiggs/Selection/' );
#outScript.write("\n"+'echo "====> List files : " ');
#outScript.write("\n"+'ls -alh');
outScript.write("\n"+'rm *.root *.txt');
outScript.write("\n"+'scramv1 b ProjectRename');
outScript.write("\n"+'eval `scram runtime -sh`');
outScript.write("\n"+command +'$1  $2 $3 $4 $5');
outScript.write("\n"+'echo "====> List root files : " ');
outScript.write("\n"+'ls *.root');
outScript.write("\n"+'echo "====> copying *.root file to stores area..." ');
outScript.write("\n"+'xrdcp -f output.root root://cmseos.fnal.gov/${6}');
outScript.write("\n"+'rm *.root');
outScript.write("\n"+'cd ${_CONDOR_SCRATCH_DIR}');
outScript.write("\n"+'rm -rf ' + CMSSWRel);
outScript.write("\n");
outScript.close();
os.system("chmod 777 "+condor_file_name+".sh");

print "===> Set Proxy Using:";
print "\tvoms-proxy-init --voms cms --valid 168:00";
print "\"condor_submit "+condor_file_name+".jdl\" to submit";
#os.system("condor_submit "+condor_file_name+".jdl")

