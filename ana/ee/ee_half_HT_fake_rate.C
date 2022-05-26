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
#include "./../lib/Cross_section.h"
#include "./../lib/setNCUStyle.C"

void ee_half_HT_fake_rate()
{
    TFile *DYincli = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");
    TFile *DYHT70 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

    TFile *DYincli_1 = new TFile("./../../../../root_file/BgEstimation/ee_DYincli_1.root");
    TFile *DYHT70_1 = new TFile("./../../../../root_file/BgEstimation/ee_ht70_1.root");
    TFile *DYHT100_1 = new TFile("./../../../../root_file/BgEstimation/ee_ht100_1.root");
    TFile *DYHT200_1 = new TFile("./../../../../root_file/BgEstimation/ee_ht200_1.root");
    TFile *DYHT400_1 = new TFile("./../../../../root_file/BgEstimation/ee_ht400_1.root");
    TFile *DYHT600_1 = new TFile("./../../../../root_file/BgEstimation/ee_ht600_1.root");
    TFile *DYHT800_1 = new TFile("./../../../../root_file/BgEstimation/ee_ht800_1.root");
    TFile *DYHT1200_1 = new TFile("./../../../../root_file/BgEstimation/ee_ht1200_1.root");
    TFile *DYHT2500_1 = new TFile("./../../../../root_file/BgEstimation/ee_ht2500_1.root");

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));

    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("Event_Variable/h_totevent"));
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
    //----------------------------------------------------------------------
    // Create Histrogram: PT, eta, NTracks
    //----------------------------------------------------------------------
    Double_t nbins[82] = {-4.889, -4.716, -4.538, -4.363, -4.191, -4.013, -3.839, -3.664, -3.489, -3.314, -3.139, -2.964, -2.853,
                          -2.65, -2.5, -2.322, -2.172, -2.043, -1.93, -1.83, -1.74, -1.653, -1.566, -1.479, -1.392, -1.305, -1.218, -1.131, -1.044,
                          -0.957, -0.879, -0.783, -0.696, -0.609, -0.522, -0.435, -0.348, -0.261, -0.174, -0.087, 0, 0.087, 0.174, 0.261, 0.348, 0.435,
                          0.522, 0.609, 0.696, 0.783, 0.879, 0.957, 1.044, 1.131, 1.218, 1.305, 1.392, 1.479, 1.566, 1.653, 1.74, 1.83, 1.93, 2.043, 2.172,
                          2.322, 2.5, 2.65, 2.853, 2.964, 3.139, 3.314, 3.489, 3.664, 3.839, 4.013, 4.191, 4.363, 4.538, 4.716, 4.889, 5.191};
    const Int_t nnbins = (sizeof(nbins) / sizeof(*nbins)) - 1;

    string HT_region[9] = {"ht0", "ht70", "ht100", "ht200", "ht400", "ht600", "ht800", "ht1200", "ht2500"};
    TH1F *h_hev_emergjetpt[9];
    TH1F *h_hev_barr_emergjetpt[9];
    TH1F *h_hev_end_emergjetpt[9];
    TH1F *h_hev_emergjetpt_cutalpha[9];
    TH1F *h_hev_barr_emergjetpt_cutalpha[9];
    TH1F *h_hev_end_emergjetpt_cutalpha[9];
    TH1F *h_hev_emergjetpt_nog[9];
    TH1F *h_hev_barr_emergjetpt_nog[9];
    TH1F *h_hev_end_emergjetpt_nog[9];
    TH1F *h_hev_emergjetpt_cutalpha_nog[9];
    TH1F *h_hev_barr_emergjetpt_cutalpha_nog[9];
    TH1F *h_hev_end_emergjetpt_cutalpha_nog[9];
    TH1F *h_light_emergjetpt[9];
    TH1F *h_light_barr_emergjetpt[9];
    TH1F *h_light_end_emergjetpt[9];
    TH1F *h_light_emergjetpt_cutalpha[9];
    TH1F *h_light_barr_emergjetpt_cutalpha[9];
    TH1F *h_light_end_emergjetpt_cutalpha[9];
    TH1F *h_hev_emergjetEta[9];
    TH1F *h_hev_barr_emergjetEta[9];
    TH1F *h_hev_end_emergjetEta[9];
    TH1F *h_hev_emergjetEta_cutalpha[9];
    TH1F *h_hev_barr_emergjetEta_cutalpha[9];
    TH1F *h_hev_end_emergjetEta_cutalpha[9];
    TH1F *h_hev_emergjetEta_nog[9];
    TH1F *h_hev_barr_emergjetEta_nog[9];
    TH1F *h_hev_end_emergjetEta_nog[9];
    TH1F *h_hev_emergjetEta_cutalpha_nog[9];
    TH1F *h_hev_barr_emergjetEta_cutalpha_nog[9];
    TH1F *h_hev_end_emergjetEta_cutalpha_nog[9];
    TH1F *h_light_emergjetEta[9];
    TH1F *h_light_barr_emergjetEta[9];
    TH1F *h_light_end_emergjetEta[9];
    TH1F *h_light_emergjetEta_cutalpha[9];
    TH1F *h_light_barr_emergjetEta_cutalpha[9];
    TH1F *h_light_end_emergjetEta_cutalpha[9];
    TH1F *h_hev_emergjetnTrack[9];
    TH1F *h_hev_barr_emergjetnTrack[9];
    TH1F *h_hev_end_emergjetnTrack[9];
    TH1F *h_hev_emergjetnTrack_cutalpha[9];
    TH1F *h_hev_barr_emergjetnTrack_cutalpha[9];
    TH1F *h_hev_end_emergjetnTrack_cutalpha[9];
    TH1F *h_hev_emergjetnTrack_nog[9];
    TH1F *h_hev_barr_emergjetnTrack_nog[9];
    TH1F *h_hev_end_emergjetnTrack_nog[9];
    TH1F *h_hev_emergjetnTrack_cutalpha_nog[9];
    TH1F *h_hev_barr_emergjetnTrack_cutalpha_nog[9];
    TH1F *h_hev_end_emergjetnTrack_cutalpha_nog[9];
    TH1F *h_light_emergjetnTrack[9];
    TH1F *h_light_barr_emergjetnTrack[9];
    TH1F *h_light_end_emergjetnTrack[9];
    TH1F *h_light_emergjetnTrack_cutalpha[9];
    TH1F *h_light_barr_emergjetnTrack_cutalpha[9];
    TH1F *h_light_end_emergjetnTrack_cutalpha[9];
    for (int i = 0; i < 9; i++)
    {
        h_hev_emergjetpt[i] = new TH1F(Form("h_%s_hev_emergjetpt", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_emergjetpt[i]->Sumw2();
        h_hev_barr_emergjetpt[i] = new TH1F(Form("h_%s_barr_emergjetpt", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_barr_emergjetpt[i]->Sumw2();
        h_hev_end_emergjetpt[i] = new TH1F(Form("h_%s_end_emergjetpt", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_end_emergjetpt[i]->Sumw2();
        h_hev_emergjetpt_cutalpha[i] = new TH1F(Form("h_%s_emergjetpt_cutalpha", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_emergjetpt_cutalpha[i]->Sumw2();
        h_hev_barr_emergjetpt_cutalpha[i] = new TH1F(Form("h_%s_barr_emergjetpt_cutalpha", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_barr_emergjetpt_cutalpha[i]->Sumw2();
        h_hev_end_emergjetpt_cutalpha[i] = new TH1F(Form("h_%s_end_emergjetpt_cutalpha", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_end_emergjetpt_cutalpha[i]->Sumw2();
        h_hev_emergjetpt_nog[i] = new TH1F(Form("h_%s_hev_emergjetpt_nog", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_emergjetpt_nog[i]->Sumw2();
        h_hev_barr_emergjetpt_nog[i] = new TH1F(Form("h_%s_barr_emergjetpt_nog", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_barr_emergjetpt_nog[i]->Sumw2();
        h_hev_end_emergjetpt_nog[i] = new TH1F(Form("h_%s_end_emergjetpt_nog", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_end_emergjetpt_nog[i]->Sumw2();
        h_hev_emergjetpt_cutalpha_nog[i] = new TH1F(Form("h_%s_emergjetpt_cutalpha_nog", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_emergjetpt_cutalpha_nog[i]->Sumw2();
        h_hev_barr_emergjetpt_cutalpha_nog[i] = new TH1F(Form("h_%s_barr_emergjetpt_cutalpha_nog", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_barr_emergjetpt_cutalpha_nog[i]->Sumw2();
        h_hev_end_emergjetpt_cutalpha_nog[i] = new TH1F(Form("h_%s_end_emergjetpt_cutalpha_nog", HT_region[i].c_str()), "", 50, 0, 500);
        h_hev_end_emergjetpt_cutalpha_nog[i]->Sumw2();
        h_light_emergjetpt[i] = new TH1F(Form("h_%s_light_emergjetpt", HT_region[i].c_str()), "", 50, 0, 500);
        h_light_emergjetpt[i]->Sumw2();
        h_light_barr_emergjetpt[i] = new TH1F(Form("h_%s_light_barr_emergjetpt", HT_region[i].c_str()), "", 50, 0, 500);
        h_light_barr_emergjetpt[i]->Sumw2();
        h_light_end_emergjetpt[i] = new TH1F(Form("h_%s_light_end_emergjetpt", HT_region[i].c_str()), "", 50, 0, 500);
        h_light_end_emergjetpt[i]->Sumw2();
        h_light_emergjetpt_cutalpha[i] = new TH1F(Form("h_%s_light_emergjetpt_cutalpha", HT_region[i].c_str()), "", 50, 0, 500);
        h_light_emergjetpt_cutalpha[i]->Sumw2();
        h_light_barr_emergjetpt_cutalpha[i] = new TH1F(Form("h_%s_light_barr_emergjetpt_cutalpha", HT_region[i].c_str()), "", 50, 0, 500);
        h_light_barr_emergjetpt_cutalpha[i]->Sumw2();
        h_light_end_emergjetpt_cutalpha[i] = new TH1F(Form("h_%s_light_end_emergjetpt_cutalpha", HT_region[i].c_str()), "", 50, 0, 500);
        h_light_end_emergjetpt_cutalpha[i]->Sumw2();
        h_hev_emergjetEta[i] = new TH1F(Form("h_%s_hev_emergjetEta", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_emergjetEta[i]->Sumw2();
        h_hev_barr_emergjetEta[i] = new TH1F(Form("h_%s_hev_barr_emergjetEta", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_barr_emergjetEta[i]->Sumw2();
        h_hev_end_emergjetEta[i] = new TH1F(Form("h_%s_hev_end_emergjetEta", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_end_emergjetEta[i]->Sumw2();
        h_hev_emergjetEta_cutalpha[i] = new TH1F(Form("h_%s_hev_emergjetEta_cutalpha", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_emergjetEta_cutalpha[i]->Sumw2();
        h_hev_barr_emergjetEta_cutalpha[i] = new TH1F(Form("h_%s_hev_barr_emergjetEta_cutalpha", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_barr_emergjetEta_cutalpha[i]->Sumw2();
        h_hev_end_emergjetEta_cutalpha[i] = new TH1F(Form("h_%s_hev_end_emergjetEta_cutalpha", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_end_emergjetEta_cutalpha[i]->Sumw2();
        h_hev_emergjetEta_nog[i] = new TH1F(Form("h_%s_hev_emergjetEta_nog", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_emergjetEta_nog[i]->Sumw2();
        h_hev_barr_emergjetEta_nog[i] = new TH1F(Form("h_%s_hev_barr_emergjetEta_nog", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_barr_emergjetEta_nog[i]->Sumw2();
        h_hev_end_emergjetEta_nog[i] = new TH1F(Form("h_%s_hev_end_emergjetEta_nog", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_end_emergjetEta_nog[i]->Sumw2();
        h_hev_emergjetEta_cutalpha_nog[i] = new TH1F(Form("h_%s_hev_emergjetEta_cutalpha_nog", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_emergjetEta_cutalpha_nog[i]->Sumw2();
        h_hev_barr_emergjetEta_cutalpha_nog[i] = new TH1F(Form("h_%s_hev_barr_emergjetEta_cutalpha_nog", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_barr_emergjetEta_cutalpha_nog[i]->Sumw2();
        h_hev_end_emergjetEta_cutalpha_nog[i] = new TH1F(Form("h_%s_hev_end_emergjetEta_cutalpha_nog", HT_region[i].c_str()), "", nnbins, nbins);
        h_hev_end_emergjetEta_cutalpha_nog[i]->Sumw2();

        h_light_emergjetEta[i] = new TH1F(Form("h_%s_light_emergjetEta", HT_region[i].c_str()), "", nnbins, nbins);
        h_light_emergjetEta[i]->Sumw2();
        h_light_barr_emergjetEta[i] = new TH1F(Form("h_%s_light_barr_emergjetEta", HT_region[i].c_str()), "", nnbins, nbins);
        h_light_barr_emergjetEta[i]->Sumw2();
        h_light_end_emergjetEta[i] = new TH1F(Form("h_%s_light_end_emergjetEta", HT_region[i].c_str()), "", nnbins, nbins);
        h_light_end_emergjetEta[i]->Sumw2();
        h_light_emergjetEta_cutalpha[i] = new TH1F(Form("h_%s_light_emergjetEta_cutalpha", HT_region[i].c_str()), "", nnbins, nbins);
        h_light_emergjetEta_cutalpha[i]->Sumw2();
        h_light_barr_emergjetEta_cutalpha[i] = new TH1F(Form("h_%s_light_barr_emergjetEta_cutalpha", HT_region[i].c_str()), "", nnbins, nbins);
        h_light_barr_emergjetEta_cutalpha[i]->Sumw2();
        h_light_end_emergjetEta_cutalpha[i] = new TH1F(Form("h_%s_light_end_emergjetEta_cutalpha", HT_region[i].c_str()), "", nnbins, nbins);
        h_light_end_emergjetEta_cutalpha[i]->Sumw2();
        h_hev_emergjetnTrack[i] = new TH1F(Form("h_%s_hev_emergjetnTrack", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_emergjetnTrack[i]->Sumw2();
        h_hev_barr_emergjetnTrack[i] = new TH1F(Form("h_%s_hev_barr_emergjetnTrack", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_barr_emergjetnTrack[i]->Sumw2();
        h_hev_end_emergjetnTrack[i] = new TH1F(Form("h_%s_hev_end_emergjetnTrack", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_end_emergjetnTrack[i]->Sumw2();
        h_hev_emergjetnTrack_cutalpha[i] = new TH1F(Form("h_%s_hev_emergjetnTrack_cutalpha", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_emergjetnTrack_cutalpha[i]->Sumw2();
        h_hev_barr_emergjetnTrack_cutalpha[i] = new TH1F(Form("h_%s_hev_barr_emergjetnTrack_cutalpha", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_barr_emergjetnTrack_cutalpha[i]->Sumw2();
        h_hev_end_emergjetnTrack_cutalpha[i] = new TH1F(Form("h_%s_hev_end_emergjetnTrack_cutalpha", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_end_emergjetnTrack_cutalpha[i]->Sumw2();

        h_hev_emergjetnTrack_nog[i] = new TH1F(Form("h_%s_hev_emergjetnTrack_nog", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_emergjetnTrack_nog[i]->Sumw2();
        h_hev_barr_emergjetnTrack_nog[i] = new TH1F(Form("h_%s_hev_barr_emergjetnTrack_nog", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_barr_emergjetnTrack_nog[i]->Sumw2();
        h_hev_end_emergjetnTrack_nog[i] = new TH1F(Form("h_%s_hev_end_emergjetnTrack_nog", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_end_emergjetnTrack_nog[i]->Sumw2();
        h_hev_emergjetnTrack_cutalpha_nog[i] = new TH1F(Form("h_%s_hev_emergjetnTrack_cutalpha_nog", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_emergjetnTrack_cutalpha_nog[i]->Sumw2();
        h_hev_barr_emergjetnTrack_cutalpha_nog[i] = new TH1F(Form("h_%s_hev_barr_emergjetnTrack_cutalpha_nog", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_barr_emergjetnTrack_cutalpha_nog[i]->Sumw2();
        h_hev_end_emergjetnTrack_cutalpha_nog[i] = new TH1F(Form("h_%s_hev_end_emergjetnTrack_cutalpha_nog", HT_region[i].c_str()), "", 50, 0, 50);
        h_hev_end_emergjetnTrack_cutalpha_nog[i]->Sumw2();

        h_light_emergjetnTrack[i] = new TH1F(Form("h_%s_light_emergjetnTrack", HT_region[i].c_str()), "", 50, 0, 50);
        h_light_emergjetnTrack[i]->Sumw2();
        h_light_barr_emergjetnTrack[i] = new TH1F(Form("h_%s_light_barr_emergjetnTrack", HT_region[i].c_str()), "", 50, 0, 50);
        h_light_barr_emergjetnTrack[i]->Sumw2();
        h_light_end_emergjetnTrack[i] = new TH1F(Form("h_%s_light_end_emergjetnTrack", HT_region[i].c_str()), "", 50, 0, 50);
        h_light_end_emergjetnTrack[i]->Sumw2();
        h_light_emergjetnTrack_cutalpha[i] = new TH1F(Form("h_%s_light_emergjetnTrack_cutalpha", HT_region[i].c_str()), "", 50, 0, 50);
        h_light_emergjetnTrack_cutalpha[i]->Sumw2();
        h_light_barr_emergjetnTrack_cutalpha[i] = new TH1F(Form("h_%s_light_barr_emergjetnTrack_cutalpha", HT_region[i].c_str()), "", 50, 0, 50);
        h_light_barr_emergjetnTrack_cutalpha[i]->Sumw2();
        h_light_end_emergjetnTrack_cutalpha[i] = new TH1F(Form("h_%s_end_emergjetnTrack_cutalpha", HT_region[i].c_str()), "", 50, 0, 50);
        h_light_end_emergjetnTrack_cutalpha[i]->Sumw2();
    }
    float_t HT;

    Int_t I_ht0_nThinJets, I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets, I_ht600_nThinJets,
        I_ht800_nThinJets, I_ht1200_nThinJets, I_ht2500_nThinJets;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

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

    vector<float> *v_ht0_JetPT = new vector<float>();
    vector<float> *v_ht70_JetPT = new vector<float>();
    vector<float> *v_ht100_JetPT = new vector<float>();
    vector<float> *v_ht200_JetPT = new vector<float>();
    vector<float> *v_ht400_JetPT = new vector<float>();
    vector<float> *v_ht600_JetPT = new vector<float>();
    vector<float> *v_ht800_JetPT = new vector<float>();
    vector<float> *v_ht1200_JetPT = new vector<float>();
    vector<float> *v_ht2500_JetPT = new vector<float>();

    v_ht0_JetPT->clear();
    v_ht70_JetPT->clear();
    v_ht100_JetPT->clear();
    v_ht200_JetPT->clear();
    v_ht400_JetPT->clear();
    v_ht600_JetPT->clear();
    v_ht800_JetPT->clear();
    v_ht1200_JetPT->clear();
    v_ht2500_JetPT->clear();

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

    vector<int> *v_ht0_Jethadronflavor = new vector<int>();
    vector<int> *v_ht70_Jethadronflavor = new vector<int>();
    vector<int> *v_ht100_Jethadronflavor = new vector<int>();
    vector<int> *v_ht200_Jethadronflavor = new vector<int>();
    vector<int> *v_ht400_Jethadronflavor = new vector<int>();
    vector<int> *v_ht600_Jethadronflavor = new vector<int>();
    vector<int> *v_ht800_Jethadronflavor = new vector<int>();
    vector<int> *v_ht1200_Jethadronflavor = new vector<int>();
    vector<int> *v_ht2500_Jethadronflavor = new vector<int>();

    v_ht0_Jethadronflavor->clear();
    v_ht70_Jethadronflavor->clear();
    v_ht100_Jethadronflavor->clear();
    v_ht200_Jethadronflavor->clear();
    v_ht400_Jethadronflavor->clear();
    v_ht600_Jethadronflavor->clear();
    v_ht800_Jethadronflavor->clear();
    v_ht1200_Jethadronflavor->clear();
    v_ht2500_Jethadronflavor->clear();

    vector<int> *v_ht0_Jetpartonflavor = new vector<int>();
    vector<int> *v_ht70_Jetpartonflavor = new vector<int>();
    vector<int> *v_ht100_Jetpartonflavor = new vector<int>();
    vector<int> *v_ht200_Jetpartonflavor = new vector<int>();
    vector<int> *v_ht400_Jetpartonflavor = new vector<int>();
    vector<int> *v_ht600_Jetpartonflavor = new vector<int>();
    vector<int> *v_ht800_Jetpartonflavor = new vector<int>();
    vector<int> *v_ht1200_Jetpartonflavor = new vector<int>();
    vector<int> *v_ht2500_Jetpartonflavor = new vector<int>();

    v_ht0_Jetpartonflavor->clear();
    v_ht70_Jetpartonflavor->clear();
    v_ht100_Jetpartonflavor->clear();
    v_ht200_Jetpartonflavor->clear();
    v_ht400_Jetpartonflavor->clear();
    v_ht600_Jetpartonflavor->clear();
    v_ht800_Jetpartonflavor->clear();
    v_ht1200_Jetpartonflavor->clear();
    v_ht2500_Jetpartonflavor->clear();

    vector<int> *v_ht0_JetnTracks = new vector<int>();
    vector<int> *v_ht70_JetnTracks = new vector<int>();
    vector<int> *v_ht100_JetnTracks = new vector<int>();
    vector<int> *v_ht200_JetnTracks = new vector<int>();
    vector<int> *v_ht400_JetnTracks = new vector<int>();
    vector<int> *v_ht600_JetnTracks = new vector<int>();
    vector<int> *v_ht800_JetnTracks = new vector<int>();
    vector<int> *v_ht1200_JetnTracks = new vector<int>();
    vector<int> *v_ht2500_JetnTracks = new vector<int>();

    v_ht0_JetnTracks->clear();
    v_ht70_JetnTracks->clear();
    v_ht100_JetnTracks->clear();
    v_ht200_JetnTracks->clear();
    v_ht400_JetnTracks->clear();
    v_ht600_JetnTracks->clear();
    v_ht800_JetnTracks->clear();
    v_ht1200_JetnTracks->clear();
    v_ht2500_JetnTracks->clear();
    //---------------------
    // Define the HTWeight
    //---------------------
    float HT0Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT0CS) / (HT0_70_event)) * 1000 * 2;
    float HT70Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT70CS) / (HT70_100_event)) * 1000 * 2;
    float HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000 * 2;
    float HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000 * 2;
    float HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000 * 2;
    float HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000 * 2;
    float HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000 * 2;
    float HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000 * 2;
    float HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000 * 2;

    TTree *T_event;
    DYincli_1->GetObject("h1", T_event);
    T_event->SetBranchAddress("I_weight", &I_ht0_weight);
    T_event->SetBranchAddress("f_HT", &HT);
    T_event->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
    T_event->SetBranchAddress("v_fakeJetpartonflavor", &v_ht0_Jetpartonflavor);
    T_event->SetBranchAddress("v_fakeJetPt", &v_ht0_JetPT);
    T_event->SetBranchAddress("v_fakeJetEta", &v_ht0_JetEta);
    T_event->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    T_event->SetBranchAddress("v_N_Tracks", &v_ht0_JetnTracks);
    T_event->SetBranchAddress("I_nJets", &I_ht0_nThinJets);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        for (int i = 0; i < v_ht0_Jethadronflavor->size(); i++)
        {
            if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
            {
                if (HT < 70)
                {
                    h_hev_emergjetpt[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                    h_hev_emergjetEta[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                    h_hev_emergjetnTrack[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_nog[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                        h_hev_emergjetEta_nog[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                        h_hev_emergjetnTrack_nog[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                    }
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                        h_hev_barr_emergjetEta[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                        h_hev_barr_emergjetnTrack[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_nog[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                            h_hev_barr_emergjetEta_nog[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                            h_hev_barr_emergjetnTrack_nog[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                        h_hev_end_emergjetEta[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                        h_hev_end_emergjetnTrack[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_nog[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                            h_hev_end_emergjetEta_nog[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                            h_hev_end_emergjetnTrack_nog[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                        }
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_hev_emergjetpt_cutalpha[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                        h_hev_emergjetEta_cutalpha[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                        h_hev_emergjetnTrack_cutalpha[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_emergjetpt_cutalpha_nog[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                            h_hev_emergjetEta_cutalpha_nog[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                            h_hev_emergjetnTrack_cutalpha_nog[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                        }
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_hev_barr_emergjetpt_cutalpha[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                            h_hev_barr_emergjetEta_cutalpha[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                            h_hev_barr_emergjetnTrack_cutalpha[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_barr_emergjetpt_cutalpha_nog[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                                h_hev_barr_emergjetEta_cutalpha_nog[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                                h_hev_barr_emergjetnTrack_cutalpha_nog[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                            }
                        }
                        else
                        {
                            h_hev_end_emergjetpt_cutalpha[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                            h_hev_end_emergjetEta_cutalpha[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                            h_hev_end_emergjetnTrack_cutalpha[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_end_emergjetpt_cutalpha_nog[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                                h_hev_end_emergjetEta_cutalpha_nog[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                                h_hev_end_emergjetnTrack_cutalpha_nog[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                            }
                        }
                    } // alpha cut
                }     // HT<70
                else if (HT >= 70 && HT < 100)
                {
                    h_hev_emergjetpt[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                    h_hev_emergjetEta[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                    h_hev_emergjetnTrack[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_nog[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                        h_hev_emergjetEta_nog[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                        h_hev_emergjetnTrack_nog[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                    }
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                        h_hev_barr_emergjetEta[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                        h_hev_barr_emergjetnTrack[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_nog[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                            h_hev_barr_emergjetEta_nog[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                            h_hev_barr_emergjetnTrack_nog[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                        h_hev_end_emergjetEta[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                        h_hev_end_emergjetnTrack[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_nog[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                            h_hev_end_emergjetEta_nog[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                            h_hev_end_emergjetnTrack_nog[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                        }
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_hev_emergjetpt_cutalpha[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                        h_hev_emergjetEta_cutalpha[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                        h_hev_emergjetnTrack_cutalpha[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_emergjetpt_cutalpha_nog[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                            h_hev_emergjetEta_cutalpha_nog[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                            h_hev_emergjetnTrack_cutalpha_nog[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                        }
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_hev_barr_emergjetpt_cutalpha[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                            h_hev_barr_emergjetEta_cutalpha[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                            h_hev_barr_emergjetnTrack_cutalpha[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_barr_emergjetpt_cutalpha_nog[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                                h_hev_barr_emergjetEta_cutalpha_nog[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                                h_hev_barr_emergjetnTrack_cutalpha_nog[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                            }
                        }
                        else
                        {
                            h_hev_end_emergjetpt_cutalpha[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                            h_hev_end_emergjetEta_cutalpha[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                            h_hev_end_emergjetnTrack_cutalpha[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_end_emergjetpt_cutalpha_nog[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                                h_hev_end_emergjetEta_cutalpha_nog[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                                h_hev_end_emergjetnTrack_cutalpha_nog[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                            }
                        }
                    } // alpha cut
                }     // HT<100
                else if (HT >= 100 && HT < 200)
                {
                    h_hev_emergjetpt[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                    h_hev_emergjetEta[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                    h_hev_emergjetnTrack[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_nog[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                        h_hev_emergjetEta_nog[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                        h_hev_emergjetnTrack_nog[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                    }
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                        h_hev_barr_emergjetEta[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                        h_hev_barr_emergjetnTrack[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_nog[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                            h_hev_barr_emergjetEta_nog[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                            h_hev_barr_emergjetnTrack_nog[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                        h_hev_end_emergjetEta[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                        h_hev_end_emergjetnTrack[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_nog[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                            h_hev_end_emergjetEta_nog[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                            h_hev_end_emergjetnTrack_nog[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                        }
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_hev_emergjetpt_cutalpha[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                        h_hev_emergjetEta_cutalpha[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                        h_hev_emergjetnTrack_cutalpha[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_emergjetpt_cutalpha_nog[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                            h_hev_emergjetEta_cutalpha_nog[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                            h_hev_emergjetnTrack_cutalpha_nog[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                        }
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_hev_barr_emergjetpt_cutalpha[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                            h_hev_barr_emergjetEta_cutalpha[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                            h_hev_barr_emergjetnTrack_cutalpha[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_barr_emergjetpt_cutalpha_nog[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                                h_hev_barr_emergjetEta_cutalpha_nog[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                                h_hev_barr_emergjetnTrack_cutalpha_nog[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                            }
                        }
                        else
                        {
                            h_hev_end_emergjetpt_cutalpha[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                            h_hev_end_emergjetEta_cutalpha[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                            h_hev_end_emergjetnTrack_cutalpha[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_end_emergjetpt_cutalpha_nog[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                                h_hev_end_emergjetEta_cutalpha_nog[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                                h_hev_end_emergjetnTrack_cutalpha_nog[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                            }
                        }
                    }
                } // HT<200
                else if (HT >= 200 && HT < 400)
                {
                    h_hev_emergjetpt[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                    h_hev_emergjetEta[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                    h_hev_emergjetnTrack[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_nog[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                        h_hev_emergjetEta_nog[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                        h_hev_emergjetnTrack_nog[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                    }
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                        h_hev_barr_emergjetEta[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                        h_hev_barr_emergjetnTrack[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_nog[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                            h_hev_barr_emergjetEta_nog[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                            h_hev_barr_emergjetnTrack_nog[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                        h_hev_end_emergjetEta[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                        h_hev_end_emergjetnTrack[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_nog[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                            h_hev_end_emergjetEta_nog[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                            h_hev_end_emergjetnTrack_nog[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                        }
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_hev_emergjetpt_cutalpha[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                        h_hev_emergjetEta_cutalpha[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                        h_hev_emergjetnTrack_cutalpha[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_emergjetpt_cutalpha_nog[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                            h_hev_emergjetEta_cutalpha_nog[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                            h_hev_emergjetnTrack_cutalpha_nog[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                        }
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_hev_barr_emergjetpt_cutalpha[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                            h_hev_barr_emergjetEta_cutalpha[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                            h_hev_barr_emergjetnTrack_cutalpha[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_barr_emergjetpt_cutalpha_nog[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                                h_hev_barr_emergjetEta_cutalpha_nog[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                                h_hev_barr_emergjetnTrack_cutalpha_nog[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                            }
                        }
                        else
                        {
                            h_hev_end_emergjetpt_cutalpha[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                            h_hev_end_emergjetEta_cutalpha[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                            h_hev_end_emergjetnTrack_cutalpha[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_end_emergjetpt_cutalpha_nog[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                                h_hev_end_emergjetEta_cutalpha_nog[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                                h_hev_end_emergjetnTrack_cutalpha_nog[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                            }
                        }
                    }
                }
                else if (HT >= 400 && HT < 600)
                {
                    h_hev_emergjetpt[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                    h_hev_emergjetEta[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                    h_hev_emergjetnTrack[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_nog[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                        h_hev_emergjetEta_nog[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                        h_hev_emergjetnTrack_nog[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                    }
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                        h_hev_barr_emergjetEta[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                        h_hev_barr_emergjetnTrack[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_nog[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                            h_hev_barr_emergjetEta_nog[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                            h_hev_barr_emergjetnTrack_nog[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                        h_hev_end_emergjetEta[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                        h_hev_end_emergjetnTrack[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_nog[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                            h_hev_end_emergjetEta_nog[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                            h_hev_end_emergjetnTrack_nog[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                        }
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_hev_emergjetpt_cutalpha[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                        h_hev_emergjetEta_cutalpha[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                        h_hev_emergjetnTrack_cutalpha[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_emergjetpt_cutalpha_nog[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                            h_hev_emergjetEta_cutalpha_nog[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                            h_hev_emergjetnTrack_cutalpha_nog[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                        }
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_hev_barr_emergjetpt_cutalpha[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                            h_hev_barr_emergjetEta_cutalpha[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                            h_hev_barr_emergjetnTrack_cutalpha[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_barr_emergjetpt_cutalpha_nog[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                                h_hev_barr_emergjetEta_cutalpha_nog[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                                h_hev_barr_emergjetnTrack_cutalpha_nog[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                            }
                        }
                        else
                        {
                            h_hev_end_emergjetpt_cutalpha[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                            h_hev_end_emergjetEta_cutalpha[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                            h_hev_end_emergjetnTrack_cutalpha[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_end_emergjetpt_cutalpha_nog[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                                h_hev_end_emergjetEta_cutalpha_nog[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                                h_hev_end_emergjetnTrack_cutalpha_nog[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                            }
                        }
                    }
                }
                else if (HT >= 600 && HT < 800)
                {
                    h_hev_emergjetpt[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                    h_hev_emergjetEta[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                    h_hev_emergjetnTrack[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_nog[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                        h_hev_emergjetEta_nog[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                        h_hev_emergjetnTrack_nog[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                    }
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                        h_hev_barr_emergjetEta[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                        h_hev_barr_emergjetnTrack[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_nog[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                            h_hev_barr_emergjetEta_nog[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                            h_hev_barr_emergjetnTrack_nog[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                        h_hev_end_emergjetEta[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                        h_hev_end_emergjetnTrack[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_nog[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                            h_hev_end_emergjetEta_nog[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                            h_hev_end_emergjetnTrack_nog[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                        }
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_hev_emergjetpt_cutalpha[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                        h_hev_emergjetEta_cutalpha[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                        h_hev_emergjetnTrack_cutalpha[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_emergjetpt_cutalpha_nog[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                            h_hev_emergjetEta_cutalpha_nog[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                            h_hev_emergjetnTrack_cutalpha_nog[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                        }
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_hev_barr_emergjetpt_cutalpha[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                            h_hev_barr_emergjetEta_cutalpha[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                            h_hev_barr_emergjetnTrack_cutalpha[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_barr_emergjetpt_cutalpha_nog[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                                h_hev_barr_emergjetEta_cutalpha_nog[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                                h_hev_barr_emergjetnTrack_cutalpha_nog[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                            }
                        }
                        else
                        {
                            h_hev_end_emergjetpt_cutalpha[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                            h_hev_end_emergjetEta_cutalpha[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                            h_hev_end_emergjetnTrack_cutalpha[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_end_emergjetpt_cutalpha_nog[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                                h_hev_end_emergjetEta_cutalpha_nog[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                                h_hev_end_emergjetnTrack_cutalpha_nog[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                            }
                        }
                    }
                }
                else if (HT >= 800 && HT < 1200)
                {
                    h_hev_emergjetpt[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                    h_hev_emergjetEta[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                    h_hev_emergjetnTrack[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_nog[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                        h_hev_emergjetEta_nog[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                        h_hev_emergjetnTrack_nog[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                    }
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                        h_hev_barr_emergjetEta[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                        h_hev_barr_emergjetnTrack[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_nog[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                            h_hev_barr_emergjetEta_nog[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                            h_hev_barr_emergjetnTrack_nog[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                        h_hev_end_emergjetEta[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                        h_hev_end_emergjetnTrack[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_nog[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                            h_hev_end_emergjetEta_nog[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                            h_hev_end_emergjetnTrack_nog[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                        }
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_hev_emergjetpt_cutalpha[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                        h_hev_emergjetEta_cutalpha[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                        h_hev_emergjetnTrack_cutalpha[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_emergjetpt_cutalpha_nog[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                            h_hev_emergjetEta_cutalpha_nog[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                            h_hev_emergjetnTrack_cutalpha_nog[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                        }
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_hev_barr_emergjetpt_cutalpha[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                            h_hev_barr_emergjetEta_cutalpha[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                            h_hev_barr_emergjetnTrack_cutalpha[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_barr_emergjetpt_cutalpha_nog[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                                h_hev_barr_emergjetEta_cutalpha_nog[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                                h_hev_barr_emergjetnTrack_cutalpha_nog[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                            }
                        }
                        else
                        {
                            h_hev_end_emergjetpt_cutalpha[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                            h_hev_end_emergjetEta_cutalpha[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                            h_hev_end_emergjetnTrack_cutalpha[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_end_emergjetpt_cutalpha_nog[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                                h_hev_end_emergjetEta_cutalpha_nog[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                                h_hev_end_emergjetnTrack_cutalpha_nog[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                            }
                        }
                    }
                }
                else if (HT >= 1200 && HT < 2500)
                {
                    h_hev_emergjetpt[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                    h_hev_emergjetEta[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                    h_hev_emergjetnTrack[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_nog[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                        h_hev_emergjetEta_nog[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                        h_hev_emergjetnTrack_nog[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                    }
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                        h_hev_barr_emergjetEta[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                        h_hev_barr_emergjetnTrack[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_nog[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                            h_hev_barr_emergjetEta_nog[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                            h_hev_barr_emergjetnTrack_nog[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                        h_hev_end_emergjetEta[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                        h_hev_end_emergjetnTrack[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_nog[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                            h_hev_end_emergjetEta_nog[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                            h_hev_end_emergjetnTrack_nog[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                        }
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_hev_emergjetpt_cutalpha[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                        h_hev_emergjetEta_cutalpha[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                        h_hev_emergjetnTrack_cutalpha[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_emergjetpt_cutalpha_nog[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                            h_hev_emergjetEta_cutalpha_nog[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                            h_hev_emergjetnTrack_cutalpha_nog[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                        }
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_hev_barr_emergjetpt_cutalpha[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                            h_hev_barr_emergjetEta_cutalpha[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                            h_hev_barr_emergjetnTrack_cutalpha[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_barr_emergjetpt_cutalpha_nog[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                                h_hev_barr_emergjetEta_cutalpha_nog[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                                h_hev_barr_emergjetnTrack_cutalpha_nog[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                            }
                        }
                        else
                        {
                            h_hev_end_emergjetpt_cutalpha[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                            h_hev_end_emergjetEta_cutalpha[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                            h_hev_end_emergjetnTrack_cutalpha[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_end_emergjetpt_cutalpha_nog[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                                h_hev_end_emergjetEta_cutalpha_nog[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                                h_hev_end_emergjetnTrack_cutalpha_nog[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                            }
                        }
                    }
                }
                else if (HT >= 2500)
                {
                    h_hev_emergjetpt[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                    h_hev_emergjetEta[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                    h_hev_emergjetnTrack[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                    if ((*v_ht0_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_nog[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                        h_hev_emergjetEta_nog[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                        h_hev_emergjetnTrack_nog[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                    }
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                        h_hev_barr_emergjetEta[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                        h_hev_barr_emergjetnTrack[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_nog[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                            h_hev_barr_emergjetEta_nog[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                            h_hev_barr_emergjetnTrack_nog[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                        h_hev_end_emergjetEta[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                        h_hev_end_emergjetnTrack[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_nog[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                            h_hev_end_emergjetEta_nog[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                            h_hev_end_emergjetnTrack_nog[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                        }
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_hev_emergjetpt_cutalpha[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                        h_hev_emergjetEta_cutalpha[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                        h_hev_emergjetnTrack_cutalpha[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                        if ((*v_ht0_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_emergjetpt_cutalpha_nog[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                            h_hev_emergjetEta_cutalpha_nog[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                            h_hev_emergjetnTrack_cutalpha_nog[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                        }
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_hev_barr_emergjetpt_cutalpha[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                            h_hev_barr_emergjetEta_cutalpha[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                            h_hev_barr_emergjetnTrack_cutalpha[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_barr_emergjetpt_cutalpha_nog[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                                h_hev_barr_emergjetEta_cutalpha_nog[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                                h_hev_barr_emergjetnTrack_cutalpha_nog[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                            }
                        }
                        else
                        {
                            h_hev_end_emergjetpt_cutalpha[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                            h_hev_end_emergjetEta_cutalpha[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                            h_hev_end_emergjetnTrack_cutalpha[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                            if ((*v_ht0_Jetpartonflavor)[i] != 21)
                            {
                                h_hev_end_emergjetpt_cutalpha_nog[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                                h_hev_end_emergjetEta_cutalpha_nog[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                                h_hev_end_emergjetnTrack_cutalpha_nog[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                            }
                        }
                    }
                }
            }
            else
            {
                if (HT < 70)
                {
                    h_light_emergjetpt[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                    h_light_emergjetEta[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                    h_light_emergjetnTrack[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                        h_light_barr_emergjetEta[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                        h_light_barr_emergjetnTrack[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                        h_light_end_emergjetEta[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                        h_light_end_emergjetnTrack[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_light_emergjetpt_cutalpha[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                        h_light_emergjetEta_cutalpha[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                        h_light_emergjetnTrack_cutalpha[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_light_barr_emergjetpt_cutalpha[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                            h_light_barr_emergjetEta_cutalpha[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                            h_light_barr_emergjetnTrack_cutalpha[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                        }
                        else
                        {
                            h_light_end_emergjetpt_cutalpha[0]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                            h_light_end_emergjetEta_cutalpha[0]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                            h_light_end_emergjetnTrack_cutalpha[0]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                        }
                    }
                }
                else if (HT >= 70 && HT < 100)
                {
                    h_light_emergjetpt[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                    h_light_emergjetEta[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                    h_light_emergjetnTrack[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                        h_light_barr_emergjetEta[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                        h_light_barr_emergjetnTrack[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                        h_light_end_emergjetEta[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                        h_light_end_emergjetnTrack[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_light_emergjetpt_cutalpha[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                        h_light_emergjetEta_cutalpha[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                        h_light_emergjetnTrack_cutalpha[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_light_barr_emergjetpt_cutalpha[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                            h_light_barr_emergjetEta_cutalpha[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                            h_light_barr_emergjetnTrack_cutalpha[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                        }
                        else
                        {
                            h_light_end_emergjetpt_cutalpha[1]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                            h_light_end_emergjetEta_cutalpha[1]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                            h_light_end_emergjetnTrack_cutalpha[1]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                        }
                    }
                }
                else if (HT >= 100 && HT < 200)
                {
                    h_light_emergjetpt[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                    h_light_emergjetEta[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                    h_light_emergjetnTrack[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                        h_light_barr_emergjetEta[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                        h_light_barr_emergjetnTrack[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                        h_light_end_emergjetEta[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                        h_light_end_emergjetnTrack[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_light_emergjetpt_cutalpha[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                        h_light_emergjetEta_cutalpha[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                        h_light_emergjetnTrack_cutalpha[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_light_barr_emergjetpt_cutalpha[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                            h_light_barr_emergjetEta_cutalpha[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                            h_light_barr_emergjetnTrack_cutalpha[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                        }
                        else
                        {
                            h_light_end_emergjetpt_cutalpha[2]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                            h_light_end_emergjetEta_cutalpha[2]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                            h_light_end_emergjetnTrack_cutalpha[2]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                        }
                    }
                }
                else if (HT >= 200 && HT < 400)
                {
                    h_light_emergjetpt[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                    h_light_emergjetEta[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                    h_light_emergjetnTrack[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                        h_light_barr_emergjetEta[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                        h_light_barr_emergjetnTrack[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                        h_light_end_emergjetEta[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                        h_light_end_emergjetnTrack[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_light_emergjetpt_cutalpha[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                        h_light_emergjetEta_cutalpha[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                        h_light_emergjetnTrack_cutalpha[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_light_barr_emergjetpt_cutalpha[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                            h_light_barr_emergjetEta_cutalpha[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                            h_light_barr_emergjetnTrack_cutalpha[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                        }
                        else
                        {
                            h_light_end_emergjetpt_cutalpha[3]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                            h_light_end_emergjetEta_cutalpha[3]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                            h_light_end_emergjetnTrack_cutalpha[3]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                        }
                    }
                }
                else if (HT >= 400 && HT < 600)
                {
                    h_light_emergjetpt[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                    h_light_emergjetEta[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                    h_light_emergjetnTrack[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                        h_light_barr_emergjetEta[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                        h_light_barr_emergjetnTrack[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                        h_light_end_emergjetEta[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                        h_light_end_emergjetnTrack[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_light_emergjetpt_cutalpha[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                        h_light_emergjetEta_cutalpha[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                        h_light_emergjetnTrack_cutalpha[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_light_barr_emergjetpt_cutalpha[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                            h_light_barr_emergjetEta_cutalpha[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                            h_light_barr_emergjetnTrack_cutalpha[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                        }
                        else
                        {
                            h_light_end_emergjetpt_cutalpha[4]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                            h_light_end_emergjetEta_cutalpha[4]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                            h_light_end_emergjetnTrack_cutalpha[4]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                        }
                    }
                }
                else if (HT >= 600 && HT < 800)
                {
                    h_light_emergjetpt[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                    h_light_emergjetEta[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                    h_light_emergjetnTrack[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                        h_light_barr_emergjetEta[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                        h_light_barr_emergjetnTrack[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                        h_light_end_emergjetEta[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                        h_light_end_emergjetnTrack[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_light_emergjetpt_cutalpha[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                        h_light_emergjetEta_cutalpha[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                        h_light_emergjetnTrack_cutalpha[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_light_barr_emergjetpt_cutalpha[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                            h_light_barr_emergjetEta_cutalpha[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                            h_light_barr_emergjetnTrack_cutalpha[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                        }
                        else
                        {
                            h_light_end_emergjetpt_cutalpha[5]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                            h_light_end_emergjetEta_cutalpha[5]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                            h_light_end_emergjetnTrack_cutalpha[5]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                        }
                    }
                }
                else if (HT >= 800 && HT < 1200)
                {
                    h_light_emergjetpt[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                    h_light_emergjetEta[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                    h_light_emergjetnTrack[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                        h_light_barr_emergjetEta[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                        h_light_barr_emergjetnTrack[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                        h_light_end_emergjetEta[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                        h_light_end_emergjetnTrack[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_light_emergjetpt_cutalpha[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                        h_light_emergjetEta_cutalpha[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                        h_light_emergjetnTrack_cutalpha[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_light_barr_emergjetpt_cutalpha[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                            h_light_barr_emergjetEta_cutalpha[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                            h_light_barr_emergjetnTrack_cutalpha[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                        }
                        else
                        {
                            h_light_end_emergjetpt_cutalpha[6]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                            h_light_end_emergjetEta_cutalpha[6]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                            h_light_end_emergjetnTrack_cutalpha[6]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                        }
                    }
                }
                else if (HT >= 1200 && HT < 2500)
                {
                    h_light_emergjetpt[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                    h_light_emergjetEta[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                    h_light_emergjetnTrack[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                        h_light_barr_emergjetEta[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                        h_light_barr_emergjetnTrack[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                        h_light_end_emergjetEta[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                        h_light_end_emergjetnTrack[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_light_emergjetpt_cutalpha[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                        h_light_emergjetEta_cutalpha[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                        h_light_emergjetnTrack_cutalpha[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_light_barr_emergjetpt_cutalpha[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                            h_light_barr_emergjetEta_cutalpha[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                            h_light_barr_emergjetnTrack_cutalpha[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                        }
                        else
                        {
                            h_light_end_emergjetpt_cutalpha[7]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                            h_light_end_emergjetEta_cutalpha[7]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                            h_light_end_emergjetnTrack_cutalpha[7]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                        }
                    }
                }
                else if (HT >= 2500)
                {
                    h_light_emergjetpt[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                    h_light_emergjetEta[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                    h_light_emergjetnTrack[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                        h_light_barr_emergjetEta[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                        h_light_barr_emergjetnTrack[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                        h_light_end_emergjetEta[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                        h_light_end_emergjetnTrack[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_light_emergjetpt_cutalpha[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                        h_light_emergjetEta_cutalpha[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                        h_light_emergjetnTrack_cutalpha[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_light_barr_emergjetpt_cutalpha[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                            h_light_barr_emergjetEta_cutalpha[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                            h_light_barr_emergjetnTrack_cutalpha[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                        }
                        else
                        {
                            h_light_end_emergjetpt_cutalpha[8]->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                            h_light_end_emergjetEta_cutalpha[8]->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                            h_light_end_emergjetnTrack_cutalpha[8]->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                        }
                    }
                }
            }
        }
    } // End of DYHT0 loop
    TTree *T_event1;
    DYHT100_1->GetObject("h1", T_event1);
    T_event1->SetBranchAddress("I_weight", &I_ht100_weight);
    T_event1->SetBranchAddress("v_fakeJethadronflavor", &v_ht100_Jethadronflavor);
    T_event1->SetBranchAddress("v_fakeJetpartonflavor", &v_ht100_Jetpartonflavor);
    T_event1->SetBranchAddress("v_fakeJetPt", &v_ht100_JetPT);
    T_event1->SetBranchAddress("v_fakeJetEta", &v_ht100_JetEta);
    T_event1->SetBranchAddress("v_fakealpha", &v_ht100_alpha);
    T_event1->SetBranchAddress("v_N_Tracks", &v_ht100_JetnTracks);
    T_event1->SetBranchAddress("I_nJets", &I_ht100_nThinJets);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        for (int i = 0; i < v_ht100_Jethadronflavor->size(); i++)
        {
            if ((*v_ht100_Jethadronflavor)[i] == 4 || (*v_ht100_Jethadronflavor)[i] == 5)
            {
                h_hev_emergjetpt[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                h_hev_emergjetEta[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                h_hev_emergjetnTrack[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                if ((*v_ht100_Jetpartonflavor)[i] != 21)
                {
                    h_hev_emergjetpt_nog[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_hev_emergjetEta_nog[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    h_hev_emergjetnTrack_nog[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                }
                if (abs((*v_ht100_JetEta)[i]) < 1.479)
                {
                    h_hev_barr_emergjetpt[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_hev_barr_emergjetEta[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    h_hev_barr_emergjetnTrack[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                    if ((*v_ht100_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_barr_emergjetpt_nog[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                        h_hev_barr_emergjetEta_nog[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                        h_hev_barr_emergjetnTrack_nog[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                    }
                }
                else
                {
                    h_hev_end_emergjetpt[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_hev_end_emergjetEta[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    h_hev_end_emergjetnTrack[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                    if ((*v_ht100_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_end_emergjetpt_nog[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                        h_hev_end_emergjetEta_nog[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                        h_hev_end_emergjetnTrack_nog[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                    }
                }
                if ((*v_ht100_alpha)[i] <= 0.35)
                {
                    h_hev_emergjetpt_cutalpha[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_hev_emergjetEta_cutalpha[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    h_hev_emergjetnTrack_cutalpha[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                    if ((*v_ht100_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_cutalpha_nog[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                        h_hev_emergjetEta_cutalpha_nog[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                        h_hev_emergjetnTrack_cutalpha_nog[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                    }
                    if (abs((*v_ht100_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt_cutalpha[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                        h_hev_barr_emergjetEta_cutalpha[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                        h_hev_barr_emergjetnTrack_cutalpha[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                        if ((*v_ht100_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_cutalpha_nog[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                            h_hev_barr_emergjetEta_cutalpha_nog[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                            h_hev_barr_emergjetnTrack_cutalpha_nog[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt_cutalpha[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                        h_hev_end_emergjetEta_cutalpha[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                        h_hev_end_emergjetnTrack_cutalpha[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                        if ((*v_ht100_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_cutalpha_nog[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                            h_hev_end_emergjetEta_cutalpha_nog[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                            h_hev_end_emergjetnTrack_cutalpha_nog[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                        }
                    }
                }
            }
            else
            {
                h_light_emergjetpt[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                h_light_emergjetEta[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                h_light_emergjetnTrack[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                if (abs((*v_ht100_JetEta)[i]) < 1.479)
                {
                    h_light_barr_emergjetpt[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_light_barr_emergjetEta[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    h_light_barr_emergjetnTrack[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                }
                else
                {
                    h_light_end_emergjetpt[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_light_end_emergjetEta[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    h_light_end_emergjetnTrack[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                }
                if ((*v_ht100_alpha)[i] <= 0.35)
                {
                    h_light_emergjetpt_cutalpha[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_light_emergjetEta_cutalpha[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    h_light_emergjetnTrack_cutalpha[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                    if (abs((*v_ht100_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt_cutalpha[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                        h_light_barr_emergjetEta_cutalpha[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                        h_light_barr_emergjetnTrack_cutalpha[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt_cutalpha[2]->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                        h_light_end_emergjetEta_cutalpha[2]->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                        h_light_end_emergjetnTrack_cutalpha[2]->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                    }
                }
            }
        }
    } // End of HT100 loop
    TTree *T_event2;
    DYHT200_1->GetObject("h1", T_event2);
    T_event2->SetBranchAddress("I_weight", &I_ht200_weight);
    T_event2->SetBranchAddress("v_fakeJethadronflavor", &v_ht200_Jethadronflavor);
    T_event2->SetBranchAddress("v_fakeJetpartonflavor", &v_ht200_Jetpartonflavor);
    T_event2->SetBranchAddress("v_fakeJetPt", &v_ht200_JetPT);
    T_event2->SetBranchAddress("v_fakeJetEta", &v_ht200_JetEta);
    T_event2->SetBranchAddress("v_fakealpha", &v_ht200_alpha);
    T_event2->SetBranchAddress("v_N_Tracks", &v_ht200_JetnTracks);
    T_event2->SetBranchAddress("I_nJets", &I_ht200_nThinJets);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        for (int i = 0; i < v_ht200_Jethadronflavor->size(); i++)
        {
            if ((*v_ht200_Jethadronflavor)[i] == 4 || (*v_ht200_Jethadronflavor)[i] == 5)
            {
                h_hev_emergjetpt[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                h_hev_emergjetEta[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                h_hev_emergjetnTrack[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                if ((*v_ht200_Jetpartonflavor)[i] != 21)
                {
                    h_hev_emergjetpt_nog[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                    h_hev_emergjetEta_nog[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    h_hev_emergjetnTrack_nog[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                }
                if (abs((*v_ht200_JetEta)[i]) < 1.479)
                {
                    h_hev_barr_emergjetpt[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                    h_hev_barr_emergjetEta[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    h_hev_barr_emergjetnTrack[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    if ((*v_ht200_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_barr_emergjetpt_nog[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_hev_barr_emergjetEta_nog[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                        h_hev_barr_emergjetnTrack_nog[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    }
                }
                else
                {
                    h_hev_end_emergjetpt[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                    h_hev_end_emergjetEta[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    h_hev_end_emergjetnTrack[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    if ((*v_ht200_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_end_emergjetpt_nog[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_hev_end_emergjetEta_nog[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                        h_hev_end_emergjetnTrack_nog[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    }
                }
                if ((*v_ht200_alpha)[i] <= 0.35)
                {
                    h_hev_emergjetpt_cutalpha[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                    h_hev_emergjetEta_cutalpha[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    h_hev_emergjetnTrack_cutalpha[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    if ((*v_ht200_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_cutalpha_nog[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_hev_emergjetEta_cutalpha_nog[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                        h_hev_emergjetnTrack_cutalpha_nog[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    }
                    if (abs((*v_ht200_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt_cutalpha[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_hev_barr_emergjetEta_cutalpha[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                        h_hev_barr_emergjetnTrack_cutalpha[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                        if ((*v_ht200_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_cutalpha_nog[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                            h_hev_barr_emergjetEta_cutalpha_nog[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                            h_hev_barr_emergjetnTrack_cutalpha_nog[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt_cutalpha[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_hev_end_emergjetEta_cutalpha[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                        h_hev_end_emergjetnTrack_cutalpha[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                        if ((*v_ht200_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_cutalpha_nog[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                            h_hev_end_emergjetEta_cutalpha_nog[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                            h_hev_end_emergjetnTrack_cutalpha_nog[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                        }
                    }
                }
            }
            else
            {
                h_light_emergjetpt[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                h_light_emergjetEta[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                h_light_emergjetnTrack[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                if (abs((*v_ht200_JetEta)[i]) < 1.479)
                {
                    h_light_barr_emergjetpt[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                    h_light_barr_emergjetEta[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    h_light_barr_emergjetnTrack[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                }
                else
                {
                    h_light_end_emergjetpt[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                    h_light_end_emergjetEta[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    h_light_end_emergjetnTrack[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                }
                if ((*v_ht200_alpha)[i] <= 0.35)
                {
                    h_light_emergjetpt_cutalpha[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                    h_light_emergjetEta_cutalpha[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    h_light_emergjetnTrack_cutalpha[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    if (abs((*v_ht200_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt_cutalpha[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_light_barr_emergjetEta_cutalpha[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                        h_light_barr_emergjetnTrack_cutalpha[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt_cutalpha[3]->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_light_end_emergjetEta_cutalpha[3]->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                        h_light_end_emergjetnTrack_cutalpha[3]->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    }
                }
            }
        }
    } // End of HT200 loop
    TTree *T_event3;
    DYHT400_1->GetObject("h1", T_event3);
    T_event3->SetBranchAddress("I_weight", &I_ht400_weight);
    T_event3->SetBranchAddress("v_fakeJethadronflavor", &v_ht400_Jethadronflavor);
    T_event3->SetBranchAddress("v_fakeJetpartonflavor", &v_ht400_Jetpartonflavor);
    T_event3->SetBranchAddress("v_fakeJetPt", &v_ht400_JetPT);
    T_event3->SetBranchAddress("v_fakeJetEta", &v_ht400_JetEta);
    T_event3->SetBranchAddress("v_fakealpha", &v_ht400_alpha);
    T_event3->SetBranchAddress("v_N_Tracks", &v_ht400_JetnTracks);
    T_event3->SetBranchAddress("I_nJets", &I_ht400_nThinJets);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        for (int i = 0; i < v_ht400_Jethadronflavor->size(); i++)
        {
            if ((*v_ht400_Jethadronflavor)[i] == 4 || (*v_ht400_Jethadronflavor)[i] == 5)
            {
                h_hev_emergjetpt[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                h_hev_emergjetEta[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                h_hev_emergjetnTrack[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                if ((*v_ht400_Jetpartonflavor)[i] != 21)
                {
                    h_hev_emergjetpt_nog[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                    h_hev_emergjetEta_nog[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    h_hev_emergjetnTrack_nog[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                }
                if (abs((*v_ht400_JetEta)[i]) < 1.479)
                {
                    h_hev_barr_emergjetpt[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                    h_hev_barr_emergjetEta[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    h_hev_barr_emergjetnTrack[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    if ((*v_ht400_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_barr_emergjetpt_nog[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_hev_barr_emergjetEta_nog[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                        h_hev_barr_emergjetnTrack_nog[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    }
                }
                else
                {
                    h_hev_end_emergjetpt[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                    h_hev_end_emergjetEta[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    h_hev_end_emergjetnTrack[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    if ((*v_ht400_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_end_emergjetpt_nog[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_hev_end_emergjetEta_nog[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                        h_hev_end_emergjetnTrack_nog[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    }
                }
                if ((*v_ht400_alpha)[i] <= 0.35)
                {
                    h_hev_emergjetpt_cutalpha[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                    h_hev_emergjetEta_cutalpha[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    h_hev_emergjetnTrack_cutalpha[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    if ((*v_ht400_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_cutalpha_nog[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_hev_emergjetEta_cutalpha_nog[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                        h_hev_emergjetnTrack_cutalpha_nog[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    }
                    if (abs((*v_ht400_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt_cutalpha[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_hev_barr_emergjetEta_cutalpha[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                        h_hev_barr_emergjetnTrack_cutalpha[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                        if ((*v_ht400_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_cutalpha_nog[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                            h_hev_barr_emergjetEta_cutalpha_nog[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                            h_hev_barr_emergjetnTrack_cutalpha_nog[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt_cutalpha[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_hev_end_emergjetEta_cutalpha[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                        h_hev_end_emergjetnTrack_cutalpha[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                        if ((*v_ht400_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_cutalpha_nog[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                            h_hev_end_emergjetEta_cutalpha_nog[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                            h_hev_end_emergjetnTrack_cutalpha_nog[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                        }
                    }
                }
            }
            else
            {
                h_light_emergjetpt[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                h_light_emergjetEta[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                h_light_emergjetnTrack[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                if (abs((*v_ht400_JetEta)[i]) < 1.479)
                {
                    h_light_barr_emergjetpt[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                    h_light_barr_emergjetEta[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    h_light_barr_emergjetnTrack[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                }
                else
                {
                    h_light_end_emergjetpt[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                    h_light_end_emergjetEta[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    h_light_end_emergjetnTrack[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                }
                if ((*v_ht400_alpha)[i] <= 0.35)
                {
                    h_light_emergjetpt_cutalpha[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                    h_light_emergjetEta_cutalpha[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    h_light_emergjetnTrack_cutalpha[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    if (abs((*v_ht400_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt_cutalpha[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_light_barr_emergjetEta_cutalpha[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                        h_light_barr_emergjetnTrack_cutalpha[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt_cutalpha[4]->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_light_end_emergjetEta_cutalpha[4]->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                        h_light_end_emergjetnTrack_cutalpha[4]->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    }
                }
            }
        }
    } // End of HT400 loop
    TTree *T_event4;
    DYHT600_1->GetObject("h1", T_event4);
    T_event4->SetBranchAddress("I_weight", &I_ht600_weight);
    T_event4->SetBranchAddress("v_fakeJethadronflavor", &v_ht600_Jethadronflavor);
    T_event4->SetBranchAddress("v_fakeJetpartonflavor", &v_ht600_Jetpartonflavor);
    T_event4->SetBranchAddress("v_fakeJetPt", &v_ht600_JetPT);
    T_event4->SetBranchAddress("v_fakeJetEta", &v_ht600_JetEta);
    T_event4->SetBranchAddress("v_fakealpha", &v_ht600_alpha);
    T_event4->SetBranchAddress("v_N_Tracks", &v_ht600_JetnTracks);
    T_event4->SetBranchAddress("I_nJets", &I_ht600_nThinJets);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        for (int i = 0; i < v_ht600_Jethadronflavor->size(); i++)
        {
            if ((*v_ht600_Jethadronflavor)[i] == 4 || (*v_ht600_Jethadronflavor)[i] == 5)
            {
                h_hev_emergjetpt[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                h_hev_emergjetEta[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                h_hev_emergjetnTrack[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                if ((*v_ht600_Jetpartonflavor)[i] != 21)
                {
                    h_hev_emergjetpt_nog[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                    h_hev_emergjetEta_nog[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    h_hev_emergjetnTrack_nog[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                }
                if (abs((*v_ht600_JetEta)[i]) < 1.479)
                {
                    h_hev_barr_emergjetpt[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                    h_hev_barr_emergjetEta[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    h_hev_barr_emergjetnTrack[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    if ((*v_ht600_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_barr_emergjetpt_nog[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_hev_barr_emergjetEta_nog[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                        h_hev_barr_emergjetnTrack_nog[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    }
                }
                else
                {
                    h_hev_end_emergjetpt[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                    h_hev_end_emergjetEta[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    h_hev_end_emergjetnTrack[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    if ((*v_ht600_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_end_emergjetpt_nog[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_hev_end_emergjetEta_nog[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                        h_hev_end_emergjetnTrack_nog[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    }
                }
                if ((*v_ht600_alpha)[i] <= 0.35)
                {
                    h_hev_emergjetpt_cutalpha[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                    h_hev_emergjetEta_cutalpha[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    h_hev_emergjetnTrack_cutalpha[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    if ((*v_ht600_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_cutalpha_nog[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_hev_emergjetEta_cutalpha_nog[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                        h_hev_emergjetnTrack_cutalpha_nog[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    }
                    if (abs((*v_ht600_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt_cutalpha[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_hev_barr_emergjetEta_cutalpha[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                        h_hev_barr_emergjetnTrack_cutalpha[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                        if ((*v_ht600_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_cutalpha_nog[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                            h_hev_barr_emergjetEta_cutalpha_nog[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                            h_hev_barr_emergjetnTrack_cutalpha_nog[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt_cutalpha[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_hev_end_emergjetEta_cutalpha[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                        h_hev_end_emergjetnTrack_cutalpha[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                        if ((*v_ht600_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_cutalpha_nog[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                            h_hev_end_emergjetEta_cutalpha_nog[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                            h_hev_end_emergjetnTrack_cutalpha_nog[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                        }
                    }
                }
            }
            else
            {
                h_light_emergjetpt[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                h_light_emergjetEta[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                h_light_emergjetnTrack[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                if (abs((*v_ht600_JetEta)[i]) < 1.479)
                {
                    h_light_barr_emergjetpt[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                    h_light_barr_emergjetEta[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    h_light_barr_emergjetnTrack[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                }
                else
                {
                    h_light_end_emergjetpt[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                    h_light_end_emergjetEta[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    h_light_end_emergjetnTrack[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                }
                if ((*v_ht600_alpha)[i] <= 0.35)
                {
                    h_light_emergjetpt_cutalpha[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                    h_light_emergjetEta_cutalpha[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    h_light_emergjetnTrack_cutalpha[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    if (abs((*v_ht600_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt_cutalpha[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_light_barr_emergjetEta_cutalpha[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                        h_light_barr_emergjetnTrack_cutalpha[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt_cutalpha[5]->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_light_end_emergjetEta_cutalpha[5]->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                        h_light_end_emergjetnTrack_cutalpha[5]->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    }
                }
            }
        }
    } // End of HT600 loop
    TTree *T_event5;
    DYHT800_1->GetObject("h1", T_event5);
    T_event5->SetBranchAddress("I_weight", &I_ht800_weight);
    T_event5->SetBranchAddress("v_fakeJethadronflavor", &v_ht800_Jethadronflavor);
    T_event5->SetBranchAddress("v_fakeJetpartonflavor", &v_ht800_Jetpartonflavor);
    T_event5->SetBranchAddress("v_fakeJetPt", &v_ht800_JetPT);
    T_event5->SetBranchAddress("v_fakeJetEta", &v_ht800_JetEta);
    T_event5->SetBranchAddress("v_fakealpha", &v_ht800_alpha);
    T_event5->SetBranchAddress("v_N_Tracks", &v_ht800_JetnTracks);
    T_event5->SetBranchAddress("I_nJets", &I_ht800_nThinJets);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        for (int i = 0; i < v_ht800_Jethadronflavor->size(); i++)
        {
            if ((*v_ht800_Jethadronflavor)[i] == 4 || (*v_ht800_Jethadronflavor)[i] == 5)
            {
                h_hev_emergjetpt[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                h_hev_emergjetEta[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                h_hev_emergjetnTrack[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                if ((*v_ht800_Jetpartonflavor)[i] != 21)
                {
                    h_hev_emergjetpt_nog[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                    h_hev_emergjetEta_nog[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    h_hev_emergjetnTrack_nog[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                }
                if (abs((*v_ht800_JetEta)[i]) < 1.479)
                {
                    h_hev_barr_emergjetpt[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                    h_hev_barr_emergjetEta[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    h_hev_barr_emergjetnTrack[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    if ((*v_ht800_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_barr_emergjetpt_nog[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_hev_barr_emergjetEta_nog[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                        h_hev_barr_emergjetnTrack_nog[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    }
                }
                else
                {
                    h_hev_end_emergjetpt[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                    h_hev_end_emergjetEta[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    h_hev_end_emergjetnTrack[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    if ((*v_ht800_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_end_emergjetpt_nog[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_hev_end_emergjetEta_nog[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                        h_hev_end_emergjetnTrack_nog[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    }
                }
                if ((*v_ht800_alpha)[i] <= 0.35)
                {
                    h_hev_emergjetpt_cutalpha[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                    h_hev_emergjetEta_cutalpha[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    h_hev_emergjetnTrack_cutalpha[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    if ((*v_ht800_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_cutalpha_nog[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_hev_emergjetEta_cutalpha_nog[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                        h_hev_emergjetnTrack_cutalpha_nog[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    }
                    if (abs((*v_ht800_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt_cutalpha[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_hev_barr_emergjetEta_cutalpha[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                        h_hev_barr_emergjetnTrack_cutalpha[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                        if ((*v_ht800_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_cutalpha_nog[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                            h_hev_barr_emergjetEta_cutalpha_nog[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                            h_hev_barr_emergjetnTrack_cutalpha_nog[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt_cutalpha[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_hev_end_emergjetEta_cutalpha[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                        h_hev_end_emergjetnTrack_cutalpha[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                        if ((*v_ht800_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_cutalpha_nog[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                            h_hev_end_emergjetEta_cutalpha_nog[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                            h_hev_end_emergjetnTrack_cutalpha_nog[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                        }
                    }
                }
            }
            else
            {
                h_light_emergjetpt[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                h_light_emergjetEta[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                h_light_emergjetnTrack[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                if (abs((*v_ht800_JetEta)[i]) < 1.479)
                {
                    h_light_barr_emergjetpt[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                    h_light_barr_emergjetEta[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    h_light_barr_emergjetnTrack[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                }
                else
                {
                    h_light_end_emergjetpt[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                    h_light_end_emergjetEta[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    h_light_end_emergjetnTrack[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                }
                if ((*v_ht800_alpha)[i] <= 0.35)
                {
                    h_light_emergjetpt_cutalpha[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                    h_light_emergjetEta_cutalpha[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    h_light_emergjetnTrack_cutalpha[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    if (abs((*v_ht800_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt_cutalpha[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_light_barr_emergjetEta_cutalpha[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                        h_light_barr_emergjetnTrack_cutalpha[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt_cutalpha[6]->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_light_end_emergjetEta_cutalpha[6]->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                        h_light_end_emergjetnTrack_cutalpha[6]->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    }
                }
            }
        }
    } // End of HT800 loop
    TTree *T_event6;
    DYHT1200_1->GetObject("h1", T_event6);
    T_event6->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_event6->SetBranchAddress("v_fakeJethadronflavor", &v_ht1200_Jethadronflavor);
    T_event6->SetBranchAddress("v_fakeJetpartonflavor", &v_ht1200_Jetpartonflavor);
    T_event6->SetBranchAddress("v_fakeJetPt", &v_ht1200_JetPT);
    T_event6->SetBranchAddress("v_fakeJetEta", &v_ht1200_JetEta);
    T_event6->SetBranchAddress("v_fakealpha", &v_ht1200_alpha);
    T_event6->SetBranchAddress("v_N_Tracks", &v_ht1200_JetnTracks);
    T_event6->SetBranchAddress("I_nJets", &I_ht1200_nThinJets);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        for (int i = 0; i < v_ht1200_Jethadronflavor->size(); i++)
        {
            if ((*v_ht1200_Jethadronflavor)[i] == 4 || (*v_ht1200_Jethadronflavor)[i] == 5)
            {
                h_hev_emergjetpt[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                h_hev_emergjetEta[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                h_hev_emergjetnTrack[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                if ((*v_ht1200_Jetpartonflavor)[i] != 21)
                {
                    h_hev_emergjetpt_nog[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                    h_hev_emergjetEta_nog[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    h_hev_emergjetnTrack_nog[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                }
                if (abs((*v_ht1200_JetEta)[i]) < 1.479)
                {
                    h_hev_barr_emergjetpt[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                    h_hev_barr_emergjetEta[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    h_hev_barr_emergjetnTrack[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    if ((*v_ht1200_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_barr_emergjetpt_nog[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_hev_barr_emergjetEta_nog[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                        h_hev_barr_emergjetnTrack_nog[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    }
                }
                else
                {
                    h_hev_end_emergjetpt[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                    h_hev_end_emergjetEta[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    h_hev_end_emergjetnTrack[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    if ((*v_ht1200_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_end_emergjetpt_nog[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_hev_end_emergjetEta_nog[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                        h_hev_end_emergjetnTrack_nog[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    }
                }
                if ((*v_ht1200_alpha)[i] <= 0.35)
                {
                    h_hev_emergjetpt_cutalpha[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                    h_hev_emergjetEta_cutalpha[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    h_hev_emergjetnTrack_cutalpha[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    if ((*v_ht1200_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_cutalpha_nog[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_hev_emergjetEta_cutalpha_nog[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                        h_hev_emergjetnTrack_cutalpha_nog[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    }
                    if (abs((*v_ht1200_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt_cutalpha[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_hev_barr_emergjetEta_cutalpha[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                        h_hev_barr_emergjetnTrack_cutalpha[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                        if ((*v_ht1200_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_cutalpha_nog[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                            h_hev_barr_emergjetEta_cutalpha_nog[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                            h_hev_barr_emergjetnTrack_cutalpha_nog[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt_cutalpha[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_hev_end_emergjetEta_cutalpha[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                        h_hev_end_emergjetnTrack_cutalpha[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                        if ((*v_ht1200_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_cutalpha_nog[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                            h_hev_end_emergjetEta_cutalpha_nog[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                            h_hev_end_emergjetnTrack_cutalpha_nog[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                        }
                    }
                }
            }
            else
            {
                h_light_emergjetpt[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                h_light_emergjetEta[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                h_light_emergjetnTrack[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                if (abs((*v_ht1200_JetEta)[i]) < 1.479)
                {
                    h_light_barr_emergjetpt[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                    h_light_barr_emergjetEta[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    h_light_barr_emergjetnTrack[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                }
                else
                {
                    h_light_end_emergjetpt[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                    h_light_end_emergjetEta[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    h_light_end_emergjetnTrack[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                }
                if ((*v_ht1200_alpha)[i] <= 0.35)
                {
                    h_light_emergjetpt_cutalpha[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                    h_light_emergjetEta_cutalpha[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    h_light_emergjetnTrack_cutalpha[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    if (abs((*v_ht1200_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt_cutalpha[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_light_barr_emergjetEta_cutalpha[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                        h_light_barr_emergjetnTrack_cutalpha[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt_cutalpha[7]->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_light_end_emergjetEta_cutalpha[7]->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                        h_light_end_emergjetnTrack_cutalpha[7]->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    }
                }
            }
        }
    } // End of HT1200 loop
    TTree *T_event7;
    DYHT2500_1->GetObject("h1", T_event7);
    T_event7->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_event7->SetBranchAddress("v_fakeJethadronflavor", &v_ht2500_Jethadronflavor);
    T_event7->SetBranchAddress("v_fakeJetpartonflavor", &v_ht2500_Jetpartonflavor);
    T_event7->SetBranchAddress("v_fakeJetPt", &v_ht2500_JetPT);
    T_event7->SetBranchAddress("v_fakeJetEta", &v_ht2500_JetEta);
    T_event7->SetBranchAddress("v_fakealpha", &v_ht2500_alpha);
    T_event7->SetBranchAddress("v_N_Tracks", &v_ht2500_JetnTracks);
    T_event7->SetBranchAddress("I_nJets", &I_ht2500_nThinJets);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        for (int i = 0; i < v_ht2500_Jethadronflavor->size(); i++)
        {
            if ((*v_ht2500_Jethadronflavor)[i] == 4 || (*v_ht2500_Jethadronflavor)[i] == 5)
            {
                h_hev_emergjetpt[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                h_hev_emergjetEta[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                h_hev_emergjetnTrack[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                if ((*v_ht2500_Jetpartonflavor)[i] != 21)
                {
                    cout<<"here"<<endl;
                    h_hev_emergjetpt_nog[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                    h_hev_emergjetEta_nog[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    h_hev_emergjetnTrack_nog[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                }
                if (abs((*v_ht2500_JetEta)[i]) < 1.479)
                {
                    h_hev_barr_emergjetpt[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                    h_hev_barr_emergjetEta[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    h_hev_barr_emergjetnTrack[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    if ((*v_ht2500_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_barr_emergjetpt_nog[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_hev_barr_emergjetEta_nog[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                        h_hev_barr_emergjetnTrack_nog[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    }
                }
                else
                {
                    h_hev_end_emergjetpt[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                    h_hev_end_emergjetEta[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    h_hev_end_emergjetnTrack[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    if ((*v_ht2500_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_end_emergjetpt_nog[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_hev_end_emergjetEta_nog[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                        h_hev_end_emergjetnTrack_nog[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    }
                }
                if ((*v_ht2500_alpha)[i] <= 0.35)
                {
                    h_hev_emergjetpt_cutalpha[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                    h_hev_emergjetEta_cutalpha[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    h_hev_emergjetnTrack_cutalpha[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    if ((*v_ht2500_Jetpartonflavor)[i] != 21)
                    {
                        h_hev_emergjetpt_cutalpha_nog[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_hev_emergjetEta_cutalpha_nog[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                        h_hev_emergjetnTrack_cutalpha_nog[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    }
                    if (abs((*v_ht2500_JetEta)[i]) < 1.479)
                    {
                        h_hev_barr_emergjetpt_cutalpha[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_hev_barr_emergjetEta_cutalpha[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                        h_hev_barr_emergjetnTrack_cutalpha[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                        if ((*v_ht2500_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_barr_emergjetpt_cutalpha_nog[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                            h_hev_barr_emergjetEta_cutalpha_nog[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                            h_hev_barr_emergjetnTrack_cutalpha_nog[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                        }
                    }
                    else
                    {
                        h_hev_end_emergjetpt_cutalpha[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_hev_end_emergjetEta_cutalpha[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                        h_hev_end_emergjetnTrack_cutalpha[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                        if ((*v_ht2500_Jetpartonflavor)[i] != 21)
                        {
                            h_hev_end_emergjetpt_cutalpha_nog[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                            h_hev_end_emergjetEta_cutalpha_nog[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                            h_hev_end_emergjetnTrack_cutalpha_nog[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                        }
                    }
                }
            }
            else
            {
                h_light_emergjetpt[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                h_light_emergjetEta[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                h_light_emergjetnTrack[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                if (abs((*v_ht2500_JetEta)[i]) < 1.479)
                {
                    h_light_barr_emergjetpt[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                    h_light_barr_emergjetEta[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    h_light_barr_emergjetnTrack[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                }
                else
                {
                    h_light_end_emergjetpt[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                    h_light_end_emergjetEta[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    h_light_end_emergjetnTrack[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                }
                if ((*v_ht2500_alpha)[i] <= 0.35)
                {
                    h_light_emergjetpt_cutalpha[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                    h_light_emergjetEta_cutalpha[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    h_light_emergjetnTrack_cutalpha[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    if (abs((*v_ht2500_JetEta)[i]) < 1.479)
                    {
                        h_light_barr_emergjetpt_cutalpha[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_light_barr_emergjetEta_cutalpha[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                        h_light_barr_emergjetnTrack_cutalpha[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    }
                    else
                    {
                        h_light_end_emergjetpt_cutalpha[8]->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_light_end_emergjetEta_cutalpha[8]->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                        h_light_end_emergjetnTrack_cutalpha[8]->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    }
                }
            }
        }
    } // End of HT2500 loop

    for (int i = 0; i < 8; i++)
    {
        h_hev_emergjetpt[0]->Add(h_hev_emergjetpt[i + 1]);
        h_hev_barr_emergjetpt[0]->Add(h_hev_barr_emergjetpt[i + 1]);
        h_hev_end_emergjetpt[0]->Add(h_hev_end_emergjetpt[i + 1]);
        h_hev_emergjetpt_cutalpha[0]->Add(h_hev_emergjetpt_cutalpha[i + 1]);
        h_hev_barr_emergjetpt_cutalpha[0]->Add(h_hev_barr_emergjetpt_cutalpha[i + 1]);
        h_hev_end_emergjetpt_cutalpha[0]->Add(h_hev_end_emergjetpt_cutalpha[i + 1]);
        h_hev_emergjetpt_nog[0]->Add(h_hev_emergjetpt_nog[i + 1]);
        h_hev_barr_emergjetpt_nog[0]->Add(h_hev_barr_emergjetpt_nog[i + 1]);
        h_hev_end_emergjetpt_nog[0]->Add(h_hev_end_emergjetpt_nog[i + 1]);
        h_hev_emergjetpt_cutalpha_nog[0]->Add(h_hev_emergjetpt_cutalpha_nog[i + 1]);
        h_hev_barr_emergjetpt_cutalpha_nog[0]->Add(h_hev_barr_emergjetpt_cutalpha_nog[i + 1]);
        h_hev_end_emergjetpt_cutalpha_nog[0]->Add(h_hev_end_emergjetpt_cutalpha_nog[i + 1]);
        h_light_emergjetpt[0]->Add(h_light_emergjetpt[i + 1]);
        h_light_barr_emergjetpt[0]->Add(h_light_barr_emergjetpt[i + 1]);
        h_light_end_emergjetpt[0]->Add(h_light_end_emergjetpt[i + 1]);
        h_light_emergjetpt_cutalpha[0]->Add(h_light_emergjetpt_cutalpha[i + 1]);
        h_light_barr_emergjetpt_cutalpha[0]->Add(h_light_barr_emergjetpt_cutalpha[i + 1]);
        h_light_end_emergjetpt_cutalpha[0]->Add(h_light_end_emergjetpt_cutalpha[i + 1]);
        h_hev_emergjetEta[0]->Add(h_hev_emergjetEta[i + 1]);
        h_hev_barr_emergjetEta[0]->Add(h_hev_barr_emergjetEta[i + 1]);
        h_hev_end_emergjetEta[0]->Add(h_hev_end_emergjetEta[i + 1]);
        h_hev_emergjetEta_cutalpha[0]->Add(h_hev_emergjetEta_cutalpha[i + 1]);
        h_hev_barr_emergjetEta_cutalpha[0]->Add(h_hev_barr_emergjetEta_cutalpha[i + 1]);
        h_hev_end_emergjetEta_cutalpha[0]->Add(h_hev_end_emergjetEta_cutalpha[i + 1]);
        h_hev_emergjetEta_nog[0]->Add(h_hev_emergjetEta_nog[i + 1]);
        h_hev_barr_emergjetEta_nog[0]->Add(h_hev_barr_emergjetEta_nog[i + 1]);
        h_hev_end_emergjetEta_nog[0]->Add(h_hev_end_emergjetEta_nog[i + 1]);
        h_hev_emergjetEta_cutalpha_nog[0]->Add(h_hev_emergjetEta_cutalpha_nog[i + 1]);
        h_hev_barr_emergjetEta_cutalpha_nog[0]->Add(h_hev_barr_emergjetEta_cutalpha_nog[i + 1]);
        h_hev_end_emergjetEta_cutalpha_nog[0]->Add(h_hev_end_emergjetEta_cutalpha_nog[i + 1]);
        h_light_emergjetEta[0]->Add(h_light_emergjetEta[i + 1]);
        h_light_barr_emergjetEta[0]->Add(h_light_barr_emergjetEta[i + 1]);
        h_light_end_emergjetEta[0]->Add(h_light_end_emergjetEta[i + 1]);
        h_light_emergjetEta_cutalpha[0]->Add(h_light_emergjetEta_cutalpha[i + 1]);
        h_light_barr_emergjetEta_cutalpha[0]->Add(h_light_barr_emergjetEta_cutalpha[i + 1]);
        h_light_end_emergjetEta_cutalpha[0]->Add(h_light_end_emergjetEta_cutalpha[i + 1]);
        h_hev_emergjetnTrack[0]->Add(h_hev_emergjetnTrack[i + 1]);
        h_hev_barr_emergjetnTrack[0]->Add(h_hev_barr_emergjetnTrack[i + 1]);
        h_hev_end_emergjetnTrack[0]->Add(h_hev_end_emergjetnTrack[i + 1]);
        h_hev_emergjetnTrack_cutalpha[0]->Add(h_hev_emergjetnTrack_cutalpha[i + 1]);
        h_hev_barr_emergjetnTrack_cutalpha[0]->Add(h_hev_barr_emergjetnTrack_cutalpha[i + 1]);
        h_hev_end_emergjetnTrack_cutalpha[0]->Add(h_hev_end_emergjetnTrack_cutalpha[i + 1]);
        h_hev_emergjetnTrack_nog[0]->Add(h_hev_emergjetnTrack_nog[i + 1]);
        h_hev_barr_emergjetnTrack_nog[0]->Add(h_hev_barr_emergjetnTrack_nog[i + 1]);
        h_hev_end_emergjetnTrack_nog[0]->Add(h_hev_end_emergjetnTrack_nog[i + 1]);
        h_hev_emergjetnTrack_cutalpha_nog[0]->Add(h_hev_emergjetnTrack_cutalpha_nog[i + 1]);
        h_hev_barr_emergjetnTrack_cutalpha_nog[0]->Add(h_hev_barr_emergjetnTrack_cutalpha_nog[i + 1]);
        h_hev_end_emergjetnTrack_cutalpha_nog[0]->Add(h_hev_end_emergjetnTrack_cutalpha_nog[i + 1]);
        h_light_emergjetnTrack[0]->Add(h_light_emergjetnTrack[i + 1]);
        h_light_barr_emergjetnTrack[0]->Add(h_light_barr_emergjetnTrack[i + 1]);
        h_light_end_emergjetnTrack[0]->Add(h_light_end_emergjetnTrack[i + 1]);
        h_light_emergjetnTrack_cutalpha[0]->Add(h_light_emergjetnTrack_cutalpha[i + 1]);
        h_light_barr_emergjetnTrack_cutalpha[0]->Add(h_light_barr_emergjetnTrack_cutalpha[i + 1]);
        h_light_end_emergjetnTrack_cutalpha[0]->Add(h_light_end_emergjetnTrack_cutalpha[i + 1]);
    }
    h_hev_end_emergjetnTrack_nog[0]->Draw();
    TH1D *DY_hev_emergjetpt_fakeRate = (TH1D *)h_hev_emergjetpt_cutalpha[0]->Clone("DY_hev_emergjetpt_fakeRate");
    DY_hev_emergjetpt_fakeRate->Divide(DY_hev_emergjetpt_fakeRate, h_hev_emergjetpt[0], 1, 1, "b");

    TH1F *DY_hev_emergjetEta_fakeRate = (TH1F *)h_hev_emergjetEta_cutalpha[0]->Clone("DY_hev_emergjetEta_fakeRate");
    DY_hev_emergjetEta_fakeRate->Divide(DY_hev_emergjetEta_fakeRate, h_hev_emergjetEta[0], 1, 1, "b");

    TH1F *DY_hev_emergjetnTrack_fakeRate = (TH1F *)h_hev_emergjetnTrack_cutalpha[0]->Clone("DY_hev_emergjetnTrack_fakeRate");
    DY_hev_emergjetnTrack_fakeRate->Divide(DY_hev_emergjetnTrack_fakeRate, h_hev_emergjetnTrack[0], 1, 1, "b");

    TH1D *DY_hev_emergjetpt_nog_fakeRate = (TH1D *)h_hev_emergjetpt_cutalpha_nog[0]->Clone("DY_hev_emergjetpt_nog_fakeRate");
    DY_hev_emergjetpt_nog_fakeRate->Divide(DY_hev_emergjetpt_nog_fakeRate, h_hev_emergjetpt_nog[0], 1, 1, "b");

    TH1F *DY_hev_emergjetEta_nog_fakeRate = (TH1F *)h_hev_emergjetEta_cutalpha_nog[0]->Clone("DY_hev_emergjetEta_nog_fakeRate");
    DY_hev_emergjetEta_nog_fakeRate->Divide(DY_hev_emergjetEta_nog_fakeRate, h_hev_emergjetEta_nog[0], 1, 1, "b");

    TH1F *DY_hev_emergjetnTrack_nog_fakeRate = (TH1F *)h_hev_emergjetnTrack_cutalpha_nog[0]->Clone("DY_hev_emergjetnTrack_nog_fakeRate");
    DY_hev_emergjetnTrack_nog_fakeRate->Divide(DY_hev_emergjetnTrack_nog_fakeRate, h_hev_emergjetnTrack_nog[0], 1, 1, "b");

    TH1F *DY_light_emergjetpt_fakeRate = (TH1F *)h_light_emergjetpt_cutalpha[0]->Clone("DY_light_emergjetpt_fakeRate");
    DY_light_emergjetpt_fakeRate->Divide(DY_light_emergjetpt_fakeRate, h_light_emergjetpt[0], 1, 1, "b");

    TH1F *DY_light_emergjetEta_fakeRate = (TH1F *)h_light_emergjetEta_cutalpha[0]->Clone("DY_light_emergjetEta_fakeRate");
    DY_light_emergjetEta_fakeRate->Divide(DY_light_emergjetEta_fakeRate, h_light_emergjetEta[0], 1, 1, "b");

    TH1F *DY_light_emergjetnTrack_fakeRate = (TH1F *)h_light_emergjetnTrack_cutalpha[0]->Clone("DY_light_emergjetnTrack_fakeRate");
    DY_light_emergjetnTrack_fakeRate->Divide(DY_light_emergjetnTrack_fakeRate, h_light_emergjetnTrack[0], 1, 1, "b");

    TH1D *DY_hev_barr_emergjetpt_fakeRate = (TH1D *)h_hev_barr_emergjetpt_cutalpha[0]->Clone("DY_hev_barr_emergjetpt_fakeRate");
    DY_hev_barr_emergjetpt_fakeRate->Divide(DY_hev_barr_emergjetpt_fakeRate, h_hev_barr_emergjetpt[0], 1, 1, "b");

    TH1F *DY_hev_barr_emergjetEta_fakeRate = (TH1F *)h_hev_barr_emergjetEta_cutalpha[0]->Clone("DY_hev_barr_emergjetEta_fakeRate");
    DY_hev_barr_emergjetEta_fakeRate->Divide(DY_hev_barr_emergjetEta_fakeRate, h_hev_barr_emergjetEta[0], 1, 1, "b");

    TH1F *DY_hev_barr_emergjetnTrack_fakeRate = (TH1F *)h_hev_barr_emergjetnTrack_cutalpha[0]->Clone("DY_hev_barr_emergjetnTrack_fakeRate");
    DY_hev_barr_emergjetnTrack_fakeRate->Divide(DY_hev_barr_emergjetnTrack_fakeRate, h_hev_barr_emergjetnTrack[0], 1, 1, "b");

    TH1D *DY_hev_barr_emergjetpt_nog_fakeRate = (TH1D *)h_hev_barr_emergjetpt_cutalpha_nog[0]->Clone("DY_hev_barr_emergjetpt_nog_fakeRate");
    DY_hev_barr_emergjetpt_nog_fakeRate->Divide(DY_hev_barr_emergjetpt_nog_fakeRate, h_hev_barr_emergjetpt_nog[0], 1, 1, "b");

    TH1F *DY_hev_barr_emergjetEta_nog_fakeRate = (TH1F *)h_hev_barr_emergjetEta_cutalpha_nog[0]->Clone("DY_hev_barr_emergjetEta_nog_fakeRate");
    DY_hev_barr_emergjetEta_nog_fakeRate->Divide(DY_hev_barr_emergjetEta_nog_fakeRate, h_hev_barr_emergjetEta_nog[0], 1, 1, "b");

    TH1F *DY_hev_barr_emergjetnTrack_nog_fakeRate = (TH1F *)h_hev_barr_emergjetnTrack_cutalpha_nog[0]->Clone("DY_hev_barr_emergjetnTrack_nog_fakeRate");
    DY_hev_barr_emergjetnTrack_nog_fakeRate->Divide(DY_hev_barr_emergjetnTrack_nog_fakeRate, h_hev_barr_emergjetnTrack_nog[0], 1, 1, "b");

    TH1F *DY_light_barr_emergjetpt_fakeRate = (TH1F *)h_light_barr_emergjetpt_cutalpha[0]->Clone("DY_light_barr_emergjetpt_fakeRate");
    DY_light_barr_emergjetpt_fakeRate->Divide(DY_light_barr_emergjetpt_fakeRate, h_light_barr_emergjetpt[0], 1, 1, "b");

    TH1F *DY_light_barr_emergjetEta_fakeRate = (TH1F *)h_light_barr_emergjetEta_cutalpha[0]->Clone("DY_light_barr_emergjetEta_fakeRate");
    DY_light_barr_emergjetEta_fakeRate->Divide(DY_light_barr_emergjetEta_fakeRate, h_light_barr_emergjetEta[0], 1, 1, "b");

    TH1F *DY_light_barr_emergjetnTrack_fakeRate = (TH1F *)h_light_barr_emergjetnTrack_cutalpha[0]->Clone("DY_light_barr_emergjetnTrack_fakeRate");
    DY_light_barr_emergjetnTrack_fakeRate->Divide(DY_light_barr_emergjetnTrack_fakeRate, h_light_barr_emergjetnTrack[0], 1, 1, "b");

    TH1D *DY_hev_end_emergjetpt_fakeRate = (TH1D *)h_hev_end_emergjetpt_cutalpha[0]->Clone("DY_hev_end_emergjetpt_fakeRate");
    DY_hev_end_emergjetpt_fakeRate->Divide(DY_hev_end_emergjetpt_fakeRate, h_hev_end_emergjetpt[0], 1, 1, "b");

    TH1F *DY_hev_end_emergjetEta_fakeRate = (TH1F *)h_hev_end_emergjetEta_cutalpha[0]->Clone("DY_hev_end_emergjetEta_fakeRate");
    DY_hev_end_emergjetEta_fakeRate->Divide(DY_hev_end_emergjetEta_fakeRate, h_hev_end_emergjetEta[0], 1, 1, "b");

    TH1F *DY_hev_end_emergjetnTrack_fakeRate = (TH1F *)h_hev_end_emergjetnTrack_cutalpha[0]->Clone("DY_hev_end_emergjetnTrack_fakeRate");
    DY_hev_end_emergjetnTrack_fakeRate->Divide(DY_hev_end_emergjetnTrack_fakeRate, h_hev_end_emergjetnTrack[0], 1, 1, "b");

    TH1D *DY_hev_end_emergjetpt_nog_fakeRate = (TH1D *)h_hev_end_emergjetpt_cutalpha_nog[0]->Clone("DY_hev_end_emergjetpt_nog_fakeRate");
    DY_hev_end_emergjetpt_nog_fakeRate->Divide(DY_hev_end_emergjetpt_nog_fakeRate, h_hev_end_emergjetpt_nog[0], 1, 1, "b");

    TH1F *DY_hev_end_emergjetEta_nog_fakeRate = (TH1F *)h_hev_end_emergjetEta_cutalpha_nog[0]->Clone("DY_hev_end_emergjetEta_nog_fakeRate");
    DY_hev_end_emergjetEta_nog_fakeRate->Divide(DY_hev_end_emergjetEta_nog_fakeRate, h_hev_end_emergjetEta_nog[0], 1, 1, "b");

    TH1F *DY_hev_end_emergjetnTrack_nog_fakeRate = (TH1F *)h_hev_end_emergjetnTrack_cutalpha_nog[0]->Clone("DY_hev_end_emergjetnTrack_nog_fakeRate");
    DY_hev_end_emergjetnTrack_nog_fakeRate->Divide(DY_hev_end_emergjetnTrack_nog_fakeRate, h_hev_end_emergjetnTrack_nog[0], 1, 1, "b");

    TH1F *DY_light_end_emergjetpt_fakeRate = (TH1F *)h_light_end_emergjetpt_cutalpha[0]->Clone("DY_light_end_emergjetpt_fakeRate");
    DY_light_end_emergjetpt_fakeRate->Divide(DY_light_end_emergjetpt_fakeRate, h_light_end_emergjetpt[0], 1, 1, "b");

    TH1F *DY_light_end_emergjetEta_fakeRate = (TH1F *)h_light_end_emergjetEta_cutalpha[0]->Clone("DY_light_end_emergjetEta_fakeRate");
    DY_light_end_emergjetEta_fakeRate->Divide(DY_light_end_emergjetEta_fakeRate, h_light_end_emergjetEta[0], 1, 1, "b");

    TH1F *DY_light_end_emergjetnTrack_fakeRate = (TH1F *)h_light_end_emergjetnTrack_cutalpha[0]->Clone("DY_light_end_emergjetnTrack_fakeRate");
    DY_light_end_emergjetnTrack_fakeRate->Divide(DY_light_end_emergjetnTrack_fakeRate, h_light_end_emergjetnTrack[0], 1, 1, "b");

    DY_hev_barr_emergjetnTrack_fakeRate->Draw();

    TFile *outFile = new TFile("./../../../../root_file/BgEstimation/DYHT_fakerateStudy_v2.root", "RECREATE");
    outFile->cd();
    DY_hev_emergjetpt_fakeRate->Write();
    DY_hev_emergjetEta_fakeRate->Write();
    DY_hev_emergjetnTrack_fakeRate->Write();
    DY_hev_emergjetpt_nog_fakeRate->Write();
    DY_hev_emergjetEta_nog_fakeRate->Write();
    DY_hev_emergjetnTrack_nog_fakeRate->Write();
    DY_light_emergjetpt_fakeRate->Write();
    DY_light_emergjetEta_fakeRate->Write();
    DY_light_emergjetnTrack_fakeRate->Write();
    DY_hev_barr_emergjetpt_fakeRate->Write();
    DY_hev_barr_emergjetEta_fakeRate->Write();
    DY_hev_barr_emergjetnTrack_fakeRate->Write();
    DY_hev_barr_emergjetpt_nog_fakeRate->Write();
    DY_hev_barr_emergjetEta_nog_fakeRate->Write();
    DY_hev_barr_emergjetnTrack_nog_fakeRate->Write();
    DY_light_barr_emergjetpt_fakeRate->Write();
    DY_light_barr_emergjetEta_fakeRate->Write();
    DY_light_barr_emergjetnTrack_fakeRate->Write();
    DY_hev_end_emergjetpt_fakeRate->Write();
    DY_hev_end_emergjetEta_fakeRate->Write();
    DY_hev_end_emergjetnTrack_fakeRate->Write();
    DY_hev_end_emergjetpt_nog_fakeRate->Write();
    DY_hev_end_emergjetEta_nog_fakeRate->Write();
    DY_hev_end_emergjetnTrack_nog_fakeRate->Write();
    DY_light_end_emergjetpt_fakeRate->Write();
    DY_light_end_emergjetEta_fakeRate->Write();
    DY_light_end_emergjetnTrack_fakeRate->Write();

    // TH1F *DY_hev_barr_emergjetnTrack_fakeRate = (TH1F *)DY_hev_barr_emergjetnTrack_cutalpha[0]->Clone("DY_hev_barr_emergjetnTrack_fakeRate");
    // DY_hev_barr_emergjetnTrack_fakeRate->Divide(DY_hev_barr_emergjetnTrack_cutalpha[0], h_hev_emergjetnTrack[0], 1, 1, "b");

    // TH1F *h_hev_DY_emergjetpt = (TH1F *)h_hev_emergjetpt[0]->Clone("h_hev_DY_emergjetpt");

} // End of voild function
int main(int argc, char *argv[])
{
    ee_half_HT_fake_rate();
}