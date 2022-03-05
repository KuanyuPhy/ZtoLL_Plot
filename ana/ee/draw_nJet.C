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
#include "./../lib/Cross_section.h"
#include "./../lib/setNCUStyle.C"
using namespace RooFit;
void draw_nJet()
{
    TFile *Mx2_1 = new TFile("./../../../root_file/Ztoee/Mx2_1.root");
    TFile *Mx2_50 = new TFile("./../../../root_file/Ztoee/Mx2_50.root");
    TFile *Mx2_150 = new TFile("./../../../root_file/Ztoee/Mx2_150.root");

    TFile *DYincli = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");
    TFile *DYHT70 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

    TFile *Top_TTTo2L2Nu = new TFile("./../../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)Top_TTTo2L2Nu->Get("Event_Variable/h_totevent"));

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));

    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("Event_Variable/h_totevent"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("Event_Variable/h_totevent"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("Event_Variable/h_totevent"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("Event_Variable/h_totevent"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("Event_Variable/h_totevent"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("Event_Variable/h_totevent"));

    int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();

    int DYHT100_totevt = DYHT100_sumevt->Integral();
    int DYHT200_totevt = DYHT200_sumevt->Integral();
    int DYHT400_totevt = DYHT400_sumevt->Integral();
    int DYHT600_totevt = DYHT600_sumevt->Integral();
    int DYHT800_totevt = DYHT800_sumevt->Integral();
    int DYHT1200_totevt = DYHT1200_sumevt->Integral();
    int DYHT2500_totevt = DYHT2500_sumevt->Integral();

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
    // Define the HTWeight
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

    float TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTTo2L2Nu / (TTTo2L2Nu_totevt)) * 1000;

    float_t HT;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    Int_t I_ht0_nThinJets, I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets, I_ht600_nThinJets,
        I_ht800_nThinJets, I_ht1200_nThinJets, I_ht2500_nThinJets;

    Int_t I_TTTo2L2Nu_nThinJets;

    Int_t f_TTTo2L2Nu_weight;

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;

    Int_t I_Mx1_nThinJets, I_Mx50_nThinJets, I_Mx150_nThinJets;

    TH1F *h_ht0_nJets = new TH1F("h_ht0_nJets", "numbers of jets", 10, 0, 10);
    h_ht0_nJets->Sumw2();
    TH1F *h_ht70_nJets = new TH1F("h_ht70_nJets", "numbers of jets", 10, 0, 10);
    h_ht70_nJets->Sumw2();
    TH1F *h_ht100_nJets = new TH1F("h_ht100_nJets", "numbers of jets", 10, 0, 10);
    h_ht100_nJets->Sumw2();
    TH1F *h_ht200_nJets = new TH1F("h_ht200_nJets", "numbers of jets", 10, 0, 10);
    h_ht200_nJets->Sumw2();
    TH1F *h_ht400_nJets = new TH1F("h_ht400_nJets", "numbers of jets", 10, 0, 10);
    h_ht400_nJets->Sumw2();
    TH1F *h_ht600_nJets = new TH1F("h_ht600_nJets", "numbers of jets", 10, 0, 10);
    h_ht600_nJets->Sumw2();
    TH1F *h_ht800_nJets = new TH1F("h_ht800_nJets", "numbers of jets", 10, 0, 10);
    h_ht800_nJets->Sumw2();
    TH1F *h_ht1200_nJets = new TH1F("h_ht1200_nJets", "numbers of jets", 10, 0, 10);
    h_ht1200_nJets->Sumw2();
    TH1F *h_ht2500_nJets = new TH1F("h_ht2500_nJets", "numbers of jets", 10, 0, 10);
    h_ht2500_nJets->Sumw2();

    TH1F *h_TTTo2L2Nu_nJets = new TH1F("h_TTTo2L2Nu_nJets", "numbers of jets", 10, 0, 10);
    h_TTTo2L2Nu_nJets->Sumw2();

    TH1F *h_Mx2_1_nJets = new TH1F("h_Mx2_1_nJets", "numbers of jets", 10, 0, 10);
    h_Mx2_1_nJets->Sumw2();
    TH1F *h_Mx2_50_nJets = new TH1F("h_Mx2_50_nJets", "numbers of jets", 10, 0, 10);
    h_Mx2_50_nJets->Sumw2();
    TH1F *h_Mx2_150_nJets = new TH1F("h_Mx2_150_nJets", "numbers of jets", 10, 0, 10);
    h_Mx2_150_nJets->Sumw2();

    TTree *T_event;
    DYincli->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &I_ht0_weight);
    T_event->SetBranchAddress("f_HT", &HT);
    T_event->SetBranchAddress("I_nThinJets", &I_ht0_nThinJets);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (HT < 70)
        {
            h_ht0_nJets->Fill(I_ht0_nThinJets, I_ht0_weight * HT0Weight);
        }
        else if (HT >= 70 && HT < 100)
        {
            h_ht70_nJets->Fill(I_ht0_nThinJets, I_ht0_weight * HT70Weight);
        }
        else if (HT >= 100 && HT < 200)
        {
            h_ht100_nJets->Fill(I_ht0_nThinJets, I_ht0_weight * HT100Weight);
        }
        else if (HT >= 200 && HT < 400)
        {
            h_ht200_nJets->Fill(I_ht0_nThinJets, I_ht0_weight * HT200Weight);
        }
        else if (HT >= 400 && HT < 600)
        {
            h_ht400_nJets->Fill(I_ht0_nThinJets, I_ht0_weight * HT400Weight);
        }
        else if (HT >= 600 && HT < 800)
        {
            h_ht600_nJets->Fill(I_ht0_nThinJets, I_ht0_weight * HT600Weight);
        }
        else if (HT >= 800 && HT < 1200)
        {
            h_ht800_nJets->Fill(I_ht0_nThinJets, I_ht0_weight * HT800Weight);
        }
        else if (HT >= 1200 && HT < 2500)
        {
            h_ht1200_nJets->Fill(I_ht0_nThinJets, I_ht0_weight * HT1200Weight);
        }
        else if (HT >= 2500)
        {
            h_ht2500_nJets->Fill(I_ht0_nThinJets, I_ht0_weight * HT2500Weight);
        }
    }
    TTree *T_event1;
    DYHT100->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("I_weight", &I_ht100_weight);
    T_event1->SetBranchAddress("I_nThinJets", &I_ht100_nThinJets);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        h_ht100_nJets->Fill(I_ht100_nThinJets, I_ht100_weight * HT100Weight);
    }
    TTree *T_event2;
    DYHT200->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("I_weight", &I_ht200_weight);
    T_event2->SetBranchAddress("I_nThinJets", &I_ht200_nThinJets);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        h_ht200_nJets->Fill(I_ht200_nThinJets, I_ht200_weight * HT200Weight);
    }
    TTree *T_event3;
    DYHT400->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("I_weight", &I_ht400_weight);
    T_event3->SetBranchAddress("I_nThinJets", &I_ht400_nThinJets);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        h_ht400_nJets->Fill(I_ht400_nThinJets, I_ht400_weight * HT400Weight);
    }
    TTree *T_event4;
    DYHT600->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("I_weight", &I_ht600_weight);
    T_event4->SetBranchAddress("I_nThinJets", &I_ht600_nThinJets);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        h_ht600_nJets->Fill(I_ht600_nThinJets, I_ht600_weight * HT600Weight);
    }
    TTree *T_event5;
    DYHT800->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("I_weight", &I_ht800_weight);
    T_event5->SetBranchAddress("I_nThinJets", &I_ht800_nThinJets);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        h_ht800_nJets->Fill(I_ht800_nThinJets, I_ht800_weight * HT800Weight);
    }
    TTree *T_event6;
    DYHT1200->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_event6->SetBranchAddress("I_nThinJets", &I_ht1200_nThinJets);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        h_ht1200_nJets->Fill(I_ht1200_nThinJets, I_ht1200_weight * HT1200Weight);
    }
    TTree *T_event7;
    DYHT2500->GetObject("T_event", T_event7);
    T_event7->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_event7->SetBranchAddress("I_nThinJets", &I_ht2500_nThinJets);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        h_ht2500_nJets->Fill(I_ht2500_nThinJets, I_ht2500_weight * HT2500Weight);
    }
    TTree *T_event8;
    Top_TTTo2L2Nu->GetObject("T_event", T_event8);
    T_event8->SetBranchAddress("I_weight", &f_TTTo2L2Nu_weight);
    T_event8->SetBranchAddress("I_nThinJets", &I_TTTo2L2Nu_nThinJets);
    for (int evt = 0; evt < T_event8->GetEntries(); evt++)
    {
        T_event8->GetEntry(evt);
        h_TTTo2L2Nu_nJets->Fill(I_TTTo2L2Nu_nThinJets, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
    }

    TTree *Mx1_tree;
    Mx2_1->GetObject("T_event", Mx1_tree);
    Mx1_tree->SetBranchAddress("I_weight", &I_Mx1_weight);
    Mx1_tree->SetBranchAddress("I_nThinJets", &I_Mx1_nThinJets);
    for (int evt = 0; evt < Mx1_tree->GetEntries(); evt++)
    {
        Mx1_tree->GetEntry(evt);
        h_Mx2_1_nJets->Fill(I_Mx1_nThinJets, I_Mx1_weight);
    }

    TTree *Mx50_tree;
    Mx2_50->GetObject("T_event", Mx50_tree);
    Mx50_tree->SetBranchAddress("I_weight", &I_Mx50_weight);
    Mx50_tree->SetBranchAddress("I_nThinJets", &I_Mx50_nThinJets);
    for (int evt = 0; evt < Mx50_tree->GetEntries(); evt++)
    {
        Mx50_tree->GetEntry(evt);
        h_Mx2_50_nJets->Fill(I_Mx50_nThinJets, I_Mx50_weight);
    }

    TTree *Mx150_tree;
    Mx2_150->GetObject("T_event", Mx150_tree);
    Mx150_tree->SetBranchAddress("I_weight", &I_Mx150_weight);
    Mx150_tree->SetBranchAddress("I_nThinJets", &I_Mx150_nThinJets);
    for (int evt = 0; evt < Mx150_tree->GetEntries(); evt++)
    {
        Mx150_tree->GetEntry(evt);
        h_Mx2_150_nJets->Fill(I_Mx150_nThinJets, I_Mx150_weight);
    }
    h_ht0_nJets->Add(h_ht70_nJets);
    h_ht0_nJets->Add(h_ht100_nJets);
    h_ht0_nJets->Add(h_ht200_nJets);
    h_ht0_nJets->Add(h_ht400_nJets);
    h_ht0_nJets->Add(h_ht600_nJets);
    h_ht0_nJets->Add(h_ht800_nJets);
    h_ht0_nJets->Add(h_ht1200_nJets);
    h_ht0_nJets->Add(h_ht2500_nJets);

    h_TTTo2L2Nu_nJets->SetLineWidth(2);
    h_ht0_nJets->SetLineWidth(2);
    h_Mx2_1_nJets->SetLineWidth(2);
    h_Mx2_50_nJets->SetLineWidth(2);
    h_Mx2_150_nJets->SetLineWidth(2);

    h_TTTo2L2Nu_nJets->SetLineColor(kMagenta);
    h_ht0_nJets->SetLineColor(kRed);
    h_ht0_nJets->SetFillColor(kRed);
    h_ht0_nJets->SetFillStyle(3001);
    h_ht0_nJets->SetLineColor(kRed);
    h_Mx2_1_nJets->SetLineColor(kBlack);
    h_Mx2_50_nJets->SetLineColor(kBlue);
    h_Mx2_150_nJets->SetLineColor(kGreen - 5);

    h_ht0_nJets->DrawNormalized("hist ");
    h_Mx2_1_nJets->DrawNormalized("hist same");
    h_TTTo2L2Nu_nJets->DrawNormalized("hist same ");

    h_Mx2_50_nJets->DrawNormalized("hist same");
    h_Mx2_150_nJets->DrawNormalized("hist same");

    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_Mx2_1_nJets, "ctau=1mm m_{x^{2}}=1", "l");
    l1->AddEntry(h_Mx2_50_nJets, "ctau=10mm m_{x^{2}}=50", "l");
    l1->AddEntry(h_Mx2_150_nJets, "ctau=1mm m_{x^{2}}=150", "l");
    l1->AddEntry(h_ht0_nJets, "Drell-Yan", "f");
    l1->AddEntry(h_TTTo2L2Nu_nJets, "Top process", "f");
    l1->Draw();

    gStyle->SetOptStat(0);
}