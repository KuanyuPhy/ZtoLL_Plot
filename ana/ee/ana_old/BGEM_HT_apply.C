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
    double par0 = 9.01203e-02;
    double par1 = -1.68788e-03;
    double par2 = -1.28635e-04;
    double par3 = 1.70366e+00;
    double par4 = 3.90493e-03;
    double par5 = -5.80040e-06;
    //double par6 = 6.19540e-08;

    // Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 * x * x + par4 * x + par5);
    // Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 + par4 * x + par5 * x * x + par6 * x * x * x);
    Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 + par4 * x + par5 * x * x);
    return weight;
}
void BGEM_HT_apply()
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
    TH1F *h_ht0A_leadjetpt = new TH1F("h_ht0A_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht0A_leadjetpt->Sumw2();
    TH1F *h_ht0B_leadjetpt = new TH1F("h_ht0B_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht0B_leadjetpt->Sumw2();
    TH1F *h_ht0C_leadjetpt = new TH1F("h_ht0C_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht0C_leadjetpt->Sumw2();
    TH1F *h_ht0D_leadjetpt = new TH1F("h_ht0D_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht0D_leadjetpt->Sumw2();

    TH1F *h_ht70A_leadjetpt = new TH1F("h_ht70A_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht70A_leadjetpt->Sumw2();
    TH1F *h_ht70B_leadjetpt = new TH1F("h_ht70B_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht70B_leadjetpt->Sumw2();
    TH1F *h_ht70C_leadjetpt = new TH1F("h_ht70C_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht70C_leadjetpt->Sumw2();
    TH1F *h_ht70D_leadjetpt = new TH1F("h_ht70D_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht70D_leadjetpt->Sumw2();

    TH1F *h_ht100A_leadjetpt = new TH1F("h_ht100A_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht100A_leadjetpt->Sumw2();
    TH1F *h_ht100B_leadjetpt = new TH1F("h_ht100B_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht100B_leadjetpt->Sumw2();
    TH1F *h_ht100C_leadjetpt = new TH1F("h_ht100C_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht100C_leadjetpt->Sumw2();
    TH1F *h_ht100D_leadjetpt = new TH1F("h_ht100D_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht100D_leadjetpt->Sumw2();

    TH1F *h_ht200A_leadjetpt = new TH1F("h_ht200A_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht200A_leadjetpt->Sumw2();
    TH1F *h_ht200B_leadjetpt = new TH1F("h_ht200B_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht200B_leadjetpt->Sumw2();
    TH1F *h_ht200C_leadjetpt = new TH1F("h_ht200C_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht200C_leadjetpt->Sumw2();
    TH1F *h_ht200D_leadjetpt = new TH1F("h_ht200D_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht200D_leadjetpt->Sumw2();

    TH1F *h_ht400A_leadjetpt = new TH1F("h_ht400A_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht400A_leadjetpt->Sumw2();
    TH1F *h_ht400B_leadjetpt = new TH1F("h_ht400B_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht400B_leadjetpt->Sumw2();
    TH1F *h_ht400C_leadjetpt = new TH1F("h_ht400C_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht400C_leadjetpt->Sumw2();
    TH1F *h_ht400D_leadjetpt = new TH1F("h_ht400D_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht400D_leadjetpt->Sumw2();

    TH1F *h_ht600A_leadjetpt = new TH1F("h_ht600A_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht600A_leadjetpt->Sumw2();
    TH1F *h_ht600B_leadjetpt = new TH1F("h_ht600B_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht600B_leadjetpt->Sumw2();
    TH1F *h_ht600C_leadjetpt = new TH1F("h_ht600C_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht600C_leadjetpt->Sumw2();
    TH1F *h_ht600D_leadjetpt = new TH1F("h_ht600D_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht600D_leadjetpt->Sumw2();

    TH1F *h_ht800A_leadjetpt = new TH1F("h_ht800A_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht800A_leadjetpt->Sumw2();
    TH1F *h_ht800B_leadjetpt = new TH1F("h_ht800B_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht800B_leadjetpt->Sumw2();
    TH1F *h_ht800C_leadjetpt = new TH1F("h_ht800C_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht800C_leadjetpt->Sumw2();
    TH1F *h_ht800D_leadjetpt = new TH1F("h_ht800D_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht800D_leadjetpt->Sumw2();

    TH1F *h_ht1200A_leadjetpt = new TH1F("h_ht1200A_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht1200A_leadjetpt->Sumw2();
    TH1F *h_ht1200B_leadjetpt = new TH1F("h_ht1200B_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht1200B_leadjetpt->Sumw2();
    TH1F *h_ht1200C_leadjetpt = new TH1F("h_ht1200C_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht1200C_leadjetpt->Sumw2();
    TH1F *h_ht1200D_leadjetpt = new TH1F("h_ht1200D_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht1200D_leadjetpt->Sumw2();

    TH1F *h_ht2500A_leadjetpt = new TH1F("h_ht2500A_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht2500A_leadjetpt->Sumw2();
    TH1F *h_ht2500B_leadjetpt = new TH1F("h_ht2500B_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht2500B_leadjetpt->Sumw2();
    TH1F *h_ht2500C_leadjetpt = new TH1F("h_ht2500C_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht2500C_leadjetpt->Sumw2();
    TH1F *h_ht2500D_leadjetpt = new TH1F("h_ht2500D_leadjetpt", "leading Jet PT", 10, 0, 1000);
    h_ht2500D_leadjetpt->Sumw2();

    TH1F *h_ht0A_minjetpt = new TH1F("h_ht0A_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht0A_minjetpt->Sumw2();
    TH1F *h_ht0B_minjetpt = new TH1F("h_ht0B_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht0B_minjetpt->Sumw2();
    TH1F *h_ht0C_minjetpt = new TH1F("h_ht0C_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht0C_minjetpt->Sumw2();
    TH1F *h_ht0D_minjetpt = new TH1F("h_ht0D_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht0D_minjetpt->Sumw2();

    TH1F *h_ht70A_minjetpt = new TH1F("h_ht70A_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht70A_minjetpt->Sumw2();
    TH1F *h_ht70B_minjetpt = new TH1F("h_ht70B_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht70B_minjetpt->Sumw2();
    TH1F *h_ht70C_minjetpt = new TH1F("h_ht70C_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht70C_minjetpt->Sumw2();
    TH1F *h_ht70D_minjetpt = new TH1F("h_ht70D_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht70D_minjetpt->Sumw2();

    TH1F *h_ht100A_minjetpt = new TH1F("h_ht100A_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht100A_minjetpt->Sumw2();
    TH1F *h_ht100B_minjetpt = new TH1F("h_ht100B_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht100B_minjetpt->Sumw2();
    TH1F *h_ht100C_minjetpt = new TH1F("h_ht100C_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht100C_minjetpt->Sumw2();
    TH1F *h_ht100D_minjetpt = new TH1F("h_ht100D_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht100D_minjetpt->Sumw2();

    TH1F *h_ht200A_minjetpt = new TH1F("h_ht200A_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht200A_minjetpt->Sumw2();
    TH1F *h_ht200B_minjetpt = new TH1F("h_ht200B_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht200B_minjetpt->Sumw2();
    TH1F *h_ht200C_minjetpt = new TH1F("h_ht200C_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht200C_minjetpt->Sumw2();
    TH1F *h_ht200D_minjetpt = new TH1F("h_ht200D_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht200D_minjetpt->Sumw2();

    TH1F *h_ht400A_minjetpt = new TH1F("h_ht400A_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht400A_minjetpt->Sumw2();
    TH1F *h_ht400B_minjetpt = new TH1F("h_ht400B_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht400B_minjetpt->Sumw2();
    TH1F *h_ht400C_minjetpt = new TH1F("h_ht400C_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht400C_minjetpt->Sumw2();
    TH1F *h_ht400D_minjetpt = new TH1F("h_ht400D_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht400D_minjetpt->Sumw2();

    TH1F *h_ht600A_minjetpt = new TH1F("h_ht600A_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht600A_minjetpt->Sumw2();
    TH1F *h_ht600B_minjetpt = new TH1F("h_ht600B_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht600B_minjetpt->Sumw2();
    TH1F *h_ht600C_minjetpt = new TH1F("h_ht600C_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht600C_minjetpt->Sumw2();
    TH1F *h_ht600D_minjetpt = new TH1F("h_ht600D_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht600D_minjetpt->Sumw2();

    TH1F *h_ht800A_minjetpt = new TH1F("h_ht800A_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht800A_minjetpt->Sumw2();
    TH1F *h_ht800B_minjetpt = new TH1F("h_ht800B_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht800B_minjetpt->Sumw2();
    TH1F *h_ht800C_minjetpt = new TH1F("h_ht800C_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht800C_minjetpt->Sumw2();
    TH1F *h_ht800D_minjetpt = new TH1F("h_ht800D_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht800D_minjetpt->Sumw2();

    TH1F *h_ht1200A_minjetpt = new TH1F("h_ht1200A_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht1200A_minjetpt->Sumw2();
    TH1F *h_ht1200B_minjetpt = new TH1F("h_ht1200B_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht1200B_minjetpt->Sumw2();
    TH1F *h_ht1200C_minjetpt = new TH1F("h_ht1200C_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht1200C_minjetpt->Sumw2();
    TH1F *h_ht1200D_minjetpt = new TH1F("h_ht1200D_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht1200D_minjetpt->Sumw2();

    TH1F *h_ht2500A_minjetpt = new TH1F("h_ht2500A_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht2500A_minjetpt->Sumw2();
    TH1F *h_ht2500B_minjetpt = new TH1F("h_ht2500B_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht2500B_minjetpt->Sumw2();
    TH1F *h_ht2500C_minjetpt = new TH1F("h_ht2500C_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht2500C_minjetpt->Sumw2();
    TH1F *h_ht2500D_minjetpt = new TH1F("h_ht2500D_minjetpt", "alphamin Jet PT", 10, 0, 1000);
    h_ht2500D_minjetpt->Sumw2();

    TH1D *h_ht0A_leadjeteta = new TH1D("h_ht0A_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht0A_leadjeteta->Sumw2();
    TH1F *h_ht0B_leadjeteta = new TH1F("h_ht0B_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht0B_leadjeteta->Sumw2();
    TH1F *h_ht0C_leadjeteta = new TH1F("h_ht0C_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht0C_leadjeteta->Sumw2();
    TH1F *h_ht0D_leadjeteta = new TH1F("h_ht0D_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht0D_leadjeteta->Sumw2();

    TH1D *h_ht70A_leadjeteta = new TH1D("h_ht70A_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht70A_leadjeteta->Sumw2();
    TH1F *h_ht70B_leadjeteta = new TH1F("h_ht70B_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht70B_leadjeteta->Sumw2();
    TH1F *h_ht70C_leadjeteta = new TH1F("h_ht70C_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht70C_leadjeteta->Sumw2();
    TH1F *h_ht70D_leadjeteta = new TH1F("h_ht70D_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht70D_leadjeteta->Sumw2();

    TH1D *h_ht100A_leadjeteta = new TH1D("h_ht100A_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht100A_leadjeteta->Sumw2();
    TH1F *h_ht100B_leadjeteta = new TH1F("h_ht100B_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht100B_leadjeteta->Sumw2();
    TH1F *h_ht100C_leadjeteta = new TH1F("h_ht100C_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht100C_leadjeteta->Sumw2();
    TH1F *h_ht100D_leadjeteta = new TH1F("h_ht100D_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht100D_leadjeteta->Sumw2();

    TH1D *h_ht200A_leadjeteta = new TH1D("h_ht200A_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht200A_leadjeteta->Sumw2();
    TH1F *h_ht200B_leadjeteta = new TH1F("h_ht200B_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht200B_leadjeteta->Sumw2();
    TH1F *h_ht200C_leadjeteta = new TH1F("h_ht200C_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht200C_leadjeteta->Sumw2();
    TH1F *h_ht200D_leadjeteta = new TH1F("h_ht200D_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht200D_leadjeteta->Sumw2();

    TH1D *h_ht400A_leadjeteta = new TH1D("h_ht400A_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht400A_leadjeteta->Sumw2();
    TH1F *h_ht400B_leadjeteta = new TH1F("h_ht400B_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht400B_leadjeteta->Sumw2();
    TH1F *h_ht400C_leadjeteta = new TH1F("h_ht400C_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht400C_leadjeteta->Sumw2();
    TH1F *h_ht400D_leadjeteta = new TH1F("h_ht400D_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht400D_leadjeteta->Sumw2();

    TH1D *h_ht600A_leadjeteta = new TH1D("h_ht600A_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht600A_leadjeteta->Sumw2();
    TH1F *h_ht600B_leadjeteta = new TH1F("h_ht600B_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht600B_leadjeteta->Sumw2();
    TH1F *h_ht600C_leadjeteta = new TH1F("h_ht600C_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht600C_leadjeteta->Sumw2();
    TH1F *h_ht600D_leadjeteta = new TH1F("h_ht600D_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht600D_leadjeteta->Sumw2();

    TH1D *h_ht800A_leadjeteta = new TH1D("h_ht800A_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht800A_leadjeteta->Sumw2();
    TH1F *h_ht800B_leadjeteta = new TH1F("h_ht800B_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht800B_leadjeteta->Sumw2();
    TH1F *h_ht800C_leadjeteta = new TH1F("h_ht800C_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht800C_leadjeteta->Sumw2();
    TH1F *h_ht800D_leadjeteta = new TH1F("h_ht800D_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht800D_leadjeteta->Sumw2();

    TH1D *h_ht1200A_leadjeteta = new TH1D("h_ht1200A_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht1200A_leadjeteta->Sumw2();
    TH1F *h_ht1200B_leadjeteta = new TH1F("h_ht1200B_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht1200B_leadjeteta->Sumw2();
    TH1F *h_ht1200C_leadjeteta = new TH1F("h_ht1200C_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht1200C_leadjeteta->Sumw2();
    TH1F *h_ht1200D_leadjeteta = new TH1F("h_ht1200D_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht1200D_leadjeteta->Sumw2();

    TH1D *h_ht2500A_leadjeteta = new TH1D("h_ht2500A_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht2500A_leadjeteta->Sumw2();
    TH1F *h_ht2500B_leadjeteta = new TH1F("h_ht2500B_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht2500B_leadjeteta->Sumw2();
    TH1F *h_ht2500C_leadjeteta = new TH1F("h_ht2500C_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht2500C_leadjeteta->Sumw2();
    TH1F *h_ht2500D_leadjeteta = new TH1F("h_ht2500D_leadjeteta", "leading Jet Eta", 20, -5, 5);
    h_ht2500D_leadjeteta->Sumw2();

    TH1D *h_ht0A_minjeteta = new TH1D("h_ht0A_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht0A_minjeteta->Sumw2();
    TH1F *h_ht0B_minjeteta = new TH1F("h_ht0B_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht0B_minjeteta->Sumw2();
    TH1F *h_ht0C_minjeteta = new TH1F("h_ht0C_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht0C_minjeteta->Sumw2();
    TH1F *h_ht0D_minjeteta = new TH1F("h_ht0D_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht0D_minjeteta->Sumw2();

    TH1D *h_ht70A_minjeteta = new TH1D("h_ht70A_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht70A_minjeteta->Sumw2();
    TH1F *h_ht70B_minjeteta = new TH1F("h_ht70B_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht70B_minjeteta->Sumw2();
    TH1F *h_ht70C_minjeteta = new TH1F("h_ht70C_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht70C_minjeteta->Sumw2();
    TH1F *h_ht70D_minjeteta = new TH1F("h_ht70D_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht70D_minjeteta->Sumw2();

    TH1D *h_ht100A_minjeteta = new TH1D("h_ht100A_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht100A_minjeteta->Sumw2();
    TH1F *h_ht100B_minjeteta = new TH1F("h_ht100B_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht100B_minjeteta->Sumw2();
    TH1F *h_ht100C_minjeteta = new TH1F("h_ht100C_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht100C_minjeteta->Sumw2();
    TH1F *h_ht100D_minjeteta = new TH1F("h_ht100D_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht100D_minjeteta->Sumw2();

    TH1D *h_ht200A_minjeteta = new TH1D("h_ht200A_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht200A_minjeteta->Sumw2();
    TH1F *h_ht200B_minjeteta = new TH1F("h_ht200B_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht200B_minjeteta->Sumw2();
    TH1F *h_ht200C_minjeteta = new TH1F("h_ht200C_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht200C_minjeteta->Sumw2();
    TH1F *h_ht200D_minjeteta = new TH1F("h_ht200D_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht200D_minjeteta->Sumw2();

    TH1D *h_ht400A_minjeteta = new TH1D("h_ht400A_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht400A_minjeteta->Sumw2();
    TH1F *h_ht400B_minjeteta = new TH1F("h_ht400B_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht400B_minjeteta->Sumw2();
    TH1F *h_ht400C_minjeteta = new TH1F("h_ht400C_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht400C_minjeteta->Sumw2();
    TH1F *h_ht400D_minjeteta = new TH1F("h_ht400D_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht400D_minjeteta->Sumw2();

    TH1D *h_ht600A_minjeteta = new TH1D("h_ht600A_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht600A_minjeteta->Sumw2();
    TH1F *h_ht600B_minjeteta = new TH1F("h_ht600B_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht600B_minjeteta->Sumw2();
    TH1F *h_ht600C_minjeteta = new TH1F("h_ht600C_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht600C_minjeteta->Sumw2();
    TH1F *h_ht600D_minjeteta = new TH1F("h_ht600D_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht600D_minjeteta->Sumw2();

    TH1D *h_ht800A_minjeteta = new TH1D("h_ht800A_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht800A_minjeteta->Sumw2();
    TH1F *h_ht800B_minjeteta = new TH1F("h_ht800B_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht800B_minjeteta->Sumw2();
    TH1F *h_ht800C_minjeteta = new TH1F("h_ht800C_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht800C_minjeteta->Sumw2();
    TH1F *h_ht800D_minjeteta = new TH1F("h_ht800D_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht800D_minjeteta->Sumw2();

    TH1D *h_ht1200A_minjeteta = new TH1D("h_ht1200A_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht1200A_minjeteta->Sumw2();
    TH1F *h_ht1200B_minjeteta = new TH1F("h_ht1200B_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht1200B_minjeteta->Sumw2();
    TH1F *h_ht1200C_minjeteta = new TH1F("h_ht1200C_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht1200C_minjeteta->Sumw2();
    TH1F *h_ht1200D_minjeteta = new TH1F("h_ht1200D_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht1200D_minjeteta->Sumw2();

    TH1D *h_ht2500A_minjeteta = new TH1D("h_ht2500A_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht2500A_minjeteta->Sumw2();
    TH1F *h_ht2500B_minjeteta = new TH1F("h_ht2500B_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht2500B_minjeteta->Sumw2();
    TH1F *h_ht2500C_minjeteta = new TH1F("h_ht2500C_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht2500C_minjeteta->Sumw2();
    TH1F *h_ht2500D_minjeteta = new TH1F("h_ht2500D_minjeteta", "alphamin Jet Eta", 20, -5, 5);
    h_ht2500D_minjeteta->Sumw2();

    TH1D *h_ht0A_jetmet = new TH1D("h_ht0A_jetmet", "Met", 10, 0, 1000);
    h_ht0A_jetmet->Sumw2();
    TH1F *h_ht0B_jetmet = new TH1F("h_ht0B_jetmet", "Met", 10, 0, 1000);
    h_ht0B_jetmet->Sumw2();
    TH1F *h_ht0C_jetmet = new TH1F("h_ht0C_jetmet", "Met", 20, 0, 200);
    h_ht0C_jetmet->Sumw2();
    TH1F *h_ht0D_jetmet = new TH1F("h_ht0D_jetmet", "Met", 20, 0, 200);
    h_ht0D_jetmet->Sumw2();

    TH1D *h_ht70A_jetmet = new TH1D("h_ht70A_jetmet", "Met", 10, 0, 1000);
    h_ht70A_jetmet->Sumw2();
    TH1F *h_ht70B_jetmet = new TH1F("h_ht70B_jetmet", "Met", 10, 0, 1000);
    h_ht70B_jetmet->Sumw2();
    TH1F *h_ht70C_jetmet = new TH1F("h_ht70C_jetmet", "Met", 20, 0, 200);
    h_ht70C_jetmet->Sumw2();
    TH1F *h_ht70D_jetmet = new TH1F("h_ht70D_jetmet", "Met", 20, 0, 200);
    h_ht70D_jetmet->Sumw2();

    TH1D *h_ht100A_jetmet = new TH1D("h_ht100A_jetmet", "Met", 10, 0, 1000);
    h_ht100A_jetmet->Sumw2();
    TH1F *h_ht100B_jetmet = new TH1F("h_ht100B_jetmet", "Met", 10, 0, 1000);
    h_ht100B_jetmet->Sumw2();
    TH1F *h_ht100C_jetmet = new TH1F("h_ht100C_jetmet", "Met", 20, 0, 200);
    h_ht100C_jetmet->Sumw2();
    TH1F *h_ht100D_jetmet = new TH1F("h_ht100D_jetmet", "Met", 20, 0, 200);
    h_ht100D_jetmet->Sumw2();

    TH1D *h_ht200A_jetmet = new TH1D("h_ht200A_jetmet", "Met", 10, 0, 1000);
    h_ht200A_jetmet->Sumw2();
    TH1F *h_ht200B_jetmet = new TH1F("h_ht200B_jetmet", "Met", 10, 0, 1000);
    h_ht200B_jetmet->Sumw2();
    TH1F *h_ht200C_jetmet = new TH1F("h_ht200C_jetmet", "Met", 20, 0, 200);
    h_ht200C_jetmet->Sumw2();
    TH1F *h_ht200D_jetmet = new TH1F("h_ht200D_jetmet", "Met", 20, 0, 200);
    h_ht200D_jetmet->Sumw2();

    TH1D *h_ht400A_jetmet = new TH1D("h_ht400A_jetmet", "Met", 10, 0, 1000);
    h_ht400A_jetmet->Sumw2();
    TH1F *h_ht400B_jetmet = new TH1F("h_ht400B_jetmet", "Met", 10, 0, 1000);
    h_ht400B_jetmet->Sumw2();
    TH1F *h_ht400C_jetmet = new TH1F("h_ht400C_jetmet", "Met", 20, 0, 200);
    h_ht400C_jetmet->Sumw2();
    TH1F *h_ht400D_jetmet = new TH1F("h_ht400D_jetmet", "Met", 20, 0, 200);
    h_ht400D_jetmet->Sumw2();

    TH1D *h_ht600A_jetmet = new TH1D("h_ht600A_jetmet", "Met", 10, 0, 1000);
    h_ht600A_jetmet->Sumw2();
    TH1F *h_ht600B_jetmet = new TH1F("h_ht600B_jetmet", "Met", 10, 0, 1000);
    h_ht600B_jetmet->Sumw2();
    TH1F *h_ht600C_jetmet = new TH1F("h_ht600C_jetmet", "Met", 20, 0, 200);
    h_ht600C_jetmet->Sumw2();
    TH1F *h_ht600D_jetmet = new TH1F("h_ht600D_jetmet", "Met", 20, 0, 200);
    h_ht600D_jetmet->Sumw2();

    TH1D *h_ht800A_jetmet = new TH1D("h_ht800A_jetmet", "Met", 10, 0, 1000);
    h_ht800A_jetmet->Sumw2();
    TH1F *h_ht800B_jetmet = new TH1F("h_ht800B_jetmet", "Met", 10, 0, 1000);
    h_ht800B_jetmet->Sumw2();
    TH1F *h_ht800C_jetmet = new TH1F("h_ht800C_jetmet", "Met", 20, 0, 200);
    h_ht800C_jetmet->Sumw2();
    TH1F *h_ht800D_jetmet = new TH1F("h_ht800D_jetmet", "Met", 20, 0, 200);
    h_ht800D_jetmet->Sumw2();

    TH1D *h_ht1200A_jetmet = new TH1D("h_ht1200A_jetmet", "Met", 10, 0, 1000);
    h_ht1200A_jetmet->Sumw2();
    TH1F *h_ht1200B_jetmet = new TH1F("h_ht1200B_jetmet", "Met", 10, 0, 1000);
    h_ht1200B_jetmet->Sumw2();
    TH1F *h_ht1200C_jetmet = new TH1F("h_ht1200C_jetmet", "Met", 20, 0, 200);
    h_ht1200C_jetmet->Sumw2();
    TH1F *h_ht1200D_jetmet = new TH1F("h_ht1200D_jetmet", "Met", 20, 0, 200);
    h_ht1200D_jetmet->Sumw2();

    TH1D *h_ht2500A_jetmet = new TH1D("h_ht2500A_jetmet", "Met", 10, 0, 1000);
    h_ht2500A_jetmet->Sumw2();
    TH1F *h_ht2500B_jetmet = new TH1F("h_ht2500B_jetmet", "Met", 10, 0, 1000);
    h_ht2500B_jetmet->Sumw2();
    TH1F *h_ht2500C_jetmet = new TH1F("h_ht2500C_jetmet", "Met", 20, 0, 200);
    h_ht2500C_jetmet->Sumw2();
    TH1F *h_ht2500D_jetmet = new TH1F("h_ht2500D_jetmet", "Met", 20, 0, 200);
    h_ht2500D_jetmet->Sumw2();

    TH1D *h_ht0A_diLp_PT = new TH1D("h_ht0A_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht0A_diLp_PT->Sumw2();
    TH1F *h_ht0B_diLp_PT = new TH1F("h_ht0B_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht0B_diLp_PT->Sumw2();
    TH1F *h_ht0C_diLp_PT = new TH1F("h_ht0C_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht0C_diLp_PT->Sumw2();
    TH1F *h_ht0D_diLp_PT = new TH1F("h_ht0D_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht0D_diLp_PT->Sumw2();

    TH1D *h_ht70A_diLp_PT = new TH1D("h_ht70A_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht70A_diLp_PT->Sumw2();
    TH1F *h_ht70B_diLp_PT = new TH1F("h_ht70B_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht70B_diLp_PT->Sumw2();
    TH1F *h_ht70C_diLp_PT = new TH1F("h_ht70C_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht70C_diLp_PT->Sumw2();
    TH1F *h_ht70D_diLp_PT = new TH1F("h_ht70D_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht70D_diLp_PT->Sumw2();

    TH1D *h_ht100A_diLp_PT = new TH1D("h_ht100A_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht100A_diLp_PT->Sumw2();
    TH1F *h_ht100B_diLp_PT = new TH1F("h_ht100B_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht100B_diLp_PT->Sumw2();
    TH1F *h_ht100C_diLp_PT = new TH1F("h_ht100C_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht100C_diLp_PT->Sumw2();
    TH1F *h_ht100D_diLp_PT = new TH1F("h_ht100D_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht100D_diLp_PT->Sumw2();

    TH1D *h_ht200A_diLp_PT = new TH1D("h_ht200A_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht200A_diLp_PT->Sumw2();
    TH1F *h_ht200B_diLp_PT = new TH1F("h_ht200B_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht200B_diLp_PT->Sumw2();
    TH1F *h_ht200C_diLp_PT = new TH1F("h_ht200C_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht200C_diLp_PT->Sumw2();
    TH1F *h_ht200D_diLp_PT = new TH1F("h_ht200D_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht200D_diLp_PT->Sumw2();

    TH1D *h_ht400A_diLp_PT = new TH1D("h_ht400A_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht400A_diLp_PT->Sumw2();
    TH1F *h_ht400B_diLp_PT = new TH1F("h_ht400B_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht400B_diLp_PT->Sumw2();
    TH1F *h_ht400C_diLp_PT = new TH1F("h_ht400C_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht400C_diLp_PT->Sumw2();
    TH1F *h_ht400D_diLp_PT = new TH1F("h_ht400D_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht400D_diLp_PT->Sumw2();

    TH1D *h_ht600A_diLp_PT = new TH1D("h_ht600A_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht600A_diLp_PT->Sumw2();
    TH1F *h_ht600B_diLp_PT = new TH1F("h_ht600B_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht600B_diLp_PT->Sumw2();
    TH1F *h_ht600C_diLp_PT = new TH1F("h_ht600C_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht600C_diLp_PT->Sumw2();
    TH1F *h_ht600D_diLp_PT = new TH1F("h_ht600D_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht600D_diLp_PT->Sumw2();

    TH1D *h_ht800A_diLp_PT = new TH1D("h_ht800A_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht800A_diLp_PT->Sumw2();
    TH1F *h_ht800B_diLp_PT = new TH1F("h_ht800B_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht800B_diLp_PT->Sumw2();
    TH1F *h_ht800C_diLp_PT = new TH1F("h_ht800C_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht800C_diLp_PT->Sumw2();
    TH1F *h_ht800D_diLp_PT = new TH1F("h_ht800D_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht800D_diLp_PT->Sumw2();

    TH1D *h_ht1200A_diLp_PT = new TH1D("h_ht1200A_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht1200A_diLp_PT->Sumw2();
    TH1F *h_ht1200B_diLp_PT = new TH1F("h_ht1200B_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht1200B_diLp_PT->Sumw2();
    TH1F *h_ht1200C_diLp_PT = new TH1F("h_ht1200C_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht1200C_diLp_PT->Sumw2();
    TH1F *h_ht1200D_diLp_PT = new TH1F("h_ht1200D_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht1200D_diLp_PT->Sumw2();

    TH1D *h_ht2500A_diLp_PT = new TH1D("h_ht2500A_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht2500A_diLp_PT->Sumw2();
    TH1F *h_ht2500B_diLp_PT = new TH1F("h_ht2500B_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht2500B_diLp_PT->Sumw2();
    TH1F *h_ht2500C_diLp_PT = new TH1F("h_ht2500C_diLp_PT", "dilepton PT", 10, 0, 500);
    h_ht2500C_diLp_PT->Sumw2();
    TH1F *h_ht2500D_diLp_PT = new TH1F("h_ht2500D_diLp_PT", "dilepton PT", 10, 0, 500);
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

    float_t f_ht0_minJetpt, f_ht70_minJetpt, f_ht100_minJetpt, f_ht200_minJetpt, f_ht400_minJetpt, f_ht600_minJetpt,
        f_ht800_minJetpt, f_ht1200_minJetpt, f_ht2500_minJetpt;

    float_t f_ht0_minJeteta, f_ht70_minJeteta, f_ht100_minJeteta, f_ht200_minJeteta, f_ht400_minJeteta, f_ht600_minJeteta,
        f_ht800_minJeteta, f_ht1200_minJeteta, f_ht2500_minJeteta;

    float_t f_ht0_dilpPT, f_ht70_dilpPT, f_ht100_dilpPT, f_ht200_dilpPT, f_ht400_dilpPT, f_ht600_dilpPT,
        f_ht800_dilpPT, f_ht1200_dilpPT, f_ht2500_dilpPT;

    Int_t I_ht0_nThinJets, I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets,
        I_ht600_nThinJets, I_ht800_nThinJets, I_ht1200_nThinJets, I_ht2500_nThinJets;

    Int_t I_ht0_minJetflavor, I_ht70_minJetflavor, I_ht100_minJetflavor, I_ht200_minJetflavor, I_ht400_minJetflavor,
        I_ht600_minJetflavor, I_ht800_minJetflavor, I_ht1200_minJetflavor, I_ht2500_minJetflavor;

    float alphaminupbound = 0.6;
    float alphaminlowerbound = 0.3;

    TTree *T_event;
    DYincli->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &I_ht0_weight);
    T_event->SetBranchAddress("f_alphamin", &f_ht0_alphamin);
    T_event->SetBranchAddress("f_Met", &f_ht0_Met);
    T_event->SetBranchAddress("f_HT", &HT);
    T_event->SetBranchAddress("f_leadJetpt", &f_ht0_leadJetpt);
    T_event->SetBranchAddress("f_leadJeteta", &f_ht0_leadJeteta);
    T_event->SetBranchAddress("f_minalphaJeteta", &f_ht0_minJeteta);
    T_event->SetBranchAddress("f_minalphaJetpt", &f_ht0_minJetpt);
    T_event->SetBranchAddress("f_dileptonPT", &f_ht0_dilpPT);
    T_event->SetBranchAddress("I_nThinJets", &I_ht0_nThinJets);
    T_event->SetBranchAddress("I_minJetflavor", &I_ht0_minJetflavor);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (I_ht0_nThinJets < 2)
            continue;
        if (I_ht0_minJetflavor == 4 || I_ht0_minJetflavor == 5)
        {
            if (HT < 70)
            {

                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met > 160)
                {
                    h_ht0A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                    h_ht0A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                    h_ht0A_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                    h_ht0A_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                    h_ht0A_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                    h_ht0A_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160)
                {
                    h_ht0B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT0Weight);
                    h_ht0B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT0Weight);
                    h_ht0B_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT0Weight);
                    h_ht0B_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT0Weight);
                    h_ht0B_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT0Weight);
                    h_ht0B_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT0Weight);
                }
                else if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met < 100)
                {
                    h_ht0C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                    h_ht0C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                    h_ht0C_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                    h_ht0C_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                    h_ht0C_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                    h_ht0C_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT0Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
                {
                    h_ht0D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT0Weight);
                    h_ht0D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT0Weight);
                    h_ht0D_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT0Weight);
                    h_ht0D_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT0Weight);
                    h_ht0D_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT0Weight);
                    h_ht0D_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT0Weight);
                }
            }
            else if (HT >= 70 && HT < 100)
            {

                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met > 160)
                {
                    h_ht70A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                    h_ht70A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                    h_ht70A_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                    h_ht70A_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                    h_ht70A_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                    h_ht70A_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160)
                {
                    h_ht70B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT70Weight);
                    h_ht70B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT70Weight);
                    h_ht70B_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT70Weight);
                    h_ht70B_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT70Weight);
                    h_ht70B_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT70Weight);
                    h_ht70B_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT70Weight);
                }
                else if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met < 100)
                {
                    h_ht70C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                    h_ht70C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                    h_ht70C_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                    h_ht70C_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                    h_ht70C_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                    h_ht70C_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT70Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
                {
                    h_ht70D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT70Weight);
                    h_ht70D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT70Weight);
                    h_ht70D_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT70Weight);
                    h_ht70D_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT70Weight);
                    h_ht70D_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT70Weight);
                    h_ht70D_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT70Weight);
                }
            }
            else if (HT >= 100 && HT < 200)
            {
                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met > 160)
                {
                    h_ht100A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                    h_ht100A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                    h_ht100A_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                    h_ht100A_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                    h_ht100A_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                    h_ht100A_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160)
                {
                    h_ht100B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT100Weight);
                    h_ht100B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT100Weight);
                    h_ht100B_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT100Weight);
                    h_ht100B_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT100Weight);
                    h_ht100B_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT100Weight);
                    h_ht100B_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT100Weight);
                }
                else if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met < 100)
                {
                    h_ht100C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                    h_ht100C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                    h_ht100C_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                    h_ht100C_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                    h_ht100C_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                    h_ht100C_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT100Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
                {
                    h_ht100D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT100Weight);
                    h_ht100D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT100Weight);
                    h_ht100D_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT100Weight);
                    h_ht100D_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT100Weight);
                    h_ht100D_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT100Weight);
                    h_ht100D_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT100Weight);
                }
            }
            else if (HT >= 200 && HT < 400)
            {

                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met > 160)
                {
                    h_ht200A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                    h_ht200A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                    h_ht200A_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                    h_ht200A_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                    h_ht200A_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                    h_ht200A_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160)
                {
                    h_ht200B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT200Weight);
                    h_ht200B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT200Weight);
                    h_ht200B_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT200Weight);
                    h_ht200B_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT200Weight);
                    h_ht200B_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT200Weight);
                    h_ht200B_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT200Weight);
                }
                else if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met < 100)
                {
                    h_ht200C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                    h_ht200C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                    h_ht200C_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                    h_ht200C_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                    h_ht200C_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                    h_ht200C_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT200Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
                {
                    h_ht200D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT200Weight);
                    h_ht200D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT200Weight);
                    h_ht200D_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT200Weight);
                    h_ht200D_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT200Weight);
                    h_ht200D_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT200Weight);
                    h_ht200D_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT200Weight);
                }
            }
            else if (HT >= 400 && HT < 600)
            {

                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met > 160)
                {
                    h_ht400A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                    h_ht400A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                    h_ht400A_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                    h_ht400A_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                    h_ht400A_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                    h_ht400A_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160 )
                {
                    h_ht400B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT400Weight);
                    h_ht400B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT400Weight);
                    h_ht400B_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT400Weight);
                    h_ht400B_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT400Weight);
                    h_ht400B_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT400Weight);
                    h_ht400B_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT400Weight);
                }
                else if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met < 100)
                {
                    h_ht400C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                    h_ht400C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                    h_ht400C_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                    h_ht400C_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                    h_ht400C_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                    h_ht400C_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT400Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
                {
                    h_ht400D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT400Weight);
                    h_ht400D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT400Weight);
                    h_ht400D_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT400Weight);
                    h_ht400D_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT400Weight);
                    h_ht400D_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT400Weight);
                    h_ht400D_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT400Weight);
                }
            }
            else if (HT >= 600 && HT < 800)
            {

                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met > 160)
                {
                    h_ht600A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                    h_ht600A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                    h_ht600A_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                    h_ht600A_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                    h_ht600A_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                    h_ht600A_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160)
                {
                    h_ht600B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT600Weight);
                    h_ht600B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT600Weight);
                    h_ht600B_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT600Weight);
                    h_ht600B_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT600Weight);
                    h_ht600B_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT600Weight);
                    h_ht600B_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT600Weight);
                }
                else if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met < 100)
                {
                    h_ht600C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                    h_ht600C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                    h_ht600C_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                    h_ht600C_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                    h_ht600C_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                    h_ht600C_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT600Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
                {
                    h_ht600D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT600Weight);
                    h_ht600D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT600Weight);
                    h_ht600D_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT600Weight);
                    h_ht600D_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT600Weight);
                    h_ht600D_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT600Weight);
                    h_ht600D_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT600Weight);
                }
            }
            else if (HT >= 800 && HT < 1200)
            {

                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met > 160 )
                {
                    h_ht800A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                    h_ht800A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                    h_ht800A_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                    h_ht800A_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                    h_ht800A_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                    h_ht800A_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160)
                {
                    h_ht800B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT800Weight);
                    h_ht800B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT800Weight);
                    h_ht800B_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT800Weight);
                    h_ht800B_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT800Weight);
                    h_ht800B_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT800Weight);
                    h_ht800B_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT800Weight);
                }
                else if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met < 100)
                {
                    h_ht800C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                    h_ht800C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                    h_ht800C_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                    h_ht800C_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                    h_ht800C_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                    h_ht800C_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT800Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
                {
                    h_ht800D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT800Weight);
                    h_ht800D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT800Weight);
                    h_ht800D_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT800Weight);
                    h_ht800D_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT800Weight);
                    h_ht800D_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT800Weight);
                    h_ht800D_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT800Weight);
                }
            }
            else if (HT >= 1200 && HT < 2500)
            {

                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met > 160)
                {
                    h_ht1200A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                    h_ht1200A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                    h_ht1200A_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                    h_ht1200A_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                    h_ht1200A_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                    h_ht1200A_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160)
                {
                    h_ht1200B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT1200Weight);
                    h_ht1200B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT1200Weight);
                    h_ht1200B_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT1200Weight);
                    h_ht1200B_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT1200Weight);
                    h_ht1200B_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT1200Weight);
                    h_ht1200B_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT1200Weight);
                }
                else if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met < 100)
                {
                    h_ht1200C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                    h_ht1200C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                    h_ht1200C_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                    h_ht1200C_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                    h_ht1200C_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                    h_ht1200C_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT1200Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
                {
                    h_ht1200D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT1200Weight);
                    h_ht1200D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT1200Weight);
                    h_ht1200D_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT1200Weight);
                    h_ht1200D_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT1200Weight);
                    h_ht1200D_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT1200Weight);
                    h_ht1200D_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT1200Weight);
                }
            }
            else if (HT >= 2500)
            {
                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met > 160)
                {
                    h_ht2500A_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                    h_ht2500A_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                    h_ht2500A_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                    h_ht2500A_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                    h_ht2500A_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                    h_ht2500A_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met > 160)
                {
                    h_ht2500B_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT2500Weight);
                    h_ht2500B_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT2500Weight);
                    h_ht2500B_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT2500Weight);
                    h_ht2500B_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT2500Weight);
                    h_ht2500B_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT2500Weight);
                    h_ht2500B_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT2500Weight);
                }
                else if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound && f_ht0_Met < 100)
                {
                    h_ht2500C_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                    h_ht2500C_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                    h_ht2500C_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                    h_ht2500C_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                    h_ht2500C_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                    h_ht2500C_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT2500Weight / background(f_ht0_Met));
                }
                else if (f_ht0_alphamin < 0.1 && f_ht0_Met < 100)
                {
                    h_ht2500D_jetmet->Fill(f_ht0_Met, I_ht0_weight * HT2500Weight);
                    h_ht2500D_diLp_PT->Fill(f_ht0_dilpPT, I_ht0_weight * HT2500Weight);
                    h_ht2500D_leadjetpt->Fill(f_ht0_leadJetpt, I_ht0_weight * HT2500Weight);
                    h_ht2500D_leadjeteta->Fill(f_ht0_leadJeteta, I_ht0_weight * HT2500Weight);
                    h_ht2500D_minjetpt->Fill(f_ht0_minJetpt, I_ht0_weight * HT2500Weight);
                    h_ht2500D_minjeteta->Fill(f_ht0_minJeteta, I_ht0_weight * HT2500Weight);
                }
            }
        }
    } // End of inclusive sample

    TTree *T_event1;
    DYHT100->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_leadJeteta", &f_ht100_leadJeteta);
    T_event1->SetBranchAddress("f_leadJetpt", &f_ht100_leadJetpt);
    T_event1->SetBranchAddress("f_minalphaJeteta", &f_ht100_minJeteta);
    T_event1->SetBranchAddress("f_minalphaJetpt", &f_ht100_minJetpt);
    T_event1->SetBranchAddress("f_alphamin", &f_ht100_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_ht100_Met);
    T_event1->SetBranchAddress("f_dileptonPT", &f_ht100_dilpPT);
    T_event1->SetBranchAddress("I_weight", &I_ht100_weight);
    T_event1->SetBranchAddress("I_nThinJets", &I_ht100_nThinJets);
    T_event1->SetBranchAddress("I_minJetflavor", &I_ht100_minJetflavor);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (I_ht100_nThinJets < 2)
            continue;
        if (I_ht100_minJetflavor == 4 || I_ht100_minJetflavor == 5)
        {
            if (alphaminupbound > f_ht100_alphamin && f_ht100_alphamin > alphaminlowerbound && f_ht100_Met > 160 )
            {
                h_ht100A_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight / background(f_ht100_Met));
                h_ht100A_diLp_PT->Fill(f_ht100_dilpPT, I_ht100_weight * HT100Weight / background(f_ht100_Met));
                h_ht100A_leadjetpt->Fill(f_ht100_leadJetpt, I_ht100_weight * HT100Weight / background(f_ht100_Met));
                h_ht100A_leadjeteta->Fill(f_ht100_leadJeteta, I_ht100_weight * HT100Weight / background(f_ht100_Met));
                h_ht100A_minjetpt->Fill(f_ht100_minJetpt, I_ht100_weight * HT100Weight / background(f_ht100_Met));
                h_ht100A_minjeteta->Fill(f_ht100_minJeteta, I_ht100_weight * HT100Weight / background(f_ht100_Met));
            }
            else if (f_ht100_alphamin < 0.1 && f_ht100_Met > 160 )
            {
                h_ht100B_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
                h_ht100B_diLp_PT->Fill(f_ht100_dilpPT, I_ht100_weight * HT100Weight);
                h_ht100B_leadjetpt->Fill(f_ht100_leadJetpt, I_ht100_weight * HT100Weight);
                h_ht100B_leadjeteta->Fill(f_ht100_leadJeteta, I_ht100_weight * HT100Weight);
                h_ht100B_minjetpt->Fill(f_ht100_minJetpt, I_ht100_weight * HT100Weight);
                h_ht100B_minjeteta->Fill(f_ht100_minJeteta, I_ht100_weight * HT100Weight);
            }
            else if (alphaminupbound > f_ht100_alphamin && f_ht100_alphamin > alphaminlowerbound && f_ht100_Met < 100)
            {
                h_ht100C_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight / background(f_ht100_Met));
                h_ht100C_diLp_PT->Fill(f_ht100_dilpPT, I_ht100_weight * HT100Weight / background(f_ht100_Met));
                h_ht100C_leadjetpt->Fill(f_ht100_leadJetpt, I_ht100_weight * HT100Weight / background(f_ht100_Met));
                h_ht100C_leadjeteta->Fill(f_ht100_leadJeteta, I_ht100_weight * HT100Weight / background(f_ht100_Met));
                h_ht100C_minjetpt->Fill(f_ht100_minJetpt, I_ht100_weight * HT100Weight / background(f_ht100_Met));
                h_ht100C_minjeteta->Fill(f_ht100_minJeteta, I_ht100_weight * HT100Weight / background(f_ht100_Met));
            }
            else if (f_ht100_alphamin < 0.1 && f_ht100_Met < 100)
            {
                h_ht100D_jetmet->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
                h_ht100D_diLp_PT->Fill(f_ht100_dilpPT, I_ht100_weight * HT100Weight);
                h_ht100D_leadjetpt->Fill(f_ht100_leadJetpt, I_ht100_weight * HT100Weight);
                h_ht100D_leadjeteta->Fill(f_ht100_leadJeteta, I_ht100_weight * HT100Weight);
                h_ht100D_minjetpt->Fill(f_ht100_minJetpt, I_ht100_weight * HT100Weight);
                h_ht100D_minjeteta->Fill(f_ht100_minJeteta, I_ht100_weight * HT100Weight);
            }
        }
    } // End of HT100

    TTree *T_event2;
    DYHT200->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_leadJeteta", &f_ht200_leadJeteta);
    T_event2->SetBranchAddress("f_leadJetpt", &f_ht200_leadJetpt);
    T_event2->SetBranchAddress("f_minalphaJeteta", &f_ht200_minJeteta);
    T_event2->SetBranchAddress("f_minalphaJetpt", &f_ht200_minJetpt);
    T_event2->SetBranchAddress("f_alphamin", &f_ht200_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_ht200_Met);
    T_event2->SetBranchAddress("f_dileptonPT", &f_ht200_dilpPT);
    T_event2->SetBranchAddress("I_weight", &I_ht200_weight);
    T_event2->SetBranchAddress("I_nThinJets", &I_ht200_nThinJets);
    T_event2->SetBranchAddress("I_minJetflavor", &I_ht200_minJetflavor);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (I_ht200_nThinJets < 2)
            continue;
        if (I_ht200_minJetflavor == 4 || I_ht200_minJetflavor == 5)
        {
            if (alphaminupbound > f_ht200_alphamin && f_ht200_alphamin > alphaminlowerbound && f_ht200_Met > 160)
            {
                h_ht200A_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight / background(f_ht200_Met));
                h_ht200A_diLp_PT->Fill(f_ht200_dilpPT, I_ht200_weight * HT200Weight / background(f_ht200_Met));
                h_ht200A_leadjetpt->Fill(f_ht200_leadJetpt, I_ht200_weight * HT200Weight / background(f_ht200_Met));
                h_ht200A_leadjeteta->Fill(f_ht200_leadJeteta, I_ht200_weight * HT200Weight / background(f_ht200_Met));
                h_ht200A_minjetpt->Fill(f_ht200_minJetpt, I_ht200_weight * HT200Weight / background(f_ht200_Met));
                h_ht200A_minjeteta->Fill(f_ht200_minJeteta, I_ht200_weight * HT200Weight / background(f_ht200_Met));
            }
            else if (f_ht200_alphamin < 0.1 && f_ht200_Met > 160)
            {
                h_ht200B_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
                h_ht200B_diLp_PT->Fill(f_ht200_dilpPT, I_ht200_weight * HT200Weight);
                h_ht200B_leadjetpt->Fill(f_ht200_leadJetpt, I_ht200_weight * HT200Weight);
                h_ht200B_leadjeteta->Fill(f_ht200_leadJeteta, I_ht200_weight * HT200Weight);
                h_ht200B_minjetpt->Fill(f_ht200_minJetpt, I_ht200_weight * HT200Weight);
                h_ht200B_minjeteta->Fill(f_ht200_minJeteta, I_ht200_weight * HT200Weight);
            }
            else if (alphaminupbound > f_ht200_alphamin && f_ht200_alphamin > alphaminlowerbound && f_ht200_Met < 100)
            {
                h_ht200C_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight / background(f_ht200_Met));
                h_ht200C_diLp_PT->Fill(f_ht200_dilpPT, I_ht200_weight * HT200Weight / background(f_ht200_Met));
                h_ht200C_leadjetpt->Fill(f_ht200_leadJetpt, I_ht200_weight * HT200Weight / background(f_ht200_Met));
                h_ht200C_leadjeteta->Fill(f_ht200_leadJeteta, I_ht200_weight * HT200Weight / background(f_ht200_Met));
                h_ht200C_minjetpt->Fill(f_ht200_minJetpt, I_ht200_weight * HT200Weight / background(f_ht200_Met));
                h_ht200C_minjeteta->Fill(f_ht200_minJeteta, I_ht200_weight * HT200Weight / background(f_ht200_Met));
            }
            else if (f_ht200_alphamin < 0.1 && f_ht200_Met < 100)
            {
                h_ht200D_jetmet->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
                h_ht200D_diLp_PT->Fill(f_ht200_dilpPT, I_ht200_weight * HT200Weight);
                h_ht200D_leadjetpt->Fill(f_ht200_leadJetpt, I_ht200_weight * HT200Weight);
                h_ht200D_leadjeteta->Fill(f_ht200_leadJeteta, I_ht200_weight * HT200Weight);
                h_ht200D_minjetpt->Fill(f_ht200_minJetpt, I_ht200_weight * HT200Weight);
                h_ht200D_minjeteta->Fill(f_ht200_minJeteta, I_ht200_weight * HT200Weight);
            }
        }
    } // End of HT200

    TTree *T_event3;
    DYHT400->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_leadJeteta", &f_ht400_leadJeteta);
    T_event3->SetBranchAddress("f_leadJetpt", &f_ht400_leadJetpt);
    T_event3->SetBranchAddress("f_minalphaJeteta", &f_ht400_minJeteta);
    T_event3->SetBranchAddress("f_minalphaJetpt", &f_ht400_minJetpt);
    T_event3->SetBranchAddress("f_alphamin", &f_ht400_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_ht400_Met);
    T_event3->SetBranchAddress("f_dileptonPT", &f_ht400_dilpPT);
    T_event3->SetBranchAddress("I_weight", &I_ht400_weight);
    T_event3->SetBranchAddress("I_nThinJets", &I_ht400_nThinJets);
    T_event3->SetBranchAddress("I_minJetflavor", &I_ht400_minJetflavor);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (I_ht400_nThinJets < 2)
            continue;
        if (I_ht400_minJetflavor == 4 || I_ht400_minJetflavor == 5)
        {
            if (alphaminupbound > f_ht400_alphamin && f_ht400_alphamin > alphaminlowerbound && f_ht400_Met > 160)
            {
                h_ht400A_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight / background(f_ht400_Met));
                h_ht400A_diLp_PT->Fill(f_ht400_dilpPT, I_ht400_weight * HT400Weight / background(f_ht400_Met));
                h_ht400A_leadjetpt->Fill(f_ht400_leadJetpt, I_ht400_weight * HT400Weight / background(f_ht400_Met));
                h_ht400A_leadjeteta->Fill(f_ht400_leadJeteta, I_ht400_weight * HT400Weight / background(f_ht400_Met));
                h_ht400A_minjetpt->Fill(f_ht400_minJetpt, I_ht400_weight * HT400Weight / background(f_ht400_Met));
                h_ht400A_minjeteta->Fill(f_ht400_minJeteta, I_ht400_weight * HT400Weight / background(f_ht400_Met));
            }
            else if (f_ht400_alphamin < 0.1 && f_ht400_Met > 160)
            {
                h_ht400B_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
                h_ht400B_diLp_PT->Fill(f_ht400_dilpPT, I_ht400_weight * HT400Weight);
                h_ht400B_leadjetpt->Fill(f_ht400_leadJetpt, I_ht400_weight * HT400Weight);
                h_ht400B_leadjeteta->Fill(f_ht400_leadJeteta, I_ht400_weight * HT400Weight);
                h_ht400B_minjetpt->Fill(f_ht400_minJetpt, I_ht400_weight * HT400Weight);
                h_ht400B_minjeteta->Fill(f_ht400_minJeteta, I_ht400_weight * HT400Weight);
            }
            else if (alphaminupbound > f_ht400_alphamin && f_ht400_alphamin > alphaminlowerbound && f_ht400_Met < 100)
            {
                h_ht400C_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight / background(f_ht400_Met));
                h_ht400C_diLp_PT->Fill(f_ht400_dilpPT, I_ht400_weight * HT400Weight / background(f_ht400_Met));
                h_ht400C_leadjetpt->Fill(f_ht400_leadJetpt, I_ht400_weight * HT400Weight / background(f_ht400_Met));
                h_ht400C_leadjeteta->Fill(f_ht400_leadJeteta, I_ht400_weight * HT400Weight / background(f_ht400_Met));
                h_ht400C_minjetpt->Fill(f_ht400_minJetpt, I_ht400_weight * HT400Weight / background(f_ht400_Met));
                h_ht400C_minjeteta->Fill(f_ht400_minJeteta, I_ht400_weight * HT400Weight / background(f_ht400_Met));
            }
            else if (f_ht400_alphamin < 0.1 && f_ht400_Met < 100)
            {
                h_ht400D_jetmet->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
                h_ht400D_diLp_PT->Fill(f_ht400_dilpPT, I_ht400_weight * HT400Weight);
                h_ht400D_leadjetpt->Fill(f_ht400_leadJetpt, I_ht400_weight * HT400Weight);
                h_ht400D_leadjeteta->Fill(f_ht400_leadJeteta, I_ht400_weight * HT400Weight);
                h_ht400D_minjetpt->Fill(f_ht400_minJetpt, I_ht400_weight * HT400Weight);
                h_ht400D_minjeteta->Fill(f_ht400_minJeteta, I_ht400_weight * HT400Weight);
            }
        }
    } // End of HT400

    TTree *T_event4;
    DYHT600->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_leadJeteta", &f_ht600_leadJeteta);
    T_event4->SetBranchAddress("f_leadJetpt", &f_ht600_leadJetpt);
    T_event4->SetBranchAddress("f_minalphaJeteta", &f_ht600_minJeteta);
    T_event4->SetBranchAddress("f_minalphaJetpt", &f_ht600_minJetpt);
    T_event4->SetBranchAddress("f_alphamin", &f_ht600_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_ht600_Met);
    T_event4->SetBranchAddress("f_dileptonPT", &f_ht600_dilpPT);
    T_event4->SetBranchAddress("I_weight", &I_ht600_weight);
    T_event4->SetBranchAddress("I_nThinJets", &I_ht600_nThinJets);
    T_event4->SetBranchAddress("I_minJetflavor", &I_ht600_minJetflavor);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (I_ht600_nThinJets < 2)
            continue;
        if (I_ht600_minJetflavor == 4 || I_ht600_minJetflavor == 5)
        {
            if (alphaminupbound > f_ht600_alphamin && f_ht600_alphamin > alphaminlowerbound && f_ht600_Met > 160)
            {
                h_ht600A_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight / background(f_ht600_Met));
                h_ht600A_diLp_PT->Fill(f_ht600_dilpPT, I_ht600_weight * HT600Weight / background(f_ht600_Met));
                h_ht600A_leadjetpt->Fill(f_ht600_leadJetpt, I_ht600_weight * HT600Weight / background(f_ht600_Met));
                h_ht600A_leadjeteta->Fill(f_ht600_leadJeteta, I_ht600_weight * HT600Weight / background(f_ht600_Met));
                h_ht600A_minjetpt->Fill(f_ht600_minJetpt, I_ht600_weight * HT600Weight / background(f_ht600_Met));
                h_ht600A_minjeteta->Fill(f_ht600_minJeteta, I_ht600_weight * HT600Weight / background(f_ht600_Met));
            }
            else if (f_ht600_alphamin < 0.1 && f_ht600_Met > 160)
            {
                h_ht600B_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
                h_ht600B_diLp_PT->Fill(f_ht600_dilpPT, I_ht600_weight * HT600Weight);
                h_ht600B_leadjetpt->Fill(f_ht600_leadJetpt, I_ht600_weight * HT600Weight);
                h_ht600B_leadjeteta->Fill(f_ht600_leadJeteta, I_ht600_weight * HT600Weight);
                h_ht600B_minjetpt->Fill(f_ht600_minJetpt, I_ht600_weight * HT600Weight);
                h_ht600B_minjeteta->Fill(f_ht600_minJeteta, I_ht600_weight * HT600Weight);
            }
            else if (alphaminupbound > f_ht600_alphamin && f_ht600_alphamin > alphaminlowerbound && f_ht600_Met < 100)
            {
                h_ht600C_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight / background(f_ht600_Met));
                h_ht600C_diLp_PT->Fill(f_ht600_dilpPT, I_ht600_weight * HT600Weight / background(f_ht600_Met));
                h_ht600C_leadjetpt->Fill(f_ht600_leadJetpt, I_ht600_weight * HT600Weight / background(f_ht600_Met));
                h_ht600C_leadjeteta->Fill(f_ht600_leadJeteta, I_ht600_weight * HT600Weight / background(f_ht600_Met));
                h_ht600C_minjetpt->Fill(f_ht600_minJetpt, I_ht600_weight * HT600Weight / background(f_ht600_Met));
                h_ht600C_minjeteta->Fill(f_ht600_minJeteta, I_ht600_weight * HT600Weight / background(f_ht600_Met));
            }
            else if (f_ht600_alphamin < 0.1 && f_ht600_Met < 100)
            {
                h_ht600D_jetmet->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
                h_ht600D_diLp_PT->Fill(f_ht600_dilpPT, I_ht600_weight * HT600Weight);
                h_ht600D_leadjetpt->Fill(f_ht600_leadJetpt, I_ht600_weight * HT600Weight);
                h_ht600D_leadjeteta->Fill(f_ht600_leadJeteta, I_ht600_weight * HT600Weight);
                h_ht600D_minjetpt->Fill(f_ht600_minJetpt, I_ht600_weight * HT600Weight);
                h_ht600D_minjeteta->Fill(f_ht600_minJeteta, I_ht600_weight * HT600Weight);
            }
        }

    } // End of HT600

    TTree *T_event5;
    DYHT800->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_leadJeteta", &f_ht800_leadJeteta);
    T_event5->SetBranchAddress("f_leadJetpt", &f_ht800_leadJetpt);
    T_event5->SetBranchAddress("f_minalphaJeteta", &f_ht800_minJeteta);
    T_event5->SetBranchAddress("f_minalphaJetpt", &f_ht800_minJetpt);
    T_event5->SetBranchAddress("f_alphamin", &f_ht800_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_ht800_Met);
    T_event5->SetBranchAddress("f_dileptonPT", &f_ht800_dilpPT);
    T_event5->SetBranchAddress("I_weight", &I_ht800_weight);
    T_event5->SetBranchAddress("I_nThinJets", &I_ht800_nThinJets);
    T_event5->SetBranchAddress("I_minJetflavor", &I_ht800_minJetflavor);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (I_ht800_nThinJets < 2)
            continue;
        if (I_ht800_minJetflavor == 4 || I_ht800_minJetflavor == 5)
        {
            if (alphaminupbound > f_ht800_alphamin && f_ht800_alphamin > alphaminlowerbound && f_ht800_Met > 160 )
            {
                h_ht800A_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight / background(f_ht800_Met));
                h_ht800A_diLp_PT->Fill(f_ht800_dilpPT, I_ht800_weight * HT800Weight / background(f_ht800_Met));
                h_ht800A_leadjetpt->Fill(f_ht800_leadJetpt, I_ht800_weight * HT800Weight / background(f_ht800_Met));
                h_ht800A_leadjeteta->Fill(f_ht800_leadJeteta, I_ht800_weight * HT800Weight / background(f_ht800_Met));
                h_ht800A_minjetpt->Fill(f_ht800_minJetpt, I_ht800_weight * HT800Weight / background(f_ht800_Met));
                h_ht800A_minjeteta->Fill(f_ht800_minJeteta, I_ht800_weight * HT800Weight / background(f_ht800_Met));
            }
            else if (f_ht800_alphamin < 0.1 && f_ht800_Met > 160 )
            {
                h_ht800B_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
                h_ht800B_diLp_PT->Fill(f_ht800_dilpPT, I_ht800_weight * HT800Weight);
                h_ht800B_leadjetpt->Fill(f_ht800_leadJetpt, I_ht800_weight * HT800Weight);
                h_ht800B_leadjeteta->Fill(f_ht800_leadJeteta, I_ht800_weight * HT800Weight);
                h_ht800B_minjetpt->Fill(f_ht800_minJetpt, I_ht800_weight * HT800Weight);
                h_ht800B_minjeteta->Fill(f_ht800_minJeteta, I_ht800_weight * HT800Weight);
            }
            else if (alphaminupbound > f_ht800_alphamin && f_ht800_alphamin > alphaminlowerbound && f_ht800_Met < 100)
            {
                h_ht800C_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight / background(f_ht800_Met));
                h_ht800C_diLp_PT->Fill(f_ht800_dilpPT, I_ht800_weight * HT800Weight / background(f_ht800_Met));
                h_ht800C_leadjetpt->Fill(f_ht800_leadJetpt, I_ht800_weight * HT800Weight / background(f_ht800_Met));
                h_ht800C_leadjeteta->Fill(f_ht800_leadJeteta, I_ht800_weight * HT800Weight / background(f_ht800_Met));
                h_ht800C_minjetpt->Fill(f_ht800_minJetpt, I_ht800_weight * HT800Weight / background(f_ht800_Met));
                h_ht800C_minjeteta->Fill(f_ht800_minJeteta, I_ht800_weight * HT800Weight / background(f_ht800_Met));
            }
            else if (f_ht800_alphamin < 0.1 && f_ht800_Met < 100)
            {
                h_ht800D_jetmet->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
                h_ht800D_diLp_PT->Fill(f_ht800_dilpPT, I_ht800_weight * HT800Weight);
                h_ht800D_leadjetpt->Fill(f_ht800_leadJetpt, I_ht800_weight * HT800Weight);
                h_ht800D_leadjeteta->Fill(f_ht800_leadJeteta, I_ht800_weight * HT800Weight);
                h_ht800D_minjetpt->Fill(f_ht800_minJetpt, I_ht800_weight * HT800Weight);
                h_ht800D_minjeteta->Fill(f_ht800_minJeteta, I_ht800_weight * HT800Weight);
            }
        }
    } // End of HT800

    TTree *T_event6;
    DYHT1200->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_leadJeteta", &f_ht1200_leadJeteta);
    T_event6->SetBranchAddress("f_leadJetpt", &f_ht1200_leadJetpt);
    T_event6->SetBranchAddress("f_minalphaJeteta", &f_ht1200_minJeteta);
    T_event6->SetBranchAddress("f_minalphaJetpt", &f_ht1200_minJetpt);
    T_event6->SetBranchAddress("f_alphamin", &f_ht1200_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_ht1200_Met);
    T_event6->SetBranchAddress("f_dileptonPT", &f_ht1200_dilpPT);
    T_event6->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_event6->SetBranchAddress("I_nThinJets", &I_ht1200_nThinJets);
    T_event6->SetBranchAddress("I_minJetflavor", &I_ht1200_minJetflavor);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (I_ht1200_nThinJets < 2)
            continue;
        if (I_ht1200_minJetflavor == 4 || I_ht1200_minJetflavor == 5)
        {
            if (alphaminupbound > f_ht1200_alphamin && f_ht1200_alphamin > alphaminlowerbound && f_ht1200_Met > 160)
            {
                h_ht1200A_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
                h_ht1200A_diLp_PT->Fill(f_ht1200_dilpPT, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
                h_ht1200A_leadjetpt->Fill(f_ht1200_leadJetpt, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
                h_ht1200A_leadjeteta->Fill(f_ht1200_leadJeteta, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
                h_ht1200A_minjetpt->Fill(f_ht1200_minJetpt, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
                h_ht1200A_minjeteta->Fill(f_ht1200_minJeteta, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
            }
            else if (f_ht1200_alphamin < 0.1 && f_ht1200_Met > 160)
            {
                h_ht1200B_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
                h_ht1200B_diLp_PT->Fill(f_ht1200_dilpPT, I_ht1200_weight * HT1200Weight);
                h_ht1200B_leadjetpt->Fill(f_ht1200_leadJetpt, I_ht1200_weight * HT1200Weight);
                h_ht1200B_leadjeteta->Fill(f_ht1200_leadJeteta, I_ht1200_weight * HT1200Weight);
                h_ht1200B_minjetpt->Fill(f_ht1200_minJetpt, I_ht1200_weight * HT1200Weight);
                h_ht1200B_minjeteta->Fill(f_ht1200_minJeteta, I_ht1200_weight * HT1200Weight);
            }
            else if (alphaminupbound > f_ht1200_alphamin && f_ht1200_alphamin > alphaminlowerbound && f_ht1200_Met < 100)
            {

                h_ht1200C_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
                h_ht1200C_diLp_PT->Fill(f_ht1200_dilpPT, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
                h_ht1200C_leadjetpt->Fill(f_ht1200_leadJetpt, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
                h_ht1200C_leadjeteta->Fill(f_ht1200_leadJeteta, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
                h_ht1200C_minjetpt->Fill(f_ht1200_minJetpt, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
                h_ht1200C_minjeteta->Fill(f_ht1200_minJeteta, I_ht1200_weight * HT1200Weight / background(f_ht1200_Met));
            }
            else if (f_ht1200_alphamin < 0.1 && f_ht1200_Met < 100)
            {
                h_ht1200D_jetmet->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
                h_ht1200D_diLp_PT->Fill(f_ht1200_dilpPT, I_ht1200_weight * HT1200Weight);
                h_ht1200D_leadjetpt->Fill(f_ht1200_leadJetpt, I_ht1200_weight * HT1200Weight);
                h_ht1200D_leadjeteta->Fill(f_ht1200_leadJeteta, I_ht1200_weight * HT1200Weight);
                h_ht1200D_minjetpt->Fill(f_ht1200_minJetpt, I_ht1200_weight * HT1200Weight);
                h_ht1200D_minjeteta->Fill(f_ht1200_minJeteta, I_ht1200_weight * HT1200Weight);
            }
        }

    } // End of HT1200

    TTree *T_event7;
    DYHT2500->GetObject("T_event", T_event7);
    T_event7->SetBranchAddress("f_leadJeteta", &f_ht2500_leadJeteta);
    T_event7->SetBranchAddress("f_leadJetpt", &f_ht2500_leadJetpt);
    T_event7->SetBranchAddress("f_minalphaJeteta", &f_ht2500_minJeteta);
    T_event7->SetBranchAddress("f_minalphaJetpt", &f_ht2500_minJetpt);
    T_event7->SetBranchAddress("f_alphamin", &f_ht2500_alphamin);
    T_event7->SetBranchAddress("f_Met", &f_ht2500_Met);
    T_event7->SetBranchAddress("f_dileptonPT", &f_ht2500_dilpPT);
    T_event7->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_event7->SetBranchAddress("I_nThinJets", &I_ht2500_nThinJets);
    T_event7->SetBranchAddress("I_minJetflavor", &I_ht2500_minJetflavor);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        if (I_ht2500_nThinJets < 2)
            continue;
        if (I_ht2500_minJetflavor == 4 || I_ht2500_minJetflavor == 5)
        {
            if (alphaminupbound > f_ht2500_alphamin && f_ht2500_alphamin > alphaminlowerbound && f_ht2500_Met > 160)
            {
                h_ht2500A_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
                h_ht2500A_diLp_PT->Fill(f_ht2500_dilpPT, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
                h_ht2500A_leadjetpt->Fill(f_ht2500_leadJetpt, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
                h_ht2500A_leadjeteta->Fill(f_ht2500_leadJeteta, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
                h_ht2500A_minjetpt->Fill(f_ht2500_minJetpt, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
                h_ht2500A_minjeteta->Fill(f_ht2500_minJeteta, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
            }
            else if (f_ht2500_alphamin < 0.1 && f_ht2500_Met > 160)
            {
                h_ht2500B_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
                h_ht2500B_diLp_PT->Fill(f_ht2500_dilpPT, I_ht2500_weight * HT2500Weight);
                h_ht2500B_leadjetpt->Fill(f_ht2500_leadJetpt, I_ht2500_weight * HT2500Weight);
                h_ht2500B_leadjeteta->Fill(f_ht2500_leadJeteta, I_ht2500_weight * HT2500Weight);
                h_ht2500B_minjetpt->Fill(f_ht2500_minJetpt, I_ht2500_weight * HT2500Weight);
                h_ht2500B_minjeteta->Fill(f_ht2500_minJeteta, I_ht2500_weight * HT2500Weight);
            }
            else if (alphaminupbound > f_ht2500_alphamin && f_ht2500_alphamin > alphaminlowerbound && f_ht2500_Met < 100)
            {
                h_ht2500C_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
                h_ht2500C_diLp_PT->Fill(f_ht2500_dilpPT, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
                h_ht2500C_leadjetpt->Fill(f_ht2500_leadJetpt, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
                h_ht2500C_leadjeteta->Fill(f_ht2500_leadJeteta, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
                h_ht2500C_minjetpt->Fill(f_ht2500_minJetpt, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
                h_ht2500C_minjeteta->Fill(f_ht2500_minJeteta, I_ht2500_weight * HT2500Weight / background(f_ht2500_Met));
            }
            else if (f_ht2500_alphamin < 0.1 && f_ht2500_Met < 100)
            {
                h_ht2500D_jetmet->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
                h_ht2500D_diLp_PT->Fill(f_ht2500_dilpPT, I_ht2500_weight * HT2500Weight);
                h_ht2500D_leadjetpt->Fill(f_ht2500_leadJetpt, I_ht2500_weight * HT2500Weight);
                h_ht2500D_leadjeteta->Fill(f_ht2500_leadJeteta, I_ht2500_weight * HT2500Weight);
                h_ht2500D_minjetpt->Fill(f_ht2500_minJetpt, I_ht2500_weight * HT2500Weight);
                h_ht2500D_minjeteta->Fill(f_ht2500_minJeteta, I_ht2500_weight * HT2500Weight);
            }
        }

    } // End of HT2500

    h_ht0A_leadjetpt->Add(h_ht70A_leadjetpt);
    h_ht0A_leadjetpt->Add(h_ht100A_leadjetpt);
    h_ht0A_leadjetpt->Add(h_ht200A_leadjetpt);
    h_ht0A_leadjetpt->Add(h_ht400A_leadjetpt);
    h_ht0A_leadjetpt->Add(h_ht600A_leadjetpt);
    h_ht0A_leadjetpt->Add(h_ht800A_leadjetpt);
    h_ht0A_leadjetpt->Add(h_ht1200A_leadjetpt);
    h_ht0A_leadjetpt->Add(h_ht2500A_leadjetpt);

    h_ht0B_leadjetpt->Add(h_ht70B_leadjetpt);
    h_ht0B_leadjetpt->Add(h_ht100B_leadjetpt);
    h_ht0B_leadjetpt->Add(h_ht200B_leadjetpt);
    h_ht0B_leadjetpt->Add(h_ht400B_leadjetpt);
    h_ht0B_leadjetpt->Add(h_ht600B_leadjetpt);
    h_ht0B_leadjetpt->Add(h_ht800B_leadjetpt);
    h_ht0B_leadjetpt->Add(h_ht1200B_leadjetpt);
    h_ht0B_leadjetpt->Add(h_ht2500B_leadjetpt);

    h_ht0C_leadjetpt->Add(h_ht70C_leadjetpt);
    h_ht0C_leadjetpt->Add(h_ht100C_leadjetpt);
    h_ht0C_leadjetpt->Add(h_ht200C_leadjetpt);
    h_ht0C_leadjetpt->Add(h_ht400C_leadjetpt);
    h_ht0C_leadjetpt->Add(h_ht600C_leadjetpt);
    h_ht0C_leadjetpt->Add(h_ht800C_leadjetpt);
    h_ht0C_leadjetpt->Add(h_ht1200C_leadjetpt);
    h_ht0C_leadjetpt->Add(h_ht2500C_leadjetpt);

    h_ht0D_leadjetpt->Add(h_ht70D_leadjetpt);
    h_ht0D_leadjetpt->Add(h_ht100D_leadjetpt);
    h_ht0D_leadjetpt->Add(h_ht200D_leadjetpt);
    h_ht0D_leadjetpt->Add(h_ht400D_leadjetpt);
    h_ht0D_leadjetpt->Add(h_ht600D_leadjetpt);
    h_ht0D_leadjetpt->Add(h_ht800D_leadjetpt);
    h_ht0D_leadjetpt->Add(h_ht1200D_leadjetpt);
    h_ht0D_leadjetpt->Add(h_ht2500D_leadjetpt);

    h_ht0A_minjetpt->Add(h_ht70A_minjetpt);
    h_ht0A_minjetpt->Add(h_ht100A_minjetpt);
    h_ht0A_minjetpt->Add(h_ht200A_minjetpt);
    h_ht0A_minjetpt->Add(h_ht400A_minjetpt);
    h_ht0A_minjetpt->Add(h_ht600A_minjetpt);
    h_ht0A_minjetpt->Add(h_ht800A_minjetpt);
    h_ht0A_minjetpt->Add(h_ht1200A_minjetpt);
    h_ht0A_minjetpt->Add(h_ht2500A_minjetpt);

    h_ht0B_minjetpt->Add(h_ht70B_minjetpt);
    h_ht0B_minjetpt->Add(h_ht100B_minjetpt);
    h_ht0B_minjetpt->Add(h_ht200B_minjetpt);
    h_ht0B_minjetpt->Add(h_ht400B_minjetpt);
    h_ht0B_minjetpt->Add(h_ht600B_minjetpt);
    h_ht0B_minjetpt->Add(h_ht800B_minjetpt);
    h_ht0B_minjetpt->Add(h_ht1200B_minjetpt);
    h_ht0B_minjetpt->Add(h_ht2500B_minjetpt);

    h_ht0C_minjetpt->Add(h_ht70C_minjetpt);
    h_ht0C_minjetpt->Add(h_ht100C_minjetpt);
    h_ht0C_minjetpt->Add(h_ht200C_minjetpt);
    h_ht0C_minjetpt->Add(h_ht400C_minjetpt);
    h_ht0C_minjetpt->Add(h_ht600C_minjetpt);
    h_ht0C_minjetpt->Add(h_ht800C_minjetpt);
    h_ht0C_minjetpt->Add(h_ht1200C_minjetpt);
    h_ht0C_minjetpt->Add(h_ht2500C_minjetpt);

    h_ht0D_minjetpt->Add(h_ht70D_minjetpt);
    h_ht0D_minjetpt->Add(h_ht100D_minjetpt);
    h_ht0D_minjetpt->Add(h_ht200D_minjetpt);
    h_ht0D_minjetpt->Add(h_ht400D_minjetpt);
    h_ht0D_minjetpt->Add(h_ht600D_minjetpt);
    h_ht0D_minjetpt->Add(h_ht800D_minjetpt);
    h_ht0D_minjetpt->Add(h_ht1200D_minjetpt);
    h_ht0D_minjetpt->Add(h_ht2500D_minjetpt);

    h_ht0A_leadjeteta->Add(h_ht70A_leadjeteta);
    h_ht0A_leadjeteta->Add(h_ht100A_leadjeteta);
    h_ht0A_leadjeteta->Add(h_ht200A_leadjeteta);
    h_ht0A_leadjeteta->Add(h_ht400A_leadjeteta);
    h_ht0A_leadjeteta->Add(h_ht600A_leadjeteta);
    h_ht0A_leadjeteta->Add(h_ht800A_leadjeteta);
    h_ht0A_leadjeteta->Add(h_ht1200A_leadjeteta);
    h_ht0A_leadjeteta->Add(h_ht2500A_leadjeteta);

    h_ht0B_leadjeteta->Add(h_ht70B_leadjeteta);
    h_ht0B_leadjeteta->Add(h_ht100B_leadjeteta);
    h_ht0B_leadjeteta->Add(h_ht200B_leadjeteta);
    h_ht0B_leadjeteta->Add(h_ht400B_leadjeteta);
    h_ht0B_leadjeteta->Add(h_ht600B_leadjeteta);
    h_ht0B_leadjeteta->Add(h_ht800B_leadjeteta);
    h_ht0B_leadjeteta->Add(h_ht1200B_leadjeteta);
    h_ht0B_leadjeteta->Add(h_ht2500B_leadjeteta);

    h_ht0C_leadjeteta->Add(h_ht70C_leadjeteta);
    h_ht0C_leadjeteta->Add(h_ht100C_leadjeteta);
    h_ht0C_leadjeteta->Add(h_ht200C_leadjeteta);
    h_ht0C_leadjeteta->Add(h_ht400C_leadjeteta);
    h_ht0C_leadjeteta->Add(h_ht600C_leadjeteta);
    h_ht0C_leadjeteta->Add(h_ht800C_leadjeteta);
    h_ht0C_leadjeteta->Add(h_ht1200C_leadjeteta);
    h_ht0C_leadjeteta->Add(h_ht2500C_leadjeteta);

    h_ht0D_leadjeteta->Add(h_ht70D_leadjeteta);
    h_ht0D_leadjeteta->Add(h_ht100D_leadjeteta);
    h_ht0D_leadjeteta->Add(h_ht200D_leadjeteta);
    h_ht0D_leadjeteta->Add(h_ht400D_leadjeteta);
    h_ht0D_leadjeteta->Add(h_ht600D_leadjeteta);
    h_ht0D_leadjeteta->Add(h_ht800D_leadjeteta);
    h_ht0D_leadjeteta->Add(h_ht1200D_leadjeteta);
    h_ht0D_leadjeteta->Add(h_ht2500D_leadjeteta);

    h_ht0A_minjeteta->Add(h_ht70A_minjeteta);
    h_ht0A_minjeteta->Add(h_ht100A_minjeteta);
    h_ht0A_minjeteta->Add(h_ht200A_minjeteta);
    h_ht0A_minjeteta->Add(h_ht400A_minjeteta);
    h_ht0A_minjeteta->Add(h_ht600A_minjeteta);
    h_ht0A_minjeteta->Add(h_ht800A_minjeteta);
    h_ht0A_minjeteta->Add(h_ht1200A_minjeteta);
    h_ht0A_minjeteta->Add(h_ht2500A_minjeteta);

    h_ht0B_minjeteta->Add(h_ht70B_minjeteta);
    h_ht0B_minjeteta->Add(h_ht100B_minjeteta);
    h_ht0B_minjeteta->Add(h_ht200B_minjeteta);
    h_ht0B_minjeteta->Add(h_ht400B_minjeteta);
    h_ht0B_minjeteta->Add(h_ht600B_minjeteta);
    h_ht0B_minjeteta->Add(h_ht800B_minjeteta);
    h_ht0B_minjeteta->Add(h_ht1200B_minjeteta);
    h_ht0B_minjeteta->Add(h_ht2500B_minjeteta);

    h_ht0C_minjeteta->Add(h_ht70C_minjeteta);
    h_ht0C_minjeteta->Add(h_ht100C_minjeteta);
    h_ht0C_minjeteta->Add(h_ht200C_minjeteta);
    h_ht0C_minjeteta->Add(h_ht400C_minjeteta);
    h_ht0C_minjeteta->Add(h_ht600C_minjeteta);
    h_ht0C_minjeteta->Add(h_ht800C_minjeteta);
    h_ht0C_minjeteta->Add(h_ht1200C_minjeteta);
    h_ht0C_minjeteta->Add(h_ht2500C_minjeteta);

    h_ht0D_minjeteta->Add(h_ht70D_minjeteta);
    h_ht0D_minjeteta->Add(h_ht100D_minjeteta);
    h_ht0D_minjeteta->Add(h_ht200D_minjeteta);
    h_ht0D_minjeteta->Add(h_ht400D_minjeteta);
    h_ht0D_minjeteta->Add(h_ht600D_minjeteta);
    h_ht0D_minjeteta->Add(h_ht800D_minjeteta);
    h_ht0D_minjeteta->Add(h_ht1200D_minjeteta);
    h_ht0D_minjeteta->Add(h_ht2500D_minjeteta);

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
    c1->Divide(4, 2);

    c1->cd(1);
    gStyle->SetOptStat(0);
    h_ht0B_jetmet->SetTitle("Met");
    h_ht0B_jetmet->SetXTitle("Met");
    h_ht0B_jetmet->SetYTitle("");
    h_ht0B_jetmet->SetLineWidth(2);
    h_ht0A_jetmet->SetLineWidth(2);
    h_ht0A_jetmet->SetLineColor(kOrange + 7);
    // h_ht0A_leadjetpt->SetFillColor(kOrange + 7);
    h_ht0B_jetmet->SetLineColor(kGray + 3);
    // h_ht0B_leadjetpt->SetFillColor(kGray + 3);
    // h_ht0B_jetmet->Draw("hist&&E");
    h_ht0B_jetmet->Draw("hist&&E");
    h_ht0A_jetmet->Draw("hist&&E&&same");
    

    TLegend *l1 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_ht0A_jetmet, "Region A / ratio ", "l");
    l1->AddEntry(h_ht0B_jetmet, "Region B (SR) ", "l");
    l1->Draw();
    c1->cd(5);
    gStyle->SetOptStat(0);
    h_ht0D_jetmet->SetXTitle("Met");
    h_ht0C_jetmet->SetYTitle("N events");
    h_ht0C_jetmet->SetLineWidth(2);
    h_ht0D_jetmet->SetLineWidth(2);
    h_ht0C_jetmet->SetLineColor(kOrange + 7);
    h_ht0D_jetmet->SetLineColor(kGray + 3);
    h_ht0D_jetmet->Draw("hist&&E");

    h_ht0C_jetmet->Draw("hist&&E&&same");
    
    // h_ht0A_leadjetpt->Divide(h_ht0B_leadjetpt);
    // h_ht0D_leadjetpt->SetTitle("D*Ratio");
    // h_ht0D_leadjetpt->SetXTitle("Jet PT");
    // h_ht0D_leadjetpt->DrawNormalized("hist");

    TLegend *l2 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(h_ht0C_jetmet, "Region C / ratio ", "l");
    l2->AddEntry(h_ht0D_jetmet, "Region D ", "l");
    l2->Draw();

    c1->cd(2);
    gStyle->SetOptStat(0);
    h_ht0A_diLp_PT->SetXTitle("dilepton PT");
    // h_ht0A_diLp_PT->SetYTitle("Normalized");
    h_ht0A_diLp_PT->SetLineWidth(2);
    h_ht0B_diLp_PT->SetLineWidth(2);
    h_ht0A_diLp_PT->SetLineColor(kOrange + 7);
    h_ht0B_diLp_PT->SetLineColor(kGray + 3);
    h_ht0B_diLp_PT->Draw("hist&&e");
    h_ht0A_diLp_PT->Draw("hist&&e&&same");
    

    TLegend *l3 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.04);
    l3->AddEntry(h_ht0A_diLp_PT, "Region A / ratio ", "l");
    l3->AddEntry(h_ht0B_diLp_PT, "Region B ", "l");
    //l3->Draw();
    c1->cd(6);
    gStyle->SetOptStat(0);
    h_ht0C_diLp_PT->SetXTitle("dilepton PT");
    // h_ht0C_diLp_PT->SetYTitle("Normalized");
    h_ht0C_diLp_PT->SetLineWidth(2);
    h_ht0D_diLp_PT->SetLineWidth(2);
    h_ht0C_diLp_PT->SetLineColor(kOrange + 7);
    h_ht0D_diLp_PT->SetLineColor(kGray + 3);
    h_ht0D_diLp_PT->Draw("hist&&e");
    h_ht0C_diLp_PT->Draw("hist&&e&&same");

    TLegend *l4 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.04);
    l4->AddEntry(h_ht0C_diLp_PT, "Region C / ratio ", "l");
    l4->AddEntry(h_ht0D_diLp_PT, "Region D ", "l");
    //l4->Draw();
    /*
        c1->cd(3);
        gStyle->SetOptStat(0);
        h_ht0A_leadjetpt->SetXTitle("leading Jet PT");
        // h_ht0A_leadjetpt->SetYTitle("Normalized");
        h_ht0A_leadjetpt->SetLineWidth(2);
        h_ht0B_leadjetpt->SetLineWidth(2);
        h_ht0A_leadjetpt->SetLineColor(kOrange + 7);
        h_ht0B_leadjetpt->SetLineColor(kGray + 3);
        h_ht0A_leadjetpt->Draw("hist&&e");
        h_ht0B_leadjetpt->Draw("hist&&e&&same");


        TLegend *l5 = new TLegend(0.20, 0.55, 0.70, 0.8);
        l5->SetBorderSize(0);
        l5->SetTextSize(0.04);
        l5->AddEntry(h_ht0A_leadjetpt, "Region A / ratio ", "l");
        l5->AddEntry(h_ht0B_leadjetpt, "Region B ", "l");
        //l5->Draw();
        c1->cd(7);
        gStyle->SetOptStat(0);
        h_ht0C_leadjetpt->SetXTitle("leading Jet PT");
        // h_ht0C_leadjetpt->SetYTitle("Normalized");
        h_ht0C_leadjetpt->SetLineWidth(2);
        h_ht0D_leadjetpt->SetLineWidth(2);
        h_ht0C_leadjetpt->SetLineColor(kOrange + 7);
        h_ht0D_leadjetpt->SetLineColor(kGray + 3);
        h_ht0D_leadjetpt->Draw("hist&&e");
        h_ht0C_leadjetpt->Draw("hist&&e&&same");



        TLegend *l6 = new TLegend(0.20, 0.55, 0.70, 0.8);
        l6->SetBorderSize(0);
        l6->SetTextSize(0.04);
        l6->AddEntry(h_ht0C_leadjetpt, "Region C / ratio ", "l");
        l6->AddEntry(h_ht0D_leadjetpt, "Region D ", "l");
        //l6->Draw();
        c1->cd(3);
        gStyle->SetOptStat(0);
        h_ht0A_leadjeteta->SetXTitle("leading Jet eta");
        // h_ht0A_leadjeteta->SetYTitle("Normalized");
        h_ht0A_leadjeteta->SetLineWidth(2);
        h_ht0B_leadjeteta->SetLineWidth(2);
        h_ht0A_leadjeteta->SetLineColor(kOrange + 7);
        h_ht0B_leadjeteta->SetLineColor(kGray + 3);
        h_ht0A_leadjeteta->Draw("hist&&e");
        h_ht0B_leadjeteta->Draw("hist&&e&&same");


        TLegend *l7 = new TLegend(0.20, 0.55, 0.70, 0.8);
        l7->SetBorderSize(0);
        l7->SetTextSize(0.04);
        l7->AddEntry(h_ht0A_leadjeteta, "Region A / ratio ", "l");
        l7->AddEntry(h_ht0B_leadjeteta, "Region B ", "l");
        //l7->Draw();
        c1->cd(8);
        gStyle->SetOptStat(0);
        h_ht0C_leadjeteta->SetXTitle("leading Jet eta");
        // h_ht0C_leadjeteta->SetYTitle("Normalized");
        h_ht0C_leadjeteta->SetLineWidth(2);
        h_ht0D_leadjeteta->SetLineWidth(2);
        h_ht0C_leadjeteta->SetLineColor(kOrange + 7);
        h_ht0D_leadjeteta->SetLineColor(kGray + 3);
        h_ht0C_leadjeteta->Draw("hist&&e");
        h_ht0D_leadjeteta->Draw("hist&&e&&same");

        TLegend *l8 = new TLegend(0.20, 0.55, 0.70, 0.8);
        l8->SetBorderSize(0);
        l8->SetTextSize(0.04);
        l8->AddEntry(h_ht0C_leadjeteta, "Region C / ratio ", "l");
        l8->AddEntry(h_ht0D_leadjeteta, "Region D ", "l");
        //l8->Draw();
    */
    // auto c2 = new TCanvas("c", "BPRE");
    // c2->Divide(6, 2);
    c1->cd(3);
    h_ht0A_minjetpt->SetXTitle("minJet Jet PT");
    // h_ht0A_leadjetpt->SetYTitle("Normalized");
    h_ht0A_minjetpt->SetLineWidth(2);
    h_ht0B_minjetpt->SetLineWidth(2);
    h_ht0A_minjetpt->SetLineColor(kOrange + 7);
    h_ht0B_minjetpt->SetLineColor(kGray + 3);
    h_ht0B_minjetpt->Draw("hist&&e");
    h_ht0A_minjetpt->Draw("hist&&e&&same");
    

    TLegend *i1 = new TLegend(0.20, 0.55, 0.70, 0.8);
    i1->SetBorderSize(0);
    i1->SetTextSize(0.04);
    i1->AddEntry(h_ht0A_minjetpt, "Region A/Ratio ", "l");
    i1->AddEntry(h_ht0B_minjetpt, "Region B ", "l");
    // i1->Draw();
    c1->cd(7);
    gStyle->SetOptStat(0);
    h_ht0C_minjetpt->SetXTitle("minJet Jet PT");
    h_ht0C_minjetpt->SetLineWidth(2);
    h_ht0D_minjetpt->SetLineWidth(2);
    h_ht0C_minjetpt->SetLineColor(kOrange + 7);
    h_ht0D_minjetpt->SetLineColor(kGray + 3);
    h_ht0D_minjetpt->Draw("hist&&e");
    h_ht0C_minjetpt->Draw("hist&&e&&same");

    TLegend *i2 = new TLegend(0.20, 0.55, 0.70, 0.8);
    i2->SetBorderSize(0);
    i2->SetTextSize(0.04);
    i2->AddEntry(h_ht0C_minjetpt, "Region C/Ratio ", "l");
    i2->AddEntry(h_ht0D_minjetpt, "Region D ", "l");
    //i2->Draw();

    c1->cd(4);
    gStyle->SetOptStat(0);
    
    h_ht0A_minjeteta->SetLineWidth(2);
    h_ht0B_minjeteta->SetLineWidth(2);
    h_ht0A_minjeteta->SetLineColor(kOrange + 7);
    h_ht0B_minjeteta->SetLineColor(kGray + 3);
    h_ht0A_minjeteta->Draw("hist&&e");
    h_ht0B_minjeteta->Draw("hist&&e&&same");

    TLegend *i3 = new TLegend(0.20, 0.55, 0.70, 0.8);
    i3->SetBorderSize(0);
    i3->SetTextSize(0.04);
    i3->AddEntry(h_ht0A_minjeteta, "Region A/Ratio ", "l");
    i3->AddEntry(h_ht0B_minjeteta, "Region B ", "l");
    // i3->Draw();

    c1->cd(8);
    gStyle->SetOptStat(0);
    // h_ht0C_leadjeteta->SetYTitle("Normalized");
    h_ht0C_minjeteta->SetLineWidth(2);
    h_ht0D_minjeteta->SetLineWidth(2);
    h_ht0C_minjeteta->SetLineColor(kOrange + 7);
    h_ht0D_minjeteta->SetLineColor(kGray + 3);
    h_ht0C_minjeteta->Draw("hist&&e");
    h_ht0D_minjeteta->Draw("hist&&e&&same");


    TLegend *i4 = new TLegend(0.20, 0.55, 0.70, 0.8);
    i4->SetBorderSize(0);
    i4->SetTextSize(0.04);
    i4->AddEntry(h_ht0C_minjeteta, "Region C/Ratio ", "l");
    i4->AddEntry(h_ht0D_minjeteta, "Region D ", "l");
    // i4->Draw();
}
