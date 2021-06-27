#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
using namespace std;
void ROC()
{
    float HT70CS = 175.3;
    float HT100CS = 147.4;
    float HT200CS = 41.04;
    float HT400CS = 5.674;
    float HT600CS = 1.358;
    float HT800CS = 0.6229;
    float HT1200CS = 0.1512;
    float HT2500CS = 0.003659;
    float PT50CS = 344.3;
    float PT100CS = 80.64;
    float PT250CS = 2.955;
    float PT400CS = 0.3807;
    float PT650CS = 0.03711;

    TFile *Mx2_1 = new TFile("tmpMx2_1.root");
    TFile *Mx2_50 = new TFile("tmpMx2_50.root");
    TFile *Mx2_150 = new TFile("tmpMx2_150.root");
    TFile *DYHT70 = new TFile("tmpHT70_100.root");
    TFile *DYHT100 = new TFile("tmpHT100_200.root");
    TFile *DYHT200 = new TFile("tmpHT200_400.root");
    TFile *DYHT400 = new TFile("tmpHT400_600.root");
    TFile *DYHT600 = new TFile("tmpHT600_800.root");
    TFile *DYHT800 = new TFile("tmpHT800_1200.root");
    TFile *DYHT1200 = new TFile("tmpHT1200_2500.root");
    TFile *DYHT2500 = new TFile("tmpHT2500_Inf.root");

    TFile *DYpT50 = new TFile("tmppt50_100.root");
    TFile *DYpT100 = new TFile("tmppt100_250.root");
    TFile *DYpT250 = new TFile("tmppt250_400.root");
    TFile *DYpT400 = new TFile("tmppt400_650.root");
    TFile *DYpT650 = new TFile("tmppt650_Inf.root");

    TH1D *Mx2_1_nT = ((TH1D *)Mx2_1->Get("h_aph1"));
    TH1D *Mx2_50_nT = ((TH1D *)Mx2_50->Get("h_aph1"));
    TH1D *Mx2_150_nT = ((TH1D *)Mx2_150->Get("h_aph1"));

    TH1D *HT70_nT = ((TH1D *)DYHT70->Get("h_aph1"));
    TH1D *HT70_evt = ((TH1D *)DYHT70->Get("h_event"));

    TH1D *HT100_nT = ((TH1D *)DYHT100->Get("h_aph1"));
    TH1D *HT100_evt = ((TH1D *)DYHT100->Get("h_event"));

    TH1D *HT200_nT = ((TH1D *)DYHT200->Get("h_aph1"));
    TH1D *HT200_evt = ((TH1D *)DYHT200->Get("h_event"));
    TH1D *HT400_nT = ((TH1D *)DYHT400->Get("h_aph1"));
    TH1D *HT400_evt = ((TH1D *)DYHT400->Get("h_event"));
    TH1D *HT600_nT = ((TH1D *)DYHT600->Get("h_aph1"));
    TH1D *HT600_evt = ((TH1D *)DYHT600->Get("h_event"));
    TH1D *HT800_nT = ((TH1D *)DYHT800->Get("h_aph1"));
    TH1D *HT800_evt = ((TH1D *)DYHT800->Get("h_event"));
    TH1D *HT1200_nT = ((TH1D *)DYHT1200->Get("h_aph1"));
    TH1D *HT1200_evt = ((TH1D *)DYHT1200->Get("h_event"));
    TH1D *HT2500_nT = ((TH1D *)DYHT2500->Get("h_aph1"));
    TH1D *HT2500_evt = ((TH1D *)DYHT2500->Get("h_event"));

    TH1D *DYPT50_nT = ((TH1D *)DYpT50->Get("h_aph1"));
    TH1D *DYPT50_sumW = ((TH1D *)DYpT50->Get("h_SumWeight"));
    TH1D *DYPT100_nT = ((TH1D *)DYpT100->Get("h_aph1"));
    TH1D *DYPT100_sumW = ((TH1D *)DYpT100->Get("h_SumWeight"));
    TH1D *DYPT250_nT = ((TH1D *)DYpT250->Get("h_aph1"));
    TH1D *DYPT250_sumW = ((TH1D *)DYpT250->Get("h_SumWeight"));
    TH1D *DYPT400_nT = ((TH1D *)DYpT400->Get("h_aph1"));
    TH1D *DYPT400_sumW = ((TH1D *)DYpT400->Get("h_SumWeight"));
    TH1D *DYPT650_nT = ((TH1D *)DYpT650->Get("h_aph1"));
    TH1D *DYPT650_sumW = ((TH1D *)DYpT650->Get("h_SumWeight"));

    double HT70_event = HT70_evt->GetEntries();
    HT70_nT->Scale(HT70CS / HT70_event);

    double HT100_event = HT100_evt->GetEntries();
    HT100_nT->Scale(HT100CS / HT100_event);

    double HT200_event = HT200_evt->GetEntries();
    HT200_nT->Scale(HT200CS / HT200_event);

    double HT400_event = HT400_evt->GetEntries();
    HT400_nT->Scale(HT400CS / HT400_event);

    double HT600_event = HT600_evt->GetEntries();
    HT600_nT->Scale(HT600CS / HT600_event);

    double HT800_event = HT800_evt->GetEntries();
    HT800_nT->Scale(HT800CS / HT800_event);

    double HT1200_event = HT1200_evt->GetEntries();
    HT1200_nT->Scale(HT1200CS / HT1200_event);

    double HT2500_event = HT2500_evt->GetEntries();
    HT2500_nT->Scale(HT2500CS / HT2500_event);

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

    HT70_nT->Add(HT100_nT);
    HT70_nT->Add(HT200_nT);
    HT70_nT->Add(HT400_nT);
    HT70_nT->Add(HT600_nT);
    HT70_nT->Add(HT800_nT);
    HT70_nT->Add(HT1200_nT);
    HT70_nT->Add(HT2500_nT);

    //HT70_nT->Draw();
    //============
    //  ROC
    //============
    double nSigEvent = Mx2_150_nT->Integral();
    double nBgEvent = HT70_nT->Integral();
    int nBin = Mx2_150_nT->GetNbinsX();
    cout << nBin << endl;
    cout << "nSigEvent = " << nSigEvent << endl;
    cout << "nBgEvent = " << nBgEvent << endl;
    vector<vector<float>> effs(2, vector<float>(nBin)); //2-D vector
    float Teffs[100], Teffb[100];
    vector<vector<double>> effs_t(2, vector<double>(nBin)); //with total
    vector<vector<float>> effb(2, vector<float>(nBin));     //bg
    vector<vector<double>> effb_t(2, vector<double>(nBin)); //with total
    for (auto &vec : effs_t)
        vec.clear();
    for (auto &vec : effb_t)
        vec.clear();
    for (auto &vec : effs)
        vec.clear();
    for (auto &vec : effb)
        vec.clear();
    double event[2][2] = {0, 0, 0, 0};
    for (int i = 0; i < nBin; i++)
    {
        event[0][0] += Mx2_150_nT->GetBinContent(i + 1); //from 0 to end for sig
        event[0][1] += HT70_nT->GetBinContent(i + 1);
        effs[0].push_back(event[0][0] / nSigEvent); //(sig/other)
        //effs[1].push_back(event[1][1] / nSigEvent);
        effb[0].push_back(event[0][1] / nBgEvent);
        //effb[1].push_back(event[1][0] / nBgEvent);
        //cout << " event " << event[0][1] << endl;
        //<< ": nBgEvent " << nBgEvent << ": EFFB " << effb[0] << " : " << i << endl;
        cout << " effs " << effs[0][i] << endl;
        cout << " effb " << effb[0][i] << endl;
    }
    //reverse(effs[1].begin(), effs[1].end());
    //reverse(effb[1].begin(), effb[1].end());

    for (int i = 0; i < nBin; i++)
    {

        Teffs[i] = effs[0][i];
        Teffb[i] = 1 - effb[0][i];
        cout << Teffs[i] << "  " << Teffb[i] << "  " << endl;
    }
    auto c1 = new TCanvas();
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
}