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
void quick_flavor()
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

    TH2F *h_ht0_Met_alphamin = new TH2F("h_ht0_Met_alphamin", "", 20, 0, 800, 24, 0, 1.2);
    TH2F *h_ht70_Met_alphamin = new TH2F("h_ht70_Met_alphamin", "", 20, 0, 800, 24, 0, 1.2);
    TH2F *h_ht100_Met_alphamin = new TH2F("h_ht100_Met_alphamin", "", 20, 0, 800, 24, 0, 1.2);
    TH2F *h_ht200_Met_alphamin = new TH2F("h_ht200_Met_alphamin", "", 20, 0, 800, 24, 0, 1.2);
    TH2F *h_ht400_Met_alphamin = new TH2F("h_ht400_Met_alphamin", "", 20, 0, 800, 24, 0, 1.2);
    TH2F *h_ht600_Met_alphamin = new TH2F("h_ht600_Met_alphamin", "", 20, 0, 800, 24, 0, 1.2);
    TH2F *h_ht800_Met_alphamin = new TH2F("h_ht800_Met_alphamin", "", 20, 0, 800, 24, 0, 1.2);
    TH2F *h_ht1200_Met_alphamin = new TH2F("h_ht1200_Met_alphamin", "", 20, 0, 800, 24, 0, 1.2);
    TH2F *h_ht2500_Met_alphamin = new TH2F("h_ht2500_Met_alphamin", "", 20, 0, 800, 24, 0, 1.2);

    TH1F *h_ht0_minJetFlavor = new TH1F("h_ht0_minJetFlavor", "minJetFlavor", 6, 0, 6);
    TH1F *h_ht70_minJetFlavor = new TH1F("h_ht70_minJetFlavor", "", 6, 0, 6);
    TH1F *h_ht100_minJetFlavor = new TH1F("h_ht100_minJetFlavor", "", 6, 0, 6);
    TH1F *h_ht200_minJetFlavor = new TH1F("h_ht200_minJetFlavor", "", 6, 0, 6);
    TH1F *h_ht400_minJetFlavor = new TH1F("h_ht400_minJetFlavor", "", 6, 0, 6);
    TH1F *h_ht600_minJetFlavor = new TH1F("h_ht600_minJetFlavor", "", 6, 0, 6);
    TH1F *h_ht800_minJetFlavor = new TH1F("h_ht800_minJetFlavor", "", 6, 0, 6);
    TH1F *h_ht1200_minJetFlavor = new TH1F("h_ht1200_minJetFlavor", "", 6, 0, 6);
    TH1F *h_ht2500_minJetFlavor = new TH1F("h_ht2500_minJetFlavor", "", 6, 0, 6);

    setNCUStyle(true);

    TFile *Mx2_1 = new TFile("./../../root_file/Ztoee/Mx2_1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/Ztoee/Mx2_50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/Ztoee/Mx2_150.root");

    TFile *DYincli = new TFile("./../../root_file/Ztoee/ee_DYincli.root");

    TFile *DYHT70 = new TFile("./../../root_file/Ztoee/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../root_file/Ztoee/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../root_file/Ztoee/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../root_file/Ztoee/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../root_file/Ztoee/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../root_file/Ztoee/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../root_file/Ztoee/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../root_file/Ztoee/ee_ht2500.root");

    TFile *Top = new TFile("./../../root_file/Ztoee/Top_All.root");

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));

    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("Event_Variable/h_event"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("Event_Variable/h_event"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("Event_Variable/h_event"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("Event_Variable/h_event"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("Event_Variable/h_event"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("Event_Variable/h_event"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("Event_Variable/h_event"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("Event_Variable/h_event"));

    TH1F *Top_quark_minJetFlavor = ((TH1F *)Top->Get("Top_quark_minJetFlavor"));


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

    float HT0Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT0CS) / (HT0_70_event)) * 1000;
    float HT70Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT70CS) / (HT70_100_event)) * 1000;
    float HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000;
    float HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000;
    float HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000;
    float HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000;
    float HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000;
    float HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000;
    float HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000;

    float_t HT;

    Double_t f_ht0_alphamin, f_ht70_alphamin, f_ht100_alphamin, f_ht200_alphamin, f_ht400_alphamin,
        f_ht600_alphamin, f_ht800_alphamin, f_ht1200_alphamin, f_ht2500_alphamin;
    float_t f_ht0_Met, f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;

    Int_t I_ht0_nThinJets, I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets, I_ht600_nThinJets,
        I_ht800_nThinJets, I_ht1200_nThinJets, I_ht2500_nThinJets;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    float_t f_ht0_leadJeteta, f_ht70_leadJeteta, f_ht100_leadJeteta, f_ht200_leadJeteta, f_ht400_leadJeteta,
        f_ht600_leadJeteta, f_ht800_leadJeteta, f_ht1200_leadJeteta, f_ht2500_leadJeteta;

    float_t f_ht0_leadJetpt, f_ht70_leadJetpt, f_ht100_leadJetpt, f_ht200_leadJetpt, f_ht400_leadJetpt,
        f_ht600_leadJetpt, f_ht800_leadJetpt, f_ht1200_leadJetpt, f_ht2500_leadJetpt;

    float_t f_ht0_minJeteta, f_ht70_minJeteta, f_ht100_minJeteta, f_ht200_minJeteta, f_ht400_minJeteta,
        f_ht600_minJeteta, f_ht800_minJeteta, f_ht1200_minJeteta, f_ht2500_minJeteta;

    float_t f_ht0_minJetpt, f_ht70_minJetpt, f_ht100_minJetpt, f_ht200_minJetpt, f_ht400_minJetpt,
        f_ht600_minJetpt, f_ht800_minJetpt, f_ht1200_minJetpt, f_ht2500_minJetpt;

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;
    Int_t I_Mx1_nThinJets, I_Mx50_nThinJets, I_Mx150_nThinJets;
    float_t f_Mx1_jeteta, f_Mx50_jeteta, f_Mx150_jeteta;
    float_t f_Mx1_Met, f_Mx50_Met, f_Mx150_Met;
    Double_t d_Mx1_alphamin, d_Mx50_alphamin, d_Mx150_alphamin;
    Int_t I_Mx1_leadJetflavor, I_Mx50_leadJetflavor, I_Mx150_leadJetflavor;
    Int_t I_Mx1_minJetflavor, I_Mx50_minJetflavor, I_Mx150_minJetflavor;

    Int_t I_ht0_leadJetflavor, I_ht70_leadJetflavor, I_ht100_leadJetflavor, I_ht200_leadJetflavor, I_ht400_leadJetflavor,
        I_ht600_leadJetflavor, I_ht800_leadJetflavor, I_ht1200_leadJetflavor, I_ht2500_leadJetflavor;
    Int_t I_ht0_minJetflavor, I_ht70_minJetflavor, I_ht100_minJetflavor, I_ht200_minJetflavor, I_ht400_minJetflavor,
        I_ht600_minJetflavor, I_ht800_minJetflavor, I_ht1200_minJetflavor, I_ht2500_minJetflavor;



    float someupvalue = 0.9;
    float somelowvalue = 0.1;

    TTree *T_event;
    DYincli->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &I_ht0_weight);
    T_event->SetBranchAddress("f_alphamin", &f_ht0_alphamin);
    T_event->SetBranchAddress("f_Met", &f_ht0_Met);
    T_event->SetBranchAddress("f_HT", &HT);
    T_event->SetBranchAddress("f_leadJeteta", &f_ht0_leadJeteta);
    T_event->SetBranchAddress("f_leadJetpt", &f_ht0_leadJetpt);
    T_event->SetBranchAddress("f_minalphaJeteta", &f_ht0_minJeteta);
    T_event->SetBranchAddress("f_minalphaJetpt", &f_ht0_minJetpt);
    T_event->SetBranchAddress("I_nThinJets", &I_ht0_nThinJets);
    T_event->SetBranchAddress("I_nThinJets", &I_ht0_nThinJets);
    T_event->SetBranchAddress("I_leadJetflavor", &I_ht0_leadJetflavor);
    T_event->SetBranchAddress("I_minJetflavor", &I_ht0_minJetflavor);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (I_ht0_nThinJets < 2)
            continue;
        if (HT < 70)
        {
            h_ht0_Met_alphamin->Fill(f_ht0_Met, f_ht0_alphamin, I_ht0_weight * HT0Weight);
            h_ht0_minJetFlavor->Fill(I_ht0_minJetflavor, I_ht0_weight * HT0Weight);
        }
        else if (HT >= 70 && HT < 100)
        {
            h_ht70_Met_alphamin->Fill(f_ht0_Met, f_ht0_alphamin, I_ht0_weight * HT70Weight);
            h_ht70_minJetFlavor->Fill(I_ht0_minJetflavor, I_ht0_weight * HT70Weight);
        }
        else if (HT >= 100 && HT < 200)
        {
            h_ht100_Met_alphamin->Fill(f_ht0_Met, f_ht0_alphamin, I_ht0_weight * HT100Weight);
            h_ht100_minJetFlavor->Fill(I_ht0_minJetflavor, I_ht0_weight * HT100Weight);
        }

        else if (HT >= 200 && HT < 400)
        {
            h_ht200_Met_alphamin->Fill(f_ht0_Met, f_ht0_alphamin, I_ht0_weight * HT200Weight);
            h_ht200_minJetFlavor->Fill(I_ht0_minJetflavor, I_ht0_weight * HT200Weight);
        }
        else if (HT >= 400 && HT < 600)
        {
            h_ht400_Met_alphamin->Fill(f_ht0_Met, f_ht0_alphamin, I_ht0_weight * HT400Weight);
            h_ht400_minJetFlavor->Fill(I_ht0_minJetflavor, I_ht0_weight * HT400Weight);
        }
        else if (HT >= 600 && HT < 800)
        {
            h_ht600_Met_alphamin->Fill(f_ht0_Met, f_ht0_alphamin, I_ht0_weight * HT600Weight);
            h_ht600_minJetFlavor->Fill(I_ht0_minJetflavor, I_ht0_weight * HT600Weight);
        }
        else if (HT >= 800 && HT < 1200)
        {
            h_ht800_Met_alphamin->Fill(f_ht0_Met, f_ht0_alphamin, I_ht0_weight * HT800Weight);
            h_ht800_minJetFlavor->Fill(I_ht0_minJetflavor, I_ht0_weight * HT800Weight);
        }
        else if (HT >= 1200 && HT < 2500)
        {
            h_ht1200_Met_alphamin->Fill(f_ht0_Met, f_ht0_alphamin, I_ht0_weight * HT1200Weight);
            h_ht1200_minJetFlavor->Fill(I_ht0_minJetflavor, I_ht0_weight * HT1200Weight);
        }
        else if (HT >= 2500)
        {
            h_ht2500_Met_alphamin->Fill(f_ht0_Met, f_ht0_alphamin, I_ht0_weight * HT2500Weight);
            h_ht2500_minJetFlavor->Fill(I_ht0_minJetflavor, I_ht0_weight * HT2500Weight);
        }
    }
    TTree *T_event1;
    DYHT100->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_ht100_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_ht100_Met);
    T_event1->SetBranchAddress("I_weight", &I_ht100_weight);
    T_event1->SetBranchAddress("I_nThinJets", &I_ht100_nThinJets);
    T_event1->SetBranchAddress("f_leadJeteta", &f_ht100_leadJeteta);
    T_event1->SetBranchAddress("f_leadJetpt", &f_ht100_leadJetpt);
    T_event1->SetBranchAddress("f_minalphaJeteta", &f_ht100_minJeteta);
    T_event1->SetBranchAddress("f_minalphaJetpt", &f_ht100_minJetpt);
    T_event1->SetBranchAddress("I_nThinJets", &I_ht100_nThinJets);
    T_event1->SetBranchAddress("I_leadJetflavor", &I_ht100_leadJetflavor);
    T_event1->SetBranchAddress("I_minJetflavor", &I_ht100_minJetflavor);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (I_ht100_nThinJets < 2)
            continue;
        h_ht100_Met_alphamin->Fill(f_ht100_Met, f_ht100_alphamin, I_ht100_weight * HT100Weight);
        h_ht100_minJetFlavor->Fill(I_ht100_minJetflavor, I_ht100_weight * HT100Weight);
    }
    TTree *T_event2;
    DYHT200->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_ht200_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_ht200_Met);
    T_event2->SetBranchAddress("I_weight", &I_ht200_weight);
    T_event2->SetBranchAddress("I_nThinJets", &I_ht200_nThinJets);
    T_event2->SetBranchAddress("f_leadJeteta", &f_ht200_leadJeteta);
    T_event2->SetBranchAddress("f_leadJetpt", &f_ht200_leadJetpt);
    T_event2->SetBranchAddress("f_minalphaJeteta", &f_ht200_minJeteta);
    T_event2->SetBranchAddress("f_minalphaJetpt", &f_ht200_minJetpt);
    T_event2->SetBranchAddress("I_nThinJets", &I_ht200_nThinJets);
    T_event2->SetBranchAddress("I_leadJetflavor", &I_ht200_leadJetflavor);
    T_event2->SetBranchAddress("I_minJetflavor", &I_ht200_minJetflavor);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (I_ht200_nThinJets < 2)
            continue;
        h_ht200_Met_alphamin->Fill(f_ht200_Met, f_ht200_alphamin, I_ht200_weight * I_ht200_weight);
        h_ht200_minJetFlavor->Fill(I_ht200_minJetflavor, I_ht200_weight * HT200Weight);
    }
    TTree *T_event3;
    DYHT400->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &f_ht400_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_ht400_Met);
    T_event3->SetBranchAddress("I_weight", &I_ht400_weight);
    T_event3->SetBranchAddress("I_nThinJets", &I_ht400_nThinJets);
    T_event3->SetBranchAddress("f_leadJeteta", &f_ht400_leadJeteta);
    T_event3->SetBranchAddress("f_leadJetpt", &f_ht400_leadJetpt);
    T_event3->SetBranchAddress("f_minalphaJeteta", &f_ht400_minJeteta);
    T_event3->SetBranchAddress("f_minalphaJetpt", &f_ht400_minJetpt);
    T_event3->SetBranchAddress("I_nThinJets", &I_ht400_nThinJets);
    T_event3->SetBranchAddress("I_leadJetflavor", &I_ht400_leadJetflavor);
    T_event3->SetBranchAddress("I_minJetflavor", &I_ht400_minJetflavor);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (I_ht400_nThinJets < 2)
            continue;
        h_ht400_Met_alphamin->Fill(f_ht400_Met, f_ht400_alphamin, I_ht400_weight * HT400Weight);
        h_ht400_minJetFlavor->Fill(I_ht400_minJetflavor, I_ht400_weight * HT400Weight);
    }
    TTree *T_event4;
    DYHT600->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &f_ht600_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_ht600_Met);
    T_event4->SetBranchAddress("I_weight", &I_ht600_weight);
    T_event4->SetBranchAddress("I_nThinJets", &I_ht600_nThinJets);
    T_event4->SetBranchAddress("f_leadJeteta", &f_ht600_leadJeteta);
    T_event4->SetBranchAddress("f_leadJetpt", &f_ht600_leadJetpt);
    T_event4->SetBranchAddress("f_minalphaJeteta", &f_ht600_minJeteta);
    T_event4->SetBranchAddress("f_minalphaJetpt", &f_ht600_minJetpt);
    T_event4->SetBranchAddress("I_nThinJets", &I_ht600_nThinJets);
    T_event4->SetBranchAddress("I_leadJetflavor", &I_ht600_leadJetflavor);
    T_event4->SetBranchAddress("I_minJetflavor", &I_ht600_minJetflavor);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (I_ht600_nThinJets < 2)
            continue;
        h_ht600_Met_alphamin->Fill(f_ht600_Met, f_ht600_alphamin, I_ht600_weight * HT600Weight);
        h_ht600_minJetFlavor->Fill(I_ht600_minJetflavor, I_ht600_weight * HT600Weight);
    }
    TTree *T_event5;
    DYHT800->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &f_ht800_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_ht800_Met);
    T_event5->SetBranchAddress("I_weight", &I_ht800_weight);
    T_event5->SetBranchAddress("I_nThinJets", &I_ht800_nThinJets);
    T_event5->SetBranchAddress("f_leadJeteta", &f_ht800_leadJeteta);
    T_event5->SetBranchAddress("f_leadJetpt", &f_ht800_leadJetpt);
    T_event5->SetBranchAddress("f_minalphaJeteta", &f_ht800_minJeteta);
    T_event5->SetBranchAddress("f_minalphaJetpt", &f_ht800_minJetpt);
    T_event5->SetBranchAddress("I_nThinJets", &I_ht800_nThinJets);
    T_event5->SetBranchAddress("I_leadJetflavor", &I_ht800_leadJetflavor);
    T_event5->SetBranchAddress("I_minJetflavor", &I_ht800_minJetflavor);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (I_ht800_nThinJets < 2)
            continue;
        h_ht800_Met_alphamin->Fill(f_ht800_Met, f_ht800_alphamin, I_ht800_weight * HT800Weight);
        h_ht800_minJetFlavor->Fill(I_ht800_minJetflavor, I_ht800_weight * HT800Weight);
    }
    TTree *T_event6;
    DYHT1200->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &f_ht1200_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_ht1200_Met);
    T_event6->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_event6->SetBranchAddress("I_nThinJets", &I_ht1200_nThinJets);
    T_event6->SetBranchAddress("f_leadJeteta", &f_ht1200_leadJeteta);
    T_event6->SetBranchAddress("f_leadJetpt", &f_ht1200_leadJetpt);
    T_event6->SetBranchAddress("f_minalphaJeteta", &f_ht1200_minJeteta);
    T_event6->SetBranchAddress("f_minalphaJetpt", &f_ht1200_minJetpt);
    T_event6->SetBranchAddress("I_nThinJets", &I_ht1200_nThinJets);
    T_event6->SetBranchAddress("I_leadJetflavor", &I_ht1200_leadJetflavor);
    T_event6->SetBranchAddress("I_minJetflavor", &I_ht1200_minJetflavor);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (I_ht1200_nThinJets < 2)
            continue;
        h_ht1200_Met_alphamin->Fill(f_ht1200_Met, f_ht1200_alphamin, I_ht1200_weight * HT1200Weight);
        h_ht1200_minJetFlavor->Fill(I_ht1200_minJetflavor, I_ht1200_weight * HT1200Weight);
    }

    TTree *T_event7;
    DYHT2500->GetObject("T_event", T_event7);
    T_event7->SetBranchAddress("f_alphamin", &f_ht2500_alphamin);
    T_event7->SetBranchAddress("f_Met", &f_ht2500_Met);
    T_event7->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_event7->SetBranchAddress("I_nThinJets", &I_ht2500_nThinJets);
    T_event7->SetBranchAddress("f_leadJeteta", &f_ht2500_leadJeteta);
    T_event7->SetBranchAddress("f_leadJetpt", &f_ht2500_leadJetpt);
    T_event7->SetBranchAddress("f_minalphaJeteta", &f_ht2500_minJeteta);
    T_event7->SetBranchAddress("f_minalphaJetpt", &f_ht2500_minJetpt);
    T_event7->SetBranchAddress("I_nThinJets", &I_ht2500_nThinJets);
    T_event7->SetBranchAddress("I_leadJetflavor", &I_ht2500_leadJetflavor);
    T_event7->SetBranchAddress("I_minJetflavor", &I_ht2500_minJetflavor);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        if (I_ht2500_nThinJets < 2)
            continue;
        h_ht2500_Met_alphamin->Fill(f_ht2500_Met, f_ht2500_alphamin, I_ht2500_weight * HT2500Weight);
        h_ht2500_minJetFlavor->Fill(I_ht2500_minJetflavor, I_ht2500_weight * HT2500Weight);
    }

    h_ht0_Met_alphamin->Add(h_ht70_Met_alphamin);
    h_ht0_Met_alphamin->Add(h_ht100_Met_alphamin);
    h_ht0_Met_alphamin->Add(h_ht200_Met_alphamin);
    h_ht0_Met_alphamin->Add(h_ht400_Met_alphamin);
    h_ht0_Met_alphamin->Add(h_ht600_Met_alphamin);
    h_ht0_Met_alphamin->Add(h_ht800_Met_alphamin);
    h_ht0_Met_alphamin->Add(h_ht1200_Met_alphamin);
    h_ht0_Met_alphamin->Add(h_ht2500_Met_alphamin);

    h_ht0_minJetFlavor->Add(h_ht70_minJetFlavor);
    h_ht0_minJetFlavor->Add(h_ht100_minJetFlavor);
    h_ht0_minJetFlavor->Add(h_ht200_minJetFlavor);
    h_ht0_minJetFlavor->Add(h_ht400_minJetFlavor);
    h_ht0_minJetFlavor->Add(h_ht600_minJetFlavor);
    h_ht0_minJetFlavor->Add(h_ht800_minJetFlavor);
    h_ht0_minJetFlavor->Add(h_ht1200_minJetFlavor);
    h_ht0_minJetFlavor->Add(h_ht2500_minJetFlavor);

    gStyle->SetOptStat(0);

    auto c2 = new TCanvas("c", "BPRE");
    // c2->Divide(2, 1);
    // c2->cd(1);
    // h_ht0_Met_alphamin->SetTitle("Met : #alpha_{3D_{min}}");
    // h_ht0_Met_alphamin->GetYaxis()->SetTitle("#alpha_{3D_{min}}");
    // h_ht0_Met_alphamin->GetXaxis()->SetTitle("Met");
    // h_ht0_Met_alphamin->Draw("COLZ1");
    Top_quark_minJetFlavor->GetXaxis()->SetTitle("minJetFlavor");
    Top_quark_minJetFlavor->SetLineWidth(2);
    Top_quark_minJetFlavor->Draw("hist");
}