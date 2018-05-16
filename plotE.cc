#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include "TROOT.h"
#include "TF1.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TNtuple.h"
#include "TFile.h"
#include "TRandom.h"
#include "TMath.h"
#include "TCanvas.h"

using namespace std;

void plotE(){

	string name2,jel,name1,particleName;
	Double_t momdirX,momdirY,momdirZ,Edep,preX,preY,preZ;
	Double_t momdirTheta,momdirPhi,postX,postY,postZ;
	string prevolume,postvolume;
	
	Int_t osztas=1000;
	Double_t minZ=20.0,maxZ=23.0,minXY=-25.0,maxXY=25.0;
	
	TCanvas  * cX = new TCanvas("Canvas","Results",800,600);
	auto h1 = new TH1D("TH1D", "Energy_Z", osztas, minZ, maxZ);
	auto h2 = new TH2D("TH2D", "Energy_XY", osztas, minXY, maxXY, osztas, minXY, maxXY);
	
	ifstream in1("out.txt");
	
	while(!in1.eof())
	{
		in1>>name2>>jel>>name1>>particleName>>momdirX>>momdirY>>momdirZ>>Edep>>preX>>preY>>preZ>>momdirTheta>>momdirPhi>>postX>>postY>>postZ>>prevolume>>postvolume;
		h1->Fill(postZ,Edep); //histo1 feltoltese adatokkal
		h2->Fill(postX,postY,Edep); //histo2 feltoltese adatokkal
	}
	
	cX->Divide(2,1);
	cX->cd(1);
	h1->Draw("hist");
	cX->cd(2);
	h2->Draw("colz");
	
	in1.close();

}
