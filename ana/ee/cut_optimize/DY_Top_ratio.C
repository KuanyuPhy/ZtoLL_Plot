#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <TH3D.h>
#include <TROOT.h>
#include <TCanvas.h>
 
#include <TLatex.h>
#include <TAxis.h>
#include <TLine.h>
#include <TH1D.h>
#include <THStack.h>
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "./../../lib/Cross_section.h"
#include "./../../lib/setNCUStyle.C"
using namespace std;

float getRMS(vector<float> Var_value)
{
    float Sum = 0.;
    float Sumdev = 0.;
    for (auto i : Var_value)
    {
        Sum = Sum + i;
    }
    float mean = Sum / Var_value.size();
    // Calculate sum deviation from mean
    for (auto i : Var_value)
    {
        Sumdev = Sumdev + pow(i - mean, 2);
    }
    float RMSvalue = sqrt(Sumdev / Var_value.size());

    // float RMSvalue;
    return RMSvalue;
}

void DY_Top_ratio(TString inputfile = "./DY/ee_DY_emjet.root", TString outputfile1 = "./ee_DY_emjet.root")
{
    setNCUStyle(true);
    TFile *DYprocess = TFile::Open(inputfile);
    TFile *Topprocess = new TFile("./top/ee_Top_emjet.root");

    TH1D *DYmet = ((TH1D *)DYprocess->Get("h_DY_Met"));
    TH1D *Topmet = ((TH1D *)Topprocess->Get("h_Top_Met"));

    TH1D *HT_fakeRate = ((TH1D *)DYprocess->Get("HT_fakeRate"));
    TH1D *HT_heavy_fakeRate = ((TH1D *)DYprocess->Get("HT_heavy_fakeRate"));
    TH1D *HT_heavy_nogluon_fakeRate = ((TH1D *)DYprocess->Get("HT_heavy_nogluon_fakeRate"));
    TH1D *HT_bjet_fakeRate = ((TH1D *)DYprocess->Get("HT_bjet_fakeRate"));
    TH1D *HT_cjet_fakeRate = ((TH1D *)DYprocess->Get("HT_cjet_fakeRate"));
    TH1D *HT_light_fakeRate = ((TH1D *)DYprocess->Get("HT_light_fakeRate"));

    TH1D *DYnTracks = ((TH1D *)DYprocess->Get("h_DY_nTracks"));
    TH1D *HT_nTracks_bjet = ((TH1D *)DYprocess->Get("h_DY_nTracks_bjet"));
    TH1D *HT_nTracks_cjet = ((TH1D *)DYprocess->Get("h_DY_nTracks_cjet"));

    TH1D *DYnTracks_heavy = ((TH1D *)DYprocess->Get("h_DY_nTracks_heavy"));
    TH1D *DYnTracks_heavy_nogluon = ((TH1D *)DYprocess->Get("h_DY_nTracks_heavy_nogluon"));
    TH1D *HT_nTracks_lightjet = ((TH1D *)DYprocess->Get("h_DY_nTracks_light"));

    // Jet Pt, eta
    TH1D *HT_JetPt_bjet = ((TH1D *)DYprocess->Get("h_DY_JetPt_bjet"));
    TH1D *HT_JetEta_bjet = ((TH1D *)DYprocess->Get("h_DY_JetEta_bjet"));
    TH1D *HT_alpha3D_bjet = ((TH1D *)DYprocess->Get("h_DY_alpha3D_bjet"));

    TH1D *HT_JetPt_cjet = ((TH1D *)DYprocess->Get("h_DY_JetPt_cjet"));
    TH1D *HT_JetEta_cjet = ((TH1D *)DYprocess->Get("h_DY_JetEta_cjet"));
    TH1D *HT_alpha3D_cjet = ((TH1D *)DYprocess->Get("h_DY_alpha3D_cjet"));

    TH1D *HT_JetPt_lightjet = ((TH1D *)DYprocess->Get("h_DY_JetPt_light"));
    TH1D *HT_JetEta_lightjet = ((TH1D *)DYprocess->Get("h_DY_JetEta_light"));
    TH1D *HT_alpha3D_lightjet = ((TH1D *)DYprocess->Get("h_DY_alpha3D_light"));

    TH1D *DYnTracks_cut = ((TH1D *)DYprocess->Get("h_DY_nTracks_cut"));
    TH1D *HT_nTracks_cjet_cut = ((TH1D *)DYprocess->Get("h_DY_nTracks_cjet_cut"));
    TH1D *DYnTracks_heavy_cut = ((TH1D *)DYprocess->Get("h_DY_nTracks_heavy_cut"));
    TH1D *DYnTracks_heavy_nogluon_cut = ((TH1D *)DYprocess->Get("h_DY_nTracks_heavy_nogluon_cut"));
    TH1D *DYnTracks_light_cut = ((TH1D *)DYprocess->Get("h_DY_nTracks_light_cut"));

    TH1D *Top_fakeRate = ((TH1D *)Topprocess->Get("Top_fakeRate"));
    TH1D *Top_bjet_fakeRate = ((TH1D *)Topprocess->Get("Top_bjet_fakeRate"));
    TH1D *Top_cjet_fakeRate = ((TH1D *)Topprocess->Get("Top_cjet_fakeRate"));
    TH1D *Top_heavy_fakeRate = ((TH1D *)Topprocess->Get("Top_heavy_fakeRate"));
    TH1D *Top_light_fakeRate = ((TH1D *)Topprocess->Get("Top_light_fakeRate"));

    TH1D *TopnTracks = ((TH1D *)Topprocess->Get("h_Top_nTracks"));
    TH1D *Top_nTracks_bjet = ((TH1D *)Topprocess->Get("h_Top_nTracks_bjet"));
    TH1D *Top_nTracks_cjet = ((TH1D *)Topprocess->Get("h_Top_nTracks_cjet"));
    TH1D *TopnTracks_heavy = ((TH1D *)Topprocess->Get("h_Top_nTracks_heavy"));
    TH1D *Top_nTracks_lightjet = ((TH1D *)Topprocess->Get("h_Top_nTracks_light"));

    // Jet Pt, eta
    TH1D *Top_JetPt_bjet = ((TH1D *)Topprocess->Get("h_Top_jetpt_bjet"));
    TH1D *Top_JetEta_bjet = ((TH1D *)Topprocess->Get("h_Top_jeteta_bjet"));
    TH1D *Top_alpha3D_bjet = ((TH1D *)Topprocess->Get("h_Top_alpha3D_bjet"));

    TH1D *Top_JetPt_cjet = ((TH1D *)Topprocess->Get("h_Top_jetpt_cjet"));
    TH1D *Top_JetEta_cjet = ((TH1D *)Topprocess->Get("h_Top_jeteta_cjet"));
    TH1D *Top_alpha3D_cjet = ((TH1D *)Topprocess->Get("h_Top_alpha3D_cjet"));

    TH1D *Top_JetPt_lightjet = ((TH1D *)Topprocess->Get("h_Top_jetpt_light"));
    TH1D *Top_JetEta_lightjet = ((TH1D *)Topprocess->Get("h_Top_jeteta_light"));
    TH1D *Top_alpha3D_lightjet = ((TH1D *)Topprocess->Get("h_Top_alpha3D_light"));

    TH1D *TopnTracks_cut = ((TH1D *)Topprocess->Get("h_Top_nTracks_cut"));
    TH1D *Top_nTracks_cjet_cut = ((TH1D *)Topprocess->Get("h_Top_nTracks_cjet_cut"));
    TH1D *TopnTracks_heavy_cut = ((TH1D *)Topprocess->Get("h_Top_nTracks_heavy_cut"));
    TH1D *TopnTracks_light_cut = ((TH1D *)Topprocess->Get("h_Top_nTracks_light_cut"));

    DYmet->SetLineWidth(2);
    Topmet->SetLineWidth(2);

    HT_fakeRate->SetLineWidth(2);
    HT_heavy_fakeRate->SetLineWidth(2);
    HT_heavy_nogluon_fakeRate->SetLineWidth(2);
    HT_bjet_fakeRate->SetLineWidth(2);
    HT_cjet_fakeRate->SetLineWidth(2);
    HT_light_fakeRate->SetLineWidth(2);

    DYnTracks->SetLineWidth(2);
    HT_nTracks_bjet->SetLineWidth(2);
    HT_nTracks_cjet->SetLineWidth(2);
    DYnTracks_heavy->SetLineWidth(2);
    DYnTracks_heavy_nogluon->SetLineWidth(2);
    HT_nTracks_lightjet->SetLineWidth(2);

    HT_JetPt_bjet->SetLineWidth(2);
    HT_JetEta_bjet->SetLineWidth(2);
    HT_alpha3D_bjet->SetLineWidth(2);

    HT_JetPt_cjet->SetLineWidth(2);
    HT_JetEta_cjet->SetLineWidth(2);
    HT_alpha3D_cjet->SetLineWidth(2);

    HT_JetPt_lightjet->SetLineWidth(2);
    HT_JetEta_lightjet->SetLineWidth(2);
    HT_alpha3D_lightjet->SetLineWidth(2);

    DYnTracks_cut->SetLineWidth(2);
    HT_nTracks_cjet_cut->SetLineWidth(2);
    DYnTracks_heavy_cut->SetLineWidth(2);
    DYnTracks_heavy_nogluon_cut->SetLineWidth(2);
    DYnTracks_light_cut->SetLineWidth(2);

    Top_fakeRate->SetLineWidth(2);
    Top_bjet_fakeRate->SetLineWidth(2);
    Top_cjet_fakeRate->SetLineWidth(2);
    Top_heavy_fakeRate->SetLineWidth(2);
    Top_light_fakeRate->SetLineWidth(2);

    TopnTracks->SetLineWidth(2);
    Top_nTracks_bjet->SetLineWidth(2);
    Top_nTracks_cjet->SetLineWidth(2);
    TopnTracks_heavy->SetLineWidth(2);
    Top_nTracks_lightjet->SetLineWidth(2);

    // Jet Pt, eta
    Top_JetPt_bjet->SetLineWidth(2);
    Top_JetEta_bjet->SetLineWidth(2);
    Top_alpha3D_bjet->SetLineWidth(2);

    Top_JetPt_cjet->SetLineWidth(2);
    Top_JetEta_cjet->SetLineWidth(2);
    Top_alpha3D_cjet->SetLineWidth(2);

    Top_JetPt_lightjet->SetLineWidth(2);
    Top_JetEta_lightjet->SetLineWidth(2);
    Top_alpha3D_lightjet->SetLineWidth(2);

    TopnTracks_cut->SetLineWidth(2);
    Top_nTracks_cjet_cut->SetLineWidth(2);
    TopnTracks_heavy_cut->SetLineWidth(2);
    TopnTracks_light_cut->SetLineWidth(2);

    DYmet->SetFillColor(kOrange - 3);
    Topmet->SetLineWidth(2);

    HT_fakeRate->SetLineColor(kOrange - 3);
    HT_heavy_fakeRate->SetLineColor(kOrange - 3);
    HT_heavy_nogluon_fakeRate->SetLineColor(kOrange - 3);
    HT_bjet_fakeRate->SetLineColor(kOrange - 3);
    HT_cjet_fakeRate->SetLineColor(kOrange - 3);
    HT_light_fakeRate->SetLineColor(kOrange - 3);

    DYnTracks->SetLineColor(kOrange - 3);
    HT_nTracks_bjet->SetLineColor(kOrange - 3);
    HT_nTracks_cjet->SetLineColor(kOrange - 3);
    DYnTracks_heavy->SetLineColor(kOrange - 3);
    DYnTracks_heavy_nogluon->SetLineColor(kOrange - 3);
    HT_nTracks_lightjet->SetLineColor(kOrange - 3);

    HT_JetPt_bjet->SetLineColor(kOrange - 3);
    HT_JetEta_bjet->SetLineColor(kOrange - 3);
    HT_alpha3D_bjet->SetLineColor(kOrange - 3);

    HT_JetPt_cjet->SetLineColor(kOrange - 3);
    HT_JetEta_cjet->SetLineColor(kOrange - 3);
    HT_alpha3D_cjet->SetLineColor(kOrange - 3);

    HT_JetPt_lightjet->SetLineColor(kOrange - 3);
    HT_JetEta_lightjet->SetLineColor(kOrange - 3);
    HT_alpha3D_lightjet->SetLineColor(kOrange - 3);

    DYnTracks_cut->SetLineColor(kOrange - 3);
    HT_nTracks_cjet_cut->SetLineColor(kOrange - 3);
    DYnTracks_heavy_cut->SetLineColor(kOrange - 3);
    DYnTracks_heavy_nogluon_cut->SetLineColor(kOrange - 3);
    DYnTracks_light_cut->SetLineColor(kOrange - 3);

    Top_fakeRate->SetLineColor(kGreen + 3);
    Top_bjet_fakeRate->SetLineColor(kGreen + 3);
    Top_cjet_fakeRate->SetLineColor(kGreen + 3);
    Top_heavy_fakeRate->SetLineColor(kGreen + 3);
    Top_light_fakeRate->SetLineColor(kGreen + 3);

    TopnTracks->SetLineColor(kGreen + 3);
    Top_nTracks_bjet->SetLineColor(kGreen + 3);
    Top_nTracks_cjet->SetLineColor(kGreen + 3);
    TopnTracks_heavy->SetLineColor(kGreen + 3);
    Top_nTracks_lightjet->SetLineColor(kGreen + 3);

    // Jet Pt, eta
    Top_JetPt_bjet->SetLineColor(kGreen + 3);
    Top_JetEta_bjet->SetLineColor(kGreen + 3);
    Top_alpha3D_bjet->SetLineColor(kGreen + 3);

    Top_JetPt_cjet->SetLineColor(kGreen + 3);
    Top_JetEta_cjet->SetLineColor(kGreen + 3);
    Top_alpha3D_cjet->SetLineColor(kGreen + 3);

    Top_JetPt_lightjet->SetLineColor(kGreen + 3);
    Top_JetEta_lightjet->SetLineColor(kGreen + 3);
    Top_alpha3D_lightjet->SetLineColor(kGreen + 3);

    TopnTracks_cut->SetLineColor(kGreen + 3);
    Top_nTracks_cjet_cut->SetLineColor(kGreen + 3);
    TopnTracks_heavy_cut->SetLineColor(kGreen + 3);
    TopnTracks_light_cut->SetLineColor(kGreen + 3);

    // DYnTracks->SetFillStyle(3001);
    // Dibosonmet->SetFillColor(kAzure + 7);

    TH1F *RatioTop = new TH1F("RatioTop", "", 50, 0, 50);
    RatioTop->Sumw2();

    //-------------
    // Get Ratio
    //-------------

    //------------
    // Normalized
    //------------
    // HT_JetPt_bjet->Scale(1 / HT_JetPt_bjet->Integral());
    // Top_JetPt_bjet->Scale(1 / Top_JetPt_bjet->Integral());

    TH1D *HT_var = (TH1D *)HT_bjet_fakeRate->Clone("HT_var");
    TH1D *Top_var = (TH1D *)Top_bjet_fakeRate->Clone("Top_var");

    TH1D *RatioTop_DY = (TH1D *)Top_var->Clone("RatioTop_DY");
    RatioTop_DY->Divide(RatioTop_DY, HT_var);

    int nBins = HT_var->GetNbinsX();
    Double_t Arr_ratio[nBins];
    Double_t X_DYvalue[nBins];
    vector<float> DY_values;
    vector<float> Top_values;
    DY_values.clear();
    Top_values.clear();
    for (int i = 0; i < nBins; i++)
    {
        float DY_content = HT_var->GetBinContent(i + 1);
        float Top_content = Top_var->GetBinContent(i + 1);

        float Ratio = Top_content / DY_content;

        if (isnan(abs(Ratio)))
        {
            Ratio = 0.;
        }
        DY_values.push_back(DY_content);
        Top_values.push_back(Top_content);
        RatioTop->SetBinContent(i + 1, Ratio);
        // cout << "Ratio = " << Ratio << endl;
        Arr_ratio[i] = Ratio;
        X_DYvalue[i] = Top_content;
    }

    // for (int i = 0; i <nBins; i++)
    //{
    //     RatioTop->SetBinError(i+1,getRMS(X_values));
    // }
    // cout << "RMS = " <<getRMS(X_values)<<endl;
    //  RatioTop->Draw();

    const double LABELSIZE = 20.0;
    auto c1 = new TCanvas("c", "", 700, 1000);
    c1->Divide(1, 2, 0.01, 0);
    c1->cd(1);
    double temp1_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    double label1_size = LABELSIZE / temp1_pad;

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    HT_var->GetXaxis()->SetLabelSize(label1_size);
    HT_var->GetYaxis()->SetLabelSize(label1_size);
    Top_var->GetYaxis()->SetLabelSize(label1_size);
    HT_var->GetXaxis()->SetNdivisions(5);
    HT_var->GetYaxis()->SetDecimals();
    //"Jet #eta"
    // HT_var->GetXaxis()->SetTitle("Track multicity");
    // HT_var->GetYaxis()->SetTitle("N Jets / Normalized");
    HT_var->GetYaxis()->SetTitle("fake rate");
    HT_var->GetXaxis()->SetLabelSize(0);
    Top_var->GetXaxis()->SetLabelSize(0);

    HT_var->Draw("");
    Top_var->Draw("same ");

    TLegend *leg = new TLegend(0.54, 0.163, 0.470, 0.736);
    // TLegend *leg = new TLegend(0.34, 0.463, 0.470, 0.636);
    leg->SetFillColor(0);
    leg->SetFillStyle(0);
    leg->SetTextSize(0.045);
    leg->SetBorderSize(0);
    leg->SetFillColor(0);
    leg->SetFillStyle(0);
    leg->AddEntry(HT_var, "Drell-Yan c flavor");
    leg->AddEntry(Top_var, "Top process c flavor");
    leg->Draw();
    gStyle->SetOptStat(0);

    c1->cd(2);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();
    double temp2_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    double label2_size = LABELSIZE / temp2_pad;

    /*
    TGraph *gRatio = new TGraph(nBins, X_DYvalue, Arr_ratio);
    gRatio->SetMarkerColor(1);
    gRatio->SetLineColor(kAzure + 7);
    RatioTop_DY->SetLineColor(kAzure + 7);
    gRatio->SetTitle("");
    gRatio->GetXaxis()->SetTitle("Bins");
    gRatio->GetYaxis()->SetTitle("Top/Drell-Yan");
    gRatio->GetXaxis()->SetLabelSize(label2_size);
    gRatio->GetYaxis()->SetLabelSize(label2_size);
    gRatio->GetXaxis()->SetDecimals();
    gRatio->GetYaxis()->SetDecimals();
    */
    // gRatio->Draw("AL*");
    RatioTop_DY->GetYaxis()->SetTitle("Top / Drell-Yan");
    RatioTop_DY->GetXaxis()->SetTitle("Trackmulticity");
    // RatioTop_DY->GetXaxis()->SetTitle("#alpha_{3D}");
    // RatioTop_DY->GetXaxis()->SetTitle("Jet pt");
    RatioTop_DY->Draw("e1");

    //c1->SaveAs("light_fakerate_ratio.png");
}
