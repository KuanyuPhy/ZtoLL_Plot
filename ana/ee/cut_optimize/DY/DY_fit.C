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
#include <TMinuit.h>
#include <TLine.h>
#include <TF1.h>
#include <RooDataHist.h>
#include <RooPlot.h>
#include "RooChebychev.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooExponential.h"
#include "RooAddPdf.h"
#include "RooProdPdf.h"
#include "./../../../lib/setNCUStyle.C"
using namespace RooFit;
using namespace std;

TH1D *hist = 0;
void makeModel(RooWorkspace &w)
{
    // Construct model here
    // w.factory("Exponential::f(x[1,30],alpha[-1.54, -5., 1.0])");
    w.factory("CEXPR::mypdf()");
}

Double_t rootfitPDF(Double_t *x, Double_t *par)
{
    // return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3] + par[5] * x[0] + par[4] * x[0] * x[0]);
    // return ((TMath::Exp(par[0] + par[1] * x[0])) + par[2] + par[3] * x[0]);
    // return ((TMath::Exp(par[0]  + par[1] * x[0])) + par[2] * x[0] + par[3]);
    return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3] * x[0] + par[4]);
    // return ((TMath::Exp(par[0] * x)));
    //  return ((TMath::Exp(par[0] + par[1] * x[0])) + (1 + par[2] * x[0] + par[3] * (2 * x[0] * x[0] - 1)));
}
/*
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
*/
Double_t bjet_background(Double_t x)
{
    // double par0 = -0.4166;
    // double par1 = -0.2182;
    // double par2 = -0.01874;
    // double par3 = 0.00066;
    // Double_t weight = ((TMath::Exp(par0 + par1 * x)) + par2 + par3 * x);
    //(TMath::Exp(par[0] + par[1] * x[0])) + par[2] + par[3] * x[0] +  par[4] * x[0] * x[0]);

    double par0 = -4.16583e-01;
    double par1 = -2.18205e-01;
    double par2 = 6.60044e-04;
    double par3 = -1.87443e-02;
    Double_t weight = ((TMath::Exp(par0 + par1 * x)) + par2 * x + par3);
    return weight;
}
Double_t cjet_background(Double_t x)
{
    double par0 = -1.67992e-01;
    double par1 = -6.54795e-01;
    double par2 = 1.11829e-02;
    double par3 = -1.80126e-05;
    double par4 = 4.59121e-04;
    Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 * x + par4);
    return weight;
}
Double_t lightjet_background(float x)
{

    // double par0 = -3.96908e-01;
    // double par1 = -6.44591e-01;
    // double par2 = 1.12289e-02;
    // double par3 = 1.33488e-05;
    // double par4 = -3.42398e-04;
    double par0 = 0.08054419;
    double par1 = -0.6358334;
    double par2 = 0.01123651;
    double par3 = -5.991368e-7;
    double par4 = 0.00009634264;
    Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 * x + par4);
    return weight;
}
void DY_fit()
{
    // ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Minuit2");
    //  setNCUStyle(true);
    TFile *file = new TFile("./ee_DY_emjet_half.root");
    TH1D *h_fake_rate = ((TH1D *)file->Get("HT_cjet_fakeRate"));
    h_fake_rate->SetTitle("DY c jet fakeRate");
    h_fake_rate->GetYaxis()->SetTitle("fake rate");
    h_fake_rate->GetXaxis()->SetTitle("Jet track multiplicity");
    // h_fake_rate->Sumw2();

    // h_fake_rate->GetXaxis()->SetRangeUser(1, 50);
    h_fake_rate->SetLineWidth(3);

    Float_t Xmin = h_fake_rate->GetXaxis()->GetXmin();
    Float_t Xmax = h_fake_rate->GetXaxis()->GetXmax();

    // TF1 *f2 = new TF1("f2", background, Xmin, Xmax, 6);
    //  TF1 *f3 = new TF1("f3", "expo*expo", Xmin, Xmax);
    // f2->SetLineWidth(2);
    //  h_fake_rate->Fit("f2", "MF");
    RooRealVar x("x", "Jet track multiplicity", 1, 50);
    // x.setRange(0.1,3) ;
    RooDataHist data("data", "dataset with x", x, h_fake_rate);
    RooRealVar tau("tau", "tau", -0.25271, -0.5, 1.);
    RooRealVar tau2("tau2", "tau2", -1.54, -5., 1.0);
    RooExponential expo1("expo1", "exp^{cx}", x, tau);
    RooExponential expo2("expo2", "exp^{cx}", x, tau2);

    // RooRealVar var1("var1", "var1", 1., -5., 5.);
    // RooRealVar var2("var2", "var2", 0.5, -5., 5.);
    // RooRealVar var3("var3", "var3", 0.5, -5., 5.);

    RooRealVar var1("var1", "var1", -0.76, -2., 2.);
    RooRealVar var2("var2", "var2", 0.9, -2., 2.);
    RooRealVar var3("var3", "var3", 0.6, -1., 1.);

    RooChebychev poly3("poly3", "poly3", x, RooArgList(var1, var2, var3));
    RooChebychev poly2("poly2", "poly2", x, RooArgList(var1, var2));
    RooChebychev poly1("poly1", "poly1", x, var1);

    RooRealVar twofunction_fraction("twofunction_fraction", "twofunction_fraction", 0.8, 0.0, 1.0);
    // RooProdPdf expoo("expoo", "expo pdf", RooArgList(expo1, expo2));
    RooAddPdf expo("expo", "expo pdf", RooArgList(expo1, poly2), twofunction_fraction); // testtttt

    // expo.chi2FitTo(data, "m");
    RooPlot *xframe = x.frame(Title("DY c jet fakeRate"));
    data.plotOn(xframe);
    expo.plotOn(xframe, LineStyle(kDashed));
    expo.paramOn(xframe, Layout(0.3, 0.5, 0.7));

    // Construct a histogram with the pulls of the data w.r.t the curve
    // RooHist *hpull = xframe->pullHist();
    // RooHist *hresidual = xframe->residHist();
    // Create a new frame to draw the pull distribution and add the distribution to the frame
    // RooPlot *frame3 = x.frame(Title("Pull Distribution"));

    // frame3->addPlotable(hpull, "P");
    cout << "chi^2 = " << xframe->chiSquare() << endl;
    const double LABELSIZE = 20.0;
    auto c1 = new TCanvas("c1", "", 700, 1000);
    c1->Divide(1, 2, 0.01, 0);
    c1->cd(1);
    double temp1_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    double label1_size = LABELSIZE / temp1_pad;

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    //  gPad->SetTopMargin(0 - 0.3);
    //  gPad->SetBottomMargin(0.02);
    //  gPad->SetRightMargin(0.04);
    //  gPad->SetTickx();
    //  h_fake_rate->SetLabelSize(0);
    //   h_fake_rate->Draw("");
    // c1->cd(2);
    //  gStyle->SetStatW(0.3);
    //  gStyle->SetStatH(0.3);
    //  gStyle->SetStatX(0.879447);
    //  gStyle->SetStatY(0.939033);
    //  gStyle->SetStatFontSize(0.05);
    //  gStyle->SetStatBorderSize(0);
    //  gPad->SetRightMargin(0.04);
    //  gPad->SetTopMargin(0);
    //  gPad->SetBottomMargin(0.2);
    //  gPad->SetTickx();
    // xframe->GetXaxis()->SetTitleOffset(1.6);
    // xframe->Draw();
    //  c1->cd(2);

    // TF1 *f1 = new TF1("f1", "(TMath::Exp(-0.25271 * x)) +  (1-0.999984584) * (1 + -0.76* (x) +  0.9* (2 * x * x - 1))", 1, 30);
    TF1 *f2 = new TF1("f2", rootfitPDF, 1., 50., 5);
    f2->SetParameters(0.07484943356324936, -0.6296413404697103, 0.009827579804612824, 2.776417776713538e-06, 0.000326526663406202);
    //f2->SetParameter(0, -0.4365997);
    f2->SetParLimits(0, -1, 1);
    //f2->SetParameter(1, -0.2879801);
    f2->SetParLimits(1, -1, 1);
    //f2->SetParameter(2, -0.001180108);
    f2->SetParLimits(2, -1, 1);
    //f2->SetParameter(3, -0.0001652946);
    f2->SetParLimits(3, -1, 1);
    f2->SetParLimits(4, -1, 1);
    //   f2->SetParLimits(3, 0.05, 0.09);
    h_fake_rate->Fit("f2", "RMF");
    f2->SetLineWidth(2);
    f2->SetLineStyle(kDashed);
    cout << "NBin : " << h_fake_rate->GetNbinsX() << endl;
    cout << "chi value: " << f2->GetChisquare() << endl;
    cout << "NDF : " << h_fake_rate->GetNbinsX() << endl;
    cout << "chi square: " << f2->GetChisquare() / (h_fake_rate->GetNbinsX() - 5) << endl;

    TH1D *Ratioresult = new TH1D("Ratioresult", "", 49, 1, 50);
    Ratioresult->Sumw2();
    // int nBins = h_fake_rate->GetNbinsX();
    for (int i = 1; i <= 49; i++)
    {
        double DY_content = h_fake_rate->GetBinContent(i);
        double rootfit_content = cjet_background(i - 1);
        double Error = sqrt((pow(sqrt(DY_content) / DY_content, 2) + pow(sqrt(rootfit_content) / rootfit_content, 2)));
        // cout << "i = " << i << " DY_content = " << DY_content << " rootfit_content =  " << rootfit_content << " Error = " << Error << endl;
        cout << "i = " << i << " rootfit_content = " << DY_content << endl;

        // cout<< "i = " << i <<" DY_content = " << DY_content << " rootfit_content =  " << rootfit_content << " Error = " << Error << endl;

        double Ratio = DY_content / rootfit_content;
        if (isnan(abs(Ratio)) || DY_content == 0)
        {
            Ratio = 0.;
        }
        if (isnan(abs(Error)) || DY_content == 0)
        {
            Error = 0.;
        }
        Ratioresult->SetBinContent(i, rootfit_content);
        // Ratioresult->SetBinError(i, Error);
        //  double rootfit_content = bjet_background(i + 1);
        //  Ratioresult->Fill(Ratio);
    }
    h_fake_rate->SetLabelSize(0);
    // h_fake_rate->GetXaxis()->SetRangeUser(0, 50);
    h_fake_rate->Draw("");
    // f2->Draw("same");
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(1111);

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
    // double temp2_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    // double label2_size = LABELSIZE / temp2_pad;
    Ratioresult->SetLineWidth(2);
    Ratioresult->GetYaxis()->SetTitle("fake rate / Curve");
    Ratioresult->GetXaxis()->SetTitle("Jet track multiplicity");
    Ratioresult->GetXaxis()->SetTitleOffset(1.5);
    Ratioresult->SetLineColor(kBlue);
    Ratioresult->Draw("E1");
    gStyle->SetOptStat(0);
}