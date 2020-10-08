//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Oct  7 11:05:00 2020 by ROOT version 6.12/07
// from TTree Runs/Runs
// found on file: root://cmseos.fnal.gov//store/user/rasharma/double-higgs/nanoAOD_skim/Run2016_v7_06Oct2020/DoubleEG/Run2017B/201006_131113/04265FBD-F908-4846-BC5C-517288B1AF79_SkimHadd.root
//////////////////////////////////////////////////////////

#ifndef NanoAOD_Weights_Data_h
#define NanoAOD_Weights_Data_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class NanoAOD_Weights_Data {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;

   // List of branches
   TBranch        *b_run;   //!


   NanoAOD_Weights_Data(TTree *tree) : fChain(0)
   {
   // if parameter tree is not specified (or zero), connect the file
   // used to generate this class and read the Tree.
      if (tree == 0) {
         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://cmseos.fnal.gov//store/user/rasharma/double-higgs/nanoAOD_skim/Run2016_v7_06Oct2020/DoubleEG/Run2017B/201006_131113/04265FBD-F908-4846-BC5C-517288B1AF79_SkimHadd.root");
         if (!f || !f->IsOpen()) {
            f = new TFile("root://cmseos.fnal.gov//store/user/rasharma/double-higgs/nanoAOD_skim/Run2016_v7_06Oct2020/DoubleEG/Run2017B/201006_131113/04265FBD-F908-4846-BC5C-517288B1AF79_SkimHadd.root");
         }
         f->GetObject("Runs",tree);

      }
      Init(tree);
   }

   ~NanoAOD_Weights_Data()
   {
      // if (!fChain) return;
      // delete fChain->GetCurrentFile();
   }

   // NanoAOD_Weights_Data(TTree *tree=0);
   // virtual ~NanoAOD_Weights_Data();
   // virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   // virtual void     Loop();
   // virtual Bool_t   Notify();
   // virtual void     Show(Long64_t entry = -1);

};

#endif

// #ifdef NanoAOD_Weights_Data_cxx

Int_t NanoAOD_Weights_Data::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t NanoAOD_Weights_Data::LoadTree(Long64_t entry)
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

void NanoAOD_Weights_Data::Init(TTree *tree)
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
   // Notify();
}

// #endif // #ifdef NanoAOD_Weights_Data_cxx
