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

void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, float Weight, TH1F *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, int flavor2, float hadronflavor, float tmp, float Weight, TH1F *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

void ee_HT_produce_half(TString inputfile = "./../../../../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root", TString outputfile1 = "./ee_DY_emjet_half.root")
{
    TFile *DYincli = TFile::Open(inputfile);
    TFile *DYHT100 = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

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

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));

    int HT0_70_event = h_HT_eventCout->GetBinContent(2);
    int HT70_100_event = h_HT_eventCout->GetBinContent(3);
    int HT100_200_event = h_HT_eventCout->GetBinContent(4);
    int HT200_400_event = h_HT_eventCout->GetBinContent(5);
    int HT400_600_event = h_HT_eventCout->GetBinContent(6);
    int HT600_800_event = h_HT_eventCout->GetBinContent(7);
    int HT800_1200_event = h_HT_eventCout->GetBinContent(8);
    int HT1200_2500_event = h_HT_eventCout->GetBinContent(9);
    int HT2500_Inf_event = h_HT_eventCout->GetBinContent(10);

    TH1F *h_DY_alpha[4];
    for (int i = 0; i < 4; i++)
    {
        h_DY_alpha[i] = new TH1F(Form("h_DY_alpha_%d", i + 1), "", 24, 0, 1.2);
        h_DY_alpha[i]->Sumw2();
    }

    TH1F *h_DY_IP2D = new TH1F("h_DY_IP2D", "", 200, -20, 20);
    h_DY_IP2D->GetXaxis()->SetTitle("");
    h_DY_IP2D->GetYaxis()->SetTitle("");
    h_DY_IP2D->Sumw2();

    TH1F *h_DY_Chi3Dlog = new TH1F("h_DY_Chi3Dlog", "", 100, -10, 10);
    h_DY_Chi3Dlog->GetXaxis()->SetTitle("");
    h_DY_Chi3Dlog->GetYaxis()->SetTitle("");
    h_DY_Chi3Dlog->Sumw2();

    TH1F *h_DY_Met = new TH1F("h_DY_Met", "", 50, 0, 500);
    h_DY_Met->GetXaxis()->SetTitle("");
    h_DY_Met->GetYaxis()->SetTitle("");
    h_DY_Met->Sumw2();

    //-------------
    //  nTracks
    //-------------
    TH1F *h_DY_nTracks = new TH1F("h_DY_nTracks", "", 100,0,100);
    h_DY_nTracks->GetXaxis()->SetTitle("");
    h_DY_nTracks->GetYaxis()->SetTitle("");
    h_DY_nTracks->Sumw2();

    TH1F *h_DY_nTracks_heavy = new TH1F("h_DY_nTracks_heavy", "", 100,0,100);
    h_DY_nTracks_heavy->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy->Sumw2();

    TH1F *h_DY_nTracks_bjet = new TH1F("h_DY_nTracks_bjet", "", 30,0,30);
    h_DY_nTracks_bjet->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet->Sumw2();

    TH1F *h_DY_nTracks_cjet = new TH1F("h_DY_nTracks_cjet", "", 50,0,50);
    h_DY_nTracks_cjet->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet->Sumw2();

    TH1F *h_DY_nTracks_heavy_cut = new TH1F("h_DY_nTracks_heavy_cut", "", 100,0,100);
    h_DY_nTracks_heavy_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_cut->Sumw2();

    TH1F *h_DY_nTracks_bjet_cut = new TH1F("h_DY_nTracks_bjet_cut", "",  30,0,30);
    h_DY_nTracks_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_bjet_cut->Sumw2();

    TH1F *h_DY_nTracks_cjet_cut = new TH1F("h_DY_nTracks_cjet_cut", "", 50,0,50);
    h_DY_nTracks_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_cjet_cut->Sumw2();

    TH1F *h_DY_nTracks_heavy_nogluon = new TH1F("h_DY_nTracks_heavy_nogluon", "", 100,0,100);
    h_DY_nTracks_heavy_nogluon->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon->Sumw2();

    TH1F *h_DY_nTracks_heavy_nogluon_cut = new TH1F("h_DY_nTracks_heavy_nogluon_cut", "", 100,0,100);
    h_DY_nTracks_heavy_nogluon_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_heavy_nogluon_cut->Sumw2();

    TH1F *h_DY_nTracks_light = new TH1F("h_DY_nTracks_light", "", 50,0,50);
    h_DY_nTracks_light->GetXaxis()->SetTitle("");
    h_DY_nTracks_light->GetYaxis()->SetTitle("");
    h_DY_nTracks_light->Sumw2();

    TH1F *h_DY_nTracks_light_cut = new TH1F("h_DY_nTracks_light_cut", "", 50,0,50);
    h_DY_nTracks_light_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_light_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_light_cut->Sumw2();

    TH1F *h_DY_nTracks_cut = new TH1F("h_DY_nTracks_cut", "", 100,0,100);
    h_DY_nTracks_cut->GetXaxis()->SetTitle("");
    h_DY_nTracks_cut->GetYaxis()->SetTitle("");
    h_DY_nTracks_cut->Sumw2();

    //-------------
    //  JetPt
    //-------------
    TH1F *h_DY_JetPt = new TH1F("h_DY_JetPt", "", 50, 0, 500);
    h_DY_JetPt->GetXaxis()->SetTitle("");
    h_DY_JetPt->GetYaxis()->SetTitle("");
    h_DY_JetPt->Sumw2();

    TH1F *h_DY_JetPt_heavy = new TH1F("h_DY_JetPt_heavy", "", 50, 0, 500);
    h_DY_JetPt_heavy->GetXaxis()->SetTitle("");
    h_DY_JetPt_heavy->GetYaxis()->SetTitle("");
    h_DY_JetPt_heavy->Sumw2();

    TH1F *h_DY_JetPt_bjet = new TH1F("h_DY_JetPt_bjet", "", 50, 0, 500);
    h_DY_JetPt_bjet->GetXaxis()->SetTitle("");
    h_DY_JetPt_bjet->GetYaxis()->SetTitle("");
    h_DY_JetPt_bjet->Sumw2();

    TH1F *h_DY_JetPt_cjet = new TH1F("h_DY_JetPt_cjet", "", 50, 0, 500);
    h_DY_JetPt_cjet->GetXaxis()->SetTitle("");
    h_DY_JetPt_cjet->GetYaxis()->SetTitle("");
    h_DY_JetPt_cjet->Sumw2();

    TH1F *h_DY_JetPt_heavy_cut = new TH1F("h_DY_JetPt_heavy_cut", "", 50, 0, 500);
    h_DY_JetPt_heavy_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_heavy_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_heavy_cut->Sumw2();

    TH1F *h_DY_JetPt_bjet_cut = new TH1F("h_DY_JetPt_bjet_cut", "", 50, 0, 500);
    h_DY_JetPt_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_bjet_cut->Sumw2();

    TH1F *h_DY_JetPt_cjet_cut = new TH1F("h_DY_JetPt_cjet_cut", "", 50, 0, 500);
    h_DY_JetPt_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_cjet_cut->Sumw2();

    TH1F *h_DY_JetPt_heavy_nogluon = new TH1F("h_DY_JetPt_heavy_nogluon", "", 50, 0, 500);
    h_DY_JetPt_heavy_nogluon->GetXaxis()->SetTitle("");
    h_DY_JetPt_heavy_nogluon->GetYaxis()->SetTitle("");
    h_DY_JetPt_heavy_nogluon->Sumw2();

    TH1F *h_DY_JetPt_heavy_nogluon_cut = new TH1F("h_DY_JetPt_heavy_nogluon_cut", "", 50, 0, 500);
    h_DY_JetPt_heavy_nogluon_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_heavy_nogluon_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_heavy_nogluon_cut->Sumw2();

    TH1F *h_DY_JetPt_light = new TH1F("h_DY_JetPt_light", "", 50, 0, 500);
    h_DY_JetPt_light->GetXaxis()->SetTitle("");
    h_DY_JetPt_light->GetYaxis()->SetTitle("");
    h_DY_JetPt_light->Sumw2();

    TH1F *h_DY_JetPt_light_cut = new TH1F("h_DY_JetPt_light_cut", "", 50, 0, 500);
    h_DY_JetPt_light_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_light_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_light_cut->Sumw2();

    TH1F *h_DY_JetPt_cut = new TH1F("h_DY_JetPt_cut", "", 50, 0, 500);
    h_DY_JetPt_cut->GetXaxis()->SetTitle("");
    h_DY_JetPt_cut->GetYaxis()->SetTitle("");
    h_DY_JetPt_cut->Sumw2();

    //-------------
    //  Jet eta
    //-------------
    TH1F *h_DY_JetEta = new TH1F("h_DY_JetEta", "", 60, -3, 3);
    h_DY_JetEta->GetXaxis()->SetTitle("");
    h_DY_JetEta->GetYaxis()->SetTitle("");
    h_DY_JetEta->Sumw2();

    TH1F *h_DY_JetEta_heavy = new TH1F("h_DY_JetEta_heavy", "", 60, -3, 3);
    h_DY_JetEta_heavy->GetXaxis()->SetTitle("");
    h_DY_JetEta_heavy->GetYaxis()->SetTitle("");
    h_DY_JetEta_heavy->Sumw2();

    TH1F *h_DY_JetEta_bjet = new TH1F("h_DY_JetEta_bjet", "", 60, -3, 3);
    h_DY_JetEta_bjet->GetXaxis()->SetTitle("");
    h_DY_JetEta_bjet->GetYaxis()->SetTitle("");
    h_DY_JetEta_bjet->Sumw2();

    TH1F *h_DY_JetEta_cjet = new TH1F("h_DY_JetEta_cjet", "", 60, -3, 3);
    h_DY_JetEta_cjet->GetXaxis()->SetTitle("");
    h_DY_JetEta_cjet->GetYaxis()->SetTitle("");
    h_DY_JetEta_cjet->Sumw2();

    TH1F *h_DY_JetEta_heavy_cut = new TH1F("h_DY_JetEta_heavy_cut", "", 60, -3, 3);
    h_DY_JetEta_heavy_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_heavy_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_heavy_cut->Sumw2();

    TH1F *h_DY_JetEta_bjet_cut = new TH1F("h_DY_JetEta_bjet_cut", "", 60, -3, 3);
    h_DY_JetEta_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_bjet_cut->Sumw2();

    TH1F *h_DY_JetEta_cjet_cut = new TH1F("h_DY_JetEta_cjet_cut", "", 60, -3, 3);
    h_DY_JetEta_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_cjet_cut->Sumw2();

    TH1F *h_DY_JetEta_heavy_nogluon = new TH1F("h_DY_JetEta_heavy_nogluon", "", 60, -3, 3);
    h_DY_JetEta_heavy_nogluon->GetXaxis()->SetTitle("");
    h_DY_JetEta_heavy_nogluon->GetYaxis()->SetTitle("");
    h_DY_JetEta_heavy_nogluon->Sumw2();

    TH1F *h_DY_JetEta_heavy_nogluon_cut = new TH1F("h_DY_JetEta_heavy_nogluon_cut", "", 60, -3, 3);
    h_DY_JetEta_heavy_nogluon_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_heavy_nogluon_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_heavy_nogluon_cut->Sumw2();

    TH1F *h_DY_JetEta_light = new TH1F("h_DY_JetEta_light", "", 60, -3, 3);
    h_DY_JetEta_light->GetXaxis()->SetTitle("");
    h_DY_JetEta_light->GetYaxis()->SetTitle("");
    h_DY_JetEta_light->Sumw2();

    TH1F *h_DY_JetEta_light_cut = new TH1F("h_DY_JetEta_light_cut", "", 60, -3, 3);
    h_DY_JetEta_light_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_light_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_light_cut->Sumw2();

    TH1F *h_DY_JetEta_cut = new TH1F("h_DY_JetEta_cut", "", 60, -3, 3);
    h_DY_JetEta_cut->GetXaxis()->SetTitle("");
    h_DY_JetEta_cut->GetYaxis()->SetTitle("");
    h_DY_JetEta_cut->Sumw2();

    //-------------
    //  alpha_3D
    //-------------
    TH1F *h_DY_alpha3D = new TH1F("h_DY_alpha3D", "", 24, 0, 1.2);
    h_DY_alpha3D->GetXaxis()->SetTitle("");
    h_DY_alpha3D->GetYaxis()->SetTitle("");
    h_DY_alpha3D->Sumw2();

    TH1F *h_DY_alpha3D_heavy = new TH1F("h_DY_alpha3D_heavy", "", 24, 0, 1.2);
    h_DY_alpha3D_heavy->GetXaxis()->SetTitle("");
    h_DY_alpha3D_heavy->GetYaxis()->SetTitle("");
    h_DY_alpha3D_heavy->Sumw2();

    TH1F *h_DY_alpha3D_bjet = new TH1F("h_DY_alpha3D_bjet", "", 24, 0, 1.2);
    h_DY_alpha3D_bjet->GetXaxis()->SetTitle("");
    h_DY_alpha3D_bjet->GetYaxis()->SetTitle("");
    h_DY_alpha3D_bjet->Sumw2();

    TH1F *h_DY_alpha3D_cjet = new TH1F("h_DY_alpha3D_cjet", "", 24, 0, 1.2);
    h_DY_alpha3D_cjet->GetXaxis()->SetTitle("");
    h_DY_alpha3D_cjet->GetYaxis()->SetTitle("");
    h_DY_alpha3D_cjet->Sumw2();

    TH1F *h_DY_alpha3D_heavy_cut = new TH1F("h_DY_alpha3D_heavy_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_heavy_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_heavy_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_heavy_cut->Sumw2();

    TH1F *h_DY_alpha3D_bjet_cut = new TH1F("h_DY_alpha3D_bjet_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_bjet_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_bjet_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_bjet_cut->Sumw2();

    TH1F *h_DY_alpha3D_cjet_cut = new TH1F("h_DY_alpha3D_cjet_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_cjet_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_cjet_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_cjet_cut->Sumw2();

    TH1F *h_DY_alpha3D_heavy_nogluon = new TH1F("h_DY_alpha3D_heavy_nogluon", "", 24, 0, 1.2);
    h_DY_alpha3D_heavy_nogluon->GetXaxis()->SetTitle("");
    h_DY_alpha3D_heavy_nogluon->GetYaxis()->SetTitle("");
    h_DY_alpha3D_heavy_nogluon->Sumw2();

    TH1F *h_DY_alpha3D_heavy_nogluon_cut = new TH1F("h_DY_alpha3D_heavy_nogluon_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_heavy_nogluon_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_heavy_nogluon_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_heavy_nogluon_cut->Sumw2();

    TH1F *h_DY_alpha3D_light = new TH1F("h_DY_alpha3D_light", "", 24, 0, 1.2);
    h_DY_alpha3D_light->GetXaxis()->SetTitle("");
    h_DY_alpha3D_light->GetYaxis()->SetTitle("");
    h_DY_alpha3D_light->Sumw2();

    TH1F *h_DY_alpha3D_light_cut = new TH1F("h_DY_alpha3D_light_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_light_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_light_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_light_cut->Sumw2();

    TH1F *h_DY_alpha3D_cut = new TH1F("h_DY_alpha3D_cut", "", 24, 0, 1.2);
    h_DY_alpha3D_cut->GetXaxis()->SetTitle("");
    h_DY_alpha3D_cut->GetYaxis()->SetTitle("");
    h_DY_alpha3D_cut->Sumw2();
    //---------------------
    // Define HTWeight
    //---------------------
    double HT0Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT0CS) / (HT0_70_event)) * 1000 * 2;
    double HT70Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT70CS) / (HT70_100_event)) * 1000 * 2;
    double HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000 * 2;
    double HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000 * 2;
    double HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000 * 2;
    double HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000 * 2;
    double HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000 * 2;
    double HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000 * 2;
    double HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000 * 2;

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

    
    TTree *h1;
    DYincli_1->GetObject("h1", h1);
    h1->SetBranchAddress("I_weight", &I_ht0_weight);
    h1->SetBranchAddress("f_HT", &HT);
    h1->SetBranchAddress("f_Met", &I_ht0_met);
    h1->SetBranchAddress("I_nJets", &I_ht0_nThinJets);
    h1->SetBranchAddress("v_N_Tracks", &v_ht0_nTrack);
    h1->SetBranchAddress("v_IP2D", &v_ht0_2DIP);
    h1->SetBranchAddress("v_Chi3Dlog", &v_ht0_Chi3Dlog);
    h1->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    h1->SetBranchAddress("v_fakealpha2", &v_ht0_alpha2);
    h1->SetBranchAddress("v_fakealpha3", &v_ht0_alpha3);
    h1->SetBranchAddress("v_fakealpha4", &v_ht0_alpha4);
    h1->SetBranchAddress("v_fakeJetPt", &v_ht0_JetPt);
    h1->SetBranchAddress("v_fakeJetEta", &v_ht0_JetEta);
    h1->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
    h1->SetBranchAddress("v_fakeJetpartonflavor", &v_ht0_Jetpartonflavor);
    for (int evt = 0; evt < h1->GetEntries(); evt++)
    {
        h1->GetEntry(evt);

        if (HT < 70)
        {
            double HT0_eventWeight = I_ht0_weight * HT0Weight;
            h_DY_Met->Fill(I_ht0_met, HT0_eventWeight);
            for (size_t i = 0; i < v_ht0_alpha->size(); i++)
            {
                h_DY_alpha[0]->Fill((*v_ht0_alpha)[i], HT0_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha2->size(); i++)
            {
                h_DY_alpha[1]->Fill((*v_ht0_alpha2)[i], HT0_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha3->size(); i++)
            {
                h_DY_alpha[2]->Fill((*v_ht0_alpha3)[i], HT0_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha4->size(); i++)
            {
                h_DY_alpha[3]->Fill((*v_ht0_alpha4)[i], HT0_eventWeight);
            }
            //-----------------
            //  3DSig
            //-----------------
            for (size_t i = 0; i < v_ht0_Chi3Dlog->size(); i++)
            {
                h_DY_Chi3Dlog->Fill((*v_ht0_Chi3Dlog)[i], HT0_eventWeight);
            }
            //-----------------
            //  2D IP
            //-----------------
            for (size_t i = 0; i < v_ht0_2DIP->size(); i++)
            {
                h_DY_IP2D->Fill((*v_ht0_2DIP)[i], HT0_eventWeight);
            }
            //--------------------------------
            // nTracks, JetPt, JetEta, alpha3D
            //--------------------------------
            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT0_eventWeight);
                h_DY_JetPt->Fill((*v_ht0_JetPt)[i], HT0_eventWeight);
                h_DY_JetEta->Fill((*v_ht0_JetEta)[i], HT0_eventWeight);
                h_DY_alpha3D->Fill((*v_ht0_alpha)[i], HT0_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT0_eventWeight, h_DY_JetPt_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_JetEta_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT0_eventWeight, h_DY_alpha3D_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT0_eventWeight, h_DY_JetPt_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_JetEta_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT0_eventWeight, h_DY_alpha3D_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT0_eventWeight, h_DY_JetPt_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_JetEta_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT0_eventWeight, h_DY_alpha3D_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT0_eventWeight, h_DY_JetPt_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_JetEta_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT0_eventWeight, h_DY_alpha3D_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT0_eventWeight);
                        h_DY_JetPt_heavy_nogluon->Fill((*v_ht0_JetPt)[i], HT0_eventWeight);
                        h_DY_JetEta_heavy_nogluon->Fill((*v_ht0_JetEta)[i], HT0_eventWeight);
                        h_DY_alpha3D_heavy_nogluon->Fill((*v_ht0_alpha)[i], HT0_eventWeight);
                    }
                }

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT0_eventWeight);
                    h_DY_JetPt_cut->Fill((*v_ht0_JetPt)[i], HT0_eventWeight);
                    h_DY_JetEta_cut->Fill((*v_ht0_JetEta)[i], HT0_eventWeight);
                    h_DY_alpha3D_cut->Fill((*v_ht0_alpha)[i], HT0_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT0_eventWeight, h_DY_JetPt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_JetEta_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT0_eventWeight, h_DY_alpha3D_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT0_eventWeight, h_DY_JetPt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_JetEta_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT0_eventWeight, h_DY_alpha3D_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT0_eventWeight, h_DY_JetPt_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_JetEta_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT0_eventWeight, h_DY_alpha3D_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT0_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT0_eventWeight, h_DY_JetPt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT0_eventWeight, h_DY_JetEta_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT0_eventWeight, h_DY_alpha3D_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT0_eventWeight);
                            h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht0_JetPt)[i], HT0_eventWeight);
                            h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht0_JetEta)[i], HT0_eventWeight);
                            h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht0_alpha)[i], HT0_eventWeight);
                        }
                    }

                } // alpha cut
            }
        }
        else if (HT >= 70 && HT < 100)
        {
            double HT70_eventWeight = I_ht0_weight * HT70Weight;

            h_DY_Met->Fill(I_ht0_met, HT70_eventWeight);
            for (size_t i = 0; i < v_ht0_alpha->size(); i++)
            {
                h_DY_alpha[0]->Fill((*v_ht0_alpha)[i], HT70_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha2->size(); i++)
            {
                h_DY_alpha[1]->Fill((*v_ht0_alpha2)[i], HT70_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha3->size(); i++)
            {
                h_DY_alpha[2]->Fill((*v_ht0_alpha3)[i], HT70_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha4->size(); i++)
            {
                h_DY_alpha[3]->Fill((*v_ht0_alpha4)[i], HT70_eventWeight);
            }
            //-----------------
            //  3DSig, nTracks
            //-----------------
            for (size_t i = 0; i < v_ht0_Chi3Dlog->size(); i++)
            {
                h_DY_Chi3Dlog->Fill((*v_ht0_Chi3Dlog)[i], HT70_eventWeight);
            }
            //-----------------
            //  2D IP
            //-----------------
            for (size_t i = 0; i < v_ht0_2DIP->size(); i++)
            {
                h_DY_IP2D->Fill((*v_ht0_2DIP)[i], HT70_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT70_eventWeight);
                h_DY_JetPt->Fill((*v_ht0_JetPt)[i], HT70_eventWeight);
                h_DY_JetEta->Fill((*v_ht0_JetEta)[i], HT70_eventWeight);
                h_DY_alpha3D->Fill((*v_ht0_alpha)[i], HT70_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT70_eventWeight, h_DY_JetPt_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_JetEta_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT70_eventWeight, h_DY_alpha3D_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT70_eventWeight, h_DY_JetPt_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_JetEta_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT70_eventWeight, h_DY_alpha3D_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT70_eventWeight, h_DY_JetPt_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_JetEta_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT70_eventWeight, h_DY_alpha3D_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT70_eventWeight, h_DY_JetPt_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_JetEta_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT70_eventWeight, h_DY_alpha3D_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {

                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT70_eventWeight);
                        h_DY_JetPt_heavy_nogluon->Fill((*v_ht0_JetPt)[i], HT70_eventWeight);
                        h_DY_JetEta_heavy_nogluon->Fill((*v_ht0_JetEta)[i], HT70_eventWeight);
                        h_DY_alpha3D_heavy_nogluon->Fill((*v_ht0_alpha)[i], HT70_eventWeight);
                    }
                }

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT70_eventWeight);
                    h_DY_JetPt_cut->Fill((*v_ht0_JetPt)[i], HT70_eventWeight);
                    h_DY_JetEta_cut->Fill((*v_ht0_JetEta)[i], HT70_eventWeight);
                    h_DY_alpha3D_cut->Fill((*v_ht0_alpha)[i], HT70_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT70_eventWeight, h_DY_JetPt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_JetEta_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT70_eventWeight, h_DY_alpha3D_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT70_eventWeight, h_DY_JetPt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_JetEta_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT70_eventWeight, h_DY_alpha3D_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT70_eventWeight, h_DY_JetPt_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_JetEta_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT70_eventWeight, h_DY_alpha3D_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT70_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT70_eventWeight, h_DY_JetPt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT70_eventWeight, h_DY_JetEta_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT70_eventWeight, h_DY_alpha3D_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT70_eventWeight);
                            h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht0_JetPt)[i], HT70_eventWeight);
                            h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht0_JetEta)[i], HT70_eventWeight);
                            h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht0_alpha)[i], HT70_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 100 && HT < 200)
        {
            double HT100_eventWeight = I_ht0_weight * HT100Weight;

            h_DY_Met->Fill(I_ht0_met, HT100_eventWeight);
            for (size_t i = 0; i < v_ht0_alpha->size(); i++)
            {
                h_DY_alpha[0]->Fill((*v_ht0_alpha)[i], HT100_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha2->size(); i++)
            {
                h_DY_alpha[1]->Fill((*v_ht0_alpha2)[i], HT100_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha3->size(); i++)
            {
                h_DY_alpha[2]->Fill((*v_ht0_alpha3)[i], HT100_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha4->size(); i++)
            {
                h_DY_alpha[3]->Fill((*v_ht0_alpha4)[i], HT100_eventWeight);
            }
            //-----------------
            //  3DSig, nTracks
            //-----------------
            for (size_t i = 0; i < v_ht0_Chi3Dlog->size(); i++)
            {
                h_DY_Chi3Dlog->Fill((*v_ht0_Chi3Dlog)[i], HT100_eventWeight);
            }
            //-----------------
            //  2D IP
            //-----------------
            for (size_t i = 0; i < v_ht0_2DIP->size(); i++)
            {
                h_DY_IP2D->Fill((*v_ht0_2DIP)[i], HT100_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT100_eventWeight);
                h_DY_JetPt->Fill((*v_ht0_JetPt)[i], HT100_eventWeight);
                h_DY_JetEta->Fill((*v_ht0_JetEta)[i], HT100_eventWeight);
                h_DY_alpha3D->Fill((*v_ht0_alpha)[i], HT100_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT100_eventWeight, h_DY_JetPt_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_JetEta_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT100_eventWeight, h_DY_alpha3D_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT100_eventWeight, h_DY_JetPt_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_JetEta_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT100_eventWeight, h_DY_alpha3D_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT100_eventWeight, h_DY_JetPt_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_JetEta_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT100_eventWeight, h_DY_alpha3D_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT100_eventWeight, h_DY_JetPt_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_JetEta_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT100_eventWeight, h_DY_alpha3D_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {

                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT100_eventWeight);
                        h_DY_JetPt_heavy_nogluon->Fill((*v_ht0_JetPt)[i], HT100_eventWeight);
                        h_DY_JetEta_heavy_nogluon->Fill((*v_ht0_JetEta)[i], HT100_eventWeight);
                        h_DY_alpha3D_heavy_nogluon->Fill((*v_ht0_alpha)[i], HT100_eventWeight);
                    }
                }

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT100_eventWeight);
                    h_DY_JetPt_cut->Fill((*v_ht0_JetPt)[i], HT100_eventWeight);
                    h_DY_JetEta_cut->Fill((*v_ht0_JetEta)[i], HT100_eventWeight);
                    h_DY_alpha3D_cut->Fill((*v_ht0_alpha)[i], HT100_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT100_eventWeight, h_DY_JetPt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_JetEta_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT100_eventWeight, h_DY_alpha3D_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT100_eventWeight, h_DY_JetPt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_JetEta_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT100_eventWeight, h_DY_alpha3D_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT100_eventWeight, h_DY_JetPt_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_JetEta_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT100_eventWeight, h_DY_alpha3D_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT100_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT100_eventWeight, h_DY_JetPt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT100_eventWeight, h_DY_JetEta_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT100_eventWeight, h_DY_alpha3D_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT100_eventWeight);
                            h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht0_JetPt)[i], HT100_eventWeight);
                            h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht0_JetEta)[i], HT100_eventWeight);
                            h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht0_alpha)[i], HT100_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 200 && HT < 400)
        {

            double HT200_eventWeight = I_ht0_weight * HT200Weight;

            h_DY_Met->Fill(I_ht0_met, HT200_eventWeight);

            for (size_t i = 0; i < v_ht0_alpha->size(); i++)
            {
                h_DY_alpha[0]->Fill((*v_ht0_alpha)[i], HT200_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha2->size(); i++)
            {
                h_DY_alpha[1]->Fill((*v_ht0_alpha2)[i], HT200_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha3->size(); i++)
            {
                h_DY_alpha[2]->Fill((*v_ht0_alpha3)[i], HT200_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha4->size(); i++)
            {
                h_DY_alpha[3]->Fill((*v_ht0_alpha4)[i], HT200_eventWeight);
            }
            //-----------------
            //  3DSig, nTracks
            //-----------------
            for (size_t i = 0; i < v_ht0_Chi3Dlog->size(); i++)
            {
                h_DY_Chi3Dlog->Fill((*v_ht0_Chi3Dlog)[i], HT200_eventWeight);
            }
            //-----------------
            //  2D IP
            //-----------------
            for (size_t i = 0; i < v_ht0_2DIP->size(); i++)
            {
                h_DY_IP2D->Fill((*v_ht0_2DIP)[i], HT200_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT200_eventWeight);
                h_DY_JetPt->Fill((*v_ht0_JetPt)[i], HT200_eventWeight);
                h_DY_JetEta->Fill((*v_ht0_JetEta)[i], HT200_eventWeight);
                h_DY_alpha3D->Fill((*v_ht0_alpha)[i], HT200_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT200_eventWeight, h_DY_JetPt_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_JetEta_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT200_eventWeight, h_DY_alpha3D_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT200_eventWeight, h_DY_JetPt_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_JetEta_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT200_eventWeight, h_DY_alpha3D_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT200_eventWeight, h_DY_JetPt_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_JetEta_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT200_eventWeight, h_DY_alpha3D_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT200_eventWeight, h_DY_JetPt_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_JetEta_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT200_eventWeight, h_DY_alpha3D_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT200_eventWeight);
                        h_DY_JetPt_heavy_nogluon->Fill((*v_ht0_JetPt)[i], HT200_eventWeight);
                        h_DY_JetEta_heavy_nogluon->Fill((*v_ht0_JetEta)[i], HT200_eventWeight);
                        h_DY_alpha3D_heavy_nogluon->Fill((*v_ht0_alpha)[i], HT200_eventWeight);
                    }
                }

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT200_eventWeight);
                    h_DY_JetPt_cut->Fill((*v_ht0_JetPt)[i], HT200_eventWeight);
                    h_DY_JetEta_cut->Fill((*v_ht0_JetEta)[i], HT200_eventWeight);
                    h_DY_alpha3D_cut->Fill((*v_ht0_alpha)[i], HT200_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT200_eventWeight, h_DY_JetPt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_JetEta_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT200_eventWeight, h_DY_alpha3D_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT200_eventWeight, h_DY_JetPt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_JetEta_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT200_eventWeight, h_DY_alpha3D_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT200_eventWeight, h_DY_JetPt_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_JetEta_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT200_eventWeight, h_DY_alpha3D_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT200_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT200_eventWeight, h_DY_JetPt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT200_eventWeight, h_DY_JetEta_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT200_eventWeight, h_DY_alpha3D_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT200_eventWeight);
                            h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht0_JetPt)[i], HT200_eventWeight);
                            h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht0_JetEta)[i], HT200_eventWeight);
                            h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht0_alpha)[i], HT200_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 400 && HT < 600)
        {
            double HT400_eventWeight = I_ht0_weight * HT400Weight;

            h_DY_Met->Fill(I_ht0_met, HT400_eventWeight);
            for (size_t i = 0; i < v_ht0_alpha->size(); i++)
            {
                h_DY_alpha[0]->Fill((*v_ht0_alpha)[i], HT400_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha2->size(); i++)
            {
                h_DY_alpha[1]->Fill((*v_ht0_alpha2)[i], HT400_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha3->size(); i++)
            {
                h_DY_alpha[2]->Fill((*v_ht0_alpha3)[i], HT400_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha4->size(); i++)
            {
                h_DY_alpha[3]->Fill((*v_ht0_alpha4)[i], HT400_eventWeight);
            }
            //-----------------
            //  3DSig, nTracks
            //-----------------
            for (size_t i = 0; i < v_ht0_Chi3Dlog->size(); i++)
            {
                h_DY_Chi3Dlog->Fill((*v_ht0_Chi3Dlog)[i], HT400_eventWeight);
            }
            //-----------------
            //  2D IP
            //-----------------
            for (size_t i = 0; i < v_ht0_2DIP->size(); i++)
            {
                h_DY_IP2D->Fill((*v_ht0_2DIP)[i], HT400_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT400_eventWeight);
                h_DY_JetPt->Fill((*v_ht0_JetPt)[i], HT400_eventWeight);
                h_DY_JetEta->Fill((*v_ht0_JetEta)[i], HT400_eventWeight);
                h_DY_alpha3D->Fill((*v_ht0_alpha)[i], HT400_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT400_eventWeight, h_DY_JetPt_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_JetEta_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT400_eventWeight, h_DY_alpha3D_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT400_eventWeight, h_DY_JetPt_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_JetEta_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT400_eventWeight, h_DY_alpha3D_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT400_eventWeight, h_DY_JetPt_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_JetEta_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT400_eventWeight, h_DY_alpha3D_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT400_eventWeight, h_DY_JetPt_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_JetEta_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT400_eventWeight, h_DY_alpha3D_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT400_eventWeight);
                        h_DY_JetPt_heavy_nogluon->Fill((*v_ht0_JetPt)[i], HT400_eventWeight);
                        h_DY_JetEta_heavy_nogluon->Fill((*v_ht0_JetEta)[i], HT400_eventWeight);
                        h_DY_alpha3D_heavy_nogluon->Fill((*v_ht0_alpha)[i], HT400_eventWeight);
                    }
                }

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT400_eventWeight);
                    h_DY_JetPt_cut->Fill((*v_ht0_JetPt)[i], HT400_eventWeight);
                    h_DY_JetEta_cut->Fill((*v_ht0_JetEta)[i], HT400_eventWeight);
                    h_DY_alpha3D_cut->Fill((*v_ht0_alpha)[i], HT400_eventWeight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT400_eventWeight, h_DY_JetPt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_JetEta_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT400_eventWeight, h_DY_alpha3D_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT400_eventWeight, h_DY_JetPt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_JetEta_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT400_eventWeight, h_DY_alpha3D_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT400_eventWeight, h_DY_JetPt_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_JetEta_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT400_eventWeight, h_DY_alpha3D_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT400_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT400_eventWeight, h_DY_JetPt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT400_eventWeight, h_DY_JetEta_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT400_eventWeight, h_DY_alpha3D_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT400_eventWeight);
                            h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht0_JetPt)[i], HT400_eventWeight);
                            h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht0_JetEta)[i], HT400_eventWeight);
                            h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht0_alpha)[i], HT400_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 600 && HT < 800)
        {
            double HT600_eventWeight = I_ht0_weight * HT600Weight;

            h_DY_Met->Fill(I_ht0_met, HT600_eventWeight);
            for (size_t i = 0; i < v_ht0_alpha->size(); i++)
            {
                h_DY_alpha[0]->Fill((*v_ht0_alpha)[i], HT600_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha2->size(); i++)
            {
                h_DY_alpha[1]->Fill((*v_ht0_alpha2)[i], HT600_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha3->size(); i++)
            {
                h_DY_alpha[2]->Fill((*v_ht0_alpha3)[i], HT600_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha4->size(); i++)
            {
                h_DY_alpha[3]->Fill((*v_ht0_alpha4)[i], HT600_eventWeight);
            }
            //-----------------
            //  3DSig, nTracks
            //-----------------
            for (size_t i = 0; i < v_ht0_Chi3Dlog->size(); i++)
            {
                h_DY_Chi3Dlog->Fill((*v_ht0_Chi3Dlog)[i], HT600_eventWeight);
            }
            //-----------------
            //  2D IP
            //-----------------
            for (size_t i = 0; i < v_ht0_2DIP->size(); i++)
            {
                h_DY_IP2D->Fill((*v_ht0_2DIP)[i], HT600_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT600_eventWeight);
                h_DY_JetPt->Fill((*v_ht0_JetPt)[i], HT600_eventWeight);
                h_DY_JetEta->Fill((*v_ht0_JetEta)[i], HT600_eventWeight);
                h_DY_alpha3D->Fill((*v_ht0_alpha)[i], HT600_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT600_eventWeight, h_DY_JetPt_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_JetEta_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT600_eventWeight, h_DY_alpha3D_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT600_eventWeight, h_DY_JetPt_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_JetEta_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT600_eventWeight, h_DY_alpha3D_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT600_eventWeight, h_DY_JetPt_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_JetEta_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT600_eventWeight, h_DY_alpha3D_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT600_eventWeight, h_DY_JetPt_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_JetEta_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT600_eventWeight, h_DY_alpha3D_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT600_eventWeight);
                        h_DY_JetPt_heavy_nogluon->Fill((*v_ht0_JetPt)[i], HT600_eventWeight);
                        h_DY_JetEta_heavy_nogluon->Fill((*v_ht0_JetEta)[i], HT600_eventWeight);
                        h_DY_alpha3D_heavy_nogluon->Fill((*v_ht0_alpha)[i], HT600_eventWeight);
                    }
                }

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT600_eventWeight);
                    h_DY_JetPt_cut->Fill((*v_ht0_JetPt)[i], HT600_eventWeight);
                    h_DY_JetEta_cut->Fill((*v_ht0_JetEta)[i], HT600_eventWeight);
                    h_DY_alpha3D_cut->Fill((*v_ht0_alpha)[i], HT600_eventWeight);

                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT600_eventWeight, h_DY_JetPt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_JetEta_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT600_eventWeight, h_DY_alpha3D_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT600_eventWeight, h_DY_JetPt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_JetEta_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT600_eventWeight, h_DY_alpha3D_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT600_eventWeight, h_DY_JetPt_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_JetEta_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT600_eventWeight, h_DY_alpha3D_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT600_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT600_eventWeight, h_DY_JetPt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT600_eventWeight, h_DY_JetEta_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT600_eventWeight, h_DY_alpha3D_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT600_eventWeight);
                            h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht0_JetPt)[i], HT600_eventWeight);
                            h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht0_JetEta)[i], HT600_eventWeight);
                            h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht0_alpha)[i], HT600_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 800 && HT < 1200)
        {
            double HT800_eventWeight = I_ht0_weight * HT800Weight;
            h_DY_Met->Fill(I_ht0_met, HT800_eventWeight);
            for (size_t i = 0; i < v_ht0_alpha->size(); i++)
            {
                h_DY_alpha[0]->Fill((*v_ht0_alpha)[i], HT800_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha2->size(); i++)
            {
                h_DY_alpha[1]->Fill((*v_ht0_alpha2)[i], HT800_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha3->size(); i++)
            {
                h_DY_alpha[2]->Fill((*v_ht0_alpha3)[i], HT800_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha4->size(); i++)
            {
                h_DY_alpha[3]->Fill((*v_ht0_alpha4)[i], HT800_eventWeight);
            }
            //-----------------
            //  3DSig, nTracks
            //-----------------
            for (size_t i = 0; i < v_ht0_Chi3Dlog->size(); i++)
            {
                h_DY_Chi3Dlog->Fill((*v_ht0_Chi3Dlog)[i], HT800_eventWeight);
            }
            //-----------------
            //  2D IP
            //-----------------
            for (size_t i = 0; i < v_ht0_2DIP->size(); i++)
            {
                h_DY_IP2D->Fill((*v_ht0_2DIP)[i], HT800_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT800_eventWeight);
                h_DY_JetPt->Fill((*v_ht0_JetPt)[i], HT800_eventWeight);
                h_DY_JetEta->Fill((*v_ht0_JetEta)[i], HT800_eventWeight);
                h_DY_alpha3D->Fill((*v_ht0_alpha)[i], HT800_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT800_eventWeight, h_DY_JetPt_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT800_eventWeight, h_DY_JetEta_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT800_eventWeight, h_DY_alpha3D_bjet);
                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT800_eventWeight, h_DY_JetPt_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT800_eventWeight, h_DY_JetEta_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT800_eventWeight, h_DY_alpha3D_cjet);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT800_eventWeight, h_DY_JetPt_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT800_eventWeight, h_DY_JetEta_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT800_eventWeight, h_DY_alpha3D_heavy);
                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT800_eventWeight, h_DY_JetPt_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT800_eventWeight, h_DY_JetEta_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT800_eventWeight, h_DY_alpha3D_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT800_eventWeight);
                        h_DY_JetPt_heavy_nogluon->Fill((*v_ht0_JetPt)[i], HT800_eventWeight);
                        h_DY_JetEta_heavy_nogluon->Fill((*v_ht0_JetEta)[i], HT800_eventWeight);
                        h_DY_alpha3D_heavy_nogluon->Fill((*v_ht0_alpha)[i], HT800_eventWeight);
                    }
                }
                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT800_eventWeight);
                    h_DY_JetPt_cut->Fill((*v_ht0_JetPt)[i], HT800_eventWeight);
                    h_DY_JetEta_cut->Fill((*v_ht0_JetEta)[i], HT800_eventWeight);
                    h_DY_alpha3D_cut->Fill((*v_ht0_alpha)[i], HT800_eventWeight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT800_eventWeight, h_DY_JetPt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT800_eventWeight, h_DY_JetEta_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT800_eventWeight, h_DY_alpha3D_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT800_eventWeight, h_DY_JetPt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT800_eventWeight, h_DY_JetEta_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT800_eventWeight, h_DY_alpha3D_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT800_eventWeight, h_DY_JetPt_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT800_eventWeight, h_DY_JetEta_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT800_eventWeight, h_DY_alpha3D_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT800_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT800_eventWeight, h_DY_JetPt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT800_eventWeight, h_DY_JetEta_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT800_eventWeight, h_DY_alpha3D_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT800_eventWeight);
                            h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht0_JetPt)[i], HT800_eventWeight);
                            h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht0_JetEta)[i], HT800_eventWeight);
                            h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht0_alpha)[i], HT800_eventWeight);
                        }
                    }

                } // alpha cut
            }
        }
        else if (HT >= 1200 && HT < 2500)
        {
            double HT1200_eventWeight = I_ht0_weight * HT1200Weight;
            h_DY_Met->Fill(I_ht0_met, HT1200_eventWeight);
            for (size_t i = 0; i < v_ht0_alpha->size(); i++)
            {
                h_DY_alpha[0]->Fill((*v_ht0_alpha)[i], HT1200_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha2->size(); i++)
            {
                h_DY_alpha[1]->Fill((*v_ht0_alpha2)[i], HT1200_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha3->size(); i++)
            {
                h_DY_alpha[2]->Fill((*v_ht0_alpha3)[i], HT1200_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha4->size(); i++)
            {
                h_DY_alpha[3]->Fill((*v_ht0_alpha4)[i], HT1200_eventWeight);
            }
            //-----------------
            //  3DSig, nTracks
            //-----------------
            for (size_t i = 0; i < v_ht0_Chi3Dlog->size(); i++)
            {
                h_DY_Chi3Dlog->Fill((*v_ht0_Chi3Dlog)[i], HT1200_eventWeight);
            }
            //-----------------
            //  2D IP
            //-----------------
            for (size_t i = 0; i < v_ht0_2DIP->size(); i++)
            {
                h_DY_IP2D->Fill((*v_ht0_2DIP)[i], HT1200_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT1200_eventWeight);
                h_DY_JetPt->Fill((*v_ht0_JetPt)[i], HT1200_eventWeight);
                h_DY_JetEta->Fill((*v_ht0_JetEta)[i], HT1200_eventWeight);
                h_DY_alpha3D->Fill((*v_ht0_alpha)[i], HT1200_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_bjet);
                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_cjet);
                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_heavy);
                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT1200_eventWeight);
                        h_DY_JetPt_heavy_nogluon->Fill((*v_ht0_JetPt)[i], HT1200_eventWeight);
                        h_DY_JetEta_heavy_nogluon->Fill((*v_ht0_JetEta)[i], HT1200_eventWeight);
                        h_DY_alpha3D_heavy_nogluon->Fill((*v_ht0_alpha)[i], HT1200_eventWeight);
                    }
                }
                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT1200_eventWeight);
                    h_DY_JetPt_cut->Fill((*v_ht0_JetPt)[i], HT1200_eventWeight);
                    h_DY_JetEta_cut->Fill((*v_ht0_JetEta)[i], HT1200_eventWeight);
                    h_DY_alpha3D_cut->Fill((*v_ht0_alpha)[i], HT1200_eventWeight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT1200_eventWeight);
                            h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht0_JetPt)[i], HT1200_eventWeight);
                            h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht0_JetEta)[i], HT1200_eventWeight);
                            h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht0_alpha)[i], HT1200_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
        else if (HT >= 2500)
        {
            double HT2500_eventWeight = I_ht0_weight * HT2500Weight;
            h_DY_Met->Fill(I_ht0_met, HT2500_eventWeight);
            for (size_t i = 0; i < v_ht0_alpha->size(); i++)
            {
                h_DY_alpha[0]->Fill((*v_ht0_alpha)[i], HT2500_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha2->size(); i++)
            {
                h_DY_alpha[1]->Fill((*v_ht0_alpha2)[i], HT2500_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha3->size(); i++)
            {
                h_DY_alpha[2]->Fill((*v_ht0_alpha3)[i], HT2500_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_alpha4->size(); i++)
            {
                h_DY_alpha[3]->Fill((*v_ht0_alpha4)[i], HT2500_eventWeight);
            }
            //-----------------
            //  3DSig, nTracks
            //-----------------
            for (size_t i = 0; i < v_ht0_Chi3Dlog->size(); i++)
            {
                h_DY_Chi3Dlog->Fill((*v_ht0_Chi3Dlog)[i], HT2500_eventWeight);
            }
            //-----------------
            //  2D IP
            //-----------------
            for (size_t i = 0; i < v_ht0_2DIP->size(); i++)
            {
                h_DY_IP2D->Fill((*v_ht0_2DIP)[i], HT2500_eventWeight);
            }
            for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
            {
                h_DY_nTracks->Fill((*v_ht0_nTrack)[i], HT2500_eventWeight);
                h_DY_JetPt->Fill((*v_ht0_JetPt)[i], HT2500_eventWeight);
                h_DY_JetEta->Fill((*v_ht0_JetEta)[i], HT2500_eventWeight);
                h_DY_alpha3D->Fill((*v_ht0_alpha)[i], HT2500_eventWeight);
                // For b jet
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_bjet);
                for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_bjet);

                // For c jet
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_cjet);
                for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_cjet);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_heavy);
                for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_heavy);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_light);
                for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_light);

                if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon->Fill((*v_ht0_nTrack)[i], HT2500_eventWeight);
                        h_DY_JetPt_heavy_nogluon->Fill((*v_ht0_JetPt)[i], HT2500_eventWeight);
                        h_DY_JetEta_heavy_nogluon->Fill((*v_ht0_JetEta)[i], HT2500_eventWeight);
                        h_DY_alpha3D_heavy_nogluon->Fill((*v_ht0_alpha)[i], HT2500_eventWeight);
                    }
                }

                if ((*v_ht0_alpha)[i] < 0.15)
                {
                    h_DY_nTracks_cut->Fill((*v_ht0_nTrack)[i], HT2500_eventWeight);
                    h_DY_JetPt_cut->Fill((*v_ht0_JetPt)[i], HT2500_eventWeight);
                    h_DY_JetEta_cut->Fill((*v_ht0_JetEta)[i], HT2500_eventWeight);
                    h_DY_alpha3D_cut->Fill((*v_ht0_alpha)[i], HT2500_eventWeight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_bjet_cut);
                    for_signalflavor_jet(5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_bjet_cut);

                    // For c jet
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_cjet_cut);
                    for_signalflavor_jet(4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_cjet_cut);

                    // For heavy flavor
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_heavy_cut);
                    for_doubleflavor_jet(4, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_heavy_cut);

                    // For light flavor
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_light_cut);
                    for_signalflavor_jet(0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_light_cut);

                    if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
                    {
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht0_nTrack)[i], HT2500_eventWeight);
                            h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht0_JetPt)[i], HT2500_eventWeight);
                            h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht0_JetEta)[i], HT2500_eventWeight);
                            h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht0_alpha)[i], HT2500_eventWeight);
                        }
                    }
                } // alpha cut
            }
        }
    } // End of DY_inclusive
    TTree *T_tree2;
    DYHT100_1->GetObject("h1", T_tree2);
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
        h_DY_Met->Fill(I_ht100_met, HT100_eventWeight);
        for (size_t i = 0; i < v_ht100_alpha->size(); i++)
        {
            h_DY_alpha[0]->Fill((*v_ht100_alpha)[i], HT100_eventWeight);
        }
        for (size_t i = 0; i < v_ht100_alpha2->size(); i++)
        {
            h_DY_alpha[1]->Fill((*v_ht100_alpha2)[i], HT100_eventWeight);
        }
        for (size_t i = 0; i < v_ht100_alpha3->size(); i++)
        {
            h_DY_alpha[2]->Fill((*v_ht100_alpha3)[i], HT100_eventWeight);
        }
        for (size_t i = 0; i < v_ht100_alpha4->size(); i++)
        {
            h_DY_alpha[3]->Fill((*v_ht100_alpha4)[i], HT100_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_ht100_Chi3Dlog->size(); i++)
        {
            h_DY_Chi3Dlog->Fill((*v_ht100_Chi3Dlog)[i], HT100_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_ht100_2DIP->size(); i++)
        {
            h_DY_IP2D->Fill((*v_ht100_2DIP)[i], HT100_eventWeight);
        }
        for (size_t i = 0; i < v_ht100_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht100_nTrack)[i], HT100_eventWeight);
            h_DY_JetPt->Fill((*v_ht100_JetPt)[i], HT100_eventWeight);
            h_DY_JetEta->Fill((*v_ht100_JetEta)[i], HT100_eventWeight);
            h_DY_alpha3D->Fill((*v_ht100_alpha)[i], HT100_eventWeight);
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
            for_doubleflavor_jet(4, 5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_light);

            if ((*v_ht100_Jethadronflavor)[i] == 4 || (*v_ht100_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht100_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht100_nTrack)[i], HT100_eventWeight);
                    h_DY_JetPt_heavy_nogluon->Fill((*v_ht100_JetPt)[i], HT100_eventWeight);
                    h_DY_JetEta_heavy_nogluon->Fill((*v_ht100_JetEta)[i], HT100_eventWeight);
                    h_DY_alpha3D_heavy_nogluon->Fill((*v_ht100_alpha)[i], HT100_eventWeight);
                }
            }
            if ((*v_ht100_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht100_nTrack)[i], HT100_eventWeight);
                h_DY_JetPt_cut->Fill((*v_ht100_JetPt)[i], HT100_eventWeight);
                h_DY_JetEta_cut->Fill((*v_ht100_JetEta)[i], HT100_eventWeight);
                h_DY_alpha3D_cut->Fill((*v_ht100_alpha)[i], HT100_eventWeight);
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
                for_doubleflavor_jet(4, 5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_nTrack)[i], HT100_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetPt)[i], HT100_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_JetEta)[i], HT100_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_alpha)[i], HT100_eventWeight, h_DY_alpha3D_light_cut);

                if ((*v_ht100_Jethadronflavor)[i] == 4 || (*v_ht100_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht100_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht100_nTrack)[i], HT100_eventWeight);
                        h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht100_JetPt)[i], HT100_eventWeight);
                        h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht100_JetEta)[i], HT100_eventWeight);
                        h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht100_alpha)[i], HT100_eventWeight);
                    }
                }

            } // alpha cut
        }
    }
    TTree *T_tree3;
    DYHT200_1->GetObject("h1", T_tree3);
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
        h_DY_Met->Fill(I_ht200_met, HT200_eventWeight);
        for (size_t i = 0; i < v_ht200_alpha->size(); i++)
        {
            h_DY_alpha[0]->Fill((*v_ht200_alpha)[i], HT200_eventWeight);
        }
        for (size_t i = 0; i < v_ht200_alpha2->size(); i++)
        {
            h_DY_alpha[1]->Fill((*v_ht200_alpha2)[i], HT200_eventWeight);
        }
        for (size_t i = 0; i < v_ht200_alpha3->size(); i++)
        {
            h_DY_alpha[2]->Fill((*v_ht200_alpha3)[i], HT200_eventWeight);
        }
        for (size_t i = 0; i < v_ht200_alpha4->size(); i++)
        {
            h_DY_alpha[3]->Fill((*v_ht200_alpha4)[i], HT200_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_ht200_Chi3Dlog->size(); i++)
        {
            h_DY_Chi3Dlog->Fill((*v_ht200_Chi3Dlog)[i], HT200_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_ht200_2DIP->size(); i++)
        {
            h_DY_IP2D->Fill((*v_ht200_2DIP)[i], HT200_eventWeight);
        }
        for (size_t i = 0; i < v_ht200_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht200_nTrack)[i], HT200_eventWeight);
            h_DY_JetPt->Fill((*v_ht200_JetPt)[i], HT200_eventWeight);
            h_DY_JetEta->Fill((*v_ht200_JetEta)[i], HT200_eventWeight);
            h_DY_alpha3D->Fill((*v_ht200_alpha)[i], HT200_eventWeight);
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
            for_doubleflavor_jet(4, 5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_light);

            if ((*v_ht200_Jethadronflavor)[i] == 4 || (*v_ht200_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht200_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht200_nTrack)[i], HT200_eventWeight);
                    h_DY_JetPt_heavy_nogluon->Fill((*v_ht200_JetPt)[i], HT200_eventWeight);
                    h_DY_JetEta_heavy_nogluon->Fill((*v_ht200_JetEta)[i], HT200_eventWeight);
                    h_DY_alpha3D_heavy_nogluon->Fill((*v_ht200_alpha)[i], HT200_eventWeight);
                }
            }
            if ((*v_ht200_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht200_nTrack)[i], HT200_eventWeight);
                h_DY_JetPt_cut->Fill((*v_ht200_JetPt)[i], HT200_eventWeight);
                h_DY_JetEta_cut->Fill((*v_ht200_JetEta)[i], HT200_eventWeight);
                h_DY_alpha3D_cut->Fill((*v_ht200_alpha)[i], HT200_eventWeight);
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
                for_doubleflavor_jet(4, 5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_nTrack)[i], HT200_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetPt)[i], HT200_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_JetEta)[i], HT200_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_alpha)[i], HT200_eventWeight, h_DY_alpha3D_light_cut);

                if ((*v_ht200_Jethadronflavor)[i] == 4 || (*v_ht200_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht200_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht200_nTrack)[i], HT200_eventWeight);
                        h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht200_JetPt)[i], HT200_eventWeight);
                        h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht200_JetEta)[i], HT200_eventWeight);
                        h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht200_alpha)[i], HT200_eventWeight);
                    }
                }
            } // alpha cut
        }
    }
    TTree *T_tree4;
    DYHT400_1->GetObject("h1", T_tree4);
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
        h_DY_Met->Fill(I_ht400_met, HT400_eventWeight);
        for (size_t i = 0; i < v_ht400_alpha->size(); i++)
        {
            h_DY_alpha[0]->Fill((*v_ht400_alpha)[i], HT400_eventWeight);
        }
        for (size_t i = 0; i < v_ht400_alpha2->size(); i++)
        {
            h_DY_alpha[1]->Fill((*v_ht400_alpha2)[i], HT400_eventWeight);
        }
        for (size_t i = 0; i < v_ht400_alpha3->size(); i++)
        {
            h_DY_alpha[2]->Fill((*v_ht400_alpha3)[i], HT400_eventWeight);
        }
        for (size_t i = 0; i < v_ht400_alpha4->size(); i++)
        {
            h_DY_alpha[3]->Fill((*v_ht400_alpha4)[i], HT400_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_ht400_Chi3Dlog->size(); i++)
        {
            h_DY_Chi3Dlog->Fill((*v_ht400_Chi3Dlog)[i], HT400_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_ht400_2DIP->size(); i++)
        {
            h_DY_IP2D->Fill((*v_ht400_2DIP)[i], HT400_eventWeight);
        }
        for (size_t i = 0; i < v_ht400_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht400_nTrack)[i], HT400_eventWeight);
            h_DY_JetPt->Fill((*v_ht400_JetPt)[i], HT400_eventWeight);
            h_DY_JetEta->Fill((*v_ht400_JetEta)[i], HT400_eventWeight);
            h_DY_alpha3D->Fill((*v_ht400_alpha)[i], HT400_eventWeight);
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
            for_doubleflavor_jet(4, 5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_light);

            if ((*v_ht400_Jethadronflavor)[i] == 4 || (*v_ht400_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht400_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht400_nTrack)[i], HT400_eventWeight);
                    h_DY_JetPt_heavy_nogluon->Fill((*v_ht400_JetPt)[i], HT400_eventWeight);
                    h_DY_JetEta_heavy_nogluon->Fill((*v_ht400_JetEta)[i], HT400_eventWeight);
                    h_DY_alpha3D_heavy_nogluon->Fill((*v_ht400_alpha)[i], HT400_eventWeight);
                }
            }
            if ((*v_ht400_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht400_nTrack)[i], HT400_eventWeight);
                h_DY_JetPt_cut->Fill((*v_ht400_JetPt)[i], HT400_eventWeight);
                h_DY_JetEta_cut->Fill((*v_ht400_JetEta)[i], HT400_eventWeight);
                h_DY_alpha3D_cut->Fill((*v_ht400_alpha)[i], HT400_eventWeight);
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
                for_doubleflavor_jet(4, 5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_nTrack)[i], HT400_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetPt)[i], HT400_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_JetEta)[i], HT400_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_alpha)[i], HT400_eventWeight, h_DY_alpha3D_light_cut);

                if ((*v_ht400_Jethadronflavor)[i] == 4 || (*v_ht400_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht400_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht400_nTrack)[i], HT400_eventWeight);
                        h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht400_JetPt)[i], HT400_eventWeight);
                        h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht400_JetEta)[i], HT400_eventWeight);
                        h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht400_alpha)[i], HT400_eventWeight);
                    }
                }
            } // alpha cut
        }
    }
    TTree *T_tree5;
    DYHT600_1->GetObject("h1", T_tree5);
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
        h_DY_Met->Fill(I_ht600_met, HT600_eventWeight);
        for (size_t i = 0; i < v_ht600_alpha->size(); i++)
        {
            h_DY_alpha[0]->Fill((*v_ht600_alpha)[i], HT600_eventWeight);
        }
        for (size_t i = 0; i < v_ht600_alpha2->size(); i++)
        {
            h_DY_alpha[1]->Fill((*v_ht600_alpha2)[i], HT600_eventWeight);
        }
        for (size_t i = 0; i < v_ht600_alpha3->size(); i++)
        {
            h_DY_alpha[2]->Fill((*v_ht600_alpha3)[i], HT600_eventWeight);
        }
        for (size_t i = 0; i < v_ht600_alpha4->size(); i++)
        {
            h_DY_alpha[3]->Fill((*v_ht600_alpha4)[i], HT600_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_ht600_Chi3Dlog->size(); i++)
        {
            h_DY_Chi3Dlog->Fill((*v_ht600_Chi3Dlog)[i], HT600_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_ht600_2DIP->size(); i++)
        {
            h_DY_IP2D->Fill((*v_ht600_2DIP)[i], HT600_eventWeight);
        }
        for (size_t i = 0; i < v_ht600_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht600_nTrack)[i], HT600_eventWeight);
            h_DY_JetPt->Fill((*v_ht600_JetPt)[i], HT600_eventWeight);
            h_DY_JetEta->Fill((*v_ht600_JetEta)[i], HT600_eventWeight);
            h_DY_alpha3D->Fill((*v_ht600_alpha)[i], HT600_eventWeight);
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
            for_doubleflavor_jet(4, 5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_light);

            if ((*v_ht600_Jethadronflavor)[i] == 4 || (*v_ht600_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht600_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht600_nTrack)[i], HT600_eventWeight);
                    h_DY_JetPt_heavy_nogluon->Fill((*v_ht600_JetPt)[i], HT600_eventWeight);
                    h_DY_JetEta_heavy_nogluon->Fill((*v_ht600_JetEta)[i], HT600_eventWeight);
                    h_DY_alpha3D_heavy_nogluon->Fill((*v_ht600_alpha)[i], HT600_eventWeight);
                }
            }
            if ((*v_ht600_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht600_nTrack)[i], HT600_eventWeight);
                h_DY_JetPt_cut->Fill((*v_ht600_JetPt)[i], HT600_eventWeight);
                h_DY_JetEta_cut->Fill((*v_ht600_JetEta)[i], HT600_eventWeight);
                h_DY_alpha3D_cut->Fill((*v_ht600_alpha)[i], HT600_eventWeight);

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
                for_doubleflavor_jet(4, 5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_nTrack)[i], HT600_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetPt)[i], HT600_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_JetEta)[i], HT600_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_alpha)[i], HT600_eventWeight, h_DY_alpha3D_light_cut);

                if ((*v_ht600_Jethadronflavor)[i] == 4 || (*v_ht600_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht600_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht600_nTrack)[i], HT600_eventWeight);
                        h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht600_JetPt)[i], HT600_eventWeight);
                        h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht600_JetEta)[i], HT600_eventWeight);
                        h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht600_alpha)[i], HT600_eventWeight);
                    }
                }
            } // alpha cut
        }
    }
    TTree *T_tree6;
    DYHT800_1->GetObject("h1", T_tree6);
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

        h_DY_Met->Fill(I_ht800_met, HT800_eventWeight);
        for (size_t i = 0; i < v_ht800_alpha->size(); i++)
        {
            h_DY_alpha[0]->Fill((*v_ht800_alpha)[i], HT800_eventWeight);
        }
        for (size_t i = 0; i < v_ht800_alpha2->size(); i++)
        {
            h_DY_alpha[1]->Fill((*v_ht800_alpha2)[i], HT800_eventWeight);
        }
        for (size_t i = 0; i < v_ht800_alpha3->size(); i++)
        {
            h_DY_alpha[2]->Fill((*v_ht800_alpha3)[i], HT800_eventWeight);
        }
        for (size_t i = 0; i < v_ht800_alpha4->size(); i++)
        {
            h_DY_alpha[3]->Fill((*v_ht800_alpha4)[i], HT800_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_ht800_Chi3Dlog->size(); i++)
        {
            h_DY_Chi3Dlog->Fill((*v_ht800_Chi3Dlog)[i], HT800_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_ht800_2DIP->size(); i++)
        {
            h_DY_IP2D->Fill((*v_ht800_2DIP)[i], HT800_eventWeight);
        }
        for (size_t i = 0; i < v_ht800_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht800_nTrack)[i], HT800_eventWeight);
            h_DY_JetPt->Fill((*v_ht800_JetPt)[i], HT800_eventWeight);
            h_DY_JetEta->Fill((*v_ht800_JetEta)[i], HT800_eventWeight);
            h_DY_alpha3D->Fill((*v_ht800_alpha)[i], HT800_eventWeight);
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
            for_doubleflavor_jet(4, 5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_light);

            if ((*v_ht800_Jethadronflavor)[i] == 4 || (*v_ht800_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht800_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht800_nTrack)[i], HT800_eventWeight);
                    h_DY_JetPt_heavy_nogluon->Fill((*v_ht800_JetPt)[i], HT800_eventWeight);
                    h_DY_JetEta_heavy_nogluon->Fill((*v_ht800_JetEta)[i], HT800_eventWeight);
                    h_DY_alpha3D_heavy_nogluon->Fill((*v_ht800_alpha)[i], HT800_eventWeight);
                }
            }
            if ((*v_ht800_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht800_nTrack)[i], HT800_eventWeight);
                h_DY_JetPt_cut->Fill((*v_ht800_JetPt)[i], HT800_eventWeight);
                h_DY_JetEta_cut->Fill((*v_ht800_JetEta)[i], HT800_eventWeight);
                h_DY_alpha3D_cut->Fill((*v_ht800_alpha)[i], HT800_eventWeight);
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
                for_doubleflavor_jet(4, 5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_nTrack)[i], HT800_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetPt)[i], HT800_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_JetEta)[i], HT800_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_alpha)[i], HT800_eventWeight, h_DY_alpha3D_light_cut);

                if ((*v_ht800_Jethadronflavor)[i] == 4 || (*v_ht800_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht800_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht800_nTrack)[i], HT800_eventWeight);
                        h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht800_JetPt)[i], HT800_eventWeight);
                        h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht800_JetEta)[i], HT800_eventWeight);
                        h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht800_alpha)[i], HT800_eventWeight);
                    }
                }
            } // alpha cut
        }
    }
    TTree *T_tree7;
    DYHT1200_1->GetObject("h1", T_tree7);
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
        h_DY_Met->Fill(I_ht1200_met, HT1200_eventWeight);
        for (size_t i = 0; i < v_ht1200_alpha->size(); i++)
        {
            h_DY_alpha[0]->Fill((*v_ht1200_alpha)[i], HT1200_eventWeight);
        }
        for (size_t i = 0; i < v_ht1200_alpha2->size(); i++)
        {
            h_DY_alpha[1]->Fill((*v_ht1200_alpha2)[i], HT1200_eventWeight);
        }
        for (size_t i = 0; i < v_ht1200_alpha3->size(); i++)
        {
            h_DY_alpha[2]->Fill((*v_ht1200_alpha3)[i], HT1200_eventWeight);
        }
        for (size_t i = 0; i < v_ht1200_alpha4->size(); i++)
        {
            h_DY_alpha[3]->Fill((*v_ht1200_alpha4)[i], HT1200_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_ht1200_Chi3Dlog->size(); i++)
        {
            h_DY_Chi3Dlog->Fill((*v_ht1200_Chi3Dlog)[i], HT1200_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_ht1200_2DIP->size(); i++)
        {
            h_DY_IP2D->Fill((*v_ht1200_2DIP)[i], HT1200_eventWeight);
        }
        for (size_t i = 0; i < v_ht1200_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht1200_nTrack)[i], HT1200_eventWeight);
            h_DY_JetPt->Fill((*v_ht1200_JetPt)[i], HT1200_eventWeight);
            h_DY_JetEta->Fill((*v_ht1200_JetEta)[i], HT1200_eventWeight);
            h_DY_alpha3D->Fill((*v_ht1200_alpha)[i], HT1200_eventWeight);
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
            for_doubleflavor_jet(4, 5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_light);

            if ((*v_ht1200_Jethadronflavor)[i] == 4 || (*v_ht1200_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht1200_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht1200_nTrack)[i], HT1200_eventWeight);
                    h_DY_JetPt_heavy_nogluon->Fill((*v_ht1200_JetPt)[i], HT1200_eventWeight);
                    h_DY_JetEta_heavy_nogluon->Fill((*v_ht1200_JetEta)[i], HT1200_eventWeight);
                    h_DY_alpha3D_heavy_nogluon->Fill((*v_ht1200_alpha)[i], HT1200_eventWeight);
                }
            }
            if ((*v_ht1200_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht1200_nTrack)[i], HT1200_eventWeight);
                h_DY_JetPt_cut->Fill((*v_ht1200_JetPt)[i], HT1200_eventWeight);
                h_DY_JetEta_cut->Fill((*v_ht1200_JetEta)[i], HT1200_eventWeight);
                h_DY_alpha3D_cut->Fill((*v_ht1200_alpha)[i], HT1200_eventWeight);
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
                for_doubleflavor_jet(4, 5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_nTrack)[i], HT1200_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetPt)[i], HT1200_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_JetEta)[i], HT1200_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_alpha)[i], HT1200_eventWeight, h_DY_alpha3D_light_cut);

                if ((*v_ht1200_Jethadronflavor)[i] == 4 || (*v_ht1200_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht1200_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht1200_nTrack)[i], HT1200_eventWeight);
                        h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht1200_JetPt)[i], HT1200_eventWeight);
                        h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht1200_JetEta)[i], HT1200_eventWeight);
                        h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht1200_alpha)[i], HT1200_eventWeight);
                    }
                }
            } // alpha cut
        }
    }
    
    TTree *T_tree8;
    DYHT2500_1->GetObject("h1", T_tree8);
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
        h_DY_Met->Fill(I_ht2500_met, HT2500_eventWeight);
        for (size_t i = 0; i < v_ht2500_alpha->size(); i++)
        {
            h_DY_alpha[0]->Fill((*v_ht2500_alpha)[i], HT2500_eventWeight);
        }
        for (size_t i = 0; i < v_ht2500_alpha2->size(); i++)
        {
            h_DY_alpha[1]->Fill((*v_ht2500_alpha2)[i], HT2500_eventWeight);
        }
        for (size_t i = 0; i < v_ht2500_alpha3->size(); i++)
        {
            h_DY_alpha[2]->Fill((*v_ht2500_alpha3)[i], HT2500_eventWeight);
        }
        for (size_t i = 0; i < v_ht2500_alpha4->size(); i++)
        {
            h_DY_alpha[3]->Fill((*v_ht2500_alpha4)[i], HT2500_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_ht2500_Chi3Dlog->size(); i++)
        {
            h_DY_Chi3Dlog->Fill((*v_ht2500_Chi3Dlog)[i], HT2500_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_ht2500_2DIP->size(); i++)
        {
            h_DY_IP2D->Fill((*v_ht2500_2DIP)[i], HT2500_eventWeight);
        }
        for (size_t i = 0; i < v_ht2500_nTrack->size(); i++)
        {
            h_DY_nTracks->Fill((*v_ht2500_nTrack)[i], HT2500_eventWeight);
            h_DY_JetPt->Fill((*v_ht2500_JetPt)[i], HT2500_eventWeight);
            h_DY_JetEta->Fill((*v_ht2500_JetEta)[i], HT2500_eventWeight);
            h_DY_alpha3D->Fill((*v_ht2500_alpha)[i], HT2500_eventWeight);
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
            for_doubleflavor_jet(4, 5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_heavy);
            for_doubleflavor_jet(4, 5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_light);
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_light);
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_light);
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_light);

            if ((*v_ht2500_Jethadronflavor)[i] == 4 || (*v_ht2500_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht2500_Jetpartonflavor)[i] != 21)
                {
                    h_DY_nTracks_heavy_nogluon->Fill((*v_ht2500_nTrack)[i], HT2500_eventWeight);
                    h_DY_JetPt_heavy_nogluon->Fill((*v_ht2500_JetPt)[i], HT2500_eventWeight);
                    h_DY_JetEta_heavy_nogluon->Fill((*v_ht2500_JetEta)[i], HT2500_eventWeight);
                    h_DY_alpha3D_heavy_nogluon->Fill((*v_ht2500_alpha)[i], HT2500_eventWeight);
                }
            }
            if ((*v_ht2500_alpha)[i] < 0.15)
            {
                h_DY_nTracks_cut->Fill((*v_ht2500_nTrack)[i], HT2500_eventWeight);
                h_DY_JetPt_cut->Fill((*v_ht2500_JetPt)[i], HT2500_eventWeight);
                h_DY_JetEta_cut->Fill((*v_ht2500_JetEta)[i], HT2500_eventWeight);
                h_DY_alpha3D_cut->Fill((*v_ht2500_alpha)[i], HT2500_eventWeight);

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
                for_doubleflavor_jet(4, 5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_nTrack)[i], HT2500_eventWeight, h_DY_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetPt)[i], HT2500_eventWeight, h_DY_JetPt_light_cut);
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_JetEta)[i], HT2500_eventWeight, h_DY_JetEta_light_cut);
                for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_alpha)[i], HT2500_eventWeight, h_DY_alpha3D_light_cut);

                if ((*v_ht2500_Jethadronflavor)[i] == 4 || (*v_ht2500_Jethadronflavor)[i] == 5)
                {
                    if ((*v_ht2500_Jetpartonflavor)[i] != 21)
                    {
                        h_DY_nTracks_heavy_nogluon_cut->Fill((*v_ht2500_nTrack)[i], HT2500_eventWeight);
                        h_DY_JetPt_heavy_nogluon_cut->Fill((*v_ht2500_JetPt)[i], HT2500_eventWeight);
                        h_DY_JetEta_heavy_nogluon_cut->Fill((*v_ht2500_JetEta)[i], HT2500_eventWeight);
                        h_DY_alpha3D_heavy_nogluon_cut->Fill((*v_ht2500_alpha)[i], HT2500_eventWeight);
                    }
                }
            } // alpha cut
        }
    }

    TH1D *HT_fakeRate = (TH1D *)h_DY_nTracks_cut->Clone("HT_fakeRate");
    HT_fakeRate->Divide(h_DY_nTracks_cut, h_DY_nTracks, 1, 1, "b");

    TH1D *HT_heavy_fakeRate = (TH1D *)h_DY_nTracks_heavy_cut->Clone("HT_heavy_fakeRate");
    HT_heavy_fakeRate->Divide(h_DY_nTracks_heavy_cut, h_DY_nTracks_heavy, 1, 1, "b");

    TH1D *HT_bjet_fakeRate = (TH1D *)h_DY_nTracks_bjet_cut->Clone("HT_bjet_fakeRate");
    HT_bjet_fakeRate->Divide(h_DY_nTracks_bjet_cut, h_DY_nTracks_bjet, 1, 1, "b");

    TH1D *HT_cjet_fakeRate = (TH1D *)h_DY_nTracks_cjet_cut->Clone("HT_cjet_fakeRate");
    HT_cjet_fakeRate->Divide(h_DY_nTracks_cjet_cut, h_DY_nTracks_cjet, 1, 1, "b");

    TH1F *HT_heavy_nogluon_fakeRate = (TH1F *)h_DY_nTracks_heavy_nogluon_cut->Clone("HT_heavy_nogluon_fakeRate");
    HT_heavy_nogluon_fakeRate->Divide(h_DY_nTracks_heavy_nogluon_cut, h_DY_nTracks_heavy_nogluon, 1, 1, "b");

    TH1D *HT_light_fakeRate = (TH1D *)h_DY_nTracks_light_cut->Clone("HT_light_fakeRate");
    HT_light_fakeRate->Divide(h_DY_nTracks_light_cut, h_DY_nTracks_light, 1, 1, "b");

    HT_bjet_fakeRate->SetTitle("Drell-Yan b fake rate");
    HT_bjet_fakeRate->SetLineWidth(2);
    HT_bjet_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_bjet_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_bjet_fakeRate->Draw("");
    gStyle->SetOptStat(0);
    //HT_light_fakeRate->SetLineColor(kBlue);
    //h_DY_nTracks_bjet_cut->Draw("same");

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
    HT_heavy_nogluon_fakeRate->Write();
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