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
using namespace std;

//---------------------------------------
// Define the HTWeight and Cross_section
//---------------------------------------
TFile *DYincli = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");
TFile *DYHT100 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
TFile *DYHT200 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
TFile *DYHT400 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
TFile *DYHT600 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
TFile *DYHT800 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
TFile *DYHT1200 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
TFile *DYHT2500 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));
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

double HT0Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT0CS / (HT0_70_event)) * 1000 * 2;
double HT70Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT70CS / (HT70_100_event)) * 1000 * 2;
double HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000 * 2;
double HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000 * 2;
double HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000 * 2;
double HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000 * 2;
double HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000 * 2;
double HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000 * 2;
double HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000 * 2;

//-------------------------------
// Valid Function
//-------------------------------
void for_inclusive_bin_by_bin_sigleflavor(float HT, int flavor, float hadronflavor, TH1D *h_fakerate, float nTrack, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        double fakerate_weight = h_fakerate->GetBinContent(nTrack) * Weight;
        if (nTrack > 20)
        {
            fakerate_weight = h_fakerate->GetBinContent(20) * Weight;
        }
        if (HT < 70)
        {
            h_tmp->Fill(nTrack, fakerate_weight * HT0Weight);
        }
        else if (HT >= 70 && HT < 100)
        {
            h_tmp->Fill(nTrack, fakerate_weight * HT70Weight);
        }
        else if (HT >= 100 && HT < 200)
        {
            h_tmp->Fill(nTrack, fakerate_weight * HT100Weight);
        }
        else if (HT >= 200 && HT < 400)
        {
            h_tmp->Fill(nTrack, fakerate_weight * HT200Weight);
        }
        else if (HT >= 400 && HT < 600)
        {
            h_tmp->Fill(nTrack, fakerate_weight * HT400Weight);
        }
        else if (HT >= 600 && HT < 800)
        {
            h_tmp->Fill(nTrack, fakerate_weight * HT600Weight);
        }
        else if (HT >= 800 && HT < 1200)
        {
            h_tmp->Fill(nTrack, fakerate_weight * HT800Weight);
        }
        else if (HT >= 1200 && HT < 2500)
        {
            h_tmp->Fill(nTrack, fakerate_weight * HT1200Weight);
        }
        else if (HT >= 2500)
        {
            h_tmp->Fill(nTrack, fakerate_weight * HT2500Weight);
        }
    }
}
void for_inclusive_DY_sample(float HT, int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (HT < 70)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT0Weight);
        }
    }
    else if (HT >= 70 && HT < 100)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT70Weight);
        }
    }
    else if (HT >= 100 && HT < 200)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT100Weight);
        }
    }
    else if (HT >= 200 && HT < 400)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT200Weight);
        }
    }
    else if (HT >= 400 && HT < 600)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT400Weight);
        }
    }
    else if (HT >= 600 && HT < 800)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT600Weight);
        }
    }
    else if (HT >= 800 && HT < 1200)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT800Weight);
        }
    }
    else if (HT >= 1200 && HT < 2500)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT1200Weight);
        }
    }
    else if (HT >= 2500)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT2500Weight);
        }
    }
}
void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void for_bin_by_bin_sigleflavor_jet(int flavor, float hadronflavor, TH1D *h_fakerate, float nTrack, double Weight, TH1D *h_tmp)
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

void for_doubleflavor_jet(int flavor1, int flavor2, int hadronflavor, float tmp, float Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

Double_t bjet_background(Double_t x)
{
    double par0 = -2.20561e-01;
    double par1 = -3.35302e-01;
    double par2 = 1.48207e-02;
    double par3 = -6.83255e-04;
    double par4 = 2.13010e-03;
    Double_t weight = (TMath::Exp(par0 + par1 * x + par2 * x * x + par3 * x * x * x) + par4);
    return weight;
}
Double_t cjet_background(Double_t x)
{
    double par0 = 3.20915e-01;
    double par1 = -9.51465e-01;
    double par2 = 5.77686e-02;
    double par3 = -1.85558e-03;
    double par4 = 1.96915e-04;
    Double_t weight = (TMath::Exp(par0 + par1 * x + par2 * x * x + par3 * x * x * x) + par4);
    return weight;
}
Double_t lightjet_background(float x)
{
    double par0 = 4.34949e-01;
    double par1 = -6.81086e-01;
    double par2 = 2.04019e-02;
    double par3 = -7.37354e-04;
    double par4 = 6.43088e-04;
    double par5 = -6.73695e-06;
    Double_t weight = (TMath::Exp(par0 + par1 * x + par2 * x * x + par3 * x * x * x) + par4 + par5 * x);
    return weight;
}

void Ratio_HT_apply_nTrack()
{
    //-------------
    // Open Tree
    //-------------
    TFile *DYincli_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_DYincli_2.root");
    TFile *DYHT100_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht100_2.root");
    TFile *DYHT200_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht200_2.root");
    TFile *DYHT400_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht400_2.root");
    TFile *DYHT600_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht600_2.root");
    TFile *DYHT800_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht800_2.root");
    TFile *DYHT1200_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht1200_2.root");
    TFile *DYHT2500_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht2500_2.root");

    TFile *DYfile = new TFile("./../ee_DY_emjet_half.root");

    TH1D *h_DY_bfake_rate = ((TH1D *)DYfile->Get("HT_bjet_fakeRate"));
    TH1D *h_DY_cfake_rate = ((TH1D *)DYfile->Get("HT_cjet_fakeRate"));
    TH1D *h_DY_lightfake_rate = ((TH1D *)DYfile->Get("HT_light_fakeRate"));

    //-------------
    //  nTracks
    //-------------

    TH1D *h_DY_nTracks = new TH1D("h_DY_nTracks", "", 50, 0, 50);
    h_DY_nTracks->GetXaxis()->SetTitle("");
    h_DY_nTracks->GetYaxis()->SetTitle("");
    h_DY_nTracks->Sumw2();

    TH1D *h_DY_nTracks_cut = new TH1D("h_DY_nTracks_cut", "", 50, 0, 50);
    h_DY_nTracks_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_cut->Sumw2();

    TH1D *h_DY_nTracks_CR = new TH1D("h_DY_nTracks_CR", "", 50, 0, 50);
    h_DY_nTracks_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_CR->Sumw2();

    TH1D *h_DY_nTracks_heavy = new TH1D("h_DY_nTracks_heavy", "", 50, 0, 50);
    h_DY_nTracks_heavy->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy->Sumw2();

    TH1D *h_DY_nTracks_heavy_cut = new TH1D("h_DY_nTracks_heavy_cut", "", 50, 0, 50);
    h_DY_nTracks_heavy_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_cut->Sumw2();

    TH1D *h_DY_nTracks_heavy_CR = new TH1D("h_DY_nTracks_heavy_CR", "", 50, 0, 50);
    h_DY_nTracks_heavy_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_CR->Sumw2();

    TH1D *h_DY_nTracks_bjet = new TH1D("h_DY_nTracks_bjet", "", 30, 0, 30);
    h_DY_nTracks_bjet->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet->Sumw2();

    TH1D *h_DY_nTracks_bjet_cut = new TH1D("h_DY_nTracks_bjet_cut", "", 30, 0, 30);
    h_DY_nTracks_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet_cut->Sumw2();

    TH1D *h_DY_nTracks_bjet_CR = new TH1D("h_DY_nTracks_bjet_CR", "", 30, 0, 30);
    h_DY_nTracks_bjet_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet_CR->Sumw2();

    TH1D *h_DY_nTracks_bjet_bybin_CR = new TH1D("h_DY_nTracks_bjet_bybin_CR", "", 30, 0, 30);
    h_DY_nTracks_bjet_bybin_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet_bybin_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet_bybin_CR->Sumw2();

    TH1D *h_DY_nTracks_cjet = new TH1D("h_DY_nTracks_cjet", "", 50, 0, 50);
    h_DY_nTracks_cjet->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet->Sumw2();

    TH1D *h_DY_nTracks_cjet_cut = new TH1D("h_DY_nTracks_cjet_cut", "", 50, 0, 50);
    h_DY_nTracks_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet_cut->Sumw2();

    TH1D *h_DY_nTracks_cjet_CR = new TH1D("h_DY_nTracks_cjet_CR", "", 50, 0, 50);
    h_DY_nTracks_cjet_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet_CR->Sumw2();

    TH1D *h_DY_nTracks_cjet_bybin_CR = new TH1D("h_DY_nTracks_cjet_bybin_CR", "", 50, 0, 50);
    h_DY_nTracks_cjet_bybin_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet_bybin_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet_bybin_CR->Sumw2();

    TH1D *h_DY_nTracks_light = new TH1D("h_DY_nTracks_light", "", 50, 0, 50);
    h_DY_nTracks_light->GetXaxis()->SetTitle("");
    h_DY_nTracks_light->GetYaxis()->SetTitle("");
    h_DY_nTracks_light->Sumw2();

    TH1D *h_DY_nTracks_light_cut = new TH1D("h_DY_nTracks_light_cut", "", 50, 0, 50);
    h_DY_nTracks_light_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_light_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_light_cut->Sumw2();

    TH1D *h_DY_nTracks_light_CR = new TH1D("h_DY_nTracks_light_CR", "", 50, 0, 50);
    h_DY_nTracks_light_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_light_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_light_CR->Sumw2();

    TH1D *h_DY_nTracks_light_bybin_CR = new TH1D("h_DY_nTracks_light_bybin_CR", "", 50, 0, 50);
    h_DY_nTracks_light_bybin_CR->GetXaxis()->SetTitle("");
    h_DY_nTracks_light_bybin_CR->GetYaxis()->SetTitle("");
    h_DY_nTracks_light_bybin_CR->Sumw2();

    float HT;

    Int_t I_ht0_nThinJets, I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets, I_ht600_nThinJets, I_ht800_nThinJets,
        I_ht1200_nThinJets, I_ht2500_nThinJets;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight, I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    float_t I_ht0_met, I_ht70_met, I_ht100_met, I_ht200_met, I_ht400_met, I_ht600_met, I_ht800_met, I_ht1200_met, I_ht2500_met;

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
    vector<float> *v_ht100_2DIP = new vector<float>();
    vector<float> *v_ht200_2DIP = new vector<float>();
    vector<float> *v_ht400_2DIP = new vector<float>();
    vector<float> *v_ht600_2DIP = new vector<float>();
    vector<float> *v_ht800_2DIP = new vector<float>();
    vector<float> *v_ht1200_2DIP = new vector<float>();
    vector<float> *v_ht2500_2DIP = new vector<float>();

    v_ht0_2DIP->clear();
    v_ht100_2DIP->clear();
    v_ht200_2DIP->clear();
    v_ht400_2DIP->clear();
    v_ht600_2DIP->clear();
    v_ht800_2DIP->clear();
    v_ht1200_2DIP->clear();
    v_ht2500_2DIP->clear();

    vector<float> *v_ht0_nTrack = new vector<float>();
    vector<float> *v_ht100_nTrack = new vector<float>();
    vector<float> *v_ht200_nTrack = new vector<float>();
    vector<float> *v_ht400_nTrack = new vector<float>();
    vector<float> *v_ht600_nTrack = new vector<float>();
    vector<float> *v_ht800_nTrack = new vector<float>();
    vector<float> *v_ht1200_nTrack = new vector<float>();
    vector<float> *v_ht2500_nTrack = new vector<float>();

    v_ht0_nTrack->clear();
    v_ht100_nTrack->clear();
    v_ht200_nTrack->clear();
    v_ht400_nTrack->clear();
    v_ht600_nTrack->clear();
    v_ht800_nTrack->clear();
    v_ht1200_nTrack->clear();
    v_ht2500_nTrack->clear();

    vector<float> *v_ht0_JetPt = new vector<float>();
    vector<float> *v_ht100_JetPt = new vector<float>();
    vector<float> *v_ht200_JetPt = new vector<float>();
    vector<float> *v_ht400_JetPt = new vector<float>();
    vector<float> *v_ht600_JetPt = new vector<float>();
    vector<float> *v_ht800_JetPt = new vector<float>();
    vector<float> *v_ht1200_JetPt = new vector<float>();
    vector<float> *v_ht2500_JetPt = new vector<float>();

    v_ht0_JetPt->clear();
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
    vector<float> *v_ht100_Jethadronflavor = new vector<float>();
    vector<float> *v_ht200_Jethadronflavor = new vector<float>();
    vector<float> *v_ht400_Jethadronflavor = new vector<float>();
    vector<float> *v_ht600_Jethadronflavor = new vector<float>();
    vector<float> *v_ht800_Jethadronflavor = new vector<float>();
    vector<float> *v_ht1200_Jethadronflavor = new vector<float>();
    vector<float> *v_ht2500_Jethadronflavor = new vector<float>();

    v_ht0_Jethadronflavor->clear();
    v_ht100_Jethadronflavor->clear();
    v_ht200_Jethadronflavor->clear();
    v_ht400_Jethadronflavor->clear();
    v_ht600_Jethadronflavor->clear();
    v_ht800_Jethadronflavor->clear();
    v_ht1200_Jethadronflavor->clear();
    v_ht2500_Jethadronflavor->clear();

    vector<float> *v_ht0_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht100_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht200_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht400_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht600_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht800_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht1200_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht2500_Jetpartonflavor = new vector<float>();

    v_ht0_Jetpartonflavor->clear();
    v_ht100_Jetpartonflavor->clear();
    v_ht200_Jetpartonflavor->clear();
    v_ht400_Jetpartonflavor->clear();
    v_ht600_Jetpartonflavor->clear();
    v_ht800_Jetpartonflavor->clear();
    v_ht1200_Jetpartonflavor->clear();
    v_ht2500_Jetpartonflavor->clear();

    TTree *Treeh0;
    DYincli_2->GetObject("h2", Treeh0);
    Treeh0->SetBranchAddress("I_weight", &I_ht0_weight);
    Treeh0->SetBranchAddress("f_HT", &HT);
    Treeh0->SetBranchAddress("f_Met", &I_ht0_met);
    Treeh0->SetBranchAddress("I_nJets", &I_ht0_nThinJets);
    Treeh0->SetBranchAddress("v_N_Tracks", &v_ht0_nTrack);
    Treeh0->SetBranchAddress("v_IP2D", &v_ht0_2DIP);
    Treeh0->SetBranchAddress("v_Chi3Dlog", &v_ht0_Chi3Dlog);
    Treeh0->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    Treeh0->SetBranchAddress("v_fakeJetPt", &v_ht0_JetPt);
    Treeh0->SetBranchAddress("v_fakeJetEta", &v_ht0_JetEta);
    Treeh0->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
    Treeh0->SetBranchAddress("v_fakeJetpartonflavor", &v_ht0_Jetpartonflavor);
    for (int evt = 0; evt < Treeh0->GetEntries(); evt++)
    {
        Treeh0->GetEntry(evt);
        for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
        {
            for_inclusive_DY_sample(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_bjet);
            for_inclusive_DY_sample(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_cjet);
            for_inclusive_DY_sample(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_inclusive_bin_by_bin_sigleflavor(HT, 5, (*v_ht0_Jethadronflavor)[i], h_DY_bfake_rate, (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_bjet_bybin_CR);
            for_inclusive_bin_by_bin_sigleflavor(HT, 4, (*v_ht0_Jethadronflavor)[i], h_DY_cfake_rate, (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_cjet_bybin_CR);
            for_inclusive_bin_by_bin_sigleflavor(HT, 0, (*v_ht0_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_light_bybin_CR);
            //----------------------------
            // apply fit fake rate curve
            //----------------------------
            double rootfit_bjetWeight = bjet_background((*v_ht0_nTrack)[i]);
            double rootfit_cjetWeight = cjet_background((*v_ht0_nTrack)[i]);
            double rootfit_lightjetWeight = lightjet_background((*v_ht0_nTrack)[i]);
            for_inclusive_DY_sample(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], rootfit_bjetWeight * I_ht0_weight, h_DY_nTracks_bjet_CR);
            for_inclusive_DY_sample(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], rootfit_cjetWeight * I_ht0_weight, h_DY_nTracks_cjet_CR);
            for_inclusive_DY_sample(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], rootfit_lightjetWeight * I_ht0_weight, h_DY_nTracks_light_CR);
            //----------------------------
            // Signal Region
            //----------------------------
            if ((*v_ht0_alpha)[i] < 0.15)
            {
                for_inclusive_DY_sample(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_bjet_cut);
                for_inclusive_DY_sample(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_cjet_cut);
                for_inclusive_DY_sample(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_light_cut);
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
    T_tree2->SetBranchAddress("v_fakeJetPt", &v_ht100_JetPt);
    T_tree2->SetBranchAddress("v_fakeJetEta", &v_ht100_JetEta);
    T_tree2->SetBranchAddress("v_fakeJethadronflavor", &v_ht100_Jethadronflavor);
    T_tree2->SetBranchAddress("v_fakeJetpartonflavor", &v_ht100_Jetpartonflavor);
    for (int evt = 0; evt < T_tree2->GetEntries(); evt++)
    {
        T_tree2->GetEntry(evt);
        if (I_ht100_weight != 1)
        {
            cout << "bug" << endl;
        }
        for (size_t i = 0; i < v_ht100_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100Weight, h_DY_nTracks_bjet);
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100Weight, h_DY_nTracks_cjet);
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100Weight, h_DY_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_ht100_Jethadronflavor)[i], h_DY_bfake_rate, (*v_ht100_nTrack)[i], I_ht100_weight * HT100Weight, h_DY_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_ht100_Jethadronflavor)[i], h_DY_cfake_rate, (*v_ht100_nTrack)[i], I_ht100_weight * HT100Weight, h_DY_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_ht100_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_ht100_nTrack)[i], I_ht100_weight * HT100Weight, h_DY_nTracks_light_bybin_CR);
            //----------------------------
            // apply fit fake rate curve
            //----------------------------
            double rootfit_bjetWeight = bjet_background((*v_ht100_nTrack)[i]) * HT100Weight;
            double rootfit_cjetWeight = cjet_background((*v_ht100_nTrack)[i]) * HT100Weight;
            double rootfit_lightjetWeight = lightjet_background((*v_ht100_nTrack)[i]) * HT100Weight;
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], rootfit_bjetWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], rootfit_cjetWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], rootfit_lightjetWeight, h_DY_nTracks_light_CR);
            //----------------------------
            // Signal Region
            //----------------------------
            if ((*v_ht100_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100Weight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100Weight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100Weight, h_DY_nTracks_light_cut);
            }
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
    T_tree3->SetBranchAddress("v_fakeJetPt", &v_ht200_JetPt);
    T_tree3->SetBranchAddress("v_fakeJetEta", &v_ht200_JetEta);
    T_tree3->SetBranchAddress("v_fakeJethadronflavor", &v_ht200_Jethadronflavor);
    T_tree3->SetBranchAddress("v_fakeJetpartonflavor", &v_ht200_Jetpartonflavor);
    for (int evt = 0; evt < T_tree3->GetEntries(); evt++)
    {
        T_tree3->GetEntry(evt);
        if (I_ht200_weight != 1)
        {
            cout << "bug" << endl;
        }
        for (size_t i = 0; i < v_ht200_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200Weight, h_DY_nTracks_bjet);
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200Weight, h_DY_nTracks_cjet);
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200Weight, h_DY_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_ht200_Jethadronflavor)[i], h_DY_bfake_rate, (*v_ht200_nTrack)[i], I_ht200_weight * HT200Weight, h_DY_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_ht200_Jethadronflavor)[i], h_DY_cfake_rate, (*v_ht200_nTrack)[i], I_ht200_weight * HT200Weight, h_DY_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_ht200_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_ht200_nTrack)[i], I_ht200_weight * HT200Weight, h_DY_nTracks_light_bybin_CR);
            //----------------------------
            // apply fit fake rate curve
            //----------------------------
            double rootfit_bjetWeight = bjet_background((*v_ht200_nTrack)[i]) * HT200Weight;
            double rootfit_cjetWeight = cjet_background((*v_ht200_nTrack)[i]) * HT200Weight;
            double rootfit_lightjetWeight = lightjet_background((*v_ht200_nTrack)[i]) * HT200Weight;
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], rootfit_bjetWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], rootfit_cjetWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], rootfit_lightjetWeight, h_DY_nTracks_light_CR);
            //----------------------------
            // Signal Region
            //----------------------------
            if ((*v_ht200_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200Weight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200Weight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200Weight, h_DY_nTracks_light_cut);
            }
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
    T_tree4->SetBranchAddress("v_fakeJetPt", &v_ht400_JetPt);
    T_tree4->SetBranchAddress("v_fakeJetEta", &v_ht400_JetEta);
    T_tree4->SetBranchAddress("v_fakeJethadronflavor", &v_ht400_Jethadronflavor);
    T_tree4->SetBranchAddress("v_fakeJetpartonflavor", &v_ht400_Jetpartonflavor);
    for (int evt = 0; evt < T_tree4->GetEntries(); evt++)
    {
        T_tree4->GetEntry(evt);
        if (I_ht400_weight != 1)
        {
            cout << "bug" << endl;
        }
        for (size_t i = 0; i < v_ht400_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400Weight, h_DY_nTracks_bjet);
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400Weight, h_DY_nTracks_cjet);
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400Weight, h_DY_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_ht400_Jethadronflavor)[i], h_DY_bfake_rate, (*v_ht400_nTrack)[i], I_ht400_weight * HT400Weight, h_DY_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_ht400_Jethadronflavor)[i], h_DY_cfake_rate, (*v_ht400_nTrack)[i], I_ht400_weight * HT400Weight, h_DY_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_ht400_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_ht400_nTrack)[i], I_ht400_weight * HT400Weight, h_DY_nTracks_light_bybin_CR);
            //----------------------------
            // apply fit fake rate curve
            //----------------------------
            double rootfit_bjetWeight = bjet_background((*v_ht400_nTrack)[i]) * HT400Weight;
            double rootfit_cjetWeight = cjet_background((*v_ht400_nTrack)[i]) * HT400Weight;
            double rootfit_lightjetWeight = lightjet_background((*v_ht400_nTrack)[i]) * HT400Weight;
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], rootfit_bjetWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], rootfit_cjetWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], rootfit_lightjetWeight, h_DY_nTracks_light_CR);
            //----------------------------
            // Signal Region
            //----------------------------
            if ((*v_ht400_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400Weight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400Weight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400Weight, h_DY_nTracks_light_cut);
            }
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
    T_tree5->SetBranchAddress("v_fakeJetPt", &v_ht600_JetPt);
    T_tree5->SetBranchAddress("v_fakeJetEta", &v_ht600_JetEta);
    T_tree5->SetBranchAddress("v_fakeJethadronflavor", &v_ht600_Jethadronflavor);
    T_tree5->SetBranchAddress("v_fakeJetpartonflavor", &v_ht600_Jetpartonflavor);
    for (int evt = 0; evt < T_tree5->GetEntries(); evt++)
    {
        T_tree5->GetEntry(evt);
        if (I_ht600_weight != 1)
        {
            cout << "bug" << endl;
        }
        for (size_t i = 0; i < v_ht600_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600Weight, h_DY_nTracks_bjet);
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600Weight, h_DY_nTracks_cjet);
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600Weight, h_DY_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_ht600_Jethadronflavor)[i], h_DY_bfake_rate, (*v_ht600_nTrack)[i], I_ht600_weight * HT600Weight, h_DY_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_ht600_Jethadronflavor)[i], h_DY_cfake_rate, (*v_ht600_nTrack)[i], I_ht600_weight * HT600Weight, h_DY_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_ht600_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_ht600_nTrack)[i], I_ht600_weight * HT600Weight, h_DY_nTracks_light_bybin_CR);
            //----------------------------
            // apply fit fake rate curve
            //----------------------------
            double rootfit_bjetWeight = bjet_background((*v_ht600_nTrack)[i]) * HT600Weight;
            double rootfit_cjetWeight = cjet_background((*v_ht600_nTrack)[i]) * HT600Weight;
            double rootfit_lightjetWeight = lightjet_background((*v_ht600_nTrack)[i]) * HT600Weight;
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], rootfit_bjetWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], rootfit_cjetWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], rootfit_lightjetWeight, h_DY_nTracks_light_CR);
            //----------------------------
            // Signal Region
            //----------------------------
            if ((*v_ht600_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600Weight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600Weight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600Weight, h_DY_nTracks_light_cut);
            }
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
    T_tree6->SetBranchAddress("v_fakeJetPt", &v_ht800_JetPt);
    T_tree6->SetBranchAddress("v_fakeJetEta", &v_ht800_JetEta);
    T_tree6->SetBranchAddress("v_fakeJethadronflavor", &v_ht800_Jethadronflavor);
    T_tree6->SetBranchAddress("v_fakeJetpartonflavor", &v_ht800_Jetpartonflavor);
    for (int evt = 0; evt < T_tree6->GetEntries(); evt++)
    {
        T_tree6->GetEntry(evt);
        if (I_ht800_weight != 1)
        {
            cout << "bug" << endl;
        }
        for (size_t i = 0; i < v_ht800_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800Weight, h_DY_nTracks_bjet);
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800Weight, h_DY_nTracks_cjet);
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800Weight, h_DY_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_ht800_Jethadronflavor)[i], h_DY_bfake_rate, (*v_ht800_nTrack)[i], I_ht800_weight * HT800Weight, h_DY_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_ht800_Jethadronflavor)[i], h_DY_cfake_rate, (*v_ht800_nTrack)[i], I_ht800_weight * HT800Weight, h_DY_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_ht800_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_ht800_nTrack)[i], I_ht800_weight * HT800Weight, h_DY_nTracks_light_bybin_CR);
            //----------------------------
            // apply fit fake rate curve
            //----------------------------
            double rootfit_bjetWeight = bjet_background((*v_ht800_nTrack)[i]) * HT800Weight;
            double rootfit_cjetWeight = cjet_background((*v_ht800_nTrack)[i]) * HT800Weight;
            double rootfit_lightjetWeight = lightjet_background((*v_ht800_nTrack)[i]) * HT800Weight;
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], rootfit_bjetWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], rootfit_cjetWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], rootfit_lightjetWeight, h_DY_nTracks_light_CR);
            //----------------------------
            // Signal Region
            //----------------------------
            if ((*v_ht800_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800Weight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800Weight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800Weight, h_DY_nTracks_light_cut);
            }
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
    T_tree7->SetBranchAddress("v_fakeJetPt", &v_ht1200_JetPt);
    T_tree7->SetBranchAddress("v_fakeJetEta", &v_ht1200_JetEta);
    T_tree7->SetBranchAddress("v_fakeJethadronflavor", &v_ht1200_Jethadronflavor);
    T_tree7->SetBranchAddress("v_fakeJetpartonflavor", &v_ht1200_Jetpartonflavor);
    for (int evt = 0; evt < T_tree7->GetEntries(); evt++)
    {
        T_tree7->GetEntry(evt);
        if (I_ht1200_weight != 1)
        {
            cout << "bug" << endl;
        }
        for (size_t i = 0; i < v_ht1200_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200Weight, h_DY_nTracks_bjet);
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200Weight, h_DY_nTracks_cjet);
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200Weight, h_DY_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], h_DY_bfake_rate, (*v_ht1200_nTrack)[i], I_ht1200_weight * HT1200Weight, h_DY_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], h_DY_cfake_rate, (*v_ht1200_nTrack)[i], I_ht1200_weight * HT1200Weight, h_DY_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_ht1200_nTrack)[i], I_ht1200_weight * HT1200Weight, h_DY_nTracks_light_bybin_CR);
            //----------------------------
            // apply fit fake rate curve
            //----------------------------
            double rootfit_bjetWeight = bjet_background((*v_ht1200_nTrack)[i]) * HT1200Weight;
            double rootfit_cjetWeight = cjet_background((*v_ht1200_nTrack)[i]) * HT1200Weight;
            double rootfit_lightjetWeight = lightjet_background((*v_ht1200_nTrack)[i]) * HT1200Weight;
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], rootfit_bjetWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], rootfit_cjetWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], rootfit_lightjetWeight, h_DY_nTracks_light_CR);
            //----------------------------
            // Signal Region
            //----------------------------
            if ((*v_ht1200_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200Weight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200Weight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200Weight, h_DY_nTracks_light_cut);
            }
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
    T_tree8->SetBranchAddress("v_fakeJetPt", &v_ht2500_JetPt);
    T_tree8->SetBranchAddress("v_fakeJetEta", &v_ht2500_JetEta);
    T_tree8->SetBranchAddress("v_fakeJethadronflavor", &v_ht2500_Jethadronflavor);
    T_tree8->SetBranchAddress("v_fakeJetpartonflavor", &v_ht2500_Jetpartonflavor);
    for (int evt = 0; evt < T_tree8->GetEntries(); evt++)
    {
        T_tree8->GetEntry(evt);
        if (I_ht2500_weight != 1)
        {
            cout << "bug" << endl;
        }
        for (size_t i = 0; i < v_ht2500_nTrack->size(); i++)
        {
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500Weight, h_DY_nTracks_bjet);
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500Weight, h_DY_nTracks_cjet);
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500Weight, h_DY_nTracks_light);
            //----------------------------
            // apply bin by bin fake rate
            //----------------------------
            for_bin_by_bin_sigleflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], h_DY_bfake_rate, (*v_ht2500_nTrack)[i], I_ht2500_weight * HT2500Weight, h_DY_nTracks_bjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], h_DY_cfake_rate, (*v_ht2500_nTrack)[i], I_ht2500_weight * HT2500Weight, h_DY_nTracks_cjet_bybin_CR);
            for_bin_by_bin_sigleflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], h_DY_lightfake_rate, (*v_ht2500_nTrack)[i], I_ht2500_weight * HT2500Weight, h_DY_nTracks_light_bybin_CR);
            //----------------------------
            // apply fit fake rate curve
            //----------------------------
            double rootfit_bjetWeight = bjet_background((*v_ht2500_nTrack)[i]) * HT2500Weight;
            double rootfit_cjetWeight = cjet_background((*v_ht2500_nTrack)[i]) * HT2500Weight;
            double rootfit_lightjetWeight = lightjet_background((*v_ht2500_nTrack)[i]) * HT2500Weight;
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], rootfit_bjetWeight, h_DY_nTracks_bjet_CR);
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], rootfit_cjetWeight, h_DY_nTracks_cjet_CR);
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], rootfit_lightjetWeight, h_DY_nTracks_light_CR);
            //----------------------------
            // Signal Region
            //----------------------------
            if ((*v_ht2500_alpha)[i] < 0.15)
            {
                for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500Weight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500Weight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500Weight, h_DY_nTracks_light_cut);
            }
        }
    }
    h_DY_nTracks_light_cut->SetLineWidth(2);
    h_DY_nTracks_light_CR->SetLineWidth(2);
    h_DY_nTracks_light_bybin_CR->SetLineWidth(2);
    // h_DY_nTracks_light_cut->SetTitle("light jet (DY)");
    h_DY_nTracks_light_cut->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_light_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    // h_DY_nTracks_light_cut->GetXaxis()->SetTitleOffset(1.5);

    // h_DY_nTracks_light_CR->SetTitle("light jet (DY)");
    h_DY_nTracks_light_CR->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_light_CR->GetXaxis()->SetTitle("Jet track multiplicity");
    h_DY_nTracks_light_CR->GetXaxis()->SetTitleOffset(1.5);

    h_DY_nTracks_bjet_cut->SetLineWidth(2);
    h_DY_nTracks_bjet_CR->SetLineWidth(2);
    h_DY_nTracks_bjet_bybin_CR->SetLineWidth(2);
    h_DY_nTracks_bjet_bybin_CR->SetTitle("bjet jet (DY)");
    // h_DY_nTracks_bjet_cut->SetTitle("bjet jet (DY)");
    h_DY_nTracks_bjet_cut->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_bjet_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    // h_DY_nTracks_bjet_cut->GetXaxis()->SetTitleOffset(1.5);

    // h_DY_nTracks_bjet_CR->SetTitle("bjet jet (DY)");
    h_DY_nTracks_bjet_CR->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_bjet_CR->GetXaxis()->SetTitle("Jet track multiplicity");
    h_DY_nTracks_bjet_CR->GetXaxis()->SetTitleOffset(1.5);

    h_DY_nTracks_cjet_cut->SetLineWidth(2);
    h_DY_nTracks_cjet_CR->SetLineWidth(2);
    h_DY_nTracks_cjet_bybin_CR->SetLineWidth(2);
    // h_DY_nTracks_cjet_cut->SetTitle("cjet jet (DY)");
    h_DY_nTracks_cjet_cut->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_cjet_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    // h_DY_nTracks_cjet_cut->GetXaxis()->SetTitleOffset(1.5);

    // h_DY_nTracks_cjet_CR->SetTitle("cjet jet (DY)");
    h_DY_nTracks_cjet_CR->GetYaxis()->SetTitle("nJet");
    h_DY_nTracks_cjet_CR->GetXaxis()->SetTitle("Jet track multiplicity");
    h_DY_nTracks_cjet_CR->GetXaxis()->SetTitleOffset(1.5);

    //-------------
    // Get Maximum value
    //-------------
    int lightbinmax = h_DY_nTracks_light_cut->FindLastBinAbove();
    int bjetbinmax = h_DY_nTracks_bjet_CR->FindLastBinAbove();
    int cjetbinmax = h_DY_nTracks_cjet_cut->FindLastBinAbove();

    auto c1 = new TCanvas("c1", "", 700, 700);
    c1->Divide(1, 2, 0.01, 0);
    c1->cd(1);
    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);
    TH1D *Ratioresult = (TH1D *)h_DY_nTracks_light_CR->Clone("Ratioresult");
    h_DY_nTracks_bjet_CR->SetLabelSize(0);
    h_DY_nTracks_cjet_CR->SetLabelSize(0);
    h_DY_nTracks_light_CR->SetLabelSize(0);
    h_DY_nTracks_cjet_CR->SetLineColor(kRed);
    h_DY_nTracks_bjet_CR->SetLineColor(kRed);
    h_DY_nTracks_light_CR->SetLineColor(kRed);
    h_DY_nTracks_bjet_bybin_CR->SetLineColor(kGreen + 3);
    h_DY_nTracks_cjet_bybin_CR->SetLineColor(kGreen + 3);
    h_DY_nTracks_light_bybin_CR->SetLineColor(kGreen + 3);
    h_DY_nTracks_bjet_CR->GetXaxis()->SetRangeUser(0, 30);
    h_DY_nTracks_light_cut->GetXaxis()->SetRangeUser(0, lightbinmax + 1);
    h_DY_nTracks_light_CR->GetXaxis()->SetRangeUser(0, lightbinmax);
    h_DY_nTracks_bjet_CR->GetXaxis()->SetRangeUser(0, bjetbinmax);
    h_DY_nTracks_cjet_CR->GetXaxis()->SetRangeUser(0, cjetbinmax);
    // h_DY_nTracks_bjet_cut->SetLabelSize(0);
    h_DY_nTracks_light_CR->Draw("hist e ");
    h_DY_nTracks_light_cut->Draw("hist e same");
    h_DY_nTracks_light_bybin_CR->Draw("hist e same");

    TLegend *l0 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l0->SetHeader("Drell-Yan (light Jet)");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(h_DY_nTracks_cjet_cut, "Drell-Yan SR", "l");
    l0->AddEntry(h_DY_nTracks_cjet_CR, "Drell-Yan apply fit result", "l");
    l0->AddEntry(h_DY_nTracks_cjet_bybin_CR, "Drell-Yan apply bin by bin result", "l");
    l0->Draw();
    gStyle->SetOptStat(0);

    Ratioresult->Divide(h_DY_nTracks_light_CR, h_DY_nTracks_light_cut);
    Ratioresult->SetLineWidth(2);
    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    // Ratioresult->SetLabelSize(1);
    Ratioresult->GetYaxis()->SetTitle("Fit / MC");
    Ratioresult->GetXaxis()->SetRangeUser(0, lightbinmax);
    Ratioresult->GetYaxis()->SetRangeUser(-0.5, 2);
    Ratioresult->Draw();
    /*TH1D *Ratioresult = new TH1D("Ratioresult", "", 50, 0, 50);
    Ratioresult->Sumw2();
    int nBins = h_DY_nTracks_bjet_cut->GetNbinsX();
    for (int i = 1; i <= nBins; i++)
    {
        double fit_content = h_DY_nTracks_bjet_CR->GetBinContent(i);
        double MC_content = h_DY_nTracks_bjet_cut->GetBinContent(i);
        double ratio_FM = (fit_content) / (MC_content);
        double Error = sqrt(pow(sqrt(fit_content) / fit_content, 2) + pow(sqrt(MC_content) / MC_content, 2));
        if (isnan(abs(Error)) || fit_content == 0)
        {
            ratio_FM = 0;
            Error = 0;
        }

        // cout << " i = " << i << " fit_content = " << fit_content << "MC_content = " << MC_content << " ratio_FM =  " << ratio_FM << endl;
        Ratioresult->SetBinContent(i, ratio_FM);
        Ratioresult->SetBinError(i, Error);
    }
    Ratioresult->GetXaxis()->SetRangeUser(0, bjetbinmax);
    Ratioresult->GetYaxis()->SetRangeUser(-2,2);
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
}
