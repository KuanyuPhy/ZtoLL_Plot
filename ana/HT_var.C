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

void HT_var()
{

    // auto c1 = new TCanvas("c", "BPRE");
    TFile *DYincli = new TFile("./../../root_file/Ztoee/ee_DYincli.root");

    TFile *DYHT70 = new TFile("./../../root_file/Ztoee/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../root_file/Ztoee/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../root_file/Ztoee/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../root_file/Ztoee/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../root_file/Ztoee/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../root_file/Ztoee/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../root_file/Ztoee/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../root_file/Ztoee/ee_ht2500.root");

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));

    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("Event_Variable/h_event"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("Event_Variable/h_event"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("Event_Variable/h_event"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("Event_Variable/h_event"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("Event_Variable/h_event"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("Event_Variable/h_event"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("Event_Variable/h_event"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("Event_Variable/h_event"));

    int DYHT70_totevt = DYHT100_sumevt->Integral();
    int DYHT70_totevtIn = DYHT100_sumevt->Integral();
    //cout <<"DYHT70_totevt Intergral = "<<DYHT70_totevtIn<<endl;
    //cout <<"DYHT70_totevt GetEntries = "<<DYHT70_totevt<<endl;
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

    // DYHT
    TH1F *h_ht0_aphmin = new TH1F("h_ht0_aphmin", "", 24, 0, 1.2);
    h_ht0_aphmin->Sumw2();

    TH1F *h_ht70_aphmin = new TH1F("h_ht70_aphmin", "", 24, 0, 1.2);
    h_ht70_aphmin->Sumw2();

    TH1F *h_ht100_aphmin = new TH1F("h_ht100_aphmin", "", 24, 0, 1.2);
    h_ht100_aphmin->Sumw2();

    TH1F *h_ht200_aphmin = new TH1F("h_ht200_aphmin", "", 24, 0, 1.2);
    h_ht200_aphmin->Sumw2();

    TH1F *h_ht400_aphmin = new TH1F("h_ht400_aphmin", "", 24, 0, 1.2);
    h_ht400_aphmin->Sumw2();

    TH1F *h_ht600_aphmin = new TH1F("h_ht600_aphmin", "", 24, 0, 1.2);
    h_ht600_aphmin->Sumw2();

    TH1F *h_ht800_aphmin = new TH1F("h_ht800_aphmin", "", 24, 0, 1.2);
    h_ht800_aphmin->Sumw2();

    TH1F *h_ht1200_aphmin = new TH1F("h_ht1200_aphmin", "", 24, 0, 1.2);
    h_ht1200_aphmin->Sumw2();

    TH1F *h_ht2500_aphmin = new TH1F("h_ht2500_aphmin", "", 24, 0, 1.2);
    h_ht2500_aphmin->Sumw2();

    // int nbins = 10;

    // 20, 0, 800

    // DYHT
    TH1F *h_ht0_met = new TH1F("h_ht0_met", "", 20, 0, 800);
    h_ht0_met->Sumw2();

    TH1F *h_ht70_met = new TH1F("h_ht70_met", "", 20, 0, 800);
    h_ht70_met->Sumw2();

    TH1F *h_ht100_met = new TH1F("h_ht100_met", "", 20, 0, 800);
    h_ht100_met->Sumw2();

    TH1F *h_ht200_met = new TH1F("h_ht200_met", "", 20, 0, 800);
    h_ht200_met->Sumw2();

    TH1F *h_ht400_met = new TH1F("h_ht400_met", "", 20, 0, 800);
    h_ht400_met->Sumw2();

    TH1F *h_ht600_met = new TH1F("h_ht600_met", "", 20, 0, 800);
    h_ht600_met->Sumw2();

    TH1F *h_ht800_met = new TH1F("h_ht800_met", "", 20, 0, 800);
    h_ht800_met->Sumw2();

    TH1F *h_ht1200_met = new TH1F("h_ht1200_met", "", 20, 0, 800);
    h_ht1200_met->Sumw2();

    TH1F *h_ht2500_met = new TH1F("h_ht2500_met", "", 20, 0, 800);
    h_ht2500_met->Sumw2();

    float_t HT;

    Double_t f_ht70_alphamin, f_ht100_alphamin, f_ht200_alphamin, f_ht400_alphamin,
        f_ht600_alphamin, f_ht800_alphamin, f_ht1200_alphamin, f_ht2500_alphamin;
    float_t f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;
    Int_t I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    float_t HT0met;

    Double_t HT0alphamin;
    Int_t HT0eventWeight;

    int I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets, I_ht600_nThinJets, I_ht800_nThinJets, I_ht1200_nThinJets, I_ht2500_nThinJets;

    // Define the HTWeight

    float HT0Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT0CS) / (HT0_70_event)) * 1000;
    float HT70Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT70CS) / (HT70_100_event)) * 1000;
    //cout <<"HT70Weight = " <<HT70Weight << endl;
    float HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000;
    //cout <<"HT100Weight = " <<HT100Weight << endl;
    float HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000;
    //cout <<"HT200Weight = " <<HT200Weight << endl;
    float HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000;
    //cout <<"HT400Weight = " <<HT400Weight << endl;
    float HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000;
    //cout <<"HT600Weight = " <<HT600Weight << endl;
    float HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000;
    //cout <<"HT800Weight = " <<HT800Weight << endl;
    float HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000;
    //cout <<"HT1200Weight = " <<HT1200Weight << endl;
    float HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000;
    //cout <<"HT2500Weight = " <<HT2500Weight << endl;

    //float HT0Weight =(GlobalConstants::HT0CS);
    //float HT70Weight = (GlobalConstants::HT70CS);
    //float HT100Weight = (GlobalConstants::HT100CS);
    //float HT200Weight = (GlobalConstants::HT200CS);
    //float HT400Weight = (GlobalConstants::HT400CS);
    //float HT600Weight = (GlobalConstants::HT600CS);
    //float HT800Weight = (GlobalConstants::HT800CS);
    //float HT1200Weight = (GlobalConstants::HT1200CS);
    //float HT2500Weight = (GlobalConstants::HT2500CS);

    TTree *T_event;
    DYincli->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &HT0eventWeight);
    T_event->SetBranchAddress("f_alphamin", &HT0alphamin);
    T_event->SetBranchAddress("f_Met", &HT0met);
    T_event->SetBranchAddress("f_HT", &HT);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (HT < 70)
        {
            h_ht0_aphmin->Fill(HT0alphamin, HT0eventWeight * HT0Weight);
            h_ht0_met->Fill(HT0met, HT0eventWeight * HT0Weight);
        }
        else if (HT > 70 && HT < 100)
        {
            h_ht70_aphmin->Fill(HT0alphamin, HT0eventWeight * HT70Weight);
            h_ht70_met->Fill(HT0met, HT0eventWeight * HT70Weight);
        }
        else if (HT > 100 && HT < 200)
        {
            h_ht100_aphmin->Fill(HT0alphamin, HT0eventWeight * HT100Weight);
            h_ht100_met->Fill(HT0met, HT0eventWeight * HT100Weight);
        }
        else if (HT > 200 && HT < 400)
        {
            h_ht200_aphmin->Fill(HT0alphamin, HT0eventWeight * HT200Weight);
            h_ht200_met->Fill(HT0met, HT0eventWeight * HT200Weight);
        }
        else if (HT > 400 && HT < 600)
        {
            h_ht400_aphmin->Fill(HT0alphamin, HT0eventWeight * HT400Weight);
            h_ht400_met->Fill(HT0met, HT0eventWeight * HT400Weight);
        }
        else if (HT > 600 && HT < 800)
        {
            h_ht600_aphmin->Fill(HT0alphamin, HT0eventWeight * HT600Weight);
            h_ht600_met->Fill(HT0met, HT0eventWeight * HT600Weight);
        }
        else if (HT > 800 && HT < 1200)
        {
            h_ht800_aphmin->Fill(HT0alphamin, HT0eventWeight * HT800Weight);
            h_ht800_met->Fill(HT0met, HT0eventWeight * HT800Weight);
        }
        else if (HT > 1200 && HT < 2500)
        {
            h_ht1200_aphmin->Fill(HT0alphamin, HT0eventWeight * HT1200Weight);
            h_ht1200_met->Fill(HT0met, HT0eventWeight * HT1200Weight);
        }
        else if (HT > 2500)
        {
            h_ht2500_aphmin->Fill(HT0alphamin, HT0eventWeight * HT2500Weight);
            h_ht2500_met->Fill(HT0met, HT0eventWeight * HT2500Weight);
        }
    }

    TTree *T_event1;
    DYHT100->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_ht100_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_ht100_Met);
    T_event1->SetBranchAddress("I_weight", &I_ht100_weight);
    T_event1->SetBranchAddress("I_nThinJets", &I_ht100_nThinJets);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        h_ht100_aphmin->Fill(f_ht100_alphamin, I_ht100_weight * HT100Weight);
        h_ht100_met->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
    }

    TTree *T_event2;
    DYHT200->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_ht200_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_ht200_Met);
    T_event2->SetBranchAddress("I_weight", &I_ht200_weight);
    T_event2->SetBranchAddress("I_nThinJets", &I_ht200_nThinJets);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        h_ht200_aphmin->Fill(f_ht200_alphamin, I_ht200_weight * HT200Weight);
        h_ht200_met->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
    }

    TTree *T_event3;
    DYHT400->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &f_ht400_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_ht400_Met);
    T_event3->SetBranchAddress("I_weight", &I_ht400_weight);
    T_event3->SetBranchAddress("I_nThinJets", &I_ht400_nThinJets);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        h_ht400_aphmin->Fill(f_ht400_alphamin, I_ht400_weight * HT400Weight);
        h_ht400_met->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
    }

    TTree *T_event4;
    DYHT600->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &f_ht600_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_ht600_Met);
    T_event4->SetBranchAddress("I_weight", &I_ht600_weight);
    T_event4->SetBranchAddress("I_nThinJets", &I_ht600_nThinJets);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        h_ht600_aphmin->Fill(f_ht600_alphamin, I_ht600_weight * HT600Weight);
        h_ht600_met->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
    }

    TTree *T_event5;
    DYHT800->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &f_ht800_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_ht800_Met);
    T_event5->SetBranchAddress("I_weight", &I_ht800_weight);
    T_event5->SetBranchAddress("I_nThinJets", &I_ht800_nThinJets);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        h_ht800_aphmin->Fill(f_ht800_alphamin, I_ht800_weight * HT800Weight);
        h_ht800_met->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
    }

    TTree *T_event6;
    DYHT1200->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &f_ht1200_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_ht1200_Met);
    T_event6->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_event6->SetBranchAddress("I_nThinJets", &I_ht1200_nThinJets);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        h_ht1200_aphmin->Fill(f_ht1200_alphamin, I_ht1200_weight * HT1200Weight);
        h_ht1200_met->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
    }

    TTree *T_event7;
    DYHT2500->GetObject("T_event", T_event7);
    T_event7->SetBranchAddress("f_alphamin", &f_ht2500_alphamin);
    T_event7->SetBranchAddress("f_Met", &f_ht2500_Met);
    T_event7->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_event7->SetBranchAddress("I_nThinJets", &I_ht2500_nThinJets);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        h_ht2500_aphmin->Fill(f_ht2500_alphamin, I_ht2500_weight * HT2500Weight);
        h_ht2500_met->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
    }

    h_ht0_aphmin->Add(h_ht70_aphmin);
    h_ht0_aphmin->Add(h_ht100_aphmin);
    h_ht0_aphmin->Add(h_ht200_aphmin);
    h_ht0_aphmin->Add(h_ht400_aphmin);
    h_ht0_aphmin->Add(h_ht600_aphmin);
    h_ht0_aphmin->Add(h_ht800_aphmin);
    h_ht0_aphmin->Add(h_ht1200_aphmin);
    h_ht0_aphmin->Add(h_ht2500_aphmin);

    h_ht0_met->Add(h_ht70_met);
    h_ht0_met->Add(h_ht100_met);
    h_ht0_met->Add(h_ht200_met);
    h_ht0_met->Add(h_ht400_met);
    h_ht0_met->Add(h_ht600_met);
    h_ht0_met->Add(h_ht800_met);
    h_ht0_met->Add(h_ht1200_met);
    h_ht0_met->Add(h_ht2500_met);

    //h_ht0_aphmin->Draw();

    TFile *outFile = new TFile("./../../root_file/Ztoee/DYHT_All.root", "RECREATE");
    outFile->cd();

    h_ht0_aphmin->Write();
    h_ht0_met->Write();

    outFile->Close();
    
}