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
void quick_Top_draw()
{

    Int_t KON = TColor::GetFreeColorIndex();
    TColor *KON_color = new TColor(KON, 0.06, 0.15, 0.25);

    //setNCUStyle(true);

    TFile *Top = new TFile("./../../ABCD_Top.root");

    TH1F *Top_tW_top_a_met = ((TH1F *)Top->Get("Top_tW_top_a_met"));
    TH1F *Top_tW_antitop_a_met = ((TH1F *)Top->Get("Top_tW_antitop_a_met"));
    TH1F *Top_TTTo2L2Nu_a_met = ((TH1F *)Top->Get("Top_TTTo2L2Nu_a_met"));
    TH1F *Top_TTWJetsToLNu_a_met = ((TH1F *)Top->Get("Top_TTWJetsToLNu_a_met"));
    TH1F *Top_TTWJetsToQQ_a_met = ((TH1F *)Top->Get("Top_TTWJetsToQQ_a_met"));
    TH1F *Top_TTZToLLNuNu_a_met = ((TH1F *)Top->Get("Top_TTZToLLNuNu_a_met"));
    TH1F *Top_TTZToQQ_a_met = ((TH1F *)Top->Get("Top_TTZToQQ_a_met"));
    TH1F *Top_tW_top_b_met = ((TH1F *)Top->Get("Top_tW_top_b_met"));
    TH1F *Top_tW_antitop_b_met = ((TH1F *)Top->Get("Top_tW_antitop_b_met"));
    TH1F *Top_TTTo2L2Nu_b_met = ((TH1F *)Top->Get("Top_TTTo2L2Nu_b_met"));
    TH1F *Top_TTWJetsToLNu_b_met = ((TH1F *)Top->Get("Top_TTWJetsToLNu_b_met"));
    TH1F *Top_TTWJetsToQQ_b_met = ((TH1F *)Top->Get("Top_TTWJetsToQQ_b_met"));
    TH1F *Top_TTZToLLNuNu_b_met = ((TH1F *)Top->Get("Top_TTZToLLNuNu_b_met"));
    TH1F *Top_TTZToQQ_b_met = ((TH1F *)Top->Get("Top_TTZToQQ_b_met"));
    TH1F *h_Top_met_A = ((TH1F *)Top->Get("h_Top_met_A"));
    TH1F *h_Top_met_B = ((TH1F *)Top->Get("h_Top_met_B"));
    TH1F *h_Top_met_Ratio = ((TH1F *)Top->Get("h_Top_met_Ratio"));

    TCanvas *c1 = new TCanvas("", "",10, 10, 700, 700);
    c1->Divide(4, 2);
    c1->cd(1);
    //h_ht0A_met->Divide(h_ht0B_met);
    Top_tW_top_b_met->SetLineWidth(3);
    Top_tW_top_b_met->Draw("text");
    c1->cd(2);
    Top_tW_antitop_b_met->SetLineWidth(3);
    Top_tW_antitop_b_met->Draw("text");
    c1->cd(3);
    //h_ht100A_met->Divide(h_ht100B_met);
    Top_TTTo2L2Nu_b_met->SetLineWidth(3);
    Top_TTTo2L2Nu_b_met->Draw("text");
     c1->cd(4);
    //h_ht200A_met->Divide(h_ht200B_met);
    Top_TTWJetsToLNu_b_met->SetLineWidth(3);
    Top_TTWJetsToLNu_b_met->Draw("text");
    c1->cd(5);
    //h_ht400A_met->Divide(h_ht400B_met);
    Top_TTWJetsToQQ_b_met->SetLineWidth(3);
    Top_TTWJetsToQQ_b_met->Draw("text");
    c1->cd(6);
    //h_ht600A_met->Divide(h_ht600B_met);
    Top_TTZToLLNuNu_b_met->SetLineWidth(3);
    Top_TTZToLLNuNu_b_met->Draw("text");
    c1->cd(7);
    //h_ht800A_met->Divide(h_ht800B_met);
    Top_TTZToQQ_b_met->SetLineWidth(3);
    Top_TTZToQQ_b_met->Draw("text");

}