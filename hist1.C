#include <TCanvas.h>
#include <TFile.h>
void hist1()
{
	const int n=14;
	int a[n]={12,11,12,14,7,8,5,13,15,14,19,14,12,14};
	TH1F* h1= new TH1F("h1","Hist from Array",50,2,20);
	for (int i=0; i<n; i++)
	{  
		h1 -> Fill(a[i]);
	} 
	h1 -> SetFillColor(4);
	h1 -> SetLineStyle(5);
	h1 -> SetFillStyle(3002);
	h1 -> GetXaxis()-> SetTitle("X");
	h1 -> GetYaxis()-> SetTitle("Events");
	h1 -> GetXaxis()-> CenterTitle();
	h1 -> GetYaxis()-> CenterTitle();
	TCanvas *c1 = new TCanvas;
	h1 -> Draw();
	TFile *file = new TFile( "HistFromArray.root","recreate");
	file -> mkdir("general");
	file -> cd("general");
	h1 -> Write();
	c1 -> SaveAs("HistFromArray.pdf");
}
