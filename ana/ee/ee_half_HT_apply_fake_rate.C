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
using namespace RooFit;
void ee_half_HT_apply_fake_rate()
{
    TFile *fakeRate = new TFile("/home/kuanyu/Documents/CMS/ZtoLL_Plot/ana/ee/cut_optimize/DY/ee_DY_emjet_half.root");
    TFile *DYincli = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");
    TFile *DYHT70 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht70.root");
    TFile *DYHT100 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/DY/ee_ht100.root");
    TFile *DYHT200 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/DY/ee_ht200.root");
    TFile *DYHT400 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/DY/ee_ht400.root");
    TFile *DYHT600 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/DY/ee_ht600.root");
    TFile *DYHT800 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/DY/ee_ht800.root");
    TFile *DYHT1200 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

    TFile *DYincli_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_DYincli_2.root");
    TFile *DYHT70_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht70_2.root");
    TFile *DYHT100_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht100_2.root");
    TFile *DYHT200_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht200_2.root");
    TFile *DYHT400_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht400_2.root");
    TFile *DYHT600_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht600_2.root");
    TFile *DYHT800_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht800_2.root");
    TFile *DYHT1200_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht1200_2.root");
    TFile *DYHT2500_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/ee_ht2500_2.root");

    TH1F *HT_hev_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_hev_emergjetnTrack_fakeRate"));
    TH1F *HT_light_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_light_emergjetnTrack_fakeRate"));

    TH1F *HT_hev_barr_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_hev_barr_emergjetnTrack_fakeRate"));
    TH1F *HT_light_barr_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_light_barr_emergjetnTrack_fakeRate"));

    TH1F *HT_hev_end_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_hev_end_emergjetnTrack_fakeRate"));
    TH1F *HT_light_end_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_light_end_emergjetnTrack_fakeRate"));
    // TH1F *h_ht0_hev_emergjetnTrack_cutalpha = ((TH1F *)fakeRate->Get("h_ht0_hev_emergjetnTrack_cutalpha"));
    // TH1F *h_ht0_light_emergjetnTrack_cutalpha = ((TH1F *)fakeRate->Get("h_ht0_light_emergjetnTrack_cutalpha"));

    // TH1F *HT_hev_fakerate_ntr = (TH1F *)h_ht0_hev_emergjetnTrack_cutalpha->Clone("HT_hev_fakerate_ntr");
    // HT_hev_fakerate_ntr->Divide(h_ht0_hev_emergjetnTrack_cutalpha, h_ht0_hev_emergjetnTrack, 1, 1, "b");

    // TH1F *HT_light_fakerate_ntr = (TH1F *)h_ht0_light_emergjetnTrack_cutalpha->Clone("HT_light_fakerate_ntr");
    // HT_light_fakerate_ntr->Divide(h_ht0_light_emergjetnTrack_cutalpha, h_ht0_light_emergjetnTrack, 1, 1, "b");

    // TH1D *Top_hev_fakerate_ntr = ((TH1D *)fakeRate->Get("Top_hev_emergjetnTrack_fakeRate"));
    // TH1D *Top_light_fakerate_ntr = ((TH1D *)fakeRate->Get("Top_light_emergjetnTrack_fakeRate"));
    // TH1D *HT_hev_fakerate_ntr = ((TH1D *)fakeRate->Get("h_hev_emergjetnTrack_fakeRate"));
    // TH1D *HT_light_fakerate_ntr = ((TH1D *)fakeRate->Get("h_light_emergjetnTrack_fakeRate"));

    // HT_light_fakerate_ntr->Draw();

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

    TH1F *h_ht0_hev_exp_emergjetpt = new TH1F("h_ht0_hev_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_hev_exp_emergjetpt->Sumw2();
    TH1F *h_ht70_hev_exp_emergjetpt = new TH1F("h_ht70_hev_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_hev_exp_emergjetpt->Sumw2();
    TH1F *h_ht100_hev_exp_emergjetpt = new TH1F("h_ht100_hev_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_hev_exp_emergjetpt->Sumw2();
    TH1F *h_ht200_hev_exp_emergjetpt = new TH1F("h_ht200_hev_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_hev_exp_emergjetpt->Sumw2();
    TH1F *h_ht400_hev_exp_emergjetpt = new TH1F("h_ht400_hev_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_hev_exp_emergjetpt->Sumw2();
    TH1F *h_ht600_hev_exp_emergjetpt = new TH1F("h_ht600_hev_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_hev_exp_emergjetpt->Sumw2();
    TH1F *h_ht800_hev_exp_emergjetpt = new TH1F("h_ht800_hev_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_hev_exp_emergjetpt->Sumw2();
    TH1F *h_ht1200_hev_exp_emergjetpt = new TH1F("h_ht1200_hev_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_hev_exp_emergjetpt->Sumw2();
    TH1F *h_ht2500_hev_exp_emergjetpt = new TH1F("h_ht2500_hev_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_hev_exp_emergjetpt->Sumw2();

    TH1F *h_ht0_light_exp_emergjetpt = new TH1F("h_ht0_light_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_light_exp_emergjetpt->Sumw2();
    TH1F *h_ht70_light_exp_emergjetpt = new TH1F("h_ht70_light_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_light_exp_emergjetpt->Sumw2();
    TH1F *h_ht100_light_exp_emergjetpt = new TH1F("h_ht100_light_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_light_exp_emergjetpt->Sumw2();
    TH1F *h_ht200_light_exp_emergjetpt = new TH1F("h_ht200_light_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_light_exp_emergjetpt->Sumw2();
    TH1F *h_ht400_light_exp_emergjetpt = new TH1F("h_ht400_light_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_light_exp_emergjetpt->Sumw2();
    TH1F *h_ht600_light_exp_emergjetpt = new TH1F("h_ht600_light_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_light_exp_emergjetpt->Sumw2();
    TH1F *h_ht800_light_exp_emergjetpt = new TH1F("h_ht800_light_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_light_exp_emergjetpt->Sumw2();
    TH1F *h_ht1200_light_exp_emergjetpt = new TH1F("h_ht1200_light_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_light_exp_emergjetpt->Sumw2();
    TH1F *h_ht2500_light_exp_emergjetpt = new TH1F("h_ht2500_light_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_light_exp_emergjetpt->Sumw2();

    TH1F *h_ht0_hev_exp_emergjetEta = new TH1F("h_ht0_hev_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_hev_exp_emergjetEta->Sumw2();
    TH1F *h_ht70_hev_exp_emergjetEta = new TH1F("h_ht70_hev_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_hev_exp_emergjetEta->Sumw2();
    TH1F *h_ht100_hev_exp_emergjetEta = new TH1F("h_ht100_hev_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_hev_exp_emergjetEta->Sumw2();
    TH1F *h_ht200_hev_exp_emergjetEta = new TH1F("h_ht200_hev_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_hev_exp_emergjetEta->Sumw2();
    TH1F *h_ht400_hev_exp_emergjetEta = new TH1F("h_ht400_hev_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_hev_exp_emergjetEta->Sumw2();
    TH1F *h_ht600_hev_exp_emergjetEta = new TH1F("h_ht600_hev_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_hev_exp_emergjetEta->Sumw2();
    TH1F *h_ht800_hev_exp_emergjetEta = new TH1F("h_ht800_hev_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_hev_exp_emergjetEta->Sumw2();
    TH1F *h_ht1200_hev_exp_emergjetEta = new TH1F("h_ht1200_hev_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_hev_exp_emergjetEta->Sumw2();
    TH1F *h_ht2500_hev_exp_emergjetEta = new TH1F("h_ht2500_hev_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_hev_exp_emergjetEta->Sumw2();

    TH1F *h_ht0_light_exp_emergjetEta = new TH1F("h_ht0_light_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_light_exp_emergjetEta->Sumw2();
    TH1F *h_ht70_light_exp_emergjetEta = new TH1F("h_ht70_light_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_light_exp_emergjetEta->Sumw2();
    TH1F *h_ht100_light_exp_emergjetEta = new TH1F("h_ht100_light_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_light_exp_emergjetEta->Sumw2();
    TH1F *h_ht200_light_exp_emergjetEta = new TH1F("h_ht200_light_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_light_exp_emergjetEta->Sumw2();
    TH1F *h_ht400_light_exp_emergjetEta = new TH1F("h_ht400_light_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_light_exp_emergjetEta->Sumw2();
    TH1F *h_ht600_light_exp_emergjetEta = new TH1F("h_ht600_light_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_light_exp_emergjetEta->Sumw2();
    TH1F *h_ht800_light_exp_emergjetEta = new TH1F("h_ht800_light_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_light_exp_emergjetEta->Sumw2();
    TH1F *h_ht1200_light_exp_emergjetEta = new TH1F("h_ht1200_light_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_light_exp_emergjetEta->Sumw2();
    TH1F *h_ht2500_light_exp_emergjetEta = new TH1F("h_ht2500_light_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_light_exp_emergjetEta->Sumw2();

    TH1F *h_ht0_hev_exp_emergjetnTrack = new TH1F("h_ht0_hev_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_hev_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht70_hev_exp_emergjetnTrack = new TH1F("h_ht70_hev_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_hev_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht100_hev_exp_emergjetnTrack = new TH1F("h_ht100_hev_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_hev_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht200_hev_exp_emergjetnTrack = new TH1F("h_ht200_hev_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_hev_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht400_hev_exp_emergjetnTrack = new TH1F("h_ht400_hev_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_hev_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht600_hev_exp_emergjetnTrack = new TH1F("h_ht600_hev_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_hev_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht800_hev_exp_emergjetnTrack = new TH1F("h_ht800_hev_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_hev_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_hev_exp_emergjetnTrack = new TH1F("h_ht1200_hev_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_hev_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_hev_exp_emergjetnTrack = new TH1F("h_ht2500_hev_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_hev_exp_emergjetnTrack->Sumw2();

    TH1F *h_ht0_light_exp_emergjetnTrack = new TH1F("h_ht0_light_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_light_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht70_light_exp_emergjetnTrack = new TH1F("h_ht70_light_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_light_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht100_light_exp_emergjetnTrack = new TH1F("h_ht100_light_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_light_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht200_light_exp_emergjetnTrack = new TH1F("h_ht200_light_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_light_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht400_light_exp_emergjetnTrack = new TH1F("h_ht400_light_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_light_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht600_light_exp_emergjetnTrack = new TH1F("h_ht600_light_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_light_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht800_light_exp_emergjetnTrack = new TH1F("h_ht800_light_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_light_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_light_exp_emergjetnTrack = new TH1F("h_ht1200_light_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_light_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_light_exp_emergjetnTrack = new TH1F("h_ht2500_light_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_light_exp_emergjetnTrack->Sumw2();

    TH1F *h_ht0_hev_pred_emergjetpt = new TH1F("h_ht0_hev_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_hev_pred_emergjetpt->Sumw2();
    TH1F *h_ht70_hev_pred_emergjetpt = new TH1F("h_ht70_hev_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_hev_pred_emergjetpt->Sumw2();
    TH1F *h_ht100_hev_pred_emergjetpt = new TH1F("h_ht100_hev_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_hev_pred_emergjetpt->Sumw2();
    TH1F *h_ht200_hev_pred_emergjetpt = new TH1F("h_ht200_hev_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_hev_pred_emergjetpt->Sumw2();
    TH1F *h_ht400_hev_pred_emergjetpt = new TH1F("h_ht400_hev_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_hev_pred_emergjetpt->Sumw2();
    TH1F *h_ht600_hev_pred_emergjetpt = new TH1F("h_ht600_hev_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_hev_pred_emergjetpt->Sumw2();
    TH1F *h_ht800_hev_pred_emergjetpt = new TH1F("h_ht800_hev_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_hev_pred_emergjetpt->Sumw2();
    TH1F *h_ht1200_hev_pred_emergjetpt = new TH1F("h_ht1200_hev_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_hev_pred_emergjetpt->Sumw2();
    TH1F *h_ht2500_hev_pred_emergjetpt = new TH1F("h_ht2500_hev_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_hev_pred_emergjetpt->Sumw2();

    TH1F *h_ht0_light_pred_emergjetpt = new TH1F("h_ht0_light_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_light_pred_emergjetpt->Sumw2();
    TH1F *h_ht70_light_pred_emergjetpt = new TH1F("h_ht70_light_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_light_pred_emergjetpt->Sumw2();
    TH1F *h_ht100_light_pred_emergjetpt = new TH1F("h_ht100_light_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_light_pred_emergjetpt->Sumw2();
    TH1F *h_ht200_light_pred_emergjetpt = new TH1F("h_ht200_light_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_light_pred_emergjetpt->Sumw2();
    TH1F *h_ht400_light_pred_emergjetpt = new TH1F("h_ht400_light_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_light_pred_emergjetpt->Sumw2();
    TH1F *h_ht600_light_pred_emergjetpt = new TH1F("h_ht600_light_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_light_pred_emergjetpt->Sumw2();
    TH1F *h_ht800_light_pred_emergjetpt = new TH1F("h_ht800_light_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_light_pred_emergjetpt->Sumw2();
    TH1F *h_ht1200_light_pred_emergjetpt = new TH1F("h_ht1200_light_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_light_pred_emergjetpt->Sumw2();
    TH1F *h_ht2500_light_pred_emergjetpt = new TH1F("h_ht2500_light_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_light_pred_emergjetpt->Sumw2();

    TH1F *h_ht0_hev_pred_emergjetEta = new TH1F("h_ht0_hev_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_hev_pred_emergjetEta->Sumw2();
    TH1F *h_ht70_hev_pred_emergjetEta = new TH1F("h_ht70_hev_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_hev_pred_emergjetEta->Sumw2();
    TH1F *h_ht100_hev_pred_emergjetEta = new TH1F("h_ht100_hev_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_hev_pred_emergjetEta->Sumw2();
    TH1F *h_ht200_hev_pred_emergjetEta = new TH1F("h_ht200_hev_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_hev_pred_emergjetEta->Sumw2();
    TH1F *h_ht400_hev_pred_emergjetEta = new TH1F("h_ht400_hev_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_hev_pred_emergjetEta->Sumw2();
    TH1F *h_ht600_hev_pred_emergjetEta = new TH1F("h_ht600_hev_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_hev_pred_emergjetEta->Sumw2();
    TH1F *h_ht800_hev_pred_emergjetEta = new TH1F("h_ht800_hev_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_hev_pred_emergjetEta->Sumw2();
    TH1F *h_ht1200_hev_pred_emergjetEta = new TH1F("h_ht1200_hev_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_hev_pred_emergjetEta->Sumw2();
    TH1F *h_ht2500_hev_pred_emergjetEta = new TH1F("h_ht2500_hev_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_hev_pred_emergjetEta->Sumw2();

    TH1F *h_ht0_light_pred_emergjetEta = new TH1F("h_ht0_light_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_light_pred_emergjetEta->Sumw2();
    TH1F *h_ht70_light_pred_emergjetEta = new TH1F("h_ht70_light_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_light_pred_emergjetEta->Sumw2();
    TH1F *h_ht100_light_pred_emergjetEta = new TH1F("h_ht100_light_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_light_pred_emergjetEta->Sumw2();
    TH1F *h_ht200_light_pred_emergjetEta = new TH1F("h_ht200_light_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_light_pred_emergjetEta->Sumw2();
    TH1F *h_ht400_light_pred_emergjetEta = new TH1F("h_ht400_light_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_light_pred_emergjetEta->Sumw2();
    TH1F *h_ht600_light_pred_emergjetEta = new TH1F("h_ht600_light_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_light_pred_emergjetEta->Sumw2();
    TH1F *h_ht800_light_pred_emergjetEta = new TH1F("h_ht800_light_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_light_pred_emergjetEta->Sumw2();
    TH1F *h_ht1200_light_pred_emergjetEta = new TH1F("h_ht1200_light_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_light_pred_emergjetEta->Sumw2();
    TH1F *h_ht2500_light_pred_emergjetEta = new TH1F("h_ht2500_light_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_light_pred_emergjetEta->Sumw2();

    TH1F *h_ht0_hev_pred_emergjetnTrack = new TH1F("h_ht0_hev_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_hev_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht70_hev_pred_emergjetnTrack = new TH1F("h_ht70_hev_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_hev_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht100_hev_pred_emergjetnTrack = new TH1F("h_ht100_hev_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_hev_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht200_hev_pred_emergjetnTrack = new TH1F("h_ht200_hev_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_hev_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht400_hev_pred_emergjetnTrack = new TH1F("h_ht400_hev_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_hev_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht600_hev_pred_emergjetnTrack = new TH1F("h_ht600_hev_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_hev_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht800_hev_pred_emergjetnTrack = new TH1F("h_ht800_hev_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_hev_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_hev_pred_emergjetnTrack = new TH1F("h_ht1200_hev_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_hev_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_hev_pred_emergjetnTrack = new TH1F("h_ht2500_hev_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_hev_pred_emergjetnTrack->Sumw2();

    TH1F *h_ht0_light_pred_emergjetnTrack = new TH1F("h_ht0_light_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_light_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht70_light_pred_emergjetnTrack = new TH1F("h_ht70_light_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_light_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht100_light_pred_emergjetnTrack = new TH1F("h_ht100_light_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_light_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht200_light_pred_emergjetnTrack = new TH1F("h_ht200_light_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_light_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht400_light_pred_emergjetnTrack = new TH1F("h_ht400_light_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_light_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht600_light_pred_emergjetnTrack = new TH1F("h_ht600_light_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_light_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht800_light_pred_emergjetnTrack = new TH1F("h_ht800_light_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_light_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_light_pred_emergjetnTrack = new TH1F("h_ht1200_light_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_light_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_light_pred_emergjetnTrack = new TH1F("h_ht2500_light_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_light_pred_emergjetnTrack->Sumw2();

    //---
    TH1F *h_ht0_hev_barr_exp_emergjetpt = new TH1F("h_ht0_hev_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_hev_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht70_hev_barr_exp_emergjetpt = new TH1F("h_ht70_hev_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_hev_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht100_hev_barr_exp_emergjetpt = new TH1F("h_ht100_hev_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_hev_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht200_hev_barr_exp_emergjetpt = new TH1F("h_ht200_hev_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_hev_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht400_hev_barr_exp_emergjetpt = new TH1F("h_ht400_hev_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_hev_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht600_hev_barr_exp_emergjetpt = new TH1F("h_ht600_hev_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_hev_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht800_hev_barr_exp_emergjetpt = new TH1F("h_ht800_hev_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_hev_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht1200_hev_barr_exp_emergjetpt = new TH1F("h_ht1200_hev_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_hev_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht2500_hev_barr_exp_emergjetpt = new TH1F("h_ht2500_hev_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_hev_barr_exp_emergjetpt->Sumw2();

    TH1F *h_ht0_light_barr_exp_emergjetpt = new TH1F("h_ht0_light_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_light_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht70_light_barr_exp_emergjetpt = new TH1F("h_ht70_light_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_light_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht100_light_barr_exp_emergjetpt = new TH1F("h_ht100_light_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_light_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht200_light_barr_exp_emergjetpt = new TH1F("h_ht200_light_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_light_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht400_light_barr_exp_emergjetpt = new TH1F("h_ht400_light_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_light_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht600_light_barr_exp_emergjetpt = new TH1F("h_ht600_light_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_light_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht800_light_barr_exp_emergjetpt = new TH1F("h_ht800_light_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_light_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht1200_light_barr_exp_emergjetpt = new TH1F("h_ht1200_light_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_light_barr_exp_emergjetpt->Sumw2();
    TH1F *h_ht2500_light_barr_exp_emergjetpt = new TH1F("h_ht2500_light_barr_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_light_barr_exp_emergjetpt->Sumw2();

    TH1F *h_ht0_hev_barr_exp_emergjetEta = new TH1F("h_ht0_hev_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_hev_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht70_hev_barr_exp_emergjetEta = new TH1F("h_ht70_hev_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_hev_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht100_hev_barr_exp_emergjetEta = new TH1F("h_ht100_hev_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_hev_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht200_hev_barr_exp_emergjetEta = new TH1F("h_ht200_hev_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_hev_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht400_hev_barr_exp_emergjetEta = new TH1F("h_ht400_hev_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_hev_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht600_hev_barr_exp_emergjetEta = new TH1F("h_ht600_hev_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_hev_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht800_hev_barr_exp_emergjetEta = new TH1F("h_ht800_hev_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_hev_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht1200_hev_barr_exp_emergjetEta = new TH1F("h_ht1200_hev_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_hev_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht2500_hev_barr_exp_emergjetEta = new TH1F("h_ht2500_hev_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_hev_barr_exp_emergjetEta->Sumw2();

    TH1F *h_ht0_light_barr_exp_emergjetEta = new TH1F("h_ht0_light_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_light_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht70_light_barr_exp_emergjetEta = new TH1F("h_ht70_light_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_light_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht100_light_barr_exp_emergjetEta = new TH1F("h_ht100_light_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_light_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht200_light_barr_exp_emergjetEta = new TH1F("h_ht200_light_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_light_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht400_light_barr_exp_emergjetEta = new TH1F("h_ht400_light_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_light_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht600_light_barr_exp_emergjetEta = new TH1F("h_ht600_light_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_light_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht800_light_barr_exp_emergjetEta = new TH1F("h_ht800_light_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_light_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht1200_light_barr_exp_emergjetEta = new TH1F("h_ht1200_light_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_light_barr_exp_emergjetEta->Sumw2();
    TH1F *h_ht2500_light_barr_exp_emergjetEta = new TH1F("h_ht2500_light_barr_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_light_barr_exp_emergjetEta->Sumw2();

    TH1F *h_ht0_hev_barr_exp_emergjetnTrack = new TH1F("h_ht0_hev_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_hev_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht70_hev_barr_exp_emergjetnTrack = new TH1F("h_ht70_hev_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_hev_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht100_hev_barr_exp_emergjetnTrack = new TH1F("h_ht100_hev_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_hev_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht200_hev_barr_exp_emergjetnTrack = new TH1F("h_ht200_hev_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_hev_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht400_hev_barr_exp_emergjetnTrack = new TH1F("h_ht400_hev_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_hev_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht600_hev_barr_exp_emergjetnTrack = new TH1F("h_ht600_hev_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_hev_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht800_hev_barr_exp_emergjetnTrack = new TH1F("h_ht800_hev_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_hev_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_hev_barr_exp_emergjetnTrack = new TH1F("h_ht1200_hev_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_hev_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_hev_barr_exp_emergjetnTrack = new TH1F("h_ht2500_hev_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_hev_barr_exp_emergjetnTrack->Sumw2();

    TH1F *h_ht0_light_barr_exp_emergjetnTrack = new TH1F("h_ht0_light_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_light_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht70_light_barr_exp_emergjetnTrack = new TH1F("h_ht70_light_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_light_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht100_light_barr_exp_emergjetnTrack = new TH1F("h_ht100_light_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_light_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht200_light_barr_exp_emergjetnTrack = new TH1F("h_ht200_light_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_light_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht400_light_barr_exp_emergjetnTrack = new TH1F("h_ht400_light_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_light_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht600_light_barr_exp_emergjetnTrack = new TH1F("h_ht600_light_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_light_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht800_light_barr_exp_emergjetnTrack = new TH1F("h_ht800_light_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_light_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_light_barr_exp_emergjetnTrack = new TH1F("h_ht1200_light_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_light_barr_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_light_barr_exp_emergjetnTrack = new TH1F("h_ht2500_light_barr_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_light_barr_exp_emergjetnTrack->Sumw2();

    TH1F *h_ht0_hev_barr_pred_emergjetpt = new TH1F("h_ht0_hev_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_hev_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht70_hev_barr_pred_emergjetpt = new TH1F("h_ht70_hev_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_hev_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht100_hev_barr_pred_emergjetpt = new TH1F("h_ht100_hev_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_hev_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht200_hev_barr_pred_emergjetpt = new TH1F("h_ht200_hev_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_hev_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht400_hev_barr_pred_emergjetpt = new TH1F("h_ht400_hev_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_hev_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht600_hev_barr_pred_emergjetpt = new TH1F("h_ht600_hev_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_hev_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht800_hev_barr_pred_emergjetpt = new TH1F("h_ht800_hev_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_hev_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht1200_hev_barr_pred_emergjetpt = new TH1F("h_ht1200_hev_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_hev_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht2500_hev_barr_pred_emergjetpt = new TH1F("h_ht2500_hev_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_hev_barr_pred_emergjetpt->Sumw2();

    TH1F *h_ht0_light_barr_pred_emergjetpt = new TH1F("h_ht0_light_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_light_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht70_light_barr_pred_emergjetpt = new TH1F("h_ht70_light_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_light_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht100_light_barr_pred_emergjetpt = new TH1F("h_ht100_light_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_light_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht200_light_barr_pred_emergjetpt = new TH1F("h_ht200_light_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_light_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht400_light_barr_pred_emergjetpt = new TH1F("h_ht400_light_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_light_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht600_light_barr_pred_emergjetpt = new TH1F("h_ht600_light_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_light_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht800_light_barr_pred_emergjetpt = new TH1F("h_ht800_light_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_light_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht1200_light_barr_pred_emergjetpt = new TH1F("h_ht1200_light_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_light_barr_pred_emergjetpt->Sumw2();
    TH1F *h_ht2500_light_barr_pred_emergjetpt = new TH1F("h_ht2500_light_barr_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_light_barr_pred_emergjetpt->Sumw2();

    TH1F *h_ht0_hev_barr_pred_emergjetEta = new TH1F("h_ht0_hev_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_hev_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht70_hev_barr_pred_emergjetEta = new TH1F("h_ht70_hev_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_hev_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht100_hev_barr_pred_emergjetEta = new TH1F("h_ht100_hev_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_hev_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht200_hev_barr_pred_emergjetEta = new TH1F("h_ht200_hev_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_hev_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht400_hev_barr_pred_emergjetEta = new TH1F("h_ht400_hev_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_hev_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht600_hev_barr_pred_emergjetEta = new TH1F("h_ht600_hev_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_hev_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht800_hev_barr_pred_emergjetEta = new TH1F("h_ht800_hev_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_hev_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht1200_hev_barr_pred_emergjetEta = new TH1F("h_ht1200_hev_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_hev_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht2500_hev_barr_pred_emergjetEta = new TH1F("h_ht2500_hev_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_hev_barr_pred_emergjetEta->Sumw2();

    TH1F *h_ht0_light_barr_pred_emergjetEta = new TH1F("h_ht0_light_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_light_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht70_light_barr_pred_emergjetEta = new TH1F("h_ht70_light_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_light_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht100_light_barr_pred_emergjetEta = new TH1F("h_ht100_light_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_light_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht200_light_barr_pred_emergjetEta = new TH1F("h_ht200_light_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_light_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht400_light_barr_pred_emergjetEta = new TH1F("h_ht400_light_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_light_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht600_light_barr_pred_emergjetEta = new TH1F("h_ht600_light_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_light_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht800_light_barr_pred_emergjetEta = new TH1F("h_ht800_light_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_light_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht1200_light_barr_pred_emergjetEta = new TH1F("h_ht1200_light_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_light_barr_pred_emergjetEta->Sumw2();
    TH1F *h_ht2500_light_barr_pred_emergjetEta = new TH1F("h_ht2500_light_barr_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_light_barr_pred_emergjetEta->Sumw2();

    TH1F *h_ht0_hev_barr_pred_emergjetnTrack = new TH1F("h_ht0_hev_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_hev_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht70_hev_barr_pred_emergjetnTrack = new TH1F("h_ht70_hev_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_hev_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht100_hev_barr_pred_emergjetnTrack = new TH1F("h_ht100_hev_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_hev_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht200_hev_barr_pred_emergjetnTrack = new TH1F("h_ht200_hev_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_hev_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht400_hev_barr_pred_emergjetnTrack = new TH1F("h_ht400_hev_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_hev_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht600_hev_barr_pred_emergjetnTrack = new TH1F("h_ht600_hev_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_hev_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht800_hev_barr_pred_emergjetnTrack = new TH1F("h_ht800_hev_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_hev_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_hev_barr_pred_emergjetnTrack = new TH1F("h_ht1200_hev_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_hev_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_hev_barr_pred_emergjetnTrack = new TH1F("h_ht2500_hev_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_hev_barr_pred_emergjetnTrack->Sumw2();

    TH1F *h_ht0_light_barr_pred_emergjetnTrack = new TH1F("h_ht0_light_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_light_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht70_light_barr_pred_emergjetnTrack = new TH1F("h_ht70_light_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_light_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht100_light_barr_pred_emergjetnTrack = new TH1F("h_ht100_light_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_light_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht200_light_barr_pred_emergjetnTrack = new TH1F("h_ht200_light_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_light_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht400_light_barr_pred_emergjetnTrack = new TH1F("h_ht400_light_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_light_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht600_light_barr_pred_emergjetnTrack = new TH1F("h_ht600_light_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_light_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht800_light_barr_pred_emergjetnTrack = new TH1F("h_ht800_light_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_light_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_light_barr_pred_emergjetnTrack = new TH1F("h_ht1200_light_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_light_barr_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_light_barr_pred_emergjetnTrack = new TH1F("h_ht2500_light_barr_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_light_barr_pred_emergjetnTrack->Sumw2();
    //--
    TH1F *h_ht0_hev_end_exp_emergjetpt = new TH1F("h_ht0_hev_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_hev_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht70_hev_end_exp_emergjetpt = new TH1F("h_ht70_hev_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_hev_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht100_hev_end_exp_emergjetpt = new TH1F("h_ht100_hev_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_hev_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht200_hev_end_exp_emergjetpt = new TH1F("h_ht200_hev_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_hev_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht400_hev_end_exp_emergjetpt = new TH1F("h_ht400_hev_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_hev_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht600_hev_end_exp_emergjetpt = new TH1F("h_ht600_hev_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_hev_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht800_hev_end_exp_emergjetpt = new TH1F("h_ht800_hev_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_hev_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht1200_hev_end_exp_emergjetpt = new TH1F("h_ht1200_hev_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_hev_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht2500_hev_end_exp_emergjetpt = new TH1F("h_ht2500_hev_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_hev_end_exp_emergjetpt->Sumw2();

    TH1F *h_ht0_light_end_exp_emergjetpt = new TH1F("h_ht0_light_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_light_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht70_light_end_exp_emergjetpt = new TH1F("h_ht70_light_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_light_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht100_light_end_exp_emergjetpt = new TH1F("h_ht100_light_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_light_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht200_light_end_exp_emergjetpt = new TH1F("h_ht200_light_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_light_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht400_light_end_exp_emergjetpt = new TH1F("h_ht400_light_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_light_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht600_light_end_exp_emergjetpt = new TH1F("h_ht600_light_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_light_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht800_light_end_exp_emergjetpt = new TH1F("h_ht800_light_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_light_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht1200_light_end_exp_emergjetpt = new TH1F("h_ht1200_light_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_light_end_exp_emergjetpt->Sumw2();
    TH1F *h_ht2500_light_end_exp_emergjetpt = new TH1F("h_ht2500_light_end_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_light_end_exp_emergjetpt->Sumw2();

    TH1F *h_ht0_hev_end_exp_emergjetEta = new TH1F("h_ht0_hev_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_hev_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht70_hev_end_exp_emergjetEta = new TH1F("h_ht70_hev_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_hev_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht100_hev_end_exp_emergjetEta = new TH1F("h_ht100_hev_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_hev_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht200_hev_end_exp_emergjetEta = new TH1F("h_ht200_hev_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_hev_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht400_hev_end_exp_emergjetEta = new TH1F("h_ht400_hev_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_hev_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht600_hev_end_exp_emergjetEta = new TH1F("h_ht600_hev_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_hev_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht800_hev_end_exp_emergjetEta = new TH1F("h_ht800_hev_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_hev_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht1200_hev_end_exp_emergjetEta = new TH1F("h_ht1200_hev_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_hev_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht2500_hev_end_exp_emergjetEta = new TH1F("h_ht2500_hev_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_hev_end_exp_emergjetEta->Sumw2();

    TH1F *h_ht0_light_end_exp_emergjetEta = new TH1F("h_ht0_light_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_light_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht70_light_end_exp_emergjetEta = new TH1F("h_ht70_light_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_light_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht100_light_end_exp_emergjetEta = new TH1F("h_ht100_light_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_light_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht200_light_end_exp_emergjetEta = new TH1F("h_ht200_light_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_light_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht400_light_end_exp_emergjetEta = new TH1F("h_ht400_light_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_light_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht600_light_end_exp_emergjetEta = new TH1F("h_ht600_light_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_light_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht800_light_end_exp_emergjetEta = new TH1F("h_ht800_light_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_light_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht1200_light_end_exp_emergjetEta = new TH1F("h_ht1200_light_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_light_end_exp_emergjetEta->Sumw2();
    TH1F *h_ht2500_light_end_exp_emergjetEta = new TH1F("h_ht2500_light_end_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_light_end_exp_emergjetEta->Sumw2();

    TH1F *h_ht0_hev_end_exp_emergjetnTrack = new TH1F("h_ht0_hev_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_hev_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht70_hev_end_exp_emergjetnTrack = new TH1F("h_ht70_hev_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_hev_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht100_hev_end_exp_emergjetnTrack = new TH1F("h_ht100_hev_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_hev_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht200_hev_end_exp_emergjetnTrack = new TH1F("h_ht200_hev_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_hev_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht400_hev_end_exp_emergjetnTrack = new TH1F("h_ht400_hev_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_hev_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht600_hev_end_exp_emergjetnTrack = new TH1F("h_ht600_hev_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_hev_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht800_hev_end_exp_emergjetnTrack = new TH1F("h_ht800_hev_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_hev_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_hev_end_exp_emergjetnTrack = new TH1F("h_ht1200_hev_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_hev_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_hev_end_exp_emergjetnTrack = new TH1F("h_ht2500_hev_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_hev_end_exp_emergjetnTrack->Sumw2();

    TH1F *h_ht0_light_end_exp_emergjetnTrack = new TH1F("h_ht0_light_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_light_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht70_light_end_exp_emergjetnTrack = new TH1F("h_ht70_light_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_light_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht100_light_end_exp_emergjetnTrack = new TH1F("h_ht100_light_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_light_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht200_light_end_exp_emergjetnTrack = new TH1F("h_ht200_light_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_light_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht400_light_end_exp_emergjetnTrack = new TH1F("h_ht400_light_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_light_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht600_light_end_exp_emergjetnTrack = new TH1F("h_ht600_light_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_light_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht800_light_end_exp_emergjetnTrack = new TH1F("h_ht800_light_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_light_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_light_end_exp_emergjetnTrack = new TH1F("h_ht1200_light_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_light_end_exp_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_light_end_exp_emergjetnTrack = new TH1F("h_ht2500_light_end_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_light_end_exp_emergjetnTrack->Sumw2();

    TH1F *h_ht0_hev_end_pred_emergjetpt = new TH1F("h_ht0_hev_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_hev_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht70_hev_end_pred_emergjetpt = new TH1F("h_ht70_hev_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_hev_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht100_hev_end_pred_emergjetpt = new TH1F("h_ht100_hev_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_hev_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht200_hev_end_pred_emergjetpt = new TH1F("h_ht200_hev_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_hev_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht400_hev_end_pred_emergjetpt = new TH1F("h_ht400_hev_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_hev_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht600_hev_end_pred_emergjetpt = new TH1F("h_ht600_hev_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_hev_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht800_hev_end_pred_emergjetpt = new TH1F("h_ht800_hev_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_hev_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht1200_hev_end_pred_emergjetpt = new TH1F("h_ht1200_hev_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_hev_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht2500_hev_end_pred_emergjetpt = new TH1F("h_ht2500_hev_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_hev_end_pred_emergjetpt->Sumw2();

    TH1F *h_ht0_light_end_pred_emergjetpt = new TH1F("h_ht0_light_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_light_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht70_light_end_pred_emergjetpt = new TH1F("h_ht70_light_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_light_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht100_light_end_pred_emergjetpt = new TH1F("h_ht100_light_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_light_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht200_light_end_pred_emergjetpt = new TH1F("h_ht200_light_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_light_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht400_light_end_pred_emergjetpt = new TH1F("h_ht400_light_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_light_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht600_light_end_pred_emergjetpt = new TH1F("h_ht600_light_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_light_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht800_light_end_pred_emergjetpt = new TH1F("h_ht800_light_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_light_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht1200_light_end_pred_emergjetpt = new TH1F("h_ht1200_light_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_light_end_pred_emergjetpt->Sumw2();
    TH1F *h_ht2500_light_end_pred_emergjetpt = new TH1F("h_ht2500_light_end_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_light_end_pred_emergjetpt->Sumw2();

    TH1F *h_ht0_hev_end_pred_emergjetEta = new TH1F("h_ht0_hev_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_hev_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht70_hev_end_pred_emergjetEta = new TH1F("h_ht70_hev_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_hev_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht100_hev_end_pred_emergjetEta = new TH1F("h_ht100_hev_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_hev_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht200_hev_end_pred_emergjetEta = new TH1F("h_ht200_hev_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_hev_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht400_hev_end_pred_emergjetEta = new TH1F("h_ht400_hev_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_hev_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht600_hev_end_pred_emergjetEta = new TH1F("h_ht600_hev_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_hev_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht800_hev_end_pred_emergjetEta = new TH1F("h_ht800_hev_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_hev_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht1200_hev_end_pred_emergjetEta = new TH1F("h_ht1200_hev_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_hev_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht2500_hev_end_pred_emergjetEta = new TH1F("h_ht2500_hev_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_hev_end_pred_emergjetEta->Sumw2();

    TH1F *h_ht0_light_end_pred_emergjetEta = new TH1F("h_ht0_light_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_light_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht70_light_end_pred_emergjetEta = new TH1F("h_ht70_light_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_light_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht100_light_end_pred_emergjetEta = new TH1F("h_ht100_light_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_light_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht200_light_end_pred_emergjetEta = new TH1F("h_ht200_light_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_light_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht400_light_end_pred_emergjetEta = new TH1F("h_ht400_light_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_light_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht600_light_end_pred_emergjetEta = new TH1F("h_ht600_light_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_light_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht800_light_end_pred_emergjetEta = new TH1F("h_ht800_light_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_light_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht1200_light_end_pred_emergjetEta = new TH1F("h_ht1200_light_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_light_end_pred_emergjetEta->Sumw2();
    TH1F *h_ht2500_light_end_pred_emergjetEta = new TH1F("h_ht2500_light_end_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_light_end_pred_emergjetEta->Sumw2();

    TH1F *h_ht0_hev_end_pred_emergjetnTrack = new TH1F("h_ht0_hev_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_hev_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht70_hev_end_pred_emergjetnTrack = new TH1F("h_ht70_hev_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_hev_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht100_hev_end_pred_emergjetnTrack = new TH1F("h_ht100_hev_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_hev_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht200_hev_end_pred_emergjetnTrack = new TH1F("h_ht200_hev_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_hev_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht400_hev_end_pred_emergjetnTrack = new TH1F("h_ht400_hev_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_hev_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht600_hev_end_pred_emergjetnTrack = new TH1F("h_ht600_hev_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_hev_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht800_hev_end_pred_emergjetnTrack = new TH1F("h_ht800_hev_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_hev_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_hev_end_pred_emergjetnTrack = new TH1F("h_ht1200_hev_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_hev_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_hev_end_pred_emergjetnTrack = new TH1F("h_ht2500_hev_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_hev_end_pred_emergjetnTrack->Sumw2();

    TH1F *h_ht0_light_end_pred_emergjetnTrack = new TH1F("h_ht0_light_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_light_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht70_light_end_pred_emergjetnTrack = new TH1F("h_ht70_light_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_light_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht100_light_end_pred_emergjetnTrack = new TH1F("h_ht100_light_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_light_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht200_light_end_pred_emergjetnTrack = new TH1F("h_ht200_light_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_light_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht400_light_end_pred_emergjetnTrack = new TH1F("h_ht400_light_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_light_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht600_light_end_pred_emergjetnTrack = new TH1F("h_ht600_light_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_light_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht800_light_end_pred_emergjetnTrack = new TH1F("h_ht800_light_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_light_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_light_end_pred_emergjetnTrack = new TH1F("h_ht1200_light_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_light_end_pred_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_light_end_pred_emergjetnTrack = new TH1F("h_ht2500_light_end_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_light_end_pred_emergjetnTrack->Sumw2();

    float_t HT;

    Double_t f_ht0_alphamin, f_ht70_alphamin, f_ht100_alphamin, f_ht200_alphamin, f_ht400_alphamin,
        f_ht600_alphamin, f_ht800_alphamin, f_ht1200_alphamin, f_ht2500_alphamin;
    float_t f_ht0_Met, f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;

    Int_t I_ht0_nThinJets, I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets, I_ht600_nThinJets,
        I_ht800_nThinJets, I_ht1200_nThinJets, I_ht2500_nThinJets;

    Int_t I_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    Int_t I_ht0_disJet_multiplicity, I_ht70_disJet_multiplicity, I_ht100_disJet_multiplicity, I_ht200_disJet_multiplicity, I_ht400_disJet_multiplicity,
        I_ht600_disJet_multiplicity, I_ht800_disJet_multiplicity, I_ht1200_disJet_multiplicity, I_ht2500_disJet_multiplicity;

    Int_t I_ht0_minJetflavor, I_ht70_minJetflavor, I_ht100_minJetflavor, I_ht200_minJetflavor, I_ht400_minJetflavor,
        I_ht600_minJetflavor, I_ht800_minJetflavor, I_ht1200_minJetflavor, I_ht2500_minJetflavor;

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
    DYincli_2->GetObject("h2", T_event);
    T_event->SetBranchAddress("I_weight", &I_weight);
    T_event->SetBranchAddress("f_Met", &f_ht0_Met);
    T_event->SetBranchAddress("f_HT", &HT);
    T_event->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
    T_event->SetBranchAddress("v_fakeJetPt", &v_ht0_JetPT);
    T_event->SetBranchAddress("v_fakeJetEta", &v_ht0_JetEta);
    T_event->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    T_event->SetBranchAddress("v_N_Tracks", &v_ht0_JetnTracks);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        for (int i = 0; i < v_ht0_Jethadronflavor->size(); i++)
        {
            if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
            {
                if (HT < 70)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht0_hev_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight);
                        h_ht0_hev_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight);
                        h_ht0_hev_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht0_hev_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight);
                            h_ht0_hev_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight);
                            h_ht0_hev_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight);
                        }
                        else
                        {
                            h_ht0_hev_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight);
                            h_ht0_hev_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight);
                            h_ht0_hev_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight);
                        }
                    }

                    float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht0_hev_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight * ff);
                    h_ht0_hev_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight * ff);
                    h_ht0_hev_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht0_hev_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight * ff_barr);
                        h_ht0_hev_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight * ff_barr);
                        h_ht0_hev_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_hev_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht0_hev_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight * ff_end);
                        h_ht0_hev_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight * ff_end);
                        h_ht0_hev_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight * ff_end);
                    }
                }
                else if (HT >= 70 && HT < 100)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht70_hev_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight);
                        h_ht70_hev_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight);
                        h_ht70_hev_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht70_hev_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight);
                            h_ht70_hev_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight);
                            h_ht70_hev_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight);
                        }
                        else
                        {
                            h_ht70_hev_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight);
                            h_ht70_hev_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight);
                            h_ht70_hev_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight);
                        }
                    }

                    float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht70_hev_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight * ff);
                    h_ht70_hev_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight * ff);
                    h_ht70_hev_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht70_hev_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight * ff_barr);
                        h_ht70_hev_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight * ff_barr);
                        h_ht70_hev_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_hev_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht70_hev_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight * ff_end);
                        h_ht70_hev_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight * ff_end);
                        h_ht70_hev_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight * ff_end);
                    }
                }
                else if (HT >= 100 && HT < 200)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht100_hev_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight);
                        h_ht100_hev_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight);
                        h_ht100_hev_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht100_hev_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight);
                            h_ht100_hev_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight);
                            h_ht100_hev_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight);
                        }
                        else
                        {
                            h_ht100_hev_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight);
                            h_ht100_hev_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight);
                            h_ht100_hev_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight);
                        }
                    }

                    float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht100_hev_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight * ff);
                    h_ht100_hev_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight * ff);
                    h_ht100_hev_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ffbarr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht100_hev_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight * ffbarr);
                        h_ht100_hev_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight * ffbarr);
                        h_ht100_hev_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight * ffbarr);
                    }
                    else
                    {
                        float ff_end = HT_hev_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht100_hev_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight * ff_end);
                        h_ht100_hev_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight * ff_end);
                        h_ht100_hev_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight * ff_end);
                    }
                }
                else if (HT >= 200 && HT < 400)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht200_hev_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight);
                        h_ht200_hev_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight);
                        h_ht200_hev_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht200_hev_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight);
                            h_ht200_hev_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight);
                            h_ht200_hev_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight);
                        }
                        else
                        {
                            h_ht200_hev_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight);
                            h_ht200_hev_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight);
                            h_ht200_hev_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight);
                        }
                    }

                    float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht200_hev_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight * ff);
                    h_ht200_hev_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight * ff);
                    h_ht200_hev_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht200_hev_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight * ff_barr);
                        h_ht200_hev_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight * ff_barr);
                        h_ht200_hev_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_hev_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht200_hev_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight * ff_end);
                        h_ht200_hev_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight * ff_end);
                        h_ht200_hev_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight * ff_end);
                    }
                }
                else if (HT >= 400 && HT < 600)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht400_hev_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight);
                        h_ht400_hev_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight);
                        h_ht400_hev_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht400_hev_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight);
                            h_ht400_hev_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight);
                            h_ht400_hev_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight);
                        }
                        else
                        {
                            h_ht400_hev_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight);
                            h_ht400_hev_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight);
                            h_ht400_hev_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight);
                        }
                    }

                    float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht400_hev_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight * ff);
                    h_ht400_hev_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight * ff);
                    h_ht400_hev_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht400_hev_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight * ff_barr);
                        h_ht400_hev_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight * ff_barr);
                        h_ht400_hev_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_hev_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht400_hev_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight * ff_end);
                        h_ht400_hev_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight * ff_end);
                        h_ht400_hev_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight * ff_end);
                    }
                }
                else if (HT >= 600 && HT < 800)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht600_hev_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight);
                        h_ht600_hev_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight);
                        h_ht600_hev_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht600_hev_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight);
                            h_ht600_hev_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight);
                            h_ht600_hev_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight);
                        }
                        else
                        {
                            h_ht600_hev_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight);
                            h_ht600_hev_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight);
                            h_ht600_hev_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight);
                        }
                    }
                    float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht600_hev_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight * ff);
                    h_ht600_hev_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight * ff);
                    h_ht600_hev_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht600_hev_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight * ff_barr);
                        h_ht600_hev_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight * ff_barr);
                        h_ht600_hev_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht600_hev_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight * ff_end);
                        h_ht600_hev_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight * ff_end);
                        h_ht600_hev_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight * ff_end);
                    }
                }
                else if (HT >= 800 && HT < 1200)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht800_hev_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight);
                        h_ht800_hev_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight);
                        h_ht800_hev_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht800_hev_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight);
                            h_ht800_hev_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight);
                            h_ht800_hev_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight);
                        }
                        else
                        {
                            h_ht800_hev_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight);
                            h_ht800_hev_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight);
                            h_ht800_hev_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight);
                        }
                    }

                    float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht800_hev_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight * ff);
                    h_ht800_hev_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight * ff);
                    h_ht800_hev_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht800_hev_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight * ff_barr);
                        h_ht800_hev_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight * ff_barr);
                        h_ht800_hev_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_hev_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht800_hev_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight * ff_end);
                        h_ht800_hev_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight * ff_end);
                        h_ht800_hev_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight * ff_end);
                    }
                }
                else if (HT >= 1200 && HT < 2500)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht1200_hev_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight);
                        h_ht1200_hev_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight);
                        h_ht1200_hev_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht1200_hev_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight);
                            h_ht1200_hev_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight);
                            h_ht1200_hev_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight);
                        }
                        else
                        {
                            h_ht1200_hev_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight);
                            h_ht1200_hev_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight);
                            h_ht1200_hev_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight);
                        }
                    }

                    float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht1200_hev_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight * ff);
                    h_ht1200_hev_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight * ff);
                    h_ht1200_hev_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht1200_hev_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight * ff_barr);
                        h_ht1200_hev_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight * ff_barr);
                        h_ht1200_hev_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_hev_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht1200_hev_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight * ff_end);
                        h_ht1200_hev_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight * ff_end);
                        h_ht1200_hev_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight * ff_end);
                    }
                }
                else if (HT >= 2500)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht2500_hev_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight);
                        h_ht2500_hev_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight);
                        h_ht2500_hev_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht2500_hev_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight);
                            h_ht2500_hev_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight);
                            h_ht2500_hev_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight);
                        }
                        else
                        {
                            h_ht2500_hev_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight);
                            h_ht2500_hev_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight);
                            h_ht2500_hev_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight);
                        }
                    }

                    float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht2500_hev_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight * ff);
                    h_ht2500_hev_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight * ff);
                    h_ht2500_hev_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht2500_hev_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight * ff_barr);
                        h_ht2500_hev_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight * ff_barr);
                        h_ht2500_hev_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_hev_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht2500_hev_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight * ff_end);
                        h_ht2500_hev_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight * ff_end);
                        h_ht2500_hev_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight * ff_end);
                    }
                }
            }
            else
            {
                if (HT < 70)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht0_light_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight);
                        h_ht0_light_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight);
                        h_ht0_light_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht0_light_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight);
                            h_ht0_light_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight);
                            h_ht0_light_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight);
                        }
                        else
                        {
                            h_ht0_light_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight);
                            h_ht0_light_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight);
                            h_ht0_light_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight);
                        }
                    }

                    float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht0_light_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight * ff);
                    h_ht0_light_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight * ff);
                    h_ht0_light_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht0_light_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight * ff_barr);
                        h_ht0_light_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight * ff_barr);
                        h_ht0_light_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_light_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht0_light_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT0Weight * ff_end);
                        h_ht0_light_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT0Weight * ff_end);
                        h_ht0_light_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT0Weight * ff_end);
                    }
                }
                else if (HT >= 70 && HT < 100)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht70_light_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight);
                        h_ht70_light_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight);
                        h_ht70_light_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht70_light_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight);
                            h_ht70_light_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight);
                            h_ht70_light_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight);
                        }
                        else
                        {
                            h_ht70_light_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight);
                            h_ht70_light_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight);
                            h_ht70_light_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight);
                        }
                    }
                    float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht70_light_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight * ff);
                    h_ht70_light_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight * ff);
                    h_ht70_light_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht70_light_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight * ff_barr);
                        h_ht70_light_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight * ff_barr);
                        h_ht70_light_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_light_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht70_light_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT70Weight * ff_end);
                        h_ht70_light_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT70Weight * ff_end);
                        h_ht70_light_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT70Weight * ff_end);
                    }
                }
                else if (HT >= 100 && HT < 200)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht100_light_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight);
                        h_ht100_light_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight);
                        h_ht100_light_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht100_light_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight);
                            h_ht100_light_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight);
                            h_ht100_light_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight);
                        }
                        else
                        {
                            h_ht100_light_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight);
                            h_ht100_light_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight);
                            h_ht100_light_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight);
                        }
                    }

                    float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht100_light_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight * ff);
                    h_ht100_light_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight * ff);
                    h_ht100_light_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ffbarr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht100_light_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight * ffbarr);
                        h_ht100_light_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight * ffbarr);
                        h_ht100_light_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight * ffbarr);
                    }
                    else
                    {
                        float ff_end = HT_light_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht100_light_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT100Weight * ff_end);
                        h_ht100_light_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT100Weight * ff_end);
                        h_ht100_light_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT100Weight * ff_end);
                    }
                }
                else if (HT >= 200 && HT < 400)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht200_light_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight);
                        h_ht200_light_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight);
                        h_ht200_light_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht200_light_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight);
                            h_ht200_light_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight);
                            h_ht200_light_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight);
                        }
                        else
                        {
                            h_ht200_light_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight);
                            h_ht200_light_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight);
                            h_ht200_light_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight);
                        }
                    }

                    float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht200_light_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight * ff);
                    h_ht200_light_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight * ff);
                    h_ht200_light_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht200_light_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight * ff_barr);
                        h_ht200_light_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight * ff_barr);
                        h_ht200_light_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_light_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht200_light_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT200Weight * ff_end);
                        h_ht200_light_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT200Weight * ff_end);
                        h_ht200_light_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT200Weight * ff_end);
                    }
                }
                else if (HT >= 400 && HT < 600)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht400_light_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight);
                        h_ht400_light_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight);
                        h_ht400_light_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht400_light_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight);
                            h_ht400_light_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight);
                            h_ht400_light_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight);
                        }
                        else
                        {
                            h_ht400_light_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight);
                            h_ht400_light_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight);
                            h_ht400_light_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight);
                        }
                    }

                    float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht400_light_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight * ff);
                    h_ht400_light_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight * ff);
                    h_ht400_light_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht400_light_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight * ff_barr);
                        h_ht400_light_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight * ff_barr);
                        h_ht400_light_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_light_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht400_light_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT400Weight * ff_end);
                        h_ht400_light_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT400Weight * ff_end);
                        h_ht400_light_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT400Weight * ff_end);
                    }
                }
                else if (HT >= 600 && HT < 800)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht600_light_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight);
                        h_ht600_light_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight);
                        h_ht600_light_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht600_light_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight);
                            h_ht600_light_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight);
                            h_ht600_light_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight);
                        }
                        else
                        {
                            h_ht600_light_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight);
                            h_ht600_light_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight);
                            h_ht600_light_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight);
                        }
                    }

                    float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht600_light_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight * ff);
                    h_ht600_light_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight * ff);
                    h_ht600_light_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht600_light_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight * ff_barr);
                        h_ht600_light_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight * ff_barr);
                        h_ht600_light_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht600_light_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT600Weight * ff_end);
                        h_ht600_light_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT600Weight * ff_end);
                        h_ht600_light_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT600Weight * ff_end);
                    }
                }
                else if (HT >= 800 && HT < 1200)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht800_light_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight);
                        h_ht800_light_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight);
                        h_ht800_light_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht800_light_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight);
                            h_ht800_light_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight);
                            h_ht800_light_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight);
                        }
                        else
                        {
                            h_ht800_light_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight);
                            h_ht800_light_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight);
                            h_ht800_light_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight);
                        }
                    }

                    float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht800_light_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight * ff);
                    h_ht800_light_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight * ff);
                    h_ht800_light_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht800_light_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight * ff_barr);
                        h_ht800_light_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight * ff_barr);
                        h_ht800_light_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_light_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht800_light_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT800Weight * ff_end);
                        h_ht800_light_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT800Weight * ff_end);
                        h_ht800_light_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT800Weight * ff_end);
                    }
                }
                else if (HT >= 1200 && HT < 2500)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht1200_light_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight);
                        h_ht1200_light_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight);
                        h_ht1200_light_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht1200_light_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight);
                            h_ht1200_light_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight);
                            h_ht1200_light_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight);
                        }
                        else
                        {
                            h_ht1200_light_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight);
                            h_ht1200_light_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight);
                            h_ht1200_light_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight);
                        }
                    }

                    float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht1200_light_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight * ff);
                    h_ht1200_light_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight * ff);
                    h_ht1200_light_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht1200_light_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight * ff_barr);
                        h_ht1200_light_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight * ff_barr);
                        h_ht1200_light_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_light_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht1200_light_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT1200Weight * ff_end);
                        h_ht1200_light_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT1200Weight * ff_end);
                        h_ht1200_light_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT1200Weight * ff_end);
                    }
                }
                else if (HT >= 2500)
                {
                    if ((*v_ht0_alpha)[i] <= 0.35)
                    {
                        h_ht2500_light_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight);
                        h_ht2500_light_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight);
                        h_ht2500_light_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight);
                        if (abs((*v_ht0_JetEta)[i]) < 1.479)
                        {
                            h_ht2500_light_barr_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight);
                            h_ht2500_light_barr_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight);
                            h_ht2500_light_barr_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight);
                        }
                        else
                        {
                            h_ht2500_light_end_exp_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight);
                            h_ht2500_light_end_exp_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight);
                            h_ht2500_light_end_exp_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight);
                        }
                    }
                    float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                    h_ht2500_light_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight * ff);
                    h_ht2500_light_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight * ff);
                    h_ht2500_light_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight * ff);
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht2500_light_barr_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight * ff_barr);
                        h_ht2500_light_barr_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight * ff_barr);
                        h_ht2500_light_barr_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight * ff_barr);
                    }
                    else
                    {
                        float ff_end = HT_light_end_fakerate_ntr->GetBinContent((*v_ht0_JetnTracks)[i] + 1);
                        h_ht2500_light_end_pred_emergjetpt->Fill((*v_ht0_JetPT)[i], I_weight * HT2500Weight * ff_end);
                        h_ht2500_light_end_pred_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_weight * HT2500Weight * ff_end);
                        h_ht2500_light_end_pred_emergjetEta->Fill((*v_ht0_JetEta)[i], I_weight * HT2500Weight * ff_end);
                    }
                }
            }
        }
    }
    TTree *T_event1;
    DYHT100_2->GetObject("h2", T_event1);
    T_event1->SetBranchAddress("f_Met", &f_ht100_Met);
    T_event1->SetBranchAddress("I_weight", &I_ht100_weight);
    T_event1->SetBranchAddress("v_fakeJethadronflavor", &v_ht100_Jethadronflavor);
    T_event1->SetBranchAddress("v_fakeJetPt", &v_ht100_JetPT);
    T_event1->SetBranchAddress("v_fakeJetEta", &v_ht100_JetEta);
    T_event1->SetBranchAddress("v_fakealpha", &v_ht100_alpha);
    T_event1->SetBranchAddress("v_N_Tracks", &v_ht100_JetnTracks);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        for (int i = 0; i < v_ht100_Jethadronflavor->size(); i++)
        {
            if ((*v_ht100_Jethadronflavor)[i] == 4 || (*v_ht100_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht100_alpha)[i] <= 0.35)
                {
                    h_ht100_hev_exp_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_ht100_hev_exp_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                    h_ht100_hev_exp_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    if (abs((*v_ht100_JetEta)[i]) < 1.479)
                    {
                        h_ht100_hev_barr_exp_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                        h_ht100_hev_barr_exp_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                        h_ht100_hev_barr_exp_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    }
                    else
                    {
                        h_ht100_hev_end_exp_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                        h_ht100_hev_end_exp_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                        h_ht100_hev_end_exp_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    }
                }
                float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht100_JetnTracks)[i] + 1);
                h_ht100_hev_pred_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight * ff);
                h_ht100_hev_pred_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight * ff);
                h_ht100_hev_pred_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight * ff);
                if (abs((*v_ht100_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht100_JetnTracks)[i] + 1);
                    h_ht100_hev_barr_pred_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight * ff_barr);
                    h_ht100_hev_barr_pred_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight * ff_barr);
                    h_ht100_hev_barr_pred_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_hev_fakerate_ntr->GetBinContent((*v_ht100_JetnTracks)[i] + 1);
                    h_ht100_hev_end_pred_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight * ff_end);
                    h_ht100_hev_end_pred_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight * ff_end);
                    h_ht100_hev_end_pred_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight * ff_end);
                }
            }
            else
            {
                if ((*v_ht100_alpha)[i] <= 0.35)
                {
                    h_ht100_light_exp_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_ht100_light_exp_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                    h_ht100_light_exp_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    if (abs((*v_ht100_JetEta)[i]) < 1.479)
                    {
                        h_ht100_light_barr_exp_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                        h_ht100_light_barr_exp_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                        h_ht100_light_barr_exp_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    }
                    else
                    {
                        h_ht100_light_end_exp_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                        h_ht100_light_end_exp_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                        h_ht100_light_end_exp_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    }
                }
                float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht100_JetnTracks)[i] + 1);
                h_ht100_light_pred_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight * ff);
                h_ht100_light_pred_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight * ff);
                h_ht100_light_pred_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight * ff);
                if (abs((*v_ht100_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht100_JetnTracks)[i] + 1);
                    h_ht100_light_barr_pred_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight * ff_barr);
                    h_ht100_light_barr_pred_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight * ff_barr);
                    h_ht100_light_barr_pred_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_light_fakerate_ntr->GetBinContent((*v_ht100_JetnTracks)[i] + 1);
                    h_ht100_light_end_pred_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight * ff_end);
                    h_ht100_light_end_pred_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight * ff_end);
                    h_ht100_light_end_pred_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight * ff_end);
                }
            }
        }
    }
    TTree *T_event2;
    DYHT200_2->GetObject("h2", T_event2);
    T_event2->SetBranchAddress("f_Met", &f_ht200_Met);
    T_event2->SetBranchAddress("I_weight", &I_ht200_weight);
    T_event2->SetBranchAddress("v_fakeJethadronflavor", &v_ht200_Jethadronflavor);
    T_event2->SetBranchAddress("v_fakeJetPt", &v_ht200_JetPT);
    T_event2->SetBranchAddress("v_fakeJetEta", &v_ht200_JetEta);
    T_event2->SetBranchAddress("v_fakealpha", &v_ht200_alpha);
    T_event2->SetBranchAddress("v_N_Tracks", &v_ht200_JetnTracks);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        for (int i = 0; i < v_ht200_Jethadronflavor->size(); i++)
        {
            if ((*v_ht200_Jethadronflavor)[i] == 4 || (*v_ht200_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht200_alpha)[i] <= 0.35)
                {
                    h_ht200_hev_exp_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                    h_ht200_hev_exp_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    h_ht200_hev_exp_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    if (abs((*v_ht200_JetEta)[i]) < 1.479)
                    {
                        h_ht200_hev_barr_exp_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_ht200_hev_barr_exp_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                        h_ht200_hev_barr_exp_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    }
                    else
                    {
                        h_ht200_hev_end_exp_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_ht200_hev_end_exp_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                        h_ht200_hev_end_exp_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    }
                }
                float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht200_JetnTracks)[i] + 1);
                h_ht200_hev_pred_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight * ff);
                h_ht200_hev_pred_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight * ff);
                h_ht200_hev_pred_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight * ff);
                if (abs((*v_ht200_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht200_JetnTracks)[i] + 1);
                    h_ht200_hev_barr_pred_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight * ff_barr);
                    h_ht200_hev_barr_pred_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight * ff_barr);
                    h_ht200_hev_barr_pred_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_hev_fakerate_ntr->GetBinContent((*v_ht200_JetnTracks)[i] + 1);
                    h_ht200_hev_end_pred_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight * ff_end);
                    h_ht200_hev_end_pred_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight * ff_end);
                    h_ht200_hev_end_pred_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight * ff_end);
                }
            }
            else
            {
                if ((*v_ht200_alpha)[i] <= 0.35)
                {
                    h_ht200_light_exp_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                    h_ht200_light_exp_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    h_ht200_light_exp_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    if (abs((*v_ht200_JetEta)[i]) < 1.479)
                    {
                        h_ht200_light_barr_exp_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_ht200_light_barr_exp_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                        h_ht200_light_barr_exp_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    }
                    else
                    {
                        h_ht200_light_end_exp_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_ht200_light_end_exp_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                        h_ht200_light_end_exp_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    }
                }
                float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht200_JetnTracks)[i] + 1);
                h_ht200_light_pred_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight * ff);
                h_ht200_light_pred_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight * ff);
                h_ht200_light_pred_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight * ff);
                if (abs((*v_ht200_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht200_JetnTracks)[i] + 1);
                    h_ht200_light_barr_pred_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight * ff_barr);
                    h_ht200_light_barr_pred_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight * ff_barr);
                    h_ht200_light_barr_pred_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_light_fakerate_ntr->GetBinContent((*v_ht200_JetnTracks)[i] + 1);
                    h_ht200_light_end_pred_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight * ff_end);
                    h_ht200_light_end_pred_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight * ff_end);
                    h_ht200_light_end_pred_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight * ff_end);
                }
            }
        }
    }

    TTree *T_event3;
    DYHT400_2->GetObject("h2", T_event3);
    T_event3->SetBranchAddress("f_Met", &f_ht400_Met);
    T_event3->SetBranchAddress("I_weight", &I_ht400_weight);
    T_event3->SetBranchAddress("v_fakeJethadronflavor", &v_ht400_Jethadronflavor);
    T_event3->SetBranchAddress("v_fakeJetPt", &v_ht400_JetPT);
    T_event3->SetBranchAddress("v_fakeJetEta", &v_ht400_JetEta);
    T_event3->SetBranchAddress("v_fakealpha", &v_ht400_alpha);
    T_event3->SetBranchAddress("v_N_Tracks", &v_ht400_JetnTracks);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        for (int i = 0; i < v_ht400_Jethadronflavor->size(); i++)
        {
            if ((*v_ht400_Jethadronflavor)[i] == 4 || (*v_ht400_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht400_alpha)[i] <= 0.35)
                {
                    h_ht400_hev_exp_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                    h_ht400_hev_exp_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    h_ht400_hev_exp_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    if (abs((*v_ht400_JetEta)[i]) < 1.479)
                    {
                        h_ht400_hev_barr_exp_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_ht400_hev_barr_exp_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                        h_ht400_hev_barr_exp_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    }
                    else
                    {
                        h_ht400_hev_end_exp_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_ht400_hev_end_exp_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                        h_ht400_hev_end_exp_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    }
                }
                float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht400_JetnTracks)[i] + 1);
                h_ht400_hev_pred_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight * ff);
                h_ht400_hev_pred_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight * ff);
                h_ht400_hev_pred_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight * ff);
                if (abs((*v_ht400_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht400_JetnTracks)[i] + 1);
                    h_ht400_hev_barr_pred_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight * ff_barr);
                    h_ht400_hev_barr_pred_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight * ff_barr);
                    h_ht400_hev_barr_pred_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_hev_fakerate_ntr->GetBinContent((*v_ht400_JetnTracks)[i] + 1);
                    h_ht400_hev_end_pred_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight * ff_end);
                    h_ht400_hev_end_pred_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight * ff_end);
                    h_ht400_hev_end_pred_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight * ff_end);
                }
            }
            else
            {
                if ((*v_ht400_alpha)[i] <= 0.35)
                {
                    h_ht400_light_exp_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                    h_ht400_light_exp_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    h_ht400_light_exp_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    if (abs((*v_ht400_JetEta)[i]) < 1.479)
                    {
                        h_ht400_light_barr_exp_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_ht400_light_barr_exp_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                        h_ht400_light_barr_exp_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    }
                    else
                    {
                        h_ht400_light_end_exp_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_ht400_light_end_exp_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                        h_ht400_light_end_exp_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                    }
                }
                float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht400_JetnTracks)[i] + 1);
                h_ht400_light_pred_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight * ff);
                h_ht400_light_pred_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight * ff);
                h_ht400_light_pred_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight * ff);
                if (abs((*v_ht400_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht400_JetnTracks)[i] + 1);
                    h_ht400_light_barr_pred_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight * ff_barr);
                    h_ht400_light_barr_pred_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight * ff_barr);
                    h_ht400_light_barr_pred_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_light_fakerate_ntr->GetBinContent((*v_ht400_JetnTracks)[i] + 1);
                    h_ht400_light_end_pred_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight * ff_end);
                    h_ht400_light_end_pred_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight * ff_end);
                    h_ht400_light_end_pred_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight * ff_end);
                }
            }
        }
    }
    TTree *T_event4;
    DYHT600_2->GetObject("h2", T_event4);
    T_event4->SetBranchAddress("f_Met", &f_ht600_Met);
    T_event4->SetBranchAddress("I_weight", &I_ht600_weight);
    T_event4->SetBranchAddress("v_fakeJethadronflavor", &v_ht600_Jethadronflavor);
    T_event4->SetBranchAddress("v_fakeJetPt", &v_ht600_JetPT);
    T_event4->SetBranchAddress("v_fakeJetEta", &v_ht600_JetEta);
    T_event4->SetBranchAddress("v_fakealpha", &v_ht600_alpha);
    T_event4->SetBranchAddress("v_N_Tracks", &v_ht600_JetnTracks);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        for (int i = 0; i < v_ht600_Jethadronflavor->size(); i++)
        {
            if ((*v_ht600_Jethadronflavor)[i] == 4 || (*v_ht600_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht600_alpha)[i] <= 0.35)
                {
                    h_ht600_hev_exp_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                    h_ht600_hev_exp_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    h_ht600_hev_exp_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    if (abs((*v_ht600_JetEta)[i]) < 1.479)
                    {
                        h_ht600_hev_barr_exp_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_ht600_hev_barr_exp_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                        h_ht600_hev_barr_exp_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    }
                    else
                    {
                        h_ht600_hev_end_exp_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_ht600_hev_end_exp_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                        h_ht600_hev_end_exp_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    }
                }
                float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht600_JetnTracks)[i] + 1);
                h_ht600_hev_pred_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight * ff);
                h_ht600_hev_pred_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight * ff);
                h_ht600_hev_pred_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight * ff);
                if (abs((*v_ht600_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht600_JetnTracks)[i] + 1);
                    h_ht600_hev_barr_pred_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight * ff_barr);
                    h_ht600_hev_barr_pred_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight * ff_barr);
                    h_ht600_hev_barr_pred_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_hev_fakerate_ntr->GetBinContent((*v_ht600_JetnTracks)[i] + 1);
                    h_ht600_hev_end_pred_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight * ff_end);
                    h_ht600_hev_end_pred_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight * ff_end);
                    h_ht600_hev_end_pred_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight * ff_end);
                }
            }
            else
            {
                if ((*v_ht600_alpha)[i] <= 0.35)
                {
                    h_ht600_light_exp_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                    h_ht600_light_exp_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    h_ht600_light_exp_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    if (abs((*v_ht600_JetEta)[i]) < 1.479)
                    {
                        h_ht600_light_barr_exp_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_ht600_light_barr_exp_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                        h_ht600_light_barr_exp_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    }
                    else
                    {
                        h_ht600_light_end_exp_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_ht600_light_end_exp_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                        h_ht600_light_end_exp_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                    }
                }
                float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht600_JetnTracks)[i] + 1);
                h_ht600_light_pred_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight * ff);
                h_ht600_light_pred_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight * ff);
                h_ht600_light_pred_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight * ff);
                if (abs((*v_ht600_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht600_JetnTracks)[i] + 1);
                    h_ht600_light_barr_pred_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight * ff_barr);
                    h_ht600_light_barr_pred_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight * ff_barr);
                    h_ht600_light_barr_pred_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_light_fakerate_ntr->GetBinContent((*v_ht600_JetnTracks)[i] + 1);
                    h_ht600_light_end_pred_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight * ff_end);
                    h_ht600_light_end_pred_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight * ff_end);
                    h_ht600_light_end_pred_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight * ff_end);
                }
            }
        }
    }

    TTree *T_event5;
    DYHT800_2->GetObject("h2", T_event5);
    T_event5->SetBranchAddress("f_Met", &f_ht800_Met);
    T_event5->SetBranchAddress("I_weight", &I_ht800_weight);
    T_event5->SetBranchAddress("v_fakeJethadronflavor", &v_ht800_Jethadronflavor);
    T_event5->SetBranchAddress("v_fakeJetPt", &v_ht800_JetPT);
    T_event5->SetBranchAddress("v_fakeJetEta", &v_ht800_JetEta);
    T_event5->SetBranchAddress("v_fakealpha", &v_ht800_alpha);
    T_event5->SetBranchAddress("v_N_Tracks", &v_ht800_JetnTracks);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        for (int i = 0; i < v_ht800_Jethadronflavor->size(); i++)
        {
            if ((*v_ht800_Jethadronflavor)[i] == 4 || (*v_ht800_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht800_alpha)[i] <= 0.35)
                {
                    h_ht800_hev_exp_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                    h_ht800_hev_exp_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    h_ht800_hev_exp_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    if (abs((*v_ht800_JetEta)[i]) < 1.479)
                    {
                        h_ht800_hev_barr_exp_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_ht800_hev_barr_exp_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                        h_ht800_hev_barr_exp_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    }
                    else
                    {
                        h_ht800_hev_end_exp_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_ht800_hev_end_exp_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                        h_ht800_hev_end_exp_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    }
                }
                float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht800_JetnTracks)[i] + 1);
                h_ht800_hev_pred_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight * ff);
                h_ht800_hev_pred_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight * ff);
                h_ht800_hev_pred_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight * ff);
                if (abs((*v_ht800_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht800_JetnTracks)[i] + 1);
                    h_ht800_hev_barr_pred_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight * ff_barr);
                    h_ht800_hev_barr_pred_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight * ff_barr);
                    h_ht800_hev_barr_pred_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_hev_fakerate_ntr->GetBinContent((*v_ht800_JetnTracks)[i] + 1);
                    h_ht800_hev_end_pred_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight * ff_end);
                    h_ht800_hev_end_pred_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight * ff_end);
                    h_ht800_hev_end_pred_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight * ff_end);
                }
            }
            else
            {
                if ((*v_ht800_alpha)[i] <= 0.35)
                {
                    h_ht800_light_exp_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                    h_ht800_light_exp_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    h_ht800_light_exp_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    if (abs((*v_ht800_JetEta)[i]) < 1.479)
                    {
                        h_ht800_light_barr_exp_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_ht800_light_barr_exp_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                        h_ht800_light_barr_exp_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    }
                    else
                    {
                        h_ht800_light_end_exp_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_ht800_light_end_exp_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                        h_ht800_light_end_exp_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                    }
                }
                float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht800_JetnTracks)[i] + 1);
                h_ht800_light_pred_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight * ff);
                h_ht800_light_pred_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight * ff);
                h_ht800_light_pred_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight * ff);
                if (abs((*v_ht800_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht800_JetnTracks)[i] + 1);
                    h_ht800_light_barr_pred_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight * ff_barr);
                    h_ht800_light_barr_pred_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight * ff_barr);
                    h_ht800_light_barr_pred_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_light_fakerate_ntr->GetBinContent((*v_ht800_JetnTracks)[i] + 1);
                    h_ht800_light_end_pred_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight * ff_end);
                    h_ht800_light_end_pred_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight * ff_end);
                    h_ht800_light_end_pred_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight * ff_end);
                }
            }
        }
    }

    TTree *T_event6;
    DYHT1200_2->GetObject("h2", T_event6);
    T_event6->SetBranchAddress("f_Met", &f_ht1200_Met);
    T_event6->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_event6->SetBranchAddress("v_fakeJethadronflavor", &v_ht1200_Jethadronflavor);
    T_event6->SetBranchAddress("v_fakeJetPt", &v_ht1200_JetPT);
    T_event6->SetBranchAddress("v_fakeJetEta", &v_ht1200_JetEta);
    T_event6->SetBranchAddress("v_fakealpha", &v_ht1200_alpha);
    T_event6->SetBranchAddress("v_N_Tracks", &v_ht1200_JetnTracks);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        for (int i = 0; i < v_ht1200_Jethadronflavor->size(); i++)
        {
            if ((*v_ht1200_Jethadronflavor)[i] == 4 || (*v_ht1200_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht1200_alpha)[i] <= 0.35)
                {
                    h_ht1200_hev_exp_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                    h_ht1200_hev_exp_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    h_ht1200_hev_exp_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    if (abs((*v_ht1200_JetEta)[i]) < 1.479)
                    {
                        h_ht1200_hev_barr_exp_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_hev_barr_exp_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_hev_barr_exp_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    }
                    else
                    {
                        h_ht1200_hev_end_exp_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_hev_end_exp_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_hev_end_exp_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    }
                }
                float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht1200_JetnTracks)[i] + 1);
                h_ht1200_hev_pred_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight * ff);
                h_ht1200_hev_pred_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight * ff);
                h_ht1200_hev_pred_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight * ff);
                if (abs((*v_ht1200_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht1200_JetnTracks)[i] + 1);
                    h_ht1200_hev_barr_pred_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight * ff_barr);
                    h_ht1200_hev_barr_pred_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight * ff_barr);
                    h_ht1200_hev_barr_pred_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_hev_fakerate_ntr->GetBinContent((*v_ht1200_JetnTracks)[i] + 1);
                    h_ht1200_hev_end_pred_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight * ff_end);
                    h_ht1200_hev_end_pred_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight * ff_end);
                    h_ht1200_hev_end_pred_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight * ff_end);
                }
            }
            else
            {
                if ((*v_ht1200_alpha)[i] <= 0.35)
                {
                    h_ht1200_light_exp_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                    h_ht1200_light_exp_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    h_ht1200_light_exp_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    if (abs((*v_ht1200_JetEta)[i]) < 1.479)
                    {
                        h_ht1200_light_barr_exp_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_light_barr_exp_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_light_barr_exp_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    }
                    else
                    {
                        h_ht1200_light_end_exp_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_light_end_exp_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_light_end_exp_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                    }
                }
                float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht1200_JetnTracks)[i] + 1);
                h_ht1200_light_pred_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight * ff);
                h_ht1200_light_pred_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight * ff);
                h_ht1200_light_pred_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight * ff);
                if (abs((*v_ht1200_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht1200_JetnTracks)[i] + 1);
                    h_ht1200_light_barr_pred_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight * ff_barr);
                    h_ht1200_light_barr_pred_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight * ff_barr);
                    h_ht1200_light_barr_pred_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_light_fakerate_ntr->GetBinContent((*v_ht1200_JetnTracks)[i] + 1);
                    h_ht1200_light_end_pred_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight * ff_end);
                    h_ht1200_light_end_pred_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight * ff_end);
                    h_ht1200_light_end_pred_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight * ff_end);
                }
            }
        }
    }

    TTree *T_event7;
    DYHT2500_2->GetObject("h2", T_event7);
    T_event7->SetBranchAddress("f_Met", &f_ht2500_Met);
    T_event7->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_event7->SetBranchAddress("v_fakeJethadronflavor", &v_ht2500_Jethadronflavor);
    T_event7->SetBranchAddress("v_fakeJetPt", &v_ht2500_JetPT);
    T_event7->SetBranchAddress("v_fakeJetEta", &v_ht2500_JetEta);
    T_event7->SetBranchAddress("v_fakealpha", &v_ht2500_alpha);
    T_event7->SetBranchAddress("v_N_Tracks", &v_ht2500_JetnTracks);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        for (int i = 0; i < v_ht2500_Jethadronflavor->size(); i++)
        {
            if ((*v_ht2500_Jethadronflavor)[i] == 4 || (*v_ht2500_Jethadronflavor)[i] == 5)
            {
                if ((*v_ht2500_alpha)[i] <= 0.35)
                {
                    h_ht2500_hev_exp_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                    h_ht2500_hev_exp_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    h_ht2500_hev_exp_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    if (abs((*v_ht2500_JetEta)[i]) < 1.479)
                    {
                        h_ht2500_hev_barr_exp_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_hev_barr_exp_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_hev_barr_exp_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    }
                    else
                    {
                        h_ht2500_hev_end_exp_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_hev_end_exp_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_hev_end_exp_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    }
                }
                float ff = HT_hev_fakerate_ntr->GetBinContent((*v_ht2500_JetnTracks)[i] + 1);
                h_ht2500_hev_pred_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight * ff);
                h_ht2500_hev_pred_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight * ff);
                h_ht2500_hev_pred_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight * ff);
                if (abs((*v_ht2500_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_hev_barr_fakerate_ntr->GetBinContent((*v_ht2500_JetnTracks)[i] + 1);
                    h_ht2500_hev_barr_pred_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight * ff_barr);
                    h_ht2500_hev_barr_pred_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight * ff_barr);
                    h_ht2500_hev_barr_pred_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_hev_fakerate_ntr->GetBinContent((*v_ht2500_JetnTracks)[i] + 1);
                    h_ht2500_hev_end_pred_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight * ff_end);
                    h_ht2500_hev_end_pred_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight * ff_end);
                    h_ht2500_hev_end_pred_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight * ff_end);
                }
            }
            else
            {
                if ((*v_ht2500_alpha)[i] <= 0.35)
                {
                    h_ht2500_light_exp_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                    h_ht2500_light_exp_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    h_ht2500_light_exp_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    if (abs((*v_ht2500_JetEta)[i]) < 1.479)
                    {
                        h_ht2500_light_barr_exp_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_light_barr_exp_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_light_barr_exp_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    }
                    else
                    {
                        h_ht2500_light_end_exp_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_light_end_exp_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_light_end_exp_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                    }
                }
                float ff = HT_light_fakerate_ntr->GetBinContent((*v_ht2500_JetnTracks)[i] + 1);
                h_ht2500_light_pred_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight * ff);
                h_ht2500_light_pred_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight * ff);
                h_ht2500_light_pred_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight * ff);
                if (abs((*v_ht2500_JetEta)[i]) < 1.479)
                {
                    float ff_barr = HT_light_barr_fakerate_ntr->GetBinContent((*v_ht2500_JetnTracks)[i] + 1);
                    h_ht2500_light_barr_pred_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight * ff_barr);
                    h_ht2500_light_barr_pred_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight * ff_barr);
                    h_ht2500_light_barr_pred_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight * ff_barr);
                }
                else
                {
                    float ff_end = HT_light_fakerate_ntr->GetBinContent((*v_ht2500_JetnTracks)[i] + 1);
                    h_ht2500_light_end_pred_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight * ff_end);
                    h_ht2500_light_end_pred_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight * ff_end);
                    h_ht2500_light_end_pred_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight * ff_end);
                }
            }
        }
    }
    h_ht0_hev_pred_emergjetpt->Add(h_ht70_hev_pred_emergjetpt);
    h_ht0_hev_pred_emergjetpt->Add(h_ht100_hev_pred_emergjetpt);
    h_ht0_hev_pred_emergjetpt->Add(h_ht200_hev_pred_emergjetpt);
    h_ht0_hev_pred_emergjetpt->Add(h_ht400_hev_pred_emergjetpt);
    h_ht0_hev_pred_emergjetpt->Add(h_ht600_hev_pred_emergjetpt);
    h_ht0_hev_pred_emergjetpt->Add(h_ht800_hev_pred_emergjetpt);
    h_ht0_hev_pred_emergjetpt->Add(h_ht1200_hev_pred_emergjetpt);
    h_ht0_hev_pred_emergjetpt->Add(h_ht2500_hev_pred_emergjetpt);

    h_ht0_hev_exp_emergjetpt->Add(h_ht70_hev_exp_emergjetpt);
    h_ht0_hev_exp_emergjetpt->Add(h_ht100_hev_exp_emergjetpt);
    h_ht0_hev_exp_emergjetpt->Add(h_ht200_hev_exp_emergjetpt);
    h_ht0_hev_exp_emergjetpt->Add(h_ht400_hev_exp_emergjetpt);
    h_ht0_hev_exp_emergjetpt->Add(h_ht600_hev_exp_emergjetpt);
    h_ht0_hev_exp_emergjetpt->Add(h_ht800_hev_exp_emergjetpt);
    h_ht0_hev_exp_emergjetpt->Add(h_ht1200_hev_exp_emergjetpt);
    h_ht0_hev_exp_emergjetpt->Add(h_ht2500_hev_exp_emergjetpt);

    h_ht0_light_pred_emergjetpt->Add(h_ht70_light_pred_emergjetpt);
    h_ht0_light_pred_emergjetpt->Add(h_ht100_light_pred_emergjetpt);
    h_ht0_light_pred_emergjetpt->Add(h_ht200_light_pred_emergjetpt);
    h_ht0_light_pred_emergjetpt->Add(h_ht400_light_pred_emergjetpt);
    h_ht0_light_pred_emergjetpt->Add(h_ht600_light_pred_emergjetpt);
    h_ht0_light_pred_emergjetpt->Add(h_ht800_light_pred_emergjetpt);
    h_ht0_light_pred_emergjetpt->Add(h_ht1200_light_pred_emergjetpt);
    h_ht0_light_pred_emergjetpt->Add(h_ht2500_light_pred_emergjetpt);

    h_ht0_light_exp_emergjetpt->Add(h_ht70_light_exp_emergjetpt);
    h_ht0_light_exp_emergjetpt->Add(h_ht100_light_exp_emergjetpt);
    h_ht0_light_exp_emergjetpt->Add(h_ht200_light_exp_emergjetpt);
    h_ht0_light_exp_emergjetpt->Add(h_ht400_light_exp_emergjetpt);
    h_ht0_light_exp_emergjetpt->Add(h_ht600_light_exp_emergjetpt);
    h_ht0_light_exp_emergjetpt->Add(h_ht800_light_exp_emergjetpt);
    h_ht0_light_exp_emergjetpt->Add(h_ht1200_light_exp_emergjetpt);
    h_ht0_light_exp_emergjetpt->Add(h_ht2500_light_exp_emergjetpt);

    h_ht0_hev_pred_emergjetnTrack->Add(h_ht70_hev_pred_emergjetnTrack);
    h_ht0_hev_pred_emergjetnTrack->Add(h_ht100_hev_pred_emergjetnTrack);
    h_ht0_hev_pred_emergjetnTrack->Add(h_ht200_hev_pred_emergjetnTrack);
    h_ht0_hev_pred_emergjetnTrack->Add(h_ht400_hev_pred_emergjetnTrack);
    h_ht0_hev_pred_emergjetnTrack->Add(h_ht600_hev_pred_emergjetnTrack);
    h_ht0_hev_pred_emergjetnTrack->Add(h_ht800_hev_pred_emergjetnTrack);
    h_ht0_hev_pred_emergjetnTrack->Add(h_ht1200_hev_pred_emergjetnTrack);
    h_ht0_hev_pred_emergjetnTrack->Add(h_ht2500_hev_pred_emergjetnTrack);

    h_ht0_hev_exp_emergjetnTrack->Add(h_ht70_hev_exp_emergjetnTrack);
    h_ht0_hev_exp_emergjetnTrack->Add(h_ht100_hev_exp_emergjetnTrack);
    h_ht0_hev_exp_emergjetnTrack->Add(h_ht200_hev_exp_emergjetnTrack);
    h_ht0_hev_exp_emergjetnTrack->Add(h_ht400_hev_exp_emergjetnTrack);
    h_ht0_hev_exp_emergjetnTrack->Add(h_ht600_hev_exp_emergjetnTrack);
    h_ht0_hev_exp_emergjetnTrack->Add(h_ht800_hev_exp_emergjetnTrack);
    h_ht0_hev_exp_emergjetnTrack->Add(h_ht1200_hev_exp_emergjetnTrack);
    h_ht0_hev_exp_emergjetnTrack->Add(h_ht2500_hev_exp_emergjetnTrack);

    h_ht0_light_pred_emergjetnTrack->Add(h_ht70_light_pred_emergjetnTrack);
    h_ht0_light_pred_emergjetnTrack->Add(h_ht100_light_pred_emergjetnTrack);
    h_ht0_light_pred_emergjetnTrack->Add(h_ht200_light_pred_emergjetnTrack);
    h_ht0_light_pred_emergjetnTrack->Add(h_ht400_light_pred_emergjetnTrack);
    h_ht0_light_pred_emergjetnTrack->Add(h_ht600_light_pred_emergjetnTrack);
    h_ht0_light_pred_emergjetnTrack->Add(h_ht800_light_pred_emergjetnTrack);
    h_ht0_light_pred_emergjetnTrack->Add(h_ht1200_light_pred_emergjetnTrack);
    h_ht0_light_pred_emergjetnTrack->Add(h_ht2500_light_pred_emergjetnTrack);

    h_ht0_light_exp_emergjetnTrack->Add(h_ht70_light_exp_emergjetnTrack);
    h_ht0_light_exp_emergjetnTrack->Add(h_ht100_light_exp_emergjetnTrack);
    h_ht0_light_exp_emergjetnTrack->Add(h_ht200_light_exp_emergjetnTrack);
    h_ht0_light_exp_emergjetnTrack->Add(h_ht400_light_exp_emergjetnTrack);
    h_ht0_light_exp_emergjetnTrack->Add(h_ht600_light_exp_emergjetnTrack);
    h_ht0_light_exp_emergjetnTrack->Add(h_ht800_light_exp_emergjetnTrack);
    h_ht0_light_exp_emergjetnTrack->Add(h_ht1200_light_exp_emergjetnTrack);
    h_ht0_light_exp_emergjetnTrack->Add(h_ht2500_light_exp_emergjetnTrack);

    h_ht0_hev_pred_emergjetEta->Add(h_ht70_hev_pred_emergjetEta);
    h_ht0_hev_pred_emergjetEta->Add(h_ht100_hev_pred_emergjetEta);
    h_ht0_hev_pred_emergjetEta->Add(h_ht200_hev_pred_emergjetEta);
    h_ht0_hev_pred_emergjetEta->Add(h_ht400_hev_pred_emergjetEta);
    h_ht0_hev_pred_emergjetEta->Add(h_ht600_hev_pred_emergjetEta);
    h_ht0_hev_pred_emergjetEta->Add(h_ht800_hev_pred_emergjetEta);
    h_ht0_hev_pred_emergjetEta->Add(h_ht1200_hev_pred_emergjetEta);
    h_ht0_hev_pred_emergjetEta->Add(h_ht2500_hev_pred_emergjetEta);

    h_ht0_hev_exp_emergjetEta->Add(h_ht70_hev_exp_emergjetEta);
    h_ht0_hev_exp_emergjetEta->Add(h_ht100_hev_exp_emergjetEta);
    h_ht0_hev_exp_emergjetEta->Add(h_ht200_hev_exp_emergjetEta);
    h_ht0_hev_exp_emergjetEta->Add(h_ht400_hev_exp_emergjetEta);
    h_ht0_hev_exp_emergjetEta->Add(h_ht600_hev_exp_emergjetEta);
    h_ht0_hev_exp_emergjetEta->Add(h_ht800_hev_exp_emergjetEta);
    h_ht0_hev_exp_emergjetEta->Add(h_ht1200_hev_exp_emergjetEta);
    h_ht0_hev_exp_emergjetEta->Add(h_ht2500_hev_exp_emergjetEta);

    h_ht0_light_pred_emergjetEta->Add(h_ht70_light_pred_emergjetEta);
    h_ht0_light_pred_emergjetEta->Add(h_ht100_light_pred_emergjetEta);
    h_ht0_light_pred_emergjetEta->Add(h_ht200_light_pred_emergjetEta);
    h_ht0_light_pred_emergjetEta->Add(h_ht400_light_pred_emergjetEta);
    h_ht0_light_pred_emergjetEta->Add(h_ht600_light_pred_emergjetEta);
    h_ht0_light_pred_emergjetEta->Add(h_ht800_light_pred_emergjetEta);
    h_ht0_light_pred_emergjetEta->Add(h_ht1200_light_pred_emergjetEta);
    h_ht0_light_pred_emergjetEta->Add(h_ht2500_light_pred_emergjetEta);

    h_ht0_light_exp_emergjetEta->Add(h_ht70_light_exp_emergjetEta);
    h_ht0_light_exp_emergjetEta->Add(h_ht100_light_exp_emergjetEta);
    h_ht0_light_exp_emergjetEta->Add(h_ht200_light_exp_emergjetEta);
    h_ht0_light_exp_emergjetEta->Add(h_ht400_light_exp_emergjetEta);
    h_ht0_light_exp_emergjetEta->Add(h_ht600_light_exp_emergjetEta);
    h_ht0_light_exp_emergjetEta->Add(h_ht800_light_exp_emergjetEta);
    h_ht0_light_exp_emergjetEta->Add(h_ht1200_light_exp_emergjetEta);
    h_ht0_light_exp_emergjetEta->Add(h_ht2500_light_exp_emergjetEta);

    h_ht0_hev_barr_pred_emergjetpt->Add(h_ht70_hev_barr_pred_emergjetpt);
    h_ht0_hev_barr_pred_emergjetpt->Add(h_ht100_hev_barr_pred_emergjetpt);
    h_ht0_hev_barr_pred_emergjetpt->Add(h_ht200_hev_barr_pred_emergjetpt);
    h_ht0_hev_barr_pred_emergjetpt->Add(h_ht400_hev_barr_pred_emergjetpt);
    h_ht0_hev_barr_pred_emergjetpt->Add(h_ht600_hev_barr_pred_emergjetpt);
    h_ht0_hev_barr_pred_emergjetpt->Add(h_ht800_hev_barr_pred_emergjetpt);
    h_ht0_hev_barr_pred_emergjetpt->Add(h_ht1200_hev_barr_pred_emergjetpt);
    h_ht0_hev_barr_pred_emergjetpt->Add(h_ht2500_hev_barr_pred_emergjetpt);

    h_ht0_hev_barr_exp_emergjetpt->Add(h_ht70_hev_barr_exp_emergjetpt);
    h_ht0_hev_barr_exp_emergjetpt->Add(h_ht100_hev_barr_exp_emergjetpt);
    h_ht0_hev_barr_exp_emergjetpt->Add(h_ht200_hev_barr_exp_emergjetpt);
    h_ht0_hev_barr_exp_emergjetpt->Add(h_ht400_hev_barr_exp_emergjetpt);
    h_ht0_hev_barr_exp_emergjetpt->Add(h_ht600_hev_barr_exp_emergjetpt);
    h_ht0_hev_barr_exp_emergjetpt->Add(h_ht800_hev_barr_exp_emergjetpt);
    h_ht0_hev_barr_exp_emergjetpt->Add(h_ht1200_hev_barr_exp_emergjetpt);
    h_ht0_hev_barr_exp_emergjetpt->Add(h_ht2500_hev_barr_exp_emergjetpt);

    h_ht0_light_barr_pred_emergjetpt->Add(h_ht70_light_barr_pred_emergjetpt);
    h_ht0_light_barr_pred_emergjetpt->Add(h_ht100_light_barr_pred_emergjetpt);
    h_ht0_light_barr_pred_emergjetpt->Add(h_ht200_light_barr_pred_emergjetpt);
    h_ht0_light_barr_pred_emergjetpt->Add(h_ht400_light_barr_pred_emergjetpt);
    h_ht0_light_barr_pred_emergjetpt->Add(h_ht600_light_barr_pred_emergjetpt);
    h_ht0_light_barr_pred_emergjetpt->Add(h_ht800_light_barr_pred_emergjetpt);
    h_ht0_light_barr_pred_emergjetpt->Add(h_ht1200_light_barr_pred_emergjetpt);
    h_ht0_light_barr_pred_emergjetpt->Add(h_ht2500_light_barr_pred_emergjetpt);

    h_ht0_light_barr_exp_emergjetpt->Add(h_ht70_light_barr_exp_emergjetpt);
    h_ht0_light_barr_exp_emergjetpt->Add(h_ht100_light_barr_exp_emergjetpt);
    h_ht0_light_barr_exp_emergjetpt->Add(h_ht200_light_barr_exp_emergjetpt);
    h_ht0_light_barr_exp_emergjetpt->Add(h_ht400_light_barr_exp_emergjetpt);
    h_ht0_light_barr_exp_emergjetpt->Add(h_ht600_light_barr_exp_emergjetpt);
    h_ht0_light_barr_exp_emergjetpt->Add(h_ht800_light_barr_exp_emergjetpt);
    h_ht0_light_barr_exp_emergjetpt->Add(h_ht1200_light_barr_exp_emergjetpt);
    h_ht0_light_barr_exp_emergjetpt->Add(h_ht2500_light_barr_exp_emergjetpt);

    h_ht0_hev_barr_pred_emergjetnTrack->Add(h_ht70_hev_barr_pred_emergjetnTrack);
    h_ht0_hev_barr_pred_emergjetnTrack->Add(h_ht100_hev_barr_pred_emergjetnTrack);
    h_ht0_hev_barr_pred_emergjetnTrack->Add(h_ht200_hev_barr_pred_emergjetnTrack);
    h_ht0_hev_barr_pred_emergjetnTrack->Add(h_ht400_hev_barr_pred_emergjetnTrack);
    h_ht0_hev_barr_pred_emergjetnTrack->Add(h_ht600_hev_barr_pred_emergjetnTrack);
    h_ht0_hev_barr_pred_emergjetnTrack->Add(h_ht800_hev_barr_pred_emergjetnTrack);
    h_ht0_hev_barr_pred_emergjetnTrack->Add(h_ht1200_hev_barr_pred_emergjetnTrack);
    h_ht0_hev_barr_pred_emergjetnTrack->Add(h_ht2500_hev_barr_pred_emergjetnTrack);

    h_ht0_hev_barr_exp_emergjetnTrack->Add(h_ht70_hev_barr_exp_emergjetnTrack);
    h_ht0_hev_barr_exp_emergjetnTrack->Add(h_ht100_hev_barr_exp_emergjetnTrack);
    h_ht0_hev_barr_exp_emergjetnTrack->Add(h_ht200_hev_barr_exp_emergjetnTrack);
    h_ht0_hev_barr_exp_emergjetnTrack->Add(h_ht400_hev_barr_exp_emergjetnTrack);
    h_ht0_hev_barr_exp_emergjetnTrack->Add(h_ht600_hev_barr_exp_emergjetnTrack);
    h_ht0_hev_barr_exp_emergjetnTrack->Add(h_ht800_hev_barr_exp_emergjetnTrack);
    h_ht0_hev_barr_exp_emergjetnTrack->Add(h_ht1200_hev_barr_exp_emergjetnTrack);
    h_ht0_hev_barr_exp_emergjetnTrack->Add(h_ht2500_hev_barr_exp_emergjetnTrack);

    h_ht0_light_barr_pred_emergjetnTrack->Add(h_ht70_light_barr_pred_emergjetnTrack);
    h_ht0_light_barr_pred_emergjetnTrack->Add(h_ht100_light_barr_pred_emergjetnTrack);
    h_ht0_light_barr_pred_emergjetnTrack->Add(h_ht200_light_barr_pred_emergjetnTrack);
    h_ht0_light_barr_pred_emergjetnTrack->Add(h_ht400_light_barr_pred_emergjetnTrack);
    h_ht0_light_barr_pred_emergjetnTrack->Add(h_ht600_light_barr_pred_emergjetnTrack);
    h_ht0_light_barr_pred_emergjetnTrack->Add(h_ht800_light_barr_pred_emergjetnTrack);
    h_ht0_light_barr_pred_emergjetnTrack->Add(h_ht1200_light_barr_pred_emergjetnTrack);
    h_ht0_light_barr_pred_emergjetnTrack->Add(h_ht2500_light_barr_pred_emergjetnTrack);

    h_ht0_light_barr_exp_emergjetnTrack->Add(h_ht70_light_barr_exp_emergjetnTrack);
    h_ht0_light_barr_exp_emergjetnTrack->Add(h_ht100_light_barr_exp_emergjetnTrack);
    h_ht0_light_barr_exp_emergjetnTrack->Add(h_ht200_light_barr_exp_emergjetnTrack);
    h_ht0_light_barr_exp_emergjetnTrack->Add(h_ht400_light_barr_exp_emergjetnTrack);
    h_ht0_light_barr_exp_emergjetnTrack->Add(h_ht600_light_barr_exp_emergjetnTrack);
    h_ht0_light_barr_exp_emergjetnTrack->Add(h_ht800_light_barr_exp_emergjetnTrack);
    h_ht0_light_barr_exp_emergjetnTrack->Add(h_ht1200_light_barr_exp_emergjetnTrack);
    h_ht0_light_barr_exp_emergjetnTrack->Add(h_ht2500_light_barr_exp_emergjetnTrack);

    h_ht0_hev_barr_pred_emergjetEta->Add(h_ht70_hev_barr_pred_emergjetEta);
    h_ht0_hev_barr_pred_emergjetEta->Add(h_ht100_hev_barr_pred_emergjetEta);
    h_ht0_hev_barr_pred_emergjetEta->Add(h_ht200_hev_barr_pred_emergjetEta);
    h_ht0_hev_barr_pred_emergjetEta->Add(h_ht400_hev_barr_pred_emergjetEta);
    h_ht0_hev_barr_pred_emergjetEta->Add(h_ht600_hev_barr_pred_emergjetEta);
    h_ht0_hev_barr_pred_emergjetEta->Add(h_ht800_hev_barr_pred_emergjetEta);
    h_ht0_hev_barr_pred_emergjetEta->Add(h_ht1200_hev_barr_pred_emergjetEta);
    h_ht0_hev_barr_pred_emergjetEta->Add(h_ht2500_hev_barr_pred_emergjetEta);

    h_ht0_hev_barr_exp_emergjetEta->Add(h_ht70_hev_barr_exp_emergjetEta);
    h_ht0_hev_barr_exp_emergjetEta->Add(h_ht100_hev_barr_exp_emergjetEta);
    h_ht0_hev_barr_exp_emergjetEta->Add(h_ht200_hev_barr_exp_emergjetEta);
    h_ht0_hev_barr_exp_emergjetEta->Add(h_ht400_hev_barr_exp_emergjetEta);
    h_ht0_hev_barr_exp_emergjetEta->Add(h_ht600_hev_barr_exp_emergjetEta);
    h_ht0_hev_barr_exp_emergjetEta->Add(h_ht800_hev_barr_exp_emergjetEta);
    h_ht0_hev_barr_exp_emergjetEta->Add(h_ht1200_hev_barr_exp_emergjetEta);
    h_ht0_hev_barr_exp_emergjetEta->Add(h_ht2500_hev_barr_exp_emergjetEta);

    h_ht0_light_barr_pred_emergjetEta->Add(h_ht70_light_barr_pred_emergjetEta);
    h_ht0_light_barr_pred_emergjetEta->Add(h_ht100_light_barr_pred_emergjetEta);
    h_ht0_light_barr_pred_emergjetEta->Add(h_ht200_light_barr_pred_emergjetEta);
    h_ht0_light_barr_pred_emergjetEta->Add(h_ht400_light_barr_pred_emergjetEta);
    h_ht0_light_barr_pred_emergjetEta->Add(h_ht600_light_barr_pred_emergjetEta);
    h_ht0_light_barr_pred_emergjetEta->Add(h_ht800_light_barr_pred_emergjetEta);
    h_ht0_light_barr_pred_emergjetEta->Add(h_ht1200_light_barr_pred_emergjetEta);
    h_ht0_light_barr_pred_emergjetEta->Add(h_ht2500_light_barr_pred_emergjetEta);

    h_ht0_light_barr_exp_emergjetEta->Add(h_ht70_light_barr_exp_emergjetEta);
    h_ht0_light_barr_exp_emergjetEta->Add(h_ht100_light_barr_exp_emergjetEta);
    h_ht0_light_barr_exp_emergjetEta->Add(h_ht200_light_barr_exp_emergjetEta);
    h_ht0_light_barr_exp_emergjetEta->Add(h_ht400_light_barr_exp_emergjetEta);
    h_ht0_light_barr_exp_emergjetEta->Add(h_ht600_light_barr_exp_emergjetEta);
    h_ht0_light_barr_exp_emergjetEta->Add(h_ht800_light_barr_exp_emergjetEta);
    h_ht0_light_barr_exp_emergjetEta->Add(h_ht1200_light_barr_exp_emergjetEta);
    h_ht0_light_barr_exp_emergjetEta->Add(h_ht2500_light_barr_exp_emergjetEta);

    h_ht0_hev_end_pred_emergjetpt->Add(h_ht70_hev_end_pred_emergjetpt);
    h_ht0_hev_end_pred_emergjetpt->Add(h_ht100_hev_end_pred_emergjetpt);
    h_ht0_hev_end_pred_emergjetpt->Add(h_ht200_hev_end_pred_emergjetpt);
    h_ht0_hev_end_pred_emergjetpt->Add(h_ht400_hev_end_pred_emergjetpt);
    h_ht0_hev_end_pred_emergjetpt->Add(h_ht600_hev_end_pred_emergjetpt);
    h_ht0_hev_end_pred_emergjetpt->Add(h_ht800_hev_end_pred_emergjetpt);
    h_ht0_hev_end_pred_emergjetpt->Add(h_ht1200_hev_end_pred_emergjetpt);
    h_ht0_hev_end_pred_emergjetpt->Add(h_ht2500_hev_end_pred_emergjetpt);

    h_ht0_hev_end_exp_emergjetpt->Add(h_ht70_hev_end_exp_emergjetpt);
    h_ht0_hev_end_exp_emergjetpt->Add(h_ht100_hev_end_exp_emergjetpt);
    h_ht0_hev_end_exp_emergjetpt->Add(h_ht200_hev_end_exp_emergjetpt);
    h_ht0_hev_end_exp_emergjetpt->Add(h_ht400_hev_end_exp_emergjetpt);
    h_ht0_hev_end_exp_emergjetpt->Add(h_ht600_hev_end_exp_emergjetpt);
    h_ht0_hev_end_exp_emergjetpt->Add(h_ht800_hev_end_exp_emergjetpt);
    h_ht0_hev_end_exp_emergjetpt->Add(h_ht1200_hev_end_exp_emergjetpt);
    h_ht0_hev_end_exp_emergjetpt->Add(h_ht2500_hev_end_exp_emergjetpt);

    h_ht0_light_end_pred_emergjetpt->Add(h_ht70_light_end_pred_emergjetpt);
    h_ht0_light_end_pred_emergjetpt->Add(h_ht100_light_end_pred_emergjetpt);
    h_ht0_light_end_pred_emergjetpt->Add(h_ht200_light_end_pred_emergjetpt);
    h_ht0_light_end_pred_emergjetpt->Add(h_ht400_light_end_pred_emergjetpt);
    h_ht0_light_end_pred_emergjetpt->Add(h_ht600_light_end_pred_emergjetpt);
    h_ht0_light_end_pred_emergjetpt->Add(h_ht800_light_end_pred_emergjetpt);
    h_ht0_light_end_pred_emergjetpt->Add(h_ht1200_light_end_pred_emergjetpt);
    h_ht0_light_end_pred_emergjetpt->Add(h_ht2500_light_end_pred_emergjetpt);

    h_ht0_light_end_exp_emergjetpt->Add(h_ht70_light_end_exp_emergjetpt);
    h_ht0_light_end_exp_emergjetpt->Add(h_ht100_light_end_exp_emergjetpt);
    h_ht0_light_end_exp_emergjetpt->Add(h_ht200_light_end_exp_emergjetpt);
    h_ht0_light_end_exp_emergjetpt->Add(h_ht400_light_end_exp_emergjetpt);
    h_ht0_light_end_exp_emergjetpt->Add(h_ht600_light_end_exp_emergjetpt);
    h_ht0_light_end_exp_emergjetpt->Add(h_ht800_light_end_exp_emergjetpt);
    h_ht0_light_end_exp_emergjetpt->Add(h_ht1200_light_end_exp_emergjetpt);
    h_ht0_light_end_exp_emergjetpt->Add(h_ht2500_light_end_exp_emergjetpt);

    h_ht0_hev_end_pred_emergjetnTrack->Add(h_ht70_hev_end_pred_emergjetnTrack);
    h_ht0_hev_end_pred_emergjetnTrack->Add(h_ht100_hev_end_pred_emergjetnTrack);
    h_ht0_hev_end_pred_emergjetnTrack->Add(h_ht200_hev_end_pred_emergjetnTrack);
    h_ht0_hev_end_pred_emergjetnTrack->Add(h_ht400_hev_end_pred_emergjetnTrack);
    h_ht0_hev_end_pred_emergjetnTrack->Add(h_ht600_hev_end_pred_emergjetnTrack);
    h_ht0_hev_end_pred_emergjetnTrack->Add(h_ht800_hev_end_pred_emergjetnTrack);
    h_ht0_hev_end_pred_emergjetnTrack->Add(h_ht1200_hev_end_pred_emergjetnTrack);
    h_ht0_hev_end_pred_emergjetnTrack->Add(h_ht2500_hev_end_pred_emergjetnTrack);

    h_ht0_hev_end_exp_emergjetnTrack->Add(h_ht70_hev_end_exp_emergjetnTrack);
    h_ht0_hev_end_exp_emergjetnTrack->Add(h_ht100_hev_end_exp_emergjetnTrack);
    h_ht0_hev_end_exp_emergjetnTrack->Add(h_ht200_hev_end_exp_emergjetnTrack);
    h_ht0_hev_end_exp_emergjetnTrack->Add(h_ht400_hev_end_exp_emergjetnTrack);
    h_ht0_hev_end_exp_emergjetnTrack->Add(h_ht600_hev_end_exp_emergjetnTrack);
    h_ht0_hev_end_exp_emergjetnTrack->Add(h_ht800_hev_end_exp_emergjetnTrack);
    h_ht0_hev_end_exp_emergjetnTrack->Add(h_ht1200_hev_end_exp_emergjetnTrack);
    h_ht0_hev_end_exp_emergjetnTrack->Add(h_ht2500_hev_end_exp_emergjetnTrack);

    h_ht0_light_end_pred_emergjetnTrack->Add(h_ht70_light_end_pred_emergjetnTrack);
    h_ht0_light_end_pred_emergjetnTrack->Add(h_ht100_light_end_pred_emergjetnTrack);
    h_ht0_light_end_pred_emergjetnTrack->Add(h_ht200_light_end_pred_emergjetnTrack);
    h_ht0_light_end_pred_emergjetnTrack->Add(h_ht400_light_end_pred_emergjetnTrack);
    h_ht0_light_end_pred_emergjetnTrack->Add(h_ht600_light_end_pred_emergjetnTrack);
    h_ht0_light_end_pred_emergjetnTrack->Add(h_ht800_light_end_pred_emergjetnTrack);
    h_ht0_light_end_pred_emergjetnTrack->Add(h_ht1200_light_end_pred_emergjetnTrack);
    h_ht0_light_end_pred_emergjetnTrack->Add(h_ht2500_light_end_pred_emergjetnTrack);

    h_ht0_light_end_exp_emergjetnTrack->Add(h_ht70_light_end_exp_emergjetnTrack);
    h_ht0_light_end_exp_emergjetnTrack->Add(h_ht100_light_end_exp_emergjetnTrack);
    h_ht0_light_end_exp_emergjetnTrack->Add(h_ht200_light_end_exp_emergjetnTrack);
    h_ht0_light_end_exp_emergjetnTrack->Add(h_ht400_light_end_exp_emergjetnTrack);
    h_ht0_light_end_exp_emergjetnTrack->Add(h_ht600_light_end_exp_emergjetnTrack);
    h_ht0_light_end_exp_emergjetnTrack->Add(h_ht800_light_end_exp_emergjetnTrack);
    h_ht0_light_end_exp_emergjetnTrack->Add(h_ht1200_light_end_exp_emergjetnTrack);
    h_ht0_light_end_exp_emergjetnTrack->Add(h_ht2500_light_end_exp_emergjetnTrack);

    h_ht0_hev_end_pred_emergjetEta->Add(h_ht70_hev_end_pred_emergjetEta);
    h_ht0_hev_end_pred_emergjetEta->Add(h_ht100_hev_end_pred_emergjetEta);
    h_ht0_hev_end_pred_emergjetEta->Add(h_ht200_hev_end_pred_emergjetEta);
    h_ht0_hev_end_pred_emergjetEta->Add(h_ht400_hev_end_pred_emergjetEta);
    h_ht0_hev_end_pred_emergjetEta->Add(h_ht600_hev_end_pred_emergjetEta);
    h_ht0_hev_end_pred_emergjetEta->Add(h_ht800_hev_end_pred_emergjetEta);
    h_ht0_hev_end_pred_emergjetEta->Add(h_ht1200_hev_end_pred_emergjetEta);
    h_ht0_hev_end_pred_emergjetEta->Add(h_ht2500_hev_end_pred_emergjetEta);

    h_ht0_hev_end_exp_emergjetEta->Add(h_ht70_hev_end_exp_emergjetEta);
    h_ht0_hev_end_exp_emergjetEta->Add(h_ht100_hev_end_exp_emergjetEta);
    h_ht0_hev_end_exp_emergjetEta->Add(h_ht200_hev_end_exp_emergjetEta);
    h_ht0_hev_end_exp_emergjetEta->Add(h_ht400_hev_end_exp_emergjetEta);
    h_ht0_hev_end_exp_emergjetEta->Add(h_ht600_hev_end_exp_emergjetEta);
    h_ht0_hev_end_exp_emergjetEta->Add(h_ht800_hev_end_exp_emergjetEta);
    h_ht0_hev_end_exp_emergjetEta->Add(h_ht1200_hev_end_exp_emergjetEta);
    h_ht0_hev_end_exp_emergjetEta->Add(h_ht2500_hev_end_exp_emergjetEta);

    h_ht0_light_end_pred_emergjetEta->Add(h_ht70_light_end_pred_emergjetEta);
    h_ht0_light_end_pred_emergjetEta->Add(h_ht100_light_end_pred_emergjetEta);
    h_ht0_light_end_pred_emergjetEta->Add(h_ht200_light_end_pred_emergjetEta);
    h_ht0_light_end_pred_emergjetEta->Add(h_ht400_light_end_pred_emergjetEta);
    h_ht0_light_end_pred_emergjetEta->Add(h_ht600_light_end_pred_emergjetEta);
    h_ht0_light_end_pred_emergjetEta->Add(h_ht800_light_end_pred_emergjetEta);
    h_ht0_light_end_pred_emergjetEta->Add(h_ht1200_light_end_pred_emergjetEta);
    h_ht0_light_end_pred_emergjetEta->Add(h_ht2500_light_end_pred_emergjetEta);

    h_ht0_light_end_exp_emergjetEta->Add(h_ht70_light_end_exp_emergjetEta);
    h_ht0_light_end_exp_emergjetEta->Add(h_ht100_light_end_exp_emergjetEta);
    h_ht0_light_end_exp_emergjetEta->Add(h_ht200_light_end_exp_emergjetEta);
    h_ht0_light_end_exp_emergjetEta->Add(h_ht400_light_end_exp_emergjetEta);
    h_ht0_light_end_exp_emergjetEta->Add(h_ht600_light_end_exp_emergjetEta);
    h_ht0_light_end_exp_emergjetEta->Add(h_ht800_light_end_exp_emergjetEta);
    h_ht0_light_end_exp_emergjetEta->Add(h_ht1200_light_end_exp_emergjetEta);
    h_ht0_light_end_exp_emergjetEta->Add(h_ht2500_light_end_exp_emergjetEta);

    h_ht0_hev_pred_emergjetpt->SetLineWidth(2);
    h_ht0_hev_exp_emergjetpt->SetLineWidth(2);

    h_ht0_light_pred_emergjetpt->SetLineWidth(2);
    h_ht0_light_exp_emergjetpt->SetLineWidth(2);

    h_ht0_hev_pred_emergjetnTrack->SetLineWidth(2);
    h_ht0_hev_exp_emergjetnTrack->SetLineWidth(2);

    h_ht0_light_pred_emergjetnTrack->SetLineWidth(2);
    h_ht0_light_exp_emergjetnTrack->SetLineWidth(2);

    h_ht0_hev_pred_emergjetEta->SetLineWidth(2);
    h_ht0_hev_exp_emergjetEta->SetLineWidth(2);

    h_ht0_light_pred_emergjetEta->SetLineWidth(2);
    h_ht0_light_exp_emergjetEta->SetLineWidth(2);

    h_ht0_hev_barr_pred_emergjetpt->SetLineWidth(2);
    h_ht0_hev_barr_exp_emergjetpt->SetLineWidth(2);

    h_ht0_light_barr_pred_emergjetpt->SetLineWidth(2);
    h_ht0_light_barr_exp_emergjetpt->SetLineWidth(2);

    h_ht0_hev_barr_pred_emergjetnTrack->SetLineWidth(2);
    h_ht0_hev_barr_exp_emergjetnTrack->SetLineWidth(2);

    h_ht0_light_barr_pred_emergjetnTrack->SetLineWidth(2);
    h_ht0_light_barr_exp_emergjetnTrack->SetLineWidth(2);

    h_ht0_hev_barr_pred_emergjetEta->SetLineWidth(2);
    h_ht0_hev_barr_exp_emergjetEta->SetLineWidth(2);

    h_ht0_light_barr_pred_emergjetEta->SetLineWidth(2);
    h_ht0_light_barr_exp_emergjetEta->SetLineWidth(2);

    h_ht0_hev_end_pred_emergjetpt->SetLineWidth(2);
    h_ht0_hev_end_exp_emergjetpt->SetLineWidth(2);

    h_ht0_light_end_pred_emergjetpt->SetLineWidth(2);
    h_ht0_light_end_exp_emergjetpt->SetLineWidth(2);

    h_ht0_hev_end_pred_emergjetnTrack->SetLineWidth(2);
    h_ht0_hev_end_exp_emergjetnTrack->SetLineWidth(2);

    h_ht0_light_end_pred_emergjetnTrack->SetLineWidth(2);
    h_ht0_light_end_exp_emergjetnTrack->SetLineWidth(2);

    h_ht0_hev_end_pred_emergjetEta->SetLineWidth(2);
    h_ht0_hev_end_exp_emergjetEta->SetLineWidth(2);

    h_ht0_light_end_pred_emergjetEta->SetLineWidth(2);
    h_ht0_light_end_exp_emergjetEta->SetLineWidth(2);

    h_ht0_hev_pred_emergjetpt->SetLineColor(kRed);
    h_ht0_light_pred_emergjetpt->SetLineColor(kRed);
    h_ht0_hev_pred_emergjetnTrack->SetLineColor(kRed);
    h_ht0_light_pred_emergjetnTrack->SetLineColor(kRed);
    h_ht0_hev_pred_emergjetEta->SetLineColor(kRed);
    h_ht0_light_pred_emergjetEta->SetLineColor(kRed);

    h_ht0_hev_barr_pred_emergjetpt->SetLineColor(kRed);
    h_ht0_light_barr_pred_emergjetpt->SetLineColor(kRed);
    h_ht0_hev_barr_pred_emergjetnTrack->SetLineColor(kRed);
    h_ht0_light_barr_pred_emergjetnTrack->SetLineColor(kRed);
    h_ht0_hev_barr_pred_emergjetEta->SetLineColor(kRed);
    h_ht0_light_barr_pred_emergjetEta->SetLineColor(kRed);

    h_ht0_hev_end_pred_emergjetpt->SetLineColor(kRed);
    h_ht0_light_end_pred_emergjetpt->SetLineColor(kRed);
    h_ht0_hev_end_pred_emergjetnTrack->SetLineColor(kRed);
    h_ht0_light_end_pred_emergjetnTrack->SetLineColor(kRed);
    h_ht0_hev_end_pred_emergjetEta->SetLineColor(kRed);
    h_ht0_light_end_pred_emergjetEta->SetLineColor(kRed);

    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(3, 2);
    c1->cd(1);
    /*
    h_ht0_hev_pred_emergjetpt->SetTitle("heavy");
    h_ht0_hev_pred_emergjetpt->GetXaxis()->SetTitle("Jet PT");
    h_ht0_hev_pred_emergjetpt->Draw("hist  e");
    h_ht0_hev_exp_emergjetpt->Draw("hist same e");
    TLegend *l0 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(h_ht0_hev_pred_emergjetpt, "Predict", "l");
    l0->AddEntry(h_ht0_hev_exp_emergjetpt, "expect", "l");
    l0->Draw();
    c1->cd(4);
    h_ht0_light_exp_emergjetpt->SetTitle("light");
    h_ht0_light_exp_emergjetpt->GetXaxis()->SetTitle("Jet PT");
    h_ht0_light_exp_emergjetpt->Draw("hist  e");
    h_ht0_light_pred_emergjetpt->Draw("hist same e");
    TLegend *l1 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_ht0_light_pred_emergjetpt, "Predict", "l");
    l1->AddEntry(h_ht0_light_exp_emergjetpt, "expect", "l");
    l1->Draw();
    c1->cd(2);
    h_ht0_hev_pred_emergjetnTrack->SetTitle("heavy");
    h_ht0_hev_pred_emergjetnTrack->GetXaxis()->SetTitle("Trackmultiplicity");
    h_ht0_hev_pred_emergjetnTrack->Draw("hist  e");
    h_ht0_hev_exp_emergjetnTrack->Draw("hist same e");
    TLegend *l2 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(h_ht0_hev_pred_emergjetnTrack, "Predict", "l");
    l2->AddEntry(h_ht0_hev_exp_emergjetnTrack, "expect", "l");
    l2->Draw();
    c1->cd(5);
    h_ht0_light_pred_emergjetnTrack->SetTitle("light");
    h_ht0_light_pred_emergjetnTrack->GetXaxis()->SetTitle("Trackmultiplicity");
    h_ht0_light_pred_emergjetnTrack->Draw("hist  e");
    h_ht0_light_exp_emergjetnTrack->Draw("hist same e");
    TLegend *l3 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.04);
    l3->AddEntry(h_ht0_light_pred_emergjetnTrack, "Predict", "l");
    l3->AddEntry(h_ht0_light_exp_emergjetnTrack, "expect", "l");
    l3->Draw();

    c1->cd(3);
    h_ht0_hev_pred_emergjetEta->SetTitle("heavy");
    h_ht0_hev_exp_emergjetEta->SetTitle("heavy");
    h_ht0_hev_pred_emergjetEta->GetXaxis()->SetTitle("Jet(#eta)");
    h_ht0_hev_exp_emergjetEta->GetXaxis()->SetTitle("Jet(#eta)");
    h_ht0_hev_exp_emergjetEta->Draw("hist  e");
    h_ht0_hev_pred_emergjetEta->Draw("hist same e");
    TLegend *l4 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.04);
    l4->AddEntry(h_ht0_hev_pred_emergjetEta, "Predict", "l");
    l4->AddEntry(h_ht0_hev_exp_emergjetEta, "expect", "l");
    l4->Draw();

    c1->cd(6);
    h_ht0_light_pred_emergjetEta->SetTitle("light");
    h_ht0_light_exp_emergjetEta->SetTitle("light");
    h_ht0_light_pred_emergjetEta->GetXaxis()->SetTitle("Jet(#eta)");
    h_ht0_light_exp_emergjetEta->GetXaxis()->SetTitle("Jet(#eta)");
    h_ht0_light_exp_emergjetEta->Draw("hist  e");
    h_ht0_light_pred_emergjetEta->Draw("hist same e");
    TLegend *l5 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l5->SetBorderSize(0);
    l5->SetTextSize(0.04);
    l5->AddEntry(h_ht0_light_pred_emergjetEta, "Predict", "l");
    l5->AddEntry(h_ht0_light_exp_emergjetEta, "expect", "l");
    l5->Draw();
    gStyle->SetOptStat(0);
    */
    h_ht0_hev_pred_emergjetpt->SetTitle("heavy");
    h_ht0_hev_pred_emergjetpt->GetXaxis()->SetTitle("Jet PT");
    h_ht0_hev_pred_emergjetpt->Draw("hist  e");
    h_ht0_hev_exp_emergjetpt->Draw("hist same e");
    TLegend *l0 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(h_ht0_hev_pred_emergjetpt, "Predict", "l");
    l0->AddEntry(h_ht0_hev_exp_emergjetpt, "expect", "l");
    l0->Draw();
    c1->cd(4);
    h_ht0_light_exp_emergjetpt->SetTitle("light");
    h_ht0_light_exp_emergjetpt->GetXaxis()->SetTitle("Jet PT");
    h_ht0_light_exp_emergjetpt->Draw("hist  e");
    h_ht0_light_pred_emergjetpt->Draw("hist same e");
    TLegend *l1 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_ht0_light_pred_emergjetpt, "Predict", "l");
    l1->AddEntry(h_ht0_light_exp_emergjetpt, "expect", "l");
    l1->Draw();
    c1->cd(2);
    h_ht0_hev_pred_emergjetnTrack->SetTitle("heavy");
    h_ht0_hev_pred_emergjetnTrack->GetXaxis()->SetTitle("Trackmultiplicity");
    h_ht0_hev_pred_emergjetnTrack->Draw("hist  e");
    h_ht0_hev_exp_emergjetnTrack->Draw("hist same e");
    TLegend *l2 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(h_ht0_hev_pred_emergjetnTrack, "Predict", "l");
    l2->AddEntry(h_ht0_hev_exp_emergjetnTrack, "expect", "l");
    l2->Draw();
    c1->cd(5);
    h_ht0_light_pred_emergjetnTrack->SetTitle("light");
    h_ht0_light_exp_emergjetnTrack->SetTitle("light");
    h_ht0_light_pred_emergjetnTrack->GetXaxis()->SetTitle("Trackmultiplicity");
    h_ht0_light_exp_emergjetnTrack->GetXaxis()->SetTitle("Trackmultiplicity");
    h_ht0_light_exp_emergjetnTrack->Draw("hist  e");
    h_ht0_light_pred_emergjetnTrack->Draw("hist same e");
    
    TLegend *l3 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.04);
    l3->AddEntry(h_ht0_light_pred_emergjetnTrack, "Predict", "l");
    l3->AddEntry(h_ht0_light_exp_emergjetnTrack, "expect", "l");
    l3->Draw();

    c1->cd(3);
    h_ht0_hev_pred_emergjetEta->SetTitle("heavy");
    h_ht0_hev_exp_emergjetEta->SetTitle("heavy");
    h_ht0_hev_pred_emergjetEta->GetXaxis()->SetTitle("Jet(#eta)");
    h_ht0_hev_exp_emergjetEta->GetXaxis()->SetTitle("Jet(#eta)");
      h_ht0_hev_pred_emergjetEta->Draw("hist  e");
    h_ht0_hev_exp_emergjetEta->Draw("hist same e");
  
    TLegend *l4 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.04);
    l4->AddEntry(h_ht0_hev_pred_emergjetEta, "Predict", "l");
    l4->AddEntry(h_ht0_hev_exp_emergjetEta, "expect", "l");
    l4->Draw();

    c1->cd(6);
    h_ht0_light_pred_emergjetEta->SetTitle("light");
    h_ht0_light_exp_emergjetEta->SetTitle("light");
    h_ht0_light_pred_emergjetEta->GetXaxis()->SetTitle("Jet(#eta)");
    h_ht0_light_exp_emergjetEta->GetXaxis()->SetTitle("Jet(#eta)");
    h_ht0_light_exp_emergjetEta->Draw("hist  e");
    h_ht0_light_pred_emergjetEta->Draw("hist same e");
    TLegend *l5 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l5->SetBorderSize(0);
    l5->SetTextSize(0.04);
    l5->AddEntry(h_ht0_light_pred_emergjetEta, "Predict", "l");
    l5->AddEntry(h_ht0_light_exp_emergjetEta, "expect", "l");
    l5->Draw();
    gStyle->SetOptStat(0);
}
