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

using namespace RooFit;
//#include "TRooH1D.h"
//#include "Cross_section.h"

// Quadratic background function
Double_t background(Double_t *x, Double_t *par)
{
    return par[0] + par[1] * x[0] + par[2] * x[0] * x[0];
}

// Lorentzian Peak function
Double_t lorentzianPeak(Double_t *x, Double_t *par)
{
    return (0.5 * par[0] * par[1] / TMath::Pi()) / TMath::Max(1.e-10,
                                                              (x[0] - par[2]) * (x[0] - par[2]) + .25 * par[1] * par[1]);
}


void BGEM_fit()
{
    setNCUStyle(true);
    TFile *ABCD = new TFile("./../../ABCD_HT.root");

    TH1F *h_ht70A_aphmin = ((TH1F *)ABCD->Get("h_ht70A_aphmin"));
    h_ht70A_aphmin->GetXaxis()->SetTitle("alphamin");

    //TH1F *h_ht70A_met = ((TH1F *)ABCD->Get("h_ht70A_met"));
    

    TH1F *h_ht70B_aphmin = ((TH1F *)ABCD->Get("h_ht70B_aphmin"));
    h_ht70B_aphmin->GetXaxis()->SetTitle("alphamin");
/*
    TH1F *h_pt50_B_met = ((TH1F *)ABCD->Get("h_pt50_B_met"));
    h_pt50_B_met->GetXaxis()->SetTitle("Met");

    TH1F *h_pt50_C_alphamin = ((TH1F *)ABCD->Get("h_pt50_C_alphamin"));
    TH1F *h_pt50_C_met = ((TH1F *)ABCD->Get("h_pt50_C_met"));

    TH1F *h_pt50_D_alphamin = ((TH1F *)ABCD->Get("h_pt50_D_alphamin"));
    TH1F *h_pt50_D_met = ((TH1F *)ABCD->Get("h_pt50_D_met"));
*/
    //TH1F *h_ht70A_aphmin = ((TH1F *)ABCD->Get("h_ht70A_aphmin"));
    //TH1F *h_pt50B_aphmin = ((TH1F *)ABCD->Get("h_pt50B_aphmin"));

    TH1F *h_ht70A_met = ((TH1F *)ABCD->Get("h_ht70A_met"));
    h_ht70A_met->SetTitle("ratio of Met");
    h_ht70A_met->GetXaxis()->SetTitle("Met");
    h_ht70A_met->GetXaxis()->SetLabelSize(0.03);
    h_ht70A_met->GetYaxis()->SetLabelSize(0.03);
    TH1F *h_ht70B_met = ((TH1F *)ABCD->Get("h_ht70B_met"));    

    //h_ht70A_aphmin->Divide(h_ht70B_aphmin);
    //h_ht70A_aphmin->Draw();

    h_ht70A_met->Divide(h_ht70B_met);
    //h_pt50A_met->GetXaxis()->SetRangeUser(0,750);
    int nBin = h_ht70A_met->GetNbinsX();
    cout << nBin << endl;
    h_ht70A_met->Draw();


    float metAB_xmin = h_ht70A_met->GetXaxis()->GetXmin();
    float metAB_xax = h_ht70A_met->GetXaxis()->GetXmax();
    TF1 *f2 = new TF1("f2", "landau", metAB_xmin, metAB_xax);
    gStyle->SetOptFit(0001111);
    h_ht70A_met->Fit("f2", "IMF");

    c1->SetLogy();


    float alpmaAB_xmin = h_ht70A_aphmin->GetXaxis()->GetXmin();
    float alpmaAB_xax = h_ht70A_aphmin->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", "expo(3)*pol3", alpmaAB_xmin, alpmaAB_xax);
    gStyle->SetOptFit(1111);
    h_ht70A_aphmin->SetMarkerColor(kBlack);
    f1->SetLineStyle(kSolid);
    //h_ht70A_aphmin->Fit("f1", "IMF");



    //h_pt50_B_alphamin->Divide(h_pt50_D_alphamin);
    //h_pt50_B_alphamin->Draw();

    //float alpma_xmin = h_pt50_A_alphamin->GetXaxis()->GetXmin();
    //float alpma_xax = h_pt50_A_alphamin->GetXaxis()->GetXmax();

    //TCanvas *c1 = new TCanvas("Simfit", "Simultaneous fit of two histograms",10, 10, 700, 700);
    //c1->Divide(1, 2);
    //c1->cd(1);

    //gStyle->SetOptFit(1111);

    //TF1 *f1 = new TF1("f1", "pol6", alpma_xmin, alpma_xax);

    //h_pt50_C_met->Divide(h_pt50_D_met);

    //h_pt50_A_alphamin->Fit("f1", "LFM");

    //h_pt50_C_met->Draw();

    //float met_xmin = h_pt50_C_met->GetXaxis()->GetXmin();
    //float met_xax = h_pt50_C_met->GetXaxis()->GetXmax();
    //TF1 *f2 = new TF1("f2", "expo+pol2", met_xmin, met_xax);
    //TF1 *f2 = new TF1("f2", "x*sin(x) ", met_xmin, met_xax);

    //c1->cd(2);

    //h_pt50_C_met->Fit("f2", "LFM");

}