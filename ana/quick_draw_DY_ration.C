#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./lib/Cross_section.h"
#include "setNCUStyle.C"
using namespace std;
void quick_draw_DY_ration()
{

    Int_t KON = TColor::GetFreeColorIndex();
    TColor *KON_color = new TColor(KON, 0.06, 0.15, 0.25);

    //setNCUStyle(true);

    TFile *DYHT = new TFile("./../../ABCD_HT.root");

    TH1F *h_ht0A_met = ((TH1F *)DYHT->Get("h_ht0A_met"));
    TH1F *h_ht0B_met = ((TH1F *)DYHT->Get("h_ht0B_met"));
    TH1F *h_ht70A_met = ((TH1F *)DYHT->Get("h_ht70A_met"));
    TH1F *h_ht70B_met = ((TH1F *)DYHT->Get("h_ht70B_met"));
    TH1F *h_ht100A_met = ((TH1F *)DYHT->Get("h_ht100A_met"));
    TH1F *h_ht100B_met = ((TH1F *)DYHT->Get("h_ht100B_met"));
    TH1F *h_ht200A_met = ((TH1F *)DYHT->Get("h_ht200A_met"));
    TH1F *h_ht200B_met = ((TH1F *)DYHT->Get("h_ht200B_met"));
    TH1F *h_ht400A_met = ((TH1F *)DYHT->Get("h_ht400A_met"));
    TH1F *h_ht400B_met = ((TH1F *)DYHT->Get("h_ht400B_met"));
    TH1F *h_ht600A_met = ((TH1F *)DYHT->Get("h_ht600A_met"));
    TH1F *h_ht600B_met = ((TH1F *)DYHT->Get("h_ht600B_met"));
    TH1F *h_ht800A_met = ((TH1F *)DYHT->Get("h_ht800A_met"));
    TH1F *h_ht800B_met = ((TH1F *)DYHT->Get("h_ht800B_met"));
    TH1F *h_ht1200A_met = ((TH1F *)DYHT->Get("h_ht1200A_met"));
    TH1F *h_ht1200B_met = ((TH1F *)DYHT->Get("h_ht1200B_met"));
    TH1F *h_ht2500A_met = ((TH1F *)DYHT->Get("h_ht2500A_met"));
    TH1F *h_ht2500B_met = ((TH1F *)DYHT->Get("h_ht2500B_met"));

    TCanvas *c1 = new TCanvas("", "",10, 10, 700, 700);
    c1->Divide(4, 3);
    c1->cd(1);
    //h_ht0A_met->Divide(h_ht0B_met);
    h_ht0A_met->SetLineWidth(3);
    h_ht0A_met->Draw("text");
    c1->cd(2);
    //h_ht70A_met->Divide(h_ht70B_met);
    h_ht70A_met->SetLineWidth(3);
    h_ht70A_met->Draw("text");
    c1->cd(3);
    //h_ht100A_met->Divide(h_ht100B_met);
    h_ht100A_met->SetLineWidth(3);
    h_ht100A_met->Draw("text");
     c1->cd(4);
    //h_ht200A_met->Divide(h_ht200B_met);
    h_ht200A_met->SetLineWidth(3);
    h_ht200A_met->Draw("text");
    c1->cd(5);
    //h_ht400A_met->Divide(h_ht400B_met);
    h_ht400A_met->SetLineWidth(3);
    h_ht400A_met->Draw("text");
    c1->cd(6);
    //h_ht600A_met->Divide(h_ht600B_met);
    h_ht600A_met->SetLineWidth(3);
    h_ht600A_met->Draw("text");
    c1->cd(7);
    //h_ht800A_met->Divide(h_ht800B_met);
    h_ht800A_met->SetLineWidth(3);
    h_ht800A_met->Draw("text");
    c1->cd(8);
    //h_ht1200A_met->Divide(h_ht1200B_met);
    h_ht1200A_met->SetLineWidth(3);
    h_ht1200A_met->Draw("text");
    c1->cd(9);
    //h_ht2500A_met->Divide(h_ht2500B_met);
    h_ht2500A_met->SetLineWidth(3);
    h_ht2500A_met->Draw("text");
}