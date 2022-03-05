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
void ee_half_HT_fake_rate()
{
    TFile *DYincli = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");
    TFile *DYHT70 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

    TFile *DYincli_1 = new TFile("/mnt/c/Users/USER/Documents/ZtoLL_Plot/ana/ee/output/ee_DYincli_1.root");
    TFile *DYHT70_1 = new TFile("/mnt/c/Users/USER/Documents/ZtoLL_Plot/ana/ee/output/ee_ht70_1.root");
    TFile *DYHT100_1 = new TFile("/mnt/c/Users/USER/Documents/ZtoLL_Plot/ana/ee/output/ee_ht100_1.root");
    TFile *DYHT200_1 = new TFile("/mnt/c/Users/USER/Documents/ZtoLL_Plot/ana/ee/output/ee_ht200_1.root");
    TFile *DYHT400_1 = new TFile("/mnt/c/Users/USER/Documents/ZtoLL_Plot/ana/ee/output/ee_ht400_1.root");
    TFile *DYHT600_1 = new TFile("/mnt/c/Users/USER/Documents/ZtoLL_Plot/ana/ee/output/ee_ht600_1.root");
    TFile *DYHT800_1 = new TFile("/mnt/c/Users/USER/Documents/ZtoLL_Plot/ana/ee/output/ee_ht800_1.root");
    TFile *DYHT1200_1 = new TFile("/mnt/c/Users/USER/Documents/ZtoLL_Plot/ana/ee/output/ee_ht1200_1.root");
    TFile *DYHT2500_1 = new TFile("/mnt/c/Users/USER/Documents/ZtoLL_Plot/ana/ee/output/ee_ht2500_1.root");

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
    TH1F *h_ht0_hev_emergjetpt = new TH1F("h_ht0_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_hev_emergjetpt->Sumw2();
    TH1F *h_ht70_hev_emergjetpt = new TH1F("h_ht70_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_hev_emergjetpt->Sumw2();
    TH1F *h_ht100_hev_emergjetpt = new TH1F("h_ht100_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_hev_emergjetpt->Sumw2();
    TH1F *h_ht200_hev_emergjetpt = new TH1F("h_ht200_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_hev_emergjetpt->Sumw2();
    TH1F *h_ht400_hev_emergjetpt = new TH1F("h_ht400_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_hev_emergjetpt->Sumw2();
    TH1F *h_ht600_hev_emergjetpt = new TH1F("h_ht600_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_hev_emergjetpt->Sumw2();
    TH1F *h_ht800_hev_emergjetpt = new TH1F("h_ht800_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_hev_emergjetpt->Sumw2();
    TH1F *h_ht1200_hev_emergjetpt = new TH1F("h_ht1200_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_hev_emergjetpt->Sumw2();
    TH1F *h_ht2500_hev_emergjetpt = new TH1F("h_ht2500_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_hev_emergjetpt->Sumw2();

    TH1F *h_ht0_hev_emergjetpt_cutalpha = new TH1F("h_ht0_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht0_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht70_hev_emergjetpt_cutalpha = new TH1F("h_ht70_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht70_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht100_hev_emergjetpt_cutalpha = new TH1F("h_ht100_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht100_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht200_hev_emergjetpt_cutalpha = new TH1F("h_ht200_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht200_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht400_hev_emergjetpt_cutalpha = new TH1F("h_ht400_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht400_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht600_hev_emergjetpt_cutalpha = new TH1F("h_ht600_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht600_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht800_hev_emergjetpt_cutalpha = new TH1F("h_ht800_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht800_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht1200_hev_emergjetpt_cutalpha = new TH1F("h_ht1200_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht1200_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht2500_hev_emergjetpt_cutalpha = new TH1F("h_ht2500_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht2500_hev_emergjetpt_cutalpha->Sumw2();

    TH1F *h_ht0_light_emergjetpt = new TH1F("h_ht0_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht0_light_emergjetpt->Sumw2();
    TH1F *h_ht70_light_emergjetpt = new TH1F("h_ht70_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht70_light_emergjetpt->Sumw2();
    TH1F *h_ht100_light_emergjetpt = new TH1F("h_ht100_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht100_light_emergjetpt->Sumw2();
    TH1F *h_ht200_light_emergjetpt = new TH1F("h_ht200_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht200_light_emergjetpt->Sumw2();
    TH1F *h_ht400_light_emergjetpt = new TH1F("h_ht400_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht400_light_emergjetpt->Sumw2();
    TH1F *h_ht600_light_emergjetpt = new TH1F("h_ht600_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht600_light_emergjetpt->Sumw2();
    TH1F *h_ht800_light_emergjetpt = new TH1F("h_ht800_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht800_light_emergjetpt->Sumw2();
    TH1F *h_ht1200_light_emergjetpt = new TH1F("h_ht1200_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht1200_light_emergjetpt->Sumw2();
    TH1F *h_ht2500_light_emergjetpt = new TH1F("h_ht2500_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_ht2500_light_emergjetpt->Sumw2();

    TH1F *h_ht0_light_emergjetpt_cutalpha = new TH1F("h_ht0_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht0_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht70_light_emergjetpt_cutalpha = new TH1F("h_ht70_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht70_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht100_light_emergjetpt_cutalpha = new TH1F("h_ht100_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht100_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht200_light_emergjetpt_cutalpha = new TH1F("h_ht200_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht200_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht400_light_emergjetpt_cutalpha = new TH1F("h_ht400_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht400_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht600_light_emergjetpt_cutalpha = new TH1F("h_ht600_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht600_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht800_light_emergjetpt_cutalpha = new TH1F("h_ht800_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht800_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht1200_light_emergjetpt_cutalpha = new TH1F("h_ht1200_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht1200_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_ht2500_light_emergjetpt_cutalpha = new TH1F("h_ht2500_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_ht2500_light_emergjetpt_cutalpha->Sumw2();

    Double_t nbins[82] = {-4.889, -4.716, -4.538, -4.363, -4.191, -4.013, -3.839, -3.664, -3.489, -3.314, -3.139, -2.964, -2.853,
                          -2.65, -2.5, -2.322, -2.172, -2.043, -1.93, -1.83, -1.74, -1.653, -1.566, -1.479, -1.392, -1.305, -1.218, -1.131, -1.044,
                          -0.957, -0.879, -0.783, -0.696, -0.609, -0.522, -0.435, -0.348, -0.261, -0.174, -0.087, 0, 0.087, 0.174, 0.261, 0.348, 0.435,
                          0.522, 0.609, 0.696, 0.783, 0.879, 0.957, 1.044, 1.131, 1.218, 1.305, 1.392, 1.479, 1.566, 1.653, 1.74, 1.83, 1.93, 2.043, 2.172,
                          2.322, 2.5, 2.65, 2.853, 2.964, 3.139, 3.314, 3.489, 3.664, 3.839, 4.013, 4.191, 4.363, 4.538, 4.716, 4.889, 5.191};
    const Int_t nnbins = (sizeof(nbins) / sizeof(*nbins)) - 1;
    cout << nnbins << endl;
    TH1F *h_ht0_hev_emergjetEta = new TH1F("h_ht0_hev_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_hev_emergjetEta->Sumw2();
    TH1F *h_ht70_hev_emergjetEta = new TH1F("h_ht70_hev_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_hev_emergjetEta->Sumw2();
    TH1F *h_ht100_hev_emergjetEta = new TH1F("h_ht100_hev_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_hev_emergjetEta->Sumw2();
    TH1F *h_ht200_hev_emergjetEta = new TH1F("h_ht200_hev_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_hev_emergjetEta->Sumw2();
    TH1F *h_ht400_hev_emergjetEta = new TH1F("h_ht400_hev_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_hev_emergjetEta->Sumw2();
    TH1F *h_ht600_hev_emergjetEta = new TH1F("h_ht600_hev_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_hev_emergjetEta->Sumw2();
    TH1F *h_ht800_hev_emergjetEta = new TH1F("h_ht800_hev_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_hev_emergjetEta->Sumw2();
    TH1F *h_ht1200_hev_emergjetEta = new TH1F("h_ht1200_hev_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_hev_emergjetEta->Sumw2();
    TH1F *h_ht2500_hev_emergjetEta = new TH1F("h_ht2500_hev_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_hev_emergjetEta->Sumw2();

    TH1F *h_ht0_hev_emergjetEta_cutalpha = new TH1F("h_ht0_hev_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht0_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht70_hev_emergjetEta_cutalpha = new TH1F("h_ht70_hev_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht70_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht100_hev_emergjetEta_cutalpha = new TH1F("h_ht100_hev_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht100_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht200_hev_emergjetEta_cutalpha = new TH1F("h_ht200_hev_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht200_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht400_hev_emergjetEta_cutalpha = new TH1F("h_ht400_hev_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht400_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht600_hev_emergjetEta_cutalpha = new TH1F("h_ht600_hev_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht600_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht800_hev_emergjetEta_cutalpha = new TH1F("h_ht800_hev_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht800_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht1200_hev_emergjetEta_cutalpha = new TH1F("h_ht1200_hev_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht1200_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht2500_hev_emergjetEta_cutalpha = new TH1F("h_ht2500_hev_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht2500_hev_emergjetEta_cutalpha->Sumw2();

    TH1F *h_ht0_light_emergjetEta = new TH1F("h_ht0_light_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht0_light_emergjetEta->Sumw2();
    TH1F *h_ht70_light_emergjetEta = new TH1F("h_ht70_light_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht70_light_emergjetEta->Sumw2();
    TH1F *h_ht100_light_emergjetEta = new TH1F("h_ht100_light_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht100_light_emergjetEta->Sumw2();
    TH1F *h_ht200_light_emergjetEta = new TH1F("h_ht200_light_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht200_light_emergjetEta->Sumw2();
    TH1F *h_ht400_light_emergjetEta = new TH1F("h_ht400_light_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht400_light_emergjetEta->Sumw2();
    TH1F *h_ht600_light_emergjetEta = new TH1F("h_ht600_light_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht600_light_emergjetEta->Sumw2();
    TH1F *h_ht800_light_emergjetEta = new TH1F("h_ht800_light_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht800_light_emergjetEta->Sumw2();
    TH1F *h_ht1200_light_emergjetEta = new TH1F("h_ht1200_light_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht1200_light_emergjetEta->Sumw2();
    TH1F *h_ht2500_light_emergjetEta = new TH1F("h_ht2500_light_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_ht2500_light_emergjetEta->Sumw2();

    TH1F *h_ht0_light_emergjetEta_cutalpha = new TH1F("h_ht0_light_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht0_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht70_light_emergjetEta_cutalpha = new TH1F("h_ht70_light_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht70_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht100_light_emergjetEta_cutalpha = new TH1F("h_ht100_light_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht100_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht200_light_emergjetEta_cutalpha = new TH1F("h_ht200_light_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht200_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht400_light_emergjetEta_cutalpha = new TH1F("h_ht400_light_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht400_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht600_light_emergjetEta_cutalpha = new TH1F("h_ht600_light_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht600_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht800_light_emergjetEta_cutalpha = new TH1F("h_ht800_light_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht800_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht1200_light_emergjetEta_cutalpha = new TH1F("h_ht1200_light_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht1200_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_ht2500_light_emergjetEta_cutalpha = new TH1F("h_ht2500_light_emergjetEta_cutalpha", "emerging jet Eta", nnbins, nbins);
    h_ht2500_light_emergjetEta_cutalpha->Sumw2();

    TH1F *h_ht0_hev_emergjetnTrack = new TH1F("h_ht0_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_hev_emergjetnTrack->Sumw2();
    TH1F *h_ht70_hev_emergjetnTrack = new TH1F("h_ht70_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_hev_emergjetnTrack->Sumw2();
    TH1F *h_ht100_hev_emergjetnTrack = new TH1F("h_ht100_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_hev_emergjetnTrack->Sumw2();
    TH1F *h_ht200_hev_emergjetnTrack = new TH1F("h_ht200_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_hev_emergjetnTrack->Sumw2();
    TH1F *h_ht400_hev_emergjetnTrack = new TH1F("h_ht400_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_hev_emergjetnTrack->Sumw2();
    TH1F *h_ht600_hev_emergjetnTrack = new TH1F("h_ht600_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_hev_emergjetnTrack->Sumw2();
    TH1F *h_ht800_hev_emergjetnTrack = new TH1F("h_ht800_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_hev_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_hev_emergjetnTrack = new TH1F("h_ht1200_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_hev_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_hev_emergjetnTrack = new TH1F("h_ht2500_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_hev_emergjetnTrack->Sumw2();

    TH1F *h_ht0_hev_emergjetnTrack_cutalpha = new TH1F("h_ht0_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht0_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht70_hev_emergjetnTrack_cutalpha = new TH1F("h_ht70_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht70_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht100_hev_emergjetnTrack_cutalpha = new TH1F("h_ht100_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht100_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht200_hev_emergjetnTrack_cutalpha = new TH1F("h_ht200_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht200_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht400_hev_emergjetnTrack_cutalpha = new TH1F("h_ht400_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht400_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht600_hev_emergjetnTrack_cutalpha = new TH1F("h_ht600_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht600_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht800_hev_emergjetnTrack_cutalpha = new TH1F("h_ht800_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht800_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht1200_hev_emergjetnTrack_cutalpha = new TH1F("h_ht1200_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht2500_hev_emergjetnTrack_cutalpha = new TH1F("h_ht2500_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_hev_emergjetnTrack_cutalpha->Sumw2();

    TH1F *h_ht0_light_emergjetnTrack = new TH1F("h_ht0_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht0_light_emergjetnTrack->Sumw2();
    TH1F *h_ht70_light_emergjetnTrack = new TH1F("h_ht70_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht70_light_emergjetnTrack->Sumw2();
    TH1F *h_ht100_light_emergjetnTrack = new TH1F("h_ht100_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht100_light_emergjetnTrack->Sumw2();
    TH1F *h_ht200_light_emergjetnTrack = new TH1F("h_ht200_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht200_light_emergjetnTrack->Sumw2();
    TH1F *h_ht400_light_emergjetnTrack = new TH1F("h_ht400_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht400_light_emergjetnTrack->Sumw2();
    TH1F *h_ht600_light_emergjetnTrack = new TH1F("h_ht600_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht600_light_emergjetnTrack->Sumw2();
    TH1F *h_ht800_light_emergjetnTrack = new TH1F("h_ht800_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht800_light_emergjetnTrack->Sumw2();
    TH1F *h_ht1200_light_emergjetnTrack = new TH1F("h_ht1200_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_light_emergjetnTrack->Sumw2();
    TH1F *h_ht2500_light_emergjetnTrack = new TH1F("h_ht2500_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_light_emergjetnTrack->Sumw2();

    TH1F *h_ht0_light_emergjetnTrack_cutalpha = new TH1F("h_ht0_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht0_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht70_light_emergjetnTrack_cutalpha = new TH1F("h_ht70_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht70_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht100_light_emergjetnTrack_cutalpha = new TH1F("h_ht100_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht100_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht200_light_emergjetnTrack_cutalpha = new TH1F("h_ht200_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht200_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht400_light_emergjetnTrack_cutalpha = new TH1F("h_ht400_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht400_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht600_light_emergjetnTrack_cutalpha = new TH1F("h_ht600_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht600_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht800_light_emergjetnTrack_cutalpha = new TH1F("h_ht800_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht800_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht1200_light_emergjetnTrack_cutalpha = new TH1F("h_ht1200_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht1200_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_ht2500_light_emergjetnTrack_cutalpha = new TH1F("h_ht2500_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_ht2500_light_emergjetnTrack_cutalpha->Sumw2();

    TH1F *h_ht0_emergjethadronflavor = new TH1F("h_ht0_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_ht0_emergjethadronflavor->Sumw2();
    TH1F *h_ht70_emergjethadronflavor = new TH1F("h_ht70_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_ht70_emergjethadronflavor->Sumw2();
    TH1F *h_ht100_emergjethadronflavor = new TH1F("h_ht100_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_ht100_emergjethadronflavor->Sumw2();
    TH1F *h_ht200_emergjethadronflavor = new TH1F("h_ht200_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_ht200_emergjethadronflavor->Sumw2();
    TH1F *h_ht400_emergjethadronflavor = new TH1F("h_ht400_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_ht400_emergjethadronflavor->Sumw2();
    TH1F *h_ht600_emergjethadronflavor = new TH1F("h_ht600_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_ht600_emergjethadronflavor->Sumw2();
    TH1F *h_ht800_emergjethadronflavor = new TH1F("h_ht800_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_ht800_emergjethadronflavor->Sumw2();
    TH1F *h_ht1200_emergjethadronflavor = new TH1F("h_ht1200_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_ht1200_emergjethadronflavor->Sumw2();
    TH1F *h_ht2500_emergjethadronflavor = new TH1F("h_ht2500_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_ht2500_emergjethadronflavor->Sumw2();

    float_t HT;

    Double_t f_ht0_alphamin, f_ht70_alphamin, f_ht100_alphamin, f_ht200_alphamin, f_ht400_alphamin,
        f_ht600_alphamin, f_ht800_alphamin, f_ht1200_alphamin, f_ht2500_alphamin;
    float_t f_ht0_Met, f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;

    Int_t I_ht0_nThinJets, I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets, I_ht600_nThinJets,
        I_ht800_nThinJets, I_ht1200_nThinJets, I_ht2500_nThinJets;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
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
    DYincli_1->GetObject("h1", T_event);
    T_event->SetBranchAddress("I_weight", &I_ht0_weight);
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
            h_ht0_emergjethadronflavor->Fill((*v_ht0_Jethadronflavor)[i], I_ht0_weight * HT0Weight);
            if ((*v_ht0_Jethadronflavor)[i] == 4 || (*v_ht0_Jethadronflavor)[i] == 5)
            {
                if (HT < 70)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht0_hev_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                        h_ht0_hev_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                        h_ht0_hev_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht0_hev_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                        h_ht0_hev_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                        h_ht0_hev_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                    }
                }
                else if (HT >= 70 && HT < 100)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht70_hev_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                        h_ht70_hev_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                        h_ht70_hev_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht70_hev_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                        h_ht70_hev_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                        h_ht70_hev_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                    }
                }
                else if (HT >= 100 && HT < 200)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht100_hev_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                        h_ht100_hev_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                        h_ht100_hev_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht100_hev_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                        h_ht100_hev_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                        h_ht100_hev_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                    }
                }
                else if (HT >= 200 && HT < 400)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht200_hev_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                        h_ht200_hev_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                        h_ht200_hev_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht200_hev_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                        h_ht200_hev_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                        h_ht200_hev_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                    }
                }
                else if (HT >= 400 && HT < 600)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht400_hev_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                        h_ht400_hev_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                        h_ht400_hev_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht400_hev_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                        h_ht400_hev_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                        h_ht400_hev_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                    }
                }
                else if (HT >= 600 && HT < 800)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht600_hev_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                        h_ht600_hev_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                        h_ht600_hev_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht600_hev_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                        h_ht600_hev_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                        h_ht600_hev_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                    }
                }
                else if (HT >= 800 && HT < 1200)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht800_hev_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                        h_ht800_hev_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                        h_ht800_hev_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht800_hev_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                        h_ht800_hev_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                        h_ht800_hev_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                    }
                }
                else if (HT >= 1200 && HT < 2500)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht1200_hev_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                        h_ht1200_hev_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                        h_ht1200_hev_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht1200_hev_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                        h_ht1200_hev_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                        h_ht1200_hev_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                    }
                }
                else if (HT >= 2500)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht2500_hev_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                        h_ht2500_hev_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                        h_ht2500_hev_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht2500_hev_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                        h_ht2500_hev_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                        h_ht2500_hev_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                    }
                }
            }
            else
            {
                if (HT < 70)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht0_light_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                        h_ht0_light_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                        h_ht0_light_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht0_light_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT0Weight);
                        h_ht0_light_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT0Weight);
                        h_ht0_light_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT0Weight);
                    }
                }
                else if (HT >= 70 && HT < 100)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht70_light_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                        h_ht70_light_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                        h_ht70_light_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht70_light_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT70Weight);
                        h_ht70_light_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT70Weight);
                        h_ht70_light_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT70Weight);
                    }
                }
                else if (HT >= 100 && HT < 200)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht100_light_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                        h_ht100_light_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                        h_ht100_light_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht100_light_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT100Weight);
                        h_ht100_light_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT100Weight);
                        h_ht100_light_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT100Weight);
                    }
                }
                else if (HT >= 200 && HT < 400)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht200_light_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                        h_ht200_light_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                        h_ht200_light_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht200_light_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT200Weight);
                        h_ht200_light_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT200Weight);
                        h_ht200_light_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT200Weight);
                    }
                }
                else if (HT >= 400 && HT < 600)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht400_light_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                        h_ht400_light_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                        h_ht400_light_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht400_light_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT400Weight);
                        h_ht400_light_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT400Weight);
                        h_ht400_light_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT400Weight);
                    }
                }
                else if (HT >= 600 && HT < 800)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht600_light_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                        h_ht600_light_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                        h_ht600_light_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht600_light_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT600Weight);
                        h_ht600_light_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT600Weight);
                        h_ht600_light_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT600Weight);
                    }
                }
                else if (HT >= 800 && HT < 1200)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht800_light_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                        h_ht800_light_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                        h_ht800_light_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht800_light_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT800Weight);
                        h_ht800_light_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT800Weight);
                        h_ht800_light_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT800Weight);
                    }
                }
                else if (HT >= 1200 && HT < 2500)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht1200_light_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                        h_ht1200_light_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                        h_ht1200_light_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht1200_light_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT1200Weight);
                        h_ht1200_light_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT1200Weight);
                        h_ht1200_light_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT1200Weight);
                    }
                }
                else if (HT >= 2500)
                {
                    if (abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht2500_light_emergjetpt->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                        h_ht2500_light_emergjetEta->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                        h_ht2500_light_emergjetnTrack->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                    }
                    if ((*v_ht0_alpha)[i] <= 0.35 && abs((*v_ht0_JetEta)[i]) < 1.479)
                    {
                        h_ht2500_light_emergjetpt_cutalpha->Fill((*v_ht0_JetPT)[i], I_ht0_weight * HT2500Weight);
                        h_ht2500_light_emergjetEta_cutalpha->Fill((*v_ht0_JetEta)[i], I_ht0_weight * HT2500Weight);
                        h_ht2500_light_emergjetnTrack_cutalpha->Fill((*v_ht0_JetnTracks)[i], I_ht0_weight * HT2500Weight);
                    }
                }
            }
        }
    }
    TTree *T_event1;
    DYHT100_1->GetObject("h1", T_event1);
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
            h_ht100_emergjethadronflavor->Fill((*v_ht100_Jethadronflavor)[i], I_ht100_weight * HT100Weight);
            if ((*v_ht100_Jethadronflavor)[i] == 4 || (*v_ht100_Jethadronflavor)[i] == 5)
            {
                if (abs((*v_ht100_JetEta)[i]) < 1.479)
                {
                    h_ht100_hev_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_ht100_hev_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    h_ht100_hev_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                }
                if ((*v_ht100_alpha)[i] <= 0.35 && abs((*v_ht100_JetEta)[i]) < 1.479)
                {
                    h_ht100_hev_emergjetpt_cutalpha->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_ht100_hev_emergjetEta_cutalpha->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    h_ht100_hev_emergjetnTrack_cutalpha->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                }
            }
            else
            {
                if (abs((*v_ht100_JetEta)[i]) < 1.479)
                {
                    h_ht100_light_emergjetpt->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_ht100_light_emergjetEta->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    h_ht100_light_emergjetnTrack->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                }
                if ((*v_ht100_alpha)[i] <= 0.35 && abs((*v_ht100_JetEta)[i]) < 1.479)
                {
                    h_ht100_light_emergjetpt_cutalpha->Fill((*v_ht100_JetPT)[i], I_ht100_weight * HT100Weight);
                    h_ht100_light_emergjetEta_cutalpha->Fill((*v_ht100_JetEta)[i], I_ht100_weight * HT100Weight);
                    h_ht100_light_emergjetnTrack_cutalpha->Fill((*v_ht100_JetnTracks)[i], I_ht100_weight * HT100Weight);
                }
            }
        }
    }

    TTree *T_event2;
    DYHT200_1->GetObject("h1", T_event2);
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
            h_ht200_emergjethadronflavor->Fill((*v_ht200_Jethadronflavor)[i], I_ht200_weight * HT200Weight);
            if ((*v_ht200_Jethadronflavor)[i] == 4 || (*v_ht200_Jethadronflavor)[i] == 5)
            {
                if (abs((*v_ht200_JetEta)[i]) < 1.479)
                {
                    h_ht200_hev_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                    h_ht200_hev_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                    h_ht200_hev_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    if ((*v_ht200_alpha)[i] <= 0.35 && abs((*v_ht200_JetEta)[i]) < 1.479)
                    {
                        h_ht200_hev_emergjetpt_cutalpha->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_ht200_hev_emergjetEta_cutalpha->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                        h_ht200_hev_emergjetnTrack_cutalpha->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    }
                }
                else
                {
                    if (abs((*v_ht200_JetEta)[i]) < 1.479)
                    {
                        h_ht200_light_emergjetpt->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_ht200_light_emergjetEta->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                        h_ht200_light_emergjetnTrack->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    }
                    if ((*v_ht200_alpha)[i] <= 0.35 && abs((*v_ht200_JetEta)[i]) < 1.479)
                    {
                        h_ht200_light_emergjetpt_cutalpha->Fill((*v_ht200_JetPT)[i], I_ht200_weight * HT200Weight);
                        h_ht200_light_emergjetEta_cutalpha->Fill((*v_ht200_JetEta)[i], I_ht200_weight * HT200Weight);
                        h_ht200_light_emergjetnTrack_cutalpha->Fill((*v_ht200_JetnTracks)[i], I_ht200_weight * HT200Weight);
                    }
                }
            }
        }
    }
        TTree *T_event3;
        DYHT400_1->GetObject("h1", T_event3);
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
                h_ht400_emergjethadronflavor->Fill((*v_ht400_Jethadronflavor)[i], I_ht400_weight * HT400Weight);
                if ((*v_ht400_Jethadronflavor)[i] == 4 || (*v_ht400_Jethadronflavor)[i] == 5)
                {
                    if (abs((*v_ht400_JetEta)[i]) < 1.479)
                    {
                        h_ht400_hev_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_ht400_hev_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                        h_ht400_hev_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    }
                    if ((*v_ht400_alpha)[i] <= 0.35 && abs((*v_ht400_alpha)[i]) < 1.479)
                    {
                        h_ht400_hev_emergjetpt_cutalpha->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_ht400_hev_emergjetEta_cutalpha->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                        h_ht400_hev_emergjetnTrack_cutalpha->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    }
                }
                else
                {
                    if (abs((*v_ht400_JetEta)[i]) < 1.479)
                    {
                        h_ht400_light_emergjetpt->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_ht400_light_emergjetEta->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                        h_ht400_light_emergjetnTrack->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    }
                    if ((*v_ht400_alpha)[i] <= 0.35 && abs((*v_ht400_alpha)[i]) < 1.479)
                    {
                        h_ht400_light_emergjetpt_cutalpha->Fill((*v_ht400_JetPT)[i], I_ht400_weight * HT400Weight);
                        h_ht400_light_emergjetEta_cutalpha->Fill((*v_ht400_JetEta)[i], I_ht400_weight * HT400Weight);
                        h_ht400_light_emergjetnTrack_cutalpha->Fill((*v_ht400_JetnTracks)[i], I_ht400_weight * HT400Weight);
                    }
                }
            }
        }
        TTree *T_event4;
        DYHT600_1->GetObject("h1", T_event4);
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
                h_ht600_emergjethadronflavor->Fill((*v_ht600_Jethadronflavor)[i], I_ht600_weight * HT600Weight);
                if ((*v_ht600_Jethadronflavor)[i] == 4 || (*v_ht600_Jethadronflavor)[i] == 5)
                {
                    if (abs((*v_ht600_JetEta)[i]) < 1.479)
                    {
                        h_ht600_hev_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_ht600_hev_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                        h_ht600_hev_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    }
                    if ((*v_ht600_alpha)[i] <= 0.35 && abs((*v_ht600_JetEta)[i]) < 1.479)
                    {
                        h_ht600_hev_emergjetpt_cutalpha->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_ht600_hev_emergjetEta_cutalpha->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                        h_ht600_hev_emergjetnTrack_cutalpha->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    }
                }
                else
                {
                    if (abs((*v_ht600_JetEta)[i]) < 1.479)
                    {
                        h_ht600_light_emergjetpt->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_ht600_light_emergjetEta->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                        h_ht600_light_emergjetnTrack->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    }
                    if ((*v_ht600_alpha)[i] <= 0.35 && abs((*v_ht600_JetEta)[i]) < 1.479)
                    {
                        h_ht600_light_emergjetpt_cutalpha->Fill((*v_ht600_JetPT)[i], I_ht600_weight * HT600Weight);
                        h_ht600_light_emergjetEta_cutalpha->Fill((*v_ht600_JetEta)[i], I_ht600_weight * HT600Weight);
                        h_ht600_light_emergjetnTrack_cutalpha->Fill((*v_ht600_JetnTracks)[i], I_ht600_weight * HT600Weight);
                    }
                }
            }
        }

        TTree *T_event5;
        DYHT800_1->GetObject("h1", T_event5);
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
                h_ht800_emergjethadronflavor->Fill((*v_ht800_Jethadronflavor)[i], I_ht800_weight * HT800Weight);
                if ((*v_ht800_Jethadronflavor)[i] == 4 || (*v_ht800_Jethadronflavor)[i] == 5)
                {
                    if (abs((*v_ht800_JetEta)[i]) < 1.479)
                    {
                        h_ht800_hev_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_ht800_hev_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                        h_ht800_hev_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    }
                    if ((*v_ht800_alpha)[i] <= 0.35 && abs((*v_ht800_JetEta)[i]) < 1.479)
                    {
                        h_ht800_hev_emergjetpt_cutalpha->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_ht800_hev_emergjetEta_cutalpha->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                        h_ht800_hev_emergjetnTrack_cutalpha->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    }
                }
                else
                {
                    if (abs((*v_ht800_JetEta)[i]) < 1.479)
                    {
                        h_ht800_light_emergjetpt->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_ht800_light_emergjetEta->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                        h_ht800_light_emergjetnTrack->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    }
                    if ((*v_ht800_alpha)[i] <= 0.35 && abs((*v_ht800_JetEta)[i]) < 1.479)
                    {
                        h_ht800_light_emergjetpt_cutalpha->Fill((*v_ht800_JetPT)[i], I_ht800_weight * HT800Weight);
                        h_ht800_light_emergjetEta_cutalpha->Fill((*v_ht800_JetEta)[i], I_ht800_weight * HT800Weight);
                        h_ht800_light_emergjetnTrack_cutalpha->Fill((*v_ht800_JetnTracks)[i], I_ht800_weight * HT800Weight);
                    }
                }
            }
        }

        TTree *T_event6;
        DYHT1200_1->GetObject("h1", T_event6);
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
                h_ht1200_emergjethadronflavor->Fill((*v_ht1200_Jethadronflavor)[i], I_ht1200_weight * HT1200Weight);
                if ((*v_ht1200_Jethadronflavor)[i] == 4 || (*v_ht1200_Jethadronflavor)[i] == 5)
                {
                    if (abs((*v_ht1200_JetEta)[i]) < 1.479)
                    {
                        h_ht1200_hev_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_hev_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_hev_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    }
                    if ((*v_ht1200_alpha)[i] <= 0.35 && abs((*v_ht1200_JetEta)[i]) < 1.479)
                    {
                        h_ht1200_hev_emergjetpt_cutalpha->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_hev_emergjetEta_cutalpha->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_hev_emergjetnTrack_cutalpha->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    }
                }
                else
                {
                    if (abs((*v_ht1200_JetEta)[i]) < 1.479)
                    {
                        h_ht1200_light_emergjetpt->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_light_emergjetEta->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_light_emergjetnTrack->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    }
                    if ((*v_ht1200_alpha)[i] <= 0.35 && abs((*v_ht1200_JetEta)[i]) < 1.479)
                    {
                        h_ht1200_light_emergjetpt_cutalpha->Fill((*v_ht1200_JetPT)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_light_emergjetEta_cutalpha->Fill((*v_ht1200_JetEta)[i], I_ht1200_weight * HT1200Weight);
                        h_ht1200_light_emergjetnTrack_cutalpha->Fill((*v_ht1200_JetnTracks)[i], I_ht1200_weight * HT1200Weight);
                    }
                }
            }
        }

        TTree *T_event7;
        DYHT2500_1->GetObject("h1", T_event7);
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
                h_ht2500_emergjethadronflavor->Fill((*v_ht2500_Jethadronflavor)[i], I_ht2500_weight * HT2500Weight);
                if ((*v_ht2500_Jethadronflavor)[i] == 4 || (*v_ht2500_Jethadronflavor)[i] == 5)
                {
                    if (abs((*v_ht2500_JetEta)[i]) < 1.479)
                    {
                        h_ht2500_hev_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_hev_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_hev_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    }
                    if ((*v_ht2500_alpha)[i] <= 0.35 && abs((*v_ht2500_JetEta)[i]) < 1.479)
                    {
                        h_ht2500_hev_emergjetpt_cutalpha->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_hev_emergjetEta_cutalpha->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_hev_emergjetnTrack_cutalpha->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    }
                }
                else
                {
                    if (abs((*v_ht2500_JetEta)[i]) < 1.479)
                    {
                        h_ht2500_light_emergjetpt->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_light_emergjetEta->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_light_emergjetnTrack->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    }
                    if ((*v_ht2500_alpha)[i] <= 0.35 && abs((*v_ht2500_JetEta)[i]) < 1.479)
                    {
                        h_ht2500_light_emergjetpt_cutalpha->Fill((*v_ht2500_JetPT)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_light_emergjetEta_cutalpha->Fill((*v_ht2500_JetEta)[i], I_ht2500_weight * HT2500Weight);
                        h_ht2500_light_emergjetnTrack_cutalpha->Fill((*v_ht2500_JetnTracks)[i], I_ht2500_weight * HT2500Weight);
                    }
                }
            }
        }
        h_ht0_hev_emergjetpt->Add(h_ht70_hev_emergjetpt);
        h_ht0_hev_emergjetpt->Add(h_ht100_hev_emergjetpt);
        h_ht0_hev_emergjetpt->Add(h_ht200_hev_emergjetpt);
        h_ht0_hev_emergjetpt->Add(h_ht400_hev_emergjetpt);
        h_ht0_hev_emergjetpt->Add(h_ht600_hev_emergjetpt);
        h_ht0_hev_emergjetpt->Add(h_ht800_hev_emergjetpt);
        h_ht0_hev_emergjetpt->Add(h_ht1200_hev_emergjetpt);
        h_ht0_hev_emergjetpt->Add(h_ht2500_hev_emergjetpt);

        h_ht0_light_emergjetpt->Add(h_ht70_light_emergjetpt);
        h_ht0_light_emergjetpt->Add(h_ht100_light_emergjetpt);
        h_ht0_light_emergjetpt->Add(h_ht200_light_emergjetpt);
        h_ht0_light_emergjetpt->Add(h_ht400_light_emergjetpt);
        h_ht0_light_emergjetpt->Add(h_ht600_light_emergjetpt);
        h_ht0_light_emergjetpt->Add(h_ht800_light_emergjetpt);
        h_ht0_light_emergjetpt->Add(h_ht1200_light_emergjetpt);
        h_ht0_light_emergjetpt->Add(h_ht2500_light_emergjetpt);

        h_ht0_hev_emergjetpt_cutalpha->Add(h_ht70_hev_emergjetpt_cutalpha);
        h_ht0_hev_emergjetpt_cutalpha->Add(h_ht100_hev_emergjetpt_cutalpha);
        h_ht0_hev_emergjetpt_cutalpha->Add(h_ht200_hev_emergjetpt_cutalpha);
        h_ht0_hev_emergjetpt_cutalpha->Add(h_ht400_hev_emergjetpt_cutalpha);
        h_ht0_hev_emergjetpt_cutalpha->Add(h_ht600_hev_emergjetpt_cutalpha);
        h_ht0_hev_emergjetpt_cutalpha->Add(h_ht800_hev_emergjetpt_cutalpha);
        h_ht0_hev_emergjetpt_cutalpha->Add(h_ht1200_hev_emergjetpt_cutalpha);
        h_ht0_hev_emergjetpt_cutalpha->Add(h_ht2500_hev_emergjetpt_cutalpha);

        h_ht0_light_emergjetpt_cutalpha->Add(h_ht70_light_emergjetpt_cutalpha);
        h_ht0_light_emergjetpt_cutalpha->Add(h_ht100_light_emergjetpt_cutalpha);
        h_ht0_light_emergjetpt_cutalpha->Add(h_ht200_light_emergjetpt_cutalpha);
        h_ht0_light_emergjetpt_cutalpha->Add(h_ht400_light_emergjetpt_cutalpha);
        h_ht0_light_emergjetpt_cutalpha->Add(h_ht600_light_emergjetpt_cutalpha);
        h_ht0_light_emergjetpt_cutalpha->Add(h_ht800_light_emergjetpt_cutalpha);
        h_ht0_light_emergjetpt_cutalpha->Add(h_ht1200_light_emergjetpt_cutalpha);
        h_ht0_light_emergjetpt_cutalpha->Add(h_ht2500_light_emergjetpt_cutalpha);

        h_ht0_hev_emergjetEta->Add(h_ht70_hev_emergjetEta);
        h_ht0_hev_emergjetEta->Add(h_ht100_hev_emergjetEta);
        h_ht0_hev_emergjetEta->Add(h_ht200_hev_emergjetEta);
        h_ht0_hev_emergjetEta->Add(h_ht400_hev_emergjetEta);
        h_ht0_hev_emergjetEta->Add(h_ht600_hev_emergjetEta);
        h_ht0_hev_emergjetEta->Add(h_ht800_hev_emergjetEta);
        h_ht0_hev_emergjetEta->Add(h_ht1200_hev_emergjetEta);
        h_ht0_hev_emergjetEta->Add(h_ht2500_hev_emergjetEta);

        h_ht0_light_emergjetEta->Add(h_ht70_light_emergjetEta);
        h_ht0_light_emergjetEta->Add(h_ht100_light_emergjetEta);
        h_ht0_light_emergjetEta->Add(h_ht200_light_emergjetEta);
        h_ht0_light_emergjetEta->Add(h_ht400_light_emergjetEta);
        h_ht0_light_emergjetEta->Add(h_ht600_light_emergjetEta);
        h_ht0_light_emergjetEta->Add(h_ht800_light_emergjetEta);
        h_ht0_light_emergjetEta->Add(h_ht1200_light_emergjetEta);
        h_ht0_light_emergjetEta->Add(h_ht2500_light_emergjetEta);

        h_ht0_hev_emergjetEta_cutalpha->Add(h_ht70_hev_emergjetEta_cutalpha);
        h_ht0_hev_emergjetEta_cutalpha->Add(h_ht100_hev_emergjetEta_cutalpha);
        h_ht0_hev_emergjetEta_cutalpha->Add(h_ht200_hev_emergjetEta_cutalpha);
        h_ht0_hev_emergjetEta_cutalpha->Add(h_ht400_hev_emergjetEta_cutalpha);
        h_ht0_hev_emergjetEta_cutalpha->Add(h_ht600_hev_emergjetEta_cutalpha);
        h_ht0_hev_emergjetEta_cutalpha->Add(h_ht800_hev_emergjetEta_cutalpha);
        h_ht0_hev_emergjetEta_cutalpha->Add(h_ht1200_hev_emergjetEta_cutalpha);
        h_ht0_hev_emergjetEta_cutalpha->Add(h_ht2500_hev_emergjetEta_cutalpha);

        h_ht0_light_emergjetEta_cutalpha->Add(h_ht70_light_emergjetEta_cutalpha);
        h_ht0_light_emergjetEta_cutalpha->Add(h_ht100_light_emergjetEta_cutalpha);
        h_ht0_light_emergjetEta_cutalpha->Add(h_ht200_light_emergjetEta_cutalpha);
        h_ht0_light_emergjetEta_cutalpha->Add(h_ht400_light_emergjetEta_cutalpha);
        h_ht0_light_emergjetEta_cutalpha->Add(h_ht600_light_emergjetEta_cutalpha);
        h_ht0_light_emergjetEta_cutalpha->Add(h_ht800_light_emergjetEta_cutalpha);
        h_ht0_light_emergjetEta_cutalpha->Add(h_ht1200_light_emergjetEta_cutalpha);
        h_ht0_light_emergjetEta_cutalpha->Add(h_ht2500_light_emergjetEta_cutalpha);

        h_ht0_hev_emergjetnTrack->Add(h_ht70_hev_emergjetnTrack);
        h_ht0_hev_emergjetnTrack->Add(h_ht100_hev_emergjetnTrack);
        h_ht0_hev_emergjetnTrack->Add(h_ht200_hev_emergjetnTrack);
        h_ht0_hev_emergjetnTrack->Add(h_ht400_hev_emergjetnTrack);
        h_ht0_hev_emergjetnTrack->Add(h_ht600_hev_emergjetnTrack);
        h_ht0_hev_emergjetnTrack->Add(h_ht800_hev_emergjetnTrack);
        h_ht0_hev_emergjetnTrack->Add(h_ht1200_hev_emergjetnTrack);
        h_ht0_hev_emergjetnTrack->Add(h_ht2500_hev_emergjetnTrack);

        h_ht0_light_emergjetnTrack->Add(h_ht70_light_emergjetnTrack);
        h_ht0_light_emergjetnTrack->Add(h_ht100_light_emergjetnTrack);
        h_ht0_light_emergjetnTrack->Add(h_ht200_light_emergjetnTrack);
        h_ht0_light_emergjetnTrack->Add(h_ht400_light_emergjetnTrack);
        h_ht0_light_emergjetnTrack->Add(h_ht600_light_emergjetnTrack);
        h_ht0_light_emergjetnTrack->Add(h_ht800_light_emergjetnTrack);
        h_ht0_light_emergjetnTrack->Add(h_ht1200_light_emergjetnTrack);
        h_ht0_light_emergjetnTrack->Add(h_ht2500_light_emergjetnTrack);

        h_ht0_hev_emergjetnTrack_cutalpha->Add(h_ht70_hev_emergjetnTrack_cutalpha);
        h_ht0_hev_emergjetnTrack_cutalpha->Add(h_ht100_hev_emergjetnTrack_cutalpha);
        h_ht0_hev_emergjetnTrack_cutalpha->Add(h_ht200_hev_emergjetnTrack_cutalpha);
        h_ht0_hev_emergjetnTrack_cutalpha->Add(h_ht400_hev_emergjetnTrack_cutalpha);
        h_ht0_hev_emergjetnTrack_cutalpha->Add(h_ht600_hev_emergjetnTrack_cutalpha);
        h_ht0_hev_emergjetnTrack_cutalpha->Add(h_ht800_hev_emergjetnTrack_cutalpha);
        h_ht0_hev_emergjetnTrack_cutalpha->Add(h_ht1200_hev_emergjetnTrack_cutalpha);
        h_ht0_hev_emergjetnTrack_cutalpha->Add(h_ht2500_hev_emergjetnTrack_cutalpha);

        h_ht0_light_emergjetnTrack_cutalpha->Add(h_ht70_light_emergjetnTrack_cutalpha);
        h_ht0_light_emergjetnTrack_cutalpha->Add(h_ht100_light_emergjetnTrack_cutalpha);
        h_ht0_light_emergjetnTrack_cutalpha->Add(h_ht200_light_emergjetnTrack_cutalpha);
        h_ht0_light_emergjetnTrack_cutalpha->Add(h_ht400_light_emergjetnTrack_cutalpha);
        h_ht0_light_emergjetnTrack_cutalpha->Add(h_ht600_light_emergjetnTrack_cutalpha);
        h_ht0_light_emergjetnTrack_cutalpha->Add(h_ht800_light_emergjetnTrack_cutalpha);
        h_ht0_light_emergjetnTrack_cutalpha->Add(h_ht1200_light_emergjetnTrack_cutalpha);
        h_ht0_light_emergjetnTrack_cutalpha->Add(h_ht2500_light_emergjetnTrack_cutalpha);

        h_ht0_emergjethadronflavor->Add(h_ht70_emergjethadronflavor);
        h_ht0_emergjethadronflavor->Add(h_ht100_emergjethadronflavor);
        h_ht0_emergjethadronflavor->Add(h_ht200_emergjethadronflavor);
        h_ht0_emergjethadronflavor->Add(h_ht400_emergjethadronflavor);
        h_ht0_emergjethadronflavor->Add(h_ht600_emergjethadronflavor);
        h_ht0_emergjethadronflavor->Add(h_ht800_emergjethadronflavor);
        h_ht0_emergjethadronflavor->Add(h_ht1200_emergjethadronflavor);
        h_ht0_emergjethadronflavor->Add(h_ht2500_emergjethadronflavor);
        TFile *outFile = new TFile("./../../../root_file/BgEstimation/DYHT_fakerateStudy.root", "RECREATE");
        outFile->cd();
        h_ht0_hev_emergjetpt->Write();
        h_ht0_light_emergjetpt->Write();
        h_ht0_hev_emergjetpt_cutalpha->Write();
        h_ht0_light_emergjetpt_cutalpha->Write();
        h_ht0_hev_emergjetEta->Write();
        h_ht0_light_emergjetEta->Write();
        h_ht0_hev_emergjetEta_cutalpha->Write();
        h_ht0_light_emergjetEta_cutalpha->Write();
        h_ht0_hev_emergjetnTrack->Write();
        h_ht0_light_emergjetnTrack->Write();
        h_ht0_hev_emergjetnTrack_cutalpha->Write();
        h_ht0_light_emergjetnTrack_cutalpha->Write();
        h_ht0_emergjethadronflavor->Write();
        outFile->Close();
    }
