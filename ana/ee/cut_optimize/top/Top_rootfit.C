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
    return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0] + par[3] * x[0] * x[0] * x[0])) + par[4] + par[5] * x[0]);
     //return((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0] + par[3] * x[0] * x[0] * x[0])) + par[4] + par[5] * x[0]);
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
void Top_rootfit()
{
    TFile *file = new TFile("./ee_Top_emjet_half.root");
    TH1D *h_fake_rate = ((TH1D *)file->Get("Top_light_fakeRate"));
    h_fake_rate->SetTitle("DY light jet fakeRate");
    h_fake_rate->GetYaxis()->SetTitle("fake rate");
    h_fake_rate->GetXaxis()->SetTitle("Jet track multiplicity");
    //-------------
    // Get Maximum value
    //-------------
    // ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Minuit");

    int binmax = h_fake_rate->FindLastBinAbove();
    cout << "binmax = " << binmax << endl;
    h_fake_rate->GetXaxis()->SetRangeUser(1, binmax + 1);
    h_fake_rate->SetLineWidth(3);
    h_fake_rate->Draw();
    // gPad->SetLogy();
    TF1 *f1 = new TF1("f1", rootfitPDF, 1., binmax, npar);
    // f1->SetParameters(3.15257e-01, -9.46826e-01, 5.67463e-02, -1.78427e-03, 1.58125e-04);
    //   f1->SetParameters(-2.86604e-01, -2.44863e-01, 4.58122e-03, -4.71342e-02, 7.56581e-04);
    //   TF1 *f1 = new TF1("f1", "expo", 1.,10);
    //   TF1 *f2 = new TF1("f2", "pol", 10, binmax);
    h_fake_rate->Fit("f1", "MFR+");
    // h_fake_rate->Fit("f2","FR+");
    cout << "chi value: " << f1->GetChisquare() << endl;
    cout << "NDF : " << f1->GetNDF() << endl;
    // cout << "NDF : " << h_fake_rate->GetNbinsX() << endl;
    cout << "chi square: " << f1->GetChisquare() / f1->GetNDF() << endl;
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(1111);
}