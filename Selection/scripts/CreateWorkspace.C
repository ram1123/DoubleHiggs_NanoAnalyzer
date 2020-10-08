{
  TFile * myFile = new TFile("/uscms/home/rasharma/nobackup/double-higgs/nanoAODAnalyzer/CMSSW_10_2_22/src/DoubleHiggs/Selection/Signal.root","r");
  TTree *myTree = (TTree*)myFile->Get("Events");

  float diphoton_m, genWeight,diphoton_pt;
  myTree->SetBranchAddress("diphoton_m",&diphoton_m);
  myTree->SetBranchAddress("genWeight",&genWeight);
  myTree->SetBranchAddress("diphoton_pt",&diphoton_pt);

  double nTotal=1, nNeg=1;
  TH1F* hTotEvents = (TH1F*) myFile->Get("TotalEvents"); assert(hTotEvents);
  nTotal = hTotEvents->GetBinContent(2);
  nNeg = hTotEvents->GetBinContent(1);

  float Lumi = 41.5;
  float xsec = 0.001;

  int entries = myTree->GetEntriesFast();
  std::cout <<"Total entries: " << entries << std::endl;

  RooRealVar CMS_hgg_mass("CMS_hgg_mass", "CMS_hgg_mass", 125.10,100,180, "GeV");
  RooRealVar IntLumi("IntLumi", "IntLumi", 36.5);
  RooRealVar weight("weight", "weight", -1000,1000);

  RooDataSet Data_13TeV_HHWWggTag_2("GluGluToHHTo_WWgg_qqqq_nodeSM_13TeV_HHWWggTag_2", "GluGluToHHTo_WWgg_qqqq_nodeSM_13TeV_HHWWggTag_2", RooArgSet(CMS_hgg_mass));
  RooDataSet Data_13TeV_HHWWggTag_2_weight("GluGluToHHTo_WWgg_qqqq_nodeSM_13TeV_HHWWggTag_2_weight", "GluGluToHHTo_WWgg_qqqq_nodeSM_13TeV_HHWWggTag_2_weight", RooArgSet(CMS_hgg_mass,weight));

  for (int i=0; i < entries; i++)
  {
    int nb = myTree->GetEntry(i);
    // if (diphoton_m < 0.) continue;
    if (diphoton_pt<100.0) continue;
    if (diphoton_m < 100. || diphoton_m > 180) continue;
    CMS_hgg_mass.setVal(diphoton_m);
    weight.setVal(xsec*Lumi*genWeight/(1.0*nTotal));
    // Data_13TeV_HHWWggTag_2.add(RooArgSet(CMS_hgg_mass));
    Data_13TeV_HHWWggTag_2.add(RooArgSet(CMS_hgg_mass,weight));
    Data_13TeV_HHWWggTag_2_weight.add(RooArgSet(CMS_hgg_mass,weight),xsec*Lumi*genWeight/(1.0*nTotal));
  }

  Data_13TeV_HHWWggTag_2.Print("v");

  RooWorkspace *workspace = new RooWorkspace("cms_hgg_13TeV", "cms_hgg_13TeV");
  workspace->import(Data_13TeV_HHWWggTag_2);
  workspace->Print();

  TCanvas* c1 = new TCanvas("c1", "Without weight");
  RooPlot* massDist = CMS_hgg_mass.frame(RooFit::Title("CMS_hgg_mass"));
  Data_13TeV_HHWWggTag_2.plotOn(massDist);
  massDist->Draw();
  c1->SaveAs("NoWeight.png");

  TCanvas* c2 = new TCanvas("c2", "After applying weight");
  RooPlot* massDist2 = CMS_hgg_mass.frame(RooFit::Title("CMS_hgg_mass"));
  Data_13TeV_HHWWggTag_2_weight.plotOn(massDist2);
  massDist2->Draw();
  c2->SaveAs("AfterWeight.png");

  workspace->writeToFile("nodeSM_HHWWgg_qqqq.root","kTRUE");

}

