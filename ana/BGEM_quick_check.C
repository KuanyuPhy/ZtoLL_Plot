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
#include "./lib/Cross_section.h"
using namespace RooFit;

Double_t background(Double_t x)
{
    Double_t weight = (TMath::Exp(2.929 + (-0.01548) * x) + 0.0299);
    return weight;
}

void BGEM_quick_check()
{

    TFile *DYincli = new TFile("./../../root_file/Ztoee/ee_DYincli.root");

    TFile *DYHT70 = new TFile("./../../root_file/Ztoee/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../root_file/Ztoee/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../root_file/Ztoee/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../root_file/Ztoee/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../root_file/Ztoee/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../root_file/Ztoee/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../root_file/Ztoee/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../root_file/Ztoee/ee_ht2500.root");

    TFile *ABCDRatio = new TFile("./../../ABCD_fit.root");

    TH1D *h_Ratio = ((TH1D *)ABCDRatio->Get("h_ht0A_met"));

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("h_HT_eventCout"));

    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("h_event"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("h_event"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("h_event"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("h_event"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("h_event"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("h_event"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("h_event"));

    int DYHT100_totevt = DYHT100_sumevt->GetEntries();
    int DYHT200_totevt = DYHT200_sumevt->GetEntries();
    int DYHT400_totevt = DYHT400_sumevt->GetEntries();
    int DYHT600_totevt = DYHT600_sumevt->GetEntries();
    int DYHT800_totevt = DYHT800_sumevt->GetEntries();
    int DYHT1200_totevt = DYHT1200_sumevt->GetEntries();
    int DYHT2500_totevt = DYHT2500_sumevt->GetEntries();

    int HT0_70_event = h_HT_eventCout->GetBinContent(2);
    int HT70_100_event = h_HT_eventCout->GetBinContent(3);
    int HT100_200_event = h_HT_eventCout->GetBinContent(4);
    int HT200_400_event = h_HT_eventCout->GetBinContent(5);
    int HT400_600_event = h_HT_eventCout->GetBinContent(6);
    int HT600_800_event = h_HT_eventCout->GetBinContent(7);
    int HT800_1200_event = h_HT_eventCout->GetBinContent(8);
    int HT1200_2500_event = h_HT_eventCout->GetBinContent(9);
    int HT2500_Inf_event = h_HT_eventCout->GetBinContent(10);

    // DYHT
    TH1F *h_ht0A_jetpt = new TH1F("h_ht0A_jetpt", "", 100, 0, 1000);
    h_ht0A_jetpt->Sumw2();
    TH1F *h_ht0B_jetpt = new TH1F("h_ht0B_jetpt", "", 100, 0, 1000);
    h_ht0B_jetpt->Sumw2();
    TH1F *h_ht0C_jetpt = new TH1F("h_ht0C_jetpt", "", 100, 0, 1000);
    h_ht0C_jetpt->Sumw2();
    TH1F *h_ht0D_jetpt = new TH1F("h_ht0D_jetpt", "", 100, 0, 1000);
    h_ht0D_jetpt->Sumw2();

    TH1F *h_ht70A_jetpt = new TH1F("h_ht70A_jetpt", "", 100, 0, 1000);
    h_ht70A_jetpt->Sumw2();
    TH1F *h_ht70B_jetpt = new TH1F("h_ht70B_jetpt", "", 100, 0, 1000);
    h_ht70B_jetpt->Sumw2();
    TH1F *h_ht70C_jetpt = new TH1F("h_ht70C_jetpt", "", 100, 0, 1000);
    h_ht70C_jetpt->Sumw2();
    TH1F *h_ht70D_jetpt = new TH1F("h_ht70D_jetpt", "", 100, 0, 1000);
    h_ht70D_jetpt->Sumw2();

    TH1F *h_ht100A_jetpt = new TH1F("h_ht100A_jetpt", "", 100, 0, 1000);
    h_ht100A_jetpt->Sumw2();
    TH1F *h_ht100B_jetpt = new TH1F("h_ht100B_jetpt", "", 100, 0, 1000);
    h_ht100B_jetpt->Sumw2();
    TH1F *h_ht100C_jetpt = new TH1F("h_ht100C_jetpt", "", 100, 0, 1000);
    h_ht100C_jetpt->Sumw2();
    TH1F *h_ht100D_jetpt = new TH1F("h_ht100D_jetpt", "", 100, 0, 1000);
    h_ht100D_jetpt->Sumw2();

    TH1F *h_ht200A_jetpt = new TH1F("h_ht200A_jetpt", "", 100, 0, 1000);
    h_ht200A_jetpt->Sumw2();
    TH1F *h_ht200B_jetpt = new TH1F("h_ht200B_jetpt", "", 100, 0, 1000);
    h_ht200B_jetpt->Sumw2();
    TH1F *h_ht200C_jetpt = new TH1F("h_ht200C_jetpt", "", 100, 0, 1000);
    h_ht200C_jetpt->Sumw2();
    TH1F *h_ht200D_jetpt = new TH1F("h_ht200D_jetpt", "", 100, 0, 1000);
    h_ht200D_jetpt->Sumw2();

    TH1F *h_ht400A_jetpt = new TH1F("h_ht400A_jetpt", "", 100, 0, 1000);
    h_ht400A_jetpt->Sumw2();
    TH1F *h_ht400B_jetpt = new TH1F("h_ht400B_jetpt", "", 100, 0, 1000);
    h_ht400B_jetpt->Sumw2();
    TH1F *h_ht400C_jetpt = new TH1F("h_ht400C_jetpt", "", 100, 0, 1000);
    h_ht400C_jetpt->Sumw2();
    TH1F *h_ht400D_jetpt = new TH1F("h_ht400D_jetpt", "", 100, 0, 1000);
    h_ht400D_jetpt->Sumw2();

    TH1F *h_ht600A_jetpt = new TH1F("h_ht600A_jetpt", "", 100, 0, 1000);
    h_ht600A_jetpt->Sumw2();
    TH1F *h_ht600B_jetpt = new TH1F("h_ht600B_jetpt", "", 100, 0, 1000);
    h_ht600B_jetpt->Sumw2();
    TH1F *h_ht600C_jetpt = new TH1F("h_ht600C_jetpt", "", 100, 0, 1000);
    h_ht600C_jetpt->Sumw2();
    TH1F *h_ht600D_jetpt = new TH1F("h_ht600D_jetpt", "", 100, 0, 1000);
    h_ht600D_jetpt->Sumw2();

    TH1F *h_ht800A_jetpt = new TH1F("h_ht800A_jetpt", "", 100, 0, 1000);
    h_ht800A_jetpt->Sumw2();
    TH1F *h_ht800B_jetpt = new TH1F("h_ht800B_jetpt", "", 100, 0, 1000);
    h_ht800B_jetpt->Sumw2();
    TH1F *h_ht800C_jetpt = new TH1F("h_ht800C_jetpt", "", 100, 0, 1000);
    h_ht800C_jetpt->Sumw2();
    TH1F *h_ht800D_jetpt = new TH1F("h_ht800D_jetpt", "", 100, 0, 1000);
    h_ht800D_jetpt->Sumw2();

    TH1F *h_ht1200A_jetpt = new TH1F("h_ht1200A_jetpt", "", 100, 0, 1000);
    h_ht1200A_jetpt->Sumw2();
    TH1F *h_ht1200B_jetpt = new TH1F("h_ht1200B_jetpt", "", 100, 0, 1000);
    h_ht1200B_jetpt->Sumw2();
    TH1F *h_ht1200C_jetpt = new TH1F("h_ht1200C_jetpt", "", 100, 0, 1000);
    h_ht1200C_jetpt->Sumw2();
    TH1F *h_ht1200D_jetpt = new TH1F("h_ht1200D_jetpt", "", 100, 0, 1000);
    h_ht1200D_jetpt->Sumw2();

    TH1F *h_ht2500A_jetpt = new TH1F("h_ht2500A_jetpt", "", 100, 0, 1000);
    h_ht2500A_jetpt->Sumw2();
    TH1F *h_ht2500B_jetpt = new TH1F("h_ht2500B_jetpt", "", 100, 0, 1000);
    h_ht2500B_jetpt->Sumw2();
    TH1F *h_ht2500C_jetpt = new TH1F("h_ht2500C_jetpt", "", 100, 0, 1000);
    h_ht2500C_jetpt->Sumw2();
    TH1F *h_ht2500D_jetpt = new TH1F("h_ht2500D_jetpt", "", 100, 0, 1000);
    h_ht2500D_jetpt->Sumw2();

    TH1D *h_ht0A_jeteta = new TH1D("h_ht0A_jeteta", "eta jets", 10, -5, 5);
    h_ht0A_jeteta->Sumw2();
    TH1F *h_ht0B_jeteta = new TH1F("h_ht0B_jeteta", "eta jets", 10, -5, 5);
    h_ht0B_jeteta->Sumw2();
    TH1F *h_ht0C_jeteta = new TH1F("h_ht0C_jeteta", "eta jets", 10, -5, 5);
    h_ht0C_jeteta->Sumw2();
    TH1F *h_ht0D_jeteta = new TH1F("h_ht0D_jeteta", "eta jets", 10, -5, 5);
    h_ht0D_jeteta->Sumw2();

    TH1D *h_ht70A_jeteta = new TH1D("h_ht70A_jeteta", "eta jets", 10, -5, 5);
    h_ht70A_jeteta->Sumw2();
    TH1F *h_ht70B_jeteta = new TH1F("h_ht70B_jeteta", "eta jets", 10, -5, 5);
    h_ht70B_jeteta->Sumw2();
    TH1F *h_ht70C_jeteta = new TH1F("h_ht70C_jeteta", "eta jets", 10, -5, 5);
    h_ht70C_jeteta->Sumw2();
    TH1F *h_ht70D_jeteta = new TH1F("h_ht70D_jeteta", "eta jets", 10, -5, 5);
    h_ht70D_jeteta->Sumw2();

    TH1D *h_ht100A_jeteta = new TH1D("h_ht100A_jeteta", "eta jets", 10, -5, 5);
    h_ht100A_jeteta->Sumw2();
    TH1F *h_ht100B_jeteta = new TH1F("h_ht100B_jeteta", "eta jets", 10, -5, 5);
    h_ht100B_jeteta->Sumw2();
    TH1F *h_ht100C_jeteta = new TH1F("h_ht100C_jeteta", "eta jets", 10, -5, 5);
    h_ht100C_jeteta->Sumw2();
    TH1F *h_ht100D_jeteta = new TH1F("h_ht100D_jeteta", "eta jets", 10, -5, 5);
    h_ht100D_jeteta->Sumw2();

    TH1D *h_ht200A_jeteta = new TH1D("h_ht200A_jeteta", "eta jets", 10, -5, 5);
    h_ht200A_jeteta->Sumw2();
    TH1F *h_ht200B_jeteta = new TH1F("h_ht200B_jeteta", "eta jets", 10, -5, 5);
    h_ht200B_jeteta->Sumw2();
    TH1F *h_ht200C_jeteta = new TH1F("h_ht200C_jeteta", "eta jets", 10, -5, 5);
    h_ht200C_jeteta->Sumw2();
    TH1F *h_ht200D_jeteta = new TH1F("h_ht200D_jeteta", "eta jets", 10, -5, 5);
    h_ht200D_jeteta->Sumw2();

    TH1D *h_ht400A_jeteta = new TH1D("h_ht400A_jeteta", "eta jets", 10, -5, 5);
    h_ht400A_jeteta->Sumw2();
    TH1F *h_ht400B_jeteta = new TH1F("h_ht400B_jeteta", "eta jets", 10, -5, 5);
    h_ht400B_jeteta->Sumw2();
    TH1F *h_ht400C_jeteta = new TH1F("h_ht400C_jeteta", "eta jets", 10, -5, 5);
    h_ht400C_jeteta->Sumw2();
    TH1F *h_ht400D_jeteta = new TH1F("h_ht400D_jeteta", "eta jets", 10, -5, 5);
    h_ht400D_jeteta->Sumw2();

    TH1D *h_ht600A_jeteta = new TH1D("h_ht600A_jeteta", "eta jets", 10, -5, 5);
    h_ht600A_jeteta->Sumw2();
    TH1F *h_ht600B_jeteta = new TH1F("h_ht600B_jeteta", "eta jets", 10, -5, 5);
    h_ht600B_jeteta->Sumw2();
    TH1F *h_ht600C_jeteta = new TH1F("h_ht600C_jeteta", "eta jets", 10, -5, 5);
    h_ht600C_jeteta->Sumw2();
    TH1F *h_ht600D_jeteta = new TH1F("h_ht600D_jeteta", "eta jets", 10, -5, 5);
    h_ht600D_jeteta->Sumw2();

    TH1D *h_ht800A_jeteta = new TH1D("h_ht800A_jeteta", "eta jets", 10, -5, 5);
    h_ht800A_jeteta->Sumw2();
    TH1F *h_ht800B_jeteta = new TH1F("h_ht800B_jeteta", "eta jets", 10, -5, 5);
    h_ht800B_jeteta->Sumw2();
    TH1F *h_ht800C_jeteta = new TH1F("h_ht800C_jeteta", "eta jets", 10, -5, 5);
    h_ht800C_jeteta->Sumw2();
    TH1F *h_ht800D_jeteta = new TH1F("h_ht800D_jeteta", "eta jets", 10, -5, 5);
    h_ht800D_jeteta->Sumw2();

    TH1D *h_ht1200A_jeteta = new TH1D("h_ht1200A_jeteta", "eta jets", 10, -5, 5);
    h_ht1200A_jeteta->Sumw2();
    TH1F *h_ht1200B_jeteta = new TH1F("h_ht1200B_jeteta", "eta jets", 10, -5, 5);
    h_ht1200B_jeteta->Sumw2();
    TH1F *h_ht1200C_jeteta = new TH1F("h_ht1200C_jeteta", "eta jets", 10, -5, 5);
    h_ht1200C_jeteta->Sumw2();
    TH1F *h_ht1200D_jeteta = new TH1F("h_ht1200D_jeteta", "eta jets", 10, -5, 5);
    h_ht1200D_jeteta->Sumw2();

    TH1D *h_ht2500A_jeteta = new TH1D("h_ht2500A_jeteta", "eta jets", 10, -5, 5);
    h_ht2500A_jeteta->Sumw2();
    TH1F *h_ht2500B_jeteta = new TH1F("h_ht2500B_jeteta", "eta jets", 10, -5, 5);
    h_ht2500B_jeteta->Sumw2();
    TH1F *h_ht2500C_jeteta = new TH1F("h_ht2500C_jeteta", "eta jets", 10, -5, 5);
    h_ht2500C_jeteta->Sumw2();
    TH1F *h_ht2500D_jeteta = new TH1F("h_ht2500D_jeteta", "eta jets", 10, -5, 5);
    h_ht2500D_jeteta->Sumw2();

    TH1D *h_ht0A_jetmet = new TH1D("h_ht0A_jetmet", "jet Met", 10, 0, 1000);
    h_ht0A_jetmet->Sumw2();
    TH1F *h_ht0B_jetmet = new TH1F("h_ht0B_jetmet", "jet Met", 10, 0, 1000);
    h_ht0B_jetmet->Sumw2();
    TH1F *h_ht0C_jetmet = new TH1F("h_ht0C_jetmet", "jet Met", 10, 0, 1000);
    h_ht0C_jetmet->Sumw2();
    TH1F *h_ht0D_jetmet = new TH1F("h_ht0D_jetmet", "jet Met", 10, 0, 1000);
    h_ht0D_jetmet->Sumw2();

    TH1D *h_ht70A_jetmet = new TH1D("h_ht70A_jetmet", "jet Met", 10, 0, 1000);
    h_ht70A_jetmet->Sumw2();
    TH1F *h_ht70B_jetmet = new TH1F("h_ht70B_jetmet", "jet Met", 10, 0, 1000);
    h_ht70B_jetmet->Sumw2();
    TH1F *h_ht70C_jetmet = new TH1F("h_ht70C_jetmet", "jet Met", 10, 0, 1000);
    h_ht70C_jetmet->Sumw2();
    TH1F *h_ht70D_jetmet = new TH1F("h_ht70D_jetmet", "jet Met", 10, 0, 1000);
    h_ht70D_jetmet->Sumw2();

    TH1D *h_ht100A_jetmet = new TH1D("h_ht100A_jetmet", "jet Met", 10, 0, 1000);
    h_ht100A_jetmet->Sumw2();
    TH1F *h_ht100B_jetmet = new TH1F("h_ht100B_jetmet", "jet Met", 10, 0, 1000);
    h_ht100B_jetmet->Sumw2();
    TH1F *h_ht100C_jetmet = new TH1F("h_ht100C_jetmet", "jet Met", 10, 0, 1000);
    h_ht100C_jetmet->Sumw2();
    TH1F *h_ht100D_jetmet = new TH1F("h_ht100D_jetmet", "jet Met", 10, 0, 1000);
    h_ht100D_jetmet->Sumw2();

    TH1D *h_ht200A_jetmet = new TH1D("h_ht200A_jetmet", "jet Met", 10, 0, 1000);
    h_ht200A_jetmet->Sumw2();
    TH1F *h_ht200B_jetmet = new TH1F("h_ht200B_jetmet", "jet Met", 10, 0, 1000);
    h_ht200B_jetmet->Sumw2();
    TH1F *h_ht200C_jetmet = new TH1F("h_ht200C_jetmet", "jet Met", 10, 0, 1000);
    h_ht200C_jetmet->Sumw2();
    TH1F *h_ht200D_jetmet = new TH1F("h_ht200D_jetmet", "jet Met", 10, 0, 1000);
    h_ht200D_jetmet->Sumw2();

    TH1D *h_ht400A_jetmet = new TH1D("h_ht400A_jetmet", "jet Met", 10, 0, 1000);
    h_ht400A_jetmet->Sumw2();
    TH1F *h_ht400B_jetmet = new TH1F("h_ht400B_jetmet", "jet Met", 10, 0, 1000);
    h_ht400B_jetmet->Sumw2();
    TH1F *h_ht400C_jetmet = new TH1F("h_ht400C_jetmet", "jet Met", 10, 0, 1000);
    h_ht400C_jetmet->Sumw2();
    TH1F *h_ht400D_jetmet = new TH1F("h_ht400D_jetmet", "jet Met", 10, 0, 1000);
    h_ht400D_jetmet->Sumw2();

    TH1D *h_ht600A_jetmet = new TH1D("h_ht600A_jetmet", "jet Met", 10, 0, 1000);
    h_ht600A_jetmet->Sumw2();
    TH1F *h_ht600B_jetmet = new TH1F("h_ht600B_jetmet", "jet Met", 10, 0, 1000);
    h_ht600B_jetmet->Sumw2();
    TH1F *h_ht600C_jetmet = new TH1F("h_ht600C_jetmet", "jet Met", 10, 0, 1000);
    h_ht600C_jetmet->Sumw2();
    TH1F *h_ht600D_jetmet = new TH1F("h_ht600D_jetmet", "jet Met", 10, 0, 1000);
    h_ht600D_jetmet->Sumw2();

    TH1D *h_ht800A_jetmet = new TH1D("h_ht800A_jetmet", "jet Met", 10, 0, 1000);
    h_ht800A_jetmet->Sumw2();
    TH1F *h_ht800B_jetmet = new TH1F("h_ht800B_jetmet", "jet Met", 10, 0, 1000);
    h_ht800B_jetmet->Sumw2();
    TH1F *h_ht800C_jetmet = new TH1F("h_ht800C_jetmet", "jet Met", 10, 0, 1000);
    h_ht800C_jetmet->Sumw2();
    TH1F *h_ht800D_jetmet = new TH1F("h_ht800D_jetmet", "jet Met", 10, 0, 1000);
    h_ht800D_jetmet->Sumw2();

    TH1D *h_ht1200A_jetmet = new TH1D("h_ht1200A_jetmet", "jet Met", 10, 0, 1000);
    h_ht1200A_jetmet->Sumw2();
    TH1F *h_ht1200B_jetmet = new TH1F("h_ht1200B_jetmet", "jet Met", 10, 0, 1000);
    h_ht1200B_jetmet->Sumw2();
    TH1F *h_ht1200C_jetmet = new TH1F("h_ht1200C_jetmet", "jet Met", 10, 0, 1000);
    h_ht1200C_jetmet->Sumw2();
    TH1F *h_ht1200D_jetmet = new TH1F("h_ht1200D_jetmet", "jet Met", 10, 0, 1000);
    h_ht1200D_jetmet->Sumw2();

    TH1D *h_ht2500A_jetmet = new TH1D("h_ht2500A_jetmet", "jet Met", 10, 0, 1000);
    h_ht2500A_jetmet->Sumw2();
    TH1F *h_ht2500B_jetmet = new TH1F("h_ht2500B_jetmet", "jet Met", 10, 0, 1000);
    h_ht2500B_jetmet->Sumw2();
    TH1F *h_ht2500C_jetmet = new TH1F("h_ht2500C_jetmet", "jet Met", 10, 0, 1000);
    h_ht2500C_jetmet->Sumw2();
    TH1F *h_ht2500D_jetmet = new TH1F("h_ht2500D_jetmet", "jet Met", 10, 0, 1000);
    h_ht2500D_jetmet->Sumw2();

    // Define the HTWeight
    /*
    float HT0Weight = 35.9 * ((4609.090666) / (HT0_70_event)) * 1000;
    float HT70Weight = 35.9 * ((4609.090666) / (HT0_70_event)) * 1000;
    float HT100Weight = 35.9 * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000;
    float HT200Weight = 35.9 * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000;
    float HT400Weight = 35.9 * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000;
    float HT600Weight = 35.9 * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000;
    float HT800Weight = 35.9 * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000;
    float HT1200Weight = 35.9 * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000;
    float HT2500Weight = 35.9 * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000;
*/
    float HT0Weight = 1;
    float HT70Weight = 1;
    float HT100Weight = 1;
    float HT200Weight = 1;
    float HT400Weight = 1;
    float HT600Weight = 1;
    float HT800Weight = 1;
    float HT1200Weight = 1;
    float HT2500Weight = 1;
    float_t HT;

    Double_t f_ht70_alphamin, f_ht100_alphamin, f_ht200_alphamin, f_ht400_alphamin,
        f_ht600_alphamin, f_ht800_alphamin, f_ht1200_alphamin, f_ht2500_alphamin;
    float_t f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;
    Int_t I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    float_t HT0met;

    Double_t HT0alphamin;
    Int_t HT0eventWeight;

    std::vector<Float_t> *HT0_matchJet_PT = new std::vector<Float_t>();
    std::vector<Float_t> *HT0_matchJet_eta = new std::vector<Float_t>();

    TTree *T_event;
    DYincli->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &HT0eventWeight);
    T_event->SetBranchAddress("f_alphamin", &HT0alphamin);
    T_event->SetBranchAddress("f_Met", &HT0met);
    T_event->SetBranchAddress("f_HT", &HT);
    T_event->SetBranchAddress("f_matchJet_PT", &HT0_matchJet_PT);
    T_event->SetBranchAddress("f_matchJet_Eta", &HT0_matchJet_eta);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (HT < 70)
        {
            if (HT0_matchJet_PT->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_PT->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht0A_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT0Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht0B_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT0Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht0C_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT0Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht0D_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT0Weight);
                    }
                }
            }

            if (HT0_matchJet_eta->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_eta->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht0A_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT0Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht0B_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT0Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht0C_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT0Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht0D_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT0Weight);
                    }
                }
            }

            if (HT0alphamin > 0.3 && HT0met > 160)
            {
                h_ht0A_jetmet->Fill(HT0met, HT0eventWeight * HT0Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met > 160)
            {
                h_ht0B_jetmet->Fill(HT0met, HT0eventWeight * HT0Weight);
            }
            else if (HT0alphamin > 0.3 && HT0met < 100)
            {
                h_ht0C_jetmet->Fill(HT0met, HT0eventWeight * HT0Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met < 100)
            {
                h_ht0D_jetmet->Fill(HT0met, HT0eventWeight * HT0Weight);
            }
        }
        else if (HT > 70 && HT < 100)
        {
            if (HT0_matchJet_PT->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_PT->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht70A_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT70Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht70B_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT70Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht70C_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT70Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht70D_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT70Weight);
                    }
                }
            }

            if (HT0_matchJet_eta->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_eta->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht70A_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT70Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht70B_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT70Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht70C_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT70Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht70D_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT70Weight);
                    }
                }
            }

            if (HT0alphamin > 0.3 && HT0met > 160)
            {
                h_ht70A_jetmet->Fill(HT0met, HT0eventWeight * HT70Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met > 160)
            {
                h_ht70B_jetmet->Fill(HT0met, HT0eventWeight * HT70Weight);
            }
            else if (HT0alphamin > 0.3 && HT0met < 100)
            {
                h_ht70C_jetmet->Fill(HT0met, HT0eventWeight * HT70Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met < 100)
            {
                h_ht70D_jetmet->Fill(HT0met, HT0eventWeight * HT70Weight);
            }
        }
        else if (HT > 100 && HT < 200)
        {
            if (HT0_matchJet_PT->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_PT->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht100A_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT100Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht100B_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT100Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht100C_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT100Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht100D_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT100Weight);
                    }
                }
            }

            if (HT0_matchJet_eta->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_eta->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht100A_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT100Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht100B_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT100Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht100C_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT100Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht100D_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT100Weight);
                    }
                }
            }

            if (HT0alphamin > 0.3 && HT0met > 160)
            {
                h_ht100A_jetmet->Fill(HT0met, HT0eventWeight * HT100Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met > 160)
            {
                h_ht100B_jetmet->Fill(HT0met, HT0eventWeight * HT100Weight);
            }
            else if (HT0alphamin > 0.3 && HT0met < 100)
            {
                h_ht100C_jetmet->Fill(HT0met, HT0eventWeight * HT100Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met < 100)
            {
                h_ht100D_jetmet->Fill(HT0met, HT0eventWeight * HT100Weight);
            }
        }
        else if (HT > 200 && HT < 400)
        {
            if (HT0_matchJet_PT->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_PT->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht200A_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT200Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht200B_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT200Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht200C_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT200Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht200D_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT200Weight);
                    }
                }
            }
            if (HT0_matchJet_eta->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_eta->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht200A_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT200Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht200B_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT200Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht200C_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT200Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht200D_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT200Weight);
                    }
                }
            }

            if (HT0alphamin > 0.3 && HT0met > 160)
            {
                h_ht200A_jetmet->Fill(HT0met, HT0eventWeight * HT200Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met > 160)
            {
                h_ht200B_jetmet->Fill(HT0met, HT0eventWeight * HT200Weight);
            }
            else if (HT0alphamin > 0.3 && HT0met < 100)
            {
                h_ht200C_jetmet->Fill(HT0met, HT0eventWeight * HT200Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met < 100)
            {
                h_ht200D_jetmet->Fill(HT0met, HT0eventWeight * HT200Weight);
            }
        }
        else if (HT > 400 && HT < 600)
        {
            if (HT0_matchJet_PT->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_PT->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht400A_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT400Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht400B_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT400Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht400C_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT400Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht400D_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT400Weight);
                    }
                }
            }

            if (HT0_matchJet_eta->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_eta->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht400A_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT400Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht400B_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT400Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht400C_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT400Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht400D_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT400Weight);
                    }
                }
            }

            if (HT0alphamin > 0.3 && HT0met > 160)
            {
                h_ht400A_jetmet->Fill(HT0met, HT0eventWeight * HT400Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met > 160)
            {
                h_ht400B_jetmet->Fill(HT0met, HT0eventWeight * HT400Weight);
            }
            else if (HT0alphamin > 0.3 && HT0met < 100)
            {
                h_ht400C_jetmet->Fill(HT0met, HT0eventWeight * HT400Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met < 100)
            {
                h_ht400D_jetmet->Fill(HT0met, HT0eventWeight * HT400Weight);
            }
        }
        else if (HT > 600 && HT < 800)
        {
            if (HT0_matchJet_PT->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_PT->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht600A_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT600Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht600B_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT600Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht600C_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT600Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht600D_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT600Weight);
                    }
                }
            }

            if (HT0_matchJet_eta->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_eta->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht600A_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT600Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht600B_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT600Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht600C_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT600Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht600D_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT600Weight);
                    }
                }
            }

            if (HT0alphamin > 0.3 && HT0met > 160)
            {
                h_ht600A_jetmet->Fill(HT0met, HT0eventWeight * HT600Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met > 160)
            {
                h_ht600B_jetmet->Fill(HT0met, HT0eventWeight * HT600Weight);
            }
            else if (HT0alphamin > 0.3 && HT0met < 100)
            {
                h_ht600C_jetmet->Fill(HT0met, HT0eventWeight * HT600Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met < 100)
            {
                h_ht600D_jetmet->Fill(HT0met, HT0eventWeight * HT600Weight);
            }
        }
        else if (HT > 800 && HT < 1200)
        {
            if (HT0_matchJet_PT->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_PT->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht800A_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT800Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht800B_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT800Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht800C_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT800Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht800D_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT800Weight);
                    }
                }
            }

            if (HT0_matchJet_eta->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_eta->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht800A_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT800Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht800B_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT800Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht800C_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT800Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht800D_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT800Weight);
                    }
                }
            }

            if (HT0alphamin > 0.3 && HT0met > 160)
            {
                h_ht800A_jetmet->Fill(HT0met, HT0eventWeight * HT800Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met > 160)
            {
                h_ht800B_jetmet->Fill(HT0met, HT0eventWeight * HT800Weight);
            }
            else if (HT0alphamin > 0.3 && HT0met < 100)
            {
                h_ht800C_jetmet->Fill(HT0met, HT0eventWeight * HT800Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met < 100)
            {
                h_ht800D_jetmet->Fill(HT0met, HT0eventWeight * HT800Weight);
            }
        }
        else if (HT > 1200 && HT < 2500)
        {
            if (HT0_matchJet_PT->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_PT->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht1200A_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT1200Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht1200B_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT1200Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht1200C_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT1200Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht1200D_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT1200Weight);
                    }
                }
            }

            if (HT0_matchJet_eta->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_eta->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht1200A_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT1200Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht1200B_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT1200Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht1200C_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT1200Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht1200D_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT1200Weight);
                    }
                }
            }

            if (HT0alphamin > 0.3 && HT0met > 160)
            {
                h_ht1200A_jetmet->Fill(HT0met, HT0eventWeight * HT1200Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met > 160)
            {
                h_ht1200B_jetmet->Fill(HT0met, HT0eventWeight * HT1200Weight);
            }
            else if (HT0alphamin > 0.3 && HT0met < 100)
            {
                h_ht1200C_jetmet->Fill(HT0met, HT0eventWeight * HT1200Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met < 100)
            {
                h_ht1200D_jetmet->Fill(HT0met, HT0eventWeight * HT1200Weight);
            }
        }
        else if (HT > 2500)
        {
            if (HT0_matchJet_PT->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_PT->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht2500A_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT2500Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht2500B_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT2500Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht2500C_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT2500Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht2500D_jetpt->Fill((*HT0_matchJet_PT)[j], HT0eventWeight * HT2500Weight);
                    }
                }
            }
            if (HT0_matchJet_eta->size() > 0)
            {
                for (Int_t j = 0; j < HT0_matchJet_eta->size(); j++)
                {
                    if (HT0alphamin > 0.3 && HT0met > 160)
                    {
                        h_ht2500A_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT2500Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met > 160)
                    {
                        h_ht2500B_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT2500Weight);
                    }
                    else if (HT0alphamin > 0.3 && HT0met < 100)
                    {
                        h_ht2500C_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT2500Weight);
                    }
                    else if (HT0alphamin < 0.1 && HT0met < 100)
                    {
                        h_ht2500D_jeteta->Fill((*HT0_matchJet_eta)[j], HT0eventWeight * HT2500Weight);
                    }
                }
            }

            if (HT0alphamin > 0.3 && HT0met > 160)
            {
                h_ht2500A_jetmet->Fill(HT0met, HT0eventWeight * HT2500Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met > 160)
            {
                h_ht2500B_jetmet->Fill(HT0met, HT0eventWeight * HT2500Weight);
            }
            else if (HT0alphamin > 0.3 && HT0met < 100)
            {
                h_ht2500C_jetmet->Fill(HT0met, HT0eventWeight * HT2500Weight);
            }
            else if (HT0alphamin < 0.1 && HT0met < 100)
            {
                h_ht2500D_jetmet->Fill(HT0met, HT0eventWeight * HT2500Weight);
            }
        }
    } // End of inclusive sample

    std::vector<Float_t> *HT100_matchJet_PT = new std::vector<Float_t>();
    std::vector<Float_t> *HT100_matchJet_eta = new std::vector<Float_t>();
    TTree *T_event1;
    DYHT100->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_matchJet_Eta", &HT100_matchJet_eta);
    T_event1->SetBranchAddress("f_matchJet_PT", &HT100_matchJet_PT);
    T_event1->SetBranchAddress("f_alphamin", &f_ht100_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_ht100_Met);
    T_event1->SetBranchAddress("I_weight", &I_ht100_weight);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (HT100_matchJet_PT->size() > 0)
        {
            for (Int_t j = 0; j < HT100_matchJet_PT->size(); j++)
            {
                if (f_ht100_alphamin > 0.3 && f_ht100_Met > 160)
                {
                    h_ht100A_jetpt->Fill((*HT100_matchJet_PT)[j], I_ht100_weight * HT100Weight);
                }
                else if (f_ht100_alphamin < 0.1 && f_ht100_Met > 160)
                {
                    h_ht100B_jetpt->Fill((*HT100_matchJet_PT)[j], I_ht100_weight * HT100Weight);
                }
                else if (f_ht100_alphamin > 0.3 && f_ht100_Met < 100)
                {
                    h_ht100C_jetpt->Fill((*HT100_matchJet_PT)[j], I_ht100_weight * HT100Weight);
                }
                else if (f_ht100_alphamin < 0.1 && f_ht100_Met < 100)
                {
                    h_ht100D_jetpt->Fill((*HT100_matchJet_PT)[j], I_ht100_weight * HT100Weight);
                }
            }
        }

        if (HT100_matchJet_eta->size() > 0)
        {
            for (Int_t j = 0; j < HT100_matchJet_eta->size(); j++)
            {
                if (f_ht100_alphamin > 0.3 && f_ht100_Met > 160)
                {
                    h_ht100A_jeteta->Fill((*HT100_matchJet_eta)[j], I_ht100_weight * HT100Weight);
                }
                else if (f_ht100_alphamin < 0.1 && f_ht100_Met > 160)
                {
                    h_ht100B_jeteta->Fill((*HT100_matchJet_eta)[j], I_ht100_weight * HT100Weight);
                }
                else if (f_ht100_alphamin > 0.3 && f_ht100_Met < 100)
                {
                    h_ht100C_jeteta->Fill((*HT100_matchJet_eta)[j], I_ht100_weight * HT100Weight);
                }
                else if (f_ht100_alphamin < 0.1 && f_ht100_Met < 100)
                {
                    h_ht100D_jeteta->Fill((*HT100_matchJet_eta)[j], I_ht100_weight * HT100Weight);
                }
            }
        }

        if (f_ht100_alphamin > 0.3 && f_ht100_Met > 160)
        {
            h_ht100A_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
        }
        else if (f_ht100_alphamin < 0.1 && f_ht100_Met > 160)
        {
            h_ht100B_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
        }
        else if (f_ht100_alphamin > 0.3 && f_ht100_Met < 100)
        {
            h_ht100C_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
        }
        else if (f_ht100_alphamin < 0.1 && f_ht100_Met < 100)
        {
            h_ht100D_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
        }
    } // End of HT100
    std::vector<Float_t> *HT200_matchJet_PT = new std::vector<Float_t>();
    std::vector<Float_t> *HT200_matchJet_eta = new std::vector<Float_t>();
    TTree *T_event2;
    DYHT200->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_matchJet_Eta", &HT200_matchJet_eta);
    T_event2->SetBranchAddress("f_matchJet_PT", &HT200_matchJet_PT);
    T_event2->SetBranchAddress("f_alphamin", &f_ht200_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_ht200_Met);
    T_event2->SetBranchAddress("I_weight", &I_ht200_weight);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (HT200_matchJet_PT->size() > 0)
        {
            for (Int_t j = 0; j < HT200_matchJet_PT->size(); j++)
            {
                if (f_ht200_alphamin > 0.3 && f_ht200_Met > 160)
                {
                    h_ht200A_jetpt->Fill((*HT200_matchJet_PT)[j], I_ht200_weight * HT200Weight);
                }
                else if (f_ht200_alphamin < 0.1 && f_ht200_Met > 160)
                {
                    h_ht200B_jetpt->Fill((*HT200_matchJet_PT)[j], I_ht200_weight * HT200Weight);
                }
                else if (f_ht200_alphamin > 0.3 && f_ht200_Met < 100)
                {
                    h_ht200C_jetpt->Fill((*HT200_matchJet_PT)[j], I_ht200_weight * HT200Weight);
                }
                else if (f_ht200_alphamin < 0.1 && f_ht200_Met < 100)
                {
                    h_ht200D_jetpt->Fill((*HT200_matchJet_PT)[j], I_ht200_weight * HT200Weight);
                }
            }
        }

        if (HT200_matchJet_eta->size() > 0)
        {
            for (Int_t j = 0; j < HT200_matchJet_eta->size(); j++)
            {
                if (f_ht200_alphamin > 0.3 && f_ht200_Met > 160)
                {
                    h_ht200A_jeteta->Fill((*HT200_matchJet_eta)[j], I_ht200_weight * HT200Weight);
                }
                else if (f_ht200_alphamin < 0.1 && f_ht200_Met > 160)
                {
                    h_ht200B_jeteta->Fill((*HT200_matchJet_eta)[j], I_ht200_weight * HT200Weight);
                }
                else if (f_ht200_alphamin > 0.3 && f_ht200_Met < 100)
                {
                    h_ht200C_jeteta->Fill((*HT200_matchJet_eta)[j], I_ht200_weight * HT200Weight);
                }
                else if (f_ht200_alphamin < 0.1 && f_ht200_Met < 100)
                {
                    h_ht200D_jeteta->Fill((*HT200_matchJet_eta)[j], I_ht200_weight * HT200Weight);
                }
            }
        }

        if (f_ht200_alphamin > 0.3 && f_ht200_Met > 160)
        {
            h_ht200A_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
        }
        else if (f_ht200_alphamin < 0.1 && f_ht200_Met > 160)
        {
            h_ht200B_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
        }
        else if (f_ht200_alphamin > 0.3 && f_ht200_Met < 100)
        {
            h_ht200C_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
        }
        else if (f_ht200_alphamin < 0.1 && f_ht200_Met < 100)
        {
            h_ht200D_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
        }
    } // End of HT200
    std::vector<Float_t> *HT400_matchJet_PT = new std::vector<Float_t>();
    std::vector<Float_t> *HT400_matchJet_eta = new std::vector<Float_t>();
    TTree *T_event3;
    DYHT400->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_matchJet_Eta", &HT400_matchJet_eta);
    T_event3->SetBranchAddress("f_matchJet_PT", &HT400_matchJet_PT);
    T_event3->SetBranchAddress("f_alphamin", &f_ht400_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_ht400_Met);
    T_event3->SetBranchAddress("I_weight", &I_ht400_weight);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (HT400_matchJet_PT->size() > 0)
        {
            for (Int_t j = 0; j < HT400_matchJet_PT->size(); j++)
            {
                if (f_ht400_alphamin > 0.3 && f_ht400_Met > 160)
                {
                    h_ht400A_jetpt->Fill((*HT400_matchJet_PT)[j], I_ht400_weight * HT400Weight);
                }
                else if (f_ht400_alphamin < 0.1 && f_ht400_Met > 160)
                {
                    h_ht400B_jetpt->Fill((*HT400_matchJet_PT)[j], I_ht400_weight * HT400Weight);
                }
                else if (f_ht400_alphamin > 0.3 && f_ht400_Met < 100)
                {
                    h_ht400C_jetpt->Fill((*HT400_matchJet_PT)[j], I_ht400_weight * HT400Weight);
                }
                else if (f_ht400_alphamin < 0.1 && f_ht400_Met < 100)
                {
                    h_ht400D_jetpt->Fill((*HT400_matchJet_PT)[j], I_ht400_weight * HT400Weight);
                }
            }
        }

        if (HT400_matchJet_eta->size() > 0)
        {
            for (Int_t j = 0; j < HT400_matchJet_eta->size(); j++)
            {
                if (f_ht400_alphamin > 0.3 && f_ht400_Met > 160)
                {
                    h_ht400A_jeteta->Fill((*HT400_matchJet_eta)[j], I_ht400_weight * HT400Weight);
                }
                else if (f_ht400_alphamin < 0.1 && f_ht400_Met > 160)
                {
                    h_ht400B_jeteta->Fill((*HT400_matchJet_eta)[j], I_ht400_weight * HT400Weight);
                }
                else if (f_ht400_alphamin > 0.3 && f_ht400_Met < 100)
                {
                    h_ht400C_jeteta->Fill((*HT400_matchJet_eta)[j], I_ht400_weight * HT400Weight);
                }
                else if (f_ht400_alphamin < 0.1 && f_ht400_Met < 100)
                {
                    h_ht400D_jeteta->Fill((*HT400_matchJet_eta)[j], I_ht400_weight * HT400Weight);
                }
            }
        }

        if (f_ht400_alphamin > 0.3 && f_ht400_Met > 160)
        {
            h_ht400A_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
        }
        else if (f_ht400_alphamin < 0.1 && f_ht400_Met > 160)
        {
            h_ht400B_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
        }
        else if (f_ht400_alphamin > 0.3 && f_ht400_Met < 100)
        {
            h_ht400C_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
        }
        else if (f_ht400_alphamin < 0.1 && f_ht400_Met < 100)
        {
            h_ht400D_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
        }
    } // End of HT400
    std::vector<Float_t> *HT600_matchJet_PT = new std::vector<Float_t>();
    std::vector<Float_t> *HT600_matchJet_eta = new std::vector<Float_t>();
    TTree *T_event4;
    DYHT600->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_matchJet_Eta", &HT600_matchJet_eta);
    T_event4->SetBranchAddress("f_matchJet_PT", &HT600_matchJet_PT);
    T_event4->SetBranchAddress("f_alphamin", &f_ht600_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_ht600_Met);
    T_event4->SetBranchAddress("I_weight", &I_ht600_weight);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (HT600_matchJet_PT->size() > 0)
        {
            for (Int_t j = 0; j < HT600_matchJet_PT->size(); j++)
            {
                if (f_ht600_alphamin > 0.3 && f_ht600_Met > 160)
                {
                    h_ht600A_jetpt->Fill((*HT600_matchJet_PT)[j], I_ht600_weight * HT600Weight);
                }
                else if (f_ht600_alphamin < 0.1 && f_ht600_Met > 160)
                {
                    h_ht600B_jetpt->Fill((*HT600_matchJet_PT)[j], I_ht600_weight * HT600Weight);
                }
                else if (f_ht600_alphamin > 0.3 && f_ht600_Met < 100)
                {
                    h_ht600C_jetpt->Fill((*HT600_matchJet_PT)[j], I_ht600_weight * HT600Weight);
                }
                else if (f_ht600_alphamin < 0.1 && f_ht600_Met < 100)
                {
                    h_ht600D_jetpt->Fill((*HT600_matchJet_PT)[j], I_ht600_weight * HT600Weight);
                }
            }
        }

        if (HT600_matchJet_eta->size() > 0)
        {
            for (Int_t j = 0; j < HT600_matchJet_eta->size(); j++)
            {
                if (f_ht600_alphamin > 0.3 && f_ht600_Met > 160)
                {
                    h_ht600A_jeteta->Fill((*HT600_matchJet_eta)[j], I_ht600_weight * HT600Weight);
                }
                else if (f_ht600_alphamin < 0.1 && f_ht600_Met > 160)
                {
                    h_ht600B_jeteta->Fill((*HT600_matchJet_eta)[j], I_ht600_weight * HT600Weight);
                }
                else if (f_ht600_alphamin > 0.3 && f_ht600_Met < 100)
                {
                    h_ht600C_jeteta->Fill((*HT600_matchJet_eta)[j], I_ht600_weight * HT600Weight);
                }
                else if (f_ht600_alphamin < 0.1 && f_ht600_Met < 100)
                {
                    h_ht600D_jeteta->Fill((*HT600_matchJet_eta)[j], I_ht600_weight * HT600Weight);
                }
            }
        }

        if (f_ht600_alphamin > 0.3 && f_ht600_Met > 160)
        {
            h_ht600A_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
        }
        else if (f_ht600_alphamin < 0.1 && f_ht600_Met > 160)
        {
            h_ht600B_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
        }
        else if (f_ht600_alphamin > 0.3 && f_ht600_Met < 100)
        {
            h_ht600C_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
        }
        else if (f_ht600_alphamin < 0.1 && f_ht600_Met < 100)
        {
            h_ht600D_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
        }
    } // End of HT600
    std::vector<Float_t> *HT800_matchJet_PT = new std::vector<Float_t>();
    std::vector<Float_t> *HT800_matchJet_eta = new std::vector<Float_t>();
    TTree *T_event5;
    DYHT800->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_matchJet_Eta", &HT800_matchJet_eta);
    T_event5->SetBranchAddress("f_matchJet_PT", &HT800_matchJet_PT);
    T_event5->SetBranchAddress("f_alphamin", &f_ht800_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_ht800_Met);
    T_event5->SetBranchAddress("I_weight", &I_ht800_weight);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (HT800_matchJet_PT->size() > 0)
        {
            for (Int_t j = 0; j < HT800_matchJet_PT->size(); j++)
            {
                if (f_ht800_alphamin > 0.3 && f_ht800_Met > 160)
                {
                    h_ht800A_jetpt->Fill((*HT800_matchJet_PT)[j], I_ht800_weight * HT800Weight);
                }
                else if (f_ht800_alphamin < 0.1 && f_ht800_Met > 160)
                {
                    h_ht800B_jetpt->Fill((*HT800_matchJet_PT)[j], I_ht800_weight * HT800Weight);
                }
                else if (f_ht800_alphamin > 0.3 && f_ht800_Met < 100)
                {
                    h_ht800C_jetpt->Fill((*HT800_matchJet_PT)[j], I_ht800_weight * HT800Weight);
                }
                else if (f_ht800_alphamin < 0.1 && f_ht800_Met < 100)
                {
                    h_ht800D_jetpt->Fill((*HT800_matchJet_PT)[j], I_ht800_weight * HT800Weight);
                }
            }
        }

        if (HT800_matchJet_eta->size() > 0)
        {
            for (Int_t j = 0; j < HT800_matchJet_eta->size(); j++)
            {
                if (f_ht800_alphamin > 0.3 && f_ht800_Met > 160)
                {
                    h_ht800A_jeteta->Fill((*HT800_matchJet_eta)[j], I_ht800_weight * HT800Weight);
                }
                else if (f_ht800_alphamin < 0.1 && f_ht800_Met > 160)
                {
                    h_ht800B_jeteta->Fill((*HT800_matchJet_eta)[j], I_ht800_weight * HT800Weight);
                }
                else if (f_ht800_alphamin > 0.3 && f_ht800_Met < 100)
                {
                    h_ht800C_jeteta->Fill((*HT800_matchJet_eta)[j], I_ht800_weight * HT800Weight);
                }
                else if (f_ht800_alphamin < 0.1 && f_ht800_Met < 100)
                {
                    h_ht800D_jeteta->Fill((*HT800_matchJet_eta)[j], I_ht800_weight * HT800Weight);
                }
            }
        }

        if (f_ht800_alphamin > 0.3 && f_ht800_Met > 160)
        {
            h_ht800A_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
        }
        else if (f_ht800_alphamin < 0.1 && f_ht800_Met > 160)
        {
            h_ht800B_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
        }
        else if (f_ht800_alphamin > 0.3 && f_ht800_Met < 100)
        {
            h_ht800C_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
        }
        else if (f_ht800_alphamin < 0.1 && f_ht800_Met < 100)
        {
            h_ht800D_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
        }
    } // End of HT800
    std::vector<Float_t> *HT1200_matchJet_PT = new std::vector<Float_t>();
    std::vector<Float_t> *HT1200_matchJet_eta = new std::vector<Float_t>();
    TTree *T_event6;
    DYHT1200->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_matchJet_PT", &HT1200_matchJet_PT);
    T_event6->SetBranchAddress("f_matchJet_Eta", &HT1200_matchJet_eta);
    T_event6->SetBranchAddress("f_alphamin", &f_ht1200_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_ht1200_Met);
    T_event6->SetBranchAddress("I_weight", &I_ht1200_weight);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (HT1200_matchJet_PT->size() > 0)
        {
            for (Int_t j = 0; j < HT1200_matchJet_PT->size(); j++)
            {
                if (f_ht1200_alphamin > 0.3 && f_ht1200_Met > 160)
                {
                    h_ht1200A_jetpt->Fill((*HT1200_matchJet_PT)[j], I_ht1200_weight * HT1200Weight);
                }
                else if (f_ht1200_alphamin < 0.1 && f_ht1200_Met > 160)
                {
                    h_ht1200B_jetpt->Fill((*HT1200_matchJet_PT)[j], I_ht1200_weight * HT1200Weight);
                }
                else if (f_ht1200_alphamin > 0.3 && f_ht1200_Met < 100)
                {
                    h_ht1200C_jetpt->Fill((*HT1200_matchJet_PT)[j], I_ht1200_weight * HT1200Weight);
                }
                else if (f_ht1200_alphamin < 0.1 && f_ht1200_Met < 100)
                {
                    h_ht1200D_jetpt->Fill((*HT1200_matchJet_PT)[j], I_ht1200_weight * HT1200Weight);
                }
            }
        }

        if (HT1200_matchJet_eta->size() > 0)
        {
            for (Int_t j = 0; j < HT1200_matchJet_eta->size(); j++)
            {
                if (f_ht1200_alphamin > 0.3 && f_ht1200_Met > 160)
                {
                    h_ht1200A_jeteta->Fill((*HT1200_matchJet_eta)[j], I_ht1200_weight * HT1200Weight);
                }
                else if (f_ht1200_alphamin < 0.1 && f_ht1200_Met > 160)
                {
                    h_ht1200B_jeteta->Fill((*HT1200_matchJet_eta)[j], I_ht1200_weight * HT1200Weight);
                }
                else if (f_ht1200_alphamin > 0.3 && f_ht1200_Met < 100)
                {
                    h_ht1200C_jeteta->Fill((*HT1200_matchJet_eta)[j], I_ht1200_weight * HT1200Weight);
                }
                else if (f_ht1200_alphamin < 0.1 && f_ht1200_Met < 100)
                {
                    h_ht1200D_jeteta->Fill((*HT1200_matchJet_eta)[j], I_ht1200_weight * HT1200Weight);
                }
            }
        }

        if (f_ht1200_alphamin > 0.3 && f_ht1200_Met > 160)
        {
            h_ht1200A_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
        }
        else if (f_ht1200_alphamin < 0.1 && f_ht1200_Met > 160)
        {
            h_ht1200B_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
        }
        else if (f_ht1200_alphamin > 0.3 && f_ht1200_Met < 100)
        {
            h_ht1200C_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
        }
        else if (f_ht1200_alphamin < 0.1 && f_ht1200_Met < 100)
        {
            h_ht1200D_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
        }
    } // End of HT1200
    std::vector<Float_t> *HT2500_matchJet_PT = new std::vector<Float_t>();
    std::vector<Float_t> *HT2500_matchJet_eta = new std::vector<Float_t>();
    TTree *T_event7;
    DYHT2500->GetObject("T_event", T_event7);
    T_event7->SetBranchAddress("f_matchJet_Eta", &HT2500_matchJet_eta);
    T_event7->SetBranchAddress("f_matchJet_PT", &HT2500_matchJet_PT);
    T_event7->SetBranchAddress("f_alphamin", &f_ht2500_alphamin);
    T_event7->SetBranchAddress("f_Met", &f_ht2500_Met);
    T_event7->SetBranchAddress("I_weight", &I_ht2500_weight);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        if (HT2500_matchJet_PT->size() > 0)
        {
            for (Int_t j = 0; j < HT2500_matchJet_PT->size(); j++)
            {
                if (f_ht2500_alphamin > 0.3 && f_ht2500_Met > 160)
                {
                    h_ht2500A_jetpt->Fill((*HT2500_matchJet_PT)[j], I_ht2500_weight * HT2500Weight);
                }
                else if (f_ht2500_alphamin < 0.1 && f_ht2500_Met > 160)
                {
                    h_ht2500B_jetpt->Fill((*HT2500_matchJet_PT)[j], I_ht2500_weight * HT2500Weight);
                }
                else if (f_ht2500_alphamin > 0.3 && f_ht2500_Met < 100)
                {
                    h_ht2500C_jetpt->Fill((*HT2500_matchJet_PT)[j], I_ht2500_weight * HT2500Weight);
                }
                else if (f_ht2500_alphamin < 0.1 && f_ht2500_Met < 100)
                {
                    h_ht2500D_jetpt->Fill((*HT2500_matchJet_PT)[j], I_ht2500_weight * HT2500Weight);
                }
            }
        }

        if (HT2500_matchJet_eta->size() > 0)
        {
            for (Int_t j = 0; j < HT2500_matchJet_eta->size(); j++)
            {
                if (f_ht2500_alphamin > 0.3 && f_ht2500_Met > 160)
                {
                    h_ht2500A_jeteta->Fill((*HT2500_matchJet_eta)[j], I_ht2500_weight * HT2500Weight);
                }
                else if (f_ht2500_alphamin < 0.1 && f_ht2500_Met > 160)
                {
                    h_ht2500B_jeteta->Fill((*HT2500_matchJet_eta)[j], I_ht2500_weight * HT2500Weight);
                }
                else if (f_ht2500_alphamin > 0.3 && f_ht2500_Met < 100)
                {
                    h_ht2500C_jeteta->Fill((*HT2500_matchJet_eta)[j], I_ht2500_weight * HT2500Weight);
                }
                else if (f_ht2500_alphamin < 0.1 && f_ht2500_Met < 100)
                {
                    h_ht2500D_jeteta->Fill((*HT2500_matchJet_eta)[j], I_ht2500_weight * HT2500Weight);
                }
            }
        }

        if (f_ht2500_alphamin > 0.3 && f_ht2500_Met > 160)
        {
            h_ht2500A_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
        }
        else if (f_ht2500_alphamin < 0.1 && f_ht2500_Met > 160)
        {
            h_ht2500B_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
        }
        else if (f_ht2500_alphamin > 0.3 && f_ht2500_Met < 2500)
        {
            h_ht2500C_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
        }
        else if (f_ht2500_alphamin < 0.1 && f_ht2500_Met < 2500)
        {
            h_ht2500D_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
        }
    } // End of HT2500

    h_ht0A_jetpt->Add(h_ht70A_jetpt);
    h_ht0A_jetpt->Add(h_ht100A_jetpt);
    h_ht0A_jetpt->Add(h_ht200A_jetpt);
    h_ht0A_jetpt->Add(h_ht400A_jetpt);
    h_ht0A_jetpt->Add(h_ht600A_jetpt);
    h_ht0A_jetpt->Add(h_ht800A_jetpt);
    h_ht0A_jetpt->Add(h_ht1200A_jetpt);
    h_ht0A_jetpt->Add(h_ht2500A_jetpt);

    h_ht0B_jetpt->Add(h_ht70B_jetpt);
    h_ht0B_jetpt->Add(h_ht100B_jetpt);
    h_ht0B_jetpt->Add(h_ht200B_jetpt);
    h_ht0B_jetpt->Add(h_ht400B_jetpt);
    h_ht0B_jetpt->Add(h_ht600B_jetpt);
    h_ht0B_jetpt->Add(h_ht800B_jetpt);
    h_ht0B_jetpt->Add(h_ht1200B_jetpt);
    h_ht0B_jetpt->Add(h_ht2500B_jetpt);

    h_ht0C_jetpt->Add(h_ht70C_jetpt);
    h_ht0C_jetpt->Add(h_ht100C_jetpt);
    h_ht0C_jetpt->Add(h_ht200C_jetpt);
    h_ht0C_jetpt->Add(h_ht400C_jetpt);
    h_ht0C_jetpt->Add(h_ht600C_jetpt);
    h_ht0C_jetpt->Add(h_ht800C_jetpt);
    h_ht0C_jetpt->Add(h_ht1200C_jetpt);
    h_ht0C_jetpt->Add(h_ht2500C_jetpt);

    h_ht0D_jetpt->Add(h_ht70D_jetpt);
    h_ht0D_jetpt->Add(h_ht100D_jetpt);
    h_ht0D_jetpt->Add(h_ht200D_jetpt);
    h_ht0D_jetpt->Add(h_ht400D_jetpt);
    h_ht0D_jetpt->Add(h_ht600D_jetpt);
    h_ht0D_jetpt->Add(h_ht800D_jetpt);
    h_ht0D_jetpt->Add(h_ht1200D_jetpt);
    h_ht0D_jetpt->Add(h_ht2500D_jetpt);

    h_ht0A_jeteta->Add(h_ht70A_jeteta);
    h_ht0A_jeteta->Add(h_ht100A_jeteta);
    h_ht0A_jeteta->Add(h_ht200A_jeteta);
    h_ht0A_jeteta->Add(h_ht400A_jeteta);
    h_ht0A_jeteta->Add(h_ht600A_jeteta);
    h_ht0A_jeteta->Add(h_ht800A_jeteta);
    h_ht0A_jeteta->Add(h_ht1200A_jeteta);
    h_ht0A_jeteta->Add(h_ht2500A_jeteta);

    h_ht0B_jeteta->Add(h_ht70B_jeteta);
    h_ht0B_jeteta->Add(h_ht100B_jeteta);
    h_ht0B_jeteta->Add(h_ht200B_jeteta);
    h_ht0B_jeteta->Add(h_ht400B_jeteta);
    h_ht0B_jeteta->Add(h_ht600B_jeteta);
    h_ht0B_jeteta->Add(h_ht800B_jeteta);
    h_ht0B_jeteta->Add(h_ht1200B_jeteta);
    h_ht0B_jeteta->Add(h_ht2500B_jeteta);

    h_ht0C_jeteta->Add(h_ht70C_jeteta);
    h_ht0C_jeteta->Add(h_ht100C_jeteta);
    h_ht0C_jeteta->Add(h_ht200C_jeteta);
    h_ht0C_jeteta->Add(h_ht400C_jeteta);
    h_ht0C_jeteta->Add(h_ht600C_jeteta);
    h_ht0C_jeteta->Add(h_ht800C_jeteta);
    h_ht0C_jeteta->Add(h_ht1200C_jeteta);
    h_ht0C_jeteta->Add(h_ht2500C_jeteta);

    h_ht0D_jeteta->Add(h_ht70D_jeteta);
    h_ht0D_jeteta->Add(h_ht100D_jeteta);
    h_ht0D_jeteta->Add(h_ht200D_jeteta);
    h_ht0D_jeteta->Add(h_ht400D_jeteta);
    h_ht0D_jeteta->Add(h_ht600D_jeteta);
    h_ht0D_jeteta->Add(h_ht800D_jeteta);
    h_ht0D_jeteta->Add(h_ht1200D_jeteta);
    h_ht0D_jeteta->Add(h_ht2500D_jeteta);

    h_ht0A_jetmet->Add(h_ht70A_jetmet);
    h_ht0A_jetmet->Add(h_ht100A_jetmet);
    h_ht0A_jetmet->Add(h_ht200A_jetmet);
    h_ht0A_jetmet->Add(h_ht400A_jetmet);
    h_ht0A_jetmet->Add(h_ht600A_jetmet);
    h_ht0A_jetmet->Add(h_ht800A_jetmet);
    h_ht0A_jetmet->Add(h_ht1200A_jetmet);
    h_ht0A_jetmet->Add(h_ht2500A_jetmet);

    h_ht0B_jetmet->Add(h_ht70B_jetmet);
    h_ht0B_jetmet->Add(h_ht100B_jetmet);
    h_ht0B_jetmet->Add(h_ht200B_jetmet);
    h_ht0B_jetmet->Add(h_ht400B_jetmet);
    h_ht0B_jetmet->Add(h_ht600B_jetmet);
    h_ht0B_jetmet->Add(h_ht800B_jetmet);
    h_ht0B_jetmet->Add(h_ht1200B_jetmet);
    h_ht0B_jetmet->Add(h_ht2500B_jetmet);

    h_ht0C_jetmet->Add(h_ht70C_jetmet);
    h_ht0C_jetmet->Add(h_ht100C_jetmet);
    h_ht0C_jetmet->Add(h_ht200C_jetmet);
    h_ht0C_jetmet->Add(h_ht400C_jetmet);
    h_ht0C_jetmet->Add(h_ht600C_jetmet);
    h_ht0C_jetmet->Add(h_ht800C_jetmet);
    h_ht0C_jetmet->Add(h_ht1200C_jetmet);
    h_ht0C_jetmet->Add(h_ht2500C_jetmet);

    h_ht0D_jetmet->Add(h_ht70D_jetmet);
    h_ht0D_jetmet->Add(h_ht100D_jetmet);
    h_ht0D_jetmet->Add(h_ht200D_jetmet);
    h_ht0D_jetmet->Add(h_ht400D_jetmet);
    h_ht0D_jetmet->Add(h_ht600D_jetmet);
    h_ht0D_jetmet->Add(h_ht800D_jetmet);
    h_ht0D_jetmet->Add(h_ht1200D_jetmet);
    h_ht0D_jetmet->Add(h_ht2500D_jetmet);


    //TH1D *h_A_scale = new TH1D("h_A_scale", "Met", 10, 0, 1000);
    //h_A_scale->Sumw2();

    int nBin = h_Ratio->GetNbinsX();
    cout<<"Bin= "<<nBin<<endl;
    
    TH1F *h_A_scale = (TH1F*)h_ht0A_jetmet->Clone("h_A_scale");
    h_A_scale->Divide(h_Ratio);
/*
    for (int i = 0; i < nBin; i++)
    {
        float RatioWeight = h_Ratio->GetBinContent(i+1);
        float h_ht0_value = h_ht0A_jetmet->GetBinContent(i+1);
        float Value = h_ht0_value/RatioWeight;
        h_A_scale->SetBinContent(i+1,Value);
        //h_A_scale->Fill(Value);
        //h_ht0A_jetmet->Scale
        //cout<<"i = " << i << "RatioWeight = "<<RatioWeight<<endl;
        //cout<<"i = " << i <<  "h_ht0_value = "<<h_ht0_value<<endl;
        //cout<<"value = " <<h_ht0_value/RatioWeight<<endl;
    }
*/
    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(2,1);
    c1->cd(1);
    gStyle->SetOptStat(0);
    h_ht0B_jetmet->SetTitle("Met");
    h_ht0B_jetmet->SetXTitle("Met");
    h_ht0B_jetmet->SetYTitle("");
    h_A_scale->SetLineWidth(2);
    h_ht0B_jetmet->SetLineWidth(2);
    h_A_scale->SetLineColor(kOrange + 7);
    // h_ht0A_jetpt->SetFillColor(kOrange + 7);
    h_ht0B_jetmet->SetLineColor(kGray + 3);
    // h_ht0B_jetpt->SetFillColor(kGray + 3);
    h_ht0B_jetmet->Draw("hist&&E");
    h_A_scale->Draw("hist&&same");
    //h_A_scale->Draw("text45");
    TLegend *l1 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_A_scale, "Region A /Ratio", "l");
    l1->AddEntry(h_ht0B_jetmet, "Region B (SR) ", "l");
    l1->Draw();
    c1->cd(2);
    h_A_scale->Draw("E");
    // gStyle->SetOptStat(0);
    // h_ht0A_jeteta->SetTitle("");
    // h_ht0B_jeteta->SetXTitle("Jet eta");
    // h_ht0B_jeteta->SetYTitle("Normalized");
    // h_ht0A_jeteta->SetLineWidth(2);
    // h_ht0B_jeteta->SetLineWidth(2);
    // h_ht0A_jeteta->SetLineColor(kOrange + 7);
    //  h_ht0A_jeteta->SetFillColor(kOrange + 7);
    // h_ht0B_jeteta->SetLineColor(kGray + 3);
    //  h_ht0B_jeteta->SetFillColor(kGray + 3);
    // h_ht0B_jeteta->DrawNormalized("hist");
    // h_ht0A_jeteta->DrawNormalized("hist&&same");
    //  h_ht0A_jetpt->Divide(h_ht0B_jetpt);
    //  h_ht0D_jetpt->SetTitle("D*Ratio");
    //  h_ht0D_jetpt->SetXTitle("Jet PT");
    //  h_ht0D_jetpt->DrawNormalized("hist");

    // TLegend *l4 = new TLegend(0.20, 0.55, 0.70, 0.8);
    // l4->SetBorderSize(0);
    // l4->SetTextSize(0.04);
    // l4->AddEntry(h_ht0A_jeteta, "Region A / Ratio", "l");
    // l4->AddEntry(h_ht0B_jeteta, "Region B (SR)", "l");
    // l4->Draw();
}
