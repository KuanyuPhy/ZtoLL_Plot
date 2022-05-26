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
#include "./../../../lib/setNCUStyle.C"
#include "./../../../lib/Cross_section.h"
using namespace RooFit;
using namespace std;

void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, float Weight, TH1F *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, float flavor2, float hadronflavor, float tmp, float Weight, TH1F *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

Double_t background(Double_t x)
{
    double par1 = -0.25271;
    double frac = 0.999984584;
    double par2 = -0.76;
    double par3 = 0.9;

    Double_t weight = ((TMath::Exp(par1 * x)) + frac * (1 + par2 * (x) + par3 * (2 * x * x - 1)));
    return weight;
}

Double_t bjet_background(Double_t x)
{
    double par0 = -0.359;
    double par1 = -0.2133;
    double par2 = -0.0008248;
    double par3 = -0.02116;
    double par4 = 0.0007806;

    Double_t weight = (TMath::Exp(par0 + par1 * x + par2 * x * x) + par3 + par4 * x);
    return weight;
}
Double_t cjet_background(Double_t x)
{
    double par0 = -0.2871;
    double par1 = -0.5981;
    double par2 = 0.003053;

    Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)));
    return weight;
}
Double_t lightjet_background(Double_t x)
{
    double par0 = 0.2743;
    double par1 = -0.7015;
    double par2 = 0.008359;

    Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)));
    return weight;
}

void Ratio_Top_apply()
{
    setNCUStyle(true);
    TFile *TTTo2L2Nufile = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
    TFile *Top_TTWJetsToLNufile = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQfile = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToQQfile = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_TTZToLLNuNufile = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_tW_antitopfile = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_topfile = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

    //-------------
    // Open Tree
    //-------------
    TFile *TTTo2L2Nufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTTo2L2Nu_2.root");
    TFile *Top_TTWJetsToLNufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTWJetsToLNu_2.root");
    TFile *Top_TTWJetsToQQfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTWJetsToQQ_2.root");
    TFile *Top_TTZToQQfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTZToQQ_2.root");
    TFile *Top_TTZToLLNuNufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTZToLLNuNu_2.root");
    TFile *Top_tW_antitopfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_tW_antitop_2.root");
    TFile *Top_tW_topfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_tW_top_2.root");

    TFile *Topfile = new TFile("./ee_Top_emjet_half.root");

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)TTTo2L2Nufile->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNufile->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQfile->Get("Event_Variable/h_totevent"));
    TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQfile->Get("Event_Variable/h_totevent"));
    TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNufile->Get("Event_Variable/h_totevent"));
    TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitopfile->Get("Event_Variable/h_totevent"));
    TH1D *tW_top_sumevt = ((TH1D *)Top_tW_topfile->Get("Event_Variable/h_totevent"));

    TH1F *h_Top_bfake_rate = ((TH1F *)Topfile->Get("Top_bjet_fakeRate"));
    TH1F *h_Top_cfake_rate = ((TH1F *)Topfile->Get("Top_cjet_fakeRate"));
    TH1F *h_Top_lightfake_rate = ((TH1F *)Topfile->Get("Top_light_fakeRate"));

    int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();
    int TTWJetsToLNu_totevt = TTWJetsToLNu_sumevt->Integral();
    int TTWJetsToQQ_totevt = TTWJetsToQQ_sumevt->Integral();
    int TTZToQQ_totevt = TTZToQQ_sumevt->Integral();
    int TTZToLLNuNu_totevt = TTZToLLNuNu_sumevt->Integral();
    int tW_antitop_totevt = tW_antitop_sumevt->Integral();
    int tW_top_totevt = tW_top_sumevt->Integral();

    //---------------------
    // Define TopWeight
    //---------------------
    float TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * ((GlobalConstants::TTTo2L2Nu) / (TTTo2L2Nu_totevt)) * 1000 * 2;
    float ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000 * 2;
    float ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000 * 2;
    float TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000 * 2;
    float TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000 * 2;
    float TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000 * 2;
    float TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000 * 2;

    //-------------
    //  nTracks
    //-------------
    TH1F *h_Top_nTracks = new TH1F("h_Top_nTracks", "", 50, 0, 50);
    h_Top_nTracks->GetXaxis()->SetTitle("");
    h_Top_nTracks->GetYaxis()->SetTitle("");
    h_Top_nTracks->Sumw2();

    TH1F *h_Top_nTracks_heavy = new TH1F("h_Top_nTracks_heavy", "", 50, 0, 50);
    h_Top_nTracks_heavy->GetXaxis()->SetTitle("");
    h_Top_nTracks_heavy->GetYaxis()->SetTitle("");
    h_Top_nTracks_heavy->Sumw2();

    TH1F *h_Top_nTracks_bjet = new TH1F("h_Top_nTracks_bjet", "", 50, 0, 50);
    h_Top_nTracks_bjet->GetXaxis()->SetTitle("");
    h_Top_nTracks_bjet->GetYaxis()->SetTitle("");
    h_Top_nTracks_bjet->Sumw2();

    TH1F *h_Top_nTracks_cjet = new TH1F("h_Top_nTracks_cjet", "", 50, 0, 50);
    h_Top_nTracks_cjet->GetXaxis()->SetTitle("");
    h_Top_nTracks_cjet->GetYaxis()->SetTitle("");
    h_Top_nTracks_cjet->Sumw2();

    TH1F *h_Top_nTracks_CR = new TH1F("h_Top_nTracks_CR", "", 50, 0, 50);
    h_Top_nTracks_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_CR->Sumw2();

    TH1F *h_Top_nTracks_heavy_CR = new TH1F("h_Top_nTracks_heavy_CR", "", 50, 0, 50);
    h_Top_nTracks_heavy_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_heavy_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_heavy_CR->Sumw2();

    TH1F *h_Top_nTracks_bjet_CR = new TH1F("h_Top_nTracks_bjet_CR", "", 50, 0, 50);
    h_Top_nTracks_bjet_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_bjet_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_bjet_CR->Sumw2();

    TH1F *h_Top_nTracks_cjet_CR = new TH1F("h_Top_nTracks_cjet_CR", "", 50, 0, 50);
    h_Top_nTracks_cjet_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_cjet_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_cjet_CR->Sumw2();

    TH1F *h_Top_nTracks_heavy_cut = new TH1F("h_Top_nTracks_heavy_cut", "", 50, 0, 50);
    h_Top_nTracks_heavy_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_heavy_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_heavy_cut->Sumw2();

    TH1F *h_Top_nTracks_bjet_cut = new TH1F("h_Top_nTracks_bjet_cut", "", 50, 0, 50);
    h_Top_nTracks_bjet_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_bjet_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_bjet_cut->Sumw2();

    TH1F *h_Top_nTracks_cjet_cut = new TH1F("h_Top_nTracks_cjet_cut", "", 50, 0, 50);
    h_Top_nTracks_cjet_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_cjet_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_cjet_cut->Sumw2();

    TH1F *h_Top_nTracks_bjet_bybin_CR = new TH1F("h_Top_nTracks_bjet_bybin_CR", "", 50, 0, 50);
    h_Top_nTracks_bjet_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_bjet_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_bjet_bybin_CR->Sumw2();

    TH1F *h_Top_nTracks_cjet_bybin_CR = new TH1F("h_Top_nTracks_cjet_bybin_CR", "", 50, 0, 50);
    h_Top_nTracks_cjet_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_cjet_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_cjet_bybin_CR->Sumw2();

    TH1F *h_Top_nTracks_light_bybin_CR = new TH1F("h_Top_nTracks_light_bybin_CR", "", 50, 0, 50);
    h_Top_nTracks_light_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_light_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_light_bybin_CR->Sumw2();

    TH1F *h_Top_nTracks_heavy_nogluon = new TH1F("h_Top_nTracks_heavy_nogluon", "", 50, 0, 50);
    h_Top_nTracks_heavy_nogluon->GetXaxis()->SetTitle("");
    h_Top_nTracks_heavy_nogluon->GetYaxis()->SetTitle("");
    h_Top_nTracks_heavy_nogluon->Sumw2();

    TH1F *h_Top_nTracks_heavy_nogluon_cut = new TH1F("h_Top_nTracks_heavy_nogluon_cut", "", 50, 0, 50);
    h_Top_nTracks_heavy_nogluon_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_heavy_nogluon_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_heavy_nogluon_cut->Sumw2();

    TH1F *h_Top_nTracks_light = new TH1F("h_Top_nTracks_light", "", 50, 0, 50);
    h_Top_nTracks_light->GetXaxis()->SetTitle("");
    h_Top_nTracks_light->GetYaxis()->SetTitle("");
    h_Top_nTracks_light->Sumw2();

    TH1F *h_Top_nTracks_light_CR = new TH1F("h_Top_nTracks_light_CR", "", 50, 0, 50);
    h_Top_nTracks_light_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_light_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_light_CR->Sumw2();

    TH1F *h_Top_nTracks_light_cut = new TH1F("h_Top_nTracks_light_cut", "", 50, 0, 50);
    h_Top_nTracks_light_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_light_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_light_cut->Sumw2();

    TH1F *h_Top_nTracks_cut = new TH1F("h_Top_nTracks_cut", "", 50, 0, 50);
    h_Top_nTracks_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_cut->Sumw2();

    TH1F *h_Top_jetpt_light_CR = new TH1F("h_Top_jetpt_light_CR", "", 50, 0, 500);
    h_Top_jetpt_light_CR->GetXaxis()->SetTitle("");
    h_Top_jetpt_light_CR->GetYaxis()->SetTitle("");
    h_Top_jetpt_light_CR->Sumw2();

    TH1F *h_Top_jetpt_light_cut = new TH1F("h_Top_jetpt_light_cut", "", 50, 0, 500);
    h_Top_jetpt_light_cut->GetXaxis()->SetTitle("");
    h_Top_jetpt_light_cut->GetYaxis()->SetTitle("");
    h_Top_jetpt_light_cut->Sumw2();

    TH1F *h_Top_jetpt_bjet_CR = new TH1F("h_Top_jetpt_bjet_CR", "", 50, 0, 500);
    h_Top_jetpt_bjet_CR->GetXaxis()->SetTitle("");
    h_Top_jetpt_bjet_CR->GetYaxis()->SetTitle("");
    h_Top_jetpt_bjet_CR->Sumw2();

    TH1F *h_Top_jetpt_bjet_cut = new TH1F("h_Top_jetpt_bjet_cut", "", 50, 0, 500);
    h_Top_jetpt_bjet_cut->GetXaxis()->SetTitle("");
    h_Top_jetpt_bjet_cut->GetYaxis()->SetTitle("");
    h_Top_jetpt_bjet_cut->Sumw2();

    TH1F *h_Top_jetpt_cjet_CR = new TH1F("h_Top_jetpt_cjet_CR", "", 50, 0, 500);
    h_Top_jetpt_cjet_CR->GetXaxis()->SetTitle("");
    h_Top_jetpt_cjet_CR->GetYaxis()->SetTitle("");
    h_Top_jetpt_cjet_CR->Sumw2();

    TH1F *h_Top_jetpt_cjet_cut = new TH1F("h_Top_jetpt_cjet_cut", "", 50, 0, 500);
    h_Top_jetpt_cjet_cut->GetXaxis()->SetTitle("");
    h_Top_jetpt_cjet_cut->GetYaxis()->SetTitle("");
    h_Top_jetpt_cjet_cut->Sumw2();

    TH1F *h_Top_jeteta_light_CR = new TH1F("h_Top_jeteta_light_CR", "", 30, -3, 3);
    h_Top_jeteta_light_CR->GetXaxis()->SetTitle("");
    h_Top_jeteta_light_CR->GetYaxis()->SetTitle("");
    h_Top_jeteta_light_CR->Sumw2();

    TH1F *h_Top_jeteta_light_cut = new TH1F("h_Top_jeteta_light_cut", "", 30, -3, 3);
    h_Top_jeteta_light_cut->GetXaxis()->SetTitle("");
    h_Top_jeteta_light_cut->GetYaxis()->SetTitle("");
    h_Top_jeteta_light_cut->Sumw2();

    TH1F *h_Top_jeteta_bjet_CR = new TH1F("h_Top_jeteta_bjet_CR", "", 30, -3, 3);
    h_Top_jeteta_bjet_CR->GetXaxis()->SetTitle("");
    h_Top_jeteta_bjet_CR->GetYaxis()->SetTitle("");
    h_Top_jeteta_bjet_CR->Sumw2();

    TH1F *h_Top_jeteta_bjet_cut = new TH1F("h_Top_jeteta_bjet_cut", "", 30, -3, 3);
    h_Top_jeteta_bjet_cut->GetXaxis()->SetTitle("");
    h_Top_jeteta_bjet_cut->GetYaxis()->SetTitle("");
    h_Top_jeteta_bjet_cut->Sumw2();

    TH1F *h_Top_jeteta_cjet_CR = new TH1F("h_Top_jeteta_cjet_CR", "", 30, -3, 3);
    h_Top_jeteta_cjet_CR->GetXaxis()->SetTitle("");
    h_Top_jeteta_cjet_CR->GetYaxis()->SetTitle("");
    h_Top_jeteta_cjet_CR->Sumw2();

    TH1F *h_Top_jeteta_cjet_cut = new TH1F("h_Top_jeteta_cjet_cut", "", 30, -3, 3);
    h_Top_jeteta_cjet_cut->GetXaxis()->SetTitle("");
    h_Top_jeteta_cjet_cut->GetYaxis()->SetTitle("");
    h_Top_jeteta_cjet_cut->Sumw2();

    TH1F *h_Top_jetalpha_light_CR = new TH1F("h_Top_jetalpha_light_CR", "", 24, 0, 1.2);
    h_Top_jetalpha_light_CR->GetXaxis()->SetTitle("");
    h_Top_jetalpha_light_CR->GetYaxis()->SetTitle("");
    h_Top_jetalpha_light_CR->Sumw2();

    TH1F *h_Top_jetalpha_light_cut = new TH1F("h_Top_jetalpha_light_cut", "", 24, 0, 1.2);
    h_Top_jetalpha_light_cut->GetXaxis()->SetTitle("");
    h_Top_jetalpha_light_cut->GetYaxis()->SetTitle("");
    h_Top_jetalpha_light_cut->Sumw2();

    TH1F *h_Top_jetalpha_bjet_CR = new TH1F("h_Top_jetalpha_bjet_CR", "", 24, 0, 1.2);
    h_Top_jetalpha_bjet_CR->GetXaxis()->SetTitle("");
    h_Top_jetalpha_bjet_CR->GetYaxis()->SetTitle("");
    h_Top_jetalpha_bjet_CR->Sumw2();

    TH1F *h_Top_jetalpha_bjet_cut = new TH1F("h_Top_jetalpha_bjet_cut", "", 24, 0, 1.2);
    h_Top_jetalpha_bjet_cut->GetXaxis()->SetTitle("");
    h_Top_jetalpha_bjet_cut->GetYaxis()->SetTitle("");
    h_Top_jetalpha_bjet_cut->Sumw2();

    TH1F *h_Top_jetalpha_cjet_CR = new TH1F("h_Top_jetalpha_cjet_CR", "", 24, 0, 1.2);
    h_Top_jetalpha_cjet_CR->GetXaxis()->SetTitle("");
    h_Top_jetalpha_cjet_CR->GetYaxis()->SetTitle("");
    h_Top_jetalpha_cjet_CR->Sumw2();

    TH1F *h_Top_jetalpha_cjet_cut = new TH1F("h_Top_jetalpha_cjet_cut", "", 24, 0, 1.2);
    h_Top_jetalpha_cjet_cut->GetXaxis()->SetTitle("");
    h_Top_jetalpha_cjet_cut->GetYaxis()->SetTitle("");
    h_Top_jetalpha_cjet_cut->Sumw2();

    Int_t I_TTTo2L2Nu_nThinJets;
    Int_t I_ST_tW_top_nThinJets;
    Int_t I_ST_tW_antitop_nThinJets;
    Int_t I_TTWJetsToLNu_nThinJets;
    Int_t I_TTWJetsToQQ_nThinJets;
    Int_t I_TTZToQQ_nThinJets;
    Int_t I_TTZToLLNuNu_nThinJets;

    Int_t I_TTTo2L2Nu_weight;
    Int_t I_ST_tW_top_weight;
    Int_t I_ST_tW_antitop_weight;
    Int_t I_TTWJetsToLNu_weight;
    Int_t I_TTWJetsToQQ_weight;
    Int_t I_TTZToQQ_weight;
    Int_t I_TTZToLLNuNu_weight;

    float_t f_TTTo2L2Nu_met;
    float_t f_ST_tW_top_met;
    float_t f_ST_tW_antitop_met;
    float_t f_TTWJetsToLNu_met;
    float_t f_TTWJetsToQQ_met;
    float_t f_TTZToQQ_met;
    float_t f_TTZToLLNuNu_met;

    vector<float> *v_TTTo2L2Nu_alpha = new vector<float>();
    vector<float> *v_TTTo2L2Nu_alpha2 = new vector<float>();
    vector<float> *v_TTTo2L2Nu_alpha3 = new vector<float>();
    vector<float> *v_TTTo2L2Nu_alpha4 = new vector<float>();

    vector<float> *v_ST_tW_top_alpha = new vector<float>();
    vector<float> *v_ST_tW_top_alpha2 = new vector<float>();
    vector<float> *v_ST_tW_top_alpha3 = new vector<float>();
    vector<float> *v_ST_tW_top_alpha4 = new vector<float>();

    vector<float> *v_ST_tW_antitop_alpha = new vector<float>();
    vector<float> *v_ST_tW_antitop_alpha2 = new vector<float>();
    vector<float> *v_ST_tW_antitop_alpha3 = new vector<float>();
    vector<float> *v_ST_tW_antitop_alpha4 = new vector<float>();

    vector<float> *v_TTWJetsToLNu_alpha = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha2 = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha3 = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha4 = new vector<float>();

    vector<float> *v_TTWJetsToQQ_alpha = new vector<float>();
    vector<float> *v_TTWJetsToQQ_alpha2 = new vector<float>();
    vector<float> *v_TTWJetsToQQ_alpha3 = new vector<float>();
    vector<float> *v_TTWJetsToQQ_alpha4 = new vector<float>();

    vector<float> *v_TTZToQQ_alpha = new vector<float>();
    vector<float> *v_TTZToQQ_alpha2 = new vector<float>();
    vector<float> *v_TTZToQQ_alpha3 = new vector<float>();
    vector<float> *v_TTZToQQ_alpha4 = new vector<float>();

    vector<float> *v_TTZToLLNuNu_alpha = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha2 = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha3 = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha4 = new vector<float>();

    vector<float> *v_TTTo2L2Nu_Chi3Dlog = new vector<float>();
    vector<float> *v_ST_tW_top_Chi3Dlog = new vector<float>();
    vector<float> *v_ST_tW_antitop_Chi3Dlog = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Chi3Dlog = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Chi3Dlog = new vector<float>();
    vector<float> *v_TTZToQQ_Chi3Dlog = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Chi3Dlog = new vector<float>();

    vector<float> *v_TTTo2L2Nu_2DIP = new vector<float>();
    vector<float> *v_ST_tW_top_2DIP = new vector<float>();
    vector<float> *v_ST_tW_antitop_2DIP = new vector<float>();
    vector<float> *v_TTWJetsToLNu_2DIP = new vector<float>();
    vector<float> *v_TTWJetsToQQ_2DIP = new vector<float>();
    vector<float> *v_TTZToQQ_2DIP = new vector<float>();
    vector<float> *v_TTZToLLNuNu_2DIP = new vector<float>();

    vector<float> *v_TTTo2L2Nu_nTrack = new vector<float>();
    vector<float> *v_ST_tW_top_nTrack = new vector<float>();
    vector<float> *v_ST_tW_antitop_nTrack = new vector<float>();
    vector<float> *v_TTWJetsToLNu_nTrack = new vector<float>();
    vector<float> *v_TTWJetsToQQ_nTrack = new vector<float>();
    vector<float> *v_TTZToQQ_nTrack = new vector<float>();
    vector<float> *v_TTZToLLNuNu_nTrack = new vector<float>();

    vector<float> *v_TTTo2L2Nu_Jethadronflavor = new vector<float>();
    vector<float> *v_ST_tW_top_Jethadronflavor = new vector<float>();
    vector<float> *v_ST_tW_antitop_Jethadronflavor = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Jethadronflavor = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Jethadronflavor = new vector<float>();
    vector<float> *v_TTZToQQ_Jethadronflavor = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Jethadronflavor = new vector<float>();

    vector<float> *v_TTTo2L2Nu_Jetpartonflavor = new vector<float>();
    vector<float> *v_ST_tW_top_Jetpartonflavor = new vector<float>();
    vector<float> *v_ST_tW_antitop_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTZToQQ_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Jetpartonflavor = new vector<float>();

    vector<float> *v_TTTo2L2Nu_JetPT = new vector<float>();
    vector<float> *v_ST_tW_top_JetPT = new vector<float>();
    vector<float> *v_ST_tW_antitop_JetPT = new vector<float>();
    vector<float> *v_TTWJetsToLNu_JetPT = new vector<float>();
    vector<float> *v_TTWJetsToQQ_JetPT = new vector<float>();
    vector<float> *v_TTZToQQ_JetPT = new vector<float>();
    vector<float> *v_TTZToLLNuNu_JetPT = new vector<float>();

    vector<float> *v_TTTo2L2Nu_JetEta = new vector<float>();
    vector<float> *v_ST_tW_top_JetEta = new vector<float>();
    vector<float> *v_ST_tW_antitop_JetEta = new vector<float>();
    vector<float> *v_TTWJetsToLNu_JetEta = new vector<float>();
    vector<float> *v_TTWJetsToQQ_JetEta = new vector<float>();
    vector<float> *v_TTZToQQ_JetEta = new vector<float>();
    vector<float> *v_TTZToLLNuNu_JetEta = new vector<float>();

    v_TTTo2L2Nu_alpha->clear();
    v_TTTo2L2Nu_alpha2->clear();
    v_TTTo2L2Nu_alpha3->clear();
    v_TTTo2L2Nu_alpha4->clear();

    v_ST_tW_top_alpha->clear();
    v_ST_tW_top_alpha2->clear();
    v_ST_tW_top_alpha3->clear();
    v_ST_tW_top_alpha4->clear();

    v_ST_tW_antitop_alpha->clear();
    v_ST_tW_antitop_alpha2->clear();
    v_ST_tW_antitop_alpha3->clear();
    v_ST_tW_antitop_alpha4->clear();

    v_TTWJetsToLNu_alpha->clear();
    v_TTWJetsToLNu_alpha2->clear();
    v_TTWJetsToLNu_alpha3->clear();
    v_TTWJetsToLNu_alpha4->clear();

    v_TTWJetsToQQ_alpha->clear();
    v_TTWJetsToQQ_alpha2->clear();
    v_TTWJetsToQQ_alpha3->clear();
    v_TTWJetsToQQ_alpha4->clear();

    v_TTZToQQ_alpha->clear();
    v_TTZToQQ_alpha2->clear();
    v_TTZToQQ_alpha3->clear();
    v_TTZToQQ_alpha4->clear();

    v_TTZToLLNuNu_alpha->clear();
    v_TTZToLLNuNu_alpha2->clear();
    v_TTZToLLNuNu_alpha3->clear();
    v_TTZToLLNuNu_alpha4->clear();

    v_TTTo2L2Nu_Chi3Dlog->clear();
    v_ST_tW_top_Chi3Dlog->clear();
    v_ST_tW_antitop_Chi3Dlog->clear();
    v_TTWJetsToLNu_Chi3Dlog->clear();
    v_TTWJetsToQQ_Chi3Dlog->clear();
    v_TTZToQQ_Chi3Dlog->clear();
    v_TTZToLLNuNu_Chi3Dlog->clear();

    v_TTTo2L2Nu_2DIP->clear();
    v_ST_tW_top_2DIP->clear();
    v_ST_tW_antitop_2DIP->clear();
    v_TTWJetsToLNu_2DIP->clear();
    v_TTWJetsToQQ_2DIP->clear();
    v_TTZToQQ_2DIP->clear();
    v_TTZToLLNuNu_2DIP->clear();

    v_TTTo2L2Nu_nTrack->clear();
    v_ST_tW_top_nTrack->clear();
    v_ST_tW_antitop_nTrack->clear();
    v_TTWJetsToLNu_nTrack->clear();
    v_TTWJetsToQQ_nTrack->clear();
    v_TTZToQQ_nTrack->clear();
    v_TTZToLLNuNu_nTrack->clear();

    v_TTTo2L2Nu_Jethadronflavor->clear();
    v_ST_tW_top_Jethadronflavor->clear();
    v_ST_tW_antitop_Jethadronflavor->clear();
    v_TTWJetsToLNu_Jethadronflavor->clear();
    v_TTWJetsToQQ_Jethadronflavor->clear();
    v_TTZToQQ_Jethadronflavor->clear();
    v_TTZToLLNuNu_Jethadronflavor->clear();

    v_TTTo2L2Nu_Jetpartonflavor->clear();
    v_ST_tW_top_Jetpartonflavor->clear();
    v_ST_tW_antitop_Jetpartonflavor->clear();
    v_TTWJetsToLNu_Jetpartonflavor->clear();
    v_TTWJetsToQQ_Jetpartonflavor->clear();
    v_TTZToQQ_Jetpartonflavor->clear();
    v_TTZToLLNuNu_Jetpartonflavor->clear();

    v_TTTo2L2Nu_JetPT->clear();
    v_ST_tW_top_JetPT->clear();
    v_ST_tW_antitop_JetPT->clear();
    v_TTWJetsToLNu_JetPT->clear();
    v_TTWJetsToQQ_JetPT->clear();
    v_TTZToQQ_JetPT->clear();
    v_TTZToLLNuNu_JetPT->clear();

    v_TTTo2L2Nu_JetEta->clear();
    v_ST_tW_top_JetEta->clear();
    v_ST_tW_antitop_JetEta->clear();
    v_TTWJetsToLNu_JetEta->clear();
    v_TTWJetsToQQ_JetEta->clear();
    v_TTZToQQ_JetEta->clear();
    v_TTZToLLNuNu_JetEta->clear();

    TTree *T_TTTo2L2Nu_tree;
    TTTo2L2Nufile_1->GetObject("h2", T_TTTo2L2Nu_tree);
    T_TTTo2L2Nu_tree->SetBranchAddress("I_weight", &I_TTTo2L2Nu_weight);
    T_TTTo2L2Nu_tree->SetBranchAddress("I_nJets", &I_TTTo2L2Nu_nThinJets);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_N_Tracks", &v_TTTo2L2Nu_nTrack);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_IP2D", &v_TTTo2L2Nu_2DIP);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTTo2L2Nu_Chi3Dlog);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha", &v_TTTo2L2Nu_alpha);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha2", &v_TTTo2L2Nu_alpha2);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha3", &v_TTTo2L2Nu_alpha3);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha4", &v_TTTo2L2Nu_alpha4);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTTo2L2Nu_Jethadronflavor);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTTo2L2Nu_Jetpartonflavor);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetPt", &v_TTTo2L2Nu_JetPT);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetEta", &v_TTTo2L2Nu_JetEta);

    for (int evt = 0; evt < T_TTTo2L2Nu_tree->GetEntries(); evt++)
    {
        T_TTTo2L2Nu_tree->GetEntry(evt);

        float TTTo2L2Nu_eventWeight = I_TTTo2L2Nu_weight * TTTo2L2NuWeight;
        for (size_t i = 0; i < v_TTTo2L2Nu_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight);
            // For b jet
            for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_light);

            if ((*v_TTTo2L2Nu_Jethadronflavor)[i] == 4 || (*v_TTTo2L2Nu_Jethadronflavor)[i] == 5)
            {
                if ((*v_TTTo2L2Nu_Jetpartonflavor)[i] != 21)
                {
                    h_Top_nTracks_heavy_nogluon->Fill((*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight);
                }
            }

            // By bin
            double bWeightbybin = h_Top_bfake_rate->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;
            double cWeightbybin = h_Top_cfake_rate->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;
            double lightWeightbybin = h_Top_lightfake_rate->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;

            for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], bWeightbybin, h_Top_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], cWeightbybin, h_Top_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], lightWeightbybin, h_Top_nTracks_light_bybin_CR);

            if ((*v_TTTo2L2Nu_alpha)[i] < 0.15)
            {

                h_Top_nTracks_cut->Fill((*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight, h_Top_jetalpha_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight, h_Top_jetalpha_cjet_cut);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight, h_Top_jetalpha_light_cut);
                if ((*v_TTTo2L2Nu_Jethadronflavor)[i] == 4 || (*v_TTTo2L2Nu_Jethadronflavor)[i] == 5)
                {
                    if ((*v_TTTo2L2Nu_Jetpartonflavor)[i] != 21)
                    {
                        h_Top_nTracks_heavy_nogluon_cut->Fill((*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight);
                    }
                }

            } // alpha cut
            else
            {
                // cout << "Here"<<endl;
                double bWeight = bjet_background((*v_TTTo2L2Nu_nTrack)[i]) * TTTo2L2Nu_eventWeight;
                double cWeight = cjet_background((*v_TTTo2L2Nu_nTrack)[i]) * TTTo2L2Nu_eventWeight;
                double lightWeight = lightjet_background((*v_TTTo2L2Nu_nTrack)[i]) * TTTo2L2Nu_eventWeight;
                double Weight = background((*v_TTTo2L2Nu_nTrack)[i]) * TTTo2L2Nu_eventWeight;
                h_Top_nTracks_CR->Fill((*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], bWeight, h_Top_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], bWeight, h_Top_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], bWeight, h_Top_jeteta_bjet_CR);
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], bWeight, h_Top_jetalpha_bjet_CR);
                // For c jet
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], cWeight, h_Top_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], cWeight, h_Top_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], cWeight, h_Top_jeteta_cjet_CR);
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], cWeight, h_Top_jetalpha_cjet_CR);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], Weight, h_Top_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], lightWeight, h_Top_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], lightWeight, h_Top_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], lightWeight, h_Top_jeteta_light_CR);
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], lightWeight, h_Top_jetalpha_light_CR);
            } // apply fake rate
        }

    } // End of TTTo2L2Nu

    TTree *T_ST_tW_top_tree;
    Top_tW_topfile_1->GetObject("h2", T_ST_tW_top_tree);
    T_ST_tW_top_tree->SetBranchAddress("I_weight", &I_ST_tW_top_weight);
    T_ST_tW_top_tree->SetBranchAddress("I_nJets", &I_ST_tW_top_nThinJets);
    T_ST_tW_top_tree->SetBranchAddress("v_N_Tracks", &v_ST_tW_top_nTrack);
    T_ST_tW_top_tree->SetBranchAddress("f_Met", &f_ST_tW_top_met);
    T_ST_tW_top_tree->SetBranchAddress("v_IP2D", &v_ST_tW_top_2DIP);
    T_ST_tW_top_tree->SetBranchAddress("v_Chi3Dlog", &v_ST_tW_top_Chi3Dlog);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_top_alpha);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha2", &v_ST_tW_top_alpha2);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha3", &v_ST_tW_top_alpha3);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha4", &v_ST_tW_top_alpha4);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ST_tW_top_Jethadronflavor);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ST_tW_top_Jetpartonflavor);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetPt", &v_ST_tW_top_JetPT);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetEta", &v_ST_tW_top_JetEta);
    for (int evt = 0; evt < T_ST_tW_top_tree->GetEntries(); evt++)
    {
        T_ST_tW_top_tree->GetEntry(evt);

        float ST_tW_top_eventWeight = I_ST_tW_top_weight * ST_tW_topWeight;

        for (size_t i = 0; i < v_ST_tW_top_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight);
            // For b jet
            for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_light);

            if ((*v_ST_tW_top_Jethadronflavor)[i] == 4 || (*v_ST_tW_top_Jethadronflavor)[i] == 5)
            {
                if ((*v_ST_tW_top_Jetpartonflavor)[i] != 21)
                {
                    h_Top_nTracks_heavy_nogluon->Fill((*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight);
                }
            }

            // By bin
            double bWeightbybin = h_Top_bfake_rate->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;
            double cWeightbybin = h_Top_cfake_rate->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;
            double lightWeightbybin = h_Top_lightfake_rate->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;

            for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], bWeightbybin, h_Top_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], cWeightbybin, h_Top_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], lightWeightbybin, h_Top_nTracks_light_bybin_CR);

            if ((*v_ST_tW_top_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight, h_Top_jetalpha_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight, h_Top_jetalpha_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight, h_Top_jetalpha_light_cut);
                if ((*v_ST_tW_top_Jethadronflavor)[i] == 4 || (*v_ST_tW_top_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ST_tW_top_Jetpartonflavor)[i] != 21)
                    {
                        h_Top_nTracks_heavy_nogluon_cut->Fill((*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight);
                    }
                }

            } // alpha cut
            else
            {
                double bWeight = bjet_background((*v_ST_tW_top_nTrack)[i]) * ST_tW_top_eventWeight;
                double cWeight = cjet_background((*v_ST_tW_top_nTrack)[i]) * ST_tW_top_eventWeight;
                double lightWeight = lightjet_background((*v_ST_tW_top_nTrack)[i]) * ST_tW_top_eventWeight;
                double Weight = background((*v_ST_tW_top_nTrack)[i]) * ST_tW_top_eventWeight;
                h_Top_nTracks_CR->Fill((*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], bWeight, h_Top_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], bWeight, h_Top_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], bWeight, h_Top_jeteta_bjet_CR);
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], bWeight, h_Top_jetalpha_bjet_CR);
                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], cWeight, h_Top_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], cWeight, h_Top_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], cWeight, h_Top_jeteta_cjet_CR);
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], cWeight, h_Top_jetalpha_cjet_CR);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], Weight, h_Top_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], lightWeight, h_Top_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], lightWeight, h_Top_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], lightWeight, h_Top_jeteta_light_CR);
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], lightWeight, h_Top_jetalpha_light_CR);
            } // apply fake rate
        }
    } // End of ST_tW_top_tree

    TTree *T_ST_tW_antitop_tree;
    Top_tW_antitopfile_1->GetObject("h2", T_ST_tW_antitop_tree);
    T_ST_tW_antitop_tree->SetBranchAddress("I_weight", &I_ST_tW_antitop_weight);
    T_ST_tW_antitop_tree->SetBranchAddress("I_nJets", &I_ST_tW_antitop_nThinJets);
    T_ST_tW_antitop_tree->SetBranchAddress("v_N_Tracks", &v_ST_tW_antitop_nTrack);
    T_ST_tW_antitop_tree->SetBranchAddress("f_Met", &f_ST_tW_antitop_met);
    T_ST_tW_antitop_tree->SetBranchAddress("v_IP2D", &v_ST_tW_antitop_2DIP);
    T_ST_tW_antitop_tree->SetBranchAddress("v_Chi3Dlog", &v_ST_tW_antitop_Chi3Dlog);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_antitop_alpha);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha2", &v_ST_tW_antitop_alpha2);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha3", &v_ST_tW_antitop_alpha3);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha4", &v_ST_tW_antitop_alpha4);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ST_tW_antitop_Jethadronflavor);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ST_tW_antitop_Jetpartonflavor);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetPt", &v_ST_tW_antitop_JetPT);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetEta", &v_ST_tW_antitop_JetEta);
    for (int evt = 0; evt < T_ST_tW_antitop_tree->GetEntries(); evt++)
    {
        T_ST_tW_antitop_tree->GetEntry(evt);
        float ST_tW_antitop_eventWeight = I_ST_tW_antitop_weight * ST_tW_antitopWeight;
        for (size_t i = 0; i < v_ST_tW_antitop_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight);
            // For b jet
            for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_light);

            if ((*v_ST_tW_antitop_Jethadronflavor)[i] == 4 || (*v_ST_tW_antitop_Jethadronflavor)[i] == 5)
            {
                if ((*v_ST_tW_antitop_Jetpartonflavor)[i] != 21)
                {
                    h_Top_nTracks_heavy_nogluon->Fill((*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight);
                }
            }

            // By bin
            double bWeightbybin = h_Top_bfake_rate->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;
            double cWeightbybin = h_Top_cfake_rate->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;
            double lightWeightbybin = h_Top_lightfake_rate->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;

            for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], bWeightbybin, h_Top_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], cWeightbybin, h_Top_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], lightWeightbybin, h_Top_nTracks_light_bybin_CR);

            if ((*v_ST_tW_antitop_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight, h_Top_jetalpha_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight, h_Top_jetalpha_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight, h_Top_jetalpha_light_cut);
                if ((*v_ST_tW_antitop_Jethadronflavor)[i] == 4 || (*v_ST_tW_antitop_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ST_tW_antitop_Jetpartonflavor)[i] != 21)
                    {
                        h_Top_nTracks_heavy_nogluon_cut->Fill((*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight);
                    }
                }

            } // alpha cut
            else
            {
                double bWeight = bjet_background((*v_ST_tW_antitop_nTrack)[i]) * ST_tW_antitop_eventWeight;
                double cWeight = cjet_background((*v_ST_tW_antitop_nTrack)[i]) * ST_tW_antitop_eventWeight;
                double lightWeight = lightjet_background((*v_ST_tW_antitop_nTrack)[i]) * ST_tW_antitop_eventWeight;
                double Weight = background((*v_ST_tW_antitop_nTrack)[i]) * ST_tW_antitop_eventWeight;
                h_Top_nTracks_CR->Fill((*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], bWeight, h_Top_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], bWeight, h_Top_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], bWeight, h_Top_jeteta_bjet_CR);
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], bWeight, h_Top_jetalpha_bjet_CR);
                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], cWeight, h_Top_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], cWeight, h_Top_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], cWeight, h_Top_jeteta_cjet_CR);
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], cWeight, h_Top_jetalpha_cjet_CR);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], Weight, h_Top_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], lightWeight, h_Top_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], lightWeight, h_Top_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], lightWeight, h_Top_jeteta_light_CR);
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], lightWeight, h_Top_jetalpha_light_CR);
            } // apply fake rate
        }
    } // End of ST_tW_antitop_tree
    TTree *T_TTWJetsToLNu_tree;
    Top_TTWJetsToLNufile_1->GetObject("h2", T_TTWJetsToLNu_tree);
    T_TTWJetsToLNu_tree->SetBranchAddress("I_weight", &I_TTWJetsToLNu_weight);
    T_TTWJetsToLNu_tree->SetBranchAddress("I_nJets", &I_TTWJetsToLNu_nThinJets);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_N_Tracks", &v_TTWJetsToLNu_nTrack);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_IP2D", &v_TTWJetsToLNu_2DIP);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTWJetsToLNu_Chi3Dlog);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToLNu_alpha);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha2", &v_TTWJetsToLNu_alpha2);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha3", &v_TTWJetsToLNu_alpha3);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha4", &v_TTWJetsToLNu_alpha4);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTWJetsToLNu_Jethadronflavor);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTWJetsToLNu_Jetpartonflavor);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetPt", &v_TTWJetsToLNu_JetPT);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetEta", &v_TTWJetsToLNu_JetEta);
    for (int evt = 0; evt < T_TTWJetsToLNu_tree->GetEntries(); evt++)
    {
        T_TTWJetsToLNu_tree->GetEntry(evt);
        float TTWJetsToLNu_eventWeight = I_TTWJetsToLNu_weight * TTWJetsToLNuWeight;
        for (size_t i = 0; i < v_TTWJetsToLNu_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight);
            // For b jet
            for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_light);

            if ((*v_TTWJetsToLNu_Jethadronflavor)[i] == 4 || (*v_TTWJetsToLNu_Jethadronflavor)[i] == 5)
            {
                if ((*v_TTWJetsToLNu_Jetpartonflavor)[i] != 21)
                {
                    h_Top_nTracks_heavy_nogluon->Fill((*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight);
                }
            }

            // By bin
            double bWeightbybin = h_Top_bfake_rate->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;
            double cWeightbybin = h_Top_cfake_rate->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;
            double lightWeightbybin = h_Top_lightfake_rate->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;

            for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], bWeightbybin, h_Top_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], cWeightbybin, h_Top_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], lightWeightbybin, h_Top_nTracks_light_bybin_CR);

            if ((*v_TTWJetsToLNu_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight, h_Top_jetalpha_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight, h_Top_jetalpha_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight, h_Top_jetalpha_light_cut);
                if ((*v_TTWJetsToLNu_Jethadronflavor)[i] == 4 || (*v_TTWJetsToLNu_Jethadronflavor)[i] == 5)
                {
                    if ((*v_TTWJetsToLNu_Jetpartonflavor)[i] != 21)
                    {
                        h_Top_nTracks_heavy_nogluon_cut->Fill((*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight);
                    }
                }

            } // alpha cut
            else
            {
                double bWeight = bjet_background((*v_TTWJetsToLNu_nTrack)[i]) * TTWJetsToLNu_eventWeight;
                double cWeight = cjet_background((*v_TTWJetsToLNu_nTrack)[i]) * TTWJetsToLNu_eventWeight;
                double lightWeight = lightjet_background((*v_TTWJetsToLNu_nTrack)[i]) * TTWJetsToLNu_eventWeight;
                double Weight = background((*v_TTWJetsToLNu_nTrack)[i]) * TTWJetsToLNu_eventWeight;
                h_Top_nTracks_CR->Fill((*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], bWeight, h_Top_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], bWeight, h_Top_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], bWeight, h_Top_jeteta_bjet_CR);
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], bWeight, h_Top_jetalpha_bjet_CR);
                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], cWeight, h_Top_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], cWeight, h_Top_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], cWeight, h_Top_jeteta_cjet_CR);
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], cWeight, h_Top_jetalpha_cjet_CR);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], Weight, h_Top_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], lightWeight, h_Top_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], lightWeight, h_Top_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], lightWeight, h_Top_jeteta_light_CR);
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], lightWeight, h_Top_jetalpha_light_CR);
            } // apply fake rate
        }
    }
    TTree *T_TTWJetsToQQ_tree;
    Top_TTWJetsToQQfile_1->GetObject("h2", T_TTWJetsToQQ_tree);
    T_TTWJetsToQQ_tree->SetBranchAddress("I_weight", &I_TTWJetsToQQ_weight);
    T_TTWJetsToQQ_tree->SetBranchAddress("I_nJets", &I_TTWJetsToQQ_nThinJets);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_N_Tracks", &v_TTWJetsToQQ_nTrack);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_IP2D", &v_TTWJetsToQQ_2DIP);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_Chi3Dlog", &v_TTWJetsToQQ_Chi3Dlog);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToQQ_alpha);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha2", &v_TTWJetsToQQ_alpha2);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha3", &v_TTWJetsToQQ_alpha3);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha4", &v_TTWJetsToQQ_alpha4);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTWJetsToQQ_Jethadronflavor);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTWJetsToQQ_Jetpartonflavor);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetPt", &v_TTWJetsToQQ_JetPT);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetEta", &v_TTWJetsToQQ_JetEta);
    for (int evt = 0; evt < T_TTWJetsToQQ_tree->GetEntries(); evt++)
    {
        T_TTWJetsToQQ_tree->GetEntry(evt);

        float TTWJetsToQQ_eventWeight = I_TTWJetsToQQ_weight * TTWJetsToQQWeight;
        for (size_t i = 0; i < v_TTWJetsToQQ_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight);
            // For b jet
            for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_light);

            if ((*v_TTWJetsToQQ_Jethadronflavor)[i] == 4 || (*v_TTWJetsToQQ_Jethadronflavor)[i] == 5)
            {
                if ((*v_TTWJetsToQQ_Jetpartonflavor)[i] != 21)
                {
                    h_Top_nTracks_heavy_nogluon->Fill((*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight);
                }
            }

            // By bin
            double bWeightbybin = h_Top_bfake_rate->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;
            double cWeightbybin = h_Top_cfake_rate->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;
            double lightWeightbybin = h_Top_lightfake_rate->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;

            for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], bWeightbybin, h_Top_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], cWeightbybin, h_Top_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], lightWeightbybin, h_Top_nTracks_light_bybin_CR);

            if ((*v_TTWJetsToQQ_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight, h_Top_jetalpha_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight, h_Top_jetalpha_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight, h_Top_jetalpha_light_cut);
                if ((*v_TTWJetsToQQ_Jethadronflavor)[i] == 4 || (*v_TTWJetsToQQ_Jethadronflavor)[i] == 5)
                {
                    if ((*v_TTWJetsToQQ_Jetpartonflavor)[i] != 21)
                    {
                        h_Top_nTracks_heavy_nogluon_cut->Fill((*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight);
                    }
                }
            } // alpha cut
            else
            {
                double bWeight = bjet_background((*v_TTWJetsToQQ_nTrack)[i]) * TTWJetsToQQ_eventWeight;
                double cWeight = cjet_background((*v_TTWJetsToQQ_nTrack)[i]) * TTWJetsToQQ_eventWeight;
                double lightWeight = lightjet_background((*v_TTWJetsToQQ_nTrack)[i]) * TTWJetsToQQ_eventWeight;
                double Weight = background((*v_TTWJetsToQQ_nTrack)[i]) * TTWJetsToQQ_eventWeight;
                h_Top_nTracks_CR->Fill((*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], bWeight, h_Top_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], bWeight, h_Top_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], bWeight, h_Top_jeteta_bjet_CR);
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], bWeight, h_Top_jetalpha_bjet_CR);
                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], cWeight, h_Top_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], cWeight, h_Top_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], cWeight, h_Top_jeteta_cjet_CR);
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], cWeight, h_Top_jetalpha_cjet_CR);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], Weight, h_Top_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], lightWeight, h_Top_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], lightWeight, h_Top_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], lightWeight, h_Top_jeteta_light_CR);
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], lightWeight, h_Top_jetalpha_light_CR);
            } // apply fake rate
        }
    }
    TTree *T_TTZToQQ_tree;
    Top_TTZToQQfile_1->GetObject("h2", T_TTZToQQ_tree);
    T_TTZToQQ_tree->SetBranchAddress("I_weight", &I_TTZToQQ_weight);
    T_TTZToQQ_tree->SetBranchAddress("I_nJets", &I_TTZToQQ_nThinJets);
    T_TTZToQQ_tree->SetBranchAddress("v_N_Tracks", &v_TTZToQQ_nTrack);
    T_TTZToQQ_tree->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_TTZToQQ_tree->SetBranchAddress("v_IP2D", &v_TTZToQQ_2DIP);
    T_TTZToQQ_tree->SetBranchAddress("v_Chi3Dlog", &v_TTZToQQ_Chi3Dlog);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTZToQQ_alpha);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha2", &v_TTZToQQ_alpha2);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha3", &v_TTZToQQ_alpha3);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha4", &v_TTZToQQ_alpha4);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToQQ_Jethadronflavor);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTZToQQ_Jetpartonflavor);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetPt", &v_TTZToQQ_JetPT);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetEta", &v_TTZToQQ_JetEta);
    for (int evt = 0; evt < T_TTZToQQ_tree->GetEntries(); evt++)
    {
        T_TTZToQQ_tree->GetEntry(evt);

        float TTZToQQ_eventWeight = I_TTZToQQ_weight * TTZToQQWeight;
        for (size_t i = 0; i < v_TTZToQQ_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight);
            // For b jet
            for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_light);

            if ((*v_TTZToQQ_Jethadronflavor)[i] == 4 || (*v_TTZToQQ_Jethadronflavor)[i] == 5)
            {
                if ((*v_TTZToQQ_Jetpartonflavor)[i] != 21)
                {
                    h_Top_nTracks_heavy_nogluon->Fill((*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight);
                }
            }

            // By bin
            double bWeightbybin = h_Top_bfake_rate->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;
            double cWeightbybin = h_Top_cfake_rate->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;
            double lightWeightbybin = h_Top_lightfake_rate->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;

            for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], bWeightbybin, h_Top_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], cWeightbybin, h_Top_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], lightWeightbybin, h_Top_nTracks_light_bybin_CR);

            if ((*v_TTZToQQ_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight, h_Top_jetalpha_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight, h_Top_jetalpha_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight, h_Top_jetalpha_light_cut);
                if ((*v_TTZToQQ_Jethadronflavor)[i] == 4 || (*v_TTZToQQ_Jethadronflavor)[i] == 5)
                {
                    if ((*v_TTZToQQ_Jetpartonflavor)[i] != 21)
                    {
                        h_Top_nTracks_heavy_nogluon_cut->Fill((*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight);
                    }
                }
            } // alpha cut
            else
            {
                double bWeight = bjet_background((*v_TTZToQQ_nTrack)[i]) * TTZToQQ_eventWeight;
                double cWeight = cjet_background((*v_TTZToQQ_nTrack)[i]) * TTZToQQ_eventWeight;
                double lightWeight = lightjet_background((*v_TTZToQQ_nTrack)[i]) * TTZToQQ_eventWeight;
                double Weight = background((*v_TTZToQQ_nTrack)[i]) * TTZToQQ_eventWeight;
                h_Top_nTracks_CR->Fill((*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], bWeight, h_Top_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], bWeight, h_Top_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], bWeight, h_Top_jeteta_bjet_CR);
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], bWeight, h_Top_jetalpha_bjet_CR);
                // For c jet
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], cWeight, h_Top_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], cWeight, h_Top_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], cWeight, h_Top_jeteta_cjet_CR);
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], cWeight, h_Top_jetalpha_cjet_CR);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], Weight, h_Top_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], lightWeight, h_Top_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], lightWeight, h_Top_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], lightWeight, h_Top_jeteta_light_CR);
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], lightWeight, h_Top_jetalpha_light_CR);
            } // apply fake rate
        }
    }
    TTree *T_TTZToLLNuNu_tree;
    Top_TTZToLLNuNufile_1->GetObject("h2", T_TTZToLLNuNu_tree);
    T_TTZToLLNuNu_tree->SetBranchAddress("I_weight", &I_TTZToLLNuNu_weight);
    T_TTZToLLNuNu_tree->SetBranchAddress("I_nJets", &I_TTZToLLNuNu_nThinJets);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_N_Tracks", &v_TTZToLLNuNu_nTrack);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_IP2D", &v_TTZToLLNuNu_2DIP);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTZToLLNuNu_Chi3Dlog);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha", &v_TTZToLLNuNu_alpha);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha2", &v_TTZToLLNuNu_alpha2);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha3", &v_TTZToLLNuNu_alpha3);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha4", &v_TTZToLLNuNu_alpha4);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToLLNuNu_Jethadronflavor);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTZToLLNuNu_Jetpartonflavor);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetPt", &v_TTZToLLNuNu_JetPT);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetEta", &v_TTZToLLNuNu_JetEta);
    for (int evt = 0; evt < T_TTZToLLNuNu_tree->GetEntries(); evt++)
    {
        T_TTZToLLNuNu_tree->GetEntry(evt);

        float TTZToLLNuNu_eventWeight = I_TTZToLLNuNu_weight * TTZToLLNuNuWeight;
        for (size_t i = 0; i < v_TTZToLLNuNu_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight);
            // For b jet
            for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_light);

            if ((*v_TTZToLLNuNu_Jethadronflavor)[i] == 4 || (*v_TTZToLLNuNu_Jethadronflavor)[i] == 5)
            {
                if ((*v_TTZToLLNuNu_Jetpartonflavor)[i] != 21)
                {
                    h_Top_nTracks_heavy_nogluon->Fill((*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight);
                }
            }

            // By bin
            double bWeightbybin = h_Top_bfake_rate->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;
            double cWeightbybin = h_Top_cfake_rate->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;
            double lightWeightbybin = h_Top_lightfake_rate->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;

            for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], bWeightbybin, h_Top_nTracks_bjet_bybin_CR);
            for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], cWeightbybin, h_Top_nTracks_cjet_bybin_CR);
            for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], lightWeightbybin, h_Top_nTracks_light_bybin_CR);

            if ((*v_TTZToLLNuNu_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight, h_Top_jetalpha_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight, h_Top_jetalpha_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight, h_Top_jetalpha_light_cut);
                if ((*v_TTZToLLNuNu_Jethadronflavor)[i] == 4 || (*v_TTZToLLNuNu_Jethadronflavor)[i] == 5)
                {
                    if ((*v_TTZToLLNuNu_Jetpartonflavor)[i] != 21)
                    {
                        h_Top_nTracks_heavy_nogluon_cut->Fill((*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight);
                    }
                }
            } // alpha cut
            else
            {
                double bWeight = bjet_background((*v_TTZToLLNuNu_nTrack)[i]) * TTZToLLNuNu_eventWeight;
                double cWeight = cjet_background((*v_TTZToLLNuNu_nTrack)[i]) * TTZToLLNuNu_eventWeight;
                double lightWeight = lightjet_background((*v_TTZToLLNuNu_nTrack)[i]) * TTZToLLNuNu_eventWeight;
                double Weight = background((*v_TTZToLLNuNu_nTrack)[i]) * TTZToLLNuNu_eventWeight;
                h_Top_nTracks_CR->Fill((*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], bWeight, h_Top_nTracks_bjet_CR);
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], bWeight, h_Top_jetpt_bjet_CR);
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], bWeight, h_Top_jeteta_bjet_CR);
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], bWeight, h_Top_jetalpha_bjet_CR);
                // For c jet
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], cWeight, h_Top_nTracks_cjet_CR);
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], cWeight, h_Top_jetpt_cjet_CR);
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], cWeight, h_Top_jeteta_cjet_CR);
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], cWeight, h_Top_jetalpha_cjet_CR);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], Weight, h_Top_nTracks_heavy_CR);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], lightWeight, h_Top_nTracks_light_CR);
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], lightWeight, h_Top_jetpt_light_CR);
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], lightWeight, h_Top_jeteta_light_CR);
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], lightWeight, h_Top_jetalpha_light_CR);
            } // apply fake rate
        }
    }
    h_Top_jetpt_bjet_cut->SetLineWidth(2);
    h_Top_jetpt_cjet_cut->SetLineWidth(2);
    h_Top_jetpt_light_cut->SetLineWidth(2);
    h_Top_jetpt_bjet_CR->SetLineWidth(2);
    h_Top_jetpt_cjet_CR->SetLineWidth(2);
    h_Top_jetpt_light_CR->SetLineWidth(2);

    h_Top_jeteta_bjet_cut->SetLineWidth(2);
    h_Top_jeteta_cjet_cut->SetLineWidth(2);
    h_Top_jeteta_light_cut->SetLineWidth(2);
    h_Top_jeteta_bjet_CR->SetLineWidth(2);
    h_Top_jeteta_cjet_CR->SetLineWidth(2);
    h_Top_jeteta_light_CR->SetLineWidth(2);

    h_Top_nTracks_bjet_cut->SetTitle("b jet (Top)");
    h_Top_nTracks_cjet_cut->SetTitle("c jet (Top)");
    h_Top_nTracks_light_cut->SetTitle("light jet (Top)");
    h_Top_jetpt_bjet_cut->SetTitle("b jet (Top)");
    h_Top_jetpt_cjet_cut->SetTitle("c jet (Top)");
    h_Top_jetpt_light_cut->SetTitle("light jet (Top)");
    h_Top_jeteta_bjet_cut->SetTitle("b jet (Top)");
    h_Top_jeteta_cjet_cut->SetTitle("c jet (Top)");
    h_Top_jeteta_light_cut->SetTitle("light jet (Top)");
    h_Top_jeteta_light_CR->SetTitle("light jet (Top)");

    h_Top_nTracks_bjet_cut->GetYaxis()->SetTitle("nJets");
    h_Top_nTracks_cjet_cut->GetYaxis()->SetTitle("nJets");
    h_Top_nTracks_light_cut->GetYaxis()->SetTitle("nJets");
    h_Top_jetpt_bjet_cut->GetYaxis()->SetTitle("nJets");
    h_Top_jetpt_cjet_cut->GetYaxis()->SetTitle("nJets");
    h_Top_jetpt_light_cut->GetYaxis()->SetTitle("nJets");
    h_Top_jeteta_bjet_cut->GetYaxis()->SetTitle("nJets");
    h_Top_jeteta_cjet_cut->GetYaxis()->SetTitle("nJets");
    h_Top_jeteta_light_cut->GetYaxis()->SetTitle("nJets");
    h_Top_jeteta_light_CR->GetYaxis()->SetTitle("nJets");

    // h_Top_jetpt_light_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    h_Top_nTracks_bjet_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    h_Top_nTracks_cjet_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    h_Top_nTracks_light_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    h_Top_jetpt_bjet_cut->GetXaxis()->SetTitle("Jet PT");
    h_Top_jetpt_cjet_cut->GetXaxis()->SetTitle("Jet PT");
    h_Top_jetpt_light_cut->GetXaxis()->SetTitle("Jet PT");
    h_Top_jeteta_bjet_cut->GetXaxis()->SetTitle("Jet #eta");
    h_Top_jeteta_cjet_cut->GetXaxis()->SetTitle("Jet #eta");
    h_Top_jeteta_light_cut->GetXaxis()->SetTitle("Jet #eta");
    h_Top_jeteta_light_CR->GetXaxis()->SetTitle("Jet #eta");

    h_Top_nTracks_bjet_cut->GetXaxis()->SetTitleOffset(1.5);
    h_Top_nTracks_cjet_cut->GetXaxis()->SetTitleOffset(1.5);
    h_Top_nTracks_light_cut->GetXaxis()->SetTitleOffset(1.5);
    h_Top_jetpt_bjet_cut->GetXaxis()->SetTitleOffset(1.5);
    h_Top_jetpt_cjet_cut->GetXaxis()->SetTitleOffset(1.5);
    h_Top_jetpt_light_cut->GetXaxis()->SetTitleOffset(1.5);
    h_Top_jeteta_bjet_cut->GetXaxis()->SetTitleOffset(1.5);
    h_Top_jeteta_cjet_cut->GetXaxis()->SetTitleOffset(1.5);
    h_Top_jeteta_light_cut->GetXaxis()->SetTitleOffset(1.5);
    h_Top_jeteta_light_CR->GetXaxis()->SetTitleOffset(1.5);

    TCanvas *c1 = new TCanvas("c1", "", 1000, 1000);
    c1->Divide(3, 1);
    c1->cd(1);
    h_Top_nTracks_bjet_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_nTracks_cjet_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_nTracks_light_bybin_CR->SetLineColor(kGreen + 3);

    h_Top_nTracks_bjet_cut->GetXaxis()->SetRangeUser(0,20);
    h_Top_nTracks_bjet_cut->Draw("hist e same");
    h_Top_nTracks_bjet_bybin_CR->Draw("hist e same");
    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_Top_nTracks_bjet_cut, "Top SR", "l");
    l1->AddEntry(h_Top_nTracks_bjet_bybin_CR, "Top bin by bin check", "l");
    l1->Draw();
    c1->cd(2);
    h_Top_nTracks_cjet_cut->GetXaxis()->SetRangeUser(0,20);
    h_Top_nTracks_cjet_cut->Draw("hist e same");
    h_Top_nTracks_cjet_bybin_CR->Draw("hist e same");
    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(h_Top_nTracks_cjet_cut, "Top SR", "l");
    l2->AddEntry(h_Top_nTracks_cjet_bybin_CR, "Top bin by bin check", "l");
    l2->Draw();
    c1->cd(3);
    h_Top_nTracks_light_cut->GetXaxis()->SetRangeUser(0,20);
    h_Top_nTracks_light_cut->Draw("hist e same");
    h_Top_nTracks_light_bybin_CR->Draw("hist e same");

    TLegend *l3 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.03);
    l3->AddEntry(h_Top_nTracks_light_cut, "Top SR", "l");
    l3->AddEntry(h_Top_nTracks_light_bybin_CR, "Top bin by bin check", "l");
    l3->Draw();
    /*
    h_Top_nTracks_light_cut->Draw();
    h_Top_nTracks_light_CR->SetLineColor(kRed);
    h_Top_nTracks_light_CR->Draw("same");

    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_Top_nTracks_light_cut, "Top SR", "l");
    l1->AddEntry(h_Top_nTracks_light_CR, "Top CR", "l");
    l1->Draw();

    c1->cd(2);
    h_Top_jetpt_light_cut->Draw();
    h_Top_jetpt_light_CR->SetLineColor(kRed);
    h_Top_jetpt_light_CR->Draw("same");

    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(h_Top_jetpt_light_cut, "Top SR", "l");
    l2->AddEntry(h_Top_jetpt_light_CR, "Top CR", "l");
    l2->Draw();

    c1->cd(3);
    h_Top_jeteta_light_CR->Draw();
    h_Top_jeteta_light_CR->SetLineColor(kRed);
    // h_Top_jeteta_light_cut->Draw("same");

    TLegend *l3 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.03);
    l3->AddEntry(h_Top_jeteta_light_cut, "Top SR", "l");
    l3->AddEntry(h_Top_jeteta_light_CR, "Top CR", "l");
    l3->Draw();
    */
}
