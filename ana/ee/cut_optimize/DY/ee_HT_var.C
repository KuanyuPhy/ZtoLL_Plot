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

//---------------------
// Define the HTWeight
//---------------------
double HT0Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT0CS) / (HT0_70_event)) * 1000;
double HT70Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT70CS) / (HT70_100_event)) * 1000;
double HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000;
double HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000;
double HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000;
double HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000;
double HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000;
double HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000;
double HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000;

void for_inclusive_sample(float HT, float i_tmp, double Weight, TH1D *h_tmp)
{
    if (HT < 70)
    {
        h_tmp->Fill(i_tmp, HT0Weight);
    }
    else if (HT >= 70 && HT < 100)
    {
        h_tmp->Fill(i_tmp, HT70Weight);
    }
    else if (HT >= 100 && HT < 200)
    {
        h_tmp->Fill(i_tmp, HT100Weight);
    }
    else if (HT >= 200 && HT < 400)
    {
        h_tmp->Fill(i_tmp, HT200Weight);
    }
    else if (HT >= 400 && HT < 600)
    {
        h_tmp->Fill(i_tmp, HT400Weight);
    }
    else if (HT >= 600 && HT < 800)
    {
        h_tmp->Fill(i_tmp, HT600Weight);
    }
    else if (HT >= 800 && HT < 1200)
    {
        h_tmp->Fill(i_tmp, HT800Weight);
    }
    else if (HT >= 1200 && HT < 2500)
    {
        h_tmp->Fill(i_tmp, HT1200Weight);
    }
    else if (HT >= 2500)
    {
        h_tmp->Fill(i_tmp, HT2500Weight);
    }
}
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
void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

void ee_HT_var()
{
    TH1D *h_DY_Met = new TH1D("h_DY_Met", "", 50, 0, 500);
    h_DY_Met->Sumw2();

    TH1D *h_DY_Met_cut = new TH1D("h_DY_Met_cut", "", 50, 0, 500);
    h_DY_Met_cut->Sumw2();

    TH1D *h_DY_jetCSV = new TH1D("h_DY_jetCSV", "", 50, 0, 1);
    h_DY_jetCSV->Sumw2();

    TH1D *h_DY_bjetCSV = new TH1D("h_DY_bjetCSV", "", 50, 0, 1);
    h_DY_bjetCSV->Sumw2();

    TH1D *h_DY_cjetCSV = new TH1D("h_DY_cjetCSV", "", 50, 0, 1);
    h_DY_cjetCSV->Sumw2();

    TH1D *h_DY_ljetCSV = new TH1D("h_DY_ljetCSV", "", 50, 0, 1);
    h_DY_ljetCSV->Sumw2();

    float_t HT;

    float_t f_ht0_Met, f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;

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

    vector<float> *v_ht0_jetcsv = new vector<float>();
    vector<float> *v_ht70_jetcsv = new vector<float>();
    vector<float> *v_ht100_jetcsv = new vector<float>();
    vector<float> *v_ht200_jetcsv = new vector<float>();
    vector<float> *v_ht400_jetcsv = new vector<float>();
    vector<float> *v_ht600_jetcsv = new vector<float>();
    vector<float> *v_ht800_jetcsv = new vector<float>();
    vector<float> *v_ht1200_jetcsv = new vector<float>();
    vector<float> *v_ht2500_jetcsv = new vector<float>();

    v_ht0_jetcsv->clear();
    v_ht70_jetcsv->clear();
    v_ht100_jetcsv->clear();
    v_ht200_jetcsv->clear();
    v_ht400_jetcsv->clear();
    v_ht600_jetcsv->clear();
    v_ht800_jetcsv->clear();
    v_ht1200_jetcsv->clear();
    v_ht2500_jetcsv->clear();

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

    TTree *T_inclusive;
    DYincli->GetObject("T_tree", T_inclusive);
    T_inclusive->SetBranchAddress("I_weight", &I_ht0_weight);
    T_inclusive->SetBranchAddress("f_HT", &HT);
    T_inclusive->SetBranchAddress("f_Met", &f_ht0_Met);
    T_inclusive->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    T_inclusive->SetBranchAddress("f_thinjetCSV", &v_ht0_jetcsv);
    T_inclusive->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
    for (int evt = 0; evt < T_inclusive->GetEntries(); evt++)
    {
        T_inclusive->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_ht0_alpha->size(); i++)
        {
            if ((*v_ht0_alpha)[i] > 0.15)
            {
                alpha_cut = false;
                break;
            }
        }
        if (!alpha_cut)
        {
            continue;
        }
        for_inclusive_sample(HT, f_ht0_Met, I_ht0_weight, h_DY_Met);
        if (f_ht0_Met < 120)
        {
            continue;
        }
        for_inclusive_sample(HT, f_ht0_Met, I_ht0_weight, h_DY_Met_cut);
        for (size_t i = 0; i < v_ht0_jetcsv->size(); i++)
        {
            // b jet
            for_inclusive_DY_sigle_flavor_jetvar(HT, 5, (*v_ht0_Jethadronflavor)[i], (*v_ht0_jetcsv)[i], I_ht0_weight, h_DY_bjetCSV);
            // c jet
            for_inclusive_DY_sigle_flavor_jetvar(HT, 4, (*v_ht0_Jethadronflavor)[i], (*v_ht0_jetcsv)[i], I_ht0_weight, h_DY_cjetCSV);
            // L jet
            for_inclusive_DY_sigle_flavor_jetvar(HT, 0, (*v_ht0_Jethadronflavor)[i], (*v_ht0_jetcsv)[i], I_ht0_weight, h_DY_ljetCSV);
        }
    }
    TTree *T_HT100;
    DYHT100->GetObject("T_tree", T_HT100);
    T_HT100->SetBranchAddress("I_weight", &I_ht100_weight);
    T_HT100->SetBranchAddress("f_Met", &f_ht100_Met);
    T_HT100->SetBranchAddress("v_fakealpha", &v_ht100_alpha);
    T_HT100->SetBranchAddress("f_thinjetCSV", &v_ht100_jetcsv);
    T_HT100->SetBranchAddress("v_fakeJethadronflavor", &v_ht100_Jethadronflavor);
    for (int evt = 0; evt < T_HT100->GetEntries(); evt++)
    {
        T_HT100->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_ht100_alpha->size(); i++)
        {
            if ((*v_ht100_alpha)[i] > 0.15)
            {
                alpha_cut = false;
                break;
            }
        }
        if (!alpha_cut)
        {
            continue;
        }
        h_DY_Met->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
        if (f_ht100_Met < 120)
        {
            continue;
        }
        h_DY_Met_cut->Fill(f_ht100_Met, I_ht100_weight * HT100Weight);
        for (size_t i = 0; i < v_ht100_jetcsv->size(); i++)
        {
            // b jet
            for_signalflavor_jet(5, (*v_ht100_Jethadronflavor)[i], (*v_ht100_jetcsv)[i], I_ht100_weight * HT100Weight, h_DY_bjetCSV);
            // c jet
            for_signalflavor_jet(4, (*v_ht100_Jethadronflavor)[i], (*v_ht100_jetcsv)[i], I_ht100_weight * HT100Weight, h_DY_cjetCSV);
            // L jet
            for_signalflavor_jet(0, (*v_ht100_Jethadronflavor)[i], (*v_ht100_jetcsv)[i], I_ht100_weight * HT100Weight, h_DY_ljetCSV);
        }
    }
    TTree *T_HT200;
    DYHT200->GetObject("T_tree", T_HT200);
    T_HT200->SetBranchAddress("I_weight", &I_ht200_weight);
    T_HT200->SetBranchAddress("f_Met", &f_ht200_Met);
    T_HT200->SetBranchAddress("v_fakealpha", &v_ht200_alpha);
    T_HT200->SetBranchAddress("f_thinjetCSV", &v_ht200_jetcsv);
    T_HT200->SetBranchAddress("v_fakeJethadronflavor", &v_ht200_Jethadronflavor);
    for (int evt = 0; evt < T_HT200->GetEntries(); evt++)
    {
        T_HT200->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_ht200_alpha->size(); i++)
        {
            if ((*v_ht200_alpha)[i] > 0.15)
            {
                alpha_cut = false;
                break;
            }
        }
        if (!alpha_cut)
        {
            continue;
        }
        h_DY_Met->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
        if (f_ht200_Met < 120)
        {
            continue;
        }
        h_DY_Met_cut->Fill(f_ht200_Met, I_ht200_weight * HT200Weight);
        for (size_t i = 0; i < v_ht200_jetcsv->size(); i++)
        {
            // b jet
            for_signalflavor_jet(5, (*v_ht200_Jethadronflavor)[i], (*v_ht200_jetcsv)[i], I_ht200_weight * HT200Weight, h_DY_bjetCSV);
            // c jet
            for_signalflavor_jet(4, (*v_ht200_Jethadronflavor)[i], (*v_ht200_jetcsv)[i], I_ht200_weight * HT200Weight, h_DY_cjetCSV);
            // L jet
            for_signalflavor_jet(0, (*v_ht200_Jethadronflavor)[i], (*v_ht200_jetcsv)[i], I_ht200_weight * HT200Weight, h_DY_ljetCSV);
        }
    }
    TTree *T_HT400;
    DYHT400->GetObject("T_tree", T_HT400);
    T_HT400->SetBranchAddress("I_weight", &I_ht400_weight);
    T_HT400->SetBranchAddress("f_Met", &f_ht400_Met);
    T_HT400->SetBranchAddress("v_fakealpha", &v_ht400_alpha);
    T_HT400->SetBranchAddress("f_thinjetCSV", &v_ht400_jetcsv);
    T_HT400->SetBranchAddress("v_fakeJethadronflavor", &v_ht400_Jethadronflavor);
    for (int evt = 0; evt < T_HT400->GetEntries(); evt++)
    {
        T_HT400->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_ht400_alpha->size(); i++)
        {
            if ((*v_ht400_alpha)[i] > 0.15)
            {
                alpha_cut = false;
                break;
            }
        }
        if (!alpha_cut)
        {
            continue;
        }
        h_DY_Met->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
        if (f_ht400_Met < 120)
        {
            continue;
        }
        h_DY_Met_cut->Fill(f_ht400_Met, I_ht400_weight * HT400Weight);
        for (size_t i = 0; i < v_ht400_jetcsv->size(); i++)
        {
            // b jet
            for_signalflavor_jet(5, (*v_ht400_Jethadronflavor)[i], (*v_ht400_jetcsv)[i], I_ht400_weight * HT400Weight, h_DY_bjetCSV);
            // c jet
            for_signalflavor_jet(4, (*v_ht400_Jethadronflavor)[i], (*v_ht400_jetcsv)[i], I_ht400_weight * HT400Weight, h_DY_cjetCSV);
            // L jet
            for_signalflavor_jet(0, (*v_ht400_Jethadronflavor)[i], (*v_ht400_jetcsv)[i], I_ht400_weight * HT400Weight, h_DY_ljetCSV);
        }
    }
    TTree *T_HT600;
    DYHT600->GetObject("T_tree", T_HT600);
    T_HT600->SetBranchAddress("I_weight", &I_ht600_weight);
    T_HT600->SetBranchAddress("f_Met", &f_ht600_Met);
    T_HT600->SetBranchAddress("v_fakealpha", &v_ht600_alpha);
    T_HT600->SetBranchAddress("f_thinjetCSV", &v_ht600_jetcsv);
    T_HT600->SetBranchAddress("v_fakeJethadronflavor", &v_ht600_Jethadronflavor);
    for (int evt = 0; evt < T_HT600->GetEntries(); evt++)
    {
        T_HT600->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_ht600_alpha->size(); i++)
        {
            if ((*v_ht600_alpha)[i] > 0.15)
            {
                alpha_cut = false;
                break;
            }
        }
        if (!alpha_cut)
        {
            continue;
        }
        h_DY_Met->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
        if (f_ht600_Met < 120)
        {
            continue;
        }
        h_DY_Met_cut->Fill(f_ht600_Met, I_ht600_weight * HT600Weight);
        for (size_t i = 0; i < v_ht600_jetcsv->size(); i++)
        {
            // b jet
            for_signalflavor_jet(5, (*v_ht600_Jethadronflavor)[i], (*v_ht600_jetcsv)[i], I_ht600_weight * HT600Weight, h_DY_bjetCSV);
            // c jet
            for_signalflavor_jet(4, (*v_ht600_Jethadronflavor)[i], (*v_ht600_jetcsv)[i], I_ht600_weight * HT600Weight, h_DY_cjetCSV);
            // L jet
            for_signalflavor_jet(0, (*v_ht600_Jethadronflavor)[i], (*v_ht600_jetcsv)[i], I_ht600_weight * HT600Weight, h_DY_ljetCSV);
        }
    }
    TTree *T_HT800;
    DYHT800->GetObject("T_tree", T_HT800);
    T_HT800->SetBranchAddress("I_weight", &I_ht800_weight);
    T_HT800->SetBranchAddress("f_Met", &f_ht800_Met);
    T_HT800->SetBranchAddress("v_fakealpha", &v_ht800_alpha);
    T_HT800->SetBranchAddress("f_thinjetCSV", &v_ht800_jetcsv);
    T_HT800->SetBranchAddress("v_fakeJethadronflavor", &v_ht800_Jethadronflavor);
    for (int evt = 0; evt < T_HT800->GetEntries(); evt++)
    {
        T_HT800->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_ht800_alpha->size(); i++)
        {
            if ((*v_ht800_alpha)[i] > 0.15)
            {
                alpha_cut = false;
                break;
            }
        }
        if (!alpha_cut)
        {
            continue;
        }
        h_DY_Met->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
        if (f_ht800_Met < 120)
        {
            continue;
        }
        h_DY_Met_cut->Fill(f_ht800_Met, I_ht800_weight * HT800Weight);
        for (size_t i = 0; i < v_ht800_jetcsv->size(); i++)
        {
            // b jet
            for_signalflavor_jet(5, (*v_ht800_Jethadronflavor)[i], (*v_ht800_jetcsv)[i], I_ht800_weight * HT800Weight, h_DY_bjetCSV);
            // c jet
            for_signalflavor_jet(4, (*v_ht800_Jethadronflavor)[i], (*v_ht800_jetcsv)[i], I_ht800_weight * HT800Weight, h_DY_cjetCSV);
            // L jet
            for_signalflavor_jet(0, (*v_ht800_Jethadronflavor)[i], (*v_ht800_jetcsv)[i], I_ht800_weight * HT800Weight, h_DY_ljetCSV);
        }
    }
    TTree *T_HT1200;
    DYHT1200->GetObject("T_tree", T_HT1200);
    T_HT1200->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_HT1200->SetBranchAddress("f_Met", &f_ht1200_Met);
    T_HT1200->SetBranchAddress("v_fakealpha", &v_ht1200_alpha);
    T_HT1200->SetBranchAddress("f_thinjetCSV", &v_ht1200_jetcsv);
    T_HT1200->SetBranchAddress("v_fakeJethadronflavor", &v_ht1200_Jethadronflavor);
    for (int evt = 0; evt < T_HT1200->GetEntries(); evt++)
    {
        T_HT1200->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_ht1200_alpha->size(); i++)
        {
            if ((*v_ht1200_alpha)[i] > 0.15)
            {
                alpha_cut = false;
                break;
            }
        }
        if (!alpha_cut)
        {
            continue;
        }
        h_DY_Met->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
        if (f_ht1200_Met < 120)
        {
            continue;
        }
        h_DY_Met_cut->Fill(f_ht1200_Met, I_ht1200_weight * HT1200Weight);
        for (size_t i = 0; i < v_ht1200_jetcsv->size(); i++)
        {
            // b jet
            for_signalflavor_jet(5, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_jetcsv)[i], I_ht1200_weight * HT1200Weight, h_DY_bjetCSV);
            // c jet
            for_signalflavor_jet(4, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_jetcsv)[i], I_ht1200_weight * HT1200Weight, h_DY_cjetCSV);
            // L jet
            for_signalflavor_jet(0, (*v_ht1200_Jethadronflavor)[i], (*v_ht1200_jetcsv)[i], I_ht1200_weight * HT1200Weight, h_DY_ljetCSV);
        }
    }
    TTree *T_HT2500;
    DYHT2500->GetObject("T_tree", T_HT2500);
    T_HT2500->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_HT2500->SetBranchAddress("f_Met", &f_ht2500_Met);
    T_HT2500->SetBranchAddress("v_fakealpha", &v_ht2500_alpha);
    T_HT2500->SetBranchAddress("f_thinjetCSV", &v_ht2500_jetcsv);
    T_HT2500->SetBranchAddress("v_fakeJethadronflavor", &v_ht2500_Jethadronflavor);
    for (int evt = 0; evt < T_HT2500->GetEntries(); evt++)
    {
        T_HT2500->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_ht2500_alpha->size(); i++)
        {
            if ((*v_ht2500_alpha)[i] > 0.15)
            {
                alpha_cut = false;
                break;
            }
        }
        if (!alpha_cut)
        {
            continue;
        }
        h_DY_Met->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
        if (f_ht2500_Met < 120)
        {
            continue;
        }
        h_DY_Met_cut->Fill(f_ht2500_Met, I_ht2500_weight * HT2500Weight);
        for (size_t i = 0; i < v_ht2500_jetcsv->size(); i++)
        {
            // b jet
            for_signalflavor_jet(5, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_jetcsv)[i], I_ht2500_weight * HT2500Weight, h_DY_bjetCSV);
            // c jet
            for_signalflavor_jet(4, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_jetcsv)[i], I_ht2500_weight * HT2500Weight, h_DY_cjetCSV);
            // L jet
            for_signalflavor_jet(0, (*v_ht2500_Jethadronflavor)[i], (*v_ht2500_jetcsv)[i], I_ht2500_weight * HT2500Weight, h_DY_ljetCSV);
        }
    }
    h_DY_jetCSV->Draw();
    TString outputfile1 = "./ee_DY_Met.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_DY_Met_cut->Write();
    h_DY_Met->Write();
    h_DY_bjetCSV->Write();
    h_DY_cjetCSV->Write();
    h_DY_ljetCSV->Write();
    outfile_HT0->Close();
}