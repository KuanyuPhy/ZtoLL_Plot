#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../lib/Cross_section.h"
#include "./../../lib/setNCUStyle.C"
using namespace std;
void ee_HT_nem()
{
    TFile *Mx2_1 = new TFile("./Sig1.root");
    TFile *Mx2_50 = new TFile("./Sig50.root");
    TFile *Mx2_150 = new TFile("./Sig150.root");

    TFile *DYHT = new TFile("./DY_emjet.root");
    TH1F *h_Mx2_1_nEm_1[24];
    TH1F *h_Mx2_1_nEm_2[24];
    TH1F *h_Mx2_50_nEm_1[24];
    TH1F *h_Mx2_50_nEm_2[24];
    TH1F *h_Mx2_150_nEm_1[24];
    TH1F *h_Mx2_150_nEm_2[24];
    TH1F *h_DYHT_nEm_1[24];
    TH1F *h_DYHT_nEm_2[24];
    for (int i = 0; i < 24; i++)
    {
        h_Mx2_1_nEm_1[i] = ((TH1F *)Mx2_1->Get(("h_ht0_NemJet_" + std::to_string(i)).c_str()));
        h_Mx2_1_nEm_2[i] = ((TH1F *)Mx2_1->Get(("h_ht0_NemJet2_" + std::to_string(i)).c_str()));
        h_Mx2_50_nEm_1[i] = ((TH1F *)Mx2_50->Get(("h_ht0_NemJet_" + std::to_string(i)).c_str()));
        h_Mx2_50_nEm_2[i] = ((TH1F *)Mx2_50->Get(("h_ht0_NemJet2_" + std::to_string(i)).c_str()));
        h_Mx2_150_nEm_1[i] = ((TH1F *)Mx2_150->Get(("h_ht0_NemJet_" + std::to_string(i)).c_str()));
        h_Mx2_150_nEm_2[i] = ((TH1F *)Mx2_150->Get(("h_ht0_NemJet2_" + std::to_string(i)).c_str()));
        h_DYHT_nEm_1[i] = ((TH1F *)DYHT->Get(("h_ht0_NemJet_" + std::to_string(i)).c_str()));
        h_DYHT_nEm_2[i] = ((TH1F *)DYHT->Get(("h_ht0_NemJet2_" + std::to_string(i)).c_str()));

        h_Mx2_1_nEm_1[i]->SetLineWidth(2);
        h_Mx2_1_nEm_2[i]->SetLineWidth(2);
        h_Mx2_50_nEm_1[i]->SetLineWidth(2);
        h_Mx2_50_nEm_2[i]->SetLineWidth(2);
        h_Mx2_50_nEm_1[i]->SetTitle(("Step_" + std::to_string(i)).c_str());
        h_Mx2_50_nEm_1[i]->GetYaxis()->SetTitle("");
        h_Mx2_50_nEm_1[i]->GetXaxis()->SetTitle("N_{em}");
        h_Mx2_150_nEm_1[i]->SetLineWidth(2);
        h_Mx2_150_nEm_2[i]->SetLineWidth(2);
        h_DYHT_nEm_1[i]->SetLineWidth(2);
        h_DYHT_nEm_2[i]->SetLineWidth(2);
        h_DYHT_nEm_1[i]->SetTitle(("Step_" + std::to_string(i)).c_str());
        h_DYHT_nEm_2[i]->SetTitle(("Step_" + std::to_string(i)).c_str());
        h_DYHT_nEm_1[i]->GetYaxis()->SetTitle("Normalized");
        h_DYHT_nEm_2[i]->GetYaxis()->SetTitle("Normalized");
        h_DYHT_nEm_1[i]->GetXaxis()->SetTitle("N_{em}");
        h_DYHT_nEm_2[i]->GetXaxis()->SetTitle("N_{em}");
        h_Mx2_1_nEm_1[i]->SetLineColor(kRed);
        h_Mx2_1_nEm_2[i]->SetLineColor(kRed);
        h_Mx2_50_nEm_1[i]->SetLineColor(kBlue);
        h_Mx2_50_nEm_2[i]->SetLineColor(kBlue);
        h_Mx2_150_nEm_1[i]->SetLineColor(kGreen);
        h_Mx2_150_nEm_2[i]->SetLineColor(kGreen);
        h_DYHT_nEm_1[i]->SetLineColor(kMagenta);
        h_DYHT_nEm_2[i]->SetLineColor(kMagenta);
    }
    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(5, 5);
    for (int i = 0; i < 24; i++)
    {
        c1->cd(i + 1);
        h_DYHT_nEm_2[i]->DrawNormalized("hist");
        h_Mx2_1_nEm_2[i]->DrawNormalized("hist same");
        h_Mx2_50_nEm_2[i]->DrawNormalized("hist same");
        h_Mx2_150_nEm_2[i]->DrawNormalized("hist same");
    }
}
