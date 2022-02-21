#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./lib/Cross_section.h"
using namespace std;

void Draw_Compare_alpha()
{

    //SetColor
    Int_t KIKYO = TColor::GetFreeColorIndex();
    TColor *KIKYO_color = new TColor(KIKYO,0.42,0.30,0.61);

    //-------Cross Section--------
    //  ex Pt-100To250 use PT100CS
    //----------------------------
    auto c1 = new TCanvas("c", "BPRE");
    //----Input Signal-------
    TFile *Mx2_1 = new TFile("./../../root_file/Ztoee/Mx2_1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/Ztoee/Mx2_50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/Ztoee/Mx2_150.root");

    TH1D *Mx2_1_alphamin = ((TH1D *)Mx2_1->Get("Event_Variable/h_aphmin"));
    TH1D *Mx2_50_alphamin = ((TH1D *)Mx2_50->Get("Event_Variable/h_aphmin"));
    TH1D *Mx2_150_alphamin = ((TH1D *)Mx2_150->Get("Event_Variable/h_aphmin"));
    TH1D *Mx2_1_met = ((TH1D *)Mx2_1->Get("Event_Variable/hmet"));
    TH1D *Mx2_50_met = ((TH1D *)Mx2_50->Get("Event_Variable/hmet"));
    TH1D *Mx2_150_met = ((TH1D *)Mx2_150->Get("Event_Variable/hmet"));
    
    //----Input Background--------
    TFile *DYHT = new TFile("./../../root_file/Ztoee/DYHT_All.root");
    TH1F *DYHT_alpha = ((TH1F *)DYHT->Get("h_ht0_aphmin"));
    TH1F *DYHT_met = ((TH1F *)DYHT->Get("h_ht0_met"));

    
    Mx2_1_alphamin->SetLineStyle(7);
    Mx2_50_alphamin->SetLineStyle(7);
    Mx2_150_alphamin->SetLineStyle(7);
    DYHT_alpha->SetLineStyle(7);

    Mx2_1_alphamin->SetLineWidth(2);
    Mx2_50_alphamin->SetLineWidth(2);
    Mx2_150_alphamin->SetLineWidth(2);
    DYHT_alpha->SetLineWidth(2);

    Mx2_1_alphamin->SetLineColor(kRed);
    Mx2_50_alphamin->SetLineColor(kBlue);
    Mx2_150_alphamin->SetLineColor(kBlack);
    DYHT_alpha->SetLineColor(kViolet);
    DYHT_alpha->SetFillColor(kViolet);
    DYHT_alpha->SetFillStyle(3003);

    //DYHT_met->SetFillStyle(3004);
    

    c1->Divide(2,1);
    c1->cd(1);
    Mx2_50_alphamin->SetStats(0);
    Mx2_50_alphamin->SetYTitle("N events/Normalized");
    Mx2_50_alphamin->SetXTitle("Alphamin");
    //Mx2_1_nT->GetYaxis()->SetRangeUser(0,1);
    Mx2_50_alphamin->DrawNormalized("hist");
    Mx2_1_alphamin->DrawNormalized("hist&&same");
    Mx2_150_alphamin->DrawNormalized("hist&&same");
    DYHT_alpha->DrawNormalized("hist&&same");
    TLegend *l1 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Mx2_1_alphamin, "ctau=1mm m_{x^{2}}=1", "l");
    l1->AddEntry(Mx2_50_alphamin, "ctau=10mm m_{x^{2}}=50", "l");
    l1->AddEntry(Mx2_150_alphamin, "ctau=1mm m_{x^{2}}=150", "l");
    l1->AddEntry(DYHT_alpha, "DYHT", "l");
    l1->Draw();

    c1->cd(2);

    Mx2_1_met->SetLineStyle(7);
    Mx2_50_met->SetLineStyle(7);
    Mx2_150_met->SetLineStyle(7);
    DYHT_met->SetLineStyle(7);

    Mx2_1_met->SetLineWidth(2);
    Mx2_50_met->SetLineWidth(2);
    Mx2_150_met->SetLineWidth(2);
    DYHT_met->SetLineWidth(2);

    Mx2_1_met->SetLineColor(kRed);
    Mx2_50_met->SetLineColor(kBlue);
    Mx2_150_met->SetLineColor(kBlack);
    DYHT_met->SetLineColor(kViolet);
    DYHT_met->SetFillStyle(1001);

    DYHT_met->SetStats(0);
    DYHT_met->SetYTitle("N events/Normalized");
    DYHT_met->SetXTitle("Met");
    DYHT_met->DrawNormalized("hist");
    Mx2_1_met->DrawNormalized("hist&&same");
    Mx2_150_met->DrawNormalized("hist&&same");
    Mx2_50_met->DrawNormalized("hist&&same");
    TLegend *l2 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Mx2_1_met, "ctau=1mm m_{x^{2}}=1", "l");
    l2->AddEntry(Mx2_50_met, "ctau=10mm m_{x^{2}}=50", "l");
    l2->AddEntry(Mx2_150_met, "ctau=1mm m_{x^{2}}=150", "l");
    l2->AddEntry(DYHT_met, "DYHT", "l");
    l2->Draw();

    /*
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
*/
}