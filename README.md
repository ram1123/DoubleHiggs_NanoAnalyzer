# DoubleHiggs_NanoAnalyzer

## Get Reduced Ntuples

```bash
cmsrel CMSSW_10_6_20
cd CMSSW_10_6_20/src
git clone git@github.com:ram1123/DoubleHiggs_NanoAnalyzer.git DoubleHiggs
cd DoubleHiggs
git checkout Develop
scramv1 b -j 8
```

To run the code:

```bash
cd $CMSSW_BASE/src/DoubleHiggs/Selection
Selection inputFiles.txt output.root 1 2017  7 0 1
```
Description of arguments in above command:

- First argument is the name of input txt file having list of root files with path or one can also provide the one root file here
- Second argument is the name of output root file
- Third argument: for MC = 1, for Data = 0
- Fourth argument: Year
- Fifth argument: nanoAOD version
- Sixth argument: DEBUG (0/1); If its 1 then it prints many outputs.
- Seventh argument (0/1): When using EOS files, wants to download a local copy then run it as interactive or not.

Run code over all mass points for FH/SL samples using nohup command:

```bash
bash SubmitAllJobs_Using_nohup.sh <WhichProcess>
```
- Argument
    - `WhichProcess` = 0 for SL,
    - `WhichProcess` = 1 for few important FH mass points
    - `WhichProcess` = 2 for all FH mass points.


```bash
# check if jobs are done or not
ps -f
```

## Get cut-flow table

```bash
python CutFlow.py
```

This also give you the histogram (in pdf) for each mass point having cut-flow information.


## Get workspace from reduced ntuples (Not working now)

```bash
cd $CMSSW_BASE/src/DoubleHiggs/Selection
root -l -b  scripts/CreateWorkspace.C
```
