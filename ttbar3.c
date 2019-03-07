void ttbar3()
{
	TFile *f = new TFile ("rootFiles/Electron_TTBar.root","READ");
	TTree *t = (TTree *) f -> Get("SingleTop13TeVAnalyzer/MCTop");
	TTree *t1 = (TTree *) f -> Get("SingleTop13TeVAnalyzer/MCTop");
	t -> SetLineColor(4);
	t -> Draw("MCTopPt","","hist");
	t1 -> SetLineColor(2);
	t1 -> Draw("MCTopPt","MCTopPt > 50","hist SAME");
	


//	t -> Draw("MCTopPt >> histo");
//	TH1F *h = (TH1F*) f -> Get("histo");
//	h -> Draw("PE");
}
