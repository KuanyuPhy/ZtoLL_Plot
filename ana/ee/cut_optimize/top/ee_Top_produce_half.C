#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <string>
#include <TCanvas.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../../lib/Cross_section.h"
//#include "./../../../lib/diff_region.C"
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

void ee_Top_produce_half(TString inputfile = "/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root", TString outputfile1 = "./ee_Top_emjet_half.root")
{
    TFile *TTTo2L2Nufile = TFile::Open(inputfile);
    TFile *Top_TTWJetsToLNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_TTZToLLNuNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_tW_antitopfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_topfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

    //-------------
    // Open Tree
    //-------------
    TFile *TTTo2L2Nufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTTo2L2Nu_1.root");
    TFile *Top_TTWJetsToLNufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTWJetsToLNu_1.root");
    TFile *Top_TTWJetsToQQfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTWJetsToQQ_1.root");
    TFile *Top_TTZToQQfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTZToQQ_1.root");
    TFile *Top_TTZToLLNuNufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTZToLLNuNu_1.root");
    TFile *Top_tW_antitopfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_tW_antitop_1.root");
    TFile *Top_tW_topfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_tW_top_1.root");

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)TTTo2L2Nufile->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNufile->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQfile->Get("Event_Variable/h_totevent"));
    TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQfile->Get("Event_Variable/h_totevent"));
    TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNufile->Get("Event_Variable/h_totevent"));
    TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitopfile->Get("Event_Variable/h_totevent"));
    TH1D *tW_top_sumevt = ((TH1D *)Top_tW_topfile->Get("Event_Variable/h_totevent"));

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

    TH1F *h_Top_alpha[4];
    for (int i = 0; i < 4; i++)
    {
        h_Top_alpha[i] = new TH1F(Form("h_Top_alpha_%d", i + 1), "", 24, 0, 1.2);
        h_Top_alpha[i]->Sumw2();
    }

    TH1F *h_Top_Met = new TH1F("h_Top_Met", "", 50, 0, 500);
    h_Top_Met->GetXaxis()->SetTitle("");
    h_Top_Met->GetYaxis()->SetTitle("");
    h_Top_Met->Sumw2();

    TH1F *h_Top_Chi3Dlog = new TH1F("h_Top_Chi3Dlog", "", 100, -10, 10);
    h_Top_Chi3Dlog->GetXaxis()->SetTitle("");
    h_Top_Chi3Dlog->GetYaxis()->SetTitle("");
    h_Top_Chi3Dlog->Sumw2();

    TH1F *h_Top_IP2D = new TH1F("h_Top_IP2D", "", 200, -20, 20);
    h_Top_IP2D->GetXaxis()->SetTitle("");
    h_Top_IP2D->GetYaxis()->SetTitle("");
    h_Top_IP2D->Sumw2();

    TH1F *h_Top_nTracks = new TH1F("h_Top_nTracks", "", 50, 0., 50);
    h_Top_nTracks->GetXaxis()->SetTitle("");
    h_Top_nTracks->GetYaxis()->SetTitle("");
    h_Top_nTracks->Sumw2();

    TH1F *h_Top_nTracks_tmp = new TH1F("h_Top_nTracks_tmp", "", 50, 0., 50);
    h_Top_nTracks_tmp->GetXaxis()->SetTitle("");
    h_Top_nTracks_tmp->GetYaxis()->SetTitle("");
    h_Top_nTracks_tmp->Sumw2();

    TH1F *h_Top_nTracks_heavy = new TH1F("h_Top_nTracks_heavy", "", 50, 0., 50);
    h_Top_nTracks_heavy->GetXaxis()->SetTitle("");
    h_Top_nTracks_heavy->GetYaxis()->SetTitle("");
    h_Top_nTracks_heavy->Sumw2();

    TH1F *h_Top_nTracks_bjet = new TH1F("h_Top_nTracks_bjet", "", 50, 0., 50);
    h_Top_nTracks_bjet->GetXaxis()->SetTitle("");
    h_Top_nTracks_bjet->GetYaxis()->SetTitle("");
    h_Top_nTracks_bjet->Sumw2();

    TH1F *h_Top_nTracks_cjet = new TH1F("h_Top_nTracks_cjet", "", 50, 0., 50);
    h_Top_nTracks_cjet->GetXaxis()->SetTitle("");
    h_Top_nTracks_cjet->GetYaxis()->SetTitle("");
    h_Top_nTracks_cjet->Sumw2();

    TH1F *h_Top_nTracks_light = new TH1F("h_Top_nTracks_light", "", 50, 0., 50);
    h_Top_nTracks_light->GetXaxis()->SetTitle("");
    h_Top_nTracks_light->GetYaxis()->SetTitle("");
    h_Top_nTracks_light->Sumw2();

    TH1F *h_Top_nTracks_cut = new TH1F("h_Top_nTracks_cut", "", 50, 0., 50);
    h_Top_nTracks_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_cut->Sumw2();

    TH1F *h_Top_nTracks_heavy_cut = new TH1F("h_Top_nTracks_heavy_cut", "", 50, 0., 50);
    h_Top_nTracks_heavy_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_heavy_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_heavy_cut->Sumw2();

    TH1F *h_Top_nTracks_bjet_cut = new TH1F("h_Top_nTracks_bjet_cut", "", 50, 0., 50);
    h_Top_nTracks_bjet_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_bjet_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_bjet_cut->Sumw2();

    TH1F *h_Top_nTracks_cjet_cut = new TH1F("h_Top_nTracks_cjet_cut", "", 50, 0., 50);
    h_Top_nTracks_cjet_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_cjet_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_cjet_cut->Sumw2();

    TH1F *h_Top_nTracks_light_cut = new TH1F("h_Top_nTracks_light_cut", "", 50, 0., 50);
    h_Top_nTracks_light_cut->GetXaxis()->SetTitle("");
    h_Top_nTracks_light_cut->GetYaxis()->SetTitle("");
    h_Top_nTracks_light_cut->Sumw2();

    TH1F *h_Top_jetpt = new TH1F("h_Top_jetpt", "", 50, 0, 500);
    h_Top_jetpt->GetXaxis()->SetTitle("");
    h_Top_jetpt->GetYaxis()->SetTitle("");
    h_Top_jetpt->Sumw2();

    TH1F *h_Top_jetpt_heavy = new TH1F("h_Top_jetpt_heavy", "", 50, 0, 500);
    h_Top_jetpt_heavy->GetXaxis()->SetTitle("");
    h_Top_jetpt_heavy->GetYaxis()->SetTitle("");
    h_Top_jetpt_heavy->Sumw2();

    TH1F *h_Top_jetpt_bjet = new TH1F("h_Top_jetpt_bjet", "", 50, 0, 500);
    h_Top_jetpt_bjet->GetXaxis()->SetTitle("");
    h_Top_jetpt_bjet->GetYaxis()->SetTitle("");
    h_Top_jetpt_bjet->Sumw2();

    TH1F *h_Top_jetpt_cjet = new TH1F("h_Top_jetpt_cjet", "", 50, 0, 500);
    h_Top_jetpt_cjet->GetXaxis()->SetTitle("");
    h_Top_jetpt_cjet->GetYaxis()->SetTitle("");
    h_Top_jetpt_cjet->Sumw2();

    TH1F *h_Top_jetpt_light = new TH1F("h_Top_jetpt_light", "", 50, 0, 500);
    h_Top_jetpt_light->GetXaxis()->SetTitle("");
    h_Top_jetpt_light->GetYaxis()->SetTitle("");
    h_Top_jetpt_light->Sumw2();

    TH1F *h_Top_jetpt_cut = new TH1F("h_Top_jetpt_cut", "", 50, 0, 500);
    h_Top_jetpt_cut->GetXaxis()->SetTitle("");
    h_Top_jetpt_cut->GetYaxis()->SetTitle("");
    h_Top_jetpt_cut->Sumw2();

    TH1F *h_Top_jetpt_heavy_cut = new TH1F("h_Top_jetpt_heavy_cut", "", 50, 0, 500);
    h_Top_jetpt_heavy_cut->GetXaxis()->SetTitle("");
    h_Top_jetpt_heavy_cut->GetYaxis()->SetTitle("");
    h_Top_jetpt_heavy_cut->Sumw2();

    TH1F *h_Top_jetpt_bjet_cut = new TH1F("h_Top_jetpt_bjet_cut", "", 50, 0, 500);
    h_Top_jetpt_bjet_cut->GetXaxis()->SetTitle("");
    h_Top_jetpt_bjet_cut->GetYaxis()->SetTitle("");
    h_Top_jetpt_bjet_cut->Sumw2();

    TH1F *h_Top_jetpt_cjet_cut = new TH1F("h_Top_jetpt_cjet_cut", "", 50, 0, 500);
    h_Top_jetpt_cjet_cut->GetXaxis()->SetTitle("");
    h_Top_jetpt_cjet_cut->GetYaxis()->SetTitle("");
    h_Top_jetpt_cjet_cut->Sumw2();

    TH1F *h_Top_jetpt_light_cut = new TH1F("h_Top_jetpt_light_cut", "", 50, 0, 500);
    h_Top_jetpt_light_cut->GetXaxis()->SetTitle("");
    h_Top_jetpt_light_cut->GetYaxis()->SetTitle("");
    h_Top_jetpt_light_cut->Sumw2();

    TH1F *h_Top_jeteta = new TH1F("h_Top_jeteta", "", 60, -3, 3);
    h_Top_jeteta->GetXaxis()->SetTitle("");
    h_Top_jeteta->GetYaxis()->SetTitle("");
    h_Top_jeteta->Sumw2();

    TH1F *h_Top_jeteta_heavy = new TH1F("h_Top_jeteta_heavy", "", 60, -3, 3);
    h_Top_jeteta_heavy->GetXaxis()->SetTitle("");
    h_Top_jeteta_heavy->GetYaxis()->SetTitle("");
    h_Top_jeteta_heavy->Sumw2();

    TH1F *h_Top_jeteta_bjet = new TH1F("h_Top_jeteta_bjet", "", 60, -3, 3);
    h_Top_jeteta_bjet->GetXaxis()->SetTitle("");
    h_Top_jeteta_bjet->GetYaxis()->SetTitle("");
    h_Top_jeteta_bjet->Sumw2();

    TH1F *h_Top_jeteta_cjet = new TH1F("h_Top_jeteta_cjet", "", 60, -3, 3);
    h_Top_jeteta_cjet->GetXaxis()->SetTitle("");
    h_Top_jeteta_cjet->GetYaxis()->SetTitle("");
    h_Top_jeteta_cjet->Sumw2();

    TH1F *h_Top_jeteta_light = new TH1F("h_Top_jeteta_light", "", 60, -3, 3);
    h_Top_jeteta_light->GetXaxis()->SetTitle("");
    h_Top_jeteta_light->GetYaxis()->SetTitle("");
    h_Top_jeteta_light->Sumw2();

    TH1F *h_Top_jeteta_cut = new TH1F("h_Top_jeteta_cut", "", 60, -3, 3);
    h_Top_jeteta_cut->GetXaxis()->SetTitle("");
    h_Top_jeteta_cut->GetYaxis()->SetTitle("");
    h_Top_jeteta_cut->Sumw2();

    TH1F *h_Top_jeteta_heavy_cut = new TH1F("h_Top_jeteta_heavy_cut", "", 60, -3, 3);
    h_Top_jeteta_heavy_cut->GetXaxis()->SetTitle("");
    h_Top_jeteta_heavy_cut->GetYaxis()->SetTitle("");
    h_Top_jeteta_heavy_cut->Sumw2();

    TH1F *h_Top_jeteta_bjet_cut = new TH1F("h_Top_jeteta_bjet_cut", "", 60, -3, 3);
    h_Top_jeteta_bjet_cut->GetXaxis()->SetTitle("");
    h_Top_jeteta_bjet_cut->GetYaxis()->SetTitle("");
    h_Top_jeteta_bjet_cut->Sumw2();

    TH1F *h_Top_jeteta_cjet_cut = new TH1F("h_Top_jeteta_cjet_cut", "", 60, -3, 3);
    h_Top_jeteta_cjet_cut->GetXaxis()->SetTitle("");
    h_Top_jeteta_cjet_cut->GetYaxis()->SetTitle("");
    h_Top_jeteta_cjet_cut->Sumw2();

    TH1F *h_Top_jeteta_light_cut = new TH1F("h_Top_jeteta_light_cut", "", 60, -3, 3);
    h_Top_jeteta_light_cut->GetXaxis()->SetTitle("");
    h_Top_jeteta_light_cut->GetYaxis()->SetTitle("");
    h_Top_jeteta_light_cut->Sumw2();

    TH1F *h_Top_alpha3D = new TH1F("h_Top_alpha3D", "", 24, 0, 1.2);
    h_Top_alpha3D->GetXaxis()->SetTitle("");
    h_Top_alpha3D->GetYaxis()->SetTitle("");
    h_Top_alpha3D->Sumw2();

    TH1F *h_Top_alpha3D_heavy = new TH1F("h_Top_alpha3D_heavy", "", 24, 0, 1.2);
    h_Top_alpha3D_heavy->GetXaxis()->SetTitle("");
    h_Top_alpha3D_heavy->GetYaxis()->SetTitle("");
    h_Top_alpha3D_heavy->Sumw2();

    TH1F *h_Top_alpha3D_bjet = new TH1F("h_Top_alpha3D_bjet", "", 24, 0, 1.2);
    h_Top_alpha3D_bjet->GetXaxis()->SetTitle("");
    h_Top_alpha3D_bjet->GetYaxis()->SetTitle("");
    h_Top_alpha3D_bjet->Sumw2();

    TH1F *h_Top_alpha3D_cjet = new TH1F("h_Top_alpha3D_cjet", "", 24, 0, 1.2);
    h_Top_alpha3D_cjet->GetXaxis()->SetTitle("");
    h_Top_alpha3D_cjet->GetYaxis()->SetTitle("");
    h_Top_alpha3D_cjet->Sumw2();

    TH1F *h_Top_alpha3D_light = new TH1F("h_Top_alpha3D_light", "", 24, 0, 1.2);
    h_Top_alpha3D_light->GetXaxis()->SetTitle("");
    h_Top_alpha3D_light->GetYaxis()->SetTitle("");
    h_Top_alpha3D_light->Sumw2();

    TH1F *h_Top_alpha3D_cut = new TH1F("h_Top_alpha3D_cut", "", 24, 0, 1.2);
    h_Top_alpha3D_cut->GetXaxis()->SetTitle("");
    h_Top_alpha3D_cut->GetYaxis()->SetTitle("");
    h_Top_alpha3D_cut->Sumw2();

    TH1F *h_Top_alpha3D_heavy_cut = new TH1F("h_Top_alpha3D_heavy_cut", "", 24, 0, 1.2);
    h_Top_alpha3D_heavy_cut->GetXaxis()->SetTitle("");
    h_Top_alpha3D_heavy_cut->GetYaxis()->SetTitle("");
    h_Top_alpha3D_heavy_cut->Sumw2();

    TH1F *h_Top_alpha3D_bjet_cut = new TH1F("h_Top_alpha3D_bjet_cut", "", 24, 0, 1.2);
    h_Top_alpha3D_bjet_cut->GetXaxis()->SetTitle("");
    h_Top_alpha3D_bjet_cut->GetYaxis()->SetTitle("");
    h_Top_alpha3D_bjet_cut->Sumw2();

    TH1F *h_Top_alpha3D_cjet_cut = new TH1F("h_Top_alpha3D_cjet_cut", "", 24, 0, 1.2);
    h_Top_alpha3D_cjet_cut->GetXaxis()->SetTitle("");
    h_Top_alpha3D_cjet_cut->GetYaxis()->SetTitle("");
    h_Top_alpha3D_cjet_cut->Sumw2();

    TH1F *h_Top_alpha3D_light_cut = new TH1F("h_Top_alpha3D_light_cut", "", 24, 0, 1.2);
    h_Top_alpha3D_light_cut->GetXaxis()->SetTitle("");
    h_Top_alpha3D_light_cut->GetYaxis()->SetTitle("");
    h_Top_alpha3D_light_cut->Sumw2();

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
    TTTo2L2Nufile_1->GetObject("h1", T_TTTo2L2Nu_tree);
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

        h_Top_Met->Fill(f_TTTo2L2Nu_met, TTTo2L2Nu_eventWeight);
        for (size_t i = 0; i < v_TTTo2L2Nu_alpha->size(); i++)
        {
            h_Top_alpha[0]->Fill((*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight);
        }
        for (size_t i = 0; i < v_TTTo2L2Nu_alpha2->size(); i++)
        {
            h_Top_alpha[1]->Fill((*v_TTTo2L2Nu_alpha2)[i], TTTo2L2Nu_eventWeight);
        }
        for (size_t i = 0; i < v_TTTo2L2Nu_alpha3->size(); i++)
        {
            h_Top_alpha[2]->Fill((*v_TTTo2L2Nu_alpha3)[i], TTTo2L2Nu_eventWeight);
        }
        for (size_t i = 0; i < v_TTTo2L2Nu_alpha4->size(); i++)
        {
            h_Top_alpha[3]->Fill((*v_TTTo2L2Nu_alpha4)[i], TTTo2L2Nu_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_TTTo2L2Nu_Chi3Dlog->size(); i++)
        {
            h_Top_Chi3Dlog->Fill((*v_TTTo2L2Nu_Chi3Dlog)[i], TTTo2L2Nu_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_TTTo2L2Nu_2DIP->size(); i++)
        {
            h_Top_IP2D->Fill((*v_TTTo2L2Nu_2DIP)[i], TTTo2L2Nu_eventWeight);
        }
        for (size_t i = 0; i < v_TTTo2L2Nu_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight);
            h_Top_jetpt->Fill((*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight);
            h_Top_jeteta->Fill((*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight);
            h_Top_alpha3D->Fill((*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_jetpt_bjet);
            for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight, h_Top_jeteta_bjet);
            for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight, h_Top_alpha3D_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_jetpt_cjet);
            for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight, h_Top_jeteta_cjet);
            for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight, h_Top_alpha3D_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_jetpt_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight, h_Top_jeteta_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight, h_Top_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_light);
            for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_jetpt_light);
            for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight, h_Top_jeteta_light);
            for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight, h_Top_alpha3D_light);

            if ((*v_TTTo2L2Nu_alpha)[i] < 0.15)
            {

                h_Top_nTracks_cut->Fill((*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight);
                h_Top_jetpt_cut->Fill((*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight);
                h_Top_jeteta_cut->Fill((*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight);
                h_Top_alpha3D_cut->Fill((*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight, h_Top_alpha3D_bjet_cut);

                // For c jet
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight, h_Top_alpha3D_cjet_cut);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_jetpt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight, h_Top_jeteta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight, h_Top_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetEta)[i], TTTo2L2Nu_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_alpha)[i], TTTo2L2Nu_eventWeight, h_Top_alpha3D_light_cut);

            } // alpha cut
        }
    } // End of TTTo2L2Nu

    TTree *T_ST_tW_top_tree;
    Top_tW_topfile_1->GetObject("h1", T_ST_tW_top_tree);
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

        h_Top_Met->Fill(f_ST_tW_top_met, ST_tW_top_eventWeight);
        for (size_t i = 0; i < v_ST_tW_top_alpha->size(); i++)
        {
            h_Top_alpha[0]->Fill((*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight);
        }
        for (size_t i = 0; i < v_ST_tW_top_alpha2->size(); i++)
        {
            h_Top_alpha[1]->Fill((*v_ST_tW_top_alpha2)[i], ST_tW_top_eventWeight);
        }
        for (size_t i = 0; i < v_ST_tW_top_alpha3->size(); i++)
        {
            h_Top_alpha[2]->Fill((*v_ST_tW_top_alpha3)[i], ST_tW_top_eventWeight);
        }
        for (size_t i = 0; i < v_ST_tW_top_alpha4->size(); i++)
        {
            h_Top_alpha[3]->Fill((*v_ST_tW_top_alpha4)[i], ST_tW_top_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_ST_tW_top_Chi3Dlog->size(); i++)
        {
            h_Top_Chi3Dlog->Fill((*v_ST_tW_top_Chi3Dlog)[i], ST_tW_top_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_ST_tW_top_2DIP->size(); i++)
        {
            h_Top_IP2D->Fill((*v_ST_tW_top_2DIP)[i], ST_tW_top_eventWeight);
        }
        for (size_t i = 0; i < v_ST_tW_top_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight);
            h_Top_jetpt->Fill((*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight);
            h_Top_jeteta->Fill((*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight);
            h_Top_alpha3D->Fill((*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_jetpt_bjet);
            for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight, h_Top_jeteta_bjet);
            for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight, h_Top_alpha3D_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_jetpt_cjet);
            for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight, h_Top_jeteta_cjet);
            for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight, h_Top_alpha3D_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_jetpt_heavy);
            for_doubleflavor_jet(4, 5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight, h_Top_jeteta_heavy);
            for_doubleflavor_jet(4, 5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight, h_Top_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_light);
            for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_jetpt_light);
            for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight, h_Top_jeteta_light);
            for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight, h_Top_alpha3D_light);

            if ((*v_ST_tW_top_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight);
                h_Top_jetpt_cut->Fill((*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight);
                h_Top_jeteta_cut->Fill((*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight);
                h_Top_alpha3D_cut->Fill((*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight, h_Top_alpha3D_bjet_cut);

                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight, h_Top_alpha3D_cjet_cut);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_jetpt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight, h_Top_jeteta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight, h_Top_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetEta)[i], ST_tW_top_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_alpha)[i], ST_tW_top_eventWeight, h_Top_alpha3D_light_cut);

            } // alpha cut
        }
    } // End of ST_tW_top_tree

    TTree *T_ST_tW_antitop_tree;
    Top_tW_antitopfile_1->GetObject("h1", T_ST_tW_antitop_tree);
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

        h_Top_Met->Fill(f_ST_tW_antitop_met, ST_tW_antitop_eventWeight);
        for (size_t i = 0; i < v_ST_tW_antitop_alpha->size(); i++)
        {
            h_Top_alpha[0]->Fill((*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight);
        }
        for (size_t i = 0; i < v_ST_tW_antitop_alpha2->size(); i++)
        {
            h_Top_alpha[1]->Fill((*v_ST_tW_antitop_alpha2)[i], ST_tW_antitop_eventWeight);
        }
        for (size_t i = 0; i < v_ST_tW_antitop_alpha3->size(); i++)
        {
            h_Top_alpha[2]->Fill((*v_ST_tW_antitop_alpha3)[i], ST_tW_antitop_eventWeight);
        }
        for (size_t i = 0; i < v_ST_tW_antitop_alpha4->size(); i++)
        {
            h_Top_alpha[3]->Fill((*v_ST_tW_antitop_alpha4)[i], ST_tW_antitop_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_ST_tW_antitop_Chi3Dlog->size(); i++)
        {
            h_Top_Chi3Dlog->Fill((*v_ST_tW_antitop_Chi3Dlog)[i], ST_tW_antitop_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_ST_tW_antitop_2DIP->size(); i++)
        {
            h_Top_IP2D->Fill((*v_ST_tW_antitop_2DIP)[i], ST_tW_antitop_eventWeight);
        }
        for (size_t i = 0; i < v_ST_tW_antitop_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight);
            h_Top_jetpt->Fill((*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight);
            h_Top_jeteta->Fill((*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight);
            h_Top_alpha3D->Fill((*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_jetpt_bjet);
            for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight, h_Top_jeteta_bjet);
            for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight, h_Top_alpha3D_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_jetpt_cjet);
            for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight, h_Top_jeteta_cjet);
            for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight, h_Top_alpha3D_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_jetpt_heavy);
            for_doubleflavor_jet(4, 5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight, h_Top_jeteta_heavy);
            for_doubleflavor_jet(4, 5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight, h_Top_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_light);
            for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_jetpt_light);
            for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight, h_Top_jeteta_light);
            for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight, h_Top_alpha3D_light);

            if ((*v_ST_tW_antitop_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight);
                h_Top_jetpt_cut->Fill((*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight);
                h_Top_jeteta_cut->Fill((*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight);
                h_Top_alpha3D_cut->Fill((*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight, h_Top_alpha3D_bjet_cut);

                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight, h_Top_alpha3D_cjet_cut);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_jetpt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight, h_Top_jeteta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight, h_Top_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetEta)[i], ST_tW_antitop_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_alpha)[i], ST_tW_antitop_eventWeight, h_Top_alpha3D_light_cut);

            } // alpha cut
        }
    } // End of ST_tW_antitop

    TTree *T_TTWJetsToLNu_tree;
    Top_TTWJetsToLNufile_1->GetObject("h1", T_TTWJetsToLNu_tree);
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
        h_Top_Met->Fill(f_TTWJetsToLNu_met, TTWJetsToLNu_eventWeight);
        for (size_t i = 0; i < v_TTWJetsToLNu_alpha->size(); i++)
        {
            h_Top_alpha[0]->Fill((*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight);
        }
        for (size_t i = 0; i < v_TTWJetsToLNu_alpha2->size(); i++)
        {
            h_Top_alpha[1]->Fill((*v_TTWJetsToLNu_alpha2)[i], TTWJetsToLNu_eventWeight);
        }
        for (size_t i = 0; i < v_TTWJetsToLNu_alpha3->size(); i++)
        {
            h_Top_alpha[2]->Fill((*v_TTWJetsToLNu_alpha3)[i], TTWJetsToLNu_eventWeight);
        }
        for (size_t i = 0; i < v_TTWJetsToLNu_alpha4->size(); i++)
        {
            h_Top_alpha[3]->Fill((*v_TTWJetsToLNu_alpha4)[i], TTWJetsToLNu_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_TTWJetsToLNu_Chi3Dlog->size(); i++)
        {
            h_Top_Chi3Dlog->Fill((*v_TTWJetsToLNu_Chi3Dlog)[i], TTWJetsToLNu_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_TTWJetsToLNu_2DIP->size(); i++)
        {
            h_Top_IP2D->Fill((*v_TTWJetsToLNu_2DIP)[i], TTWJetsToLNu_eventWeight);
        }
        for (size_t i = 0; i < v_TTWJetsToLNu_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight);
            h_Top_jetpt->Fill((*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight);
            h_Top_jeteta->Fill((*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight);
            h_Top_alpha3D->Fill((*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_jetpt_bjet);
            for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight, h_Top_jeteta_bjet);
            for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight, h_Top_alpha3D_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_jetpt_cjet);
            for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight, h_Top_jeteta_cjet);
            for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight, h_Top_alpha3D_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_jetpt_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight, h_Top_jeteta_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight, h_Top_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_light);
            for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_jetpt_light);
            for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight, h_Top_jeteta_light);
            for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight, h_Top_alpha3D_light);

            if ((*v_TTWJetsToLNu_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight);
                h_Top_jetpt_cut->Fill((*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight);
                h_Top_jeteta_cut->Fill((*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight);
                h_Top_alpha3D_cut->Fill((*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight, h_Top_alpha3D_bjet_cut);

                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight, h_Top_alpha3D_cjet_cut);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_jetpt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight, h_Top_jeteta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight, h_Top_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetEta)[i], TTWJetsToLNu_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_alpha)[i], TTWJetsToLNu_eventWeight, h_Top_alpha3D_light_cut);

            } // alpha cut
        }
    } // End of TTWJetsToLNu

    TTree *T_TTWJetsToQQ_tree;
    Top_TTWJetsToQQfile_1->GetObject("h1", T_TTWJetsToQQ_tree);
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

        h_Top_Met->Fill(f_TTWJetsToQQ_met, TTWJetsToQQ_eventWeight);
        for (size_t i = 0; i < v_TTWJetsToQQ_alpha->size(); i++)
        {
            h_Top_alpha[0]->Fill((*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight);
        }
        for (size_t i = 0; i < v_TTWJetsToQQ_alpha2->size(); i++)
        {
            h_Top_alpha[1]->Fill((*v_TTWJetsToQQ_alpha2)[i], TTWJetsToQQ_eventWeight);
        }
        for (size_t i = 0; i < v_TTWJetsToQQ_alpha3->size(); i++)
        {
            h_Top_alpha[2]->Fill((*v_TTWJetsToQQ_alpha3)[i], TTWJetsToQQ_eventWeight);
        }
        for (size_t i = 0; i < v_TTWJetsToQQ_alpha4->size(); i++)
        {
            h_Top_alpha[3]->Fill((*v_TTWJetsToQQ_alpha4)[i], TTWJetsToQQ_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_TTWJetsToQQ_Chi3Dlog->size(); i++)
        {
            h_Top_Chi3Dlog->Fill((*v_TTWJetsToQQ_Chi3Dlog)[i], TTWJetsToQQ_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_TTWJetsToQQ_2DIP->size(); i++)
        {
            h_Top_IP2D->Fill((*v_TTWJetsToQQ_2DIP)[i], TTWJetsToQQ_eventWeight);
        }
        for (size_t i = 0; i < v_TTWJetsToQQ_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight);
            h_Top_jetpt->Fill((*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight);
            h_Top_jeteta->Fill((*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight);
            h_Top_alpha3D->Fill((*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_jetpt_bjet);
            for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight, h_Top_jeteta_bjet);
            for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight, h_Top_alpha3D_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_jetpt_cjet);
            for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight, h_Top_jeteta_cjet);
            for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight, h_Top_alpha3D_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_jetpt_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight, h_Top_jeteta_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight, h_Top_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_light);
            for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_jetpt_light);
            for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight, h_Top_jeteta_light);
            for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight, h_Top_alpha3D_light);

            if ((*v_TTWJetsToQQ_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight);
                h_Top_jetpt_cut->Fill((*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight);
                h_Top_jeteta_cut->Fill((*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight);
                h_Top_alpha3D_cut->Fill((*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight, h_Top_alpha3D_bjet_cut);

                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight, h_Top_alpha3D_cjet_cut);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_jetpt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight, h_Top_jeteta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight, h_Top_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_JetEta)[i], TTWJetsToQQ_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_alpha)[i], TTWJetsToQQ_eventWeight, h_Top_alpha3D_light_cut);

            } // alpha cut
        }
    } // End of TTWJetsToQQ

    TTree *T_TTZToQQ_tree;
    Top_TTZToQQfile_1->GetObject("h1", T_TTZToQQ_tree);
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

        h_Top_Met->Fill(f_TTZToQQ_met, TTZToQQ_eventWeight);
        for (size_t i = 0; i < v_TTZToQQ_alpha->size(); i++)
        {
            h_Top_alpha[0]->Fill((*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight);
        }
        for (size_t i = 0; i < v_TTZToQQ_alpha2->size(); i++)
        {
            h_Top_alpha[1]->Fill((*v_TTZToQQ_alpha2)[i], TTZToQQ_eventWeight);
        }
        for (size_t i = 0; i < v_TTZToQQ_alpha3->size(); i++)
        {
            h_Top_alpha[2]->Fill((*v_TTZToQQ_alpha3)[i], TTZToQQ_eventWeight);
        }
        for (size_t i = 0; i < v_TTZToQQ_alpha4->size(); i++)
        {
            h_Top_alpha[3]->Fill((*v_TTZToQQ_alpha4)[i], TTZToQQ_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_TTZToQQ_Chi3Dlog->size(); i++)
        {
            h_Top_Chi3Dlog->Fill((*v_TTZToQQ_Chi3Dlog)[i], TTZToQQ_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_TTZToQQ_2DIP->size(); i++)
        {
            h_Top_IP2D->Fill((*v_TTZToQQ_2DIP)[i], TTZToQQ_eventWeight);
        }
        for (size_t i = 0; i < v_TTZToQQ_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight);
            h_Top_jetpt->Fill((*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight);
            h_Top_jeteta->Fill((*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight);
            h_Top_alpha3D->Fill((*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_jetpt_bjet);
            for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight, h_Top_jeteta_bjet);
            for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight, h_Top_alpha3D_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_jetpt_cjet);
            for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight, h_Top_jeteta_cjet);
            for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight, h_Top_alpha3D_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_jetpt_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight, h_Top_jeteta_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight, h_Top_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_light);
            for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_jetpt_light);
            for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight, h_Top_jeteta_light);
            for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight, h_Top_alpha3D_light);

            if ((*v_TTZToQQ_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight);
                h_Top_jetpt_cut->Fill((*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight);
                h_Top_jeteta_cut->Fill((*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight);
                h_Top_alpha3D_cut->Fill((*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight, h_Top_alpha3D_bjet_cut);

                // For c jet
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight, h_Top_alpha3D_cjet_cut);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_jetpt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight, h_Top_jeteta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight, h_Top_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetEta)[i], TTZToQQ_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_alpha)[i], TTZToQQ_eventWeight, h_Top_alpha3D_light_cut);

            } // alpha cut
        }
    } // End of TTZToQQ

    TTree *T_TTZToLLNuNu_tree;
    Top_TTZToLLNuNufile_1->GetObject("h1", T_TTZToLLNuNu_tree);
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

        h_Top_Met->Fill(f_TTZToLLNuNu_met, TTZToLLNuNu_eventWeight);
        for (size_t i = 0; i < v_TTZToLLNuNu_alpha->size(); i++)
        {
            h_Top_alpha[0]->Fill((*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight);
        }
        for (size_t i = 0; i < v_TTZToLLNuNu_alpha2->size(); i++)
        {
            h_Top_alpha[1]->Fill((*v_TTZToLLNuNu_alpha2)[i], TTZToLLNuNu_eventWeight);
        }
        for (size_t i = 0; i < v_TTZToLLNuNu_alpha3->size(); i++)
        {
            h_Top_alpha[2]->Fill((*v_TTZToLLNuNu_alpha3)[i], TTZToLLNuNu_eventWeight);
        }
        for (size_t i = 0; i < v_TTZToLLNuNu_alpha4->size(); i++)
        {
            h_Top_alpha[3]->Fill((*v_TTZToLLNuNu_alpha4)[i], TTZToLLNuNu_eventWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_TTZToLLNuNu_Chi3Dlog->size(); i++)
        {
            h_Top_Chi3Dlog->Fill((*v_TTZToLLNuNu_Chi3Dlog)[i], TTZToLLNuNu_eventWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_TTZToLLNuNu_2DIP->size(); i++)
        {
            h_Top_IP2D->Fill((*v_TTZToLLNuNu_2DIP)[i], TTZToLLNuNu_eventWeight);
        }
        for (size_t i = 0; i < v_TTZToLLNuNu_nTrack->size(); i++)
        {
            h_Top_nTracks->Fill((*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight);
            h_Top_jetpt->Fill((*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight);
            h_Top_jeteta->Fill((*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight);
            h_Top_alpha3D->Fill((*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight);

            // For b jet
            for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet);
            for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_jetpt_bjet);
            for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight, h_Top_jeteta_bjet);
            for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight, h_Top_alpha3D_bjet);

            // For c jet
            for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet);
            for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_jetpt_cjet);
            for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight, h_Top_jeteta_cjet);
            for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight, h_Top_alpha3D_cjet);

            // For heavy flavor
            for_doubleflavor_jet(4, 5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_jetpt_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight, h_Top_jeteta_heavy);
            for_doubleflavor_jet(4, 5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight, h_Top_alpha3D_heavy);

            // For light flavor
            for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_light);
            for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_jetpt_light);
            for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight, h_Top_jeteta_light);
            for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight, h_Top_alpha3D_light);

            if ((*v_TTZToLLNuNu_alpha)[i] < 0.15)
            {
                h_Top_nTracks_cut->Fill((*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight);
                h_Top_jetpt_cut->Fill((*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight);
                h_Top_jeteta_cut->Fill((*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight);
                h_Top_alpha3D_cut->Fill((*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight);

                // For b jet
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_jetpt_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight, h_Top_jeteta_bjet_cut);
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight, h_Top_alpha3D_bjet_cut);

                // For c jet
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_jetpt_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight, h_Top_jeteta_cjet_cut);
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight, h_Top_alpha3D_cjet_cut);

                // For heavy flavor
                for_doubleflavor_jet(4, 5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_jetpt_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight, h_Top_jeteta_heavy_cut);
                for_doubleflavor_jet(4, 5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight, h_Top_alpha3D_heavy_cut);

                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_light_cut);
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_jetpt_light_cut);
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetEta)[i], TTZToLLNuNu_eventWeight, h_Top_jeteta_light_cut);
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_alpha)[i], TTZToLLNuNu_eventWeight, h_Top_alpha3D_light_cut);

            } // alpha cut
        }
    } // End of TTZToLLNuNu

    h_Top_IP2D->SetLineWidth(2);
    h_Top_IP2D->Draw();

    TH1F *Top_fakeRate = (TH1F *)h_Top_nTracks_cut->Clone("Top_fakeRate");
    Top_fakeRate->Divide(h_Top_nTracks_cut, h_Top_nTracks, 1, 1, "b");

    TH1F *Top_light_fakeRate = (TH1F *)h_Top_nTracks_light_cut->Clone("Top_light_fakeRate");
    Top_light_fakeRate->Divide(h_Top_nTracks_light_cut, h_Top_nTracks_light, 1, 1, "b");
    Top_light_fakeRate->SetTitle("Top process light flavor fake rate");
    Top_light_fakeRate->GetYaxis()->SetTitle("fake rate");
    Top_light_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    Top_light_fakeRate->SetLineWidth(2);

    TH1F *Top_heavy_fakeRate = (TH1F *)h_Top_nTracks_heavy_cut->Clone("Top_heavy_fakeRate");
    Top_heavy_fakeRate->Divide(h_Top_nTracks_heavy_cut, h_Top_nTracks_heavy, 1, 1, "b");

    TH1F *Top_bjet_fakeRate = (TH1F *)h_Top_nTracks_bjet_cut->Clone("Top_bjet_fakeRate");
    Top_bjet_fakeRate->Divide(h_Top_nTracks_bjet_cut, h_Top_nTracks_bjet, 1, 1, "b");
    Top_bjet_fakeRate->SetTitle("Top process b flavor fake rate");
    Top_bjet_fakeRate->GetYaxis()->SetTitle("fake rate");
    Top_bjet_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    Top_bjet_fakeRate->SetLineWidth(2);

    TH1F *Top_cjet_fakeRate = (TH1F *)h_Top_nTracks_cjet_cut->Clone("Top_cjet_fakeRate");
    Top_cjet_fakeRate->Divide(h_Top_nTracks_cjet_cut, h_Top_nTracks_cjet, 1, 1, "b");
    Top_cjet_fakeRate->SetTitle("Top process c flavor fake rate");
    Top_cjet_fakeRate->GetYaxis()->SetTitle("fake rate");
    Top_cjet_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    Top_cjet_fakeRate->SetLineWidth(2);

    //-----------------
    // Jet PT
    //-----------------
    TH1F *Top_lightPT_fakeRate = (TH1F *)h_Top_jetpt_light_cut->Clone("Top_lightPT_fakeRate");
    Top_lightPT_fakeRate->Divide(h_Top_jetpt_light_cut, h_Top_jetpt_light, 1, 1, "b");
    Top_lightPT_fakeRate->SetTitle("Top process light flavor fake rate");
    Top_lightPT_fakeRate->GetYaxis()->SetTitle("fake rate");
    Top_lightPT_fakeRate->GetXaxis()->SetTitle("Jet PT");
    Top_lightPT_fakeRate->SetLineWidth(2);

    TH1F *Top_bjetPT_fakeRate = (TH1F *)h_Top_jetpt_bjet_cut->Clone("Top_bjetPT_fakeRate");
    Top_bjetPT_fakeRate->Divide(h_Top_jetpt_bjet_cut, h_Top_jetpt_bjet, 1, 1, "b");
    Top_bjetPT_fakeRate->SetTitle("Top process b flavor fake rate");
    Top_bjetPT_fakeRate->GetYaxis()->SetTitle("fake rate");
    Top_bjetPT_fakeRate->GetXaxis()->SetTitle("Jet PT");
    Top_bjetPT_fakeRate->SetLineWidth(2);

    TH1F *Top_cjetPT_fakeRate = (TH1F *)h_Top_jetpt_cjet_cut->Clone("Top_cjetPT_fakeRate");
    Top_cjetPT_fakeRate->Divide(h_Top_jetpt_cjet_cut, h_Top_jetpt_cjet, 1, 1, "b");
    Top_cjetPT_fakeRate->SetTitle("Top process c flavor fake rate");
    Top_cjetPT_fakeRate->GetYaxis()->SetTitle("fake rate");
    Top_cjetPT_fakeRate->GetXaxis()->SetTitle("Jet PT");
    Top_cjetPT_fakeRate->SetLineWidth(2);
    //-----------------
    // Jet Eta
    //-----------------
    TH1F *Top_lightEta_fakeRate = (TH1F *)h_Top_jeteta_light_cut->Clone("Top_lightEta_fakeRate");
    Top_lightEta_fakeRate->Divide(h_Top_jeteta_light_cut, h_Top_jeteta_light, 1, 1, "b");
    Top_lightEta_fakeRate->SetTitle("Top process light flavor fake rate");
    Top_lightEta_fakeRate->GetYaxis()->SetTitle("fake rate");
    Top_lightEta_fakeRate->GetXaxis()->SetTitle("Jet #eta");
    Top_lightEta_fakeRate->SetLineWidth(2);

    TH1F *Top_bjetEta_fakeRate = (TH1F *)h_Top_jeteta_bjet_cut->Clone("Top_bjetEta_fakeRate");
    Top_bjetEta_fakeRate->Divide(h_Top_jeteta_bjet_cut, h_Top_jeteta_bjet, 1, 1, "b");
    Top_bjetEta_fakeRate->SetTitle("Top process b flavor fake rate");
    Top_bjetEta_fakeRate->GetYaxis()->SetTitle("fake rate");
    Top_bjetEta_fakeRate->GetXaxis()->SetTitle("Jet #eta");
    Top_bjetEta_fakeRate->SetLineWidth(2);

    TH1F *Top_cjetEta_fakeRate = (TH1F *)h_Top_jeteta_cjet_cut->Clone("Top_cjetEta_fakeRate");
    Top_cjetEta_fakeRate->Divide(h_Top_jeteta_cjet_cut, h_Top_jeteta_cjet, 1, 1, "b");
    Top_cjetEta_fakeRate->SetTitle("Top process c flavor fake rate");
    Top_cjetEta_fakeRate->GetYaxis()->SetTitle("fake rate");
    Top_cjetEta_fakeRate->GetXaxis()->SetTitle("Jet #eta");
    Top_cjetEta_fakeRate->SetLineWidth(2);
    auto c1 = new TCanvas("c1", "", 700, 700);
    // c1->Divide(3, 1);
    // c1->cd(1);
    /*
    Top_light_fakeRate->SetTitle("fakeRate vs track multiplicity");
    Top_light_fakeRate->SetLineColor(kGreen);
    Top_bjet_fakeRate->SetLineColor(kRed);
    Top_cjet_fakeRate->SetLineColor(kBlack);
    Top_light_fakeRate->Draw("");
    Top_bjet_fakeRate->Draw("same");
    Top_cjet_fakeRate->Draw("same");
    */
    /*
    Top_lightPT_fakeRate->SetTitle("fakeRate vs Jet Pt");
    Top_lightPT_fakeRate->SetLineColor(kGreen);
    Top_bjetPT_fakeRate->SetLineColor(kRed);
    Top_cjetPT_fakeRate->SetLineColor(kBlack);
    Top_lightPT_fakeRate->Draw("");
    Top_bjetPT_fakeRate->Draw("same");
    Top_cjetPT_fakeRate->Draw("same");
    */
    Top_lightEta_fakeRate->SetTitle("fakeRate vs Jet Pt");
    Top_lightEta_fakeRate->SetLineColor(kGreen);
    Top_bjetEta_fakeRate->SetLineColor(kRed);
    Top_cjetEta_fakeRate->SetLineColor(kBlack);
    Top_lightEta_fakeRate->Draw("");
    Top_bjetEta_fakeRate->Draw("same");
    Top_cjetEta_fakeRate->Draw("same");
    gPad->SetLogy();
    gStyle->SetOptStat(0);
    TLegend *l0 = new TLegend(0.65, 0.6, 0.90, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->SetHeader("Top process");
    l0->AddEntry(Top_lightPT_fakeRate, "light flavor", "l");
    l0->AddEntry(Top_bjetPT_fakeRate, "b flavor", "l");
    l0->AddEntry(Top_cjetPT_fakeRate, "c flavor", "l");
    //l0->Draw();
    /*
    c1->cd(2);
    Top_lightPT_fakeRate->SetLineColor(kGreen);
    Top_bjetPT_fakeRate->SetLineColor(kRed);
    Top_cjetPT_fakeRate->SetLineColor(kBlack);
    Top_lightPT_fakeRate->Draw("");
    Top_bjetPT_fakeRate->Draw("same");
    Top_cjetPT_fakeRate->Draw("same");
    gPad->SetLogy();
    //->Draw("");
    c1->cd(3);
    Top_lightEta_fakeRate->SetLineColor(kGreen);
    Top_bjetEta_fakeRate->SetLineColor(kRed);
    Top_cjetEta_fakeRate->SetLineColor(kBlack);
    Top_lightEta_fakeRate->Draw("");
    Top_bjetEta_fakeRate->Draw("same");
    Top_cjetEta_fakeRate->Draw("same");
    gPad->SetLogy();
    */
    //->Draw("");
    // c1->cd(4);
    // Top_lightPT_fakeRate->Draw("");
    // c1->cd(5);
    // Top_bjetPT_fakeRate->Draw("");
    // c1->cd(6);
    // Top_cjetPT_fakeRate->Draw("");
    // c1->cd(7);
    // Top_lightEta_fakeRate->Draw("");
    // c1->cd(8);
    // Top_bjetEta_fakeRate->Draw("");
    // c1->cd(9);
    // Top_cjetEta_fakeRate->Draw("");

    // Top_cjet_fakeRate->SetLineWidth(2);
    // Top_cjet_fakeRate->Draw("");

    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Top_nTracks->Write();
    h_Top_nTracks_heavy->Write();
    h_Top_nTracks_light->Write();
    h_Top_nTracks_heavy_cut->Write();
    h_Top_nTracks_light_cut->Write();
    h_Top_nTracks_cut->Write();
    h_Top_Met->Write();
    Top_fakeRate->Write();
    Top_heavy_fakeRate->Write();
    Top_light_fakeRate->Write();
    Top_bjet_fakeRate->Write();
    Top_cjet_fakeRate->Write();
    h_Top_nTracks_bjet->Write();
    h_Top_nTracks_cjet->Write();
    h_Top_nTracks_cjet_cut->Write();
    h_Top_IP2D->Write();
    h_Top_Chi3Dlog->Write();
    h_Top_jetpt->Write();
    h_Top_jetpt_heavy->Write();
    h_Top_jetpt_bjet->Write();
    h_Top_jetpt_cjet->Write();
    h_Top_jetpt_light->Write();
    h_Top_jetpt_cut->Write();
    h_Top_jetpt_heavy_cut->Write();
    h_Top_jetpt_bjet_cut->Write();
    h_Top_jetpt_cjet_cut->Write();
    h_Top_jetpt_light_cut->Write();
    h_Top_jeteta->Write();
    h_Top_jeteta_heavy->Write();
    h_Top_jeteta_bjet->Write();
    h_Top_jeteta_cjet->Write();
    h_Top_jeteta_light->Write();
    h_Top_jeteta_cut->Write();
    h_Top_jeteta_heavy_cut->Write();
    h_Top_jeteta_bjet_cut->Write();
    h_Top_jeteta_cjet_cut->Write();
    h_Top_jeteta_light_cut->Write();
    h_Top_alpha3D->Write();
    h_Top_alpha3D_heavy->Write();
    h_Top_alpha3D_bjet->Write();
    h_Top_alpha3D_cjet->Write();
    h_Top_alpha3D_light->Write();
    h_Top_alpha3D_cut->Write();
    h_Top_alpha3D_heavy_cut->Write();
    h_Top_alpha3D_bjet_cut->Write();
    h_Top_alpha3D_cjet_cut->Write();
    h_Top_alpha3D_light_cut->Write();
    outfile_HT0->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_Top_produce_half();
    }
    else if (argc == 3)
    {
        ee_Top_produce_half(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}