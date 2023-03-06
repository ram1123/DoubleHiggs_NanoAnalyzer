#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <stdint.h>
#include <iomanip>
#include <ctime>
#include <map>
#include <math.h>

#include "TROOT.h"
#include "TFile.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TChain.h"
#include "TProfile.h"
#include "TMath.h"
#include "TString.h"
#include "TClass.h"
#include "TApplication.h"
#include "TLorentzVector.h"
#include "TF1.h"
#include "TH2.h"
#include <TClonesArray.h>

#include "../interface/NanoReader.hh"
#include "../interface/ScaleFactors.hh"
#include "../interface/Utils.hh"
#include "../interface/METzCalculator.h"

int main (int argc, char** argv) {

    std::cout << "[INFO]: Program name is : " << argv[0] << std::endl;
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    int isMC = atoi(argv[3]);
    int era = atoi(argv[4]);
    int nanoVersion = atoi(argv[5]);
    bool DEBUG = atoi(argv[6]);
    bool DOWNLOAD_LOCAL_COPY = atoi(argv[7]);
    int DEBUG_nEvents = atoi(argv[8]);

    ScaleFactors scaleFactor(era);

    std::vector<TLorentzVector> LV_LHE_Higgs;
    std::vector<TLorentzVector> LV_GEN_Higgs;
    std::vector<TLorentzVector> LV_GEN_WBosons;
    std::vector<TLorentzVector> LV_GEN_ZBosons;
    std::vector<TLorentzVector> LV_GEN_quarks;
    std::vector<TLorentzVector> LV_GEN_VBFquarks;


    std::vector<TLorentzVector> LV_tightMuon;
    std::vector<TLorentzVector> LV_tightEle;
    std::vector<TLorentzVector> LV_tightPhoton;

    std::vector<TLorentzVector> LV_Ak4Jets;
    // std::vector<TLorentzVector> LV_VBBFAk4Jets;
    // std::vector<TLorentzVector> Ak4JetsTem;
    std::vector<TLorentzVector> LV_Ak8WZJets;
    std::vector<TLorentzVector> LV_Ak8HiggsJets;

    std::vector<int> goodAK4JetIndex;
    // std::vector<int> goodAK4VBFJetIndex;
    std::vector<int> goodWJetIndex;
    std::vector<int> goodWLepJetIndex;
    std::vector<int> goodHJetIndex;
    // std::vector<int> goodAK4JetTem;
    //
    //
    //   INPUT/OUTPUT
    //
    //

    TFile *of = new TFile(outputFile.c_str(),"RECREATE");
    TTree *ot = new TTree("Events","Events");
    WVJJData* WVJJTree = new WVJJData(ot);
    TH1F *totalEvents = new TH1F("TotalEvents","TotalEvents",2,-1,1);
    TH1F *totalCutFlow_FH = new TH1F("totalCutFlow_FH","totalCutFlow_FH",15,0,15);
    totalCutFlow_FH->GetXaxis()->SetBinLabel(1,"MC Gen");
    totalCutFlow_FH->GetXaxis()->SetBinLabel(2,"nEvent");
    totalCutFlow_FH->GetXaxis()->SetBinLabel(3,"Skim NanoAOD");
    totalCutFlow_FH->GetXaxis()->SetBinLabel(4,"Trigger");
    totalCutFlow_FH->GetXaxis()->SetBinLabel(5,"Photon Selection");
    totalCutFlow_FH->GetXaxis()->SetBinLabel(6,"Lepton Selection");
    totalCutFlow_FH->GetXaxis()->SetBinLabel(7,"nAK8_Higgs >= 1");  // 1 jet category
    totalCutFlow_FH->GetXaxis()->SetBinLabel(8,"nAK8H=0 & nAK8_W >= 2"); // 2  jet category
    totalCutFlow_FH->GetXaxis()->SetBinLabel(9,"nAK8H=0 & nAK8_W=1 & nAK4>=2");  // 3 jet catego
    totalCutFlow_FH->GetXaxis()->SetBinLabel(10,"nAK8H=0 & nAK8_W>=1 & nAK4>=2");  // 3 jet catego
    totalCutFlow_FH->GetXaxis()->SetBinLabel(11,"nAK8H=0 & nAK8W=0 & nAK4>=4"); // 4 jet category
    totalCutFlow_FH->GetXaxis()->SetBinLabel(12,"nAK4 >= 4");
    totalCutFlow_FH->GetXaxis()->SetBinLabel(13,"1Jet2Jet3Jet4Jet");
    totalCutFlow_FH->GetXaxis()->SetBinLabel(14,"pT/mgg cut");
    totalCutFlow_FH->GetXaxis()->SetBinLabel(15,"pT(#gamma #gamma)>100");

    TH1F *totalCutFlow_FH_GENMatch = new TH1F("totalCutFlow_FH_GENMatch","totalCutFlow_FH_GENMatch",15,0,15);
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(1,"MC Gen");
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(2,"nEvent");
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(3,"Skim NanoAOD");
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(4,"Trigger");
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(5,"Photon Selection");
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(6,"Lepton Selection");
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(7,"nAK8_Higgs >= 1");  // 1 jet category
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(8,"nAK8H=0 & nAK8_W >= 2"); // 2  jet category
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(9,"nAK8H=0 & nAK8_W=1 & nAK4>=2");  // 3 jet catego
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(10,"nAK8H=0 & nAK8_W>=1 & nAK4>=2");  // 3 jet catego
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(11,"nAK8H=0 & nAK8W=0 & nAK4>=4"); // 4 jet category
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(12,"nAK4 >= 4");
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(13,"1Jet2Jet3Jet4Jet");
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(14,"pT/mgg cut");
    totalCutFlow_FH_GENMatch->GetXaxis()->SetBinLabel(15,"pT(#gamma #gamma)>100");


    // TH1F *totalCutFlow_SL = (TH1F*)totalCutFlow_FH->Clone("totalCutFlow_SL");
    // totalCutFlow_SL->SetTitle("totalCutFlow_SL");
    TH1F *totalCutFlow_SL = new TH1F("totalCutFlow_SL","totalCutFlow_SL",11,0,11);
    totalCutFlow_SL->GetXaxis()->SetBinLabel(1,"MC Gen");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(2,"nEvent");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(3,"Skim NanoAOD");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(4,"Trigger");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(5,"Photon Selection");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(6,"Lepton Selection");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(7,"nAK8_W >= 1");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(8,"nAK4 >= 2");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(9,"1Jet+2Jet");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(10,"pT/mgg cut");
    totalCutFlow_SL->GetXaxis()->SetBinLabel(11,"pT(#gamma #gamma)>100");


    TFile *f=0;
    TTree *t=0, *r=0;

    /**
     * If the inputFile ends with ".root", then add it into the text file.
     */
    if (ends_with(inputFile,"root"))
    {
        std::string str = "echo ";
        str = str + inputFile + " > InputRootFileList.txt";
        const char *command = str.c_str();
        system(command);
        inputFile = "InputRootFileList.txt";
    }

    if(DEBUG) std::cout << "[INFO]: inputTextFile: " << inputFile << std::endl;
    if(DEBUG) std::cout << "[INFO]: outputFile: " << outputFile << std::endl;

    std::ifstream ifs;
    ifs.open(inputFile.data());
    assert(ifs.is_open());
    std::string line;
    int lineCount=0;

    // Create a temporary directory to download the file from EOS
    // if (DOWNLOAD_LOCAL_COPY) {
    char test[] = "/tmp/rasharma/tmpdir_XXXXXX";
    char *dir_name = mkdtemp(test);
    int CountEvents = 0;
    // }
    while (getline(ifs,line)) {
        std::stringstream ss(line);
        std::string filetoopen;
        ss >> filetoopen;

        lineCount+=1;

        std::cout << "[INFO]: current file: " << filetoopen << std::endl;
        // f = TFile::Open(TString("root://cmseos.fnal.gov/") + TString(filetoopen), "read");
        // f = TFile::Open(TString("root://xrootd-cms.infn.it/")+TString(filetoopen),"read");
        if (DOWNLOAD_LOCAL_COPY) {
            TString EOSFileDownloadCommand = TString("xrdcp ") + TString(filetoopen) + TString("  ") + TString(dir_name);
            if(DEBUG) std::cout << "EOS file download command: \n\t" << EOSFileDownloadCommand << std::endl;
            system((std::string(EOSFileDownloadCommand)).c_str());
            std::vector<std::string> fields;
            const std::string delimiter = "\\";
            Tokenize(filetoopen,fields); // TO-DO: Add the delimiter here.
            // f = TFile::Open(TString(fields[9]),"read"); // TO-DO: instead of 9th element it should take last element
            std::cout << "File to run: " << TString(dir_name)+"/"+TString(fields.back()) << std::endl;
            f = TFile::Open(TString(dir_name)+"/"+TString(fields.back()),"read"); // TO-DO: instead of 9th element it should take last element
        }
        else {
            f = TFile::Open(TString(filetoopen),"read");
        }

        if (f->IsZombie())
        {
            std::cout << "SKIPPING: This root file is IsZombie." << std::endl;
            continue;
        }

        if(DEBUG) std::cout << "[INFO]: current file: " << filetoopen << std::endl;

        t = (TTree *)f->Get("Events");
        r = (TTree *)f->Get("Runs");
        if (t==NULL)
        {
            std::cout << "SKIPPING: No tree named \"Events\" exits." << std::endl;
            continue;
        }

        NanoReader NanoReader_ = NanoReader(t);
        NanoReader NanoWeightReader = NanoReader(r);

        NanoWeightReader.GetEntry(0);

        float genEventSumw=0.0;
        float genEventCount=0.0;
        if (isMC && nanoVersion == 6) {
            genEventSumw = *NanoWeightReader.genEventSumw_;
            genEventCount = *NanoWeightReader.genEventCount_;
        }
        else if (isMC && nanoVersion >= 7) {
            genEventSumw = *NanoWeightReader.genEventSumw;
            genEventCount = *NanoWeightReader.genEventCount;
        }
        totalEvents->SetBinContent(2,totalEvents->GetBinContent(2)+genEventSumw);
        totalCutFlow_FH->Fill("MC Gen",genEventCount);
        totalCutFlow_FH->Fill("nEvent",genEventSumw);
        totalCutFlow_SL->Fill("MC Gen",genEventCount);
        totalCutFlow_SL->Fill("nEvent",genEventSumw);
        totalCutFlow_FH_GENMatch->Fill("MC Gen",genEventCount);
        totalCutFlow_FH_GENMatch->Fill("nEvent",genEventSumw);


        if(DEBUG) std::cout << "\t[INFO]: Start of event loop. " << std::endl;

        uint TotalEntries = t->GetEntries();
        // for (uint i=0; i < t->GetEntries(); i++)
        if (DEBUG_nEvents != -1) TotalEntries = DEBUG_nEvents;
        for (uint i=0; i < TotalEntries; i++)
        // for (uint i=0; i < 200; i++)
        {
            WVJJTree->clearVars();
            NanoReader_.GetEntry(i);
            totalCutFlow_FH->Fill("Skim NanoAOD",1);
            totalCutFlow_SL->Fill("Skim NanoAOD",1);
            totalCutFlow_FH_GENMatch->Fill("Skim NanoAOD",1);

            if (i%10000==0) std::cout <<"\t[INFO]: file " << lineCount << ": event " << i << std::endl;
            if (DEBUG)       std::cout <<"\t[INFO]: file " << lineCount << ": event " << i << std::endl;

            if (isMC==1) {
                WVJJTree->genWeight=*NanoReader_.Generator_weight;
            }

            WVJJTree->run = *NanoReader_.run;
            WVJJTree->evt = *NanoReader_.event;
            WVJJTree->ls = *NanoReader_.luminosityBlock;

            // WVJJTree->nPV = *NanoReader_.PV_npvsGood;
            if (isMC) WVJJTree->nPU_mean = *NanoReader_.Pileup_nPU;

            WVJJTree->puWeight = scaleFactor.GetPUWeight(WVJJTree->nPU_mean, 0);
            WVJJTree->puWeight_Up = scaleFactor.GetPUWeight(WVJJTree->nPU_mean, 1);
            WVJJTree->puWeight_Down = scaleFactor.GetPUWeight(WVJJTree->nPU_mean, -1);

            // LHE information: Before partion shower
            // It contains information for pp -> Radion -> HH, only.
            if (isMC==1)
            {
                LV_LHE_Higgs.clear();
                for (UInt_t LHEPartCount = 0; LHEPartCount < *NanoReader_.nLHEPart; ++LHEPartCount)
                {
                    continue;
                    // if (NanoReader_.LHEPart_status[LHEPartCount] == 1)
                    // std::cout <<  "Event No. " << i << "/" << lineCount
                    //             << "\tLHE: pdgID = " << NanoReader_.LHEPart_pdgId[LHEPartCount]
                    //             << "\t Status = " << NanoReader_.LHEPart_status[LHEPartCount]
                    //             << "\t mass = " << NanoReader_.LHEPart_mass[LHEPartCount]
                    //             << "\t pT = " << NanoReader_.LHEPart_pt[LHEPartCount]
                    //             << std::endl;
                    // if (NanoReader_.LHEPart_pdgId[LHEPartCount] == 25 && NanoReader_.LHEPart_status[LHEPartCount] == 1)
                    // {
                    //     LV_LHE_Higgs.push_back(TLorentzVector(0,0,0,0));
                    //     LV_LHE_Higgs.back().SetPtEtaPhiM(NanoReader_.LHEPart_pt[LHEPartCount],
                    //                                      NanoReader_.LHEPart_eta[LHEPartCount],
                    //                                      NanoReader_.LHEPart_phi[LHEPartCount],
                    //                                      NanoReader_.LHEPart_mass[LHEPartCount]);
                    // }
                }
                // if (LV_LHE_Higgs.size() != 2)
                // {
                //     std::cout << "Higgs size = " << LV_LHE_Higgs.size() << std::endl;
                //     std::cout << "LHE Higgs bosons are not equal to 2. Please check..." << std::endl;
                //     exit(0);
                // }
                // WVJJTree->LHE_deltaR_HH = deltaR(LV_LHE_Higgs[0].Eta(),LV_LHE_Higgs[0].Phi(),LV_LHE_Higgs[1].Eta(),LV_LHE_Higgs[1].Phi());
                // WVJJTree->LHE_deltaEta_HH = LV_LHE_Higgs[0].Eta() - LV_LHE_Higgs[1].Eta();
                // WVJJTree->LHE_deltaPhi_HH = deltaPhi(LV_LHE_Higgs[0].Phi(),LV_LHE_Higgs[1].Phi());
            }

            // Below part : GEN information
            //              This contains information of the Higgs decays and after shower effects.
            //
            if (isMC==1)
            {
                LV_GEN_Higgs.clear();
                LV_GEN_WBosons.clear();
                LV_GEN_ZBosons.clear();
                LV_GEN_quarks.clear();
                LV_GEN_VBFquarks.clear();
                for (UInt_t GENPartCount = 0; GENPartCount < *NanoReader_.nGenPart; ++GENPartCount)
                {
                    int pdgid = NanoReader_.GenPart_pdgId[GENPartCount];
                    int status = NanoReader_.GenPart_status[GENPartCount];
                    int motherPDGid = NanoReader_.GenPart_pdgId[NanoReader_.GenPart_genPartIdxMother[GENPartCount]];

                    bool isPrompt = (NanoReader_.GenPart_statusFlags[i] >> 0  & 1 );
                    bool isHardProcess = (NanoReader_.GenPart_statusFlags[i] >> 7  & 1 );
                    bool isFromHardProcess = (NanoReader_.GenPart_statusFlags[i] >> 8  & 1 );
                    bool isFromHardProcessBeforeFSR = (NanoReader_.GenPart_statusFlags[i] >> 11  & 1 );
                    // if (NanoReader_.GenPart_statusFlags[i] >> 0  & 1 ) std::cout << "Status Flags is Prompt "  << std::endl;
                    // if (NanoReader_.GenPart_statusFlags[i] >> 7  & 1 ) std::cout << "Status Flags is HardProcess "  << std::endl;
                    // if (NanoReader_.GenPart_statusFlags[i] >> 8  & 1 ) std::cout << "Status Flags is from HardProcess "  << std::endl;
                    // if (NanoReader_.GenPart_statusFlags[i] >> 11 & 1 ) std::cout << "Status Flags is from HardProcessBeforeFSR "  << std::endl;

                    // Get Higgs bosons
                    if (pdgid == 25 && status == 22)
                    {
                        // std::cout << "\tEvent No. " << i << "/" << lineCount << ":\tHiggs: pdgID: " << pdgid
                                //   << "\tstatus: " << status << "\tMother pdgID: " <<  motherPDGid
                                //   << "\tpT: " << NanoReader_.GenPart_pt[GENPartCount] << std::endl;
                        LV_GEN_Higgs.push_back(TLorentzVector(0,0,0,0));
                        LV_GEN_Higgs.back().SetPtEtaPhiM(NanoReader_.GenPart_pt[GENPartCount],
                                                           NanoReader_.GenPart_eta[GENPartCount],
                                                           NanoReader_.GenPart_phi[GENPartCount],
                                                           NanoReader_.GenPart_mass[GENPartCount]);
                    }

            //         // Get GEN photons
            //         // status 1 and 23 => final state particles
            //         // check status code here: http://th-www.if.uj.edu.pl/~erichter/TauAnalFrame/external/pythia8185/htmldoc/ParticleProperties.html
                    // if (abs(pdgid) == 23 && (status==1 || status == 23) && motherPDGid==25)
                    if (abs(pdgid) == 23 && motherPDGid==25)
                    {
                        // std::cout << "Event No. " << i << "/" << lineCount << ":\tpdgID: " << pdgid
                                //   << "\tstatus: " << status << "\tMother pdgID: " <<  motherPDGid
                                //   <<  std::endl;

                        LV_GEN_ZBosons.push_back(TLorentzVector(0,0,0,0));
                        LV_GEN_ZBosons.back().SetPtEtaPhiM(NanoReader_.GenPart_pt[GENPartCount],
                                                           NanoReader_.GenPart_eta[GENPartCount],
                                                           NanoReader_.GenPart_phi[GENPartCount],
                                                           NanoReader_.GenPart_mass[GENPartCount]);
                    }

            //         // Get W-bosons from Higgs
            //         if (abs(pdgid) == 24 && motherPDGid == 25)
            //         {
            //             // std::cout << "\tEvent No. " << i << "/" << lineCount << ":\tWBoson: pdgID: " << pdgid
            //                       // << "\tstatus: " << status << "\tMother pdgID: " <<  motherPDGid
            //                       // << "\tpT: " << NanoReader_.GenPart_pt[GENPartCount] << std::endl;
            //             LV_GEN_WBosons.push_back(TLorentzVector(0,0,0,0));
            //             LV_GEN_WBosons.back().SetPtEtaPhiM(NanoReader_.GenPart_pt[GENPartCount],
            //                                                NanoReader_.GenPart_eta[GENPartCount],
            //                                                NanoReader_.GenPart_phi[GENPartCount],
            //                                                NanoReader_.GenPart_mass[GENPartCount]);
            //         }

            //         // Get quarks coming from W-bosons and should be final state particles
            //         // status = 23 => final state particles
                    if (abs(pdgid) <= 6 && abs(motherPDGid) == 23 && status == 23 )
                    {
                        // std::cout << "\tEvent No. " << i << "/" << lineCount << ":\tQuarks: pdgID: " << pdgid
                                //   << "\tstatus: " << status << "\tMother pdgID: " <<  motherPDGid
                                //   << "\tpT: " << NanoReader_.GenPart_pt[GENPartCount] << std::endl;
                        CountEvents++;
                        LV_GEN_quarks.push_back(TLorentzVector(0,0,0,0));
                        LV_GEN_quarks.back().SetPtEtaPhiM(NanoReader_.GenPart_pt[GENPartCount],
                                                           NanoReader_.GenPart_eta[GENPartCount],
                                                           NanoReader_.GenPart_phi[GENPartCount],
                                                           NanoReader_.GenPart_mass[GENPartCount]);
                    }

                    if (abs(pdgid) <= 6 && abs(motherPDGid) != 23 && status == 23  && isHardProcess)
                    {
                        std::cout << "\tEvent No. " << i << "/" << lineCount << ":\tQuarks: pdgID: " << pdgid
                                  << "\tstatus: " << status << "\tMother pdgID: " <<  motherPDGid
                                  << "\tisPrompt " << isPrompt << "\tisHardProcess " << isHardProcess
                                  << "\tisFromHardProcess " << isFromHardProcess << "\tisFromHardProcessBeforeFSR " << isFromHardProcessBeforeFSR
                                //   << "\tpT: " << NanoReader_.GenPart_pt[GENPartCount]
                                  << std::endl;
                        // CountEvents++;
                        LV_GEN_VBFquarks.push_back(TLorentzVector(0,0,0,0));
                        LV_GEN_VBFquarks.back().SetPtEtaPhiM(NanoReader_.GenPart_pt[GENPartCount],
                                                           NanoReader_.GenPart_eta[GENPartCount],
                                                           NanoReader_.GenPart_phi[GENPartCount],
                                                           NanoReader_.GenPart_mass[GENPartCount]);
                    }
                }
                if (LV_GEN_ZBosons.size() != 2)
                {
                    std::cout << "Z-boson size = " << LV_GEN_ZBosons.size() << std::endl;
                    std::cout << "GEN Z-boson are more than 2. Please check..." << std::endl;
                    exit(0);
                }
                if (LV_GEN_Higgs.size() != 1)
                {
                    std::cout << "Higgs size = " << LV_GEN_Higgs.size() << std::endl;
                    std::cout << "GEN Higgs not 1. Please check..." << std::endl;
                    exit(0);
                }
            //     if (LV_GEN_WBosons.size()>2)
            //     {
            //         std::cout << "W-Bosons size = " << LV_GEN_WBosons.size() << std::endl;
            //         std::cout << "GEN W-Bosons are more than 2. Please check..." << std::endl;
            //         exit(0);
            //     }
                if (LV_GEN_quarks.size() != 2)
                {
                    std::cout << "Z-Quarks size = " << LV_GEN_quarks.size() << std::endl;
                    std::cout << "GEN Z-Quarks is not 2. Please check..." << std::endl;
                    exit(0);
                }
                if (LV_GEN_VBFquarks.size() > 2)
                {
                    std::cout << "VBF-Quarks size = " << LV_GEN_quarks.size() << std::endl;
                    std::cout << "GEN VBF-Quarks is not 2. Please check..." << std::endl;
                    exit(0);
                }
            }

            // TLorentzVector LV_GEN_HiggsGG(0,0,0,0);
            // TLorentzVector LV_GEN_HiggsWW(0,0,0,0);
            // LV_GEN_HiggsGG = LV_GEN_ZBosons[0] + LV_GEN_ZBosons[1];
            // LV_GEN_HiggsWW = LV_GEN_WBosons[0] + LV_GEN_WBosons[1];
            // WVJJTree->LHEGEN_deltaR_HToGGH = TMath::Min(deltaR(LV_LHE_Higgs[0].Eta(),LV_LHE_Higgs[0].Phi(),LV_GEN_HiggsGG.Eta(),LV_GEN_HiggsGG.Phi()),
            //                                         deltaR(LV_LHE_Higgs[1].Eta(),LV_LHE_Higgs[1].Phi(),LV_GEN_HiggsGG.Eta(),LV_GEN_HiggsGG.Phi()));
            // WVJJTree->LHEGEN_deltaR_HToWWH = TMath::Min(deltaR(LV_LHE_Higgs[0].Eta(),LV_LHE_Higgs[0].Phi(),LV_GEN_HiggsWW.Eta(),LV_GEN_HiggsWW.Phi()),
            //                                         deltaR(LV_LHE_Higgs[1].Eta(),LV_LHE_Higgs[1].Phi(),LV_GEN_HiggsWW.Eta(),LV_GEN_HiggsWW.Phi()));

            // // Save pT, eta, phi and mass of LV_GEN_ZBosons[0] in output Tree
            // // Save pT, eta, phi and mass of LV_GEN_ZBosons[1] in output Tree
            // WVJJTree->GEN_LeadingPhoton_pT = LV_GEN_ZBosons[0].Pt();
            // WVJJTree->GEN_LeadingPhoton_eta = LV_GEN_ZBosons[0].Eta();
            // WVJJTree->GEN_LeadingPhoton_phi = LV_GEN_ZBosons[0].Phi();
            // WVJJTree->GEN_LeadingPhoton_energy = LV_GEN_ZBosons[0].E();
            // WVJJTree->GEN_LeadingPhoton_mass = LV_GEN_ZBosons[0].M();

            // WVJJTree->GEN_SubLeadingPhoton_pT = LV_GEN_ZBosons[1].Pt();
            // WVJJTree->GEN_SubLeadingPhoton_eta = LV_GEN_ZBosons[1].Eta();
            // WVJJTree->GEN_SubLeadingPhoton_phi = LV_GEN_ZBosons[1].Phi();
            // WVJJTree->GEN_SubLeadingPhoton_energy = LV_GEN_ZBosons[1].E();
            // WVJJTree->GEN_SubLeadingPhoton_mass = LV_GEN_ZBosons[1].M();

            // // Save pT, eta, phi and mass of LV_GEN_quarks[0] in output Tree
            // // Save pT, eta, phi and mass of LV_GEN_quarks[1] in output Tree
            // // Save pT, eta, phi and mass of LV_GEN_quarks[2] in output Tree
            // // Save pT, eta, phi and mass of LV_GEN_quarks[3] in output Tree

            // WVJJTree->GEN_Q1_pT = LV_GEN_quarks[0].Pt();
            // WVJJTree->GEN_Q1_eta = LV_GEN_quarks[0].Eta();
            // WVJJTree->GEN_Q1_phi = LV_GEN_quarks[0].Phi();
            // WVJJTree->GEN_Q1_energy = LV_GEN_quarks[0].E();
            // WVJJTree->GEN_Q1_mass = LV_GEN_quarks[0].M();

            // WVJJTree->GEN_Q2_pT = LV_GEN_quarks[1].Pt();
            // WVJJTree->GEN_Q2_eta = LV_GEN_quarks[1].Eta();
            // WVJJTree->GEN_Q2_phi = LV_GEN_quarks[1].Phi();
            // WVJJTree->GEN_Q2_energy = LV_GEN_quarks[1].E();
            // WVJJTree->GEN_Q2_mass = LV_GEN_quarks[1].M();

            // WVJJTree->GEN_Q3_pT = LV_GEN_quarks[2].Pt();
            // WVJJTree->GEN_Q3_eta = LV_GEN_quarks[2].Eta();
            // WVJJTree->GEN_Q3_phi = LV_GEN_quarks[2].Phi();
            // WVJJTree->GEN_Q3_energy = LV_GEN_quarks[2].E();
            // WVJJTree->GEN_Q3_mass = LV_GEN_quarks[2].M();

            // WVJJTree->GEN_Q4_pT = LV_GEN_quarks[3].Pt();
            // WVJJTree->GEN_Q4_eta = LV_GEN_quarks[3].Eta();
            // WVJJTree->GEN_Q4_phi = LV_GEN_quarks[3].Phi();
            // WVJJTree->GEN_Q4_energy = LV_GEN_quarks[3].E();
            // WVJJTree->GEN_Q4_mass = LV_GEN_quarks[3].M();

            // // Save pT, eta, phi and mass of LV_GEN_WBosons[0] in output Tree
            // // Save pT, eta, phi and mass of LV_GEN_WBosons[1] in output Tree

            // WVJJTree->GEN_W1_pT = LV_GEN_WBosons[0].Pt();
            // WVJJTree->GEN_W1_eta = LV_GEN_WBosons[0].Eta();
            // WVJJTree->GEN_W1_phi = LV_GEN_WBosons[0].Phi();
            // WVJJTree->GEN_W1_energy = LV_GEN_WBosons[0].E();
            // WVJJTree->GEN_W1_mass = LV_GEN_WBosons[0].M();

            // WVJJTree->GEN_W2_pT = LV_GEN_WBosons[1].Pt();
            // WVJJTree->GEN_W2_eta = LV_GEN_WBosons[1].Eta();
            // WVJJTree->GEN_W2_phi = LV_GEN_WBosons[1].Phi();
            // WVJJTree->GEN_W2_energy = LV_GEN_WBosons[1].E();
            // WVJJTree->GEN_W2_mass = LV_GEN_WBosons[1].M();

            // // Save pT, eta, phi and mass of LV_GEN_Higgs[0] in output Tree
            // // Save pT, eta, phi and mass of LV_GEN_Higgs[1] in output Tree
            // WVJJTree->GEN_H1_pT = LV_GEN_Higgs[0].Pt();
            // WVJJTree->GEN_H1_eta = LV_GEN_Higgs[0].Eta();
            // WVJJTree->GEN_H1_phi = LV_GEN_Higgs[0].Phi();
            // WVJJTree->GEN_H1_energy = LV_GEN_Higgs[0].E();
            // WVJJTree->GEN_H1_mass = LV_GEN_Higgs[0].M();

            // WVJJTree->GEN_H2_pT = LV_GEN_Higgs[1].Pt();
            // WVJJTree->GEN_H2_eta = LV_GEN_Higgs[1].Eta();
            // WVJJTree->GEN_H2_phi = LV_GEN_Higgs[1].Phi();
            // WVJJTree->GEN_H2_energy = LV_GEN_Higgs[1].E();
            // WVJJTree->GEN_H2_mass = LV_GEN_Higgs[1].M();

            // WVJJTree->GEN_deltaR_HH = deltaR(LV_GEN_Higgs[0],LV_GEN_Higgs[1]);
            // WVJJTree->GEN_deltaEta_HH = LV_GEN_Higgs[0].Eta() - LV_GEN_Higgs[1].Eta();
            // WVJJTree->GEN_deltaPhi_HH = deltaPhi(LV_GEN_Higgs[0],LV_GEN_Higgs[1]);

            // WVJJTree->GEN_HWW_pT = (LV_GEN_WBosons[0]+LV_GEN_WBosons[1]).Pt();
            // WVJJTree->GEN_HWW_eta = (LV_GEN_WBosons[0]+LV_GEN_WBosons[1]).Eta();
            // WVJJTree->GEN_HWW_phi = (LV_GEN_WBosons[0]+LV_GEN_WBosons[1]).Phi();
            // WVJJTree->GEN_HWW_energy = (LV_GEN_WBosons[0]+LV_GEN_WBosons[1]).E();
            // WVJJTree->GEN_HWW_mass = (LV_GEN_WBosons[0]+LV_GEN_WBosons[1]).M();

            // WVJJTree->GEN_HGG_pT = (LV_GEN_ZBosons[1]+LV_GEN_ZBosons[0]).Pt();
            // WVJJTree->GEN_HGG_eta = (LV_GEN_ZBosons[1]+LV_GEN_ZBosons[0]).Eta();
            // WVJJTree->GEN_HGG_phi = (LV_GEN_ZBosons[1]+LV_GEN_ZBosons[0]).Phi();
            // WVJJTree->GEN_HGG_energy = (LV_GEN_ZBosons[1]+LV_GEN_ZBosons[0]).E();
            // WVJJTree->GEN_HGG_mass = (LV_GEN_ZBosons[1]+LV_GEN_ZBosons[0]).M();





            if (isMC==1) {
                WVJJTree->nScaleWeight = *NanoReader_.nLHEScaleWeight;
                WVJJTree->nPdfWeight = *NanoReader_.nLHEPdfWeight;

                for (uint j=0; j<WVJJTree->nScaleWeight; j++) {
                    //LHE scale variation weights (w_var / w_nominal); [0] is MUR="0.5" MUF="0.5";
                    //[1] is MUR="0.5" MUF="1.0"; [2] is MUR="0.5" MUF="2.0"; [3] is MUR="1.0" MUF="0.5";
                    //[4] is MUR="1.0" MUF="2.0"; [5] is MUR="2.0" MUF="0.5"; [6] is MUR="2.0" MUF="1.0";
                    //[7] is MUR="2.0" MUF="2.0"
                    WVJJTree->scaleWeight[j]=NanoReader_.LHEScaleWeight[j];
                }
                for (uint j=0; j<WVJJTree->nPdfWeight; j++) {
                    //LHE pdf variation weights (w_var / w_nominal) for LHA IDs 91400 - 91432
                    WVJJTree->pdfWeight[j]=NanoReader_.LHEPdfWeight[j];
                }

                // tZq events in ZV signal sample
                if ( (NanoReader_.GenPart_genPartIdxMother[2] == 0 && abs(NanoReader_.GenPart_pdgId[2]) == 6)
                    || (NanoReader_.GenPart_genPartIdxMother[3] == 0 && abs(NanoReader_.GenPart_pdgId[3]) == 6)
                    ) {
                    WVJJTree->is_tZq = true;
                }
                //std::cout<<abs(NanoReader_.GenPart_pdgId[2])<< " " << WVJJTree->is_tZq << std::endl;
            }

            if (isMC==1 && *NanoReader_.nLHEReweightingWeight!=0) {
                WVJJTree->nAqgcWeight=*NanoReader_.nLHEReweightingWeight;

                for (uint j=0; j<WVJJTree->nAqgcWeight; j++) {
                    WVJJTree->aqgcWeight[j]=NanoReader_.LHEReweightingWeight[j];
                }

            }

            if (isMC) {
                //if (era==2016) {
                //  WVJJTree->btagWeight = *NanoReader_.btagWeight_CMVA;
                //}
                //else {
                //  WVJJTree->btagWeight = *NanoReader_.btagWeight_DeepCSVB;
                //}

                if (era!=2018) {
                    WVJJTree->L1PFWeight = *NanoReader_.L1PreFiringWeight_Nom;
                    WVJJTree->L1PFWeight_Up = *NanoReader_.L1PreFiringWeight_Up;
                    WVJJTree->L1PFWeight_Down = *NanoReader_.L1PreFiringWeight_Dn;
                }
            }

            ot->Fill();
        }

        delete t;
        delete r;
        delete f;
        //t=0;
        //r=0;
        //f=0;
    }

    of->Write();
    of->Close();
    TString removeCommand = TString("rm -rf ") + TString(dir_name);
    std::cout << "Delete the temp directory: " << removeCommand << std::endl;
    system((std::string(removeCommand)).c_str());

    return 0;

}
