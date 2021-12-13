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

void Diboson_var()
{
    // SetColor
    Int_t KIKYO = TColor::GetFreeColorIndex();
    TColor *KIKYO_color = new TColor(KIKYO, 0.42, 0.30, 0.61);
    Int_t KON = TColor::GetFreeColorIndex();
    TColor *KON_color = new TColor(KON, 0.06, 0.15, 0.25);

    Int_t HIWAMOEGI = TColor::GetFreeColorIndex();
    TColor *HIWAMOEGI_color = new TColor(HIWAMOEGI, 0.56, 0.71, 0.29);

    TFile *diboson_gg_ZZ_2e2mu = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2mu.root");
    TFile *diboson_gg_ZZ_2e2nu = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2nu.root");
    TFile *diboson_gg_ZZ_2e2tau = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2tau.root");
    TFile *diboson_gg_ZZ_2mu2nu = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2mu2nu.root");
    TFile *diboson_gg_ZZ_2mu2tau = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2mu2tau.root");
    TFile *diboson_gg_ZZ_4e = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4e.root");
    TFile *diboson_gg_ZZ_4mu = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4mu.root");
    TFile *diboson_gg_ZZ_4tau = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4tau.root");
    TFile *diboson_gg_WW_2L2Nu = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_WW_2L2Nu.root");
    TFile *diboson_qq_WW_2L2Nu = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WW_2L2Nu.root");
    TFile *diboson_qq_WZ_2L2Q = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WZ_2L2Q.root");
    TFile *diboson_qq_WZ_3LNu = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WZ_3LNu.root");
    TFile *diboson_qq_ZZ_2L2Nu = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_2L2Nu.root");
    TFile *diboson_qq_ZZ_2L2Q = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_2L2Q.root");
    TFile *diboson_qq_ZZ_4L = new TFile("./../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_4L.root");

    TH1D *gg_ZZ_2e2mu_sumevt = ((TH1D *)diboson_gg_ZZ_2e2mu->Get("Event_Variable/h_event"));
    TH1D *gg_ZZ_2e2nu_sumevt = ((TH1D *)diboson_gg_ZZ_2e2nu->Get("Event_Variable/h_event"));
    TH1D *gg_ZZ_2e2tau_sumevt = ((TH1D *)diboson_gg_ZZ_2e2tau->Get("Event_Variable/h_event"));
    TH1D *gg_ZZ_2mu2nu_sumevt = ((TH1D *)diboson_gg_ZZ_2mu2nu->Get("Event_Variable/h_event"));
    TH1D *gg_ZZ_2mu2tau_sumevt = ((TH1D *)diboson_gg_ZZ_2mu2tau->Get("Event_Variable/h_event"));
    TH1D *gg_ZZ_4e_sumevt = ((TH1D *)diboson_gg_ZZ_4e->Get("Event_Variable/h_event"));
    TH1D *gg_ZZ_4mu_sumevt = ((TH1D *)diboson_gg_ZZ_4mu->Get("Event_Variable/h_event"));
    TH1D *gg_ZZ_4tau_sumevt = ((TH1D *)diboson_gg_ZZ_4tau->Get("Event_Variable/h_event"));
    TH1D *gg_WW_2L2Nu_sumevt = ((TH1D *)diboson_gg_WW_2L2Nu->Get("Event_Variable/h_event"));
    TH1D *qq_WW_2L2Nu_sumevt = ((TH1D *)diboson_qq_WW_2L2Nu->Get("Event_Variable/h_event"));
    TH1D *qq_WZ_2L2Q_sumevt = ((TH1D *)diboson_qq_WZ_2L2Q->Get("Event_Variable/h_event"));
    TH1D *qq_WZ_3LNu_sumevt = ((TH1D *)diboson_qq_WZ_3LNu->Get("Event_Variable/h_event"));
    TH1D *qq_ZZ_2L2Nu_sumevt = ((TH1D *)diboson_qq_ZZ_2L2Nu->Get("Event_Variable/h_event"));
    TH1D *qq_ZZ_2L2Q_sumevt = ((TH1D *)diboson_qq_ZZ_2L2Q->Get("Event_Variable/h_event"));
    TH1D *qq_ZZ_4L_sumevt = ((TH1D *)diboson_qq_ZZ_4L->Get("Event_Variable/h_event"));

    int gg_ZZ_2e2mu_totevt = gg_ZZ_2e2mu_sumevt->Integral();
    int gg_ZZ_2e2nu_totevt = gg_ZZ_2e2nu_sumevt->Integral();
    int gg_ZZ_2e2tau_totevt = gg_ZZ_2e2tau_sumevt->Integral();
    int gg_ZZ_2mu2nu_totevt = gg_ZZ_2mu2nu_sumevt->Integral();
    int gg_ZZ_2mu2tau_totevt = gg_ZZ_2mu2tau_sumevt->Integral();
    int gg_ZZ_4e_totevt = gg_ZZ_4e_sumevt->Integral();
    int gg_ZZ_4mu_totevt = gg_ZZ_4mu_sumevt->Integral();
    int gg_ZZ_4tau_totevt = gg_ZZ_4tau_sumevt->Integral();
    int gg_WW_2L2Nu_totevt = gg_WW_2L2Nu_sumevt->Integral();
    int qq_WW_2L2Nu_totevt = qq_WW_2L2Nu_sumevt->Integral();
    int qq_WZ_2L2Q_totevt = qq_WZ_2L2Q_sumevt->Integral();
    int qq_WZ_3LNu_totevt = qq_WZ_3LNu_sumevt->Integral();
    int qq_ZZ_2L2Nu_totevt = qq_ZZ_2L2Nu_sumevt->Integral();
    int qq_ZZ_2L2Q_totevt = qq_ZZ_2L2Q_sumevt->Integral();
    int qq_ZZ_4L_totevt = qq_ZZ_4L_sumevt->Integral();

    // Diboson
    TH1F *diboson_gg_WW_2L2Nu_aphmin = new TH1F("diboson_gg_WW_2L2Nu_aphmin", "", 24, 0, 1.2);
    diboson_gg_WW_2L2Nu_aphmin->Sumw2();

    TH1F *diboson_gg_ZZ_2e2mu_aphmin = new TH1F("diboson_gg_ZZ_2e2mu_aphmin", "", 24, 0, 1.2);
    diboson_gg_ZZ_2e2mu_aphmin->Sumw2();

    TH1F *diboson_gg_ZZ_2e2nu_aphmin = new TH1F("diboson_gg_ZZ_2e2nu_aphmin", "", 24, 0, 1.2);
    diboson_gg_ZZ_2e2nu_aphmin->Sumw2();

    TH1F *diboson_gg_ZZ_2e2tau_aphmin = new TH1F("diboson_gg_ZZ_2e2tau_aphmin", "", 24, 0, 1.2);
    diboson_gg_ZZ_2e2tau_aphmin->Sumw2();

    TH1F *diboson_gg_ZZ_2mu2nu_aphmin = new TH1F("diboson_gg_ZZ_2mu2nu_aphmin", "", 24, 0, 1.2);
    diboson_gg_ZZ_2mu2nu_aphmin->Sumw2();

    TH1F *diboson_gg_ZZ_2mu2tau_aphmin = new TH1F("diboson_gg_ZZ_2mu2tau_aphmin", "", 24, 0, 1.2);
    diboson_gg_ZZ_2mu2tau_aphmin->Sumw2();

    TH1F *diboson_gg_ZZ_4e_aphmin = new TH1F("diboson_gg_ZZ_4e_aphmin", "", 24, 0, 1.2);
    diboson_gg_ZZ_4e_aphmin->Sumw2();

    TH1F *diboson_gg_ZZ_4mu_aphmin = new TH1F("diboson_gg_ZZ_4mu_aphmin", "", 24, 0, 1.2);
    diboson_gg_ZZ_4mu_aphmin->Sumw2();

    TH1F *diboson_gg_ZZ_4tau_aphmin = new TH1F("diboson_gg_ZZ_4tau_aphmin", "", 24, 0, 1.2);
    diboson_gg_ZZ_4tau_aphmin->Sumw2();

    TH1F *diboson_qq_WW_2L2Nu_aphmin = new TH1F("diboson_qq_WW_2L2Nu_aphmin", "", 24, 0, 1.2);
    diboson_qq_WW_2L2Nu_aphmin->Sumw2();

    TH1F *diboson_qq_WZ_2L2Q_aphmin = new TH1F("diboson_qq_WZ_2L2Q_aphmin", "", 24, 0, 1.2);
    diboson_qq_WZ_2L2Q_aphmin->Sumw2();

    TH1F *diboson_qq_WZ_3LNu_aphmin = new TH1F("diboson_qq_WZ_3LNu_aphmin", "", 24, 0, 1.2);
    diboson_qq_WZ_3LNu_aphmin->Sumw2();

    TH1F *diboson_qq_ZZ_2L2Nu_aphmin = new TH1F("diboson_qq_ZZ_2L2Nu_aphmin", "", 24, 0, 1.2);
    diboson_qq_ZZ_2L2Nu_aphmin->Sumw2();

    TH1F *diboson_qq_ZZ_2L2Q_aphmin = new TH1F("diboson_qq_ZZ_2L2Q_aphmin", "", 24, 0, 1.2);
    diboson_qq_ZZ_2L2Q_aphmin->Sumw2();

    TH1F *diboson_qq_ZZ_4L_aphmin = new TH1F("diboson_qq_ZZ_4L_aphmin", "", 24, 0, 1.2);
    diboson_qq_ZZ_4L_aphmin->Sumw2();

    TH1F *diboson_gg_WW_2L2Nu_met = new TH1F("diboson_gg_WW_2L2Nu_met", "", 20, 0, 800);
    diboson_gg_WW_2L2Nu_met->Sumw2();

    TH1F *diboson_gg_ZZ_2e2mu_met = new TH1F("diboson_gg_ZZ_2e2mu_met", "", 20, 0, 800);
    diboson_gg_ZZ_2e2mu_met->Sumw2();

    TH1F *diboson_gg_ZZ_2e2nu_met = new TH1F("diboson_gg_ZZ_2e2nu_met", "", 20, 0, 800);
    diboson_gg_ZZ_2e2nu_met->Sumw2();

    TH1F *diboson_gg_ZZ_2e2tau_met = new TH1F("diboson_gg_ZZ_2e2tau_met", "", 20, 0, 800);
    diboson_gg_ZZ_2e2tau_met->Sumw2();

    TH1F *diboson_gg_ZZ_2mu2nu_met = new TH1F("diboson_gg_ZZ_2mu2nu_met", "", 20, 0, 800);
    diboson_gg_ZZ_2mu2nu_met->Sumw2();

    TH1F *diboson_gg_ZZ_2mu2tau_met = new TH1F("diboson_gg_ZZ_2mu2tau_met", "", 20, 0, 800);
    diboson_gg_ZZ_2mu2tau_met->Sumw2();

    TH1F *diboson_gg_ZZ_4e_met = new TH1F("diboson_gg_ZZ_4e_met", "", 20, 0, 800);
    diboson_gg_ZZ_4e_met->Sumw2();

    TH1F *diboson_gg_ZZ_4mu_met = new TH1F("diboson_gg_ZZ_4mu_met", "", 20, 0, 800);
    diboson_gg_ZZ_4mu_met->Sumw2();

    TH1F *diboson_gg_ZZ_4tau_met = new TH1F("diboson_gg_ZZ_4tau_met", "", 20, 0, 800);
    diboson_gg_ZZ_4tau_met->Sumw2();

    TH1F *diboson_qq_WW_2L2Nu_met = new TH1F("diboson_qq_WW_2L2Nu_met", "", 20, 0, 800);
    diboson_qq_WW_2L2Nu_met->Sumw2();

    TH1F *diboson_qq_WZ_2L2Q_met = new TH1F("diboson_qq_WZ_2L2Q_met", "", 20, 0, 800);
    diboson_qq_WZ_2L2Q_met->Sumw2();

    TH1F *diboson_qq_WZ_3LNu_met = new TH1F("diboson_qq_WZ_3LNu_met", "", 20, 0, 800);
    diboson_qq_WZ_3LNu_met->Sumw2();

    TH1F *diboson_qq_ZZ_2L2Nu_met = new TH1F("diboson_qq_ZZ_2L2Nu_met", "", 20, 0, 800);
    diboson_qq_ZZ_2L2Nu_met->Sumw2();

    TH1F *diboson_qq_ZZ_2L2Q_met = new TH1F("diboson_qq_ZZ_2L2Q_met", "", 20, 0, 800);
    diboson_qq_ZZ_2L2Q_met->Sumw2();

    TH1F *diboson_qq_ZZ_4L_met = new TH1F("diboson_qq_ZZ_4L_met", "", 20, 0, 800);
    diboson_qq_ZZ_4L_met->Sumw2();

    Double_t f_gg_ZZ_2e2mu_alphamin, f_gg_ZZ_2e2nu_alphamin, f_gg_ZZ_2e2tau_alphamin, f_gg_ZZ_2mu2nu_alphamin,
        f_gg_ZZ_2mu2tau_alphamin, f_gg_ZZ_4e_alphamin, f_gg_ZZ_4mu_alphamin, f_gg_ZZ_4tau_alphamin, f_gg_WW_2L2Nu_alphamin,
        f_qq_WW_2L2Nu_alphamin, f_qq_WZ_2L2Q_alphamin, f_qq_WZ_3LNu_alphamin, f_qq_ZZ_2L2Nu_alphamin, f_qq_ZZ_2L2Q_alphamin,
        f_qq_ZZ_4L_alphamin;

    Float_t f_gg_ZZ_2e2mu_met, f_gg_ZZ_2e2nu_met, f_gg_ZZ_2e2tau_met, f_gg_ZZ_2mu2nu_met,
        f_gg_ZZ_2mu2tau_met, f_gg_ZZ_4e_met, f_gg_ZZ_4mu_met, f_gg_ZZ_4tau_met, f_gg_WW_2L2Nu_met,
        f_qq_WW_2L2Nu_met, f_qq_WZ_2L2Q_met, f_qq_WZ_3LNu_met, f_qq_ZZ_2L2Nu_met, f_qq_ZZ_2L2Q_met,
        f_qq_ZZ_4L_met;

    Int_t f_gg_ZZ_2e2mu_weight, f_gg_ZZ_2e2nu_weight, f_gg_ZZ_2e2tau_weight, f_gg_ZZ_2mu2nu_weight,
        f_gg_ZZ_2mu2tau_weight, f_gg_ZZ_4e_weight, f_gg_ZZ_4mu_weight, f_gg_ZZ_4tau_weight, f_gg_WW_2L2Nu_weight,
        f_qq_WW_2L2Nu_weight, f_qq_WZ_2L2Q_weight, f_qq_WZ_3LNu_weight, f_qq_ZZ_2L2Nu_weight, f_qq_ZZ_2L2Q_weight,
        f_qq_ZZ_4L_weight;

    // Define the HTWeight

    float diboson_gg_ZZ_2e2mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2mu / (gg_ZZ_2e2mu_totevt))*1000;
    float diboson_gg_ZZ_2e2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2nu / (gg_ZZ_2e2nu_totevt))*1000;
    float diboson_gg_ZZ_2e2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2tau / (gg_ZZ_2e2tau_totevt))*1000;
    float diboson_gg_ZZ_2mu2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2nu / (gg_ZZ_2mu2nu_totevt))*1000;
    float diboson_gg_ZZ_2mu2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2tau / (gg_ZZ_2mu2tau_totevt))*1000;
    float diboson_gg_ZZ_4e_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4e / (gg_ZZ_4e_totevt))*1000;
    float diboson_gg_ZZ_4mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4mu / (gg_ZZ_4mu_totevt))*1000;
    float diboson_gg_ZZ_4tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4tau / (gg_ZZ_4tau_totevt))*1000;
    float diboson_gg_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WW_2L2Nu / (gg_WW_2L2Nu_totevt))*1000;
    float diboson_qq_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Nu / (qq_WW_2L2Nu_totevt))*1000;
    float diboson_qq_WZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_2L2Q / (qq_WZ_2L2Q_totevt))*1000;
    float diboson_qq_WZ_3LNu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_3LNu / (qq_WZ_3LNu_totevt))*1000;
    float diboson_qq_ZZ_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Nu / (qq_ZZ_2L2Nu_totevt))*1000;
    float diboson_qq_ZZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Q / (qq_ZZ_2L2Q_totevt))*1000;
    float diboson_qq_ZZ_4L_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_4L / (qq_ZZ_4L_totevt))*1000;

    TTree *T_event;
    diboson_gg_ZZ_2e2mu->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &f_gg_ZZ_2e2mu_weight);
    T_event->SetBranchAddress("f_alphamin", &f_gg_ZZ_2e2mu_alphamin);
    T_event->SetBranchAddress("f_Met", &f_gg_ZZ_2e2mu_met);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        diboson_gg_ZZ_2e2mu_aphmin->Fill(f_gg_ZZ_2e2mu_alphamin, f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight);
        diboson_gg_ZZ_2e2mu_met->Fill(f_gg_ZZ_2e2mu_met, f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight);
        // Top_quark_aphmin->Fill(f_tW_top_alphamin, f_tW_top_weight * ST_tW_topWeight);
        // Top_quark_met->Fill(f_tW_top_met, f_tW_top_weight * ST_tW_topWeight);
    }

    TTree *T_event1;
    diboson_gg_ZZ_2e2nu->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_gg_ZZ_2e2nu_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_gg_ZZ_2e2nu_met);
    T_event1->SetBranchAddress("I_weight", &f_gg_ZZ_2e2nu_weight);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        diboson_gg_ZZ_2e2nu_aphmin->Fill(f_gg_ZZ_2e2nu_alphamin, f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight);
        diboson_gg_ZZ_2e2nu_met->Fill(f_gg_ZZ_2e2nu_met, f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight);
    }

    TTree *T_event2;
    diboson_gg_ZZ_2e2tau->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_gg_ZZ_2e2tau_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_gg_ZZ_2e2tau_met);
    T_event2->SetBranchAddress("I_weight", &f_gg_ZZ_2e2tau_weight);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        diboson_gg_ZZ_2e2tau_aphmin->Fill(f_gg_ZZ_2e2tau_alphamin, f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight);
        diboson_gg_ZZ_2e2tau_met->Fill(f_gg_ZZ_2e2tau_met, f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight);
    }

    TTree *T_event3;
    diboson_gg_ZZ_2mu2nu->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &f_gg_ZZ_2mu2nu_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_gg_ZZ_2mu2nu_met);
    T_event3->SetBranchAddress("I_weight", &f_gg_ZZ_2mu2nu_weight);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        diboson_gg_ZZ_2mu2nu_aphmin->Fill(f_gg_ZZ_2mu2nu_alphamin, f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight);
        diboson_gg_ZZ_2mu2nu_met->Fill(f_gg_ZZ_2mu2nu_met, f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight);
    }

    TTree *T_event4;
    diboson_gg_ZZ_2mu2tau->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &f_gg_ZZ_2mu2tau_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_gg_ZZ_2mu2tau_met);
    T_event4->SetBranchAddress("I_weight", &f_gg_ZZ_2mu2tau_weight);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        diboson_gg_ZZ_2mu2tau_aphmin->Fill(f_gg_ZZ_2mu2tau_alphamin, f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight);
        diboson_gg_ZZ_2mu2tau_met->Fill(f_gg_ZZ_2mu2tau_met, f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight);
    }

    TTree *T_event5;
    diboson_gg_ZZ_4e->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &f_gg_ZZ_4e_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_gg_ZZ_4e_met);
    T_event5->SetBranchAddress("I_weight", &f_gg_ZZ_4e_weight);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        diboson_gg_ZZ_4e_aphmin->Fill(f_gg_ZZ_4e_alphamin, f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight);
        diboson_gg_ZZ_4e_met->Fill(f_gg_ZZ_4e_met, f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight);
    }

    TTree *T_event6;
    diboson_gg_ZZ_4mu->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &f_gg_ZZ_4mu_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_gg_ZZ_4mu_met);
    T_event6->SetBranchAddress("I_weight", &f_gg_ZZ_4mu_weight);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        diboson_gg_ZZ_4mu_aphmin->Fill(f_gg_ZZ_4mu_alphamin, f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight);
        diboson_gg_ZZ_4mu_met->Fill(f_gg_ZZ_4mu_met, f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight);
    }

    TTree *T_event7;
    diboson_gg_ZZ_4tau->GetObject("T_event", T_event7);
    T_event7->SetBranchAddress("I_weight", &f_gg_ZZ_4tau_weight);
    T_event7->SetBranchAddress("f_alphamin", &f_gg_ZZ_4tau_alphamin);
    T_event7->SetBranchAddress("f_Met", &f_gg_ZZ_4tau_met);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        diboson_gg_ZZ_4tau_aphmin->Fill(f_gg_ZZ_4tau_alphamin, f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight);
        diboson_gg_ZZ_4tau_met->Fill(f_gg_ZZ_4tau_met, f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight);
    }

    TTree *T_event8;
    diboson_gg_WW_2L2Nu->GetObject("T_event", T_event8);
    T_event8->SetBranchAddress("f_alphamin", &f_gg_WW_2L2Nu_alphamin);
    T_event8->SetBranchAddress("f_Met", &f_gg_WW_2L2Nu_met);
    T_event8->SetBranchAddress("I_weight", &f_gg_WW_2L2Nu_weight);
    for (int evt = 0; evt < T_event8->GetEntries(); evt++)
    {
        T_event8->GetEntry(evt);
        diboson_gg_WW_2L2Nu_aphmin->Fill(f_gg_WW_2L2Nu_alphamin, f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight);
        diboson_gg_WW_2L2Nu_met->Fill(f_gg_WW_2L2Nu_met, f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight);
    }

    TTree *T_event9;
    diboson_qq_WW_2L2Nu->GetObject("T_event", T_event9);
    T_event9->SetBranchAddress("f_alphamin", &f_qq_WW_2L2Nu_alphamin);
    T_event9->SetBranchAddress("f_Met", &f_qq_WW_2L2Nu_met);
    T_event9->SetBranchAddress("I_weight", &f_qq_WW_2L2Nu_weight);
    for (int evt = 0; evt < T_event9->GetEntries(); evt++)
    {
        T_event9->GetEntry(evt);
        diboson_qq_WW_2L2Nu_aphmin->Fill(f_qq_WW_2L2Nu_alphamin, f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight);
        diboson_qq_WW_2L2Nu_met->Fill(f_qq_WW_2L2Nu_met, f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight);
    }

    TTree *T_event10;
    diboson_qq_WZ_2L2Q->GetObject("T_event", T_event10);
    T_event10->SetBranchAddress("f_alphamin", &f_qq_WZ_2L2Q_alphamin);
    T_event10->SetBranchAddress("f_Met", &f_qq_WZ_2L2Q_met);
    T_event10->SetBranchAddress("I_weight", &f_qq_WZ_2L2Q_weight);
    for (int evt = 0; evt < T_event10->GetEntries(); evt++)
    {
        T_event10->GetEntry(evt);
        diboson_qq_WZ_2L2Q_aphmin->Fill(f_qq_WZ_2L2Q_alphamin, f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight);
        diboson_qq_WZ_2L2Q_met->Fill(f_qq_WZ_2L2Q_met, f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight);
    }

    TTree *T_event11;
    diboson_qq_WZ_3LNu->GetObject("T_event", T_event11);
    T_event11->SetBranchAddress("f_alphamin", &f_qq_WZ_3LNu_alphamin);
    T_event11->SetBranchAddress("f_Met", &f_qq_WZ_3LNu_met);
    T_event11->SetBranchAddress("I_weight", &f_qq_WZ_3LNu_weight);
    for (int evt = 0; evt < T_event11->GetEntries(); evt++)
    {
        T_event11->GetEntry(evt);
        diboson_qq_WZ_3LNu_aphmin->Fill(f_qq_WZ_3LNu_alphamin, f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight);
        diboson_qq_WZ_3LNu_met->Fill(f_qq_WZ_3LNu_met, f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight);
    }

    TTree *T_event12;
    diboson_qq_ZZ_2L2Nu->GetObject("T_event", T_event12);
    T_event12->SetBranchAddress("f_alphamin", &f_qq_ZZ_2L2Nu_alphamin);
    T_event12->SetBranchAddress("f_Met", &f_qq_ZZ_2L2Nu_met);
    T_event12->SetBranchAddress("I_weight", &f_qq_ZZ_2L2Nu_weight);
    for (int evt = 0; evt < T_event12->GetEntries(); evt++)
    {
        T_event12->GetEntry(evt);
        diboson_qq_ZZ_2L2Nu_aphmin->Fill(f_qq_ZZ_2L2Nu_alphamin, f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight);
        diboson_qq_ZZ_2L2Nu_met->Fill(f_qq_ZZ_2L2Nu_met, f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight);
    }

    TTree *T_event13;
    diboson_qq_ZZ_2L2Q->GetObject("T_event", T_event13);
    T_event13->SetBranchAddress("f_alphamin", &f_qq_ZZ_2L2Q_alphamin);
    T_event13->SetBranchAddress("f_Met", &f_qq_ZZ_2L2Q_met);
    T_event13->SetBranchAddress("I_weight", &f_qq_ZZ_2L2Q_weight);
    for (int evt = 0; evt < T_event13->GetEntries(); evt++)
    {
        T_event13->GetEntry(evt);
        diboson_qq_ZZ_2L2Q_aphmin->Fill(f_qq_ZZ_2L2Q_alphamin, f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight);
        diboson_qq_ZZ_2L2Q_met->Fill(f_qq_ZZ_2L2Q_met, f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight);
    }

    TTree *T_event14;
    diboson_qq_ZZ_4L->GetObject("T_event", T_event14);
    T_event14->SetBranchAddress("f_alphamin", &f_qq_ZZ_4L_alphamin);
    T_event14->SetBranchAddress("f_Met", &f_qq_ZZ_4L_met);
    T_event14->SetBranchAddress("I_weight", &f_qq_ZZ_4L_weight);
    for (int evt = 0; evt < T_event14->GetEntries(); evt++)
    {
        T_event14->GetEntry(evt);
        diboson_qq_ZZ_4L_aphmin->Fill(f_qq_ZZ_4L_alphamin, f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight);
        diboson_qq_ZZ_4L_met->Fill(f_qq_ZZ_4L_met, f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight);
    }

    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(4, 4);
    c1->cd(1);
    diboson_gg_ZZ_2e2nu_met->SetTitle("gg_ZZ_2e2nu");
    diboson_gg_ZZ_2e2mu_aphmin->SetTitle("gg_ZZ_2e2nu");
    diboson_gg_ZZ_2e2nu_met->SetFillColor(HIWAMOEGI);
    // diboson_gg_ZZ_2e2mu_aphmin->SetFillColor(HIWAMOEGI);
    diboson_gg_ZZ_2e2nu_met->Draw("hist");
    // diboson_gg_ZZ_2e2mu_aphmin->Draw("hist");
    c1->cd(2);
    diboson_gg_ZZ_2e2nu_aphmin->SetTitle("gg_ZZ_2e2nu");
    diboson_gg_ZZ_2e2nu_met->SetTitle("gg_ZZ_2e2nu");
    diboson_gg_ZZ_2e2nu_aphmin->SetFillColor(HIWAMOEGI);
    diboson_gg_ZZ_2e2nu_met->SetFillColor(HIWAMOEGI);
    // diboson_gg_ZZ_2e2nu_aphmin->Draw("hist");
    diboson_gg_ZZ_2e2nu_met->Draw("hist");
    c1->cd(3);
    diboson_gg_ZZ_2e2tau_aphmin->SetTitle("gg_ZZ_2e2tau");
    diboson_gg_ZZ_2e2tau_met->SetTitle("gg_ZZ_2e2tau");
    diboson_gg_ZZ_2e2tau_aphmin->SetFillColor(HIWAMOEGI);
    diboson_gg_ZZ_2e2tau_met->SetFillColor(HIWAMOEGI);
    // diboson_gg_ZZ_2e2tau_aphmin->Draw("hist");
    diboson_gg_ZZ_2e2tau_met->Draw("hist");
    c1->cd(4);
    diboson_gg_ZZ_2mu2nu_aphmin->SetTitle("gg_ZZ_2mu2nu");
    diboson_gg_ZZ_2mu2nu_met->SetTitle("gg_ZZ_2mu2nu");
    diboson_gg_ZZ_2mu2nu_aphmin->SetFillColor(HIWAMOEGI);
    diboson_gg_ZZ_2mu2nu_met->SetFillColor(HIWAMOEGI);
    // diboson_gg_ZZ_2mu2nu_aphmin->Draw("hist");
    diboson_gg_ZZ_2mu2nu_met->Draw("hist");
    c1->cd(5);
    diboson_gg_ZZ_2mu2tau_aphmin->SetTitle("gg_ZZ_2mu2tau");
    diboson_gg_ZZ_2mu2tau_met->SetTitle("gg_ZZ_2mu2tau");
    diboson_gg_ZZ_2mu2tau_aphmin->SetFillColor(HIWAMOEGI);
    diboson_gg_ZZ_2mu2tau_met->SetFillColor(HIWAMOEGI);
    // diboson_gg_ZZ_2mu2tau_aphmin->Draw("hist");
    diboson_gg_ZZ_2mu2tau_met->Draw("hist");
    c1->cd(6);
    diboson_gg_ZZ_4e_aphmin->SetTitle("gg_ZZ_4e");
    diboson_gg_ZZ_4e_met->SetTitle("gg_ZZ_4e");
    diboson_gg_ZZ_4e_aphmin->SetFillColor(HIWAMOEGI);
    diboson_gg_ZZ_4e_met->SetFillColor(HIWAMOEGI);
    // diboson_gg_ZZ_4e_aphmin->Draw("hist");
    diboson_gg_ZZ_4e_met->Draw("hist");
    c1->cd(7);
    diboson_gg_ZZ_4mu_aphmin->SetTitle("gg_ZZ_4mu");
    diboson_gg_ZZ_4mu_met->SetTitle("gg_ZZ_4mu");
    diboson_gg_ZZ_4mu_aphmin->SetFillColor(HIWAMOEGI);
    diboson_gg_ZZ_4mu_met->SetFillColor(HIWAMOEGI);
    // diboson_gg_ZZ_4mu_aphmin->Draw("hist");
    diboson_gg_ZZ_4mu_met->Draw("hist");
    c1->cd(8);
    diboson_gg_ZZ_4tau_aphmin->SetTitle("gg_ZZ_4tau");
    diboson_gg_ZZ_4tau_met->SetTitle("gg_ZZ_4tau");
    diboson_gg_ZZ_4tau_aphmin->SetFillColor(HIWAMOEGI);
    diboson_gg_ZZ_4tau_met->SetFillColor(HIWAMOEGI);
    // diboson_gg_ZZ_4tau_aphmin->Draw("hist");
    diboson_gg_ZZ_4tau_met->Draw("hist");
    c1->cd(9);
    diboson_gg_WW_2L2Nu_aphmin->SetTitle("gg_WW_2L2Nu");
    diboson_gg_WW_2L2Nu_met->SetTitle("gg_WW_2L2Nu");
    diboson_gg_WW_2L2Nu_aphmin->SetFillColor(HIWAMOEGI);
    diboson_gg_WW_2L2Nu_met->SetFillColor(HIWAMOEGI);
    // diboson_gg_WW_2L2Nu_aphmin->Draw("hist");
    diboson_gg_WW_2L2Nu_met->Draw("hist");
    c1->cd(10);
    diboson_qq_WW_2L2Nu_aphmin->SetTitle("qq_WW_2L2Nu");
    diboson_qq_WW_2L2Nu_met->SetTitle("qq_WW_2L2Nu");
    diboson_qq_WW_2L2Nu_aphmin->SetFillColor(HIWAMOEGI);
    diboson_qq_WW_2L2Nu_met->SetFillColor(HIWAMOEGI);
    // diboson_qq_WW_2L2Nu_aphmin->Draw("hist");
    diboson_qq_WW_2L2Nu_met->Draw("hist");
    c1->cd(11);
    diboson_qq_WZ_2L2Q_aphmin->SetTitle("qq_WZ_2L2Q");
    diboson_qq_WZ_2L2Q_met->SetTitle("qq_WZ_2L2Q");
    diboson_qq_WZ_2L2Q_aphmin->SetFillColor(HIWAMOEGI);
    diboson_qq_WZ_2L2Q_met->SetFillColor(HIWAMOEGI);
    // diboson_qq_WZ_2L2Q_aphmin->Draw("hist");
    diboson_qq_WZ_2L2Q_met->Draw("hist");
    c1->cd(12);
    diboson_qq_WZ_3LNu_aphmin->SetTitle("qq_WZ_3LNu");
    diboson_qq_WZ_3LNu_met->SetTitle("qq_WZ_3LNu");
    diboson_qq_WZ_3LNu_aphmin->SetFillColor(HIWAMOEGI);
    diboson_qq_WZ_3LNu_met->SetFillColor(HIWAMOEGI);
    // diboson_qq_WZ_3LNu_aphmin->Draw("hist");
    diboson_qq_WZ_3LNu_met->Draw("hist");
    c1->cd(13);
    diboson_qq_ZZ_2L2Nu_aphmin->SetTitle("qq_ZZ_2L2Nu");
    diboson_qq_ZZ_2L2Nu_met->SetTitle("qq_ZZ_2L2Nu");
    diboson_qq_ZZ_2L2Nu_aphmin->SetFillColor(HIWAMOEGI);
    diboson_qq_ZZ_2L2Nu_met->SetFillColor(HIWAMOEGI);
    // diboson_qq_ZZ_2L2Nu_aphmin->Draw("hist");
    diboson_qq_ZZ_2L2Nu_met->Draw("hist");
    c1->cd(14);
    diboson_qq_ZZ_2L2Q_aphmin->SetTitle("qq_ZZ_2L2Q");
    diboson_qq_ZZ_2L2Q_met->SetTitle("qq_ZZ_2L2Q");
    diboson_qq_ZZ_2L2Q_aphmin->SetFillColor(HIWAMOEGI);
    diboson_qq_ZZ_2L2Q_met->SetFillColor(HIWAMOEGI);
    // diboson_qq_ZZ_2L2Q_aphmin->Draw("hist");
    diboson_qq_ZZ_2L2Q_met->Draw("hist");
    c1->cd(15);
    diboson_qq_ZZ_4L_aphmin->SetTitle("qq_ZZ_4L");
    diboson_qq_ZZ_4L_met->SetTitle("qq_ZZ_4L");
    diboson_qq_ZZ_4L_aphmin->SetFillColor(HIWAMOEGI);
    diboson_qq_ZZ_4L_met->SetFillColor(HIWAMOEGI);
    // diboson_qq_ZZ_4L_aphmin->Draw("hist");
    diboson_qq_ZZ_4L_met->Draw("hist");

    diboson_gg_ZZ_2e2mu_met->Add(diboson_gg_ZZ_2e2nu_met);
    diboson_gg_ZZ_2e2mu_met->Add(diboson_gg_ZZ_2e2tau_met);
    diboson_gg_ZZ_2e2mu_met->Add(diboson_gg_ZZ_2mu2nu_met);
    diboson_gg_ZZ_2e2mu_met->Add(diboson_gg_ZZ_2mu2tau_met);
    diboson_gg_ZZ_2e2mu_met->Add(diboson_gg_ZZ_4e_met);
    diboson_gg_ZZ_2e2mu_met->Add(diboson_gg_ZZ_4mu_met);
    diboson_gg_ZZ_2e2mu_met->Add(diboson_gg_ZZ_4tau_met);

    diboson_gg_ZZ_2e2mu_aphmin->Add(diboson_gg_ZZ_2e2nu_aphmin);
    diboson_gg_ZZ_2e2mu_aphmin->Add(diboson_gg_ZZ_2e2tau_aphmin);
    diboson_gg_ZZ_2e2mu_aphmin->Add(diboson_gg_ZZ_2mu2nu_aphmin);
    diboson_gg_ZZ_2e2mu_aphmin->Add(diboson_gg_ZZ_2mu2tau_aphmin);
    diboson_gg_ZZ_2e2mu_aphmin->Add(diboson_gg_ZZ_4e_aphmin);
    diboson_gg_ZZ_2e2mu_aphmin->Add(diboson_gg_ZZ_4mu_aphmin);
    diboson_gg_ZZ_2e2mu_aphmin->Add(diboson_gg_ZZ_4tau_aphmin);

    diboson_qq_WZ_2L2Q_aphmin->Add(diboson_qq_WZ_3LNu_aphmin);
    diboson_qq_WZ_2L2Q_met->Add(diboson_qq_WZ_3LNu_met);

    diboson_qq_ZZ_2L2Nu_aphmin->Add(diboson_qq_ZZ_2L2Q_aphmin);
    diboson_qq_ZZ_2L2Nu_aphmin->Add(diboson_qq_ZZ_4L_aphmin);

    diboson_qq_ZZ_2L2Nu_met->Add(diboson_qq_ZZ_2L2Q_met);
    diboson_qq_ZZ_2L2Nu_met->Add(diboson_qq_ZZ_4L_met);

    TFile *outFile = new TFile("./../../root_file/Ztoee/Diboson_All.root", "RECREATE");
    outFile->cd();
    // diboson_gg_ZZ_2e2mu_met->Write();
    // diboson_gg_ZZ_2e2mu_aphmin->Write();
    // diboson_gg_ZZ_2e2nu_aphmin->Write();
    // diboson_gg_ZZ_2e2nu_met->Write();
    // diboson_gg_ZZ_2e2tau_aphmin->Write();
    // diboson_gg_ZZ_2e2tau_met->Write();
    // diboson_gg_ZZ_2mu2nu_aphmin->Write();
    // diboson_gg_ZZ_2mu2nu_met->Write();
    // diboson_gg_ZZ_2mu2tau_aphmin->Write();
    // diboson_gg_ZZ_2mu2tau_met->Write();
    // diboson_gg_ZZ_4e_aphmin->Write();
    // diboson_gg_ZZ_4e_met->Write();
    // diboson_gg_ZZ_4mu_aphmin->Write();
    // diboson_gg_ZZ_4mu_met->Write();
    // diboson_gg_ZZ_4tau_aphmin->Write();
    // diboson_gg_ZZ_4tau_met->Write();
    diboson_gg_ZZ_2e2mu_met->Write();
    diboson_gg_ZZ_2e2mu_aphmin->Write();

    diboson_gg_WW_2L2Nu_aphmin->Write();
    diboson_gg_WW_2L2Nu_met->Write();

    diboson_qq_WW_2L2Nu_aphmin->Write();
    diboson_qq_WW_2L2Nu_met->Write();

    diboson_qq_WZ_2L2Q_aphmin->Write();
    diboson_qq_WZ_2L2Q_met->Write();

    diboson_qq_ZZ_2L2Nu_aphmin->Write();
    diboson_qq_ZZ_2L2Nu_met->Write();

    outFile->Close();
}