#include "DoubleHiggs/Selection/interface/output.hh"

void output::init() {

  clearVars();

  fTree->Branch("test",&test,"test/F");
  fTree->Branch("nTagJets",&nTagJets,"nTagJets/F");
  fTree->Branch("allAK4JetsSum_pt",&allAK4JetsSum_pt,"allAK4JetsSum_pt/F");
  fTree->Branch("allAK8JetsSum_pt",&allAK8JetsSum_pt,"allAK8JetsSum_pt/F");
  fTree->Branch("nGoodFatjet",&nGoodFatjet,"nGoodFatjet/F");

fTree->Branch("FatJet_area	",&	FatJet_area	,"	FatJet_area	");
fTree->Branch("FatJet_btagCMVA	",&	FatJet_btagCMVA	,"	FatJet_btagCMVA	");
fTree->Branch("FatJet_btagCSVV2	",&	FatJet_btagCSVV2	,"	FatJet_btagCSVV2	");
fTree->Branch("FatJet_btagDDBvL	",&	FatJet_btagDDBvL	,"	FatJet_btagDDBvL	");
fTree->Branch("FatJet_btagDDBvL_noMD	",&	FatJet_btagDDBvL_noMD	,"FatJet_btagDDBvL_noMD");
fTree->Branch("FatJet_btagDDCvB	",&	FatJet_btagDDCvB	,"	FatJet_btagDDCvB	");
fTree->Branch("FatJet_btagDDCvB_noMD	",&	FatJet_btagDDCvB_noMD	,"FatJet_btagDDCvB_noMD	");
fTree->Branch("FatJet_btagDDCvL	",&	FatJet_btagDDCvL	,"	FatJet_btagDDCvL	");
fTree->Branch("FatJet_btagDDCvL_noMD	",&	FatJet_btagDDCvL_noMD	,"FatJet_btagDDCvL_noMD	");
fTree->Branch("FatJet_btagDeepB	",&	FatJet_btagDeepB	,"	FatJet_btagDeepB	");
fTree->Branch("FatJet_btagHbb	",&	FatJet_btagHbb	,"	FatJet_btagHbb	");
fTree->Branch("FatJet_deepTagMD_H4qvsQCD	",&	FatJet_deepTagMD_H4qvsQCD	,"	FatJet_deepTagMD_H4qvsQCD	");
fTree->Branch("FatJet_deepTagMD_HbbvsQCD	",&	FatJet_deepTagMD_HbbvsQCD	,"	FatJet_deepTagMD_HbbvsQCD	");
fTree->Branch("FatJet_deepTagMD_TvsQCD	",&	FatJet_deepTagMD_TvsQCD	,"	FatJet_deepTagMD_TvsQCD	");
fTree->Branch("FatJet_deepTagMD_WvsQCD	",&	FatJet_deepTagMD_WvsQCD	,"	FatJet_deepTagMD_WvsQCD	");
fTree->Branch("FatJet_deepTagMD_ZHbbvsQCD	",&	FatJet_deepTagMD_ZHbbvsQCD	,"	FatJet_deepTagMD_ZHbbvsQCD	");
fTree->Branch("FatJet_deepTagMD_ZHccvsQCD	",&	FatJet_deepTagMD_ZHccvsQCD	,"	FatJet_deepTagMD_ZHccvsQCD	");
fTree->Branch("FatJet_deepTagMD_ZbbvsQCD	",&	FatJet_deepTagMD_ZbbvsQCD	,"	FatJet_deepTagMD_ZbbvsQCD	");
fTree->Branch("FatJet_deepTagMD_ZvsQCD	",&	FatJet_deepTagMD_ZvsQCD	,"	FatJet_deepTagMD_ZvsQCD	");
fTree->Branch("FatJet_deepTagMD_bbvsLight	",&	FatJet_deepTagMD_bbvsLight	,"	FatJet_deepTagMD_bbvsLight	");
fTree->Branch("FatJet_deepTagMD_ccvsLight	",&	FatJet_deepTagMD_ccvsLight	,"	FatJet_deepTagMD_ccvsLight	");
fTree->Branch("FatJet_deepTag_H	",&	FatJet_deepTag_H	,"	FatJet_deepTag_H	");
fTree->Branch("FatJet_deepTag_QCD	",&	FatJet_deepTag_QCD	,"	FatJet_deepTag_QCD	");
fTree->Branch("FatJet_deepTag_QCDothers	",&	FatJet_deepTag_QCDothers	,"	FatJet_deepTag_QCDothers	");
fTree->Branch("FatJet_deepTag_TvsQCD	",&	FatJet_deepTag_TvsQCD	,"	FatJet_deepTag_TvsQCD	");
fTree->Branch("FatJet_deepTag_WvsQCD	",&	FatJet_deepTag_WvsQCD	,"	FatJet_deepTag_WvsQCD	");
fTree->Branch("FatJet_deepTag_ZvsQCD	",&	FatJet_deepTag_ZvsQCD	,"	FatJet_deepTag_ZvsQCD	");
fTree->Branch("FatJet_electronIdx3SJ	",&	FatJet_electronIdx3SJ	,"	FatJet_electronIdx3SJ	");
fTree->Branch("FatJet_eta	",&	FatJet_eta	,"	FatJet_eta	");
fTree->Branch("FatJet_genJetAK8Idx	",&	FatJet_genJetAK8Idx	,"	FatJet_genJetAK8Idx	");
fTree->Branch("FatJet_hadronFlavour	",&	FatJet_hadronFlavour	,"	FatJet_hadronFlavour	");
fTree->Branch("FatJet_jetId	",&	FatJet_jetId	,"	FatJet_jetId	");
fTree->Branch("FatJet_lsf3	",&	FatJet_lsf3	,"	FatJet_lsf3	");
fTree->Branch("FatJet_mass	",&	FatJet_mass	,"	FatJet_mass	");
fTree->Branch("FatJet_msoftdrop	",&	FatJet_msoftdrop	,"	FatJet_msoftdrop	");
fTree->Branch("FatJet_muonIdx3SJ	",&	FatJet_muonIdx3SJ	,"	FatJet_muonIdx3SJ	");
fTree->Branch("FatJet_n2b1	",&	FatJet_n2b1	,"	FatJet_n2b1	");
fTree->Branch("FatJet_n3b1	",&	FatJet_n3b1	,"	FatJet_n3b1	");
fTree->Branch("FatJet_nBHadrons	",&	FatJet_nBHadrons	,"	FatJet_nBHadrons	");
fTree->Branch("FatJet_nCHadrons	",&	FatJet_nCHadrons	,"	FatJet_nCHadrons	");
fTree->Branch("FatJet_particleNetMD_QCD	",&	FatJet_particleNetMD_QCD	,"	FatJet_particleNetMD_QCD	");
fTree->Branch("FatJet_particleNetMD_Xbb	",&	FatJet_particleNetMD_Xbb	,"	FatJet_particleNetMD_Xbb	");
fTree->Branch("FatJet_particleNetMD_Xcc	",&	FatJet_particleNetMD_Xcc	,"	FatJet_particleNetMD_Xcc	");
fTree->Branch("FatJet_particleNetMD_Xqq	",&	FatJet_particleNetMD_Xqq	,"	FatJet_particleNetMD_Xqq	");
fTree->Branch("FatJet_particleNet_H4qvsQCD	",&	FatJet_particleNet_H4qvsQCD	,"	FatJet_particleNet_H4qvsQCD	");
fTree->Branch("FatJet_particleNet_HbbvsQCD	",&	FatJet_particleNet_HbbvsQCD	,"	FatJet_particleNet_HbbvsQCD	");
fTree->Branch("FatJet_particleNet_HccvsQCD	",&	FatJet_particleNet_HccvsQCD	,"	FatJet_particleNet_HccvsQCD	");
fTree->Branch("FatJet_particleNet_QCD	",&	FatJet_particleNet_QCD	,"	FatJet_particleNet_QCD	");
fTree->Branch("FatJet_particleNet_TvsQCD	",&	FatJet_particleNet_TvsQCD	,"	FatJet_particleNet_TvsQCD	");
fTree->Branch("FatJet_particleNet_WvsQCD	",&	FatJet_particleNet_WvsQCD	,"	FatJet_particleNet_WvsQCD	");
fTree->Branch("FatJet_particleNet_ZvsQCD	",&	FatJet_particleNet_ZvsQCD	,"	FatJet_particleNet_ZvsQCD	");
fTree->Branch("FatJet_phi	",&	FatJet_phi	,"	FatJet_phi	");
fTree->Branch("FatJet_pt	",&	FatJet_pt	,"	FatJet_pt	");
fTree->Branch("FatJet_rawFactor	",&	FatJet_rawFactor	,"	FatJet_rawFactor	");
fTree->Branch("FatJet_subJetIdx1	",&	FatJet_subJetIdx1	,"	FatJet_subJetIdx1	");
fTree->Branch("FatJet_subJetIdx2	",&	FatJet_subJetIdx2	,"	FatJet_subJetIdx2	");
fTree->Branch("FatJet_tau1	",&	FatJet_tau1	,"	FatJet_tau1	");
fTree->Branch("FatJet_tau2	",&	FatJet_tau2	,"	FatJet_tau2	");
fTree->Branch("FatJet_tau3	",&	FatJet_tau3	,"	FatJet_tau3	");
fTree->Branch("FatJet_tau4	",&	FatJet_tau4	,"	FatJet_tau4	");
fTree->Branch("nFatJet	",&	nFatJet	,"	nFatJet	");


  fTree->Branch("AK4_Jet1_pt",&AK4_Jet1_pt,"AK4_Jet1_pt/F");
  fTree->Branch("AK4_Jet2_pt",&AK4_Jet2_pt,"AK4_Jet2_pt/F");
  fTree->Branch("AK4_Jet3_pt",&AK4_Jet3_pt,"AK4_Jet3_pt/F");
  fTree->Branch("AK4_Jet4_pt",&AK4_Jet4_pt,"AK4_Jet4_pt/F");

  fTree->Branch("AK4_Jet1_eta",&AK4_Jet1_eta,"AK4_Jet1_eta/F");
  fTree->Branch("AK4_Jet2_eta",&AK4_Jet2_eta,"AK4_Jet2_eta/F");
  fTree->Branch("AK4_Jet3_eta",&AK4_Jet3_eta,"AK4_Jet3_eta/F");
  fTree->Branch("AK4_Jet4_eta",&AK4_Jet4_eta,"AK4_Jet4_eta/F");

  fTree->Branch("AK4_Jet1_phi",&AK4_Jet1_phi,"AK4_Jet1_phi/F");
  fTree->Branch("AK4_Jet2_phi",&AK4_Jet2_phi,"AK4_Jet2_phi/F");
  fTree->Branch("AK4_Jet3_phi",&AK4_Jet3_phi,"AK4_Jet3_phi/F");
  fTree->Branch("AK4_Jet4_phi",&AK4_Jet4_phi,"AK4_Jet4_phi/F");

  fTree->Branch("AK4_Jet1_E",&AK4_Jet1_E,"AK4_Jet1_E/F");
  fTree->Branch("AK4_Jet2_E",&AK4_Jet2_E,"AK4_Jet2_E/F");
  fTree->Branch("AK4_Jet3_E",&AK4_Jet3_E,"AK4_Jet3_E/F");
  fTree->Branch("AK4_Jet4_E",&AK4_Jet4_E,"AK4_Jet4_E/F");

  fTree->Branch("AK4_Jet1_M",&AK4_Jet1_M,"AK4_Jet1_M/F");
  fTree->Branch("AK4_Jet2_M",&AK4_Jet2_M,"AK4_Jet2_M/F");
  fTree->Branch("AK4_Jet3_M",&AK4_Jet3_M,"AK4_Jet3_M/F");
  fTree->Branch("AK4_Jet4_M",&AK4_Jet4_M,"AK4_Jet4_M/F");

  fTree->Branch("TwoLeadingJets_pt",&TwoLeadingJets_pt,"TwoLeadingJets_pt/F");
  fTree->Branch("TwoLeadingJets_eta",&TwoLeadingJets_eta,"TwoLeadingJets_eta/F");
  fTree->Branch("TwoLeadingJets_phi",&TwoLeadingJets_phi,"TwoLeadingJets_phi/F");
  fTree->Branch("TwoLeadingJets_m",&TwoLeadingJets_m,"TwoLeadingJets_m/F");
  fTree->Branch("TwoLeadingJets_E",&TwoLeadingJets_E,"TwoLeadingJets_E/F");

  fTree->Branch("ThirdFourthJets_pt",&ThirdFourthJets_pt,"ThirdFourthJets_pt/F");
  fTree->Branch("ThirdFourthJets_eta",&ThirdFourthJets_eta,"ThirdFourthJets_eta/F");
  fTree->Branch("ThirdFourthJets_phi",&ThirdFourthJets_phi,"ThirdFourthJets_phi/F");
  fTree->Branch("ThirdFourthJets_m",&ThirdFourthJets_m,"ThirdFourthJets_m/F");
  fTree->Branch("ThirdFourthJets_E",&ThirdFourthJets_E,"ThirdFourthJets_E/F");

  fTree->Branch("FourJets_pt",&FourJets_pt,"FourJets_pt/F");
  fTree->Branch("FourJets_eta",&FourJets_eta,"FourJets_eta/F");
  fTree->Branch("FourJets_phi",&FourJets_phi,"FourJets_phi/F");
  fTree->Branch("FourJets_m",&FourJets_m,"FourJets_m/F");
  fTree->Branch("FourJets_E",&FourJets_E,"FourJets_E/F");

  //metadata and weights
  fTree->Branch("run",&run,"run/I");
  fTree->Branch("ls",&ls,"ls/I");
  fTree->Branch("evt",&evt,"evt/I");
  // fTree->Branch("nPV",&nPV,"nPV/F");
  fTree->Branch("nPU_mean",&nPU_mean,"nPU_mean/F");
  fTree->Branch("genWeight",&genWeight,"genWeight/F");
  fTree->Branch("puWeight",&puWeight,"puWeight/F");
  fTree->Branch("puWeight_Up",&puWeight_Up,"puWeight_Up/F");
  fTree->Branch("puWeight_Dn",&puWeight_Dn,"puWeight_Dn/F");
  fTree->Branch("L1PFWeight",&L1PFWeight,"L1PFWeight/F");
  fTree->Branch("LHEWeight",&LHEWeight[0],"LHEWeight[1164]/F");
  fTree->Branch("nScaleWeight",&nScaleWeight,"nScaleWeight/I");
  fTree->Branch("nPdfWeight",&nPdfWeight,"nPdfWeight/I");
  fTree->Branch("scaleWeight",&scaleWeight[0],"scaleWeight[200]/F");
  fTree->Branch("pdfWeight",&pdfWeight[0],"pdfWeight[200]/F");
  //btag counters
  fTree->Branch("nBtag_loose",&nBtag_loose,"nBtag_loose/I");
  fTree->Branch("nBtag_medium",&nBtag_medium,"nBtag_medium/I");
  fTree->Branch("nBtag_tight",&nBtag_tight,"nBtag_tight/I");
  fTree->Branch("btagWeight",&btagWeight,"btagWeight/F");
  //trigger
  fTree->Branch("trigger_1Pho",&trigger_1Pho,"trigger_1Pho/O");
  fTree->Branch("trigger_2Pho",&trigger_2Pho,"trigger_2Pho/O");

  fTree->Branch("isAntiIso",&isAntiIso,"isAntiIso/O");
  //lepton 1
  fTree->Branch("pho1_pt",&pho1_pt,"pho1_pt/F");
  fTree->Branch("pho1_eta",&pho1_eta,"pho1_eta/F");
  fTree->Branch("pho1_phi",&pho1_phi,"pho1_phi/F");
  fTree->Branch("pho1_m",&pho1_m,"pho1_m/F");
  fTree->Branch("pho1_q",&pho1_q,"pho1_q/F");
  fTree->Branch("pho1_iso",&pho1_iso,"pho1_iso/F");
  fTree->Branch("pho1_dxy",&pho1_dxy,"pho1_dxy/F");
  fTree->Branch("pho1_dz",&pho1_dz,"pho1_dz/F");
  fTree->Branch("pho1_E",&pho1_E,"pho1_E/F");
  fTree->Branch("pho1_idEffWeight",&pho1_idEffWeight,"pho1_idEffWeight/F");
  //lepton 1 scale variations
  fTree->Branch("pho1_pt_scaleUp",&pho1_pt_scaleUp,"pho1_pt_scaleUp/F");
  fTree->Branch("pho1_pt_scaleDn",&pho1_pt_scaleDn,"pho1_pt_scaleDn/F");

  fTree->Branch("pho1_mvaIDFall17V2",&pho1_mvaIDFall17V2,"pho1_mvaIDFall17V2/F");
  fTree->Branch("pho1_mvaIDFall17V1",&pho1_mvaIDFall17V1,"pho1_mvaIDFall17V1/F");
  fTree->Branch("pho1_mvaID_WP80",&pho1_mvaID_WP80,"pho1_mvaID_WP80/F");
  fTree->Branch("pho1_mvaID_WP90",&pho1_mvaID_WP90,"pho1_mvaID_WP90/F");
  fTree->Branch("pho1_pt_byMgg",&pho1_pt_byMgg,"pho1_pt_byMgg/F");
  fTree->Branch("pho1_E_byMgg",&pho1_E_byMgg,"pho1_E_byMgg/F");

  //lepton 2
  fTree->Branch("pho2_pt",&pho2_pt,"pho2_pt/F");
  fTree->Branch("pho2_eta",&pho2_eta,"pho2_eta/F");
  fTree->Branch("pho2_phi",&pho2_phi,"pho2_phi/F");
  fTree->Branch("pho2_m",&pho2_m,"pho2_m/F");
  fTree->Branch("pho2_q",&pho2_q,"pho2_q/F");
  fTree->Branch("pho2_iso",&pho2_iso,"pho2_iso/F");
  fTree->Branch("pho2_dxy",&pho2_dxy,"pho2_dxy/F");
  fTree->Branch("pho2_dz",&pho2_dz,"pho2_dz/F");
  fTree->Branch("pho2_E",&pho2_E,"pho2_E/F");
  fTree->Branch("pho2_idEffWeight",&pho2_idEffWeight,"pho2_idEffWeight/F");
  //lepton 2 scale variations
  fTree->Branch("pho2_pt_scaleUp",&pho2_pt_scaleUp,"pho2_pt_scaleUp/F");
  fTree->Branch("pho2_pt_scaleDn",&pho2_pt_scaleDn,"pho2_pt_scaleDn/F");

  fTree->Branch("pho2_mvaIDFall17V2",&pho2_mvaIDFall17V2,"pho2_mvaIDFall17V2/F");
  fTree->Branch("pho2_mvaIDFall17V1",&pho2_mvaIDFall17V1,"pho2_mvaIDFall17V1/F");
  fTree->Branch("pho2_mvaID_WP80",&pho2_mvaID_WP80,"pho2_mvaID_WP80/F");
  fTree->Branch("pho2_mvaID_WP90",&pho2_mvaID_WP90,"pho2_mvaID_WP90/F");
  fTree->Branch("pho2_pt_byMgg",&pho2_pt_byMgg,"pho2_pt_byMgg/F");
  fTree->Branch("pho2_E_byMgg",&pho2_E_byMgg,"pho2_E_byMgg/F");

  //dilepton final state
  fTree->Branch("diphoton_m",&diphoton_m,"diphoton_m/F");
  fTree->Branch("diphoton_pt",&diphoton_pt,"diphoton_pt/F");
  fTree->Branch("diphoton_eta",&diphoton_eta,"diphoton_eta/F");
  fTree->Branch("diphoton_phi",&diphoton_phi,"diphoton_phi/F");
  fTree->Branch("diphoton_E",&diphoton_E,"diphoton_E/F");
  //dilepton scale variations
  fTree->Branch("diphoton_m_scaleUp",&diphoton_m_scaleUp,"diphoton_m_scaleUp/F");
  fTree->Branch("diphoton_m_scaleDn",&diphoton_m_scaleDn,"diphoton_m_scaleDn/F");
  fTree->Branch("diphoton_pt_scaleUp",&diphoton_pt_scaleUp,"diphoton_pt_scaleUp/F");
  fTree->Branch("diphoton_pt_scaleDn",&diphoton_pt_scaleDn,"diphoton_pt_scaleDn/F");

};

void output::clearVars() {

  //------------------------------------//
  //       METADATA AND EVENT WEIGHTS   //
  //------------------------------------//

  run = 0;
  ls = 0;
  evt = 0;
  test = -999.0;
  AK4_Jet1_pt = -999.0;
  AK4_Jet2_pt = -999.0;
  AK4_Jet3_pt = -999.0;
  AK4_Jet4_pt = -999.0;

  AK4_Jet1_eta = -999.0;
  AK4_Jet2_eta = -999.0;
  AK4_Jet3_eta = -999.0;
  AK4_Jet4_eta = -999.0;

  AK4_Jet1_phi = -999.0;
  AK4_Jet2_phi = -999.0;
  AK4_Jet3_phi = -999.0;
  AK4_Jet4_phi = -999.0;

  // AK8_Jet1_pt = -999.0;
  // AK8_Jet2_pt = -999.0;
  // AK8_Jet3_pt = -999.0;
  // AK8_Jet4_pt = -999.0;

  // AK8_Jet1_eta = -999.0;
  // AK8_Jet2_eta = -999.0;
  // AK8_Jet3_eta = -999.0;
  // AK8_Jet4_eta = -999.0;

  // AK8_Jet1_phi = -999.0;
  // AK8_Jet2_phi = -999.0;
  // AK8_Jet3_phi = -999.0;
  // AK8_Jet4_phi = -999.0;


  // nPV = 0;
  nPU_mean = 0;

  genWeight = 1.0;
  puWeight = 1.0;
  puWeight_Up = 1.0;
  puWeight_Dn = 1.0;

  L1PFWeight = 1.0;

  std::fill_n(LHEWeight,1164,0);

  nScaleWeight = 0;
  nPdfWeight = 0;
  std::fill_n(scaleWeight,200,0);
  std::fill_n(pdfWeight,200,0);

  nBtag_loose = 0;
  nBtag_medium = 0;
  nBtag_tight = 0;

  btagWeight = 1.0;

  trigger_1Pho = false;
  trigger_2Pho = false;

  isAntiIso = false;

  //------------------------------------//
  //       LEPTONS                      //
  //------------------------------------//

  //lepton 1
  pho1_pt = -999.0;
  pho1_eta = -999.0;
  pho1_phi = -999.0;
  pho1_m = -999.0;
  pho1_q = -999.0;
  pho1_dxy = -999.0;
  pho1_dz = -999.0;
  pho1_iso = -999.0;
  pho1_idEffWeight = 1.0;

  //lepton 1 scale variations
  pho1_pt_scaleUp = -999.0;
  pho1_pt_scaleDn = -999.0;

  pho1_mvaIDFall17V2 = -999.0;
  pho1_mvaIDFall17V1 = -999.0;
  pho1_mvaID_WP80 = -999.0;
  pho1_mvaID_WP90 = -999.0;
  pho1_pt_byMgg = -999.0;
  pho1_E_byMgg = -999.0;

  //lepton 2
  pho2_pt = -999.0;
  pho2_eta = -999.0;
  pho2_phi = -999.0;
  pho2_m = -999.0;
  pho2_q = -999.0;
  pho2_dxy = -999.0;
  pho2_dz = -999.0;
  pho2_iso = -999.0;
  pho2_idEffWeight = 1.0;

  //lepton 2 scale variations
  pho2_pt_scaleUp = -999.0;
  pho2_pt_scaleDn = -999.0;

  pho2_mvaIDFall17V2 = -999.0;
  pho2_mvaIDFall17V1 = -999.0;
  pho2_mvaID_WP80 = -999.0;
  pho2_mvaID_WP90 = -999.0;
  pho2_pt_byMgg = -999.0;
  pho2_E_byMgg = -999.0;

  //dilepton final state
  diphoton_m = -999.0;
  diphoton_pt = -999.0;
  diphoton_eta = -999.0;
  diphoton_phi = -999.0;

  //dilepton scale variations
  diphoton_m_scaleUp = -999.0;
  diphoton_m_scaleDn = -999.0;
  diphoton_pt_scaleUp = -999.0;
  diphoton_pt_scaleDn = -999.0;

};

