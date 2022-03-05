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

    // Top_hev_emergjetpt_cutalpha

    Top_emergjethadronflavor->SetTitle("Top process");
    Top_emergjethadronflavor->GetXaxis()->SetTitle("Jet Flavor");
    Top_emergjethadronflavor->GetYaxis()->SetTitle("N Jets");

    TH1D *Top_hev_emergjetpt_fakeRate = (TH1D *)Top_hev_emergjetpt_cutalpha->Clone("Top_hev_emergjetpt_fakeRate");
    Top_hev_emergjetpt_fakeRate->Divide(Top_hev_emergjetpt_cutalpha, Top_hev_emergjetpt, 1, 1, "b");
    // c1->cd(1);
    // Top_hev_emergjetpt->Draw();
    // c1->cd(2);
    Top_hev_emergjetpt_cutalpha->Draw();
    TH1F *Top_light_emergjetpt_fakeRate = (TH1F *)Top_light_emergjetpt_cutalpha->Clone("Top_light_emergjetpt_fakeRate");
    Top_light_emergjetpt_fakeRate->Divide(Top_light_emergjetpt_cutalpha, Top_light_emergjetpt, 1, 1, "b");

    TH1F *Top_hev_emergjetEta_fakeRate = (TH1F *)Top_hev_emergjetEta_cutalpha->Clone("Top_hev_emergjetEta_fakeRate");
    Top_hev_emergjetEta_fakeRate->Divide(Top_hev_emergjetEta_cutalpha, Top_hev_emergjetEta, 1, 1, "b");

    TH1F *Top_light_emergjetEta_fakeRate = (TH1F *)Top_light_emergjetEta_cutalpha->Clone("Top_light_emergjetEta_fakeRate");
    Top_light_emergjetEta_fakeRate->Divide(Top_light_emergjetEta_cutalpha, Top_light_emergjetEta, 1, 1, "b");

    TH1F *Top_hev_emergjetnTrack_fakeRate = (TH1F *)Top_hev_emergjetnTrack_cutalpha->Clone("Top_hev_emergjetnTrack_fakeRate");
    Top_hev_emergjetnTrack_fakeRate->Divide(Top_hev_emergjetnTrack_cutalpha, Top_hev_emergjetnTrack, 1, 1, "b");

    TH1F *Top_light_emergjetnTrack_fakeRate = (TH1F *)Top_light_emergjetnTrack_cutalpha->Clone("Top_light_emergjetnTrack_fakeRate");
    Top_light_emergjetnTrack_fakeRate->Divide(Top_light_emergjetnTrack_cutalpha, Top_light_emergjetnTrack, 1, 1, "b");

    Top_hev_emergjetpt_fakeRate->SetTitle("fake rate vs Jet PT");
    Top_hev_emergjetpt_fakeRate->GetXaxis()->SetTitle("P_{T}(jet)[GeV]");
    Top_hev_emergjetpt_fakeRate->GetYaxis()->SetTitle("fake rate");

    Top_light_emergjetpt_fakeRate->SetTitle("fake rate vs Jet PT");
    Top_light_emergjetpt_fakeRate->GetXaxis()->SetTitle("P_{T}(jet)[GeV]");
    Top_light_emergjetpt_fakeRate->GetYaxis()->SetTitle("fake rate");

    Top_hev_emergjetEta_fakeRate->SetTitle("fake rate vs Jet #eta");
    Top_hev_emergjetEta_fakeRate->GetXaxis()->SetTitle("#eta(jet)");
    Top_hev_emergjetEta_fakeRate->GetYaxis()->SetTitle("fake rate");

    Top_light_emergjetEta_fakeRate->SetTitle("fake rate vs Jet #eta");
    Top_light_emergjetEta_fakeRate->GetXaxis()->SetTitle("#eta(jet)");
    Top_light_emergjetEta_fakeRate->GetYaxis()->SetTitle("fake rate");

    Top_hev_emergjetnTrack_fakeRate->SetTitle("fake rate vs track multiplicity");
    Top_hev_emergjetnTrack_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    Top_hev_emergjetnTrack_fakeRate->GetYaxis()->SetTitle("fake rate");

    Top_light_emergjetnTrack_fakeRate->SetTitle("fake rate vs track multiplicity");
    Top_light_emergjetnTrack_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    Top_light_emergjetnTrack_fakeRate->GetYaxis()->SetTitle("fake rate");

    Top_hev_emergjetpt_fakeRate->SetLineWidth(2);
    Top_light_emergjetpt_fakeRate->SetLineWidth(2);
    Top_hev_emergjetEta_fakeRate->SetLineWidth(2);
    Top_light_emergjetEta_fakeRate->SetLineWidth(2);
    Top_hev_emergjetnTrack_fakeRate->SetLineWidth(2);
    Top_light_emergjetnTrack_fakeRate->SetLineWidth(2);

    HT_hev_emergjetpt_fakeRate->SetLineWidth(2);
    HT_light_emergjetpt_fakeRate->SetLineWidth(2);
    HT_hev_emergjetEta_fakeRate->SetLineWidth(2);
    HT_light_emergjetEta_fakeRate->SetLineWidth(2);
    HT_hev_emergjetnTrack_fakeRate->SetLineWidth(2);
    HT_light_emergjetnTrack_fakeRate->SetLineWidth(2);

    Top_hev_emergjetpt_fakeRate->SetLineColor(kRed);
    Top_light_emergjetpt_fakeRate->SetLineColor(kGreen);
    Top_hev_emergjetEta_fakeRate->SetLineColor(kRed);
    Top_light_emergjetEta_fakeRate->SetLineColor(kGreen);
    Top_hev_emergjetnTrack_fakeRate->SetLineColor(kRed);
    Top_light_emergjetnTrack_fakeRate->SetLineColor(kGreen);

    HT_hev_emergjetpt_fakeRate->SetLineColor(kMagenta);
    HT_light_emergjetpt_fakeRate->SetLineColor(kCyan - 7);
    HT_hev_emergjetEta_fakeRate->SetLineColor(kMagenta);
    HT_light_emergjetEta_fakeRate->SetLineColor(kCyan - 7);
    HT_hev_emergjetnTrack_fakeRate->SetLineColor(kMagenta);
    HT_light_emergjetnTrack_fakeRate->SetLineColor(kCyan - 7);

    // h_hev_emergjetpt_fakeRate->Draw("");
    // h_light_emergjetpt_fakeRate->Draw("same");
    // h_hev_emergjetEta_fakeRate->Draw("");
    // h_light_emergjetEta_fakeRate->Draw("same");
    // HT_hev_emergjetEta_fakeRate->Draw("same");
    // HT_light_emergjetEta_fakeRate->Draw("same");
    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(3, 2);
    c1->cd(1);
    Top_hev_emergjetnTrack_fakeRate->Draw("");
    HT_hev_emergjetnTrack_fakeRate->Draw("same");
    TLegend *l0 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_hev_emergjetnTrack_fakeRate, "Top heavy Jet", "l");
    l0->AddEntry(HT_hev_emergjetnTrack_fakeRate, "HT heavy Jet", "l");
    l0->Draw();
    c1->cd(4);
    Top_light_emergjetnTrack_fakeRate->Draw("");
    HT_light_emergjetnTrack_fakeRate->Draw("same");
    // h_hev_emergjetnTrack_fakeRate->Draw("");
    // h_light_emergjetnTrack_fakeRate->Draw("same");
    TLegend *l1 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_light_emergjetnTrack_fakeRate, "Top light Jet", "l");
    l1->AddEntry(HT_hev_emergjetnTrack_fakeRate, "HT light Jet", "l");
    l1->Draw();
    c1->cd(2);
    Top_hev_emergjetpt_fakeRate->Draw("");
    HT_hev_emergjetpt_fakeRate->Draw("same");
    TLegend *l2 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_hev_emergjetpt_fakeRate, "Top heavy Jet", "l");
    l2->AddEntry(HT_hev_emergjetpt_fakeRate, "HT heavy Jet", "l");
    l2->Draw();
    c1->cd(5);
    Top_light_emergjetpt_fakeRate->Draw("");
    HT_light_emergjetpt_fakeRate->Draw("same");
    TLegend *l3 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.04);
    l3->AddEntry(Top_light_emergjetpt_fakeRate, "Top light Jet", "l");
    l3->AddEntry(HT_light_emergjetpt_fakeRate, "HT light Jet", "l");
    l3->Draw();
    c1->cd(3);
    Top_hev_emergjetEta_fakeRate->Draw("");
    HT_hev_emergjetEta_fakeRate->Draw("same");
    TLegend *l4 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.04);
    l4->AddEntry(Top_hev_emergjetEta_fakeRate, "Top heavy Jet", "l");
    l4->AddEntry(HT_hev_emergjetEta_fakeRate, "HT heavy Jet", "l");
    l4->Draw();
    c1->cd(6);
    Top_light_emergjetEta_fakeRate->Draw("");
    HT_light_emergjetEta_fakeRate->Draw("same");
    TLegend *l5 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l5->SetBorderSize(0);
    l5->SetTextSize(0.04);
    l5->AddEntry(Top_light_emergjetEta_fakeRate, "Top light Jet", "l");
    l5->AddEntry(HT_light_emergjetEta_fakeRate, "HT light Jet", "l");
    l5->Draw();

    gStyle->SetOptStat(0);

    TFile *outFile = new TFile("./../../../root_file/BgEstimation/Clouse_test.root", "RECREATE");
    outFile->cd();
    Top_hev_emergjetnTrack_fakeRate->Write();
    HT_hev_emergjetnTrack_fakeRate->Write();
    Top_light_emergjetnTrack_fakeRate->Write();
    HT_light_emergjetnTrack_fakeRate->Write();
    outFile->Close();

}
//h_ht0_light_pred_emergjetpt->Sumw2();
//h_ht70_light_pred_emergjetpt->Sumw2();
//h_ht100_light_pred_emergjetpt->Sumw2();
//h_ht200_light_pred_emergjetpt->Sumw2();
//h_ht400_light_pred_emergjetpt->Sumw2();
//h_ht600_light_pred_emergjetpt->Sumw2();
//h_ht800_light_pred_emergjetpt->Sumw2();
//h_ht1200_light_pred_emergjetpt->Sumw2();
//h_ht2500_light_pred_emergjetpt->Sumw2();


//h_ht0_hev_pred_emergjetpt->Sumw2();
//h_ht70_hev_pred_emergjetpt->Sumw2();
//h_ht100_hev_pred_emergjetpt->Sumw2();
//h_ht200_hev_pred_emergjetpt->Sumw2();
//h_ht400_hev_pred_emergjetpt->Sumw2();
//h_ht600_hev_pred_emergjetpt->Sumw2();
//h_ht800_hev_pred_emergjetpt->Sumw2();
//h_ht1200_hev_pred_emergjetpt->Sumw2();
//h_ht2500_hev_pred_emergjetpt->Sumw2();


//h_ht0_hev_exp_emergjetpt->Sumw2();
//h_ht70_hev_exp_emergjetpt->Sumw2();
//h_ht100_hev_exp_emergjetpt->Sumw2();
//h_ht200_hev_exp_emergjetpt->Sumw2();
//h_ht400_hev_exp_emergjetpt->Sumw2();
//h_ht600_hev_exp_emergjetpt->Sumw2();
//h_ht800_hev_exp_emergjetpt->Sumw2();
//h_ht1200_hev_exp_emergjetpt->Sumw2();
//h_ht2500_hev_exp_emergjetpt->Sumw2();

//h_ht0_light_exp_emergjetpt->Sumw2();
//h_ht70_light_exp_emergjetpt->Sumw2();
//h_ht100_light_exp_emergjetpt->Sumw2();
//h_ht200_light_exp_emergjetpt->Sumw2();
//h_ht400_light_exp_emergjetpt->Sumw2();
//h_ht600_light_exp_emergjetpt->Sumw2();
//h_ht800_light_exp_emergjetpt->Sumw2();
//h_ht1200_light_exp_emergjetpt->Sumw2();
//h_ht2500_light_exp_emergjetpt->Sumw2();