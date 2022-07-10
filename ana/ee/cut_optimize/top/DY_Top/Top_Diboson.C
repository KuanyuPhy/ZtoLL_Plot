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
#include "./../../../../lib/setNCUStyle.C"
using namespace std;
void Top_Diboson(TString inputfile = "./../ee_Top_emjet_half.root")
{
    setNCUStyle();
    TFile *Topfile = TFile::Open(inputfile);
    TFile *DYfile = TFile::Open("./../../DY/ee_DY_emjet_half.root");
    TFile *Dibosonfile = TFile::Open("./../../diboson/ee_Diboson_emjet_half.root");

    //----------------------------
    // Read fake rate
    //----------------------------
    TH1D *Top_hev_nTrkfakerate = ((TH1D *)Topfile->Get("Top_heavy_fakeRate"));
    TH1D *Top_light_nTrkfakerate = ((TH1D *)Topfile->Get("Top_light_fakeRate"));
    TH1D *Top_bjet_nTrkfakerate = ((TH1D *)Topfile->Get("Top_bjet_fakeRate"));
    TH1D *Top_cjet_nTrkfakerate = ((TH1D *)Topfile->Get("Top_cjet_fakeRate"));

    TH1D *Diboson_hev_nTrkfakerate = ((TH1D *)Dibosonfile->Get("Diboson_heavy_fakeRate"));
    TH1D *Diboson_light_nTrkfakerate = ((TH1D *)Dibosonfile->Get("Diboson_light_fakeRate"));
    TH1D *Diboson_bjet_nTrkfakerate = ((TH1D *)Dibosonfile->Get("Diboson_bjet_fakeRate"));
    TH1D *Diboson_cjet_nTrkfakerate = ((TH1D *)Dibosonfile->Get("Diboson_cjet_fakeRate"));

    TH1D *DY_hev_nTrkfakerate = ((TH1D *)DYfile->Get("HT_heavy_fakeRate"));
    TH1D *DY_light_nTrkfakerate = ((TH1D *)DYfile->Get("HT_light_fakeRate"));
    TH1D *DY_bjet_nTrkfakerate = ((TH1D *)DYfile->Get("HT_bjet_fakeRate"));
    TH1D *DY_cjet_nTrkfakerate = ((TH1D *)DYfile->Get("HT_cjet_fakeRate"));

    Top_hev_nTrkfakerate->SetLineWidth(2);
    Top_light_nTrkfakerate->SetLineWidth(2);
    Top_bjet_nTrkfakerate->SetLineWidth(2);
    Top_cjet_nTrkfakerate->SetLineWidth(2);

    Diboson_hev_nTrkfakerate->SetLineWidth(2);
    Diboson_light_nTrkfakerate->SetLineWidth(2);
    Diboson_bjet_nTrkfakerate->SetLineWidth(2);
    Diboson_cjet_nTrkfakerate->SetLineWidth(2);

    DY_hev_nTrkfakerate->SetLineWidth(2);
    DY_light_nTrkfakerate->SetLineWidth(2);
    DY_bjet_nTrkfakerate->SetLineWidth(2);
    DY_cjet_nTrkfakerate->SetLineWidth(2);

    DY_hev_nTrkfakerate->SetLineColor(kOrange - 3);
    DY_light_nTrkfakerate->SetLineColor(kOrange - 3);
    DY_bjet_nTrkfakerate->SetLineColor(kOrange - 3);
    DY_cjet_nTrkfakerate->SetLineColor(kOrange - 3);

    Diboson_hev_nTrkfakerate->SetLineColor(kAzure + 7);
    Diboson_light_nTrkfakerate->SetLineColor(kAzure + 7);
    Diboson_bjet_nTrkfakerate->SetLineColor(kAzure + 7);
    Diboson_cjet_nTrkfakerate->SetLineColor(kAzure + 7);

    Top_hev_nTrkfakerate->SetLineColor(kGreen + 3);
    Top_light_nTrkfakerate->SetLineColor(kGreen + 3);
    Top_bjet_nTrkfakerate->SetLineColor(kGreen + 3);
    Top_cjet_nTrkfakerate->SetLineColor(kGreen + 3);

    auto c1 = new TCanvas("c1");
    c1->Divide(3, 1);
    /*
    c1->cd(1);
    DY_hev_nTrkfakerate->GetYaxis()->SetTitle("fake rate");
    DY_hev_nTrkfakerate->GetXaxis()->SetTitle("Track multiplicity");
    DY_hev_nTrkfakerate->Draw();
    Top_hev_nTrkfakerate->Draw("same");
    TLegend *l0 = new TLegend(0.65, 0.6, 0.90, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->SetHeader("heavy flavor");
    l0->AddEntry(DY_hev_nTrkfakerate, "DY process", "l");
    l0->AddEntry(Top_hev_nTrkfakerate, "Top process", "l");
    l0->Draw();
    c1->cd(2);
    DY_light_nTrkfakerate->SetTitle("");
    DY_light_nTrkfakerate->GetYaxis()->SetTitle("fake rate");
    DY_light_nTrkfakerate->GetXaxis()->SetTitle("Track multiplicity");
    DY_light_nTrkfakerate->Draw();
    Top_light_nTrkfakerate->Draw("same");
    TLegend *l1 = new TLegend(0.65, 0.6, 0.90, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->SetHeader("light flavor");
    l1->AddEntry(DY_hev_nTrkfakerate, "DY process", "l");
    l1->AddEntry(Top_hev_nTrkfakerate, "Top process", "l");
    l1->Draw();
    */
    c1->cd(1);
    Top_bjet_nTrkfakerate->SetTitle("");
    Top_bjet_nTrkfakerate->GetYaxis()->SetTitle("fake rate");
    Top_bjet_nTrkfakerate->GetXaxis()->SetTitle("Track multiplicity");
    Top_bjet_nTrkfakerate->Draw();
    Diboson_bjet_nTrkfakerate->Draw("same");
    DY_bjet_nTrkfakerate->Draw("same");

    TLegend *l2 = new TLegend(0.65, 0.6, 0.90, 0.80);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->SetHeader("b flavor");
    l2->AddEntry(Diboson_bjet_nTrkfakerate, "Diboson process", "l");
    l2->AddEntry(Top_bjet_nTrkfakerate, "Top process", "l");
    l2->AddEntry(DY_bjet_nTrkfakerate, "DY process", "l");
    l2->Draw();
    c1->cd(2);
    Top_cjet_nTrkfakerate->SetTitle("");
    Top_cjet_nTrkfakerate->GetYaxis()->SetTitle("fake rate");
    Top_cjet_nTrkfakerate->GetXaxis()->SetTitle("Track multiplicity");
    DY_cjet_nTrkfakerate->SetTitle("");
    DY_cjet_nTrkfakerate->GetYaxis()->SetTitle("fake rate");
    DY_cjet_nTrkfakerate->GetXaxis()->SetTitle("Track multiplicity");
    DY_cjet_nTrkfakerate->Draw();
    Top_cjet_nTrkfakerate->Draw("same");
    Diboson_cjet_nTrkfakerate->Draw("same");

    TLegend *l3 = new TLegend(0.65, 0.6, 0.90, 0.80);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.03);
    l3->SetHeader("c flavor");
    l3->AddEntry(Diboson_bjet_nTrkfakerate, "Diboson process", "l");
    l3->AddEntry(Top_bjet_nTrkfakerate, "Top process", "l");
    l3->AddEntry(DY_bjet_nTrkfakerate, "DY process", "l");
    l3->Draw();
    c1->cd(3);
    Top_light_nTrkfakerate->SetTitle("");
    Top_light_nTrkfakerate->GetYaxis()->SetTitle("fake rate");
    Top_light_nTrkfakerate->GetXaxis()->SetTitle("Track multiplicity");
    Top_light_nTrkfakerate->Draw();
    Diboson_light_nTrkfakerate->Draw("same");
    DY_light_nTrkfakerate->Draw("same");

    TLegend *l4 = new TLegend(0.65, 0.6, 0.90, 0.80);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.03);
    l4->SetHeader("light flavor");
    l4->AddEntry(Diboson_bjet_nTrkfakerate, "Diboson process", "l");
    l4->AddEntry(Top_bjet_nTrkfakerate, "Top process", "l");
    l4->AddEntry(DY_bjet_nTrkfakerate, "DY process", "l");
    l4->Draw();
    gStyle->SetOptStat(0);
}