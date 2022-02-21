#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../lib/Cross_section.h"
#include "./../../lib/setNCUStyle.C"
using namespace std;
void ee_3Dsig()
{
    TFile *Mx2_1 = new TFile("./../../../../root_file/Ztoee/Mx2_1.root");
    TFile *Mx2_50 = new TFile("./../../../../root_file/Ztoee/Mx2_50.root");
    TFile *Mx2_150 = new TFile("./../../../../root_file/Ztoee/Mx2_150.root");

    TFile *DYincli = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");
    TFile *DYHT70 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

    TFile *Top_TTTo2L2Nu = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
    TFile *Top_TTWJetsToLNu = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQ = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToLLNuNu = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_TTZToQQ = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_tW_antitop = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_top = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));

    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("Event_Variable/h_totevent"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("Event_Variable/h_totevent"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("Event_Variable/h_totevent"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("Event_Variable/h_totevent"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("Event_Variable/h_totevent"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("Event_Variable/h_totevent"));

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)Top_TTTo2L2Nu->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNu->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQ->Get("Event_Variable/h_totevent"));
    TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNu->Get("Event_Variable/h_totevent"));
    TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQ->Get("Event_Variable/h_totevent"));
    TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitop->Get("Event_Variable/h_totevent"));
    TH1D *tW_top_sumevt = ((TH1D *)Top_tW_top->Get("Event_Variable/h_totevent"));

    int DYHT100_totevt = DYHT100_sumevt->Integral();
    int DYHT200_totevt = DYHT200_sumevt->Integral();
    int DYHT400_totevt = DYHT400_sumevt->Integral();
    int DYHT600_totevt = DYHT600_sumevt->Integral();
    int DYHT800_totevt = DYHT800_sumevt->Integral();
    int DYHT1200_totevt = DYHT1200_sumevt->Integral();
    int DYHT2500_totevt = DYHT2500_sumevt->Integral();

    int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();
    int TTWJetsToLNu_totevt = TTWJetsToLNu_sumevt->Integral();
    int TTWJetsToQQ_totevt = TTWJetsToQQ_sumevt->Integral();
    int TTZToLLNuNu_totevt = TTZToLLNuNu_sumevt->Integral();
    int TTZToQQ_totevt = TTZToQQ_sumevt->Integral();
    int tW_antitop_totevt = tW_antitop_sumevt->Integral();
    int tW_top_totevt = tW_top_sumevt->Integral();

    int HT0_70_event = h_HT_eventCout->GetBinContent(2);
    int HT70_100_event = h_HT_eventCout->GetBinContent(3);
    int HT100_200_event = h_HT_eventCout->GetBinContent(4);
    int HT200_400_event = h_HT_eventCout->GetBinContent(5);
    int HT400_600_event = h_HT_eventCout->GetBinContent(6);
    int HT600_800_event = h_HT_eventCout->GetBinContent(7);
    int HT800_1200_event = h_HT_eventCout->GetBinContent(8);
    int HT1200_2500_event = h_HT_eventCout->GetBinContent(9);
    int HT2500_Inf_event = h_HT_eventCout->GetBinContent(10);

    //---------------------
    // Define HTWeight
    //---------------------
    float HT0Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT0CS) / (HT0_70_event)) * 1000;
    float HT70Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT70CS) / (HT70_100_event)) * 1000;
    float HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000;
    float HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000;
    float HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000;
    float HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000;
    float HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000;
    float HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000;
    float HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000;

    float ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000;
    float ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000;
    float TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTTo2L2Nu / (TTTo2L2Nu_totevt)) * 1000;
    float TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000;
    float TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000;
    float TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000;
    float TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000;

    TH1D *Mx2_1_3Dsig = ((TH1D *)Mx2_1->Get("Track_Variable/Chi3Dlog"));
    TH1D *Mx2_1_3Dsigpaper = ((TH1D *)Mx2_1->Get("Track_Variable/Chi3DPaperlog"));
    TH1D *Mx2_50_3Dsig = ((TH1D *)Mx2_50->Get("Track_Variable/Chi3Dlog"));
    TH1D *Mx2_50_3Dsigpaper = ((TH1D *)Mx2_50->Get("Track_Variable/Chi3DPaperlog"));
    TH1D *Mx2_150_3Dsig = ((TH1D *)Mx2_150->Get("Track_Variable/Chi3Dlog"));
    TH1D *Mx2_150_3Dsigpaper = ((TH1D *)Mx2_150->Get("Track_Variable/Chi3DPaperlog"));

    TH1D *DYHT70_3Dsig = ((TH1D *)DYHT70->Get("Track_Variable/Chi3Dlog"));
    TH1D *DYHT70_3Dsigpaper = ((TH1D *)DYHT70->Get("Track_Variable/Chi3DPaperlog"));
    TH1D *DYHT100_3Dsig = ((TH1D *)DYHT100->Get("Track_Variable/Chi3Dlog"));
    TH1D *DYHT100_3Dsigpaper = ((TH1D *)DYHT100->Get("Track_Variable/Chi3DPaperlog"));
    TH1D *DYHT200_3Dsig = ((TH1D *)DYHT200->Get("Track_Variable/Chi3Dlog"));
    TH1D *DYHT200_3Dsigpaper = ((TH1D *)DYHT200->Get("Track_Variable/Chi3DPaperlog"));
    TH1D *DYHT400_3Dsig = ((TH1D *)DYHT400->Get("Track_Variable/Chi3Dlog"));
    TH1D *DYHT400_3Dsigpaper = ((TH1D *)DYHT400->Get("Track_Variable/Chi3DPaperlog"));
    TH1D *DYHT600_3Dsig = ((TH1D *)DYHT600->Get("Track_Variable/Chi3Dlog"));
    TH1D *DYHT600_3Dsigpaper = ((TH1D *)DYHT600->Get("Track_Variable/Chi3DPaperlog"));
    TH1D *DYHT800_3Dsig = ((TH1D *)DYHT800->Get("Track_Variable/Chi3Dlog"));
    TH1D *DYHT800_3Dsigpaper = ((TH1D *)DYHT800->Get("Track_Variable/Chi3DPaperlog"));
    TH1D *DYHT1200_3Dsig = ((TH1D *)DYHT1200->Get("Track_Variable/Chi3Dlog"));
    TH1D *DYHT1200_3Dsigpaper = ((TH1D *)DYHT1200->Get("Track_Variable/Chi3DPaperlog"));
    TH1D *DYHT2500_3Dsig = ((TH1D *)DYHT2500->Get("Track_Variable/Chi3Dlog"));
    TH1D *DYHT2500_3Dsigpaper = ((TH1D *)DYHT2500->Get("Track_Variable/Chi3DPaperlog"));

    TH1D *TTTo2L2Nu_3Dsig = ((TH1D *)Top_TTTo2L2Nu->Get("Track_Variable/Chi3Dlog"));
    TH1D *TTTo2L2Nu_3Dsigpaper = ((TH1D *)Top_TTTo2L2Nu->Get("Track_Variable/Chi3DPaperlog"));

    DYHT70_3Dsig->Scale(HT70Weight);
    DYHT70_3Dsigpaper->Scale(HT70Weight);
    DYHT100_3Dsig->Scale(HT100Weight);
    DYHT100_3Dsigpaper->Scale(HT100Weight);
    DYHT200_3Dsig->Scale(HT200Weight);
    DYHT200_3Dsigpaper->Scale(HT200Weight);
    DYHT400_3Dsig->Scale(HT400Weight);
    DYHT400_3Dsigpaper->Scale(HT400Weight);
    DYHT600_3Dsig->Scale(HT600Weight);
    DYHT600_3Dsigpaper->Scale(HT600Weight);
    DYHT800_3Dsig->Scale(HT800Weight);
    DYHT800_3Dsigpaper->Scale(HT800Weight);
    DYHT1200_3Dsig->Scale(HT1200Weight);
    DYHT1200_3Dsigpaper->Scale(HT1200Weight);
    DYHT2500_3Dsig->Scale(HT2500Weight);
    DYHT2500_3Dsigpaper->Scale(HT2500Weight);

    TTTo2L2Nu_3Dsig->Scale(TTTo2L2NuWeight);
    TTTo2L2Nu_3Dsigpaper->Scale(TTTo2L2NuWeight);

    DYHT70_3Dsig->Add(DYHT100_3Dsig);
    DYHT70_3Dsig->Add(DYHT200_3Dsig);
    DYHT70_3Dsig->Add(DYHT400_3Dsig);
    DYHT70_3Dsig->Add(DYHT600_3Dsig);
    DYHT70_3Dsig->Add(DYHT1200_3Dsig);
    DYHT70_3Dsig->Add(DYHT2500_3Dsig);

    DYHT70_3Dsigpaper->Add(DYHT100_3Dsigpaper);
    DYHT70_3Dsigpaper->Add(DYHT200_3Dsigpaper);
    DYHT70_3Dsigpaper->Add(DYHT400_3Dsigpaper);
    DYHT70_3Dsigpaper->Add(DYHT600_3Dsigpaper);
    DYHT70_3Dsigpaper->Add(DYHT800_3Dsigpaper);
    DYHT70_3Dsigpaper->Add(DYHT1200_3Dsigpaper);
    DYHT70_3Dsigpaper->Add(DYHT2500_3Dsigpaper);

    DYHT70_3Dsig->SetLineWidth(2);
    TTTo2L2Nu_3Dsig->SetLineWidth(2);
    Mx2_1_3Dsig->SetLineWidth(2);
    Mx2_50_3Dsig->SetLineWidth(2);
    Mx2_150_3Dsig->SetLineWidth(2);

    DYHT70_3Dsigpaper->SetLineWidth(2);
    TTTo2L2Nu_3Dsigpaper->SetLineWidth(2);
    Mx2_1_3Dsigpaper->SetLineWidth(2);
    Mx2_50_3Dsigpaper->SetLineWidth(2);
    Mx2_150_3Dsigpaper->SetLineWidth(2);

    Mx2_1_3Dsig->SetLineColor(kBlack);
    Mx2_1_3Dsigpaper->SetLineColor(kBlack);
    Mx2_50_3Dsig->SetLineColor(kBlue);
    Mx2_50_3Dsigpaper->SetLineColor(kBlue);
    Mx2_150_3Dsig->SetLineColor(kGreen - 5);
    Mx2_150_3Dsigpaper->SetLineColor(kGreen - 5);

    DYHT70_3Dsig->SetLineColor(kMagenta);
    DYHT70_3Dsigpaper->SetLineColor(kMagenta);

    TTTo2L2Nu_3Dsig->SetLineColor(kRed);
    TTTo2L2Nu_3Dsigpaper->SetLineColor(kRed);

    DYHT70_3Dsig->SetTitle("3Dsig");
    DYHT70_3Dsig->GetYaxis()->SetTitle("N Tracks/Normalized");
    DYHT70_3Dsig->GetXaxis()->SetTitle("log_{10}(3DIP_{sig})");

    DYHT70_3Dsigpaper->SetTitle("X");
    DYHT70_3Dsigpaper->GetYaxis()->SetTitle("N Tracks/Normalized");
    DYHT70_3Dsigpaper->GetXaxis()->SetTitle("log_{10}(X)");

    /*
    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(2, 1);
    c1->cd(1);
    DYHT70_3Dsig->DrawNormalized("hist");
    TTTo2L2Nu_3Dsig->DrawNormalized("hist&&same");
    Mx2_1_3Dsig->DrawNormalized("hist&&same");
    Mx2_50_3Dsig->DrawNormalized("hist&&same");
    Mx2_150_3Dsig->DrawNormalized("hist&&same");

    TLegend *i2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    i2->SetBorderSize(0);
    i2->SetTextSize(0.03);
    i2->AddEntry(Mx2_1_3Dsig, "ctau=1mm m_{x^{2}}=1", "l");
    i2->AddEntry(Mx2_50_3Dsig, "ctau=10mm m_{x^{2}}=50", "l");
    i2->AddEntry(Mx2_150_3Dsig, "ctau=1mm m_{x^{2}}=150", "l");
    i2->AddEntry(TTTo2L2Nu_3Dsig, "Top", "l");
    i2->AddEntry(DYHT70_3Dsig, "Drell-Yan", "l");
    i2->Draw();

    gStyle->SetOptStat(0);

    c1->cd(2);

    DYHT70_3Dsigpaper->DrawNormalized("hist");
    TTTo2L2Nu_3Dsigpaper->DrawNormalized("hist&&same");
    Mx2_1_3Dsigpaper->DrawNormalized("hist&&same");
    Mx2_50_3Dsigpaper->DrawNormalized("hist&&same");
    Mx2_150_3Dsigpaper->DrawNormalized("hist&&same");


    gStyle->SetOptStat(0);
    */

    float TotSigEvent_Mx1 = Mx2_1_3Dsig->Integral();
    float TotSigEvent_Mx50 = Mx2_50_3Dsig->Integral();
    float TotSigEvent_Mx150 = Mx2_150_3Dsig->Integral();
    float TotBgEvent_Mx1 = DYHT70_3Dsig->Integral();
    int nBin = Mx2_1_3Dsig->GetNbinsX();
    int half = nBin / 2;

    float nSigEvent_Mx1 = 0;
    float nSigEvent_Mx50 = 0;
    float nSigEvent_Mx150 = 0;
    float nBgEvent_Mx1 = 0;

    float Teffs_Mx1[half], Teffb_Mx1[half];
    float Teffs_Mx50[half];
    float Teffs_Mx150[half];
    vector<float> effs_Mx1;
    vector<float> effb_Mx1;
    vector<float> effs_Mx50;
    vector<float> effs_Mx150;
    effs_Mx1.clear();
    effb_Mx1.clear();
    effs_Mx50.clear();
    effs_Mx150.clear();

    for (int i = 0; i < half; i++)
    {
        nSigEvent_Mx1 += Mx2_1_3Dsig->GetBinContent(half + i + 1); // from 0 to end for sig
        nSigEvent_Mx1 += Mx2_1_3Dsig->GetBinContent(half - i);     // from 0 to end for sig
        // nSigEvent_Mx50 += Mx2_50_3Dsig->GetBinContent(i + 1);      // from 0 to end for sig
        // nSigEvent_Mx50 += Mx2_50_3Dsig->GetBinContent(nBin - i);   // from 0 to end for sig
        nSigEvent_Mx50 += Mx2_50_3Dsig->GetBinContent(half + i + 1); // from 0 to end for sig
        nSigEvent_Mx50 += Mx2_50_3Dsig->GetBinContent(half - i);
        // nSigEvent_Mx150 += Mx2_150_3Dsig->GetBinContent(i + 1);    // from 0 to end for sig
        // nSigEvent_Mx150 += Mx2_150_3Dsig->GetBinContent(nBin - i); // from 0 to end for sig
        nSigEvent_Mx150 += Mx2_150_3Dsig->GetBinContent(half + i + 1); // from 0 to end for sig
        nSigEvent_Mx150 += Mx2_150_3Dsig->GetBinContent(half - i);
        nBgEvent_Mx1 += DYHT70_3Dsig->GetBinContent(half + i + 1);
        nBgEvent_Mx1 += DYHT70_3Dsig->GetBinContent(half - i);
        effs_Mx1.push_back(nSigEvent_Mx1 / TotSigEvent_Mx1);
        effs_Mx50.push_back(nSigEvent_Mx50 / TotSigEvent_Mx50);
        effs_Mx150.push_back(nSigEvent_Mx150 / TotSigEvent_Mx150);
        effb_Mx1.push_back(nBgEvent_Mx1 / TotBgEvent_Mx1);
        cout << "i = " << i << endl;
        cout << " effs_Mx1 " << nSigEvent_Mx1 / TotSigEvent_Mx1 << endl;
        cout << " effb_Mx1 " << nBgEvent_Mx1 / TotBgEvent_Mx1 << endl;
    }

    float TotSigEvent_Mx1paper = Mx2_1_3Dsigpaper->Integral();
    float TotSigEvent_Mx50paper = Mx2_50_3Dsigpaper->Integral();
    float TotSigEvent_Mx150paper = Mx2_150_3Dsigpaper->Integral();
    float TotBgEvent_Mx1paper = DYHT70_3Dsigpaper->Integral();

    float nSigEvent_Mx1paper = 0;
    float nSigEvent_Mx50paper = 0;
    float nSigEvent_Mx150paper = 0;
    float nBgEvent_Mx1paper = 0;

    float Teffs_Mx1paper[half], Teffb_Mx1paper[half];
    float Teffs_Mx50paper[half];
    float Teffs_Mx150paper[half];
    vector<float> effs_Mx1paper;
    vector<float> effb_Mx1paper;
    vector<float> effs_Mx50paper;
    vector<float> effs_Mx150paper;
    effs_Mx1paper.clear();
    effb_Mx1paper.clear();
    effs_Mx50paper.clear();
    effs_Mx150paper.clear();
    for (int i = 0; i < half; i++)
    {
        nSigEvent_Mx1paper += Mx2_1_3Dsigpaper->GetBinContent(half + i + 1); // from 0 to end for sig
        nSigEvent_Mx1paper += Mx2_1_3Dsigpaper->GetBinContent(half - i); // from 0 to end for sig
        nSigEvent_Mx50paper += Mx2_50_3Dsigpaper->GetBinContent(half + i + 1); // from 0 to end for sig
        nSigEvent_Mx50paper += Mx2_50_3Dsigpaper->GetBinContent(half - i);   // from 0 to end for sig
        nSigEvent_Mx150paper += Mx2_150_3Dsigpaper->GetBinContent(half + i + 1); // from 0 to end for sig
        nSigEvent_Mx150paper += Mx2_150_3Dsigpaper->GetBinContent(half - i); // from 0 to end for sig
        nBgEvent_Mx1paper += DYHT70_3Dsigpaper->GetBinContent(half + i + 1);
        nBgEvent_Mx1paper += DYHT70_3Dsigpaper->GetBinContent(half - i);

        effs_Mx1paper.push_back(nSigEvent_Mx1paper / TotSigEvent_Mx1paper);
        effs_Mx50paper.push_back(nSigEvent_Mx50paper / TotSigEvent_Mx50paper);
        effs_Mx150paper.push_back(nSigEvent_Mx150paper / TotSigEvent_Mx150paper);
        effb_Mx1paper.push_back(nBgEvent_Mx1paper / TotBgEvent_Mx1paper);
    }

    for (int i = 0; i < half; i++)
    {
        Teffs_Mx1[i] = effs_Mx1[i];
        Teffs_Mx50[i] = effs_Mx50[i];
        Teffs_Mx150[i] = effs_Mx150[i];
        Teffb_Mx1[i] = 1 - effb_Mx1[i];
        Teffs_Mx1paper[i] = effs_Mx1paper[i];
        Teffs_Mx50paper[i] = effs_Mx50paper[i];
        Teffs_Mx150paper[i] = effs_Mx150paper[i];
        Teffb_Mx1paper[i] = 1 - effb_Mx1paper[i];
    }

    TGraph *ROC_Mx1 = new TGraph(half, Teffs_Mx1, Teffb_Mx1);
    TGraph *ROC_Mx50 = new TGraph(half, Teffs_Mx50, Teffb_Mx1);
    TGraph *ROC_Mx150 = new TGraph(half, Teffs_Mx150, Teffb_Mx1);

    TGraph *ROC_Mx1paper = new TGraph(half, Teffs_Mx1paper, Teffb_Mx1paper);
    TGraph *ROC_Mx50paper = new TGraph(half, Teffs_Mx50paper, Teffb_Mx1paper);
    TGraph *ROC_Mx150paper = new TGraph(half, Teffs_Mx150paper, Teffb_Mx1paper);

    TH2F *ROC_total = new TH2F("ROC_total", "", 100, 0, 1, 100, 0, 1);
    ROC_total->SetXTitle("Sig Efficiency");
    ROC_total->SetYTitle("Bkg rejection Efficiency");

    ROC_Mx1->SetLineWidth(2);
    ROC_Mx50->SetLineWidth(2);
    ROC_Mx150->SetLineWidth(2);

    ROC_Mx1paper->SetLineWidth(2);
    ROC_Mx50paper->SetLineWidth(2);
    ROC_Mx150paper->SetLineWidth(2);

    ROC_Mx1->SetLineColor(kRed);
    ROC_Mx50->SetLineColor(kBlue);
    ROC_Mx150->SetLineColor(kGreen);

    ROC_Mx1paper->SetLineColor(kMagenta);
    ROC_Mx50paper->SetLineColor(kYellow + 3);
    ROC_Mx150paper->SetLineColor(kCyan - 7);

    ROC_Mx1->GetXaxis()->SetTitle("Sig Efficiency");
    // sigEff_vs_bkgEff->GetXaxis()->SetLimits(0, 1.0);
    // sigEff_vs_bkgEff->GetXaxis()->SetTickSize(0.03);
    ROC_Mx1->GetXaxis()->SetTitleOffset(1.2);
    ROC_Mx1->GetXaxis()->SetLabelOffset(0.015);
    ROC_Mx1->GetYaxis()->SetTitle("Bkg rejection Efficiency");
    ROC_total->Draw();
    ROC_Mx1->Draw("L* same");
    ROC_Mx50->Draw("L* same");
    ROC_Mx150->Draw("L*");
    ROC_Mx1paper->Draw("L* same");
    ROC_Mx50paper->Draw("L* same");
    ROC_Mx150paper->Draw("L* same");

    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(ROC_Mx1, "ctau=1mm m_{x^{2}}=1 (3DSig)", "l");
    l1->AddEntry(ROC_Mx50, "ctau=10mm m_{x^{2}}=50 (3DSig)", "l");
    l1->AddEntry(ROC_Mx150, "ctau=1mm m_{x^{2}}=150 (3DSig)", "l");
    l1->AddEntry(ROC_Mx1paper, "ctau=1mm m_{x^{2}}=1 (X)", "l");
    l1->AddEntry(ROC_Mx50paper, "ctau=10mm m_{x^{2}}=50 (X)", "l");
    l1->AddEntry(ROC_Mx150paper, "ctau=1mm m_{x^{2}}=150 (X)", "l");
    l1->Draw();

    gStyle->SetOptStat(0);
}
