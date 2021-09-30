#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./lib/Cross_section.h"
using namespace std;

//define punzi_eq
double punzi(double sigeff, double bg){
	return sigeff/(1+TMath::Power(abs(bg),0.5));
} 

void punzi()
{

    TFile *Mx2_1 = new TFile("./../../root_file/Ztoee/test1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/Ztoee/test50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/Ztoee/test150.root");


    TFile *DYpT50 = new TFile("./../../root_file/Ztoee/test_pt50.root");
    TFile *DYpT100 = new TFile("./../../root_file/Ztoee/test_pt100.root");
    TFile *DYpT250 = new TFile("./../../root_file/Ztoee/test_pt250.root");
    TFile *DYpT400 = new TFile("./../../root_file/Ztoee/test_pt400.root");
    TFile *DYpT650 = new TFile("./../../root_file/Ztoee/test_pt650.root");

    TFile *DYHT70 = new TFile("./../../root_file/Ztoee/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../root_file/Ztoee/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../root_file/Ztoee/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../root_file/Ztoee/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../root_file/Ztoee/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../root_file/Ztoee/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../root_file/Ztoee/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../root_file/Ztoee/ee_ht2500.root");



    TH1D *Mx2_1_nT = ((TH1D *)Mx2_1->Get("h_aphmin"));
    TH1D *Mx2_50_nT = ((TH1D *)Mx2_50->Get("h_aphmin"));
    TH1D *Mx2_150_nT = ((TH1D *)Mx2_150->Get("h_aphmin"));


    TH1D *DYPT50_nT = ((TH1D *)DYpT50->Get("h_aphmin"));
    TH1D *DYPT50_sumW = ((TH1D *)DYpT50->Get("h_SumWeight"));
    TH1D *DYPT100_nT = ((TH1D *)DYpT100->Get("h_aphmin"));
    TH1D *DYPT100_sumW = ((TH1D *)DYpT100->Get("h_SumWeight"));
    TH1D *DYPT250_nT = ((TH1D *)DYpT250->Get("h_aphmin"));
    TH1D *DYPT250_sumW = ((TH1D *)DYpT250->Get("h_SumWeight"));
    TH1D *DYPT400_nT = ((TH1D *)DYpT400->Get("h_aphmin"));
    TH1D *DYPT400_sumW = ((TH1D *)DYpT400->Get("h_SumWeight"));
    TH1D *DYPT650_nT = ((TH1D *)DYpT650->Get("h_aphmin"));
    TH1D *DYPT650_sumW = ((TH1D *)DYpT650->Get("h_SumWeight"));

    TH1D *DYHT70_nT = ((TH1D *)DYHT70->Get("h_aphmin"));
    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("h_event"));
    TH1D *DYHT100_nT = ((TH1D *)DYHT100->Get("h_aphmin"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("h_event"));
    TH1D *DYHT200_nT = ((TH1D *)DYHT200->Get("h_aphmin"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("h_event"));
    TH1D *DYHT400_nT = ((TH1D *)DYHT400->Get("h_aphmin"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("h_event"));
    TH1D *DYHT600_nT = ((TH1D *)DYHT600->Get("h_aphmin"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("h_event"));
    TH1D *DYHT800_nT = ((TH1D *)DYHT800->Get("h_aphmin"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("h_event"));
    TH1D *DYHT1200_nT = ((TH1D *)DYHT1200->Get("h_aphmin"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("h_event"));
    TH1D *DYHT2500_nT = ((TH1D *)DYHT2500->Get("h_aphmin"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("h_event")); 

    int DYHT70_totevt = DYHT70_sumevt->GetEntries();
    int DYHT100_totevt = DYHT100_sumevt->GetEntries();
    int DYHT200_totevt = DYHT200_sumevt->GetEntries();
    int DYHT400_totevt = DYHT400_sumevt->GetEntries();
    int DYHT600_totevt = DYHT600_sumevt->GetEntries();
    int DYHT800_totevt = DYHT800_sumevt->GetEntries();
    int DYHT1200_totevt = DYHT1200_sumevt->GetEntries();
    int DYHT2500_totevt = DYHT2500_sumevt->GetEntries();  


    double DYPT50_SW = DYPT50_sumW->GetBinContent(1);
    DYPT50_nT->Scale(GlobalConstants::PT50CS / DYPT50_SW);

    double DYPT100_SW = DYPT100_sumW->GetBinContent(1);
    DYPT100_nT->Scale(GlobalConstants::PT100CS / DYPT100_SW);

    double DYPT250_SW = DYPT250_sumW->GetBinContent(1);
    DYPT250_nT->Scale(GlobalConstants::PT250CS / DYPT250_SW);

    double DYPT400_SW = DYPT400_sumW->GetBinContent(1);
    DYPT400_nT->Scale(GlobalConstants::PT400CS / DYPT400_SW);

    double DYPT650_SW = DYPT650_sumW->GetBinContent(1);
    DYPT650_nT->Scale(GlobalConstants::PT650CS / DYPT650_SW);

    DYHT70_nT->Scale(GlobalConstants::HT70CS/DYHT70_totevt);
    DYHT100_nT->Scale(GlobalConstants::HT100CS/DYHT100_totevt);    
    DYHT200_nT->Scale(GlobalConstants::HT200CS/DYHT200_totevt); 
    DYHT400_nT->Scale(GlobalConstants::HT400CS/DYHT400_totevt);
    DYHT600_nT->Scale(GlobalConstants::HT600CS/DYHT600_totevt);
    DYHT800_nT->Scale(GlobalConstants::HT800CS/DYHT800_totevt);
    DYHT1200_nT->Scale(GlobalConstants::HT1200CS/DYHT1200_totevt);
    DYHT2500_nT->Scale(GlobalConstants::HT2500CS/DYHT2500_totevt);

    DYPT50_nT->Add(DYPT100_nT);
    DYPT50_nT->Add(DYPT250_nT);
    DYPT50_nT->Add(DYPT400_nT);
    DYPT50_nT->Add(DYPT650_nT);

    DYHT70_nT->Add(DYHT100_nT);
    DYHT70_nT->Add(DYHT200_nT);
    DYHT70_nT->Add(DYHT400_nT);
    DYHT70_nT->Add(DYHT600_nT);
    DYHT70_nT->Add(DYHT800_nT);
    DYHT70_nT->Add(DYHT1200_nT);
    DYHT70_nT->Add(DYHT2500_nT);

    TH1F* punzi_met = new TH1F("punzi_met","", 24, 0, 1.2);

    //HT70_nT->Draw();
    //============
    //  Punzi
    //============
    //Mx2_1_nT->GetXaxis()->SetRangeUser(-4,4);
    //DYPT50_nT->Draw("text");

    
    double nSigEvent = Mx2_150_nT->Integral();
    double nBgEvent = DYHT70_nT->Integral();
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
        event[1][1] += Mx2_150_nT->GetBinContent(nBin-i-1);//from end to 0 -upper and lower
        event[1][0] += DYHT70_nT->GetBinContent(nBin-i-1);
        //cout<<"bin= "<<i<<" event[1][0] = "<<event[1][0]<<endl;
        effs[1].push_back(event[1][1] / nSigEvent);
        effb[1].push_back(event[1][0] / nBgEvent);
        //cout << " event " << event[0][1] << endl;
        //<< ": nBgEvent " << nBgEvent << ": EFFB " << effb[0] << " : " << i << endl;
        //cout << " effs " << effs[0][i] << endl;
        //cout << " effb " << effb[0][i] << endl;
        
  	  	punziList[1].push_back(punzi(event[1][1]/nSigEvent,event[1][0]));
        //cout << "bin = "<<nBin-i-1<< " punziList[1][i] = " <<punziList[1][i]<<endl;
    }
    for(int i = 0; i < nBin; i++)
    {
        event[0][0] += Mx2_150_nT->GetBinContent(i + 1); //from 0 to end for sig
        event[0][1] += DYHT70_nT->GetBinContent(i + 1);
        effs[0].push_back(event[0][0] / nSigEvent); //(sig/other)
        effb[0].push_back(event[0][1] / nBgEvent);
        punziList[0].push_back(punzi(event[0][0]/nSigEvent,event[0][1]));
    }
    //reverse(effs[1].begin(), effs[1].end());
    //reverse(effb[1].begin(), effb[1].end());
    reverse(punziList[1].begin(),punziList[1].end());
    
    for (int i = 0; i < nBin; i++)
    {
        //Teffs[i] = effs[0][i];
        //Teffb[i] = 1 - effb[0][i];
        //cout << Teffs[i] << "  " << Teffb[i] << "  " << endl;
        //punzi_met->SetBinContent(i,punziList[1][i]);
        punzi_met->SetBinContent(i,punziList[0][i]);
    }
    float_t punz = 0 ; 
	Int_t max_bin = 0;
    //punz = punzi_Net->GetMaximum();
	//max_bin = punzi_Net->GetMaximumBin();
    //cout << "punzi_maximum = "  << punz << endl;
	//cout << "punzi_max_bin = "  << max_bin-1 << endl;
    auto c1 = new TCanvas();
    
    punzi_met->GetXaxis()->SetTitle("aphmin");
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