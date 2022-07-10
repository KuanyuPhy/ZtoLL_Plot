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
#include <TCanvas.h>
#include "./../../../lib/Cross_section.h"
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
void for_inclusive_DY_sigle_flavor_jetvar(float HT, int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
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
void for_inclusive_DY_two_flavor_jetvar(float HT, int flavor1, int flavor2, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (HT < 70)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT0Weight);
        }
    }
    else if (HT >= 70 && HT < 100)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT70Weight);
        }
    }
    else if (HT >= 100 && HT < 200)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT100Weight);
        }
    }
    else if (HT >= 200 && HT < 400)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT200Weight);
        }
    }
    else if (HT >= 400 && HT < 600)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT400Weight);
        }
    }
    else if (HT >= 600 && HT < 800)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT600Weight);
        }
    }
    else if (HT >= 800 && HT < 1200)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT800Weight);
        }
    }
    else if (HT >= 1200 && HT < 2500)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT1200Weight);
        }
    }
    else if (HT >= 2500)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT2500Weight);
        }
    }
}
void for_inclusive_DY_var(float HT, float tmp, double Weight, TH1D *h_tmp)
{
    if (HT < 70)
    {
        h_tmp->Fill(tmp, Weight * HT0Weight);
    }
    else if (HT >= 70 && HT < 100)
    {
        h_tmp->Fill(tmp, Weight * HT70Weight);
    }
    else if (HT >= 100 && HT < 200)
    {
        h_tmp->Fill(tmp, Weight * HT100Weight);
    }
    else if (HT >= 200 && HT < 400)
    {
        h_tmp->Fill(tmp, Weight * HT200Weight);
    }
    else if (HT >= 400 && HT < 600)
    {
        h_tmp->Fill(tmp, Weight * HT400Weight);
    }
    else if (HT >= 600 && HT < 800)
    {
        h_tmp->Fill(tmp, Weight * HT600Weight);
    }
    else if (HT >= 800 && HT < 1200)
    {
        h_tmp->Fill(tmp, Weight * HT800Weight);
    }
    else if (HT >= 1200 && HT < 2500)
    {
        h_tmp->Fill(tmp, Weight * HT1200Weight);
    }
    else if (HT >= 2500)
    {
        h_tmp->Fill(tmp, Weight * HT2500Weight);
    }
}
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
void for_var_jet(float tmp, double Weight, TH1D *h_tmp)
{
    h_tmp->Fill(tmp, Weight);
}
void ee_HT_produce_half(TString inputfile = "/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root", TString outputfile1 = "./ee_DY_emjet_half.root")
{
    //-------------
    // Open Tree
    //-------------
    TFile *DYincli_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_DYincli_1.root");
    TFile *DYHT100_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht100_1.root");
    TFile *DYHT200_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht200_1.root");
    TFile *DYHT400_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht400_1.root");
    TFile *DYHT600_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht600_1.root");
    TFile *DYHT800_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht800_1.root");
    TFile *DYHT1200_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht1200_1.root");
    TFile *DYHT2500_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht2500_1.root");

    TH1D *h_DY_alpha[4];
    for (int i = 0; i < 4; i++)
    {
        h_DY_alpha[i] = new TH1D(Form("h_DY_alpha_%d", i + 1), "", 24, 0, 1.2);
        h_DY_alpha[i]->Sumw2();
    }

    TH1D *h_DY_IP2D = new TH1D("h_DY_IP2D", "", 200, -20, 20);
    h_DY_IP2D->GetXaxis()->SetTitle("");
    h_DY_IP2D->GetYaxis()->SetTitle("");
    h_DY_IP2D->Sumw2();

    TH1D *h_DY_Chi3Dlog = new TH1D("h_DY_Chi3Dlog", "", 100, -10, 10);
    h_DY_Chi3Dlog->GetXaxis()->SetTitle("");
    h_DY_Chi3Dlog->GetYaxis()->SetTitle("");
    h_DY_Chi3Dlog->Sumw2();

    TH1D *h_DY_Met = new TH1D("h_DY_Met", "", 10, 0, 500);
    h_DY_Met->GetXaxis()->SetTitle("");
    h_DY_Met->GetYaxis()->SetTitle("");
    h_DY_Met->Sumw2();

    //-------------
    //  nTracks
    //-------------
    const Int_t XBINS = 20;
    Double_t xEdges[XBINS + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13., 14., 15., 16.,
                                  17., 18., 19., 20., 50.};
    TH1D *h_DY_nTracks = new TH1D("h_DY_nTracks", "", XBINS, xEdges);
    h_DY_nTracks->GetXaxis()->SetTitle("");
    h_DY_nTracks->GetYaxis()->SetTitle("");
    h_DY_nTracks->Sumw2();

    TH1D *h_DY_nTracks_heavy = new TH1D("h_DY_nTracks_heavy", "", XBINS, xEdges);
    h_DY_nTracks_heavy->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy->Sumw2();

    TH1D *h_DY_nTracks_bjet = new TH1D("h_DY_nTracks_bjet", "", XBINS, xEdges);
    h_DY_nTracks_bjet->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet->Sumw2();

    TH1D *h_DY_nTracks_cjet = new TH1D("h_DY_nTracks_cjet", "", XBINS, xEdges);
    h_DY_nTracks_cjet->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet->Sumw2();

    TH1D *h_DY_nTracks_heavy_cut = new TH1D("h_DY_nTracks_heavy_cut", "", XBINS, xEdges);
    h_DY_nTracks_heavy_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_cut->Sumw2();

    TH1D *h_DY_nTracks_bjet_cut = new TH1D("h_DY_nTracks_bjet_cut", "", XBINS, xEdges);
    h_DY_nTracks_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet_cut->Sumw2();

    TH1D *h_DY_nTracks_cjet_cut = new TH1D("h_DY_nTracks_cjet_cut", "", XBINS, xEdges);
    h_DY_nTracks_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet_cut->Sumw2();

    TH1D *h_DY_nTracks_heavy_nogluon = new TH1D("h_DY_nTracks_heavy_nogluon", "", XBINS, xEdges);
    h_DY_nTracks_heavy_nogluon->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon->Sumw2();

    TH1D *h_DY_nTracks_heavy_nogluon_cut = new TH1D("h_DY_nTracks_heavy_nogluon_cut", "", XBINS, xEdges);
    h_DY_nTracks_heavy_nogluon_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon_cut->Sumw2();

    TH1D *h_DY_nTracks_light = new TH1D("h_DY_nTracks_light", "", XBINS, xEdges);
    h_DY_nTracks_light->GetXaxis()->SetTitle("");
    h_DY_nTracks_light->GetYaxis()->SetTitle("");
    h_DY_nTracks_light->Sumw2();

    TH1D *h_DY_nTracks_light_cut = new TH1D("h_DY_nTracks_light_cut", "", XBINS, xEdges);
    h_DY_nTracks_light_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_light_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_light_cut->Sumw2();

    TH1D *h_DY_nTracks_cut = new TH1D("h_DY_nTracks_cut", "", XBINS, xEdges);
    h_DY_nTracks_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_cut->Sumw2();

    //-------------
    //  JetPt
    //-------------
    TH1D *h_DY_JetPt = new TH1D("h_DY_JetPt", "", 20, 0, 1000);
    h_DY_JetPt->GetXaxis()->SetTitle("");
    h_DY_JetPt->GetYaxis()->SetTitle("");
    h_DY_JetPt->Sumw2();

    TH1D *h_DY_JetPt_heavy = new TH1D("h_DY_JetPt_heavy", "", 20, 0, 1000);
    h_DY_JetPt_heavy->GetXaxis()->SetTitle("");
    h_DY_JetPt_heavy->GetYaxis()->SetTitle("");
    h_DY_JetPt_heavy->Sumw2();

    TH1D *h_DY_JetPt_bjet = new TH1D("h_DY_JetPt_bjet", "", 20, 0, 1000);
    h_DY_JetPt_bjet->GetXaxis()->SetTitle("");
    h_DY_JetPt_bjet->GetYaxis()->SetTitle("");
    h_DY_JetPt_bjet->Sumw2();

    TH1D *h_DY_JetPt_cjet = new TH1D("h_DY_JetPt_cjet", "", 20, 0, 1000);
    h_DY_JetPt_cjet->GetXaxis()->SetTitle("");
    h_DY_JetPt_cjet->GetYaxis()->SetTitle("");
    h_DY_JetPt_cjet->Sumw2();

    TH1D *h_DY_JetPt_heavy_cut = new TH1D("h_DY_JetPt_heavy_cut", "", 20, 0, 1000);
    h_DY_JetPt_heavy_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_heavy_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_heavy_cut->Sumw2();

    TH1D *h_DY_JetPt_bjet_cut = new TH1D("h_DY_JetPt_bjet_cut", "", 20, 0, 1000);
    h_DY_JetPt_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_bjet_cut->Sumw2();

    TH1D *h_DY_JetPt_cjet_cut = new TH1D("h_DY_JetPt_cjet_cut", "", 20, 0, 1000);
    h_DY_JetPt_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_cjet_cut->Sumw2();

    TH1D *h_DY_JetPt_heavy_nogluon = new TH1D("h_DY_JetPt_heavy_nogluon", "", 20, 0, 1000);
    h_DY_JetPt_heavy_nogluon->GetXaxis()->SetTitle("");
    h_DY_JetPt_heavy_nogluon->GetYaxis()->SetTitle("");
    h_DY_JetPt_heavy_nogluon->Sumw2();

    TH1D *h_DY_JetPt_heavy_nogluon_cut = new TH1D("h_DY_JetPt_heavy_nogluon_cut", "", 20, 0, 1000);
    h_DY_JetPt_heavy_nogluon_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_heavy_nogluon_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_heavy_nogluon_cut->Sumw2();

    TH1D *h_DY_JetPt_light = new TH1D("h_DY_JetPt_light", "", 20, 0, 1000);
    h_DY_JetPt_light->GetXaxis()->SetTitle("");
    h_DY_JetPt_light->GetYaxis()->SetTitle("");
    h_DY_JetPt_light->Sumw2();

    TH1D *h_DY_JetPt_light_cut = new TH1D("h_DY_JetPt_light_cut", "", 20, 0, 1000);
    h_DY_JetPt_light_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_light_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_light_cut->Sumw2();

    TH1D *h_DY_JetPt_cut = new TH1D("h_DY_JetPt_cut", "", 20, 0, 1000);
    h_DY_JetPt_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_cut->Sumw2();

    //-------------
    //  Jet eta
    //-------------
    TH1D *h_DY_JetEta = new TH1D("h_DY_JetEta", "", 60, -3, 3);
    h_DY_JetEta->GetXaxis()->SetTitle("");
    h_DY_JetEta->GetYaxis()->SetTitle("");
    h_DY_JetEta->Sumw2();

    TH1D *h_DY_JetEta_heavy = new TH1D("h_DY_JetEta_heavy", "", 60, -3, 3);
    h_DY_JetEta_heavy->GetXaxis()->SetTitle("");
    h_DY_JetEta_heavy->GetYaxis()->SetTitle("");
    h_DY_JetEta_heavy->Sumw2();

    TH1D *h_DY_JetEta_bjet = new TH1D("h_DY_JetEta_bjet", "", 60, -3, 3);
    h_DY_JetEta_bjet->GetXaxis()->SetTitle("");
    h_DY_JetEta_bjet->GetYaxis()->SetTitle("");
    h_DY_JetEta_bjet->Sumw2();

    TH1D *h_DY_JetEta_cjet = new TH1D("h_DY_JetEta_cjet", "", 60, -3, 3);
    h_DY_JetEta_cjet->GetXaxis()->SetTitle("");
    h_DY_JetEta_cjet->GetYaxis()->SetTitle("");
    h_DY_JetEta_cjet->Sumw2();

    TH1D *h_DY_JetEta_heavy_cut = new TH1D("h_DY_JetEta_heavy_cut", "", 60, -3, 3);
    h_DY_JetEta_heavy_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_heavy_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_heavy_cut->Sumw2();

    TH1D *h_DY_JetEta_bjet_cut = new TH1D("h_DY_JetEta_bjet_cut", "", 60, -3, 3);
    h_DY_JetEta_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_bjet_cut->Sumw2();

    TH1D *h_DY_JetEta_cjet_cut = new TH1D("h_DY_JetEta_cjet_cut", "", 60, -3, 3);
    h_DY_JetEta_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_cjet_cut->Sumw2();

    TH1D *h_DY_JetEta_heavy_nogluon = new TH1D("h_DY_JetEta_heavy_nogluon", "", 60, -3, 3);
    h_DY_JetEta_heavy_nogluon->GetXaxis()->SetTitle("");
    h_DY_JetEta_heavy_nogluon->GetYaxis()->SetTitle("");
    h_DY_JetEta_heavy_nogluon->Sumw2();

    TH1D *h_DY_JetEta_heavy_nogluon_cut = new TH1D("h_DY_JetEta_heavy_nogluon_cut", "", 60, -3, 3);
    h_DY_JetEta_heavy_nogluon_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_heavy_nogluon_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_heavy_nogluon_cut->Sumw2();

    TH1D *h_DY_JetEta_light = new TH1D("h_DY_JetEta_light", "", 60, -3, 3);
    h_DY_JetEta_light->GetXaxis()->SetTitle("");
    h_DY_JetEta_light->GetYaxis()->SetTitle("");
    h_DY_JetEta_light->Sumw2();

    TH1D *h_DY_JetEta_light_cut = new TH1D("h_DY_JetEta_light_cut", "", 60, -3, 3);
    h_DY_JetEta_light_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_light_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_light_cut->Sumw2();

    TH1D *h_DY_JetEta_cut = new TH1D("h_DY_JetEta_cut", "", 60, -3, 3);
    h_DY_JetEta_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_cut->Sumw2();

    //-------------
    //  alpha_3D
    //-------------
    TH1D *h_DY_alpha3D = new TH1D("h_DY_alpha3D", "", 24, 0, 1.2);
    h_DY_alpha3D->GetXaxis()->SetTitle("");
    h_DY_alpha3D->GetYaxis()->SetTitle("");
    h_DY_alpha3D->Sumw2();

    TH1D *h_DY_alpha3D_heavy = new TH1D("h_DY_alpha3D_heavy", "", 24, 0, 1.2);
    h_DY_alpha3D_heavy->GetXaxis()->SetTitle("");
    h_DY_alpha3D_heavy->GetYaxis()->SetTitle("");
    h_DY_alpha3D_heavy->Sumw2();

    TH1D *h_DY_alpha3D_bjet = new TH1D("h_DY_alpha3D_bjet", "", 24, 0, 1.2);
    h_DY_alpha3D_bjet->GetXaxis()->SetTitle("");
    h_DY_alpha3D_bjet->GetYaxis()->SetTitle("");
    h_DY_alpha3D_bjet->Sumw2();

    TH1D *h_DY_alpha3D_cjet = new TH1D("h_DY_alpha3D_cjet", "", 24, 0, 1.2);
    h_DY_alpha3D_cjet->GetXaxis()->SetTitle("");
    h_DY_alpha3D_cjet->GetYaxis()->SetTitle("");
    h_DY_alpha3D_cjet->Sumw2();

    TH1D *h_DY_alpha3D_heavy_cut = new TH1D("h_DY_alpha3D_heavy_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_heavy_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_heavy_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_heavy_cut->Sumw2();

    TH1D *h_DY_alpha3D_bjet_cut = new TH1D("h_DY_alpha3D_bjet_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_bjet_cut->Sumw2();

    TH1D *h_DY_alpha3D_cjet_cut = new TH1D("h_DY_alpha3D_cjet_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_cjet_cut->Sumw2();

    TH1D *h_DY_alpha3D_heavy_nogluon = new TH1D("h_DY_alpha3D_heavy_nogluon", "", 24, 0, 1.2);
    h_DY_alpha3D_heavy_nogluon->GetXaxis()->SetTitle("");
    h_DY_alpha3D_heavy_nogluon->GetYaxis()->SetTitle("");
    h_DY_alpha3D_heavy_nogluon->Sumw2();

    TH1D *h_DY_alpha3D_heavy_nogluon_cut = new TH1D("h_DY_alpha3D_heavy_nogluon_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_heavy_nogluon_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_heavy_nogluon_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_heavy_nogluon_cut->Sumw2();

    TH1D *h_DY_alpha3D_light = new TH1D("h_DY_alpha3D_light", "", 24, 0, 1.2);
    h_DY_alpha3D_light->GetXaxis()->SetTitle("");
    h_DY_alpha3D_light->GetYaxis()->SetTitle("");
    h_DY_alpha3D_light->Sumw2();

    TH1D *h_DY_alpha3D_light_cut = new TH1D("h_DY_alpha3D_light_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_light_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_light_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_light_cut->Sumw2();

    TH1D *h_DY_alpha3D_cut = new TH1D("h_DY_alpha3D_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_cut->Sumw2();

    float HT;

    Int_t I_ht0_nThinJets, I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets, I_ht600_nThinJets, I_ht800_nThinJets,
        I_ht1200_nThinJets, I_ht2500_nThinJets;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight, I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    float_t f_ht0_met, f_ht70_met, f_ht100_met, f_ht200_met, f_ht400_met, f_ht600_met, f_ht800_met, f_ht1200_met, f_ht2500_met;

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

    TTree *h1;
    DYincli_1->GetObject("h1", h1);
    h1->SetBranchAddress("I_weight", &I_ht0_weight);
    h1->SetBranchAddress("f_HT", &HT);
    h1->SetBranchAddress("f_Met", &f_ht0_met);
    h1->SetBranchAddress("I_nJets", &I_ht0_nThinJets);
    h1->SetBranchAddress("v_N_Tracks", &v_ht0_nTrack);
    h1->SetBranchAddress("v_IP2D", &v_ht0_2DIP);
    h1->SetBranchAddress("v_Chi3Dlog", &v_ht0_Chi3Dlog);
    h1->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    h1->SetBranchAddress("v_fakeJetPt", &v_ht0_JetPt);
    h1->SetBranchAddress("v_fakeJetEta", &v_ht0_JetEta);
    h1->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
    h1->SetBranchAddress("v_fakeJetpartonflavor", &v_ht0_Jetpartonflavor);
    for (int evt = 0; evt < h1->GetEntries(); evt++)
    {
        h1->GetEntry(evt);
        if (f_ht0_met < 120)
        {
            continue;
        }
        //-----------------
        // Event var : Met
        //-----------------
        for_inclusive_DY_var(HT, f_ht0_met, I_ht0_weight, h_DY_Met);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
        {
            for_inclusive_DY_var(HT, (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks);
            for_inclusive_DY_var(HT, (*v_ht0_JetPt)[i], I_ht0_weight, h_DY_JetPt);
            for_inclusive_DY_var(HT, (*v_ht0_JetEta)[i], I_ht0_weight, h_DY_JetEta);
            for_inclusive_DY_var(HT, (*v_ht0_alpha)[i], I_ht0_weight, h_DY_alpha3D);
            // For b jet
            for_inclusive_DY_sigle_flavor_jetvar(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_bjet);
            for_inclusive_DY_sigle_flavor_jetvar(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], I_ht0_weight, h_DY_JetPt_bjet);
            for_inclusive_DY_sigle_flavor_jetvar(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], I_ht0_weight, h_DY_JetEta_bjet);
            for_inclusive_DY_sigle_flavor_jetvar(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], I_ht0_weight, h_DY_alpha3D_bjet);
            // For c jet
            for_inclusive_DY_sigle_flavor_jetvar(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_cjet);
            for_inclusive_DY_sigle_flavor_jetvar(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], I_ht0_weight, h_DY_JetPt_cjet);
            for_inclusive_DY_sigle_flavor_jetvar(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], I_ht0_weight, h_DY_JetEta_cjet);
            for_inclusive_DY_sigle_flavor_jetvar(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], I_ht0_weight, h_DY_alpha3D_cjet);
            // For heavy flavor
            for_inclusive_DY_two_flavor_jetvar(HT, 4, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_heavy);
            for_inclusive_DY_two_flavor_jetvar(HT, 4, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], I_ht0_weight, h_DY_JetPt_heavy);
            for_inclusive_DY_two_flavor_jetvar(HT, 4, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], I_ht0_weight, h_DY_JetEta_heavy);
            for_inclusive_DY_two_flavor_jetvar(HT, 4, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], I_ht0_weight, h_DY_alpha3D_heavy);
            // For light flavor
            for_inclusive_DY_sigle_flavor_jetvar(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_light);
            for_inclusive_DY_sigle_flavor_jetvar(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], I_ht0_weight, h_DY_JetPt_light);
            for_inclusive_DY_sigle_flavor_jetvar(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], I_ht0_weight, h_DY_JetEta_light);
            for_inclusive_DY_sigle_flavor_jetvar(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], I_ht0_weight, h_DY_alpha3D_light);
            //---------------------
            // Signal Region
            //---------------------
            if ((*v_ht0_alpha)[i] < 0.15)
            {
                for_inclusive_DY_var(HT, (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_cut);
                for_inclusive_DY_var(HT, (*v_ht0_JetPt)[i], I_ht0_weight, h_DY_JetPt_cut);
                for_inclusive_DY_var(HT, (*v_ht0_JetEta)[i], I_ht0_weight, h_DY_JetEta_cut);
                for_inclusive_DY_var(HT, (*v_ht0_alpha)[i], I_ht0_weight, h_DY_alpha3D_cut);
                // For b jet
                for_inclusive_DY_sigle_flavor_jetvar(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_bjet_cut);
                for_inclusive_DY_sigle_flavor_jetvar(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], I_ht0_weight, h_DY_JetPt_bjet_cut);
                for_inclusive_DY_sigle_flavor_jetvar(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], I_ht0_weight, h_DY_JetEta_bjet_cut);
                for_inclusive_DY_sigle_flavor_jetvar(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], I_ht0_weight, h_DY_alpha3D_bjet_cut);
                // For c jet
                for_inclusive_DY_sigle_flavor_jetvar(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_cjet_cut);
                for_inclusive_DY_sigle_flavor_jetvar(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], I_ht0_weight, h_DY_JetPt_cjet_cut);
                for_inclusive_DY_sigle_flavor_jetvar(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], I_ht0_weight, h_DY_JetEta_cjet_cut);
                for_inclusive_DY_sigle_flavor_jetvar(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], I_ht0_weight, h_DY_alpha3D_cjet_cut);
                // For heavy flavor
                for_inclusive_DY_two_flavor_jetvar(HT, 4, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_heavy_cut);
                for_inclusive_DY_two_flavor_jetvar(HT, 4, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], I_ht0_weight, h_DY_JetPt_heavy_cut);
                for_inclusive_DY_two_flavor_jetvar(HT, 4, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], I_ht0_weight, h_DY_JetEta_heavy_cut);
                for_inclusive_DY_two_flavor_jetvar(HT, 4, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], I_ht0_weight, h_DY_alpha3D_heavy_cut);
                // For light flavor
                for_inclusive_DY_sigle_flavor_jetvar(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], I_ht0_weight, h_DY_nTracks_light_cut);
                for_inclusive_DY_sigle_flavor_jetvar(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], I_ht0_weight, h_DY_JetPt_light_cut);
                for_inclusive_DY_sigle_flavor_jetvar(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], I_ht0_weight, h_DY_JetEta_light_cut);
                for_inclusive_DY_sigle_flavor_jetvar(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], I_ht0_weight, h_DY_alpha3D_light_cut);
            }
        }
        //---------------------------
        // Track var : 3DSig , 2D IP
        //---------------------------
        for (size_t i = 0; i < v_ht0_Chi3Dlog->size(); i++)
        {
            for_inclusive_DY_var(HT, (*v_ht0_Chi3Dlog)[i], I_ht0_weight, h_DY_Chi3Dlog);
            for_inclusive_DY_var(HT, (*v_ht0_2DIP)[i], I_ht0_weight, h_DY_IP2D);
        }
    } // End of DY_inclusive
    TTree *T_tree2;
    DYHT100_1->GetObject("h1", T_tree2);
    T_tree2->SetBranchAddress("I_weight", &I_ht100_weight);
    T_tree2->SetBranchAddress("I_nJets", &I_ht100_nThinJets);
    T_tree2->SetBranchAddress("v_N_Tracks", &v_ht100_nTrack);
    T_tree2->SetBranchAddress("f_Met", &f_ht100_met);
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
        if (f_ht100_met < 120)
        {
            continue;
        }
        double HT100_eventWeight = I_ht100_weight * HT100Weight;
        //-----------------
        // Event var : Met
        //-----------------
        for_var_jet(f_ht100_met, HT100_eventWeight, h_DY_Met);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_ht100_nTrack->size(); i++)
        {
            for_var_jet((*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks);
            for_var_jet((*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt);
            for_var_jet((*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta);
            for_var_jet((*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D);
            // For b jet
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_bjet);
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_bjet);
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_bjet);
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_cjet);
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_cjet);
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_cjet);
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_light);
            //---------------------
            // Signal Region
            //---------------------
            if ((*v_ht100_alpha)[i] < 0.15)
            {
                for_var_jet((*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_cut);
                for_var_jet((*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_cut);
                for_var_jet((*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_cut);
                for_var_jet((*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_cut);
                // For b jet
                for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_bjet_cut);
                for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_cjet_cut);
                for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_light_cut);
            }
        }
        //---------------------------
        // Track var : 3DSig , 2D IP
        //---------------------------
        for (size_t i = 0; i < v_ht100_Chi3Dlog->size(); i++)
        {
            for_var_jet((*v_ht100_Chi3Dlog)[i], HT100_eventWeight, h_DY_Chi3Dlog);
            for_var_jet((*v_ht100_2DIP)[i], HT100_eventWeight, h_DY_IP2D);
        }
    }
    TTree *T_tree3;
    DYHT200_1->GetObject("h1", T_tree3);
    T_tree3->SetBranchAddress("I_weight", &I_ht200_weight);
    T_tree3->SetBranchAddress("I_nJets", &I_ht200_nThinJets);
    T_tree3->SetBranchAddress("v_N_Tracks", &v_ht200_nTrack);
    T_tree3->SetBranchAddress("f_Met", &f_ht200_met);
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
        if (f_ht200_met < 120)
        {
            continue;
        }
        double HT200_eventWeight = I_ht200_weight * HT200Weight;
        //-----------------
        // Event var : Met
        //-----------------
        for_var_jet(f_ht200_met, HT200_eventWeight, h_DY_Met);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_ht200_nTrack->size(); i++)
        {
            for_var_jet((*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks);
            for_var_jet((*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt);
            for_var_jet((*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta);
            for_var_jet((*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D);
            // For b jet
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_bjet);
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_bjet);
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_bjet);
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_cjet);
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_cjet);
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_cjet);
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_light);
            //---------------------
            // Signal Region
            //---------------------
            if ((*v_ht200_alpha)[i] < 0.15)
            {
                for_var_jet((*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_cut);
                for_var_jet((*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_cut);
                for_var_jet((*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_cut);
                for_var_jet((*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_cut);
                // For b jet
                for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_bjet_cut);
                for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_cjet_cut);
                for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_light_cut);
            }
        }
        //---------------------------
        // Track var : 3DSig , 2D IP
        //---------------------------
        for (size_t i = 0; i < v_ht200_Chi3Dlog->size(); i++)
        {
            for_var_jet((*v_ht200_Chi3Dlog)[i], HT200_eventWeight, h_DY_Chi3Dlog);
            for_var_jet((*v_ht200_2DIP)[i], HT200_eventWeight, h_DY_IP2D);
        }
    }
    TTree *T_tree4;
    DYHT400_1->GetObject("h1", T_tree4);
    T_tree4->SetBranchAddress("I_weight", &I_ht400_weight);
    T_tree4->SetBranchAddress("I_nJets", &I_ht400_nThinJets);
    T_tree4->SetBranchAddress("v_N_Tracks", &v_ht400_nTrack);
    T_tree4->SetBranchAddress("f_Met", &f_ht400_met);
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
        if (f_ht400_met < 120)
        {
            continue;
        }
        double HT400_eventWeight = I_ht400_weight * HT400Weight;
        //-----------------
        // Event var : Met
        //-----------------
        for_var_jet(f_ht400_met, HT400_eventWeight, h_DY_Met);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_ht400_nTrack->size(); i++)
        {
            for_var_jet((*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks);
            for_var_jet((*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt);
            for_var_jet((*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta);
            for_var_jet((*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D);
            // For b jet
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_bjet);
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_bjet);
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_bjet);
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_cjet);
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_cjet);
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_cjet);
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_light);
            //---------------------
            // Signal Region
            //---------------------
            if ((*v_ht400_alpha)[i] < 0.15)
            {
                for_var_jet((*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_cut);
                for_var_jet((*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_cut);
                for_var_jet((*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_cut);
                for_var_jet((*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_cut);
                // For b jet
                for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_bjet_cut);
                for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_cjet_cut);
                for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_light_cut);
            }
        }
        //---------------------------
        // Track var : 3DSig , 2D IP
        //---------------------------
        for (size_t i = 0; i < v_ht400_Chi3Dlog->size(); i++)
        {
            for_var_jet((*v_ht400_Chi3Dlog)[i], HT400_eventWeight, h_DY_Chi3Dlog);
            for_var_jet((*v_ht400_2DIP)[i], HT400_eventWeight, h_DY_IP2D);
        }
    }
    TTree *T_tree5;
    DYHT600_1->GetObject("h1", T_tree5);
    T_tree5->SetBranchAddress("I_weight", &I_ht600_weight);
    T_tree5->SetBranchAddress("I_nJets", &I_ht600_nThinJets);
    T_tree5->SetBranchAddress("v_N_Tracks", &v_ht600_nTrack);
    T_tree5->SetBranchAddress("f_Met", &f_ht600_met);
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
        if (f_ht600_met < 120)
        {
            continue;
        }
        double HT600_eventWeight = I_ht600_weight * HT600Weight;
        //-----------------
        // Event var : Met
        //-----------------
        for_var_jet(f_ht600_met, HT600_eventWeight, h_DY_Met);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_ht600_nTrack->size(); i++)
        {
            for_var_jet((*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks);
            for_var_jet((*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt);
            for_var_jet((*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta);
            for_var_jet((*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D);
            // For b jet
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_bjet);
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_bjet);
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_bjet);
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_cjet);
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_cjet);
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_cjet);
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_light);
            //---------------------
            // Signal Region
            //---------------------
            if ((*v_ht600_alpha)[i] < 0.15)
            {
                for_var_jet((*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_cut);
                for_var_jet((*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_cut);
                for_var_jet((*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_cut);
                for_var_jet((*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_cut);
                // For b jet
                for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_bjet_cut);
                for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_cjet_cut);
                for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_light_cut);
            }
        }
        //---------------------------
        // Track var : 3DSig , 2D IP
        //---------------------------
        for (size_t i = 0; i < v_ht600_Chi3Dlog->size(); i++)
        {
            for_var_jet((*v_ht600_Chi3Dlog)[i], HT600_eventWeight, h_DY_Chi3Dlog);
            for_var_jet((*v_ht600_2DIP)[i], HT600_eventWeight, h_DY_IP2D);
        }
    }
    TTree *T_tree6;
    DYHT800_1->GetObject("h1", T_tree6);
    T_tree6->SetBranchAddress("I_weight", &I_ht800_weight);
    T_tree6->SetBranchAddress("I_nJets", &I_ht800_nThinJets);
    T_tree6->SetBranchAddress("v_N_Tracks", &v_ht800_nTrack);
    T_tree6->SetBranchAddress("f_Met", &f_ht800_met);
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
        if (f_ht800_met < 120)
        {
            continue;
        }
        double HT800_eventWeight = I_ht800_weight * HT800Weight;
        //-----------------
        // Event var : Met
        //-----------------
        for_var_jet(f_ht800_met, HT800_eventWeight, h_DY_Met);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_ht800_nTrack->size(); i++)
        {
            for_var_jet((*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks);
            for_var_jet((*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt);
            for_var_jet((*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta);
            for_var_jet((*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D);
            // For b jet
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_bjet);
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_bjet);
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_bjet);
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_cjet);
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_cjet);
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_cjet);
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_light);
            //---------------------
            // Signal Region
            //---------------------
            if ((*v_ht800_alpha)[i] < 0.15)
            {
                for_var_jet((*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_cut);
                for_var_jet((*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_cut);
                for_var_jet((*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_cut);
                for_var_jet((*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_cut);
                // For b jet
                for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_bjet_cut);
                for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_cjet_cut);
                for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_light_cut);
            }
        }
        //---------------------------
        // Track var : 3DSig , 2D IP
        //---------------------------
        for (size_t i = 0; i < v_ht800_Chi3Dlog->size(); i++)
        {
            for_var_jet((*v_ht800_Chi3Dlog)[i], HT800_eventWeight, h_DY_Chi3Dlog);
            for_var_jet((*v_ht800_2DIP)[i], HT800_eventWeight, h_DY_IP2D);
        }
    }
    TTree *T_tree7;
    DYHT1200_1->GetObject("h1", T_tree7);
    T_tree7->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_tree7->SetBranchAddress("I_nJets", &I_ht1200_nThinJets);
    T_tree7->SetBranchAddress("v_N_Tracks", &v_ht1200_nTrack);
    T_tree7->SetBranchAddress("f_Met", &f_ht1200_met);
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
        if (f_ht1200_met < 120)
        {
            continue;
        }
        double HT1200_eventWeight = I_ht1200_weight * HT1200Weight;
        //-----------------
        // Event var : Met
        //-----------------
        for_var_jet(f_ht1200_met, HT1200_eventWeight, h_DY_Met);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_ht1200_nTrack->size(); i++)
        {
            for_var_jet((*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks);
            for_var_jet((*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt);
            for_var_jet((*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta);
            for_var_jet((*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D);
            // For b jet
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_bjet);
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_bjet);
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_bjet);
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_cjet);
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_cjet);
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_cjet);
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_light);
            //---------------------
            // Signal Region
            //---------------------
            if ((*v_ht1200_alpha)[i] < 0.15)
            {
                for_var_jet((*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_cut);
                for_var_jet((*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_cut);
                for_var_jet((*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_cut);
                for_var_jet((*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_cut);
                // For b jet
                for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_bjet_cut);
                for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_cjet_cut);
                for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_light_cut);
            }
        }
        //---------------------------
        // Track var : 3DSig , 2D IP
        //---------------------------
        for (size_t i = 0; i < v_ht1200_Chi3Dlog->size(); i++)
        {
            for_var_jet((*v_ht1200_Chi3Dlog)[i], HT1200_eventWeight, h_DY_Chi3Dlog);
            for_var_jet((*v_ht1200_2DIP)[i], HT1200_eventWeight, h_DY_IP2D);
        }
    }

    TTree *T_tree8;
    DYHT2500_1->GetObject("h1", T_tree8);
    T_tree8->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_tree8->SetBranchAddress("I_nJets", &I_ht2500_nThinJets);
    T_tree8->SetBranchAddress("v_N_Tracks", &v_ht2500_nTrack);
    T_tree8->SetBranchAddress("f_Met", &f_ht2500_met);
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
        if (f_ht2500_met < 120)
        {
            continue;
        }
        double HT2500_eventWeight = I_ht2500_weight * HT2500Weight;
        //-----------------
        // Event var : Met
        //-----------------
        for_var_jet(f_ht2500_met, HT2500_eventWeight, h_DY_Met);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_ht2500_nTrack->size(); i++)
        {
            for_var_jet((*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks);
            for_var_jet((*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt);
            for_var_jet((*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta);
            for_var_jet((*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D);
            // For b jet
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_bjet);
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_bjet);
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_bjet);
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_cjet);
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_cjet);
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_cjet);
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_cjet);
            // For heavy flavor
            for_doubleflavor_jet(4, 0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_heavy);
            // For light flavor
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_light);
            //---------------------
            // Signal Region
            //---------------------
            if ((*v_ht2500_alpha)[i] < 0.15)
            {
                for_var_jet((*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_cut);
                for_var_jet((*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_cut);
                for_var_jet((*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_cut);
                for_var_jet((*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_cut);
                // For b jet
                for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_bjet_cut);
                for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_bjet_cut);
                for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_cjet_cut);
                for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_cjet_cut);
                for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_cjet_cut);
                // For heavy flavor
                for_doubleflavor_jet(4, 0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_heavy_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_light_cut);
            }
        }
        //---------------------------
        // Track var : 3DSig , 2D IP
        //---------------------------
        for (size_t i = 0; i < v_ht2500_Chi3Dlog->size(); i++)
        {
            for_var_jet((*v_ht2500_Chi3Dlog)[i], HT2500_eventWeight, h_DY_Chi3Dlog);
            for_var_jet((*v_ht2500_2DIP)[i], HT2500_eventWeight, h_DY_IP2D);
        }
    }
    //---------------------
    // Fake rate for nTrack
    //---------------------
    TH1D *HT_fakeRate = (TH1D *)h_DY_nTracks_cut->Clone("HT_fakeRate");
    HT_fakeRate->Divide(h_DY_nTracks_cut, h_DY_nTracks, 1, 1, "b");
    TH1D *HT_heavy_fakeRate = (TH1D *)h_DY_nTracks_heavy_cut->Clone("HT_heavy_fakeRate");
    HT_heavy_fakeRate->Divide(h_DY_nTracks_heavy_cut, h_DY_nTracks_heavy, 1, 1, "b");
    TH1D *HT_bjet_fakeRate = (TH1D *)h_DY_nTracks_bjet_cut->Clone("HT_bjet_fakeRate");
    HT_bjet_fakeRate->Divide(h_DY_nTracks_bjet_cut, h_DY_nTracks_bjet, 1, 1, "b");
    TH1D *HT_cjet_fakeRate = (TH1D *)h_DY_nTracks_cjet_cut->Clone("HT_cjet_fakeRate");
    HT_cjet_fakeRate->Divide(h_DY_nTracks_cjet_cut, h_DY_nTracks_cjet, 1, 1, "b");
    TH1D *HT_light_fakeRate = (TH1D *)h_DY_nTracks_light_cut->Clone("HT_light_fakeRate");
    HT_light_fakeRate->Divide(h_DY_nTracks_light_cut, h_DY_nTracks_light, 1, 1, "b");

    //-------------------
    // Fake rate for eta
    //-------------------
    TH1D *HT_bjet_etafakeRate = (TH1D *)h_DY_JetEta_bjet_cut->Clone("HT_bjet_etafakeRate");
    HT_bjet_etafakeRate->Divide(h_DY_JetEta_bjet_cut, h_DY_JetEta_bjet, 1, 1, "b");
    TH1D *HT_cjet_etafakeRate = (TH1D *)h_DY_JetEta_cjet_cut->Clone("HT_cjet_etafakeRate");
    HT_cjet_etafakeRate->Divide(h_DY_JetEta_cjet_cut, h_DY_JetEta_cjet, 1, 1, "b");
    TH1D *HT_light_etafakeRate = (TH1D *)h_DY_JetEta_light_cut->Clone("HT_light_etafakeRate");
    HT_light_etafakeRate->Divide(h_DY_JetEta_light_cut, h_DY_JetEta_light, 1, 1, "b");

    //-------------------
    // Fake rate for Pt
    //-------------------
    TH1D *HT_bjet_PtfakeRate = (TH1D *)h_DY_JetPt_bjet_cut->Clone("HT_bjet_PtfakeRate");
    HT_bjet_PtfakeRate->Divide(h_DY_JetPt_bjet_cut, h_DY_JetPt_bjet, 1, 1, "b");
    TH1D *HT_cjet_PtfakeRate = (TH1D *)h_DY_JetPt_cjet_cut->Clone("HT_cjet_PtfakeRate");
    HT_cjet_PtfakeRate->Divide(h_DY_JetPt_cjet_cut, h_DY_JetPt_cjet, 1, 1, "b");
    TH1D *HT_heavy_PtfakeRate = (TH1D *)h_DY_JetPt_heavy_cut->Clone("HT_heavy_PtfakeRate");
    HT_heavy_PtfakeRate->Divide(h_DY_JetPt_heavy_cut, h_DY_JetPt_heavy, 1, 1, "b");
    TH1D *HT_light_PtfakeRate = (TH1D *)h_DY_JetPt_light_cut->Clone("HT_light_PtfakeRate");
    HT_light_PtfakeRate->Divide(h_DY_JetPt_light_cut, h_DY_JetPt_light, 1, 1, "b");

    HT_bjet_fakeRate->SetTitle("Drell-Yan b fake rate");
    HT_bjet_PtfakeRate->SetTitle("Drell-Yan b fake rate");
    HT_bjet_etafakeRate->SetTitle("Drell-Yan b fake rate");
    HT_bjet_fakeRate->SetLineWidth(2);
    HT_bjet_PtfakeRate->SetLineWidth(2);
    HT_bjet_etafakeRate->SetLineWidth(2);
    HT_bjet_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_bjet_PtfakeRate->GetXaxis()->SetTitle("Jet PT");
    HT_bjet_etafakeRate->GetXaxis()->SetTitle("Jet #eta");
    HT_bjet_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_bjet_PtfakeRate->GetYaxis()->SetTitle("fake rate");
    HT_bjet_etafakeRate->GetYaxis()->SetTitle("fake rate");

    HT_cjet_fakeRate->SetTitle("Drell-Yan c fake rate");
    HT_cjet_PtfakeRate->SetTitle("Drell-Yan c fake rate");
    HT_cjet_etafakeRate->SetTitle("Drell-Yan c fake rate");
    HT_cjet_fakeRate->SetLineWidth(2);
    HT_cjet_PtfakeRate->SetLineWidth(2);
    HT_cjet_etafakeRate->SetLineWidth(2);
    HT_cjet_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_cjet_PtfakeRate->GetXaxis()->SetTitle("Jet PT");
    HT_cjet_etafakeRate->GetXaxis()->SetTitle("Jet #eta");
    HT_cjet_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_cjet_PtfakeRate->GetYaxis()->SetTitle("fake rate");
    HT_cjet_etafakeRate->GetYaxis()->SetTitle("fake rate");

    HT_light_fakeRate->SetTitle("Drell-Yan light fake rate");
    HT_light_PtfakeRate->SetTitle("Drell-Yan light fake rate");
    HT_light_etafakeRate->SetTitle("Drell-Yan light fake rate");
    HT_light_fakeRate->SetLineWidth(2);
    HT_light_PtfakeRate->SetLineWidth(2);
    HT_light_etafakeRate->SetLineWidth(2);
    HT_light_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_light_PtfakeRate->GetXaxis()->SetTitle("Jet PT");
    HT_light_etafakeRate->GetXaxis()->SetTitle("Jet #eta");
    HT_light_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_light_PtfakeRate->GetYaxis()->SetTitle("fake rate");
    HT_light_etafakeRate->GetYaxis()->SetTitle("fake rate");

    auto c1 = new TCanvas("c1", "", 700, 700);
    h_DY_Met->Draw();
    // c1->Divide(3, 3);
    /*
    HT_light_fakeRate->SetTitle("fakeRate vs track multiplicity");
    HT_light_fakeRate->SetLineColor(kGreen);
    HT_bjet_fakeRate->SetLineColor(kRed);
    HT_cjet_fakeRate->SetLineColor(kBlack);
    HT_light_fakeRate->Draw("");
    HT_bjet_fakeRate->Draw("same");
    HT_cjet_fakeRate->Draw("same");
    */
    /*
    HT_light_PtfakeRate->SetTitle("fakeRate vs Jet Pt");
    HT_light_PtfakeRate->SetLineColor(kGreen);
    HT_bjet_PtfakeRate->SetLineColor(kRed);
    HT_cjet_PtfakeRate->SetLineColor(kBlack);
    HT_light_PtfakeRate->Draw("");
    HT_bjet_PtfakeRate->Draw("same");
    HT_cjet_PtfakeRate->Draw("same");
    */
    /*
    HT_light_etafakeRate->SetTitle("fakeRate vs Jet #eta");
    HT_light_etafakeRate->SetLineColor(kGreen);
    HT_bjet_etafakeRate->SetLineColor(kRed);
    HT_cjet_etafakeRate->SetLineColor(kBlack);
    HT_light_etafakeRate->Draw("");
    HT_bjet_etafakeRate->Draw("same");
    HT_cjet_etafakeRate->Draw("same");
    gPad->SetLogy();
    gStyle->SetOptStat(0);
    TLegend *l0 = new TLegend(0.65, 0.6, 0.90, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->SetHeader("Drell-Yan process");
    l0->AddEntry(HT_light_etafakeRate, "light flavor", "l");
    l0->AddEntry(HT_bjet_etafakeRate, "b flavor", "l");
    l0->AddEntry(HT_cjet_etafakeRate, "c flavor", "l");
    */
    // l0->Draw();
    /*
    c1->cd(1);

    c1->cd(2);

    c1->cd(3);

    c1->cd(4);
    HT_light_PtfakeRate->Draw("");
    c1->cd(5);
    HT_bjet_PtfakeRate->Draw("");
    c1->cd(6);
    HT_cjet_PtfakeRate->Draw("");
    c1->cd(7);
    HT_light_etafakeRate->Draw("");
    c1->cd(8);
    HT_bjet_etafakeRate->Draw("");
    c1->cd(9);
    HT_cjet_etafakeRate->Draw("");
    */

    // gStyle->SetOptStat(0);
    //  HT_light_fakeRate->SetLineColor(kBlue);
    //  h_DY_nTracks_bjet_cut->Draw("same");

    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_DY_nTracks->Write();
    h_DY_nTracks_heavy->Write();
    h_DY_nTracks_heavy_nogluon->Write();
    h_DY_nTracks_light->Write();
    h_DY_nTracks_cut->Write();
    h_DY_nTracks_heavy_cut->Write();
    h_DY_nTracks_heavy_nogluon_cut->Write();
    h_DY_nTracks_light_cut->Write();
    HT_fakeRate->Write();
    HT_heavy_fakeRate->Write();
    HT_bjet_fakeRate->Write();
    HT_cjet_fakeRate->Write();
    h_DY_nTracks_bjet->Write();
    h_DY_nTracks_bjet_cut->Write();
    h_DY_nTracks_cjet->Write();
    h_DY_nTracks_cjet_cut->Write();
    HT_light_fakeRate->Write();
    h_DY_Met->Write();
    h_DY_Chi3Dlog->Write();
    h_DY_IP2D->Write();
    h_DY_JetPt->Write();
    h_DY_JetPt_heavy->Write();
    h_DY_JetPt_bjet->Write();
    h_DY_JetPt_cjet->Write();
    h_DY_JetPt_heavy_cut->Write();
    h_DY_JetPt_bjet_cut->Write();
    h_DY_JetPt_cjet_cut->Write();
    h_DY_JetPt_heavy_nogluon->Write();
    h_DY_JetPt_heavy_nogluon_cut->Write();
    h_DY_JetPt_light->Write();
    h_DY_JetPt_light_cut->Write();
    h_DY_JetPt_cut->Write();
    h_DY_JetEta->Write();
    h_DY_JetEta_heavy->Write();
    h_DY_JetEta_bjet->Write();
    h_DY_JetEta_cjet->Write();
    h_DY_JetEta_heavy_cut->Write();
    h_DY_JetEta_bjet_cut->Write();
    h_DY_JetEta_cjet_cut->Write();
    h_DY_JetEta_heavy_nogluon->Write();
    h_DY_JetEta_heavy_nogluon_cut->Write();
    h_DY_JetEta_light->Write();
    h_DY_JetEta_light_cut->Write();
    h_DY_JetEta_cut->Write();
    h_DY_alpha3D->Write();
    h_DY_alpha3D_heavy->Write();
    h_DY_alpha3D_bjet->Write();
    h_DY_alpha3D_cjet->Write();
    h_DY_alpha3D_heavy_cut->Write();
    h_DY_alpha3D_bjet_cut->Write();
    h_DY_alpha3D_cjet_cut->Write();
    h_DY_alpha3D_heavy_nogluon->Write();
    h_DY_alpha3D_heavy_nogluon_cut->Write();
    h_DY_alpha3D_light->Write();
    h_DY_alpha3D_light_cut->Write();
    h_DY_alpha3D_cut->Write();
    HT_bjet_etafakeRate->Write();
    HT_cjet_etafakeRate->Write();
    HT_light_etafakeRate->Write();
    HT_bjet_PtfakeRate->Write();
    HT_cjet_PtfakeRate->Write();
    HT_heavy_PtfakeRate->Write();
    HT_light_PtfakeRate->Write();
    for (int i = 0; i < 4; i++)
    {
        h_DY_alpha[i]->Write();
    }
    outfile_HT0->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_HT_produce_half();
    }
    else if (argc == 3)
    {
        ee_HT_produce_half(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}