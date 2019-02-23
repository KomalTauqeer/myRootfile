void ex1()
{
	TH1F *h1 = new TH1F("h1","Histogram",80,0,8);
	for (int i=0;i<10000;++i)
	{
		h1 -> Fill(gRandom->Gaus(3,1));
	}
	h1 -> GetXaxis() -> SetTitle("Random Number");
	h1 -> GetYaxis() -> SetTitle("Events");
	h1 -> GetYaxis() -> SetRangeUser(0,750);
	h1 -> SetLineWidth(2);
	h1 -> Draw();

	TH1F *h2 = new TH1F("h2","",80,0,8);
	for (int j=0;j<10000;++j)
	{
		h2 -> Fill(gRandom->Gaus(2,1));
	}
	h2 -> Draw("Same");
	h2 -> SetLineColor(8);
	h2 -> SetLineWidth(2);


	//Adding histograms
	
	TH1F *h3 = new TH1F("h3","",80,0,8);
	h3 -> Add(h1,h2);
	h3 -> SetLineColor(2);
	h3 -> SetLineWidth(2);

	//h3 -> GetYaxis() -> SetRange(0,600);
	h3 -> Draw("Same");

	//Dividing histograms
	
	TH1F *h4 = new TH1F("h4","",80,0,8);
	h4 -> Divide(h1,h2);
	h4 -> SetLineWidth(2);
	h4 -> SetLineColor(6);
	h4 -> Draw("Same");

	auto legend = new TLegend(.7,.7,.9,.9, "  ");
	legend -> AddEntry(h1,"h1","L");
	legend -> AddEntry(h2,"h2","L");
	legend -> AddEntry(h3,"h1 + h2","L");
	legend -> AddEntry(h4,"h1 / h2","L");
	legend -> Draw();

	//gStyle -> SetOptStat(0);
	gStyle -> SetOptFit(1111);
}
