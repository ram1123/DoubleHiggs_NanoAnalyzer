//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Oct  6 15:48:15 2020 by ROOT version 6.12/07
// from TTree Runs/Runs
// found on file: root://cmseos.fnal.gov//eos/uscms/store/user/rasharma/double-higgs/nanoAOD_skim/Run2016_v7_06Oct2020/GluGluToHHTo2G4Q_node_SM_TuneCP5_PSWeights_13TeV-madgraph-pythia8/201006_131113/255129E3-D986-F54C-9897-1F8D507D7521_SkimHadd.root
//////////////////////////////////////////////////////////

#ifndef NanoAOD_Weights_h
#define NanoAOD_Weights_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class NanoAOD_Weights {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   Long64_t        genEventCount;
   Double_t        genEventSumw;
   Double_t        genEventSumw2;
   UInt_t          nLHEScaleSumw;
   Double_t        LHEScaleSumw[9];   //[nLHEScaleSumw]
   UInt_t          nLHEPdfSumw;
   Double_t        LHEPdfSumw[103];   //[nLHEPdfSumw]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_genEventCount;   //!
   TBranch        *b_genEventSumw;   //!
   TBranch        *b_genEventSumw2;   //!
   TBranch        *b_nLHEScaleSumw;   //!
   TBranch        *b_LHEScaleSumw;   //!
   TBranch        *b_nLHEPdfSumw;   //!
   TBranch        *b_LHEPdfSumw;   //!

   NanoAOD_Weights(TTree *tree=0) {
      if (tree == 0) {
         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://cmseos.fnal.gov//store/user/lnujj/VVjj_aQGC/nanoAOD_skim/Run2018_v6/WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8/200408_094108/FB0B3C91-4F33-9D41-BF4C-D6677CEFD73A_Skim.root");
         if (!f || !f->IsOpen()) {
            f = new TFile("root://cmseos.fnal.gov//store/user/lnujj/VVjj_aQGC/nanoAOD_skim/Run2018_v6/WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8/200408_094108/FB0B3C91-4F33-9D41-BF4C-D6677CEFD73A_Skim.root");
         }
         f->GetObject("Runs",tree);
      }
      Init(tree);
   };

   virtual ~NanoAOD_Weights() {
      if (!fChain) return;
      delete fChain->GetCurrentFile();
   };
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);

   // NanoAOD_Weights(TTree *tree=0);
   // virtual ~NanoAOD_Weights();
   // virtual Int_t    Cut(Long64_t entry);
   // virtual Int_t    GetEntry(Long64_t entry);
   // virtual Long64_t LoadTree(Long64_t entry);
   // virtual void     Init(TTree *tree);
   // virtual void     Loop();
   // virtual Bool_t   Notify();
   // virtual void     Show(Long64_t entry = -1);
};


// // #ifdef NanoAOD_Weights_cxx
// NanoAOD_Weights::NanoAOD_Weights(TTree *tree) : fChain(0)
// {
// // if parameter tree is not specified (or zero), connect the file
// // used to generate this class and read the Tree.
//    if (tree == 0) {
//       TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://cmseos.fnal.gov//eos/uscms/store/user/rasharma/double-higgs/nanoAOD_skim/Run2016_v7_06Oct2020/GluGluToHHTo2G4Q_node_SM_TuneCP5_PSWeights_13TeV-madgraph-pythia8/201006_131113/255129E3-D986-F54C-9897-1F8D507D7521_SkimHadd.root");
//       if (!f || !f->IsOpen()) {
//          f = new TFile("root://cmseos.fnal.gov//eos/uscms/store/user/rasharma/double-higgs/nanoAOD_skim/Run2016_v7_06Oct2020/GluGluToHHTo2G4Q_node_SM_TuneCP5_PSWeights_13TeV-madgraph-pythia8/201006_131113/255129E3-D986-F54C-9897-1F8D507D7521_SkimHadd.root");
//       }
//       f->GetObject("Runs",tree);

//    }
//    Init(tree);
// }

// NanoAOD_Weights::~NanoAOD_Weights()
// {
//    if (!fChain) return;
//    delete fChain->GetCurrentFile();
// }

#endif
Int_t NanoAOD_Weights::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t NanoAOD_Weights::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      // Notify();
   }
   return centry;
}

void NanoAOD_Weights::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("genEventCount", &genEventCount, &b_genEventCount);
   fChain->SetBranchAddress("genEventSumw", &genEventSumw, &b_genEventSumw);
   fChain->SetBranchAddress("genEventSumw2", &genEventSumw2, &b_genEventSumw2);
   fChain->SetBranchAddress("nLHEScaleSumw", &nLHEScaleSumw, &b_nLHEScaleSumw);
   fChain->SetBranchAddress("LHEScaleSumw", LHEScaleSumw, &b_LHEScaleSumw);
   fChain->SetBranchAddress("nLHEPdfSumw", &nLHEPdfSumw, &b_nLHEPdfSumw);
   fChain->SetBranchAddress("LHEPdfSumw", LHEPdfSumw, &b_LHEPdfSumw);
   // Notify();
}

// Bool_t NanoAOD_Weights::Notify()
// {
//    // The Notify() function is called when a new file is opened. This
//    // can be either for a new TTree in a TChain or when when a new TTree
//    // is started when using PROOF. It is normally not necessary to make changes
//    // to the generated code, but the routine can be extended by the
//    // user if needed. The return value is currently not used.

//    return kTRUE;
// }

// void NanoAOD_Weights::Show(Long64_t entry)
// {
// // Print contents of entry.
// // If entry is not specified, print current entry
//    if (!fChain) return;
//    fChain->Show(entry);
// }
// Int_t NanoAOD_Weights::Cut(Long64_t entry)
// {
// // This function may be called from Loop.
// // returns  1 if entry is accepted.
// // returns -1 otherwise.
//    return 1;
// }
// #endif // #ifdef NanoAOD_Weights_cxx
