#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "Cross_section.h"
using namespace std;

//define punzi_eq
double punzi(double sigeff, double bg){
	return sigeff/(1+TMath::Power(abs(bg),0.5));
} 

void punzi()
{

    TFile *Mx2_1 = new TFile("./../../root_file/test/test1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/test/test50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/test/test150.root");


    TFile *DYpT50 = new TFile("./../../root_file/test/test_pt50.root");
    TFile *DYpT100 = new TFile("./../../root_file/test/test_pt100.root");
    TFile *DYpT250 = new TFile("./../../root_file/test/test_pt250.root");
    TFile *DYpT400 = new TFile("./../../root_file/test/test_pt400.root");
    TFile *DYpT650 = new TFile("./../../root_file/test/test_pt650.root");

    TH1D *Mx2_1_nT = ((TH1D *)Mx2_1->Get("hmet"));
    TH1D *Mx2_50_nT = ((TH1D *)Mx2_50->Get("hmet"));
    TH1D *Mx2_150_nT = ((TH1D *)Mx2_150->Get("hmet"));


    TH1D *DYPT50_nT = ((TH1D *)DYpT50->Get("hmet"));
    TH1D *DYPT50_sumW = ((TH1D *)DYpT50->Get("h_SumWeight"));
    TH1D *DYPT100_nT = ((TH1D *)DYpT100->Get("hmet"));
    TH1D *DYPT100_sumW = ((TH1D *)DYpT100->Get("h_SumWeight"));
    TH1D *DYPT250_nT = ((TH1D *)DYpT250->Get("hmet"));
    TH1D *DYPT250_sumW = ((TH1D *)DYpT250->Get("h_SumWeight"));
    TH1D *DYPT400_nT = ((TH1D *)DYpT400->Get("hmet"));
    TH1D *DYPT400_sumW = ((TH1D *)DYpT400->Get("h_SumWeight"));
    TH1D *DYPT650_nT = ((TH1D *)DYpT650->Get("hmet"));
    TH1D *DYPT650_sumW = ((TH1D *)DYpT650->Get("h_SumWeight"));

    double DYPT50_SW = DYPT50_sumW->GetBinContent(1);
    DYPT50_nT->Scale(PT50CS / DYPT50_SW);

    double DYPT100_SW = DYPT100_sumW->GetBinContent(1);
    DYPT100_nT->Scale(PT100CS / DYPT100_SW);

    double DYPT250_SW = DYPT250_sumW->GetBinContent(1);
    DYPT250_nT->Scale(PT250CS / DYPT250_SW);

    double DYPT400_SW = DYPT400_sumW->GetBinContent(1);
    DYPT400_nT->Scale(PT400CS / DYPT400_SW);

    double DYPT650_SW = DYPT650_sumW->GetBinContent(1);
    DYPT650_nT->Scale(PT650CS / DYPT650_SW);

    DYPT50_nT->Add(DYPT100_nT);
    DYPT50_nT->Add(DYPT250_nT);
    DYPT50_nT->Add(DYPT400_nT);
    DYPT50_nT->Add(DYPT650_nT);

    TH1F* punzi_met = new TH1F("punzi_met","", 20, 0, 800);

    //HT70_nT->Draw();
    //============
    //  Punzi
    //============
    //Mx2_1_nT->GetXaxis()->SetRangeUser(-4,4);
    //DYPT50_nT->Draw("text");

    
    double nSigEvent = Mx2_150_nT->Integral();
    double nBgEvent = DYPT50_nT->Integral();
    int nBin = Mx2_150_nT->GetNbinsX();
    cout << nBin << endl;
    cout << "nSigEvent = " << nSigEvent << endl;
    cout << "nBgEvent = " << nBgEvent << endl;
    vector<vector<float>> effs(2, vector<float>(nBin)); //2-D vector
    float Teffs[100], Teffb[100];
    vector<vector<double>> effs_t(2, vector<double>(nBin)); //with total
    vector<vector<float>> effb(2, vector<float>(nBin));     //bg
    vector<vector<double>> effb_t(2, vector<double>(nBin)); //with total
    vector <vector<double>> punziList(2, vector<double>(nBin));
    for (auto &vec : effs_t)
        vec.clear();
    for (auto &vec : effb_t)
        vec.clear();
    for (auto &vec : effs)
        vec.clear();
    for (auto &vec : effb)
        vec.clear();
    for (auto &vec : punziList)
        vec.clear();

    double event[2][2] = {0, 0, 0, 0};
    for (int i = 0; i < nBin; i++)
    {
        event[0][0] += Mx2_150_nT->GetBinContent(i + 1); //from 0 to end for sig
        event[1][1] += Mx2_150_nT->GetBinContent(nBin-i-1);//from end to 0 -upper and lower
        event[0][1] += DYPT50_nT->GetBinContent(i + 1);
        event[1][0] += DYPT50_nT->GetBinContent(nBin-i-1);
        //cout<<"bin= "<<i<<" event[1][0] = "<<event[1][0]<<endl;
        effs[0].push_back(event[0][0] / nSigEvent); //(sig/other)
        effs[1].push_back(event[1][1] / nSigEvent);
        effb[0].push_back(event[0][1] / nBgEvent);
        effb[1].push_back(event[1][0] / nBgEvent);
        //cout << " event " << event[0][1] << endl;
        //<< ": nBgEvent " << nBgEvent << ": EFFB " << effb[0] << " : " << i << endl;
        //cout << " effs " << effs[0][i] << endl;
        //cout << " effb " << effb[0][i] << endl;
        //punziList[0].push_back(punzi(event[0][0]/nSigEvent,event[0][1]));
  	  	punziList[1].push_back(punzi(event[1][1]/nSigEvent,event[1][0]));
        cout << "bin = "<<i << " punziList[1][i] = " <<punziList[1][i]<<endl;
    }
    //reverse(effs[1].begin(), effs[1].end());
    //reverse(effb[1].begin(), effb[1].end());

    reverse(punziList[1].begin(),punziList[1].end());
    for (int i = 0; i < nBin; i++)
    {

        //Teffs[i] = effs[0][i];
        //Teffb[i] = 1 - effb[0][i];
        //cout << Teffs[i] << "  " << Teffb[i] << "  " << endl;
        punzi_met->SetBinContent(i,punziList[1][i]);
    }
    float_t punz = 0 ; 
	Int_t max_bin = 0;
    //punz = punzi_Net->GetMaximum();
	//max_bin = punzi_Net->GetMaximumBin();
    //cout << "punzi_maximum = "  << punz << endl;
	//cout << "punzi_max_bin = "  << max_bin-1 << endl;
    auto c1 = new TCanvas();
    
    punzi_met->GetXaxis()->SetTitle("alphamin");
  	punzi_met->GetYaxis()->SetTitle("Punzi_significance");
  	punzi_met->GetYaxis()->SetTitleOffset(1.4);
	punzi_met->SetLineColor(kRed);
  	punzi_met->SetLineWidth(2);
  	punzi_met->Draw();
    //punzi_aphmin->SaveAs("PN-alphamin1.png");

/*
    TGraph *sigEff_vs_bkgEff = new TGraph(50, Teffs, Teffb);
    //sigEff_vs_bkgEff->SetMaximum(1.2);
    //sigEff_vs_bkgEff->Draw("ap");
    sigEff_vs_bkgEff->SetTitle("");
    sigEff_vs_bkgEff->GetXaxis()->SetTitle("Sig Efficiency");
    //sigEff_vs_bkgEff->GetXaxis()->SetLimits(0, 1.0);
    //sigEff_vs_bkgEff->GetXaxis()->SetTickSize(0.03);
    sigEff_vs_bkgEff->GetXaxis()->SetTitleOffset(1.2);
    sigEff_vs_bkgEff->GetXaxis()->SetLabelOffset(0.015);
    sigEff_vs_bkgEff->GetYaxis()->SetTitle("Bkg rejection Efficiency");
    sigEff_vs_bkgEff->GetYaxis()->SetTitleOffset(1.3);
    //sigEff_vs_bkgEff->GetYaxis()->SetNdivisions(505);
    //sigEff_vs_bkgEff->GetYaxis()->SetTickSize(0.03);
    sigEff_vs_bkgEff->GetYaxis()->SetLabelOffset(0.005);
    //sigEff_vs_bkgEff->GetHistogram()->SetMaximum(1.0); // along
    //sigEff_vs_bkgEff->GetHistogram()->SetMinimum(0.);
    //sigEff_vs_bkgEff->SetLineWidth(1508);
    sigEff_vs_bkgEff->Draw("AC*");
    //sigEff_vs_bkgEff->Draw("C");
*/
}