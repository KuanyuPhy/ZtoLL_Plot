#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <string>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../../lib/Cross_section.h"
using namespace std;
void ee_diboson_produce(TString inputfile = "./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2mu.root", TString outputfile1 = "./ee_Diboson_emjet.root")
{
    TFile *diboson_gg_ZZ_2e2mu = TFile::Open(inputfile);
    TFile *diboson_gg_ZZ_2e2nu = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2nu.root");
    TFile *diboson_gg_ZZ_2e2tau = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2tau.root");
    TFile *diboson_gg_ZZ_2mu2nu = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2mu2nu.root");
    TFile *diboson_gg_ZZ_2mu2tau = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2mu2tau.root");
    TFile *diboson_gg_ZZ_4e = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4e.root");
    TFile *diboson_gg_ZZ_4mu = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4mu.root");
    TFile *diboson_gg_ZZ_4tau = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4tau.root");
    TFile *diboson_gg_WW_2L2Nu = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_WW_2L2Nu.root");
    TFile *diboson_qq_WW_2L2Nu = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WW_2L2Nu.root");
    TFile *diboson_qq_WZ_2L2Q = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WZ_2L2Q.root");
    TFile *diboson_qq_WZ_3LNu = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WZ_3LNu.root");
    TFile *diboson_qq_ZZ_2L2Nu = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_2L2Nu.root");
    TFile *diboson_qq_ZZ_2L2Q = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_2L2Q.root");
    TFile *diboson_qq_ZZ_4L = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_4L.root");

    TH1D *gg_ZZ_2e2mu_sumevt = ((TH1D *)diboson_gg_ZZ_2e2mu->Get("Event_Variable/h_totevent"));
    TH1D *gg_ZZ_2e2nu_sumevt = ((TH1D *)diboson_gg_ZZ_2e2nu->Get("Event_Variable/h_totevent"));
    TH1D *gg_ZZ_2e2tau_sumevt = ((TH1D *)diboson_gg_ZZ_2e2tau->Get("Event_Variable/h_totevent"));
    TH1D *gg_ZZ_2mu2nu_sumevt = ((TH1D *)diboson_gg_ZZ_2mu2nu->Get("Event_Variable/h_totevent"));
    TH1D *gg_ZZ_2mu2tau_sumevt = ((TH1D *)diboson_gg_ZZ_2mu2tau->Get("Event_Variable/h_totevent"));
    TH1D *gg_ZZ_4e_sumevt = ((TH1D *)diboson_gg_ZZ_4e->Get("Event_Variable/h_totevent"));
    TH1D *gg_ZZ_4mu_sumevt = ((TH1D *)diboson_gg_ZZ_4mu->Get("Event_Variable/h_totevent"));
    TH1D *gg_ZZ_4tau_sumevt = ((TH1D *)diboson_gg_ZZ_4tau->Get("Event_Variable/h_totevent"));
    TH1D *gg_WW_2L2Nu_sumevt = ((TH1D *)diboson_gg_WW_2L2Nu->Get("Event_Variable/h_totevent"));
    TH1D *qq_WW_2L2Nu_sumevt = ((TH1D *)diboson_qq_WW_2L2Nu->Get("Event_Variable/h_totevent"));
    TH1D *qq_WZ_2L2Q_sumevt = ((TH1D *)diboson_qq_WZ_2L2Q->Get("Event_Variable/h_totevent"));
    TH1D *qq_WZ_3LNu_sumevt = ((TH1D *)diboson_qq_WZ_3LNu->Get("Event_Variable/h_totevent"));
    TH1D *qq_ZZ_2L2Nu_sumevt = ((TH1D *)diboson_qq_ZZ_2L2Nu->Get("Event_Variable/h_totevent"));
    TH1D *qq_ZZ_2L2Q_sumevt = ((TH1D *)diboson_qq_ZZ_2L2Q->Get("Event_Variable/h_totevent"));
    TH1D *qq_ZZ_4L_sumevt = ((TH1D *)diboson_qq_ZZ_4L->Get("Event_Variable/h_totevent"));

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

    TH1F *h_diboson_alpha[4];
    for (int i = 0; i < 4; i++)
    {
        h_diboson_alpha[i] = new TH1F(Form("h_diboson_alpha_%d", i + 1), "", 24, 0, 1.2);
        h_diboson_alpha[i]->Sumw2();
    }

    TH1F *h_diboson_Chi3Dlog = new TH1F("h_diboson_Chi3Dlog", "", 100, -10, 10);
    h_diboson_Chi3Dlog->GetXaxis()->SetTitle("");
    h_diboson_Chi3Dlog->GetYaxis()->SetTitle("");
    h_diboson_Chi3Dlog->Sumw2();

    TH1F *h_diboson_IP2D = new TH1F("h_diboson_IP2D", "", 100, -10, 10);
    h_diboson_IP2D->GetXaxis()->SetTitle("");
    h_diboson_IP2D->GetYaxis()->SetTitle("");
    h_diboson_IP2D->Sumw2();

    TH1F *h_diboson_Met = new TH1F("h_diboson_Met", "", 50, 0, 500);
    h_diboson_Met->GetXaxis()->SetTitle("");
    h_diboson_Met->GetYaxis()->SetTitle("");
    h_diboson_Met->Sumw2();

    TH1F *h_diboson_nTracks = new TH1F("h_diboson_nTracks", "", 50, 0, 50);
    h_diboson_nTracks->GetXaxis()->SetTitle("");
    h_diboson_nTracks->GetYaxis()->SetTitle("");
    h_diboson_nTracks->Sumw2();

    //---------------------
    // Define Diboson Weight
    //---------------------
    float diboson_gg_ZZ_2e2mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2mu / (gg_ZZ_2e2mu_totevt)) * 1000;
    float diboson_gg_ZZ_2e2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2nu / (gg_ZZ_2e2nu_totevt)) * 1000;
    float diboson_gg_ZZ_2e2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2tau / (gg_ZZ_2e2tau_totevt)) * 1000;
    float diboson_gg_ZZ_2mu2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2nu / (gg_ZZ_2mu2nu_totevt)) * 1000;
    float diboson_gg_ZZ_2mu2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2tau / (gg_ZZ_2mu2tau_totevt)) * 1000;
    float diboson_gg_ZZ_4e_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4e / (gg_ZZ_4e_totevt)) * 1000;
    float diboson_gg_ZZ_4mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4mu / (gg_ZZ_4mu_totevt)) * 1000;
    float diboson_gg_ZZ_4tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4tau / (gg_ZZ_4tau_totevt)) * 1000;
    float diboson_gg_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WW_2L2Nu / (gg_WW_2L2Nu_totevt)) * 1000;
    float diboson_qq_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Nu / (qq_WW_2L2Nu_totevt)) * 1000;
    float diboson_qq_WZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_2L2Q / (qq_WZ_2L2Q_totevt)) * 1000;
    float diboson_qq_WZ_3LNu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_3LNu / (qq_WZ_3LNu_totevt)) * 1000;
    float diboson_qq_ZZ_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Nu / (qq_ZZ_2L2Nu_totevt)) * 1000;
    float diboson_qq_ZZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Q / (qq_ZZ_2L2Q_totevt)) * 1000;
    float diboson_qq_ZZ_4L_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_4L / (qq_ZZ_4L_totevt)) * 1000;

    Int_t I_gg_ZZ_2e2mu_nThinJets, I_gg_ZZ_2e2nu_nThinJets, I_gg_ZZ_2e2tau_nThinJets, I_gg_ZZ_2mu2nu_nThinJets,
        I_gg_ZZ_2mu2tau_nThinJets, I_gg_ZZ_4e_nThinJets, I_gg_ZZ_4mu_nThinJets, I_gg_ZZ_4tau_nThinJets, I_gg_WW_2L2Nu_nThinJets,
        I_qq_WW_2L2Nu_nThinJets, I_qq_WZ_2L2Q_nThinJets, I_qq_WZ_3LNu_nThinJets, I_qq_ZZ_2L2Nu_nThinJets, I_qq_ZZ_2L2Q_nThinJets,
        I_qq_ZZ_4L_nThinJets;

    Int_t f_gg_ZZ_2e2mu_weight, f_gg_ZZ_2e2nu_weight, f_gg_ZZ_2e2tau_weight, f_gg_ZZ_2mu2nu_weight,
        f_gg_ZZ_2mu2tau_weight, f_gg_ZZ_4e_weight, f_gg_ZZ_4mu_weight, f_gg_ZZ_4tau_weight, f_gg_WW_2L2Nu_weight,
        f_qq_WW_2L2Nu_weight, f_qq_WZ_2L2Q_weight, f_qq_WZ_3LNu_weight, f_qq_ZZ_2L2Nu_weight, f_qq_ZZ_2L2Q_weight,
        f_qq_ZZ_4L_weight;

    float_t f_gg_ZZ_2e2mu_met, f_gg_ZZ_2e2nu_met, f_gg_ZZ_2e2tau_met, f_gg_ZZ_2mu2nu_met,
        f_gg_ZZ_2mu2tau_met, f_gg_ZZ_4e_met, f_gg_ZZ_4mu_met, f_gg_ZZ_4tau_met, f_gg_WW_2L2Nu_met,
        f_qq_WW_2L2Nu_met, f_qq_WZ_2L2Q_met, f_qq_WZ_3LNu_met, f_qq_ZZ_2L2Nu_met, f_qq_ZZ_2L2Q_met,
        f_qq_ZZ_4L_met;

    vector<float> *v_gg_ZZ_2e2mu_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_2e2nu_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_2e2tau_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2nu_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2tau_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_4e_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_4mu_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_4tau_alpha = new vector<float>();
    vector<float> *v_gg_WW_2L2Nu_alpha = new vector<float>();
    vector<float> *v_qq_WW_2L2Nu_alpha = new vector<float>();
    vector<float> *v_qq_WZ_2L2Q_alpha = new vector<float>();
    vector<float> *v_qq_WZ_3LNu_alpha = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Nu_alpha = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Q_alpha = new vector<float>();
    vector<float> *v_qq_ZZ_4L_alpha = new vector<float>();

    vector<float> *v_gg_ZZ_2e2mu_alpha2 = new vector<float>();
    vector<float> *v_gg_ZZ_2e2nu_alpha2 = new vector<float>();
    vector<float> *v_gg_ZZ_2e2tau_alpha2 = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2nu_alpha2 = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2tau_alpha2 = new vector<float>();
    vector<float> *v_gg_ZZ_4e_alpha2 = new vector<float>();
    vector<float> *v_gg_ZZ_4mu_alpha2 = new vector<float>();
    vector<float> *v_gg_ZZ_4tau_alpha2 = new vector<float>();
    vector<float> *v_gg_WW_2L2Nu_alpha2 = new vector<float>();
    vector<float> *v_qq_WW_2L2Nu_alpha2 = new vector<float>();
    vector<float> *v_qq_WZ_2L2Q_alpha2 = new vector<float>();
    vector<float> *v_qq_WZ_3LNu_alpha2 = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Nu_alpha2 = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Q_alpha2 = new vector<float>();
    vector<float> *v_qq_ZZ_4L_alpha2 = new vector<float>();

    vector<float> *v_gg_ZZ_2e2mu_alpha3 = new vector<float>();
    vector<float> *v_gg_ZZ_2e2nu_alpha3 = new vector<float>();
    vector<float> *v_gg_ZZ_2e2tau_alpha3 = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2nu_alpha3 = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2tau_alpha3 = new vector<float>();
    vector<float> *v_gg_ZZ_4e_alpha3 = new vector<float>();
    vector<float> *v_gg_ZZ_4mu_alpha3 = new vector<float>();
    vector<float> *v_gg_ZZ_4tau_alpha3 = new vector<float>();
    vector<float> *v_gg_WW_2L2Nu_alpha3 = new vector<float>();
    vector<float> *v_qq_WW_2L2Nu_alpha3 = new vector<float>();
    vector<float> *v_qq_WZ_2L2Q_alpha3 = new vector<float>();
    vector<float> *v_qq_WZ_3LNu_alpha3 = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Nu_alpha3 = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Q_alpha3 = new vector<float>();
    vector<float> *v_qq_ZZ_4L_alpha3 = new vector<float>();

    vector<float> *v_gg_ZZ_2e2mu_alpha4 = new vector<float>();
    vector<float> *v_gg_ZZ_2e2nu_alpha4 = new vector<float>();
    vector<float> *v_gg_ZZ_2e2tau_alpha4 = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2nu_alpha4 = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2tau_alpha4 = new vector<float>();
    vector<float> *v_gg_ZZ_4e_alpha4 = new vector<float>();
    vector<float> *v_gg_ZZ_4mu_alpha4 = new vector<float>();
    vector<float> *v_gg_ZZ_4tau_alpha4 = new vector<float>();
    vector<float> *v_gg_WW_2L2Nu_alpha4 = new vector<float>();
    vector<float> *v_qq_WW_2L2Nu_alpha4 = new vector<float>();
    vector<float> *v_qq_WZ_2L2Q_alpha4 = new vector<float>();
    vector<float> *v_qq_WZ_3LNu_alpha4 = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Nu_alpha4 = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Q_alpha4 = new vector<float>();
    vector<float> *v_qq_ZZ_4L_alpha4 = new vector<float>();

    v_gg_ZZ_2e2mu_alpha->clear();
    v_gg_ZZ_2e2nu_alpha->clear();
    v_gg_ZZ_2e2tau_alpha->clear();
    v_gg_ZZ_2mu2nu_alpha->clear();
    v_gg_ZZ_2mu2tau_alpha->clear();
    v_gg_ZZ_4e_alpha->clear();
    v_gg_ZZ_4mu_alpha->clear();
    v_gg_ZZ_4tau_alpha->clear();
    v_gg_WW_2L2Nu_alpha->clear();
    v_qq_WW_2L2Nu_alpha->clear();
    v_qq_WZ_2L2Q_alpha->clear();
    v_qq_WZ_3LNu_alpha->clear();
    v_qq_ZZ_2L2Nu_alpha->clear();
    v_qq_ZZ_2L2Q_alpha->clear();
    v_qq_ZZ_4L_alpha->clear();

    v_gg_ZZ_2e2mu_alpha2->clear();
    v_gg_ZZ_2e2nu_alpha2->clear();
    v_gg_ZZ_2e2tau_alpha2->clear();
    v_gg_ZZ_2mu2nu_alpha2->clear();
    v_gg_ZZ_2mu2tau_alpha2->clear();
    v_gg_ZZ_4e_alpha2->clear();
    v_gg_ZZ_4mu_alpha2->clear();
    v_gg_ZZ_4tau_alpha2->clear();
    v_gg_WW_2L2Nu_alpha2->clear();
    v_qq_WW_2L2Nu_alpha2->clear();
    v_qq_WZ_2L2Q_alpha2->clear();
    v_qq_WZ_3LNu_alpha2->clear();
    v_qq_ZZ_2L2Nu_alpha2->clear();
    v_qq_ZZ_2L2Q_alpha2->clear();
    v_qq_ZZ_4L_alpha2->clear();

    v_gg_ZZ_2e2mu_alpha3->clear();
    v_gg_ZZ_2e2nu_alpha3->clear();
    v_gg_ZZ_2e2tau_alpha3->clear();
    v_gg_ZZ_2mu2nu_alpha3->clear();
    v_gg_ZZ_2mu2tau_alpha3->clear();
    v_gg_ZZ_4e_alpha3->clear();
    v_gg_ZZ_4mu_alpha3->clear();
    v_gg_ZZ_4tau_alpha3->clear();
    v_gg_WW_2L2Nu_alpha3->clear();
    v_qq_WW_2L2Nu_alpha3->clear();
    v_qq_WZ_2L2Q_alpha3->clear();
    v_qq_WZ_3LNu_alpha3->clear();
    v_qq_ZZ_2L2Nu_alpha3->clear();
    v_qq_ZZ_2L2Q_alpha3->clear();
    v_qq_ZZ_4L_alpha3->clear();

    v_gg_ZZ_2e2mu_alpha4->clear();
    v_gg_ZZ_2e2nu_alpha4->clear();
    v_gg_ZZ_2e2tau_alpha4->clear();
    v_gg_ZZ_2mu2nu_alpha4->clear();
    v_gg_ZZ_2mu2tau_alpha4->clear();
    v_gg_ZZ_4e_alpha4->clear();
    v_gg_ZZ_4mu_alpha4->clear();
    v_gg_ZZ_4tau_alpha4->clear();
    v_gg_WW_2L2Nu_alpha4->clear();
    v_qq_WW_2L2Nu_alpha4->clear();
    v_qq_WZ_2L2Q_alpha4->clear();
    v_qq_WZ_3LNu_alpha4->clear();
    v_qq_ZZ_2L2Nu_alpha4->clear();
    v_qq_ZZ_2L2Q_alpha4->clear();
    v_qq_ZZ_4L_alpha4->clear();

    vector<float> *v_gg_ZZ_2e2mu_Chi3Dlog = new vector<float>();
    vector<float> *v_gg_ZZ_2e2nu_Chi3Dlog = new vector<float>();
    vector<float> *v_gg_ZZ_2e2tau_Chi3Dlog = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2nu_Chi3Dlog = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2tau_Chi3Dlog = new vector<float>();
    vector<float> *v_gg_ZZ_4e_Chi3Dlog = new vector<float>();
    vector<float> *v_gg_ZZ_4mu_Chi3Dlog = new vector<float>();
    vector<float> *v_gg_ZZ_4tau_Chi3Dlog = new vector<float>();
    vector<float> *v_gg_WW_2L2Nu_Chi3Dlog = new vector<float>();
    vector<float> *v_qq_WW_2L2Nu_Chi3Dlog = new vector<float>();
    vector<float> *v_qq_WZ_2L2Q_Chi3Dlog = new vector<float>();
    vector<float> *v_qq_WZ_3LNu_Chi3Dlog = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Nu_Chi3Dlog = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Q_Chi3Dlog = new vector<float>();
    vector<float> *v_qq_ZZ_4L_Chi3Dlog = new vector<float>();

    vector<float> *v_gg_ZZ_2e2mu_2DIP = new vector<float>();
    vector<float> *v_gg_ZZ_2e2nu_2DIP = new vector<float>();
    vector<float> *v_gg_ZZ_2e2tau_2DIP = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2nu_2DIP = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2tau_2DIP = new vector<float>();
    vector<float> *v_gg_ZZ_4e_2DIP = new vector<float>();
    vector<float> *v_gg_ZZ_4mu_2DIP = new vector<float>();
    vector<float> *v_gg_ZZ_4tau_2DIP = new vector<float>();
    vector<float> *v_gg_WW_2L2Nu_2DIP = new vector<float>();
    vector<float> *v_qq_WW_2L2Nu_2DIP = new vector<float>();
    vector<float> *v_qq_WZ_2L2Q_2DIP = new vector<float>();
    vector<float> *v_qq_WZ_3LNu_2DIP = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Nu_2DIP = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Q_2DIP = new vector<float>();
    vector<float> *v_qq_ZZ_4L_2DIP = new vector<float>();

    vector<float> *v_gg_ZZ_2e2mu_nTracks = new vector<float>();
    vector<float> *v_gg_ZZ_2e2nu_nTracks = new vector<float>();
    vector<float> *v_gg_ZZ_2e2tau_nTracks = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2nu_nTracks = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2tau_nTracks = new vector<float>();
    vector<float> *v_gg_ZZ_4e_nTracks = new vector<float>();
    vector<float> *v_gg_ZZ_4mu_nTracks = new vector<float>();
    vector<float> *v_gg_ZZ_4tau_nTracks = new vector<float>();
    vector<float> *v_gg_WW_2L2Nu_nTracks = new vector<float>();
    vector<float> *v_qq_WW_2L2Nu_nTracks = new vector<float>();
    vector<float> *v_qq_WZ_2L2Q_nTracks = new vector<float>();
    vector<float> *v_qq_WZ_3LNu_nTracks = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Nu_nTracks = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Q_nTracks = new vector<float>();
    vector<float> *v_qq_ZZ_4L_nTracks = new vector<float>();

    vector<float> *v_gg_ZZ_2e2mu_Jethadronflavor = new vector<float>();
    vector<float> *v_gg_ZZ_2e2nu_Jethadronflavor = new vector<float>();
    vector<float> *v_gg_ZZ_2e2tau_Jethadronflavor = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2nu_Jethadronflavor = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2tau_Jethadronflavor = new vector<float>();
    vector<float> *v_gg_ZZ_4e_Jethadronflavor = new vector<float>();
    vector<float> *v_gg_ZZ_4mu_Jethadronflavor = new vector<float>();
    vector<float> *v_gg_ZZ_4tau_Jethadronflavor = new vector<float>();
    vector<float> *v_gg_WW_2L2Nu_Jethadronflavor = new vector<float>();
    vector<float> *v_qq_WW_2L2Nu_Jethadronflavor = new vector<float>();
    vector<float> *v_qq_WZ_2L2Q_Jethadronflavor = new vector<float>();
    vector<float> *v_qq_WZ_3LNu_Jethadronflavor = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Nu_Jethadronflavor = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Q_Jethadronflavor = new vector<float>();
    vector<float> *v_qq_ZZ_4L_Jethadronflavor = new vector<float>();

    vector<float> *v_gg_ZZ_2e2mu_Jetpartonflavor = new vector<float>();
    vector<float> *v_gg_ZZ_2e2nu_Jetpartonflavor = new vector<float>();
    vector<float> *v_gg_ZZ_2e2tau_Jetpartonflavor = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2nu_Jetpartonflavor = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2tau_Jetpartonflavor = new vector<float>();
    vector<float> *v_gg_ZZ_4e_Jetpartonflavor = new vector<float>();
    vector<float> *v_gg_ZZ_4mu_Jetpartonflavor = new vector<float>();
    vector<float> *v_gg_ZZ_4tau_Jetpartonflavor = new vector<float>();
    vector<float> *v_gg_WW_2L2Nu_Jetpartonflavor = new vector<float>();
    vector<float> *v_qq_WW_2L2Nu_Jetpartonflavor = new vector<float>();
    vector<float> *v_qq_WZ_2L2Q_Jetpartonflavor = new vector<float>();
    vector<float> *v_qq_WZ_3LNu_Jetpartonflavor = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Nu_Jetpartonflavor = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Q_Jetpartonflavor = new vector<float>();
    vector<float> *v_qq_ZZ_4L_Jetpartonflavor = new vector<float>();

    v_gg_ZZ_2e2mu_Chi3Dlog->clear();
    v_gg_ZZ_2e2nu_Chi3Dlog->clear();
    v_gg_ZZ_2e2tau_Chi3Dlog->clear();
    v_gg_ZZ_2mu2nu_Chi3Dlog->clear();
    v_gg_ZZ_2mu2tau_Chi3Dlog->clear();
    v_gg_ZZ_4e_Chi3Dlog->clear();
    v_gg_ZZ_4mu_Chi3Dlog->clear();
    v_gg_ZZ_4tau_Chi3Dlog->clear();
    v_gg_WW_2L2Nu_Chi3Dlog->clear();
    v_qq_WW_2L2Nu_Chi3Dlog->clear();
    v_qq_WZ_2L2Q_Chi3Dlog->clear();
    v_qq_WZ_3LNu_Chi3Dlog->clear();
    v_qq_ZZ_2L2Nu_Chi3Dlog->clear();
    v_qq_ZZ_2L2Q_Chi3Dlog->clear();
    v_qq_ZZ_4L_Chi3Dlog->clear();

    v_gg_ZZ_2e2mu_2DIP->clear();
    v_gg_ZZ_2e2nu_2DIP->clear();
    v_gg_ZZ_2e2tau_2DIP->clear();
    v_gg_ZZ_2mu2nu_2DIP->clear();
    v_gg_ZZ_2mu2tau_2DIP->clear();
    v_gg_ZZ_4e_2DIP->clear();
    v_gg_ZZ_4mu_2DIP->clear();
    v_gg_ZZ_4tau_2DIP->clear();
    v_gg_WW_2L2Nu_2DIP->clear();
    v_qq_WW_2L2Nu_2DIP->clear();
    v_qq_WZ_2L2Q_2DIP->clear();
    v_qq_WZ_3LNu_2DIP->clear();
    v_qq_ZZ_2L2Nu_2DIP->clear();
    v_qq_ZZ_2L2Q_2DIP->clear();
    v_qq_ZZ_4L_2DIP->clear();

    v_gg_ZZ_2e2mu_nTracks->clear();
    v_gg_ZZ_2e2nu_nTracks->clear();
    v_gg_ZZ_2e2tau_nTracks->clear();
    v_gg_ZZ_2mu2nu_nTracks->clear();
    v_gg_ZZ_2mu2tau_nTracks->clear();
    v_gg_ZZ_4e_nTracks->clear();
    v_gg_ZZ_4mu_nTracks->clear();
    v_gg_ZZ_4tau_nTracks->clear();
    v_gg_WW_2L2Nu_nTracks->clear();
    v_qq_WW_2L2Nu_nTracks->clear();
    v_qq_WZ_2L2Q_nTracks->clear();
    v_qq_WZ_3LNu_nTracks->clear();
    v_qq_ZZ_2L2Nu_nTracks->clear();
    v_qq_ZZ_2L2Q_nTracks->clear();
    v_qq_ZZ_4L_nTracks->clear();

    v_gg_ZZ_2e2mu_Jethadronflavor->clear();
    v_gg_ZZ_2e2nu_Jethadronflavor->clear();
    v_gg_ZZ_2e2tau_Jethadronflavor->clear();
    v_gg_ZZ_2mu2nu_Jethadronflavor->clear();
    v_gg_ZZ_2mu2tau_Jethadronflavor->clear();
    v_gg_ZZ_4e_Jethadronflavor->clear();
    v_gg_ZZ_4mu_Jethadronflavor->clear();
    v_gg_ZZ_4tau_Jethadronflavor->clear();
    v_gg_WW_2L2Nu_Jethadronflavor->clear();
    v_qq_WW_2L2Nu_Jethadronflavor->clear();
    v_qq_WZ_2L2Q_Jethadronflavor->clear();
    v_qq_WZ_3LNu_Jethadronflavor->clear();
    v_qq_ZZ_2L2Nu_Jethadronflavor->clear();
    v_qq_ZZ_2L2Q_Jethadronflavor->clear();
    v_qq_ZZ_4L_Jethadronflavor->clear();

    v_gg_ZZ_2e2mu_Jetpartonflavor->clear();
    v_gg_ZZ_2e2nu_Jetpartonflavor->clear();
    v_gg_ZZ_2e2tau_Jetpartonflavor->clear();
    v_gg_ZZ_2mu2nu_Jetpartonflavor->clear();
    v_gg_ZZ_2mu2tau_Jetpartonflavor->clear();
    v_gg_ZZ_4e_Jetpartonflavor->clear();
    v_gg_ZZ_4mu_Jetpartonflavor->clear();
    v_gg_ZZ_4tau_Jetpartonflavor->clear();
    v_gg_WW_2L2Nu_Jetpartonflavor->clear();
    v_qq_WW_2L2Nu_Jetpartonflavor->clear();
    v_qq_WZ_2L2Q_Jetpartonflavor->clear();
    v_qq_WZ_3LNu_Jetpartonflavor->clear();
    v_qq_ZZ_2L2Nu_Jetpartonflavor->clear();
    v_qq_ZZ_2L2Q_Jetpartonflavor->clear();
    v_qq_ZZ_4L_Jetpartonflavor->clear();

    TTree *T_event;
    diboson_gg_ZZ_2e2mu->GetObject("T_tree", T_event);
    T_event->SetBranchAddress("I_weight", &f_gg_ZZ_2e2mu_weight);
    T_event->SetBranchAddress("f_Met", &f_gg_ZZ_2e2mu_met);
    T_event->SetBranchAddress("v_IP2D", &v_gg_ZZ_2e2mu_2DIP);
    T_event->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_2e2mu_Chi3Dlog);
    T_event->SetBranchAddress("I_nThinJets", &I_gg_ZZ_2e2mu_nThinJets);
    T_event->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_2e2mu_nTracks);
    T_event->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2e2mu_alpha);
    T_event->SetBranchAddress("v_fakealpha2", &v_gg_ZZ_2e2mu_alpha2);
    T_event->SetBranchAddress("v_fakealpha3", &v_gg_ZZ_2e2mu_alpha3);
    T_event->SetBranchAddress("v_fakealpha4", &v_gg_ZZ_2e2mu_alpha4);
    T_event->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_2e2mu_Jethadronflavor);
    T_event->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_2e2mu_Jetpartonflavor);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);

        h_diboson_Met->Fill(f_gg_ZZ_2e2mu_met, f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight);
        for (size_t i = 0; i < v_gg_ZZ_2e2mu_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_gg_ZZ_2e2mu_alpha)[i], f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2mu_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_gg_ZZ_2e2mu_alpha2)[i], f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2mu_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_gg_ZZ_2e2mu_alpha3)[i], f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2mu_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_gg_ZZ_2e2mu_alpha4)[i], f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_gg_ZZ_2e2mu_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_gg_ZZ_2e2mu_Chi3Dlog)[i], f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_gg_ZZ_2e2mu_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_gg_ZZ_2e2mu_2DIP)[i])), f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2mu_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_gg_ZZ_2e2mu_nTracks)[i], f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight);
        }
    }

    TTree *T_event1;
    diboson_gg_ZZ_2e2nu->GetObject("T_tree", T_event1);
    T_event1->SetBranchAddress("I_weight", &f_gg_ZZ_2e2nu_weight);
    T_event1->SetBranchAddress("f_Met", &f_gg_ZZ_2e2nu_met);
    T_event1->SetBranchAddress("v_IP2D", &v_gg_ZZ_2e2nu_2DIP);
    T_event1->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_2e2nu_Chi3Dlog);
    T_event1->SetBranchAddress("I_nThinJets", &I_gg_ZZ_2e2nu_nThinJets);
    T_event1->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_2e2nu_nTracks);
    T_event1->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2e2nu_alpha);
    T_event1->SetBranchAddress("v_fakealpha2", &v_gg_ZZ_2e2nu_alpha2);
    T_event1->SetBranchAddress("v_fakealpha3", &v_gg_ZZ_2e2nu_alpha3);
    T_event1->SetBranchAddress("v_fakealpha4", &v_gg_ZZ_2e2nu_alpha4);
    T_event1->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_2e2nu_Jethadronflavor);
    T_event1->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_2e2nu_Jetpartonflavor);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);

        h_diboson_Met->Fill(f_gg_ZZ_2e2nu_met, f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight);
        for (size_t i = 0; i < v_gg_ZZ_2e2nu_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_gg_ZZ_2e2nu_alpha)[i], f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2nu_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_gg_ZZ_2e2nu_alpha2)[i], f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2nu_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_gg_ZZ_2e2nu_alpha3)[i], f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2nu_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_gg_ZZ_2e2nu_alpha4)[i], f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_gg_ZZ_2e2nu_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_gg_ZZ_2e2nu_Chi3Dlog)[i], f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_gg_ZZ_2e2nu_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_gg_ZZ_2e2nu_2DIP)[i])), f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2nu_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_gg_ZZ_2e2nu_nTracks)[i], f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight);
        }
    }

    TTree *T_event2;
    diboson_gg_ZZ_2e2tau->GetObject("T_tree", T_event2);
    T_event2->SetBranchAddress("I_weight", &f_gg_ZZ_2e2tau_weight);
    T_event2->SetBranchAddress("f_Met", &f_gg_ZZ_2e2tau_met);
    T_event2->SetBranchAddress("v_IP2D", &v_gg_ZZ_2e2tau_2DIP);
    T_event2->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_2e2tau_Chi3Dlog);
    T_event2->SetBranchAddress("I_nThinJets", &I_gg_ZZ_2e2tau_nThinJets);
    T_event2->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_2e2tau_nTracks);
    T_event2->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2e2tau_alpha);
    T_event2->SetBranchAddress("v_fakealpha2", &v_gg_ZZ_2e2tau_alpha2);
    T_event2->SetBranchAddress("v_fakealpha3", &v_gg_ZZ_2e2tau_alpha3);
    T_event2->SetBranchAddress("v_fakealpha4", &v_gg_ZZ_2e2tau_alpha4);
    T_event2->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_2e2tau_Jethadronflavor);
    T_event2->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_2e2tau_Jetpartonflavor);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);

        h_diboson_Met->Fill(f_gg_ZZ_2e2tau_met, f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight);
        for (size_t i = 0; i < v_gg_ZZ_2e2tau_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_gg_ZZ_2e2tau_alpha)[i], f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2tau_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_gg_ZZ_2e2tau_alpha2)[i], f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2tau_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_gg_ZZ_2e2tau_alpha3)[i], f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2tau_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_gg_ZZ_2e2tau_alpha4)[i], f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_gg_ZZ_2e2tau_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_gg_ZZ_2e2tau_Chi3Dlog)[i], f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_gg_ZZ_2e2tau_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_gg_ZZ_2e2tau_2DIP)[i])), f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight);
        }        
        for (size_t i = 0; i < v_gg_ZZ_2e2tau_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_gg_ZZ_2e2tau_nTracks)[i], f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight);
        }
    }

    TTree *T_event3;
    diboson_gg_ZZ_2mu2nu->GetObject("T_tree", T_event3);
    T_event3->SetBranchAddress("I_weight", &f_gg_ZZ_2mu2nu_weight);
    T_event3->SetBranchAddress("f_Met", &f_gg_ZZ_2mu2nu_met);
    T_event3->SetBranchAddress("v_IP2D", &v_gg_ZZ_2mu2nu_2DIP);
    T_event3->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_2mu2nu_Chi3Dlog);
    T_event3->SetBranchAddress("I_nThinJets", &I_gg_ZZ_2mu2nu_nThinJets);
    T_event3->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_2mu2nu_nTracks);
    T_event3->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2mu2nu_alpha);
    T_event3->SetBranchAddress("v_fakealpha2", &v_gg_ZZ_2mu2nu_alpha2);
    T_event3->SetBranchAddress("v_fakealpha3", &v_gg_ZZ_2mu2nu_alpha3);
    T_event3->SetBranchAddress("v_fakealpha4", &v_gg_ZZ_2mu2nu_alpha4);
    T_event3->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_2mu2nu_Jethadronflavor);
    T_event3->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_2mu2nu_Jetpartonflavor);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);

        h_diboson_Met->Fill(f_gg_ZZ_2mu2nu_met, f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight);
        for (size_t i = 0; i < v_gg_ZZ_2mu2nu_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_gg_ZZ_2mu2nu_alpha)[i], f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2mu2nu_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_gg_ZZ_2mu2nu_alpha2)[i], f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2mu2nu_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_gg_ZZ_2mu2nu_alpha3)[i], f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2mu2nu_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_gg_ZZ_2mu2nu_alpha4)[i], f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_gg_ZZ_2mu2nu_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_gg_ZZ_2mu2nu_Chi3Dlog)[i], f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_gg_ZZ_2mu2nu_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_gg_ZZ_2mu2nu_2DIP)[i])), f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2mu2nu_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_gg_ZZ_2mu2nu_nTracks)[i], f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight);
        }
    }

    TTree *T_event4;
    diboson_gg_ZZ_2mu2tau->GetObject("T_tree", T_event4);
    T_event4->SetBranchAddress("I_weight", &f_gg_ZZ_2mu2tau_weight);
    T_event4->SetBranchAddress("f_Met", &f_gg_ZZ_2mu2tau_met);
    T_event4->SetBranchAddress("v_IP2D", &v_gg_ZZ_2mu2tau_2DIP);
    T_event4->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_2mu2tau_Chi3Dlog);
    T_event4->SetBranchAddress("I_nThinJets", &I_gg_ZZ_2mu2tau_nThinJets);
    T_event4->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_2mu2tau_nTracks);
    T_event4->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2mu2tau_alpha);
    T_event4->SetBranchAddress("v_fakealpha2", &v_gg_ZZ_2mu2tau_alpha2);
    T_event4->SetBranchAddress("v_fakealpha3", &v_gg_ZZ_2mu2tau_alpha3);
    T_event4->SetBranchAddress("v_fakealpha4", &v_gg_ZZ_2mu2tau_alpha4);
    T_event4->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_2mu2tau_Jethadronflavor);
    T_event4->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_2mu2tau_Jetpartonflavor);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);

        h_diboson_Met->Fill(f_gg_ZZ_2mu2tau_met, f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight);
        for (size_t i = 0; i < v_gg_ZZ_2mu2tau_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_gg_ZZ_2mu2tau_alpha)[i], f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2mu2tau_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_gg_ZZ_2mu2tau_alpha2)[i], f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2mu2tau_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_gg_ZZ_2mu2tau_alpha3)[i], f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2mu2tau_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_gg_ZZ_2mu2tau_alpha4)[i], f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_gg_ZZ_2mu2tau_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_gg_ZZ_2mu2tau_Chi3Dlog)[i], f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_gg_ZZ_2mu2tau_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_gg_ZZ_2mu2tau_2DIP)[i])), f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_2mu2tau_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_gg_ZZ_2mu2tau_nTracks)[i], f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight);
        }
    }

    TTree *T_event5;
    diboson_gg_ZZ_4e->GetObject("T_tree", T_event5);
    T_event5->SetBranchAddress("I_weight", &f_gg_ZZ_4e_weight);
    T_event5->SetBranchAddress("f_Met", &f_gg_ZZ_4e_met);
    T_event5->SetBranchAddress("v_IP2D", &v_gg_ZZ_4e_2DIP);
    T_event5->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_4e_Chi3Dlog);
    T_event5->SetBranchAddress("I_nThinJets", &I_gg_ZZ_4e_nThinJets);
    T_event5->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_4e_nTracks);
    T_event5->SetBranchAddress("v_fakealpha", &v_gg_ZZ_4e_alpha);
    T_event5->SetBranchAddress("v_fakealpha2", &v_gg_ZZ_4e_alpha2);
    T_event5->SetBranchAddress("v_fakealpha3", &v_gg_ZZ_4e_alpha3);
    T_event5->SetBranchAddress("v_fakealpha4", &v_gg_ZZ_4e_alpha4);
    T_event5->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_4e_Jethadronflavor);
    T_event5->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_4e_Jetpartonflavor);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);

        h_diboson_Met->Fill(f_gg_ZZ_4e_met, f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight);
        for (size_t i = 0; i < v_gg_ZZ_4e_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_gg_ZZ_4e_alpha)[i], f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4e_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_gg_ZZ_4e_alpha2)[i], f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4e_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_gg_ZZ_4e_alpha3)[i], f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4e_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_gg_ZZ_4e_alpha4)[i], f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_gg_ZZ_4e_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_gg_ZZ_4e_Chi3Dlog)[i], f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_gg_ZZ_4e_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_gg_ZZ_4e_2DIP)[i])), f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4e_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_gg_ZZ_4e_nTracks)[i], f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight);
        }
    }

    TTree *T_event6;
    diboson_gg_ZZ_4mu->GetObject("T_tree", T_event6);
    T_event6->SetBranchAddress("I_weight", &f_gg_ZZ_4mu_weight);
    T_event6->SetBranchAddress("f_Met", &f_gg_ZZ_4mu_met);
    T_event6->SetBranchAddress("v_IP2D", &v_gg_ZZ_4mu_2DIP);
    T_event6->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_4mu_Chi3Dlog);
    T_event6->SetBranchAddress("I_nThinJets", &I_gg_ZZ_4mu_nThinJets);
    T_event6->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_4mu_nTracks);
    T_event6->SetBranchAddress("v_fakealpha", &v_gg_ZZ_4mu_alpha);
    T_event6->SetBranchAddress("v_fakealpha2", &v_gg_ZZ_4mu_alpha2);
    T_event6->SetBranchAddress("v_fakealpha3", &v_gg_ZZ_4mu_alpha3);
    T_event6->SetBranchAddress("v_fakealpha4", &v_gg_ZZ_4mu_alpha4);
    T_event6->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_4mu_Jethadronflavor);
    T_event6->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_4mu_Jetpartonflavor);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);

        h_diboson_Met->Fill(f_gg_ZZ_4mu_met, f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight);
        for (size_t i = 0; i < v_gg_ZZ_4mu_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_gg_ZZ_4mu_alpha)[i], f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4mu_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_gg_ZZ_4mu_alpha2)[i], f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4mu_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_gg_ZZ_4mu_alpha3)[i], f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4mu_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_gg_ZZ_4mu_alpha4)[i], f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_gg_ZZ_4mu_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_gg_ZZ_4mu_Chi3Dlog)[i], f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_gg_ZZ_4mu_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_gg_ZZ_4mu_2DIP)[i])), f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4mu_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_gg_ZZ_4mu_nTracks)[i], f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight);
        }
    }

    TTree *T_event7;
    diboson_gg_ZZ_4tau->GetObject("T_tree", T_event7);
    T_event7->SetBranchAddress("I_weight", &f_gg_ZZ_4tau_weight);
    T_event7->SetBranchAddress("f_Met", &f_gg_ZZ_4tau_met);
    T_event7->SetBranchAddress("v_IP2D", &v_gg_ZZ_4tau_2DIP);
    T_event7->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_4tau_Chi3Dlog);
    T_event7->SetBranchAddress("I_nThinJets", &I_gg_ZZ_4tau_nThinJets);
    T_event7->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_4tau_nTracks);
    T_event7->SetBranchAddress("v_fakealpha", &v_gg_ZZ_4tau_alpha);
    T_event7->SetBranchAddress("v_fakealpha2", &v_gg_ZZ_4tau_alpha2);
    T_event7->SetBranchAddress("v_fakealpha3", &v_gg_ZZ_4tau_alpha3);
    T_event7->SetBranchAddress("v_fakealpha4", &v_gg_ZZ_4tau_alpha4);
    T_event7->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_4tau_Jethadronflavor);
    T_event7->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_4tau_Jetpartonflavor);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);

        h_diboson_Met->Fill(f_gg_ZZ_4tau_met, f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight);
        for (size_t i = 0; i < v_gg_ZZ_4tau_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_gg_ZZ_4tau_alpha)[i], f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4tau_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_gg_ZZ_4tau_alpha2)[i], f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4tau_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_gg_ZZ_4tau_alpha3)[i], f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4tau_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_gg_ZZ_4tau_alpha4)[i], f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_gg_ZZ_4tau_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_gg_ZZ_4tau_Chi3Dlog)[i], f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_gg_ZZ_4tau_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_gg_ZZ_4tau_2DIP)[i])), f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight);
        }
        for (size_t i = 0; i < v_gg_ZZ_4tau_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_gg_ZZ_4tau_nTracks)[i], f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight);
        }
    }

    TTree *T_event8;
    diboson_gg_WW_2L2Nu->GetObject("T_tree", T_event8);
    T_event8->SetBranchAddress("I_weight", &f_gg_WW_2L2Nu_weight);
    T_event8->SetBranchAddress("f_Met", &f_gg_WW_2L2Nu_met);
    T_event8->SetBranchAddress("v_IP2D", &v_gg_WW_2L2Nu_2DIP);
    T_event8->SetBranchAddress("v_Chi3Dlog", &v_gg_WW_2L2Nu_Chi3Dlog);
    T_event8->SetBranchAddress("I_nThinJets", &I_gg_WW_2L2Nu_nThinJets);
    T_event8->SetBranchAddress("v_N_Tracks", &v_gg_WW_2L2Nu_nTracks);
    T_event8->SetBranchAddress("v_fakealpha", &v_gg_WW_2L2Nu_alpha);
    T_event8->SetBranchAddress("v_fakealpha2", &v_gg_WW_2L2Nu_alpha2);
    T_event8->SetBranchAddress("v_fakealpha3", &v_gg_WW_2L2Nu_alpha3);
    T_event8->SetBranchAddress("v_fakealpha4", &v_gg_WW_2L2Nu_alpha4);
    T_event8->SetBranchAddress("v_fakeJethadronflavor", &v_gg_WW_2L2Nu_Jethadronflavor);
    T_event8->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_WW_2L2Nu_Jetpartonflavor);
    for (int evt = 0; evt < T_event8->GetEntries(); evt++)
    {
        T_event8->GetEntry(evt);

        h_diboson_Met->Fill(f_gg_WW_2L2Nu_met, f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight);
        for (size_t i = 0; i < v_gg_WW_2L2Nu_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_gg_WW_2L2Nu_alpha)[i], f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_gg_WW_2L2Nu_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_gg_WW_2L2Nu_alpha2)[i], f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_gg_WW_2L2Nu_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_gg_WW_2L2Nu_alpha3)[i], f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_gg_WW_2L2Nu_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_gg_WW_2L2Nu_alpha4)[i], f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_gg_WW_2L2Nu_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_gg_WW_2L2Nu_Chi3Dlog)[i], f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_gg_WW_2L2Nu_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_gg_WW_2L2Nu_2DIP)[i])), f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_gg_WW_2L2Nu_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_gg_WW_2L2Nu_nTracks)[i], f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight);
        }
    }

    TTree *T_event9;
    diboson_qq_WW_2L2Nu->GetObject("T_tree", T_event9);
    T_event9->SetBranchAddress("I_weight", &f_qq_WW_2L2Nu_weight);
    T_event9->SetBranchAddress("f_Met", &f_qq_WW_2L2Nu_met);
    T_event9->SetBranchAddress("v_IP2D", &v_qq_WW_2L2Nu_2DIP);
    T_event9->SetBranchAddress("v_Chi3Dlog", &v_qq_WW_2L2Nu_Chi3Dlog);
    T_event9->SetBranchAddress("I_nThinJets", &I_qq_WW_2L2Nu_nThinJets);
    T_event9->SetBranchAddress("v_N_Tracks", &v_qq_WW_2L2Nu_nTracks);
    T_event9->SetBranchAddress("v_fakealpha", &v_qq_WW_2L2Nu_alpha);
    T_event9->SetBranchAddress("v_fakealpha2", &v_qq_WW_2L2Nu_alpha2);
    T_event9->SetBranchAddress("v_fakealpha3", &v_qq_WW_2L2Nu_alpha3);
    T_event9->SetBranchAddress("v_fakealpha4", &v_qq_WW_2L2Nu_alpha4);
    T_event9->SetBranchAddress("v_fakeJethadronflavor", &v_qq_WW_2L2Nu_Jethadronflavor);
    T_event9->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_WW_2L2Nu_Jetpartonflavor);
    for (int evt = 0; evt < T_event9->GetEntries(); evt++)
    {
        T_event9->GetEntry(evt);

        h_diboson_Met->Fill(f_qq_WW_2L2Nu_met, f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight);
        for (size_t i = 0; i < v_qq_WW_2L2Nu_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_qq_WW_2L2Nu_alpha)[i], f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_qq_WW_2L2Nu_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_qq_WW_2L2Nu_alpha2)[i], f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_qq_WW_2L2Nu_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_qq_WW_2L2Nu_alpha3)[i], f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_qq_WW_2L2Nu_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_qq_WW_2L2Nu_alpha4)[i], f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_qq_WW_2L2Nu_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_qq_WW_2L2Nu_Chi3Dlog)[i], f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_qq_WW_2L2Nu_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_qq_WW_2L2Nu_2DIP)[i])), f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_qq_WW_2L2Nu_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_qq_WW_2L2Nu_nTracks)[i], f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight);
        }
    }

    TTree *T_event10;
    diboson_qq_WZ_2L2Q->GetObject("T_tree", T_event10);
    T_event10->SetBranchAddress("I_weight", &f_qq_WZ_2L2Q_weight);
    T_event10->SetBranchAddress("f_Met", &f_qq_WZ_2L2Q_met);
    T_event10->SetBranchAddress("v_IP2D", &v_qq_WZ_2L2Q_2DIP);
    T_event10->SetBranchAddress("v_Chi3Dlog", &v_qq_WZ_2L2Q_Chi3Dlog);
    T_event10->SetBranchAddress("I_nThinJets", &I_qq_WZ_2L2Q_nThinJets);
    T_event10->SetBranchAddress("v_N_Tracks", &v_qq_WZ_2L2Q_nTracks);
    T_event10->SetBranchAddress("v_fakealpha", &v_qq_WZ_2L2Q_alpha);
    T_event10->SetBranchAddress("v_fakealpha2", &v_qq_WZ_2L2Q_alpha2);
    T_event10->SetBranchAddress("v_fakealpha3", &v_qq_WZ_2L2Q_alpha3);
    T_event10->SetBranchAddress("v_fakealpha4", &v_qq_WZ_2L2Q_alpha4);
    T_event10->SetBranchAddress("v_fakeJethadronflavor", &v_qq_WZ_2L2Q_Jethadronflavor);
    T_event10->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_WZ_2L2Q_Jetpartonflavor);
    for (int evt = 0; evt < T_event10->GetEntries(); evt++)
    {
        T_event10->GetEntry(evt);
        if (I_qq_WZ_2L2Q_nThinJets < 2)
            continue;
        h_diboson_Met->Fill(f_qq_WZ_2L2Q_met, f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight);
        for (size_t i = 0; i < v_qq_WZ_2L2Q_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_qq_WZ_2L2Q_alpha)[i], f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight);
        }
        for (size_t i = 0; i < v_qq_WZ_2L2Q_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_qq_WZ_2L2Q_alpha2)[i], f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight);
        }
        for (size_t i = 0; i < v_qq_WZ_2L2Q_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_qq_WZ_2L2Q_alpha3)[i], f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight);
        }
        for (size_t i = 0; i < v_qq_WZ_2L2Q_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_qq_WZ_2L2Q_alpha4)[i], f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_qq_WZ_2L2Q_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_qq_WZ_2L2Q_Chi3Dlog)[i], f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_qq_WZ_2L2Q_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_qq_WZ_2L2Q_2DIP)[i])), f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight);
        }
        for (size_t i = 0; i < v_qq_WZ_2L2Q_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_qq_WZ_2L2Q_nTracks)[i], f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight);
        }
    }

    TTree *T_event11;
    diboson_qq_WZ_3LNu->GetObject("T_tree", T_event11);
    T_event11->SetBranchAddress("I_weight", &f_qq_WZ_3LNu_weight);
    T_event11->SetBranchAddress("f_Met", &f_qq_WZ_3LNu_met);
    T_event11->SetBranchAddress("v_IP2D", &v_qq_WZ_3LNu_2DIP);
    T_event11->SetBranchAddress("v_Chi3Dlog", &v_qq_WZ_3LNu_Chi3Dlog);
    T_event11->SetBranchAddress("I_nThinJets", &I_qq_WZ_3LNu_nThinJets);
    T_event11->SetBranchAddress("v_N_Tracks", &v_qq_WZ_3LNu_nTracks);
    T_event11->SetBranchAddress("v_fakealpha", &v_qq_WZ_3LNu_alpha);
    T_event11->SetBranchAddress("v_fakealpha2", &v_qq_WZ_3LNu_alpha2);
    T_event11->SetBranchAddress("v_fakealpha3", &v_qq_WZ_3LNu_alpha3);
    T_event11->SetBranchAddress("v_fakealpha4", &v_qq_WZ_3LNu_alpha4);
    T_event11->SetBranchAddress("v_fakeJethadronflavor", &v_qq_WZ_3LNu_Jethadronflavor);
    T_event11->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_WZ_3LNu_Jetpartonflavor);
    for (int evt = 0; evt < T_event11->GetEntries(); evt++)
    {
        T_event11->GetEntry(evt);
        h_diboson_Met->Fill(f_qq_WZ_3LNu_met, f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight);
        for (size_t i = 0; i < v_qq_WZ_3LNu_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_qq_WZ_3LNu_alpha)[i], f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight);
        }
        for (size_t i = 0; i < v_qq_WZ_3LNu_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_qq_WZ_3LNu_alpha2)[i], f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight);
        }
        for (size_t i = 0; i < v_qq_WZ_3LNu_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_qq_WZ_3LNu_alpha3)[i], f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight);
        }
        for (size_t i = 0; i < v_qq_WZ_3LNu_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_qq_WZ_3LNu_alpha4)[i], f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_qq_WZ_3LNu_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_qq_WZ_3LNu_Chi3Dlog)[i], f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_qq_WZ_3LNu_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_qq_WZ_3LNu_2DIP)[i])), f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight);
        }
        for (size_t i = 0; i < v_qq_WZ_3LNu_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_qq_WZ_3LNu_nTracks)[i], f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight);
        }
    }

    TTree *T_event12;
    diboson_qq_ZZ_2L2Nu->GetObject("T_tree", T_event12);
    T_event12->SetBranchAddress("I_weight", &f_qq_ZZ_2L2Nu_weight);
    T_event12->SetBranchAddress("f_Met", &f_qq_ZZ_2L2Nu_met);
    T_event12->SetBranchAddress("v_IP2D", &v_qq_ZZ_2L2Nu_2DIP);
    T_event12->SetBranchAddress("v_Chi3Dlog", &v_qq_ZZ_2L2Nu_Chi3Dlog);
    T_event12->SetBranchAddress("I_nThinJets", &I_qq_ZZ_2L2Nu_nThinJets);
    T_event12->SetBranchAddress("v_N_Tracks", &v_qq_ZZ_2L2Nu_nTracks);
    T_event12->SetBranchAddress("v_fakealpha", &v_qq_ZZ_2L2Nu_alpha);
    T_event12->SetBranchAddress("v_fakealpha2", &v_qq_ZZ_2L2Nu_alpha2);
    T_event12->SetBranchAddress("v_fakealpha3", &v_qq_ZZ_2L2Nu_alpha3);
    T_event12->SetBranchAddress("v_fakealpha4", &v_qq_ZZ_2L2Nu_alpha4);
    T_event12->SetBranchAddress("v_fakeJethadronflavor", &v_qq_ZZ_2L2Nu_Jethadronflavor);
    T_event12->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_ZZ_2L2Nu_Jetpartonflavor);
    for (int evt = 0; evt < T_event12->GetEntries(); evt++)
    {
        T_event12->GetEntry(evt);
        h_diboson_Met->Fill(f_qq_ZZ_2L2Nu_met, f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight);
        for (size_t i = 0; i < v_qq_ZZ_2L2Nu_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_qq_ZZ_2L2Nu_alpha)[i], f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_2L2Nu_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_qq_ZZ_2L2Nu_alpha2)[i], f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_2L2Nu_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_qq_ZZ_2L2Nu_alpha3)[i], f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_2L2Nu_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_qq_ZZ_2L2Nu_alpha4)[i], f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_qq_ZZ_2L2Nu_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_qq_ZZ_2L2Nu_Chi3Dlog)[i], f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_qq_ZZ_2L2Nu_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_qq_ZZ_2L2Nu_2DIP)[i])), f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_2L2Nu_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_qq_ZZ_2L2Nu_nTracks)[i], f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight);
        }
    }

    TTree *T_event13;
    diboson_qq_ZZ_2L2Q->GetObject("T_tree", T_event13);
    T_event13->SetBranchAddress("I_weight", &f_qq_ZZ_2L2Q_weight);
    T_event13->SetBranchAddress("f_Met", &f_qq_ZZ_2L2Q_met);
    T_event13->SetBranchAddress("v_IP2D", &v_qq_ZZ_2L2Q_2DIP);
    T_event13->SetBranchAddress("v_Chi3Dlog", &v_qq_ZZ_2L2Q_Chi3Dlog);
    T_event13->SetBranchAddress("I_nThinJets", &I_qq_ZZ_2L2Q_nThinJets);
    T_event13->SetBranchAddress("v_N_Tracks", &v_qq_ZZ_2L2Q_nTracks);
    T_event13->SetBranchAddress("v_fakealpha", &v_qq_ZZ_2L2Q_alpha);
    T_event13->SetBranchAddress("v_fakealpha2", &v_qq_ZZ_2L2Q_alpha2);
    T_event13->SetBranchAddress("v_fakealpha3", &v_qq_ZZ_2L2Q_alpha3);
    T_event13->SetBranchAddress("v_fakealpha4", &v_qq_ZZ_2L2Q_alpha4);
    T_event13->SetBranchAddress("v_fakeJethadronflavor", &v_qq_ZZ_2L2Q_Jethadronflavor);
    T_event13->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_ZZ_2L2Q_Jetpartonflavor);
    for (int evt = 0; evt < T_event13->GetEntries(); evt++)
    {
        T_event13->GetEntry(evt);

        h_diboson_Met->Fill(f_qq_ZZ_2L2Q_met, f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight);
        for (size_t i = 0; i < v_qq_ZZ_2L2Q_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_qq_ZZ_2L2Q_alpha)[i], f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_2L2Q_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_qq_ZZ_2L2Q_alpha2)[i], f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_2L2Q_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_qq_ZZ_2L2Q_alpha3)[i], f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_2L2Q_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_qq_ZZ_2L2Q_alpha4)[i], f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_qq_ZZ_2L2Q_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_qq_ZZ_2L2Q_Chi3Dlog)[i], f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_qq_ZZ_2L2Q_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_qq_ZZ_2L2Q_2DIP)[i])), f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_2L2Q_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_qq_ZZ_2L2Q_nTracks)[i], f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight);
        }
    }

    TTree *T_event14;
    diboson_qq_ZZ_4L->GetObject("T_tree", T_event14);
    T_event14->SetBranchAddress("I_weight", &f_qq_ZZ_4L_weight);
    T_event14->SetBranchAddress("f_Met", &f_qq_ZZ_4L_met);
    T_event14->SetBranchAddress("v_IP2D", &v_qq_ZZ_4L_2DIP);
    T_event14->SetBranchAddress("v_Chi3Dlog", &v_qq_ZZ_4L_Chi3Dlog);
    T_event14->SetBranchAddress("I_nThinJets", &I_qq_ZZ_4L_nThinJets);
    T_event14->SetBranchAddress("v_N_Tracks", &v_qq_ZZ_4L_nTracks);
    T_event14->SetBranchAddress("v_fakealpha", &v_qq_ZZ_4L_alpha);
    T_event14->SetBranchAddress("v_fakealpha2", &v_qq_ZZ_4L_alpha2);
    T_event14->SetBranchAddress("v_fakealpha3", &v_qq_ZZ_4L_alpha3);
    T_event14->SetBranchAddress("v_fakealpha4", &v_qq_ZZ_4L_alpha4);
    T_event14->SetBranchAddress("v_fakeJethadronflavor", &v_qq_ZZ_4L_Jethadronflavor);
    T_event14->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_ZZ_4L_Jetpartonflavor);
    for (int evt = 0; evt < T_event14->GetEntries(); evt++)
    {
        T_event14->GetEntry(evt);

        h_diboson_Met->Fill(f_qq_ZZ_4L_met, f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight);
        for (size_t i = 0; i < v_qq_ZZ_4L_alpha->size(); i++)
        {
            h_diboson_alpha[0]->Fill((*v_qq_ZZ_4L_alpha)[i], f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_4L_alpha2->size(); i++)
        {
            h_diboson_alpha[1]->Fill((*v_qq_ZZ_4L_alpha2)[i], f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_4L_alpha3->size(); i++)
        {
            h_diboson_alpha[2]->Fill((*v_qq_ZZ_4L_alpha3)[i], f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_4L_alpha4->size(); i++)
        {
            h_diboson_alpha[3]->Fill((*v_qq_ZZ_4L_alpha4)[i], f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_qq_ZZ_4L_Chi3Dlog->size(); i++)
        {
            h_diboson_Chi3Dlog->Fill((*v_qq_ZZ_4L_Chi3Dlog)[i], f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_qq_ZZ_4L_2DIP->size(); i++)
        {
            h_diboson_IP2D->Fill(log10(abs((*v_qq_ZZ_4L_2DIP)[i])), f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight);
        }
        for (size_t i = 0; i < v_qq_ZZ_4L_nTracks->size(); i++)
        {
            h_diboson_nTracks->Fill((*v_qq_ZZ_4L_nTracks)[i], f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight);
        }
    }
    h_diboson_IP2D->SetLineWidth(2);
    h_diboson_IP2D->Draw();
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_diboson_Met->Write();
    h_diboson_nTracks->Write();
    h_diboson_IP2D->Write();
    h_diboson_Chi3Dlog->Write();
    for (int i = 0; i < 4; i++)
    {
        h_diboson_alpha[i]->Write();
    }
    outfile_HT0->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_diboson_produce();
    }
    else if (argc == 3)
    {
        ee_diboson_produce(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}