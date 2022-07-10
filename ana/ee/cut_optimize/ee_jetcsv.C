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
#include <THStack.h>
#include "./../../lib/Cross_section.h"
#include "./../../lib/setNCUStyle.C"
using namespace std;
void ee_jetcsv(TString inputfile = "./DY/ee_DY_Met.root")
{
    setNCUStyle(true);
    TFile *DYprocess = TFile::Open(inputfile);
    TFile *Topprocess = new TFile("./top/ee_Top_Met.root");
    TFile *Dibosonprocess = new TFile("./diboson/ee_Diboson_Met.root");
    TFile *Tribosonprocess = new TFile("./triboson/ee_Triboson_Met.root");

    //-----------
    // For jetcsv
    //-----------

    TH1D *HT_jetcsv = ((TH1D *)DYprocess->Get("h_DY_bjetCSV"));
    TH1D *Top_jetcsv = ((TH1D *)Topprocess->Get("h_Top_bjetcsv"));
    TH1D *Diboson_jetcsv = ((TH1D *)Dibosonprocess->Get("h_diboson_bjetCSV"));

    HT_jetcsv->SetLineColor(kOrange - 3);
    Top_jetcsv->SetLineColor(kGreen + 3);
    Diboson_jetcsv->SetLineColor(kAzure + 7);

    //HT_jetcsv->SetFillColor(kOrange - 3);
    //Top_jetcsv->SetFillColor(kGreen + 3);
    //Diboson_jetcsv->SetFillColor(kAzure + 7);

    // Sig1_Met->SetLineColor(kRed);
    // Sig50_Met->SetLineColor(kBlack);
    // Sig150_Met->SetLineColor(kBlue);

    HT_jetcsv->SetLineWidth(2);
    Top_jetcsv->SetLineWidth(2);
    Diboson_jetcsv->SetLineWidth(2);

    // Sig1_Met->SetLineWidth(2);
    // Sig50_Met->SetLineWidth(2);
    // Sig150_Met->SetLineWidth(2);

    TCanvas *c1 = new TCanvas();

    Top_jetcsv->GetYaxis()->SetTitle("nJet");
    Top_jetcsv->GetXaxis()->SetTitle("jetcsv");

    Top_jetcsv->Draw(" ");
    HT_jetcsv->Draw(" same");
    Diboson_jetcsv->Draw(" same");
    // Triboson_Met->Draw("h same");
    // Sig1_Met->DrawNormalized("h same");
    // Sig50_Met->DrawNormalized("h same");
    // Sig150_Met->DrawNormalized("h same");

    TLegend *l0 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->SetHeader("b flavor");
    l0->AddEntry(HT_jetcsv, "Drell-Yan process", "f");
    l0->AddEntry(Top_jetcsv, "Top process", "f");
    l0->AddEntry(Diboson_jetcsv, "Diboson process", "f");
    l0->Draw();

    c1->Modified();
}
