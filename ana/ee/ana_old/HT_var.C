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

void HT_var()
{

    setNCUStyle(true);
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

    // DYHT Met
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

    TH1F *h_ht0_met_njetcut = new TH1F("h_ht0_met_njetcut", "", 20, 0, 800);
    h_ht0_met_njetcut->Sumw2();

    TH1F *h_ht70_met_njetcut = new TH1F("h_ht70_met_njetcut", "", 20, 0, 800);
    h_ht70_met_njetcut->Sumw2();

    TH1F *h_ht100_met_njetcut = new TH1F("h_ht100_met_njetcut", "", 20, 0, 800);
    h_ht100_met_njetcut->Sumw2();

    TH1F *h_ht200_met_njetcut = new TH1F("h_ht200_met_njetcut", "", 20, 0, 800);
    h_ht200_met_njetcut->Sumw2();

    TH1F *h_ht400_met_njetcut = new TH1F("h_ht400_met_njetcut", "", 20, 0, 800);
    h_ht400_met_njetcut->Sumw2();

    TH1F *h_ht600_met_njetcut = new TH1F("h_ht600_met_njetcut", "", 20, 0, 800);
    h_ht600_met_njetcut->Sumw2();

    TH1F *h_ht800_met_njetcut = new TH1F("h_ht800_met_njetcut", "", 20, 0, 800);
    h_ht800_met_njetcut->Sumw2();

    TH1F *h_ht1200_met_njetcut = new TH1F("h_ht1200_met_njetcut", "", 20, 0, 800);
    h_ht1200_met_njetcut->Sumw2();

    TH1F *h_ht2500_met_njetcut = new TH1F("h_ht2500_met_njetcut", "", 20, 0, 800);
    h_ht2500_met_njetcut->Sumw2();

    // DY PT
    TH1F *h_ht0_leadjetpt = new TH1F("h_ht0_leadjetpt", "leading jet pt", 100, 0, 1000);
    h_ht0_leadjetpt->Sumw2();
    TH1F *h_ht70_leadjetpt = new TH1F("h_ht70_leadjetpt", "leading jet pt", 100, 0, 1000);
    h_ht70_leadjetpt->Sumw2();
    TH1F *h_ht100_leadjetpt = new TH1F("h_ht100_leadjetpt", "leading jet pt", 100, 0, 1000);
    h_ht100_leadjetpt->Sumw2();
    TH1F *h_ht200_leadjetpt = new TH1F("h_ht200_leadjetpt", "leading jet pt", 100, 0, 1000);
    h_ht200_leadjetpt->Sumw2();
    TH1F *h_ht400_leadjetpt = new TH1F("h_ht400_leadjetpt", "leading jet pt", 100, 0, 1000);
    h_ht400_leadjetpt->Sumw2();
    TH1F *h_ht600_leadjetpt = new TH1F("h_ht600_leadjetpt", "leading jet pt", 100, 0, 1000);
    h_ht600_leadjetpt->Sumw2();
    TH1F *h_ht800_leadjetpt = new TH1F("h_ht800_leadjetpt", "leading jet pt", 100, 0, 1000);
    h_ht800_leadjetpt->Sumw2();
    TH1F *h_ht1200_leadjetpt = new TH1F("h_ht1200_leadjetpt", "leading jet pt", 100, 0, 1000);
    h_ht1200_leadjetpt->Sumw2();
    TH1F *h_ht2500_leadjetpt = new TH1F("h_ht2500_leadjetpt", "leading jet pt", 100, 0, 1000);
    h_ht2500_leadjetpt->Sumw2();

    TH1F *h_ht0_minjetpt = new TH1F("h_ht0_minjetpt", "alphamin jet pt", 100, 0, 1000);
    h_ht0_minjetpt->Sumw2();
    TH1F *h_ht70_minjetpt = new TH1F("h_ht70_minjetpt", "alphamin jet pt", 100, 0, 1000);
    h_ht70_minjetpt->Sumw2();
    TH1F *h_ht100_minjetpt = new TH1F("h_ht100_minjetpt", "alphamin jet pt", 100, 0, 1000);
    h_ht100_minjetpt->Sumw2();
    TH1F *h_ht200_minjetpt = new TH1F("h_ht200_minjetpt", "alphamin jet pt", 100, 0, 1000);
    h_ht200_minjetpt->Sumw2();
    TH1F *h_ht400_minjetpt = new TH1F("h_ht400_minjetpt", "alphamin jet pt", 100, 0, 1000);
    h_ht400_minjetpt->Sumw2();
    TH1F *h_ht600_minjetpt = new TH1F("h_ht600_minjetpt", "alphamin jet pt", 100, 0, 1000);
    h_ht600_minjetpt->Sumw2();
    TH1F *h_ht800_minjetpt = new TH1F("h_ht800_minjetpt", "alphamin jet pt", 100, 0, 1000);
    h_ht800_minjetpt->Sumw2();
    TH1F *h_ht1200_minjetpt = new TH1F("h_ht1200_minjetpt", "alphamin jet pt", 100, 0, 1000);
    h_ht1200_minjetpt->Sumw2();
    TH1F *h_ht2500_minjetpt = new TH1F("h_ht2500_minjetpt", "alphamin jet pt", 100, 0, 1000);
    h_ht2500_minjetpt->Sumw2();

    // DYHT eta
    TH1F *h_ht0_leadjeteta = new TH1F("h_ht0_leadjeteta", "leading jet eta", 100, -5, 5);
    h_ht0_leadjeteta->Sumw2();
    TH1F *h_ht70_leadjeteta = new TH1F("h_ht70_leadjeteta", "leading jet eta", 100, -5, 5);
    h_ht70_leadjeteta->Sumw2();
    TH1F *h_ht100_leadjeteta = new TH1F("h_ht100_leadjeteta", "leading jet eta", 100, -5, 5);
    h_ht100_leadjeteta->Sumw2();
    TH1F *h_ht200_leadjeteta = new TH1F("h_ht200_leadjeteta", "leading jet eta", 100, -5, 5);
    h_ht200_leadjeteta->Sumw2();
    TH1F *h_ht400_leadjeteta = new TH1F("h_ht400_leadjeteta", "leading jet eta", 100, -5, 5);
    h_ht400_leadjeteta->Sumw2();
    TH1F *h_ht600_leadjeteta = new TH1F("h_ht600_leadjeteta", "leading jet eta", 100, -5, 5);
    h_ht600_leadjeteta->Sumw2();
    TH1F *h_ht800_leadjeteta = new TH1F("h_ht800_leadjeteta", "leading jet eta", 100, -5, 5);
    h_ht800_leadjeteta->Sumw2();
    TH1F *h_ht1200_leadjeteta = new TH1F("h_ht1200_leadjeteta", "leading jet eta", 100, -5, 5);
    h_ht1200_leadjeteta->Sumw2();
    TH1F *h_ht2500_leadjeteta = new TH1F("h_ht2500_leadjeteta", "leading jet eta", 100, -5, 5);
    h_ht2500_leadjeteta->Sumw2();

    TH1F *h_ht0_minjeteta = new TH1F("h_ht0_minjeteta", "alphamin jet eta", 100, -5, 5);
    h_ht0_minjeteta->Sumw2();
    TH1F *h_ht70_minjeteta = new TH1F("h_ht70_minjeteta", "alphamin jet eta", 100, -5, 5);
    h_ht70_minjeteta->Sumw2();
    TH1F *h_ht100_minjeteta = new TH1F("h_ht100_minjeteta", "alphamin jet eta", 100, -5, 5);
    h_ht100_minjeteta->Sumw2();
    TH1F *h_ht200_minjeteta = new TH1F("h_ht200_minjeteta", "alphamin jet eta", 100, -5, 5);
    h_ht200_minjeteta->Sumw2();
    TH1F *h_ht400_minjeteta = new TH1F("h_ht400_minjeteta", "alphamin jet eta", 100, -5, 5);
    h_ht400_minjeteta->Sumw2();
    TH1F *h_ht600_minjeteta = new TH1F("h_ht600_minjeteta", "alphamin jet eta", 100, -5, 5);
    h_ht600_minjeteta->Sumw2();
    TH1F *h_ht800_minjeteta = new TH1F("h_ht800_minjeteta", "alphamin jet eta", 100, -5, 5);
    h_ht800_minjeteta->Sumw2();
    TH1F *h_ht1200_minjeteta = new TH1F("h_ht1200_minjeteta", "alphamin jet eta", 100, -5, 5);
    h_ht1200_minjeteta->Sumw2();
    TH1F *h_ht2500_minjeteta = new TH1F("h_ht2500_minjeteta", "alphamin jet eta", 100, -5, 5);
    h_ht2500_minjeteta->Sumw2();

    TH1F *h_ht0_jeteta_met_cut = new TH1F("h_ht0_jeteta_met_cut", "leading jet eta", 100, -5, 5);
    h_ht0_jeteta_met_cut->Sumw2();
    TH1F *h_ht70_jeteta_met_cut = new TH1F("h_ht70_jeteta_met_cut", "leading jet eta", 100, -5, 5);
    h_ht70_jeteta_met_cut->Sumw2();
    TH1F *h_ht100_jeteta_met_cut = new TH1F("h_ht100_jeteta_met_cut", "leading jet eta", 100, -5, 5);
    h_ht100_jeteta_met_cut->Sumw2();
    TH1F *h_ht200_jeteta_met_cut = new TH1F("h_ht200_jeteta_met_cut", "leading jet eta", 100, -5, 5);
    h_ht200_jeteta_met_cut->Sumw2();
    TH1F *h_ht400_jeteta_met_cut = new TH1F("h_ht400_jeteta_met_cut", "leading jet eta", 100, -5, 5);
    h_ht400_jeteta_met_cut->Sumw2();
    TH1F *h_ht600_jeteta_met_cut = new TH1F("h_ht600_jeteta_met_cut", "leading jet eta", 100, -5, 5);
    h_ht600_jeteta_met_cut->Sumw2();
    TH1F *h_ht800_jeteta_met_cut = new TH1F("h_ht800_jeteta_met_cut", "leading jet eta", 100, -5, 5);
    h_ht800_jeteta_met_cut->Sumw2();
    TH1F *h_ht1200_jeteta_met_cut = new TH1F("h_ht1200_jeteta_met_cut", "leading jet eta", 100, -5, 5);
    h_ht1200_jeteta_met_cut->Sumw2();
    TH1F *h_ht2500_jeteta_met_cut = new TH1F("h_ht2500_jeteta_met_cut", "leading jet eta", 100, -5, 5);
    h_ht2500_jeteta_met_cut->Sumw2();

    // nJets
    TH1F *h_ht0_njet = new TH1F("h_ht0_njet", "nJets", 15, 0, 15);
    h_ht0_njet->Sumw2();
    TH1F *h_ht70_njet = new TH1F("h_ht70_njet", "nJets", 15, 0, 15);
    h_ht70_njet->Sumw2();
    TH1F *h_ht100_njet = new TH1F("h_ht100_njet", "nJets", 15, 0, 15);
    h_ht100_njet->Sumw2();
    TH1F *h_ht200_njet = new TH1F("h_ht200_njet", "nJets", 15, 0, 15);
    h_ht200_njet->Sumw2();
    TH1F *h_ht400_njet = new TH1F("h_ht400_njet", "nJets", 15, 0, 15);
    h_ht400_njet->Sumw2();
    TH1F *h_ht600_njet = new TH1F("h_ht600_njet", "nJets", 15, 0, 15);
    h_ht600_njet->Sumw2();
    TH1F *h_ht800_njet = new TH1F("h_ht800_njet", "nJets", 15, 0, 15);
    h_ht800_njet->Sumw2();
    TH1F *h_ht1200_njet = new TH1F("h_ht1200_njet", "nJets", 15, 0, 15);
    h_ht1200_njet->Sumw2();
    TH1F *h_ht2500_njet = new TH1F("h_ht2500_njet", "nJets", 15, 0, 15);
    h_ht2500_njet->Sumw2();

    // h_ht0_disJet_multiplicity
    TH1F *h_ht0_disJet_multiplicity = new TH1F("h_ht0_disJet_multiplicity", "", 10, 0, 10);
    h_ht0_disJet_multiplicity->SetYTitle("N event");
    h_ht0_disJet_multiplicity->Sumw2();

    TH1F *h_ht70_disJet_multiplicity = new TH1F("h_ht70_disJet_multiplicity", "", 10, 0, 10);
    h_ht70_disJet_multiplicity->SetYTitle("N event");
    h_ht70_disJet_multiplicity->Sumw2();

    TH1F *h_ht100_disJet_multiplicity = new TH1F("h_ht100_disJet_multiplicity", "", 10, 0, 10);
    h_ht100_disJet_multiplicity->SetYTitle("N event");
    h_ht100_disJet_multiplicity->Sumw2();

    TH1F *h_ht200_disJet_multiplicity = new TH1F("h_ht200_disJet_multiplicity", "", 10, 0, 10);
    h_ht200_disJet_multiplicity->SetYTitle("N event");
    h_ht200_disJet_multiplicity->Sumw2();

    TH1F *h_ht400_disJet_multiplicity = new TH1F("h_ht400_disJet_multiplicity", "", 10, 0, 10);
    h_ht400_disJet_multiplicity->SetYTitle("N event");
    h_ht400_disJet_multiplicity->Sumw2();

    TH1F *h_ht600_disJet_multiplicity = new TH1F("h_ht600_disJet_multiplicity", "", 10, 0, 10);
    h_ht600_disJet_multiplicity->SetYTitle("N event");
    h_ht600_disJet_multiplicity->Sumw2();

    TH1F *h_ht800_disJet_multiplicity = new TH1F("h_ht800_disJet_multiplicity", "", 10, 0, 10);
    h_ht800_disJet_multiplicity->SetYTitle("N event");
    h_ht800_disJet_multiplicity->Sumw2();

    TH1F *h_ht1200_disJet_multiplicity = new TH1F("h_ht1200_disJet_multiplicity", "", 10, 0, 10);
    h_ht1200_disJet_multiplicity->SetYTitle("N event");
    h_ht1200_disJet_multiplicity->Sumw2();

    TH1F *h_ht2500_disJet_multiplicity = new TH1F("h_ht2500_disJet_multiplicity", "", 10, 0, 10);
    h_ht2500_disJet_multiplicity->SetYTitle("N event");
    h_ht2500_disJet_multiplicity->Sumw2();

    // alpha
    TH1F *h_ht0_alpha = new TH1F("h_ht0_alpha", "", 24, 0, 1.2);
    h_ht0_alpha->SetYTitle("N Jets");
    h_ht0_alpha->Sumw2();

    TH1F *h_ht70_alpha = new TH1F("h_ht70_alpha", "", 24, 0, 1.2);
    h_ht70_alpha->SetYTitle("N Jets");
    h_ht70_alpha->Sumw2();

    TH1F *h_ht100_alpha = new TH1F("h_ht100_alpha", "", 24, 0, 1.2);
    h_ht100_alpha->SetYTitle("N Jets");
    h_ht100_alpha->Sumw2();

    TH1F *h_ht200_alpha = new TH1F("h_ht200_alpha", "", 24, 0, 1.2);
    h_ht200_alpha->SetYTitle("N Jets");
    h_ht200_alpha->Sumw2();

    TH1F *h_ht400_alpha = new TH1F("h_ht400_alpha", "", 24, 0, 1.2);
    h_ht400_alpha->SetYTitle("N Jets");
    h_ht400_alpha->Sumw2();

    TH1F *h_ht600_alpha = new TH1F("h_ht600_alpha", "", 24, 0, 1.2);
    h_ht600_alpha->SetYTitle("N Jets");
    h_ht600_alpha->Sumw2();

    TH1F *h_ht800_alpha = new TH1F("h_ht800_alpha", "", 24, 0, 1.2);
    h_ht800_alpha->SetYTitle("N Jets");
    h_ht800_alpha->Sumw2();

    TH1F *h_ht1200_alpha = new TH1F("h_ht1200_alpha", "", 24, 0, 1.2);
    h_ht1200_alpha->SetYTitle("N Jets");
    h_ht1200_alpha->Sumw2();

    TH1F *h_ht2500_alpha = new TH1F("h_ht2500_alpha", "", 24, 0, 1.2);
    h_ht2500_alpha->SetYTitle("N Jets");
    h_ht2500_alpha->Sumw2();

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

    Int_t I_ht0_disJet_multiplicity, I_ht70_disJet_multiplicity, I_ht100_disJet_multiplicity, I_ht200_disJet_multiplicity, I_ht400_disJet_multiplicity,
        I_ht600_disJet_multiplicity, I_ht800_disJet_multiplicity, I_ht1200_disJet_multiplicity, I_ht2500_disJet_multiplicity;
    Int_t I_ht0_minJetflavor, I_ht70_minJetflavor, I_ht100_minJetflavor, I_ht200_minJetflavor, I_ht400_minJetflavor,
        I_ht600_minJetflavor, I_ht800_minJetflavor, I_ht1200_minJetflavor, I_ht2500_minJetflavor;

    vector<float> *v_ht0_alpha = new vector<float>();
    vector<float> *v_ht70_alpha = new vector<float>();
    vector<float> *v_ht100_alpha = new vector<float>();
    vector<float> *v_ht200_alpha = new vector<float>();
    vector<float> *v_ht400_alpha = new vector<float>();
    vector<float> *v_ht600_alpha = new vector<float>();
    vector<float> *v_ht800_alpha = new vector<float>();
    vector<float> *v_ht1200_alpha = new vector<float>();
    vector<float> *v_ht2500_alpha = new vector<float>();

    v_ht0_alpha->clear();
    v_ht70_alpha->clear();
    v_ht100_alpha->clear();
    v_ht200_alpha->clear();
    v_ht400_alpha->clear();
    v_ht600_alpha->clear();
    v_ht800_alpha->clear();
    v_ht1200_alpha->clear();
    v_ht2500_alpha->clear();
    // Define the HTWeight

    float HT0Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT0CS) / (HT0_70_event)) * 1000;
    float HT70Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT70CS) / (HT70_100_event)) * 1000;
    // cout <<"HT70Weight = " <<HT70Weight << endl;
    float HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000;
    // cout <<"HT100Weight = " <<HT100Weight << endl;
    float HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000;
    // cout <<"HT200Weight = " <<HT200Weight << endl;
    float HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000;
    // cout <<"HT400Weight = " <<HT400Weight << endl;
    float HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000;
    // cout <<"HT600Weight = " <<HT600Weight << endl;
    float HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000;
    // cout <<"HT800Weight = " <<HT800Weight << endl;
    float HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000;
    // cout <<"HT1200Weight = " <<HT1200Weight << endl;
    float HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000;
    // cout <<"HT2500Weight = " <<HT2500Weight << endl;

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
    T_event->SetBranchAddress("I_minJetflavor", &I_ht0_minJetflavor);
    T_event->SetBranchAddress("I_disJet_multiplicity", &I_ht0_disJet_multiplicity);
    T_event->SetBranchAddress("v_ht0_alpha", &v_ht0_alpha);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (I_ht0_nThinJets < 2)
            continue;
        if (I_ht0_minJetflavor == 4 || I_ht0_minJetflavor == 5)
        {
            if (HT < 70)
            {
                h_ht0_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT0Weight);
                h_ht0_met->Fill(f_ht0_Met, I_ht0_weight * HT0Weight);
                h_ht0_njet->Fill(I_ht0_nThinJets, I_ht0_weight * HT0Weight);
                if (f_ht0_Met > 90)
                {
                    h_ht0_jeteta_met_cut->Fill(f_ht0_leadJeteta, I_ht0_weight * HT0Weight);
                }
                h_ht0_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT0Weight);
                h_ht0_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT0Weight);
                h_ht0_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT0Weight);
                h_ht0_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT0Weight);
                h_ht0_disJet_multiplicity->Fill(I_ht0_disJet_multiplicity, I_ht0_weight * HT0Weight);
            }

            else if (HT >= 70 && HT < 100)
            {
                h_ht70_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT70Weight);
                h_ht70_met->Fill(f_ht0_Met, I_ht0_weight * HT70Weight);
                h_ht70_njet->Fill(I_ht0_nThinJets, I_ht0_weight * HT70Weight);
                if (f_ht0_Met > 90)
                {
                    h_ht70_jeteta_met_cut->Fill(f_ht0_leadJeteta, I_ht0_weight * HT70Weight);
                }
                h_ht70_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT70Weight);
                h_ht70_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT70Weight);
                h_ht70_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT70Weight);
                h_ht70_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT70Weight);
                h_ht70_disJet_multiplicity->Fill(I_ht0_disJet_multiplicity, I_ht0_weight * HT70Weight);
            }
            else if (HT >= 100 && HT < 200)
            {
                h_ht100_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT100Weight);
                h_ht100_met->Fill(f_ht0_Met, I_ht0_weight * HT100Weight);
                h_ht100_njet->Fill(I_ht0_nThinJets, I_ht0_weight * HT100Weight);
                if (f_ht0_Met > 90)
                {
                    h_ht100_jeteta_met_cut->Fill(f_ht0_leadJeteta, I_ht0_weight * HT100Weight);
                }
                h_ht100_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT100Weight);
                h_ht100_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT100Weight);
                h_ht100_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT100Weight);
                h_ht100_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT100Weight);
                h_ht100_disJet_multiplicity->Fill(I_ht0_disJet_multiplicity, I_ht0_weight * HT100Weight);
            }
            else if (HT >= 200 && HT < 400)
            {
                h_ht200_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT200Weight);
                h_ht200_met->Fill(f_ht0_Met, I_ht0_weight * HT200Weight);
                h_ht200_njet->Fill(I_ht0_nThinJets, I_ht0_weight * HT200Weight);
                if (f_ht0_Met > 90)
                {
                    h_ht200_jeteta_met_cut->Fill(f_ht0_leadJeteta, I_ht0_weight * HT200Weight);
                }
                h_ht200_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT200Weight);
                h_ht200_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT200Weight);
                h_ht200_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT200Weight);
                h_ht200_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT200Weight);
                h_ht200_disJet_multiplicity->Fill(I_ht0_disJet_multiplicity, I_ht0_weight * HT200Weight);
            }
            else if (HT >= 400 && HT < 600)
            {
                h_ht400_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT400Weight);
                h_ht400_met->Fill(f_ht0_Met, I_ht0_weight * HT400Weight);
                h_ht400_njet->Fill(I_ht0_nThinJets, I_ht0_weight * HT400Weight);
                if (f_ht0_Met > 90)
                {
                    h_ht400_jeteta_met_cut->Fill(f_ht0_leadJeteta, I_ht0_weight * HT400Weight);
                }
                h_ht400_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT400Weight);
                h_ht400_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT400Weight);
                h_ht400_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT400Weight);
                h_ht400_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT400Weight);
                h_ht400_disJet_multiplicity->Fill(I_ht0_disJet_multiplicity, I_ht0_weight * HT400Weight);
            }
            else if (HT >= 600 && HT < 800)
            {
                h_ht600_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT600Weight);
                h_ht600_met->Fill(f_ht0_Met, I_ht0_weight * HT600Weight);
                h_ht600_njet->Fill(I_ht0_nThinJets, I_ht0_weight * HT600Weight);
                if (f_ht0_Met > 90)
                {
                    h_ht600_jeteta_met_cut->Fill(f_ht0_leadJeteta, I_ht0_weight * HT600Weight);
                }
                h_ht600_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT600Weight);
                h_ht600_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT600Weight);
                h_ht600_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT600Weight);
                h_ht600_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT600Weight);
                h_ht600_disJet_multiplicity->Fill(I_ht0_disJet_multiplicity, I_ht0_weight * HT600Weight);
            }
            else if (HT >= 800 && HT < 1200)
            {
                h_ht800_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT800Weight);
                h_ht800_met->Fill(f_ht0_Met, I_ht0_weight * HT800Weight);
                h_ht800_njet->Fill(I_ht0_nThinJets, I_ht0_weight * HT800Weight);
                if (f_ht0_Met > 90)
                {
                    h_ht800_jeteta_met_cut->Fill(f_ht0_leadJeteta, I_ht0_weight * HT800Weight);
                }
                h_ht800_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT800Weight);
                h_ht800_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT800Weight);
                h_ht800_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT800Weight);
                h_ht800_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT800Weight);
                h_ht800_disJet_multiplicity->Fill(I_ht0_disJet_multiplicity, I_ht0_weight * HT800Weight);
            }
            else if (HT >= 1200 && HT < 2500)
            {
                h_ht1200_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT1200Weight);
                h_ht1200_met->Fill(f_ht0_Met, I_ht0_weight * HT1200Weight);
                h_ht1200_njet->Fill(I_ht0_nThinJets, I_ht0_weight * HT1200Weight);
                if (f_ht0_Met > 90)
                {
                    h_ht1200_jeteta_met_cut->Fill(f_ht0_leadJeteta, I_ht0_weight * HT800Weight);
                }
                h_ht1200_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT1200Weight);
                h_ht1200_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT1200Weight);
                h_ht1200_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT1200Weight);
                h_ht1200_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT1200Weight);
                h_ht1200_disJet_multiplicity->Fill(I_ht0_disJet_multiplicity, I_ht0_weight * HT1200Weight);
            }
            else if (HT >= 2500)
            {
                h_ht2500_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT2500Weight);
                h_ht2500_met->Fill(f_ht0_Met, I_ht0_weight * HT2500Weight);
                h_ht2500_njet->Fill(I_ht0_nThinJets, I_ht0_weight * HT2500Weight);
                if (f_ht0_Met > 90)
                {
                    h_ht2500_jeteta_met_cut->Fill(f_ht0_leadJeteta, I_ht0_weight * HT2500Weight);
                }
                h_ht2500_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT2500Weight);
                h_ht2500_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT2500Weight);
                h_ht2500_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT2500Weight);
                h_ht2500_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT2500Weight);
                h_ht2500_disJet_multiplicity->Fill(I_ht0_disJet_multiplicity, I_ht0_weight * HT2500Weight);
            }
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
    T_event1->SetBranchAddress("I_minJetflavor", &I_ht100_minJetflavor);
    T_event1->SetBranchAddress("I_disJet_multiplicity", &I_ht100_disJet_multiplicity);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (I_ht100_nThinJets < 2)
            continue;
        if (I_ht100_minJetflavor == 4 || I_ht100_minJetflavor == 5)
        {
            h_ht100_aphmin->Fill(f_ht100_alphamin, I_ht100_weight * HT100Weight);
            h_ht100_met->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
            h_ht100_njet->Fill(I_ht100_nThinJets, I_ht100_weight * HT100Weight);
            if (f_ht100_Met > 90)
            {
                h_ht100_jeteta_met_cut->Fill(f_ht100_leadJeteta, I_ht100_weight * HT100Weight);
            }
            h_ht100_leadjeteta->Fill(f_ht100_leadJeteta, I_ht100_weight * HT100Weight);
            h_ht100_leadjetpt->Fill(f_ht100_leadJetpt, I_ht100_weight * HT100Weight);
            h_ht100_minjeteta->Fill(f_ht100_minJeteta, I_ht100_weight * HT100Weight);
            h_ht100_minjetpt->Fill(f_ht100_minJetpt, I_ht100_weight * HT100Weight);
            h_ht100_disJet_multiplicity->Fill(I_ht100_disJet_multiplicity, I_ht100_weight * HT100Weight);
        }
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
    T_event2->SetBranchAddress("I_minJetflavor", &I_ht200_minJetflavor);
    T_event2->SetBranchAddress("I_disJet_multiplicity", &I_ht200_disJet_multiplicity);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (I_ht200_nThinJets < 2)
            continue;
        if (I_ht200_minJetflavor == 4 || I_ht200_minJetflavor == 5)
        {
            h_ht200_aphmin->Fill(f_ht200_alphamin, I_ht200_weight * HT200Weight);
            h_ht200_met->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
            h_ht200_njet->Fill(I_ht200_nThinJets, I_ht200_weight * HT200Weight);
            if (f_ht200_Met > 90)
            {
                h_ht200_jeteta_met_cut->Fill(f_ht200_leadJeteta, I_ht200_weight * HT200Weight);
            }
            h_ht200_leadjeteta->Fill(f_ht200_leadJeteta, I_ht200_weight * HT200Weight);
            h_ht200_leadjetpt->Fill(f_ht200_leadJetpt, I_ht200_weight * HT200Weight);
            h_ht200_minjeteta->Fill(f_ht200_minJeteta, I_ht200_weight * HT200Weight);
            h_ht200_minjetpt->Fill(f_ht200_minJetpt, I_ht200_weight * HT200Weight);
            h_ht200_disJet_multiplicity->Fill(I_ht200_disJet_multiplicity, I_ht200_weight * HT200Weight);
        }
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
    T_event3->SetBranchAddress("I_minJetflavor", &I_ht400_minJetflavor);
    T_event3->SetBranchAddress("I_disJet_multiplicity", &I_ht400_disJet_multiplicity);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (I_ht400_nThinJets < 2)
            continue;
        if (I_ht400_minJetflavor == 4 || I_ht400_minJetflavor == 5)
        {
            h_ht400_aphmin->Fill(f_ht400_alphamin, I_ht400_weight * HT400Weight);
            h_ht400_met->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
            h_ht400_njet->Fill(I_ht400_nThinJets, I_ht400_weight * HT400Weight);
            if (f_ht400_Met > 90)
            {
                h_ht400_jeteta_met_cut->Fill(f_ht400_leadJeteta, I_ht400_weight * HT400Weight);
            }
            h_ht400_leadjeteta->Fill(f_ht400_leadJeteta, I_ht400_weight * HT400Weight);
            h_ht400_leadjetpt->Fill(f_ht400_leadJetpt, I_ht400_weight * HT400Weight);
            h_ht400_minjeteta->Fill(f_ht400_minJeteta, I_ht400_weight * HT400Weight);
            h_ht400_minjetpt->Fill(f_ht400_minJetpt, I_ht400_weight * HT400Weight);
            h_ht400_disJet_multiplicity->Fill(I_ht400_disJet_multiplicity, I_ht400_weight * HT400Weight);
        }
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
    T_event4->SetBranchAddress("I_minJetflavor", &I_ht600_minJetflavor);
    T_event4->SetBranchAddress("I_disJet_multiplicity", &I_ht600_disJet_multiplicity);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (I_ht600_nThinJets < 2)
            continue;
        if (I_ht600_minJetflavor == 4 || I_ht600_minJetflavor == 5)
        {
            h_ht600_aphmin->Fill(f_ht600_alphamin, I_ht600_weight * HT600Weight);
            h_ht600_met->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
            h_ht600_njet->Fill(I_ht600_nThinJets, I_ht600_weight * HT600Weight);
            if (f_ht600_Met > 90)
            {
                h_ht600_jeteta_met_cut->Fill(f_ht600_leadJeteta, I_ht600_weight * HT600Weight);
            }
            h_ht600_leadjeteta->Fill(f_ht600_leadJeteta, I_ht600_weight * HT600Weight);
            h_ht600_leadjetpt->Fill(f_ht600_leadJetpt, I_ht600_weight * HT600Weight);
            h_ht600_minjeteta->Fill(f_ht600_minJeteta, I_ht600_weight * HT600Weight);
            h_ht600_minjetpt->Fill(f_ht600_minJetpt, I_ht600_weight * HT600Weight);
            h_ht600_disJet_multiplicity->Fill(I_ht600_disJet_multiplicity, I_ht600_weight * HT600Weight);
        }
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
    T_event5->SetBranchAddress("I_minJetflavor", &I_ht800_minJetflavor);
    T_event5->SetBranchAddress("I_disJet_multiplicity", &I_ht800_disJet_multiplicity);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (I_ht800_nThinJets < 2)
            continue;
        if (I_ht800_minJetflavor == 4 || I_ht800_minJetflavor == 5)
        {
            h_ht800_aphmin->Fill(f_ht800_alphamin, I_ht800_weight * HT800Weight);
            h_ht800_met->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
            h_ht800_njet->Fill(I_ht800_nThinJets, I_ht800_weight * HT800Weight);
            if (f_ht800_Met > 90)
            {
                h_ht800_jeteta_met_cut->Fill(f_ht800_leadJeteta, I_ht800_weight * HT800Weight);
            }
            h_ht800_leadjeteta->Fill(f_ht800_leadJeteta, I_ht800_weight * HT800Weight);
            h_ht800_leadjetpt->Fill(f_ht800_leadJetpt, I_ht800_weight * HT800Weight);
            h_ht800_minjeteta->Fill(f_ht800_minJeteta, I_ht800_weight * HT800Weight);
            h_ht800_minjetpt->Fill(f_ht800_minJetpt, I_ht800_weight * HT800Weight);
            h_ht800_disJet_multiplicity->Fill(I_ht800_disJet_multiplicity, I_ht800_weight * HT800Weight);
        }
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
    T_event6->SetBranchAddress("I_minJetflavor", &I_ht1200_minJetflavor);
    T_event6->SetBranchAddress("I_disJet_multiplicity", &I_ht1200_disJet_multiplicity);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (I_ht1200_nThinJets < 2)
            continue;
        if (I_ht1200_minJetflavor == 4 || I_ht1200_minJetflavor == 5)
        {
            h_ht1200_aphmin->Fill(f_ht1200_alphamin, I_ht1200_weight * HT1200Weight);
            h_ht1200_met->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
            h_ht1200_njet->Fill(I_ht1200_nThinJets, I_ht1200_weight * HT1200Weight);
            if (f_ht1200_Met > 90)
            {
                h_ht1200_jeteta_met_cut->Fill(f_ht1200_leadJeteta, I_ht1200_weight * HT1200Weight);
            }
            h_ht1200_leadjeteta->Fill(f_ht1200_leadJeteta, I_ht1200_weight * HT1200Weight);
            h_ht1200_leadjetpt->Fill(f_ht1200_leadJetpt, I_ht1200_weight * HT1200Weight);
            h_ht1200_minjeteta->Fill(f_ht1200_minJeteta, I_ht1200_weight * HT1200Weight);
            h_ht1200_minjetpt->Fill(f_ht1200_minJetpt, I_ht1200_weight * HT1200Weight);
            h_ht1200_disJet_multiplicity->Fill(I_ht1200_disJet_multiplicity, I_ht1200_weight * HT1200Weight);
        }
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
    T_event7->SetBranchAddress("I_minJetflavor", &I_ht2500_minJetflavor);

    T_event7->SetBranchAddress("I_disJet_multiplicity", &I_ht2500_disJet_multiplicity);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        if (I_ht2500_nThinJets < 2)
            continue;
        if (I_ht2500_minJetflavor == 4 || I_ht2500_minJetflavor == 5)
        {
            h_ht2500_aphmin->Fill(f_ht2500_alphamin, I_ht2500_weight * HT2500Weight);
            h_ht2500_met->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
            h_ht2500_njet->Fill(I_ht2500_nThinJets, I_ht2500_weight * HT2500Weight);
            if (f_ht2500_Met > 90)
            {
                h_ht2500_jeteta_met_cut->Fill(f_ht2500_leadJeteta, I_ht2500_weight * HT2500Weight);
            }

            h_ht2500_leadjeteta->Fill(f_ht2500_leadJeteta, I_ht2500_weight * HT2500Weight);
            h_ht2500_leadjetpt->Fill(f_ht2500_leadJetpt, I_ht2500_weight * HT2500Weight);
            h_ht2500_minjeteta->Fill(f_ht2500_minJeteta, I_ht2500_weight * HT2500Weight);
            h_ht2500_minjetpt->Fill(f_ht2500_minJetpt, I_ht2500_weight * HT2500Weight);
            h_ht2500_disJet_multiplicity->Fill(I_ht2500_disJet_multiplicity, I_ht2500_weight * HT2500Weight);
        }
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

    h_ht0_leadjeteta->Add(h_ht70_leadjeteta);
    h_ht0_leadjeteta->Add(h_ht100_leadjeteta);
    h_ht0_leadjeteta->Add(h_ht200_leadjeteta);
    h_ht0_leadjeteta->Add(h_ht400_leadjeteta);
    h_ht0_leadjeteta->Add(h_ht600_leadjeteta);
    h_ht0_leadjeteta->Add(h_ht800_leadjeteta);
    h_ht0_leadjeteta->Add(h_ht1200_leadjeteta);
    h_ht0_leadjeteta->Add(h_ht2500_leadjeteta);

    h_ht0_leadjetpt->Add(h_ht70_leadjetpt);
    h_ht0_leadjetpt->Add(h_ht100_leadjetpt);
    h_ht0_leadjetpt->Add(h_ht200_leadjetpt);
    h_ht0_leadjetpt->Add(h_ht400_leadjetpt);
    h_ht0_leadjetpt->Add(h_ht600_leadjetpt);
    h_ht0_leadjetpt->Add(h_ht800_leadjetpt);
    h_ht0_leadjetpt->Add(h_ht1200_leadjetpt);
    h_ht0_leadjetpt->Add(h_ht2500_leadjetpt);

    h_ht0_minjeteta->Add(h_ht70_minjeteta);
    h_ht0_minjeteta->Add(h_ht100_minjeteta);
    h_ht0_minjeteta->Add(h_ht200_minjeteta);
    h_ht0_minjeteta->Add(h_ht400_minjeteta);
    h_ht0_minjeteta->Add(h_ht600_minjeteta);
    h_ht0_minjeteta->Add(h_ht800_minjeteta);
    h_ht0_minjeteta->Add(h_ht1200_minjeteta);
    h_ht0_minjeteta->Add(h_ht2500_minjeteta);

    h_ht0_minjetpt->Add(h_ht70_minjetpt);
    h_ht0_minjetpt->Add(h_ht100_minjetpt);
    h_ht0_minjetpt->Add(h_ht200_minjetpt);
    h_ht0_minjetpt->Add(h_ht400_minjetpt);
    h_ht0_minjetpt->Add(h_ht600_minjetpt);
    h_ht0_minjetpt->Add(h_ht800_minjetpt);
    h_ht0_minjetpt->Add(h_ht1200_minjetpt);
    h_ht0_minjetpt->Add(h_ht2500_minjetpt);

    h_ht0_jeteta_met_cut->Add(h_ht70_jeteta_met_cut);
    h_ht0_jeteta_met_cut->Add(h_ht100_jeteta_met_cut);
    h_ht0_jeteta_met_cut->Add(h_ht200_jeteta_met_cut);
    h_ht0_jeteta_met_cut->Add(h_ht400_jeteta_met_cut);
    h_ht0_jeteta_met_cut->Add(h_ht600_jeteta_met_cut);
    h_ht0_jeteta_met_cut->Add(h_ht800_jeteta_met_cut);
    h_ht0_jeteta_met_cut->Add(h_ht1200_jeteta_met_cut);
    h_ht0_jeteta_met_cut->Add(h_ht2500_jeteta_met_cut);

    h_ht0_njet->Add(h_ht70_njet);
    h_ht0_njet->Add(h_ht100_njet);
    h_ht0_njet->Add(h_ht200_njet);
    h_ht0_njet->Add(h_ht400_njet);
    h_ht0_njet->Add(h_ht600_njet);
    h_ht0_njet->Add(h_ht800_njet);
    h_ht0_njet->Add(h_ht1200_njet);
    h_ht0_njet->Add(h_ht2500_njet);

    h_ht0_disJet_multiplicity->Add(h_ht70_disJet_multiplicity);
    h_ht0_disJet_multiplicity->Add(h_ht100_disJet_multiplicity);
    h_ht0_disJet_multiplicity->Add(h_ht200_disJet_multiplicity);
    h_ht0_disJet_multiplicity->Add(h_ht400_disJet_multiplicity);
    h_ht0_disJet_multiplicity->Add(h_ht600_disJet_multiplicity);
    h_ht0_disJet_multiplicity->Add(h_ht800_disJet_multiplicity);
    h_ht0_disJet_multiplicity->Add(h_ht1200_disJet_multiplicity);
    h_ht0_disJet_multiplicity->Add(h_ht2500_disJet_multiplicity);

    h_ht0_disJet_multiplicity->Draw("hist");

    TFile *outFile = new TFile("./../../root_file/Ztoee/DYHT_All.root", "RECREATE");
    outFile->cd();
    h_ht0_aphmin->Write();
    h_ht0_met->Write();
    h_ht0_leadjeteta->Write();
    h_ht0_leadjetpt->Write();
    h_ht0_minjeteta->Write();
    h_ht0_minjetpt->Write();
    h_ht0_jeteta_met_cut->Write();
    h_ht0_njet->Write();
    h_ht0_disJet_multiplicity->Write();
    outFile->Close();
}
