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
#include "RooDataHist.h"
#include "RooExponential.h"
#include "RooAddPdf.h"
#include "RooProdPdf.h"
#include "RooChebychev.h"
#include "./../../../../lib/setNCUStyle.C"
using namespace RooFit;
Double_t rootfitPDF(Double_t *x, Double_t *par)
{
     return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) );//+ par[3]+ par[4] * x[0] + par[5] * x[0] * x[0]);
    //return ((TMath::Exp(par[0] * x[0]))+ par[1]);
}
void Top_fit()
{
    setNCUStyle(true);
    TFile *file = new TFile("./../ee_Top_emjet_half.root");

    TH1F *h_fake_rate = ((TH1F *)file->Get("Top_bjet_fakeRate"));
    h_fake_rate->SetTitle("b jet fakeRate");
    h_fake_rate->GetYaxis()->SetTitle("fake rate");
    h_fake_rate->GetXaxis()->SetTitle("Jet track multiplicity");

    h_fake_rate->GetXaxis()->SetRangeUser(1, 25);

    h_fake_rate->SetLineWidth(3);

    // h_fake_rate->Fit("f2", "MF");
    RooRealVar x("x", "Track multiplicity ", 1, 30);
    RooDataHist *data = new RooDataHist("data", "dataset with x", x, h_fake_rate);
    RooRealVar tau("tau", "tau", -2.3, -5.,-0.1);
    RooRealVar tau2("tau2", "tau2", -1.54, -5, -0.1);
    RooExponential expo("expo", "exp^{cx}", x, tau);
    RooExponential expo2("expo2", "exp^{cx}", x, tau2);

    // RooRealVar var1("var1", "var1", 1., -5., 5.);
    // RooRealVar var2("var2", "var2", 0.5, -5., 5.);
    // RooRealVar var3("var3", "var3", 0.5, -5., 5.); 

    RooRealVar var1("var1", "var1", 0.6, -1., 1.);
    RooRealVar var2("var2", "var2", 0.6, -1., 2.);

    RooRealVar var3("var3", "var3", 0.6, -1., 2.);
    RooChebychev poly3("poly3", "poly3", x, RooArgList(var1, var2, var3));
    RooChebychev poly2("poly2", "poly2", x, RooArgList(var1, var2));
    RooChebychev poly1("poly1", "poly1", x, var1);

    RooRealVar twofunction_fraction("twofunction_fraction", "twofunction_fraction", 0.5, 0.0, 2.0);
    // RooProdPdf expo("expo", "expo pdf", RooArgList(expo1, expo2));
    //RooAddPdf expo("expo", "expo pdf", expo1, expo2,twofunction_fraction); // testtttt

    //RooAddPdf expo("expo", "expo pdf", expo1, poly2, twofunction_fraction); // testtttt

    expo.chi2FitTo(*data);
    RooPlot *xframe = x.frame(Title("Top bjet fakeRate"));
    data->plotOn(xframe);
    expo.plotOn(xframe, LineStyle(kDashed));
    expo.paramOn(xframe, Layout(0.3, 0.5, 0.7));


    //cout << "chi^2 = " << xframe->chiSquare() << endl;

    TF1 *f2 = new TF1("f2", rootfitPDF, 1., 25.,3);

    f2->SetParameter(0, -0.1902);
    f2->SetParLimits(0, -3, -0.1);

    auto c1 = new TCanvas("c1", "", 600, 800);
    c1->Divide(2, 1);

    c1->cd(1);
    //xframe->GetXaxis()->SetTitleOffset(1.6);
    //xframe->Draw();
    TH1F *hm = (TH1F*)h_fake_rate->Clone("hm");
    hm->Fit("f2","");
    hm->Draw();
    
    c1->cd(2);
    Float_t metAB_xmin = 1.;
    Float_t metAB_xax = 30.;


    // f2->SetParLimits(2,-1.,1.);
    h_fake_rate->Fit("f2","MW");

    f2->SetLineWidth(2);
    f2->SetLineStyle(kDashed);
    // TF1 *f1 = new TF1("f1", "sin(x)/x", -10, 10);
    h_fake_rate->Draw();
    // frame3->GetYaxis()->SetTitleOffset(1.6);
    // hpull.paramOn(frame3, Layout(0.3, 0.5, 0.7));
    //  frame3->Draw();
}