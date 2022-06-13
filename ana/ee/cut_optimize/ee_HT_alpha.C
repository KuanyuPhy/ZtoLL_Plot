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
void ee_HT_alpha()
{

    TFile *Mx2_1 = new TFile("./Sig1.root");
    TFile *Mx2_50 = new TFile("./Sig50.root");
    TFile *Mx2_150 = new TFile("./Sig150.root");

    TFile *DYHT = new TFile("./DY_emjet.root");
    TH1F *h_Mx2_1_alpha[4];
    TH1F *h_Mx2_50_alpha[4];
    TH1F *h_Mx2_150_alpha[4];
    TH1F *h_DYHT_alpha[4];
    for (int i = 0; i < 4; i++)
    {
        h_Mx2_1_alpha[i] = ((TH1F *)Mx2_1->Get(("h_DYHT_alpha_" + std::to_string(i)).c_str()));
        h_Mx2_50_alpha[i] = ((TH1F *)Mx2_50->Get(("h_DYHT_alpha_" + std::to_string(i)).c_str()));
        h_Mx2_150_alpha[i] = ((TH1F *)Mx2_150->Get(("h_DYHT_alpha_" + std::to_string(i)).c_str()));
        h_DYHT_alpha[i] = ((TH1F *)DYHT->Get(("h_DYHT_alpha_" + std::to_string(i)).c_str()));

        h_Mx2_1_alpha[i]->SetLineWidth(2);
        h_Mx2_50_alpha[i]->SetLineWidth(2);
        h_Mx2_50_alpha[i]->SetTitle(("cut" + std::to_string(i+1)).c_str());
        h_Mx2_50_alpha[i]->GetYaxis()->SetTitle("N Jets / Normalized");
        h_Mx2_50_alpha[i]->GetXaxis()->SetTitle("#alpha_{3D}");
        h_Mx2_150_alpha[i]->SetLineWidth(2);
        h_DYHT_alpha[i]->SetLineWidth(2);
        h_DYHT_alpha[i]->SetTitle(("cut" + std::to_string(i+1)).c_str());
        h_DYHT_alpha[i]->GetYaxis()->SetTitle("N Jets / Normalized");
        h_DYHT_alpha[i]->GetXaxis()->SetTitle("#alpha_{3D}");
        h_Mx2_1_alpha[i]->SetLineColor(kRed);
        h_Mx2_50_alpha[i]->SetLineColor(kBlue);
        h_Mx2_150_alpha[i]->SetLineColor(kGreen);
        h_DYHT_alpha[i]->SetLineColor(kMagenta);
    }
    auto c1 = new TCanvas("c", "", 1000, 1000);
    c1->Divide(2, 2);
    c1->cd(1);
    h_Mx2_50_alpha[0]->DrawNormalized("hist ");
    h_Mx2_1_alpha[0]->DrawNormalized("hist same");
    h_Mx2_150_alpha[0]->DrawNormalized("hist same");
    h_DYHT_alpha[0]->DrawNormalized("hist same");

    TLegend *i2 = new TLegend(0.40, 0.45, 0.70, 0.80);
    i2->SetBorderSize(0);
    i2->SetTextSize(0.03);
    i2->AddEntry(h_Mx2_1_alpha[0], "ctau=1mm m_{x^{2}}=1", "l");
    i2->AddEntry(h_Mx2_50_alpha[0], "ctau=10mm m_{x^{2}}=50", "l");
    i2->AddEntry(h_Mx2_150_alpha[0], "ctau=1mm m_{x^{2}}=150", "l");
    i2->AddEntry(h_DYHT_alpha[0], "Drell-Yan", "f");
    i2->Draw();
    c1->cd(2);
    h_DYHT_alpha[1]->DrawNormalized("hist ");
    h_Mx2_50_alpha[1]->DrawNormalized("hist same");
    h_Mx2_1_alpha[1]->DrawNormalized("hist same");
    h_Mx2_150_alpha[1]->DrawNormalized("hist same");

    c1->cd(3);
    h_Mx2_50_alpha[2]->DrawNormalized("hist ");
    h_Mx2_1_alpha[2]->DrawNormalized("hist same");
    h_Mx2_150_alpha[2]->DrawNormalized("hist same");
    h_DYHT_alpha[2]->DrawNormalized("hist same");
    c1->cd(4);
    h_Mx2_50_alpha[3]->DrawNormalized("hist ");
    h_Mx2_1_alpha[3]->DrawNormalized("hist same");
    h_Mx2_150_alpha[3]->DrawNormalized("hist same");
    h_DYHT_alpha[3]->DrawNormalized("hist same");
    gStyle->SetOptStat(0);
    c1->SaveAs("differentcut_alpha3D.pdf");
}
