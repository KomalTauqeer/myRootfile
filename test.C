void test()
{
	TH1F *hist1= new TH1F("hist1","",1000,0,10) ;
	for (int n=0;n<=250000;n++)
	{
		hist1->Fill(gRandom->Gaus(5,2));
	}
	hist1->SetLineColor(6);
	hist1->SetFillColor(6);
	hist1->SetLineStyle(6);
	hist1->Draw();
}
