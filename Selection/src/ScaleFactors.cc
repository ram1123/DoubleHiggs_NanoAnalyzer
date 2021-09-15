#include "../interface/ScaleFactors.hh"

void ScaleFactors::setupSFs() {

  if (era_==2016) {
    pileupFileMC = TFile::Open("data/puWeights_80x_37ifb.root","READ");
    puWeights = (TH1D*)pileupFileMC->Get("puWeights");
    puWeightsUp = (TH1D*)pileupFileMC->Get("puWeightsUp");
    puWeightsDown = (TH1D*)pileupFileMC->Get("puWeightsDown");

    IDIsoEle = TFile::Open("data/SF2016/2016LegacyReReco_ElectronMVA90_Fall17V2.root","READ");
    hIDIsoEle = (TH2F*)IDIsoEle->Get("EGamma_SF2D");

    FREle = TFile::Open("data/SF2016/EleFR_jet30.root","READ");
    hFREle = (TH2D*)FREle->Get("FR_pT_eta");

    IDMu = TFile::Open("data/SF2016/Muon_Run2016BCDEF_SF_ID.root","READ");
    hIDMu = (TH2D*)IDMu->Get("NUM_TightID_DEN_genTracks_eta_pt");
    IsoMu = TFile::Open("data/SF2016/Muon_Run2016BCDEF_SF_ISO.root","READ");
    hIsoMu = (TH2D*)IsoMu->Get("NUM_TightRelIso_DEN_TightIDandIPCut_eta_pt");

    FRMu = TFile::Open("data/SF2016/MuonFR_jet30.root","READ");
    hFRMu = (TH2D*)FREle->Get("FR_pT_eta");

    //btag eff maps file
    bTagEff = TFile::Open("data/bTagEff/btag_eff_2016.root");
  }

  if (era_==2017) {
    pileupFileMC = TFile::Open("data/puWeights_90x_2017.root","READ");
    puWeights = (TH1D*)pileupFileMC->Get("puWeights");
    puWeightsUp = (TH1D*)pileupFileMC->Get("puWeightsUp");
    puWeightsDown = (TH1D*)pileupFileMC->Get("puWeightsDown");

    IDIsoEle = TFile::Open("data/SF2017/2017_ElectronMVA90.root","READ");
    hIDIsoEle = (TH2F*)IDIsoEle->Get("EGamma_SF2D");

    FREle = TFile::Open("data/SF2017/EleFR_jet30.root","READ");
    hFREle = (TH2D*)FREle->Get("FR_pT_eta");

    IDMu = TFile::Open("data/SF2017/Muon_Run2017BCDEF_SF_ID.root","READ");
    hIDMu = (TH2D*)IDMu->Get("NUM_TightID_DEN_genTracks_pt_abseta");
    IsoMu = TFile::Open("data/SF2017/Muon_Run2017BCDEF_SF_ISO.root","READ");
    hIsoMu = (TH2D*)IsoMu->Get("NUM_TightRelIso_DEN_TightIDandIPCut_pt_abseta");

    FRMu = TFile::Open("data/SF2017/MuonFR_jet30.root","READ");
    hFRMu = (TH2D*)FREle->Get("FR_pT_eta");

    //btag eff maps file
    bTagEff = TFile::Open("data/bTagEff/btag_eff_2017.root");
  }


  if (era_==2018) {
    pileupFileMC = TFile::Open("data/puWeights_90x_2018.root","READ");
    puWeights = (TH1D*)pileupFileMC->Get("puWeights");
    puWeightsUp = (TH1D*)pileupFileMC->Get("puWeightsUp");
    puWeightsDown = (TH1D*)pileupFileMC->Get("puWeightsDown");

    IDIsoEle = TFile::Open("data/SF2018/2018_ElectronMVA90.root","READ");
    hIDIsoEle = (TH2F*)IDIsoEle->Get("EGamma_SF2D");

    FREle = TFile::Open("data/SF2018/EleFR_jet30.root","READ");
    hFREle = (TH2D*)FREle->Get("FR_pT_eta");


    IDMu = TFile::Open("data/SF2018/Muon_Run2018ABCD_SF_ID.root","READ");
    hIDMu = (TH2D*)IDMu->Get("NUM_TightID_DEN_TrackerMuons_pt_abseta");
    IsoMu = TFile::Open("data/SF2018/Muon_Run2018ABCD_SF_ISO.root","READ");
    hIsoMu = (TH2D*)IsoMu->Get("NUM_TightRelIso_DEN_TightIDandIPCut_pt_abseta");

    FRMu = TFile::Open("data/SF2018/MuonFR_jet30.root","READ");
    hFRMu = (TH2D*)FREle->Get("FR_pT_eta");

    //btag eff maps file
    bTagEff = TFile::Open("data/bTagEff/btag_eff_2018.root");
  }

  hbTagEff_loose_b = (TH2D*)bTagEff->Get("h2_btag_deepcsv_wpL_EFF_B");
  hbTagEff_loose_c = (TH2D*)bTagEff->Get("h2_btag_deepcsv_wpL_EFF_C");
  hbTagEff_loose_l = (TH2D*)bTagEff->Get("h2_btag_deepcsv_wpL_EFF_L");

  hbTagEff_medium_b = (TH2D*)bTagEff->Get("h2_btag_deepcsv_wpM_EFF_B");
  hbTagEff_medium_c = (TH2D*)bTagEff->Get("h2_btag_deepcsv_wpM_EFF_C");
  hbTagEff_medium_l = (TH2D*)bTagEff->Get("h2_btag_deepcsv_wpM_EFF_L");

  hbTagEff_tight_b = (TH2D*)bTagEff->Get("h2_btag_deepcsv_wpT_EFF_B");
  hbTagEff_tight_c = (TH2D*)bTagEff->Get("h2_btag_deepcsv_wpT_EFF_C");
  hbTagEff_tight_l = (TH2D*)bTagEff->Get("h2_btag_deepcsv_wpT_EFF_L");

}
