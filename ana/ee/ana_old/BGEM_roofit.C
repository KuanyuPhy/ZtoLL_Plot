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
#include "setNCUStyle.C"
#include "RooExponential.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooFitResult.h"
#include "RooPlot.h"

using namespace RooFit;

void BGEM_roofit()
{
    setNCUStyle(true);

    TFile *ABCD = new TFile("./../../ABCD_HT.root");
    TH1F *h_ht0A_met_2 = ((TH1F *)ABCD->Get("h_ht0A_met_2"));
    h_ht0A_met_2->GetXaxis()->SetTitle("Ratio");

    float min = h_ht0A_met_2->GetXaxis()->GetXmin();
    float max = h_ht0A_met_2->GetXaxis()->GetXmax();

    RooRealVar x("x", "Ratio", min, max);

    RooDataHist data("data", "", x, h_ht0A_met_2);

    // Exponential function
    RooRealVar Slope1("Slope1", "Slope", -10, 10);
    RooExponential expo1("expo1", "exponential PDF", x, Slope1);

    // PDF variable
    RooRealVar par1("par1", "par1", -10, 50);
    RooRealVar par2("par2", "par2", -10, 10);
    RooRealVar par3("par3", "par3", -10, 10);
    RooRealVar par4("par4", "par4", -10, 10);
    RooRealVar par5("par5", "par5", 5,-10, 25);

    // Generic pdf
    RooGenericPdf highorderexpo("highorderexpo", "RooGeneric Pdf", "exp(par1 - par2*x - par3* x* x)+par5", RooArgSet(x, par1, par2, par3, par5));

    // Poly

    RooRealVar par6("par6", "par6", -10, 10);
    RooPolynomial pol2("pol2", "Polynomial", x, RooArgSet(par5, par6));

    // add up: highorderexpo + Poly
    RooRealVar fraction("fraction", "fraction of expo+poly", 0.5, 0., 1.);
    // RooAddPdf model("model", "PDF model", RooArgList(highorderexpo, pol2),RooArgList(fraction));

    RooProdPdf model("model", "PDF model", highorderexpo, pol2);

    highorderexpo.fitTo(data, SumW2Error(true), NumCPU(8));
    auto c2 = new TCanvas("c2", "BPRE");
    RooPlot *xframe = x.frame(Title("Ratio pdf."));
    data.plotOn(xframe);
    highorderexpo.plotOn(xframe);
    xframe->Draw();
}