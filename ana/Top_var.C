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

void Top_var()
{
    // SetColor
    Int_t KIKYO = TColor::GetFreeColorIndex();
    TColor *KIKYO_color = new TColor(KIKYO, 0.42, 0.30, 0.61);
    Int_t KON = TColor::GetFreeColorIndex();
    TColor *KON_color = new TColor(KON, 0.06, 0.15, 0.25);

    TFile *Top_TTTo2L2Nu = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
    TFile *Top_TTWJetsToLNu = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQ = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToLLNuNu = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_TTZToQQ = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_tW_antitop = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_top = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)Top_TTTo2L2Nu->Get("Event_Variable/h_event"));
    TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNu->Get("Event_Variable/h_event"));
    TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQ->Get("Event_Variable/h_event"));
    TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNu->Get("Event_Variable/h_event"));
    TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQ->Get("Event_Variable/h_event"));
    TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitop->Get("Event_Variable/h_event"));
    TH1D *tW_top_sumevt = ((TH1D *)Top_tW_top->Get("Event_Variable/h_event"));

    int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();
    int TTWJetsToLNu_totevt = TTWJetsToLNu_sumevt->Integral();
    int TTWJetsToQQ_totevt = TTWJetsToQQ_sumevt->Integral();
    int TTZToLLNuNu_totevt = TTZToLLNuNu_sumevt->Integral();
    int TTZToQQ_totevt = TTZToQQ_sumevt->Integral();
    int tW_antitop_totevt = tW_antitop_sumevt->Integral();
    int tW_top_totevt = tW_top_sumevt->Integral();


    // DYHT
    TH1F *Top_TTTo2L2Nu_aphmin = new TH1F("Top_TTTo2L2Nu_aphmin", "", 24, 0, 1.2);
    Top_TTTo2L2Nu_aphmin->Sumw2();

    TH1F *Top_TTWJetsToLNu_aphmin = new TH1F("Top_TTWJetsToLNu_aphmin", "", 24, 0, 1.2);
    Top_TTWJetsToLNu_aphmin->Sumw2();

    TH1F *Top_TTWJetsToQQ_aphmin = new TH1F("Top_TTWJetsToQQ_aphmin", "", 24, 0, 1.2);
    Top_TTWJetsToQQ_aphmin->Sumw2();

    TH1F *Top_TTZToLLNuNu_aphmin = new TH1F("Top_TTZToLLNuNu_aphmin", "", 24, 0, 1.2);
    Top_TTZToLLNuNu_aphmin->Sumw2();

    TH1F *Top_TTZToQQ_aphmin = new TH1F("Top_TTZToQQ_aphmin", "", 24, 0, 1.2);
    Top_TTZToQQ_aphmin->Sumw2();

    TH1F *Top_tW_antitop_aphmin = new TH1F("Top_tW_antitop_aphmin", "", 24, 0, 1.2);
    Top_tW_antitop_aphmin->Sumw2();

    TH1F *Top_tW_top_aphmin = new TH1F("Top_tW_top_aphmin", "", 24, 0, 1.2);
    Top_tW_top_aphmin->Sumw2();

    TH1F *Top_quark_aphmin = new TH1F("Top_quark_aphmin", "", 24, 0, 1.2);
    Top_quark_aphmin->Sumw2();

    // Top
    TH1F *Top_TTTo2L2Nu_met = new TH1F("Top_TTTo2L2Nu_met", "", 20, 0, 800);
    Top_TTTo2L2Nu_met->Sumw2();

    TH1F *Top_TTWJetsToLNu_met = new TH1F("Top_TTWJetsToLNu_met", "", 20, 0, 800);
    Top_TTWJetsToLNu_met->Sumw2();

    TH1F *Top_TTWJetsToQQ_met = new TH1F("Top_TTWJetsToQQ_met", "", 20, 0, 800);
    Top_TTWJetsToQQ_met->Sumw2();

    TH1F *Top_TTZToLLNuNu_met = new TH1F("Top_TTZToLLNuNu_met", "", 20, 0, 800);
    Top_TTZToLLNuNu_met->Sumw2();

    TH1F *Top_TTZToQQ_met = new TH1F("Top_TTZToQQ_met", "", 20, 0, 800);
    Top_TTZToQQ_met->Sumw2();

    TH1F *Top_tW_antitop_met = new TH1F("Top_tW_antitop_met", "", 20, 0, 800);
    Top_tW_antitop_met->Sumw2();

    TH1F *Top_tW_top_met = new TH1F("Top_tW_top_met", "", 20, 0, 800);
    Top_tW_top_met->Sumw2();

    TH1F *Top_quark_met = new TH1F("Top_quark_met", "", 20, 0, 800);
    Top_quark_met->Sumw2();

    Double_t f_tW_top_alphamin, f_tW_antitop_alphamin, f_TTTo2L2Nu_alphamin, f_TTWJetsToLNu_alphamin,
        f_TTWJetsToQQ_alphamin, f_TTZToLLNuNu_alphamin, f_TTZToQQ_alphamin;
    Float_t f_tW_top_met, f_tW_antitop_met, f_TTTo2L2Nu_met, f_TTWJetsToLNu_met,
        f_TTWJetsToQQ_met, f_TTZToLLNuNu_met, f_TTZToQQ_met;

    Int_t f_tW_top_weight, f_tW_antitop_weight, f_TTTo2L2Nu_weight, f_TTWJetsToLNu_weight, f_TTWJetsToQQ_weight,
        f_TTZToLLNuNu_weight, f_TTZToQQ_weight;

    // Define the HTWeight

    float ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000;
    float ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000;
    float TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTTo2L2Nu / (TTTo2L2Nu_totevt)) * 1000;
    float TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000;
    float TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000;
    float TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000;
    float TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000;

    TTree *T_event;
    Top_tW_top->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &f_tW_top_weight);
    T_event->SetBranchAddress("f_alphamin", &f_tW_top_alphamin);
    T_event->SetBranchAddress("f_Met", &f_tW_top_met);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        Top_tW_top_aphmin->Fill(f_tW_top_alphamin, f_tW_top_weight * ST_tW_topWeight);
        Top_tW_top_met->Fill(f_tW_top_met, f_tW_top_weight * ST_tW_topWeight);
        Top_quark_aphmin->Fill(f_tW_top_alphamin, f_tW_top_weight * ST_tW_topWeight);
        Top_quark_met->Fill(f_tW_top_met, f_tW_top_weight * ST_tW_topWeight);
    }

    TTree *T_event1;
    Top_tW_antitop->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_tW_antitop_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_tW_antitop_met);
    T_event1->SetBranchAddress("I_weight", &f_tW_antitop_weight);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        Top_tW_antitop_aphmin->Fill(f_tW_antitop_alphamin, f_tW_antitop_weight * ST_tW_antitopWeight);
        Top_tW_antitop_met->Fill(f_tW_antitop_met, f_tW_antitop_weight * ST_tW_antitopWeight);
    }

    TTree *T_event2;
    Top_TTTo2L2Nu->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_TTTo2L2Nu_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_event2->SetBranchAddress("I_weight", &f_TTTo2L2Nu_weight);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        Top_TTTo2L2Nu_aphmin->Fill(f_TTTo2L2Nu_alphamin, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        Top_TTTo2L2Nu_met->Fill(f_TTTo2L2Nu_met, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
    }

    TTree *T_event3;
    Top_TTWJetsToLNu->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &f_TTWJetsToLNu_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_event3->SetBranchAddress("I_weight", &f_TTWJetsToLNu_weight);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        Top_TTWJetsToLNu_aphmin->Fill(f_TTWJetsToLNu_alphamin, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        Top_TTWJetsToLNu_met->Fill(f_TTWJetsToLNu_met, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
    }

    TTree *T_event4;
    Top_TTWJetsToQQ->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &f_TTWJetsToQQ_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_event4->SetBranchAddress("I_weight", &f_TTWJetsToQQ_weight);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        Top_TTWJetsToQQ_aphmin->Fill(f_TTWJetsToQQ_alphamin, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        Top_TTWJetsToQQ_met->Fill(f_TTWJetsToQQ_met, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
    }

    TTree *T_event5;
    Top_TTZToLLNuNu->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &f_TTZToLLNuNu_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_event5->SetBranchAddress("I_weight", &f_TTZToLLNuNu_weight);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        Top_TTZToLLNuNu_aphmin->Fill(f_TTZToLLNuNu_alphamin, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        Top_TTZToLLNuNu_met->Fill(f_TTZToLLNuNu_met, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
    }

    TTree *T_event6;
    Top_TTZToQQ->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &f_TTZToQQ_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_event6->SetBranchAddress("I_weight", &f_TTZToQQ_weight);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        Top_TTZToQQ_aphmin->Fill(f_TTZToQQ_alphamin, f_TTZToQQ_weight * TTZToQQWeight);
        Top_TTZToQQ_met->Fill(f_TTZToQQ_met, f_TTZToQQ_weight * TTZToQQWeight);
    }

    // h_Rpf = (TH1F*)h_sb->Clone("h_Rpf");

    Top_quark_aphmin->Add(Top_tW_antitop_aphmin);
    Top_quark_aphmin->Add(Top_TTTo2L2Nu_aphmin);
    Top_quark_aphmin->Add(Top_TTWJetsToLNu_aphmin);
    Top_quark_aphmin->Add(Top_TTWJetsToQQ_aphmin);
    Top_quark_aphmin->Add(Top_TTZToLLNuNu_aphmin);
    Top_quark_aphmin->Add(Top_TTZToQQ_aphmin);

    Top_quark_met->Add(Top_tW_antitop_met);
    Top_quark_met->Add(Top_TTTo2L2Nu_met);
    Top_quark_met->Add(Top_TTWJetsToLNu_met);
    Top_quark_met->Add(Top_TTWJetsToQQ_met);
    Top_quark_met->Add(Top_TTZToLLNuNu_met);
    Top_quark_met->Add(Top_TTZToQQ_met);

    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(3, 3);
    c1->cd(1);
    Top_tW_top_aphmin->SetTitle("tW_top");
    Top_tW_top_met->SetTitle("tW_top");
    Top_tW_top_aphmin->SetFillColor(KON);
    Top_tW_top_met->SetFillColor(KON);
    //Top_tW_top_aphmin->SetFillStyle(3001);
    //Top_tW_top_aphmin->Draw("hist");
    Top_tW_top_met->Draw("hist");
    c1->cd(2);
    Top_tW_antitop_aphmin->SetTitle("tW_antitop");
    Top_tW_antitop_met->SetTitle("tW_antitop");
    Top_tW_antitop_aphmin->SetFillColor(KON);
    Top_tW_antitop_met->SetFillColor(KON);
    //Top_tW_antitop_aphmin->Draw("hist");
    Top_tW_antitop_met->Draw("hist");
    c1->cd(3);
    Top_TTTo2L2Nu_aphmin->SetTitle("TTTo2L2Nu");
    Top_TTTo2L2Nu_met->SetTitle("TTTo2L2Nu");
    Top_TTTo2L2Nu_aphmin->SetFillColor(KON);
    Top_TTTo2L2Nu_met->SetFillColor(KON);
    //Top_TTTo2L2Nu_aphmin->Draw("hist");
    Top_TTTo2L2Nu_met->Draw("hist");
    c1->cd(4);
    Top_TTWJetsToLNu_aphmin->SetTitle("TTWJetsToLNu");
    Top_TTWJetsToLNu_met->SetTitle("TTWJetsToLNu");
    Top_TTWJetsToLNu_aphmin->SetFillColor(KON);
    Top_TTWJetsToLNu_met->SetFillColor(KON);
    //Top_TTWJetsToLNu_aphmin->Draw("hist");
    Top_TTWJetsToLNu_met->Draw("hist");
    c1->cd(5);
    Top_TTWJetsToQQ_aphmin->SetTitle("TTWJetsToQQ");
    Top_TTWJetsToQQ_met->SetTitle("TTWJetsToQQ");
    Top_TTWJetsToQQ_aphmin->SetFillColor(KON);
    Top_TTWJetsToQQ_met->SetFillColor(KON);
    //Top_TTWJetsToQQ_aphmin->Draw("hist");
    Top_TTWJetsToQQ_met->Draw("hist");
    c1->cd(6);
    Top_TTZToLLNuNu_aphmin->SetTitle("TTZToLLNuNu");
    Top_TTZToLLNuNu_met->SetTitle("TTZToLLNuNu");
    Top_TTZToLLNuNu_aphmin->SetFillColor(KON);
    Top_TTZToLLNuNu_met->SetFillColor(KON);
    //Top_TTZToLLNuNu_aphmin->Draw("hist");
    Top_TTZToLLNuNu_met->Draw("hist");
    c1->cd(7);
    Top_TTZToQQ_aphmin->SetTitle("TTZToQQ");
    Top_TTZToQQ_met->SetTitle("TTZToQQ");
    Top_TTZToQQ_aphmin->SetFillColor(KON);
    Top_TTZToQQ_met->SetFillColor(KON);
    //Top_TTZToQQ_aphmin->Draw("hist");
    Top_TTZToQQ_met->Draw("hist");

    TFile *outFile = new TFile("./../../root_file/Ztoee/Top_All.root", "RECREATE");
    outFile->cd();

    Top_quark_aphmin->Write();
    Top_quark_met->Write();
    Top_tW_top_aphmin->Write();
    Top_tW_top_met->Write();
    Top_tW_antitop_aphmin->Write();
    Top_TTTo2L2Nu_aphmin->Write();
    Top_TTWJetsToLNu_aphmin->Write();
    Top_TTWJetsToQQ_aphmin->Write();
    Top_TTZToLLNuNu_aphmin->Write();
    Top_TTZToQQ_aphmin->Write();
    Top_tW_antitop_met->Write();
    Top_TTTo2L2Nu_met->Write();
    Top_TTWJetsToLNu_met->Write();
    Top_TTWJetsToQQ_met->Write();
    Top_TTZToLLNuNu_met->Write();
    Top_TTZToQQ_met->Write();

    outFile->Close();
}