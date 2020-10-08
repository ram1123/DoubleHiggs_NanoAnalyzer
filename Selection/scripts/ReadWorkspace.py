from ROOT import *

myfile = TFile('nodeSM_HHWWgg_qqqq.root')
w = myfile.Get("cms_hgg_13TeV")

w.Print();

print "="*51
mass = w.var("CMS_hgg_mass")

wMass = w.data("GluGluToHHTo_WWgg_qqqq_nodeSM_13TeV_HHWWggTag_3_MCScaleHighR9EBUp01sigma");
#wMassNoWeight = w.data("GluGluToHHTo_WWgg_qqqq_nodeSM_13TeV_HHWWggTag_2");

obs = wMass.get()
xmass = obs.find("CMS_hgg_mass")

print "="*51

for x in xrange(0, wMass.numEntries()):
  wMass.get(x)
  # print xmass.getValV()
  # print xmass.getValV(),"\t",xweight.getValV()

c1 = TCanvas("c1")
rooplot = mass.frame(RooFit.Title("test"))
#wMassNoWeight.plotOn(rooplot)
#rooplot.Draw()

#c2 = TCanvas("c2","Without Weight")
#rooplot = mass.frame(RooFit.Title("test"))
wMass.plotOn(rooplot)
rooplot.Draw()
#rooplot.Draw("same")
raw_input()
