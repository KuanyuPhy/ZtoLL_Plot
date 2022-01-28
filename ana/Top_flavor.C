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
#include "setNCUStyle.C"
using namespace RooFit;

void Top_flavor()
{
    // setNCUStyle(true);
    //--------------
    //  Input Files
    //--------------
    TFile *Top_TTTo2L2Nu = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
    TFile *Top_TTWJetsToLNu = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQ = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToLLNuNu = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_TTZToQQ = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_tW_antitop = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_top = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

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

    Int_t I_tW_top_Jethadronflavor, I_tW_antitop_Jethadronflavor, I_TTTo2L2Nu_Jethadronflavor, I_TTWJetsToLNu_Jethadronflavor, I_TTWJetsToQQ_Jethadronflavor,
        I_TTZToLLNuNu_Jethadronflavor, I_TTZToQQ_Jethadronflavor;

    Int_t I_tW_top_Jetpartonflavor, I_tW_antitop_Jetpartonflavor, I_TTTo2L2Nu_Jetpartonflavor, I_TTWJetsToLNu_Jetpartonflavor, I_TTWJetsToQQ_Jetpartonflavor,
        I_TTZToLLNuNu_Jetpartonflavor, I_TTZToQQ_Jetpartonflavor;
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

    //--------------------
    // Create Histrogram
    //--------------------

    TH1F *h_tW_top_light_partonflavor = new TH1F("h_tW_top_light_partonflavor", "", 44, -22, 22);
    h_tW_top_light_partonflavor->Sumw2();

    TH1F *h_tW_antitop_light_partonflavor = new TH1F("h_tW_antitop_light_partonflavor", "", 44, -22, 22);
    h_tW_antitop_light_partonflavor->Sumw2();

    TH1F *h_TTTo2L2Nu_light_partonflavor = new TH1F("h_TTTo2L2Nu_light_partonflavor", "", 44, -22, 22);
    h_TTTo2L2Nu_light_partonflavor->Sumw2();

    TH1F *h_TTWJetsToLNu_light_partonflavor = new TH1F("h_TTWJetsToLNu_light_partonflavor", "", 44, -22, 22);
    h_TTWJetsToLNu_light_partonflavor->Sumw2();

    TH1F *h_TWJetsToQQ_light_partonflavor = new TH1F("h_TWJetsToQQ_light_partonflavor", "", 44, -22, 22);
    h_TWJetsToQQ_light_partonflavor->Sumw2();

    TH1F *h_TTZToLLNuNu_light_partonflavor = new TH1F("h_TTZToLLNuNu_light_partonflavor", "", 44, -22, 22);
    h_TTZToLLNuNu_light_partonflavor->Sumw2();

    TH1F *h_TTZToQQ_light_partonflavor = new TH1F("h_TTZToQQ_light_partonflavor", "", 44, -22, 22);
    h_TTZToQQ_light_partonflavor->Sumw2();

    TH1F *h_tW_top_heavy_partonflavor = new TH1F("h_tW_top_heavy_partonflavor", "", 44, -22, 22);
    h_tW_top_heavy_partonflavor->Sumw2();

    TH1F *h_tW_antitop_heavy_partonflavor = new TH1F("h_tW_antitop_heavy_partonflavor", "", 44, -22, 22);
    h_tW_antitop_heavy_partonflavor->Sumw2();

    TH1F *h_TTTo2L2Nu_heavy_partonflavor = new TH1F("h_TTTo2L2Nu_heavy_partonflavor", "", 44, -22, 22);
    h_TTTo2L2Nu_heavy_partonflavor->Sumw2();

    TH1F *h_TTWJetsToLNu_heavy_partonflavor = new TH1F("h_TTWJetsToLNu_heavy_partonflavor", "", 44, -22, 22);
    h_TTWJetsToLNu_heavy_partonflavor->Sumw2();

    TH1F *h_TWJetsToQQ_heavy_partonflavor = new TH1F("h_TWJetsToQQ_heavy_partonflavor", "", 44, -22, 22);
    h_TWJetsToQQ_heavy_partonflavor->Sumw2();

    TH1F *h_TTZToLLNuNu_heavy_partonflavor = new TH1F("h_TTZToLLNuNu_heavy_partonflavor", "", 44, -22, 22);
    h_TTZToLLNuNu_heavy_partonflavor->Sumw2();

    TH1F *h_TTZToQQ_heavy_partonflavor = new TH1F("h_TTZToQQ_heavy_partonflavor", "", 44, -22, 22);
    h_TTZToQQ_heavy_partonflavor->Sumw2();

    TTree *T_event;
    Top_tW_top->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &f_tW_top_weight);
    T_event->SetBranchAddress("f_alphamin", &f_tW_top_alphamin);
    T_event->SetBranchAddress("f_Met", &f_tW_top_met);
    T_event->SetBranchAddress("I_nThinJets", &I_tW_top_nThinJets);
    T_event->SetBranchAddress("f_minalphaJetpt", &f_tW_top_minJetpt);
    T_event->SetBranchAddress("I_disJet_multiplicity", &I_tW_top_disJet_multiplicity);
    T_event->SetBranchAddress("I_minJethadronflavor", &I_tW_top_Jethadronflavor);
    T_event->SetBranchAddress("I_minJetpartonflavor", &I_tW_top_Jetpartonflavor);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (I_tW_top_nThinJets < 2)
            continue;
        if (I_tW_top_Jethadronflavor == 4 || I_tW_top_Jethadronflavor == 5)
        {
            h_tW_top_heavy_partonflavor->Fill(I_tW_top_Jetpartonflavor, f_tW_top_weight * ST_tW_topWeight);
        }
        else if (I_tW_top_Jethadronflavor == 0)
        {
            h_tW_top_light_partonflavor->Fill(I_tW_top_Jetpartonflavor, f_tW_top_weight * ST_tW_topWeight);
        }
    }

    TTree *T_event1;
    Top_tW_antitop->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_tW_antitop_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_tW_antitop_met);
    T_event1->SetBranchAddress("I_weight", &f_tW_antitop_weight);
    T_event1->SetBranchAddress("I_nThinJets", &I_tW_antitop_nThinJets);
    T_event1->SetBranchAddress("f_minalphaJetpt", &f_tW_antitop_minJetpt);
    T_event1->SetBranchAddress("I_disJet_multiplicity", &I_tW_antitop_disJet_multiplicity);
    T_event1->SetBranchAddress("I_minJethadronflavor", &I_tW_antitop_Jethadronflavor);
    T_event1->SetBranchAddress("I_minJetpartonflavor", &I_tW_antitop_Jetpartonflavor);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (I_tW_antitop_nThinJets < 2)
            continue;
        if (I_tW_antitop_Jethadronflavor == 4 || I_tW_antitop_Jethadronflavor == 5)
        {
            h_tW_antitop_heavy_partonflavor->Fill(I_tW_antitop_Jetpartonflavor, f_tW_antitop_weight * ST_tW_antitopWeight);
        }
        else if (I_tW_antitop_Jethadronflavor == 0)
        {
            h_tW_antitop_light_partonflavor->Fill(I_tW_antitop_Jetpartonflavor, f_tW_antitop_weight * ST_tW_antitopWeight);
        }
    }

    TTree *T_event2;
    Top_TTTo2L2Nu->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_TTTo2L2Nu_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_event2->SetBranchAddress("I_weight", &f_TTTo2L2Nu_weight);
    T_event2->SetBranchAddress("I_nThinJets", &I_TTTo2L2Nu_nThinJets);
    T_event2->SetBranchAddress("f_minalphaJetpt", &f_TTTo2L2Nu_minJetpt);
    T_event2->SetBranchAddress("I_disJet_multiplicity", &I_TTTo2L2Nu_disJet_multiplicity);
    T_event2->SetBranchAddress("I_minJethadronflavor", &I_TTTo2L2Nu_Jethadronflavor);
    T_event2->SetBranchAddress("I_minJetpartonflavor", &I_TTTo2L2Nu_Jetpartonflavor);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (I_TTTo2L2Nu_nThinJets < 2)
            continue;
        if (I_TTTo2L2Nu_Jethadronflavor == 4 || I_TTTo2L2Nu_Jethadronflavor == 5)
        {
            h_TTTo2L2Nu_heavy_partonflavor->Fill(I_TTTo2L2Nu_Jetpartonflavor, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        }
        else if (I_TTTo2L2Nu_Jethadronflavor == 0)
        {
            h_TTTo2L2Nu_light_partonflavor->Fill(I_TTTo2L2Nu_Jetpartonflavor, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        }
    }

    TTree *T_event3;
    Top_TTWJetsToLNu->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &f_TTWJetsToLNu_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_event3->SetBranchAddress("I_weight", &f_TTWJetsToLNu_weight);
    T_event3->SetBranchAddress("I_nThinJets", &I_TTWJetsToLNu_nThinJets);
    T_event3->SetBranchAddress("f_minalphaJetpt", &f_TTWJetsToLNu_minJetpt);
    T_event3->SetBranchAddress("I_disJet_multiplicity", &I_TTWJetsToLNu_disJet_multiplicity);
    T_event3->SetBranchAddress("I_minJethadronflavor", &I_TTWJetsToLNu_Jethadronflavor);
    T_event3->SetBranchAddress("I_minJetpartonflavor", &I_TTWJetsToLNu_Jetpartonflavor);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (I_TTWJetsToLNu_nThinJets < 2)
            continue;
        if (I_TTWJetsToLNu_Jethadronflavor == 4 || I_TTWJetsToLNu_Jethadronflavor == 5)
        {
            h_TTWJetsToLNu_heavy_partonflavor->Fill(I_TTWJetsToLNu_Jetpartonflavor, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        }
        else if (I_TTWJetsToLNu_Jethadronflavor == 0)
        {
            h_TTWJetsToLNu_light_partonflavor->Fill(I_TTWJetsToLNu_Jetpartonflavor, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        }
    }

    TTree *T_event4;
    Top_TTWJetsToQQ->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &f_TTWJetsToQQ_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_event4->SetBranchAddress("I_weight", &f_TTWJetsToQQ_weight);
    T_event4->SetBranchAddress("I_nThinJets", &I_TTWJetsToQQ_nThinJets);
    T_event4->SetBranchAddress("f_minalphaJetpt", &f_TTWJetsToQQ_minJetpt);
    T_event4->SetBranchAddress("I_disJet_multiplicity", &I_TTWJetsToQQ_disJet_multiplicity);
    T_event4->SetBranchAddress("I_minJethadronflavor", &I_TTWJetsToQQ_Jethadronflavor);
    T_event4->SetBranchAddress("I_minJetpartonflavor", &I_TTWJetsToQQ_Jetpartonflavor);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (I_TTWJetsToQQ_nThinJets < 2)
            continue;
        if (I_TTWJetsToQQ_Jethadronflavor == 4 || I_TTWJetsToQQ_Jethadronflavor == 5)
        {
            h_TWJetsToQQ_heavy_partonflavor->Fill(I_TTWJetsToQQ_Jetpartonflavor, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        }
        else if (I_TTWJetsToQQ_Jethadronflavor == 0)
        {
            h_TWJetsToQQ_light_partonflavor->Fill(I_TTWJetsToQQ_Jetpartonflavor, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        }
    }

    TTree *T_event5;
    Top_TTZToLLNuNu->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &f_TTZToLLNuNu_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_event5->SetBranchAddress("I_weight", &f_TTZToLLNuNu_weight);
    T_event5->SetBranchAddress("I_nThinJets", &I_TTZToLLNuNu_nThinJets);
    T_event5->SetBranchAddress("f_minalphaJetpt", &f_TTZToLLNuNu_minJetpt);
    T_event5->SetBranchAddress("I_disJet_multiplicity", &I_TTZToLLNuNu_disJet_multiplicity);
    T_event5->SetBranchAddress("I_minJethadronflavor", &I_TTZToLLNuNu_Jethadronflavor);
    T_event5->SetBranchAddress("I_minJetpartonflavor", &I_TTZToLLNuNu_Jetpartonflavor);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (I_TTZToLLNuNu_nThinJets < 2)
            continue;
        if (I_TTZToLLNuNu_Jethadronflavor == 4 || I_TTZToLLNuNu_Jethadronflavor == 5)
        {
            h_TTZToLLNuNu_heavy_partonflavor->Fill(I_TTZToLLNuNu_Jetpartonflavor, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        }
        else if (I_TTZToLLNuNu_Jethadronflavor == 0)
        {
            h_TTZToLLNuNu_light_partonflavor->Fill(I_TTZToLLNuNu_Jetpartonflavor, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        }
    }

    TTree *T_event6;
    Top_TTZToQQ->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &f_TTZToQQ_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_event6->SetBranchAddress("I_weight", &f_TTZToQQ_weight);
    T_event6->SetBranchAddress("I_nThinJets", &I_TTZToQQ_nThinJets);
    T_event6->SetBranchAddress("f_minalphaJetpt", &f_TTZToQQ_minJetpt);
    T_event6->SetBranchAddress("I_disJet_multiplicity", &I_TTZToQQ_disJet_multiplicity);
    T_event6->SetBranchAddress("I_minJethadronflavor", &I_TTZToQQ_Jethadronflavor);
    T_event6->SetBranchAddress("I_minJetpartonflavor", &I_TTZToQQ_Jetpartonflavor);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (I_TTZToQQ_nThinJets < 2)
            continue;
        if (I_TTZToQQ_Jethadronflavor == 4 || I_TTZToQQ_Jethadronflavor == 5)
        {
            h_TTZToQQ_heavy_partonflavor->Fill(I_TTZToQQ_Jetpartonflavor, f_TTZToQQ_weight * TTZToQQWeight);
        }
        else if (I_TTZToQQ_Jethadronflavor == 0)
        {
            h_TTZToQQ_light_partonflavor->Fill(I_TTZToQQ_Jetpartonflavor, f_TTZToQQ_weight * TTZToQQWeight);
        }
    }
    h_tW_top_heavy_partonflavor->Add(h_tW_antitop_heavy_partonflavor);
    h_tW_top_heavy_partonflavor->Add(h_TTWJetsToLNu_heavy_partonflavor);
    h_tW_top_heavy_partonflavor->Add(h_TWJetsToQQ_heavy_partonflavor);
    h_tW_top_heavy_partonflavor->Add(h_TTZToLLNuNu_heavy_partonflavor);
    h_tW_top_heavy_partonflavor->Add(h_TTZToQQ_heavy_partonflavor);

    h_tW_top_light_partonflavor->Add(h_tW_antitop_light_partonflavor);
    h_tW_top_light_partonflavor->Add(h_TTTo2L2Nu_light_partonflavor);
    h_tW_top_light_partonflavor->Add(h_TTWJetsToLNu_light_partonflavor);
    h_tW_top_light_partonflavor->Add(h_TWJetsToQQ_light_partonflavor);
    h_tW_top_light_partonflavor->Add(h_TTZToLLNuNu_light_partonflavor);
    h_tW_top_light_partonflavor->Add(h_TTZToQQ_light_partonflavor);
    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(2, 1);
    c1->cd(1);
    h_tW_top_light_partonflavor->SetLineWidth(2);
    h_tW_top_light_partonflavor->SetTitle("light_partonflavor");    
    h_tW_top_light_partonflavor->GetYaxis()->SetTitle("N Events");
    h_tW_top_light_partonflavor->Draw("hist");
    c1->cd(2);
    h_tW_top_heavy_partonflavor->SetLineWidth(2);
    h_tW_top_heavy_partonflavor->SetTitle("heavy_partonflavor");
    h_tW_top_heavy_partonflavor->GetYaxis()->SetTitle("N Events");
    h_tW_top_heavy_partonflavor->Draw("hist");
}

    
    

