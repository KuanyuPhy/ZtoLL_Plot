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
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "./../lib/Cross_section.h"
#include "./../lib/setNCUStyle.C"
using namespace RooFit;
void ee_Top_fake_rate_plot()
{
    // setNCUStyle(true);
    TFile *Top = new TFile("./../../../root_file/BgEstimation/Top_fakerateStudy.root");
    TH1D *Top_emergjethadronflavor = ((TH1D *)Top->Get("h_TTTo2L2Nu_emergjethadronflavor"));
    TH1D *Top_hev_emergjetpt = ((TH1D *)Top->Get("h_TTTo2L2Nu_hev_emergjetpt"));
    TH1D *Top_light_emergjetpt = ((TH1D *)Top->Get("h_TTTo2L2Nu_light_emergjetpt"));
    TH1D *Top_hev_emergjetpt_cutalpha = ((TH1D *)Top->Get("h_TTTo2L2Nu_hev_emergjetpt_cutalpha"));
    TH1D *Top_light_emergjetpt_cutalpha = ((TH1D *)Top->Get("h_TTTo2L2Nu_light_emergjetpt_cutalpha"));
    TH1D *Top_hev_emergjetEta = ((TH1D *)Top->Get("h_TTTo2L2Nu_hev_emergjetEta"));
    TH1D *Top_light_emergjetEta = ((TH1D *)Top->Get("h_TTTo2L2Nu_light_emergjetEta"));
    TH1D *Top_hev_emergjetEta_cutalpha = ((TH1D *)Top->Get("h_TTTo2L2Nu_hev_emergjetEta_cutalpha"));
    TH1D *Top_light_emergjetEta_cutalpha = ((TH1D *)Top->Get("h_TTTo2L2Nu_light_emergjetEta_cutalpha"));
    TH1D *Top_hev_emergjetnTrack = ((TH1D *)Top->Get("h_TTTo2L2Nu_hev_emergjetnTrack"));
    TH1D *Top_light_emergjetnTrack = ((TH1D *)Top->Get("h_TTTo2L2Nu_light_emergjetnTrack"));
    TH1D *Top_hev_emergjetnTrack_cutalpha = ((TH1D *)Top->Get("h_TTTo2L2Nu_hev_emergjetnTrack_cutalpha"));
    TH1D *Top_light_emergjetnTrack_cutalpha = ((TH1D *)Top->Get("h_TTTo2L2Nu_light_emergjetnTrack_cutalpha"));

    TFile *HTroot = new TFile("./../../../root_file/BgEstimation/ee_HT_fakeplot.root");
    TH1D *HT_hev_emergjetpt_fakeRate = ((TH1D *)HTroot->Get("h_hev_emergjetpt_fakeRate"));
    TH1D *HT_light_emergjetpt_fakeRate = ((TH1D *)HTroot->Get("h_light_emergjetpt_fakeRate"));
    TH1D *HT_hev_emergjetEta_fakeRate = ((TH1D *)HTroot->Get("h_hev_emergjetEta_fakeRate"));
    TH1D *HT_light_emergjetEta_fakeRate = ((TH1D *)HTroot->Get("h_light_emergjetEta_fakeRate"));
    TH1D *HT_hev_emergjetnTrack_fakeRate = ((TH1D *)HTroot->Get("h_hev_emergjetnTrack_fakeRate"));
    TH1D *HT_light_emergjetnTrack_fakeRate = ((TH1D *)HTroot->Get("h_light_emergjetnTrack_fakeRate"));

    

    //Top_hev_emergjetpt_cutalpha

    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(2,1);
    Top_emergjethadronflavor->SetTitle("Top process");
    Top_emergjethadronflavor->GetXaxis()->SetTitle("Jet Flavor");
    Top_emergjethadronflavor->GetYaxis()->SetTitle("N Jets");

    TH1D *h_hev_emergjetpt_fakeRate = (TH1D *)Top_hev_emergjetpt_cutalpha->Clone("h_hev_emergjetpt_fakeRate");
    h_hev_emergjetpt_fakeRate->Divide(Top_hev_emergjetpt_cutalpha, Top_hev_emergjetpt, 1, 1, "b");
    //c1->cd(1);
    //Top_hev_emergjetpt->Draw();
    //c1->cd(2);
    Top_hev_emergjetpt_cutalpha->Draw();
    TH1F *h_light_emergjetpt_fakeRate = (TH1F *)Top_light_emergjetpt_cutalpha->Clone("h_light_emergjetpt_fakeRate");
    h_light_emergjetpt_fakeRate->Divide(Top_light_emergjetpt_cutalpha, Top_light_emergjetpt, 1, 1, "b");

    TH1F *h_hev_emergjetEta_fakeRate = (TH1F *)Top_hev_emergjetEta_cutalpha->Clone("h_hev_emergjetEta_fakeRate");
    h_hev_emergjetEta_fakeRate->Divide(Top_hev_emergjetEta_cutalpha, Top_hev_emergjetEta, 1, 1, "b");

    TH1F *h_light_emergjetEta_fakeRate = (TH1F *)Top_light_emergjetEta_cutalpha->Clone("h_light_emergjetEta_fakeRate");
    h_light_emergjetEta_fakeRate->Divide(Top_light_emergjetEta_cutalpha, Top_light_emergjetEta, 1, 1, "b");

    TH1F *h_hev_emergjetnTrack_fakeRate = (TH1F *)Top_hev_emergjetnTrack_cutalpha->Clone("h_hev_emergjetnTrack_fakeRate");
    h_hev_emergjetnTrack_fakeRate->Divide(Top_hev_emergjetnTrack_cutalpha, Top_hev_emergjetnTrack, 1, 1, "b");

    TH1F *h_light_emergjetnTrack_fakeRate = (TH1F *)Top_light_emergjetnTrack_cutalpha->Clone("h_light_emergjetnTrack_fakeRate");
    h_light_emergjetnTrack_fakeRate->Divide(Top_light_emergjetnTrack_cutalpha, Top_light_emergjetnTrack, 1, 1, "b");

    h_hev_emergjetpt_fakeRate->GetXaxis()->SetTitle("P_{T}(jet)[GeV]");
    h_hev_emergjetpt_fakeRate->GetYaxis()->SetTitle("fake rate");

    h_light_emergjetpt_fakeRate->GetXaxis()->SetTitle("P_{T}(jet)[GeV]");
    h_light_emergjetpt_fakeRate->GetYaxis()->SetTitle("fake rate");

    h_hev_emergjetEta_fakeRate->GetXaxis()->SetTitle("#eta(jet)");
    h_hev_emergjetEta_fakeRate->GetYaxis()->SetTitle("fake rate");

    h_light_emergjetEta_fakeRate->GetXaxis()->SetTitle("#eta(jet)");
    h_light_emergjetEta_fakeRate->GetYaxis()->SetTitle("fake rate");

    h_hev_emergjetnTrack_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    h_hev_emergjetnTrack_fakeRate->GetYaxis()->SetTitle("fake rate");

    h_light_emergjetnTrack_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    h_light_emergjetnTrack_fakeRate->GetYaxis()->SetTitle("fake rate");

    h_hev_emergjetpt_fakeRate->SetLineWidth(2);
    h_light_emergjetpt_fakeRate->SetLineWidth(2);
    h_hev_emergjetEta_fakeRate->SetLineWidth(2);
    h_light_emergjetEta_fakeRate->SetLineWidth(2);
    h_hev_emergjetnTrack_fakeRate->SetLineWidth(2);
    h_light_emergjetnTrack_fakeRate->SetLineWidth(2);

    HT_hev_emergjetpt_fakeRate->SetLineWidth(2);
    HT_light_emergjetpt_fakeRate->SetLineWidth(2);
    HT_hev_emergjetEta_fakeRate->SetLineWidth(2);
    HT_light_emergjetEta_fakeRate->SetLineWidth(2);
    HT_hev_emergjetnTrack_fakeRate->SetLineWidth(2);
    HT_light_emergjetnTrack_fakeRate->SetLineWidth(2);

    h_hev_emergjetpt_fakeRate->SetLineColor(kRed);
    h_light_emergjetpt_fakeRate->SetLineColor(kGreen);
    h_hev_emergjetEta_fakeRate->SetLineColor(kRed);
    h_light_emergjetEta_fakeRate->SetLineColor(kGreen);
    h_hev_emergjetnTrack_fakeRate->SetLineColor(kRed);
    h_light_emergjetnTrack_fakeRate->SetLineColor(kGreen);

    HT_hev_emergjetpt_fakeRate->SetLineColor(kMagenta);
    HT_light_emergjetpt_fakeRate->SetLineColor(kCyan - 7);
    HT_hev_emergjetEta_fakeRate->SetLineColor(kMagenta);
    HT_light_emergjetEta_fakeRate->SetLineColor(kCyan - 7);
    HT_hev_emergjetnTrack_fakeRate->SetLineColor(kMagenta);
    HT_light_emergjetnTrack_fakeRate->SetLineColor(kCyan - 7);   


    //h_hev_emergjetpt_fakeRate->Draw("");
    //h_light_emergjetpt_fakeRate->Draw("same");
    //h_hev_emergjetEta_fakeRate->Draw("");
    //h_light_emergjetEta_fakeRate->Draw("same");
    //HT_hev_emergjetEta_fakeRate->Draw("same");
    //HT_light_emergjetEta_fakeRate->Draw("same");

    h_hev_emergjetnTrack_fakeRate->Draw("");
    h_light_emergjetnTrack_fakeRate->Draw("same");
    HT_hev_emergjetnTrack_fakeRate->Draw("same");
    HT_light_emergjetnTrack_fakeRate->Draw("same");
    //h_hev_emergjetnTrack_fakeRate->Draw("");
    //h_light_emergjetnTrack_fakeRate->Draw("same");

    TLegend *l1 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_hev_emergjetEta_fakeRate, "Top heavy Jet", "l");
    l1->AddEntry(h_light_emergjetEta_fakeRate, "Top light Jet", "l");
    l1->AddEntry(HT_hev_emergjetEta_fakeRate, "HT heavy Jet", "l");
    l1->AddEntry(HT_light_emergjetEta_fakeRate, "HT light Jet", "l");
    l1->Draw();

    gStyle->SetOptStat(0);
    //gPad->SetLogy();
    // DY_emergjethadronflavor->Draw();
}
