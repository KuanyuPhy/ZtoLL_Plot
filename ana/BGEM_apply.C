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
    double par0 = 2.12675e+00;
    double par1 = 1.25145e-04;
    double par2 = -2.07980e-04;
    double par3 = 3.71091e+00;
    double par4 = -2.22213e-02;
    double par5 = 4.66336e-05;
    double par6 = -3.19504e-08;

    // Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 * x * x + par4 * x + par5);
    Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 + par4 * x + par5 * x * x + par6 * x * x * x);
    return weight;
}
void BGEM_apply()
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

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));

    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("Event_Variable/h_event"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("Event_Variable/h_event"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("Event_Variable/h_event"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("Event_Variable/h_event"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("Event_Variable/h_event"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("Event_Variable/h_event"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("Event_Variable/h_event"));

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

    TH1D *h_ht0A_diLp_PT = new TH1D("h_ht0A_diLp_PT", "jet Met", 50, 0, 500);
    h_ht0A_diLp_PT->Sumw2();
    TH1F *h_ht0B_diLp_PT = new TH1F("h_ht0B_diLp_PT", "jet Met", 50, 0, 500);
    h_ht0B_diLp_PT->Sumw2();
    TH1F *h_ht0C_diLp_PT = new TH1F("h_ht0C_diLp_PT", "jet Met", 50, 0, 500);
    h_ht0C_diLp_PT->Sumw2();
    TH1F *h_ht0D_diLp_PT = new TH1F("h_ht0D_diLp_PT", "jet Met", 50, 0, 500);
    h_ht0D_diLp_PT->Sumw2();

    TH1D *h_ht70A_diLp_PT = new TH1D("h_ht70A_diLp_PT", "jet Met", 50, 0, 500);
    h_ht70A_diLp_PT->Sumw2();
    TH1F *h_ht70B_diLp_PT = new TH1F("h_ht70B_diLp_PT", "jet Met", 50, 0, 500);
    h_ht70B_diLp_PT->Sumw2();
    TH1F *h_ht70C_diLp_PT = new TH1F("h_ht70C_diLp_PT", "jet Met", 50, 0, 500);
    h_ht70C_diLp_PT->Sumw2();
    TH1F *h_ht70D_diLp_PT = new TH1F("h_ht70D_diLp_PT", "jet Met", 50, 0, 500);
    h_ht70D_diLp_PT->Sumw2();

    TH1D *h_ht100A_diLp_PT = new TH1D("h_ht100A_diLp_PT", "jet Met", 50, 0, 500);
    h_ht100A_diLp_PT->Sumw2();
    TH1F *h_ht100B_diLp_PT = new TH1F("h_ht100B_diLp_PT", "jet Met", 50, 0, 500);
    h_ht100B_diLp_PT->Sumw2();
    TH1F *h_ht100C_diLp_PT = new TH1F("h_ht100C_diLp_PT", "jet Met", 50, 0, 500);
    h_ht100C_diLp_PT->Sumw2();
    TH1F *h_ht100D_diLp_PT = new TH1F("h_ht100D_diLp_PT", "jet Met", 50, 0, 500);
    h_ht100D_diLp_PT->Sumw2();

    TH1D *h_ht200A_diLp_PT = new TH1D("h_ht200A_diLp_PT", "jet Met", 50, 0, 500);
    h_ht200A_diLp_PT->Sumw2();
    TH1F *h_ht200B_diLp_PT = new TH1F("h_ht200B_diLp_PT", "jet Met", 50, 0, 500);
    h_ht200B_diLp_PT->Sumw2();
    TH1F *h_ht200C_diLp_PT = new TH1F("h_ht200C_diLp_PT", "jet Met", 50, 0, 500);
    h_ht200C_diLp_PT->Sumw2();
    TH1F *h_ht200D_diLp_PT = new TH1F("h_ht200D_diLp_PT", "jet Met", 50, 0, 500);
    h_ht200D_diLp_PT->Sumw2();

    TH1D *h_ht400A_diLp_PT = new TH1D("h_ht400A_diLp_PT", "jet Met", 50, 0, 500);
    h_ht400A_diLp_PT->Sumw2();
    TH1F *h_ht400B_diLp_PT = new TH1F("h_ht400B_diLp_PT", "jet Met", 50, 0, 500);
    h_ht400B_diLp_PT->Sumw2();
    TH1F *h_ht400C_diLp_PT = new TH1F("h_ht400C_diLp_PT", "jet Met", 50, 0, 500);
    h_ht400C_diLp_PT->Sumw2();
    TH1F *h_ht400D_diLp_PT = new TH1F("h_ht400D_diLp_PT", "jet Met", 50, 0, 500);
    h_ht400D_diLp_PT->Sumw2();

    TH1D *h_ht600A_diLp_PT = new TH1D("h_ht600A_diLp_PT", "jet Met", 50, 0, 500);
    h_ht600A_diLp_PT->Sumw2();
    TH1F *h_ht600B_diLp_PT = new TH1F("h_ht600B_diLp_PT", "jet Met", 50, 0, 500);
    h_ht600B_diLp_PT->Sumw2();
    TH1F *h_ht600C_diLp_PT = new TH1F("h_ht600C_diLp_PT", "jet Met", 50, 0, 500);
    h_ht600C_diLp_PT->Sumw2();
    TH1F *h_ht600D_diLp_PT = new TH1F("h_ht600D_diLp_PT", "jet Met", 50, 0, 500);
    h_ht600D_diLp_PT->Sumw2();

    TH1D *h_ht800A_diLp_PT = new TH1D("h_ht800A_diLp_PT", "jet Met", 50, 0, 500);
    h_ht800A_diLp_PT->Sumw2();
    TH1F *h_ht800B_diLp_PT = new TH1F("h_ht800B_diLp_PT", "jet Met", 50, 0, 500);
    h_ht800B_diLp_PT->Sumw2();
    TH1F *h_ht800C_diLp_PT = new TH1F("h_ht800C_diLp_PT", "jet Met", 50, 0, 500);
    h_ht800C_diLp_PT->Sumw2();
    TH1F *h_ht800D_diLp_PT = new TH1F("h_ht800D_diLp_PT", "jet Met", 50, 0, 500);
    h_ht800D_diLp_PT->Sumw2();

    TH1D *h_ht1200A_diLp_PT = new TH1D("h_ht1200A_diLp_PT", "jet Met", 50, 0, 500);
    h_ht1200A_diLp_PT->Sumw2();
    TH1F *h_ht1200B_diLp_PT = new TH1F("h_ht1200B_diLp_PT", "jet Met", 50, 0, 500);
    h_ht1200B_diLp_PT->Sumw2();
    TH1F *h_ht1200C_diLp_PT = new TH1F("h_ht1200C_diLp_PT", "jet Met", 50, 0, 500);
    h_ht1200C_diLp_PT->Sumw2();
    TH1F *h_ht1200D_diLp_PT = new TH1F("h_ht1200D_diLp_PT", "jet Met", 50, 0, 500);
    h_ht1200D_diLp_PT->Sumw2();

    TH1D *h_ht2500A_diLp_PT = new TH1D("h_ht2500A_diLp_PT", "jet Met", 50, 0, 500);
    h_ht2500A_diLp_PT->Sumw2();
    TH1F *h_ht2500B_diLp_PT = new TH1F("h_ht2500B_diLp_PT", "jet Met", 50, 0, 500);
    h_ht2500B_diLp_PT->Sumw2();
    TH1F *h_ht2500C_diLp_PT = new TH1F("h_ht2500C_diLp_PT", "jet Met", 50, 0, 500);
    h_ht2500C_diLp_PT->Sumw2();
    TH1F *h_ht2500D_diLp_PT = new TH1F("h_ht2500D_diLp_PT", "jet Met", 50, 0, 500);
    h_ht2500D_diLp_PT->Sumw2();

    // Define the HTWeight
    float HT0Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT0CS / (HT0_70_event)) * 1000;
    float HT70Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT70CS / (HT70_100_event)) * 1000;
    float HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000;
    float HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000;
    float HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000;
    float HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000;
    float HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000;
    float HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000;
    float HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000;

    float_t HT;

    Double_t f_ht0_alphamin, f_ht70_alphamin, f_ht100_alphamin, f_ht200_alphamin, f_ht400_alphamin,
        f_ht600_alphamin, f_ht800_alphamin, f_ht1200_alphamin, f_ht2500_alphamin;
    float_t f_ht0_Met, f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;
    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    float_t f_ht0_leadJetpt, f_ht70_leadJetpt, f_ht100_leadJetpt, f_ht200_leadJetpt, f_ht400_leadJetpt, f_ht600_leadJetpt,
        f_ht800_leadJetpt, f_ht1200_leadJetpt, f_ht2500_leadJetpt;

    float_t f_ht0_leadJeteta, f_ht70_leadJeteta, f_ht100_leadJeteta, f_ht200_leadJeteta, f_ht400_leadJeteta, f_ht600_leadJeteta,
        f_ht800_leadJeteta, f_ht1200_leadJeteta, f_ht2500_leadJeteta;

    float_t f_ht0_dilpPT, f_ht70_dilpPT, f_ht100_dilpPT, f_ht200_dilpPT, f_ht400_dilpPT, f_ht600_dilpPT,
        f_ht800_dilpPT, f_ht1200_dilpPT, f_ht2500_dilpPT;

    TTree *T_event;
    DYincli->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &I_ht0_weight);
    T_event->SetBranchAddress("f_alphamin", &f_ht0_alphamin);
    T_event->SetBranchAddress("f_Met", &f_ht0_Met);
    T_event->SetBranchAddress("f_HT", &HT);
    T_event->SetBranchAddress("f_leadJetpt", &f_ht0_leadJetpt);
    T_event->SetBranchAddress("f_leadJeteta", &f_ht0_leadJeteta);
    T_event->SetBranchAddress("f_dileptonPT", &f_ht0_dilpPT);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (HT < 70)
        {
            if (f_ht0_alphamin > 0.3 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht0A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                h_ht0A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT0Weight / background(f_ht0_dilpPT));
                h_ht0A_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT0Weight / background(f_ht0_leadJetpt));
                h_ht0A_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT0Weight / background(f_ht0_leadJeteta));
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht0B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT0Weight);
                h_ht0B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT0Weight);
                h_ht0B_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT0Weight);
                h_ht0B_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT0Weight);
            }
            else if (f_ht0_alphamin > 0.3 && f_ht0_Met < 100)
            {
                h_ht0C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT0Weight);
                h_ht0C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT0Weight);
                h_ht0C_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT0Weight);
                h_ht0C_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT0Weight);
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
            {
                h_ht0D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT0Weight);
                h_ht0D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT0Weight);
                h_ht0D_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT0Weight);
                h_ht0D_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT0Weight);
            }
        }
        else if (HT > 70 && HT < 100)
        {

            if (f_ht0_alphamin > 0.3 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht70A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                h_ht70A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT70Weight / background(f_ht0_dilpPT));
                h_ht70A_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT70Weight / background(f_ht0_leadJetpt));
                h_ht70A_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT70Weight / background(f_ht0_leadJeteta));
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht70B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT70Weight);
                h_ht70B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT70Weight);
                h_ht70B_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT70Weight);
                h_ht70B_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT70Weight);
            }
            else if (f_ht0_alphamin > 0.3 && f_ht0_Met < 100)
            {
                h_ht70C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT70Weight);
                h_ht70C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT70Weight);
                h_ht70C_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT70Weight);
                h_ht70C_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT70Weight);
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
            {
                h_ht70D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT70Weight);
                h_ht70D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT70Weight);
                h_ht70D_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT70Weight);
                h_ht70D_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT70Weight);
            }
        }
        else if (HT > 100 && HT < 200)
        {
            if (f_ht0_alphamin > 0.3 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht100A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                h_ht100A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT100Weight / background(f_ht0_dilpPT));
                h_ht100A_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT100Weight / background(f_ht0_leadJetpt));
                h_ht100A_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT100Weight / background(f_ht0_leadJeteta));
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht100B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT100Weight);
                h_ht100B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT100Weight);
                h_ht100B_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT100Weight);
                h_ht100B_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT100Weight);
            }
            else if (f_ht0_alphamin > 0.3 && f_ht0_Met < 100)
            {
                h_ht100C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT100Weight);
                h_ht100C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT100Weight);
                h_ht100C_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT100Weight);
                h_ht100C_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT100Weight);
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
            {
                h_ht100D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT100Weight);
                h_ht100D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT100Weight);
                h_ht100D_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT100Weight);
                h_ht100D_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT100Weight);
            }
        }
        else if (HT > 200 && HT < 400)
        {

            if (f_ht0_alphamin > 0.3 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht200A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                h_ht200A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT200Weight / background(f_ht0_dilpPT));
                h_ht200A_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT200Weight / background(f_ht0_leadJetpt));
                h_ht200A_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT200Weight / background(f_ht0_leadJeteta));
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht200B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT200Weight);
                h_ht200B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT200Weight);
                h_ht200B_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT200Weight);
                h_ht200B_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT200Weight);
            }
            else if (f_ht0_alphamin > 0.3 && f_ht0_Met < 100)
            {
                h_ht200C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT200Weight);
                h_ht200C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT200Weight);
                h_ht200C_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT200Weight);
                h_ht200C_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT200Weight);
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
            {
                h_ht200D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT200Weight);
                h_ht200D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT200Weight);
                h_ht200D_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT200Weight);
                h_ht200D_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT200Weight);
            }
        }
        else if (HT > 400 && HT < 600)
        {

            if (f_ht0_alphamin > 0.3 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht400A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                h_ht400A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT400Weight / background(f_ht0_dilpPT));
                h_ht400A_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT400Weight / background(f_ht0_leadJetpt));
                h_ht400A_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT400Weight / background(f_ht0_leadJeteta));
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht400B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT400Weight);
                h_ht400B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT400Weight);
                h_ht400B_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT400Weight);
                h_ht400B_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT400Weight);
            }
            else if (f_ht0_alphamin > 0.3 && f_ht0_Met < 100)
            {
                h_ht400C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT400Weight);
                h_ht400C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT400Weight);
                h_ht400C_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT400Weight);
                h_ht400C_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT400Weight);
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
            {
                h_ht400D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT400Weight);
                h_ht400D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT400Weight);
                h_ht400D_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT400Weight);
                h_ht400D_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT400Weight);
            }
        }
        else if (HT > 600 && HT < 800)
        {

            if (f_ht0_alphamin > 0.3 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht600A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                h_ht600A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT600Weight / background(f_ht0_dilpPT));
                h_ht600A_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT600Weight / background(f_ht0_leadJetpt));
                h_ht600A_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT600Weight / background(f_ht0_leadJeteta));
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht600B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT600Weight);
                h_ht600B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT600Weight);
                h_ht600B_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT600Weight);
                h_ht600B_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT600Weight);
            }
            else if (f_ht0_alphamin > 0.3 && f_ht0_Met < 100)
            {
                h_ht600C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT600Weight);
                h_ht600C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT600Weight);
                h_ht600C_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT600Weight);
                h_ht600C_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT600Weight);
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
            {
                h_ht600D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT600Weight);
                h_ht600D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT600Weight);
                h_ht600D_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT600Weight);
                h_ht600D_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT600Weight);
            }
        }
        else if (HT > 800 && HT < 1200)
        {

            if (f_ht0_alphamin > 0.3 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht800A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                h_ht800A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT800Weight / background(f_ht0_dilpPT));
                h_ht800A_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT800Weight / background(f_ht0_leadJetpt));
                h_ht800A_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT800Weight / background(f_ht0_leadJeteta));
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht800B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT800Weight);
                h_ht800B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT800Weight);
                h_ht800B_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT800Weight);
                h_ht800B_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT800Weight);
            }
            else if (f_ht0_alphamin > 0.3 && f_ht0_Met < 100)
            {
                h_ht800C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT800Weight);
                h_ht800C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT800Weight);
                h_ht800C_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT800Weight);
                h_ht800C_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT800Weight);
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
            {
                h_ht800D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT800Weight);
                h_ht800D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT800Weight);
                h_ht800D_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT800Weight);
                h_ht800D_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT800Weight);
            }
        }
        else if (HT > 1200 && HT < 2500)
        {

            if (f_ht0_alphamin > 0.3 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht1200A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                h_ht1200A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT1200Weight / background(f_ht0_dilpPT));
                h_ht1200A_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT1200Weight / background(f_ht0_leadJetpt));
                h_ht1200A_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT1200Weight / background(f_ht0_leadJeteta));
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht1200B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT1200Weight);
                h_ht1200B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT1200Weight);
                h_ht1200B_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT1200Weight);
                h_ht1200B_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT1200Weight);
            }
            else if (f_ht0_alphamin > 0.3 && f_ht0_Met < 100)
            {
                h_ht1200C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT1200Weight);
                h_ht1200C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT1200Weight);
                h_ht1200C_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT1200Weight);
                h_ht1200C_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT1200Weight);
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
            {
                h_ht1200D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT1200Weight);
                h_ht1200D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT1200Weight);
                h_ht1200D_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT1200Weight);
                h_ht1200D_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT1200Weight);
            }
        }
        else if (HT > 2500)
        {
            if (f_ht0_alphamin > 0.3 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht2500A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                h_ht2500A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT2500Weight / background(f_ht0_dilpPT));
                h_ht2500A_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT2500Weight / background(f_ht0_leadJetpt));
                h_ht2500A_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT2500Weight / background(f_ht0_leadJeteta));
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160 && f_ht0_Met < 800)
            {
                h_ht2500B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT2500Weight);
                h_ht2500B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT2500Weight);
                h_ht2500B_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT2500Weight);
                h_ht2500B_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT2500Weight);
            }
            else if (f_ht0_alphamin > 0.3 && f_ht0_Met < 100)
            {
                h_ht2500C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT2500Weight);
                h_ht2500C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT2500Weight);
                h_ht2500C_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT2500Weight);
                h_ht2500C_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT2500Weight);
            }
            else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
            {
                h_ht2500D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT2500Weight);
                h_ht2500D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT2500Weight);
                h_ht2500D_jetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT2500Weight);
                h_ht2500D_jeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT2500Weight);
            }
        }
    } // End of inclusive sample

    TTree *T_event1;
    DYHT100->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_leadJeteta", &f_ht100_leadJeteta);
    T_event1->SetBranchAddress("f_leadJetpt", &f_ht100_leadJetpt);
    T_event1->SetBranchAddress("f_alphamin", &f_ht100_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_ht100_Met);
    T_event1->SetBranchAddress("f_dileptonPT", &f_ht100_dilpPT);
    T_event1->SetBranchAddress("I_weight", &I_ht100_weight);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);

        if (f_ht100_alphamin > 0.3 && f_ht100_Met > 160 && f_ht100_Met < 800)
        {
            h_ht100A_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight / background(f_ht100_Met));
            h_ht100A_diLp_PT->Fill(f_ht100_dilpPT, I_ht100_weight * HT100Weight / background(f_ht100_dilpPT));
            h_ht100A_jetpt->Fill(f_ht100_leadJetpt, I_ht100_weight * HT100Weight / background(f_ht100_leadJetpt));
            h_ht100A_jeteta->Fill(f_ht100_leadJeteta, I_ht100_weight * HT100Weight / background(f_ht100_leadJeteta));
        }
        else if (f_ht100_alphamin < 0.1 && f_ht100_Met > 160 && f_ht100_Met < 800)
        {
            h_ht100B_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
            h_ht100B_diLp_PT->Fill(f_ht100_dilpPT, I_ht100_weight * HT100Weight);
            h_ht100B_jetpt->Fill(f_ht100_leadJetpt, I_ht100_weight * HT100Weight);
            h_ht100B_jeteta->Fill(f_ht100_leadJeteta, I_ht100_weight * HT100Weight);
        }
        else if (f_ht100_alphamin > 0.3 && f_ht100_Met < 100)
        {
            h_ht100C_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
            h_ht100C_diLp_PT->Fill(f_ht100_dilpPT, I_ht100_weight * HT100Weight);
            h_ht100C_jetpt->Fill(f_ht100_leadJetpt, I_ht100_weight * HT100Weight);
            h_ht100C_jeteta->Fill(f_ht100_leadJeteta, I_ht100_weight * HT100Weight);
        }
        else if (f_ht100_alphamin < 0.1 && f_ht100_Met < 100)
        {
            h_ht100D_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
            h_ht100D_diLp_PT->Fill(f_ht100_dilpPT, I_ht100_weight * HT100Weight);
            h_ht100D_jetpt->Fill(f_ht100_leadJetpt, I_ht100_weight * HT100Weight);
            h_ht100D_jeteta->Fill(f_ht100_leadJeteta, I_ht100_weight * HT100Weight);
        }
    } // End of HT100

    TTree *T_event2;
    DYHT200->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_leadJeteta", &f_ht200_leadJeteta);
    T_event2->SetBranchAddress("f_leadJetpt", &f_ht200_leadJetpt);
    T_event2->SetBranchAddress("f_alphamin", &f_ht200_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_ht200_Met);
    T_event2->SetBranchAddress("f_dileptonPT", &f_ht200_dilpPT);
    T_event2->SetBranchAddress("I_weight", &I_ht200_weight);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);

        if (f_ht200_alphamin > 0.3 && f_ht200_Met > 160 && f_ht200_Met < 800)
        {
            h_ht200A_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight / background(f_ht200_Met));
            h_ht200A_diLp_PT->Fill(f_ht200_dilpPT, I_ht200_weight * HT200Weight / background(f_ht200_dilpPT));
            h_ht200A_jetpt->Fill(f_ht200_leadJetpt, I_ht200_weight * HT200Weight / background(f_ht200_leadJetpt));
            h_ht200A_jeteta->Fill(f_ht200_leadJeteta, I_ht200_weight * HT200Weight / background(f_ht200_leadJeteta));
        }
        else if (f_ht200_alphamin < 0.1 && f_ht200_Met > 160 && f_ht200_Met < 800)
        {
            h_ht200B_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
            h_ht200B_diLp_PT->Fill(f_ht200_dilpPT, I_ht200_weight * HT200Weight);
            h_ht200B_jetpt->Fill(f_ht200_leadJetpt, I_ht200_weight * HT200Weight);
            h_ht200B_jeteta->Fill(f_ht200_leadJeteta, I_ht200_weight * HT200Weight);
        }
        else if (f_ht200_alphamin > 0.3 && f_ht200_Met < 100)
        {
            h_ht200C_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
            h_ht200C_diLp_PT->Fill(f_ht200_dilpPT, I_ht200_weight * HT200Weight);
            h_ht200C_jetpt->Fill(f_ht200_leadJetpt, I_ht200_weight * HT200Weight);
            h_ht200C_jeteta->Fill(f_ht200_leadJeteta, I_ht200_weight * HT200Weight);
        }
        else if (f_ht200_alphamin < 0.1 && f_ht200_Met < 100)
        {
            h_ht200D_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
            h_ht200D_diLp_PT->Fill(f_ht200_dilpPT, I_ht200_weight * HT200Weight);
            h_ht200D_jetpt->Fill(f_ht200_leadJetpt, I_ht200_weight * HT200Weight);
            h_ht200D_jeteta->Fill(f_ht200_leadJeteta, I_ht200_weight * HT200Weight);
        }

    } // End of HT200

    TTree *T_event3;
    DYHT400->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_leadJeteta", &f_ht400_leadJeteta);
    T_event3->SetBranchAddress("f_leadJetpt", &f_ht400_leadJetpt);
    T_event3->SetBranchAddress("f_alphamin", &f_ht400_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_ht400_Met);
    T_event3->SetBranchAddress("f_dileptonPT", &f_ht400_dilpPT);
    T_event3->SetBranchAddress("I_weight", &I_ht400_weight);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);

        if (f_ht400_alphamin > 0.3 && f_ht400_Met > 160 && f_ht400_Met < 800)
        {
            h_ht400A_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight / background(f_ht400_Met));
            h_ht400A_diLp_PT->Fill(f_ht400_dilpPT, I_ht400_weight * HT400Weight / background(f_ht400_dilpPT));
            h_ht400A_jetpt->Fill(f_ht400_leadJetpt, I_ht400_weight * HT400Weight / background(f_ht400_leadJetpt));
            h_ht400A_jeteta->Fill(f_ht400_leadJeteta, I_ht400_weight * HT400Weight / background(f_ht400_leadJeteta));
        }
        else if (f_ht400_alphamin < 0.1 && f_ht400_Met > 160 && f_ht400_Met < 800)
        {
            h_ht400B_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
            h_ht400B_diLp_PT->Fill(f_ht400_dilpPT, I_ht400_weight * HT400Weight);
            h_ht400B_jetpt->Fill(f_ht400_leadJetpt, I_ht400_weight * HT400Weight);
            h_ht400B_jeteta->Fill(f_ht400_leadJeteta, I_ht400_weight * HT400Weight);
        }
        else if (f_ht400_alphamin > 0.3 && f_ht400_Met < 100)
        {
            h_ht400C_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
            h_ht400C_diLp_PT->Fill(f_ht400_dilpPT, I_ht400_weight * HT400Weight);
            h_ht400C_jetpt->Fill(f_ht400_leadJetpt, I_ht400_weight * HT400Weight);
            h_ht400C_jeteta->Fill(f_ht400_leadJeteta, I_ht400_weight * HT400Weight);
        }
        else if (f_ht400_alphamin < 0.1 && f_ht400_Met < 100)
        {
            h_ht400D_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
            h_ht400D_diLp_PT->Fill(f_ht400_dilpPT, I_ht400_weight * HT400Weight);
            h_ht400D_jetpt->Fill(f_ht400_leadJetpt, I_ht400_weight * HT400Weight);
            h_ht400D_jeteta->Fill(f_ht400_leadJeteta, I_ht400_weight * HT400Weight);
        }
    } // End of HT400

    TTree *T_event4;
    DYHT600->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_leadJeteta", &f_ht600_leadJeteta);
    T_event4->SetBranchAddress("f_leadJetpt", &f_ht600_leadJetpt);
    T_event4->SetBranchAddress("f_alphamin", &f_ht600_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_ht600_Met);
    T_event4->SetBranchAddress("f_dileptonPT", &f_ht600_dilpPT);
    T_event4->SetBranchAddress("I_weight", &I_ht600_weight);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);

        if (f_ht600_alphamin > 0.3 && f_ht600_Met > 160 && f_ht600_Met < 800)
        {
            h_ht600A_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight / background(f_ht600_Met));
            h_ht600A_diLp_PT->Fill(f_ht600_dilpPT, I_ht600_weight * HT600Weight / background(f_ht600_dilpPT));
            h_ht600A_jetpt->Fill(f_ht600_leadJetpt, I_ht600_weight * HT600Weight / background(f_ht600_leadJetpt));
            h_ht600A_jeteta->Fill(f_ht600_leadJeteta, I_ht600_weight * HT600Weight / background(f_ht600_leadJeteta));
        }
        else if (f_ht600_alphamin < 0.1 && f_ht600_Met > 160 && f_ht600_Met < 800)
        {
            h_ht600B_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
            h_ht600B_diLp_PT->Fill(f_ht600_dilpPT, I_ht600_weight * HT600Weight);
            h_ht600B_jetpt->Fill(f_ht600_leadJetpt, I_ht600_weight * HT600Weight);
            h_ht600B_jeteta->Fill(f_ht600_leadJeteta, I_ht600_weight * HT600Weight);
        }
        else if (f_ht600_alphamin > 0.3 && f_ht600_Met < 100)
        {
            h_ht600C_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
            h_ht600C_diLp_PT->Fill(f_ht600_dilpPT, I_ht600_weight * HT600Weight);
            h_ht600C_jetpt->Fill(f_ht600_leadJetpt, I_ht600_weight * HT600Weight);
            h_ht600C_jeteta->Fill(f_ht600_leadJeteta, I_ht600_weight * HT600Weight);
        }
        else if (f_ht600_alphamin < 0.1 && f_ht600_Met < 100)
        {
            h_ht600D_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
            h_ht600D_diLp_PT->Fill(f_ht600_dilpPT, I_ht600_weight * HT600Weight);
            h_ht600D_jetpt->Fill(f_ht600_leadJetpt, I_ht600_weight * HT600Weight);
            h_ht600D_jeteta->Fill(f_ht600_leadJeteta, I_ht600_weight * HT600Weight);
        }

    } // End of HT600

    TTree *T_event5;
    DYHT800->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_leadJeteta", &f_ht800_leadJeteta);
    T_event5->SetBranchAddress("f_leadJetpt", &f_ht800_leadJetpt);
    T_event5->SetBranchAddress("f_alphamin", &f_ht800_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_ht800_Met);
    T_event5->SetBranchAddress("f_dileptonPT", &f_ht800_dilpPT);
    T_event5->SetBranchAddress("I_weight", &I_ht800_weight);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);

        if (f_ht800_alphamin > 0.3 && f_ht800_Met > 160 && f_ht800_Met < 800)
        {
            h_ht800A_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight / background(f_ht800_Met));
            h_ht800A_diLp_PT->Fill(f_ht800_dilpPT, I_ht800_weight * HT800Weight / background(f_ht800_dilpPT));
            h_ht800A_jetpt->Fill(f_ht800_leadJetpt, I_ht800_weight * HT800Weight / background(f_ht800_leadJetpt));
            h_ht800A_jeteta->Fill(f_ht800_leadJeteta, I_ht800_weight * HT800Weight / background(f_ht800_leadJeteta));
        }
        else if (f_ht800_alphamin < 0.1 && f_ht800_Met > 160 && f_ht800_Met < 800)
        {
            h_ht800B_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
            h_ht800B_diLp_PT->Fill(f_ht800_dilpPT, I_ht800_weight * HT800Weight);
            h_ht800B_jetpt->Fill(f_ht800_leadJetpt, I_ht800_weight * HT800Weight);
            h_ht800B_jeteta->Fill(f_ht800_leadJeteta, I_ht800_weight * HT800Weight);
        }
        else if (f_ht800_alphamin > 0.3 && f_ht800_Met < 100)
        {
            h_ht800C_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
            h_ht800C_diLp_PT->Fill(f_ht800_dilpPT, I_ht800_weight * HT800Weight);
            h_ht800C_jetpt->Fill(f_ht800_leadJetpt, I_ht800_weight * HT800Weight);
            h_ht800C_jeteta->Fill(f_ht800_leadJeteta, I_ht800_weight * HT800Weight);
        }
        else if (f_ht800_alphamin < 0.1 && f_ht800_Met < 100)
        {
            h_ht800D_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
            h_ht800D_diLp_PT->Fill(f_ht800_dilpPT, I_ht800_weight * HT800Weight);
            h_ht800D_jetpt->Fill(f_ht800_leadJetpt, I_ht800_weight * HT800Weight);
            h_ht800D_jeteta->Fill(f_ht800_leadJeteta, I_ht800_weight * HT800Weight);
        }
    } // End of HT800

    TTree *T_event6;
    DYHT1200->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_leadJeteta", &f_ht1200_leadJeteta);
    T_event6->SetBranchAddress("f_leadJetpt", &f_ht1200_leadJetpt);
    T_event6->SetBranchAddress("f_alphamin", &f_ht1200_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_ht1200_Met);
    T_event6->SetBranchAddress("f_dileptonPT", &f_ht1200_dilpPT);
    T_event6->SetBranchAddress("I_weight", &I_ht1200_weight);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);

        if (f_ht1200_alphamin > 0.3 && f_ht1200_Met > 160 && f_ht1200_Met < 800)
        {
            h_ht1200A_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
            h_ht1200A_diLp_PT->Fill(f_ht1200_dilpPT, I_ht1200_weight * HT1200Weight / background(f_ht1200_dilpPT));
            h_ht1200A_jetpt->Fill(f_ht1200_leadJetpt, I_ht1200_weight * HT1200Weight / background(f_ht1200_leadJetpt));
            h_ht1200A_jeteta->Fill(f_ht1200_leadJeteta, I_ht1200_weight * HT1200Weight / background(f_ht1200_leadJeteta));
        }
        else if (f_ht1200_alphamin < 0.1 && f_ht1200_Met > 160 && f_ht1200_Met < 800)
        {
            h_ht1200B_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
            h_ht1200B_diLp_PT->Fill(f_ht1200_dilpPT, I_ht1200_weight * HT1200Weight);
            h_ht1200B_jetpt->Fill(f_ht1200_leadJetpt, I_ht1200_weight * HT1200Weight);
            h_ht1200B_jeteta->Fill(f_ht1200_leadJeteta, I_ht1200_weight * HT1200Weight);
        }
        else if (f_ht1200_alphamin > 0.3 && f_ht1200_Met < 100)
        {

            h_ht1200C_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
            h_ht1200C_diLp_PT->Fill(f_ht1200_dilpPT, I_ht1200_weight * HT1200Weight);
            h_ht1200C_jetpt->Fill(f_ht1200_leadJetpt, I_ht1200_weight * HT1200Weight);
            h_ht1200C_jeteta->Fill(f_ht1200_leadJeteta, I_ht1200_weight * HT1200Weight);
        }
        else if (f_ht1200_alphamin < 0.1 && f_ht1200_Met < 100)
        {
            h_ht1200D_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
            h_ht1200D_diLp_PT->Fill(f_ht1200_dilpPT, I_ht1200_weight * HT1200Weight);
            h_ht1200D_jetpt->Fill(f_ht1200_leadJetpt, I_ht1200_weight * HT1200Weight);
            h_ht1200D_jeteta->Fill(f_ht1200_leadJeteta, I_ht1200_weight * HT1200Weight);
        }

    } // End of HT1200

    TTree *T_event7;
    DYHT2500->GetObject("T_event", T_event7);
    T_event7->SetBranchAddress("f_leadJeteta", &f_ht2500_leadJeteta);
    T_event7->SetBranchAddress("f_leadJetpt", &f_ht2500_leadJetpt);
    T_event7->SetBranchAddress("f_alphamin", &f_ht2500_alphamin);
    T_event7->SetBranchAddress("f_Met", &f_ht2500_Met);
    T_event7->SetBranchAddress("f_dileptonPT", &f_ht2500_dilpPT);
    T_event7->SetBranchAddress("I_weight", &I_ht2500_weight);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);

        if (f_ht2500_alphamin > 0.3 && f_ht2500_Met > 160 && f_ht2500_Met < 800)
        {
            h_ht2500A_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
            h_ht2500A_diLp_PT->Fill(f_ht2500_dilpPT, I_ht2500_weight * HT2500Weight / background(f_ht2500_dilpPT));
            h_ht2500A_jetpt->Fill(f_ht2500_leadJetpt, I_ht2500_weight * HT2500Weight / background(f_ht2500_leadJetpt));
            h_ht2500A_jeteta->Fill(f_ht2500_leadJeteta, I_ht2500_weight * HT2500Weight / background(f_ht2500_leadJeteta));
        }
        else if (f_ht2500_alphamin < 0.1 && f_ht2500_Met > 160 && f_ht2500_Met < 800)
        {
            h_ht2500B_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
            h_ht2500B_diLp_PT->Fill(f_ht2500_dilpPT, I_ht2500_weight * HT2500Weight);
            h_ht2500B_jetpt->Fill(f_ht2500_leadJetpt, I_ht2500_weight * HT2500Weight);
            h_ht2500B_jeteta->Fill(f_ht2500_leadJeteta, I_ht2500_weight * HT2500Weight);
        }
        else if (f_ht2500_alphamin > 0.3 && f_ht2500_Met < 100)
        {
            h_ht2500C_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
            h_ht2500C_diLp_PT->Fill(f_ht2500_dilpPT, I_ht2500_weight * HT2500Weight);
            h_ht2500C_jetpt->Fill(f_ht2500_leadJetpt, I_ht2500_weight * HT2500Weight);
            h_ht2500C_jeteta->Fill(f_ht2500_leadJeteta, I_ht2500_weight * HT2500Weight);
        }
        else if (f_ht2500_alphamin < 0.1 && f_ht2500_Met < 100)
        {
            h_ht2500D_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
            h_ht2500D_diLp_PT->Fill(f_ht2500_dilpPT, I_ht2500_weight * HT2500Weight);
            h_ht2500D_jetpt->Fill(f_ht2500_leadJetpt, I_ht2500_weight * HT2500Weight);
            h_ht2500D_jeteta->Fill(f_ht2500_leadJeteta, I_ht2500_weight * HT2500Weight);
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

    h_ht0A_diLp_PT->Add(h_ht70A_diLp_PT);
    h_ht0A_diLp_PT->Add(h_ht100A_diLp_PT);
    h_ht0A_diLp_PT->Add(h_ht200A_diLp_PT);
    h_ht0A_diLp_PT->Add(h_ht400A_diLp_PT);
    h_ht0A_diLp_PT->Add(h_ht600A_diLp_PT);
    h_ht0A_diLp_PT->Add(h_ht800A_diLp_PT);
    h_ht0A_diLp_PT->Add(h_ht1200A_diLp_PT);
    h_ht0A_diLp_PT->Add(h_ht2500A_diLp_PT);

    h_ht0B_diLp_PT->Add(h_ht70B_diLp_PT);
    h_ht0B_diLp_PT->Add(h_ht100B_diLp_PT);
    h_ht0B_diLp_PT->Add(h_ht200B_diLp_PT);
    h_ht0B_diLp_PT->Add(h_ht400B_diLp_PT);
    h_ht0B_diLp_PT->Add(h_ht600B_diLp_PT);
    h_ht0B_diLp_PT->Add(h_ht800B_diLp_PT);
    h_ht0B_diLp_PT->Add(h_ht1200B_diLp_PT);
    h_ht0B_diLp_PT->Add(h_ht2500B_diLp_PT);

    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(2, 1);
    c1->cd(1);
    gStyle->SetOptStat(0);
    h_ht0B_jetmet->SetTitle("Met");
    h_ht0B_jetmet->SetXTitle("Met");
    h_ht0B_jetmet->SetYTitle("");
    h_ht0B_jetmet->SetLineWidth(2);
    h_ht0A_jetmet->SetLineWidth(2);
    h_ht0A_jetmet->SetLineColor(kOrange + 7);
    // h_ht0A_jetpt->SetFillColor(kOrange + 7);
    h_ht0B_jetmet->SetLineColor(kGray + 3);
    // h_ht0B_jetpt->SetFillColor(kGray + 3);
    // h_ht0B_jetmet->Draw("hist&&E");
    h_ht0B_jetmet->DrawNormalized("hist&&E");
    h_ht0A_jetmet->DrawNormalized("hist&&E&&same");

    TLegend *l1 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_ht0A_jetmet, "Region A /Ratio", "l");
    l1->AddEntry(h_ht0B_jetmet, "Region B (SR) ", "l");
    l1->Draw();
    c1->cd(2);
    gStyle->SetOptStat(0);
    h_ht0A_jeteta->SetTitle("");
    h_ht0B_jeteta->SetXTitle("Leading Jet eta");
    h_ht0B_jeteta->SetYTitle("Normalized");
    h_ht0A_jeteta->SetLineWidth(2);
    h_ht0B_jeteta->SetLineWidth(2);
    h_ht0A_jeteta->SetLineColor(kOrange + 7);
    
    h_ht0B_jeteta->SetLineColor(kGray + 3);

    h_ht0B_jeteta->DrawNormalized("hist");
    h_ht0A_jeteta->DrawNormalized("hist&&same");
    // h_ht0A_jetpt->Divide(h_ht0B_jetpt);
    // h_ht0D_jetpt->SetTitle("D*Ratio");
    // h_ht0D_jetpt->SetXTitle("Jet PT");
    // h_ht0D_jetpt->DrawNormalized("hist");

    TLegend *l4 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.04);
    l4->AddEntry(h_ht0A_jeteta, "Region A / Ratio", "l");
    l4->AddEntry(h_ht0B_jeteta, "Region B (SR)", "l");
    l4->Draw();
}
