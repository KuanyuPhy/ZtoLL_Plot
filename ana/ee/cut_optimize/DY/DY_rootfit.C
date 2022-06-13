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
#include <TF1.h>
#include <TAxis.h>
#include <TLine.h>
#include <TMinuit.h>
#include "RooRealVar.h"
#include "Math/MinimizerOptions.h"
#include "RooDataSet.h"
#include "RooExponential.h"
#include "RooAddPdf.h"
#include "RooProdPdf.h"
#include "./../../../lib/setNCUStyle.C"
using namespace std;
int npar = 6;
Double_t rootfitPDF(double *x, double *par)
{
    return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3] + par[4] * x[0]);
    // return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3] );
    // return ((TMath::Exp(par[0] + par[1] * x[0]* x[0])) + par[2] * x[0] * x[0] + par[3] * x[0] + par[4]);
    // return ((TMath::Exp(par[0] + par[1] * x[0])) + (1 + par[2] * x[0] + par[3] * (2 * x[0] * x[0] - 1)));
    // Double_t fit_val = par[0] * TMath::Exp(par[1] + par[2] * x[0] + par[3] * x[0] * x[0]) + par[4] + par[5] * x[0] * x[0] * x[0] + par[6] * x[0] * x[0] + par[7] * x[0];
    // return fit_val;
}
Double_t rootfitcPDF(double *x, double *par)
{
    // Double_t fit_val = (TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3] + par[4] * x[0] + par[5] * x[0];
    Double_t fit_val = (TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0] + par[3] * x[0] * x[0] * x[0])) + par[4] + par[5] * x[0];
    return fit_val;
}
Double_t bjet_background(Double_t x)
{
    double par0 = -0.203738;
    double par1 = -0.342211;
    double par2 = 0.00870887;
    double par3 = 0.0263022;
    double par4 = -0.00253953;
    Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 + par4 * x);
    return weight;
}
Double_t cjet_background(Double_t x)
{
    double par0 = 2.88868e-01;
    double par1 = -9.26222e-01;
    double par2 = 5.29108e-02;
    double par3 = -1.49987e-03;
    double par4 = -6.16131e-04;
    double par5 = 3.31859e-05;
    Double_t weight = (TMath::Exp(par0 + par1 * x + par2 * x * x + par3 * x * x * x) + par4 + par5 * x);

    return weight;
}
Double_t lightjet_background(float x)
{

    double par0 = 4.13657e-01;
    double par1 = -6.60339e-01;
    double par2 = 1.50643e-02;
    double par3 = -2.92786e-04;
    double par4 = 2.23573e-05;
    double par5 = 5.61427e-06;
    Double_t weight = (TMath::Exp(par0 + par1 * x + par2 * x * x + par3 * x * x * x) + par4 + par5 * x);
    return weight;
}
void DY_rootfit()
{
    TFile *file = new TFile("./ee_DY_emjet_half.root");
    TH1D *h_fake_rate = ((TH1D *)file->Get("HT_light_fakeRate"));
    h_fake_rate->SetTitle("DY light jet fakeRate");
    h_fake_rate->GetYaxis()->SetTitle("fake rate");
    h_fake_rate->GetXaxis()->SetTitle("Jet track multiplicity");
    //-------------
    // Get Maximum value
    //-------------
    // ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Minuit");

    int binmax = h_fake_rate->FindLastBinAbove();
    cout << "binmax = " << binmax << endl;
    cout << "maxvalue = " << h_fake_rate->GetBinContent(binmax - 1);
    // h_fake_rate->GetXaxis()->SetRangeUser(1, binmax);
    h_fake_rate->SetLineWidth(3);
    // h_fake_rate->Draw();
    //  gPad->SetLogy();
    // TF1 *f1 = new TF1("f1", rootfitcPDF, 1., binmax, npar);
    TF1 *f2 = new TF1("f2", "TMath::Exp(4.13657e-01+ -6.60339e-01 * x + 1.50643e-02 * x * x + -2.92786e-04 * x * x * x) + 2.23573e-05 + 5.61427e-06 * x", 1, 50);
    f2->SetLineWidth(2);
    f2->SetLineColor(kGreen-4);

    // f1->SetParameters(3.15257e-01, -9.46826e-01, 5.67463e-02, -1.78427e-03, 1.58125e-04);
    // f1->SetParameters(4.13657e-01, -6.60339e-01, 1.50643e-02,-2.92786e-04, 2.23746e-05,5.61494e-06);
    // TF1 *f1 = new TF1("f1", "expo", 1.,10);
    // TF1 *f2 = new TF1("f2", "pol", 10, binmax);
    auto c1 = new TCanvas("c1", "", 700, 700);
    c1->Divide(1, 2, 0.01, 0);
    c1->cd(1);
    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);
    h_fake_rate->SetLabelSize(0);
    h_fake_rate->Draw();
    f2->Draw("same");
    // h_fake_rate->Fit("f1", "MFR+");
    //  h_fake_rate->Fit("f2","FR+");
    // cout << "chi value: " << f1->GetChisquare() << endl;
    // cout << "NDF : " << f1->GetNDF() << endl;
    //  cout << "NDF : " << h_fake_rate->GetNbinsX() << endl;
    // cout << "chi square: " << f1->GetChisquare() / f1->GetNDF() << endl;
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(1111);

    TH1D *RatioTop = new TH1D("RatioTop", "", 50, 0, 50);
    RatioTop->Sumw2();
    for (int i = 1; i <= binmax; i++)
    {
        float points = h_fake_rate->GetBinContent(i);
        float fitresult = lightjet_background(i);
        double ratio = fitresult / points;
        if (points == 0)
        {
            ratio = 0;
        }
        // cout << "i = " << i << " ratio = " << ratio << " points = " << points << endl;
        RatioTop->SetBinContent(i, ratio);
    }

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    RatioTop->GetYaxis()->SetTitle("Fit / points");
    RatioTop->GetXaxis()->SetTitle("nTracks");
    RatioTop->Draw();
    
}