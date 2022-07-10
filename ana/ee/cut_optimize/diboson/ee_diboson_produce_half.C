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

TFile *diboson_gg_ZZ_2e2mu = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2mu.root");
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

//---------------------
// Define Diboson Weight
//---------------------
double diboson_gg_ZZ_2e2mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2mu / (gg_ZZ_2e2mu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2e2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2nu / (gg_ZZ_2e2nu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2e2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2tau / (gg_ZZ_2e2tau_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2mu2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2nu / (gg_ZZ_2mu2nu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2mu2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2tau / (gg_ZZ_2mu2tau_totevt)) * 1000 * 2;
double diboson_gg_ZZ_4e_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4e / (gg_ZZ_4e_totevt)) * 1000 * 2;
double diboson_gg_ZZ_4mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4mu / (gg_ZZ_4mu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_4tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4tau / (gg_ZZ_4tau_totevt)) * 1000 * 2;
double diboson_gg_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WW_2L2Nu / (gg_WW_2L2Nu_totevt)) * 1000 * 2;
double diboson_qq_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Nu / (qq_WW_2L2Nu_totevt)) * 1000 * 2;
double diboson_qq_WZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_2L2Q / (qq_WZ_2L2Q_totevt)) * 1000 * 2;
double diboson_qq_WZ_3LNu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_3LNu / (qq_WZ_3LNu_totevt)) * 1000 * 2;
double diboson_qq_ZZ_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Nu / (qq_ZZ_2L2Nu_totevt)) * 1000 * 2;
double diboson_qq_ZZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Q / (qq_ZZ_2L2Q_totevt)) * 1000 * 2;
double diboson_qq_ZZ_4L_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_4L / (qq_ZZ_4L_totevt)) * 1000 * 2;

void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, int flavor2, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

void ee_diboson_produce_half(TString inputfile = "./../../../../../../root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2mu.root", TString outputfile1 = "./ee_Diboson_emjet_half.root")
{
    TFile *diboson_gg_ZZ_2e2mu_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_gg_ZZ_2e2mu_1.root");
    TFile *diboson_gg_ZZ_2e2nu_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_gg_ZZ_2e2nu_1.root");
    TFile *diboson_gg_ZZ_2e2tau_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_gg_ZZ_2e2tau_1.root");
    TFile *diboson_gg_ZZ_2mu2nu_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_gg_ZZ_2mu2nu_1.root");
    TFile *diboson_gg_ZZ_2mu2tau_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_gg_ZZ_2mu2tau_1.root");
    TFile *diboson_gg_ZZ_4e_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_gg_ZZ_4e_1.root");
    TFile *diboson_gg_ZZ_4mu_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_gg_ZZ_4mu_1.root");
    TFile *diboson_gg_ZZ_4tau_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_gg_ZZ_4tau_1.root");
    TFile *diboson_gg_WW_2L2Nu_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_gg_WW_2L2Nu_1.root");
    TFile *diboson_qq_WW_2L2Nu_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_qq_WW_2L2Nu_1.root");
    TFile *diboson_qq_WZ_2L2Q_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_qq_WZ_2L2Q_1.root");
    TFile *diboson_qq_WZ_3LNu_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_qq_WZ_3LNu_1.root");
    TFile *diboson_qq_ZZ_2L2Nu_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_qq_ZZ_2L2Nu_1.root");
    TFile *diboson_qq_ZZ_2L2Q_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_qq_ZZ_2L2Q_1.root");
    TFile *diboson_qq_ZZ_4L_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/diboson_qq_ZZ_4L_1.root");

    //-------------
    //  nTracks
    //-------------
    const Int_t XBINS = 20;
    Double_t xEdges[XBINS + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13., 14., 15., 16.,
                                  17., 18., 19., 20., 50.};
    TH1D *h_diboson_nTracks = new TH1D("h_diboson_nTracks", "", XBINS, xEdges);
    h_diboson_nTracks->GetXaxis()->SetTitle("");
    h_diboson_nTracks->GetYaxis()->SetTitle("");
    h_diboson_nTracks->Sumw2();

    TH1D *h_diboson_nTracks_cut = new TH1D("h_diboson_nTracks_cut", "", XBINS, xEdges);
    h_diboson_nTracks_cut->GetXaxis()->SetTitle("");
    h_diboson_nTracks_cut->GetYaxis()->SetTitle("");
    h_diboson_nTracks_cut->Sumw2();

    TH1D *h_diboson_nTracks_heavy = new TH1D("h_diboson_nTracks_heavy", "", XBINS, xEdges);
    h_diboson_nTracks_heavy->GetXaxis()->SetTitle("");
    h_diboson_nTracks_heavy->GetYaxis()->SetTitle("");
    h_diboson_nTracks_heavy->Sumw2();

    TH1D *h_diboson_nTracks_heavy_cut = new TH1D("h_diboson_nTracks_heavy_cut", "", XBINS, xEdges);
    h_diboson_nTracks_heavy_cut->GetXaxis()->SetTitle("");
    h_diboson_nTracks_heavy_cut->GetYaxis()->SetTitle("");
    h_diboson_nTracks_heavy_cut->Sumw2();

    TH1D *h_diboson_nTracks_bjet = new TH1D("h_diboson_nTracks_bjet", "", XBINS, xEdges);
    h_diboson_nTracks_bjet->GetXaxis()->SetTitle("");
    h_diboson_nTracks_bjet->GetYaxis()->SetTitle("");
    h_diboson_nTracks_bjet->Sumw2();

    TH1D *h_diboson_nTracks_bjet_cut = new TH1D("h_diboson_nTracks_bjet_cut", "", XBINS, xEdges);
    h_diboson_nTracks_bjet_cut->GetXaxis()->SetTitle("");
    h_diboson_nTracks_bjet_cut->GetYaxis()->SetTitle("");
    h_diboson_nTracks_bjet_cut->Sumw2();

    TH1D *h_diboson_nTracks_cjet = new TH1D("h_diboson_nTracks_cjet", "", XBINS, xEdges);
    h_diboson_nTracks_cjet->GetXaxis()->SetTitle("");
    h_diboson_nTracks_cjet->GetYaxis()->SetTitle("");
    h_diboson_nTracks_cjet->Sumw2();

    TH1D *h_diboson_nTracks_cjet_cut = new TH1D("h_diboson_nTracks_cjet_cut", "", XBINS, xEdges);
    h_diboson_nTracks_cjet_cut->GetXaxis()->SetTitle("");
    h_diboson_nTracks_cjet_cut->GetYaxis()->SetTitle("");
    h_diboson_nTracks_cjet_cut->Sumw2();

    TH1D *h_diboson_nTracks_heavy_nogluon = new TH1D("h_diboson_nTracks_heavy_nogluon", "", XBINS, xEdges);
    h_diboson_nTracks_heavy_nogluon->GetXaxis()->SetTitle("");
    h_diboson_nTracks_heavy_nogluon->GetYaxis()->SetTitle("");
    h_diboson_nTracks_heavy_nogluon->Sumw2();

    TH1D *h_diboson_nTracks_heavy_nogluon_cut = new TH1D("h_diboson_nTracks_heavy_nogluon_cut", "", XBINS, xEdges);
    h_diboson_nTracks_heavy_nogluon_cut->GetXaxis()->SetTitle("");
    h_diboson_nTracks_heavy_nogluon_cut->GetYaxis()->SetTitle("");
    h_diboson_nTracks_heavy_nogluon_cut->Sumw2();

    TH1D *h_diboson_nTracks_light = new TH1D("h_diboson_nTracks_light", "", XBINS, xEdges);
    h_diboson_nTracks_light->GetXaxis()->SetTitle("");
    h_diboson_nTracks_light->GetYaxis()->SetTitle("");
    h_diboson_nTracks_light->Sumw2();

    TH1D *h_diboson_nTracks_light_cut = new TH1D("h_diboson_nTracks_light_cut", "", XBINS, xEdges);
    h_diboson_nTracks_light_cut->GetXaxis()->SetTitle("");
    h_diboson_nTracks_light_cut->GetYaxis()->SetTitle("");
    h_diboson_nTracks_light_cut->Sumw2();

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
    diboson_gg_ZZ_2e2mu_1->GetObject("h1", T_event);
    T_event->SetBranchAddress("I_weight", &f_gg_ZZ_2e2mu_weight);
    T_event->SetBranchAddress("f_Met", &f_gg_ZZ_2e2mu_met);
    T_event->SetBranchAddress("v_IP2D", &v_gg_ZZ_2e2mu_2DIP);
    T_event->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_2e2mu_Chi3Dlog);
    T_event->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_2e2mu_nTracks);
    T_event->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2e2mu_alpha);
    T_event->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_2e2mu_Jethadronflavor);
    T_event->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_2e2mu_Jetpartonflavor);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        double gg_ZZ_2e2mu_eventWeight = f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight;
        if (f_gg_ZZ_2e2mu_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2mu_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_gg_ZZ_2e2mu_Jethadronflavor)[i], (*v_gg_ZZ_2e2mu_nTracks)[i], gg_ZZ_2e2mu_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_gg_ZZ_2e2mu_Jethadronflavor)[i], (*v_gg_ZZ_2e2mu_nTracks)[i], gg_ZZ_2e2mu_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_gg_ZZ_2e2mu_Jethadronflavor)[i], (*v_gg_ZZ_2e2mu_nTracks)[i], gg_ZZ_2e2mu_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_gg_ZZ_2e2mu_Jethadronflavor)[i], (*v_gg_ZZ_2e2mu_nTracks)[i], gg_ZZ_2e2mu_eventWeight, h_diboson_nTracks_light);
            if ((*v_gg_ZZ_2e2mu_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_gg_ZZ_2e2mu_Jethadronflavor)[i], (*v_gg_ZZ_2e2mu_nTracks)[i], gg_ZZ_2e2mu_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_gg_ZZ_2e2mu_Jethadronflavor)[i], (*v_gg_ZZ_2e2mu_nTracks)[i], gg_ZZ_2e2mu_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_gg_ZZ_2e2mu_Jethadronflavor)[i], (*v_gg_ZZ_2e2mu_nTracks)[i], gg_ZZ_2e2mu_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_gg_ZZ_2e2mu_Jethadronflavor)[i], (*v_gg_ZZ_2e2mu_nTracks)[i], gg_ZZ_2e2mu_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event1;
    diboson_gg_ZZ_2e2nu_1->GetObject("h1", T_event1);
    T_event1->SetBranchAddress("I_weight", &f_gg_ZZ_2e2nu_weight);
    T_event1->SetBranchAddress("f_Met", &f_gg_ZZ_2e2nu_met);
    T_event1->SetBranchAddress("v_IP2D", &v_gg_ZZ_2e2nu_2DIP);
    T_event1->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_2e2nu_Chi3Dlog);
    T_event1->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_2e2nu_nTracks);
    T_event1->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2e2nu_alpha);
    T_event1->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_2e2nu_Jethadronflavor);
    T_event1->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_2e2nu_Jetpartonflavor);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        double gg_ZZ_2e2nu_eventWeight = f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight;
        if (f_gg_ZZ_2e2nu_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2nu_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_gg_ZZ_2e2nu_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2nu_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_gg_ZZ_2e2nu_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2nu_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_gg_ZZ_2e2nu_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2nu_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_gg_ZZ_2e2nu_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2nu_eventWeight, h_diboson_nTracks_light);
            if ((*v_gg_ZZ_2e2nu_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_gg_ZZ_2e2nu_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2nu_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_gg_ZZ_2e2nu_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2nu_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_gg_ZZ_2e2nu_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2nu_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_gg_ZZ_2e2nu_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2nu_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event2;
    diboson_gg_ZZ_2e2tau_1->GetObject("h1", T_event2);
    T_event2->SetBranchAddress("I_weight", &f_gg_ZZ_2e2tau_weight);
    T_event2->SetBranchAddress("f_Met", &f_gg_ZZ_2e2tau_met);
    T_event2->SetBranchAddress("v_IP2D", &v_gg_ZZ_2e2tau_2DIP);
    T_event2->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_2e2tau_Chi3Dlog);
    T_event2->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_2e2tau_nTracks);
    T_event2->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2e2tau_alpha);
    T_event2->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_2e2tau_Jethadronflavor);
    T_event2->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_2e2tau_Jetpartonflavor);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        double gg_ZZ_2e2tau_eventWeight = f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight;
        if (f_gg_ZZ_2e2tau_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_gg_ZZ_2e2tau_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_gg_ZZ_2e2tau_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2tau_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_gg_ZZ_2e2tau_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2tau_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_gg_ZZ_2e2tau_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2tau_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_gg_ZZ_2e2tau_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2tau_eventWeight, h_diboson_nTracks_light);
            if ((*v_gg_ZZ_2e2tau_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_gg_ZZ_2e2tau_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2tau_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_gg_ZZ_2e2tau_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2tau_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_gg_ZZ_2e2tau_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2tau_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_gg_ZZ_2e2tau_Jethadronflavor)[i], (*v_gg_ZZ_2e2nu_nTracks)[i], gg_ZZ_2e2tau_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event3;
    diboson_gg_ZZ_2mu2nu_1->GetObject("h1", T_event3);
    T_event3->SetBranchAddress("I_weight", &f_gg_ZZ_2mu2nu_weight);
    T_event3->SetBranchAddress("f_Met", &f_gg_ZZ_2mu2nu_met);
    T_event3->SetBranchAddress("v_IP2D", &v_gg_ZZ_2mu2nu_2DIP);
    T_event3->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_2mu2nu_Chi3Dlog);
    T_event3->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_2mu2nu_nTracks);
    T_event3->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2mu2nu_alpha);
    T_event3->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_2mu2nu_Jethadronflavor);
    T_event3->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_2mu2nu_Jetpartonflavor);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);

        double gg_ZZ_2mu2nu_eventWeight = f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight;
        if (f_gg_ZZ_2mu2nu_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_gg_ZZ_2mu2nu_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_gg_ZZ_2mu2nu_Jethadronflavor)[i], (*v_gg_ZZ_2mu2nu_nTracks)[i], gg_ZZ_2mu2nu_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_gg_ZZ_2mu2nu_Jethadronflavor)[i], (*v_gg_ZZ_2mu2nu_nTracks)[i], gg_ZZ_2mu2nu_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_gg_ZZ_2mu2nu_Jethadronflavor)[i], (*v_gg_ZZ_2mu2nu_nTracks)[i], gg_ZZ_2mu2nu_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_gg_ZZ_2mu2nu_Jethadronflavor)[i], (*v_gg_ZZ_2mu2nu_nTracks)[i], gg_ZZ_2mu2nu_eventWeight, h_diboson_nTracks_light);

            if ((*v_gg_ZZ_2mu2nu_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_gg_ZZ_2mu2nu_Jethadronflavor)[i], (*v_gg_ZZ_2mu2nu_nTracks)[i], gg_ZZ_2mu2nu_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_gg_ZZ_2mu2nu_Jethadronflavor)[i], (*v_gg_ZZ_2mu2nu_nTracks)[i], gg_ZZ_2mu2nu_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_gg_ZZ_2mu2nu_Jethadronflavor)[i], (*v_gg_ZZ_2mu2nu_nTracks)[i], gg_ZZ_2mu2nu_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_gg_ZZ_2mu2nu_Jethadronflavor)[i], (*v_gg_ZZ_2mu2nu_nTracks)[i], gg_ZZ_2mu2nu_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event4;
    diboson_gg_ZZ_2mu2tau_1->GetObject("h1", T_event4);
    T_event4->SetBranchAddress("I_weight", &f_gg_ZZ_2mu2tau_weight);
    T_event4->SetBranchAddress("f_Met", &f_gg_ZZ_2mu2tau_met);
    T_event4->SetBranchAddress("v_IP2D", &v_gg_ZZ_2mu2tau_2DIP);
    T_event4->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_2mu2tau_Chi3Dlog);
    T_event4->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_2mu2tau_nTracks);
    T_event4->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2mu2tau_alpha);
    T_event4->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_2mu2tau_Jethadronflavor);
    T_event4->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_2mu2tau_Jetpartonflavor);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);

        double gg_ZZ_2mu2tau_eventWeight = f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight;
        if (f_gg_ZZ_2mu2tau_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_gg_ZZ_2mu2tau_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_gg_ZZ_2mu2tau_Jethadronflavor)[i], (*v_gg_ZZ_2mu2tau_nTracks)[i], gg_ZZ_2mu2tau_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_gg_ZZ_2mu2tau_Jethadronflavor)[i], (*v_gg_ZZ_2mu2tau_nTracks)[i], gg_ZZ_2mu2tau_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_gg_ZZ_2mu2tau_Jethadronflavor)[i], (*v_gg_ZZ_2mu2tau_nTracks)[i], gg_ZZ_2mu2tau_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_gg_ZZ_2mu2tau_Jethadronflavor)[i], (*v_gg_ZZ_2mu2tau_nTracks)[i], gg_ZZ_2mu2tau_eventWeight, h_diboson_nTracks_light);

            if ((*v_gg_ZZ_2mu2tau_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_gg_ZZ_2mu2tau_Jethadronflavor)[i], (*v_gg_ZZ_2mu2tau_nTracks)[i], gg_ZZ_2mu2tau_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_gg_ZZ_2mu2tau_Jethadronflavor)[i], (*v_gg_ZZ_2mu2tau_nTracks)[i], gg_ZZ_2mu2tau_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_gg_ZZ_2mu2tau_Jethadronflavor)[i], (*v_gg_ZZ_2mu2tau_nTracks)[i], gg_ZZ_2mu2tau_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_gg_ZZ_2mu2tau_Jethadronflavor)[i], (*v_gg_ZZ_2mu2tau_nTracks)[i], gg_ZZ_2mu2tau_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event5;
    diboson_gg_ZZ_4e_1->GetObject("h1", T_event5);
    T_event5->SetBranchAddress("I_weight", &f_gg_ZZ_4e_weight);
    T_event5->SetBranchAddress("f_Met", &f_gg_ZZ_4e_met);
    T_event5->SetBranchAddress("v_IP2D", &v_gg_ZZ_4e_2DIP);
    T_event5->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_4e_Chi3Dlog);
    T_event5->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_4e_nTracks);
    T_event5->SetBranchAddress("v_fakealpha", &v_gg_ZZ_4e_alpha);
    T_event5->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_4e_Jethadronflavor);
    T_event5->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_4e_Jetpartonflavor);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);

        double gg_ZZ_4e_eventWeight = f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight;
        if (f_gg_ZZ_4e_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_gg_ZZ_4e_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_gg_ZZ_4e_Jethadronflavor)[i], (*v_gg_ZZ_4e_nTracks)[i], gg_ZZ_4e_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_gg_ZZ_4e_Jethadronflavor)[i], (*v_gg_ZZ_4e_nTracks)[i], gg_ZZ_4e_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_gg_ZZ_4e_Jethadronflavor)[i], (*v_gg_ZZ_4e_nTracks)[i], gg_ZZ_4e_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_gg_ZZ_4e_Jethadronflavor)[i], (*v_gg_ZZ_4e_nTracks)[i], gg_ZZ_4e_eventWeight, h_diboson_nTracks_light);
            if ((*v_gg_ZZ_4e_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_gg_ZZ_4e_Jethadronflavor)[i], (*v_gg_ZZ_4e_nTracks)[i], gg_ZZ_4e_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_gg_ZZ_4e_Jethadronflavor)[i], (*v_gg_ZZ_4e_nTracks)[i], gg_ZZ_4e_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_gg_ZZ_4e_Jethadronflavor)[i], (*v_gg_ZZ_4e_nTracks)[i], gg_ZZ_4e_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_gg_ZZ_4e_Jethadronflavor)[i], (*v_gg_ZZ_4e_nTracks)[i], gg_ZZ_4e_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event6;
    diboson_gg_ZZ_4mu_1->GetObject("h1", T_event6);
    T_event6->SetBranchAddress("I_weight", &f_gg_ZZ_4mu_weight);
    T_event6->SetBranchAddress("f_Met", &f_gg_ZZ_4mu_met);
    T_event6->SetBranchAddress("v_IP2D", &v_gg_ZZ_4mu_2DIP);
    T_event6->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_4mu_Chi3Dlog);
    T_event6->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_4mu_nTracks);
    T_event6->SetBranchAddress("v_fakealpha", &v_gg_ZZ_4mu_alpha);
    T_event6->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_4mu_Jethadronflavor);
    T_event6->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_4mu_Jetpartonflavor);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);

        double gg_ZZ_4mu_eventWeight = f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight;
        if (f_gg_ZZ_4mu_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_gg_ZZ_4mu_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_gg_ZZ_4mu_Jethadronflavor)[i], (*v_gg_ZZ_4mu_nTracks)[i], gg_ZZ_4mu_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_gg_ZZ_4mu_Jethadronflavor)[i], (*v_gg_ZZ_4mu_nTracks)[i], gg_ZZ_4mu_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_gg_ZZ_4mu_Jethadronflavor)[i], (*v_gg_ZZ_4mu_nTracks)[i], gg_ZZ_4mu_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_gg_ZZ_4mu_Jethadronflavor)[i], (*v_gg_ZZ_4mu_nTracks)[i], gg_ZZ_4mu_eventWeight, h_diboson_nTracks_light);
            if ((*v_gg_ZZ_4mu_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_gg_ZZ_4mu_Jethadronflavor)[i], (*v_gg_ZZ_4mu_nTracks)[i], gg_ZZ_4mu_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_gg_ZZ_4mu_Jethadronflavor)[i], (*v_gg_ZZ_4mu_nTracks)[i], gg_ZZ_4mu_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_gg_ZZ_4mu_Jethadronflavor)[i], (*v_gg_ZZ_4mu_nTracks)[i], gg_ZZ_4mu_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_gg_ZZ_4mu_Jethadronflavor)[i], (*v_gg_ZZ_4mu_nTracks)[i], gg_ZZ_4mu_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event7;
    diboson_gg_ZZ_4tau_1->GetObject("h1", T_event7);
    T_event7->SetBranchAddress("I_weight", &f_gg_ZZ_4tau_weight);
    T_event7->SetBranchAddress("f_Met", &f_gg_ZZ_4tau_met);
    T_event7->SetBranchAddress("v_IP2D", &v_gg_ZZ_4tau_2DIP);
    T_event7->SetBranchAddress("v_Chi3Dlog", &v_gg_ZZ_4tau_Chi3Dlog);
    T_event7->SetBranchAddress("v_N_Tracks", &v_gg_ZZ_4tau_nTracks);
    T_event7->SetBranchAddress("v_fakealpha", &v_gg_ZZ_4tau_alpha);
    T_event7->SetBranchAddress("v_fakeJethadronflavor", &v_gg_ZZ_4tau_Jethadronflavor);
    T_event7->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_ZZ_4tau_Jetpartonflavor);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);

        double gg_ZZ_4tau_eventWeight = f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight;
        if (f_gg_ZZ_4tau_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_gg_ZZ_4tau_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_gg_ZZ_4tau_Jethadronflavor)[i], (*v_gg_ZZ_4tau_nTracks)[i], gg_ZZ_4tau_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_gg_ZZ_4tau_Jethadronflavor)[i], (*v_gg_ZZ_4tau_nTracks)[i], gg_ZZ_4tau_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_gg_ZZ_4tau_Jethadronflavor)[i], (*v_gg_ZZ_4tau_nTracks)[i], gg_ZZ_4tau_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_gg_ZZ_4tau_Jethadronflavor)[i], (*v_gg_ZZ_4tau_nTracks)[i], gg_ZZ_4tau_eventWeight, h_diboson_nTracks_light);
            if ((*v_gg_ZZ_4tau_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_gg_ZZ_4tau_Jethadronflavor)[i], (*v_gg_ZZ_4tau_nTracks)[i], gg_ZZ_4tau_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_gg_ZZ_4tau_Jethadronflavor)[i], (*v_gg_ZZ_4tau_nTracks)[i], gg_ZZ_4tau_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_gg_ZZ_4tau_Jethadronflavor)[i], (*v_gg_ZZ_4tau_nTracks)[i], gg_ZZ_4tau_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_gg_ZZ_4tau_Jethadronflavor)[i], (*v_gg_ZZ_4tau_nTracks)[i], gg_ZZ_4tau_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event8;
    diboson_gg_WW_2L2Nu_1->GetObject("h1", T_event8);
    T_event8->SetBranchAddress("I_weight", &f_gg_WW_2L2Nu_weight);
    T_event8->SetBranchAddress("f_Met", &f_gg_WW_2L2Nu_met);
    T_event8->SetBranchAddress("v_IP2D", &v_gg_WW_2L2Nu_2DIP);
    T_event8->SetBranchAddress("v_Chi3Dlog", &v_gg_WW_2L2Nu_Chi3Dlog);
    T_event8->SetBranchAddress("v_N_Tracks", &v_gg_WW_2L2Nu_nTracks);
    T_event8->SetBranchAddress("v_fakealpha", &v_gg_WW_2L2Nu_alpha);
    T_event8->SetBranchAddress("v_fakeJethadronflavor", &v_gg_WW_2L2Nu_Jethadronflavor);
    T_event8->SetBranchAddress("v_fakeJetpartonflavor", &v_gg_WW_2L2Nu_Jetpartonflavor);
    for (int evt = 0; evt < T_event8->GetEntries(); evt++)
    {
        T_event8->GetEntry(evt);

        double gg_WW_2L2Nu_eventWeight = f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight;
        if (f_gg_WW_2L2Nu_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_gg_WW_2L2Nu_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_gg_WW_2L2Nu_Jethadronflavor)[i], (*v_gg_WW_2L2Nu_nTracks)[i], gg_WW_2L2Nu_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_gg_WW_2L2Nu_Jethadronflavor)[i], (*v_gg_WW_2L2Nu_nTracks)[i], gg_WW_2L2Nu_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_gg_WW_2L2Nu_Jethadronflavor)[i], (*v_gg_WW_2L2Nu_nTracks)[i], gg_WW_2L2Nu_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_gg_WW_2L2Nu_Jethadronflavor)[i], (*v_gg_WW_2L2Nu_nTracks)[i], gg_WW_2L2Nu_eventWeight, h_diboson_nTracks_light);
            if ((*v_gg_WW_2L2Nu_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_gg_WW_2L2Nu_Jethadronflavor)[i], (*v_gg_WW_2L2Nu_nTracks)[i], gg_WW_2L2Nu_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_gg_WW_2L2Nu_Jethadronflavor)[i], (*v_gg_WW_2L2Nu_nTracks)[i], gg_WW_2L2Nu_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_gg_WW_2L2Nu_Jethadronflavor)[i], (*v_gg_WW_2L2Nu_nTracks)[i], gg_WW_2L2Nu_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_gg_WW_2L2Nu_Jethadronflavor)[i], (*v_gg_WW_2L2Nu_nTracks)[i], gg_WW_2L2Nu_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event9;
    diboson_qq_WW_2L2Nu_1->GetObject("h1", T_event9);
    T_event9->SetBranchAddress("I_weight", &f_qq_WW_2L2Nu_weight);
    T_event9->SetBranchAddress("f_Met", &f_qq_WW_2L2Nu_met);
    T_event9->SetBranchAddress("v_IP2D", &v_qq_WW_2L2Nu_2DIP);
    T_event9->SetBranchAddress("v_Chi3Dlog", &v_qq_WW_2L2Nu_Chi3Dlog);
    T_event9->SetBranchAddress("v_N_Tracks", &v_qq_WW_2L2Nu_nTracks);
    T_event9->SetBranchAddress("v_fakealpha", &v_qq_WW_2L2Nu_alpha);
    T_event9->SetBranchAddress("v_fakeJethadronflavor", &v_qq_WW_2L2Nu_Jethadronflavor);
    T_event9->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_WW_2L2Nu_Jetpartonflavor);
    for (int evt = 0; evt < T_event9->GetEntries(); evt++)
    {
        T_event9->GetEntry(evt);

        double qq_WW_2L2Nu_eventWeight = f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight;
        if (f_qq_WW_2L2Nu_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_qq_WW_2L2Nu_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_qq_WW_2L2Nu_Jethadronflavor)[i], (*v_qq_WW_2L2Nu_nTracks)[i], qq_WW_2L2Nu_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_qq_WW_2L2Nu_Jethadronflavor)[i], (*v_qq_WW_2L2Nu_nTracks)[i], qq_WW_2L2Nu_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_qq_WW_2L2Nu_Jethadronflavor)[i], (*v_qq_WW_2L2Nu_nTracks)[i], qq_WW_2L2Nu_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_qq_WW_2L2Nu_Jethadronflavor)[i], (*v_qq_WW_2L2Nu_nTracks)[i], qq_WW_2L2Nu_eventWeight, h_diboson_nTracks_light);

            if ((*v_qq_WW_2L2Nu_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_qq_WW_2L2Nu_Jethadronflavor)[i], (*v_qq_WW_2L2Nu_nTracks)[i], qq_WW_2L2Nu_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_qq_WW_2L2Nu_Jethadronflavor)[i], (*v_qq_WW_2L2Nu_nTracks)[i], qq_WW_2L2Nu_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_qq_WW_2L2Nu_Jethadronflavor)[i], (*v_qq_WW_2L2Nu_nTracks)[i], qq_WW_2L2Nu_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_qq_WW_2L2Nu_Jethadronflavor)[i], (*v_qq_WW_2L2Nu_nTracks)[i], qq_WW_2L2Nu_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event10;
    diboson_qq_WZ_2L2Q_1->GetObject("h1", T_event10);
    T_event10->SetBranchAddress("I_weight", &f_qq_WZ_2L2Q_weight);
    T_event10->SetBranchAddress("f_Met", &f_qq_WZ_2L2Q_met);
    T_event10->SetBranchAddress("v_IP2D", &v_qq_WZ_2L2Q_2DIP);
    T_event10->SetBranchAddress("v_Chi3Dlog", &v_qq_WZ_2L2Q_Chi3Dlog);
    T_event10->SetBranchAddress("v_N_Tracks", &v_qq_WZ_2L2Q_nTracks);
    T_event10->SetBranchAddress("v_fakealpha", &v_qq_WZ_2L2Q_alpha);
    T_event10->SetBranchAddress("v_fakeJethadronflavor", &v_qq_WZ_2L2Q_Jethadronflavor);
    T_event10->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_WZ_2L2Q_Jetpartonflavor);
    for (int evt = 0; evt < T_event10->GetEntries(); evt++)
    {
        T_event10->GetEntry(evt);

        double qq_WZ_2L2Q_eventWeight = f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight;
        if (f_qq_WZ_2L2Q_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_qq_WZ_2L2Q_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_qq_WZ_2L2Q_Jethadronflavor)[i], (*v_qq_WZ_2L2Q_nTracks)[i], qq_WZ_2L2Q_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_qq_WZ_2L2Q_Jethadronflavor)[i], (*v_qq_WZ_2L2Q_nTracks)[i], qq_WZ_2L2Q_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_qq_WZ_2L2Q_Jethadronflavor)[i], (*v_qq_WZ_2L2Q_nTracks)[i], qq_WZ_2L2Q_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_qq_WZ_2L2Q_Jethadronflavor)[i], (*v_qq_WZ_2L2Q_nTracks)[i], qq_WZ_2L2Q_eventWeight, h_diboson_nTracks_light);

            if ((*v_qq_WZ_2L2Q_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_qq_WZ_2L2Q_Jethadronflavor)[i], (*v_qq_WZ_2L2Q_nTracks)[i], qq_WZ_2L2Q_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_qq_WZ_2L2Q_Jethadronflavor)[i], (*v_qq_WZ_2L2Q_nTracks)[i], qq_WZ_2L2Q_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_qq_WZ_2L2Q_Jethadronflavor)[i], (*v_qq_WZ_2L2Q_nTracks)[i], qq_WZ_2L2Q_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_qq_WZ_2L2Q_Jethadronflavor)[i], (*v_qq_WZ_2L2Q_nTracks)[i], qq_WZ_2L2Q_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event11;
    diboson_qq_WZ_3LNu_1->GetObject("h1", T_event11);
    T_event11->SetBranchAddress("I_weight", &f_qq_WZ_3LNu_weight);
    T_event11->SetBranchAddress("f_Met", &f_qq_WZ_3LNu_met);
    T_event11->SetBranchAddress("v_IP2D", &v_qq_WZ_3LNu_2DIP);
    T_event11->SetBranchAddress("v_Chi3Dlog", &v_qq_WZ_3LNu_Chi3Dlog);
    T_event11->SetBranchAddress("v_N_Tracks", &v_qq_WZ_3LNu_nTracks);
    T_event11->SetBranchAddress("v_fakealpha", &v_qq_WZ_3LNu_alpha);
    T_event11->SetBranchAddress("v_fakeJethadronflavor", &v_qq_WZ_3LNu_Jethadronflavor);
    T_event11->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_WZ_3LNu_Jetpartonflavor);
    for (int evt = 0; evt < T_event11->GetEntries(); evt++)
    {
        T_event11->GetEntry(evt);

        double qq_WZ_3LNu_eventWeight = f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight;
        if (f_qq_WZ_3LNu_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_qq_WZ_3LNu_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_qq_WZ_3LNu_Jethadronflavor)[i], (*v_qq_WZ_3LNu_nTracks)[i], qq_WZ_3LNu_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_qq_WZ_3LNu_Jethadronflavor)[i], (*v_qq_WZ_3LNu_nTracks)[i], qq_WZ_3LNu_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_qq_WZ_3LNu_Jethadronflavor)[i], (*v_qq_WZ_3LNu_nTracks)[i], qq_WZ_3LNu_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_qq_WZ_3LNu_Jethadronflavor)[i], (*v_qq_WZ_3LNu_nTracks)[i], qq_WZ_3LNu_eventWeight, h_diboson_nTracks_light);

            if ((*v_qq_WZ_3LNu_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_qq_WZ_3LNu_Jethadronflavor)[i], (*v_qq_WZ_3LNu_nTracks)[i], qq_WZ_3LNu_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_qq_WZ_3LNu_Jethadronflavor)[i], (*v_qq_WZ_3LNu_nTracks)[i], qq_WZ_3LNu_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_qq_WZ_3LNu_Jethadronflavor)[i], (*v_qq_WZ_3LNu_nTracks)[i], qq_WZ_3LNu_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_qq_WZ_3LNu_Jethadronflavor)[i], (*v_qq_WZ_3LNu_nTracks)[i], qq_WZ_3LNu_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event12;
    diboson_qq_ZZ_2L2Nu_1->GetObject("h1", T_event12);
    T_event12->SetBranchAddress("I_weight", &f_qq_ZZ_2L2Nu_weight);
    T_event12->SetBranchAddress("f_Met", &f_qq_ZZ_2L2Nu_met);
    T_event12->SetBranchAddress("v_IP2D", &v_qq_ZZ_2L2Nu_2DIP);
    T_event12->SetBranchAddress("v_Chi3Dlog", &v_qq_ZZ_2L2Nu_Chi3Dlog);
    T_event12->SetBranchAddress("v_N_Tracks", &v_qq_ZZ_2L2Nu_nTracks);
    T_event12->SetBranchAddress("v_fakealpha", &v_qq_ZZ_2L2Nu_alpha);
    T_event12->SetBranchAddress("v_fakeJethadronflavor", &v_qq_ZZ_2L2Nu_Jethadronflavor);
    T_event12->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_ZZ_2L2Nu_Jetpartonflavor);
    for (int evt = 0; evt < T_event12->GetEntries(); evt++)
    {
        T_event12->GetEntry(evt);

        double qq_ZZ_2L2Nu_eventWeight = f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight;
        if (f_qq_ZZ_2L2Nu_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_qq_ZZ_2L2Nu_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_qq_ZZ_2L2Nu_Jethadronflavor)[i], (*v_qq_ZZ_2L2Nu_nTracks)[i], qq_ZZ_2L2Nu_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_qq_ZZ_2L2Nu_Jethadronflavor)[i], (*v_qq_ZZ_2L2Nu_nTracks)[i], qq_ZZ_2L2Nu_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_qq_ZZ_2L2Nu_Jethadronflavor)[i], (*v_qq_ZZ_2L2Nu_nTracks)[i], qq_ZZ_2L2Nu_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_qq_ZZ_2L2Nu_Jethadronflavor)[i], (*v_qq_ZZ_2L2Nu_nTracks)[i], qq_ZZ_2L2Nu_eventWeight, h_diboson_nTracks_light);

            if ((*v_qq_ZZ_2L2Nu_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_qq_ZZ_2L2Nu_Jethadronflavor)[i], (*v_qq_ZZ_2L2Nu_nTracks)[i], qq_ZZ_2L2Nu_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_qq_ZZ_2L2Nu_Jethadronflavor)[i], (*v_qq_ZZ_2L2Nu_nTracks)[i], qq_ZZ_2L2Nu_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_qq_ZZ_2L2Nu_Jethadronflavor)[i], (*v_qq_ZZ_2L2Nu_nTracks)[i], qq_ZZ_2L2Nu_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_qq_ZZ_2L2Nu_Jethadronflavor)[i], (*v_qq_ZZ_2L2Nu_nTracks)[i], qq_ZZ_2L2Nu_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event13;
    diboson_qq_ZZ_2L2Q_1->GetObject("h1", T_event13);
    T_event13->SetBranchAddress("I_weight", &f_qq_ZZ_2L2Q_weight);
    T_event13->SetBranchAddress("f_Met", &f_qq_ZZ_2L2Q_met);
    T_event13->SetBranchAddress("v_IP2D", &v_qq_ZZ_2L2Q_2DIP);
    T_event13->SetBranchAddress("v_Chi3Dlog", &v_qq_ZZ_2L2Q_Chi3Dlog);
    T_event13->SetBranchAddress("v_N_Tracks", &v_qq_ZZ_2L2Q_nTracks);
    T_event13->SetBranchAddress("v_fakealpha", &v_qq_ZZ_2L2Q_alpha);
    T_event13->SetBranchAddress("v_fakeJethadronflavor", &v_qq_ZZ_2L2Q_Jethadronflavor);
    T_event13->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_ZZ_2L2Q_Jetpartonflavor);
    for (int evt = 0; evt < T_event13->GetEntries(); evt++)
    {
        T_event13->GetEntry(evt);

        double qq_ZZ_2L2Q_eventWeight = f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight;
        if (f_qq_ZZ_2L2Q_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_qq_ZZ_2L2Q_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_qq_ZZ_2L2Q_Jethadronflavor)[i], (*v_qq_ZZ_2L2Q_nTracks)[i], qq_ZZ_2L2Q_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_qq_ZZ_2L2Q_Jethadronflavor)[i], (*v_qq_ZZ_2L2Q_nTracks)[i], qq_ZZ_2L2Q_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_qq_ZZ_2L2Q_Jethadronflavor)[i], (*v_qq_ZZ_2L2Q_nTracks)[i], qq_ZZ_2L2Q_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_qq_ZZ_2L2Q_Jethadronflavor)[i], (*v_qq_ZZ_2L2Q_nTracks)[i], qq_ZZ_2L2Q_eventWeight, h_diboson_nTracks_light);

            if ((*v_qq_ZZ_2L2Q_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_qq_ZZ_2L2Q_Jethadronflavor)[i], (*v_qq_ZZ_2L2Q_nTracks)[i], qq_ZZ_2L2Q_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_qq_ZZ_2L2Q_Jethadronflavor)[i], (*v_qq_ZZ_2L2Q_nTracks)[i], qq_ZZ_2L2Q_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_qq_ZZ_2L2Q_Jethadronflavor)[i], (*v_qq_ZZ_2L2Q_nTracks)[i], qq_ZZ_2L2Q_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_qq_ZZ_2L2Q_Jethadronflavor)[i], (*v_qq_ZZ_2L2Q_nTracks)[i], qq_ZZ_2L2Q_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }

    TTree *T_event14;
    diboson_qq_ZZ_4L_1->GetObject("h1", T_event14);
    T_event14->SetBranchAddress("I_weight", &f_qq_ZZ_4L_weight);
    T_event14->SetBranchAddress("f_Met", &f_qq_ZZ_4L_met);
    T_event14->SetBranchAddress("v_IP2D", &v_qq_ZZ_4L_2DIP);
    T_event14->SetBranchAddress("v_Chi3Dlog", &v_qq_ZZ_4L_Chi3Dlog);
    T_event14->SetBranchAddress("v_N_Tracks", &v_qq_ZZ_4L_nTracks);
    T_event14->SetBranchAddress("v_fakealpha", &v_qq_ZZ_4L_alpha);
    T_event14->SetBranchAddress("v_fakeJethadronflavor", &v_qq_ZZ_4L_Jethadronflavor);
    T_event14->SetBranchAddress("v_fakeJetpartonflavor", &v_qq_ZZ_4L_Jetpartonflavor);
    for (int evt = 0; evt < T_event14->GetEntries(); evt++)
    {
        T_event14->GetEntry(evt);

        double qq_ZZ_4L_eventWeight = f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight;
        if (f_qq_ZZ_4L_met < 120)
        {
            continue;
        }
        for (size_t i = 0; i < v_qq_ZZ_4L_nTracks->size(); i++)
        {
            // For b jet
            for_signalflavor_jet(5, (*v_qq_ZZ_4L_Jethadronflavor)[i], (*v_qq_ZZ_4L_nTracks)[i], qq_ZZ_4L_eventWeight, h_diboson_nTracks_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_qq_ZZ_4L_Jethadronflavor)[i], (*v_qq_ZZ_4L_nTracks)[i], qq_ZZ_4L_eventWeight, h_diboson_nTracks_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_qq_ZZ_4L_Jethadronflavor)[i], (*v_qq_ZZ_4L_nTracks)[i], qq_ZZ_4L_eventWeight, h_diboson_nTracks_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_qq_ZZ_4L_Jethadronflavor)[i], (*v_qq_ZZ_4L_nTracks)[i], qq_ZZ_4L_eventWeight, h_diboson_nTracks_light);
            if ((*v_qq_ZZ_4L_alpha)[i] < 0.15)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_qq_ZZ_4L_Jethadronflavor)[i], (*v_qq_ZZ_4L_nTracks)[i], qq_ZZ_4L_eventWeight, h_diboson_nTracks_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_qq_ZZ_4L_Jethadronflavor)[i], (*v_qq_ZZ_4L_nTracks)[i], qq_ZZ_4L_eventWeight, h_diboson_nTracks_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_qq_ZZ_4L_Jethadronflavor)[i], (*v_qq_ZZ_4L_nTracks)[i], qq_ZZ_4L_eventWeight, h_diboson_nTracks_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_qq_ZZ_4L_Jethadronflavor)[i], (*v_qq_ZZ_4L_nTracks)[i], qq_ZZ_4L_eventWeight, h_diboson_nTracks_light_cut);
            }
        }
    }
    //---------------------
    // Fake rate for nTrack
    //---------------------
    TH1D *Diboson_fakeRate = (TH1D *)h_diboson_nTracks_cut->Clone("HT_fakeRate");
    Diboson_fakeRate->Divide(h_diboson_nTracks_cut, h_diboson_nTracks, 1, 1, "b");
    TH1D *Diboson_heavy_fakeRate = (TH1D *)h_diboson_nTracks_heavy_cut->Clone("Diboson_heavy_fakeRate");
    Diboson_heavy_fakeRate->Divide(h_diboson_nTracks_heavy_cut, h_diboson_nTracks_heavy, 1, 1, "b");
    TH1D *Diboson_bjet_fakeRate = (TH1D *)h_diboson_nTracks_bjet_cut->Clone("Diboson_bjet_fakeRate");
    Diboson_bjet_fakeRate->Divide(h_diboson_nTracks_bjet_cut, h_diboson_nTracks_bjet, 1, 1, "b");
    TH1D *Diboson_cjet_fakeRate = (TH1D *)h_diboson_nTracks_cjet_cut->Clone("Diboson_cjet_fakeRate");
    Diboson_cjet_fakeRate->Divide(h_diboson_nTracks_cjet_cut, h_diboson_nTracks_cjet, 1, 1, "b");
    TH1D *Diboson_light_fakeRate = (TH1D *)h_diboson_nTracks_light_cut->Clone("Diboson_light_fakeRate");
    Diboson_light_fakeRate->Divide(h_diboson_nTracks_light_cut, h_diboson_nTracks_light, 1, 1, "b");

    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    Diboson_fakeRate->Write();
    Diboson_heavy_fakeRate->Write();
    Diboson_bjet_fakeRate->Write();
    Diboson_cjet_fakeRate->Write();
    Diboson_light_fakeRate->Write();
    outfile_HT0->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_diboson_produce_half();
    }
    else if (argc == 3)
    {
        ee_diboson_produce_half(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}