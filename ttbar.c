#include <TMath.h>
void ttbar()
{
	TFile *MyFile = new TFile("Electron_TTBar.root","READ");
	if ( MyFile->IsOpen() ) 
	{
			printf("File opened successfully\n");
	}

	//TH1F *h = (TH1F*)gDirectory->Get("MCTightJetMul");
	//h -> Draw();


	TTree *t =(TTree*)MyFile->Get("SingleTop13TeVAnalyzer/MCTop");
	t -> Draw("MCTopMass >> histogram");
	TH1F *h =(TH1F*)gDirectory-> Get("histogram");

	h->Draw("PE");
	h->GetXaxis()->SetRangeUser(0,1000);

	//TF1 *f= new TF1("f","[2]*(1/x)*(1/[1]*TMath::Sqrt(2*TMath::Pi()))*TMath::Exp(-1*(TMath::Power((TMath::Log(x)-[0]),2))/(2*TMath::Power([1],2)))",10,180);
	//f->SetParameters(200,100,1000);
	//h->Fit(f);

	//TF1 *f= new TF1("f","([0]*TMath::Power(x,3))*(1/(TMath::Exp(([1]/[2])*x)-1))",10,180);
	//f-> SetParameters(1500,500,900);
	//h->Fit(f);
	//gStyle -> SetOptFit(1111);

	//TF1 *f= new TF1("f","((Exp(-1*[0])*(Power([0],x)))/(Factorial(x))",10,180);
        //f-> SetParameters(400,500,900);
        //h-> Fit(f);
        //gStyle -> SetOptFit(1111);

	TF1 *f = new TF1("f","landau",100,200);
	TF1 *f1 = new TF1("f1","expo",150,800);
        //f-> SetParameters(400,500,900);
        h-> Fit(f,"R");
	h-> Fit(f1,"R+");
        gStyle -> SetOptFit(1111);


}


