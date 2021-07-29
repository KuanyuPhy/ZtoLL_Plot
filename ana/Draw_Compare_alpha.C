#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>

#include "Cross_section.h"
using namespace std;

void Draw_Compare_alpha()
{
    //-------Cross Section--------
    //  ex Pt-100To250 use PT100CS
    //----------------------------
    auto c1 = new TCanvas("c", "BPRE");
    //----Input Signal-------
    TFile *Mx2_1 = new TFile("./../../root_file/test/test1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/test/test50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/test/test150.root");

    TH1D *Mx2_1_nT = ((TH1D *)Mx2_1->Get("h_aphmax"));
    TH1D *Mx2_50_nT = ((TH1D *)Mx2_50->Get("h_aphmax"));
    TH1D *Mx2_150_nT = ((TH1D *)Mx2_150->Get("h_aphmax"));
    
    //----Input Background--------
    TFile *DYpT50 = new TFile("./../../root_file/test/test_pt50.root");
    TFile *DYpT100 = new TFile("./../../root_file/test/test_pt100.root");
    TFile *DYpT250 = new TFile("./../../root_file/test/test_pt250.root");
    TFile *DYpT400 = new TFile("./../../root_file/test/test_pt400.root");
    TFile *DYpT650 = new TFile("./../../root_file/test/test_pt650.root");

    TH1D *DYPT50_nT = ((TH1D *)DYpT50->Get("h_aphmax"));
    TH1D *DYPT100_nT = ((TH1D *)DYpT100->Get("h_aphmax"));
    TH1D *DYPT250_nT = ((TH1D *)DYpT250->Get("h_aphmax"));
    TH1D *DYPT400_nT = ((TH1D *)DYpT400->Get("h_aphmax"));
    TH1D *DYPT650_nT = ((TH1D *)DYpT650->Get("h_aphmax"));

    TH1D *DYPT50_sumW = ((TH1D *)DYpT50->Get("h_SumWeight"));
    TH1D *DYPT100_sumW = ((TH1D *)DYpT100->Get("h_SumWeight"));
    TH1D *DYPT250_sumW = ((TH1D *)DYpT250->Get("h_SumWeight"));
    TH1D *DYPT400_sumW = ((TH1D *)DYpT400->Get("h_SumWeight"));
    TH1D *DYPT650_sumW = ((TH1D *)DYpT650->Get("h_SumWeight"));

    double DYPT50_SW = DYPT50_sumW->GetBinContent(1);
    double DYPT100_SW = DYPT100_sumW->GetBinContent(1);
    double DYPT250_SW = DYPT250_sumW->GetBinContent(1);
    double DYPT400_SW = DYPT400_sumW->GetBinContent(1);
    double DYPT650_SW = DYPT650_sumW->GetBinContent(1);

    DYPT50_nT->Scale(PT50CS / DYPT50_SW);
    DYPT100_nT->Scale(PT100CS / DYPT100_SW);
    DYPT250_nT->Scale(PT250CS / DYPT250_SW);
    DYPT400_nT->Scale(PT400CS / DYPT400_SW);
    DYPT650_nT->Scale(PT650CS / DYPT650_SW);

    DYPT50_nT->Add(DYPT100_nT);
    DYPT50_nT->Add(DYPT250_nT);
    DYPT50_nT->Add(DYPT400_nT);
    DYPT50_nT->Add(DYPT650_nT);


    
    Mx2_1_nT->SetLineStyle(7);
    Mx2_50_nT->SetLineStyle(7);
    Mx2_150_nT->SetLineStyle(7);
    DYPT50_nT->SetLineStyle(7);

    Mx2_1_nT->SetLineWidth(2);
    Mx2_50_nT->SetLineWidth(2);
    Mx2_150_nT->SetLineWidth(2);
    DYPT50_nT->SetLineWidth(2);

    Mx2_1_nT->SetLineColor(kRed);
    Mx2_50_nT->SetLineColor(kBlue);
    Mx2_150_nT->SetLineColor(kBlack);
    DYPT50_nT->SetLineColor(kViolet);
    DYPT50_nT->SetFillColor(kViolet);

    c1->Divide(2,2);
    c1->cd(1);
    Mx2_1_nT->SetStats(0);
    Mx2_1_nT->SetYTitle("N events");
    Mx2_1_nT->Draw();
    TLegend *l1 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Mx2_1_nT, "ctau=1mm m_{x^{2}}=1", "l");
    l1->Draw();

    c1->cd(2);
    Mx2_50_nT->SetStats(0);
    Mx2_50_nT->SetYTitle("N events");
    Mx2_50_nT->Draw();
    TLegend *l2 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Mx2_50_nT, "ctau=10mm m_{x^{2}}=50", "l");
    l2->Draw();

    c1->cd(3);
    Mx2_150_nT->SetStats(0);
    Mx2_150_nT->SetYTitle("N events");
    Mx2_150_nT->Draw();

    TLegend *l3 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.04);
    l3->AddEntry(Mx2_150_nT, "ctau=1mm m_{x^{2}}=150", "l");
    l3->Draw();

    c1->cd(4);
    DYPT50_nT->SetStats(0);
    DYPT50_nT->SetYTitle("N events");
    DYPT50_nT->Draw();

    TLegend *l4 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.04);
    l4->AddEntry(DYPT50_nT, "DYJets_pTBin", "l");
    l4->Draw();

}