void ttbar()
{
	TFile *MyFile = new TFile("Electron_TTBar.root","READ");
	if ( MyFile->IsOpen() ) 
	{
			printf("File opened successfully\n");
	}
	MyFile -> ls();
	//TFile MyFile("Electron_TTBar.root");
	//if (MyFile.IsZombie()) {
   //std::cout << "Error opening file" << std::endl;
  // exit(-1);
//}	



}


