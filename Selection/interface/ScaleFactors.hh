#ifndef SCALE_FACTORS_HH
#define SCALE_FACTORS_HH

#include "TFile.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"

#include "../interface/Utils.hh"

class ScaleFactors {

public:
  ScaleFactors(int era) {
    if (era!=2016 && era!=2017 && era!=2018) {
      std::cout << "Invalid Era! Using 2016." << std::endl;
      era_ = 2016;
    }
    else {
      era_=era;
    }
    setupSFs();
  };

  ~ScaleFactors() {};

  void setupSFs();

  float GetPUWeight(int nPUmean, int var=0) {
    if (var==1) return puWeightsUp->GetBinContent(nPUmean);
    else if (var==-1) return puWeightsDown->GetBinContent(nPUmean);

    return puWeights->GetBinContent(nPUmean);
  };

  float GetLeptonWeights(float lepPt, float lepEta, int pid) {
    float totWeight=1.0;
    if (pid==11) {
      totWeight*=GetBinTH2_value(lepEta, lepPt, hIDIsoEle);
    }
    if (pid==13) {
      if (era_==2016) {
        totWeight*=GetBinTH2_value(lepEta, lepPt, hIDMu);
        totWeight*=GetBinTH2_value(lepEta, lepPt,  hIsoMu);
      }
      else {
        totWeight*=GetBinTH2_value(lepPt, abs(lepEta), hIDMu);
        totWeight*=GetBinTH2_value(lepPt, abs(lepEta), hIsoMu);
      }
    }

    return totWeight;
  };

  float GetLeptonFakeWeights(float lepPt, float lepEta, int pid) {
    float totWeight=1.0;
    if (pid==11) {
      totWeight*=GetBinTH2_value(lepPt, abs(lepEta), hFREle);
    }
    if (pid==13) {
      totWeight*=GetBinTH2_value(lepPt, abs(lepEta), hFRMu);
    }
    return totWeight;

  };

  float GetBtagEff(int jetFlavor, float jetPt, float jetEta, std::string wp) {
    float totWeight=1.0;
    if (wp == "loose") {
      if (jetFlavor == 5) totWeight = GetBinTH2_value(jetPt, abs(jetEta), hbTagEff_loose_b);
      if (jetFlavor == 4) totWeight = GetBinTH2_value(jetPt, abs(jetEta), hbTagEff_loose_c);
      if (jetFlavor == 0) totWeight = GetBinTH2_value(jetPt, abs(jetEta), hbTagEff_loose_l);
    }
    if (wp == "medium") {
      if (jetFlavor == 5) totWeight = GetBinTH2_value(jetPt, abs(jetEta), hbTagEff_medium_b);
      if (jetFlavor == 4) totWeight = GetBinTH2_value(jetPt, abs(jetEta), hbTagEff_medium_c);
      if (jetFlavor == 0) totWeight = GetBinTH2_value(jetPt, abs(jetEta), hbTagEff_medium_l);
    }
    if (wp == "tight") {
      if (jetFlavor == 5) totWeight = GetBinTH2_value(jetPt, abs(jetEta), hbTagEff_tight_b);
      if (jetFlavor == 4) totWeight = GetBinTH2_value(jetPt, abs(jetEta), hbTagEff_tight_c);
      if (jetFlavor == 0) totWeight = GetBinTH2_value(jetPt, abs(jetEta), hbTagEff_tight_l);
    }
    return totWeight;
  };


private:

  int era_;

  // pileup
  TFile* pileupFileMC;
  TH1D* puWeights;
  TH1D* puWeightsUp;
  TH1D* puWeightsDown;

  // electrons
  TFile* IDIsoEle;
  TH2F *hIDIsoEle;

  TFile* TriggerEle;
  TH2F* hTriggerEle;

  TFile* FREle;
  TH2D* hFREle;

  // muons
  TFile* IDMu;
  TH2D *hIDMu;

  TFile* IsoMu;
  TH2D *hIsoMu;

  TFile* TriggerMu;
  TH2D* hTriggerMu;

  TFile* FRMu;
  TH2D* hFRMu;

  // btag weight
  TFile* bTagEff;
  TH2D* hbTagEff_loose_b;
  TH2D* hbTagEff_loose_c;
  TH2D* hbTagEff_loose_l;

  TH2D* hbTagEff_medium_b;
  TH2D* hbTagEff_medium_c;
  TH2D* hbTagEff_medium_l;

  TH2D* hbTagEff_tight_b;
  TH2D* hbTagEff_tight_c;
  TH2D* hbTagEff_tight_l;
};

#endif
