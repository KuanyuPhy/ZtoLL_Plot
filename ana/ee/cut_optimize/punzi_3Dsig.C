#include <TFile.h>
#include <iostream>
#include <TTree.h>
#include <TMath.h>
#include <TString.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH2F.h>
#include <TGraph.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "./../../lib/Cross_section.h"
using namespace std;

// define punzi_eq
double punzi(double sigeff, double bg)
{
    return sigeff / (1 + TMath::Power(abs(bg), 0.5));
}

void punzi_3Dsig(TString inputfile = "DY_emjet.root", TString outputfile1 = "./pun.root")
{
    TFile *DYHT = TFile::Open(inputfile);
    TFile *Diboson_file = TFile::Open("./ee_Diboson_emjet.root");
    TFile *Triboson_file = TFile::Open("./ee_Triboson_emjet.root");
    TFile *Top_file = TFile::Open("./ee_Top_emjet.root");
    TFile *Sig1 = new TFile("Sig1.root");
    TFile *Sig50 = new TFile("Sig50.root");
    TFile *Sig150 = new TFile("Sig150.root");

    TH1F *h_DYHT_1[24];
    TH1F *h_DYHT_2[24];
    TH1F *h_DYHT_3[24];
    TH1F *h_DYHT_4[24];

    TH1F *h_Diboson_1[24];
    TH1F *h_Diboson_2[24];
    TH1F *h_Diboson_3[24];
    TH1F *h_Diboson_4[24];

    TH1F *h_Top_1[24];
    TH1F *h_Top_2[24];
    TH1F *h_Top_3[24];
    TH1F *h_Top_4[24];

    TH1F *h_Triboson_1[24];
    TH1F *h_Triboson_2[24];
    TH1F *h_Triboson_3[24];
    TH1F *h_Triboson_4[24];

    TH1F *h_Sig1_1[24];
    TH1F *h_Sig1_2[24];
    TH1F *h_Sig1_3[24];
    TH1F *h_Sig1_4[24];
    TH1F *h_Sig50_1[24];
    TH1F *h_Sig50_2[24];
    TH1F *h_Sig50_3[24];
    TH1F *h_Sig50_4[24];
    TH1F *h_Sig150_1[24];
    TH1F *h_Sig150_2[24];
    TH1F *h_Sig150_3[24];
    TH1F *h_Sig150_4[24];

    // 2016Total BG
    TH1F *h_TotalBG_1[24];
    TH1F *h_TotalBG_2[24];
    TH1F *h_TotalBG_3[24];
    TH1F *h_TotalBG_4[24];
    for (int i = 0; i < 24; i++)
    {
        h_DYHT_1[i] = ((TH1F *)DYHT->Get(Form("h_ht0_NemJet_%d", i)));
        h_DYHT_2[i] = ((TH1F *)DYHT->Get(Form("h_ht0_NemJet2_%d", i)));
        h_DYHT_3[i] = ((TH1F *)DYHT->Get(Form("h_ht0_NemJet3_%d", i)));
        h_DYHT_4[i] = ((TH1F *)DYHT->Get(Form("h_ht0_NemJet4_%d", i)));

        h_Top_1[i] = ((TH1F *)Top_file->Get(Form("h_Top_NemJet_%d", i + 1)));
        h_Top_2[i] = ((TH1F *)Top_file->Get(Form("h_Top_NemJet2_%d", i + 1)));
        h_Top_3[i] = ((TH1F *)Top_file->Get(Form("h_Top_NemJet3_%d", i + 1)));
        h_Top_4[i] = ((TH1F *)Top_file->Get(Form("h_Top_NemJet4_%d", i + 1)));

        h_Diboson_1[i] = ((TH1F *)Diboson_file->Get(Form("h_diboson_NemJet_%d", i + 1)));
        h_Diboson_2[i] = ((TH1F *)Diboson_file->Get(Form("h_diboson_NemJet2_%d", i + 1)));
        h_Diboson_3[i] = ((TH1F *)Diboson_file->Get(Form("h_diboson_NemJet3_%d", i + 1)));
        h_Diboson_4[i] = ((TH1F *)Diboson_file->Get(Form("h_diboson_NemJet4_%d", i + 1)));

        h_Triboson_1[i] = ((TH1F *)Triboson_file->Get(Form("h_triboson_NemJet_%d", i + 1)));
        h_Triboson_2[i] = ((TH1F *)Triboson_file->Get(Form("h_triboson_NemJet2_%d", i + 1)));
        h_Triboson_3[i] = ((TH1F *)Triboson_file->Get(Form("h_triboson_NemJet3_%d", i + 1)));
        h_Triboson_4[i] = ((TH1F *)Triboson_file->Get(Form("h_triboson_NemJet4_%d", i + 1)));

        h_TotalBG_1[i] = new TH1F(Form("h_TotalBG_1_%d", i + 1), "", 10, 0, 10);
        h_TotalBG_2[i] = new TH1F(Form("h_TotalBG_2_%d", i + 1), "", 10, 0, 10);
        h_TotalBG_3[i] = new TH1F(Form("h_TotalBG_3_%d", i + 1), "", 10, 0, 10);
        h_TotalBG_4[i] = new TH1F(Form("h_TotalBG_4_%d", i + 1), "", 10, 0, 10);

        h_TotalBG_1[i]->Add(h_DYHT_1[i]);
        h_TotalBG_1[i]->Add(h_Top_1[i]);
        h_TotalBG_1[i]->Add(h_Diboson_1[i]);
        h_TotalBG_1[i]->Add(h_Triboson_1[i]);

        h_TotalBG_2[i]->Add(h_DYHT_2[i]);
        h_TotalBG_2[i]->Add(h_Top_2[i]);
        h_TotalBG_2[i]->Add(h_Diboson_2[i]);
        h_TotalBG_2[i]->Add(h_Triboson_2[i]);

        h_TotalBG_3[i]->Add(h_DYHT_3[i]);
        h_TotalBG_3[i]->Add(h_Top_3[i]);
        h_TotalBG_3[i]->Add(h_Diboson_3[i]);
        h_TotalBG_3[i]->Add(h_Triboson_3[i]);

        h_TotalBG_4[i]->Add(h_DYHT_4[i]);
        h_TotalBG_4[i]->Add(h_Top_4[i]);
        h_TotalBG_4[i]->Add(h_Diboson_4[i]);
        h_TotalBG_4[i]->Add(h_Triboson_4[i]);

        h_Sig1_1[i] = ((TH1F *)Sig1->Get(Form("h_ht0_NemJet_%d", i)));
        h_Sig1_2[i] = ((TH1F *)Sig1->Get(Form("h_ht0_NemJet2_%d", i)));
        h_Sig1_3[i] = ((TH1F *)Sig1->Get(Form("h_ht0_NemJet3_%d", i)));
        h_Sig1_4[i] = ((TH1F *)Sig1->Get(Form("h_ht0_NemJet4_%d", i)));
        h_Sig50_1[i] = ((TH1F *)Sig50->Get(Form("h_ht0_NemJet_%d", i)));
        h_Sig50_2[i] = ((TH1F *)Sig50->Get(Form("h_ht0_NemJet2_%d", i)));
        h_Sig50_3[i] = ((TH1F *)Sig50->Get(Form("h_ht0_NemJet3_%d", i)));
        h_Sig50_4[i] = ((TH1F *)Sig50->Get(Form("h_ht0_NemJet4_%d", i)));
        h_Sig150_1[i] = ((TH1F *)Sig150->Get(Form("h_ht0_NemJet_%d", i)));
        h_Sig150_2[i] = ((TH1F *)Sig150->Get(Form("h_ht0_NemJet2_%d", i)));
        h_Sig150_3[i] = ((TH1F *)Sig150->Get(Form("h_ht0_NemJet3_%d", i)));
        h_Sig150_4[i] = ((TH1F *)Sig150->Get(Form("h_ht0_NemJet4_%d", i)));
        // cout << "Bug" <<endl;
    }

    float DYHT_totevt_1[24];
    float DYHT_totevt_2[24];
    float DYHT_totevt_3[24];
    float DYHT_totevt_4[24];

    float TotalBG_totevt_1[24];
    float TotalBG_totevt_2[24];
    float TotalBG_totevt_3[24];
    float TotalBG_totevt_4[24];

    float Sig1_totevt_1[24];
    float Sig1_totevt_2[24];
    float Sig1_totevt_3[24];
    float Sig1_totevt_4[24];
    float Sig50_totevt_1[24];
    float Sig50_totevt_2[24];
    float Sig50_totevt_3[24];
    float Sig50_totevt_4[24];
    float Sig150_totevt_1[24];
    float Sig150_totevt_2[24];
    float Sig150_totevt_3[24];
    float Sig150_totevt_4[24];
    for (int i = 0; i < 24; i++)
    {
        DYHT_totevt_1[i] = h_DYHT_1[i]->Integral();
        DYHT_totevt_2[i] = h_DYHT_2[i]->Integral();
        DYHT_totevt_3[i] = h_DYHT_3[i]->Integral();
        DYHT_totevt_4[i] = h_DYHT_4[i]->Integral();

        TotalBG_totevt_1[i] = h_TotalBG_1[i]->Integral();
        TotalBG_totevt_2[i] = h_TotalBG_2[i]->Integral();
        TotalBG_totevt_3[i] = h_TotalBG_3[i]->Integral();
        TotalBG_totevt_4[i] = h_TotalBG_4[i]->Integral();

        Sig1_totevt_1[i] = h_Sig1_1[i]->Integral();
        Sig1_totevt_2[i] = h_Sig1_2[i]->Integral();
        Sig1_totevt_3[i] = h_Sig1_3[i]->Integral();
        Sig1_totevt_4[i] = h_Sig1_4[i]->Integral();
        Sig50_totevt_1[i] = h_Sig50_1[i]->Integral();
        Sig50_totevt_2[i] = h_Sig50_2[i]->Integral();
        Sig50_totevt_3[i] = h_Sig50_3[i]->Integral();
        Sig50_totevt_4[i] = h_Sig50_4[i]->Integral();
        Sig150_totevt_1[i] = h_Sig150_1[i]->Integral();
        Sig150_totevt_2[i] = h_Sig150_2[i]->Integral();
        Sig150_totevt_3[i] = h_Sig150_3[i]->Integral();
        Sig150_totevt_4[i] = h_Sig150_4[i]->Integral();
    }
    float nSig1Event_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nSig1Event_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nSig1Event_3[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nSig1Event_4[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nSig50Event_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nSig50Event_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nSig50Event_3[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nSig50Event_4[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nSig150Event_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nSig150Event_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nSig150Event_3[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nSig150Event_4[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nBgEvent_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nBgEvent_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nBgEvent_3[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float nBgEvent_4[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig1_nEmjet_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig1_nEmjet_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig1_nEmjet_3[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig1_nEmjet_4[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig50_nEmjet_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig50_nEmjet_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig50_nEmjet_3[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig50_nEmjet_4[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig150_nEmjet_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig150_nEmjet_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig150_nEmjet_3[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float punzisig150_nEmjet_4[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //--------------
    // ROC
    //--------------
    float Teffs_Mx1_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffs_Mx1_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffs_Mx1_3[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffs_Mx1_4[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffs_Mx50_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffs_Mx50_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffs_Mx50_3[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffs_Mx50_4[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffs_Mx150_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffs_Mx150_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffs_Mx150_3[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffs_Mx150_4[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffb_1[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffb_2[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffb_3[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float Teffb_4[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 24; i++)
    {
        for (int j = 2; j < 9; j++)
        {
            nSig1Event_1[i] += h_Sig1_1[i]->GetBinContent(j + 1);
            nSig1Event_2[i] += h_Sig1_2[i]->GetBinContent(j + 1);
            nSig1Event_3[i] += h_Sig1_3[i]->GetBinContent(j + 1);
            nSig1Event_4[i] += h_Sig1_4[i]->GetBinContent(j + 1);
            nSig50Event_1[i] += h_Sig50_1[i]->GetBinContent(j + 1);
            nSig50Event_2[i] += h_Sig50_2[i]->GetBinContent(j + 1);
            nSig50Event_3[i] += h_Sig50_3[i]->GetBinContent(j + 1);
            nSig50Event_4[i] += h_Sig50_4[i]->GetBinContent(j + 1);
            nSig150Event_1[i] += h_Sig150_1[i]->GetBinContent(j + 1);
            nSig150Event_2[i] += h_Sig150_2[i]->GetBinContent(j + 1);
            nSig150Event_3[i] += h_Sig150_3[i]->GetBinContent(j + 1);
            nSig150Event_4[i] += h_Sig150_4[i]->GetBinContent(j + 1);
            nBgEvent_1[i] += h_TotalBG_1[i]->GetBinContent(j + 1);
            nBgEvent_2[i] += h_TotalBG_2[i]->GetBinContent(j + 1);
            nBgEvent_3[i] += h_TotalBG_3[i]->GetBinContent(j + 1);
            nBgEvent_4[i] += h_TotalBG_4[i]->GetBinContent(j + 1);
        }
        //cout << "eff = " << nSig1Event_2[i] / Sig1_totevt_2[i] << endl;
         cout << "i = " << i << " puzi =" << punzi(nSig1Event_2[i] / Sig1_totevt_2[i], nBgEvent_2[i]) << endl;
        punzisig1_nEmjet_1[i] = punzi(nSig1Event_1[i] / Sig1_totevt_1[i], nBgEvent_1[i]);
        punzisig1_nEmjet_2[i] = punzi(nSig1Event_2[i] / Sig1_totevt_2[i], nBgEvent_2[i]);
        punzisig1_nEmjet_3[i] = punzi(nSig1Event_3[i] / Sig1_totevt_3[i], nBgEvent_3[i]);
        punzisig1_nEmjet_4[i] = punzi(nSig1Event_4[i] / Sig1_totevt_4[i], nBgEvent_4[i]);
        punzisig50_nEmjet_1[i] = punzi(nSig50Event_1[i] / Sig50_totevt_1[i], nBgEvent_1[i]);
        punzisig50_nEmjet_2[i] = punzi(nSig50Event_2[i] / Sig50_totevt_2[i], nBgEvent_2[i]);
        punzisig50_nEmjet_3[i] = punzi(nSig50Event_3[i] / Sig50_totevt_3[i], nBgEvent_3[i]);
        punzisig50_nEmjet_4[i] = punzi(nSig50Event_4[i] / Sig50_totevt_4[i], nBgEvent_4[i]);
        punzisig150_nEmjet_1[i] = punzi(nSig150Event_1[i] / Sig150_totevt_1[i], nBgEvent_1[i]);
        punzisig150_nEmjet_2[i] = punzi(nSig150Event_2[i] / Sig150_totevt_2[i], nBgEvent_2[i]);
        punzisig150_nEmjet_3[i] = punzi(nSig150Event_3[i] / Sig150_totevt_3[i], nBgEvent_3[i]);
        punzisig150_nEmjet_4[i] = punzi(nSig150Event_4[i] / Sig150_totevt_4[i], nBgEvent_4[i]);
        Teffs_Mx1_1[i] = nSig1Event_1[i] / Sig1_totevt_1[i];
        Teffs_Mx1_2[i] = nSig1Event_2[i] / Sig1_totevt_2[i];
        Teffs_Mx1_3[i] = nSig1Event_3[i] / Sig1_totevt_3[i];
        Teffs_Mx1_4[i] = nSig1Event_4[i] / Sig1_totevt_4[i];
        Teffs_Mx50_1[i] = nSig50Event_1[i] / Sig50_totevt_1[i];
        // cout << "i = " << i << "effs50 = " << nSig50Event_1[i] / Sig50_totevt_1[i] << endl;
        Teffs_Mx50_2[i] = nSig50Event_2[i] / Sig50_totevt_2[i];
        Teffs_Mx50_3[i] = nSig50Event_3[i] / Sig50_totevt_3[i];
        Teffs_Mx50_4[i] = nSig50Event_4[i] / Sig50_totevt_4[i];
        Teffs_Mx150_1[i] = nSig150Event_1[i] / Sig150_totevt_1[i];
        Teffs_Mx150_2[i] = nSig150Event_2[i] / Sig150_totevt_2[i];
        Teffs_Mx150_3[i] = nSig150Event_3[i] / Sig150_totevt_3[i];
        Teffs_Mx150_4[i] = nSig150Event_4[i] / Sig150_totevt_4[i];
        Teffb_1[i] = 1 - (nBgEvent_1[i] / TotalBG_totevt_1[i]);
        Teffb_2[i] = 1 - (nBgEvent_2[i] / TotalBG_totevt_2[i]);
        Teffb_3[i] = 1 - (nBgEvent_3[i] / TotalBG_totevt_3[i]);
        Teffb_4[i] = 1 - (nBgEvent_4[i] / TotalBG_totevt_4[i]);
    }
    cout << " 1 = " << TotalBG_totevt_1[0] << endl;
    cout << " 2 = " << DYHT_totevt_1[0] << endl;
    for (int i = 0; i < 24; i++)
    {
        h_DYHT_1[i]->SetLineWidth(2);
        h_Sig1_1[i]->SetLineWidth(2);
        h_Sig50_1[i]->SetLineWidth(2);
        h_Sig150_1[i]->SetLineWidth(2);

        h_DYHT_1[i]->SetLineColor(kMagenta + 3);
        h_Sig1_1[i]->SetLineColor(kRed);
        h_Sig50_1[i]->SetLineColor(kBlue);
        h_Sig150_1[i]->SetLineColor(kGreen - 6);

        h_DYHT_1[i]->SetTitle(Form("emcut%d", i));
        h_Sig1_1[i]->SetTitle(Form("emcut%d", i));
        h_Sig50_1[i]->SetTitle(Form("emcut%d", i));
        h_Sig150_1[i]->SetTitle(Form("emcut%d", i));
    }

    auto c1 = new TCanvas("c1", "BPRE");

    c1->Divide(2, 1);

    // h_DYHT_1[0]->DrawNormalized("hist same");
    // h_Sig1_1[0]->DrawNormalized("hist same");
    // h_Sig50_1[0]->DrawNormalized("hist same");
    // h_Sig150_1[0]->DrawNormalized("hist same");
    /*
        auto *t1 = new TLegend(0.60, 0.55, 0.80, 0.80);
        t1->SetBorderSize(0);
        t1->SetTextSize(0.03);
        t1->AddEntry(h_DYHT[0],"DY process","l");
        t1->AddEntry(h_Sig1[0],"ctau=1mm m_{x^{2}}=1", "l");
        t1->AddEntry(h_Sig50[0],"ctau=1mm m_{x^{2}}=50", "l");
        t1->AddEntry(h_Sig150[0],"ctau=1mm m_{x^{2}}=150", "l");
        t1->Draw();

        c1->cd(2);
        h_Sig50[1]->DrawNormalized("hist");
        h_DYHT[1]->DrawNormalized("hist same");
        h_Sig1[1]->DrawNormalized("hist same");
        h_Sig150[1]->DrawNormalized("hist same");
        h_Sig50[1]->DrawNormalized("hist same");
        c1->cd(3);
        h_Sig1[2]->DrawNormalized("hist");
        h_DYHT[2]->DrawNormalized("hist same");
        //h_Sig1[2]->DrawNormalized("hist same");
        h_Sig50[2]->DrawNormalized("hist same");
        h_Sig150[2]->DrawNormalized("hist same");
        c1->cd(4);
        h_DYHT[3]->DrawNormalized("hist");
        h_Sig1[3]->DrawNormalized("hist same");
        h_Sig50[3]->DrawNormalized("hist same");
        h_Sig150[3]->DrawNormalized("hist same");
        c1->cd(5);
        h_DYHT[4]->DrawNormalized("hist");
        h_Sig1[4]->DrawNormalized("hist same");
        h_Sig50[4]->DrawNormalized("hist same");
        h_Sig150[4]->DrawNormalized("hist same");
        */
    // gStyle->SetOptStat(0);
    
    TH1F *h_punzisig1_nEmjet_1 = new TH1F("h_punzisig1_nEmjet_1", "", 24, 0, 24);
    TH1F *h_punzisig1_nEmjet_2 = new TH1F("h_punzisig1_nEmjet_2", "", 24, 0, 24);
    TH1F *h_punzisig1_nEmjet_3 = new TH1F("h_punzisig1_nEmjet_3", "", 24, 0, 24);
    TH1F *h_punzisig1_nEmjet_4 = new TH1F("h_punzisig1_nEmjet_4", "", 24, 0, 24);
    TH1F *h_punzisig50_nEmjet_1 = new TH1F("h_punzisig50_nEmjet_1", "", 24, 0, 24);
    TH1F *h_punzisig50_nEmjet_2 = new TH1F("h_punzisig50_nEmjet_2", "", 24, 0, 24);
    TH1F *h_punzisig50_nEmjet_3 = new TH1F("h_punzisig50_nEmjet_3", "", 24, 0, 24);
    TH1F *h_punzisig50_nEmjet_4 = new TH1F("h_punzisig50_nEmjet_4", "", 24, 0, 24);
    TH1F *h_punzisig150_nEmjet_1 = new TH1F("h_punzisig150_nEmjet_1", "", 24, 0, 24);
    TH1F *h_punzisig150_nEmjet_2 = new TH1F("h_punzisig150_nEmjet_2", "", 24, 0, 24);
    TH1F *h_punzisig150_nEmjet_3 = new TH1F("h_punzisig150_nEmjet_3", "", 24, 0, 24);
    TH1F *h_punzisig150_nEmjet_4 = new TH1F("h_punzisig150_nEmjet_4", "", 24, 0, 24);
    for (int i = 0; i < 24; i++)
    {
        // cout << "punzi = " << punzisig1_nEmjet_1[i] << endl;
        h_punzisig1_nEmjet_1->SetBinContent(i + 1, punzisig1_nEmjet_1[i]);
        h_punzisig1_nEmjet_2->SetBinContent(i + 1, punzisig1_nEmjet_2[i]);
        h_punzisig1_nEmjet_3->SetBinContent(i + 1, punzisig1_nEmjet_3[i]);
        h_punzisig1_nEmjet_4->SetBinContent(i + 1, punzisig1_nEmjet_4[i]);
        h_punzisig50_nEmjet_1->SetBinContent(i + 1, punzisig50_nEmjet_1[i]);
        h_punzisig50_nEmjet_2->SetBinContent(i + 1, punzisig50_nEmjet_2[i]);
        h_punzisig50_nEmjet_3->SetBinContent(i + 1, punzisig50_nEmjet_3[i]);
        h_punzisig50_nEmjet_4->SetBinContent(i + 1, punzisig50_nEmjet_4[i]);
        h_punzisig150_nEmjet_1->SetBinContent(i + 1, punzisig150_nEmjet_1[i]);
        h_punzisig150_nEmjet_2->SetBinContent(i + 1, punzisig150_nEmjet_2[i]);
        h_punzisig150_nEmjet_3->SetBinContent(i + 1, punzisig150_nEmjet_3[i]);
        h_punzisig150_nEmjet_4->SetBinContent(i + 1, punzisig150_nEmjet_4[i]);
    }
    h_punzisig1_nEmjet_1->SetLineWidth(2);
    h_punzisig1_nEmjet_2->SetLineWidth(2);
    h_punzisig1_nEmjet_3->SetLineWidth(2);
    h_punzisig1_nEmjet_4->SetLineWidth(2);
    h_punzisig50_nEmjet_1->SetLineWidth(2);
    h_punzisig50_nEmjet_2->SetLineWidth(2);
    h_punzisig50_nEmjet_3->SetLineWidth(2);
    h_punzisig50_nEmjet_4->SetLineWidth(2);
    h_punzisig150_nEmjet_1->SetLineWidth(2);
    h_punzisig150_nEmjet_2->SetLineWidth(2);
    h_punzisig150_nEmjet_3->SetLineWidth(2);
    h_punzisig150_nEmjet_4->SetLineWidth(2);

    h_punzisig1_nEmjet_1->SetLineColor(kRed);
    h_punzisig1_nEmjet_2->SetLineColor(kRed);
    h_punzisig1_nEmjet_3->SetLineColor(kRed);
    h_punzisig1_nEmjet_4->SetLineColor(kRed);
    h_punzisig50_nEmjet_1->SetLineColor(kBlue);
    h_punzisig50_nEmjet_2->SetLineColor(kBlue);
    h_punzisig50_nEmjet_3->SetLineColor(kBlue);
    h_punzisig50_nEmjet_4->SetLineColor(kBlue);
    h_punzisig150_nEmjet_1->SetLineColor(kGreen - 6);
    h_punzisig150_nEmjet_2->SetLineColor(kGreen - 6);
    h_punzisig150_nEmjet_3->SetLineColor(kGreen - 6);
    h_punzisig150_nEmjet_4->SetLineColor(kGreen - 6);

    // h_punzisig150_nEmjet_1->GetXaxis()->SetBinLabel(1, "emcut0");
    // h_punzisig150_nEmjet_1->GetXaxis()->SetBinLabel(2, "emcut1");
    // h_punzisig150_nEmjet_1->GetXaxis()->SetBinLabel(3, "emcut2");
    // h_punzisig150_nEmjet_1->GetXaxis()->SetBinLabel(4, "emcut3");
    // h_punzisig150_nEmjet_1->GetXaxis()->SetBinLabel(5, "emcut4");
    //c1->cd(1);
    
    h_punzisig50_nEmjet_1->GetYaxis()->SetTitle("punzi significance");
    h_punzisig50_nEmjet_1->GetXaxis()->SetTitle("nSteps");
    h_punzisig50_nEmjet_1->SetTitle("cut1");
    h_punzisig1_nEmjet_1->SetTitle("cut1");
    h_punzisig50_nEmjet_1->Draw("");
    h_punzisig150_nEmjet_1->Draw("same");
    h_punzisig1_nEmjet_1->Draw("same");
    gStyle->SetOptStat(0);
    TLegend *l1 = new TLegend(0.60, 0.55, 0.70, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_punzisig1_nEmjet_1, "ctau=1mm m_{x^{2}}=1 GeV", "l");
    l1->AddEntry(h_punzisig50_nEmjet_1, "ctau=10mm m_{x^{2}}=50 GeV", "l");
    l1->AddEntry(h_punzisig150_nEmjet_1, "ctau=1mm m_{x^{2}}=150 GeV", "l");
    // l1->AddEntry(h_TTTo2L2Nu_Median_2DIPsig, "Top process", "l");
    l1->Draw();
    
    //c1->SaveAs("cut1_chi1_punzi.png");
    //c1->cd(2);
    //h_punzisig50_nEmjet_2->SetTitle("emcut2");
    //h_punzisig1_nEmjet_2->SetTitle("emcut2");
    //h_punzisig50_nEmjet_2->Draw("");
    //h_punzisig150_nEmjet_2->Draw("same");
    //h_punzisig1_nEmjet_2->Draw("same");
    
    //-------------------
    // ROC
    //-------------------
    /*
    TH2F *ROC_total = new TH2F("ROC_total", "", 24, 0, 1, 100, 0, 1);
    TH2F *ROC_total2 = new TH2F("ROC_total2", "", 24, 0, 1, 100, 0, 1);
    ROC_total->SetXTitle("Sig Efficiency");
    ROC_total->SetYTitle("Bkg rejection Efficiency");
    ROC_total->GetYaxis()->SetRangeUser(0.75, 1);
    ROC_total2->SetXTitle("Sig Efficiency");
    ROC_total2->SetYTitle("Bkg rejection Efficiency");
    ROC_total2->GetYaxis()->SetRangeUser(0.75, 1);
    TGraph *ROC_Mx1_1 = new TGraph(24, Teffs_Mx1_1, Teffb_1);
    TGraph *ROC_Mx50_1 = new TGraph(24, Teffs_Mx50_1, Teffb_1);
    TGraph *ROC_Mx150_1 = new TGraph(24, Teffs_Mx150_1, Teffb_1);
    TGraph *ROC_Mx1_2 = new TGraph(24, Teffs_Mx1_2, Teffb_2);
    TGraph *ROC_Mx50_2 = new TGraph(24, Teffs_Mx50_2, Teffb_2);
    TGraph *ROC_Mx150_2 = new TGraph(24, Teffs_Mx150_2, Teffb_2);
    TGraph *ROC_Mx1_3 = new TGraph(24, Teffs_Mx1_3, Teffb_3);
    TGraph *ROC_Mx50_3 = new TGraph(24, Teffs_Mx50_3, Teffb_3);
    TGraph *ROC_Mx150_3 = new TGraph(24, Teffs_Mx150_3, Teffb_3);
    TGraph *ROC_Mx1_4 = new TGraph(24, Teffs_Mx1_4, Teffb_4);
    TGraph *ROC_Mx50_4 = new TGraph(24, Teffs_Mx50_4, Teffb_4);
    TGraph *ROC_Mx150_4 = new TGraph(24, Teffs_Mx150_4, Teffb_4);
    ROC_Mx1_1->SetLineWidth(2);
    ROC_Mx50_1->SetLineWidth(2);
    ROC_Mx150_1->SetLineWidth(2);
    ROC_Mx1_2->SetLineWidth(2);
    ROC_Mx50_2->SetLineWidth(2);
    ROC_Mx150_2->SetLineWidth(2);
    ROC_Mx1_3->SetLineWidth(2);
    ROC_Mx50_3->SetLineWidth(2);
    ROC_Mx150_3->SetLineWidth(2);
    ROC_Mx1_4->SetLineWidth(2);
    ROC_Mx50_4->SetLineWidth(2);
    ROC_Mx150_4->SetLineWidth(2);
    ROC_Mx1_1->SetLineColor(kRed);
    ROC_Mx50_1->SetLineColor(kBlue);
    ROC_Mx150_1->SetLineColor(kGreen);
    ROC_Mx1_2->SetLineColor(kRed);
    ROC_Mx50_2->SetLineColor(kBlue);
    ROC_Mx150_2->SetLineColor(kGreen);
    ROC_Mx1_3->SetLineColor(kRed);
    ROC_Mx50_3->SetLineColor(kBlue);
    ROC_Mx150_3->SetLineColor(kGreen);
    ROC_Mx1_4->SetLineColor(kRed);
    ROC_Mx50_4->SetLineColor(kBlue);
    ROC_Mx150_4->SetLineColor(kGreen);
    c1->cd(1);
    ROC_total->SetTitle("cut1");

    ROC_total->Draw();
    ROC_Mx1_1->Draw("L* same");
    ROC_Mx50_1->Draw("CP*");
    ROC_Mx150_1->Draw("C*");
    TLegend *i2 = new TLegend(0.15, 0.25, 0.40, 0.40);
    i2->SetBorderSize(0);
    i2->SetTextSize(0.03);
    i2->AddEntry(ROC_Mx1_1, "ctau=1mm m_{x^{2}}=1", "l");
    i2->AddEntry(ROC_Mx50_1, "ctau=10mm m_{x^{2}}=50", "l");
    i2->AddEntry(ROC_Mx150_1, "ctau=1mm m_{x^{2}}=150", "l");
    i2->Draw();
    c1->cd(2);
    ROC_total2->SetTitle("cut2");
    ROC_total2->Draw();
    ROC_Mx1_2->Draw("L* same");
    ROC_Mx50_2->Draw("CP*");
    ROC_Mx150_2->Draw("C*");
    gStyle->SetOptStat(0);
    c1->SaveAs("cut1_cut2_ROC.pdf");
    */
    // c1->SaveAs("test.png");
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        punzi_3Dsig();
    }
    else if (argc == 3)
    {
        punzi_3Dsig(argv[1], argv[2]);
    }
    else
    {
        cout << "ERROR" << endl;
        return 1;
    }
    return 0;
}