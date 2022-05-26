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
void ee_var(TString inputfile = "./DY/ee_DY_emjet.root", TString outputfile1 = "./ee_DY_emjet.root")
{
    setNCUStyle(true);
    TFile *DYprocess = TFile::Open(inputfile);
    TFile *Topprocess = new TFile("./top/ee_Top_emjet.root");
    TFile *Dibosonprocess = new TFile("./diboson/ee_Diboson_emjet.root");
    TFile *Tribosonprocess = new TFile("./triboson/ee_Triboson_emjet.root");

    // Fake rate
    TFile *DY_half = new TFile("./top/ee_Top_emjet_half.root");
    TFile *Top_half = new TFile("./top/ee_Top_emjet_half.root");

    TFile *Sigfile = new TFile("./sig/ee_Sig_emjet.root");

    TH1D *DYmet = ((TH1D *)DYprocess->Get("h_DY_Met"));
    TH1D *Topmet = ((TH1D *)Topprocess->Get("h_Top_Met"));
    TH1D *Dibosonmet = ((TH1D *)Dibosonprocess->Get("h_diboson_Met"));
    TH1D *Tribosonmet = ((TH1D *)Tribosonprocess->Get("h_triboson_Met"));

    TH1D *DYnTracks = ((TH1D *)DYprocess->Get("h_DY_nTracks"));
    TH1D *TopnTracks = ((TH1D *)Topprocess->Get("h_Top_nTracks"));
    TH1D *DibosonnTracks = ((TH1D *)Dibosonprocess->Get("h_diboson_nTracks"));
    TH1D *TribosonnTracks = ((TH1D *)Tribosonprocess->Get("h_triboson_nTracks"));

    TH1D *DYnTracks_heavy = ((TH1D *)DYprocess->Get("h_DY_nTracks_heavy"));
    TH1D *TopnTracks_heavy = ((TH1D *)Topprocess->Get("h_Top_nTracks_heavy"));
    TH1D *DYnTracks_heavy_cut = ((TH1D *)DYprocess->Get("h_DY_nTracks_heavy_cut"));
    TH1D *TopnTracks_heavy_cut = ((TH1D *)Topprocess->Get("h_Top_nTracks_heavy_cut"));

    TH1D *DYnTracks_light = ((TH1D *)DYprocess->Get("h_DY_nTracks_light"));
    TH1D *TopnTracks_light = ((TH1D *)Topprocess->Get("h_Top_nTracks_light"));
    TH1D *DYnTracks_light_cut = ((TH1D *)DYprocess->Get("h_DY_nTracks_light_cut"));
    TH1D *TopnTracks_light_cut = ((TH1D *)Topprocess->Get("h_Top_nTracks_light_cut"));

    TH1D *DYnTracks_heavy_nogluon = ((TH1D *)DYprocess->Get("h_DY_nTracks_heavy_nogluon"));
    TH1D *DYnTracks_heavy_nogluon_cut = ((TH1D *)DYprocess->Get("h_DY_nTracks_heavy_nogluon_cut"));

    TH1D *DYnTracks_cut = ((TH1D *)DYprocess->Get("h_DY_nTracks_cut"));
    TH1D *TopnTracks_cut = ((TH1D *)Topprocess->Get("h_Top_nTracks_cut"));

    TH1D *HT_fakeRate = ((TH1D *)DYprocess->Get("HT_fakeRate"));
    TH1D *HT_heavy_fakeRate = ((TH1D *)DYprocess->Get("HT_heavy_fakeRate"));
    TH1D *HT_bjet_fakeRate = ((TH1D *)DYprocess->Get("HT_bjet_fakeRate"));

    // TH1D *HT_exclu_bjet_fakeRate = ((TH1D *)DYprocess->Get("HT_exclu_bjet_fakeRate"));
    TH1D *HT_heavy_nogluon_fakeRate = ((TH1D *)DYprocess->Get("HT_heavy_nogluon_fakeRate"));
    TH1D *HT_light_fakeRate = ((TH1D *)DYprocess->Get("HT_light_fakeRate"));
    TH1D *Top_fakeRate = ((TH1D *)Topprocess->Get("Top_fakeRate"));
    TH1D *Top_heavy_fakeRate = ((TH1D *)Topprocess->Get("Top_heavy_fakeRate"));
    TH1D *Top_bjet_fakeRate = ((TH1D *)Topprocess->Get("Top_bjet_fakeRate"));

    // TH1D *Top_exclu_bjet_fakeRate = ((TH1D *)Topprocess->Get("Top_exclu_bjet_fakeRate"));
    TH1D *Top_light_fakeRate = ((TH1D *)Topprocess->Get("Top_light_fakeRate"));

    // For C jet
    TH1D *HT_cjet_fakeRate = ((TH1D *)DYprocess->Get("HT_cjet_fakeRate"));
    TH1D *HT_nTracks_cjet = ((TH1D *)DYprocess->Get("h_DY_nTracks_cjet"));
    TH1D *HT_nTracks_cjet_cut = ((TH1D *)DYprocess->Get("h_DY_nTracks_cjet_cut"));
    TH1D *Top_cjet_fakeRate = ((TH1D *)Topprocess->Get("Top_cjet_fakeRate"));
    TH1D *Top_nTracks_cjet = ((TH1D *)Topprocess->Get("h_Top_nTracks_cjet"));
    TH1D *Top_nTracks_cjet_cut = ((TH1D *)Topprocess->Get("h_Top_nTracks_cjet_cut"));

    // For 2D IP
    TH1D *HT_IP2D = ((TH1D *)DYprocess->Get("h_DY_IP2D"));
    TH1D *Top_IP2D = ((TH1D *)Topprocess->Get("h_Top_IP2D"));
    TH1D *Diboson_IP2D = ((TH1D *)Dibosonprocess->Get("h_diboson_IP2D"));
    TH1D *Triboson_IP2D = ((TH1D *)Tribosonprocess->Get("h_triboson_IP2D"));

    // For 3D sig
    TH1D *HT_3Dsig = ((TH1D *)DYprocess->Get("h_DY_Chi3Dlog"));
    TH1D *Top_3Dsig = ((TH1D *)Topprocess->Get("h_Top_Chi3Dlog"));
    TH1D *Diboson_3Dsig = ((TH1D *)Dibosonprocess->Get("h_diboson_Chi3Dlog"));
    TH1D *Triboson_3Dsig = ((TH1D *)Tribosonprocess->Get("h_triboson_Chi3Dlog"));
    TH1D *Sig1_3Dsig = ((TH1D *)Sigfile->Get("h_Sig1_Chi3Dlog"));
    TH1D *Sig50_3Dsig = ((TH1D *)Sigfile->Get("h_Sig50_Chi3Dlog"));
    TH1D *Sig150_3Dsig = ((TH1D *)Sigfile->Get("h_Sig150_Chi3Dlog"));

    DYmet->SetLineWidth(2);
    DYnTracks->SetLineWidth(2);
    Topmet->SetLineWidth(2);
    TopnTracks->SetLineWidth(2);
    Dibosonmet->SetLineWidth(2);
    DibosonnTracks->SetLineWidth(2);
    Tribosonmet->SetLineWidth(2);
    TribosonnTracks->SetLineWidth(2);
    DYnTracks_heavy->SetLineWidth(2);
    HT_bjet_fakeRate->SetLineWidth(2);
    HT_cjet_fakeRate->SetLineWidth(2);
    HT_nTracks_cjet->SetLineWidth(2);
    HT_nTracks_cjet_cut->SetLineWidth(2);
    // HT_exclu_bjet_fakeRate->SetLineWidth(2);
    TopnTracks_heavy->SetLineWidth(2);
    Top_bjet_fakeRate->SetLineWidth(2);
    Top_cjet_fakeRate->SetLineWidth(2);
    Top_nTracks_cjet->SetLineWidth(2);
    Top_nTracks_cjet_cut->SetLineWidth(2);
    // Top_exclu_bjet_fakeRate->SetLineWidth(2);
    DYnTracks_heavy_nogluon->SetLineWidth(2);
    DYnTracks_heavy_nogluon_cut->SetLineWidth(2);
    DYnTracks_heavy_cut->SetLineWidth(2);
    TopnTracks_heavy_cut->SetLineWidth(2);

    DYnTracks_light->SetLineWidth(2);
    TopnTracks_light->SetLineWidth(2);
    DYnTracks_light_cut->SetLineWidth(2);
    TopnTracks_light_cut->SetLineWidth(2);

    DYnTracks_cut->SetLineWidth(2);
    TopnTracks_cut->SetLineWidth(2);

    HT_fakeRate->SetLineWidth(2);
    HT_heavy_nogluon_fakeRate->SetLineWidth(2);
    HT_heavy_fakeRate->SetLineWidth(2);
    HT_light_fakeRate->SetLineWidth(2);
    Top_fakeRate->SetLineWidth(2);
    Top_heavy_fakeRate->SetLineWidth(2);
    Top_light_fakeRate->SetLineWidth(2);

    HT_IP2D->SetLineWidth(2);
    Top_IP2D->SetLineWidth(2);
    Diboson_IP2D->SetLineWidth(2);
    Triboson_IP2D->SetLineWidth(2);
    HT_3Dsig->SetLineWidth(2);
    Top_3Dsig->SetLineWidth(2);
    Diboson_3Dsig->SetLineWidth(2);
    Triboson_3Dsig->SetLineWidth(2);

    Sig1_3Dsig->SetLineWidth(2);
    Sig50_3Dsig->SetLineWidth(2);
    Sig150_3Dsig->SetLineWidth(2);

    // HT_heavy_nogluon_fakeRate->Draw();

    DYmet->SetFillColor(kOrange - 3);
    DYnTracks->SetFillColor(kOrange - 3);
    DYnTracks_heavy->SetFillColor(kOrange - 3);
    DYnTracks_light->SetFillColor(kOrange - 3);
    DYnTracks_heavy_cut->SetFillColor(kOrange - 3);
    DYnTracks_light_cut->SetFillColor(kOrange - 3);
    DYnTracks_cut->SetFillColor(kOrange - 3);
    HT_IP2D->SetFillColor(kOrange - 3);
    // HT_3Dsig->SetFillColor(kOrange - 3);
    //  DYnTracks_heavy_nogluon->SetFillColor(kOrange - 3);
    DYnTracks->SetFillStyle(3001);
    DYnTracks_heavy->SetFillStyle(3001);
    DYnTracks_light->SetFillStyle(3001);
    DYnTracks_heavy_cut->SetFillStyle(3001);
    DYnTracks_light_cut->SetFillStyle(3001);
    DYnTracks_heavy_nogluon->SetFillStyle(3001);
    DYnTracks_cut->SetFillStyle(3001);

    DYmet->SetFillStyle(3001);
    DYmet->SetLineColor(kOrange - 3);
    DYnTracks_cut->SetLineColor(kOrange - 3);
    DYnTracks_heavy->SetLineColor(kOrange - 3);
    DYnTracks_light->SetLineColor(kOrange - 3);
    DYnTracks_light_cut->SetLineColor(kOrange - 3);
    DYnTracks_heavy_cut->SetLineColor(kOrange - 3);
    HT_IP2D->SetLineColor(kOrange - 3);
    HT_3Dsig->SetLineColor(kOrange - 3);
    // DYnTracks_heavy_nogluon->SetLineColor(kOrange - 3);
    HT_fakeRate->SetLineColor(kOrange - 3);
    HT_bjet_fakeRate->SetLineColor(kOrange - 3);
    HT_cjet_fakeRate->SetLineColor(kOrange - 3);
    HT_nTracks_cjet->SetLineColor(kOrange - 3);
    HT_nTracks_cjet_cut->SetLineColor(kOrange - 3);
    // HT_exclu_bjet_fakeRate->SetLineColor(kOrange - 3);
    HT_heavy_fakeRate->SetLineColor(kOrange - 3);
    HT_light_fakeRate->SetLineColor(kOrange - 3);
    DYnTracks->SetLineColor(kOrange - 3);
    Topmet->SetFillColor(kGreen + 3);
    TopnTracks->SetFillColor(kGreen + 3);
    TopnTracks_heavy->SetFillColor(kGreen + 3);
    TopnTracks_light->SetFillColor(kGreen + 3);
    TopnTracks_heavy_cut->SetFillColor(kGreen + 3);
    TopnTracks_light_cut->SetFillColor(kGreen + 3);
    TopnTracks_cut->SetFillColor(kGreen + 3);
    Top_IP2D->SetFillColor(kGreen + 3);
    // Top_3Dsig->SetFillColor(kGreen + 3);
    Topmet->SetFillStyle(3001);
    TopnTracks->SetFillStyle(3001);
    TopnTracks_heavy->SetFillStyle(3001);
    TopnTracks_light->SetFillStyle(3001);
    TopnTracks_heavy_cut->SetFillStyle(3001);
    TopnTracks_light_cut->SetFillStyle(3001);
    TopnTracks_cut->SetFillStyle(3001);
    Topmet->SetLineColor(kGreen + 3);
    TopnTracks->SetLineColor(kGreen + 3);
    TopnTracks_cut->SetLineColor(kGreen + 3);
    TopnTracks_heavy->SetLineColor(kGreen + 3);
    Top_bjet_fakeRate->SetLineColor(kGreen + 3);
    Top_cjet_fakeRate->SetLineColor(kGreen + 3);
    Top_nTracks_cjet->SetLineColor(kGreen + 3);
    Top_nTracks_cjet_cut->SetLineColor(kGreen + 3);
    // Top_exclu_bjet_fakeRate->SetLineColor(kGreen + 3);
    TopnTracks_light->SetLineColor(kGreen + 3);
    TopnTracks_heavy_cut->SetLineColor(kGreen + 3);
    TopnTracks_light_cut->SetLineColor(kGreen + 3);
    Top_fakeRate->SetLineColor(kGreen + 3);
    Top_heavy_fakeRate->SetLineColor(kGreen + 3);
    Top_bjet_fakeRate->SetLineColor(kGreen + 3);
    Top_light_fakeRate->SetLineColor(kGreen + 3);
    Top_IP2D->SetLineColor(kGreen + 3);
    Top_3Dsig->SetLineColor(kGreen + 3);

    Dibosonmet->SetFillColor(kAzure + 7);
    DibosonnTracks->SetFillColor(kAzure + 7);
    Dibosonmet->SetFillStyle(3001);
    DibosonnTracks->SetFillStyle(3001);
    Dibosonmet->SetLineColor(kAzure + 7);
    DibosonnTracks->SetLineColor(kAzure + 7);
    Diboson_IP2D->SetLineColor(kAzure + 7);
    Diboson_3Dsig->SetLineColor(kAzure + 7);
    Diboson_IP2D->SetFillColor(kAzure + 7);
    // Diboson_3Dsig->SetFillColor(kAzure + 7);

    DYnTracks_heavy_nogluon->SetLineColor(kAzure + 7);
    DYnTracks_heavy_nogluon_cut->SetLineColor(kAzure + 7);
    HT_heavy_nogluon_fakeRate->SetLineColor(kAzure + 7);
    DYnTracks_heavy_nogluon->SetFillColor(kAzure + 7);
    DYnTracks_heavy_nogluon_cut->SetFillColor(kAzure + 7);
    Tribosonmet->SetFillColor(kMagenta - 3);
    TribosonnTracks->SetFillColor(kMagenta - 3);
    Tribosonmet->SetLineColor(kMagenta - 3);
    TribosonnTracks->SetLineColor(kMagenta - 3);
    Triboson_IP2D->SetLineColor(kMagenta - 3);
    Triboson_3Dsig->SetLineColor(kMagenta - 3);
    Triboson_IP2D->SetFillColor(kMagenta - 3);
    // Triboson_3Dsig->SetFillColor(kMagenta - 3);

    Sig1_3Dsig->SetLineColor(kRed);
    Sig50_3Dsig->SetLineColor(kBlue);
    Sig150_3Dsig->SetLineColor(kBlack);

    DYnTracks_heavy_nogluon->SetFillStyle(3001);
    DYnTracks_heavy_nogluon_cut->SetFillStyle(3001);
    Tribosonmet->SetFillStyle(3001);
    TribosonnTracks->SetFillStyle(3001);

    auto c1 = new TCanvas("c1", "", 1000, 1000);
    /*
    //--------------
    //     3DSig
    //--------------
    Sig1_3Dsig->GetXaxis()->SetTitle("log_{10}(3Dsig)");
    Sig1_3Dsig->GetYaxis()->SetTitle("nTracks/Normalized");
    Triboson_3Dsig->GetXaxis()->SetTitle("log_{10}(3Dsig)");
    Triboson_3Dsig->GetYaxis()->SetTitle("nTracks/Normalized");
    Triboson_3Dsig->GetXaxis()->SetRangeUser(-2, 5);
    Triboson_3Dsig->DrawNormalized("hist ");
    Sig1_3Dsig->DrawNormalized("hist same");
    Sig50_3Dsig->DrawNormalized("hist same");
    Sig150_3Dsig->DrawNormalized("hist same");
    HT_3Dsig->DrawNormalized("hist same");
    Top_3Dsig->DrawNormalized("hist same");
    Diboson_3Dsig->DrawNormalized("hist same");

    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(Sig1_3Dsig, "ctau=1mm m_{x^{2}}=1", "l");
    l1->AddEntry(Sig50_3Dsig, "ctau=10mm m_{x^{2}}=50", "l");
    l1->AddEntry(Sig150_3Dsig, "ctau=1mm m_{x^{2}}=150", "l");
    l1->AddEntry(HT_3Dsig, "Drell-Yan", "l");
    l1->AddEntry(Top_3Dsig, "Top process", "l");
    l1->AddEntry(Diboson_3Dsig, "Diboson process", "l");
    l1->AddEntry(Triboson_3Dsig, "Triboson process", "l");
    l1->Draw();
    c1->SaveAs("3Dsig.png");
    */
    //------------------
    //     fake rate
    //------------------
    // 1. no flavor
    
    HT_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_fakeRate->Draw();
    Top_fakeRate->Draw("same");
    TLegend *l0 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(HT_fakeRate, "Drell-Yan", "l");
    l0->AddEntry(Top_fakeRate, "Top process", "l");
    l0->Draw();
    c1->SaveAs("fakerate.png");
    // 2. heavy light flavor
    /*
    c1->Divide(2, 1);
    c1->cd(1);
    HT_heavy_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_heavy_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_heavy_fakeRate->Draw();
    Top_heavy_fakeRate->Draw("same");
    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(HT_heavy_fakeRate, "Drell-Yan heavy", "l");
    l1->AddEntry(Top_heavy_fakeRate, "Top process heavy", "l");
    l1->Draw();
    c1->cd(2);
    HT_light_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_light_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_light_fakeRate->Draw();
    Top_light_fakeRate->Draw("same");
    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(HT_light_fakeRate, "Drell-Yan light", "l");
    l2->AddEntry(Top_light_fakeRate, "Top process light", "l");
    l2->Draw();
    c1->SaveAs("h_l_fakerate.png");
    */
    /*
    // 3. b, c light flavor
    c1->Divide(3, 1);
    c1->cd(1);
    HT_bjet_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_bjet_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_bjet_fakeRate->Draw();
    Top_bjet_fakeRate->Draw("same");
    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(HT_bjet_fakeRate, "Drell-Yan b jet", "l");
    l2->AddEntry(Top_bjet_fakeRate, "Top process b jet", "l");
    l2->Draw();
    c1->cd(2);
    HT_cjet_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_cjet_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_cjet_fakeRate->Draw();
    Top_cjet_fakeRate->Draw("same");
    TLegend *l3 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.03);
    l3->AddEntry(HT_cjet_fakeRate, "Drell-Yan c jet", "l");
    l3->AddEntry(Top_cjet_fakeRate, "Top process c jet", "l");
    l3->Draw();
    c1->cd(3);
    HT_light_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_light_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_light_fakeRate->Draw();
    Top_light_fakeRate->Draw("same");
    TLegend *l4 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.03);
    l4->AddEntry(HT_light_fakeRate, "Drell-Yan light", "l");
    l4->AddEntry(Top_light_fakeRate, "Top process light", "l");
    l4->Draw();
    */
    
    /*
    DYnTracks->GetXaxis()->SetTitle("Jet track multiplicity");
    DYnTracks->GetYaxis()->SetTitle("Normalized");
    DYnTracks_cut->GetXaxis()->SetTitle("Jet track multiplicity");
    DYnTracks_cut->GetYaxis()->SetTitle("Normalized");
    DYnTracks_heavy_nogluon->GetXaxis()->SetTitle("Jet track multiplicity");
    DYnTracks_heavy_nogluon->GetYaxis()->SetTitle("Normalized");
    HT_heavy_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_light_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_bjet_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_cjet_fakeRate->GetYaxis()->SetTitle("fake rate");
    // HT_exclu_bjet_fakeRate->GetYaxis()->SetTitle("fake rate");
    HT_bjet_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_cjet_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    // HT_exclu_bjet_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_heavy_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");
    HT_light_fakeRate->GetXaxis()->SetTitle("Jet track multiplicity");

    c1->Divide(2, 1);
    c1->cd(1);
    */
    /*
    HT_bjet_fakeRate->Draw();
    Top_bjet_fakeRate->Draw("same");
    TLegend *l0 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(HT_bjet_fakeRate, "Drell-Yan (hadronflavor == 5)", "l");
    l0->AddEntry(Top_bjet_fakeRate, "Top process (hadronflavor == 5)", "l");
    l0->Draw();
    c1->cd(2);
    HT_cjet_fakeRate->Draw();
    Top_cjet_fakeRate->Draw("same");
    TLegend *l4 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.03);
    l4->AddEntry(HT_cjet_fakeRate, "Drell-Yan (hadronflavor == 4)", "l");
    l4->AddEntry(Top_cjet_fakeRate, "Top process (hadronflavor == 4)", "l");
    l4->Draw();
    */
    /*
    HT_heavy_fakeRate->Draw(" ");
    HT_heavy_nogluon_fakeRate->Draw("same");
    Top_heavy_fakeRate->Draw("same");
    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(HT_heavy_nogluon_fakeRate, "Drell-Yan heavy (without gluon)", "l");
    l2->AddEntry(HT_heavy_fakeRate, "Drell-Yan heavy", "l");
    l2->AddEntry(Top_heavy_fakeRate, "Top process heavy", "l");
    // l1->AddEntry(DibosonnTracks, "Diboson process", "l");
    // l1->AddEntry(TribosonnTracks, "Triboson process", "l");
    l2->Draw();
    c1->cd(2);
    HT_light_fakeRate->Draw(" ");
    Top_light_fakeRate->Draw(" same");
    // DYnTracks_heavy_nogluon->Draw("hist same");
    // TopnTracks_heavy->DrawNormalized("hist same");
    // DibosonnTracks->DrawNormalized("hist same");
    // TribosonnTracks->DrawNormalized("hist same");
    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    // l1->AddEntry(DYnTracks_heavy_nogluon, "Drell-Yan heavy (without gluon)", "l");
    l1->AddEntry(HT_light_fakeRate, "Drell-Yan light", "l");
    l1->AddEntry(Top_light_fakeRate, "Top process light", "l");
    // l1->AddEntry(DibosonnTracks, "Diboson process", "l");
    // l1->AddEntry(TribosonnTracks, "Triboson process", "l");
    l1->Draw();
    */
    // DYmet->SetTitle("Met (Drell-Yan process)");
    // DYmet->Draw("hist");
    /*
     THStack *hs = new THStack("hs", "Stacked Met");

     hs->Add(Tribosonmet);
     hs->Add(DYmet);
     hs->Add(Topmet);
     hs->Add(Dibosonmet);

     hs->Draw("nostack hist");
    */
    /*
     TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
     l1->SetBorderSize(0);
     l1->SetTextSize(0.03);
     l1->AddEntry(DYmet, "Drell-Yan", "l");
     l1->AddEntry(Topmet, "Top process", "l");
     l1->AddEntry(Dibosonmet, "Diboson process", "l");
     l1->AddEntry(Tribosonmet, "Triboson process", "l");
     l1->Draw();

     c1->cd(2);
     Topmet->SetTitle("Met (Top process)");
     Topmet->Draw("hist");
     c1->cd(3);
     Dibosonmet->SetTitle("Met (Diboson process)");
     Dibosonmet->Draw("hist");
     c1->cd(4);
     Tribosonmet->SetTitle("Met (Triboson process)");
     Tribosonmet->Draw("hist");
    */
    /*
        c1->cd(2);
        DYnTracks->DrawNormalized("hist");

        c1->cd(3);
        TopnTracks->GetXaxis()->SetTitle("Jet track multiplicity");
        TopnTracks->GetYaxis()->SetTitle("Normalized");
        TopnTracks->DrawNormalized("hist");

        c1->cd(4);
        DibosonnTracks->GetXaxis()->SetTitle("Jet track multiplicity");
        DibosonnTracks->GetYaxis()->SetTitle("Normalized");
        DibosonnTracks->DrawNormalized("hist");
    */
    /*
     HT_nTracks_cjet->DrawNormalized("");
     Top_nTracks_cjet->DrawNormalized("same");
     TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
     l1->SetBorderSize(0);
     l1->SetTextSize(0.03);
     l1->AddEntry(HT_nTracks_cjet, "Drell-Yan (c jet)", "l");
     l1->AddEntry(Top_nTracks_cjet, "Top process(c jet) ", "l");
     l1->Draw();
     c1->cd(2);
     HT_nTracks_cjet_cut->DrawNormalized("");
     Top_nTracks_cjet_cut->DrawNormalized("same");
     gStyle->SetOptStat(0);
     */
}
