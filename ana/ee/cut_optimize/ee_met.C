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
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "./../../lib/Cross_section.h"
#include "./../../lib/setNCUStyle.C"
using namespace std;
void ee_met(TString inputfile = "./DY/ee_DY_emjet.root", TString outputfile1 = "./ee_emjet.root")
{
    setNCUStyle(true);
    TFile *DYprocess = TFile::Open(inputfile);
    TFile *Sigfile = new TFile("./sig/ee_Sig_emjet.root");
    TFile *Topprocess = new TFile("./top/ee_Top_emjet.root");
    TFile *Dibosonprocess = new TFile("./diboson/ee_Diboson_emjet.root");
    TFile *Tribosonprocess = new TFile("./triboson/ee_Triboson_emjet.root");

    //-----------
    // For Met
    //-----------

    TH1D *HT_Met = ((TH1D *)DYprocess->Get("h_DY_Met"));
    TH1D *Top_Met = ((TH1D *)Topprocess->Get("h_Top_Met"));
    TH1D *Diboson_Met = ((TH1D *)Dibosonprocess->Get("h_diboson_Met"));
    TH1D *Triboson_Met = ((TH1D *)Tribosonprocess->Get("h_triboson_Met"));
    TH1D *Sig1_Met = ((TH1D *)Sigfile->Get("h_Sig1_Met"));
    TH1D *Sig50_Met = ((TH1D *)Sigfile->Get("h_Sig50_Met"));
    TH1D *Sig150_Met = ((TH1D *)Sigfile->Get("h_Sig150_Met"));

    HT_Met->SetLineColor(kOrange - 3);
    Top_Met->SetLineColor(kGreen + 3);
    Diboson_Met->SetLineColor(kAzure + 7);
    Triboson_Met->SetLineColor(kMagenta - 3);

    Sig1_Met->SetLineColor(kRed);
    Sig50_Met->SetLineColor(kBlack);
    Sig150_Met->SetLineColor(kBlue);

    HT_Met->SetLineWidth(2);
    Top_Met->SetLineWidth(2);
    Diboson_Met->SetLineWidth(2);
    Triboson_Met->SetLineWidth(2);
    Sig1_Met->SetLineWidth(2);
    Sig50_Met->SetLineWidth(2);
    Sig150_Met->SetLineWidth(2);

    TCanvas *c1 = new TCanvas();

    THStack *hs = new THStack("hs", "");
    hs->Add(HT_Met);
    hs->Add(Top_Met);
    hs->Add(Diboson_Met);
    hs->Add(Triboson_Met);

    cout << "number of Events with DY = " << HT_Met->Integral() << "\n";
    cout << "number of Events with Top = " << Top_Met->Integral() << "\n";
    cout << "number of Events with Diboson = " << Diboson_Met->Integral() << "\n";
    cout << "number of Events with Triboson = " << Triboson_Met->Integral() << "\n";

    /*
    hs->Draw("hist");
    hs->GetXaxis()->SetTitleOffset(1.5);
    hs->GetXaxis()->SetTitle("Met");
    hs->GetYaxis()->SetTitle("nEvents");
    */
    HT_Met->DrawNormalized("h");
    Top_Met->DrawNormalized("h same");
    Diboson_Met->DrawNormalized("h same");
    Triboson_Met->DrawNormalized("h same");
    Sig1_Met->DrawNormalized("h same");
    Sig50_Met->DrawNormalized("h same");
    Sig150_Met->DrawNormalized("h same");

    TLegend *l0 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(HT_Met, "Drell-Yan process", "f");
    l0->AddEntry(Top_Met, "Top process", "f");
    l0->AddEntry(Diboson_Met, "Diboson process", "f");
    l0->AddEntry(Triboson_Met, "Triboson process", "f");
    l0->AddEntry(Sig1_Met, "x2 = 1 GeV, ctau = 1 mm", "f");
    l0->AddEntry(Sig50_Met, "x2 = 50 GeV, ctau = 10 mm", "f");
    l0->AddEntry(Sig150_Met, "x2 = 150 GeV, ctau = 1 mm", "f");
    l0->Draw();

    c1->Modified();
}
