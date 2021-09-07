from ROOT import TCanvas, TPad, TFile, TPaveText
from ROOT import gBenchmark, gStyle, gROOT
import ROOT
c1 = TCanvas('c1','The Ntuple canvas',200,10,700,780)

# step - 1: Access the root files
f1 = TFile('/afs/cern.ch/user/z/zhenxuan/CMSSW_10_6_20/src/DoubleHiggs/Selection/output.root')

# step - 2: Get trees from the root files pointer f1/f2
treeIn1 = f1.Get('Events',"")



h1 = ROOT.TH1F("h1","",121,110,160)
h1.SetTitleFont(100,"X")
h1.SetTitleFont(100,"Y")
h1.SetLineColor(1)
h1.SetLineWidth(2)
h1.SetStats(0)
ROOT.gPad.SetLeftMargin(0.15)
ROOT.gPad.SetRightMargin(0.1)



treeIn1.Draw("diphoton_m>>h1")
pic = "plotmgg.png"
c1.SaveAs(pic)
