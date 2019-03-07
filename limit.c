void limit()
{
	const int nEvents = 1001;
	float cwww[nEvents];
	float deltaNLL[nEvents];
	float tempcwww=0.0;
	float tempdeltaNLL=0.0;

	TFile *f = new TFile("rootFiles/higgsCombine_cwww_3.6.MultiDimFit.mH120.root","READ");

	TTree *t = (TTree*) f-> Get("limit");
	TTree *t1 = (TTree*) f-> Get("limit");
	t -> SetBranchAddress("cwww",&tempcwww);
	t1 -> SetBranchAddress("deltaNLL",&tempdeltaNLL);	
	double upp_diff=100.0;
	double upp_limit=0.0;
	double low_diff=100.0;
	double low_limit=0.0;

	for (int i=0; i<nEvents; ++i)
	{ 
		 t ->  GetEntry(i);
		 cwww[i]=tempcwww;
		 t1 -> GetEntry(i);
		 deltaNLL[i]=tempdeltaNLL;
		 if ((abs(deltaNLL[i]-1.92) <low_diff)&& cwww[i]<0)
		 { 
			 low_diff =abs(deltaNLL[i]-1.92);
			 low_limit = cwww[i];
		 }
		 if ((abs(deltaNLL[i]-1.92) < upp_diff)&& cwww[i]>0)
		 {
			 upp_diff =abs(1.92-deltaNLL[i]);
			 upp_limit =cwww[i];
		 }
	   	 
	}
	cout << "upper limit  " << upp_limit << endl;
	cout << "lower limit  " << low_limit << endl;


	TGraph *tg  = new TGraph(nEvents,cwww,deltaNLL);
	tg -> Draw("AP");
	tg -> SetTitle("Limit;cwww;deltaNLL");

	TF1 *f1 = new TF1("Linear","[0]*x+[1]",-3,3);
	f1 -> SetParameters(0,1.92);
	f1 -> Draw("SAME");
	
	TF1 *f2 = new TF1 ("f2","pol4",-4,4);
	tg -> Fit(f2);

}
