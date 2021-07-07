#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
using namespace std;
void Compare_ROC()
{
    auto c1 = new TCanvas("c", "BPRE");
    TGraph *sb1 = new TGraph("h_aph1_htvsMx2_1.txt");
    TAxis *axis = sb1->GetXaxis();
    TGraph *sb2 = new TGraph("h_aph2_htvsMx2_1.txt");
    TGraph *sb3 = new TGraph("h_aph3_htvsMx2_1.txt");
    TGraph *sb4 = new TGraph("h_aph4_htvsMx2_1.txt");
    sb1->SetTitle("ROC curve(Mx2_1:DYHT)");
    sb1->GetXaxis()->SetTitle("Sig Efficiency");
    sb1->GetYaxis()->SetTitle("Bkg rejection Efficiency");
    //sb1->GetXaxis()->SetRangeUser(0.5, 1.0);
    //sb1->GetYaxis()->SetRangeUser(0, 0.55);
    //axis->SetLimits(0.,1.);
    sb1->GetHistogram()->SetMaximum(0.65);
    sb1->SetLineColor(kRed);
    sb2->SetLineColor(kBlue);
    sb3->SetLineColor(kGreen);
    sb4->SetLineColor(kBlack);
    sb1->SetLineWidth(2);
    sb2->SetLineWidth(2);
    sb3->SetLineWidth(2);
    sb4->SetLineWidth(2);
    sb1->Draw();
    sb2->Draw("same");
    sb3->Draw("same");
    sb4->Draw("same");

    TLegend *l2 = new TLegend(0.65, 0.55, 0.90, 0.88);
    l2->SetBorderSize(0);
    //l2->SetTextSize(0.5);
    l2->AddEntry(sb1, "#alpha_3D (3D_{sig}<1)", "f");
    l2->AddEntry(sb2, "#alpha_3D (3D_{sig}<2)", "f");
    l2->AddEntry(sb3, "#alpha_3D (3D_{sig}<3)", "f");
    l2->AddEntry(sb4, "#alpha_3D (3D_{sig}<4)", "f");
    l2->Draw();
    c1->SaveAs("htvsMx2_1.png");
}