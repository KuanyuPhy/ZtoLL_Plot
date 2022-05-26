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
#include <TMinuit.h>
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooExponential.h"
#include "RooAddPdf.h"
#include "RooProdPdf.h"
#include "./../../../lib/setNCUStyle.C"

TH1D *hist = 0;
void makeModel(RooWorkspace &w)
{
    // Construct model here
    // w.factory("Exponential::f(x[1,30],alpha[-1.54, -5., 1.0])");
    w.factory("CEXPR::mypdf()");
}

double rootfitPDF(double x, double *par)
{
    // return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3] + par[4] * x[0] + par[5] * x[0] * x[0]);
    return ((TMath::Exp(par[0] + par[1] * x)) + par[2] * x * x + par[3] * x + par[4]);
    //(1 + par1 * x + par2 * ((2 * x * x) - 1)));
    // return ((TMath::Exp(par[0] + par[1] * x[0])) + (1 + par[2] * x[0] + par[3] * (2 * x[0] * x[0] - 1)));
}
void fcn(int &npar, double *gin, double &f, double *par, int iflag)
{
    f = 0.;
    for (int i = 1; i <= hist->GetNbinsX(); i++)
    {
        double x = hist->GetBinCenter(i);
        double measure = hist->GetBinContent(i);
        double error = sqrt(measure);
        double func = rootfitPDF(x, par);
        double delta = (func - measure) / error;

        f += delta * delta;
    }
}

void DY_rootfit()
{
    TFile *file = new TFile("./ee_DY_emjet_half.root");
    TH1D *h_fake_rate = ((TH1D *)file->Get("HT_bjet_fakeRate"));
    h_fake_rate->SetTitle("DY c jet fakeRate");
    h_fake_rate->GetYaxis()->SetTitle("fake rate");
    h_fake_rate->GetXaxis()->SetTitle("Jet track multiplicity");
    h_fake_rate->GetXaxis()->SetRangeUser(1, 30);
    h_fake_rate->SetLineWidth(3);
    TMinuit *gMinuit = new TMinuit(5);
    double p0init = -0.5665086;
    double p1init = -0.3852185;
    double p2init = 0.0002657967;
    double p3init = -0.01259151;
    double p4init = 0.1470727;
    hist = (TH1D *)h_fake_rate->Clone("hist");
    gMinuit->SetFCN(fcn);
    gMinuit->DefineParameter(0, "p0", p0init, 1.63712e+01, p0init - 0.1, p0init + 0.1);
    gMinuit->DefineParameter(1, "p1", p1init, 8.79339e-01, p1init - 0.1, p1init + 0.1);
    gMinuit->DefineParameter(2, "p2", p2init, 1.17668e-06, p2init - 0.1, p2init + 0.1);
    gMinuit->DefineParameter(3, "p3", p3init, 2.59218e-05, p3init - 0.1, p3init + 0.1);
    gMinuit->DefineParameter(4, "p4", p4init, 5.50436e-04, p4init - 0.1, p4init + 0.1);
    gMinuit->Command("MIGRAD");
    gMinuit->Command("MIGRAD");
    gMinuit->Command("MINOS");
    double par[5], err[5];
    for (int i = 0; i < 5; i++)
        gMinuit->GetParameter(i, par[i], err[i]);
    TH1F *curve = new TH1F("curve", "curve", hist->GetNbinsX() * 5,
                           hist->GetXaxis()->GetXmin(), hist->GetXaxis()->GetXmax());
    for (int i = 1; i <= curve->GetNbinsX(); i++)
    {
        double x = curve->GetBinCenter(i);
        double f = rootfitPDF(x, par);
        curve->SetBinContent(i, f);
    }
    curve->SetLineWidth(3);
    curve->SetLineColor(kRed);
    curve->SetLineStyle(2);
    hist->Draw();
    curve->Draw("csame");
}