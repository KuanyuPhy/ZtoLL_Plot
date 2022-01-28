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
    return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3] + par[4] * x[0] + par[5] * x[0] * x[0] + par[6] * x[0] * x[0] * x[0]);
    // return ((TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0]))+(TMath::Exp(par[3] + par[4] * x[0] ))+ par[5]);
    //  return ((par[0] + par[1] * x[0] + par[2] * ((2*x[0]* x[0])-1)));
    //   f(x) = p0 + p1*x + p2*(2*x2-1)
    //    return (TMath::Exp(par[0] + par[1] * x[0])+ par[2]);
    //    return par[0] + par[1] * x[0] + par[2] * x[0] * x[0];
}

void BGEM_Top_fit()
{
    setNCUStyle(true);
    TFile *ABCD = new TFile("./../../ABCD_Top.root");

    TH1F *h_Top_met_Ratio = ((TH1F *)ABCD->Get("h_Top_met_Ratio"));
    TH1F *h_Top_met_A = ((TH1F *)ABCD->Get("h_Top_met_A"));
    TH1F *h_Top_met_B = ((TH1F *)ABCD->Get("h_Top_met_B"));
    
    h_Top_met_Ratio->GetXaxis()->SetTitle("met");

    h_Top_met_A->SetLineWidth(3);
    h_Top_met_B->SetLineWidth(3);
    h_Top_met_Ratio->SetLineWidth(3);

    Float_t metAB_xmin = h_Top_met_Ratio->GetXaxis()->GetXmin();
    Float_t metAB_xmax = h_Top_met_Ratio->GetXaxis()->GetXmax();

    TF1 *f2 = new TF1("f2", "pol3", metAB_xmin, metAB_xmax);


    f2->SetLineWidth(3);
    //h_Top_met_B->Draw("text45");
    //h_Top_met_Ratio->Fit("f2", "MF");
    //h_Top_met_Ratio->SetTitle("");
    h_Top_met_Ratio->Draw();

    // h_pt50_C_met->Fit("f2", "LFM");

    //TFile *outFile = new TFile("./../../ABCD_fit.root", "RECREATE");
    //outFile->cd();
    //h_ht0A_met->Write();
}