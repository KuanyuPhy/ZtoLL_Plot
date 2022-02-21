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

void Top_fakerate()
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

    vector<float> *v_tW_top_fakeJetPt = new vector<float>();
    vector<float> *v_tW_antitop_fakeJetPt = new vector<float>();
    vector<float> *v_TTTo2L2Nu_fakeJetPt = new vector<float>();
    vector<float> *v_TTWJetsToLNu_fakeJetPt = new vector<float>();
    vector<float> *v_TWJetsToQQ_fakeJetPt = new vector<float>();
    vector<float> *v_TTZToLLNuNu_fakeJetPt = new vector<float>();
    vector<float> *v_TTZToQQ_fakeJetPt = new vector<float>();

    vector<float> *v_tW_top_fakealpha = new vector<float>();
    vector<float> *v_tW_antitop_fakealpha = new vector<float>();
    vector<float> *v_TTTo2L2Nu_fakealpha = new vector<float>();
    vector<float> *v_TTWJetsToLNu_fakealpha = new vector<float>();
    vector<float> *v_TWJetsToQQ_fakealpha = new vector<float>();
    vector<float> *v_TTZToLLNuNu_fakealpha = new vector<float>();
    vector<float> *v_TTZToQQ_fakealpha = new vector<float>();

    vector<float> *v_tW_top_fakeJetEta = new vector<float>();
    vector<float> *v_tW_antitop_fakeJetEta = new vector<float>();
    vector<float> *v_TTTo2L2Nu_fakeJetEta = new vector<float>();
    vector<float> *v_TTWJetsToLNu_fakeJetEta = new vector<float>();
    vector<float> *v_TWJetsToQQ_fakeJetEta = new vector<float>();
    vector<float> *v_TTZToLLNuNu_fakeJetEta = new vector<float>();
    vector<float> *v_TTZToQQ_fakeJetEta = new vector<float>();

    //--------------
    // Clear vector
    //--------------
    v_tW_top_fakeJetPt->clear();
    v_tW_antitop_fakeJetPt->clear();
    v_TTTo2L2Nu_fakeJetPt->clear();
    v_TTWJetsToLNu_fakeJetPt->clear();
    v_TWJetsToQQ_fakeJetPt->clear();
    v_TTZToLLNuNu_fakeJetPt->clear();
    v_TTZToQQ_fakeJetPt->clear();

    v_tW_top_fakealpha->clear();
    v_tW_antitop_fakealpha->clear();
    v_TTTo2L2Nu_fakealpha->clear();
    v_TTWJetsToLNu_fakealpha->clear();
    v_TWJetsToQQ_fakealpha->clear();
    v_TTZToLLNuNu_fakealpha->clear();
    v_TTZToQQ_fakealpha->clear();

    v_tW_top_fakeJetEta->clear();
    v_tW_antitop_fakeJetEta->clear();
    v_TTTo2L2Nu_fakeJetEta->clear();
    v_TTWJetsToLNu_fakeJetEta->clear();
    v_TWJetsToQQ_fakeJetEta->clear();
    v_TTZToLLNuNu_fakeJetEta->clear();
    v_TTZToQQ_fakeJetEta->clear();

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
    TH1F *h_tW_top_emergjetpt = new TH1F("h_tW_top_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_tW_top_emergjetpt->Sumw2();
    TH1F *h_tW_antitop_emergjetpt = new TH1F("h_tW_antitop_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_tW_antitop_emergjetpt->Sumw2();
    TH1F *h_TTTo2L2Nu_emergjetpt = new TH1F("h_TTTo2L2Nu_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_emergjetpt->Sumw2();
    TH1F *h_TTWJetsToLNu_emergjetpt = new TH1F("h_TTWJetsToLNu_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTWJetsToLNu_emergjetpt->Sumw2();
    TH1F *h_TWJetsToQQ_emergjetpt = new TH1F("h_TWJetsToQQ_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TWJetsToQQ_emergjetpt->Sumw2();
    TH1F *h_TTZToLLNuNu_emergjetpt = new TH1F("h_TTZToLLNuNu_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTZToLLNuNu_emergjetpt->Sumw2();
    TH1F *h_TTZToQQ_emergjetpt = new TH1F("h_TTZToQQ_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTZToQQ_emergjetpt->Sumw2();

    //--------------
    // Barrel Jet PT
    //--------------
    TH1F *h_TTTo2L2Nu_barr_hev_emergjetpt = new TH1F("h_TTTo2L2Nu_barr_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_barr_hev_emergjetpt->Sumw2();
    TH1F *h_TTZToLLNuNu_barr_hev_emergjetpt = new TH1F("h_TTZToLLNuNu_barr_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTZToLLNuNu_barr_hev_emergjetpt->Sumw2();
    TH1F *h_TTTo2L2Nu_barr_light_emergjetpt = new TH1F("h_TTTo2L2Nu_barr_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_barr_light_emergjetpt->Sumw2();
    TH1F *h_TTZToLLNuNu_barr_light_emergjetpt = new TH1F("h_TTZToLLNuNu_barr_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTZToLLNuNu_barr_light_emergjetpt->Sumw2();

    TH1F *h_TTTo2L2Nu_barr_hev_emergjetpt_cutalpha = new TH1F("h_TTTo2L2Nu_barr_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_barr_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTZToLLNuNu_barr_hev_emergjetpt_cutalpha = new TH1F("h_TTZToLLNuNu_barr_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTZToLLNuNu_barr_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTTo2L2Nu_barr_light_emergjetpt_cutalpha = new TH1F("h_TTTo2L2Nu_barr_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_barr_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTZToLLNuNu_barr_light_emergjetpt_cutalpha = new TH1F("h_TTZToLLNuNu_barr_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTZToLLNuNu_barr_light_emergjetpt_cutalpha->Sumw2();

    TH1F *h_tW_top_emergjetpt_cutalpha = new TH1F("h_tW_top_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_tW_top_emergjetpt_cutalpha->Sumw2();
    TH1F *h_tW_antitop_emergjetpt_cutalpha = new TH1F("h_tW_antitop_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_tW_antitop_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTTo2L2Nu_emergjetpt_cutalpha = new TH1F("h_TTTo2L2Nu_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTWJetsToLNu_emergjetpt_cutalpha = new TH1F("h_TTWJetsToLNu_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTWJetsToLNu_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TWJetsToQQ_emergjetpt_cutalpha = new TH1F("h_TWJetsToQQ_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TWJetsToQQ_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTZToLLNuNu_emergjetpt_cutalpha = new TH1F("h_TTZToLLNuNu_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTZToLLNuNu_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTZToQQ_emergjetpt_cutalpha = new TH1F("h_TTZToQQ_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTZToQQ_emergjetpt_cutalpha->Sumw2();

    TH1F *h_tW_top_emergjetEta = new TH1F("h_tW_top_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_tW_top_emergjetEta->Sumw2();
    TH1F *h_tW_antitop_emergjetEta = new TH1F("h_tW_antitop_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_tW_antitop_emergjetEta->Sumw2();
    TH1F *h_TTTo2L2Nu_emergjetEta = new TH1F("h_TTTo2L2Nu_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTTo2L2Nu_emergjetEta->Sumw2();
    TH1F *h_TTWJetsToLNu_emergjetEta = new TH1F("h_TTWJetsToLNu_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTWJetsToLNu_emergjetEta->Sumw2();
    TH1F *h_TWJetsToQQ_emergjetEta = new TH1F("h_TWJetsToQQ_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TWJetsToQQ_emergjetEta->Sumw2();
    TH1F *h_TTZToLLNuNu_emergjetEta = new TH1F("h_TTZToLLNuNu_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTZToLLNuNu_emergjetEta->Sumw2();
    TH1F *h_TTZToQQ_emergjetEta = new TH1F("h_TTZToQQ_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTZToQQ_emergjetEta->Sumw2();
    //--------------------
    // Jet eta low Jet PT
    //--------------------
    TH1F *h_TTTo2L2Nu_emergjetEta_lowJetPt = new TH1F("h_TTTo2L2Nu_emergjetEta_lowJetPt", "emerging jet Eta", 60, -3, 3);
    h_TTTo2L2Nu_emergjetEta_lowJetPt->Sumw2();
    TH1F *h_TTZToLLNuNu_emergjetEta_lowJetPt = new TH1F("h_TTZToLLNuNu_emergjetEta_lowJetPt", "emerging jet Eta", 60, -3, 3);
    h_TTZToLLNuNu_emergjetEta_lowJetPt->Sumw2();
    //--------------------
    // Jet eta cut alpha
    //--------------------
    TH1F *h_TTTo2L2Nu_hev_emergjetEta_cutalpha = new TH1F("h_TTTo2L2Nu_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTTo2L2Nu_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TTZToLLNuNu_hev_emergjetEta_cutalpha = new TH1F("h_TTZToLLNuNu_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTZToLLNuNu_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TTTo2L2Nu_light_emergjetEta_cutalpha = new TH1F("h_TTTo2L2Nu_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTTo2L2Nu_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TTZToLLNuNu_light_emergjetEta_cutalpha = new TH1F("h_TTZToLLNuNu_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTZToLLNuNu_light_emergjetEta_cutalpha->Sumw2();

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
    T_event->SetBranchAddress("v_fakeJetPt", &v_tW_top_fakeJetPt);
    T_event->SetBranchAddress("v_fakealpha", &v_tW_top_fakealpha);
    T_event->SetBranchAddress("v_fakeJetEta", &v_tW_top_fakeJetEta);

    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (I_tW_top_nThinJets < 2)
            continue;
        if (I_tW_top_Jethadronflavor == 4 || I_tW_top_Jethadronflavor == 5)
        {
            for (int i = 0; i < v_tW_top_fakeJetPt->size(); i++)
            {
                h_tW_top_emergjetpt->Fill((*v_tW_top_fakeJetPt)[i], f_tW_top_weight * ST_tW_topWeight);
                h_tW_top_emergjetEta->Fill((*v_tW_top_fakeJetEta)[i], f_tW_top_weight * ST_tW_topWeight);
                if ((*v_tW_top_fakealpha)[i] < 0.35)
                {
                    h_tW_top_emergjetpt_cutalpha->Fill((*v_tW_top_fakeJetPt)[i], f_tW_top_weight * ST_tW_topWeight);
                }
            }
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
    T_event1->SetBranchAddress("v_fakeJetPt", &v_tW_antitop_fakeJetPt);
    T_event1->SetBranchAddress("v_fakealpha", &v_tW_antitop_fakealpha);
    T_event1->SetBranchAddress("v_fakeJetEta", &v_tW_antitop_fakeJetEta);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (I_tW_antitop_nThinJets < 2)
            continue;
        if (I_tW_antitop_Jethadronflavor == 4 || I_tW_antitop_Jethadronflavor == 5)
        {
            for (int i = 0; i < v_tW_antitop_fakeJetPt->size(); i++)
            {
                h_tW_antitop_emergjetpt->Fill((*v_tW_antitop_fakeJetPt)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                h_tW_antitop_emergjetEta->Fill((*v_tW_antitop_fakeJetEta)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                if ((*v_tW_antitop_fakealpha)[i] < 0.35)
                {
                    h_tW_antitop_emergjetpt_cutalpha->Fill((*v_tW_antitop_fakeJetPt)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                }
            }
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
    T_event2->SetBranchAddress("v_fakeJetPt", &v_TTTo2L2Nu_fakeJetPt);
    T_event2->SetBranchAddress("v_fakealpha", &v_TTTo2L2Nu_fakealpha);
    T_event2->SetBranchAddress("v_fakeJetEta", &v_TTTo2L2Nu_fakeJetEta);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (I_TTTo2L2Nu_nThinJets < 2)
            continue;
        if (I_TTTo2L2Nu_Jethadronflavor == 4 || I_TTTo2L2Nu_Jethadronflavor == 5)
        {
            for (int i = 0; i < v_TTTo2L2Nu_fakeJetPt->size(); i++)
            {
                h_TTTo2L2Nu_emergjetpt->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                h_TTTo2L2Nu_emergjetEta->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                if (abs((*v_TTTo2L2Nu_fakeJetEta)[i]) <= 1)
                {
                    h_TTTo2L2Nu_barr_hev_emergjetpt->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                }
                if ((*v_TTTo2L2Nu_fakealpha)[i] < 0.35)
                {
                    h_TTTo2L2Nu_emergjetpt_cutalpha->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    h_TTTo2L2Nu_hev_emergjetEta_cutalpha->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    if (abs((*v_TTTo2L2Nu_fakeJetEta)[i]) <= 1)
                    {
                        h_TTTo2L2Nu_barr_hev_emergjetpt_cutalpha->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    }
                    if ((*v_TTTo2L2Nu_fakeJetPt)[i] < 100)
                    {
                        h_TTTo2L2Nu_emergjetEta_lowJetPt->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < v_TTTo2L2Nu_fakeJetPt->size(); i++)
            {
                if (abs((*v_TTTo2L2Nu_fakeJetEta)[i]) <= 1)
                {
                    h_TTTo2L2Nu_barr_light_emergjetpt->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                }
                if ((*v_TTTo2L2Nu_fakealpha)[i] < 0.35)
                {
                    h_TTTo2L2Nu_light_emergjetEta_cutalpha->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    if (abs((*v_TTTo2L2Nu_fakeJetEta)[i]) <= 1)
                    {
                        h_TTTo2L2Nu_barr_light_emergjetpt_cutalpha->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    }
                }
            }
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
    T_event3->SetBranchAddress("v_fakeJetPt", &v_TTWJetsToLNu_fakeJetPt);
    T_event3->SetBranchAddress("v_fakealpha", &v_TTWJetsToLNu_fakealpha);
    T_event3->SetBranchAddress("v_fakeJetEta", &v_TTWJetsToLNu_fakeJetEta);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (I_TTWJetsToLNu_nThinJets < 2)
            continue;
        if (I_TTWJetsToLNu_Jethadronflavor == 4 || I_TTWJetsToLNu_Jethadronflavor == 5)
        {
            for (int i = 0; i < v_TTWJetsToLNu_fakeJetPt->size(); i++)
            {
                h_TTWJetsToLNu_emergjetpt->Fill((*v_TTWJetsToLNu_fakeJetPt)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                h_TTWJetsToLNu_emergjetEta->Fill((*v_TTWJetsToLNu_fakeJetEta)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                if ((*v_TTWJetsToLNu_fakealpha)[i] < 0.35)
                {
                    h_TTWJetsToLNu_emergjetpt_cutalpha->Fill((*v_TTWJetsToLNu_fakeJetPt)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                }
            }
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
    T_event4->SetBranchAddress("v_fakeJetPt", &v_TWJetsToQQ_fakeJetPt);
    T_event4->SetBranchAddress("v_fakealpha", &v_TWJetsToQQ_fakealpha);
    T_event4->SetBranchAddress("v_fakeJetEta", &v_TWJetsToQQ_fakeJetEta);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (I_TTWJetsToQQ_nThinJets < 2)
            continue;
        if (I_TTWJetsToQQ_Jethadronflavor == 4 || I_TTWJetsToQQ_Jethadronflavor == 5)
        {
            for (int i = 0; i < v_TWJetsToQQ_fakeJetPt->size(); i++)
            {
                h_TWJetsToQQ_emergjetpt->Fill((*v_TWJetsToQQ_fakeJetPt)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                h_TWJetsToQQ_emergjetEta->Fill((*v_TWJetsToQQ_fakeJetEta)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                if ((*v_TWJetsToQQ_fakealpha)[i] < 0.35)
                {
                    h_TWJetsToQQ_emergjetpt_cutalpha->Fill((*v_TWJetsToQQ_fakeJetPt)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                }
            }
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
    T_event5->SetBranchAddress("v_fakeJetPt", &v_TTZToLLNuNu_fakeJetPt);
    T_event5->SetBranchAddress("v_fakealpha", &v_TTZToLLNuNu_fakealpha);
    T_event5->SetBranchAddress("v_fakeJetEta", &v_TTZToLLNuNu_fakeJetEta);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (I_TTZToLLNuNu_nThinJets < 2)
            continue;
        if (I_TTZToLLNuNu_Jethadronflavor == 4 || I_TTZToLLNuNu_Jethadronflavor == 5)
        {
            for (int i = 0; i < v_TTZToLLNuNu_fakeJetPt->size(); i++)
            {
                h_TTZToLLNuNu_emergjetpt->Fill((*v_TTZToLLNuNu_fakeJetPt)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                h_TTZToLLNuNu_emergjetEta->Fill((*v_TTZToLLNuNu_fakeJetEta)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                if (abs((*v_TTZToLLNuNu_fakeJetEta)[i]) <= 1)
                {
                    h_TTZToLLNuNu_barr_hev_emergjetpt->Fill((*v_TTZToLLNuNu_fakeJetPt)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                }
                if ((*v_TTZToLLNuNu_fakealpha)[i] < 0.35)
                {
                    h_TTZToLLNuNu_emergjetpt_cutalpha->Fill((*v_TTZToLLNuNu_fakeJetPt)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    h_TTZToLLNuNu_hev_emergjetEta_cutalpha->Fill((*v_TTZToLLNuNu_fakeJetEta)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    if (abs((*v_TTZToLLNuNu_fakeJetEta)[i]) <= 1)
                    {
                        h_TTZToLLNuNu_barr_hev_emergjetpt_cutalpha->Fill((*v_TTZToLLNuNu_fakeJetPt)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    }
                    if ((*v_TTZToLLNuNu_fakeJetPt)[i] < 100)
                    {
                        h_TTZToLLNuNu_emergjetEta_lowJetPt->Fill((*v_TTZToLLNuNu_fakeJetEta)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < v_TTZToLLNuNu_fakeJetPt->size(); i++)
            {
                if (abs((*v_TTZToLLNuNu_fakeJetEta)[i]) <= 1)
                {
                    h_TTZToLLNuNu_barr_light_emergjetpt->Fill((*v_TTZToLLNuNu_fakeJetPt)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                }
                if ((*v_TTZToLLNuNu_fakealpha)[i] < 0.35)
                {
                    h_TTZToLLNuNu_light_emergjetEta_cutalpha->Fill((*v_TTZToLLNuNu_fakeJetEta)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    if (abs((*v_TTZToLLNuNu_fakeJetEta)[i]) <= 1)
                    {
                        h_TTZToLLNuNu_barr_light_emergjetpt_cutalpha->Fill((*v_TTZToLLNuNu_fakeJetPt)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    }
                }
            }
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
    T_event6->SetBranchAddress("v_fakeJetPt", &v_TTZToQQ_fakeJetPt);
    T_event6->SetBranchAddress("v_fakealpha", &v_TTZToQQ_fakealpha);
    T_event6->SetBranchAddress("v_fakeJetEta", &v_TTZToQQ_fakeJetEta);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (I_TTZToQQ_nThinJets < 2)
            continue;
        if (I_TTZToQQ_Jethadronflavor == 4 || I_TTZToQQ_Jethadronflavor == 5)
        {
            for (int i = 0; i < v_TTZToQQ_fakeJetPt->size(); i++)
            {
                h_TTZToQQ_emergjetpt->Fill((*v_TTZToQQ_fakeJetPt)[i], f_TTZToQQ_weight * TTZToQQWeight);
                h_TTZToQQ_emergjetEta->Fill((*v_TTZToQQ_fakeJetEta)[i], f_TTZToQQ_weight * TTZToQQWeight);
                if ((*v_TTZToQQ_fakealpha)[i] < 0.35)
                {
                    h_TTZToQQ_emergjetpt_cutalpha->Fill((*v_TTZToQQ_fakeJetPt)[i], f_TTZToQQ_weight * TTZToQQWeight);
                }
            }
        }
    }
    h_tW_top_emergjetpt->Add(h_tW_antitop_emergjetpt);
    // h_tW_top_emergjetpt->Add(h_TTTo2L2Nu_emergjetpt);
    // h_tW_top_emergjetpt->Add(h_TTWJetsToLNu_emergjetpt);
    // h_tW_top_emergjetpt->Add(h_TWJetsToQQ_emergjetpt);
    // h_tW_top_emergjetpt->Add(h_TTZToLLNuNu_emergjetpt);
    // h_tW_top_emergjetpt->Add(h_TTZToQQ_emergjetpt);

    h_tW_top_emergjetpt_cutalpha->Add(h_tW_antitop_emergjetpt_cutalpha);
    // h_tW_top_emergjetpt_cutalpha->Add(h_TTTo2L2Nu_emergjetpt_cutalpha);
    // h_tW_top_emergjetpt_cutalpha->Add(h_TTWJetsToLNu_emergjetpt_cutalpha);
    // h_tW_top_emergjetpt_cutalpha->Add(h_TWJetsToQQ_emergjetpt_cutalpha);
    // h_tW_top_emergjetpt_cutalpha->Add(h_TTZToLLNuNu_emergjetpt_cutalpha);
    // h_tW_top_emergjetpt_cutalpha->Add(h_TTZToQQ_emergjetpt_cutalpha);

    h_TTTo2L2Nu_hev_emergjetEta_cutalpha->Add(h_TTZToLLNuNu_hev_emergjetEta_cutalpha);

    h_TTTo2L2Nu_light_emergjetEta_cutalpha->Add(h_TTZToLLNuNu_light_emergjetEta_cutalpha);

    h_TTTo2L2Nu_barr_hev_emergjetpt->Add(h_TTZToLLNuNu_barr_hev_emergjetpt);
    h_TTTo2L2Nu_barr_hev_emergjetpt_cutalpha->Add(h_TTZToLLNuNu_barr_hev_emergjetpt_cutalpha);

    h_TTTo2L2Nu_barr_light_emergjetpt->Add(h_TTZToLLNuNu_barr_light_emergjetpt);
    h_TTTo2L2Nu_barr_light_emergjetpt_cutalpha->Add(h_TTZToLLNuNu_barr_light_emergjetpt_cutalpha);

    h_tW_top_emergjetEta->Add(h_tW_antitop_emergjetEta);
    h_tW_top_emergjetEta->Add(h_TTTo2L2Nu_emergjetEta);
    h_tW_top_emergjetEta->Add(h_TTWJetsToLNu_emergjetEta);
    h_tW_top_emergjetEta->Add(h_TWJetsToQQ_emergjetEta);
    h_tW_top_emergjetEta->Add(h_TTZToLLNuNu_emergjetEta);
    h_tW_top_emergjetEta->Add(h_TTZToQQ_emergjetEta);
    // h_TTTo2L2Nu_emergjetEta->Draw();

    TH1F *h_tW_top_emergjetpt_fakeRate = (TH1F *)h_tW_top_emergjetpt_cutalpha->Clone("h_tW_top_emergjetpt_fakeRate");
    h_tW_top_emergjetpt_fakeRate->Divide(h_tW_top_emergjetpt_cutalpha, h_tW_top_emergjetpt, 1, 1, "b");

    TH1F *h_tW_antitop_emergjetpt_fakeRate = (TH1F *)h_tW_antitop_emergjetpt_cutalpha->Clone("h_tW_antitop_emergjetpt_fakeRate");
    h_tW_antitop_emergjetpt_fakeRate->Divide(h_tW_antitop_emergjetpt_cutalpha, h_tW_antitop_emergjetpt, 1, 1, "b");

    TH1F *h_TTTo2L2Nu_emergjetpt_fakeRate = (TH1F *)h_TTTo2L2Nu_emergjetpt_cutalpha->Clone("h_TTTo2L2Nu_emergjetpt_fakeRate");
    h_TTTo2L2Nu_emergjetpt_fakeRate->Divide(h_TTTo2L2Nu_emergjetpt_cutalpha, h_TTTo2L2Nu_emergjetpt, 1, 1, "b");

    TH1F *h_TTWJetsToLNu_emergjetpt_fakeRate = (TH1F *)h_TTWJetsToLNu_emergjetpt_cutalpha->Clone("h_TTWJetsToLNu_emergjetpt_fakeRate");
    h_TTWJetsToLNu_emergjetpt_fakeRate->Divide(h_TTWJetsToLNu_emergjetpt_cutalpha, h_TTWJetsToLNu_emergjetpt, 1, 1, "b");

    TH1F *h_TWJetsToQQ_emergjetpt_fakeRate = (TH1F *)h_TWJetsToQQ_emergjetpt_cutalpha->Clone("h_TWJetsToQQ_emergjetpt_fakeRate");
    h_TWJetsToQQ_emergjetpt_fakeRate->Divide(h_TWJetsToQQ_emergjetpt_cutalpha, h_TWJetsToQQ_emergjetpt, 1, 1, "b");

    TH1F *h_TTZToLLNuNu_emergjetpt_fakeRate = (TH1F *)h_TTZToLLNuNu_emergjetpt_cutalpha->Clone("h_TTZToLLNuNu_emergjetpt_fakeRate");
    h_TTZToLLNuNu_emergjetpt_fakeRate->Divide(h_TTZToLLNuNu_emergjetpt_cutalpha, h_TTZToLLNuNu_emergjetpt, 1, 1, "b");

    TH1F *h_TTZToQQ_emergjetpt_fakeRate = (TH1F *)h_TTZToQQ_emergjetpt_cutalpha->Clone("h_TTZToQQ_emergjetpt_fakeRate");
    h_TTZToQQ_emergjetpt_fakeRate->Divide(h_TTZToQQ_emergjetpt_cutalpha, h_TTZToQQ_emergjetpt, 1, 1, "b");

    TH1F *h_TTZToLLNuNu_barr_hev_emergjetpt_fakeRate = (TH1F *)h_TTZToLLNuNu_barr_hev_emergjetpt->Clone("h_TTZToLLNuNu_barr_hev_emergjetpt_fakeRate");
    h_TTZToLLNuNu_barr_hev_emergjetpt_fakeRate->Divide(h_TTZToLLNuNu_barr_hev_emergjetpt_cutalpha, h_TTZToLLNuNu_barr_hev_emergjetpt, 1, 1, "b");

    TH1F *h_TTZToLLNuNu_barr_light_emergjetpt_fakeRate = (TH1F *)h_TTZToLLNuNu_barr_light_emergjetpt->Clone("h_TTZToLLNuNu_barr_light_emergjetpt_fakeRate");
    h_TTZToLLNuNu_barr_light_emergjetpt_fakeRate->Divide(h_TTZToLLNuNu_barr_light_emergjetpt_cutalpha, h_TTZToLLNuNu_barr_light_emergjetpt, 1, 1, "b");

    auto c1 = new TCanvas("c", "BPRE");
    /*
    c1->Divide(2, 1);
    c1->cd(1);
    h_TTTo2L2Nu_emergjetEta_lowJetPt->SetLineWidth(2);
    h_TTTo2L2Nu_emergjetEta_lowJetPt->SetTitle("TTTo2L2Nu");
    h_TTTo2L2Nu_emergjetEta_lowJetPt->Draw("hist");
    c1->cd(2);
    h_TTZToLLNuNu_emergjetEta_lowJetPt->SetLineWidth(2);
    h_TTZToLLNuNu_emergjetEta_lowJetPt->SetTitle("TTZToLLNuNu");
    h_TTZToLLNuNu_emergjetEta_lowJetPt->Draw("hist");
    */
    /*
     c1->Divide(3, 3);
     c1->cd(1);
     h_tW_top_emergjetpt_fakeRate->SetTitle("top");
     h_tW_top_emergjetpt_fakeRate->SetLineWidth(2);
     h_tW_top_emergjetpt_fakeRate->Draw("hist");
     c1->cd(2);
     h_tW_antitop_emergjetpt_fakeRate->SetTitle("antitop");
     h_tW_antitop_emergjetpt_fakeRate->SetLineWidth(2);
     h_tW_antitop_emergjetpt_fakeRate->Draw("hist");
     c1->cd(3);
     h_TTTo2L2Nu_emergjetpt_fakeRate->SetTitle("TTTo2L2Nu");
     h_TTTo2L2Nu_emergjetpt_fakeRate->SetLineWidth(2);
     h_TTTo2L2Nu_emergjetpt_fakeRate->Draw("hist");
     c1->cd(4);
     h_TTWJetsToLNu_emergjetpt_fakeRate->SetTitle("TTWJetsToLNu");
     h_TTWJetsToLNu_emergjetpt_fakeRate->SetLineWidth(2);
     h_TTWJetsToLNu_emergjetpt_fakeRate->Draw("hist");
     c1->cd(5);
     h_TWJetsToQQ_emergjetpt_fakeRate->SetTitle("TWJetsToQQ");
     h_TWJetsToQQ_emergjetpt_fakeRate->SetLineWidth(2);
     h_TWJetsToQQ_emergjetpt_fakeRate->Draw("hist");
     c1->cd(6);
     h_TTZToLLNuNu_emergjetpt_fakeRate->SetTitle("TTZToLLNuNu");
     h_TTZToLLNuNu_emergjetpt_fakeRate->SetLineWidth(2);
     h_TTZToLLNuNu_emergjetpt_fakeRate->Draw("hist");
     c1->cd(7);
     h_TTZToQQ_emergjetpt_fakeRate->SetTitle("TTZToQQ");
     h_TTZToQQ_emergjetpt_fakeRate->SetLineWidth(2);
     h_TTZToQQ_emergjetpt_fakeRate->Draw("hist");
 */
    // h_tW_top_emergjetpt->SetLineWidth(2);
    // h_tW_top_emergjetpt->GetYaxis()->SetTitle("NJets");
    // h_tW_top_emergjetpt->Draw("hist");
    // c1->cd(2);
    // h_tW_top_emergjetpt_cutalpha->SetLineWidth(2);
    // h_tW_top_emergjetpt_cutalpha->SetTitle("emerging jet pt(alpha<0.2)");
    // h_tW_top_emergjetpt_cutalpha->GetYaxis()->SetTitle("NJets");
    // h_tW_top_emergjetpt_cutalpha->Draw("hist");

    // h_tW_top_emergjetpt_fakeRate->SetLineWidth(2);
    // h_tW_top_emergjetEta->SetLineWidth(2);
    // h_tW_top_emergjetpt_fakeRate->SetTitle("fake rate");
    // h_tW_top_emergjetpt_fakeRate->Draw("hist&&E");
    // h_TTZToLLNuNu_barr_hev_emergjetpt_fakeRate->Draw("hist&&E");
    h_TTZToLLNuNu_barr_hev_emergjetpt_fakeRate->Draw("");
    TFile *outFile = new TFile("./../../root_file/BgEstimation/Top_fakerate.root", "RECREATE");
    outFile->cd();
    h_tW_top_emergjetpt_fakeRate->Write();
    h_tW_top_emergjetpt->Write();
    h_tW_top_emergjetpt_cutalpha->Write();
    h_tW_top_emergjetEta->Write();
    h_TTTo2L2Nu_hev_emergjetEta_cutalpha->Write();
    h_TTTo2L2Nu_light_emergjetEta_cutalpha->Write();
    h_TTZToLLNuNu_barr_hev_emergjetpt_fakeRate->Write();
    h_TTZToLLNuNu_barr_light_emergjetpt_fakeRate->Write();
    outFile->Close();
}

