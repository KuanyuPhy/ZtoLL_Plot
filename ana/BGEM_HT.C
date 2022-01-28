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

void BGEM_HT()
{

    auto c1 = new TCanvas("c", "BPRE");
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

    h_HT_eventCout->Draw();
    // TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("Event_Variable/h_event"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("Event_Variable/h_event"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("Event_Variable/h_event"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("Event_Variable/h_event"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("Event_Variable/h_event"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("Event_Variable/h_event"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("Event_Variable/h_event"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("Event_Variable/h_event"));

    // int DYHT70_totevt = DYHT70_sumevt->GetEntries();
    int DYHT100_totevt = DYHT100_sumevt->Integral();
    int DYHT200_totevt = DYHT200_sumevt->Integral();
    int DYHT400_totevt = DYHT400_sumevt->Integral();
    int DYHT600_totevt = DYHT600_sumevt->Integral();
    int DYHT800_totevt = DYHT800_sumevt->Integral();
    int DYHT1200_totevt = DYHT1200_sumevt->Integral();
    int DYHT2500_totevt = DYHT2500_sumevt->Integral();

    int HT0_70_event = h_HT_eventCout->GetBinContent(2);
    int HT70_100_event = h_HT_eventCout->GetBinContent(3);
    // cout << HT70_100_event<<endl;
    int HT100_200_event = h_HT_eventCout->GetBinContent(4);
    int HT200_400_event = h_HT_eventCout->GetBinContent(5);
    int HT400_600_event = h_HT_eventCout->GetBinContent(6);
    int HT600_800_event = h_HT_eventCout->GetBinContent(7);
    int HT800_1200_event = h_HT_eventCout->GetBinContent(8);
    int HT1200_2500_event = h_HT_eventCout->GetBinContent(9);
    int HT2500_Inf_event = h_HT_eventCout->GetBinContent(10);

    // DYHT
    TH1F *h_ht0A_aphmin = new TH1F("h_ht0A_aphmin", "", 24, 0, 1.2);
    h_ht0A_aphmin->Sumw2();
    TH1F *h_ht0B_aphmin = new TH1F("h_ht0B_aphmin", "", 24, 0, 1.2);
    h_ht0B_aphmin->Sumw2();

    TH1F *h_ht70A_aphmin = new TH1F("h_ht70A_aphmin", "", 24, 0, 1.2);
    h_ht70A_aphmin->Sumw2();
    TH1F *h_ht70B_aphmin = new TH1F("h_ht70B_aphmin", "", 24, 0, 1.2);
    h_ht70B_aphmin->Sumw2();

    TH1F *h_ht100A_aphmin = new TH1F("h_ht100A_aphmin", "", 24, 0, 1.2);
    h_ht100A_aphmin->Sumw2();
    TH1F *h_ht100B_aphmin = new TH1F("h_ht100B_aphmin", "", 24, 0, 1.2);
    h_ht100B_aphmin->Sumw2();

    TH1F *h_ht200A_aphmin = new TH1F("h_ht200A_aphmin", "", 24, 0, 1.2);
    h_ht200A_aphmin->Sumw2();
    TH1F *h_ht200B_aphmin = new TH1F("h_ht200B_aphmin", "", 24, 0, 1.2);
    h_ht200B_aphmin->Sumw2();

    TH1F *h_ht400A_aphmin = new TH1F("h_ht400A_aphmin", "", 24, 0, 1.2);
    h_ht400A_aphmin->Sumw2();
    TH1F *h_ht400B_aphmin = new TH1F("h_ht400B_aphmin", "", 24, 0, 1.2);
    h_ht400B_aphmin->Sumw2();

    TH1F *h_ht600A_aphmin = new TH1F("h_ht600A_aphmin", "", 24, 0, 1.2);
    h_ht600A_aphmin->Sumw2();
    TH1F *h_ht600B_aphmin = new TH1F("h_ht600B_aphmin", "", 24, 0, 1.2);
    h_ht600B_aphmin->Sumw2();

    TH1F *h_ht800A_aphmin = new TH1F("h_ht800A_aphmin", "", 24, 0, 1.2);
    h_ht800A_aphmin->Sumw2();
    TH1F *h_ht800B_aphmin = new TH1F("h_ht800B_aphmin", "", 24, 0, 1.2);
    h_ht800B_aphmin->Sumw2();

    TH1F *h_ht1200A_aphmin = new TH1F("h_ht1200A_aphmin", "", 24, 0, 1.2);
    h_ht1200A_aphmin->Sumw2();
    TH1F *h_ht1200B_aphmin = new TH1F("h_ht1200B_aphmin", "", 24, 0, 1.2);
    h_ht1200B_aphmin->Sumw2();

    TH1F *h_ht2500A_aphmin = new TH1F("h_ht2500A_aphmin", "", 24, 0, 1.2);
    h_ht2500A_aphmin->Sumw2();
    TH1F *h_ht2500B_aphmin = new TH1F("h_ht2500B_aphmin", "", 24, 0, 1.2);
    h_ht2500B_aphmin->Sumw2();

    // int nbins = 10;

    float_t f_Ratio = 0;

    TTree *h1 = new TTree("h1", "Tree");
    h1->Branch("f_Ratio", &f_Ratio);
    // Double_t nbins[16] = {0.0,15 ,30, 55., 80., 100., 130., 175, 225., 275., 350, 450, 550, 750, 1000,5000};
    Double_t nbins[13] = {0.0, 30, 55., 80., 100., 130., 175, 225., 300., 400, 500, 600, 800};

    // Double_t nbins[11]= {0.0,15,30 ,50,70,100,200,400,600,800,5000};
    Int_t nnbins = (sizeof(nbins) / sizeof(*nbins)) - 1;

    // nnbins, nbins

    // DYHT
    TH1F *h_ht0A_met = new TH1F("h_ht0A_met", "HT0-70", nnbins, nbins);
    h_ht0A_met->Sumw2();
    TH1F *h_ht0B_met = new TH1F("h_ht0B_met", "HT0-70", nnbins, nbins);
    h_ht0B_met->Sumw2();

    TH1F *h_ht70A_met = new TH1F("h_ht70A_met", "HT70-100", nnbins, nbins);
    h_ht70A_met->Sumw2();
    TH1F *h_ht70B_met = new TH1F("h_ht70B_met", "HT70-100", nnbins, nbins);
    h_ht70B_met->Sumw2();

    TH1F *h_ht100A_met = new TH1F("h_ht100A_met", "HT100-200", nnbins, nbins);
    h_ht100A_met->Sumw2();
    TH1F *h_ht100B_met = new TH1F("h_ht100B_met", "HT100-200", nnbins, nbins);
    h_ht100B_met->Sumw2();

    TH1F *h_ht200A_met = new TH1F("h_ht200A_met", "HT200-400", nnbins, nbins);
    h_ht200A_met->Sumw2();
    TH1F *h_ht200B_met = new TH1F("h_ht200B_met", "HT200-400", nnbins, nbins);
    h_ht200B_met->Sumw2();

    TH1F *h_ht400A_met = new TH1F("h_ht400A_met", "HT400-600", nnbins, nbins);
    h_ht400A_met->Sumw2();
    TH1F *h_ht400B_met = new TH1F("h_ht400B_met", "HT400-600", nnbins, nbins);
    h_ht400B_met->Sumw2();

    TH1F *h_ht600A_met = new TH1F("h_ht600A_met", "HT600-800", nnbins, nbins);
    h_ht600A_met->Sumw2();
    TH1F *h_ht600B_met = new TH1F("h_ht600B_met", "HT600-800", nnbins, nbins);
    h_ht600B_met->Sumw2();

    TH1F *h_ht800A_met = new TH1F("h_ht800A_met", "HT800-1200", nnbins, nbins);
    h_ht800A_met->Sumw2();
    TH1F *h_ht800B_met = new TH1F("h_ht800B_met", "HT800-1200", nnbins, nbins);
    h_ht800B_met->Sumw2();

    TH1F *h_ht1200A_met = new TH1F("h_ht1200A_met", "HT1200-2500", nnbins, nbins);
    h_ht1200A_met->Sumw2();
    TH1F *h_ht1200B_met = new TH1F("h_ht1200B_met", "HT1200-2500", nnbins, nbins);
    h_ht1200B_met->Sumw2();

    TH1F *h_ht2500A_met = new TH1F("h_ht2500A_met", "HT2500-Inf", nnbins, nbins);
    h_ht2500A_met->Sumw2();
    TH1F *h_ht2500B_met = new TH1F("h_ht2500B_met", "HT2500-Inf", nnbins, nbins);
    h_ht2500B_met->Sumw2();

    // DYHT
    TH1F *h_ht70a_njet = new TH1F("h_ht70a_njet", "", 15, 0, 15);
    h_ht70a_njet->Sumw2();
    TH1F *h_ht70b_njet = new TH1F("h_ht70b_njet", "", 15, 0, 15);
    h_ht70b_njet->Sumw2();

    TH1F *h_ht100a_njet = new TH1F("h_ht100a_njet", "", 15, 0, 15);
    h_ht100a_njet->Sumw2();
    TH1F *h_ht100b_njet = new TH1F("h_ht100b_njet", "", 15, 0, 15);
    h_ht100b_njet->Sumw2();

    TH1F *h_ht200a_njet = new TH1F("h_ht200a_njet", "", 15, 0, 15);
    h_ht200a_njet->Sumw2();
    TH1F *h_ht200b_njet = new TH1F("h_ht200b_njet", "", 15, 0, 15);
    h_ht200b_njet->Sumw2();

    TH1F *h_ht400a_njet = new TH1F("h_ht400a_njet", "", 15, 0, 15);
    h_ht400a_njet->Sumw2();
    TH1F *h_ht400b_njet = new TH1F("h_ht400b_njet", "", 15, 0, 15);
    h_ht400b_njet->Sumw2();

    TH1F *h_ht600a_njet = new TH1F("h_ht600a_njet", "", 15, 0, 15);
    h_ht600a_njet->Sumw2();
    TH1F *h_ht600b_njet = new TH1F("h_ht600b_njet", "", 15, 0, 15);
    h_ht600b_njet->Sumw2();

    TH1F *h_ht800a_njet = new TH1F("h_ht800a_njet", "", 15, 0, 15);
    h_ht800a_njet->Sumw2();
    TH1F *h_ht800b_njet = new TH1F("h_ht800b_njet", "", 15, 0, 15);
    h_ht800b_njet->Sumw2();

    TH1F *h_ht1200a_njet = new TH1F("h_ht1200a_njet", "", 15, 0, 15);
    h_ht1200a_njet->Sumw2();
    TH1F *h_ht1200b_njet = new TH1F("h_ht1200b_njet", "", 15, 0, 15);
    h_ht1200b_njet->Sumw2();

    TH1F *h_ht2500a_njet = new TH1F("h_ht2500a_njet", "", 15, 0, 15);
    h_ht2500a_njet->Sumw2();
    TH1F *h_ht2500b_njet = new TH1F("h_ht2500b_njet", "", 15, 0, 15);
    h_ht2500b_njet->Sumw2();

    float_t HT;

    Double_t f_ht0_alphamin, f_ht70_alphamin, f_ht100_alphamin, f_ht200_alphamin, f_ht400_alphamin,
        f_ht600_alphamin, f_ht800_alphamin, f_ht1200_alphamin, f_ht2500_alphamin;

    float_t f_ht0_Met, f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    float_t f_ht0_dilpPT, f_ht70_dilpPT, f_ht100_dilpPT, f_ht200_dilpPT, f_ht400_dilpPT, f_ht600_dilpPT,
        f_ht800_dilpPT, f_ht1200_dilpPT, f_ht2500_dilpPT;

    Int_t I_ht0_nThinJets, I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets,
        I_ht600_nThinJets, I_ht800_nThinJets, I_ht1200_nThinJets, I_ht2500_nThinJets;
    Int_t I_ht0_leadJetflavor, I_ht70_leadJetflavor, I_ht100_leadJetflavor, I_ht200_leadJetflavor, I_ht400_leadJetflavor,
        I_ht600_leadJetflavor, I_ht800_leadJetflavor, I_ht1200_leadJetflavor, I_ht2500_leadJetflavor;
    Int_t I_ht0_minJetflavor, I_ht70_minJetflavor, I_ht100_minJetflavor, I_ht200_minJetflavor, I_ht400_minJetflavor,
        I_ht600_minJetflavor, I_ht800_minJetflavor, I_ht1200_minJetflavor, I_ht2500_minJetflavor;

    float alphaminupbound = 100;
    float alphaminlowerbound = 0.3;
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
    TTree *T_event;
    DYincli->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &I_ht0_weight);
    T_event->SetBranchAddress("f_alphamin", &f_ht0_alphamin);
    T_event->SetBranchAddress("f_Met", &f_ht0_Met);
    T_event->SetBranchAddress("I_nThinJets", &I_ht0_nThinJets);
    T_event->SetBranchAddress("f_dileptonPT", &f_ht0_dilpPT);
    T_event->SetBranchAddress("f_HT", &HT);
    T_event->SetBranchAddress("I_minJetflavor", &I_ht0_minJetflavor);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (I_ht0_nThinJets < 2)
            continue;
        if (I_ht0_minJetflavor == 0)
        {
            if (HT < 70)
            {
                if (f_ht0_Met > 160)
                {
                    h_ht0A_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT0Weight);
                }
                if (f_ht0_Met < 100)
                {
                    h_ht0B_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT0Weight);
                }
                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound)
                {
                    h_ht0A_met->Fill(f_ht0_Met, I_ht0_weight * HT0Weight);
                }
                if (f_ht0_alphamin < 0.1)
                {
                    h_ht0B_met->Fill(f_ht0_Met, I_ht0_weight * HT0Weight);
                }
            }
            else if (HT >= 70 && HT < 100)
            {

                if (f_ht0_Met > 160)
                {
                    h_ht70A_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT70Weight);
                }
                if (f_ht0_Met < 100)
                {
                    h_ht70B_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT70Weight);
                }
                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound)
                {
                    h_ht70A_met->Fill(f_ht0_Met, I_ht0_weight * HT70Weight);
                }
                if (f_ht0_alphamin < 0.1)
                {
                    h_ht70B_met->Fill(f_ht0_Met, I_ht0_weight * HT70Weight);
                }
            }
            else if (HT >= 100 && HT < 200)
            {
                if (f_ht0_Met > 160)
                {
                    h_ht100A_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT100Weight);
                }
                if (f_ht0_Met < 100)
                {
                    h_ht100B_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT100Weight);
                }
                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound)
                {
                    h_ht100A_met->Fill(f_ht0_Met, I_ht0_weight * HT100Weight);
                }
                if (f_ht0_alphamin < 0.1)
                {
                    h_ht100B_met->Fill(f_ht0_Met, I_ht0_weight * HT100Weight);
                }
            }
            else if (HT >= 200 && HT < 400)
            {
                if (f_ht0_Met > 160)
                {
                    h_ht200A_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT200Weight);
                }
                if (f_ht0_Met < 100)
                {
                    h_ht200B_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT200Weight);
                }
                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound)
                {
                    h_ht200A_met->Fill(f_ht0_Met, I_ht0_weight * HT200Weight);
                }
                if (f_ht0_alphamin < 0.1)
                {
                    h_ht200B_met->Fill(f_ht0_Met, I_ht0_weight * HT200Weight);
                }
            }
            else if (HT >= 400 && HT < 600)
            {
                if (f_ht0_Met > 160)
                {
                    h_ht400A_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT400Weight);
                }
                if (f_ht0_Met < 100)
                {
                    h_ht400B_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT400Weight);
                }
                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound)
                {
                    h_ht400A_met->Fill(f_ht0_Met, I_ht0_weight * HT400Weight);
                }
                if (f_ht0_alphamin < 0.1)
                {
                    h_ht400B_met->Fill(f_ht0_Met, I_ht0_weight * HT400Weight);
                }
            }
            else if (HT >= 600 && HT < 800)
            {
                if (f_ht0_Met > 160)
                {
                    h_ht600A_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT600Weight);
                }
                if (f_ht0_Met < 100)
                {
                    h_ht600B_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT600Weight);
                }
                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound)
                {
                    h_ht600A_met->Fill(f_ht0_Met, I_ht0_weight * HT600Weight);
                }
                if (f_ht0_alphamin < 0.1)
                {
                    h_ht600B_met->Fill(f_ht0_Met, I_ht0_weight * HT600Weight);
                }
            }
            else if (HT >= 800 && HT < 1200)
            {
                if (f_ht0_Met > 160)
                {
                    h_ht800A_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT800Weight);
                }
                if (f_ht0_Met < 100)
                {
                    h_ht800B_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT800Weight);
                }
                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound)
                {
                    h_ht800A_met->Fill(f_ht0_Met, I_ht0_weight * HT800Weight);
                }
                if (f_ht0_alphamin < 0.1)
                {
                    h_ht800B_met->Fill(f_ht0_Met, I_ht0_weight * HT800Weight);
                }
            }
            else if (HT >= 1200 && HT < 2500)
            {
                if (f_ht0_Met > 160)
                {
                    h_ht1200A_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT1200Weight);
                }
                if (f_ht0_Met < 100)
                {
                    h_ht1200B_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT1200Weight);
                }
                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound)
                {
                    h_ht1200A_met->Fill(f_ht0_Met, I_ht0_weight * HT1200Weight);
                }
                if (f_ht0_alphamin < 0.1)
                {
                    h_ht1200B_met->Fill(f_ht0_Met, I_ht0_weight * HT1200Weight);
                }
            }
            else if (HT >= 2500)
            {
                if (f_ht0_Met > 160)
                {
                    h_ht2500A_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT2500Weight);
                }
                if (f_ht0_Met < 100)
                {
                    h_ht2500B_aphmin->Fill(f_ht0_alphamin, I_ht0_weight * HT2500Weight);
                }
                if (alphaminupbound > f_ht0_alphamin && f_ht0_alphamin > alphaminlowerbound)
                {
                    h_ht2500A_met->Fill(f_ht0_Met, I_ht0_weight * HT2500Weight);
                }
                if (f_ht0_alphamin < 0.1)
                {
                    h_ht2500B_met->Fill(f_ht0_Met, I_ht0_weight * HT2500Weight);
                }
            }
        }
    }
    // h_ht0B_met->Draw();

    TTree *T_event1;
    DYHT100->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_ht100_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_ht100_Met);
    T_event1->SetBranchAddress("I_weight", &I_ht100_weight);
    T_event1->SetBranchAddress("f_dileptonPT", &f_ht100_dilpPT);
    T_event1->SetBranchAddress("I_nThinJets", &I_ht100_nThinJets);
    T_event1->SetBranchAddress("I_minJetflavor", &I_ht100_minJetflavor);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (I_ht100_nThinJets < 2)
            continue;
        if (I_ht100_minJetflavor == 0)
        {
            if (f_ht100_Met > 160)
            {
                h_ht100A_aphmin->Fill(f_ht100_alphamin, I_ht100_weight * HT100Weight);
            }
            if (f_ht100_Met < 100)
            {
                h_ht100B_aphmin->Fill(f_ht100_alphamin, I_ht100_weight * HT100Weight);
            }
            if (alphaminupbound > f_ht100_alphamin && f_ht100_alphamin > alphaminlowerbound)
            {
                h_ht100A_met->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
            }
            if (f_ht100_alphamin < 0.1)
            {
                h_ht100B_met->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
            }
        }
    }

    TTree *T_event2;
    DYHT200->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_ht200_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_ht200_Met);
    T_event2->SetBranchAddress("I_weight", &I_ht200_weight);
    T_event2->SetBranchAddress("f_dileptonPT", &f_ht200_dilpPT);
    T_event2->SetBranchAddress("I_nThinJets", &I_ht200_nThinJets);
    T_event2->SetBranchAddress("I_minJetflavor", &I_ht200_minJetflavor);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (I_ht200_nThinJets < 2)
            continue;
        if (I_ht200_minJetflavor == 4 || I_ht200_minJetflavor == 0)
        {
            if (f_ht200_Met > 160)
            {
                h_ht200A_aphmin->Fill(f_ht200_alphamin, I_ht200_weight * HT200Weight);
            }
            if (f_ht200_Met < 100)
            {
                h_ht200B_aphmin->Fill(f_ht200_alphamin, I_ht200_weight * HT200Weight);
            }
            if (alphaminupbound > f_ht200_alphamin && f_ht200_alphamin > alphaminlowerbound)
            {
                h_ht200A_met->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
            }
            if (f_ht200_alphamin < 0.1)
            {
                h_ht200B_met->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
            }
        }
    }

    TTree *T_event3;
    DYHT400->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &f_ht400_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_ht400_Met);
    T_event3->SetBranchAddress("I_weight", &I_ht400_weight);
    T_event3->SetBranchAddress("f_dileptonPT", &f_ht400_dilpPT);
    T_event3->SetBranchAddress("I_nThinJets", &I_ht400_nThinJets);
    T_event3->SetBranchAddress("I_minJetflavor", &I_ht400_minJetflavor);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (I_ht400_nThinJets < 2)
            continue;
        if (I_ht400_minJetflavor == 0)
        {
            if (f_ht400_Met > 160)
            {
                h_ht400A_aphmin->Fill(f_ht400_alphamin, I_ht400_weight * HT400Weight);
            }
            if (f_ht400_Met < 100)
            {
                h_ht400B_aphmin->Fill(f_ht400_alphamin, I_ht400_weight * HT400Weight);
            }
            if (alphaminupbound > f_ht400_alphamin && f_ht400_alphamin > alphaminlowerbound)
            {
                h_ht400A_met->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
            }
            if (f_ht400_alphamin < 0.1)
            {
                h_ht400B_met->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
            }
        }
    }

    TTree *T_event4;
    DYHT600->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &f_ht600_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_ht600_Met);
    T_event4->SetBranchAddress("I_weight", &I_ht600_weight);
    T_event4->SetBranchAddress("f_dileptonPT", &f_ht600_dilpPT);
    T_event4->SetBranchAddress("I_nThinJets", &I_ht600_nThinJets);
    T_event4->SetBranchAddress("I_minJetflavor", &I_ht600_minJetflavor);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (I_ht600_nThinJets < 2)
            continue;
        if (I_ht600_minJetflavor == 0)
        {
            if (f_ht600_Met > 160)
            {
                h_ht600A_aphmin->Fill(f_ht600_alphamin, I_ht600_weight * HT600Weight);
            }
            if (f_ht600_Met < 100)
            {
                h_ht600B_aphmin->Fill(f_ht600_alphamin, I_ht600_weight * HT600Weight);
            }
            if (alphaminupbound > f_ht600_alphamin && f_ht600_alphamin > alphaminlowerbound)
            {
                h_ht600A_met->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
            }
            if (f_ht600_alphamin < 0.1)
            {
                h_ht600B_met->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
            }
        }
    }

    TTree *T_event5;
    DYHT800->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &f_ht800_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_ht800_Met);
    T_event5->SetBranchAddress("I_weight", &I_ht800_weight);
    T_event5->SetBranchAddress("f_dileptonPT", &f_ht800_dilpPT);
    T_event5->SetBranchAddress("I_nThinJets", &I_ht800_nThinJets);
    T_event5->SetBranchAddress("I_minJetflavor", &I_ht800_minJetflavor);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (I_ht800_nThinJets < 2)
            continue;
        if (I_ht800_minJetflavor == 0)
        {
            if (f_ht800_Met > 160)
            {
                h_ht800A_aphmin->Fill(f_ht800_alphamin, I_ht800_weight * HT800Weight);
            }
            if (f_ht800_Met < 100)
            {
                h_ht800B_aphmin->Fill(f_ht800_alphamin, I_ht800_weight * HT800Weight);
            }
            if (alphaminupbound > f_ht800_alphamin && f_ht800_alphamin > alphaminlowerbound)
            {
                h_ht800A_met->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
            }
            if (f_ht800_alphamin < 0.1)
            {
                h_ht800B_met->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
            }
        }
    }

    TTree *T_event6;
    DYHT1200->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &f_ht1200_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_ht1200_Met);
    T_event6->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_event6->SetBranchAddress("f_dileptonPT", &f_ht1200_dilpPT);
    T_event6->SetBranchAddress("I_nThinJets", &I_ht1200_nThinJets);
    T_event6->SetBranchAddress("I_minJetflavor", &I_ht1200_minJetflavor);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (I_ht1200_nThinJets < 2)
            continue;
        if ( I_ht1200_minJetflavor == 0)
        {
            if (f_ht1200_Met > 160)
            {
                h_ht1200A_aphmin->Fill(f_ht1200_alphamin, I_ht1200_weight * HT1200Weight);
            }
            if (f_ht1200_Met < 100)
            {
                h_ht1200B_aphmin->Fill(f_ht1200_alphamin, I_ht1200_weight * HT1200Weight);
            }
            if (alphaminupbound > f_ht1200_alphamin && f_ht1200_alphamin > alphaminlowerbound)
            {
                h_ht1200A_met->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
            }
            if (f_ht1200_alphamin < 0.1)
            {
                h_ht1200B_met->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
            }
        }
    }

    TTree *T_event7;
    DYHT2500->GetObject("T_event", T_event7);
    T_event7->SetBranchAddress("f_alphamin", &f_ht2500_alphamin);
    T_event7->SetBranchAddress("f_Met", &f_ht2500_Met);
    T_event7->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_event7->SetBranchAddress("f_dileptonPT", &f_ht2500_dilpPT);
    T_event7->SetBranchAddress("I_nThinJets", &I_ht2500_nThinJets);
    T_event7->SetBranchAddress("I_minJetflavor", &I_ht2500_minJetflavor);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        if (I_ht2500_nThinJets < 2)
            continue;
        if (I_ht2500_minJetflavor == 0)
        {
            if (f_ht2500_Met > 160)
            {
                h_ht2500A_aphmin->Fill(f_ht2500_alphamin, I_ht2500_weight * HT2500Weight);
            }
            if (f_ht2500_Met < 100)
            {
                h_ht2500B_aphmin->Fill(f_ht2500_alphamin, I_ht2500_weight * HT2500Weight);
            }
            if (alphaminupbound > f_ht2500_alphamin && f_ht2500_alphamin > alphaminlowerbound)
            {
                h_ht2500A_met->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
            }
            if (f_ht2500_alphamin < 0.1)
            {
                h_ht2500B_met->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
            }
        }
    }

    TH1F *h_DYHT_met_A = (TH1F *)h_ht0A_met->Clone("h_DYHT_met_A");
    TH1F *h_DYHT_met_B = (TH1F *)h_ht0B_met->Clone("h_DYHT_met_B");

    TH1F *h_DYHT_alphamin_A = (TH1F *)h_ht0A_aphmin->Clone("h_DYHT_alphamin_A");
    TH1F *h_DYHT_alphamin_B = (TH1F *)h_ht0B_aphmin->Clone("h_DYHT_alphamin_B");

    // c1->Divide(3, 4);
    // c1->cd(1);
    // h_ht0B_met->Draw();
    // c1->cd(2);
    // h_ht70A_met->Draw();
    // c1->cd(3);
    // h_ht100A_met->Draw();
    // c1->cd(3);
    // h_ht200A_met->Draw();

    h_DYHT_alphamin_A->Add(h_ht70A_aphmin);
    h_DYHT_alphamin_A->Add(h_ht100A_aphmin);
    h_DYHT_alphamin_A->Add(h_ht200A_aphmin);
    h_DYHT_alphamin_A->Add(h_ht400A_aphmin);
    h_DYHT_alphamin_A->Add(h_ht600A_aphmin);
    h_DYHT_alphamin_A->Add(h_ht800A_aphmin);
    h_DYHT_alphamin_A->Add(h_ht1200A_aphmin);
    h_DYHT_alphamin_A->Add(h_ht2500A_aphmin);

    h_DYHT_alphamin_B->Add(h_ht70B_aphmin);
    h_DYHT_alphamin_B->Add(h_ht100B_aphmin);
    h_DYHT_alphamin_B->Add(h_ht200B_aphmin);
    h_DYHT_alphamin_B->Add(h_ht400B_aphmin);
    h_DYHT_alphamin_B->Add(h_ht600B_aphmin);
    h_DYHT_alphamin_B->Add(h_ht800B_aphmin);
    h_DYHT_alphamin_B->Add(h_ht1200B_aphmin);
    h_DYHT_alphamin_B->Add(h_ht2500B_aphmin);

    h_DYHT_met_A->Add(h_ht70A_met);
    h_DYHT_met_A->Add(h_ht100A_met);
    h_DYHT_met_A->Add(h_ht200A_met);
    h_DYHT_met_A->Add(h_ht400A_met);
    h_DYHT_met_A->Add(h_ht600A_met);
    h_DYHT_met_A->Add(h_ht800A_met);
    h_DYHT_met_A->Add(h_ht1200A_met);
    h_DYHT_met_A->Add(h_ht2500A_met);

    h_DYHT_met_B->Add(h_ht70B_met);
    h_DYHT_met_B->Add(h_ht100B_met);
    h_DYHT_met_B->Add(h_ht200B_met);
    h_DYHT_met_B->Add(h_ht400B_met);
    h_DYHT_met_B->Add(h_ht600B_met);
    h_DYHT_met_B->Add(h_ht800B_met);
    h_DYHT_met_B->Add(h_ht1200B_met);
    h_DYHT_met_B->Add(h_ht2500B_met);

    TH1F *h_DYHT_met_Ratio = (TH1F *)h_DYHT_met_A->Clone("h_DYHT_met_Ratio");
    h_DYHT_met_Ratio->Divide(h_DYHT_met_B);

    TH1F *h_DYHT_alphmin_Ratio = (TH1F *)h_ht0A_aphmin->Clone("h_DYHT_alphmin_Ratio");
    h_DYHT_alphmin_Ratio->Divide(h_ht0B_aphmin);

    h_ht0A_met = (TH1F *)gDirectory->Get("h_ht0A_met");
    h_ht0B_met = (TH1F *)gDirectory->Get("h_ht0B_met");

    TFile *outFile = new TFile("./../../ABCD_HT.root", "RECREATE");
    outFile->cd();

    h_ht0A_met->Write();
    h_ht0B_met->Write();
    h_ht70A_met->Write();
    h_ht70B_met->Write();
    h_ht100A_met->Write();
    h_ht100B_met->Write();
    h_ht200A_met->Write();
    h_ht200B_met->Write();
    h_ht400A_met->Write();
    h_ht400B_met->Write();
    h_ht600A_met->Write();
    h_ht600B_met->Write();
    h_ht800A_met->Write();
    h_ht800B_met->Write();
    h_ht1200A_met->Write();
    h_ht1200B_met->Write();
    h_ht2500A_met->Write();
    h_ht2500B_met->Write();
    h_DYHT_met_A->Write();
    h_DYHT_met_B->Write();
    h_DYHT_met_Ratio->Write();
    h_DYHT_alphamin_A->Write();
    h_DYHT_alphamin_B->Write();
    h_DYHT_alphmin_Ratio->Write();
    h_ht0A_aphmin->Write();
    h_ht0B_aphmin->Write();
    outFile->Close();
}