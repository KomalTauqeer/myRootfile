void ttbar1()
{
	// Reading a root file
	
	TFile *f = new TFile("rootFiles/Electron_TTBar.root","READ");
	
	// Reading histo
	
	//TH1F *h = (TH1F*) f -> Get("SingleTop13TeVAnalyzer/MCLightJetMul");
	//h->Draw("PE");
	
	// Reading tree branch and plotting histo
	
	TTree *t = (TTree*) f -> Get("SingleTop13TeVAnalyzer/MCJets");
	t -> Draw("MCJetPt >> histo");
	TH1F *h = (TH1F*) f -> Get("histo");
	h -> Draw("PE");

	h -> GetXaxis() -> SetRangeUser(0,550);

	// Log normal fit
	
	//TF1 *f1= new TF1("f1","[2]*(1/x)*(1/[1]*TMath::Sqrt(2*TMath::Pi()))*TMath::Exp(-1*(TMath::Power((TMath::Log(x)-[0]),2))/(2*TMath::Power([1],2)))",0,200);
	//f1->SetParameters(200,100,1000);
	//h->Fit(f1,"R");
	

	//Landau fit
	
	TF1 *f3= new TF1("f3","landau",0,100);
	h -> Fit(f3,"R");
	
	// Expo 
		
	TF1 *f2 = new TF1("f2","expo",90,420);
	h->Fit(f2,"R+");
	gStyle -> SetOptFit(1111);

	
	

}

