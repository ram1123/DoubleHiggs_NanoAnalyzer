#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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

#include "DoubleHiggs/Selection/interface/NanoAOD_MC.hh"
#include "DoubleHiggs/Selection/interface/NanoAOD_Weights.hh"
#include "DoubleHiggs/Selection/interface/Utils.hh"

int main(int argc, char const *argv[])
{
    std::cout << "[INFO]: Program name is : " << argv[0] << std::endl;

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    int isMC = atoi(argv[3]);
    int era = atoi(argv[4]);
    bool DEBUG = atoi(argv[5]);

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

    const float H_MASS = 125.10;
    const float W_MASS = 80.379;

    //lepton cuts
    const float EL_PT_CUT = 10;
    const float MU_PT_CUT = 10;

    const float PHO_ETA_CUT = 4.5;
    const float PHO_PT_VETO_CUT = 10.0;
    const float PHO_PT_CUT = 10.0;

    const float AK8_LEP_DR_CUT = 0.8;

    //ak8 jet cuts
    const float AK8_MIN_PT = 200;
    const float AK8_MAX_ETA = 2.4;
    const float AK8_MIN_SDM = 40;
    const float AK8_MAX_SDM = 150;

    //ak4 jet cuts
    //const float AK4_PT_VETO_CUT = 20;
    const float AK4_ETA_CUT = 2.4;
    const float AK4_PT_CUT = 30;
    const float AK4_JJ_MIN_M = 40.0;
    const float AK4_JJ_MAX_M = 150.0;

    std::vector<TLorentzVector> TightPhoton;
    std::vector<TLorentzVector> Ak4Jets;
    std::vector<TLorentzVector> Ak8Jets;
    std::vector<int> goodAK4JetIndex;

    //
    //   INPUT/OUTPUT
    //

    TFile *of = new TFile(outputFile.c_str(),"RECREATE");
    TTree *ot = new TTree("Events","Events");
    output* OutputTree = new output(ot);
    TH1F *totalEvents = new TH1F("TotalEvents","TotalEvents",2,-1,1);

    TFile *f=0;
    TTree *t=0, *r=0;

    std::ifstream ifs;
    ifs.open(inputFile.data());
    assert(ifs.is_open());
    std::string line;
    while (getline(ifs,line)) {
        std::stringstream ss(line);
        std::string filetoopen;
        ss >> filetoopen;

        std::cout << "File: " << TString(filetoopen) << std::endl;

        //f = TFile::Open(TString("root://cmseos.fnal.gov/")+TString(filetoopen),"read");
        //f = TFile::Open(TString("root://xrootd-cms.infn.it/")+TString(filetoopen),"read");
        f = TFile::Open(TString(filetoopen),"read");
        t = (TTree *)f->Get("Events");
        r = (TTree *)f->Get("Runs");
        if (t==NULL) continue;

        //std::cout << filetoopen << std::endl;

        NanoAOD_MC NanoReader = NanoAOD_MC(t);
        NanoAOD_Weights NanoWeightReader = NanoAOD_Weights(r);

        if (isMC==1) {
            NanoWeightReader.GetEntry(0);
            totalEvents->SetBinContent(2,totalEvents->GetBinContent(2)+NanoWeightReader.genEventSumw);
        }

        for (uint i=0; i < t->GetEntries(); i++) {
            //for (uint i=0; i < 1000000; i++) {
            OutputTree->clearVars();
            NanoReader.GetEntry(i);

            if (i%1000==0) std::cout <<"event " << i << std::endl;
            // if (i>50000) exit(0);

            if (isMC==1) {
                OutputTree->genWeight=NanoReader.Generator_weight;
            }

            if (era==2017) {
                if ( NanoReader.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 || NanoReader.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 || NanoReader.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 ) OutputTree->trigger_1Pho = true;
            }
            // else if (era==2017) {
            //     if ( NanoReader.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 || NanoReader.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 || NanoReader.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 ) OutputTree->trigger_1Pho = true;
            //     if ( NanoReader.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 || NanoReader.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 || NanoReader.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 ) OutputTree->trigger_2Pho = true;
            // }
            // else if (era==2018) {
            //     if ( NanoReader.HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 || NanoReader.HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 || NanoReader.HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 ) OutputTree->trigger_1Pho = true;
            // }

            if (!(OutputTree->trigger_1Pho)) continue;

            TightPhoton.clear();
            Ak4Jets.clear();
            Ak8Jets.clear();

            OutputTree->run = NanoReader.run;
            OutputTree->evt = NanoReader.event;
            OutputTree->ls = NanoReader.luminosityBlock;

            // OutputTree->nPV = NanoReader.PV_npvsGood;
            OutputTree->nPU_mean = NanoReader.Pileup_nPU;

            OutputTree->puWeight = 1.0;//scaleFactor.GetPUWeight(info->nPUmean, 0);

            int nTightEle=0;
            int nTightMu=0;

            for (uint j=0; j < NanoReader.nMuon; j++) {
                if (!NanoReader.Muon_tightId[j]) continue;
                if ( NanoReader.Muon_pt[j] < MU_PT_CUT ) continue;
                nTightMu++;
            }
            for (uint j=0; j < NanoReader.nElectron; j++) {
                //cut-based ID Fall17 V2 (0:fail, 1:veto, 2:loose, 3:medium, 4:tight)
                if ( NanoReader.Electron_cutBased[j]<3 ) continue;
                if ( NanoReader.Electron_pt[j] < EL_PT_CUT ) continue;
                nTightEle++;
            }

            if (nTightEle+nTightMu>0) continue;

            // PHOTON SELECTION
            int nTightPhoton = 0;
            int nVetoPhoton = 0;

            for (UInt_t PhotonCount = 0; PhotonCount < NanoReader.nPhoton; ++PhotonCount)
            {
                if ( abs(NanoReader.Photon_eta[PhotonCount]) > PHO_ETA_CUT ) continue;
                //using conservative uncertainty value of 3%
                if ( 1.03*NanoReader.Photon_pt[PhotonCount] < PHO_PT_VETO_CUT ) continue;

                if (!NanoReader.Photon_cutBased[PhotonCount]) continue;
                if (NanoReader.Photon_pfRelIso03_all[PhotonCount]>0.25) continue;
                nVetoPhoton++;

                //using conservative uncertainty value of 3%
                if ( 1.03*NanoReader.Photon_pt[PhotonCount] < PHO_PT_CUT ) continue;
                if (!NanoReader.Photon_cutBased[PhotonCount]) continue;
                if (NanoReader.Photon_pfRelIso03_all[PhotonCount]>0.15) continue;

                nTightPhoton++;
                TightPhoton.push_back(TLorentzVector(0,0,0,0));
                TightPhoton.back().SetPtEtaPhiE( NanoReader.Photon_pt[PhotonCount],
                                                NanoReader.Photon_eta[PhotonCount],
                                                NanoReader.Photon_phi[PhotonCount],
                                                NanoReader.Photon_eCorr[PhotonCount]
                                                );

                if ( NanoReader.Photon_pt[PhotonCount] > OutputTree->pho1_pt ) {
                    OutputTree->pho2_pt = OutputTree->pho1_pt;
                    OutputTree->pho2_eta = OutputTree->pho1_eta;
                    OutputTree->pho2_phi = OutputTree->pho1_phi;
                    OutputTree->pho2_m = OutputTree->pho1_m;
                    OutputTree->pho2_iso = OutputTree->pho1_iso;
                    OutputTree->pho2_q = OutputTree->pho1_q;

                    OutputTree->pho1_pt = NanoReader.Photon_pt[PhotonCount];
                    OutputTree->pho1_eta = NanoReader.Photon_eta[PhotonCount];
                    OutputTree->pho1_phi = NanoReader.Photon_phi[PhotonCount];
                    OutputTree->pho1_m = NanoReader.Photon_mass[PhotonCount];
                    OutputTree->pho1_iso = NanoReader.Photon_pfRelIso03_all[PhotonCount];
                    OutputTree->pho1_q = NanoReader.Photon_charge[PhotonCount];
                }
                else if ( NanoReader.Photon_pt[PhotonCount] > OutputTree->pho2_pt ) {
                    OutputTree->pho2_pt = NanoReader.Photon_pt[PhotonCount];
                    OutputTree->pho2_eta = NanoReader.Photon_eta[PhotonCount];
                    OutputTree->pho2_phi = NanoReader.Photon_phi[PhotonCount];
                    OutputTree->pho2_m = NanoReader.Photon_mass[PhotonCount];
                    OutputTree->pho2_iso = NanoReader.Photon_pfRelIso03_all[PhotonCount];
                    OutputTree->pho2_q = NanoReader.Photon_charge[PhotonCount];
                }
            }

            if (!(nTightPhoton==2)) continue;

            TLorentzVector LV_pho1(0,0,0,0);
            LV_pho1.SetPtEtaPhiM( OutputTree->pho1_pt, OutputTree->pho1_eta, OutputTree->pho1_phi, OutputTree->pho1_m );

            TLorentzVector LV_pho2(0,0,0,0);
            LV_pho2.SetPtEtaPhiM( OutputTree->pho2_pt, OutputTree->pho2_eta, OutputTree->pho2_phi, OutputTree->pho2_m );

            TLorentzVector diphoton = LV_pho1+LV_pho2;

            OutputTree->diphoton_m = diphoton.M();
            OutputTree->diphoton_pt = diphoton.Pt();
            OutputTree->diphoton_eta = diphoton.Eta();
            OutputTree->diphoton_phi = diphoton.Phi();

            // float dmW = 3000.0;
            // int nGoodFatJet=0;
            // for (UInt_t Ak8JetCount = 0; Ak8JetCount < NanoReader.nFatJet; ++Ak8JetCount)
            // {
            //     if ( ! (NanoReader.FatJet_pt[Ak8JetCount]>AK8_MIN_PT ||
            //             NanoReader.FatJet_pt_jesTotalUp[Ak8JetCount]>AK8_MIN_PT ||
            //             NanoReader.FatJet_pt_jesTotalDown[Ak8JetCount]>AK8_MIN_PT)
            //         ) continue;
            //     if ( fabs(NanoReader.FatJet_eta[Ak8JetCount]) > AK8_MAX_ETA
            //         ) continue;

            //     if ( ! (NanoReader.FatJet_msoftdrop[Ak8JetCount]>AK8_MIN_SDM ||
            //             NanoReader.FatJet_msoftdrop_jesTotalUp[Ak8JetCount]>AK8_MIN_SDM ||
            //             NanoReader.FatJet_msoftdrop_jesTotalDown[Ak8JetCount]>AK8_MIN_SDM)
            //         ) continue;

            //     if ( ! (NanoReader.FatJet_msoftdrop[Ak8JetCount]<AK8_MAX_SDM ||
            //             NanoReader.FatJet_msoftdrop_jesTotalUp[Ak8JetCount]<AK8_MAX_SDM ||
            //             NanoReader.FatJet_msoftdrop_jesTotalDown[Ak8JetCount]<AK8_MAX_SDM)
            //         ) continue;

            //     bool isClean=true;
            //     //lepton cleaning
            //     for ( std::size_t k=0; k<TightPhoton.size(); k++) {
            //         if (deltaR( TightPhoton.at(k).Eta(), TightPhoton.at(k).Phi(),
            //                 NanoReader.FatJet_eta[Ak8JetCount], NanoReader.FatJet_phi[Ak8JetCount])
            //                 < AK8_LEP_DR_CUT)
            //         isClean = false;
            //     }

            //     if ( isClean == false ) continue;

            //     if ( fabs(NanoReader.FatJet_msoftdrop[Ak8JetCount] - H_MASS) > dmW ) continue;

            //     OutputTree->Higgs_PuppiAK8_m_sd0 = NanoReader.FatJet_msoftdrop[Ak8JetCount];
            //     OutputTree->Higgs_PuppiAK8_m_sd0_corr = NanoReader.FatJet_msoftdrop[Ak8JetCount];
            //     OutputTree->Higgs_PuppiAK8_tau2tau1 = NanoReader.FatJet_tau2[Ak8JetCount]/NanoReader.FatJet_tau1[Ak8JetCount];
            //     OutputTree->Higgs_PuppiAK8_pt = NanoReader.FatJet_pt[Ak8JetCount];
            //     OutputTree->Higgs_PuppiAK8_eta = NanoReader.FatJet_eta[Ak8JetCount];
            //     OutputTree->Higgs_PuppiAK8_phi = NanoReader.FatJet_phi[Ak8JetCount];

            //     OutputTree->Higgs_PuppiAK8_m_sd0_corr_scaleUp = NanoReader.FatJet_msoftdrop_jesTotalUp[Ak8JetCount];
            //     OutputTree->Higgs_PuppiAK8_m_sd0_corr_scaleDn = NanoReader.FatJet_msoftdrop_jesTotalDown[Ak8JetCount];
            //     OutputTree->Higgs_PuppiAK8_pt_scaleUp = NanoReader.FatJet_pt_jesTotalUp[Ak8JetCount];
            //     OutputTree->Higgs_PuppiAK8_pt_scaleDn = NanoReader.FatJet_pt_jesTotalDown[Ak8JetCount];

            //     dmW = fabs(NanoReader.FatJet_msoftdrop[Ak8JetCount] - H_MASS);
            //     nGoodFatJet++;
            // }

            goodAK4JetIndex.clear();
            for (UInt_t Ak4JetCount = 0; Ak4JetCount < NanoReader.nJet; ++Ak4JetCount)
            {
                //jet energy scale variations
                if ( NanoReader.Jet_pt[Ak4JetCount] < AK4_PT_CUT) continue;

                //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
                if (NanoReader.Jet_eta[Ak4JetCount]<2.4 && NanoReader.Jet_pt[Ak4JetCount]>30) {
                    if (NanoReader.Jet_btagDeepB[Ak4JetCount] > 0.1241) OutputTree->nBtag_loose++;
                    if (NanoReader.Jet_btagDeepB[Ak4JetCount] > 0.4184) OutputTree->nBtag_medium++;
                    if (NanoReader.Jet_btagDeepB[Ak4JetCount] > 0.7527) OutputTree->nBtag_tight++;
                }

                bool isClean=true;
                //lepton cleaning
                for ( std::size_t k=0; k<TightPhoton.size(); k++) {
                    if (deltaR( TightPhoton.at(k).Eta(), TightPhoton.at(k).Phi(),
                               NanoReader.Jet_eta[Ak4JetCount], NanoReader.Jet_phi[Ak4JetCount])
                        < AK8_LEP_DR_CUT)
                        isClean = false;
                }
                if ( isClean == false ) continue;
                //Ak4Jets
                // nTightPhoton++;
                Ak4Jets.push_back(TLorentzVector(0,0,0,0));
                Ak4Jets.back().SetPtEtaPhiM( NanoReader.Jet_pt[Ak4JetCount],
                                            NanoReader.Jet_eta[Ak4JetCount],
                                            NanoReader.Jet_phi[Ak4JetCount],
                                            NanoReader.Jet_mass[Ak4JetCount]
                                            );
                goodAK4JetIndex.push_back(Ak4JetCount);
            }


            // for (std::vector<int>::iterator It_JetIndex = goodAK4JetIndex.begin(); It_JetIndex != goodAK4JetIndex.end(); ++It_JetIndex)
            // {
            //     // std::cout << "DEBUG: " << *It_JetIndex << std::endl;
            // }
            //
            //
            // get 4 jets for FH final state with minWH vals
            double TempMinWMass = 999999.0;
            double TempMinHMass = 999999.0;

            int OnShellW_LeadingJetIndex = -1;
            int OnShellW_SubLeadingJetIndex = -1;
            int OffShellW_LeadingJetIndex = -1;
            int OffShellW_SubLeadingJetIndex = -1;

            int nTagJets = goodAK4JetIndex.size();

            if (nTagJets<4) continue;

            if (DEBUG) std::cout << "-----\n\n\n" << nTagJets << ": All Jet Index: ";
            for (int CountJet1 = 0; CountJet1 < nTagJets; CountJet1++) {
                if (DEBUG) std::cout << goodAK4JetIndex.at(CountJet1) << "\t";
            }
            if (DEBUG) std::cout << "\n\n";

            for (int CountJet1 = 0; CountJet1 < nTagJets-1; CountJet1++) {
                for (int CountJet2 = CountJet1+1; CountJet2 < nTagJets; CountJet2++) {
                    // if (DEBUG) std::cout << "(CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
                    // NanoReader.Jet_mass[Ak4JetCount]
                    TLorentzVector FirstJet(0,0,0,0);
                    FirstJet.SetPtEtaPhiM(NanoReader.Jet_pt[goodAK4JetIndex.at(CountJet1)],
                                          NanoReader.Jet_eta[goodAK4JetIndex.at(CountJet1)],
                                          NanoReader.Jet_phi[goodAK4JetIndex.at(CountJet1)],
                                          NanoReader.Jet_mass[goodAK4JetIndex.at(CountJet1)] );

                    TLorentzVector SecondJet(0,0,0,0);
                    SecondJet.SetPtEtaPhiM(NanoReader.Jet_pt[goodAK4JetIndex.at(CountJet2)],
                                           NanoReader.Jet_eta[goodAK4JetIndex.at(CountJet2)],
                                           NanoReader.Jet_phi[goodAK4JetIndex.at(CountJet2)],
                                           NanoReader.Jet_mass[goodAK4JetIndex.at(CountJet2)] );

                    double deltaMass =  abs((FirstJet+SecondJet).M() - 80.0);
                    // if (DEBUG) std::cout << "deltaMass = " << deltaMass << "\t TempMinWMass = " << TempMinWMass << std::endl;
                    if ( deltaMass < TempMinWMass)
                    {
                        if  (FirstJet.Pt() > SecondJet.Pt()) {
                            OnShellW_LeadingJetIndex = goodAK4JetIndex.at(CountJet1);
                            OnShellW_SubLeadingJetIndex = goodAK4JetIndex.at(CountJet2);
                        } else {
                            OnShellW_LeadingJetIndex = goodAK4JetIndex.at(CountJet2);
                            OnShellW_SubLeadingJetIndex = goodAK4JetIndex.at(CountJet1);
                        }
                        TempMinWMass = deltaMass;
                        // if (DEBUG) std::cout << "==> (CountJet1,CountJet2) = (" << OnShellW_LeadingJetIndex << "," << OnShellW_SubLeadingJetIndex << ")" << std::endl;
                    }
                }
            }
            // if (DEBUG) std::cout << "[INFO] Print Jet Index (After W-Selection): " << OnShellW_LeadingJetIndex << "\t" << OnShellW_SubLeadingJetIndex << "\t" << OffShellW_LeadingJetIndex << "\t" << OffShellW_SubLeadingJetIndex  << std::endl;

            for (int CountJet1 = 0; CountJet1 < nTagJets-1; CountJet1++) {
                if (goodAK4JetIndex.at(CountJet1) == OnShellW_LeadingJetIndex || goodAK4JetIndex.at(CountJet1) == OnShellW_SubLeadingJetIndex) continue;
                for (int CountJet2 = CountJet1+1; CountJet2 < nTagJets; CountJet2++) {
                    if (goodAK4JetIndex.at(CountJet2) == OnShellW_LeadingJetIndex || goodAK4JetIndex.at(CountJet2) == OnShellW_SubLeadingJetIndex) continue;
                    // if (DEBUG) std::cout << "(CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
                    // if (DEBUG) std::cout << "===> " << goodAK4JetIndex.at(CountJet1) << "\t" << goodAK4JetIndex.at(CountJet2) << std::endl;

                    TLorentzVector FirstJet(0,0,0,0);
                    FirstJet.SetPtEtaPhiM(NanoReader.Jet_pt[goodAK4JetIndex.at(CountJet1)],
                                          NanoReader.Jet_eta[goodAK4JetIndex.at(CountJet1)],
                                          NanoReader.Jet_phi[goodAK4JetIndex.at(CountJet1)],
                                          NanoReader.Jet_mass[goodAK4JetIndex.at(CountJet1)] );

                    TLorentzVector SecondJet(0,0,0,0);
                    SecondJet.SetPtEtaPhiM(NanoReader.Jet_pt[goodAK4JetIndex.at(CountJet2)],
                                           NanoReader.Jet_eta[goodAK4JetIndex.at(CountJet2)],
                                           NanoReader.Jet_phi[goodAK4JetIndex.at(CountJet2)],
                                           NanoReader.Jet_mass[goodAK4JetIndex.at(CountJet2)] );

                    TLorentzVector ThirdJet(0,0,0,0);
                    ThirdJet.SetPtEtaPhiM(NanoReader.Jet_pt[OnShellW_LeadingJetIndex],
                                          NanoReader.Jet_eta[OnShellW_LeadingJetIndex],
                                          NanoReader.Jet_phi[OnShellW_LeadingJetIndex],
                                          NanoReader.Jet_mass[OnShellW_LeadingJetIndex] );

                    TLorentzVector FourthJet(0,0,0,0);
                    FourthJet.SetPtEtaPhiM(NanoReader.Jet_pt[OnShellW_SubLeadingJetIndex],
                                           NanoReader.Jet_eta[OnShellW_SubLeadingJetIndex],
                                           NanoReader.Jet_phi[OnShellW_SubLeadingJetIndex],
                                           NanoReader.Jet_mass[OnShellW_SubLeadingJetIndex] );
                    // if (DEBUG) std::cout << "===> " << goodAK4JetIndex.at(CountJet1) << "\t" << goodAK4JetIndex.at(CountJet2) << std::endl;
                    double deltaMass =  abs(( FirstJet + SecondJet + ThirdJet + FourthJet).M() - 125.0);
                    // if (DEBUG) std::cout << "deltaMass = " << deltaMass << "\t TempMinHMass = " << TempMinHMass << std::endl;
                    if ( deltaMass < TempMinHMass)
                    {
                        if  (FirstJet.Pt() > SecondJet.Pt()) {
                            OffShellW_LeadingJetIndex = goodAK4JetIndex.at(CountJet1);
                            OffShellW_SubLeadingJetIndex = goodAK4JetIndex.at(CountJet2);
                        } else {
                            OffShellW_LeadingJetIndex = goodAK4JetIndex.at(CountJet2);
                            OffShellW_SubLeadingJetIndex = goodAK4JetIndex.at(CountJet1);
                        }
                        TempMinHMass = deltaMass;
                        // if (DEBUG) std::cout << "==> (CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
                    }
                }
            }

            if (DEBUG) std::cout << "[INFO] Print pt of 4 selected jets: " << OnShellW_LeadingJetIndex << "\t" << OnShellW_SubLeadingJetIndex << "\t" << OffShellW_LeadingJetIndex << "\t" << OffShellW_SubLeadingJetIndex  << std::endl;
            if (DEBUG) std::cout << "[INFO] jet1 pT = " << NanoReader.Jet_pt[OnShellW_LeadingJetIndex] << std::endl;
            if (DEBUG) std::cout << "[INFO] jet2 pT = " << NanoReader.Jet_pt[OnShellW_SubLeadingJetIndex] << std::endl;
            if (DEBUG) std::cout << "[INFO] jet3 pT = " << NanoReader.Jet_pt[OffShellW_LeadingJetIndex] << std::endl;
            if (DEBUG) std::cout << "[INFO] jet4 pT = " << NanoReader.Jet_pt[OffShellW_SubLeadingJetIndex] << std::endl;


            if (isMC==1) {

                OutputTree->nScaleWeight = NanoReader.nLHEScaleWeight;
                OutputTree->nPdfWeight = NanoReader.nLHEPdfWeight;

                for (uint j=0; j<OutputTree->nScaleWeight; j++) {
                    //LHE scale variation weights (w_var / w_nominal); [0] is MUR="0.5" MUF="0.5";
                    //[1] is MUR="0.5" MUF="1.0"; [2] is MUR="0.5" MUF="2.0"; [3] is MUR="1.0" MUF="0.5";
                    //[4] is MUR="1.0" MUF="2.0"; [5] is MUR="2.0" MUF="0.5"; [6] is MUR="2.0" MUF="1.0";
                    //[7] is MUR="2.0" MUF="2.0"
                    OutputTree->scaleWeight[j]=NanoReader.LHEScaleWeight[j];
                }
                for (uint j=0; j<OutputTree->nPdfWeight; j++) {
                    //LHE pdf variation weights (w_var / w_nominal) for LHA IDs 91400 - 91432
                    OutputTree->pdfWeight[j]=NanoReader.LHEPdfWeight[j];
                }

            }

            OutputTree->btagWeight = NanoReader.btagWeight_CSVV2;
            OutputTree->L1PFWeight = NanoReader.L1PreFiringWeight_Nom;

            ot->Fill();
        }
    }

    of->Write();
    of->Close();
    return 0;

}
