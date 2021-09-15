#ifndef WVJJ_DATA_HH
#define WVJJ_DATA_HH

#include "TTree.h"

class WVJJData {

public:

  WVJJData(TTree *t) {
    fTree = t;
    init();
  };

  ~WVJJData() {
    delete fTree;
  };

  void clearVars();
  void init();

  TTree *fTree;

  //------------------------------------//
  //       METADATA AND EVENT WEIGHTS   //
  //------------------------------------//

  uint run;
  uint ls;
  uint long evt;
  float nPV;
  float nPU_mean;
  float genWeight;
  float puWeight;
  float puWeight_Up;
  float puWeight_Down;
  float L1PFWeight;
  float L1PFWeight_Up;
  float L1PFWeight_Down;
  uint nScaleWeight;
  uint nPdfWeight;
  uint nAqgcWeight;
  float scaleWeight[200] = {};
  float pdfWeight[200] = {};
  float aqgcWeight[1000] = {};

  // tZq veto ZV
  bool is_tZq;

  //njet counters
  uint nAK4Jet30;
  uint nAK4Jet50;
  uint nJet30_noClean;
  uint nJet50_noClean;
  uint nGoodAK4jets;

  //btag counters
  uint nAK4Btag_loose;
  uint nAK4Btag_medium;
  uint nAK4Btag_tight;

  float btagWeight_loose;
  float btagWeight_loose_Up;
  float btagWeight_loose_Down;
  float btagWeight_medium;
  float btagWeight_medium_Up;
  float btagWeight_medium_Down;
  float btagWeight_tight;
  float btagWeight_tight_Up;
  float btagWeight_tight_Down;

  //triggers
  bool trigger_1Mu;
  bool trigger_2Mu;
  bool trigger_1El;
  bool trigger_2El;
  bool trigger_2Pho;

  //signal vs anti-iso
  bool isAntiIso;
  float lepFakeRate;

  //------------------------------------//
  //       LEPTONS                      //
  //------------------------------------//

  //lepton 1
  float lep1_pt;
  float lep1_eta;
  float lep1_phi;
  float lep1_m;
  float lep1_q;
  float lep1_iso;
  float lep1_dxy;
  float lep1_dz;
  float lep1_sip3d;
  float lep1_idEffWeight;
  float lep1_trigEffWeight;

  //lepton 1 scale variations
  float lep1_pt_scaleUp;
  float lep1_pt_scaleDown;

  //lepton 2
  float lep2_pt;
  float lep2_eta;
  float lep2_phi;
  float lep2_m;
  float lep2_q;
  float lep2_iso;
  float lep2_dxy;
  float lep2_dz;
  float lep2_sip3d;
  float lep2_idEffWeight;
  float lep2_trigEffWeight;

  //lepton 2 scale variations
  float lep2_pt_scaleUp;
  float lep2_pt_scaleDown;

  //dilepton final state
  float dilep_m;
  float dilep_mt;
  float dilep_pt;
  float dilep_eta;
  float dilep_phi;

  //dilepton JES variations
  float dilep_m_jesFlavorQCDUp;
  float dilep_m_jesFlavorQCDDown;
  float dilep_m_jesRelativeBalUp;
  float dilep_m_jesRelativeBalDown;
  float dilep_m_jesHFUp;
  float dilep_m_jesHFDown;
  float dilep_m_jesBBEC1Up;
  float dilep_m_jesBBEC1Down;
  float dilep_m_jesEC2Up;
  float dilep_m_jesEC2Down;
  float dilep_m_jesAbsoluteUp;
  float dilep_m_jesAbsoluteDown;
  float dilep_m_jesBBEC1_YearUp;
  float dilep_m_jesBBEC1_YearDown;
  float dilep_m_jesEC2_YearUp;
  float dilep_m_jesEC2_YearDown;
  float dilep_m_jesAbsolute_YearUp;
  float dilep_m_jesAbsolute_YearDown;
  float dilep_m_jesHF_YearUp;
  float dilep_m_jesHF_YearDown;
  float dilep_m_jesRelativeSample_YearUp;
  float dilep_m_jesRelativeSample_YearDown;
  float dilep_m_jesTotalUp;
  float dilep_m_jesTotalDown;

  float dilep_mt_jesFlavorQCDUp;
  float dilep_mt_jesFlavorQCDDown;
  float dilep_mt_jesRelativeBalUp;
  float dilep_mt_jesRelativeBalDown;
  float dilep_mt_jesHFUp;
  float dilep_mt_jesHFDown;
  float dilep_mt_jesBBEC1Up;
  float dilep_mt_jesBBEC1Down;
  float dilep_mt_jesEC2Up;
  float dilep_mt_jesEC2Down;
  float dilep_mt_jesAbsoluteUp;
  float dilep_mt_jesAbsoluteDown;
  float dilep_mt_jesBBEC1_YearUp;
  float dilep_mt_jesBBEC1_YearDown;
  float dilep_mt_jesEC2_YearUp;
  float dilep_mt_jesEC2_YearDown;
  float dilep_mt_jesAbsolute_YearUp;
  float dilep_mt_jesAbsolute_YearDown;
  float dilep_mt_jesHF_YearUp;
  float dilep_mt_jesHF_YearDown;
  float dilep_mt_jesRelativeSample_YearUp;
  float dilep_mt_jesRelativeSample_YearDown;
  float dilep_mt_jesTotalUp;
  float dilep_mt_jesTotalDown;

  float dilep_pt_jesFlavorQCDUp;
  float dilep_pt_jesFlavorQCDDown;
  float dilep_pt_jesRelativeBalUp;
  float dilep_pt_jesRelativeBalDown;
  float dilep_pt_jesHFUp;
  float dilep_pt_jesHFDown;
  float dilep_pt_jesBBEC1Up;
  float dilep_pt_jesBBEC1Down;
  float dilep_pt_jesEC2Up;
  float dilep_pt_jesEC2Down;
  float dilep_pt_jesAbsoluteUp;
  float dilep_pt_jesAbsoluteDown;
  float dilep_pt_jesBBEC1_YearUp;
  float dilep_pt_jesBBEC1_YearDown;
  float dilep_pt_jesEC2_YearUp;
  float dilep_pt_jesEC2_YearDown;
  float dilep_pt_jesAbsolute_YearUp;
  float dilep_pt_jesAbsolute_YearDown;
  float dilep_pt_jesHF_YearUp;
  float dilep_pt_jesHF_YearDown;
  float dilep_pt_jesRelativeSample_YearUp;
  float dilep_pt_jesRelativeSample_YearDown;
  float dilep_pt_jesTotalUp;
  float dilep_pt_jesTotalDown;

  //dilepton lepton scale variations
  float dilep_m_scaleUp;
  float dilep_m_scaleDown;
  float dilep_mt_scaleUp;
  float dilep_mt_scaleDown;
  float dilep_pt_scaleUp;
  float dilep_pt_scaleDown;


  // Photons
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
  float pho1_pt_byMgg = -999.0;
  float pho1_E_byMgg = -999.0;
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
  float pho2_pt_byMgg = -999.0;
  float pho2_E_byMgg = -999.0;

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
  float pho1_mvaID_Fall17V1p1 = -999.0;
  float pho2_mvaID_Fall17V1p1 = -999.0;
  float pho1_mvaID_WP80 = -999.0;
  float pho2_mvaID_WP80 = -999.0;
  float pho1_mvaID_WP90 = -999.0;
  float pho2_mvaID_WP90 = -999.0;
  float pho1_mvaIDFall17V1 = -999.0;
  float pho1_mvaIDFall17V2 = -999.0;
  float pho2_mvaIDFall17V1 = -999.0;
  float pho2_mvaIDFall17V2 = -999.0;


  //------------------------------------//
  //       MET                          //
  //------------------------------------//

  float MET;
  float MET_phi;
  float MET_2017;

  float MET_jesFlavorQCDUp;
  float MET_jesFlavorQCDDown;
  float MET_jesRelativeBalUp;
  float MET_jesRelativeBalDown;
  float MET_jesHFUp;
  float MET_jesHFDown;
  float MET_jesBBEC1Up;
  float MET_jesBBEC1Down;
  float MET_jesEC2Up;
  float MET_jesEC2Down;
  float MET_jesAbsoluteUp;
  float MET_jesAbsoluteDown;
  float MET_jesBBEC1_YearUp;
  float MET_jesBBEC1_YearDown;
  float MET_jesEC2_YearUp;
  float MET_jesEC2_YearDown;
  float MET_jesAbsolute_YearUp;
  float MET_jesAbsolute_YearDown;
  float MET_jesHF_YearUp;
  float MET_jesHF_YearDown;
  float MET_jesRelativeSample_YearUp;
  float MET_jesRelativeSample_YearDown;
  float MET_jesTotalUp;
  float MET_jesTotalDown;

  float MET_phi_jesFlavorQCDUp;
  float MET_phi_jesFlavorQCDDown;
  float MET_phi_jesRelativeBalUp;
  float MET_phi_jesRelativeBalDown;
  float MET_phi_jesHFUp;
  float MET_phi_jesHFDown;
  float MET_phi_jesBBEC1Up;
  float MET_phi_jesBBEC1Down;
  float MET_phi_jesEC2Up;
  float MET_phi_jesEC2Down;
  float MET_phi_jesAbsoluteUp;
  float MET_phi_jesAbsoluteDown;
  float MET_phi_jesBBEC1_YearUp;
  float MET_phi_jesBBEC1_YearDown;
  float MET_phi_jesEC2_YearUp;
  float MET_phi_jesEC2_YearDown;
  float MET_phi_jesAbsolute_YearUp;
  float MET_phi_jesAbsolute_YearDown;
  float MET_phi_jesHF_YearUp;
  float MET_phi_jesHF_YearDown;
  float MET_phi_jesRelativeSample_YearUp;
  float MET_phi_jesRelativeSample_YearDown;
  float MET_phi_jesTotalUp;
  float MET_phi_jesTotalDown;


  float PuppiMET;
  float PuppiMET_phi;

  //W neutrino pZ
  float neu_pz_type0;

  //------------------------------------//
  //       AK4 Jets                     //
  //------------------------------------//

  float FullyResolved_allAK4JetsSum_pt = -999.0;
  float FullyResolved_Jet1_pt = -999.0;
  float FullyResolved_Jet2_pt = -999.0;
  float FullyResolved_Jet3_pt = -999.0;
  float FullyResolved_Jet4_pt = -999.0;

  float FullyResolved_Jet1_eta = -999.0;
  float FullyResolved_Jet2_eta = -999.0;
  float FullyResolved_Jet3_eta = -999.0;
  float FullyResolved_Jet4_eta = -999.0;

  float FullyResolved_Jet1_phi = -999.0;
  float FullyResolved_Jet2_phi = -999.0;
  float FullyResolved_Jet3_phi = -999.0;
  float FullyResolved_Jet4_phi = -999.0;

  float FullyResolved_Jet1_E = -999.0;
  float FullyResolved_Jet2_E = -999.0;
  float FullyResolved_Jet3_E = -999.0;
  float FullyResolved_Jet4_E = -999.0;

  float FullyResolved_Jet1_M = -999.0;
  float FullyResolved_Jet2_M = -999.0;
  float FullyResolved_Jet3_M = -999.0;
  float FullyResolved_Jet4_M = -999.0;

  float FullyResolved_TwoLeadingJets_pt = -999.0;
  float FullyResolved_TwoLeadingJets_eta = -999.0;
  float FullyResolved_TwoLeadingJets_phi = -999.0;
  float FullyResolved_TwoLeadingJets_m = -999.0;
  float FullyResolved_TwoLeadingJets_E = -999.0;

  float FullyResolved_ThirdFourthJets_pt = -999.0;
  float FullyResolved_ThirdFourthJets_eta = -999.0;
  float FullyResolved_ThirdFourthJets_phi = -999.0;
  float FullyResolved_ThirdFourthJets_m = -999.0;
  float FullyResolved_ThirdFourthJets_E = -999.0;

  float FullyResolved_FourJets_pt = -999.0;
  float FullyResolved_FourJets_eta = -999.0;
  float FullyResolved_FourJets_phi = -999.0;
  float FullyResolved_FourJets_m = -999.0;
  float FullyResolved_FourJets_E = -999.0;


};

#endif
