#ifndef OUTPUT_HH
#define OUTPUT_HH

#include "TTree.h"

class output{

public:

  output(TTree *t) {
    fTree = t;
    init();
  };

  ~output() {
    delete fTree;
  };

  void clearVars();
  void init();

  TTree *fTree;
  float nTagJets = -999.0;
  float allAK4JetsSum_pt = -999.0;
  float allAK8JetsSum_pt = -999.0;
  float nGoodFatjet = -999.0;



  Float_t	FatJet_area = -999.0;
  Float_t	FatJet_btagCMVA = -999.0;
  Float_t	FatJet_btagCSVV2 = -999.0;
  Float_t	FatJet_btagDDBvL = -999.0;
  Float_t	FatJet_btagDDBvL_noMD = -999.0;
  Float_t	FatJet_btagDDCvB = -999.0;
  Float_t	FatJet_btagDDCvB_noMD = -999.0;
  Float_t	FatJet_btagDDCvL = -999.0;
  Float_t	FatJet_btagDDCvL_noMD = -999.0;
  Float_t	FatJet_btagDeepB = -999.0;
  Float_t	FatJet_btagHbb = -999.0;
  Float_t	FatJet_deepTagMD_H4qvsQCD = -999.0;
  Float_t	FatJet_deepTagMD_HbbvsQCD = -999.0;
  Float_t	FatJet_deepTagMD_TvsQCD = -999.0;
  Float_t	FatJet_deepTagMD_WvsQCD = -999.0;
  Float_t	FatJet_deepTagMD_ZHbbvsQCD = -999.0;
  Float_t	FatJet_deepTagMD_ZHccvsQCD = -999.0;
  Float_t	FatJet_deepTagMD_ZbbvsQCD = -999.0;
  Float_t	FatJet_deepTagMD_ZvsQCD = -999.0;
  Float_t	FatJet_deepTagMD_bbvsLight = -999.0;
  Float_t	FatJet_deepTagMD_ccvsLight = -999.0;
  Float_t	FatJet_deepTag_H = -999.0;
  Float_t	FatJet_deepTag_QCD = -999.0;
  Float_t	FatJet_deepTag_QCDothers = -999.0;
  Float_t	FatJet_deepTag_TvsQCD = -999.0;
  Float_t	FatJet_deepTag_WvsQCD = -999.0;
  Float_t	FatJet_deepTag_ZvsQCD = -999.0;
  Int_t	FatJet_electronIdx3SJ = -999;
  Float_t	FatJet_eta = -999.0;
  Int_t FatJet_genJetAK8Idx = -999;
  Int_t	FatJet_hadronFlavour = -999;
  Int_t	FatJet_jetId = -999;
  Float_t	FatJet_lsf3 = -999.0;
  Float_t	FatJet_mass = -999.0;
  Float_t	FatJet_msoftdrop = -999.0;
  Int_t	FatJet_muonIdx3SJ = -999;
  Float_t	FatJet_n2b1 = -999.0;
  Float_t	FatJet_n3b1 = -999.0;
  UChar_t	FatJet_nBHadrons ;
  UChar_t	FatJet_nCHadrons ;
  Float_t	FatJet_particleNetMD_QCD = -999.0;
  Float_t	FatJet_particleNetMD_Xbb = -999.0;
  Float_t	FatJet_particleNetMD_Xcc = -999.0;
  Float_t	FatJet_particleNetMD_Xqq = -999.0;
  Float_t	FatJet_particleNet_H4qvsQCD = -999.0;
  Float_t	FatJet_particleNet_HbbvsQCD = -999.0;
  Float_t	FatJet_particleNet_HccvsQCD = -999.0;
  Float_t	FatJet_particleNet_QCD = -999.0;
  Float_t	FatJet_particleNet_TvsQCD = -999.0;
  Float_t	FatJet_particleNet_WvsQCD = -999.0;
  Float_t	FatJet_particleNet_ZvsQCD = -999.0;
  Float_t	FatJet_phi = -999.0;
  Float_t	FatJet_pt = -999.0;
  Float_t	FatJet_rawFactor = -999.0;
  Int_t FatJet_subJetIdx1 = -999;
  Int_t	FatJet_subJetIdx2 = -999;
  Float_t	FatJet_tau1 = -999.0;
  Float_t	FatJet_tau2 = -999.0;
  Float_t	FatJet_tau3 = -999.0;
  Float_t	FatJet_tau4 = -999.0;
  UInt_t	nFatJet = -999; 






  float test = -999.0;
  float AK4_Jet1_pt = -999.0;
  float AK4_Jet2_pt = -999.0;
  float AK4_Jet3_pt = -999.0;
  float AK4_Jet4_pt = -999.0;

  float AK4_Jet1_eta = -999.0;
  float AK4_Jet2_eta = -999.0;
  float AK4_Jet3_eta = -999.0;
  float AK4_Jet4_eta = -999.0;

  float AK4_Jet1_phi = -999.0;
  float AK4_Jet2_phi = -999.0;
  float AK4_Jet3_phi = -999.0;
  float AK4_Jet4_phi = -999.0;

  float AK4_Jet1_E = -999.0;
  float AK4_Jet2_E = -999.0;
  float AK4_Jet3_E = -999.0;
  float AK4_Jet4_E = -999.0;

  float AK4_Jet1_M = -999.0;
  float AK4_Jet2_M = -999.0;
  float AK4_Jet3_M = -999.0;
  float AK4_Jet4_M = -999.0;

  float TwoLeadingJets_pt = -999.0;
  float TwoLeadingJets_eta = -999.0;
  float TwoLeadingJets_phi = -999.0;
  float TwoLeadingJets_m = -999.0;
  float TwoLeadingJets_E = -999.0;

  float ThirdFourthJets_pt = -999.0;
  float ThirdFourthJets_eta = -999.0;
  float ThirdFourthJets_phi = -999.0;
  float ThirdFourthJets_m = -999.0;
  float ThirdFourthJets_E = -999.0;

  float FourJets_pt = -999.0;
  float FourJets_eta = -999.0;
  float FourJets_phi = -999.0;
  float FourJets_m = -999.0;
  float FourJets_E = -999.0;

  // float AK8_Jet1_pt = -999.0;
  // float AK8_Jet2_pt = -999.0;
  // float AK8_Jet3_pt = -999.0;
  // float AK8_Jet4_pt = -999.0;

  // float AK8_Jet1_eta = -999.0;
  // float AK8_Jet2_eta = -999.0;
  // float AK8_Jet3_eta = -999.0;
  // float AK8_Jet4_eta = -999.0;

  // float AK8_Jet1_phi = -999.0;
  // float AK8_Jet2_phi = -999.0;
  // float AK8_Jet3_phi = -999.0;
  // float AK8_Jet4_phi = -999.0;


  //------------------------------------//
  //       METADATA AND EVENT WEIGHTS   //
  //------------------------------------//

  uint run = 0;
  uint ls = 0;
  uint evt = 0;
  // float nPV = -999.0;
  float nPU_mean = -999.0;
  float genWeight = -999.0;
  float puWeight = -999.0;
  float puWeight_Up = -999.0;
  float puWeight_Dn = -999.0;
  float L1PFWeight = -999.0;
  float LHEWeight[1164] = {};
  uint nScaleWeight;
  uint nPdfWeight;
  float scaleWeight[200] = {};
  float pdfWeight[200] = {};

  //btag counters
  uint nBtag_loose;
  uint nBtag_medium;
  uint nBtag_tight;

  float btagWeight = -999.0;

  //triggers
  bool trigger_1Pho = false;
  bool trigger_2Pho = false;

  //signal vs anti-iso
  bool isAntiIso = -999.0;

  //------------------------------------//
  //       LEPTONS                      //
  //------------------------------------//

  //photon 1
  float pho1_pt = -999.0;
  float pho1_eta = -999.0;
  float pho1_phi = -999.0;
  float pho1_m = -999.0;
  float pho1_q = -999.0;
  float pho1_iso = -999.0;
  float pho1_dxy = -999.0;
  float pho1_dz = -999.0;
  float pho1_idEffWeight = -999.0;
  float pho1_E = -999.0;
  //photon 1 scale variations
  float pho1_pt_scaleUp = -999.0;
  float pho1_pt_scaleDn = -999.0;

  //photon 2
  float pho2_pt = -999.0;
  float pho2_eta = -999.0;
  float pho2_phi = -999.0;
  float pho2_m = -999.0;
  float pho2_q = -999.0;
  float pho2_iso = -999.0;
  float pho2_dxy = -999.0;
  float pho2_dz = -999.0;
  float pho2_idEffWeight = -999.0;
  float pho2_E = -999.0;
  //photon 2 scale variations
  float pho2_pt_scaleUp = -999.0;
  float pho2_pt_scaleDn = -999.0;

  //diphoton final state
  float diphoton_m = -999.0;
  float diphoton_pt = -999.0;
  float diphoton_eta = -999.0;
  float diphoton_phi = -999.0;
  float diphoton_E = -999.0;
  //diphoton scale variations
  float diphoton_m_scaleUp = -999.0;
  float diphoton_m_scaleDn = -999.0;
  float diphoton_pt_scaleUp = -999.0;
  float diphoton_pt_scaleDn = -999.0;

  float Higgs_PuppiAK8_m_sd0 = -999.0;
  float Higgs_PuppiAK8_m_sd0_corr = -999.0;
  float Higgs_PuppiAK8_tau2tau1 = -999.0;
  float Higgs_PuppiAK8_pt = -999.0;
  float Higgs_PuppiAK8_eta = -999.0;
  float Higgs_PuppiAK8_phi = -999.0;
  float Higgs_PuppiAK8_m_sd0_corr_scaleUp = -999.0;
  float Higgs_PuppiAK8_m_sd0_corr_scaleDn = -999.0;
  float Higgs_PuppiAK8_pt_scaleUp = -999.0;
  float Higgs_PuppiAK8_pt_scaleDn = -999.0;

};

#endif
