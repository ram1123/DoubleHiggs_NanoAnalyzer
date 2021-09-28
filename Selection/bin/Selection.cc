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

    const float H_MASS = 125.10;

    // const float W_MASS = 80.379;
    // const float Z_MASS = 91.1876;
    const float V_MASS = 85.7863;

    const float MUON_MASS = 0.1056583745;
    const float ELE_MASS  = 0.000511;

    //lepton cuts
    const float LEP_PT_VETO_CUT = 10;
    // const float EL_PT_CUT = 10;
    const float EL_ETA_CUT = 2.5;
    // const float MU_PT_CUT = 10;
    const float MU_ETA_CUT = 2.4;

    //photon cuts
    const float PHO_ETA_CUT = 2.5;
    const float PHO_PT_VETO_CUT = 10.0;
    // const float PHO_PT_CUT = 25.0;
    const float PHO_R9_CUT = 0.8;
    const float PHOTON_PFRELISO03_CHG_CUT = 20;
    const float HOVERE_CUT = 0.08;
    const float PHO1_PT_CUT = 35;
    const float PHO2_PT_CUT = 25;
    const float PHO_MVA_ID = -0.9;

    //ak8 jet cuts
    const float AK8_HJET_MIN_PT = 300;
    const float AK8_WJET_MIN_PT = 200;
    const float AK8_MAX_ETA = 2.4;

    // Mass window cuts
    const float AK8_HJet_MIN_SDM = 90;
    const float AK8_HJet_MAX_SDM = 170;
    const float AK8_WJet_MIN_SDM = 40;
    const float AK8_WJet_MAX_SDM = 130;

    //ak4 jet cuts
    //const float AK4_PT_VETO_CUT = 20;
    // const float AK4_ETA_CUT = 2.4;
    const float AK4_PT_CUT = 25;
    const float AK4_MAX_ETA = 2.4;
    // const float AK4_JJ_MIN_M = 40.0;
    // const float AK4_JJ_MAX_M = 250.0;

    // cleaning cuts
    // To-Do: Check the cut values of jet cleaning with other jets
    const float AK8_LEP_DR_CUT = 0.8;
    const float AK4_LEP_DR_CUT = 0.8;
    const float AK8_AK8_DR_CUT = 1.6;
    const float AK4_AK8_DR_CUT = 1.2;
    const float AK4_AK4_DR_CUT = 0.8;

    // Jet sub-structure cuts
    const float TAU42 = 0.55;
    const float TAU21 = 0.55;

    // btag deepCSV a.k.a. DeepB working points
    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation94X
    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation2016Legacy
    // float btag_loose_wp = 0.0;
    // // float btag_tight_wp = 0.0;
    // // float btag_medium_wp = 0.0;
    // if (era==2018) {
    //   btag_loose_wp = 0.1241;
    //   // btag_medium_wp = 0.4184;
    //   // btag_tight_wp = 0.7527;
    // }
    // if (era==2017) {
    //   btag_loose_wp = 0.1522;
    //   // btag_medium_wp = 0.4941;
    //   // btag_tight_wp = 0.8001;
    // }
    // if (era==2016) {
    //   btag_loose_wp = 0.2217;
    //   // btag_medium_wp = 0.6321;
    //   // btag_tight_wp = 0.8953;
    // }

    ScaleFactors scaleFactor(era);

    std::vector<TLorentzVector> tightMuon;
    std::vector<TLorentzVector> tightEle;
    std::vector<TLorentzVector> tightPhoton;

    std::vector<TLorentzVector> Ak4Jets;
    // std::vector<TLorentzVector> Ak4JetsTem;
    std::vector<TLorentzVector> Ak8Jets;
    std::vector<int> goodAK4JetIndex;
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

    // Bool_t has_HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 = false;
    // Bool_t has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = false;
    // Bool_t has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = false;

    Bool_t has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 = false;
    Bool_t has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95 = false;
    Bool_t has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = false;
    Bool_t has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = false;
    Bool_t has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = false;
    Bool_t has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = false;
    Bool_t has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = false;
    Bool_t has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = false;

    // has_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ=false, has_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL=false,
    // has_HLT_DiEle27_WPTightCaloOnly_L1DoubleEG=false,
    // has_HLT_DoubleEle33_CaloIdL_MW=false, has_HLT_DoubleEle25_CaloIdL_MW=false, has_HLT_DoubleEle27_CaloIdL_MW=false;

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

    if(DEBUG) std::cout << "[INFO]: inputFile: " << inputFile << std::endl;
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
        else if (isMC && nanoVersion == 7) {
            genEventSumw = *NanoWeightReader.genEventSumw;
            genEventCount = *NanoWeightReader.genEventCount;
        }
        totalEvents->SetBinContent(2,totalEvents->GetBinContent(2)+genEventSumw);
        totalCutFlow_FH->Fill("MC Gen",genEventCount);
        totalCutFlow_FH->Fill("nEvent",genEventSumw);
        totalCutFlow_SL->Fill("MC Gen",genEventCount);
        totalCutFlow_SL->Fill("nEvent",genEventSumw);
        //check if tree has these hlt branches
        if (lineCount == 1){
            has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 = t->GetBranchStatus("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90");
            has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95 = t->GetBranchStatus("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95");
            has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55");
            has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55");
            has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55");
            has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55");
            has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55");
            has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 = t->GetBranchStatus("HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55");
        }

        if(DEBUG) std::cout << "\t[INFO]: Start of event loop. " << std::endl;
        for (uint i=0; i < t->GetEntries(); i++)
        // for (uint i=0; i < 200; i++)
        {
            WVJJTree->clearVars();
            NanoReader_.GetEntry(i);
            totalCutFlow_FH->Fill("Skim NanoAOD",1);
            totalCutFlow_SL->Fill("Skim NanoAOD",1);

            if (i%10000==0) std::cout <<"\t[INFO]: file " << lineCount << ": event " << i << std::endl;
            // if (DEBUG)       std::cout <<"\t[INFO]: file " << lineCount << ": event " << i << std::endl;

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
            // if (isMC==1)
            // {
            //     for (UInt_t LHEPartCount = 0; LHEPartCount < *NanoReader_.nLHEPart; ++LHEPartCount)
            //     {
            //         std::cout <<  "Event No. " << i << "/" << lineCount
            //                     << "\tNanoReader_.nLHEPart: pdgID = " << NanoReader_.LHEPart_pdgId[LHEPartCount]
            //                     << "\t Status = " << NanoReader_.LHEPart_status[LHEPartCount]
            //                     << "\t pT = " << NanoReader_.LHEPart_pt[LHEPartCount]
            //                     << "\t mass = " << NanoReader_.LHEPart_mass[LHEPartCount] << std::endl;
            //         // To-Do:
            //         // Grab Higgs with status 1 and fill it in branch:
            //         // branch name: LHE_Leading_Higgs_pT, LHE_Subleading_Higgs_pT
            //     }
            // }

            // Below part : GEN information
            //              This contains information of the Higgs decays and after shower effects.
            //
            // if (isMC==1)
            // {
            //     for (UInt_t LHEPartCount = 0; LHEPartCount < *NanoReader_.nGenPart; ++LHEPartCount)
            //     {
            //         // if ((NanoReader_.GenPart_statusFlags[i] >> 0  & 1) && (NanoReader_.GenPart_statusFlags[i] >> 7  & 1)  && (abs(NanoReader_.GenPart_pdgId[LHEPartCount]) == 24) && (NanoReader_.GenPart_status[LHEPartCount]==22))
            //         // if (
            //         //     (
            //         //     (NanoReader_.GenPart_statusFlags[i] >> 0  & 1) ||   // "Status Flags is Prompt "
            //         //     (NanoReader_.GenPart_statusFlags[i] >> 7  & 1) ||   // "Status Flags is HardProcess "
            //         //     (NanoReader_.GenPart_statusFlags[i] >> 8  & 1) ||   // "Status Flags is from HardProcess "
            //         //     (NanoReader_.GenPart_statusFlags[i] >> 11  & 1)     // "Status Flags is from HardProcessBeforeFSR "
            //         //     ) &&
            //         //     (abs(NanoReader_.GenPart_pdgId[LHEPartCount]) == 25))
            //         // {
            //         //     std::cout << "Event No. " << i << "/" << lineCount
            //         //               << ":\tNanoReader_.nGenPart = " << NanoReader_.GenPart_pdgId[LHEPartCount]
            //         //               << "\t" << NanoReader_.GenPart_status[LHEPartCount]
            //         //               << "\t" <<  NanoReader_.GenPart_pdgId[NanoReader_.GenPart_genPartIdxMother[LHEPartCount]]
            //         //               <<  std::endl;
            //         // }

            //         if (NanoReader_.GenPart_status[LHEPartCount] == 22 &&
            //             abs(NanoReader_.GenPart_pdgId[LHEPartCount]) == 24)
            //         {
            //             std::cout << "Event No. " << i << "/" << lineCount
            //                       << ":\tNanoReader_.nGenPart = " << NanoReader_.GenPart_pdgId[LHEPartCount]
            //                       << "\t" << NanoReader_.GenPart_status[LHEPartCount]
            //                       << "\t" <<  NanoReader_.GenPart_pdgId[NanoReader_.GenPart_genPartIdxMother[LHEPartCount]]
            //                       <<  std::endl;
            //         }
            //         // if (NanoReader_.GenPart_statusFlags[i] >> 0  & 1 ) std::cout << "Status Flags is Prompt "  << std::endl;
            //         // if (NanoReader_.GenPart_statusFlags[i] >> 7  & 1 ) std::cout << "Status Flags is HardProcess "  << std::endl;
            //         // if (NanoReader_.GenPart_statusFlags[i] >> 8  & 1 ) std::cout << "Status Flags is from HardProcess "  << std::endl;
            //         // if (NanoReader_.GenPart_statusFlags[i] >> 11 & 1 ) std::cout << "Status Flags is from HardProcessBeforeFSR "  << std::endl;
            //     }
            // }
            // exit(0);
            // continue;
            // filtering out particular event for sync
            //if (!(*NanoReader_.event==3073090041)) {
            //  continue;
            //}
            //std::cout << *NanoReader_.run << " " << *NanoReader_.event << std::endl;


            WVJJTree->trigger_2Pho = (
                                      (has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 ? *NanoReader_.HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 : 0) ||
                                      (has_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95 ? *NanoReader_.HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95 : 0) ||
                                      (has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 : 0) ||
                                      (has_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 : 0) ||
                                      (has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 : 0) ||
                                      (has_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 : 0) ||
                                      (has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55 : 0) ||
                                      (has_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 ? *NanoReader_.HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55 : 0)
                                      );

            //std::cout << "passed trigger: ";
            //if (WVJJTree->trigger_1Mu) std::cout << "1 muon ";
            //if (WVJJTree->trigger_2Mu) std::cout << "2 muon ";
            //if (WVJJTree->trigger_1El) std::cout << "1 ele ";
            //if (WVJJTree->trigger_2El) std::cout << "2 ele ";
            // if (DEBUG)
            // {
            //   if (WVJJTree->trigger_2Pho) std::cout << "\t[INFO] 2 photon trigger passed." << std::endl;
            //   else std::cout << "\t[INFO] 2 photon trigger not passed." << std::endl;
            // }
            //std::cout << std::endl;

            // if (!(WVJJTree->trigger_2Pho)) continue;
            // totalCutFlow_FH->Fill("Trigger",1);
            // totalCutFlow_SL->Fill("Trigger",1);
            if (WVJJTree->trigger_2Pho) totalCutFlow_FH->Fill("Trigger",1);
            if (WVJJTree->trigger_2Pho) totalCutFlow_SL->Fill("Trigger",1);

            /* -------------------------------------------------------------------------- */
            /*                              PHOTON SELECTION                              */
            /* -------------------------------------------------------------------------- */
            tightPhoton.clear();
            int nTightPhoton = 0;

            if (*NanoReader_.nPhoton < 2) continue;
            for (UInt_t PhotonCount = 0; PhotonCount < *NanoReader_.nPhoton; ++PhotonCount)
            {
                if (!(NanoReader_.Photon_r9[PhotonCount] > PHO_R9_CUT || (NanoReader_.Photon_pfRelIso03_chg[PhotonCount]*NanoReader_.Photon_pt[PhotonCount]) < PHOTON_PFRELISO03_CHG_CUT || NanoReader_.Photon_pfRelIso03_chg[PhotonCount] < 0.3)) continue;
                if (!(NanoReader_.Photon_hoe[PhotonCount] < HOVERE_CUT)) continue;
                if (!(NanoReader_.Photon_pt[PhotonCount] > PHO_PT_VETO_CUT)) continue;
                if (!(abs(NanoReader_.Photon_eta[PhotonCount]) < PHO_ETA_CUT )) continue;
                if (!(NanoReader_.Photon_isScEtaEB[PhotonCount] || NanoReader_.Photon_isScEtaEE[PhotonCount])) continue;
                if (!(NanoReader_.Photon_mvaID[PhotonCount] > PHO_MVA_ID)) continue;
                nTightPhoton++;

                /* ----------- push pt,eta,phi,ecorr in the TightPhoton last index ---------- */
                tightPhoton.push_back(TLorentzVector(0,0,0,0));
                tightPhoton.back().SetPtEtaPhiE( NanoReader_.Photon_pt[PhotonCount],
                                                NanoReader_.Photon_eta[PhotonCount],
                                                NanoReader_.Photon_phi[PhotonCount],
                                                NanoReader_.Photon_eCorr[PhotonCount]
                                                );
                /* ------- sort and Leading_photon -> pho1  SubLeading_photon -> pho2  ------- */
                if ( NanoReader_.Photon_pt[PhotonCount] > WVJJTree->pho1_pt ) {
                    WVJJTree->pho2_pt = WVJJTree->pho1_pt;
                    WVJJTree->pho2_eta = WVJJTree->pho1_eta;
                    WVJJTree->pho2_phi = WVJJTree->pho1_phi;
                    WVJJTree->pho2_m = WVJJTree->pho1_m;
                    WVJJTree->pho2_iso = WVJJTree->pho1_iso;
                    WVJJTree->pho2_q = WVJJTree->pho1_q;
                    WVJJTree->pho2_mvaIDFall17V2 = WVJJTree->pho1_mvaIDFall17V2;
                    WVJJTree->pho2_mvaIDFall17V1 = WVJJTree->pho1_mvaIDFall17V1;
                    WVJJTree->pho2_mvaID_WP80 = WVJJTree->pho1_mvaID_WP80;
                    WVJJTree->pho2_mvaID_WP90 = WVJJTree->pho1_mvaID_WP90;


                    WVJJTree->pho1_pt = NanoReader_.Photon_pt[PhotonCount];
                    WVJJTree->pho1_eta = NanoReader_.Photon_eta[PhotonCount];
                    WVJJTree->pho1_phi = NanoReader_.Photon_phi[PhotonCount];
                    WVJJTree->pho1_m = NanoReader_.Photon_mass[PhotonCount];
                    WVJJTree->pho1_iso = NanoReader_.Photon_pfRelIso03_all[PhotonCount];
                    WVJJTree->pho1_q = NanoReader_.Photon_charge[PhotonCount];
                    WVJJTree->pho1_mvaIDFall17V2 = NanoReader_.Photon_mvaID[PhotonCount];
                    WVJJTree->pho1_mvaIDFall17V1 = NanoReader_.Photon_mvaID_Fall17V1p1[PhotonCount];
                    WVJJTree->pho1_mvaID_WP80 = NanoReader_.Photon_mvaID_WP80[PhotonCount];
                    WVJJTree->pho1_mvaID_WP90 = NanoReader_.Photon_mvaID_WP90[PhotonCount];
                }
                else if ( NanoReader_.Photon_pt[PhotonCount] > WVJJTree->pho2_pt ) {
                    WVJJTree->pho2_pt = NanoReader_.Photon_pt[PhotonCount];
                    WVJJTree->pho2_eta = NanoReader_.Photon_eta[PhotonCount];
                    WVJJTree->pho2_phi = NanoReader_.Photon_phi[PhotonCount];
                    WVJJTree->pho2_m = NanoReader_.Photon_mass[PhotonCount];
                    WVJJTree->pho2_iso = NanoReader_.Photon_pfRelIso03_all[PhotonCount];
                    WVJJTree->pho2_q = NanoReader_.Photon_charge[PhotonCount];
                    WVJJTree->pho2_mvaIDFall17V2 = NanoReader_.Photon_mvaID[PhotonCount];
                    WVJJTree->pho2_mvaIDFall17V1 = NanoReader_.Photon_mvaID_Fall17V1p1[PhotonCount];
                    WVJJTree->pho2_mvaID_WP80 = NanoReader_.Photon_mvaID_WP80[PhotonCount];
                    WVJJTree->pho2_mvaID_WP90 = NanoReader_.Photon_mvaID_WP90[PhotonCount];
                }
            }
            /* ----------------- Leading and SubLeading photon selection ---------------- */

            if (!(nTightPhoton==2)) continue;
            if(!(WVJJTree->pho1_pt > PHO1_PT_CUT)) continue;
            if(!(WVJJTree->pho2_pt > PHO2_PT_CUT)) continue;

            totalCutFlow_FH->Fill("Photon Selection",1);
            totalCutFlow_SL->Fill("Photon Selection",1);


            // std::cout << "Exactly 2 photons found..." << std::endl;

            /* -------------------------------------------------------------------------- */
            /*                             photon m,pt,eta,phi                            */
            /* -------------------------------------------------------------------------- */
            TLorentzVector LV_pho1(0,0,0,0);
            LV_pho1.SetPtEtaPhiM( WVJJTree->pho1_pt, WVJJTree->pho1_eta, WVJJTree->pho1_phi, WVJJTree->pho1_m );

            TLorentzVector LV_pho2(0,0,0,0);
            LV_pho2.SetPtEtaPhiM( WVJJTree->pho2_pt, WVJJTree->pho2_eta, WVJJTree->pho2_phi, WVJJTree->pho2_m );

            TLorentzVector diphoton = LV_pho1+LV_pho2;

            WVJJTree->diphoton_m = diphoton.M();
            WVJJTree->diphoton_pt = diphoton.Pt();
            WVJJTree->diphoton_eta = diphoton.Eta();
            WVJJTree->diphoton_phi = diphoton.Phi();
            WVJJTree->diphoton_E = diphoton.E();
            WVJJTree->pho1_E = LV_pho1.E();
            WVJJTree->pho2_E = LV_pho2.E();
            WVJJTree->pho1_pt_byMgg = LV_pho1.Pt()/diphoton.M();
            WVJJTree->pho2_pt_byMgg = LV_pho1.Pt()/diphoton.M();
            WVJJTree->pho1_E_byMgg = LV_pho2.E()/diphoton.M();
            WVJJTree->pho2_E_byMgg = LV_pho2.E()/diphoton.M();

            // if(!(WVJJTree->pho1_pt_byMgg > 0.35)) continue;
            // if(!(WVJJTree->pho2_pt_byMgg > 0.25)) continue;

            // if(WVJJTree->diphoton_pt > 100.0) totalCutFlow_FH->Fill("pT(#gamma #gamma)>100",1);
            // if(WVJJTree->diphoton_pt > 100.0) totalCutFlow_SL->Fill("pT(#gamma #gamma)>100",1./totalCutFlow_SL);

            // LEPTON SELECTION
            /* -------------------------------------------------------------------------- */
            /*                      ele and muon Selection                                */
            /*             no electron and muon in fullyHadronic                          */
            /* -------------------------------------------------------------------------- */
            tightMuon.clear();
            tightEle.clear();
            int nTightEle = 0;
            int nTightMu = 0;

            // if(DEBUG) std::cout << "[INFO]: nMuon: " << *NanoReader_.nMuon << std::endl;
            // if(DEBUG) std::cout << "[INFO]: nElectron: " << *NanoReader_.nElectron << std::endl;

            for (uint j=0; j < *NanoReader_.nMuon; j++) {
                if ( NanoReader_.Muon_pt[j] < LEP_PT_VETO_CUT ) continue;
                if ( abs(NanoReader_.Muon_eta[j]) > MU_ETA_CUT ) continue;

                // cut-based ID, tight WP
                if ( ! NanoReader_.Muon_tightId[j] ) continue;

                // MiniIso ID from miniAOD selector (1=MiniIsoLoose, 2=MiniIsoMedium, 3=MiniIsoTight, 4=MiniIsoVeryTight)
                if ( ! (NanoReader_.Muon_miniIsoId[j] > 2) ) continue;

                if (DEBUG) std::cout << "\t[INFO::Muons] [" << i <<"/" << lineCount << "] Clean Muons with photons" << std::endl;

                bool isClean=true;
                for ( std::size_t k=0; k<tightPhoton.size(); k++) {
                    if (deltaR(tightPhoton.at(k).Eta(), tightPhoton.at(k).Phi(),
                               NanoReader_.Muon_eta[j], NanoReader_.Muon_phi[j]) < 0.4) {
                        isClean = false;
                    }
                }
                if ( isClean == false ) continue;

                TLorentzVector Mu(0,0,0,0);
                // Mu.SetPtEtaPhiM( NanoReader_.Muon_pt[j], NanoReader_.Muon_eta[j], NanoReader_.Muon_phi[j], NanoReader_.Muon_mass[j] );
                Mu.SetPtEtaPhiM( NanoReader_.Muon_pt[j], NanoReader_.Muon_eta[j], NanoReader_.Muon_phi[j], MUON_MASS );

                // Electron and photon should not give the Z-mass
                if( fabs((Mu+LV_pho1).M() - 91.187) < 5.0) continue;
                if( fabs((Mu+LV_pho2).M() - 91.187) < 5.0) continue;

                nTightMu++;
            }

            for ( uint j=0; j < *NanoReader_.nElectron; j++ ) {

                if ( NanoReader_.Electron_pt[j] < LEP_PT_VETO_CUT ) continue;
                if ( abs(NanoReader_.Electron_eta[j]) > EL_ETA_CUT ) continue;
                if ( NanoReader_.Electron_convVeto[j] == false) continue;

                // cut-based ID (0:fail, 1:veto, 2:loose, 3:medium, 4:tight)
                // Veto, 2016 -> cutbased HLT safe
                // 2017, 2018 -> cutbased loost Fall17V2
                if ( era == 2016 ) {
                    if ( NanoReader_.Electron_cutBased_HLTPreSel[j] == 0 ) continue;
                    // if ( NanoReader_.Electron_lostHits[j] >= 1 ) continue;
                }
                else {
                    if ( NanoReader_.Electron_cutBased[j] < 2 ) continue;
                    // if ( NanoReader_.Electron_convVeto[j] != 1) continue;
                    // for 2017, 2018
                    // if ( abs(NanoReader_.Electron_eta[j]) > 1.479 ) {
                    // if (abs(NanoReader_.Electron_sieie[j]) > 0.03 ) continue;
                    // if (abs(NanoReader_.Electron_eInvMinusPInv[j]) > 0.014 ) continue;
                    // }
                }
                bool isClean=true;
                for ( std::size_t k=0; k<tightPhoton.size(); k++) {
                    if (deltaR(tightPhoton.at(k).Eta(), tightPhoton.at(k).Phi(),
                               NanoReader_.Electron_eta[j], NanoReader_.Electron_phi[j]) < 0.4) {
                        isClean = false;
                    }
                }
                if ( isClean == false ) continue;

                TLorentzVector Ele(0,0,0,0);
                // Ele.SetPtEtaPhiM( NanoReader_.Electron_pt[j], NanoReader_.Electron_eta[j], NanoReader_.Electron_phi[j], NanoReader_.Electron_mass[j] );
                Ele.SetPtEtaPhiM( NanoReader_.Electron_pt[j], NanoReader_.Electron_eta[j], NanoReader_.Electron_phi[j], ELE_MASS );

                // Electron and photon should not give the Z-mass
                if( fabs((Ele+LV_pho1).M() - 91.187) < 5.0) continue;
                if( fabs((Ele+LV_pho2).M() - 91.187) < 5.0) continue;

                nTightEle++;
            }

            // if (DEBUG) std::cout << "\t[INFO] Number of leptons: " << nTightEle + nTightMu << std::endl;

            if (nTightMu + nTightEle > 0) continue;
            if (nTightMu + nTightEle == 0) totalCutFlow_FH->Fill("Lepton Selection",1);
            if (nTightMu + nTightEle == 1) totalCutFlow_SL->Fill("Lepton Selection",1);


            /* -------------------------------------------------------------------------- */
            /*                                   AK8Jet   Higgs Jet                       */
            /* -------------------------------------------------------------------------- */
            // AK8
            goodHJetIndex.clear();
            float dmV = 0.0;
            int nGood_Higgs_FatJet = 0;
            // int fj_idx = -1;

            for (uint j=0; j<*NanoReader_.nFatJet; j++)
            {
                if ( fabs(NanoReader_.FatJet_eta[j]) > AK8_MAX_ETA ) continue;
                if ( NanoReader_.FatJet_pt[j]<AK8_HJET_MIN_PT ) continue;

                if ( NanoReader_.FatJet_msoftdrop[j]<AK8_HJet_MIN_SDM ) continue;
                if ( NanoReader_.FatJet_msoftdrop[j]>AK8_HJet_MAX_SDM ) continue;

                bool isClean=true;

                //lepton cleaning
                for ( std::size_t k=0; k<tightEle.size(); k++)
                {
                    if (deltaR(tightEle.at(k).Eta(), tightEle.at(k).Phi(),
                         NanoReader_.FatJet_eta[j], NanoReader_.FatJet_phi[j]) < AK8_LEP_DR_CUT)
                    isClean = false;
                }
                for ( std::size_t k=0; k<tightMuon.size(); k++)
                {
                    if (deltaR(tightMuon.at(k).Eta(), tightMuon.at(k).Phi(),
                         NanoReader_.FatJet_eta[j], NanoReader_.FatJet_phi[j]) < AK8_LEP_DR_CUT)
                    isClean = false;
                }
                for ( std::size_t k=0; k<tightPhoton.size(); k++) {
                    if (deltaR(tightPhoton.at(k).Eta(), tightPhoton.at(k).Phi(),
                               NanoReader_.FatJet_eta[j], NanoReader_.FatJet_phi[j]) < AK8_LEP_DR_CUT) {
                        isClean = false;
                    }
                }

                if ( NanoReader_.FatJet_tau4[j]/NanoReader_.FatJet_tau2[j] > TAU42) isClean = false;

                if ( isClean == false ) continue;

                if ( nGood_Higgs_FatJet == 0 ) dmV = fabs(NanoReader_.FatJet_msoftdrop[j] - H_MASS);

                if ( fabs(NanoReader_.FatJet_msoftdrop[j] - H_MASS) > dmV ) continue;
                dmV = fabs(NanoReader_.FatJet_msoftdrop[j] - H_MASS);
                // fj_idx = j;
                nGood_Higgs_FatJet++;
                goodHJetIndex.push_back(j);
            }
            if (nGood_Higgs_FatJet>=1) totalCutFlow_FH->Fill("nAK8_Higgs >= 1",1);

            /* -------------------------------------------------------------------------- */
            /*                                   AK8Jet   W Jet                       */
            /* -------------------------------------------------------------------------- */
            // AK8
            Ak8Jets.clear();
            goodWJetIndex.clear();
            dmV = 0.0;
            int nGood_W_FatJet = 0;
            // fj_idx = -1;

            for (uint j=0; j<*NanoReader_.nFatJet; j++)
            {
                if ( fabs(NanoReader_.FatJet_eta[j]) > AK8_MAX_ETA ) continue;
                if ( NanoReader_.FatJet_pt[j]<AK8_WJET_MIN_PT ) continue;

                if ( NanoReader_.FatJet_msoftdrop[j]<AK8_WJet_MIN_SDM ) continue;
                if ( NanoReader_.FatJet_msoftdrop[j]>AK8_WJet_MAX_SDM ) continue;

                bool isClean=true;

                if ( NanoReader_.FatJet_tau2[j]/NanoReader_.FatJet_tau1[j] > TAU21) isClean = false;

                // cleaning jet from electron
                for ( std::size_t k=0; k<tightEle.size(); k++)
                {
                    if (deltaR(tightEle.at(k).Eta(), tightEle.at(k).Phi(),
                         NanoReader_.FatJet_eta[j], NanoReader_.FatJet_phi[j]) < AK8_LEP_DR_CUT)
                    isClean = false;
                }
                // cleaning jet from muons
                for ( std::size_t k=0; k<tightMuon.size(); k++)
                {
                    if (deltaR(tightMuon.at(k).Eta(), tightMuon.at(k).Phi(),
                         NanoReader_.FatJet_eta[j], NanoReader_.FatJet_phi[j]) < AK8_LEP_DR_CUT)
                    isClean = false;
                }
                // cleaning jet from photons
                for ( std::size_t k=0; k<tightPhoton.size(); k++) {
                    if (deltaR(tightPhoton.at(k).Eta(), tightPhoton.at(k).Phi(),
                               NanoReader_.FatJet_eta[j], NanoReader_.FatJet_phi[j]) < AK8_LEP_DR_CUT) {
                        isClean = false;
                    }
                }
                // cleaning fat jet with all other fat jets
                for ( std::size_t k=0; k<goodWJetIndex.size(); k++) {
                  if (deltaR(NanoReader_.FatJet_eta[goodWJetIndex.at(k)], NanoReader_.FatJet_phi[goodWJetIndex.at(k)],
                             NanoReader_.FatJet_eta[j], NanoReader_.FatJet_phi[j]) < AK8_AK8_DR_CUT) {
                    isClean = false;
                  }
                }

                if ( isClean == false ) continue;

                if ( nGood_W_FatJet == 0 ) dmV = fabs(NanoReader_.FatJet_msoftdrop[j] - V_MASS);

                if ( fabs(NanoReader_.FatJet_msoftdrop[j] - V_MASS) > dmV ) continue;
                dmV = fabs(NanoReader_.FatJet_msoftdrop[j] - V_MASS);
                // fj_idx = j;
                nGood_W_FatJet++;
                goodWJetIndex.push_back(j);
                Ak8Jets.push_back(TLorentzVector(0,0,0,0));
                Ak8Jets.back().SetPtEtaPhiM(NanoReader_.FatJet_pt[j],
                                            NanoReader_.FatJet_eta[j],
                                            NanoReader_.FatJet_phi[j],
                                            NanoReader_.FatJet_msoftdrop[j]
                                            );
            }
            // if (nGood_WLep_FatJet>=1) totalCutFlow_FH->Fill("nAK8_W >= 1",1);
            // if (nGood_WLep_FatJet>=1) totalCutFlow_SL->Fill("nAK8_W >= 1",1);

            /* -------------------------------------------------------------------------- */
            /*                                   AK4Jet                                   */
            /* -------------------------------------------------------------------------- */
            goodAK4JetIndex.clear();
            Ak4Jets.clear();

            float allAK4JetsSum_pt = 0.0;
            if (DEBUG) std::cout << "Starting AK4 jet loop" << std::endl;
            for (uint j=0; j<*NanoReader_.nJet; j++)
            {
                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] =====> JetIndex: " << j << std::endl;
                //jet energy scale variations
                if (!( NanoReader_.Jet_pt[j] > AK4_PT_CUT )) continue;
                if (!(fabs(NanoReader_.Jet_eta[j]) < AK4_MAX_ETA)) continue;
                //jet ID
                // https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookNanoAOD#Jets
                // tight jet ID
                if (!(NanoReader_.Jet_jetId[j] >= 2)) continue;
                // PU JET ID for jets pt > AK4_PT_CUT and < 50
                if (NanoReader_.Jet_pt[j] < 50 && NanoReader_.Jet_puId[j] < 3) continue;

                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] compute the btag eff." << std::endl;
                //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BTagSFMethods#1a_Event_reweighting_using_scale
                float btag_eff_loose = 1.0;
                float btag_eff_medium = 1.0;
                float btag_eff_tight = 1.0;

                bool isClean=true;

                // object cleaning
                // if (nGood_W_FatJet > 0 || nGood_Higgs_FatJet > 0)
                if (nGood_W_FatJet == 1)
                {
                    for ( std::size_t k=0; k<goodWJetIndex.size(); k++)
                    {
                        if (deltaR(NanoReader_.FatJet_eta[goodWJetIndex.at(k)], NanoReader_.FatJet_phi[goodWJetIndex.at(k)],
                             NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_AK8_DR_CUT) {
                            isClean = false;
                        }
                    }
                    // kept goodHJetIndex cleaning for future VBF study
                    for ( std::size_t k=0; k<goodHJetIndex.size(); k++)
                    {
                        if (deltaR(NanoReader_.FatJet_eta[goodHJetIndex.at(k)], NanoReader_.FatJet_phi[goodHJetIndex.at(k)],
                             NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_AK8_DR_CUT) {
                            isClean = false;
                        }
                    }
                    // kept below patch for SL category
                    // for ( std::size_t k=0; k<goodWLepJetIndex.size(); k++)
                    // {
                    //     if (deltaR(NanoReader_.FatJet_eta[goodWLepJetIndex.at(k)], NanoReader_.FatJet_phi[goodWLepJetIndex.at(k)],
                    //          NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_AK8_DR_CUT) {
                    //         isClean = false;
                    //     }
                    // }
                }

                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Clean AK4 jet with other AK4 jets" << std::endl;
                for ( std::size_t k=0; k<goodAK4JetIndex.size(); k++) {
                  if (deltaR(NanoReader_.Jet_eta[goodAK4JetIndex.at(k)], NanoReader_.Jet_phi[goodAK4JetIndex.at(k)],
                             NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_AK4_DR_CUT) {
                    isClean = false;
                  }
                }

                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Clean AK4 jet with photons jets" << std::endl;
                for ( std::size_t k=0; k<tightPhoton.size(); k++) {
                    if (deltaR(tightPhoton.at(k).Eta(), tightPhoton.at(k).Phi(),
                               NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_LEP_DR_CUT) {
                        isClean = false;
                    }
                }

                for ( std::size_t k=0; k<tightEle.size(); k++) {
                    if (deltaR(tightEle.at(k).Eta(), tightEle.at(k).Phi(),
                               NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_LEP_DR_CUT) {
                        isClean = false;
                    }
                }
                for ( std::size_t k=0; k<tightMuon.size(); k++) {
                    if (deltaR(tightMuon.at(k).Eta(), tightMuon.at(k).Phi(),
                               NanoReader_.Jet_eta[j], NanoReader_.Jet_phi[j]) < AK4_LEP_DR_CUT) {
                        isClean = false;
                    }
                }

                if ( isClean == false ) continue;
                if (NanoReader_.Jet_pt[j]>30) WVJJTree->nAK4Jet30++;
                if (NanoReader_.Jet_pt[j]>50) WVJJTree->nAK4Jet50++;

                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] AK4 jets Passed all pre-selections" << std::endl;
                if (fabs(NanoReader_.Jet_eta[j]) < 2.5) {

                    if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Within |eta|<2.5" << std::endl;
                    if (isMC) {
                        btag_eff_loose = scaleFactor.GetBtagEff(NanoReader_.Jet_hadronFlavour[j], NanoReader_.Jet_pt[j], NanoReader_.Jet_eta[j], "loose");
                        btag_eff_medium = scaleFactor.GetBtagEff(NanoReader_.Jet_hadronFlavour[j], NanoReader_.Jet_pt[j], NanoReader_.Jet_eta[j], "medium");
                        btag_eff_tight = scaleFactor.GetBtagEff(NanoReader_.Jet_hadronFlavour[j], NanoReader_.Jet_pt[j], NanoReader_.Jet_eta[j], "tight");
                    }

                    if (DEBUG) std::cout << "\t[INFO::AK4Jets] [" << i <<"/" << lineCount << "] btag_eff_loose = " << btag_eff_loose << std::endl;
                    if (DEBUG) std::cout << "\t[INFO::AK4Jets] [" << i <<"/" << lineCount << "] btag_eff_medium = " << btag_eff_medium << std::endl;
                    if (DEBUG) std::cout << "\t[INFO::AK4Jets] [" << i <<"/" << lineCount << "] btag_eff_tight  = " << btag_eff_tight << std::endl;

                    if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Got Btag SF for loose, medium and tight" << std::endl;
                    // if (NanoReader_.Jet_btagDeepB[j] > btag_loose_wp) {
                    //   WVJJTree->nAK4Btag_loose++;
                    //   if (isMC) {
                    //     WVJJTree->btagWeight_loose *= NanoReader_.Jet_btagSF_deepcsv_L[j];
                    //     WVJJTree->btagWeight_loose_Up *= NanoReader_.Jet_btagSF_deepcsv_L_up[j];
                    //     WVJJTree->btagWeight_loose_Down *= NanoReader_.Jet_btagSF_deepcsv_L_down[j];
                    //   }
                    // }
                    // else {
                    //   if (isMC) {
                    //     if (btag_eff_loose == 1.0) {
                    //       WVJJTree->btagWeight_loose *= NanoReader_.Jet_btagSF_deepcsv_L[j];
                    //       WVJJTree->btagWeight_loose_Up *= NanoReader_.Jet_btagSF_deepcsv_L_up[j];
                    //       WVJJTree->btagWeight_loose_Down *= NanoReader_.Jet_btagSF_deepcsv_L_down[j];
                    //     }
                    //     else {
                    //       WVJJTree->btagWeight_loose *= (1.0 - NanoReader_.Jet_btagSF_deepcsv_L[j] * btag_eff_loose) / (1.0 - btag_eff_loose);
                    //       WVJJTree->btagWeight_loose_Up *= (1.0 - NanoReader_.Jet_btagSF_deepcsv_L_up[j] * btag_eff_loose) / (1.0 - btag_eff_loose);
                    //       WVJJTree->btagWeight_loose_Down *= (1.0 - NanoReader_.Jet_btagSF_deepcsv_L_down[j] * btag_eff_loose) / (1.0 - btag_eff_loose);
                    //     }
                    //   }
                    // }
                    // if (NanoReader_.Jet_btagDeepB[j] > btag_medium_wp) {
                    //   WVJJTree->nAK4Btag_medium++;
                    //   if (isMC) {
                    //     WVJJTree->btagWeight_medium *= NanoReader_.Jet_btagSF_deepcsv_M[j];
                    //     WVJJTree->btagWeight_medium_Up *= NanoReader_.Jet_btagSF_deepcsv_M_up[j];
                    //     WVJJTree->btagWeight_medium_Down *= NanoReader_.Jet_btagSF_deepcsv_M_down[j];
                    //   }
                    // }
                    // else {
                    //   if (isMC) {
                    //     if (btag_eff_medium == 1.0) {
                    //       WVJJTree->btagWeight_medium *= NanoReader_.Jet_btagSF_deepcsv_M[j];
                    //       WVJJTree->btagWeight_medium_Up *= NanoReader_.Jet_btagSF_deepcsv_M_up[j];
                    //       WVJJTree->btagWeight_medium_Down *= NanoReader_.Jet_btagSF_deepcsv_M_down[j];
                    //     }
                    //     else {
                    //       WVJJTree->btagWeight_medium *= (1.0 - NanoReader_.Jet_btagSF_deepcsv_M[j] * btag_eff_medium) / (1.0 - btag_eff_medium);
                    //       WVJJTree->btagWeight_medium_Up *= (1.0 - NanoReader_.Jet_btagSF_deepcsv_M_up[j] * btag_eff_medium) / (1.0 - btag_eff_medium);
                    //       WVJJTree->btagWeight_medium_Down *= (1.0 - NanoReader_.Jet_btagSF_deepcsv_M_down[j] * btag_eff_medium) / (1.0 - btag_eff_medium);
                    //     }
                    //   }
                    // }
                    // if (NanoReader_.Jet_btagDeepB[j] > btag_tight_wp) {
                    //   WVJJTree->nAK4Btag_tight++;
                    //   if (isMC) {
                    //     WVJJTree->btagWeight_tight *= NanoReader_.Jet_btagSF_deepcsv_T[j];
                    //     WVJJTree->btagWeight_tight_Up *= NanoReader_.Jet_btagSF_deepcsv_T_up[j];
                    //     WVJJTree->btagWeight_tight_Down *= NanoReader_.Jet_btagSF_deepcsv_T_down[j];
                    //   }
                    // }
                    // else {
                    //   if (isMC) {
                    //     if (btag_eff_tight == 1.0) {
                    //       WVJJTree->btagWeight_tight *= NanoReader_.Jet_btagSF_deepcsv_T[j];
                    //       WVJJTree->btagWeight_tight_Up *= NanoReader_.Jet_btagSF_deepcsv_T_up[j];
                    //       WVJJTree->btagWeight_tight_Down *= NanoReader_.Jet_btagSF_deepcsv_T_down[j];
                    //     }
                    //     else {
                    //       WVJJTree->btagWeight_tight *= (1.0 - NanoReader_.Jet_btagSF_deepcsv_T[j] * btag_eff_tight) / (1.0 - btag_eff_tight);
                    //       WVJJTree->btagWeight_tight_Up *= (1.0 - NanoReader_.Jet_btagSF_deepcsv_T_up[j] * btag_eff_tight) / (1.0 - btag_eff_tight);
                    //       WVJJTree->btagWeight_tight_Down *= (1.0 - NanoReader_.Jet_btagSF_deepcsv_T_down[j] * btag_eff_tight) / (1.0 - btag_eff_tight);
                    //     }
                    //   }
                    // }
                }
                if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] btag weight computation done" << std::endl;

                Ak4Jets.push_back(TLorentzVector(0,0,0,0));
                Ak4Jets.back().SetPtEtaPhiM(NanoReader_.Jet_pt[j],
                                            NanoReader_.Jet_eta[j],
                                            NanoReader_.Jet_phi[j],
                                            NanoReader_.Jet_mass[j]
                                            );
                goodAK4JetIndex.push_back(j);
                allAK4JetsSum_pt += NanoReader_.Jet_pt[j];
            }
            if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Outside of AK4 jet loop." << std::endl;

            // for (std::vector<int>::iterator It_JetIndex = goodAK4JetIndex.begin(); It_JetIndex != goodAK4JetIndex.end(); ++It_JetIndex)
            // {
            // std::cout << "DEBUG: " << *It_JetIndex << std::endl;
            // }
            //
            //
            // get 4 jets for FH final state with minWH vals

            int nGoodAK4jets = goodAK4JetIndex.size();

            // FH: 2 jet category
            if (nGood_Higgs_FatJet == 0 && nGood_W_FatJet >= 2)
                totalCutFlow_FH->Fill("nAK8H=0 & nAK8_W >= 2",1);

            // FH: 3 jet category (including 2 or more good AK8 jet)
            if (nGood_Higgs_FatJet == 0 && nGood_W_FatJet >= 1 && nGoodAK4jets >= 2)
                totalCutFlow_FH->Fill("nAK8H=0 & nAK8_W>=1 & nAK4>=2",1);

            // FH: 3 jet category  (excluding events with 2 or more good AK8 jet)
            if (nGood_Higgs_FatJet == 0 && nGood_W_FatJet == 1 && nGoodAK4jets >= 2)
                totalCutFlow_FH->Fill("nAK8H=0 & nAK8_W=1 & nAK4>=2",1);

            // FH: 4 jet category
            if (nGood_Higgs_FatJet == 0 && nGood_W_FatJet == 0 && nGoodAK4jets >= 4 )
                totalCutFlow_FH->Fill("nAK8H=0 & nAK8W=0 & nAK4>=4",1);

            // Found 1 Higgs jet or
            // Fount 1 fat Wjet and 2 AK4 jets or
            // If we don't find any fat jet then choose 4 AK4 jets
            if ( (nGood_Higgs_FatJet >= 1) ||
                 (nGood_Higgs_FatJet == 0 && nGood_W_FatJet >= 2) ||
                 (nGood_Higgs_FatJet == 0 && nGood_W_FatJet == 1 && nGoodAK4jets >= 2) ||
                 (nGood_Higgs_FatJet == 0 && nGood_W_FatJet == 0 && nGoodAK4jets >= 4)
                )
                totalCutFlow_FH->Fill("1Jet2Jet3Jet4Jet",1);

            if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Passed nJet>=4 conditon" << std::endl;
            if ((nTightMu + nTightEle == 0) && nGoodAK4jets >= 4 ) totalCutFlow_FH->Fill("nAK4 >= 4",1);
            if ((nTightMu + nTightEle == 1) && nGoodAK4jets >= 2 ) totalCutFlow_SL->Fill("nAK4 >= 2",1);

            if(((nTightMu + nTightEle == 0) && nGoodAK4jets >= 4 && WVJJTree->pho1_pt_byMgg > 0.35 && WVJJTree->pho2_pt_byMgg > 0.25))
                totalCutFlow_FH->Fill("pT/mgg cut",1);
            if(((nTightMu + nTightEle == 0) && nGoodAK4jets >= 4 && WVJJTree->pho1_pt_byMgg > 0.35 && WVJJTree->pho2_pt_byMgg > 0.25 && WVJJTree->diphoton_pt > 100.0))
                totalCutFlow_FH->Fill("pT(#gamma #gamma)>100",1);

            if(((nTightMu + nTightEle == 1) && nGoodAK4jets >= 2 && WVJJTree->pho1_pt_byMgg > 0.35 && WVJJTree->pho2_pt_byMgg > 0.25))
                totalCutFlow_SL->Fill("pT/mgg cut",1);
            if(((nTightMu + nTightEle == 1) && nGoodAK4jets >= 2 && WVJJTree->pho1_pt_byMgg > 0.35 && WVJJTree->pho2_pt_byMgg > 0.25 && WVJJTree->diphoton_pt > 100.0))
                totalCutFlow_SL->Fill("pT(#gamma #gamma)>100",1);

            // if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] " << std::endl;
            if (DEBUG) std::cout << "\t[INFO::AK4jets] [" << i <<"/" << lineCount << "] Passed nAK4 jets >= 4 condition" << std::endl;
            /* ----------------------- output the AK4 jet ----------------------- */

            // if (nGoodAK4jets>=4)
            if (nGood_Higgs_FatJet == 0 && nGood_W_FatJet == 0 && nGoodAK4jets >= 4 )
            {

            /* ------------------- cout four pt to make sure in order ------------------- */
            WVJJTree->nGoodAK4jets = nGoodAK4jets;
            WVJJTree->FullyResolved_allAK4JetsSum_pt = allAK4JetsSum_pt;

            WVJJTree->FullyResolved_Jet1_pt = NanoReader_.Jet_pt[goodAK4JetIndex[0]];
            WVJJTree->FullyResolved_Jet2_pt = NanoReader_.Jet_pt[goodAK4JetIndex[1]];
            WVJJTree->FullyResolved_Jet3_pt = NanoReader_.Jet_pt[goodAK4JetIndex[2]];
            WVJJTree->FullyResolved_Jet4_pt = NanoReader_.Jet_pt[goodAK4JetIndex[3]];

            WVJJTree->FullyResolved_Jet1_eta = NanoReader_.Jet_eta[goodAK4JetIndex[0]];
            WVJJTree->FullyResolved_Jet2_eta = NanoReader_.Jet_eta[goodAK4JetIndex[1]];
            WVJJTree->FullyResolved_Jet3_eta = NanoReader_.Jet_eta[goodAK4JetIndex[2]];
            WVJJTree->FullyResolved_Jet4_eta = NanoReader_.Jet_eta[goodAK4JetIndex[3]];

            WVJJTree->FullyResolved_Jet1_phi = NanoReader_.Jet_phi[goodAK4JetIndex[0]];
            WVJJTree->FullyResolved_Jet2_phi = NanoReader_.Jet_phi[goodAK4JetIndex[1]];
            WVJJTree->FullyResolved_Jet3_phi = NanoReader_.Jet_phi[goodAK4JetIndex[2]];
            WVJJTree->FullyResolved_Jet4_phi = NanoReader_.Jet_phi[goodAK4JetIndex[3]];

            WVJJTree->FullyResolved_Jet1_M = NanoReader_.Jet_mass[goodAK4JetIndex[0]];
            WVJJTree->FullyResolved_Jet2_M = NanoReader_.Jet_mass[goodAK4JetIndex[1]];
            WVJJTree->FullyResolved_Jet3_M = NanoReader_.Jet_mass[goodAK4JetIndex[2]];
            WVJJTree->FullyResolved_Jet4_M = NanoReader_.Jet_mass[goodAK4JetIndex[3]];

            WVJJTree->FullyResolved_Jet1_E = Ak4Jets.at(0).E();
            WVJJTree->FullyResolved_Jet2_E = Ak4Jets.at(1).E();
            WVJJTree->FullyResolved_Jet3_E = Ak4Jets.at(2).E();
            WVJJTree->FullyResolved_Jet4_E = Ak4Jets.at(3).E();

            /* -------------------------- Sum of 2 leading jets ------------------------- */
            TLorentzVector TwoLeadingJets = Ak4Jets.at(0) + Ak4Jets.at(1);
            WVJJTree->FullyResolved_TwoLeadingJets_pt = TwoLeadingJets.Pt();
            WVJJTree->FullyResolved_TwoLeadingJets_eta = TwoLeadingJets.Eta();
            WVJJTree->FullyResolved_TwoLeadingJets_phi = TwoLeadingJets.Phi();
            WVJJTree->FullyResolved_TwoLeadingJets_m = TwoLeadingJets.M();
            WVJJTree->FullyResolved_TwoLeadingJets_E = TwoLeadingJets.E();

            /* -------------------------- Sum of 3rd 4th  jets -------------------------- */
            TLorentzVector ThirdFourthJets = Ak4Jets.at(2) + Ak4Jets.at(3);
            WVJJTree->FullyResolved_ThirdFourthJets_pt = ThirdFourthJets.Pt();
            WVJJTree->FullyResolved_ThirdFourthJets_eta = ThirdFourthJets.Eta();
            WVJJTree->FullyResolved_ThirdFourthJets_phi = ThirdFourthJets.Phi();
            WVJJTree->FullyResolved_ThirdFourthJets_m = ThirdFourthJets.M();
            WVJJTree->FullyResolved_ThirdFourthJets_E = ThirdFourthJets.E();

            /* ------------------------------ Sum of 4 jets ----------------------------- */
            TLorentzVector FourJets = Ak4Jets.at(0) + Ak4Jets.at(1)+ Ak4Jets.at(2) + Ak4Jets.at(3);
            WVJJTree->FullyResolved_FourJets_pt = FourJets.Pt();
            WVJJTree->FullyResolved_FourJets_eta = FourJets.Eta();
            WVJJTree->FullyResolved_FourJets_phi = FourJets.Phi();
            WVJJTree->FullyResolved_FourJets_m = FourJets.M();
            WVJJTree->FullyResolved_FourJets_E = FourJets.E();

            TLorentzVector Radion = FourJets + diphoton;
            WVJJTree->FullyResolved_Radion_pt = Radion.Pt();
            WVJJTree->FullyResolved_Radion_eta = Radion.Eta();
            WVJJTree->FullyResolved_Radion_phi = Radion.Phi();
            WVJJTree->FullyResolved_Radion_m = Radion.M();
            WVJJTree->FullyResolved_Radion_E = Radion.E();
            }

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
