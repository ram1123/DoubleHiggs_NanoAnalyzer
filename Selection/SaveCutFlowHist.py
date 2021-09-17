import ROOT
import sys

ROOT.gROOT.SetBatch(0)

if len(sys.argv) != 2:
    print "USAGE: %s <input file> <output file>"%(sys.argv[0])
    sys.exit(1)

inFileName = sys.argv[1]
print "Reading from", inFileName

inFileNameSplit = inFileName.split("_")
if len(inFileNameSplit) == 1:
    outputFile = inFileName.replace(".root","")
else:
    outputFile = inFileName.split("_")[1].replace(".root","")
inFile = ROOT.TFile.Open(inFileName, "READ")

h1 = inFile.Get("TotalCutFlow")
h1.SetTitle(outputFile)

c1 = ROOT.TCanvas()
h1.Draw("TEXT")
if outputFile == "":
    outputFile = inFileName.replace(".root","")
# c1.SaveAs(outputFile+".png")
c1.SaveAs(outputFile+".pdf")
# h1.Print("all")
