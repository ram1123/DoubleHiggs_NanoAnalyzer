#ifndef UTILS_HH
#define UTILS_HH

#include "TMath.h"
#include "../interface/WVJJData.hh"

//float deltaR(float eta1, float phi1, float eta2, float phi2) {
//
//  float dPhi = fabs(phi1-phi2);
//  if (dPhi>6.283185308) dPhi -= 6.283185308;
//  if (dPhi>3.141592654) dPhi = 6.283185308 - dPhi;
//
//  float dEta = fabs(eta1-eta2);
//
//  return sqrt( dPhi*dPhi + dEta*dEta );
//
//}

float deltaR(float eta1, float phi1, float eta2, float phi2) {
  float deltaPhi = TMath::Abs(phi1-phi2);
  float deltaEta = eta1-eta2;
  if(deltaPhi > TMath::Pi()) {
    deltaPhi = TMath::TwoPi() - deltaPhi;
  }
  return TMath::Sqrt(deltaEta*deltaEta + deltaPhi*deltaPhi);
}

float GetBinTH2_value(float x, float y, TH2* h2) {
  int nbinsX = h2->GetNbinsX();
  int nbinsY = h2->GetNbinsY();
  int xbin = h2->GetXaxis()->FindBin(x);
  int ybin = h2->GetYaxis()->FindBin(y);
  xbin = (xbin > nbinsX) ? nbinsX : (xbin < 1 ? 1 : xbin);
  ybin = (ybin > nbinsY) ? nbinsY : (ybin < 1 ? 1 : ybin);
  return h2->GetBinContent(xbin, ybin);
}

float GetSFs_Lepton(double pt, double eta, TH1 *h1){
  if (pt > h1->GetYaxis()->GetXmax())
    pt = h1->GetYaxis()->GetXmax() - 1.0;
  if (pt < h1->GetYaxis()->GetXmin())
    pt = h1->GetYaxis()->GetXmin() + 1.0;

  return h1->GetBinContent(h1->GetXaxis()->FindFixBin(eta), h1->GetYaxis()->FindFixBin(pt));
}

//double GetJECunc( double pt, double eta, JetCorrectionUncertainty *fJetUnc) {
//  fJetUnc->setJetPt ( pt  );
//  fJetUnc->setJetEta( eta );
//  return fJetUnc->getUncertainty(true);
//}

/**
 * @brief      Check if the string contains suffix or not
 *
 * @param[in]  s       Input string
 * @param[in]  suffix  Suffix to check
 *
 * @return     Return true or false if input string contains suffix or not.
 */
bool ends_with(const std::string & s, const std::string & suffix) {
    return s.rfind(suffix) == s.length() - suffix.length();
}

#endif
