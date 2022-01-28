#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./lib/Cross_section.h"
#include "setNCUStyle.C"
using namespace std;
void Top_2D_plot()
{

    Int_t KON = TColor::GetFreeColorIndex();
    TColor *KON_color = new TColor(KON, 0.06, 0.15, 0.25);
    Int_t HIWAMOEGI = TColor::GetFreeColorIndex();
    TColor *HIWAMOEGI_color = new TColor(HIWAMOEGI, 0.56, 0.71, 0.29);

    Int_t KARACHA = TColor::GetFreeColorIndex();
    TColor *KARACHA_color = new TColor(KARACHA, 0.71, 0.44, 0.34);

    Int_t JINZAMOMI = TColor::GetFreeColorIndex();
    TColor *JINZAMOMI_color = new TColor(JINZAMOMI, 0.92, 0.478, 0.46);

    Int_t BENIUKON = TColor::GetFreeColorIndex();
    TColor *BENIUKON_color = new TColor(BENIUKON, 0.913, 0.545, 0.16);

    Int_t SHIRACHA = TColor::GetFreeColorIndex();
    TColor *SHIRACHA_color = new TColor(SHIRACHA, 0.73, 0.623, 0.47);

    Int_t KARIYASU = TColor::GetFreeColorIndex();
    TColor *KARIYASU_color = new TColor(KARIYASU, 0.913, 0.803, 0.298);

    Int_t MIZUASAGI = TColor::GetFreeColorIndex();
    TColor *MIZUASAGI_color = new TColor(MIZUASAGI, 0.4, 0.729, 0.718);

    Int_t MATSUBA = TColor::GetFreeColorIndex();
    TColor *MATSUBA_color = new TColor(MATSUBA, 0.259, 0.376, 0.176);

    TH2F *h_tW_top_Met_multiplicity = new TH2F("h_tW_top_Met_multiplicity", "", 20, 0, 800, 8, 0, 8);
    TH2F *h_tW_antitop_Met_multiplicity = new TH2F("h_tW_antitop_Met_multiplicity", "", 20, 0, 800, 8, 0, 8);
    TH2F *h_TTTo2L2Nu_Met_multiplicity = new TH2F("h_TTTo2L2Nu_Met_multiplicity", "", 20, 0, 800, 8, 0, 8);
    TH2F *h_TTWJetsToLNu_Met_multiplicity = new TH2F("h_TTWJetsToLNu_Met_multiplicity", "", 20, 0, 800, 8, 0, 8);
    TH2F *h_TTWJetsToQQ_Met_multiplicity = new TH2F("h_TTWJetsToQQ_Met_multiplicity", "", 20, 0, 800, 8, 0, 8);
    TH2F *h_TTZToLLNuNu_Met_multiplicity = new TH2F("h_TTZToLLNuNu_Met_multiplicity", "", 20, 0, 800, 8, 0, 8);
    TH2F *h_TTZToQQ_Met_multiplicity = new TH2F("h_TTZToQQ_Met_multiplicity", "", 20, 0, 800, 8, 0, 8);

    TH2F *h_tW_top_Met_minJetPt = new TH2F("h_tW_top_Met_minJetPt", "", 20, 0, 800, 100, 0, 1000);
    TH2F *h_tW_antitop_Met_minJetPt = new TH2F("h_tW_antitop_Met_minJetPt", "", 20, 0, 800, 100, 0, 1000);
    TH2F *h_TTTo2L2Nu_Met_minJetPt = new TH2F("h_TTTo2L2Nu_Met_minJetPt", "", 20, 0, 800, 100, 0, 1000);
    TH2F *h_TTWJetsToLNu_Met_minJetPt = new TH2F("h_TTWJetsToLNu_Met_minJetPt", "", 20, 0, 800, 100, 0, 1000);
    TH2F *h_TTWJetsToQQ_Met_minJetPt = new TH2F("h_TTWJetsToQQ_Met_minJetPt", "", 20, 0, 800, 100, 0, 1000);
    TH2F *h_TTZToLLNuNu_Met_minJetPt = new TH2F("h_TTZToLLNuNu_Met_minJetPt", "", 20, 0, 800, 100, 0, 1000);
    TH2F *h_TTZToQQ_Met_minJetPt = new TH2F("h_TTZToQQ_Met_minJetPt", "", 20, 0, 800, 100, 0, 1000);

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

    float_t f_tW_top_minJetpt, f_tW_antitop_minJetpt, f_TTTo2L2Nu_minJetpt, f_TTWJetsToLNu_minJetpt, f_TTWJetsToQQ_minJetpt,
        f_TTZToLLNuNu_minJetpt, f_TTZToQQ_minJetpt;

    Int_t I_tW_top_disJet_multiplicity, I_tW_antitop_disJet_multiplicity, I_TTTo2L2Nu_disJet_multiplicity, I_TTWJetsToLNu_disJet_multiplicity, I_TTWJetsToQQ_disJet_multiplicity,
        I_TTZToLLNuNu_disJet_multiplicity, I_TTZToQQ_disJet_multiplicity;

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
    T_event->SetBranchAddress("I_nThinJets", &I_tW_top_nThinJets);
    T_event->SetBranchAddress("I_minJetflavor", &I_tW_top_minJetflavor);
    T_event->SetBranchAddress("f_minalphaJetpt", &f_tW_top_minJetpt);
    T_event->SetBranchAddress("I_disJet_multiplicity", &I_tW_top_disJet_multiplicity);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (I_tW_top_nThinJets < 2)
            continue;
        if (I_tW_top_minJetflavor == 4 || I_tW_top_minJetflavor == 5)
        {
            h_tW_top_Met_multiplicity->Fill(f_tW_top_met, I_tW_top_disJet_multiplicity, f_tW_antitop_weight * ST_tW_antitopWeight);
            h_tW_top_Met_minJetPt->Fill(f_tW_top_met, f_tW_top_minJetpt, f_tW_antitop_weight * ST_tW_antitopWeight);
        }
    }

    TTree *T_event1;
    Top_tW_antitop->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_tW_antitop_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_tW_antitop_met);
    T_event1->SetBranchAddress("I_weight", &f_tW_antitop_weight);
    T_event1->SetBranchAddress("I_nThinJets", &I_tW_antitop_nThinJets);
    T_event1->SetBranchAddress("I_minJetflavor", &I_tW_antitop_minJetflavor);
    T_event1->SetBranchAddress("f_minalphaJetpt", &f_tW_antitop_minJetpt);
    T_event1->SetBranchAddress("I_disJet_multiplicity", &I_tW_antitop_disJet_multiplicity);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (I_tW_antitop_nThinJets < 2)
            continue;
        if (I_tW_antitop_minJetflavor == 4 || I_tW_antitop_minJetflavor == 5)
        {
            h_tW_antitop_Met_multiplicity->Fill(f_tW_antitop_met, I_tW_antitop_disJet_multiplicity, f_tW_antitop_weight * ST_tW_antitopWeight);
            h_tW_antitop_Met_minJetPt->Fill(f_tW_antitop_met, f_tW_antitop_minJetpt, f_tW_antitop_weight * ST_tW_antitopWeight);
        }
    }

    TTree *T_event2;
    Top_TTTo2L2Nu->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_TTTo2L2Nu_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_event2->SetBranchAddress("I_weight", &f_TTTo2L2Nu_weight);
    T_event2->SetBranchAddress("I_nThinJets", &I_TTTo2L2Nu_nThinJets);
    T_event2->SetBranchAddress("I_minJetflavor", &I_TTTo2L2Nu_minJetflavor);
    T_event2->SetBranchAddress("f_minalphaJetpt", &f_TTTo2L2Nu_minJetpt);
    T_event2->SetBranchAddress("I_disJet_multiplicity", &I_TTTo2L2Nu_disJet_multiplicity);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (I_TTTo2L2Nu_nThinJets < 2)
            continue;
        if (I_TTTo2L2Nu_minJetflavor == 4 || I_TTTo2L2Nu_minJetflavor == 5)
        {
            h_TTTo2L2Nu_Met_multiplicity->Fill(f_TTTo2L2Nu_met, I_TTTo2L2Nu_disJet_multiplicity, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_TTTo2L2Nu_Met_minJetPt->Fill(f_TTTo2L2Nu_met, f_TTTo2L2Nu_minJetpt, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        }
    }

    TTree *T_event3;
    Top_TTWJetsToLNu->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &f_TTWJetsToLNu_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_event3->SetBranchAddress("I_weight", &f_TTWJetsToLNu_weight);
    T_event3->SetBranchAddress("I_nThinJets", &I_TTWJetsToLNu_nThinJets);
    T_event3->SetBranchAddress("I_minJetflavor", &I_TTWJetsToLNu_minJetflavor);
    T_event3->SetBranchAddress("f_minalphaJetpt", &f_TTWJetsToLNu_minJetpt);
    T_event3->SetBranchAddress("I_disJet_multiplicity", &I_TTWJetsToLNu_disJet_multiplicity);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (I_TTWJetsToLNu_nThinJets < 2)
            continue;
        if (I_TTWJetsToLNu_minJetflavor == 4 || I_TTWJetsToLNu_minJetflavor == 5)
        {
            h_TTWJetsToLNu_Met_multiplicity->Fill(f_TTWJetsToLNu_met, I_TTWJetsToLNu_disJet_multiplicity, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_TTWJetsToLNu_Met_minJetPt->Fill(f_TTWJetsToLNu_met, f_TTWJetsToLNu_minJetpt, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        }
    }

    TTree *T_event4;
    Top_TTWJetsToQQ->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &f_TTWJetsToQQ_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_event4->SetBranchAddress("I_weight", &f_TTWJetsToQQ_weight);
    T_event4->SetBranchAddress("I_nThinJets", &I_TTWJetsToQQ_nThinJets);
    T_event4->SetBranchAddress("I_minJetflavor", &I_TTWJetsToQQ_minJetflavor);
    T_event4->SetBranchAddress("f_minalphaJetpt", &f_TTWJetsToQQ_minJetpt);
    T_event4->SetBranchAddress("I_disJet_multiplicity", &I_TTWJetsToQQ_disJet_multiplicity);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (I_TTWJetsToQQ_nThinJets < 2)
            continue;
        if (I_TTWJetsToQQ_minJetflavor == 4 || I_TTWJetsToQQ_minJetflavor == 5)
        {
            h_TTWJetsToQQ_Met_multiplicity->Fill(f_TTZToLLNuNu_met, I_TTWJetsToQQ_disJet_multiplicity, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_TTWJetsToQQ_Met_minJetPt->Fill(f_TTZToLLNuNu_met, f_TTWJetsToQQ_minJetpt, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        }
    }

    TTree *T_event5;
    Top_TTZToLLNuNu->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &f_TTZToLLNuNu_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_event5->SetBranchAddress("I_weight", &f_TTZToLLNuNu_weight);
    T_event5->SetBranchAddress("I_nThinJets", &I_TTZToLLNuNu_nThinJets);
    T_event5->SetBranchAddress("I_minJetflavor", &I_TTZToLLNuNu_minJetflavor);
    T_event5->SetBranchAddress("f_minalphaJetpt", &f_TTZToLLNuNu_minJetpt);
    T_event5->SetBranchAddress("I_disJet_multiplicity", &I_TTZToLLNuNu_disJet_multiplicity);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (I_TTZToLLNuNu_nThinJets < 2)
            continue;
        if (I_TTZToLLNuNu_minJetflavor == 4 || I_TTZToLLNuNu_minJetflavor == 5)
        {
            h_TTZToLLNuNu_Met_multiplicity->Fill(f_TTZToLLNuNu_met, I_TTZToLLNuNu_disJet_multiplicity, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_TTZToLLNuNu_Met_minJetPt->Fill(f_TTZToLLNuNu_met, f_TTZToLLNuNu_minJetpt, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        }
    }

    TTree *T_event6;
    Top_TTZToQQ->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &f_TTZToQQ_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_event6->SetBranchAddress("I_weight", &f_TTZToQQ_weight);
    T_event6->SetBranchAddress("I_nThinJets", &I_TTZToQQ_nThinJets);
    T_event6->SetBranchAddress("I_minJetflavor", &I_TTZToQQ_minJetflavor);
    T_event6->SetBranchAddress("f_minalphaJetpt", &f_TTZToQQ_minJetpt);
    T_event6->SetBranchAddress("I_disJet_multiplicity", &I_TTZToQQ_disJet_multiplicity);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (I_TTZToQQ_nThinJets < 2)
            continue;
        if (I_TTZToQQ_minJetflavor == 4 || I_TTZToQQ_minJetflavor == 5)
        {
            h_TTZToQQ_Met_multiplicity->Fill(f_TTZToQQ_met, I_TTZToQQ_disJet_multiplicity, f_TTZToQQ_weight * TTZToQQWeight);
            h_TTZToQQ_Met_minJetPt->Fill(f_TTZToQQ_met, f_TTZToQQ_minJetpt, f_TTZToQQ_weight * TTZToQQWeight);
        }
    }
    TH2F *Top_quark_Met_multiplicity = (TH2F *)h_tW_top_Met_multiplicity->Clone("Top_quark_Met_multiplicity");
    TH2F *Top_quark_Met_minJetPt = (TH2F *)h_tW_top_Met_minJetPt->Clone("Top_quark_Met_minJetPt");

    Top_quark_Met_multiplicity->Add(h_tW_antitop_Met_multiplicity);
    Top_quark_Met_multiplicity->Add(h_TTTo2L2Nu_Met_multiplicity);
    Top_quark_Met_multiplicity->Add(h_TTWJetsToLNu_Met_multiplicity);
    Top_quark_Met_multiplicity->Add(h_TTWJetsToQQ_Met_multiplicity);
    Top_quark_Met_multiplicity->Add(h_TTZToLLNuNu_Met_multiplicity);
    Top_quark_Met_multiplicity->Add(h_TTZToQQ_Met_multiplicity);

    Top_quark_Met_minJetPt->Add(h_tW_antitop_Met_minJetPt);
    Top_quark_Met_minJetPt->Add(h_TTTo2L2Nu_Met_minJetPt);
    Top_quark_Met_minJetPt->Add(h_TTWJetsToLNu_Met_minJetPt);
    Top_quark_Met_minJetPt->Add(h_TTWJetsToQQ_Met_minJetPt);
    Top_quark_Met_minJetPt->Add(h_TTZToLLNuNu_Met_minJetPt);
    Top_quark_Met_minJetPt->Add(h_TTZToQQ_Met_minJetPt);

    gStyle->SetOptStat(0);

    auto c2 = new TCanvas("c", "BPRE");

    Top_quark_Met_multiplicity->SetTitle("Met :Jet multiplicity");
    Top_quark_Met_multiplicity->GetXaxis()->SetTitle("");

    Top_quark_Met_minJetPt->SetTitle("Met :minJet Pt");
    Top_quark_Met_minJetPt->Draw("Colz1");
}