from ROOT import TCanvas, TPad, TFile, TPaveText
from ROOT import gBenchmark, gStyle, gROOT
import ROOT
import sys
ROOT.gROOT.SetBatch(True)
c1 = TCanvas('c1')

if len(sys.argv) != 2:
    print "USAGE: %s <input file> <output file>"%(sys.argv[0])
    sys.exit(1)

Mass = sys.argv[1]

# step - 1: Access the root files
# Mass = 1500
# FileName = "GluGluToRadionToHHTo2G4Q_M250"
# FileName = "GluGluToRadionToHHTo2G4Q_M1000"
# FileName = "GluGluToRadionToHHTo2G4Q_M3000"
# FileName = "GluGluToRadionToHHTo2G4Q_M500"
# FileName = "GluGluToRadionToHHTo2G4Q_M800"
# FileName = "GluGluToRadionToHHTo2G4Q_M1500"
# FileName = "GluGluToRadionToHHTo2G4Q_M2000"
# FileName = "GluGluToRadionToHHTo2G4Q_M2500"
FileName = "GluGluToRadionToHHTo2G4Q_M"+str(Mass)
f1 = TFile(FileName+'.root')

# step - 2: Get trees from the root files pointer f1/f2
treeIn1 = f1.Get('Events')



# h1 = ROOT.TH1F("h1","",151,0,1000)
# h1.SetTitleFont(100,"X")
# h1.SetTitleFont(100,"Y")
# h1.SetLineColor(1)
# h1.SetLineWidth(2)
# h1.SetStats(0)
# ROOT.gPad.SetLeftMargin(0.15)
# ROOT.gPad.SetRightMargin(0.1)

h1 = ROOT.TH1F("h1","",151,50,200)
treeIn1.Draw("diphoton_m>>h1")
pic = FileName+"_diphoton.png"
c1.SaveAs(pic)
h2 = ROOT.TH1F("h2","",151,50,1500)
treeIn1.Draw("FullyResolved_FourJets_m>>h2")
pic = FileName+"_4jets.png"
c1.SaveAs(pic)
h3 = ROOT.TH1F("h3","",151,100,float(Mass)*2.0)
treeIn1.Draw("FullyResolved_Radion_m>>h3")
pic = FileName+"_radion.png"
c1.SaveAs(pic)
