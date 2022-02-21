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

void HT_fakerate()
{
    // setNCUStyle(true);
    //--------------
    //  Input Files
    //--------------
    TFile *DYincli = new TFile("./../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");
    TFile *DYHT70 = new TFile("./../../root_file/Ztoee/2016BKGMC/DY/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));

    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("Event_Variable/h_totevent"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("Event_Variable/h_totevent"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("Event_Variable/h_totevent"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("Event_Variable/h_totevent"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("Event_Variable/h_totevent"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("Event_Variable/h_totevent"));

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

    Int_t I_ht0_Jethadronflavor, I_ht70_Jethadronflavor, I_ht100_Jethadronflavor, I_ht200_Jethadronflavor, I_ht400_Jethadronflavor,
        I_ht600_Jethadronflavor, I_ht800_Jethadronflavor, I_ht1200_Jethadronflavor, I_ht2500_Jethadronflavor;

    vector<float> *v_ht0_fakeJetPt = new vector<float>();
    vector<float> *v_ht70_fakeJetPt = new vector<float>();
    vector<float> *v_ht100_fakeJetPt = new vector<float>();
    vector<float> *v_ht200_fakeJetPt = new vector<float>();
    vector<float> *v_ht400_fakeJetPt = new vector<float>();
    vector<float> *v_ht600_fakeJetPt = new vector<float>();
    vector<float> *v_ht800_fakeJetPt = new vector<float>();
    vector<float> *v_ht1200_fakeJetPt = new vector<float>();
    vector<float> *v_ht2500_fakeJetPt = new vector<float>();

    vector<float> *v_ht0_fakealpha = new vector<float>();
    vector<float> *v_ht70_fakealpha = new vector<float>();
    vector<float> *v_ht100_fakealpha = new vector<float>();
    vector<float> *v_ht200_fakealpha = new vector<float>();
    vector<float> *v_ht400_fakealpha = new vector<float>();
    vector<float> *v_ht600_fakealpha = new vector<float>();
    vector<float> *v_ht800_fakealpha = new vector<float>();
    vector<float> *v_ht1200_fakealpha = new vector<float>();
    vector<float> *v_ht2500_fakealpha = new vector<float>();

    vector<float> *v_ht0_fakeJetEta = new vector<float>();
    vector<float> *v_ht70_fakeJetEta = new vector<float>();
    vector<float> *v_ht100_fakeJetEta = new vector<float>();
    vector<float> *v_ht200_fakeJetEta = new vector<float>();
    vector<float> *v_ht400_fakeJetEta = new vector<float>();
    vector<float> *v_ht600_fakeJetEta = new vector<float>();
    vector<float> *v_ht800_fakeJetEta = new vector<float>();
    vector<float> *v_ht1200_fakeJetEta = new vector<float>();
    vector<float> *v_ht2500_fakeJetEta = new vector<float>();

    //--------------
    // Clear vector
    //--------------
    v_ht0_fakeJetPt->clear();
    v_ht70_fakeJetPt->clear();
    v_ht100_fakeJetPt->clear();
    v_ht200_fakeJetPt->clear();
    v_ht400_fakeJetPt->clear();
    v_ht600_fakeJetPt->clear();
    v_ht800_fakeJetPt->clear();
    v_ht1200_fakeJetPt->clear();
    v_ht2500_fakeJetPt->clear();
    v_ht0_fakealpha->clear();
    v_ht70_fakealpha->clear();
    v_ht100_fakealpha->clear();
    v_ht200_fakealpha->clear();
    v_ht400_fakealpha->clear();
    v_ht600_fakealpha->clear();
    v_ht800_fakealpha->clear();
    v_ht1200_fakealpha->clear();
    v_ht2500_fakealpha->clear();
    v_ht0_fakeJetEta->clear();
    v_ht70_fakeJetEta->clear();
    v_ht100_fakeJetEta->clear();
    v_ht200_fakeJetEta->clear();
    v_ht400_fakeJetEta->clear();
    v_ht600_fakeJetEta->clear();
    v_ht800_fakeJetEta->clear();
    v_ht1200_fakeJetEta->clear();
    v_ht2500_fakeJetEta->clear();

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

    //--------------------
    // Create Histrogram
    //--------------------
    TH1F *h_ht0_minjetpt = new TH1F("h_ht0_minjetpt", "alphamin jet pt", 50, 0, 500);
    h_ht0_minjetpt->Sumw2();
    TH1F *h_ht70_minjetpt = new TH1F("h_ht70_minjetpt", "alphamin jet pt", 50, 0, 500);
    h_ht70_minjetpt->Sumw2();
    TH1F *h_ht100_minjetpt = new TH1F("h_ht100_minjetpt", "alphamin jet pt", 50, 0, 500);
    h_ht100_minjetpt->Sumw2();
    TH1F *h_ht200_minjetpt = new TH1F("h_ht200_minjetpt", "alphamin jet pt", 50, 0, 500);
    h_ht200_minjetpt->Sumw2();
    TH1F *h_ht400_minjetpt = new TH1F("h_ht400_minjetpt", "alphamin jet pt", 50, 0, 500);
    h_ht400_minjetpt->Sumw2();
    TH1F *h_ht600_minjetpt = new TH1F("h_ht600_minjetpt", "alphamin jet pt", 50, 0, 500);
    h_ht600_minjetpt->Sumw2();
    TH1F *h_ht800_minjetpt = new TH1F("h_ht800_minjetpt", "alphamin jet pt", 50, 0, 500);
    h_ht800_minjetpt->Sumw2();
    TH1F *h_ht1200_minjetpt = new TH1F("h_ht1200_minjetpt", "alphamin jet pt", 50, 0, 500);
    h_ht1200_minjetpt->Sumw2();
    TH1F *h_ht2500_minjetpt = new TH1F("h_ht2500_minjetpt", "alphamin jet pt", 50, 0, 500);
    h_ht2500_minjetpt->Sumw2();


    TH1F *h_ht0_barr_hev_emergjetpt = new TH1F("h_ht0_barr_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_barr_hev_emergjetpt->Sumw2();
    TH1F *h_ht70_barr_hev_emergjetpt = new TH1F("h_ht70_barr_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_barr_hev_emergjetpt->Sumw2();
    TH1F *h_ht100_barr_hev_emergjetpt = new TH1F("h_ht100_barr_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_barr_hev_emergjetpt->Sumw2();
    TH1F *h_ht200_barr_hev_emergjetpt = new TH1F("h_ht200_barr_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_barr_hev_emergjetpt->Sumw2();
    TH1F *h_ht400_barr_hev_emergjetpt = new TH1F("h_ht400_barr_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_barr_hev_emergjetpt->Sumw2();
    TH1F *h_ht600_barr_hev_emergjetpt = new TH1F("h_ht600_barr_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_barr_hev_emergjetpt->Sumw2();
    TH1F *h_ht800_barr_hev_emergjetpt = new TH1F("h_ht800_barr_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_barr_hev_emergjetpt->Sumw2();
    TH1F *h_ht1200_barr_hev_emergjetpt = new TH1F("h_ht1200_barr_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_barr_hev_emergjetpt->Sumw2();
    TH1F *h_ht2500_barr_hev_emergjetpt = new TH1F("h_ht2500_barr_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_barr_hev_emergjetpt->Sumw2();

    TH1F *h_ht0_light_emergjetpt = new TH1F("h_ht0_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_light_emergjetpt->Sumw2();
    TH1F *h_ht70_light_emergjetpt = new TH1F("h_ht70_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_light_emergjetpt->Sumw2();
    TH1F *h_ht100_light_emergjetpt = new TH1F("h_ht100_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_light_emergjetpt->Sumw2();
    TH1F *h_ht200_light_emergjetpt = new TH1F("h_ht200_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_light_emergjetpt->Sumw2();
    TH1F *h_ht400_light_emergjetpt = new TH1F("h_ht400_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_light_emergjetpt->Sumw2();
    TH1F *h_ht600_light_emergjetpt = new TH1F("h_ht600_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_light_emergjetpt->Sumw2();
    TH1F *h_ht800_light_emergjetpt = new TH1F("h_ht800_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_light_emergjetpt->Sumw2();
    TH1F *h_ht1200_light_emergjetpt = new TH1F("h_ht1200_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_light_emergjetpt->Sumw2();
    TH1F *h_ht2500_light_emergjetpt = new TH1F("h_ht2500_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_light_emergjetpt->Sumw2();

    TH1F *h_ht0_barr_light_emergjetpt = new TH1F("h_ht0_barr_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_barr_light_emergjetpt->Sumw2();
    TH1F *h_ht70_barr_light_emergjetpt = new TH1F("h_ht70_barr_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_barr_light_emergjetpt->Sumw2();
    TH1F *h_ht100_barr_light_emergjetpt = new TH1F("h_ht100_barr_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_barr_light_emergjetpt->Sumw2();
    TH1F *h_ht200_barr_light_emergjetpt = new TH1F("h_ht200_barr_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_barr_light_emergjetpt->Sumw2();
    TH1F *h_ht400_barr_light_emergjetpt = new TH1F("h_ht400_barr_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_barr_light_emergjetpt->Sumw2();
    TH1F *h_ht600_barr_light_emergjetpt = new TH1F("h_ht600_barr_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_barr_light_emergjetpt->Sumw2();
    TH1F *h_ht800_barr_light_emergjetpt = new TH1F("h_ht800_barr_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_barr_light_emergjetpt->Sumw2();
    TH1F *h_ht1200_barr_light_emergjetpt = new TH1F("h_ht1200_barr_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_barr_light_emergjetpt->Sumw2();
    TH1F *h_ht2500_barr_light_emergjetpt = new TH1F("h_ht2500_barr_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_barr_light_emergjetpt->Sumw2();

    TH1F *h_ht0_hev_emergjetpt_cutalpha = new TH1F("h_ht0_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht0_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht70_hev_emergjetpt_cutalpha = new TH1F("h_ht70_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht70_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht100_hev_emergjetpt_cutalpha = new TH1F("h_ht100_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht100_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht200_hev_emergjetpt_cutalpha = new TH1F("h_ht200_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht200_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht400_hev_emergjetpt_cutalpha = new TH1F("h_ht400_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht400_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht600_hev_emergjetpt_cutalpha = new TH1F("h_ht600_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht600_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht800_hev_emergjetpt_cutalpha = new TH1F("h_ht800_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht800_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht1200_hev_emergjetpt_cutalpha = new TH1F("h_ht1200_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht1200_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht2500_hev_emergjetpt_cutalpha = new TH1F("h_ht2500_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht2500_hev_emergjetpt_cutalpha->Sumw2();

    TH1F *h_ht0_barr_hev_emergjetpt_cutalpha = new TH1F("h_ht0_barr_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht0_barr_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht70_barr_hev_emergjetpt_cutalpha = new TH1F("h_ht70_barr_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht70_barr_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht100_barr_hev_emergjetpt_cutalpha = new TH1F("h_ht100_barr_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht100_barr_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht200_barr_hev_emergjetpt_cutalpha = new TH1F("h_ht200_barr_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht200_barr_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht400_barr_hev_emergjetpt_cutalpha = new TH1F("h_ht400_barr_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht400_barr_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht600_barr_hev_emergjetpt_cutalpha = new TH1F("h_ht600_barr_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht600_barr_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht800_barr_hev_emergjetpt_cutalpha = new TH1F("h_ht800_barr_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht800_barr_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht1200_barr_hev_emergjetpt_cutalpha = new TH1F("h_ht1200_barr_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht1200_barr_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht2500_barr_hev_emergjetpt_cutalpha = new TH1F("h_ht2500_barr_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht2500_barr_hev_emergjetpt_cutalpha->Sumw2();

    TH1F *h_ht0_light_emergjetpt_cutalpha = new TH1F("h_ht0_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht0_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht70_light_emergjetpt_cutalpha = new TH1F("h_ht70_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht70_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht100_light_emergjetpt_cutalpha = new TH1F("h_ht100_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht100_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht200_light_emergjetpt_cutalpha = new TH1F("h_ht200_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht200_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht400_light_emergjetpt_cutalpha = new TH1F("h_ht400_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht400_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht600_light_emergjetpt_cutalpha = new TH1F("h_ht600_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht600_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht800_light_emergjetpt_cutalpha = new TH1F("h_ht800_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht800_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht1200_light_emergjetpt_cutalpha = new TH1F("h_ht1200_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht1200_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht2500_light_emergjetpt_cutalpha = new TH1F("h_ht2500_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht2500_light_emergjetpt_cutalpha->Sumw2();

    TH1F *h_ht0_barr_light_emergjetpt_cutalpha = new TH1F("h_ht0_barr_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht0_barr_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht70_barr_light_emergjetpt_cutalpha = new TH1F("h_ht70_barr_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht70_barr_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht100_barr_light_emergjetpt_cutalpha = new TH1F("h_ht100_barr_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht100_barr_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht200_barr_light_emergjetpt_cutalpha = new TH1F("h_ht200_barr_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht200_barr_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht400_barr_light_emergjetpt_cutalpha = new TH1F("h_ht400_barr_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht400_barr_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht600_barr_light_emergjetpt_cutalpha = new TH1F("h_ht600_barr_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht600_barr_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht800_barr_light_emergjetpt_cutalpha = new TH1F("h_ht800_barr_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht800_barr_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht1200_barr_light_emergjetpt_cutalpha = new TH1F("h_ht1200_barr_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht1200_barr_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht2500_barr_light_emergjetpt_cutalpha = new TH1F("h_ht2500_barr_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht2500_barr_light_emergjetpt_cutalpha->Sumw2();

    TH1F *h_ht0_hev_emergjetEta = new TH1F("h_ht0_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht0_hev_emergjetEta->Sumw2();
    TH1F *h_ht70_hev_emergjetEta = new TH1F("h_ht70_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht70_hev_emergjetEta->Sumw2();
    TH1F *h_ht100_hev_emergjetEta = new TH1F("h_ht100_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht100_hev_emergjetEta->Sumw2();
    TH1F *h_ht200_hev_emergjetEta = new TH1F("h_ht200_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht200_hev_emergjetEta->Sumw2();
    TH1F *h_ht400_hev_emergjetEta = new TH1F("h_ht400_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht400_hev_emergjetEta->Sumw2();
    TH1F *h_ht600_hev_emergjetEta = new TH1F("h_ht600_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht600_hev_emergjetEta->Sumw2();
    TH1F *h_ht800_hev_emergjetEta = new TH1F("h_ht800_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht800_hev_emergjetEta->Sumw2();
    TH1F *h_ht1200_hev_emergjetEta = new TH1F("h_ht1200_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht1200_hev_emergjetEta->Sumw2();
    TH1F *h_ht2500_hev_emergjetEta = new TH1F("h_ht2500_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht2500_hev_emergjetEta->Sumw2();

    TH1F *h_ht0_light_emergjetEta = new TH1F("h_ht0_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht0_light_emergjetEta->Sumw2();
    TH1F *h_ht70_light_emergjetEta = new TH1F("h_ht70_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht70_light_emergjetEta->Sumw2();
    TH1F *h_ht100_light_emergjetEta = new TH1F("h_ht100_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht100_light_emergjetEta->Sumw2();
    TH1F *h_ht200_light_emergjetEta = new TH1F("h_ht200_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht200_light_emergjetEta->Sumw2();
    TH1F *h_ht400_light_emergjetEta = new TH1F("h_ht400_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht400_light_emergjetEta->Sumw2();
    TH1F *h_ht600_light_emergjetEta = new TH1F("h_ht600_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht600_light_emergjetEta->Sumw2();
    TH1F *h_ht800_light_emergjetEta = new TH1F("h_ht800_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht800_light_emergjetEta->Sumw2();
    TH1F *h_ht1200_light_emergjetEta = new TH1F("h_ht1200_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht1200_light_emergjetEta->Sumw2();
    TH1F *h_ht2500_light_emergjetEta = new TH1F("h_ht2500_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_ht2500_light_emergjetEta->Sumw2();

    //-----------------------
    // hev Jet Eta low Jet PT
    //-----------------------
    TH1F *h_ht0_hev_emergjetEta_lowJetPt = new TH1F("h_ht0_hev_emergjetEta_lowJetPt", "emerging jet Eta", 60, -3, 3);
    h_ht0_hev_emergjetEta_lowJetPt->Sumw2();
    TH1F *h_ht70_hev_emergjetEta_lowJetPt = new TH1F("h_ht70_hev_emergjetEta_lowJetPt", "emerging jet Eta", 60, -3, 3);
    h_ht70_hev_emergjetEta_lowJetPt->Sumw2();
    TH1F *h_ht100_hev_emergjetEta_lowJetPt = new TH1F("h_ht100_hev_emergjetEta_lowJetPt", "emerging jet Eta", 60, -3, 3);
    h_ht100_hev_emergjetEta_lowJetPt->Sumw2();
    TH1F *h_ht200_hev_emergjetEta_lowJetPt = new TH1F("h_ht200_hev_emergjetEta_lowJetPt", "emerging jet Eta", 60, -3, 3);
    h_ht200_hev_emergjetEta_lowJetPt->Sumw2();
    TH1F *h_ht400_hev_emergjetEta_lowJetPt = new TH1F("h_ht400_hev_emergjetEta_lowJetPt", "emerging jet Eta", 60, -3, 3);
    h_ht400_hev_emergjetEta_lowJetPt->Sumw2();
    TH1F *h_ht600_hev_emergjetEta_lowJetPt = new TH1F("h_ht600_hev_emergjetEta_lowJetPt", "emerging jet Eta", 60, -3, 3);
    h_ht600_hev_emergjetEta_lowJetPt->Sumw2();
    TH1F *h_ht800_hev_emergjetEta_lowJetPt = new TH1F("h_ht800_hev_emergjetEta_lowJetPt", "emerging jet Eta", 60, -3, 3);
    h_ht800_hev_emergjetEta_lowJetPt->Sumw2();
    TH1F *h_ht1200_hev_emergjetEta_lowJetPt = new TH1F("h_ht1200_hev_emergjetEta_lowJetPt", "emerging jet Eta", 60, -3, 3);
    h_ht1200_hev_emergjetEta_lowJetPt->Sumw2();
    TH1F *h_ht2500_hev_emergjetEta_lowJetPt = new TH1F("h_ht2500_hev_emergjetEta_lowJetPt", "emerging jet Eta", 60, -3, 3);
    h_ht2500_hev_emergjetEta_lowJetPt->Sumw2();
    //-----------------------
    // hev Jet Eta cut alpha
    //-----------------------
    TH1F *h_ht0_hev_emergjetEta_cutalpha = new TH1F("h_ht0_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht0_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht70_hev_emergjetEta_cutalpha = new TH1F("h_ht70_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht70_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht100_hev_emergjetEta_cutalpha = new TH1F("h_ht100_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht100_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht200_hev_emergjetEta_cutalpha = new TH1F("h_ht200_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht200_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht400_hev_emergjetEta_cutalpha = new TH1F("h_ht400_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht400_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht600_hev_emergjetEta_cutalpha = new TH1F("h_ht600_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht600_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht800_hev_emergjetEta_cutalpha = new TH1F("h_ht800_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht800_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht1200_hev_emergjetEta_cutalpha = new TH1F("h_ht1200_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht1200_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht2500_hev_emergjetEta_cutalpha = new TH1F("h_ht2500_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht2500_hev_emergjetEta_cutalpha->Sumw2();

    TH1F *h_ht0_barr_hev_emergjetEta_cutalpha = new TH1F("h_ht0_barr_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht0_barr_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht70_barr_hev_emergjetEta_cutalpha = new TH1F("h_ht70_barr_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht70_barr_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht100_barr_hev_emergjetEta_cutalpha = new TH1F("h_ht100_barr_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht100_barr_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht200_barr_hev_emergjetEta_cutalpha = new TH1F("h_ht200_barr_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht200_barr_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht400_barr_hev_emergjetEta_cutalpha = new TH1F("h_ht400_barr_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht400_barr_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht600_barr_hev_emergjetEta_cutalpha = new TH1F("h_ht600_barr_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht600_barr_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht800_barr_hev_emergjetEta_cutalpha = new TH1F("h_ht800_barr_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht800_barr_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht1200_barr_hev_emergjetEta_cutalpha = new TH1F("h_ht1200_barr_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht1200_barr_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht2500_barr_hev_emergjetEta_cutalpha = new TH1F("h_ht2500_barr_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht2500_barr_hev_emergjetEta_cutalpha->Sumw2();

    TH1F *h_ht0_light_emergjetEta_cutalpha = new TH1F("h_ht0_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht0_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht70_light_emergjetEta_cutalpha = new TH1F("h_ht70_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht70_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht100_light_emergjetEta_cutalpha = new TH1F("h_ht100_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht100_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht200_light_emergjetEta_cutalpha = new TH1F("h_ht200_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht200_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht400_light_emergjetEta_cutalpha = new TH1F("h_ht400_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht400_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht600_light_emergjetEta_cutalpha = new TH1F("h_ht600_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht600_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht800_light_emergjetEta_cutalpha = new TH1F("h_ht800_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht800_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht1200_light_emergjetEta_cutalpha = new TH1F("h_ht1200_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht1200_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht2500_light_emergjetEta_cutalpha = new TH1F("h_ht2500_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht2500_light_emergjetEta_cutalpha->Sumw2();

    TH1F *h_ht0_barr_light_emergjetEta_cutalpha = new TH1F("h_ht0_barr_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht0_barr_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht70_barr_light_emergjetEta_cutalpha = new TH1F("h_ht70_barr_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht70_barr_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht100_barr_light_emergjetEta_cutalpha = new TH1F("h_ht100_barr_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht100_barr_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht200_barr_light_emergjetEta_cutalpha = new TH1F("h_ht200_barr_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht200_barr_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht400_barr_light_emergjetEta_cutalpha = new TH1F("h_ht400_barr_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht400_barr_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht600_barr_light_emergjetEta_cutalpha = new TH1F("h_ht600_barr_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht600_barr_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht800_barr_light_emergjetEta_cutalpha = new TH1F("h_ht800_barr_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht800_barr_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht1200_barr_light_emergjetEta_cutalpha = new TH1F("h_ht1200_barr_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht1200_barr_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht2500_barr_light_emergjetEta_cutalpha = new TH1F("h_ht2500_barr_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_ht2500_barr_light_emergjetEta_cutalpha->Sumw2();

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
    T_event->SetBranchAddress("I_minJethadronflavor", &I_ht0_Jethadronflavor);
    T_event->SetBranchAddress("I_disJet_multiplicity", &I_ht0_disJet_multiplicity);
    T_event->SetBranchAddress("v_fakeJetPt", &v_ht0_fakeJetPt);
    T_event->SetBranchAddress("v_fakealpha", &v_ht0_fakealpha);
    T_event->SetBranchAddress("v_fakeJetEta", &v_ht0_fakeJetEta);

    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (I_ht0_nThinJets < 2)
            continue;
        if (I_ht0_Jethadronflavor == 4 || I_ht0_Jethadronflavor == 5)
        {
            if (HT < 70)
            {
                h_ht0_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT0Weight);
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht0_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT0Weight);
                    h_ht0_hev_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT0Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) < 1)
                    {
                        h_ht0_barr_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT0Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht0_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT0Weight);
                        h_ht0_hev_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT0Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht0_barr_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT0Weight);
                        }
                        if ((*v_ht0_fakeJetPt)[i] < 100)
                        {
                            h_ht0_hev_emergjetEta_lowJetPt->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT0Weight);
                        }
                    }
                }
            }
            else if (HT >= 70 && HT < 100)
            {
                h_ht70_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT70Weight);
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht70_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT70Weight);
                    h_ht70_hev_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT70Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht70_barr_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT70Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht70_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT70Weight);
                        h_ht70_hev_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT70Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht70_barr_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT70Weight);
                        }
                        if ((*v_ht0_fakeJetPt)[i] < 100)
                        {
                            h_ht70_hev_emergjetEta_lowJetPt->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT70Weight);
                        }
                    }
                }
            }
            else if (HT >= 100 && HT < 200)
            {
                h_ht100_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT100Weight);

                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht100_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT100Weight);
                    h_ht100_hev_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT100Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht100_barr_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT100Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht100_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT100Weight);
                        h_ht100_hev_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT100Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht100_barr_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT100Weight);
                        }
                        if ((*v_ht0_fakeJetPt)[i] < 100)
                        {
                            h_ht100_hev_emergjetEta_lowJetPt->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT100Weight);
                        }
                    }
                }
            }
            else if (HT >= 200 && HT < 400)
            {
                h_ht200_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT200Weight);

                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht200_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT200Weight);
                    h_ht200_hev_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT200Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht200_barr_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT200Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht200_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT200Weight);
                        h_ht200_hev_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT200Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht200_barr_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT200Weight);
                        }
                        if ((*v_ht0_fakeJetPt)[i] < 100)
                        {
                            h_ht200_hev_emergjetEta_lowJetPt->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT200Weight);
                        }
                    }
                }
            }
            else if (HT >= 400 && HT < 600)
            {
                h_ht400_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT400Weight);
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht400_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT400Weight);
                    h_ht400_hev_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT400Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht400_barr_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT400Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht400_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT400Weight);
                        h_ht400_hev_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT400Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht400_barr_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT400Weight);
                        }
                        if ((*v_ht0_fakeJetPt)[i] < 100)
                        {
                            h_ht400_hev_emergjetEta_lowJetPt->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT400Weight);
                        }
                    }
                }
            }
            else if (HT >= 600 && HT < 800)
            {
                h_ht600_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT600Weight);

                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht600_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT600Weight);
                    h_ht600_hev_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT600Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht600_barr_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT600Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht600_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT600Weight);
                        h_ht600_hev_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT600Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht600_barr_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT600Weight);
                        }
                        if ((*v_ht0_fakeJetPt)[i] < 100)
                        {
                            h_ht600_hev_emergjetEta_lowJetPt->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT600Weight);
                        }
                    }
                }
            }
            else if (HT >= 800 && HT < 1200)
            {
                h_ht800_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT800Weight);

                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht800_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT800Weight);
                    h_ht800_hev_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT800Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht800_barr_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT800Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht800_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT800Weight);
                        h_ht800_hev_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT800Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht800_barr_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT800Weight);
                        }
                        if ((*v_ht0_fakeJetPt)[i] < 100)
                        {
                            h_ht800_hev_emergjetEta_lowJetPt->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT800Weight);
                        }
                    }
                }
            }
            else if (HT >= 1200 && HT < 2500)
            {
                h_ht1200_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT1200Weight);
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht1200_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT1200Weight);
                    h_ht1200_hev_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT1200Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht1200_barr_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT1200Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht1200_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT1200Weight);
                        h_ht1200_hev_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT1200Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht1200_barr_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT1200Weight);
                        }
                        if ((*v_ht0_fakeJetPt)[i] < 100)
                        {
                            h_ht1200_hev_emergjetEta_lowJetPt->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT1200Weight);
                        }
                    }
                }
            }

            else if (HT >= 2500)
            {
                h_ht2500_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT2500Weight);
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht2500_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT2500Weight);
                    h_ht2500_hev_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT2500Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht2500_barr_hev_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT2500Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht2500_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT2500Weight);
                        h_ht2500_hev_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT2500Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht2500_barr_hev_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT2500Weight);
                        }
                        if ((*v_ht0_fakeJetPt)[i] < 100)
                        {
                            h_ht2500_hev_emergjetEta_lowJetPt->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT2500Weight);
                        }
                    }
                }
            }
        }
        else
        {
            if (HT < 70)
            {
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht0_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT0Weight);
                    h_ht0_light_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT0Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht0_barr_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT0Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht0_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT0Weight);
                        h_ht0_light_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT0Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht0_barr_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT0Weight);
                        }
                    }
                }
            }
            else if (HT >= 70 && HT < 100)
            {
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht70_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT70Weight);
                    h_ht70_light_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT70Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht70_barr_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT70Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht70_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT70Weight);
                        h_ht70_light_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT70Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht70_barr_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT70Weight);
                        }
                    }
                }
            }
            else if (HT >= 100 && HT < 200)
            {
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht100_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT100Weight);
                    h_ht100_light_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT100Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht100_barr_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT100Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht100_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT100Weight);
                        h_ht100_light_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT100Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht100_barr_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT100Weight);
                        }
                    }
                }
            }
            else if (HT >= 200 && HT < 400)
            {
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht200_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT200Weight);
                    h_ht200_light_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT200Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht200_barr_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT200Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht200_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT200Weight);
                        h_ht200_light_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT200Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht200_barr_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT200Weight);
                        }
                    }
                }
            }
            else if (HT >= 400 && HT < 600)
            {
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht400_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT400Weight);
                    h_ht400_light_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT400Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht400_barr_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT400Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht400_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT400Weight);
                        h_ht400_light_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT400Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht400_barr_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT400Weight);
                        }
                    }
                }
            }
            else if (HT >= 600 && HT < 800)
            {
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht600_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT600Weight);
                    h_ht600_light_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT600Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht600_barr_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT600Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht600_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT600Weight);
                        h_ht600_light_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT600Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht600_barr_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT600Weight);
                        }
                    }
                }
            }
            else if (HT >= 800 && HT < 1200)
            {
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht800_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT800Weight);
                    h_ht800_light_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT800Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht800_barr_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT800Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht800_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT800Weight);
                        h_ht800_light_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT800Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht800_barr_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT800Weight);
                        }
                    }
                }
            }
            else if (HT >= 1200 && HT < 2500)
            {
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht1200_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT1200Weight);
                    h_ht1200_light_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT1200Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht1200_barr_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT1200Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht1200_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT1200Weight);
                        h_ht1200_light_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT1200Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht1200_barr_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT1200Weight);
                        }
                    }
                }
            }
            else if (HT >= 2500)
            {
                for (int i = 0; i < v_ht0_fakeJetPt->size(); i++)
                {
                    h_ht2500_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT2500Weight);
                    h_ht2500_light_emergjetEta->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT2500Weight);
                    if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                    {
                        h_ht2500_barr_light_emergjetpt->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT2500Weight);
                    }
                    if ((*v_ht0_fakealpha)[i] <0.35)
                    {
                        h_ht2500_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT2500Weight);
                        h_ht2500_light_emergjetEta_cutalpha->Fill((*v_ht0_fakeJetEta)[i], I_ht0_weight * HT2500Weight);
                        if (abs((*v_ht0_fakeJetEta)[i]) <= 1)
                        {
                            h_ht2500_barr_light_emergjetpt_cutalpha->Fill((*v_ht0_fakeJetPt)[i], I_ht0_weight * HT2500Weight);
                        }
                    }
                }
            }
        }
    }
    // cout << "bug" << endl;
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
    T_event1->SetBranchAddress("I_minJethadronflavor", &I_ht100_Jethadronflavor);
    T_event1->SetBranchAddress("I_disJet_multiplicity", &I_ht100_disJet_multiplicity);
    T_event1->SetBranchAddress("v_fakeJetPt", &v_ht100_fakeJetPt);
    T_event1->SetBranchAddress("v_fakealpha", &v_ht100_fakealpha);
    T_event1->SetBranchAddress("v_fakeJetEta", &v_ht100_fakeJetEta);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (I_ht100_nThinJets < 2)
            continue;
        if (I_ht100_Jethadronflavor == 4 || I_ht100_Jethadronflavor == 5)
        {
            h_ht100_minjetpt->Fill(f_ht100_minJetpt, I_ht100_weight * HT100Weight);
            for (int i = 0; i < v_ht100_fakeJetPt->size(); i++)
            {
                h_ht100_hev_emergjetpt->Fill((*v_ht100_fakeJetPt)[i], I_ht100_weight * HT100Weight);
                h_ht100_hev_emergjetEta->Fill((*v_ht100_fakeJetEta)[i], I_ht100_weight * HT100Weight);
                if (abs((*v_ht100_fakeJetEta)[i]) <= 1)
                {
                    h_ht100_barr_hev_emergjetpt->Fill((*v_ht100_fakeJetPt)[i], I_ht100_weight * HT100Weight);
                }
                if ((*v_ht100_fakealpha)[i] <0.35)
                {
                    h_ht100_hev_emergjetpt_cutalpha->Fill((*v_ht100_fakeJetPt)[i], I_ht100_weight * HT100Weight);
                    h_ht100_hev_emergjetEta_cutalpha->Fill((*v_ht100_fakeJetEta)[i], I_ht100_weight * HT100Weight);
                    if (abs((*v_ht100_fakeJetEta)[i]) <= 1)
                    {
                        h_ht100_barr_hev_emergjetpt_cutalpha->Fill((*v_ht100_fakeJetPt)[i], I_ht100_weight * HT100Weight);
                    }
                    if ((*v_ht100_fakeJetPt)[i] < 100)
                    {
                        h_ht100_hev_emergjetEta_lowJetPt->Fill((*v_ht100_fakeJetPt)[i], I_ht100_weight * HT100Weight);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < v_ht100_fakeJetPt->size(); i++)
            {
                if (abs((*v_ht100_fakeJetEta)[i]) <= 1)
                {
                    h_ht100_barr_light_emergjetpt->Fill((*v_ht100_fakeJetPt)[i], I_ht100_weight * HT100Weight);
                }
                if ((*v_ht100_fakealpha)[i] <0.35)
                {
                    h_ht100_light_emergjetEta_cutalpha->Fill((*v_ht100_fakeJetEta)[i], I_ht100_weight * HT100Weight);
                    if (abs((*v_ht100_fakeJetEta)[i]) <= 1)
                    {
                        h_ht100_barr_light_emergjetpt_cutalpha->Fill((*v_ht100_fakeJetPt)[i], I_ht100_weight * HT100Weight);
                    }
                }
            }
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
    T_event2->SetBranchAddress("I_minJethadronflavor", &I_ht200_Jethadronflavor);
    T_event2->SetBranchAddress("I_disJet_multiplicity", &I_ht200_disJet_multiplicity);
    T_event2->SetBranchAddress("v_fakeJetPt", &v_ht200_fakeJetPt);
    T_event2->SetBranchAddress("v_fakealpha", &v_ht200_fakealpha);
    T_event2->SetBranchAddress("v_fakeJetEta", &v_ht200_fakeJetEta);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (I_ht200_nThinJets < 2)
            continue;
        if (I_ht200_Jethadronflavor == 4 || I_ht200_Jethadronflavor == 5)
        {
            h_ht200_minjetpt->Fill(f_ht200_minJetpt, I_ht200_weight * HT200Weight);

            for (int i = 0; i < v_ht200_fakeJetPt->size(); i++)
            {
                h_ht200_hev_emergjetpt->Fill((*v_ht200_fakeJetPt)[i], I_ht200_weight * HT200Weight);
                h_ht200_hev_emergjetEta->Fill((*v_ht200_fakeJetEta)[i], I_ht200_weight * HT200Weight);
                if (abs((*v_ht200_fakeJetEta)[i]) <= 1)
                {
                    h_ht200_barr_hev_emergjetpt->Fill((*v_ht200_fakeJetPt)[i], I_ht200_weight * HT200Weight);
                }
                if ((*v_ht200_fakealpha)[i] <0.35)
                {
                    h_ht200_hev_emergjetpt_cutalpha->Fill((*v_ht200_fakeJetPt)[i], I_ht200_weight * HT200Weight);
                    h_ht200_hev_emergjetEta_cutalpha->Fill((*v_ht200_fakeJetEta)[i], I_ht200_weight * HT200Weight);
                    if (abs((*v_ht200_fakeJetEta)[i]) <= 1)
                    {
                        h_ht200_barr_hev_emergjetpt_cutalpha->Fill((*v_ht200_fakeJetPt)[i], I_ht200_weight * HT200Weight);
                    }
                    if ((*v_ht200_fakeJetPt)[i] < 100)
                    {
                        h_ht200_hev_emergjetEta_lowJetPt->Fill((*v_ht200_fakeJetPt)[i], I_ht200_weight * HT200Weight);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < v_ht200_fakeJetPt->size(); i++)
            {
                if (abs((*v_ht200_fakeJetEta)[i]) <= 1)
                {
                    h_ht200_barr_light_emergjetpt->Fill((*v_ht200_fakeJetPt)[i], I_ht200_weight * HT200Weight);
                }
                if ((*v_ht200_fakealpha)[i] <0.35)
                {
                    h_ht200_light_emergjetEta_cutalpha->Fill((*v_ht200_fakeJetEta)[i], I_ht200_weight * HT200Weight);
                    if (abs((*v_ht200_fakeJetEta)[i]) <= 1)
                    {
                        h_ht200_barr_light_emergjetpt_cutalpha->Fill((*v_ht200_fakeJetPt)[i], I_ht200_weight * HT200Weight);
                    }
                }
            }
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
    T_event3->SetBranchAddress("I_minJethadronflavor", &I_ht400_Jethadronflavor);
    T_event3->SetBranchAddress("I_disJet_multiplicity", &I_ht400_disJet_multiplicity);
    T_event3->SetBranchAddress("v_fakeJetPt", &v_ht400_fakeJetPt);
    T_event3->SetBranchAddress("v_fakealpha", &v_ht400_fakealpha);
    T_event3->SetBranchAddress("v_fakeJetEta", &v_ht400_fakeJetEta);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (I_ht400_nThinJets < 2)
            continue;
        if (I_ht400_Jethadronflavor == 4 || I_ht400_Jethadronflavor == 5)
        {
            h_ht400_minjetpt->Fill(f_ht400_minJetpt, I_ht400_weight * HT400Weight);
            for (int i = 0; i < v_ht400_fakeJetPt->size(); i++)
            {
                h_ht400_hev_emergjetpt->Fill((*v_ht400_fakeJetPt)[i], I_ht400_weight * HT400Weight);
                h_ht400_hev_emergjetEta->Fill((*v_ht400_fakeJetEta)[i], I_ht400_weight * HT400Weight);
                if (abs((*v_ht400_fakeJetEta)[i]) <= 1)
                {
                    h_ht400_barr_hev_emergjetpt->Fill((*v_ht400_fakeJetPt)[i], I_ht400_weight * HT400Weight);
                }
                if ((*v_ht400_fakealpha)[i] <0.35)
                {
                    h_ht400_hev_emergjetpt_cutalpha->Fill((*v_ht400_fakeJetPt)[i], I_ht400_weight * HT400Weight);
                    h_ht400_hev_emergjetEta_cutalpha->Fill((*v_ht400_fakeJetEta)[i], I_ht400_weight * HT400Weight);
                    if (abs((*v_ht400_fakeJetEta)[i]) <= 1)
                    {
                        h_ht400_barr_hev_emergjetpt_cutalpha->Fill((*v_ht400_fakeJetPt)[i], I_ht400_weight * HT400Weight);
                    }
                    if ((*v_ht400_fakeJetPt)[i] < 100)
                    {
                        h_ht400_hev_emergjetEta_lowJetPt->Fill((*v_ht400_fakeJetPt)[i], I_ht400_weight * HT400Weight);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < v_ht400_fakeJetPt->size(); i++)
            {
                if (abs((*v_ht400_fakeJetEta)[i]) <= 1)
                {
                    h_ht400_barr_light_emergjetpt->Fill((*v_ht400_fakeJetPt)[i], I_ht400_weight * HT400Weight);
                }
                if ((*v_ht400_fakealpha)[i] <0.35)
                {
                    h_ht400_light_emergjetEta_cutalpha->Fill((*v_ht400_fakeJetEta)[i], I_ht400_weight * HT400Weight);
                    if (abs((*v_ht400_fakeJetEta)[i]) <= 1)
                    {
                        h_ht400_barr_light_emergjetpt_cutalpha->Fill((*v_ht400_fakeJetPt)[i], I_ht400_weight * HT400Weight);
                    }
                }
            }
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
    T_event4->SetBranchAddress("I_minJethadronflavor", &I_ht600_Jethadronflavor);
    T_event4->SetBranchAddress("I_disJet_multiplicity", &I_ht600_disJet_multiplicity);
    T_event4->SetBranchAddress("v_fakeJetPt", &v_ht600_fakeJetPt);
    T_event4->SetBranchAddress("v_fakealpha", &v_ht600_fakealpha);
    T_event4->SetBranchAddress("v_fakeJetEta", &v_ht600_fakeJetEta);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (I_ht600_nThinJets < 2)
            continue;
        if (I_ht600_Jethadronflavor == 4 || I_ht600_Jethadronflavor == 5)
        {
            h_ht600_minjetpt->Fill(f_ht600_minJetpt, I_ht600_weight * HT600Weight);

            for (int i = 0; i < v_ht600_fakeJetPt->size(); i++)
            {
                h_ht600_hev_emergjetpt->Fill((*v_ht600_fakeJetPt)[i], I_ht600_weight * HT600Weight);
                h_ht600_hev_emergjetEta->Fill((*v_ht600_fakeJetEta)[i], I_ht600_weight * HT600Weight);
                if (abs((*v_ht600_fakeJetEta)[i]) <= 1)
                {
                    h_ht600_barr_hev_emergjetpt->Fill((*v_ht600_fakeJetPt)[i], I_ht600_weight * HT600Weight);
                }
                if ((*v_ht600_fakealpha)[i] <0.35)
                {
                    h_ht600_hev_emergjetpt_cutalpha->Fill((*v_ht600_fakeJetPt)[i], I_ht600_weight * HT600Weight);
                    h_ht600_hev_emergjetEta_cutalpha->Fill((*v_ht600_fakeJetEta)[i], I_ht600_weight * HT600Weight);
                    if (abs((*v_ht600_fakeJetEta)[i]) <= 1)
                    {
                        h_ht600_barr_hev_emergjetpt_cutalpha->Fill((*v_ht600_fakeJetPt)[i], I_ht600_weight * HT600Weight);
                    }
                    if ((*v_ht600_fakeJetPt)[i] < 100)
                    {
                        h_ht600_hev_emergjetEta_lowJetPt->Fill((*v_ht600_fakeJetPt)[i], I_ht600_weight * HT600Weight);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < v_ht600_fakeJetPt->size(); i++)
            {
                if (abs((*v_ht600_fakeJetEta)[i]) <= 1)
                {
                    h_ht600_barr_light_emergjetpt->Fill((*v_ht600_fakeJetPt)[i], I_ht600_weight * HT600Weight);
                }
                if ((*v_ht600_fakealpha)[i] <0.35)
                {
                    h_ht600_light_emergjetEta_cutalpha->Fill((*v_ht600_fakeJetEta)[i], I_ht600_weight * HT600Weight);
                    if (abs((*v_ht600_fakeJetEta)[i]) <= 1)
                    {
                        h_ht600_barr_light_emergjetpt_cutalpha->Fill((*v_ht600_fakeJetPt)[i], I_ht600_weight * HT600Weight);
                    }
                }
            }
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
    T_event5->SetBranchAddress("I_minJethadronflavor", &I_ht800_Jethadronflavor);
    T_event5->SetBranchAddress("I_disJet_multiplicity", &I_ht800_disJet_multiplicity);
    T_event5->SetBranchAddress("v_fakeJetPt", &v_ht800_fakeJetPt);
    T_event5->SetBranchAddress("v_fakealpha", &v_ht800_fakealpha);
    T_event5->SetBranchAddress("v_fakeJetEta", &v_ht800_fakeJetEta);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (I_ht800_nThinJets < 2)
            continue;
        if (I_ht800_Jethadronflavor == 4 || I_ht800_Jethadronflavor == 5)
        {
            h_ht800_minjetpt->Fill(f_ht800_minJetpt, I_ht800_weight * HT800Weight);

            for (int i = 0; i < v_ht800_fakeJetPt->size(); i++)
            {
                h_ht800_hev_emergjetpt->Fill((*v_ht800_fakeJetPt)[i], I_ht800_weight * HT800Weight);
                h_ht800_hev_emergjetEta->Fill((*v_ht800_fakeJetEta)[i], I_ht800_weight * HT800Weight);
                if (abs((*v_ht800_fakeJetEta)[i]) <= 1)
                {
                    h_ht800_barr_hev_emergjetpt->Fill((*v_ht800_fakeJetPt)[i], I_ht800_weight * HT800Weight);
                }
                if ((*v_ht800_fakealpha)[i] <0.35)
                {
                    h_ht800_hev_emergjetpt_cutalpha->Fill((*v_ht800_fakeJetPt)[i], I_ht800_weight * HT800Weight);
                    h_ht800_hev_emergjetEta_cutalpha->Fill((*v_ht800_fakeJetEta)[i], I_ht800_weight * HT800Weight);
                    if (abs((*v_ht800_fakeJetEta)[i]) <= 1)
                    {
                        h_ht800_barr_hev_emergjetpt_cutalpha->Fill((*v_ht800_fakeJetPt)[i], I_ht800_weight * HT800Weight);
                    }
                    if ((*v_ht800_fakeJetPt)[i] < 100)
                    {
                        h_ht800_hev_emergjetEta_lowJetPt->Fill((*v_ht800_fakeJetPt)[i], I_ht800_weight * HT800Weight);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < v_ht800_fakeJetPt->size(); i++)
            {
                if (abs((*v_ht800_fakeJetEta)[i]) <= 1)
                {
                    h_ht800_barr_light_emergjetpt->Fill((*v_ht800_fakeJetPt)[i], I_ht800_weight * HT800Weight);
                }
                if ((*v_ht800_fakealpha)[i] <0.35)
                {
                    h_ht800_light_emergjetEta_cutalpha->Fill((*v_ht800_fakeJetEta)[i], I_ht800_weight * HT800Weight);
                    if (abs((*v_ht800_fakeJetEta)[i]) <= 1)
                    {
                        h_ht800_barr_light_emergjetpt_cutalpha->Fill((*v_ht800_fakeJetPt)[i], I_ht800_weight * HT800Weight);
                    }
                }
            }
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
    T_event6->SetBranchAddress("I_minJethadronflavor", &I_ht1200_Jethadronflavor);
    T_event6->SetBranchAddress("I_disJet_multiplicity", &I_ht1200_disJet_multiplicity);
    T_event6->SetBranchAddress("v_fakeJetPt", &v_ht1200_fakeJetPt);
    T_event6->SetBranchAddress("v_fakealpha", &v_ht1200_fakealpha);
    T_event6->SetBranchAddress("v_fakeJetEta", &v_ht1200_fakeJetEta);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (I_ht1200_nThinJets < 2)
            continue;
        if (I_ht1200_Jethadronflavor == 4 || I_ht1200_Jethadronflavor == 5)
        {
            h_ht1200_minjetpt->Fill(f_ht1200_minJetpt, I_ht1200_weight * HT1200Weight);
            for (int i = 0; i < v_ht1200_fakeJetPt->size(); i++)
            {
                h_ht1200_hev_emergjetpt->Fill((*v_ht1200_fakeJetPt)[i], I_ht1200_weight * HT1200Weight);
                h_ht1200_hev_emergjetEta->Fill((*v_ht1200_fakeJetEta)[i], I_ht1200_weight * HT1200Weight);
                if (abs((*v_ht1200_fakeJetEta)[i]) <= 1)
                {
                    h_ht1200_barr_hev_emergjetpt->Fill((*v_ht1200_fakeJetPt)[i], I_ht1200_weight * HT1200Weight);
                }
                if ((*v_ht1200_fakealpha)[i] <0.35)
                {
                    h_ht1200_hev_emergjetpt_cutalpha->Fill((*v_ht1200_fakeJetPt)[i], I_ht1200_weight * HT1200Weight);
                    h_ht1200_hev_emergjetEta_cutalpha->Fill((*v_ht1200_fakeJetEta)[i], I_ht1200_weight * HT1200Weight);
                    if (abs((*v_ht1200_fakeJetEta)[i]) <= 1)
                    {
                        h_ht1200_barr_hev_emergjetpt_cutalpha->Fill((*v_ht1200_fakeJetPt)[i], I_ht1200_weight * HT1200Weight);
                    }
                    if ((*v_ht1200_fakeJetPt)[i] < 100)
                    {
                        h_ht1200_hev_emergjetEta_lowJetPt->Fill((*v_ht1200_fakeJetPt)[i], I_ht1200_weight * HT1200Weight);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < v_ht1200_fakeJetPt->size(); i++)
            {
                if (abs((*v_ht1200_fakeJetEta)[i]) <= 1)
                {
                    h_ht1200_barr_light_emergjetpt->Fill((*v_ht1200_fakeJetPt)[i], I_ht1200_weight * HT1200Weight);
                }
                if ((*v_ht1200_fakealpha)[i] <0.35)
                {
                    h_ht1200_light_emergjetEta_cutalpha->Fill((*v_ht1200_fakeJetEta)[i], I_ht1200_weight * HT1200Weight);
                    if (abs((*v_ht1200_fakeJetEta)[i]) <= 1)
                    {
                        h_ht1200_barr_light_emergjetpt_cutalpha->Fill((*v_ht1200_fakeJetPt)[i], I_ht1200_weight * HT1200Weight);
                    }
                }
            }
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
    T_event7->SetBranchAddress("I_minJethadronflavor", &I_ht2500_Jethadronflavor);
    T_event7->SetBranchAddress("I_disJet_multiplicity", &I_ht2500_disJet_multiplicity);
    T_event7->SetBranchAddress("v_fakeJetPt", &v_ht2500_fakeJetPt);
    T_event7->SetBranchAddress("v_fakealpha", &v_ht2500_fakealpha);
    T_event7->SetBranchAddress("v_fakeJetEta", &v_ht2500_fakeJetEta);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        if (I_ht2500_nThinJets < 2)
            continue;
        if (I_ht2500_Jethadronflavor == 4 || I_ht2500_Jethadronflavor == 5)
        {
            h_ht2500_minjetpt->Fill(f_ht2500_minJetpt, I_ht2500_weight * HT2500Weight);

            for (int i = 0; i < v_ht2500_fakeJetPt->size(); i++)
            {
                h_ht2500_hev_emergjetpt->Fill((*v_ht2500_fakeJetPt)[i], I_ht2500_weight * HT2500Weight);
                h_ht2500_hev_emergjetEta->Fill((*v_ht2500_fakeJetEta)[i], I_ht2500_weight * HT2500Weight);
                if (abs((*v_ht2500_fakeJetEta)[i]) <= 1)
                {
                    h_ht2500_barr_hev_emergjetpt->Fill((*v_ht2500_fakeJetPt)[i], I_ht2500_weight * HT2500Weight);
                }
                if ((*v_ht2500_fakealpha)[i] <0.35)
                {
                    h_ht2500_hev_emergjetpt_cutalpha->Fill((*v_ht2500_fakeJetPt)[i], I_ht2500_weight * HT2500Weight);
                    h_ht2500_hev_emergjetEta_cutalpha->Fill((*v_ht2500_fakeJetEta)[i], I_ht2500_weight * HT2500Weight);
                    if (abs((*v_ht2500_fakeJetEta)[i]) <= 1)
                    {
                        h_ht2500_barr_hev_emergjetpt_cutalpha->Fill((*v_ht2500_fakeJetPt)[i], I_ht2500_weight * HT2500Weight);
                    }
                    if ((*v_ht2500_fakeJetPt)[i] < 100)
                    {
                        h_ht2500_hev_emergjetEta_lowJetPt->Fill((*v_ht2500_fakeJetPt)[i], I_ht2500_weight * HT2500Weight);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < v_ht2500_fakeJetPt->size(); i++)
            {
                if (abs((*v_ht2500_fakeJetEta)[i]) <= 1)
                {
                    h_ht2500_barr_light_emergjetpt->Fill((*v_ht2500_fakeJetPt)[i], I_ht2500_weight * HT2500Weight);
                }
                if ((*v_ht2500_fakealpha)[i] <0.35)
                {
                    h_ht2500_light_emergjetEta_cutalpha->Fill((*v_ht2500_fakeJetEta)[i], I_ht2500_weight * HT2500Weight);
                    if (abs((*v_ht2500_fakeJetEta)[i]) <= 1)
                    {
                        h_ht2500_barr_light_emergjetpt_cutalpha->Fill((*v_ht2500_fakeJetPt)[i], I_ht2500_weight * HT2500Weight);
                    }
                }
            }
        }
    }
    h_ht0_hev_emergjetpt->Add(h_ht70_hev_emergjetpt);
    h_ht0_hev_emergjetpt->Add(h_ht100_hev_emergjetpt);
    h_ht0_hev_emergjetpt->Add(h_ht200_hev_emergjetpt);
    h_ht0_hev_emergjetpt->Add(h_ht400_hev_emergjetpt);
    h_ht0_hev_emergjetpt->Add(h_ht600_hev_emergjetpt);
    h_ht0_hev_emergjetpt->Add(h_ht800_hev_emergjetpt);
    h_ht0_hev_emergjetpt->Add(h_ht1200_hev_emergjetpt);
    h_ht0_hev_emergjetpt->Add(h_ht2500_hev_emergjetpt);

    h_ht0_barr_light_emergjetpt->Add(h_ht70_barr_light_emergjetpt);
    h_ht0_barr_light_emergjetpt->Add(h_ht100_barr_light_emergjetpt);
    h_ht0_barr_light_emergjetpt->Add(h_ht200_barr_light_emergjetpt);
    h_ht0_barr_light_emergjetpt->Add(h_ht400_barr_light_emergjetpt);
    h_ht0_barr_light_emergjetpt->Add(h_ht600_barr_light_emergjetpt);
    h_ht0_barr_light_emergjetpt->Add(h_ht800_barr_light_emergjetpt);
    h_ht0_barr_light_emergjetpt->Add(h_ht1200_barr_light_emergjetpt);
    h_ht0_barr_light_emergjetpt->Add(h_ht2500_barr_light_emergjetpt);

    h_ht0_hev_emergjetpt_cutalpha->Add(h_ht70_hev_emergjetpt_cutalpha);
    h_ht0_hev_emergjetpt_cutalpha->Add(h_ht100_hev_emergjetpt_cutalpha);
    h_ht0_hev_emergjetpt_cutalpha->Add(h_ht200_hev_emergjetpt_cutalpha);
    h_ht0_hev_emergjetpt_cutalpha->Add(h_ht400_hev_emergjetpt_cutalpha);
    h_ht0_hev_emergjetpt_cutalpha->Add(h_ht600_hev_emergjetpt_cutalpha);
    h_ht0_hev_emergjetpt_cutalpha->Add(h_ht800_hev_emergjetpt_cutalpha);
    h_ht0_hev_emergjetpt_cutalpha->Add(h_ht1200_hev_emergjetpt_cutalpha);
    h_ht0_hev_emergjetpt_cutalpha->Add(h_ht2500_hev_emergjetpt_cutalpha);

    h_ht0_barr_hev_emergjetpt->Add(h_ht70_barr_hev_emergjetpt);
    h_ht0_barr_hev_emergjetpt->Add(h_ht100_barr_hev_emergjetpt);
    h_ht0_barr_hev_emergjetpt->Add(h_ht200_barr_hev_emergjetpt);
    h_ht0_barr_hev_emergjetpt->Add(h_ht400_barr_hev_emergjetpt);
    h_ht0_barr_hev_emergjetpt->Add(h_ht600_barr_hev_emergjetpt);
    h_ht0_barr_hev_emergjetpt->Add(h_ht800_barr_hev_emergjetpt);
    h_ht0_barr_hev_emergjetpt->Add(h_ht1200_barr_hev_emergjetpt);
    h_ht0_barr_hev_emergjetpt->Add(h_ht2500_barr_hev_emergjetpt);

    h_ht0_barr_hev_emergjetpt_cutalpha->Add(h_ht70_barr_hev_emergjetpt_cutalpha);
    h_ht0_barr_hev_emergjetpt_cutalpha->Add(h_ht100_barr_hev_emergjetpt_cutalpha);
    h_ht0_barr_hev_emergjetpt_cutalpha->Add(h_ht200_barr_hev_emergjetpt_cutalpha);
    h_ht0_barr_hev_emergjetpt_cutalpha->Add(h_ht400_barr_hev_emergjetpt_cutalpha);
    h_ht0_barr_hev_emergjetpt_cutalpha->Add(h_ht600_barr_hev_emergjetpt_cutalpha);
    h_ht0_barr_hev_emergjetpt_cutalpha->Add(h_ht800_barr_hev_emergjetpt_cutalpha);
    h_ht0_barr_hev_emergjetpt_cutalpha->Add(h_ht1200_barr_hev_emergjetpt_cutalpha);
    h_ht0_barr_hev_emergjetpt_cutalpha->Add(h_ht2500_barr_hev_emergjetpt_cutalpha);

    h_ht0_light_emergjetEta_cutalpha->Add(h_ht70_light_emergjetEta_cutalpha);
    h_ht0_light_emergjetEta_cutalpha->Add(h_ht100_light_emergjetEta_cutalpha);
    h_ht0_light_emergjetEta_cutalpha->Add(h_ht200_light_emergjetEta_cutalpha);
    h_ht0_light_emergjetEta_cutalpha->Add(h_ht400_light_emergjetEta_cutalpha);
    h_ht0_light_emergjetEta_cutalpha->Add(h_ht600_light_emergjetEta_cutalpha);
    h_ht0_light_emergjetEta_cutalpha->Add(h_ht800_light_emergjetEta_cutalpha);
    h_ht0_light_emergjetEta_cutalpha->Add(h_ht1200_light_emergjetEta_cutalpha);
    h_ht0_light_emergjetEta_cutalpha->Add(h_ht2500_light_emergjetEta_cutalpha);

    h_ht0_barr_light_emergjetpt_cutalpha->Add(h_ht70_barr_light_emergjetpt_cutalpha);
    h_ht0_barr_light_emergjetpt_cutalpha->Add(h_ht100_barr_light_emergjetpt_cutalpha);
    h_ht0_barr_light_emergjetpt_cutalpha->Add(h_ht200_barr_light_emergjetpt_cutalpha);
    h_ht0_barr_light_emergjetpt_cutalpha->Add(h_ht400_barr_light_emergjetpt_cutalpha);
    h_ht0_barr_light_emergjetpt_cutalpha->Add(h_ht600_barr_light_emergjetpt_cutalpha);
    h_ht0_barr_light_emergjetpt_cutalpha->Add(h_ht800_barr_light_emergjetpt_cutalpha);
    h_ht0_barr_light_emergjetpt_cutalpha->Add(h_ht1200_barr_light_emergjetpt_cutalpha);
    h_ht0_barr_light_emergjetpt_cutalpha->Add(h_ht2500_barr_light_emergjetpt_cutalpha);

    h_ht0_minjetpt->Add(h_ht70_minjetpt);
    h_ht0_minjetpt->Add(h_ht100_minjetpt);
    h_ht0_minjetpt->Add(h_ht200_minjetpt);
    h_ht0_minjetpt->Add(h_ht400_minjetpt);
    h_ht0_minjetpt->Add(h_ht600_minjetpt);
    h_ht0_minjetpt->Add(h_ht800_minjetpt);
    h_ht0_minjetpt->Add(h_ht1200_minjetpt);
    h_ht0_minjetpt->Add(h_ht2500_minjetpt);

    h_ht0_hev_emergjetEta->Add(h_ht70_hev_emergjetEta);
    h_ht0_hev_emergjetEta->Add(h_ht100_hev_emergjetEta);
    h_ht0_hev_emergjetEta->Add(h_ht200_hev_emergjetEta);
    h_ht0_hev_emergjetEta->Add(h_ht400_hev_emergjetEta);
    h_ht0_hev_emergjetEta->Add(h_ht600_hev_emergjetEta);
    h_ht0_hev_emergjetEta->Add(h_ht800_hev_emergjetEta);
    h_ht0_hev_emergjetEta->Add(h_ht1200_hev_emergjetEta);
    h_ht0_hev_emergjetEta->Add(h_ht2500_hev_emergjetEta);

    h_ht0_hev_emergjetEta_lowJetPt->Add(h_ht70_hev_emergjetEta_lowJetPt);
    h_ht0_hev_emergjetEta_lowJetPt->Add(h_ht100_hev_emergjetEta_lowJetPt);
    h_ht0_hev_emergjetEta_lowJetPt->Add(h_ht200_hev_emergjetEta_lowJetPt);
    h_ht0_hev_emergjetEta_lowJetPt->Add(h_ht400_hev_emergjetEta_lowJetPt);
    h_ht0_hev_emergjetEta_lowJetPt->Add(h_ht600_hev_emergjetEta_lowJetPt);
    h_ht0_hev_emergjetEta_lowJetPt->Add(h_ht800_hev_emergjetEta_lowJetPt);
    h_ht0_hev_emergjetEta_lowJetPt->Add(h_ht1200_hev_emergjetEta_lowJetPt);
    h_ht0_hev_emergjetEta_lowJetPt->Add(h_ht2500_hev_emergjetEta_lowJetPt);

    h_ht0_hev_emergjetEta_cutalpha->Add(h_ht70_hev_emergjetEta_cutalpha);
    h_ht0_hev_emergjetEta_cutalpha->Add(h_ht100_hev_emergjetEta_cutalpha);
    h_ht0_hev_emergjetEta_cutalpha->Add(h_ht200_hev_emergjetEta_cutalpha);
    h_ht0_hev_emergjetEta_cutalpha->Add(h_ht400_hev_emergjetEta_cutalpha);
    h_ht0_hev_emergjetEta_cutalpha->Add(h_ht600_hev_emergjetEta_cutalpha);
    h_ht0_hev_emergjetEta_cutalpha->Add(h_ht800_hev_emergjetEta_cutalpha);
    h_ht0_hev_emergjetEta_cutalpha->Add(h_ht1200_hev_emergjetEta_cutalpha);
    h_ht0_hev_emergjetEta_cutalpha->Add(h_ht2500_hev_emergjetEta_cutalpha);

    TH1F *h_ht0_hev_emergjetpt_fakeRate = (TH1F *)h_ht0_hev_emergjetpt_cutalpha->Clone("h_ht0_hev_emergjetpt_fakeRate");
    h_ht0_hev_emergjetpt_fakeRate->Divide(h_ht0_hev_emergjetpt_cutalpha, h_ht0_hev_emergjetpt, 1, 1, "b");

    TH1F *h_ht0_barr_hev_emergjetpt_fakeRate = (TH1F *)h_ht0_barr_hev_emergjetpt_cutalpha->Clone("h_ht0_barr_hev_emergjetpt_fakeRate");
    h_ht0_barr_hev_emergjetpt_fakeRate->Divide(h_ht0_barr_hev_emergjetpt_cutalpha, h_ht0_barr_hev_emergjetpt, 1, 1, "b");

    TH1F *h_ht0_barr_light_emergjetpt_fakeRate = (TH1F *)h_ht0_barr_light_emergjetpt_cutalpha->Clone("h_ht0_barr_light_emergjetpt_fakeRate");
    h_ht0_barr_light_emergjetpt_fakeRate->Divide(h_ht0_barr_light_emergjetpt_cutalpha, h_ht0_barr_light_emergjetpt, 1, 1, "b");

    auto c1 = new TCanvas("c", "BPRE");
    h_ht0_hev_emergjetEta_lowJetPt->SetLineWidth(2);
    h_ht0_barr_hev_emergjetpt_fakeRate->Draw("E");

    // c1->Divide(2, 1);
    // c1->cd(1);
    // h_ht0_hev_emergjetpt->SetLineWidth(2);
    // h_ht0_hev_emergjetpt->GetYaxis()->SetTitle("NJets");
    // h_ht0_hev_emergjetpt->Draw("hist");
    // c1->cd(2);
    // h_ht0_hev_emergjetpt_cutalpha->SetLineWidth(2);
    // h_ht0_hev_emergjetpt_cutalpha->SetTitle("emerging jet pt(alpha<0.2)");
    // h_ht0_hev_emergjetpt_cutalpha->GetYaxis()->SetTitle("NJets");
    // h_ht0_hev_emergjetpt_cutalpha->Draw("hist");

    // h_ht0_hev_emergjetpt_fakeRate->SetLineWidth(2);
    // h_ht0_hev_emergjetEta->SetLineWidth(2);
    // h_ht0_hev_emergjetpt_fakeRate->SetTitle("fake rate");
    // h_ht0_hev_emergjetEta->Draw("hist&&E");

    TFile *outFile = new TFile("./../../root_file/BgEstimation/DYHT_fakerate.root", "RECREATE");
    outFile->cd();
    h_ht0_hev_emergjetpt_fakeRate->Write();
    h_ht0_hev_emergjetpt->Write();
    h_ht0_hev_emergjetpt_cutalpha->Write();
    h_ht0_hev_emergjetEta->Write();
    h_ht0_hev_emergjetEta_cutalpha->Write();
    h_ht0_light_emergjetEta_cutalpha->Write();
    h_ht0_barr_hev_emergjetpt_fakeRate->Write();
    h_ht0_barr_light_emergjetpt_fakeRate->Write();
    outFile->Close();
}
