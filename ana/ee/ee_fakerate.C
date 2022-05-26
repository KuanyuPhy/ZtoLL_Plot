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
#include "./../lib/UserColorindex.h"
void ee_fakerate()
{

    TFile *fakeRate = new TFile("./../../../../root_file/BgEstimation/Clouse_test.root");
    TFile *HT_fakeRatenog = new TFile("./../../../../root_file/BgEstimation/DYHT_fakerateStudy_v2.root");
    TFile *Top_fakeRatenog = new TFile("./../../../../root_file/BgEstimation/Top_fakerateStudy.root");

    TH1F *HT_hev_fakerate_ntr = ((TH1F *)fakeRate->Get("DY_hev_emergjetnTrack_fakeRate"));
    TH1F *HT_hev_fakerate_ntr_nog = ((TH1F *)HT_fakeRatenog->Get("DY_hev_emergjetnTrack_nog_fakeRate"));
    TH1F *HT_light_fakerate_ntr = ((TH1F *)fakeRate->Get("DY_light_emergjetnTrack_fakeRate"));

    TH1F *HT_hev_barr_fakerate_ntr = ((TH1F *)fakeRate->Get("DY_hev_barr_emergjetnTrack_fakeRate"));
    TH1F *HT_hev_barr_fakerate_ntr_nog = ((TH1F *)HT_fakeRatenog->Get("DY_hev_barr_emergjetnTrack_nog_fakeRate"));
    TH1F *HT_light_barr_fakerate_ntr = ((TH1F *)fakeRate->Get("DY_light_barr_emergjetnTrack_fakeRate"));

    TH1F *HT_hev_end_fakerate_ntr = ((TH1F *)fakeRate->Get("DY_hev_end_emergjetnTrack_fakeRate"));
    TH1F *HT_hev_end_fakerate_ntr_nog = ((TH1F *)HT_fakeRatenog->Get("DY_hev_end_emergjetnTrack_nog_fakeRate"));
    TH1F *HT_light_end_fakerate_ntr = ((TH1F *)fakeRate->Get("DY_light_end_emergjetnTrack_fakeRate"));

    TH1F *Top_hev_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_hev_emergjetnTrack_fakeRate"));
    TH1F *Top_light_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_light_emergjetnTrack_fakeRate"));

    TH1F *Top_hev_barr_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_hev_barr_emergjetnTrack_fakeRate"));
    TH1F *Top_light_barr_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_light_barr_emergjetnTrack_fakeRate"));

    TH1F *Top_hev_end_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_hev_end_emergjetnTrack_fakeRate"));
    TH1F *Top_light_end_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_light_end_emergjetnTrack_fakeRate"));

    TH1F *h_TTTo2L2Nu_hev_emergjetnTrack_nog = ((TH1F *)Top_fakeRatenog->Get("h_TTTo2L2Nu_hev_emergjetnTrack_nog"));
    TH1F *h_TTTo2L2Nu_hev_emergjetnTrack_cutalpha_nog = ((TH1F *)Top_fakeRatenog->Get("h_TTTo2L2Nu_hev_emergjetnTrack_cutalpha_nog"));
    TH1F *h_TTTo2L2Nu_hev_barr_emergjetnTrack_nog = ((TH1F *)Top_fakeRatenog->Get("h_TTTo2L2Nu_hev_barr_emergjetnTrack_nog"));
    TH1F *h_TTTo2L2Nu_hev_barr_emergjetnTrack_cutalpha_nog = ((TH1F *)Top_fakeRatenog->Get("h_TTTo2L2Nu_hev_barr_emergjetnTrack_cutalpha_nog"));
    TH1F *h_TTTo2L2Nu_hev_end_emergjetnTrack_nog = ((TH1F *)Top_fakeRatenog->Get("h_TTTo2L2Nu_hev_end_emergjetnTrack_nog"));
    TH1F *h_TTTo2L2Nu_hev_end_emergjetnTrack_cutalpha_nog = ((TH1F *)Top_fakeRatenog->Get("h_TTTo2L2Nu_hev_end_emergjetnTrack_cutalpha_nog"));

    TH1F *Top_hev_fakerate_ntr_nog = (TH1F *)h_TTTo2L2Nu_hev_emergjetnTrack_cutalpha_nog->Clone("Top_hev_fakerate_ntr_nog");
    Top_hev_fakerate_ntr_nog->Divide(Top_hev_fakerate_ntr_nog, h_TTTo2L2Nu_hev_emergjetnTrack_nog, 1, 1, "b");

    TH1F *Top_hev_barr_fakerate_ntr_nog = (TH1F *)h_TTTo2L2Nu_hev_barr_emergjetnTrack_cutalpha_nog->Clone("Top_hev_barr_fakerate_ntr_nog");
    Top_hev_barr_fakerate_ntr_nog->Divide(Top_hev_barr_fakerate_ntr_nog, h_TTTo2L2Nu_hev_barr_emergjetnTrack_nog, 1, 1, "b");

    TH1F *Top_hev_end_fakerate_ntr_nog = (TH1F *)h_TTTo2L2Nu_hev_end_emergjetnTrack_cutalpha_nog->Clone("Top_hev_end_fakerate_ntr_nog");
    Top_hev_end_fakerate_ntr_nog->Divide(Top_hev_end_fakerate_ntr_nog, h_TTTo2L2Nu_hev_end_emergjetnTrack_nog, 1, 1, "b");

    Top_hev_fakerate_ntr_nog->SetLineWidth(2);
    Top_hev_barr_fakerate_ntr_nog->SetLineWidth(2);

    Top_hev_end_fakerate_ntr->SetLineWidth(2);
    Top_hev_end_fakerate_ntr_nog->SetLineWidth(2);
    HT_hev_end_fakerate_ntr->SetLineWidth(2);

    Top_light_end_fakerate_ntr->SetLineWidth(2);
    HT_light_end_fakerate_ntr->SetLineWidth(2);

    Top_hev_barr_fakerate_ntr->SetLineColor(kGlobalColor.MIZUASAGI);
    Top_hev_barr_fakerate_ntr_nog->SetLineColor(kGlobalColor.KARIYASU);
    HT_hev_barr_fakerate_ntr->SetLineColor(kGlobalColor.JINZAMOMI);
    Top_hev_end_fakerate_ntr->SetLineColor(kGlobalColor.MIZUASAGI);
    Top_hev_end_fakerate_ntr_nog->SetLineColor(kGlobalColor.KARIYASU);
    HT_hev_end_fakerate_ntr->SetLineColor(kGlobalColor.JINZAMOMI);

    Top_light_barr_fakerate_ntr->SetLineColor(kGlobalColor.SHIRACHA);

    HT_light_barr_fakerate_ntr->SetLineColor(kGlobalColor.MATSUBA);
    Top_light_end_fakerate_ntr->SetLineColor(kGlobalColor.SHIRACHA);
    HT_light_end_fakerate_ntr->SetLineColor(kGlobalColor.MATSUBA);

    Top_hev_barr_fakerate_ntr->SetTitle("fakerate vs Track multiplicity (barrl cap)");
    Top_hev_barr_fakerate_ntr->GetYaxis()->SetTitle("fake rate");
    Top_hev_barr_fakerate_ntr->GetXaxis()->SetTitle("Trackmultiplicity");

    Top_hev_end_fakerate_ntr->SetTitle("fakerate vs Track multiplicity (end cap)");
    Top_hev_end_fakerate_ntr->GetYaxis()->SetTitle("fake rate");
    Top_hev_end_fakerate_ntr->GetXaxis()->SetTitle("Trackmultiplicity");

    Top_light_barr_fakerate_ntr->SetTitle("fakerate vs Track multiplicity (barrl cap)");
    Top_light_barr_fakerate_ntr->GetYaxis()->SetTitle("fake rate");
    Top_light_barr_fakerate_ntr->GetXaxis()->SetTitle("Trackmultiplicity");

    Top_light_end_fakerate_ntr->SetTitle("fakerate vs Track multiplicity (end cap)");
    Top_light_end_fakerate_ntr->GetYaxis()->SetTitle("fake rate");
    Top_light_end_fakerate_ntr->GetXaxis()->SetTitle("Trackmultiplicity");

    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(1, 2);
    c1->cd(1);
    Top_hev_barr_fakerate_ntr->Draw();
    Top_hev_barr_fakerate_ntr_nog->Draw("same");
    HT_hev_barr_fakerate_ntr->Draw("same");
    HT_hev_barr_fakerate_ntr_nog->Draw("same");
    TLegend *l0 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(HT_hev_barr_fakerate_ntr, "HT hev", "l");
    l0->AddEntry(Top_hev_barr_fakerate_ntr, "Top hev", "l");
    l0->AddEntry(HT_hev_barr_fakerate_ntr_nog, "HT hev (without guon)", "l");
    l0->AddEntry(Top_hev_barr_fakerate_ntr_nog, "Top hev (without guon)", "l");
    l0->Draw();
    gStyle->SetOptStat(0);
    /*
        c1->cd(3);
        Top_light_barr_fakerate_ntr->Draw();
        HT_light_barr_fakerate_ntr->Draw("same");
        TLegend *l1 = new TLegend(0.6, 0.65, 0.80, 0.85);
        l1->SetBorderSize(0);
        l1->SetTextSize(0.04);
        l1->AddEntry(Top_light_barr_fakerate_ntr, "Top light", "l");
        l1->AddEntry(HT_light_barr_fakerate_ntr, "HT light", "l");
        l1->Draw();
        gStyle->SetOptStat(0);
    */
    c1->cd(2);
    Top_hev_end_fakerate_ntr->Draw();
    Top_hev_end_fakerate_ntr_nog->Draw("same");
    HT_hev_end_fakerate_ntr->Draw("same");
    HT_hev_end_fakerate_ntr_nog->Draw("same");
    TLegend *l3 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.04);
    l3->AddEntry(HT_hev_end_fakerate_ntr, "HT hev", "l");
    l3->AddEntry(Top_hev_end_fakerate_ntr, "Top hev", "l");
    l3->AddEntry(HT_hev_end_fakerate_ntr_nog, "HT hev (without guon)", "l");
    l3->AddEntry(Top_hev_end_fakerate_ntr_nog, "Top hev (without guon)", "l");
    l3->Draw();
    gStyle->SetOptStat(0);
    /*
    c1->cd(4);
    Top_light_end_fakerate_ntr->Draw();
    HT_light_end_fakerate_ntr->Draw("same");
    TLegend *l4 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.04);
    l4->AddEntry(Top_light_end_fakerate_ntr, "Top light", "l");
    l4->AddEntry(HT_light_end_fakerate_ntr, "HT light", "l");
    l4->Draw();
    gStyle->SetOptStat(0);
    */
}

int main(int argc, char *argv[])
{
    ee_fakerate();
}