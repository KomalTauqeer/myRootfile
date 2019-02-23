void macro1()
{
	const int nPoints = 10;
	double xValue[nPoints] = {1,2,3,4,5,6,7,8,9,10};
	double yValue[nPoints] = {6,12,14,20,22,24,35,45,44,53};
	double yErrors[nPoints] = {5,5,4.7,4.5,4.2,5.1,2.9,4.1,4.8,5.43};

	auto graph = new TGraphErrors(nPoints,xValue,yValue,nullptr,yErrors);

	graph -> Draw("APEL");

	graph -> SetMarkerStyle(kFullCircle);
	graph -> SetMarkerSize(1);
	graph -> SetMarkerColor(kMagenta);
	graph -> SetLineColor(kViolet + 1);
	graph -> SetLineWidth(3);
	graph -> SetLineStyle(1);

	graph -> SetTitle("My Graph;X;Y");

	gPad -> SetGrid();

	// fitting
	
	auto f = new TF1("Linear law", "[0]+x*[1]",0.5,10.5);
	f -> SetLineColor(kRed);
	f -> SetLineStyle(2);

	graph -> Fit(f);

	// Build and draw a legend
	
	auto legend = new TLegend(.1,.7,.3,.9,"Lab. Lesson 1");
	legend -> AddEntry(graph, "Exp. Points","PE");
	legend -> AddEntry(f, "Th. Law","L");
	legend -> Draw();
}
