#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

#include "TROOT.h"
#include "TSystem.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TKey.h" 

int main (int ac, char** av) {

  std::string inputfile = av[1];
  std::string outputfile = av[2];

  //create output file
  TFile *outputFile = new TFile(outputfile.c_str(), "RECREATE");

  //loop over all TTrees in the file
  TFile *inputFile = TFile::Open(inputfile.c_str(), "READ");
  assert(inputFile);
  inputFile->cd();
  //purge unwanted TTree cycles in file
  inputFile->Purge();
  TIter nextkey(inputFile->GetListOfKeys());
  TKey *key;
  while((key = (TKey*)nextkey())){
    std::string className = key->GetClassName();
    std::cout << "Getting key from file.  Class type: " << className << std::endl;
    if(className.compare("TTree") != 0){
      std::cout << "Skipping key (not a TTree)" << std::endl;
      continue;
    }

    TTree *inputTree = (TTree*)key->ReadObj();
    std::cout << "Processing tree " << inputTree->GetName() << std::endl;

    //create new tree
    outputFile->cd();
    TTree *outputTree = inputTree->CloneTree(0);  
    std::cout << "Events in the ntuple: " << inputTree->GetEntries() << std::endl;

    UInt_t run;
    ULong64_t event;
    inputTree->SetBranchAddress("run", &run);
    inputTree->SetBranchAddress("evt", &event);
	    
    std::map<std::pair<UInt_t,ULong64_t>, bool > processedRunEvents;
    for (int n=0;n<inputTree->GetEntries();n++) { 
      if (n%1000000==0) std::cout << "Processed Event " << n << std::endl;
      inputTree->GetEntry(n);

      if(processedRunEvents.find(std::make_pair(run, event)) == processedRunEvents.end()){ 
          //not duplicate
          processedRunEvents[std::make_pair(run, event)] = true;
          outputTree->Fill(); 
      }
      else{
          std::cout << "Duplicate event " << run << " " << event << std::endl;
      }
    }

    std::cout << "Number of Input Events: " << inputTree->GetEntries() << std::endl;
    std::cout << "Number of Output Events: " << outputTree->GetEntries() << std::endl;

    //save
    outputTree->Write();
    inputFile->cd();
  }
	
  inputFile->Close();
  std::cout << "Closing output file." << std::endl;
  outputFile->Close();
  delete outputFile;
  return 0;
}
