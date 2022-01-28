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

void BGEM_Top()
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

    Double_t nbins[13] = {0.0, 30, 55., 80., 100., 130., 175, 225., 300., 400, 500, 600, 800};
    Int_t nnbins = (sizeof(nbins) / sizeof(*nbins)) - 1;
    // Top
    TH1F *Top_TTTo2L2Nu_a_met = new TH1F("Top_TTTo2L2Nu_a_met", "TTTo2L2Nu", nnbins, nbins);
    Top_TTTo2L2Nu_a_met->Sumw2();

    TH1F *Top_TTWJetsToLNu_a_met = new TH1F("Top_TTWJetsToLNu_a_met", "TTWJetsToLNu", nnbins, nbins);
    Top_TTWJetsToLNu_a_met->Sumw2();

    TH1F *Top_TTWJetsToQQ_a_met = new TH1F("Top_TTWJetsToQQ_a_met", "TTWJetsToQQ", nnbins, nbins);
    Top_TTWJetsToQQ_a_met->Sumw2();

    TH1F *Top_TTZToLLNuNu_a_met = new TH1F("Top_TTZToLLNuNu_a_met", "TTZToLLNuNu", nnbins, nbins);
    Top_TTZToLLNuNu_a_met->Sumw2();

    TH1F *Top_TTZToQQ_a_met = new TH1F("Top_TTZToQQ_a_met", "TTZToQQ", nnbins, nbins);
    Top_TTZToQQ_a_met->Sumw2();

    TH1F *Top_tW_antitop_a_met = new TH1F("Top_tW_antitop_a_met", "tW_antitop", nnbins, nbins);
    Top_tW_antitop_a_met->Sumw2();

    TH1F *Top_tW_top_a_met = new TH1F("Top_tW_top_a_met", "tW_top", nnbins, nbins);
    Top_tW_top_a_met->Sumw2();

    // TH1F *Top_quark_met = new TH1F("Top_quark_met", "", nnbins, nbins);
    // Top_quark_met->Sumw2();

    TH1F *Top_TTTo2L2Nu_b_met = new TH1F("Top_TTTo2L2Nu_b_met", "TTTo2L2Nu", nnbins, nbins);
    Top_TTTo2L2Nu_b_met->Sumw2();

    TH1F *Top_TTWJetsToLNu_b_met = new TH1F("Top_TTWJetsToLNu_b_met", "TTWJetsToLNu", nnbins, nbins);
    Top_TTWJetsToLNu_b_met->Sumw2();

    TH1F *Top_TTWJetsToQQ_b_met = new TH1F("Top_TTWJetsToQQ_b_met", "TTWJetsToQQ", nnbins, nbins);
    Top_TTWJetsToQQ_b_met->Sumw2();

    TH1F *Top_TTZToLLNuNu_b_met = new TH1F("Top_TTZToLLNuNu_b_met", "TTZToLLNuNu", nnbins, nbins);
    Top_TTZToLLNuNu_b_met->Sumw2();

    TH1F *Top_TTZToQQ_b_met = new TH1F("Top_TTZToQQ_b_met", "TTZToQQ", nnbins, nbins);
    Top_TTZToQQ_b_met->Sumw2();

    TH1F *Top_tW_antitop_b_met = new TH1F("Top_tW_antitop_b_met", "tW_antitop", nnbins, nbins);
    Top_tW_antitop_b_met->Sumw2();

    TH1F *Top_tW_top_b_met = new TH1F("Top_tW_top_b_met", "tW_top", nnbins, nbins);
    Top_tW_top_b_met->Sumw2();

    // TH1F *Top_quark_met = new TH1F("Top_quark_met", "", nnbins, nbins);
    // Top_quark_met->Sumw2();

    Double_t f_tW_top_alphamin, f_tW_antitop_alphamin, f_TTTo2L2Nu_alphamin, f_TTWJetsToLNu_alphamin,
        f_TTWJetsToQQ_alphamin, f_TTZToLLNuNu_alphamin, f_TTZToQQ_alphamin;
    Float_t f_tW_top_met, f_tW_antitop_met, f_TTTo2L2Nu_met, f_TTWJetsToLNu_met,
        f_TTWJetsToQQ_met, f_TTZToLLNuNu_met, f_TTZToQQ_met;

    Int_t f_tW_top_weight, f_tW_antitop_weight, f_TTTo2L2Nu_weight, f_TTWJetsToLNu_weight, f_TTWJetsToQQ_weight,
        f_TTZToLLNuNu_weight, f_TTZToQQ_weight;

    Int_t I_tW_top_nThinJets, I_tW_antitop_nThinJets, I_TTTo2L2Nu_nThinJets, I_TTWJetsToLNu_nThinJets, I_TTWJetsToQQ_nThinJets,
        I_TTZToLLNuNu_nThinJets, I_TTZToQQ_nThinJets;

    Int_t I_tW_top_minJetflavor, I_tW_antitop_minJetflavor, I_TTTo2L2Nu_minJetflavor, I_TTWJetsToLNu_minJetflavor, I_TTWJetsToQQ_minJetflavor,
        I_TTZToLLNuNu_minJetflavor, I_TTZToQQ_minJetflavor;

    // Define the Top
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
    T_event->SetBranchAddress("I_nThinJets", &I_tW_top_nThinJets);
    T_event->SetBranchAddress("I_minJetflavor", &I_tW_top_minJetflavor);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (I_tW_top_nThinJets < 2)
            continue;
        if (I_tW_top_minJetflavor == 0)
        {
            if (f_tW_top_alphamin > 0.3)
            {
                Top_tW_top_a_met->Fill(f_tW_top_met, f_tW_top_weight * ST_tW_topWeight);
            }
            if (f_tW_top_alphamin < 0.1)
            {
                Top_tW_top_b_met->Fill(f_tW_top_met, f_tW_top_weight * ST_tW_topWeight);
            }
        }
    }

    TTree *T_event1;
    Top_tW_antitop->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_tW_antitop_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_tW_antitop_met);
    T_event1->SetBranchAddress("I_weight", &f_tW_antitop_weight);
    T_event1->SetBranchAddress("I_nThinJets", &I_tW_antitop_nThinJets);
    T_event1->SetBranchAddress("I_minJetflavor", &I_tW_antitop_minJetflavor);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (I_tW_antitop_nThinJets < 2)
            continue;
        if (I_tW_antitop_minJetflavor == 0)
        {
            if (f_tW_antitop_alphamin > 0.3)
            {
                Top_tW_antitop_a_met->Fill(f_tW_antitop_met, f_tW_antitop_weight * ST_tW_antitopWeight);
            }
            if (f_tW_antitop_alphamin < 0.1)
            {
                Top_tW_antitop_b_met->Fill(f_tW_antitop_met, f_tW_antitop_weight * ST_tW_antitopWeight);
            }
        }
    }

    TTree *T_event2;
    Top_TTTo2L2Nu->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_TTTo2L2Nu_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_event2->SetBranchAddress("I_weight", &f_TTTo2L2Nu_weight);
    T_event2->SetBranchAddress("I_nThinJets", &I_TTTo2L2Nu_nThinJets);
    T_event2->SetBranchAddress("I_minJetflavor", &I_TTTo2L2Nu_minJetflavor);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (I_TTTo2L2Nu_nThinJets < 2)
            continue;
        if (I_TTTo2L2Nu_minJetflavor == 0)
        {
            if (f_TTTo2L2Nu_alphamin > 0.3)
            {
                Top_TTTo2L2Nu_a_met->Fill(f_TTTo2L2Nu_met, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            }
            if (f_TTTo2L2Nu_alphamin < 0.1)
            {
                Top_TTTo2L2Nu_b_met->Fill(f_TTTo2L2Nu_met, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            }
        }
    }

    TTree *T_event3;
    Top_TTWJetsToLNu->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &f_TTWJetsToLNu_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_event3->SetBranchAddress("I_weight", &f_TTWJetsToLNu_weight);
    T_event3->SetBranchAddress("I_nThinJets", &I_TTWJetsToLNu_nThinJets);
    T_event3->SetBranchAddress("I_minJetflavor", &I_TTWJetsToLNu_minJetflavor);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (I_TTWJetsToLNu_nThinJets < 2)
            continue;
        if (I_TTWJetsToLNu_minJetflavor == 0)
        {
            if (f_TTWJetsToLNu_alphamin > 0.3)
            {
                Top_TTWJetsToLNu_a_met->Fill(f_TTWJetsToLNu_met, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            }
            if (f_TTWJetsToLNu_alphamin < 0.1)
            {
                Top_TTWJetsToLNu_b_met->Fill(f_TTWJetsToLNu_met, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            }
        }
    }

    TTree *T_event4;
    Top_TTWJetsToQQ->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &f_TTWJetsToQQ_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_event4->SetBranchAddress("I_weight", &f_TTWJetsToQQ_weight);
    T_event4->SetBranchAddress("I_nThinJets", &I_TTWJetsToQQ_nThinJets);
    T_event4->SetBranchAddress("I_minJetflavor", &I_TTWJetsToQQ_minJetflavor);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (I_TTWJetsToQQ_nThinJets < 2)
            continue;
        if (I_TTWJetsToQQ_minJetflavor == 0)
        {
            if (f_TTWJetsToQQ_alphamin > 0.3)
            {
                Top_TTWJetsToQQ_a_met->Fill(f_TTWJetsToQQ_met, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            }
            if (f_TTWJetsToQQ_alphamin < 0.1)
            {
                Top_TTWJetsToQQ_b_met->Fill(f_TTWJetsToQQ_met, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            }
        }
    }

    TTree *T_event5;
    Top_TTZToLLNuNu->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &f_TTZToLLNuNu_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_event5->SetBranchAddress("I_weight", &f_TTZToLLNuNu_weight);
    T_event5->SetBranchAddress("I_nThinJets", &I_TTZToLLNuNu_nThinJets);
    T_event5->SetBranchAddress("I_minJetflavor", &I_TTZToLLNuNu_minJetflavor);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (I_TTZToLLNuNu_nThinJets < 2)
            continue;
        if (I_TTZToLLNuNu_minJetflavor == 0)
        {
            if (f_TTZToLLNuNu_alphamin > 0.3)
            {
                Top_TTZToLLNuNu_a_met->Fill(f_TTZToLLNuNu_met, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            }
            if (f_TTZToLLNuNu_alphamin < 0.1)
            {
                Top_TTZToLLNuNu_b_met->Fill(f_TTZToLLNuNu_met, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            }
        }
    }

    TTree *T_event6;
    Top_TTZToQQ->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &f_TTZToQQ_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_event6->SetBranchAddress("I_weight", &f_TTZToQQ_weight);
    T_event6->SetBranchAddress("I_nThinJets", &I_TTZToQQ_nThinJets);
    T_event6->SetBranchAddress("I_minJetflavor", &I_TTZToQQ_minJetflavor);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (I_TTZToQQ_nThinJets < 2)
            continue;
        if (I_TTZToQQ_minJetflavor == 0)
        {
            if (f_TTZToQQ_alphamin > 0.3)
            {
                Top_TTZToQQ_a_met->Fill(f_TTZToQQ_met, f_TTZToQQ_weight * TTZToQQWeight);
            }
            if (f_TTZToQQ_alphamin < 0.1)
            {
                Top_TTZToQQ_b_met->Fill(f_TTZToQQ_met, f_TTZToQQ_weight * TTZToQQWeight);
            }
        }
    }
    TH1F *h_Top_met_A = (TH1F *)Top_tW_top_a_met->Clone("h_Top_met_A");
    TH1F *h_Top_met_B = (TH1F *)Top_tW_top_b_met->Clone("h_Top_met_B");

    // TH1F *h_Top_alphamin_A = (TH1F *)h_ht0A_aphmin->Clone("h_DYHT_alphamin_A");
    // TH1F *h_Top_alphamin_B = (TH1F *)h_ht0B_aphmin->Clone("h_DYHT_alphamin_B");

    h_Top_met_A->Add(Top_tW_antitop_a_met);
    h_Top_met_A->Add(Top_TTTo2L2Nu_a_met);
    h_Top_met_A->Add(Top_TTWJetsToLNu_a_met);
    h_Top_met_A->Add(Top_TTWJetsToQQ_a_met);
    h_Top_met_A->Add(Top_TTZToLLNuNu_a_met);
    h_Top_met_A->Add(Top_TTZToQQ_a_met);

    h_Top_met_B->Add(Top_tW_antitop_b_met);
    h_Top_met_B->Add(Top_TTTo2L2Nu_b_met);
    h_Top_met_B->Add(Top_TTWJetsToLNu_b_met);
    h_Top_met_B->Add(Top_TTWJetsToQQ_b_met);
    h_Top_met_B->Add(Top_TTZToLLNuNu_b_met);
    h_Top_met_B->Add(Top_TTZToQQ_b_met);

    TH1F *h_Top_met_Ratio = (TH1F *)h_Top_met_A->Clone("h_Top_met_Ratio");
    h_Top_met_Ratio->Divide(h_Top_met_B);

    // gStyle->SetOptStat(0);
    // Top_tW_top_a_met->SetTitle("Ratio of Met");
    // Top_tW_top_a_met->SetLineWidth(2);
    h_Top_met_Ratio->Draw();

    TFile *outFile = new TFile("./../../ABCD_Top.root", "RECREATE");
    outFile->cd();
    h_Top_met_A->Write();
    h_Top_met_B->Write();
    h_Top_met_Ratio->Write();
    Top_tW_top_a_met->Write();
    Top_tW_antitop_a_met->Write();
    Top_TTTo2L2Nu_a_met->Write();
    Top_TTWJetsToLNu_a_met->Write();
    Top_TTWJetsToQQ_a_met->Write();
    Top_TTZToLLNuNu_a_met->Write();
    Top_TTZToQQ_a_met->Write();
    Top_tW_top_b_met->Write();
    Top_tW_antitop_b_met->Write();
    Top_TTTo2L2Nu_b_met->Write();
    Top_TTWJetsToLNu_b_met->Write();
    Top_TTWJetsToQQ_b_met->Write();
    Top_TTZToLLNuNu_b_met->Write();
    Top_TTZToQQ_b_met->Write();
    outFile->Close();
}