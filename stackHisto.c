void stackHisto()
{
	TH1F *h1 = new TH1F("h1","WW",50,0,200);
	TH1F *h2 = new TH1F("h2","WZ",50,0,200);
	TH1F *h3 = new TH1F("h3","W+jets",50,0,200);
	for (int n=0;n<=250000;n++)
	{
		h1->Fill(gRandom->Gaus(80,40));
		h2->Fill(gRandom->Gaus(91,40));
		h3->Fill(gRandom->Gaus(80,60));
	}

	h1 -> SetFillColor(kYellow);
	h2 -> SetFillColor(kBlue);
        h3 -> SetFillColor(kGreen);
	//h1 -> GetXaxis() -> SetTitle("mass (GeV)");
	//h1 -> GetYaxis() -> SetTitle("Events");
	THStack *hs = new THStack("hs","Stacked 1D Histograms");
	hs -> Add(h1);
	hs -> Add(h2);
	hs -> Add(h3);
	hs -> Draw();	
	hs -> GetXaxis() -> SetTitle("mass (GeV)");
        hs -> GetYaxis() -> SetTitle("Events");
	
	auto legend = new TLegend(.7,.7,.9,.9);
	legend -> AddEntry(h1,"WW","f");
	legend -> AddEntry(h2,"WZ","f");
	legend -> AddEntry(h3,"W+jets","f");
	legend -> Draw();
}
