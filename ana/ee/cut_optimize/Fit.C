#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <TH3D.h>
#include <TF1.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TAxis.h>
#include <TPad.h>
#include <TLine.h>
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooExponential.h"
#include "RooWorkspace.h"
#include "RooAddPdf.h"
#include "RooProdPdf.h"
#include "RooChebychev.h"
#include "TMinuit.h"
#include "./../../lib/setNCUStyle.C"
using namespace std;

TH1F *h_DY_fake_rate = NULL;
Double_t rootfitbjet(Double_t x, Double_t *par)
{
    return ((TMath::Exp(par[0] + par[1] * x)) + par[2] + par[3] * x);
}
Double_t rootfitcjet(Double_t *x, Double_t *par)
{
    return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3] + x[0]);
}
Double_t rootfitlightjet(Double_t *x, Double_t *par)
{
    return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])));
}
void Fit()
{
    // setNCUStyle(true);
    TFile *Topfile = new TFile("./top/ee_Top_emjet_half.root");
    TFile *DYfile = new TFile("./DY/ee_DY_emjet_half.root");
    // TH1F *h_Top_fake_rate = ((TH1F *)Topfile->Get("Top_cjet_fakeRate"));
    // h_Top_fake_rate->SetTitle("light jet fakeRate (Top)");
    // h_Top_fake_rate->GetYaxis()->SetTitle("fake rate");
    // h_Top_fake_rate->GetXaxis()->SetTitle("Jet track multiplicity");
    // h_Top_fake_rate->GetXaxis()->SetRangeUser(1, 25);
    // h_Top_fake_rate->SetLineWidth(3);

    h_DY_fake_rate = ((TH1F *)DYfile->Get("HT_bjet_fakeRate"));
    h_DY_fake_rate->SetTitle("b jet fakeRate (DY)");
    h_DY_fake_rate->GetYaxis()->SetTitle("fake rate");
    h_DY_fake_rate->GetXaxis()->SetTitle("Jet track multiplicity");
    h_DY_fake_rate->GetXaxis()->SetRangeUser(1, 30);
    h_DY_fake_rate->SetLineWidth(3);
    auto c1 = new TCanvas("c1", "", 600, 800);

    // C r e a t e   m o d e l   a n d   d a t a s e t
    // -----------------------------------------------
    RooWorkspace *w = new RooWorkspace("w");
    
}