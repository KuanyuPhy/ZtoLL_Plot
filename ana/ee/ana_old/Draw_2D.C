#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <TH3D.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TAxis.h>
#include <TLine.h>
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "./lib/Cross_section.h"
using namespace RooFit;

void Draw_2D()
{
    TFile *DYincli = new TFile("./../../root_file/Ztoee/ee_DYincli.root");

    TFile *DYHT70 = new TFile("./../../root_file/Ztoee/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../root_file/Ztoee/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../root_file/Ztoee/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../root_file/Ztoee/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../root_file/Ztoee/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../root_file/Ztoee/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../root_file/Ztoee/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../root_file/Ztoee/ee_ht2500.root");

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("h_HT_eventCout"));

    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("h_event"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("h_event"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("h_event"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("h_event"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("h_event"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("h_event"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("h_event"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("h_event"));

    int DYHT70_totevt = DYHT70_sumevt->GetEntries();
    int DYHT100_totevt = DYHT100_sumevt->GetEntries();
    int DYHT200_totevt = DYHT200_sumevt->GetEntries();
    int DYHT400_totevt = DYHT400_sumevt->GetEntries();
    int DYHT600_totevt = DYHT600_sumevt->GetEntries();
    int DYHT800_totevt = DYHT800_sumevt->GetEntries();
    int DYHT1200_totevt = DYHT1200_sumevt->GetEntries();
    int DYHT2500_totevt = DYHT2500_sumevt->GetEntries();

    int HT0_70_event = h_HT_eventCout->GetBinContent(2);
    int HT70_100_event = h_HT_eventCout->GetBinContent(3);
    int HT100_200_event = h_HT_eventCout->GetBinContent(4);
    int HT200_400_event = h_HT_eventCout->GetBinContent(5);
    int HT400_600_event = h_HT_eventCout->GetBinContent(6);
    int HT600_800_event = h_HT_eventCout->GetBinContent(7);
    int HT800_1200_event = h_HT_eventCout->GetBinContent(8);
    int HT1200_2500_event = h_HT_eventCout->GetBinContent(9);
    int HT2500_Inf_event = h_HT_eventCout->GetBinContent(10);

    float HT0_weight = 35.9 * ((4609.090666) / (HT0_70_event)) * 1000;
    float HT70_weight = (35.9 * ((149.9710714) / (HT70_100_event)) * 1000);
    float HT100_weight = (35.9 * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000);
    float HT200_weight = (35.9 * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000);
    float HT400_weight = (35.9 * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000);
    float HT600_weight = (35.9 * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000);
    float HT800_weight = (35.9 * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000);
    float HT1200_weight = (35.9 * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000);
    float HT2500_weight = (35.9 * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000);

    TH2F *h_Met_Alphamin = new TH2F("h_Met_Alphamin", "", 12, 0, 1000, 24, 0, 1.2);
    h_Met_Alphamin->Sumw2();

    float_t HT;

    Double_t f_ht0alphamin, f_ht70_alphamin, f_ht100_alphamin, f_ht200_alphamin, f_ht400_alphamin,
        f_ht600_alphamin, f_ht800_alphamin, f_ht1200_alphamin, f_ht2500_alphamin;
    float_t f_ht0_Met, f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;
    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    TTree *T_event;
    DYincli->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &I_ht0_weight);
    T_event->SetBranchAddress("f_alphamin", &f_ht0alphamin);
    T_event->SetBranchAddress("f_Met", &f_ht0_Met);
    T_event->SetBranchAddress("f_HT", &HT);

    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (HT < 70)
        {
            h_Met_Alphamin->Fill(f_ht0_Met, f_ht0alphamin, I_ht0_weight * HT0_weight);
        }
        else if (HT > 70 && HT < 100)
        {
            h_Met_Alphamin->Fill(f_ht0_Met, f_ht0alphamin, I_ht0_weight * HT70_weight);
        }
        else if (HT > 100 && HT < 200)
        {
            h_Met_Alphamin->Fill(f_ht0_Met, f_ht0alphamin, I_ht0_weight * HT100_weight);
        }
        else if (HT > 200 && HT < 400)
        {
            h_Met_Alphamin->Fill(f_ht0_Met, f_ht0alphamin, I_ht0_weight * HT200_weight);
        }
        else if (HT > 400 && HT < 600)
        {
            h_Met_Alphamin->Fill(f_ht0_Met, f_ht0alphamin, I_ht0_weight * HT400_weight);
        }
        else if (HT > 600 && HT < 800)
        {
            h_Met_Alphamin->Fill(f_ht0_Met, f_ht0alphamin, I_ht0_weight * HT600_weight);
        }
        else if (HT > 800 && HT < 1200)
        {
            h_Met_Alphamin->Fill(f_ht0_Met, f_ht0alphamin, I_ht0_weight * HT800_weight);
        }
        else if (HT > 1200 && HT < 2500)
        {
            h_Met_Alphamin->Fill(f_ht0_Met, f_ht0alphamin, I_ht0_weight * HT1200_weight);
        }
        else if (HT > 2500)
        {
            h_Met_Alphamin->Fill(f_ht0_Met, f_ht0alphamin, I_ht0_weight * HT2500_weight);
        }
    }

    TTree *T_event1;
    DYHT100->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_ht100_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_ht100_Met);
    T_event1->SetBranchAddress("I_weight", &I_ht100_weight);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        h_Met_Alphamin->Fill(f_ht100_Met, f_ht100_alphamin, I_ht100_weight * HT100_weight);
    }

    TTree *T_event2;
    DYHT200->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_ht200_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_ht200_Met);
    T_event2->SetBranchAddress("I_weight", &I_ht200_weight);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        h_Met_Alphamin->Fill(f_ht200_Met, f_ht200_alphamin, I_ht200_weight * HT200_weight);
    }
    TTree *T_event3;
    DYHT400->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &f_ht400_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_ht400_Met);
    T_event3->SetBranchAddress("I_weight", &I_ht400_weight);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        h_Met_Alphamin->Fill(f_ht400_Met, f_ht400_alphamin, I_ht400_weight * HT400_weight);
    }
    TTree *T_event4;
    DYHT600->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &f_ht600_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_ht600_Met);
    T_event4->SetBranchAddress("I_weight", &I_ht600_weight);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        h_Met_Alphamin->Fill(f_ht600_Met, f_ht600_alphamin, I_ht600_weight * HT600_weight);
    }
    TTree *T_event5;
    DYHT800->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &f_ht800_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_ht800_Met);
    T_event5->SetBranchAddress("I_weight", &I_ht800_weight);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        h_Met_Alphamin->Fill(f_ht800_Met, f_ht800_alphamin, I_ht800_weight * HT800_weight);
    }
    TTree *T_event6;
    DYHT1200->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &f_ht1200_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_ht1200_Met);
    T_event6->SetBranchAddress("I_weight", &I_ht1200_weight);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        h_Met_Alphamin->Fill(f_ht1200_Met, f_ht1200_alphamin, I_ht1200_weight * HT1200_weight);
    }
    TTree *T_event7;
    DYHT2500->GetObject("T_event", T_event7);
    T_event7->SetBranchAddress("f_alphamin", &f_ht2500_alphamin);
    T_event7->SetBranchAddress("f_Met", &f_ht2500_Met);
    T_event7->SetBranchAddress("I_weight", &I_ht2500_weight);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        h_Met_Alphamin->Fill(f_ht2500_Met, f_ht2500_alphamin, I_ht2500_weight * HT2500_weight);
    }
    h_Met_Alphamin->GetYaxis()->SetTitle("Alphamin");
    h_Met_Alphamin->GetXaxis()->SetTitle("Met");
    h_Met_Alphamin->Draw("Candle");
}