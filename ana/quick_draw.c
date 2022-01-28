#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./lib/Cross_section.h"
#include "setNCUStyle.C"
using namespace std;
void quick_draw()
{

    Int_t KON = TColor::GetFreeColorIndex();
    TColor *KON_color = new TColor(KON, 0.06, 0.15, 0.25);
    Int_t HIWAMOEGI = TColor::GetFreeColorIndex();
    TColor *HIWAMOEGI_color = new TColor(HIWAMOEGI, 0.56, 0.71, 0.29);

    Int_t KARACHA = TColor::GetFreeColorIndex();
    TColor *KARACHA_color = new TColor(KARACHA, 0.71, 0.44, 0.34);

    Int_t JINZAMOMI = TColor::GetFreeColorIndex();
    TColor *JINZAMOMI_color = new TColor(JINZAMOMI, 0.92, 0.478, 0.46);

    Int_t BENIUKON = TColor::GetFreeColorIndex();
    TColor *BENIUKON_color = new TColor(BENIUKON, 0.913, 0.545, 0.16);

    Int_t SHIRACHA = TColor::GetFreeColorIndex();
    TColor *SHIRACHA_color = new TColor(SHIRACHA, 0.73, 0.623, 0.47);

    Int_t KARIYASU = TColor::GetFreeColorIndex();
    TColor *KARIYASU_color = new TColor(KARIYASU, 0.913, 0.803, 0.298);

    Int_t MIZUASAGI = TColor::GetFreeColorIndex();
    TColor *MIZUASAGI_color = new TColor(MIZUASAGI, 0.4, 0.729, 0.718);

    Int_t MATSUBA = TColor::GetFreeColorIndex();
    TColor *MATSUBA_color = new TColor(MATSUBA, 0.259, 0.376, 0.176);

    setNCUStyle(true);

    TFile *Mx2_1 = new TFile("./../../root_file/Ztoee/Mx2_1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/Ztoee/Mx2_50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/Ztoee/Mx2_150.root");

    TFile *DYHT = new TFile("./../../root_file/Ztoee/DYHT_All.root");
    TFile *Top = new TFile("./../../root_file/Ztoee/Top_All.root");

    TH1F *DYHTleadeta = ((TH1F *)DYHT->Get("h_ht0_leadjeteta"));
    TH1F *DYHTmineta = ((TH1F *)DYHT->Get("h_ht0_minjeteta"));
    TH1F *DYHT_nJets = ((TH1F *)DYHT->Get("h_ht0_njet"));
    TH1F *DYHT_Met = ((TH1F *)DYHT->Get("h_ht0_met"));
    TH1F *DYHT_alphamin = ((TH1F *)DYHT->Get("h_ht0_aphmin"));

    TH1F *Top_quark_nThinJets = ((TH1F *)Top->Get("Top_quark_nThinJets"));

    // DYHT eta
    TH1F *h_Mx1_jeteta = new TH1F("h_Mx1_jeteta", "leading jet eta", 100, -5, 5);
    h_Mx1_jeteta->Sumw2();
    TH1F *h_Mx50_jeteta = new TH1F("h_Mx50_jeteta", "leading jet eta", 100, -5, 5);
    h_Mx50_jeteta->Sumw2();
    TH1F *h_Mx150_jeteta = new TH1F("h_Mx150_jeteta", "leading jet eta", 100, -5, 5);
    h_Mx150_jeteta->Sumw2();

    // nJets
    TH1F *h_Mx1_njet = new TH1F("h_Mx1_njet", "nJets", 15, 0, 15);
    h_Mx1_njet->Sumw2();
    TH1F *h_Mx50_njet = new TH1F("h_Mx50_njet", "nJets", 15, 0, 15);
    h_Mx50_njet->Sumw2();
    TH1F *h_Mx150_njet = new TH1F("h_Mx150_njet", "nJets", 15, 0, 15);
    h_Mx150_njet->Sumw2();

    // Met
    TH1F *h_Mx1_Met = new TH1F("h_Mx1_Met", "Met", 20, 0, 800);
    h_Mx1_Met->Sumw2();
    TH1F *h_Mx50_Met = new TH1F("h_Mx50_Met", "Met", 20, 0, 800);
    h_Mx50_Met->Sumw2();
    TH1F *h_Mx150_Met = new TH1F("h_Mx150_Met", "Met", 20, 0, 800);
    h_Mx150_Met->Sumw2();

    TH1F *h_Mx1_alphamin = new TH1F("h_Mx1_alphamin", "", 24, 0, 1.2);
    h_Mx1_alphamin->SetXTitle("alphamin");
    h_Mx1_alphamin->SetYTitle("");
    h_Mx1_alphamin->Sumw2();

    TH1F *h_Mx50_alphamin = new TH1F("h_Mx50_alphamin", "", 24, 0, 1.2);
    h_Mx50_alphamin->SetXTitle("");
    h_Mx50_alphamin->SetYTitle("");
    h_Mx50_alphamin->Sumw2();

    TH1F *h_Mx150_alphamin = new TH1F("h_Mx150_alphamin", "", 24, 0, 1.2);
    h_Mx150_alphamin->SetXTitle("");
    h_Mx150_alphamin->SetYTitle("");
    h_Mx150_alphamin->Sumw2();

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;
    Int_t I_Mx1_nThinJets, I_Mx50_nThinJets, I_Mx150_nThinJets;
    float_t f_Mx1_jeteta, f_Mx50_jeteta, f_Mx150_jeteta;
    float_t f_Mx1_Met, f_Mx50_Met, f_Mx150_Met;
    Double_t d_Mx1_alphamin, d_Mx50_alphamin, d_Mx150_alphamin;

    TTree *Mx1_tree;
    Mx2_1->GetObject("T_event", Mx1_tree);
    Mx1_tree->SetBranchAddress("I_weight", &I_Mx1_weight);
    Mx1_tree->SetBranchAddress("f_leadJeteta", &f_Mx1_jeteta);
    Mx1_tree->SetBranchAddress("I_nThinJets", &I_Mx1_nThinJets);
    Mx1_tree->SetBranchAddress("f_Met", &f_Mx1_Met);
    Mx1_tree->SetBranchAddress("f_alphamin", &d_Mx1_alphamin);

    for (int evt = 0; evt < Mx1_tree->GetEntries(); evt++)
    {
        Mx1_tree->GetEntry(evt);
        if (I_Mx1_nThinJets < 2)
            continue;
        h_Mx1_jeteta->Fill(f_Mx1_jeteta, I_Mx1_weight);
        h_Mx1_njet->Fill(I_Mx1_nThinJets, I_Mx1_weight);
        h_Mx1_Met->Fill(f_Mx1_Met, I_Mx1_weight);
        h_Mx1_alphamin->Fill(d_Mx1_alphamin, I_Mx1_weight);
    }
    TTree *Mx50_tree;
    Mx2_50->GetObject("T_event", Mx50_tree);
    Mx50_tree->SetBranchAddress("I_weight", &I_Mx50_weight);
    Mx50_tree->SetBranchAddress("f_leadJeteta", &f_Mx50_jeteta);
    Mx50_tree->SetBranchAddress("I_nThinJets", &I_Mx50_nThinJets);
    Mx50_tree->SetBranchAddress("f_Met", &f_Mx50_Met);
    Mx50_tree->SetBranchAddress("f_alphamin", &d_Mx50_alphamin);
    for (int evt = 0; evt < Mx50_tree->GetEntries(); evt++)
    {
        Mx50_tree->GetEntry(evt);
        if (I_Mx50_nThinJets < 2)
            continue;
        h_Mx50_jeteta->Fill(f_Mx50_jeteta, I_Mx50_weight);
        h_Mx50_njet->Fill(I_Mx50_nThinJets, I_Mx50_weight);
        h_Mx50_Met->Fill(f_Mx50_Met, I_Mx50_weight);
        h_Mx50_alphamin->Fill(d_Mx50_alphamin, I_Mx50_weight);
    }
    TTree *Mx150_tree;
    Mx2_150->GetObject("T_event", Mx150_tree);
    Mx150_tree->SetBranchAddress("I_weight", &I_Mx150_weight);
    Mx150_tree->SetBranchAddress("f_leadJeteta", &f_Mx150_jeteta);
    Mx150_tree->SetBranchAddress("I_nThinJets", &I_Mx150_nThinJets);
    Mx150_tree->SetBranchAddress("f_Met", &f_Mx150_Met);
    Mx150_tree->SetBranchAddress("f_alphamin", &d_Mx150_alphamin);
    for (int evt = 0; evt < Mx150_tree->GetEntries(); evt++)
    {
        Mx150_tree->GetEntry(evt);
        if (I_Mx150_nThinJets < 2)
            continue;
        h_Mx150_jeteta->Fill(f_Mx150_jeteta, I_Mx150_weight);
        h_Mx150_njet->Fill(I_Mx150_nThinJets, I_Mx150_weight);
        h_Mx150_Met->Fill(f_Mx150_Met, I_Mx150_weight);
        h_Mx150_alphamin->Fill(d_Mx150_alphamin, I_Mx150_weight);
    }

    h_Mx150_njet->SetLineStyle(7);
    h_Mx1_njet->SetLineStyle(7);
    h_Mx50_njet->SetLineStyle(7);
    DYHT_nJets->SetLineStyle(7);
    // DYHTeta_metcut->SetLineStyle(7);

    h_Mx1_njet->SetStats(0);
    h_Mx1_njet->SetLineWidth(2);
    h_Mx1_njet->SetLineColor(kRed);
    h_Mx50_njet->SetLineWidth(2);
    h_Mx50_njet->SetLineColor(kBlue);
    h_Mx150_njet->SetLineWidth(2);
    h_Mx150_njet->SetLineColor(kBlack);

    h_Mx1_Met->SetLineWidth(2);
    h_Mx1_Met->SetLineColor(kRed);
    h_Mx50_Met->SetLineWidth(2);
    h_Mx50_Met->SetLineColor(kBlue);
    h_Mx150_Met->SetLineWidth(2);
    h_Mx150_Met->SetLineColor(kBlack);

    h_Mx1_alphamin->SetLineWidth(2);
    h_Mx1_alphamin->SetLineColor(kRed);
    h_Mx50_alphamin->SetLineWidth(2);
    h_Mx50_alphamin->SetLineColor(kBlue);
    h_Mx150_alphamin->SetLineWidth(2);
    h_Mx150_alphamin->SetLineColor(kBlack);

    DYHT_nJets->SetLineWidth(2);
    DYHT_nJets->SetLineColor(HIWAMOEGI);

    DYHTmineta->SetLineWidth(2);
    DYHTmineta->SetLineColor(MIZUASAGI);

    DYHT_alphamin->SetLineWidth(2);
    DYHT_alphamin->SetLineColor(HIWAMOEGI);
    DYHT_alphamin->SetFillColor(HIWAMOEGI);
    DYHT_alphamin->SetFillStyle(3001);

    DYHTleadeta->SetLineWidth(2);
    DYHTleadeta->SetLineColor(HIWAMOEGI);

    DYHT_Met->SetLineWidth(2);
    DYHT_Met->SetLineColor(HIWAMOEGI);
    DYHT_Met->SetFillColor(HIWAMOEGI);
    DYHT_Met->SetFillStyle(3001);

    Top_quark_nThinJets->SetLineWidth(2);
    Top_quark_nThinJets->SetLineColor(KON);

    auto c2 = new TCanvas("c", "BPRE");
    // c2->Divide(2, 1);
    // c2->cd(1);
    DYHT_Met->SetTitle("MET");
    h_Mx50_alphamin->GetYaxis()->SetTitle("N events /Normalized");
    h_Mx50_alphamin->GetXaxis()->SetTitle("#alpha_{3D_{min}}");
    h_Mx50_alphamin->GetXaxis()->SetTitleSize(0.04);
    h_Mx50_alphamin->GetYaxis()->SetTitleOffset(1.5);
    h_Mx50_alphamin->GetXaxis()->SetTitleOffset(1.4);
    h_Mx50_alphamin->GetYaxis()->SetTitleSize(0.04);
    DYHT_Met->GetXaxis()->SetTitle("Met");
    h_Mx50_alphamin->DrawNormalized("hist");
    h_Mx1_alphamin->DrawNormalized("hist&&same");
    DYHT_alphamin->DrawNormalized("hist&&same");

    // c2->cd(2);

    h_Mx150_alphamin->DrawNormalized("hist&&same");

    // Top_quark_nThinJets->Draw("hist&&text45");
    // auto c1 = new TCanvas("c", "BPRE");

    // DYHTleadeta->Draw("hist&&same");
    // DYHTmineta->Draw("hist&&same");
    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_Mx1_alphamin, "ctau=1mm m_{x^{2}}=1", "f");
    l1->AddEntry(h_Mx50_alphamin, "ctau=10mm m_{x^{2}}=50", "f");
    l1->AddEntry(h_Mx150_alphamin, "ctau=1mm m_{x^{2}}=150", "f");
    l1->AddEntry(DYHT_alphamin, "Drell-Yan", "f");
    l1->Draw();

    TLatex CMS;
    CMS.DrawLatex(0.1, 0.8, "CMS");
    TLatex Sim;
    Sim.SetTextFont(12);
    Sim.DrawLatex(0.1, 0.75, "Simulation");

    TLatex Energy;
    Energy.SetTextFont(12);
    Energy.SetTextSize(0.03);
    Energy.DrawLatex(1, 0.99, "(13TeV)");

    // DYHTeta->SetFillColor(kViolet);
    //  DYHTeta->SetFillStyle(3003);

    // h_Mx50_jeteta->SetYTitle("Events/Normalized");
    // h_Mx50_jeteta->GetYaxis()->SetTitleOffset(1.5);

    /*
    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(3, 2);
    c1->cd(1);
    TLegend *l1 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_Mx1_njet, "ctau=1mm m_{x^{2}}=1", "l");
    h_Mx1_njet->Draw("hist&&text45");
    l1->Draw();

    c1->cd(2);
    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(h_Mx50_njet, "ctau=10mm m_{x^{2}}=50", "l");
    h_Mx50_njet->Draw("hist&&text45");
    l2->Draw();

    c1->cd(3);
    TLegend *l3 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.03);
    l3->AddEntry(h_Mx150_njet, "ctau=1mm m_{x^{2}}=150", "l");
    h_Mx150_njet->Draw("hist&&text45");
    l3->Draw();
    */

    // c1->cd(4);
    // TLegend *l4 = new TLegend(0.60, 0.55, 0.90, 0.90);
    // l4->SetBorderSize(0);
    // l4->SetTextSize(0.03);
    // l4->AddEntry(DYHT_nJets, "DYHT", "l");
    // DYHT_nJets->Draw("hist");
    // l4->Draw();

    // c1->cd(5);
    // TLegend *l5 = new TLegend(0.60, 0.55, 0.90, 0.90);
    // l5->SetBorderSize(0);
    // l5->SetTextSize(0.03);
    // l5->AddEntry(DYHTeta_metcut, "DYHT(Met > 90)", "l");
    // DYHTeta_metcut->Draw("hist");
    // l5->Draw();

    // l2->AddEntry(DYHTeta, "DYHT", "l");
    //  l2->AddEntry(DYPT50_nT, "DYJets_pTBin", "l");

    // c1->SetLogy();
    // c1->SaveAs("h_jet_n;1.png");
}