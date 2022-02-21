#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
using namespace std;

//define punzi_eq
double effsigg(double signpassevent, double totalevent){
	return (signpassevent/totalevent);
}

void lep_eff()
{
    TFile *Mx2_1 = new TFile("./../../root_file/Ztoee/test1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/Ztoee/test50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/Ztoee/test150.root");

    TH1D *Mx2_1_ee = ((TH1D *)Mx2_1->Get("h_ee_event"));
    TH1D *Mx2_1_npass = ((TH1D *)Mx2_1->Get("h_ee_npass"));
    TH1D *Mx2_50_ee = ((TH1D *)Mx2_50->Get("h_ee_event"));
    TH1D *Mx2_50_npass = ((TH1D *)Mx2_50->Get("h_ee_npass"));
    TH1D *Mx2_150_ee = ((TH1D *)Mx2_150->Get("h_ee_event"));
    TH1D *Mx2_150_npass = ((TH1D *)Mx2_150->Get("h_ee_npass"));

    double event_Mx2_1 = Mx2_1_ee->Integral();
    double event_Mx2_50 = Mx2_50_ee->Integral();
    double event_Mx2_150 = Mx2_150_ee->Integral();

    vector<float> effs;
    vector<float> signpass;
    effs.clear();
    signpass.clear();

    int nBin = Mx2_50_npass->GetNbinsX();
    for (int i = 0; i < nBin; i++)
    {
        //signpass[i] =  
        //cout <<"i = "<<i<< "eff = "<<effsigg(Mx2_150_npass->GetBinContent(i+1),event_Mx2_150)<<endl;
        cout <<Mx2_1_npass->GetBinContent(i+1)<<endl;
        //npass[i] = Mx2_1_npass->GetBinContent(3);
    }

    //double event_Mx2_1

    cout << "ee event = "<<event_Mx2_150<<endl;
}