#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
//#include "./lib/Cross_section.h"
#include "./lib/Cross_section.C"
#include "setNCUStyle.C"
using namespace std;
void quick_SR()
{
    setNCUStyle(true);
    auto c1 = new TCanvas("c", "BPRE");
    
    TFile *file = new TFile("./../../ABCD_HT.root");
    TH1D *ABCD_CR = ((TH1D *)file->Get("h_ht70a_njet"));
    TH1D *ABCD_SR = ((TH1D *)file->Get("h_ht70b_njet"));

    ABCD_CR->SetLineWidth(2);
    ABCD_CR->SetLineColor(kBlue);
    ABCD_SR->SetLineWidth(2);
    ABCD_SR->SetLineColor(kRed);

        ABCD_CR->SetYTitle("Events/Normalized");
    ABCD_CR->SetXTitle("nJet");

    ABCD_CR->DrawNormalized();
    ABCD_SR->DrawNormalized("same");



    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(ABCD_CR, "nJet CR (region A)", "l");
    l2->AddEntry(ABCD_SR, "nJet SR (region B)", "l");
    //l2->AddEntry(DYPT50_nT, "DYJets_pTBin", "l");
    l2->Draw();

}