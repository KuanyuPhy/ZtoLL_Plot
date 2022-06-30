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
using namespace std;

// define punzi_eq
double punzi(double sigeff, double bg)
{
    return sigeff / (1 + TMath::Power(abs(bg), 0.5));
}

void ana_punzi()
{
    TFile *Sigfile = new TFile("./ee_Sig_punzi.root");
    TFile *DYfile = new TFile("./ee_DY_punzi.root");

    TH1D *h_Mx2_1_eff = ((TH1D *)Sigfile->Get("h_Mx2_1_eff"));
    TH1D *h_Mx2_50_eff = ((TH1D *)Sigfile->Get("h_Mx2_50_eff"));
    TH1D *h_Mx2_150_eff = ((TH1D *)Sigfile->Get("h_Mx2_150_eff"));
    TH1D *h_pass_DY = ((TH1D *)DYfile->Get("h_pass_DY"));

    h_Mx2_1_eff->Draw();

    double DY_nbg = h_pass_DY->GetBinContent(2);
    cout << "DY_nbg =" << DY_nbg << endl;

    double Sig1_eff[50];
    double Sig50_eff[50];
    double Sig150_eff[50];

    double Sig1_punzi[50];
    double Sig50_punzi[50];
    double Sig150_punzi[50];
    for (int i = 1; i <= 50; i++)
    {
        Sig1_punzi[i] = punzi(h_Mx2_1_eff->GetBinContent(i + 1), DY_nbg);
        Sig50_punzi[i] = punzi(h_Mx2_50_eff->GetBinContent(i + 1), DY_nbg);
        Sig150_punzi[i] = punzi(h_Mx2_150_eff->GetBinContent(i + 1), DY_nbg);
        cout << "i =" << i << endl;
        cout << "Sig_eff =" << h_Mx2_1_eff->GetBinContent(i + 1) << endl;
    }

    TH1D *h_punzisig1 = new TH1D("h_punzisig1", "", 50, 0, 50);
    TH1D *h_punzisig50 = new TH1D("h_punzisig50", "", 50, 0, 50);
    TH1D *h_punzisig150 = new TH1D("h_punzisig150", "", 50, 0, 50);
    for (int i = 1; i <= 50; i++)
    {
        h_punzisig1->SetBinContent(i + 1, Sig1_punzi[i]);
        h_punzisig50->SetBinContent(i + 1, Sig50_punzi[i]);
        h_punzisig150->SetBinContent(i + 1, Sig150_punzi[i]);
    }
    h_punzisig1->SetLineWidth(2);
    h_punzisig50->SetLineWidth(2);
    h_punzisig150->SetLineWidth(2);

    h_punzisig1->SetLineColor(kRed);
    h_punzisig50->SetLineColor(kBlack);
    h_punzisig150->SetLineColor(kBlue);

    h_punzisig1->GetYaxis()->SetTitle("punzisig");
    //h_punzisig1->GetXaxis()->SetTitle("steps");

    h_punzisig1->GetXaxis()->SetBinLabel(1, "Met > 10");
    // h_punzisig1->GetXaxis()->SetBinLabel(2, "Met > 20");
    // h_punzisig1->GetXaxis()->SetBinLabel(3, "Met > 30");
    h_punzisig1->GetXaxis()->SetBinLabel(5, "Met > 50");
    h_punzisig1->GetXaxis()->SetBinLabel(10, "Met > 100");
    h_punzisig1->GetXaxis()->SetBinLabel(20, "Met > 200");
    h_punzisig1->GetXaxis()->SetBinLabel(30, "Met > 300");
    h_punzisig1->GetXaxis()->SetBinLabel(40, "Met > 400");
    h_punzisig1->GetXaxis()->SetBinLabel(45, "Met > 450");
    h_punzisig1->GetXaxis()->SetBinLabel(50, "Met > 500");

    h_punzisig1->Draw();
    h_punzisig50->Draw("same");
    h_punzisig150->Draw("same");

    gStyle->SetOptStat(0);

    TLegend *l1 = new TLegend(0.60, 0.55, 0.70, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_punzisig1, "ctau=1mm m_{x^{2}}=1 GeV", "l");
    l1->AddEntry(h_punzisig50, "ctau=10mm m_{x^{2}}=50 GeV", "l");
    l1->AddEntry(h_punzisig150, "ctau=1mm m_{x^{2}}=150 GeV", "l");
    // l1->AddEntry(h_TTTo2L2Nu_Median_2DIPsig, "Top process", "l");
    l1->Draw();
}