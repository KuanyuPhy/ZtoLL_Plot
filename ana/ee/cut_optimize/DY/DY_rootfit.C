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
#include "RooDataSet.h"
#include "RooExponential.h"
#include "RooAddPdf.h"
#include "RooProdPdf.h"
#include "./../../../lib/setNCUStyle.C"
using namespace std;

double rootfitPDF(double *x, double *par)
{
    return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3] + par[4] * x[0]* x[0]);
    // return ((TMath::Exp(par[0] + par[1] * x[0]* x[0])) + par[2] * x[0] * x[0] + par[3] * x[0] + par[4]);
    //(1 + par1 * x + par2 * ((2 * x * x) - 1)));
    //  return ((TMath::Exp(par[0] + par[1] * x[0])) + (1 + par[2] * x[0] + par[3] * (2 * x[0] * x[0] - 1)));
}
void DY_rootfit()
{
    TFile *file = new TFile("./ee_DY_emjet_half.root");
    TH1D *h_fake_rate = ((TH1D *)file->Get("HT_bjet_fakeRate"));
    h_fake_rate->SetTitle("DY b jet fakeRate");
    h_fake_rate->GetYaxis()->SetTitle("fake rate");
    h_fake_rate->GetXaxis()->SetTitle("Jet track multiplicity");

    //-------------
    // Get Maximum value
    //-------------
    int binmax = h_fake_rate->FindLastBinAbove();
    cout << "binmax = " << binmax << endl;
    h_fake_rate->GetXaxis()->SetRangeUser(1, binmax + 1);
    h_fake_rate->SetLineWidth(3);

    TF1 *f1 = new TF1("f2", rootfitPDF, 1., 29., 5);
    h_fake_rate->Fit("f2", "RMF");
    cout << "chi value: " << f1->GetChisquare() << endl;
    cout << "NDF : " << f1->GetNDF() << endl;
    //cout << "NDF : " << h_fake_rate->GetNbinsX() << endl;
    cout << "chi square: " << f1->GetChisquare() / (binmax + 1 - 5) << endl;
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(1111);
}