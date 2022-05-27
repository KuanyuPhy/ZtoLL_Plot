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
#include "./../../../../lib/setNCUStyle.C"
#include "./../../../../lib/Cross_section.h"
using namespace RooFit;
using namespace std;

void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, int flavor2, int hadronflavor, float tmp, float Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

Double_t background(Double_t x)
{
    double par1 = -0.25263;
    double frac = 0.999984584;
    double par2 = -0.76;
    double par3 = 0.9;

    Double_t weight = ((TMath::Exp(par1 * x)) + frac * (1 + par2 * (x) + par3 * (2 * x * x - 1)));
    return weight;
}

Double_t bjet_background(Double_t x)
{
    double par0 = -0.36929055060873117;
    double par1 = -0.32227621971627424;
    double par2 = 0.0077448118765263176;
    double par3 = -0.0018266700500858249;
    double par4 = 0.016124941879979406;
    Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 * x + par4);
    return weight;
}
Double_t cjet_background(Double_t x)
{
    double par0 = -0.155879619433122;
    double par1 = -0.8197317704086138;
    double par2 = 0.014493676237956263;
    double par3 = -0.000158355043308647;
    double par4 = 0.005435107513335813;
    Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 * x + par4);
    return weight;
}
Double_t lightjet_background(float x)
{

    double par0 = 0.08118787223744216;
    double par1 = -0.6362557021027739;
    double par2 = 0.01143712998969338;
    double par3 = 1.142707756756366e-05;
    double par4 = -0.00014995176601499091;
    Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 * x + par4);
    return weight;
}

void Ratio_HT_apply()
{
    // setNCUStyle(true);
    TFile *DYincli = new TFile("/home/kuanyu/CMS/root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");

    TFile *DYHT100 = new TFile("/home/kuanyu/CMS/root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
    TFile *DYHT200 = new TFile("/home/kuanyu/CMS/root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
    TFile *DYHT400 = new TFile("/home/kuanyu/CMS/root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
    TFile *DYHT600 = new TFile("/home/kuanyu/CMS/root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
    TFile *DYHT800 = new TFile("/home/kuanyu/CMS/root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
    TFile *DYHT1200 = new TFile("/home/kuanyu/CMS/root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("/home/kuanyu/CMS/root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

    //-------------
    // Open Tree
    //-------------
    TFile *DYincli_2 = new TFile("/home/kuanyu/CMS/root_file/BgEstimation/ee_DYincli_2.root");
    TFile *DYHT100_2 = new TFile("/home/kuanyu/CMS/root_file/BgEstimation/ee_ht100_2.root");
    TFile *DYHT200_2 = new TFile("/home/kuanyu/CMS/root_file/BgEstimation/ee_ht200_2.root");
    TFile *DYHT400_2 = new TFile("/home/kuanyu/CMS/root_file/BgEstimation/ee_ht400_2.root");
    TFile *DYHT600_2 = new TFile("/home/kuanyu/CMS/root_file/BgEstimation/ee_ht600_2.root");
    TFile *DYHT800_2 = new TFile("/home/kuanyu/CMS/root_file/BgEstimation/ee_ht800_2.root");
    TFile *DYHT1200_2 = new TFile("/home/kuanyu/CMS/root_file/BgEstimation/ee_ht1200_2.root");
    TFile *DYHT2500_2 = new TFile("/home/kuanyu/CMS/root_file/BgEstimation/ee_ht2500_2.root");

    TFile *DYfile = new TFile("./../ee_DY_emjet_half.root");

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));

    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("Event_Variable/h_totevent"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("Event_Variable/h_totevent"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("Event_Variable/h_totevent"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("Event_Variable/h_totevent"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("Event_Variable/h_totevent"));

    TH1D *h_DY_bfake_rate = ((TH1D *)DYfile->Get("HT_bjet_fakeRate"));
    TH1D *h_DY_cfake_rate = ((TH1D *)DYfile->Get("HT_cjet_fakeRate"));
    TH1D *h_DY_lightfake_rate = ((TH1D *)DYfile->Get("HT_light_fakeRate"));

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

    // Define the HTWeight
    double HT0Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT0CS / (HT0_70_event)) * 1000 * 2;
    double HT70Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT70CS / (HT70_100_event)) * 1000 * 2;
    double HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000 * 2;
    double HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000 * 2;
    double HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000 * 2;
    double HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000 * 2;
    double HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000 * 2;
    double HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000 * 2;
    double HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000 * 2;

    //-------------
    //  nTracks
    //-------------
    TH1D *h_DY_nTracks = new TH1D("h_DY_nTracks", "", 50, 0, 50);
    h_DY_nTracks->GetXaxis()->SetTitle("");
    h_DY_nTracks->GetYaxis()->SetTitle("");
    h_DY_nTracks->Sumw2();

    TH1D *h_DY_nTracks_heavy = new TH1D("h_DY_nTracks_heavy", "", 50, 0, 50);
    h_DY_nTracks_heavy->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy->Sumw2();

    TH1D *h_DY_nTracks_bjet = new TH1D("h_DY_nTracks_bjet", "", 50, 0, 50);
    h_DY_nTracks_bjet->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet->Sumw2();

    TH1D *h_DY_nTracks_cjet = new TH1D("h_DY_nTracks_cjet", "", 50, 0, 50);
    h_DY_nTracks_cjet->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet->Sumw2();

    TH1D *h_DY_nTracks_CR = new TH1D("h_DY_nTracks_CR", "", 50, 0, 50);
    h_DY_nTracks_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_CR->Sumw2();

    TH1D *h_DY_nTracks_heavy_CR = new TH1D("h_DY_nTracks_heavy_CR", "", 50, 0, 50);
    h_DY_nTracks_heavy_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_CR->Sumw2();

    TH1D *h_DY_nTracks_bjet_CR = new TH1D("h_DY_nTracks_bjet_CR", "", 50, 0, 50);
    h_DY_nTracks_bjet_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet_CR->Sumw2();

    TH1D *h_DY_nTracks_cjet_CR = new TH1D("h_DY_nTracks_cjet_CR", "", 50, 0, 50);
    h_DY_nTracks_cjet_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet_CR->Sumw2();

    TH1D *h_DY_nTracks_cjet_bybin_CR = new TH1D("h_DY_nTracks_cjet_bybin_CR", "", 50, 0, 50);
    h_DY_nTracks_cjet_bybin_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet_bybin_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet_bybin_CR->Sumw2();

    TH1D *h_DY_nTracks_heavy_cut = new TH1D("h_DY_nTracks_heavy_cut", "", 50, 0, 50);
    h_DY_nTracks_heavy_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_cut->Sumw2();

    TH1D *h_DY_nTracks_bjet_cut = new TH1D("h_DY_nTracks_bjet_cut", "", 50, 0, 50);
    h_DY_nTracks_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet_cut->Sumw2();

    TH1D *h_DY_nTracks_bjet_bybin_CR = new TH1D("h_DY_nTracks_bjet_bybin_CR", "", 50, 0, 50);
    h_DY_nTracks_bjet_bybin_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet_bybin_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet_bybin_CR->Sumw2();

    TH1D *h_DY_nTracks_cjet_cut = new TH1D("h_DY_nTracks_cjet_cut", "", 50, 0, 50);
    h_DY_nTracks_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet_cut->Sumw2();

    TH1D *h_DY_nTracks_cjet_cut_bybin = new TH1D("h_DY_nTracks_cjet_cut_bybin", "", 50, 0, 50);
    h_DY_nTracks_cjet_cut_bybin->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet_cut_bybin->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet_cut_bybin->Sumw2();

    TH1D *h_DY_nTracks_heavy_nogluon = new TH1D("h_DY_nTracks_heavy_nogluon", "", 50, 0, 50);
    h_DY_nTracks_heavy_nogluon->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon->Sumw2();

    TH1D *h_DY_nTracks_heavy_nogluon_cut = new TH1D("h_DY_nTracks_heavy_nogluon_cut", "", 50, 0, 50);
    h_DY_nTracks_heavy_nogluon_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon_cut->Sumw2();

    TH1D *h_DY_nTracks_light = new TH1D("h_DY_nTracks_light", "", 50, 0, 50);
    h_DY_nTracks_light->GetXaxis()->SetTitle("");
    h_DY_nTracks_light->GetYaxis()->SetTitle("");
    h_DY_nTracks_light->Sumw2();

    TH1D *h_DY_nTracks_light_CR = new TH1D("h_DY_nTracks_light_CR", "", 50, 0, 50);
    h_DY_nTracks_light_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_light_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_light_CR->Sumw2();

    TH1D *h_DY_nTracks_light_bybin_CR = new TH1D("h_DY_nTracks_light_bybin_CR", "", 50, 0, 50);
    h_DY_nTracks_light_bybin_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_light_bybin_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_light_bybin_CR->Sumw2();

    TH1D *h_DY_nTracks_light_cut = new TH1D("h_DY_nTracks_light_cut", "", 50, 0, 50);
    h_DY_nTracks_light_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_light_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_light_cut->Sumw2();

    TH1D *h_DY_nTracks_light_cut_bybin = new TH1D("h_DY_nTracks_light_cut_bybin", "", 50, 0, 50);
    h_DY_nTracks_light_cut_bybin->GetXaxis()->SetTitle("");
    h_DY_nTracks_light_cut_bybin->GetYaxis()->SetTitle("");
    h_DY_nTracks_light_cut_bybin->Sumw2();

    TH1D *h_DY_nTracks_cut = new TH1D("h_DY_nTracks_cut", "", 50, 0, 50);
    h_DY_nTracks_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_cut->Sumw2();

    TH1D *h_DY_jetpt_bjet_CR = new TH1D("h_DY_jetpt_bjet_CR", "", 50, 0, 500);
    h_DY_jetpt_bjet_CR->GetXaxis()->SetTitle("");
    h_DY_jetpt_bjet_CR->GetYaxis()->SetTitle("");
    h_DY_jetpt_bjet_CR->Sumw2();

    TH1D *h_DY_jetpt_bjet_cut = new TH1D("h_DY_jetpt_bjet_cut", "", 50, 0, 500);
    h_DY_jetpt_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_jetpt_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_jetpt_bjet_cut->Sumw2();

    TH1D *h_DY_jetpt_cjet_CR = new TH1D("h_DY_jetpt_cjet_CR", "", 50, 0, 500);
    h_DY_jetpt_cjet_CR->GetXaxis()->SetTitle("");
    h_DY_jetpt_cjet_CR->GetYaxis()->SetTitle("");
    h_DY_jetpt_cjet_CR->Sumw2();

    TH1D *h_DY_jetpt_cjet_cut = new TH1D("h_DY_jetpt_cjet_cut", "", 50, 0, 500);
    h_DY_jetpt_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_jetpt_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_jetpt_cjet_cut->Sumw2();

    TH1D *h_DY_jetpt_light_CR = new TH1D("h_DY_jetpt_light_CR", "", 50, 0, 500);
    h_DY_jetpt_light_CR->GetXaxis()->SetTitle("");
    h_DY_jetpt_light_CR->GetYaxis()->SetTitle("");
    h_DY_jetpt_light_CR->Sumw2();

    TH1D *h_DY_jetpt_light_cut = new TH1D("h_DY_jetpt_light_cut", "", 50, 0, 500);
    h_DY_jetpt_light_cut->GetXaxis()->SetTitle("");
    h_DY_jetpt_light_cut->GetYaxis()->SetTitle("");
    h_DY_jetpt_light_cut->Sumw2();

    TH1D *h_DY_jeteta_bjet_CR = new TH1D("h_DY_jeteta_bjet_CR", "", 30, -3, 3);
    h_DY_jeteta_bjet_CR->GetXaxis()->SetTitle("");
    h_DY_jeteta_bjet_CR->GetYaxis()->SetTitle("");
    h_DY_jeteta_bjet_CR->Sumw2();

    TH1D *h_DY_jeteta_bjet_cut = new TH1D("h_DY_jeteta_bjet_cut", "", 30, -3, 3);
    h_DY_jeteta_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_jeteta_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_jeteta_bjet_cut->Sumw2();

    TH1D *h_DY_jeteta_cjet_CR = new TH1D("h_DY_jeteta_cjet_CR", "", 30, -3, 3);
    h_DY_jeteta_cjet_CR->GetXaxis()->SetTitle("");
    h_DY_jeteta_cjet_CR->GetYaxis()->SetTitle("");
    h_DY_jeteta_cjet_CR->Sumw2();

    TH1D *h_DY_jeteta_cjet_cut = new TH1D("h_DY_jeteta_cjet_cut", "", 30, -3, 3);
    h_DY_jeteta_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_jeteta_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_jeteta_cjet_cut->Sumw2();

    TH1D *h_DY_jeteta_light_CR = new TH1D("h_DY_jeteta_light_CR", "", 30, -3, 3);
    h_DY_jeteta_light_CR->GetXaxis()->SetTitle("");
    h_DY_jeteta_light_CR->GetYaxis()->SetTitle("");
    h_DY_jeteta_light_CR->Sumw2();

    TH1D *h_DY_jeteta_light_cut = new TH1D("h_DY_jeteta_light_cut", "", 30, -3, 3);
    h_DY_jeteta_light_cut->GetXaxis()->SetTitle("");
    h_DY_jeteta_light_cut->GetYaxis()->SetTitle("");
    h_DY_jeteta_light_cut->Sumw2();

    float HT;

    Int_t I_ht0_nThinJets, I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets, I_ht600_nThinJets, I_ht800_nThinJets,
        I_ht1200_nThinJets, I_ht2500_nThinJets;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight, I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    float_t I_ht0_met, I_ht70_met, I_ht100_met, I_ht200_met, I_ht400_met, I_ht600_met, I_ht800_met, I_ht1200_met, I_ht2500_met;

    vector<float> *v_ht0_alpha = new vector<float>();
    vector<float> *v_ht0_alpha2 = new vector<float>();
    vector<float> *v_ht0_alpha3 = new vector<float>();
    vector<float> *v_ht0_alpha4 = new vector<float>();
    vector<float> *v_ht70_alpha = new vector<float>();
    vector<float> *v_ht70_alpha2 = new vector<float>();
    vector<float> *v_ht70_alpha3 = new vector<float>();
    vector<float> *v_ht70_alpha4 = new vector<float>();
    vector<float> *v_ht100_alpha = new vector<float>();
    vector<float> *v_ht100_alpha2 = new vector<float>();
    vector<float> *v_ht100_alpha3 = new vector<float>();
    vector<float> *v_ht100_alpha4 = new vector<float>();
    vector<float> *v_ht200_alpha = new vector<float>();
    vector<float> *v_ht200_alpha2 = new vector<float>();
    vector<float> *v_ht200_alpha3 = new vector<float>();
    vector<float> *v_ht200_alpha4 = new vector<float>();
    vector<float> *v_ht400_alpha = new vector<float>();
    vector<float> *v_ht400_alpha2 = new vector<float>();
    vector<float> *v_ht400_alpha3 = new vector<float>();
    vector<float> *v_ht400_alpha4 = new vector<float>();
    vector<float> *v_ht600_alpha = new vector<float>();
    vector<float> *v_ht600_alpha2 = new vector<float>();
    vector<float> *v_ht600_alpha3 = new vector<float>();
    vector<float> *v_ht600_alpha4 = new vector<float>();
    vector<float> *v_ht800_alpha = new vector<float>();
    vector<float> *v_ht800_alpha2 = new vector<float>();
    vector<float> *v_ht800_alpha3 = new vector<float>();
    vector<float> *v_ht800_alpha4 = new vector<float>();
    vector<float> *v_ht1200_alpha = new vector<float>();
    vector<float> *v_ht1200_alpha2 = new vector<float>();
    vector<float> *v_ht1200_alpha3 = new vector<float>();
    vector<float> *v_ht1200_alpha4 = new vector<float>();
    vector<float> *v_ht2500_alpha = new vector<float>();
    vector<float> *v_ht2500_alpha2 = new vector<float>();
    vector<float> *v_ht2500_alpha3 = new vector<float>();
    vector<float> *v_ht2500_alpha4 = new vector<float>();

    v_ht0_alpha->clear();
    v_ht0_alpha2->clear();
    v_ht0_alpha3->clear();
    v_ht0_alpha4->clear();
    v_ht70_alpha->clear();
    v_ht70_alpha2->clear();
    v_ht70_alpha3->clear();
    v_ht70_alpha4->clear();
    v_ht100_alpha->clear();
    v_ht100_alpha2->clear();
    v_ht100_alpha3->clear();
    v_ht100_alpha4->clear();
    v_ht200_alpha->clear();
    v_ht200_alpha2->clear();
    v_ht200_alpha3->clear();
    v_ht200_alpha4->clear();
    v_ht400_alpha->clear();
    v_ht400_alpha2->clear();
    v_ht400_alpha3->clear();
    v_ht400_alpha4->clear();
    v_ht600_alpha->clear();
    v_ht600_alpha2->clear();
    v_ht600_alpha3->clear();
    v_ht600_alpha4->clear();
    v_ht800_alpha->clear();
    v_ht800_alpha2->clear();
    v_ht800_alpha3->clear();
    v_ht800_alpha4->clear();
    v_ht1200_alpha->clear();
    v_ht1200_alpha2->clear();
    v_ht1200_alpha3->clear();
    v_ht1200_alpha4->clear();
    v_ht2500_alpha->clear();
    v_ht2500_alpha2->clear();
    v_ht2500_alpha3->clear();
    v_ht2500_alpha4->clear();

    vector<float> *v_ht0_Chi3Dlog = new vector<float>();
    vector<float> *v_ht70_Chi3Dlog = new vector<float>();
    vector<float> *v_ht100_Chi3Dlog = new vector<float>();
    vector<float> *v_ht200_Chi3Dlog = new vector<float>();
    vector<float> *v_ht400_Chi3Dlog = new vector<float>();
    vector<float> *v_ht600_Chi3Dlog = new vector<float>();
    vector<float> *v_ht800_Chi3Dlog = new vector<float>();
    vector<float> *v_ht1200_Chi3Dlog = new vector<float>();
    vector<float> *v_ht2500_Chi3Dlog = new vector<float>();

    v_ht0_Chi3Dlog->clear();
    v_ht70_Chi3Dlog->clear();
    v_ht100_Chi3Dlog->clear();
    v_ht200_Chi3Dlog->clear();
    v_ht400_Chi3Dlog->clear();
    v_ht600_Chi3Dlog->clear();
    v_ht800_Chi3Dlog->clear();
    v_ht1200_Chi3Dlog->clear();
    v_ht2500_Chi3Dlog->clear();

    vector<float> *v_ht0_2DIP = new vector<float>();
    vector<float> *v_ht70_2DIP = new vector<float>();
    vector<float> *v_ht100_2DIP = new vector<float>();
    vector<float> *v_ht200_2DIP = new vector<float>();
    vector<float> *v_ht400_2DIP = new vector<float>();
    vector<float> *v_ht600_2DIP = new vector<float>();
    vector<float> *v_ht800_2DIP = new vector<float>();
    vector<float> *v_ht1200_2DIP = new vector<float>();
    vector<float> *v_ht2500_2DIP = new vector<float>();

    v_ht0_2DIP->clear();
    v_ht70_2DIP->clear();
    v_ht100_2DIP->clear();
    v_ht200_2DIP->clear();
    v_ht400_2DIP->clear();
    v_ht600_2DIP->clear();
    v_ht800_2DIP->clear();
    v_ht1200_2DIP->clear();
    v_ht2500_2DIP->clear();

    vector<float> *v_ht0_nTrack = new vector<float>();
    vector<float> *v_ht70_nTrack = new vector<float>();
    vector<float> *v_ht100_nTrack = new vector<float>();
    vector<float> *v_ht200_nTrack = new vector<float>();
    vector<float> *v_ht400_nTrack = new vector<float>();
    vector<float> *v_ht600_nTrack = new vector<float>();
    vector<float> *v_ht800_nTrack = new vector<float>();
    vector<float> *v_ht1200_nTrack = new vector<float>();
    vector<float> *v_ht2500_nTrack = new vector<float>();

    v_ht0_nTrack->clear();
    v_ht70_nTrack->clear();
    v_ht100_nTrack->clear();
    v_ht200_nTrack->clear();
    v_ht400_nTrack->clear();
    v_ht600_nTrack->clear();
    v_ht800_nTrack->clear();
    v_ht1200_nTrack->clear();
    v_ht2500_nTrack->clear();

    vector<float> *v_ht0_JetPt = new vector<float>();
    vector<float> *v_ht70_JetPt = new vector<float>();
    vector<float> *v_ht100_JetPt = new vector<float>();
    vector<float> *v_ht200_JetPt = new vector<float>();
    vector<float> *v_ht400_JetPt = new vector<float>();
    vector<float> *v_ht600_JetPt = new vector<float>();
    vector<float> *v_ht800_JetPt = new vector<float>();
    vector<float> *v_ht1200_JetPt = new vector<float>();
    vector<float> *v_ht2500_JetPt = new vector<float>();

    v_ht0_JetPt->clear();
    v_ht70_JetPt->clear();
    v_ht100_JetPt->clear();
    v_ht200_JetPt->clear();
    v_ht400_JetPt->clear();
    v_ht600_JetPt->clear();
    v_ht800_JetPt->clear();
    v_ht1200_JetPt->clear();
    v_ht2500_JetPt->clear();

    vector<float> *v_ht0_JetEta = new vector<float>();
    vector<float> *v_ht70_JetEta = new vector<float>();
    vector<float> *v_ht100_JetEta = new vector<float>();
    vector<float> *v_ht200_JetEta = new vector<float>();
    vector<float> *v_ht400_JetEta = new vector<float>();
    vector<float> *v_ht600_JetEta = new vector<float>();
    vector<float> *v_ht800_JetEta = new vector<float>();
    vector<float> *v_ht1200_JetEta = new vector<float>();
    vector<float> *v_ht2500_JetEta = new vector<float>();

    v_ht0_JetEta->clear();
    v_ht70_JetEta->clear();
    v_ht100_JetEta->clear();
    v_ht200_JetEta->clear();
    v_ht400_JetEta->clear();
    v_ht600_JetEta->clear();
    v_ht800_JetEta->clear();
    v_ht1200_JetEta->clear();
    v_ht2500_JetEta->clear();

    vector<float> *v_ht0_Jethadronflavor = new vector<float>();
    vector<float> *v_ht70_Jethadronflavor = new vector<float>();
    vector<float> *v_ht100_Jethadronflavor = new vector<float>();
    vector<float> *v_ht200_Jethadronflavor = new vector<float>();
    vector<float> *v_ht400_Jethadronflavor = new vector<float>();
    vector<float> *v_ht600_Jethadronflavor = new vector<float>();
    vector<float> *v_ht800_Jethadronflavor = new vector<float>();
    vector<float> *v_ht1200_Jethadronflavor = new vector<float>();
    vector<float> *v_ht2500_Jethadronflavor = new vector<float>();

    v_ht0_Jethadronflavor->clear();
    v_ht70_Jethadronflavor->clear();
    v_ht100_Jethadronflavor->clear();
    v_ht200_Jethadronflavor->clear();
    v_ht400_Jethadronflavor->clear();
    v_ht600_Jethadronflavor->clear();
    v_ht800_Jethadronflavor->clear();
    v_ht1200_Jethadronflavor->clear();
    v_ht2500_Jethadronflavor->clear();

    vector<float> *v_ht0_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht70_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht100_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht200_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht400_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht600_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht800_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht1200_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht2500_Jetpartonflavor = new vector<float>();

    v_ht0_Jetpartonflavor->clear();
    v_ht70_Jetpartonflavor->clear();
    v_ht100_Jetpartonflavor->clear();
    v_ht200_Jetpartonflavor->clear();
    v_ht400_Jetpartonflavor->clear();
    v_ht600_Jetpartonflavor->clear();
    v_ht800_Jetpartonflavor->clear();
    v_ht1200_Jetpartonflavor->clear();
    v_ht2500_Jetpartonflavor->clear();

    TTree *h2;
    DYincli_2->GetObject("h2", h2);
    h2->SetBranchAddress("I_weight", &I_ht0_weight);
    h2->SetBranchAddress("f_HT", &HT);
    h2->SetBranchAddress("f_Met", &I_ht0_met);
    h2->SetBranchAddress("I_nJets", &I_ht0_nThinJets);
    h2->SetBranchAddress("v_N_Tracks", &v_ht0_nTrack);
    h2->SetBranchAddress("v_IP2D", &v_ht0_2DIP);
    h2->SetBranchAddress("v_Chi3Dlog", &v_ht0_Chi3Dlog);
    h2->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    h2->SetBranchAddress("v_fakealpha2", &v_ht0_alpha2);
    h2->SetBranchAddress("v_fakealpha3", &v_ht0_alpha3);
    h2->SetBranchAddress("v_fakealpha4", &v_ht0_alpha4);
    h2->SetBranchAddress("v_fakeJetPt", &v_ht0_JetPt);
    h2->SetBranchAddress("v_fakeJetEta", &v_ht0_JetEta);
    h2->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
    h2->SetBranchAddress("v_fakeJetpartonflavor", &v_ht0_Jetpartonflavor);
    for (int evt = 0; evt < h2->GetEntries(); evt++)
    {
        h2->GetEntry(evt);
        if (HT < 70)
        {
            double HT0_eventWeight = I_ht0_weight * HT0Weight;
            //--------------------------------
            // nTracks, JetPt, JetEta, alpha3D
            //--------------------------------
            if (v_ht0_nTrack->size() != v_ht0_Jethadronflavor->size())
            {
                cout << "bug" << endl;
            }
            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT0_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT0_eventWeight);
                    }
                }
                double Weight = background((*v_ht0_nTrack)[i]) * HT0_eventWeight;
                double bWeight = bjet_background((*v_ht0_nTrack)[i]) * HT0_eventWeight;
                double cWeight = cjet_background((*v_ht0_nTrack)[i]) * HT0_eventWeight;
                double lightWeight = lightjet_background((*v_ht0_nTrack)[i]) * HT0_eventWeight;
                h_DY_nTracks_CR->Fill((*v_ht0_nTrack)[i], Weight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_jeteta_bjet_CR);
                //  For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

                // By bin
                double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT0_eventWeight;
                double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT0_eventWeight;
                double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT0_eventWeight;

                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT0_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT0_eventWeight, h_DY_jetpt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_jeteta_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT0_eventWeight, h_DY_jetpt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_jeteta_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT0_eventWeight, h_DY_jetpt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_jeteta_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT0_eventWeight);
                        }
                    }

                } // alpha cut
            }
        }
        else if (HT >= 70 && HT < 100)
        {
            double HT70_eventWeight = I_ht0_weight * HT70Weight;

            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT70_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {

                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT70_eventWeight);
                    }
                }
                double bWeight = bjet_background((*v_ht0_nTrack)[i]) * HT70_eventWeight;
                double cWeight = cjet_background((*v_ht0_nTrack)[i]) * HT70_eventWeight;
                double lightWeight = lightjet_background((*v_ht0_nTrack)[i]) * HT70_eventWeight;
                double Weight = background((*v_ht0_nTrack)[i]) * HT70_eventWeight;
                h_DY_nTracks_CR->Fill((*v_ht0_nTrack)[i], Weight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_jeteta_bjet_CR);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

                // By bin
                double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT70_eventWeight;
                double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT70_eventWeight;
                double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT70_eventWeight;

                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT70_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT70_eventWeight, h_DY_jetpt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_jeteta_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT70_eventWeight, h_DY_jetpt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_jeteta_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT70_eventWeight, h_DY_jetpt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_jeteta_light_cut);
                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT70_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 100 && HT < 200)
        {
            double HT100_eventWeight = I_ht0_weight * HT100Weight;

            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT100_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {

                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT100_eventWeight);
                    }
                }
                double bWeight = bjet_background((*v_ht0_nTrack)[i]) * HT100_eventWeight;
                double cWeight = cjet_background((*v_ht0_nTrack)[i]) * HT100_eventWeight;
                double lightWeight = lightjet_background((*v_ht0_nTrack)[i]) * HT100_eventWeight;
                double Weight = background((*v_ht0_nTrack)[i]) * HT100_eventWeight;
                h_DY_nTracks_CR->Fill((*v_ht0_nTrack)[i], Weight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_jeteta_bjet_CR);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

                // By bin
                double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT100_eventWeight;
                double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT100_eventWeight;
                double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT100_eventWeight;
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);
                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT100_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT100_eventWeight, h_DY_jetpt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_jeteta_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT100_eventWeight, h_DY_jetpt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_jeteta_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT100_eventWeight, h_DY_jetpt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_jeteta_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT100_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 200 && HT < 400)
        {

            double HT200_eventWeight = I_ht0_weight * HT200Weight;

            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT200_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT200_eventWeight);
                    }
                }
                double bWeight = bjet_background((*v_ht0_nTrack)[i]) * HT200_eventWeight;
                double cWeight = cjet_background((*v_ht0_nTrack)[i]) * HT200_eventWeight;
                double lightWeight = lightjet_background((*v_ht0_nTrack)[i]) * HT200_eventWeight;
                double Weight = background((*v_ht0_nTrack)[i]) * HT200_eventWeight;
                h_DY_nTracks_CR->Fill((*v_ht0_nTrack)[i], Weight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_jeteta_bjet_CR);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

                // By bin
                double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT200_eventWeight;
                double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT200_eventWeight;
                double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT200_eventWeight;
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);
                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT200_eventWeight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT200_eventWeight, h_DY_jetpt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_jeteta_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT200_eventWeight, h_DY_jetpt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_jeteta_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT200_eventWeight, h_DY_jetpt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_jeteta_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT200_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 400 && HT < 600)
        {
            double HT400_eventWeight = I_ht0_weight * HT400Weight;

            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT400_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT400_eventWeight);
                    }
                }
                double bWeight = bjet_background((*v_ht0_nTrack)[i]) * HT400_eventWeight;
                double cWeight = cjet_background((*v_ht0_nTrack)[i]) * HT400_eventWeight;
                double lightWeight = lightjet_background((*v_ht0_nTrack)[i]) * HT400_eventWeight;
                double Weight = background((*v_ht0_nTrack)[i]) * HT400_eventWeight;
                h_DY_nTracks_CR->Fill((*v_ht0_nTrack)[i], Weight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_jeteta_bjet_CR);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

                // By bin
                double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT400_eventWeight;
                double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT400_eventWeight;
                double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT400_eventWeight;
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);
                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT400_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT400_eventWeight, h_DY_jetpt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_jeteta_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT400_eventWeight, h_DY_jetpt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_jeteta_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT400_eventWeight, h_DY_jetpt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_jeteta_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT400_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 600 && HT < 800)
        {
            double HT600_eventWeight = I_ht0_weight * HT600Weight;
            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT600_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT600_eventWeight);
                    }
                }
                double bWeight = bjet_background((*v_ht0_nTrack)[i]) * HT600_eventWeight;
                double cWeight = cjet_background((*v_ht0_nTrack)[i]) * HT600_eventWeight;
                double lightWeight = lightjet_background((*v_ht0_nTrack)[i]) * HT600_eventWeight;
                double Weight = background((*v_ht0_nTrack)[i]) * HT600_eventWeight;
                h_DY_nTracks_CR->Fill((*v_ht0_nTrack)[i], Weight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_jeteta_bjet_CR);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

                // By bin
                double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT600_eventWeight;
                double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT600_eventWeight;
                double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT600_eventWeight;
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT600_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT600_eventWeight, h_DY_jetpt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_jeteta_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT600_eventWeight, h_DY_jetpt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_jeteta_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT600_eventWeight, h_DY_jetpt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_jeteta_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT600_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 800 && HT < 1200)
        {
            double HT800_eventWeight = I_ht0_weight * HT800Weight;

            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT800_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_bjet);
                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_cjet);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_heavy);
                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT800_eventWeight);
                    }
                }
                double bWeight = bjet_background((*v_ht0_nTrack)[i]) * HT800_eventWeight;
                double cWeight = cjet_background((*v_ht0_nTrack)[i]) * HT800_eventWeight;
                double lightWeight = lightjet_background((*v_ht0_nTrack)[i]) * HT800_eventWeight;
                double Weight = background((*v_ht0_nTrack)[i]) * HT800_eventWeight;
                h_DY_nTracks_CR->Fill((*v_ht0_nTrack)[i], Weight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], bWeight, h_DY_jeteta_bjet_CR);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

                // By bin
                double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT800_eventWeight;
                double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT800_eventWeight;
                double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT800_eventWeight;
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT800_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT800_eventWeight, h_DY_jetpt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT800_eventWeight, h_DY_jeteta_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT800_eventWeight, h_DY_jetpt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT800_eventWeight, h_DY_jeteta_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT800_eventWeight, h_DY_jetpt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT800_eventWeight, h_DY_jeteta_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT800_eventWeight);
                        }
                    }

                } // alpha cut
            }
        }
        else if (HT >= 1200 && HT < 2500)
        {
            double HT1200_eventWeight = I_ht0_weight * HT1200Weight;

            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT1200_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_bjet);
                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_cjet);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_heavy);
                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT1200_eventWeight);
                    }
                }
                double bWeight = bjet_background((*v_ht0_nTrack)[i]) * HT1200_eventWeight;
                double cWeight = cjet_background((*v_ht0_nTrack)[i]) * HT1200_eventWeight;
                double lightWeight = lightjet_background((*v_ht0_nTrack)[i]) * HT1200_eventWeight;
                double Weight = background((*v_ht0_nTrack)[i]) * HT1200_eventWeight;
                h_DY_nTracks_CR->Fill((*v_ht0_nTrack)[i], Weight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_jeteta_bjet_CR);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

                // By bin
                double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT1200_eventWeight;
                double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT1200_eventWeight;
                double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT1200_eventWeight;
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT1200_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT1200_eventWeight, h_DY_jetpt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_jeteta_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT1200_eventWeight, h_DY_jetpt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_jeteta_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT1200_eventWeight, h_DY_jetpt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_jeteta_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT1200_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 2500)
        {
            double HT2500_eventWeight = I_ht0_weight * HT2500Weight;

            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT2500_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT2500_eventWeight);
                    }
                }
                double bWeight = bjet_background((*v_ht0_nTrack)[i]) * HT2500_eventWeight;
                double cWeight = cjet_background((*v_ht0_nTrack)[i]) * HT2500_eventWeight;
                double lightWeight = lightjet_background((*v_ht0_nTrack)[i]) * HT2500_eventWeight;
                double Weight = background((*v_ht0_nTrack)[i]) * HT2500_eventWeight;
                h_DY_nTracks_CR->Fill((*v_ht0_nTrack)[i], Weight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_jeteta_bjet_CR);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

                // By bin
                double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT2500_eventWeight;
                double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT2500_eventWeight;
                double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht0_nTrack)[i] + 1) * HT2500_eventWeight;
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT2500_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT2500_eventWeight, h_DY_jetpt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_jeteta_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT2500_eventWeight, h_DY_jetpt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_jeteta_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT2500_eventWeight, h_DY_jetpt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_jeteta_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT2500_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
    } // End of DY_inclusive
    TTree *T_tree2;
    DYHT100_2->GetObject("h2", T_tree2);
    T_tree2->SetBranchAddress("I_weight", &I_ht100_weight);
    T_tree2->SetBranchAddress("I_nJets", &I_ht100_nThinJets);
    T_tree2->SetBranchAddress("v_N_Tracks", &v_ht100_nTrack);
    T_tree2->SetBranchAddress("f_Met", &I_ht100_met);
    T_tree2->SetBranchAddress("v_IP2D", &v_ht100_2DIP);
    T_tree2->SetBranchAddress("v_Chi3Dlog", &v_ht100_Chi3Dlog);
    T_tree2->SetBranchAddress("v_fakealpha", &v_ht100_alpha);
    T_tree2->SetBranchAddress("v_fakealpha2", &v_ht100_alpha2);
    T_tree2->SetBranchAddress("v_fakealpha3", &v_ht100_alpha3);
    T_tree2->SetBranchAddress("v_fakealpha4", &v_ht100_alpha4);
    T_tree2->SetBranchAddress("v_fakeJetPt", &v_ht100_JetPt);
    T_tree2->SetBranchAddress("v_fakeJetEta", &v_ht100_JetEta);
    T_tree2->SetBranchAddress("v_fakeJethadronflavor", &v_ht100_Jethadronflavor);
    T_tree2->SetBranchAddress("v_fakeJetpartonflavor", &v_ht100_Jetpartonflavor);
    for (int evt = 0; evt < T_tree2->GetEntries(); evt++)
    {
        T_tree2->GetEntry(evt);
        double HT100_eventWeight = I_ht100_weight * HT100Weight;

        for (size_t i = 0; i < v_ht100_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht100_nTrack)[i], HT100_eventWeight);
            // For b jet
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_light);

            if ((*v_ht100_Jethadronflavor)[i] == 4 || (*v_ht100_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht100_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht100_nTrack)[i], HT100_eventWeight);
                }
            }
            double bWeight = bjet_background((*v_ht100_nTrack)[i]) * HT100_eventWeight;
            double cWeight = cjet_background((*v_ht100_nTrack)[i]) * HT100_eventWeight;
            double lightWeight = lightjet_background((*v_ht100_nTrack)[i]) * HT100_eventWeight;
            double Weight = background((*v_ht100_nTrack)[i]) * HT100_eventWeight;
            h_DY_nTracks_CR->Fill((*v_ht100_nTrack)[i], Weight);
            // For b jet
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_jeteta_bjet_CR);
            // For c jet
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);
            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

            // By bin
            double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht100_nTrack)[i] + 1) * HT100_eventWeight;
            double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht100_nTrack)[i] + 1) * HT100_eventWeight;
            double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht100_nTrack)[i] + 1) * HT100_eventWeight;
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

            if ((*v_ht100_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht100_nTrack)[i], HT100_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_jeteta_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_jeteta_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_jeteta_light_cut);
                if ((*v_ht100_Jethadronflavor)[i] == 4 || (*v_ht100_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht100_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht100_nTrack)[i], HT100_eventWeight);
                    }
                }

            } // alpha cut
        }
    }
    TTree *T_tree3;
    DYHT200_2->GetObject("h2", T_tree3);
    T_tree3->SetBranchAddress("I_weight", &I_ht200_weight);
    T_tree3->SetBranchAddress("I_nJets", &I_ht200_nThinJets);
    T_tree3->SetBranchAddress("v_N_Tracks", &v_ht200_nTrack);
    T_tree3->SetBranchAddress("f_Met", &I_ht200_met);
    T_tree3->SetBranchAddress("v_IP2D", &v_ht200_2DIP);
    T_tree3->SetBranchAddress("v_Chi3Dlog", &v_ht200_Chi3Dlog);
    T_tree3->SetBranchAddress("v_fakealpha", &v_ht200_alpha);
    T_tree3->SetBranchAddress("v_fakealpha2", &v_ht200_alpha2);
    T_tree3->SetBranchAddress("v_fakealpha3", &v_ht200_alpha3);
    T_tree3->SetBranchAddress("v_fakealpha4", &v_ht200_alpha4);
    T_tree3->SetBranchAddress("v_fakeJetPt", &v_ht200_JetPt);
    T_tree3->SetBranchAddress("v_fakeJetEta", &v_ht200_JetEta);
    T_tree3->SetBranchAddress("v_fakeJethadronflavor", &v_ht200_Jethadronflavor);
    T_tree3->SetBranchAddress("v_fakeJetpartonflavor", &v_ht200_Jetpartonflavor);
    for (int evt = 0; evt < T_tree3->GetEntries(); evt++)
    {
        T_tree3->GetEntry(evt);
        double HT200_eventWeight = I_ht200_weight * HT200Weight;

        for (size_t i = 0; i < v_ht200_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht200_nTrack)[i], HT200_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_light);

            if ((*v_ht200_Jethadronflavor)[i] == 4 || (*v_ht200_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht200_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht200_nTrack)[i], HT200_eventWeight);
                }
            }
            double bWeight = bjet_background((*v_ht200_nTrack)[i]) * HT200_eventWeight;
            double cWeight = cjet_background((*v_ht200_nTrack)[i]) * HT200_eventWeight;
            double lightWeight = lightjet_background((*v_ht200_nTrack)[i]) * HT200_eventWeight;
            double Weight = background((*v_ht200_nTrack)[i]) * HT200_eventWeight;
            h_DY_nTracks_CR->Fill((*v_ht200_nTrack)[i], Weight);
            // For b jet
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_jeteta_bjet_CR);
            // For c jet
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);
            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

            // By bin
            double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht200_nTrack)[i] + 1) * HT200_eventWeight;
            double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht200_nTrack)[i] + 1) * HT200_eventWeight;
            double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht200_nTrack)[i] + 1) * HT200_eventWeight;
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

            if ((*v_ht200_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht200_nTrack)[i], HT200_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_jeteta_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_jeteta_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_jeteta_light_cut);
                if ((*v_ht200_Jethadronflavor)[i] == 4 || (*v_ht200_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht200_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht200_nTrack)[i], HT200_eventWeight);
                    }
                }
            } // alpha cut
        }
    }
    TTree *T_tree4;
    DYHT400_2->GetObject("h2", T_tree4);
    T_tree4->SetBranchAddress("I_weight", &I_ht400_weight);
    T_tree4->SetBranchAddress("I_nJets", &I_ht400_nThinJets);
    T_tree4->SetBranchAddress("v_N_Tracks", &v_ht400_nTrack);
    T_tree4->SetBranchAddress("f_Met", &I_ht400_met);
    T_tree4->SetBranchAddress("v_IP2D", &v_ht400_2DIP);
    T_tree4->SetBranchAddress("v_Chi3Dlog", &v_ht400_Chi3Dlog);
    T_tree4->SetBranchAddress("v_fakealpha", &v_ht400_alpha);
    T_tree4->SetBranchAddress("v_fakealpha2", &v_ht400_alpha2);
    T_tree4->SetBranchAddress("v_fakealpha3", &v_ht400_alpha3);
    T_tree4->SetBranchAddress("v_fakealpha4", &v_ht400_alpha4);
    T_tree4->SetBranchAddress("v_fakeJetPt", &v_ht400_JetPt);
    T_tree4->SetBranchAddress("v_fakeJetEta", &v_ht400_JetEta);
    T_tree4->SetBranchAddress("v_fakeJethadronflavor", &v_ht400_Jethadronflavor);
    T_tree4->SetBranchAddress("v_fakeJetpartonflavor", &v_ht400_Jetpartonflavor);
    for (int evt = 0; evt < T_tree4->GetEntries(); evt++)
    {
        T_tree4->GetEntry(evt);
        double HT400_eventWeight = I_ht400_weight * HT400Weight;

        for (size_t i = 0; i < v_ht400_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht400_nTrack)[i], HT400_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_light);

            if ((*v_ht400_Jethadronflavor)[i] == 4 || (*v_ht400_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht400_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht400_nTrack)[i], HT400_eventWeight);
                }
            }
            double bWeight = bjet_background((*v_ht400_nTrack)[i]) * HT400_eventWeight;
            double cWeight = cjet_background((*v_ht400_nTrack)[i]) * HT400_eventWeight;
            double lightWeight = lightjet_background((*v_ht400_nTrack)[i]) * HT400_eventWeight;
            double Weight = background((*v_ht400_nTrack)[i]) * HT400_eventWeight;
            h_DY_nTracks_CR->Fill((*v_ht400_nTrack)[i], Weight);
            // For b jet
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_jeteta_bjet_CR);
            // For c jet
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);
            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

            // By bin
            double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht400_nTrack)[i] + 1) * HT400_eventWeight;
            double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht400_nTrack)[i] + 1) * HT400_eventWeight;
            double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht400_nTrack)[i] + 1) * HT400_eventWeight;
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

            if ((*v_ht400_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht400_nTrack)[i], HT400_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_jeteta_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_jeteta_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_jeteta_light_cut);
                if ((*v_ht400_Jethadronflavor)[i] == 4 || (*v_ht400_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht400_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht400_nTrack)[i], HT400_eventWeight);
                    }
                }
            } // alpha cut
        }
    }
    TTree *T_tree5;
    DYHT600_2->GetObject("h2", T_tree5);
    T_tree5->SetBranchAddress("I_weight", &I_ht600_weight);
    T_tree5->SetBranchAddress("I_nJets", &I_ht600_nThinJets);
    T_tree5->SetBranchAddress("v_N_Tracks", &v_ht600_nTrack);
    T_tree5->SetBranchAddress("f_Met", &I_ht600_met);
    T_tree5->SetBranchAddress("v_IP2D", &v_ht600_2DIP);
    T_tree5->SetBranchAddress("v_Chi3Dlog", &v_ht600_Chi3Dlog);
    T_tree5->SetBranchAddress("v_fakealpha", &v_ht600_alpha);
    T_tree5->SetBranchAddress("v_fakealpha2", &v_ht600_alpha2);
    T_tree5->SetBranchAddress("v_fakealpha3", &v_ht600_alpha3);
    T_tree5->SetBranchAddress("v_fakealpha4", &v_ht600_alpha4);
    T_tree5->SetBranchAddress("v_fakeJetPt", &v_ht600_JetPt);
    T_tree5->SetBranchAddress("v_fakeJetEta", &v_ht600_JetEta);
    T_tree5->SetBranchAddress("v_fakeJethadronflavor", &v_ht600_Jethadronflavor);
    T_tree5->SetBranchAddress("v_fakeJetpartonflavor", &v_ht600_Jetpartonflavor);
    for (int evt = 0; evt < T_tree5->GetEntries(); evt++)
    {
        T_tree5->GetEntry(evt);

        double HT600_eventWeight = I_ht600_weight * HT600Weight;

        for (size_t i = 0; i < v_ht600_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht600_nTrack)[i], HT600_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_light);

            if ((*v_ht600_Jethadronflavor)[i] == 4 || (*v_ht600_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht600_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht600_nTrack)[i], HT600_eventWeight);
                }
            }
            double bWeight = bjet_background((*v_ht600_nTrack)[i]) * HT600_eventWeight;
            double cWeight = cjet_background((*v_ht600_nTrack)[i]) * HT600_eventWeight;
            double lightWeight = lightjet_background((*v_ht600_nTrack)[i]) * HT600_eventWeight;
            double Weight = background((*v_ht600_nTrack)[i]) * HT600_eventWeight;
            h_DY_nTracks_CR->Fill((*v_ht600_nTrack)[i], Weight);
            // For b jet
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_jeteta_bjet_CR);
            // For c jet
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);
            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

            // By bin
            double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht600_nTrack)[i] + 1) * HT600_eventWeight;
            double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht600_nTrack)[i] + 1) * HT600_eventWeight;
            double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht600_nTrack)[i] + 1) * HT600_eventWeight;
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

            if ((*v_ht600_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht600_nTrack)[i], HT600_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_jeteta_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_jeteta_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_jeteta_light_cut);
                if ((*v_ht600_Jethadronflavor)[i] == 4 || (*v_ht600_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht600_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht600_nTrack)[i], HT600_eventWeight);
                    }
                }
            } // alpha cut
        }
    }
    TTree *T_tree6;
    DYHT800_2->GetObject("h2", T_tree6);
    T_tree6->SetBranchAddress("I_weight", &I_ht800_weight);
    T_tree6->SetBranchAddress("I_nJets", &I_ht800_nThinJets);
    T_tree6->SetBranchAddress("v_N_Tracks", &v_ht800_nTrack);
    T_tree6->SetBranchAddress("f_Met", &I_ht800_met);
    T_tree6->SetBranchAddress("v_IP2D", &v_ht800_2DIP);
    T_tree6->SetBranchAddress("v_Chi3Dlog", &v_ht800_Chi3Dlog);
    T_tree6->SetBranchAddress("v_fakealpha", &v_ht800_alpha);
    T_tree6->SetBranchAddress("v_fakealpha2", &v_ht800_alpha2);
    T_tree6->SetBranchAddress("v_fakealpha3", &v_ht800_alpha3);
    T_tree6->SetBranchAddress("v_fakealpha4", &v_ht800_alpha4);
    T_tree6->SetBranchAddress("v_fakeJetPt", &v_ht800_JetPt);
    T_tree6->SetBranchAddress("v_fakeJetEta", &v_ht800_JetEta);
    T_tree6->SetBranchAddress("v_fakeJethadronflavor", &v_ht800_Jethadronflavor);
    T_tree6->SetBranchAddress("v_fakeJetpartonflavor", &v_ht800_Jetpartonflavor);
    for (int evt = 0; evt < T_tree6->GetEntries(); evt++)
    {
        T_tree6->GetEntry(evt);

        double HT800_eventWeight = I_ht800_weight * HT800Weight;

        for (size_t i = 0; i < v_ht800_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht800_nTrack)[i], HT800_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_light);

            if ((*v_ht800_Jethadronflavor)[i] == 4 || (*v_ht800_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht800_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht800_nTrack)[i], HT800_eventWeight);
                }
            }
            double bWeight = bjet_background((*v_ht800_nTrack)[i]) * HT800_eventWeight;
            double cWeight = cjet_background((*v_ht800_nTrack)[i]) * HT800_eventWeight;
            double lightWeight = lightjet_background((*v_ht800_nTrack)[i]) * HT800_eventWeight;
            double Weight = background((*v_ht800_nTrack)[i]) * HT800_eventWeight;
            h_DY_nTracks_CR->Fill((*v_ht800_nTrack)[i], Weight);
            // For b jet
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_jeteta_bjet_CR);
            // For c jet
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);
            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

            // By bin
            double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht800_nTrack)[i] + 1) * HT800_eventWeight;
            double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht800_nTrack)[i] + 1) * HT800_eventWeight;
            double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht800_nTrack)[i] + 1) * HT800_eventWeight;
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

            if ((*v_ht800_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht800_nTrack)[i], HT800_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_jeteta_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_jeteta_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_jeteta_light_cut);
                if ((*v_ht800_Jethadronflavor)[i] == 4 || (*v_ht800_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht800_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht800_nTrack)[i], HT800_eventWeight);
                    }
                }
            } // alpha cut
        }
    }
    TTree *T_tree7;
    DYHT1200_2->GetObject("h2", T_tree7);
    T_tree7->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_tree7->SetBranchAddress("I_nJets", &I_ht1200_nThinJets);
    T_tree7->SetBranchAddress("v_N_Tracks", &v_ht1200_nTrack);
    T_tree7->SetBranchAddress("f_Met", &I_ht1200_met);
    T_tree7->SetBranchAddress("v_IP2D", &v_ht1200_2DIP);
    T_tree7->SetBranchAddress("v_Chi3Dlog", &v_ht1200_Chi3Dlog);
    T_tree7->SetBranchAddress("v_fakealpha", &v_ht1200_alpha);
    T_tree7->SetBranchAddress("v_fakealpha2", &v_ht1200_alpha2);
    T_tree7->SetBranchAddress("v_fakealpha3", &v_ht1200_alpha3);
    T_tree7->SetBranchAddress("v_fakealpha4", &v_ht1200_alpha4);
    T_tree7->SetBranchAddress("v_fakeJetPt", &v_ht1200_JetPt);
    T_tree7->SetBranchAddress("v_fakeJetEta", &v_ht1200_JetEta);
    T_tree7->SetBranchAddress("v_fakeJethadronflavor", &v_ht1200_Jethadronflavor);
    T_tree7->SetBranchAddress("v_fakeJetpartonflavor", &v_ht1200_Jetpartonflavor);
    for (int evt = 0; evt < T_tree7->GetEntries(); evt++)
    {
        T_tree7->GetEntry(evt);

        double HT1200_eventWeight = I_ht1200_weight * HT1200Weight;

        for (size_t i = 0; i < v_ht1200_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht1200_nTrack)[i], HT1200_eventWeight);
            // For b jet
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_light);

            if ((*v_ht1200_Jethadronflavor)[i] == 4 || (*v_ht1200_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht1200_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht1200_nTrack)[i], HT1200_eventWeight);
                }
            }
            double bWeight = bjet_background((*v_ht1200_nTrack)[i]) * HT1200_eventWeight;
            double cWeight = cjet_background((*v_ht1200_nTrack)[i]) * HT1200_eventWeight;
            double lightWeight = lightjet_background((*v_ht1200_nTrack)[i]) * HT1200_eventWeight;
            double Weight = background((*v_ht1200_nTrack)[i]) * HT1200_eventWeight;
            // cout << "Weight: " << Weight << endl;
            h_DY_nTracks_CR->Fill((*v_ht1200_nTrack)[i], Weight);
            // For b jet
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_jeteta_bjet_CR);
            // For c jet
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);
            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

            // By bin
            double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht1200_nTrack)[i] + 1) * HT1200_eventWeight;
            double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht1200_nTrack)[i] + 1) * HT1200_eventWeight;
            double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht1200_nTrack)[i] + 1) * HT1200_eventWeight;
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

            if ((*v_ht1200_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht1200_nTrack)[i], HT1200_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_jeteta_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_jeteta_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_jeteta_light_cut);
                if ((*v_ht1200_Jethadronflavor)[i] == 4 || (*v_ht1200_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht1200_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht1200_nTrack)[i], HT1200_eventWeight);
                    }
                }
            } // alpha cut
        }
    }

    TTree *T_tree8;
    DYHT2500_2->GetObject("h2", T_tree8);
    T_tree8->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_tree8->SetBranchAddress("I_nJets", &I_ht2500_nThinJets);
    T_tree8->SetBranchAddress("v_N_Tracks", &v_ht2500_nTrack);
    T_tree8->SetBranchAddress("f_Met", &I_ht2500_met);
    T_tree8->SetBranchAddress("v_IP2D", &v_ht2500_2DIP);
    T_tree8->SetBranchAddress("v_Chi3Dlog", &v_ht2500_Chi3Dlog);
    T_tree8->SetBranchAddress("v_fakealpha", &v_ht2500_alpha);
    T_tree8->SetBranchAddress("v_fakealpha2", &v_ht2500_alpha2);
    T_tree8->SetBranchAddress("v_fakealpha3", &v_ht2500_alpha3);
    T_tree8->SetBranchAddress("v_fakealpha4", &v_ht2500_alpha4);
    T_tree8->SetBranchAddress("v_fakeJetPt", &v_ht2500_JetPt);
    T_tree8->SetBranchAddress("v_fakeJetEta", &v_ht2500_JetEta);
    T_tree8->SetBranchAddress("v_fakeJethadronflavor", &v_ht2500_Jethadronflavor);
    T_tree8->SetBranchAddress("v_fakeJetpartonflavor", &v_ht2500_Jetpartonflavor);
    for (int evt = 0; evt < T_tree8->GetEntries(); evt++)
    {
        T_tree8->GetEntry(evt);

        double HT2500_eventWeight = I_ht2500_weight * HT2500Weight;

        for (size_t i = 0; i < v_ht2500_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht2500_nTrack)[i], HT2500_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_light);

            if ((*v_ht2500_Jethadronflavor)[i] == 4 || (*v_ht2500_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht2500_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht2500_nTrack)[i], HT2500_eventWeight);
                }
            }
            double bWeight = bjet_background((*v_ht2500_nTrack)[i]) * HT2500_eventWeight;
            double cWeight = cjet_background((*v_ht2500_nTrack)[i]) * HT2500_eventWeight;
            double lightWeight = lightjet_background((*v_ht2500_nTrack)[i]) * HT2500_eventWeight;
            double Weight = background((*v_ht2500_nTrack)[i]) * HT2500_eventWeight;
            h_DY_nTracks_CR->Fill((*v_ht2500_nTrack)[i], Weight);
            // For b jet
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], bWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], bWeight, h_DY_jetpt_bjet_CR);
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_jeteta_bjet_CR);
            // For c jet
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], cWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], cWeight, h_DY_jetpt_cjet_CR);
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], cWeight, h_DY_jeteta_cjet_CR);
            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], Weight, h_DY_nTracks_heavy_CR);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], lightWeight, h_DY_nTracks_light_CR);
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], lightWeight, h_DY_jetpt_light_CR);
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], lightWeight, h_DY_jeteta_light_CR);

            // By bin
            double bWeightbybin = h_DY_bfake_rate->GetBinContent((*v_ht2500_nTrack)[i] + 1) * HT2500_eventWeight;
            double cWeightbybin = h_DY_cfake_rate->GetBinContent((*v_ht2500_nTrack)[i] + 1) * HT2500_eventWeight;
            double lightWeightbybin = h_DY_lightfake_rate->GetBinContent((*v_ht2500_nTrack)[i] + 1) * HT2500_eventWeight;
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], bWeightbybin, h_DY_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], cWeightbybin, h_DY_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], lightWeightbybin, h_DY_nTracks_light_bybin_CR);

            if ((*v_ht2500_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht2500_nTrack)[i], HT2500_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_jeteta_bjet_cut);
                // For c jet

                for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_jeteta_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_jeteta_light_cut);
                if ((*v_ht2500_Jethadronflavor)[i] == 4 || (*v_ht2500_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht2500_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht2500_nTrack)[i], HT2500_eventWeight);
                    }
                }
            } // alpha cut
        }
    }
    h_DY_nTracks_light_cut->SetLineWidth(2);
    h_DY_nTracks_light_CR->SetLineWidth(2);
    h_DY_nTracks_light_cut->SetTitle("light jet (DY)");
    h_DY_nTracks_light_cut->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_light_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    h_DY_nTracks_light_cut->GetXaxis()->SetTitleOffset(1.5);

    h_DY_nTracks_light_CR->SetTitle("light jet (DY)");
    h_DY_nTracks_light_CR->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_light_CR->GetXaxis()->SetTitle("Jet track multiplicity");
    h_DY_nTracks_light_CR->GetXaxis()->SetTitleOffset(1.5);

    h_DY_nTracks_bjet_cut->SetLineWidth(2);
    h_DY_nTracks_bjet_CR->SetLineWidth(2);
    h_DY_nTracks_bjet_cut->SetTitle("bjet jet (DY)");
    h_DY_nTracks_bjet_cut->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_bjet_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    h_DY_nTracks_bjet_cut->GetXaxis()->SetTitleOffset(1.5);

    h_DY_nTracks_bjet_CR->SetTitle("bjet jet (DY)");
    h_DY_nTracks_bjet_CR->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_bjet_CR->GetXaxis()->SetTitle("Jet track multiplicity");
    h_DY_nTracks_bjet_CR->GetXaxis()->SetTitleOffset(1.5);

    h_DY_nTracks_cjet_cut->SetLineWidth(2);
    h_DY_nTracks_cjet_CR->SetLineWidth(2);
    h_DY_nTracks_cjet_cut->SetTitle("cjet jet (DY)");
    h_DY_nTracks_cjet_cut->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_cjet_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    h_DY_nTracks_cjet_cut->GetXaxis()->SetTitleOffset(1.5);

    h_DY_nTracks_cjet_CR->SetTitle("cjet jet (DY)");
    h_DY_nTracks_cjet_CR->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_cjet_CR->GetXaxis()->SetTitle("Jet track multiplicity");
    h_DY_nTracks_cjet_CR->GetXaxis()->SetTitleOffset(1.5);

    h_DY_jetpt_light_cut->SetLineWidth(2);
    h_DY_jetpt_light_CR->SetLineWidth(2);
    h_DY_jetpt_light_cut->SetTitle("light jet (DY)");
    h_DY_jetpt_light_cut->GetYaxis()->SetTitle("nJet");
    h_DY_jetpt_light_cut->GetXaxis()->SetTitle("Jet pt");
    h_DY_jetpt_light_cut->GetXaxis()->SetTitleOffset(1.5);

    h_DY_jetpt_bjet_cut->SetLineWidth(2);
    h_DY_jetpt_bjet_CR->SetLineWidth(2);
    h_DY_jetpt_bjet_cut->SetTitle("b jet (DY)");
    h_DY_jetpt_bjet_cut->GetYaxis()->SetTitle("nJet");
    h_DY_jetpt_bjet_cut->GetXaxis()->SetTitle("Jet pt");
    h_DY_jetpt_bjet_cut->GetXaxis()->SetTitleOffset(1.5);

    h_DY_jetpt_cjet_cut->SetLineWidth(2);
    h_DY_jetpt_cjet_CR->SetLineWidth(2);
    h_DY_jetpt_cjet_cut->SetTitle("c jet (DY)");
    h_DY_jetpt_cjet_cut->GetYaxis()->SetTitle("nJet");
    h_DY_jetpt_cjet_cut->GetXaxis()->SetTitle("Jet pt");
    h_DY_jetpt_cjet_cut->GetXaxis()->SetTitleOffset(1.5);

    h_DY_jeteta_light_cut->SetLineWidth(2);
    h_DY_jeteta_light_CR->SetLineWidth(2);
    h_DY_jeteta_light_cut->SetTitle("light jet (DY)");
    h_DY_jetpt_light_CR->SetTitle("light jet (DY)");
    h_DY_jetpt_light_cut->SetTitle("light jet (DY)");
    h_DY_jeteta_light_cut->GetYaxis()->SetTitle("nJet");
    h_DY_jetpt_light_CR->GetYaxis()->SetTitle("nJet");
    h_DY_jetpt_light_cut->GetYaxis()->SetTitle("nJet");
    h_DY_jeteta_light_cut->GetXaxis()->SetTitle("Jet #eta");
    h_DY_jeteta_light_cut->GetXaxis()->SetTitleOffset(1.5);

    h_DY_jeteta_bjet_cut->SetLineWidth(2);
    h_DY_jeteta_bjet_CR->SetLineWidth(2);
    h_DY_jeteta_bjet_cut->SetTitle("b jet (DY)");
    h_DY_jetpt_bjet_CR->SetTitle("b jet (DY)");
    h_DY_jetpt_bjet_CR->GetYaxis()->SetTitle("nJet");
    h_DY_jeteta_bjet_cut->GetYaxis()->SetTitle("nJet");
    h_DY_jeteta_bjet_cut->GetXaxis()->SetTitle("Jet #eta");
    h_DY_jeteta_bjet_cut->GetXaxis()->SetTitleOffset(1.5);

    h_DY_jeteta_cjet_cut->SetLineWidth(2);
    h_DY_jeteta_cjet_CR->SetLineWidth(2);
    h_DY_jeteta_cjet_cut->SetTitle("c jet (DY)");
    h_DY_jetpt_cjet_CR->SetTitle("c jet (DY)");
    h_DY_jeteta_cjet_cut->GetYaxis()->SetTitle("nJet");
    h_DY_jetpt_cjet_CR->GetYaxis()->SetTitle("nJet");
    h_DY_jeteta_cjet_cut->GetXaxis()->SetTitle("Jet #eta");
    h_DY_jeteta_cjet_cut->GetXaxis()->SetTitleOffset(1.5);

    //auto c1 = new TCanvas("c1", "", 700, 1000);
    //c1->Divide(1, 2, 0.01, 0);
    //c1->Divide(2, 1);
    //c1->cd(1);
    h_DY_jeteta_bjet_CR->DrawNormalized("hist e ");
    //gPad->SetTopMargin(0 - 0.3);
    //gPad->SetBottomMargin(0.02);
    //gPad->SetRightMargin(0.04);

    h_DY_nTracks_cjet_CR->SetLabelSize(0);
    h_DY_nTracks_bjet_CR->SetLabelSize(0);
    h_DY_jetpt_bjet_CR->SetLabelSize(0);
    h_DY_jetpt_bjet_cut->SetLabelSize(0);
    h_DY_jetpt_cjet_CR->SetLabelSize(0);
    h_DY_jetpt_cjet_cut->SetLabelSize(0);
    h_DY_jetpt_light_CR->SetLabelSize(0);
    h_DY_jetpt_light_cut->SetLabelSize(0);
    h_DY_nTracks_cjet_CR->SetLineColor(kRed);
    h_DY_nTracks_bjet_CR->SetLineColor(kRed);
    h_DY_jetpt_bjet_CR->SetLineColor(kRed);
    h_DY_jetpt_cjet_CR->SetLineColor(kRed);
    h_DY_jetpt_light_CR->SetLineColor(kRed);
    h_DY_nTracks_light_CR->SetLineColor(kRed);
    h_DY_nTracks_bjet_bybin_CR->SetLineColor(kGreen + 3);
    h_DY_nTracks_cjet_bybin_CR->SetLineColor(kGreen + 3);
    h_DY_nTracks_light_bybin_CR->SetLineColor(kGreen + 3);
    h_DY_nTracks_light_bybin_CR->SetLineColor(kGreen + 3);

    TH1D *Ratioresult = new TH1D("Ratioresult", "", 50, 0, 50);
    Ratioresult->Sumw2();
    int nBins = h_DY_nTracks_light_CR->GetNbinsX();
    for (int i = 1; i <= nBins; i++)
    {
        double fit_content = h_DY_nTracks_cjet_CR->GetBinContent(i);
        double MC_content = h_DY_nTracks_cjet_cut->GetBinContent(i);
        double ratio_FM = (fit_content) / (MC_content);
        double Error = sqrt(pow(sqrt(fit_content) / fit_content, 2) + pow(sqrt(MC_content) / MC_content, 2));
        if (isnan(abs(Error)) || fit_content == 0)
        {
            ratio_FM = 0;
            Error = 0;
        }
        //cout << "Error = " << Error << endl;
        // cout << " i = " << i << " fit_content = " << fit_content << "MC_content = " << MC_content << " ratio_FM =  " << ratio_FM << endl;
        Ratioresult->SetBinContent(i, ratio_FM);
        Ratioresult->SetBinError(i, Error);
    }

    // h_DY_nTracks_cjet_CR->Draw("hist e ");
    //h_DY_nTracks_bjet_CR->Draw("hist e ");
    //h_DY_nTracks_bjet_cut->Draw("hist e same");
    // Ratioresult->GetXaxis()->SetRangeUser(0, 250);
    /*
    h_DY_nTracks_cjet_cut->GetXaxis()->SetRangeUser(0, 50);
    h_DY_nTracks_cjet_CR->GetXaxis()->SetRangeUser(0, 50);
    h_DY_nTracks_cjet_CR->Draw("hist e ");
    h_DY_nTracks_cjet_cut->Draw("hist e same");
    */
   
    /*
    TLegend *l0 = new TLegend(0.35, 0.4, 0.90, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(h_DY_jetpt_bjet_cut, "Drell-Yan SR", "l");
    l0->AddEntry(h_DY_jetpt_bjet_CR, "Drell-Yan apply fit result", "l");
    l0->Draw();

    c1->cd(2);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();
    Ratioresult->SetLineWidth(2);
    Ratioresult->GetYaxis()->SetTitle("Fit / MC");
    Ratioresult->GetXaxis()->SetTitle("Jet track multiplicity");

    Ratioresult->SetLineColor(kBlue);
    Ratioresult->Draw("E1");
    gStyle->SetOptStat(0);
    */
    /*
    h_DY_nTracks_bjet_CR->GetXaxis()->SetRangeUser(0, 30);
    h_DY_nTracks_bjet_CR->Draw("hist e ");

    h_DY_nTracks_bjet_cut->Draw("hist e same");
    h_DY_nTracks_bjet_bybin_CR->Draw("hist e same");
    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_DY_nTracks_bjet_cut, "Drell-Yan SR", "l");
    // l1->AddEntry(h_DY_nTracks_bjet_CR, "Drell-Yan apply root fit result", "l");
    l1->AddEntry(h_DY_nTracks_bjet_bybin_CR, "Drell-Yan bin by bin check", "l");
    l1->Draw();
    */
    /*
    c1->cd(2);

    // h_DY_nTracks_cjet_CR->Draw("hist e ");
    h_DY_nTracks_cjet_cut->GetXaxis()->SetRangeUser(0, 20);
    h_DY_nTracks_cjet_cut->Draw("hist e same");
    h_DY_nTracks_cjet_bybin_CR->Draw("hist e same");
    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(h_DY_nTracks_cjet_cut, "Drell-Yan SR", "l");
    // l2->AddEntry(h_DY_nTracks_cjet_CR, "Drell-Yan apply root fit result", "l");
    l2->AddEntry(h_DY_nTracks_cjet_bybin_CR, "Drell-Yan bin by bin check", "l");
    l2->Draw();
    c1->cd(3);

    // h_DY_nTracks_light_CR->Draw("hist e ");
    h_DY_nTracks_light_cut->GetXaxis()->SetRangeUser(0, 20);
    h_DY_nTracks_light_cut->Draw("hist e same");
    h_DY_nTracks_light_bybin_CR->Draw("hist e same");
    TLegend *l3 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.03);
    l3->AddEntry(h_DY_nTracks_light_cut, "Drell-Yan SR", "l");
    // l3->AddEntry(h_DY_nTracks_light_CR, "Drell-Yan apply root fit result", "l");
    l3->AddEntry(h_DY_nTracks_light_bybin_CR, "Drell-Yan bin by bin check", "l");
    l3->Draw();
*/
    /*
    gStyle->SetOptStat(0);
    c1->cd(2);
    TH1D *RatioTop = new TH1D("RatioTop", "", 50, 0, 50);
    RatioTop->Sumw2();
    int nBins = h_DY_nTracks_light_cut->GetNbinsX();
    Double_t Arr_ratio[nBins];
    Double_t X_DYvalue[nBins];
    vector<double> DY_values;
    vector<double> Top_values;
    DY_values.clear();
    Top_values.clear();
    for (int i = 0; i < nBins; i++)
    {
        double cjet_content = h_DY_nTracks_light_cut->GetBinContent(i + 1);
        double cjet_bybin_content = h_DY_nTracks_light_CR->GetBinContent(i + 1);

        double Ratio = 0.;
        if (cjet_bybin_content == 0)
        {
            Ratio = 0.;
            RatioTop->SetBinContent(i + 1, Ratio);
        }
        else
        {
            Ratio = cjet_content / cjet_bybin_content;
            RatioTop->SetBinContent(i + 1, Ratio);
        }
    }

    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();
    RatioTop->GetYaxis()->SetTitle("light jet SR / light jet (root fit)");
    RatioTop->GetXaxis()->SetTitleOffset(1.5);
    RatioTop->GetXaxis()->SetTitle("Trackmulticity");
    RatioTop->Draw("");
    */
    /*
    h_DY_nTracks_cjet_cut->Draw("");
    h_DY_nTracks_cjet_CR->SetLineColor(kRed);
    //h_DY_nTracks_cjet_CR->Draw("same");
    //c1->cd(2);
    h_DY_nTracks_cjet_CR->Draw(" same");

    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_DY_nTracks_light_cut, "Drell-Yan SR", "l");
    l1->AddEntry(h_DY_nTracks_light_CR, "Drell-Yan CR", "l");
    l1->Draw();

    c1->cd(2);
    h_DY_jetpt_light_cut->Draw();
    h_DY_jetpt_light_CR->SetLineColor(kRed);
    h_DY_jetpt_light_CR->Draw("same");
    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(h_DY_jetpt_light_cut, "Drell-Yan SR", "l");
    l2->AddEntry(h_DY_jetpt_light_CR, "Drell-Yan CR", "l");
    l2->Draw();

    c1->cd(3);

    h_DY_jeteta_cjet_CR->SetLineColor(kRed);
    h_DY_jeteta_cjet_cut->Draw();
    h_DY_jeteta_cjet_CR->Draw("same");
    TLegend *l3 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.03);
    l3->AddEntry(h_DY_jeteta_cjet_cut, "Drell-Yan SR", "l");
    l3->AddEntry(h_DY_jeteta_cjet_CR, "Drell-Yan CR", "l");
    l3->Draw();
    */
    /*
     c1->cd(2);
     h_DY_nTracks_light_cut->Draw("hist same");
     c1->cd(4);
     h_DY_nTracks_light_bybin_CR->Draw("hist same");
     c1->cd(3);
     TH1D *RatioTop = new TH1D("RatioTop", "", 50, 0, 50);
     RatioTop->Sumw2();
     int nBins = h_DY_nTracks_bjet_cut->GetNbinsX();
     Double_t Arr_ratio[nBins];
     Double_t X_DYvalue[nBins];
     vector<double> DY_values;
     vector<double> Top_values;
     DY_values.clear();
     Top_values.clear();
     for (int i = 0; i < nBins; i++)
     {
         double cjet_content = h_DY_nTracks_light_cut->GetBinContent(i + 1);
         double cjet_bybin_content = h_DY_nTracks_light_bybin_CR->GetBinContent(i + 1);

         double Ratio = 0.;
         if (cjet_bybin_content == 0)
         {
             Ratio = 0.;
             RatioTop->SetBinContent(i + 1, Ratio);
         }
         else
         {
             Ratio = cjet_content / cjet_bybin_content;
             RatioTop->SetBinContent(i + 1, Ratio);
         }
     }

     gPad->SetTickx();
     RatioTop->GetYaxis()->SetTitle("Cjet SR / Cjet_bybin");
     RatioTop->GetXaxis()->SetTitle("Trackmulticity");
     RatioTop->Draw("e1");
     */
    /*
    TH1D *ROOfitplot = new TH1D("ROOfitplot", "", 50, 0, 50);
    ROOfitplot->Sumw2();
    for (int i = 0; i < 50; i++)
    {
        ROOfitplot->SetBinContent(i + 1, cjet_background(i + 1));
    }
    c1->cd(3);
    ROOfitplot->Draw();
    */
}
