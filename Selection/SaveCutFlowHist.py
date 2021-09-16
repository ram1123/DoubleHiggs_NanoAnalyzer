import ROOT
import sys

ROOT.gROOT.SetBatch(0)

if len(sys.argv) != 2:
    print "USAGE: %s <input file> <output file>"%(sys.argv[0])
    sys.exit(1)

inFileName = sys.argv[1]
print "Reading from", inFileName

outputFile = inFileName.split("_")[1].replace(".root","")
inFile = ROOT.TFile.Open(inFileName, "READ")

h1 = inFile.Get("TotalCutFlow")

c1 = ROOT.TCanvas()
h1.Draw("TEXT")
c1.SaveAs(outputFile+".png")
h1.Print("all")
# c1.SaveAs(outputFile+".png")