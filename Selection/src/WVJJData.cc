#include "../interface/WVJJData.hh"

void WVJJData::init() {

  clearVars();

  //metadata and weights
  fTree->Branch("run",&run,"run/i");
  fTree->Branch("ls",&ls,"ls/i");
  fTree->Branch("evt",&evt,"evt/l");
  fTree->Branch("nPV",&nPV,"nPV/F");
  fTree->Branch("nPU_mean",&nPU_mean,"nPU_mean/F");
  fTree->Branch("genWeight",&genWeight,"genWeight/F");
  fTree->Branch("puWeight",&puWeight,"puWeight/F");
  fTree->Branch("puWeight_Up",&puWeight_Up,"puWeight_Up/F");
  fTree->Branch("puWeight_Down",&puWeight_Down,"puWeight_Down/F");
  fTree->Branch("L1PFWeight",&L1PFWeight,"L1PFWeight/F");
  fTree->Branch("L1PFWeight_Up",&L1PFWeight_Up,"L1PFWeight_Up/F");
  fTree->Branch("L1PFWeight_Down",&L1PFWeight_Down,"L1PFWeight_Down/F");
  // LHE Weights
  fTree->Branch("nScaleWeight",&nScaleWeight,"nScaleWeight/I");
  fTree->Branch("nPdfWeight",&nPdfWeight,"nPdfWeight/I");
  fTree->Branch("nAqgcWeight",&nAqgcWeight,"nAqgcWeight/I");
  fTree->Branch("scaleWeight",&scaleWeight[0],"scaleWeight[nScaleWeight]/F");
  fTree->Branch("pdfWeight",&pdfWeight[0],"pdfWeight[nPdfWeight]/F");
  fTree->Branch("aqgcWeight",&aqgcWeight[0],"aqgcWeight[nAqgcWeight]/F");
  // tZq veto
  fTree->Branch("is_tZq",&is_tZq,"is_tZq/O");
  //jet counters
  fTree->Branch("nAK4Jet30",&nAK4Jet30,"nAK4Jet30/I");
  fTree->Branch("nAK4Jet50",&nAK4Jet50,"nAK4Jet50/I");
  fTree->Branch("nGoodAK4jets",&nGoodAK4jets,"nGoodAK4jets/I");
  //btag counters
  fTree->Branch("nAK4Btag_loose",&nAK4Btag_loose,"nAK4Btag_loose/I");
  fTree->Branch("nAK4Btag_medium",&nAK4Btag_medium,"nAK4Btag_medium/I");
  fTree->Branch("nAK4Btag_tight",&nAK4Btag_tight,"nAK4Btag_tight/I");
  fTree->Branch("btagWeight_loose",&btagWeight_loose,"btagWeight_loose/F");
  fTree->Branch("btagWeight_loose_Up",&btagWeight_loose_Up,"btagWeight_loose_Up/F");
  fTree->Branch("btagWeight_loose_Down",&btagWeight_loose_Down,"btagWeight_loose_Down/F");
  fTree->Branch("btagWeight_medium",&btagWeight_medium,"btagWeight_medium/F");
  fTree->Branch("btagWeight_medium_Up",&btagWeight_medium_Up,"btagWeight_medium_Up/F");
  fTree->Branch("btagWeight_medium_Down",&btagWeight_medium_Down,"btagWeight_medium_Down/F");
  fTree->Branch("btagWeight_tight",&btagWeight_tight,"btagWeight_tight/F");
  fTree->Branch("btagWeight_tight_Up",&btagWeight_tight_Up,"btagWeight_tight_Up/F");
  fTree->Branch("btagWeight_tight_Down",&btagWeight_tight_Down,"btagWeight_tight_Down/F");
  //trigger
  fTree->Branch("trigger_1Mu",&trigger_1Mu,"trigger_1Mu/O");
  fTree->Branch("trigger_2Mu",&trigger_2Mu,"trigger_2Mu/O");
  fTree->Branch("trigger_1El",&trigger_1El,"trigger_1El/O");
  fTree->Branch("trigger_2El",&trigger_2El,"trigger_2El/O");

  fTree->Branch("isAntiIso",&isAntiIso,"isAntiIso/O");
  fTree->Branch("lepFakeRate",&lepFakeRate,"lepFakeRate/F");
  //lepton 1
  fTree->Branch("lep1_pt",&lep1_pt,"lep1_pt/F");
  fTree->Branch("lep1_eta",&lep1_eta,"lep1_eta/F");
  fTree->Branch("lep1_phi",&lep1_phi,"lep1_phi/F");
  fTree->Branch("lep1_m",&lep1_m,"lep1_m/F");
  fTree->Branch("lep1_q",&lep1_q,"lep1_q/F");
  fTree->Branch("lep1_iso",&lep1_iso,"lep1_iso/F");
  fTree->Branch("lep1_dxy",&lep1_dxy,"lep1_dxy/F");
  fTree->Branch("lep1_dz",&lep1_dz,"lep1_dz/F");
  fTree->Branch("lep1_idEffWeight",&lep1_idEffWeight,"lep1_idEffWeight/F");
  fTree->Branch("lep1_trigEffWeight",&lep1_trigEffWeight,"lep1_trigEffWeight/F");
  //lepton 1 scale variations
  fTree->Branch("lep1_pt_scaleUp",&lep1_pt_scaleUp,"lep1_pt_scaleUp/F");
  fTree->Branch("lep1_pt_scaleDown",&lep1_pt_scaleDown,"lep1_pt_scaleDown/F");
  //lepton 2
  fTree->Branch("lep2_pt",&lep2_pt,"lep2_pt/F");
  fTree->Branch("lep2_eta",&lep2_eta,"lep2_eta/F");
  fTree->Branch("lep2_phi",&lep2_phi,"lep2_phi/F");
  fTree->Branch("lep2_m",&lep2_m,"lep2_m/F");
  fTree->Branch("lep2_q",&lep2_q,"lep2_q/F");
  fTree->Branch("lep2_iso",&lep2_iso,"lep2_iso/F");
  fTree->Branch("lep2_dxy",&lep2_dxy,"lep2_dxy/F");
  fTree->Branch("lep2_dz",&lep2_dz,"lep2_dz/F");
  fTree->Branch("lep2_idEffWeight",&lep2_idEffWeight,"lep2_idEffWeight/F");
  fTree->Branch("lep2_trigEffWeight",&lep2_trigEffWeight,"lep2_trigEffWeight/F");
  //lepton 2 scale variations
  fTree->Branch("lep2_pt_scaleUp",&lep2_pt_scaleUp,"lep2_pt_scaleUp/F");
  fTree->Branch("lep2_pt_scaleDown",&lep2_pt_scaleDown,"lep2_pt_scaleDown/F");
  //dilepton final state
  fTree->Branch("dilep_m",&dilep_m,"dilep_m/F");
  fTree->Branch("dilep_mt",&dilep_mt,"dilep_mt/F");
  fTree->Branch("dilep_pt",&dilep_pt,"dilep_pt/F");
  fTree->Branch("dilep_eta",&dilep_eta,"dilep_eta/F");
  fTree->Branch("dilep_phi",&dilep_phi,"dilep_phi/F");
  //dilepton JES variations
  fTree->Branch("dilep_m_jesFlavorQCDUp",&dilep_m_jesFlavorQCDUp,"dilep_m_jesFlavorQCDUp/F");
  fTree->Branch("dilep_m_jesFlavorQCDDown",&dilep_m_jesFlavorQCDDown,"dilep_m_jesFlavorQCDDown/F");
  fTree->Branch("dilep_m_jesRelativeBalUp",&dilep_m_jesRelativeBalUp,"dilep_m_jesRelativeBalUp/F");
  fTree->Branch("dilep_m_jesRelativeBalDown",&dilep_m_jesRelativeBalDown,"dilep_m_jesRelativeBalDown/F");
  fTree->Branch("dilep_m_jesHFUp",&dilep_m_jesHFUp,"dilep_m_jesHFUp/F");
  fTree->Branch("dilep_m_jesHFDown",&dilep_m_jesHFDown,"dilep_m_jesHFDown/F");
  fTree->Branch("dilep_m_jesBBEC1Up",&dilep_m_jesBBEC1Up,"dilep_m_jesBBEC1Up/F");
  fTree->Branch("dilep_m_jesBBEC1Down",&dilep_m_jesBBEC1Down,"dilep_m_jesBBEC1Down/F");
  fTree->Branch("dilep_m_jesEC2Up",&dilep_m_jesEC2Up,"dilep_m_jesEC2Up/F");
  fTree->Branch("dilep_m_jesEC2Down",&dilep_m_jesEC2Down,"dilep_m_jesEC2Down/F");
  fTree->Branch("dilep_m_jesAbsoluteUp",&dilep_m_jesAbsoluteUp,"dilep_m_jesAbsoluteUp/F");
  fTree->Branch("dilep_m_jesAbsoluteDown",&dilep_m_jesAbsoluteDown,"dilep_m_jesAbsoluteDown/F");
  fTree->Branch("dilep_m_jesBBEC1_YearUp",&dilep_m_jesBBEC1_YearUp,"dilep_m_jesBBEC1_YearUp/F");
  fTree->Branch("dilep_m_jesBBEC1_YearDown",&dilep_m_jesBBEC1_YearDown,"dilep_m_jesBBEC1_YearDown/F");
  fTree->Branch("dilep_m_jesEC2_YearUp",&dilep_m_jesEC2_YearUp,"dilep_m_jesEC2_YearUp/F");
  fTree->Branch("dilep_m_jesEC2_YearDown",&dilep_m_jesEC2_YearDown,"dilep_m_jesEC2_YearDown/F");
  fTree->Branch("dilep_m_jesAbsolute_YearUp",&dilep_m_jesAbsolute_YearUp,"dilep_m_jesAbsolute_YearUp/F");
  fTree->Branch("dilep_m_jesAbsolute_YearDown",&dilep_m_jesAbsolute_YearDown,"dilep_m_jesAbsolute_YearDown/F");
  fTree->Branch("dilep_m_jesHF_YearUp",&dilep_m_jesHF_YearUp,"dilep_m_jesHF_YearUp/F");
  fTree->Branch("dilep_m_jesHF_YearDown",&dilep_m_jesHF_YearDown,"dilep_m_jesHF_YearDown/F");
  fTree->Branch("dilep_m_jesRelativeSample_YearUp",&dilep_m_jesRelativeSample_YearUp,"dilep_m_jesRelativeSample_YearUp/F");
  fTree->Branch("dilep_m_jesRelativeSample_YearDown",&dilep_m_jesRelativeSample_YearDown,"dilep_m_jesRelativeSample_YearDown/F");
  fTree->Branch("dilep_m_jesTotalUp",&dilep_m_jesTotalUp,"dilep_m_jesTotalUp/F");
  fTree->Branch("dilep_m_jesTotalDown",&dilep_m_jesTotalDown,"dilep_m_jesTotalDown/F");
  fTree->Branch("dilep_mt_jesFlavorQCDUp",&dilep_mt_jesFlavorQCDUp,"dilep_mt_jesFlavorQCDUp/F");
  fTree->Branch("dilep_mt_jesFlavorQCDDown",&dilep_mt_jesFlavorQCDDown,"dilep_mt_jesFlavorQCDDown/F");
  fTree->Branch("dilep_mt_jesRelativeBalUp",&dilep_mt_jesRelativeBalUp,"dilep_mt_jesRelativeBalUp/F");
  fTree->Branch("dilep_mt_jesRelativeBalDown",&dilep_mt_jesRelativeBalDown,"dilep_mt_jesRelativeBalDown/F");
  fTree->Branch("dilep_mt_jesHFUp",&dilep_mt_jesHFUp,"dilep_mt_jesHFUp/F");
  fTree->Branch("dilep_mt_jesHFDown",&dilep_mt_jesHFDown,"dilep_mt_jesHFDown/F");
  fTree->Branch("dilep_mt_jesBBEC1Up",&dilep_mt_jesBBEC1Up,"dilep_mt_jesBBEC1Up/F");
  fTree->Branch("dilep_mt_jesBBEC1Down",&dilep_mt_jesBBEC1Down,"dilep_mt_jesBBEC1Down/F");
  fTree->Branch("dilep_mt_jesEC2Up",&dilep_mt_jesEC2Up,"dilep_mt_jesEC2Up/F");
  fTree->Branch("dilep_mt_jesEC2Down",&dilep_mt_jesEC2Down,"dilep_mt_jesEC2Down/F");
  fTree->Branch("dilep_mt_jesAbsoluteUp",&dilep_mt_jesAbsoluteUp,"dilep_mt_jesAbsoluteUp/F");
  fTree->Branch("dilep_mt_jesAbsoluteDown",&dilep_mt_jesAbsoluteDown,"dilep_mt_jesAbsoluteDown/F");
  fTree->Branch("dilep_mt_jesBBEC1_YearUp",&dilep_mt_jesBBEC1_YearUp,"dilep_mt_jesBBEC1_YearUp/F");
  fTree->Branch("dilep_mt_jesBBEC1_YearDown",&dilep_mt_jesBBEC1_YearDown,"dilep_mt_jesBBEC1_YearDown/F");
  fTree->Branch("dilep_mt_jesEC2_YearUp",&dilep_mt_jesEC2_YearUp,"dilep_mt_jesEC2_YearUp/F");
  fTree->Branch("dilep_mt_jesEC2_YearDown",&dilep_mt_jesEC2_YearDown,"dilep_mt_jesEC2_YearDown/F");
  fTree->Branch("dilep_mt_jesAbsolute_YearUp",&dilep_mt_jesAbsolute_YearUp,"dilep_mt_jesAbsolute_YearUp/F");
  fTree->Branch("dilep_mt_jesAbsolute_YearDown",&dilep_mt_jesAbsolute_YearDown,"dilep_mt_jesAbsolute_YearDown/F");
  fTree->Branch("dilep_mt_jesHF_YearUp",&dilep_mt_jesHF_YearUp,"dilep_mt_jesHF_YearUp/F");
  fTree->Branch("dilep_mt_jesHF_YearDown",&dilep_mt_jesHF_YearDown,"dilep_mt_jesHF_YearDown/F");
  fTree->Branch("dilep_mt_jesRelativeSample_YearUp",&dilep_mt_jesRelativeSample_YearUp,"dilep_mt_jesRelativeSample_YearUp/F");
  fTree->Branch("dilep_mt_jesRelativeSample_YearDown",&dilep_mt_jesRelativeSample_YearDown,"dilep_mt_jesRelativeSample_YearDown/F");
  fTree->Branch("dilep_mt_jesTotalUp",&dilep_mt_jesTotalUp,"dilep_mt_jesTotalUp/F");
  fTree->Branch("dilep_mt_jesTotalDown",&dilep_mt_jesTotalDown,"dilep_mt_jesTotalDown/F");
  fTree->Branch("dilep_pt_jesFlavorQCDUp",&dilep_pt_jesFlavorQCDUp,"dilep_pt_jesFlavorQCDUp/F");
  fTree->Branch("dilep_pt_jesFlavorQCDDown",&dilep_pt_jesFlavorQCDDown,"dilep_pt_jesFlavorQCDDown/F");
  fTree->Branch("dilep_pt_jesRelativeBalUp",&dilep_pt_jesRelativeBalUp,"dilep_pt_jesRelativeBalUp/F");
  fTree->Branch("dilep_pt_jesRelativeBalDown",&dilep_pt_jesRelativeBalDown,"dilep_pt_jesRelativeBalDown/F");
  fTree->Branch("dilep_pt_jesHFUp",&dilep_pt_jesHFUp,"dilep_pt_jesHFUp/F");
  fTree->Branch("dilep_pt_jesHFDown",&dilep_pt_jesHFDown,"dilep_pt_jesHFDown/F");
  fTree->Branch("dilep_pt_jesBBEC1Up",&dilep_pt_jesBBEC1Up,"dilep_pt_jesBBEC1Up/F");
  fTree->Branch("dilep_pt_jesBBEC1Down",&dilep_pt_jesBBEC1Down,"dilep_pt_jesBBEC1Down/F");
  fTree->Branch("dilep_pt_jesEC2Up",&dilep_pt_jesEC2Up,"dilep_pt_jesEC2Up/F");
  fTree->Branch("dilep_pt_jesEC2Down",&dilep_pt_jesEC2Down,"dilep_pt_jesEC2Down/F");
  fTree->Branch("dilep_pt_jesAbsoluteUp",&dilep_pt_jesAbsoluteUp,"dilep_pt_jesAbsoluteUp/F");
  fTree->Branch("dilep_pt_jesAbsoluteDown",&dilep_pt_jesAbsoluteDown,"dilep_pt_jesAbsoluteDown/F");
  fTree->Branch("dilep_pt_jesBBEC1_YearUp",&dilep_pt_jesBBEC1_YearUp,"dilep_pt_jesBBEC1_YearUp/F");
  fTree->Branch("dilep_pt_jesBBEC1_YearDown",&dilep_pt_jesBBEC1_YearDown,"dilep_pt_jesBBEC1_YearDown/F");
  fTree->Branch("dilep_pt_jesEC2_YearUp",&dilep_pt_jesEC2_YearUp,"dilep_pt_jesEC2_YearUp/F");
  fTree->Branch("dilep_pt_jesEC2_YearDown",&dilep_pt_jesEC2_YearDown,"dilep_pt_jesEC2_YearDown/F");
  fTree->Branch("dilep_pt_jesAbsolute_YearUp",&dilep_pt_jesAbsolute_YearUp,"dilep_pt_jesAbsolute_YearUp/F");
  fTree->Branch("dilep_pt_jesAbsolute_YearDown",&dilep_pt_jesAbsolute_YearDown,"dilep_pt_jesAbsolute_YearDown/F");
  fTree->Branch("dilep_pt_jesHF_YearUp",&dilep_pt_jesHF_YearUp,"dilep_pt_jesHF_YearUp/F");
  fTree->Branch("dilep_pt_jesHF_YearDown",&dilep_pt_jesHF_YearDown,"dilep_pt_jesHF_YearDown/F");
  fTree->Branch("dilep_pt_jesRelativeSample_YearUp",&dilep_pt_jesRelativeSample_YearUp,"dilep_pt_jesRelativeSample_YearUp/F");
  fTree->Branch("dilep_pt_jesRelativeSample_YearDown",&dilep_pt_jesRelativeSample_YearDown,"dilep_pt_jesRelativeSample_YearDown/F");
  fTree->Branch("dilep_pt_jesTotalUp",&dilep_pt_jesTotalUp,"dilep_pt_jesTotalUp/F");
  fTree->Branch("dilep_pt_jesTotalDown",&dilep_pt_jesTotalDown,"dilep_pt_jesTotalDown/F");
  //dilepton lepton scale variations
  fTree->Branch("dilep_m_scaleUp",&dilep_m_scaleUp,"dilep_m_scaleUp/F");
  fTree->Branch("dilep_m_scaleDown",&dilep_m_scaleDown,"dilep_m_scaleDown/F");
  fTree->Branch("dilep_mt_scaleUp",&dilep_mt_scaleUp,"dilep_mt_scaleUp/F");
  fTree->Branch("dilep_mt_scaleDown",&dilep_mt_scaleDown,"dilep_mt_scaleDown/F");
  fTree->Branch("dilep_pt_scaleUp",&dilep_pt_scaleUp,"dilep_pt_scaleUp/F");
  fTree->Branch("dilep_pt_scaleDown",&dilep_pt_scaleDown,"dilep_pt_scaleDown/F");

  // Photons
  fTree->Branch("pho1_pt",&pho1_pt,"pho1_pt/F");
  fTree->Branch("pho1_eta",&pho1_eta,"pho1_eta/F");
  fTree->Branch("pho1_phi",&pho1_phi,"pho1_phi/F");
  fTree->Branch("pho1_m",&pho1_m,"pho1_m/F");
  fTree->Branch("pho1_q",&pho1_q,"pho1_q/F");
  fTree->Branch("pho1_iso",&pho1_iso,"pho1_iso/F");
  fTree->Branch("pho1_dxy",&pho1_dxy,"pho1_dxy/F");
  fTree->Branch("pho1_dz",&pho1_dz,"pho1_dz/F");
  fTree->Branch("pho1_idEffWeight",&pho1_idEffWeight,"pho1_idEffWeight/F");
  fTree->Branch("pho1_E",&pho1_E,"pho1_E/F");
  fTree->Branch("pho1_pt_byMgg",&pho1_pt_byMgg,"pho1_pt_byMgg/F");
  fTree->Branch("pho1_E_byMgg",&pho1_E_byMgg,"pho1_E_byMgg/F");
  fTree->Branch("pho1_pt_scaleUp",&pho1_pt_scaleUp,"pho1_pt_scaleUp/F");
  fTree->Branch("pho1_pt_scaleDn",&pho1_pt_scaleDn,"pho1_pt_scaleDn/F");
  fTree->Branch("pho2_pt",&pho2_pt,"pho2_pt/F");
  fTree->Branch("pho2_eta",&pho2_eta,"pho2_eta/F");
  fTree->Branch("pho2_phi",&pho2_phi,"pho2_phi/F");
  fTree->Branch("pho2_m",&pho2_m,"pho2_m/F");
  fTree->Branch("pho2_q",&pho2_q,"pho2_q/F");
  fTree->Branch("pho2_iso",&pho2_iso,"pho2_iso/F");
  fTree->Branch("pho2_dxy",&pho2_dxy,"pho2_dxy/F");
  fTree->Branch("pho2_dz",&pho2_dz,"pho2_dz/F");
  fTree->Branch("pho2_idEffWeight",&pho2_idEffWeight,"pho2_idEffWeight/F");
  fTree->Branch("pho2_E",&pho2_E,"pho2_E/F");
  fTree->Branch("pho2_pt_byMgg",&pho2_pt_byMgg,"pho2_pt_byMgg/F");
  fTree->Branch("pho2_E_byMgg",&pho2_E_byMgg,"pho2_E_byMgg/F");
  fTree->Branch("pho2_pt_scaleUp",&pho2_pt_scaleUp,"pho2_pt_scaleUp/F");
  fTree->Branch("pho2_pt_scaleDn",&pho2_pt_scaleDn,"pho2_pt_scaleDn/F");
  fTree->Branch("diphoton_m",&diphoton_m,"diphoton_m/F");
  fTree->Branch("diphoton_pt",&diphoton_pt,"diphoton_pt/F");
  fTree->Branch("diphoton_eta",&diphoton_eta,"diphoton_eta/F");
  fTree->Branch("diphoton_phi",&diphoton_phi,"diphoton_phi/F");
  fTree->Branch("diphoton_E",&diphoton_E,"diphoton_E/F");
  fTree->Branch("diphoton_m_scaleUp",&diphoton_m_scaleUp,"diphoton_m_scaleUp/F");
  fTree->Branch("diphoton_m_scaleDn",&diphoton_m_scaleDn,"diphoton_m_scaleDn/F");
  fTree->Branch("diphoton_pt_scaleUp",&diphoton_pt_scaleUp,"diphoton_pt_scaleUp/F");
  fTree->Branch("diphoton_pt_scaleDn",&diphoton_pt_scaleDn,"diphoton_pt_scaleDn/F");
  fTree->Branch("pho1_mvaID_Fall17V1p1",&pho1_mvaID_Fall17V1p1,"pho1_mvaID_Fall17V1p1/F");
  fTree->Branch("pho2_mvaID_Fall17V1p1",&pho2_mvaID_Fall17V1p1,"pho2_mvaID_Fall17V1p1/F");
  fTree->Branch("pho1_mvaID_WP80",&pho1_mvaID_WP80,"pho1_mvaID_WP80/F");
  fTree->Branch("pho2_mvaID_WP80",&pho2_mvaID_WP80,"pho2_mvaID_WP80/F");
  fTree->Branch("pho1_mvaID_WP90",&pho1_mvaID_WP90,"pho1_mvaID_WP90/F");
  fTree->Branch("pho2_mvaID_WP90",&pho2_mvaID_WP90,"pho2_mvaID_WP90/F");
  fTree->Branch("pho1_mvaIDFall17V1",&pho1_mvaIDFall17V1,"pho1_mvaIDFall17V1/F");
  fTree->Branch("pho1_mvaIDFall17V2",&pho1_mvaIDFall17V2,"pho1_mvaIDFall17V2/F");
  fTree->Branch("pho2_mvaIDFall17V1",&pho2_mvaIDFall17V1,"pho2_mvaIDFall17V1/F");
  fTree->Branch("pho2_mvaIDFall17V2",&pho2_mvaIDFall17V2,"pho2_mvaIDFall17V2/F");

  //MET
  fTree->Branch("MET",&MET,"MET/F");
  fTree->Branch("MET_phi",&MET_phi,"MET_phi/F");
  fTree->Branch("MET_2017",&MET_2017,"MET_2017/F");
  fTree->Branch("MET_jesFlavorQCDUp",&MET_jesFlavorQCDUp,"MET_jesFlavorQCDUp/F");
  fTree->Branch("MET_jesFlavorQCDDown",&MET_jesFlavorQCDDown,"MET_jesFlavorQCDDown/F");
  fTree->Branch("MET_jesRelativeBalUp",&MET_jesRelativeBalUp,"MET_jesRelativeBalUp/F");
  fTree->Branch("MET_jesRelativeBalDown",&MET_jesRelativeBalDown,"MET_jesRelativeBalDown/F");
  fTree->Branch("MET_jesHFUp",&MET_jesHFUp,"MET_jesHFUp/F");
  fTree->Branch("MET_jesHFDown",&MET_jesHFDown,"MET_jesHFDown/F");
  fTree->Branch("MET_jesBBEC1Up",&MET_jesBBEC1Up,"MET_jesBBEC1Up/F");
  fTree->Branch("MET_jesBBEC1Down",&MET_jesBBEC1Down,"MET_jesBBEC1Down/F");
  fTree->Branch("MET_jesEC2Up",&MET_jesEC2Up,"MET_jesEC2Up/F");
  fTree->Branch("MET_jesEC2Down",&MET_jesEC2Down,"MET_jesEC2Down/F");
  fTree->Branch("MET_jesAbsoluteUp",&MET_jesAbsoluteUp,"MET_jesAbsoluteUp/F");
  fTree->Branch("MET_jesAbsoluteDown",&MET_jesAbsoluteDown,"MET_jesAbsoluteDown/F");
  fTree->Branch("MET_jesBBEC1_YearUp",&MET_jesBBEC1_YearUp,"MET_jesBBEC1_YearUp/F");
  fTree->Branch("MET_jesBBEC1_YearDown",&MET_jesBBEC1_YearDown,"MET_jesBBEC1_YearDown/F");
  fTree->Branch("MET_jesEC2_YearUp",&MET_jesEC2_YearUp,"MET_jesEC2_YearUp/F");
  fTree->Branch("MET_jesEC2_YearDown",&MET_jesEC2_YearDown,"MET_jesEC2_YearDown/F");
  fTree->Branch("MET_jesAbsolute_YearUp",&MET_jesAbsolute_YearUp,"MET_jesAbsolute_YearUp/F");
  fTree->Branch("MET_jesAbsolute_YearDown",&MET_jesAbsolute_YearDown,"MET_jesAbsolute_YearDown/F");
  fTree->Branch("MET_jesHF_YearUp",&MET_jesHF_YearUp,"MET_jesHF_YearUp/F");
  fTree->Branch("MET_jesHF_YearDown",&MET_jesHF_YearDown,"MET_jesHF_YearDown/F");
  fTree->Branch("MET_jesRelativeSample_YearUp",&MET_jesRelativeSample_YearUp,"MET_jesRelativeSample_YearUp/F");
  fTree->Branch("MET_jesRelativeSample_YearDown",&MET_jesRelativeSample_YearDown,"MET_jesRelativeSample_YearDown/F");
  fTree->Branch("MET_jesTotalUp",&MET_jesTotalUp,"MET_jesTotalUp/F");
  fTree->Branch("MET_jesTotalDown",&MET_jesTotalDown,"MET_jesTotalDown/F");
  fTree->Branch("MET_phi_jesFlavorQCDUp",&MET_phi_jesFlavorQCDUp,"MET_phi_jesFlavorQCDUp/F");
  fTree->Branch("MET_phi_jesFlavorQCDDown",&MET_phi_jesFlavorQCDDown,"MET_phi_jesFlavorQCDDown/F");
  fTree->Branch("MET_phi_jesRelativeBalUp",&MET_phi_jesRelativeBalUp,"MET_phi_jesRelativeBalUp/F");
  fTree->Branch("MET_phi_jesRelativeBalDown",&MET_phi_jesRelativeBalDown,"MET_phi_jesRelativeBalDown/F");
  fTree->Branch("MET_phi_jesHFUp",&MET_phi_jesHFUp,"MET_phi_jesHFUp/F");
  fTree->Branch("MET_phi_jesHFDown",&MET_phi_jesHFDown,"MET_phi_jesHFDown/F");
  fTree->Branch("MET_phi_jesBBEC1Up",&MET_phi_jesBBEC1Up,"MET_phi_jesBBEC1Up/F");
  fTree->Branch("MET_phi_jesBBEC1Down",&MET_phi_jesBBEC1Down,"MET_phi_jesBBEC1Down/F");
  fTree->Branch("MET_phi_jesEC2Up",&MET_phi_jesEC2Up,"MET_phi_jesEC2Up/F");
  fTree->Branch("MET_phi_jesEC2Down",&MET_phi_jesEC2Down,"MET_phi_jesEC2Down/F");
  fTree->Branch("MET_phi_jesAbsoluteUp",&MET_phi_jesAbsoluteUp,"MET_phi_jesAbsoluteUp/F");
  fTree->Branch("MET_phi_jesAbsoluteDown",&MET_phi_jesAbsoluteDown,"MET_phi_jesAbsoluteDown/F");
  fTree->Branch("MET_phi_jesBBEC1_YearUp",&MET_phi_jesBBEC1_YearUp,"MET_phi_jesBBEC1_YearUp/F");
  fTree->Branch("MET_phi_jesBBEC1_YearDown",&MET_phi_jesBBEC1_YearDown,"MET_phi_jesBBEC1_YearDown/F");
  fTree->Branch("MET_phi_jesEC2_YearUp",&MET_phi_jesEC2_YearUp,"MET_phi_jesEC2_YearUp/F");
  fTree->Branch("MET_phi_jesEC2_YearDown",&MET_phi_jesEC2_YearDown,"MET_phi_jesEC2_YearDown/F");
  fTree->Branch("MET_phi_jesAbsolute_YearUp",&MET_phi_jesAbsolute_YearUp,"MET_phi_jesAbsolute_YearUp/F");
  fTree->Branch("MET_phi_jesAbsolute_YearDown",&MET_phi_jesAbsolute_YearDown,"MET_phi_jesAbsolute_YearDown/F");
  fTree->Branch("MET_phi_jesHF_YearUp",&MET_phi_jesHF_YearUp,"MET_phi_jesHF_YearUp/F");
  fTree->Branch("MET_phi_jesHF_YearDown",&MET_phi_jesHF_YearDown,"MET_phi_jesHF_YearDown/F");
  fTree->Branch("MET_phi_jesRelativeSample_YearUp",&MET_phi_jesRelativeSample_YearUp,"MET_phi_jesRelativeSample_YearUp/F");
  fTree->Branch("MET_phi_jesRelativeSample_YearDown",&MET_phi_jesRelativeSample_YearDown,"MET_phi_jesRelativeSample_YearDown/F");
  fTree->Branch("MET_phi_jesTotalUp",&MET_phi_jesTotalUp,"MET_phi_jesTotalUp/F");
  fTree->Branch("MET_phi_jesTotalDown",&MET_phi_jesTotalDown,"MET_phi_jesTotalDown/F");
  //W neutrino pZ
  fTree->Branch("neu_pz_type0",&neu_pz_type0,"neu_pz_type0/F");

  fTree->Branch("FullyResolved_allAK4JetsSum_pt", &FullyResolved_allAK4JetsSum_pt, "FullyResolved_allAK4JetsSum_pt/F");
  fTree->Branch("FullyResolved_Jet1_pt", &FullyResolved_Jet1_pt, "FullyResolved_Jet1_pt/F");
  fTree->Branch("FullyResolved_Jet2_pt", &FullyResolved_Jet2_pt, "FullyResolved_Jet2_pt/F");
  fTree->Branch("FullyResolved_Jet3_pt", &FullyResolved_Jet3_pt, "FullyResolved_Jet3_pt/F");
  fTree->Branch("FullyResolved_Jet4_pt", &FullyResolved_Jet4_pt, "FullyResolved_Jet4_pt/F");

  fTree->Branch("FullyResolved_Jet1_eta", &FullyResolved_Jet1_eta, "FullyResolved_Jet1_eta/F");
  fTree->Branch("FullyResolved_Jet2_eta", &FullyResolved_Jet2_eta, "FullyResolved_Jet2_eta/F");
  fTree->Branch("FullyResolved_Jet3_eta", &FullyResolved_Jet3_eta, "FullyResolved_Jet3_eta/F");
  fTree->Branch("FullyResolved_Jet4_eta", &FullyResolved_Jet4_eta, "FullyResolved_Jet4_eta/F");

  fTree->Branch("FullyResolved_Jet1_phi", &FullyResolved_Jet1_phi, "FullyResolved_Jet1_phi/F");
  fTree->Branch("FullyResolved_Jet2_phi", &FullyResolved_Jet2_phi, "FullyResolved_Jet2_phi/F");
  fTree->Branch("FullyResolved_Jet3_phi", &FullyResolved_Jet3_phi, "FullyResolved_Jet3_phi/F");
  fTree->Branch("FullyResolved_Jet4_phi", &FullyResolved_Jet4_phi, "FullyResolved_Jet4_phi/F");

  fTree->Branch("FullyResolved_Jet1_E", &FullyResolved_Jet1_E, "FullyResolved_Jet1_E/F");
  fTree->Branch("FullyResolved_Jet2_E", &FullyResolved_Jet2_E, "FullyResolved_Jet2_E/F");
  fTree->Branch("FullyResolved_Jet3_E", &FullyResolved_Jet3_E, "FullyResolved_Jet3_E/F");
  fTree->Branch("FullyResolved_Jet4_E", &FullyResolved_Jet4_E, "FullyResolved_Jet4_E/F");

  fTree->Branch("FullyResolved_Jet1_M", &FullyResolved_Jet1_M, "FullyResolved_Jet1_M/F");
  fTree->Branch("FullyResolved_Jet2_M", &FullyResolved_Jet2_M, "FullyResolved_Jet2_M/F");
  fTree->Branch("FullyResolved_Jet3_M", &FullyResolved_Jet3_M, "FullyResolved_Jet3_M/F");
  fTree->Branch("FullyResolved_Jet4_M", &FullyResolved_Jet4_M, "FullyResolved_Jet4_M/F");

  fTree->Branch("FullyResolved_TwoLeadingJets_pt", &FullyResolved_TwoLeadingJets_pt, "FullyResolved_TwoLeadingJets_pt/F");
  fTree->Branch("FullyResolved_TwoLeadingJets_eta", &FullyResolved_TwoLeadingJets_eta, "FullyResolved_TwoLeadingJets_eta/F");
  fTree->Branch("FullyResolved_TwoLeadingJets_phi", &FullyResolved_TwoLeadingJets_phi, "FullyResolved_TwoLeadingJets_phi/F");
  fTree->Branch("FullyResolved_TwoLeadingJets_m", &FullyResolved_TwoLeadingJets_m, "FullyResolved_TwoLeadingJets_m/F");
  fTree->Branch("FullyResolved_TwoLeadingJets_E", &FullyResolved_TwoLeadingJets_E, "FullyResolved_TwoLeadingJets_E/F");

  fTree->Branch("FullyResolved_ThirdFourthJets_pt", &FullyResolved_ThirdFourthJets_pt, "FullyResolved_ThirdFourthJets_pt/F");
  fTree->Branch("FullyResolved_ThirdFourthJets_eta", &FullyResolved_ThirdFourthJets_eta, "FullyResolved_ThirdFourthJets_eta/F");
  fTree->Branch("FullyResolved_ThirdFourthJets_phi", &FullyResolved_ThirdFourthJets_phi, "FullyResolved_ThirdFourthJets_phi/F");
  fTree->Branch("FullyResolved_ThirdFourthJets_m", &FullyResolved_ThirdFourthJets_m, "FullyResolved_ThirdFourthJets_m/F");
  fTree->Branch("FullyResolved_ThirdFourthJets_E", &FullyResolved_ThirdFourthJets_E, "FullyResolved_ThirdFourthJets_E/F");

  fTree->Branch("FullyResolved_FourJets_pt", &FullyResolved_FourJets_pt, "FullyResolved_FourJets_pt/F");
  fTree->Branch("FullyResolved_FourJets_eta", &FullyResolved_FourJets_eta, "FullyResolved_FourJets_eta/F");
  fTree->Branch("FullyResolved_FourJets_phi", &FullyResolved_FourJets_phi, "FullyResolved_FourJets_phi/F");
  fTree->Branch("FullyResolved_FourJets_m", &FullyResolved_FourJets_m, "FullyResolved_FourJets_m/F");
  fTree->Branch("FullyResolved_FourJets_E", &FullyResolved_FourJets_E, "FullyResolved_FourJets_E/F");

};

void WVJJData::clearVars() {

  //------------------------------------//
  //       METADATA AND EVENT WEIGHTS   //
  //------------------------------------//

  run = 0;
  ls = 0;
  evt = 0;

  nPV = 0;
  nPU_mean = 0;

  genWeight = 1.0;
  puWeight = 1.0;
  puWeight_Up = 1.0;
  puWeight_Down = 1.0;

  L1PFWeight = 1.0;
  L1PFWeight_Up = 1.0;
  L1PFWeight_Down = 1.0;

  nScaleWeight = 0;
  nPdfWeight = 0;
  nAqgcWeight = 0;
  std::fill_n(scaleWeight,200,0);
  std::fill_n(pdfWeight,200,0);
  std::fill_n(aqgcWeight,1000,0);

  is_tZq = false;

  nAK4Jet30 = 0;
  nAK4Jet50 = 0;
  nGoodAK4jets = 0;

  nAK4Btag_loose = 0;
  nAK4Btag_medium = 0;
  nAK4Btag_tight = 0;

  btagWeight_loose = 1.0;
  btagWeight_loose_Up = 1.0;
  btagWeight_loose_Down = 1.0;
  btagWeight_medium = 1.0;
  btagWeight_medium_Up = 1.0;
  btagWeight_medium_Down = 1.0;
  btagWeight_tight = 1.0;
  btagWeight_tight_Up = 1.0;
  btagWeight_tight_Down = 1.0;

  trigger_1Mu = false;
  trigger_2Mu = false;
  trigger_1El = false;
  trigger_2El = false;

  isAntiIso = false;
  lepFakeRate = 1.0;

  //------------------------------------//
  //       LEPTONS                      //
  //------------------------------------//

  //lepton 1
  lep1_pt = -999.0;
  lep1_eta = -999.0;
  lep1_phi = -999.0;
  lep1_m = -999.0;
  lep1_q = -999.0;
  lep1_dxy = -999.0;
  lep1_dz = -999.0;
  lep1_sip3d = -999.0;
  lep1_iso = -999.0;
  lep1_idEffWeight = 1.0;
  lep1_trigEffWeight = 1.0;

  //lepton 1 scale variations
  lep1_pt_scaleUp = -999.0;
  lep1_pt_scaleDown = -999.0;

  //lepton 2
  lep2_pt = -999.0;
  lep2_eta = -999.0;
  lep2_phi = -999.0;
  lep2_m = -999.0;
  lep2_q = -999.0;
  lep2_dxy = -999.0;
  lep2_dz = -999.0;
  lep2_sip3d = -999.0;
  lep2_iso = -999.0;
  lep2_idEffWeight = 1.0;
  lep2_trigEffWeight = 1.0;

  //lepton 2 scale variations
  lep2_pt_scaleUp = -999.0;
  lep2_pt_scaleDown = -999.0;

  //dilepton final state
  dilep_m = -999.0;
  dilep_mt = -999.0;
  dilep_pt = -999.0;
  dilep_eta = -999.0;
  dilep_phi = -999.0;

  //dilepton JES variations
  dilep_m_jesFlavorQCDUp = -999.0;
  dilep_m_jesFlavorQCDDown = -999.0;
  dilep_m_jesRelativeBalUp = -999.0;
  dilep_m_jesRelativeBalDown = -999.0;
  dilep_m_jesHFUp = -999.0;
  dilep_m_jesHFDown = -999.0;
  dilep_m_jesBBEC1Up = -999.0;
  dilep_m_jesBBEC1Down = -999.0;
  dilep_m_jesEC2Up = -999.0;
  dilep_m_jesEC2Down = -999.0;
  dilep_m_jesAbsoluteUp = -999.0;
  dilep_m_jesAbsoluteDown = -999.0;
  dilep_m_jesBBEC1_YearUp = -999.0;
  dilep_m_jesBBEC1_YearDown = -999.0;
  dilep_m_jesEC2_YearUp = -999.0;
  dilep_m_jesEC2_YearDown = -999.0;
  dilep_m_jesAbsolute_YearUp = -999.0;
  dilep_m_jesAbsolute_YearDown = -999.0;
  dilep_m_jesHF_YearUp = -999.0;
  dilep_m_jesHF_YearDown = -999.0;
  dilep_m_jesRelativeSample_YearUp = -999.0;
  dilep_m_jesRelativeSample_YearDown = -999.0;
  dilep_m_jesTotalUp = -999.0;
  dilep_m_jesTotalDown = -999.0;

  dilep_mt_jesFlavorQCDUp = -999.0;
  dilep_mt_jesFlavorQCDDown = -999.0;
  dilep_mt_jesRelativeBalUp = -999.0;
  dilep_mt_jesRelativeBalDown = -999.0;
  dilep_mt_jesHFUp = -999.0;
  dilep_mt_jesHFDown = -999.0;
  dilep_mt_jesBBEC1Up = -999.0;
  dilep_mt_jesBBEC1Down = -999.0;
  dilep_mt_jesEC2Up = -999.0;
  dilep_mt_jesEC2Down = -999.0;
  dilep_mt_jesAbsoluteUp = -999.0;
  dilep_mt_jesAbsoluteDown = -999.0;
  dilep_mt_jesBBEC1_YearUp = -999.0;
  dilep_mt_jesBBEC1_YearDown = -999.0;
  dilep_mt_jesEC2_YearUp = -999.0;
  dilep_mt_jesEC2_YearDown = -999.0;
  dilep_mt_jesAbsolute_YearUp = -999.0;
  dilep_mt_jesAbsolute_YearDown = -999.0;
  dilep_mt_jesHF_YearUp = -999.0;
  dilep_mt_jesHF_YearDown = -999.0;
  dilep_mt_jesRelativeSample_YearUp = -999.0;
  dilep_mt_jesRelativeSample_YearDown = -999.0;
  dilep_mt_jesTotalUp = -999.0;
  dilep_mt_jesTotalDown = -999.0;

  dilep_pt_jesFlavorQCDUp = -999.0;
  dilep_pt_jesFlavorQCDDown = -999.0;
  dilep_pt_jesRelativeBalUp = -999.0;
  dilep_pt_jesRelativeBalDown = -999.0;
  dilep_pt_jesHFUp = -999.0;
  dilep_pt_jesHFDown = -999.0;
  dilep_pt_jesBBEC1Up = -999.0;
  dilep_pt_jesBBEC1Down = -999.0;
  dilep_pt_jesEC2Up = -999.0;
  dilep_pt_jesEC2Down = -999.0;
  dilep_pt_jesAbsoluteUp = -999.0;
  dilep_pt_jesAbsoluteDown = -999.0;
  dilep_pt_jesBBEC1_YearUp = -999.0;
  dilep_pt_jesBBEC1_YearDown = -999.0;
  dilep_pt_jesEC2_YearUp = -999.0;
  dilep_pt_jesEC2_YearDown = -999.0;
  dilep_pt_jesAbsolute_YearUp = -999.0;
  dilep_pt_jesAbsolute_YearDown = -999.0;
  dilep_pt_jesHF_YearUp = -999.0;
  dilep_pt_jesHF_YearDown = -999.0;
  dilep_pt_jesRelativeSample_YearUp = -999.0;
  dilep_pt_jesRelativeSample_YearDown = -999.0;
  dilep_pt_jesTotalUp = -999.0;
  dilep_pt_jesTotalDown = -999.0;

  //dilepton scale variations
  dilep_m_scaleUp = -999.0;
  dilep_m_scaleDown = -999.0;
  dilep_mt_scaleUp = -999.0;
  dilep_mt_scaleDown = -999.0;
  dilep_pt_scaleUp = -999.0;
  dilep_pt_scaleDown = -999.0;

 //photon 1
  pho1_pt = -999.0;
  pho1_eta = -999.0;
  pho1_phi = -999.0;
  pho1_m = -999.0;
  pho1_q = -999.0;
  pho1_iso = -999.0;
  pho1_dxy = -999.0;
  pho1_dz = -999.0;
  pho1_idEffWeight = -999.0;
  pho1_E = -999.0;
  pho1_pt_byMgg = -999.0;
  pho1_E_byMgg = -999.0;
  //photon 1 scale variations
  pho1_pt_scaleUp = -999.0;
  pho1_pt_scaleDn = -999.0;

  //photon 2
  pho2_pt = -999.0;
  pho2_eta = -999.0;
  pho2_phi = -999.0;
  pho2_m = -999.0;
  pho2_q = -999.0;
  pho2_iso = -999.0;
  pho2_dxy = -999.0;
  pho2_dz = -999.0;
  pho2_idEffWeight = -999.0;
  pho2_E = -999.0;
  pho2_pt_byMgg = -999.0;
  pho2_E_byMgg = -999.0;

  //photon 2 scale variations
  pho2_pt_scaleUp = -999.0;
  pho2_pt_scaleDn = -999.0;

  //diphoton final state
  diphoton_m = -999.0;
  diphoton_pt = -999.0;
  diphoton_eta = -999.0;
  diphoton_phi = -999.0;
  diphoton_E = -999.0;
  //diphoton scale variations
  diphoton_m_scaleUp = -999.0;
  diphoton_m_scaleDn = -999.0;
  diphoton_pt_scaleUp = -999.0;
  diphoton_pt_scaleDn = -999.0;
  pho1_mvaID_Fall17V1p1 = -999.0;
  pho2_mvaID_Fall17V1p1 = -999.0;
  pho1_mvaID_WP80 = -999.0;
  pho2_mvaID_WP80 = -999.0;
  pho1_mvaID_WP90 = -999.0;
  pho2_mvaID_WP90 = -999.0;
  pho1_mvaIDFall17V1 = -999.0;
  pho1_mvaIDFall17V2 = -999.0;
  pho2_mvaIDFall17V1 = -999.0;
  pho2_mvaIDFall17V2 = -999.0;

  //------------------------------------//
  //       MET                          //
  //------------------------------------//

  MET = -999.0;
  MET_phi = -999.0;

  MET_2017 = -999.0;

  MET_jesFlavorQCDUp = -999.0;
  MET_jesFlavorQCDDown = -999.0;
  MET_jesRelativeBalUp = -999.0;
  MET_jesRelativeBalDown = -999.0;
  MET_jesHFUp = -999.0;
  MET_jesHFDown = -999.0;
  MET_jesBBEC1Up = -999.0;
  MET_jesBBEC1Down = -999.0;
  MET_jesEC2Up = -999.0;
  MET_jesEC2Down = -999.0;
  MET_jesAbsoluteUp = -999.0;
  MET_jesAbsoluteDown = -999.0;
  MET_jesBBEC1_YearUp = -999.0;
  MET_jesBBEC1_YearDown = -999.0;
  MET_jesEC2_YearUp = -999.0;
  MET_jesEC2_YearDown = -999.0;
  MET_jesAbsolute_YearUp = -999.0;
  MET_jesAbsolute_YearDown = -999.0;
  MET_jesHF_YearUp = -999.0;
  MET_jesHF_YearDown = -999.0;
  MET_jesRelativeSample_YearUp = -999.0;
  MET_jesRelativeSample_YearDown = -999.0;
  MET_jesTotalUp = -999.0;
  MET_jesTotalDown = -999.0;

  MET_phi_jesFlavorQCDUp = -999.0;
  MET_phi_jesFlavorQCDDown = -999.0;
  MET_phi_jesRelativeBalUp = -999.0;
  MET_phi_jesRelativeBalDown = -999.0;
  MET_phi_jesHFUp = -999.0;
  MET_phi_jesHFDown = -999.0;
  MET_phi_jesBBEC1Up = -999.0;
  MET_phi_jesBBEC1Down = -999.0;
  MET_phi_jesEC2Up = -999.0;
  MET_phi_jesEC2Down = -999.0;
  MET_phi_jesAbsoluteUp = -999.0;
  MET_phi_jesAbsoluteDown = -999.0;
  MET_phi_jesBBEC1_YearUp = -999.0;
  MET_phi_jesBBEC1_YearDown = -999.0;
  MET_phi_jesEC2_YearUp = -999.0;
  MET_phi_jesEC2_YearDown = -999.0;
  MET_phi_jesAbsolute_YearUp = -999.0;
  MET_phi_jesAbsolute_YearDown = -999.0;
  MET_phi_jesHF_YearUp = -999.0;
  MET_phi_jesHF_YearDown = -999.0;
  MET_phi_jesRelativeSample_YearUp = -999.0;
  MET_phi_jesRelativeSample_YearDown = -999.0;
  MET_phi_jesTotalUp = -999.0;
  MET_phi_jesTotalDown = -999.0;


  PuppiMET = -999.0;
  PuppiMET_phi = -999.0;

  neu_pz_type0 = -999.0;

  //------------------------------------//
  //       VBF/TAGGING JETS             //
  //------------------------------------//

  FullyResolved_allAK4JetsSum_pt = -999.0;
  FullyResolved_Jet1_pt = -999.0;
  FullyResolved_Jet2_pt = -999.0;
  FullyResolved_Jet3_pt = -999.0;
  FullyResolved_Jet4_pt = -999.0;
  FullyResolved_Jet1_eta = -999.0;
  FullyResolved_Jet2_eta = -999.0;
  FullyResolved_Jet3_eta = -999.0;
  FullyResolved_Jet4_eta = -999.0;
  FullyResolved_Jet1_phi = -999.0;
  FullyResolved_Jet2_phi = -999.0;
  FullyResolved_Jet3_phi = -999.0;
  FullyResolved_Jet4_phi = -999.0;
  FullyResolved_Jet1_E = -999.0;
  FullyResolved_Jet2_E = -999.0;
  FullyResolved_Jet3_E = -999.0;
  FullyResolved_Jet4_E = -999.0;
  FullyResolved_Jet1_M = -999.0;
  FullyResolved_Jet2_M = -999.0;
  FullyResolved_Jet3_M = -999.0;
  FullyResolved_Jet4_M = -999.0;
  FullyResolved_TwoLeadingJets_pt = -999.0;
  FullyResolved_TwoLeadingJets_eta = -999.0;
  FullyResolved_TwoLeadingJets_phi = -999.0;
  FullyResolved_TwoLeadingJets_m = -999.0;
  FullyResolved_TwoLeadingJets_E = -999.0;
  FullyResolved_ThirdFourthJets_pt = -999.0;
  FullyResolved_ThirdFourthJets_eta = -999.0;
  FullyResolved_ThirdFourthJets_phi = -999.0;
  FullyResolved_ThirdFourthJets_m = -999.0;
  FullyResolved_ThirdFourthJets_E = -999.0;
  FullyResolved_FourJets_pt = -999.0;
  FullyResolved_FourJets_eta = -999.0;
  FullyResolved_FourJets_phi = -999.0;
  FullyResolved_FourJets_m = -999.0;
  FullyResolved_FourJets_E = -999.0;

};

