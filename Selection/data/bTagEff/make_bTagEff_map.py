#!/usr/bin/env python

import ROOT
import numpy as np
import argparse

ROOT.gROOT.SetBatch(True)

parser = argparse.ArgumentParser(description="make btag efficiency maps")
parser.add_argument("--era", type=str, default="2016", help="year 2016, 2017, 2018")
parser.add_argument("--input", type=str, default="dataset_2016.txt", help="input list of datasets")
parser.add_argument("--output", type=str, default="", help="output root file name")

args = parser.parse_args()


events_tfile = []
events_ttree = []

for dataset in open(args.input, "r").readlines():
    if dataset[0] == "#": continue
    print(dataset)
    events_tfile.append(ROOT.TFile.Open("root://cmseos.fnal.gov/" + dataset.strip()))
    events_ttree.append(events_tfile[-1].Get("Events"))


#pt_nbins = 5
#pt_min = 30.0
#pt_max = 1000.0
pt_bins = np.array(
    [30.0, 50.0, 70.0, 100.0, 140.0, 200.0, 300.0, 600.0, 1000.0]
)
pt_nbins = len(pt_bins) - 1

eta_nbins = 8;
eta_min = 0.0;
eta_max = 2.4;

selection = "Jet_pt_nom > 30 && abs(Jet_eta) < 2.4"
jet_B = "Jet_hadronFlavour == 5"
jet_C = "Jet_hadronFlavour == 4"
jet_L = "Jet_hadronFlavour == 0"

if args.era == "2018":
    btag_cut_wpL = "Jet_btagDeepB > 0.1241"
    btag_cut_wpM = "Jet_btagDeepB > 0.4184"
    btag_cut_wpT = "Jet_btagDeepB > 0.7527"
if args.era == "2017":
    btag_cut_wpL = "Jet_btagDeepB > 0.1522"
    btag_cut_wpM = "Jet_btagDeepB > 0.4941"
    btag_cut_wpT = "Jet_btagDeepB > 0.8001"
if args.era == "2016":
    btag_cut_wpL = "Jet_btagDeepB > 0.2217"
    btag_cut_wpM = "Jet_btagDeepB > 0.6321"
    btag_cut_wpT = "Jet_btagDeepB > 0.8953"


h2_btag_deepcsv_DEN_B = ROOT.TH2D("h2_btag_deepcsv_DEN_B", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)
h2_btag_deepcsv_DEN_C = ROOT.TH2D("h2_btag_deepcsv_DEN_C", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)
h2_btag_deepcsv_DEN_L = ROOT.TH2D("h2_btag_deepcsv_DEN_L", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)

h2_btag_deepcsv_wpL_NUM_B = ROOT.TH2D("h2_btag_deepcsv_wpL_NUM_B", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)
h2_btag_deepcsv_wpM_NUM_B = ROOT.TH2D("h2_btag_deepcsv_wpM_NUM_B", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)
h2_btag_deepcsv_wpT_NUM_B = ROOT.TH2D("h2_btag_deepcsv_wpT_NUM_B", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)

h2_btag_deepcsv_wpL_NUM_C = ROOT.TH2D("h2_btag_deepcsv_wpL_NUM_C", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)
h2_btag_deepcsv_wpM_NUM_C = ROOT.TH2D("h2_btag_deepcsv_wpM_NUM_C", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)
h2_btag_deepcsv_wpT_NUM_C = ROOT.TH2D("h2_btag_deepcsv_wpT_NUM_C", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)

h2_btag_deepcsv_wpL_NUM_L = ROOT.TH2D("h2_btag_deepcsv_wpL_NUM_L", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)
h2_btag_deepcsv_wpM_NUM_L = ROOT.TH2D("h2_btag_deepcsv_wpM_NUM_L", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)
h2_btag_deepcsv_wpT_NUM_L = ROOT.TH2D("h2_btag_deepcsv_wpT_NUM_L", "", pt_nbins, pt_bins, eta_nbins, eta_min, eta_max)


def loop(ttree):
    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_DEN_B", selection + " && " + jet_B)
    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_DEN_C", selection + " && " + jet_C)
    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_DEN_L", selection + " && " + jet_L)

    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_wpL_NUM_B", selection + " && " + jet_B + " && " + btag_cut_wpL)
    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_wpM_NUM_B", selection + " && " + jet_B + " && " + btag_cut_wpM)
    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_wpT_NUM_B", selection + " && " + jet_B + " && " + btag_cut_wpT)

    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_wpL_NUM_C", selection + " && " + jet_C + " && " + btag_cut_wpL)
    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_wpM_NUM_C", selection + " && " + jet_C + " && " + btag_cut_wpM)
    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_wpT_NUM_C", selection + " && " + jet_C + " && " + btag_cut_wpT)

    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_wpL_NUM_L", selection + " && " + jet_L + " && " + btag_cut_wpL)
    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_wpM_NUM_L", selection + " && " + jet_L + " && " + btag_cut_wpM)
    ttree.Draw("Jet_eta:Jet_pt>>+h2_btag_deepcsv_wpT_NUM_L", selection + " && " + jet_L + " && " + btag_cut_wpT)

for i, ttree in enumerate(events_ttree):
    print("File " + str(i + 1) + "/" + str(len(events_ttree)))
    loop(ttree)


h2_btag_deepcsv_wpL_EFF_B = h2_btag_deepcsv_wpL_NUM_B.Clone("h2_btag_deepcsv_wpL_EFF_B")
h2_btag_deepcsv_wpM_EFF_B = h2_btag_deepcsv_wpM_NUM_B.Clone("h2_btag_deepcsv_wpM_EFF_B")
h2_btag_deepcsv_wpT_EFF_B = h2_btag_deepcsv_wpT_NUM_B.Clone("h2_btag_deepcsv_wpT_EFF_B")

h2_btag_deepcsv_wpL_EFF_C = h2_btag_deepcsv_wpL_NUM_C.Clone("h2_btag_deepcsv_wpL_EFF_C")
h2_btag_deepcsv_wpM_EFF_C = h2_btag_deepcsv_wpM_NUM_C.Clone("h2_btag_deepcsv_wpM_EFF_C")
h2_btag_deepcsv_wpT_EFF_C = h2_btag_deepcsv_wpT_NUM_C.Clone("h2_btag_deepcsv_wpT_EFF_C")

h2_btag_deepcsv_wpL_EFF_L = h2_btag_deepcsv_wpL_NUM_L.Clone("h2_btag_deepcsv_wpL_EFF_L")
h2_btag_deepcsv_wpM_EFF_L = h2_btag_deepcsv_wpM_NUM_L.Clone("h2_btag_deepcsv_wpM_EFF_L")
h2_btag_deepcsv_wpT_EFF_L = h2_btag_deepcsv_wpT_NUM_L.Clone("h2_btag_deepcsv_wpT_EFF_L")


h2_btag_deepcsv_wpL_EFF_B.Divide(h2_btag_deepcsv_DEN_B)
h2_btag_deepcsv_wpM_EFF_B.Divide(h2_btag_deepcsv_DEN_B)
h2_btag_deepcsv_wpT_EFF_B.Divide(h2_btag_deepcsv_DEN_B)

h2_btag_deepcsv_wpL_EFF_C.Divide(h2_btag_deepcsv_DEN_C)
h2_btag_deepcsv_wpM_EFF_C.Divide(h2_btag_deepcsv_DEN_C)
h2_btag_deepcsv_wpT_EFF_C.Divide(h2_btag_deepcsv_DEN_C)

h2_btag_deepcsv_wpL_EFF_L.Divide(h2_btag_deepcsv_DEN_L)
h2_btag_deepcsv_wpM_EFF_L.Divide(h2_btag_deepcsv_DEN_L)
h2_btag_deepcsv_wpT_EFF_L.Divide(h2_btag_deepcsv_DEN_L)


if args.output == "":
    output_filename = "btag_eff_" + args.era + ".root"
else:
    output_filename = args.output
output = ROOT.TFile.Open(output_filename, "recreate")
output.cd()

h2_btag_deepcsv_DEN_B.Write()
h2_btag_deepcsv_DEN_C.Write()
h2_btag_deepcsv_DEN_L.Write()

h2_btag_deepcsv_wpL_NUM_B.Write()
h2_btag_deepcsv_wpM_NUM_B.Write()
h2_btag_deepcsv_wpT_NUM_B.Write()

h2_btag_deepcsv_wpL_NUM_C.Write()
h2_btag_deepcsv_wpM_NUM_C.Write()
h2_btag_deepcsv_wpT_NUM_C.Write()

h2_btag_deepcsv_wpL_NUM_L.Write()
h2_btag_deepcsv_wpM_NUM_L.Write()
h2_btag_deepcsv_wpT_NUM_L.Write()

h2_btag_deepcsv_wpL_EFF_B.Write()
h2_btag_deepcsv_wpM_EFF_B.Write()
h2_btag_deepcsv_wpT_EFF_B.Write()

h2_btag_deepcsv_wpL_EFF_C.Write()
h2_btag_deepcsv_wpM_EFF_C.Write()
h2_btag_deepcsv_wpT_EFF_C.Write()

h2_btag_deepcsv_wpL_EFF_L.Write()
h2_btag_deepcsv_wpM_EFF_L.Write()
h2_btag_deepcsv_wpT_EFF_L.Write()

output.Write()
output.Close()
