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
    // return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3]+ par[4] * x[0] + par[5] * x[0] * x[0]  );
    return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3] + par[4] * x[0] + par[5] * x[0] * x[0] );
    // return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0]))+(TMath::Exp(par[3] + par[4] * x[0] ))+ par[5]);
    //  return ((par[0] + par[1] * x[0] + par[2] * ((2*x[0]* x[0])-1)));
    //   f(x) = p0 + p1*x + p2*(2*x2-1)
    //    return (TMath::Exp(par[0] + par[1] * x[0])+ par[2]);
    //    return par[0] + par[1] * x[0] + par[2] * x[0] * x[0];
}

void BGEM_DY_fit()
{
    setNCUStyle(true);
    TFile *ABCD = new TFile("./../../ABCD_HT.root");

    TH1F *h_DYHT_alphmin_Ratio = ((TH1F *)ABCD->Get("h_DYHT_alphmin_Ratio"));
    h_DYHT_alphmin_Ratio->GetXaxis()->SetTitle("alphamin");

    // TH1F *h_ht70A_aphmin = ((TH1F *)ABCD->Get("h_ht70A_aphmin"));
    // TH1F *h_pt50B_aphmin = ((TH1F *)ABCD->Get("h_pt50B_aphmin"));

    TH1F *h_DYHT_met_Ratio = ((TH1F *)ABCD->Get("h_DYHT_met_Ratio"));
    h_DYHT_met_Ratio->SetTitle("ratio of Met");
    h_DYHT_met_Ratio->GetXaxis()->SetTitle("Met");
    h_DYHT_met_Ratio->GetXaxis()->SetLabelSize(0.03);
    h_DYHT_met_Ratio->GetYaxis()->SetLabelSize(0.03);

    h_DYHT_met_Ratio->SetMarkerSize(2);
    // h_DYHT_met_Ratio->GetXaxis()->SetRangeUser(0, 300);

    TH1F *h_DYHT_met_Ratio_sub;
    h_DYHT_met_Ratio_sub = (TH1F *)h_DYHT_met_Ratio->Clone("h_DYHT_met_Ratio_sub");
    h_DYHT_met_Ratio_sub->GetXaxis()->SetRangeUser(0, 200);
    // h_DYHT_met_Ratio_sub->Draw("text");

    h_DYHT_met_Ratio->SetLineWidth(3);
    h_DYHT_met_Ratio->Draw("");

    TH1F *h_DYHT_met_A = ((TH1F *)ABCD->Get("h_DYHT_met_A"));
    TH1F *h_DYHT_met_B = ((TH1F *)ABCD->Get("h_DYHT_met_B"));

    h_DYHT_met_A->SetLineWidth(3);
    h_DYHT_met_B->SetLineWidth(3);

    Float_t metAB_xmin = h_DYHT_met_Ratio->GetXaxis()->GetXmin();
    Float_t metAB_xax = h_DYHT_met_Ratio->GetXaxis()->GetXmax();
    // cout << metAB_xmin << endl;
    cout << metAB_xax << endl;
    // TF1 *fitFcn = new TF1("fitFcn",background,0,3,6);

    TF1 *f2 = new TF1("f2", background, metAB_xmin, metAB_xax, 6);

    f2->SetLineWidth(2);

    TF1 *exp1 = new TF1("exp1", "expo", metAB_xmin, metAB_xax);
    // TF1 *exp2 = new TF1("exp2", "expo+pol2", metAB_xmin, metAB_xax);
    TF1 *f3 = new TF1("f3", "expo", metAB_xmin, metAB_xax);
    // f2->SetParLimits(2, 0,1);
    // TF1 *f2 = new TF1("f2", , metAB_xmin, metAB_xax);

    // f2->SetParLimits(2,0,5);
    // gStyle->SetOptFit(0001111);

    //h_DYHT_met_Ratio->Fit("f2", "MF");

    //h_DYHT_met_A->Draw("text45");

    // h_DYHT_met_Ratio_sub->Fit("f2", "M");

    // c1->SetLogy();

    // float alpmaAB_xmin = h_ht0A_aphmin->GetXaxis()->GetXmin();
    // float alpmaAB_xax = h_ht0A_aphmin->GetXaxis()->GetXmax();
    // cout << alpmaAB_xmin << endl;
    // cout << alpmaAB_xax << endl;
    // TF1 *f1 = new TF1("f1", "pol6", alpmaAB_xmin, alpmaAB_xax);
    // gStyle->SetOptFit(1111);
    // h_ht0A_aphmin->SetMarkerColor(kBlack);
    // f1->SetLineStyle(kSolid);
    // h_ht0A_aphmin->Fit("f1", "MF");

    // h_ht70A_aphmin->Fit("f1", "IMF");

    // h_pt50_B_alphamin->Divide(h_pt50_D_alphamin);
    // h_pt50_B_alphamin->Draw();

    // float alpma_xmin = h_pt50_A_alphamin->GetXaxis()->GetXmin();
    // float alpma_xax = h_pt50_A_alphamin->GetXaxis()->GetXmax();

    // TCanvas *c1 = new TCanvas("Simfit", "Simultaneous fit of two histograms",10, 10, 700, 700);
    // c1->Divide(1, 2);
    // c1->cd(1);

    // gStyle->SetOptFit(1111);

    // TF1 *f1 = new TF1("f1", "pol6", alpma_xmin, alpma_xax);

    // h_pt50_C_met->Divide(h_pt50_D_met);

    // h_pt50_A_alphamin->Fit("f1", "LFM");

    // h_pt50_C_met->Draw();

    // float met_xmin = h_pt50_C_met->GetXaxis()->GetXmin();
    // float met_xax = h_pt50_C_met->GetXaxis()->GetXmax();
    // TF1 *f2 = new TF1("f2", "expo+pol2", met_xmin, met_xax);
    // TF1 *f2 = new TF1("f2", "x*sin(x) ", met_xmin, met_xax);

    // c1->cd(2);

    // h_pt50_C_met->Fit("f2", "LFM");

    TFile *outFile = new TFile("./../../ABCD_fit.root", "RECREATE");
    outFile->cd();
    h_DYHT_met_Ratio->Write();
}