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

  //photon 2 scale variations
  float pho2_pt_scaleUp = -999.0;
  float pho2_pt_scaleDn = -999.0;

  //diphoton final state
  float diphoton_m = -999.0;
  float diphoton_pt = -999.0;
  float diphoton_eta = -999.0;
  float diphoton_phi = -999.0;

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
