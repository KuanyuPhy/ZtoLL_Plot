#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TLegend.h>
#include <TH1D.h>
#include <string>
#include <TCanvas.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../../lib/Cross_section.h"
using namespace std;
void compare_2DIP(TString inputfile = "./ee_Sig_emjet.root")
{
    TFile *Sig_file = TFile::Open(inputfile);
    TFile *Top_file = new TFile("./../top/ee_Top_emjet.root");
    TFile *DY_file = new TFile("./../DY/ee_DY_emjet.root");

    TH1D *Sig1_IP2D = ((TH1D *)Sig_file->Get("h_Sig1_IP2D"));
    TH1D *Sig50_IP2D = ((TH1D *)Sig_file->Get("h_Sig50_IP2D"));
    TH1D *Sig150_IP2D = ((TH1D *)Sig_file->Get("h_Sig150_IP2D"));
    TH1D *Sig1_Chi3Dlog = ((TH1D *)Sig_file->Get("h_Sig1_Chi3Dlog"));
    TH1D *Sig50_Chi3Dlog = ((TH1D *)Sig_file->Get("h_Sig50_Chi3Dlog"));
    TH1D *Sig150_Chi3Dlog = ((TH1D *)Sig_file->Get("h_Sig150_Chi3Dlog"));

    TH1D *DY_IP2D = ((TH1D *)DY_file->Get("h_DY_IP2D"));
    TH1D *DY_Chi3Dlog = ((TH1D *)DY_file->Get("h_DY_Chi3Dlog"));
    TH1D *Top_IP2D = ((TH1D *)Top_file->Get("h_Top_IP2D"));
    TH1D *Top_Chi3Dlog = ((TH1D *)Top_file->Get("h_Top_Chi3Dlog"));

    Sig1_IP2D->SetLineWidth(2);
    Sig50_IP2D->SetLineWidth(2);
    Sig150_IP2D->SetLineWidth(2);
    Sig1_Chi3Dlog->SetLineWidth(2);
    Sig50_Chi3Dlog->SetLineWidth(2);
    Sig150_Chi3Dlog->SetLineWidth(2);

    DY_IP2D->SetLineWidth(2);
    DY_Chi3Dlog->SetLineWidth(2);
    Top_IP2D->SetLineWidth(2);
    Top_Chi3Dlog->SetLineWidth(2);

    Sig1_IP2D->SetLineColor(kRed);
    Sig1_Chi3Dlog->SetLineColor(kRed);
    Sig50_IP2D->SetLineColor(kBlue);
    Sig50_Chi3Dlog->SetLineColor(kBlue);
    Sig150_IP2D->SetLineColor(kBlack);
    Sig150_Chi3Dlog->SetLineColor(kBlack);

    DY_IP2D->SetLineColor(kOrange - 3);
    DY_Chi3Dlog->SetLineColor(kOrange - 3);
    Top_IP2D->SetLineColor(kGreen + 3);
    Top_Chi3Dlog->SetLineColor(kGreen + 3);

    auto c1 = new TCanvas("c", "", 700, 1000);
    c1->Divide(1, 2);
    c1->cd(1);

    DY_IP2D->GetXaxis()->SetRangeUser(-6, 4);

    DY_IP2D->DrawNormalized("hist");
    Top_IP2D->DrawNormalized("hist same");
    Sig1_IP2D->DrawNormalized("hist same");
    Sig50_IP2D->DrawNormalized("hist same");
    Sig150_IP2D->DrawNormalized("hist same");

    TLegend *leg = new TLegend(0.64, 0.463, 0.870, 0.736);
    // TLegend *leg = new TLegend(0.34, 0.463, 0.470, 0.636);
    leg->SetFillColor(0);
    leg->SetFillStyle(0);
    leg->SetTextSize(0.045);
    leg->SetBorderSize(0);
    leg->SetFillColor(0);
    leg->SetFillStyle(0);
    leg->AddEntry(Sig1_IP2D, "MX2_1");
    leg->AddEntry(Sig50_IP2D, "MX2_50");
    leg->AddEntry(Sig150_IP2D, "MX2_150");
    leg->AddEntry(DY_IP2D, "Drell-Yan");
    leg->AddEntry(Top_IP2D, "Top process ");
    leg->Draw();

    c1->cd(2);

    DY_Chi3Dlog->GetXaxis()->SetRangeUser(-6, 4);

    DY_Chi3Dlog->DrawNormalized("hist");
    Top_Chi3Dlog->DrawNormalized("hist same");
    Sig1_Chi3Dlog->DrawNormalized("hist same");
    Sig50_Chi3Dlog->DrawNormalized("hist same");
    Sig150_Chi3Dlog->DrawNormalized("hist same");
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        compare_2DIP();
    }
    else if (argc == 2)
    {
        compare_2DIP(argv[1]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}