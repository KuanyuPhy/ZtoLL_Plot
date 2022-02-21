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
void ee_Top_alpha_ROC()
{

    TFile *Mx2_1 = new TFile("./../../../../root_file/Ztoee/Mx2_1.root");
    TFile *Mx2_50 = new TFile("./../../../../root_file/Ztoee/Mx2_50.root");
    TFile *Mx2_150 = new TFile("./../../../../root_file/Ztoee/Mx2_150.root");

    TFile *DY = new TFile("./../../../../root_file/BgEstimation/ee_HT_ROC.root");

    TH1D *DY_alpha = ((TH1D *)DY->Get("DY_alpha"));

    TFile *Top_TTTo2L2Nu = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
    TFile *Top_TTWJetsToLNu = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQ = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToLLNuNu = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_TTZToQQ = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_tW_antitop = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_top = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)Top_TTTo2L2Nu->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNu->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQ->Get("Event_Variable/h_totevent"));
    TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNu->Get("Event_Variable/h_totevent"));
    TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQ->Get("Event_Variable/h_totevent"));
    TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitop->Get("Event_Variable/h_totevent"));
    TH1D *tW_top_sumevt = ((TH1D *)Top_tW_top->Get("Event_Variable/h_totevent"));

    int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();
    int TTWJetsToLNu_totevt = TTWJetsToLNu_sumevt->Integral();
    int TTWJetsToQQ_totevt = TTWJetsToQQ_sumevt->Integral();
    int TTZToLLNuNu_totevt = TTZToLLNuNu_sumevt->Integral();
    int TTZToQQ_totevt = TTZToQQ_sumevt->Integral();
    int tW_antitop_totevt = tW_antitop_sumevt->Integral();
    int tW_top_totevt = tW_top_sumevt->Integral();

    // alpha
    TH1F *h_tW_top_alpha = new TH1F("h_tW_top_alpha", "", 24, 0, 1.2);
    h_tW_top_alpha->SetYTitle("N Jets");
    h_tW_top_alpha->Sumw2();

    TH1F *h_tW_antitop_alpha = new TH1F("h_tW_antitop_alpha", "", 24, 0, 1.2);
    h_tW_antitop_alpha->SetYTitle("N Jets");
    h_tW_antitop_alpha->Sumw2();

    TH1F *h_TTTo2L2Nu_alpha = new TH1F("h_TTTo2L2Nu_alpha", "", 24, 0, 1.2);
    h_TTTo2L2Nu_alpha->SetYTitle("N Jets");
    h_TTTo2L2Nu_alpha->Sumw2();

    TH1F *h_TTWJetsToLNu_alpha = new TH1F("h_TTWJetsToLNu_alpha", "", 24, 0, 1.2);
    h_TTWJetsToLNu_alpha->SetYTitle("N Jets");
    h_TTWJetsToLNu_alpha->Sumw2();

    TH1F *h_TWJetsToQQ_alpha = new TH1F("h_TWJetsToQQ_alpha", "", 24, 0, 1.2);
    h_TWJetsToQQ_alpha->SetYTitle("N Jets");
    h_TWJetsToQQ_alpha->Sumw2();

    TH1F *h_TTZToLLNuNu_alpha = new TH1F("h_TTZToLLNuNu_alpha", "", 24, 0, 1.2);
    h_TTZToLLNuNu_alpha->SetYTitle("N Jets");
    h_TTZToLLNuNu_alpha->Sumw2();

    TH1F *h_TTZToQQ_alpha = new TH1F("h_TTZToQQ_alpha", "", 24, 0, 1.2);
    h_TTZToQQ_alpha->SetYTitle("N Jets");
    h_TTZToQQ_alpha->Sumw2();

    TH1F *h_Mx2_1_alpha = new TH1F("h_Mx2_1_alpha", "", 24, 0, 1.2);
    h_Mx2_1_alpha->SetYTitle("N Jets");
    h_Mx2_1_alpha->Sumw2();

    TH1F *h_Mx2_50_alpha = new TH1F("h_Mx2_50_alpha", "", 24, 0, 1.2);
    h_Mx2_50_alpha->SetYTitle("N Jets");
    h_Mx2_50_alpha->Sumw2();

    TH1F *h_Mx2_150_alpha = new TH1F("h_Mx2_150_alpha", "", 24, 0, 1.2);
    h_Mx2_150_alpha->SetYTitle("N Jets");
    h_Mx2_150_alpha->Sumw2();

    Int_t f_tW_top_weight, f_tW_antitop_weight, f_TTTo2L2Nu_weight, f_TTWJetsToLNu_weight, f_TTWJetsToQQ_weight,
        f_TTZToLLNuNu_weight, f_TTZToQQ_weight;

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;
    Int_t I_Mx1_nThinJets, I_Mx50_nThinJets, I_Mx150_nThinJets;

    vector<float> *v_Mx2_1_alpha = new vector<float>();
    vector<float> *v_Mx2_50_alpha = new vector<float>();
    vector<float> *v_Mx2_150_alpha = new vector<float>();

    v_Mx2_1_alpha->clear();
    v_Mx2_50_alpha->clear();
    v_Mx2_150_alpha->clear();

    vector<float> *v_tW_top_alpha = new vector<float>();
    vector<float> *v_tW_antitop_alpha = new vector<float>();
    vector<float> *v_TTTo2L2Nu_alpha = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha = new vector<float>();
    vector<float> *v_TWJetsToQQ_alpha = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha = new vector<float>();
    vector<float> *v_TTZToQQ_alpha = new vector<float>();

    v_tW_top_alpha->clear();
    v_tW_antitop_alpha->clear();
    v_TTTo2L2Nu_alpha->clear();
    v_TTWJetsToLNu_alpha->clear();
    v_TWJetsToQQ_alpha->clear();
    v_TTZToLLNuNu_alpha->clear();
    v_TTZToQQ_alpha->clear();
    //---------------------
    // Define the HTWeight
    //---------------------
    float ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000;
    float ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000;
    float TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTTo2L2Nu / (TTTo2L2Nu_totevt)) * 1000;
    float TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000;
    float TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000;
    float TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000;
    float TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000;

    //-------------
    //   ROC
    //-------------
    TTree *T_event;
    Top_tW_top->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &f_tW_top_weight);
    T_event->SetBranchAddress("v_fakealpha", &v_tW_top_alpha);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        for (auto i : *v_tW_top_alpha)
        {
            h_tW_top_alpha->Fill((*v_tW_top_alpha)[i], f_tW_top_weight * ST_tW_topWeight);
        }
    }
    TTree *T_event1;
    Top_tW_antitop->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("I_weight", &f_tW_antitop_weight);
    T_event1->SetBranchAddress("v_fakealpha", &v_tW_antitop_alpha);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        for (auto i : *v_tW_antitop_alpha)
        {
            h_tW_antitop_alpha->Fill((*v_tW_antitop_alpha)[i],f_tW_antitop_weight * ST_tW_antitopWeight);
        }
    }

    TTree *T_event2;
    Top_TTTo2L2Nu->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("I_weight", &f_TTTo2L2Nu_weight);
    T_event2->SetBranchAddress("v_fakealpha", &v_TTTo2L2Nu_alpha);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        for (auto i : *v_TTTo2L2Nu_alpha)
        {
            h_TTTo2L2Nu_alpha->Fill((*v_TTTo2L2Nu_alpha)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        }
    }

    TTree *T_event3;
    Top_TTWJetsToLNu->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("I_weight", &f_TTWJetsToLNu_weight);
    T_event3->SetBranchAddress("v_fakealpha", &v_TTWJetsToLNu_alpha);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        for (auto i : *v_TTWJetsToLNu_alpha)
        {
            h_TTWJetsToLNu_alpha->Fill((*v_TTWJetsToLNu_alpha)[i],f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        }
    }
    TTree *T_event4;
    Top_TTWJetsToQQ->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("I_weight", &f_TTWJetsToQQ_weight);
    T_event4->SetBranchAddress("v_fakealpha", &v_TWJetsToQQ_alpha);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        for (auto i : *v_TWJetsToQQ_alpha)
        {
            h_TWJetsToQQ_alpha->Fill((*v_TWJetsToQQ_alpha)[i],f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        }
    }

    TTree *T_event5;
    Top_TTZToLLNuNu->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("I_weight", &f_TTZToLLNuNu_weight);
    T_event5->SetBranchAddress("v_fakealpha", &v_TTZToLLNuNu_alpha);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        for (auto i : *v_TTZToLLNuNu_alpha)
        {
            h_TTZToLLNuNu_alpha->Fill((*v_TTZToLLNuNu_alpha)[i],f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        }
    }
    TTree *T_event6;
    Top_TTZToQQ->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("I_weight", &f_TTZToQQ_weight);
    T_event6->SetBranchAddress("v_fakealpha", &v_TTZToQQ_alpha);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        for (auto i : *v_TTZToQQ_alpha)
        {
            h_TTZToQQ_alpha->Fill((*v_TTZToQQ_alpha)[i],f_TTZToQQ_weight * TTZToQQWeight);
        }
    }
    TTree *Mx1_tree;
    Mx2_1->GetObject("T_event", Mx1_tree);
    Mx1_tree->SetBranchAddress("I_weight", &I_Mx1_weight);
    Mx1_tree->SetBranchAddress("I_nThinJets", &I_Mx1_nThinJets);
    Mx1_tree->SetBranchAddress("v_fakealpha", &v_Mx2_1_alpha);
    for (int evt = 0; evt < Mx1_tree->GetEntries(); evt++)
    {
        Mx1_tree->GetEntry(evt);
        for (auto i : *v_Mx2_1_alpha)
        {
            if (i > 1)
            {
                cout << "Mx2_1 " << endl;
                cout << "bug" << endl;
                cout << "i = " << i << endl;
            }
            h_Mx2_1_alpha->Fill(i, I_Mx1_weight);
        }
    }

    TTree *Mx50_tree;
    Mx2_50->GetObject("T_event", Mx50_tree);
    Mx50_tree->SetBranchAddress("I_weight", &I_Mx50_weight);
    Mx50_tree->SetBranchAddress("I_nThinJets", &I_Mx50_nThinJets);
    Mx50_tree->SetBranchAddress("v_fakealpha", &v_Mx2_50_alpha);
    for (int evt = 0; evt < Mx50_tree->GetEntries(); evt++)
    {
        Mx50_tree->GetEntry(evt);
        for (auto i : *v_Mx2_50_alpha)
        {
            if (i > 1)
            {
                cout << "Mx2_50 " << endl;
                cout << "bug" << endl;
                cout << "i = " << i << endl;
            }
            h_Mx2_50_alpha->Fill(i, I_Mx50_weight);
        }
    }

    TTree *Mx150_tree;
    Mx2_150->GetObject("T_event", Mx150_tree);
    Mx150_tree->SetBranchAddress("I_weight", &I_Mx150_weight);
    Mx150_tree->SetBranchAddress("I_nThinJets", &I_Mx150_nThinJets);
    Mx150_tree->SetBranchAddress("v_fakealpha", &v_Mx2_150_alpha);
    for (int evt = 0; evt < Mx150_tree->GetEntries(); evt++)
    {
        Mx150_tree->GetEntry(evt);
        for (int i = 0; i < v_Mx2_150_alpha->size(); i++)
        {
            if ((*v_Mx2_150_alpha)[i] > 1)
            {
                cout << "Mx2_150 " << endl;
                cout << "bug" << endl;
                cout << "i = " << (*v_Mx2_150_alpha)[i] << endl;
            }
            h_Mx2_150_alpha->Fill((*v_Mx2_150_alpha)[i], I_Mx150_weight);
        }
    }

    TH1F *Top_alpha = (TH1F *)h_tW_top_alpha->Clone("Top_alpha");
    Top_alpha->Add(h_tW_antitop_alpha);
    Top_alpha->Add(h_TTTo2L2Nu_alpha);
    Top_alpha->Add(h_TTWJetsToLNu_alpha);
    Top_alpha->Add(h_TWJetsToQQ_alpha);
    Top_alpha->Add(h_TTZToLLNuNu_alpha);
    Top_alpha->Add(h_TTZToQQ_alpha);

    Top_alpha->SetLineWidth(2);
    h_Mx2_1_alpha->SetLineWidth(2);
    h_Mx2_50_alpha->SetLineWidth(2);
    h_Mx2_150_alpha->SetLineWidth(2);
    DY_alpha->SetLineWidth(2);

    Top_alpha->SetLineColor(kRed);
    DY_alpha->SetLineColor(kMagenta);
    h_Mx2_1_alpha->SetLineColor(kBlack);
    h_Mx2_50_alpha->SetLineColor(kBlue);
    h_Mx2_150_alpha->SetLineColor(kGreen - 5);

    DY_alpha->SetFillColor(kMagenta);
    DY_alpha->SetFillStyle(3001);

    TH2F *ROC_total = new TH2F("ROC_total", "", 100, 0, 1, 100, 0, 1);
    ROC_total->SetXTitle("Sig Efficiency");
    ROC_total->SetYTitle("Bkg rejection Efficiency");
    auto c1 = new TCanvas("c", "BPRE");
    Top_alpha->GetYaxis()->SetTitle("N Jets / Normalized");
    Top_alpha->GetXaxis()->SetTitle("#alpha_{3D}");

    
    // DY_alpha->Draw("hist");
    Top_alpha->DrawNormalized("hist&&same");
    DY_alpha->DrawNormalized("hist&&same");
    h_Mx2_50_alpha->DrawNormalized("hist&&same");
    h_Mx2_1_alpha->DrawNormalized("hist&&same");
    h_Mx2_150_alpha->DrawNormalized("hist&&same");


    TLegend *i2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    i2->SetBorderSize(0);
    i2->SetTextSize(0.03);
    i2->AddEntry(h_Mx2_1_alpha, "ctau=1mm m_{x^{2}}=1", "l");
    i2->AddEntry(h_Mx2_50_alpha, "ctau=10mm m_{x^{2}}=50", "l");
    i2->AddEntry(h_Mx2_150_alpha, "ctau=1mm m_{x^{2}}=150", "l");
    i2->AddEntry(Top_alpha, "Top", "l");
    i2->AddEntry(DY_alpha, "Drell-Yan", "f");
    i2->Draw();

    gStyle->SetOptStat(0);
    c1->SetLogy();

    
    float TotSigEvent_Mx1 = h_Mx2_1_alpha->Integral();
    float TotSigEvent_Mx50 = h_Mx2_50_alpha->Integral();
    float TotSigEvent_Mx150 = h_Mx2_150_alpha->Integral();
    float TotBgEvent_Mx1 = Top_alpha->Integral();
    int nBin = h_Mx2_1_alpha->GetNbinsX();

    float nSigEvent_Mx1 = 0;
    float nSigEvent_Mx50 = 0;
    float nSigEvent_Mx150 = 0;
    float nBgEvent_Mx1 = 0;

    float Teffs_Mx1[24], Teffb_Mx1[24];
    float Teffs_Mx50[24];
    float Teffs_Mx150[24];
    vector<float> effs_Mx1;
    vector<float> effb_Mx1;
    vector<float> effs_Mx50;
    vector<float> effs_Mx150;
    effs_Mx1.clear();
    effb_Mx1.clear();
    effs_Mx50.clear();
    effs_Mx150.clear();
    for (int i = 0; i < nBin; i++)
    {
        nSigEvent_Mx1 += h_Mx2_1_alpha->GetBinContent(i);     // from 0 to end for sig
        nSigEvent_Mx50 += h_Mx2_50_alpha->GetBinContent(i);   // from 0 to end for sig
        nSigEvent_Mx150 += h_Mx2_150_alpha->GetBinContent(i); // from 0 to end for sig
        nBgEvent_Mx1 += Top_alpha->GetBinContent(i);

        effs_Mx1.push_back(nSigEvent_Mx1 / TotSigEvent_Mx1);
        effs_Mx50.push_back(nSigEvent_Mx50 / TotSigEvent_Mx50);
        effs_Mx150.push_back(nSigEvent_Mx150 / TotSigEvent_Mx150);
        effb_Mx1.push_back(nBgEvent_Mx1 / TotBgEvent_Mx1);
        // cout << "i = " << i << endl;
        // cout << " effs_Mx1 " << nSigEvent_Mx1 / TotSigEvent_Mx1 << endl;
        // cout << " effb_Mx1 " << nBgEvent_Mx1 / TotBgEvent_Mx1 << endl;
    }

    for (int i = 0; i < nBin; i++)
    {
        Teffs_Mx1[i] = effs_Mx1[i];
        Teffs_Mx50[i] = effs_Mx50[i];
        Teffs_Mx150[i] = effs_Mx150[i];
        Teffb_Mx1[i] = 1 - effb_Mx1[i];
    }

    TGraph *ROC_Mx1 = new TGraph(24, Teffs_Mx1, Teffb_Mx1);
    TGraph *ROC_Mx50 = new TGraph(24, Teffs_Mx50, Teffb_Mx1);
    TGraph *ROC_Mx150 = new TGraph(24, Teffs_Mx150, Teffb_Mx1);

    ROC_Mx1->SetLineWidth(2);
    ROC_Mx50->SetLineWidth(2);
    ROC_Mx150->SetLineWidth(2);

    ROC_Mx1->SetLineColor(kRed);
    ROC_Mx50->SetLineColor(kBlue);
    ROC_Mx150->SetLineColor(kGreen);

    ROC_Mx1->GetXaxis()->SetTitle("Sig Efficiency");
    // sigEff_vs_bkgEff->GetXaxis()->SetLimits(0, 1.0);
    // sigEff_vs_bkgEff->GetXaxis()->SetTickSize(0.03);
    ROC_Mx1->GetXaxis()->SetTitleOffset(1.2);
    ROC_Mx1->GetXaxis()->SetLabelOffset(0.015);
    ROC_Mx1->GetYaxis()->SetTitle("Bkg rejection Efficiency");

    gStyle->SetOptStat(0);
    //ROC_total->Draw();
    //ROC_Mx1->Draw("L* same");
    //ROC_Mx50->Draw("CP*");
    //ROC_Mx150->Draw("C*");
    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(ROC_Mx1, "ctau=1mm m_{x^{2}}=1", "l");
    l1->AddEntry(ROC_Mx50, "ctau=10mm m_{x^{2}}=50", "l");
    l1->AddEntry(ROC_Mx150, "ctau=1mm m_{x^{2}}=150", "l");
    //l1->Draw();
}