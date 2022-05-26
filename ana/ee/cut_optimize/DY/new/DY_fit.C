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
#include "RooArgSet.h"
#include "RooHist.h"
#include "RooWorkspace.h"
#include "RooPlot.h"
#include "RooExponential.h"
#include "RooAddPdf.h"
#include "RooProdPdf.h"
#include "RooUniform.h"
#include "./../../../../lib/setNCUStyle.C"
using namespace RooFit;
using namespace std;
void makeModel(RooWorkspace &w)
{
    //----------------------
    // Construct model here
    //----------------------
    w.factory("Exponential::e(x[1,30], alpha[-0.25322,-1., 1])");
    w.factory("Chebychev::Chebychevpoly(x[1,30], {a1[0.6,-1.,1.],a2[-0.6,-1.,2.]})");
    w.factory("SUM::model(exp, polyfrac[0.5,0.,1.]*Chebychevpoly)");
    // w.factory("Uniform::Uniform(x[1,30])");
}
void DY_fit()
{
    TFile *file = new TFile("./../ee_DY_emjet_half.root");
    TH1D *h_fake_rate = ((TH1D *)file->Get("HT_bjet_fakeRate"));
    RooRealVar x("x", "Track multiplicity ", 1, 30);
    RooDataHist data("data", "dataset with x", x, Import(*h_fake_rate));
    data.Print("V");
    RooWorkspace w("w");
    makeModel(w);
    w.pdf("e")->chi2FitTo(data, Save(),Minos(true));
    TCanvas *c1 = new TCanvas();
    RooPlot *xframe = x.frame(Title("DY bjet fakeRate"));
    data.plotOn(xframe);
    w.pdf("e")->plotOn(xframe, LineStyle(kDashed));
    w.pdf("e")->paramOn(xframe, Layout(0.3, 0.5, 0.7));
    cout << "chi^2 = " << xframe->chiSquare() << endl;
    cout << "getNorm = " <<  w.pdf("e")->getNorm(RooArgSet(x)) << endl;
    cout << "normalization factor = " << 1 / w.pdf("e")->getNorm(RooArgSet(x)) << endl;
    //
    RooHist *hpull = xframe->pullHist();
    c1->Divide(2, 1);
    c1->cd(1);
    xframe->Draw();
    c1->cd(2);
    hpull->Draw();
    // RooPlot *frame = w.var(“x”)->frame();
    // w.pdf(“f”)->plotOn(frame);
    w.Print();
    w.writeToFile("model.root");
    //w.var("x")->setVal(3); 
    //cout <<  "get value in x = 3  = " << w.pdf("model")->getVal() << endl;
}