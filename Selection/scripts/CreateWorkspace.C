{
  TFile * myFile = new TFile("/uscms/home/rasharma/nobackup/double-higgs/nanoAODAnalyzer/CMSSW_10_2_22/src/DoubleHiggs/Selection/output.root","r");
  TTree *myTree = (TTree*)myFile->Get("Events");

  float diphoton_m, genWeight;
  myTree->SetBranchAddress("diphoton_m",&diphoton_m);
  myTree->SetBranchAddress("genWeight",&genWeight);

  double nTotal=1, nNeg=1;
  TH1F* hTotEvents = (TH1F*) myFile->Get("TotalEvents"); assert(hTotEvents);
  nTotal = hTotEvents->GetBinContent(2);
  nNeg = hTotEvents->GetBinContent(1);

  float Lumi = 3400.0;
  float xsec = 0.001;

  int entries = myTree->GetEntriesFast();
  std::cout <<"Total entries: " << entries << std::endl;

  RooRealVar* CMS_hgg_mass = new RooRealVar("CMS_hgg_mass","CMS_hgg_mass",125.6,100,180, "GeV");
  RooRealVar* weight = new RooRealVar("weight","weight",-10,10);

  RooArgSet* ArgSet = new RooArgSet("args");
  ArgSet->add(*CMS_hgg_mass);
  ArgSet->add(*weight);
  RooDataSet* ggh_125_13TeV_cat0 = new RooDataSet("ggh_125_13TeV_cat0", "ggh_125_13TeV_cat0", *ArgSet, "weight");

  // Fill all integers from 0 to 100 as mass
  for (int i=0; i < entries; i++)
  {
    int nb = myTree->GetEntry(i);
    if (diphoton_m < 0.) continue;
    CMS_hgg_mass->setVal(diphoton_m);
    weight->setVal(xsec*Lumi*genWeight/(1.0*nTotal));
    ggh_125_13TeV_cat0->add(*ArgSet,xsec*Lumi*genWeight/(1.0*nTotal));
  }

  TCanvas* c1 = new TCanvas("c1", "After applying weight");
  RooPlot* massDist = CMS_hgg_mass->frame(RooFit::Title("CMS_hgg_mass"));
  ggh_125_13TeV_cat0->plotOn(massDist);
  massDist->Draw();
  c1->SaveAs("AfterWeight.png");

  RooWorkspace workspace("CMS_hgg_13TeV", "CMS_hgg_13TeV");
  workspace.import(*ggh_125_13TeV_cat0);
  workspace.import(*weight);
  workspace.writeToFile("workspace.root");
}

