void ttbar2()
{
	 TFile *f = new TFile("rootFiles/Electron_TTBar.root","READ");
	 TTree *t = (TTree*) f -> Get("SingleTop13TeVAnalyzer/MCTop");
	 t -> Draw("MCTopMass","MCTopMass > 50","PE");
	 // TF1 *f1 = new TF1 ("f1","landau",0,200);
	 //t -> Fit("f1","MCTopMass","MCTopMass > 50","PE");
	 //gStyle -> SetOptStat(1111);
}
