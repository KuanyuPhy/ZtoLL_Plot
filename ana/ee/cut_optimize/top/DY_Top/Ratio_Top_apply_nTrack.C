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
#include "TLegend.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "./../../../../lib/setNCUStyle.C"
#include "./../../../../lib/Cross_section.h"
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
void for_bin_by_bin_sigleflavor_jet(int flavor, float hadronflavor, TH1D *h_fakerate, int nTrack, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        if (nTrack > 20)
        {
            double fakerate_weight = h_fakerate->GetBinContent(20);
            h_tmp->Fill(nTrack, fakerate_weight * Weight);
        }
        else
        {
            double fakerate_weight = h_fakerate->GetBinContent(nTrack);
            h_tmp->Fill(nTrack, fakerate_weight * Weight);
        }
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
    double par0 = -2.32165e-01;
    double par1 = -3.29605e-01;
    double par2 = 1.63397e-02;
    double par3 = -1.08663e-03;
    double par4 = 2.10796e-02;
    double par5 = -8.92923e-04;
    Double_t weight = (TMath::Exp(par0 + par1 * x + par2 * x * x + par3 * x * x * x) + par4 + par5 * x);
    return weight;
}
Double_t cjet_background(Double_t x)
{
    double par0 = -1.01347e-01;
    double par1 = -7.13189e-01;
    double par2 = 2.12814e-02;
    double par3 = -4.20289e-04;
    double par4 = -2.06329e-03;
    double par5 = 1.06572e-04;
    Double_t weight = (TMath::Exp(par0 + par1 * x + par2 * x * x + par3 * x * x * x) + par4 + par5 * x);
    return weight;
}
Double_t lightjet_background(float x)
{
    double par0 = 2.19479e-01;
    double par1 = -6.55357e-01;
    double par2 = -1.31534e-03;
    double par3 = 5.51655e-04;
    double par4 = 3.63651e-05;
    double par5 = -6.85263e-06;
    Double_t weight = (TMath::Exp(par0 + par1 * x + par2 * x * x + par3 * x * x * x) + par4 + par5 * x);
    return weight;
}

void Ratio_Top_apply_nTrack()
{
    TFile *TTTo2L2Nufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
    TFile *Top_TTWJetsToLNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_TTZToLLNuNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_tW_antitopfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_topfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

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

    TFile *Topfile = new TFile("./../ee_Top_emjet_half.root");
    TFile *DYfile = new TFile("./../../DY/ee_DY_emjet_half.root");

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)TTTo2L2Nufile->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNufile->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQfile->Get("Event_Variable/h_totevent"));
    TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQfile->Get("Event_Variable/h_totevent"));
    TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNufile->Get("Event_Variable/h_totevent"));
    TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitopfile->Get("Event_Variable/h_totevent"));
    TH1D *tW_top_sumevt = ((TH1D *)Top_tW_topfile->Get("Event_Variable/h_totevent"));

    TH1D *h_Top_bfake_rate = ((TH1D *)Topfile->Get("Top_bjet_fakeRate"));
    TH1D *h_Top_cfake_rate = ((TH1D *)Topfile->Get("Top_cjet_fakeRate"));
    TH1D *h_Top_lightfake_rate = ((TH1D *)Topfile->Get("Top_light_fakeRate"));

    TH1D *h_DY_bfake_rate = ((TH1D *)DYfile->Get("HT_bjet_fakeRate"));
    TH1D *h_DY_cfake_rate = ((TH1D *)DYfile->Get("HT_cjet_fakeRate"));
    TH1D *h_DY_lightfake_rate = ((TH1D *)DYfile->Get("HT_light_fakeRate"));

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
    const Int_t XBINS = 20;
    Double_t xEdges[XBINS + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13., 14., 15., 16.,
                                  17., 18., 19., 20., 50.};

    TH1D *h_Top_nTracks = new TH1D("h_Top_nTracks", "",XBINS, xEdges);
    h_Top_nTracks->GetXaxis()->SetTitle("");
    h_Top_nTracks->GetYaxis()->SetTitle("");
    h_Top_nTracks->Sumw2();

    TH1D *h_Top_nTracks_cut = new TH1D("h_Top_nTracks_cut", "",XBINS, xEdges);
    h_Top_nTracks_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_cut->Sumw2();

    TH1D *h_Top_nTracks_CR = new TH1D("h_Top_nTracks_CR", "",XBINS, xEdges);
    h_Top_nTracks_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_CR->Sumw2();

    TH1D *h_Top_nTracks_heavy = new TH1D("h_Top_nTracks_heavy", "",XBINS, xEdges);
    h_Top_nTracks_heavy->GetXaxis()->SetTitle("");
    h_Top_nTracks_heavy->GetYaxis()->SetTitle("");
    h_Top_nTracks_heavy->Sumw2();

    TH1D *h_Top_nTracks_heavy_cut = new TH1D("h_Top_nTracks_heavy_cut", "",XBINS, xEdges);
    h_Top_nTracks_heavy_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_heavy_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_heavy_cut->Sumw2();

    TH1D *h_Top_nTracks_heavy_CR = new TH1D("h_Top_nTracks_heavy_CR", "",XBINS, xEdges);
    h_Top_nTracks_heavy_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_heavy_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_heavy_CR->Sumw2();

    TH1D *h_Top_nTracks_bjet = new TH1D("h_Top_nTracks_bjet", "", 30, 0, 30);
    h_Top_nTracks_bjet->GetXaxis()->SetTitle("");
    h_Top_nTracks_bjet->GetYaxis()->SetTitle("");
    h_Top_nTracks_bjet->Sumw2();

    TH1D *h_Top_nTracks_bjet_cut = new TH1D("h_Top_nTracks_bjet_cut", "", 30, 0, 30);
    h_Top_nTracks_bjet_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_bjet_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_bjet_cut->Sumw2();

    TH1D *h_Top_nTracks_bjet_CR = new TH1D("h_Top_nTracks_bjet_CR", "", 30, 0, 30);
    h_Top_nTracks_bjet_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_bjet_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_bjet_CR->Sumw2();

    TH1D *h_Top_nTracks_bjet_bybin_CR = new TH1D("h_Top_nTracks_bjet_bybin_CR", "", 30, 0, 30);
    h_Top_nTracks_bjet_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_bjet_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_bjet_bybin_CR->Sumw2();

    TH1D *h_Top_nTracks_cjet = new TH1D("h_Top_nTracks_cjet", "",XBINS, xEdges);
    h_Top_nTracks_cjet->GetXaxis()->SetTitle("");
    h_Top_nTracks_cjet->GetYaxis()->SetTitle("");
    h_Top_nTracks_cjet->Sumw2();

    TH1D *h_Top_nTracks_cjet_cut = new TH1D("h_Top_nTracks_cjet_cut", "",XBINS, xEdges);
    h_Top_nTracks_cjet_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_cjet_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_cjet_cut->Sumw2();

    TH1D *h_Top_nTracks_cjet_CR = new TH1D("h_Top_nTracks_cjet_CR", "",XBINS, xEdges);
    h_Top_nTracks_cjet_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_cjet_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_cjet_CR->Sumw2();

    TH1D *h_Top_nTracks_cjet_bybin_CR = new TH1D("h_Top_nTracks_cjet_bybin_CR", "",XBINS, xEdges);
    h_Top_nTracks_cjet_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_cjet_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_cjet_bybin_CR->Sumw2();

    TH1D *h_Top_nTracks_light = new TH1D("h_Top_nTracks_light", "",XBINS, xEdges);
    h_Top_nTracks_light->GetXaxis()->SetTitle("");
    h_Top_nTracks_light->GetYaxis()->SetTitle("");
    h_Top_nTracks_light->Sumw2();

    TH1D *h_Top_nTracks_light_cut = new TH1D("h_Top_nTracks_light_cut", "",XBINS, xEdges);
    h_Top_nTracks_light_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_light_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_light_cut->Sumw2();

    TH1D *h_Top_nTracks_light_CR = new TH1D("h_Top_nTracks_light_CR", "",XBINS, xEdges);
    h_Top_nTracks_light_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_light_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_light_CR->Sumw2();

    TH1D *h_Top_nTracks_light_bybin_CR = new TH1D("h_Top_nTracks_light_bybin_CR", "",XBINS, xEdges);
    h_Top_nTracks_light_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_nTracks_light_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_nTracks_light_bybin_CR->Sumw2();

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
        double TTTo2L2Nu_eventWeight = I_TTTo2L2Nu_weight * TTTo2L2NuWeight;
        for (size_t i = 0; i < v_TTTo2L2Nu_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], h_DY_bfake_rate, (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], h_DY_cfake_rate, (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_light_bybin_CR);

            if ((*v_TTTo2L2Nu_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_light_cut);
            } // alpha cut
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
        double ST_tW_top_eventWeight = I_ST_tW_top_weight * ST_tW_topWeight;
        for (size_t i = 0; i < v_ST_tW_top_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], h_DY_bfake_rate, (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], h_DY_cfake_rate, (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_light_bybin_CR);

            if ((*v_ST_tW_top_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_light_cut);
            } // alpha cut
        }
    } // End of ST_tW_top
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
        double ST_tW_antitop_eventWeight = I_ST_tW_antitop_weight * ST_tW_antitopWeight;
        for (size_t i = 0; i < v_ST_tW_antitop_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], h_DY_bfake_rate, (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], h_DY_cfake_rate, (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_light_bybin_CR);

            if ((*v_ST_tW_antitop_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_light_cut);
            } // alpha cut
        }
    } // End of ST_tW_antitop

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
        double TTWJetsToLNu_eventWeight = I_TTWJetsToLNu_weight * TTWJetsToLNuWeight;
        for (size_t i = 0; i < v_TTWJetsToLNu_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], h_DY_bfake_rate, (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], h_DY_cfake_rate, (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_light_bybin_CR);

            if ((*v_TTWJetsToLNu_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_light_cut);
            } // alpha cut
        }
    } // End of TTWJetsToLNu

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
        double TTWJetsToQQ_eventWeight = I_TTWJetsToQQ_weight * TTWJetsToQQWeight;
        for (size_t i = 0; i < v_TTWJetsToQQ_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], h_DY_bfake_rate, (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], h_DY_cfake_rate, (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_light_bybin_CR);

            if ((*v_TTWJetsToQQ_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_light_cut);
            } // alpha cut
        }
    } // End of TTWJetsToQQ

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
        double TTZToQQ_eventWeight = I_TTZToQQ_weight * TTZToQQWeight;
        for (size_t i = 0; i < v_TTZToQQ_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], h_DY_bfake_rate, (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], h_DY_cfake_rate, (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_light_bybin_CR);

            if ((*v_TTZToQQ_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_light_cut);
            } // alpha cut
        }
    } // End of TTZToQQ

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
        double TTZToLLNuNu_eventWeight = I_TTZToLLNuNu_weight * TTZToLLNuNuWeight;
        for (size_t i = 0; i < v_TTZToLLNuNu_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], h_DY_bfake_rate, (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], h_DY_cfake_rate, (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_light_bybin_CR);

            if ((*v_TTZToLLNuNu_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_light_cut);
            } // alpha cut
        }
    } // End of TTZToLLNuNu
    h_Top_nTracks_light_cut->SetLineWidth(2);
    h_Top_nTracks_light_CR->SetLineWidth(2);
    h_Top_nTracks_light_bybin_CR->SetLineWidth(2);
    // h_Top_nTracks_light_cut->SetTitle("light jet");
    h_Top_nTracks_light_cut->GetYaxis()->SetTitle("nJet");
    h_Top_nTracks_light_bybin_CR->GetYaxis()->SetTitle("nJet");
    h_Top_nTracks_light_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    h_Top_nTracks_light_bybin_CR->GetXaxis()->SetTitle("Jet track multiplicity");
    // h_Top_nTracks_light_cut->GetXaxis()->SetTitleOffset(1.5);

    // h_Top_nTracks_light_CR->SetTitle("light jet (Top)");
    h_Top_nTracks_light_CR->GetYaxis()->SetTitle("nJet");
    h_Top_nTracks_light_CR->GetXaxis()->SetTitle("Jet track multiplicity");
    h_Top_nTracks_light_CR->GetXaxis()->SetTitleOffset(1.5);

    h_Top_nTracks_bjet_cut->SetLineWidth(2);
    h_Top_nTracks_bjet_CR->SetLineWidth(2);
    h_Top_nTracks_bjet_bybin_CR->SetLineWidth(2);
    // h_Top_nTracks_bjet_bybin_CR->SetTitle("bjet jet (Top)");
    // h_Top_nTracks_bjet_cut->SetTitle("b  jet (Top)");
    h_Top_nTracks_bjet_cut->GetYaxis()->SetTitle("nJet");
    h_Top_nTracks_bjet_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    // h_Top_nTracks_bjet_cut->GetXaxis()->SetTitleOffset(1.5);

    // h_Top_nTracks_bjet_CR->SetTitle("b jet (Top)");
    h_Top_nTracks_bjet_CR->GetYaxis()->SetTitle("nJet");
    h_Top_nTracks_bjet_CR->GetXaxis()->SetTitle("Jet track multiplicity");
    h_Top_nTracks_bjet_CR->GetXaxis()->SetTitleOffset(1.5);

    h_Top_nTracks_cjet_cut->SetLineWidth(2);
    h_Top_nTracks_cjet_CR->SetLineWidth(2);
    h_Top_nTracks_cjet_bybin_CR->SetLineWidth(2);
    // h_Top_nTracks_cjet_cut->SetTitle("c jet (Top)");
    h_Top_nTracks_cjet_cut->GetYaxis()->SetTitle("nJet");
    h_Top_nTracks_cjet_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    // h_Top_nTracks_cjet_cut->GetXaxis()->SetTitleOffset(1.5);

    h_Top_nTracks_cjet_CR->SetTitle("c jet (Top)");
    h_Top_nTracks_cjet_CR->GetYaxis()->SetTitle("nJet");
    h_Top_nTracks_cjet_CR->GetXaxis()->SetTitle("Jet track multiplicity");
    h_Top_nTracks_cjet_CR->GetXaxis()->SetTitleOffset(1.5);

    //-------------
    // Get Maximum value
    //-------------
    int lightbinmax = h_Top_nTracks_light_cut->FindLastBinAbove();
    int bjetbinmax = h_Top_nTracks_bjet_cut->FindLastBinAbove();
    int cjetbinmax = h_Top_nTracks_cjet_cut->FindLastBinAbove();
    // double lightXbinmax = h_Top_nTracks_light_cut->GetXaxis()->GetBinLabel(lightbinmax);
    // cout<<lightXbinmax<<endl;
    auto c1 = new TCanvas("c1", "", 700, 700);
    //c1->Divide(1, 2, 0.01, 0);
    //c1->cd(1);
    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);
    TH1D *Ratioresult = (TH1D *)h_Top_nTracks_light_CR->Clone("Ratioresult");

    h_Top_nTracks_cjet_CR->SetLineColor(kRed);
    h_Top_nTracks_bjet_CR->SetLineColor(kRed);
    h_Top_nTracks_light_CR->SetLineColor(kRed);
    h_Top_nTracks_bjet_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_nTracks_cjet_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_nTracks_light_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_nTracks_bjet_CR->SetLabelSize(0);
    h_Top_nTracks_cjet_CR->SetLabelSize(0);
    h_Top_nTracks_light_CR->SetLabelSize(0);
    h_Top_nTracks_light_CR->GetXaxis()->SetRangeUser(0, lightbinmax);
    //h_Top_nTracks_light_CR->Draw("hist e ");
    h_Top_nTracks_light_bybin_CR->Draw("hist e  same");
    h_Top_nTracks_light_cut->Draw("hist e same");
    
    
    
    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("Top process (light Jet)");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(h_Top_nTracks_bjet_cut, "Top SR", "l");
    //l0->AddEntry(h_Top_nTracks_bjet_CR, "Top apply fit result", "l");
    l0->AddEntry(h_Top_nTracks_bjet_bybin_CR, "Top apply DY bin by bin result", "l");
    l0->Draw();
    gStyle->SetOptStat(0);
    Ratioresult->Divide(h_Top_nTracks_light_CR, h_Top_nTracks_light_cut);
    Ratioresult->SetLineWidth(2);
    /*
    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    Ratioresult->GetYaxis()->SetTitle("Fit / MC");
    Ratioresult->GetXaxis()->SetRangeUser(0, lightbinmax);
    Ratioresult->GetYaxis()->SetRangeUser(-0.5, 2);
    Ratioresult->Draw();
    */
    /*
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
    TH1D *Ratioresult = new TH1D("Ratioresult", "", 20, 0, 20);
    Ratioresult->Sumw2();
    int nBins = h_Top_nTracks_light_CR->GetNbinsX();
    for (int i = 1; i <= nBins; i++)
    {
        double fit_content = h_Top_nTracks_light_CR->GetBinContent(i);
        double MC_content = h_Top_nTracks_light_cut->GetBinContent(i);
        double ratio_FM = (fit_content) / (MC_content);
        double Error = sqrt(pow(sqrt(fit_content) / fit_content, 2) + pow(sqrt(MC_content) / MC_content, 2));
        cout << "Error = " << Error << endl;
        cout << " i = " << i << " fit_content = " << fit_content << "MC_content = " << MC_content << " ratio_FM =  " << ratio_FM << endl;

        if (isnan(abs(Error)) || fit_content == 0)
        {
            ratio_FM = 0;
            Error = 0;
        }

        Ratioresult->SetBinContent(i, ratio_FM);
        Ratioresult->SetBinError(i, Error);
    }
    Ratioresult->SetLineWidth(2);
    Ratioresult->GetYaxis()->SetTitle("Fit / MC");
    Ratioresult->GetXaxis()->SetTitle("Jet track multiplicity");
    Ratioresult->SetLineColor(kBlue);
    Ratioresult->GetYaxis()->SetRangeUser(-5, 5);
    Ratioresult->GetXaxis()->SetRangeUser(0, 20);
    Ratioresult->Draw("E1");

    gStyle->SetOptStat(0);
    */
}
