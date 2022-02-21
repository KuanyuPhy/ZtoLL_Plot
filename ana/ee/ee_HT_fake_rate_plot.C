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
void ee_HT_fake_rate_plot()
{
    // setNCUStyle(true);
    TFile *DYHT = new TFile("./../../../root_file/BgEstimation/DYHT_fakerateStudy.root");
    TH1D *DY_emergjethadronflavor = ((TH1D *)DYHT->Get("h_ht0_emergjethadronflavor"));
    TH1D *DY_hev_emergjetpt = ((TH1D *)DYHT->Get("h_ht0_hev_emergjetpt"));
    TH1D *DY_light_emergjetpt = ((TH1D *)DYHT->Get("h_ht0_light_emergjetpt"));
    TH1D *DY_hev_emergjetpt_cutalpha = ((TH1D *)DYHT->Get("h_ht0_hev_emergjetpt_cutalpha"));
    TH1D *DY_light_emergjetpt_cutalpha = ((TH1D *)DYHT->Get("h_ht0_light_emergjetpt_cutalpha"));
    TH1D *DY_hev_emergjetEta = ((TH1D *)DYHT->Get("h_ht0_hev_emergjetEta"));
    TH1D *DY_light_emergjetEta = ((TH1D *)DYHT->Get("h_ht0_light_emergjetEta"));
    TH1D *DY_hev_emergjetEta_cutalpha = ((TH1D *)DYHT->Get("h_ht0_hev_emergjetEta_cutalpha"));
    TH1D *DY_light_emergjetEta_cutalpha = ((TH1D *)DYHT->Get("h_ht0_light_emergjetEta_cutalpha"));
    TH1D *DY_hev_emergjetnTrack = ((TH1D *)DYHT->Get("h_ht0_hev_emergjetnTrack"));
    TH1D *DY_light_emergjetnTrack = ((TH1D *)DYHT->Get("h_ht0_light_emergjetnTrack"));
    TH1D *DY_hev_emergjetnTrack_cutalpha = ((TH1D *)DYHT->Get("h_ht0_hev_emergjetnTrack_cutalpha"));
    TH1D *DY_light_emergjetnTrack_cutalpha = ((TH1D *)DYHT->Get("h_ht0_light_emergjetnTrack_cutalpha"));

    auto c1 = new TCanvas("c", "BPRE");
    DY_emergjethadronflavor->SetTitle("Drell-Yan process");
    DY_emergjethadronflavor->GetXaxis()->SetTitle("Jet Flavor");
    DY_emergjethadronflavor->GetYaxis()->SetTitle("N Jets");

    TH1F *h_hev_emergjetpt_fakeRate = (TH1F *)DY_hev_emergjetpt_cutalpha->Clone("h_hev_emergjetpt_fakeRate");
    h_hev_emergjetpt_fakeRate->Divide(DY_hev_emergjetpt_cutalpha, DY_hev_emergjetpt, 1, 1, "b");

    TH1F *h_light_emergjetpt_fakeRate = (TH1F *)DY_light_emergjetpt_cutalpha->Clone("h_light_emergjetpt_fakeRate");
    h_light_emergjetpt_fakeRate->Divide(DY_light_emergjetpt_cutalpha, DY_light_emergjetpt, 1, 1, "b");

    TH1F *h_hev_emergjetEta_fakeRate = (TH1F *)DY_hev_emergjetEta_cutalpha->Clone("h_hev_emergjetEta_fakeRate");
    h_hev_emergjetEta_fakeRate->Divide(DY_hev_emergjetEta_cutalpha, DY_hev_emergjetEta, 1, 1, "b");

    TH1F *h_light_emergjetEta_fakeRate = (TH1F *)DY_light_emergjetEta_cutalpha->Clone("h_light_emergjetEta_fakeRate");
    h_light_emergjetEta_fakeRate->Divide(DY_light_emergjetEta_cutalpha, DY_light_emergjetEta, 1, 1, "b");

    TH1F *h_hev_emergjetnTrack_fakeRate = (TH1F *)DY_hev_emergjetnTrack_cutalpha->Clone("h_hev_emergjetnTrack_fakeRate");
    h_hev_emergjetnTrack_fakeRate->Divide(DY_hev_emergjetnTrack_cutalpha, DY_hev_emergjetnTrack, 1, 1, "b");

    TH1F *h_light_emergjetnTrack_fakeRate = (TH1F *)DY_light_emergjetnTrack_cutalpha->Clone("h_light_emergjetnTrack_fakeRate");
    h_light_emergjetnTrack_fakeRate->Divide(DY_light_emergjetnTrack_cutalpha, DY_light_emergjetnTrack, 1, 1, "b");

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

    h_hev_emergjetpt_fakeRate->SetLineColor(kRed);
    h_light_emergjetpt_fakeRate->SetLineColor(kGreen);
    h_hev_emergjetEta_fakeRate->SetLineColor(kRed);
    h_light_emergjetEta_fakeRate->SetLineColor(kGreen);
    h_hev_emergjetnTrack_fakeRate->SetLineColor(kRed);
    h_light_emergjetnTrack_fakeRate->SetLineColor(kGreen);

    // h_hev_emergjetpt_fakeRate->Draw("");
    // h_light_emergjetpt_fakeRate->Draw("same");

    h_hev_emergjetEta_fakeRate->Draw("");
    h_light_emergjetEta_fakeRate->Draw("same");

    // h_hev_emergjetnTrack_fakeRate->Draw("");
    // h_light_emergjetnTrack_fakeRate->Draw("same");

    TLegend *l1 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_hev_emergjetEta_fakeRate, "heavy Jet", "l");
    l1->AddEntry(h_light_emergjetEta_fakeRate, "light Jet", "l");
    l1->Draw();

    gStyle->SetOptStat(0);
    // gPad->SetLogy();
    //  DY_emergjethadronflavor->Draw();
    TFile *outFile = new TFile("./../../../root_file/BgEstimation/ee_HT_fakeplot.root", "RECREATE");
    outFile->cd();
    h_hev_emergjetpt_fakeRate->Write();
    h_light_emergjetpt_fakeRate->Write();
    h_hev_emergjetEta_fakeRate->Write();
    h_light_emergjetEta_fakeRate->Write();
    h_hev_emergjetnTrack_fakeRate->Write();
    h_light_emergjetnTrack_fakeRate->Write();
    outFile->Close();

    h_hev_emergjetpt_fakeRate
    h_light_emergjetpt_fakeRate
    h_hev_emergjetEta_fakeRate 
    h_light_emergjetEta_fakeRate
    h_hev_emergjetnTrack_fakeRate
    h_light_emergjetnTrack_fakeRate

    
}
