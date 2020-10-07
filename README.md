# DoubleHiggs_NanoAnalyzer

## Get Reduced Ntuples

```bash
cmsrel CMSSW_10_2_22
cd CMSSW_10_2_22/src
git clone git@github.com:ram1123/DoubleHiggs_NanoAnalyzer.git DoubleHiggs
cd DoubleHiggs
git checkout Develop
scramv1 b -j 8
```

To run the code:

```bash
cd $CMSSW_BASE/src/DoubleHiggs/Selection
Selection test.txt output.root 1 2017  1
```
Description of arguments in above command:

- First argument is the input txt file having list of root files with path
- Second argument is the name of output root file
- Third argument: for MC = 1, for Data = 0
- Fourth argument: Year
- Fifth argument: DEBUG (0/1)

## Get workspace from reduced ntuples

```bash
cd $CMSSW_BASE/src/DoubleHiggs/Selection
root -l -b  scripts/CreateWorkspace.C
```
