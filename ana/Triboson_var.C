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
#include "./lib/Cross_section.h"
using namespace RooFit;

void Triboson_var()
{
    // SetColor
    Int_t KIKYO = TColor::GetFreeColorIndex();
    TColor *KIKYO_color = new TColor(KIKYO, 0.42, 0.30, 0.61);
    Int_t KON = TColor::GetFreeColorIndex();
    TColor *KON_color = new TColor(KON, 0.06, 0.15, 0.25);
    Int_t KARACHA = TColor::GetFreeColorIndex();
    TColor *KARACHA_color = new TColor(KARACHA, 0.71, 0.44, 0.34);

    TFile *Triboson_WWZ = new TFile("./../../root_file/Ztoee/2016BKGMC/triboson/triboson_WWZ.root");
    TFile *Triboson_WZZ = new TFile("./../../root_file/Ztoee/2016BKGMC/triboson/triboson_WZZ.root");
    TFile *Triboson_ZZZ = new TFile("./../../root_file/Ztoee/2016BKGMC/triboson/triboson_ZZZ.root");

    TH1D *WWZ_sumevt = ((TH1D *)Triboson_WWZ->Get("Event_Variable/h_event"));
    TH1D *WZZ_sumevt = ((TH1D *)Triboson_WZZ->Get("Event_Variable/h_event"));
    TH1D *ZZZ_sumevt = ((TH1D *)Triboson_ZZZ->Get("Event_Variable/h_event"));

    int WWZ_totevt = WWZ_sumevt->Integral();
    int WZZ_totevt = WZZ_sumevt->Integral();
    int ZZZ_totevt = ZZZ_sumevt->Integral();

    // DYHT
    TH1F *Triboson_WWZ_aphmin = new TH1F("Triboson_WWZ_aphmin", "", 24, 0, 1.2);
    Triboson_WWZ_aphmin->Sumw2();

    TH1F *Triboson_WZZ_aphmin = new TH1F("Triboson_WZZ_aphmin", "", 24, 0, 1.2);
    Triboson_WZZ_aphmin->Sumw2();

    TH1F *Triboson_ZZZ_aphmin = new TH1F("Triboson_ZZZ_aphmin", "", 24, 0, 1.2);
    Triboson_ZZZ_aphmin->Sumw2();

    // Top
    TH1F *Triboson_WWZ_met = new TH1F("Triboson_WWZ_met", "", 20, 0, 800);
    Triboson_WWZ_met->Sumw2();

    TH1F *Triboson_WZZ_met = new TH1F("Triboson_WZZ_met", "", 20, 0, 800);
    Triboson_WZZ_met->Sumw2();

    TH1F *Triboson_ZZZ_met = new TH1F("Triboson_ZZZ_met", "", 20, 0, 800);
    Triboson_ZZZ_met->Sumw2();

    Double_t f_WWZ_alphamin, f_WZZ_alphamin, f_ZZZ_alphamin;

    Float_t f_WWZ_met, f_WZZ_met, f_ZZZ_met;

    Int_t f_WWZ_weight, f_WZZ_weight, f_ZZZ_weight;

    // Define the HTWeight

    float WWZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::WWZ_TuneCUETP8M1/(WWZ_totevt))*1000;
     cout <<"WWZWeight = " <<WWZWeight << endl;
    float WZZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::WZZ_TuneCUETP8M1/(WZZ_totevt))*1000;
     cout <<"WZZWeight = " <<WZZWeight << endl;
    float ZZZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ZZZ_TuneCUETP8M1/(ZZZ_totevt))*1000;
     cout <<"ZZZWeight = " <<ZZZWeight << endl;
    // float WWZWeight = (GlobalConstants::WWZ_TuneCUETP8M1);
    // float WZZWeight = (GlobalConstants::WZZ_TuneCUETP8M1);
    // float ZZZWeight = (GlobalConstants::ZZZ_TuneCUETP8M1);

    TTree *T_event;
    Triboson_WWZ->GetObject("T_event", T_event);
    T_event->SetBranchAddress("f_alphamin", &f_WWZ_alphamin);
    T_event->SetBranchAddress("f_Met", &f_WWZ_met);
    T_event->SetBranchAddress("I_weight", &f_WWZ_weight);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        Triboson_WWZ_aphmin->Fill(f_WWZ_alphamin, f_WWZ_weight * WWZWeight);
        Triboson_WWZ_met->Fill(f_WWZ_met, f_WWZ_weight * WWZWeight);
    }

    TTree *T_event1;
    Triboson_WZZ->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_WZZ_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_WZZ_met);
    T_event1->SetBranchAddress("I_weight", &f_WZZ_weight);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        Triboson_WZZ_aphmin->Fill(f_WZZ_alphamin, f_WZZ_weight * WZZWeight);
        Triboson_WZZ_met->Fill(f_WZZ_met, f_WZZ_weight * WZZWeight);
    }

    TTree *T_event2;
    Triboson_ZZZ->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_ZZZ_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_ZZZ_met);
    T_event2->SetBranchAddress("I_weight", &f_ZZZ_weight);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        Triboson_ZZZ_aphmin->Fill(f_ZZZ_alphamin, f_ZZZ_weight * ZZZWeight);
        Triboson_ZZZ_met->Fill(f_ZZZ_met, f_ZZZ_weight * ZZZWeight);
    }

    // h_Rpf = (TH1F*)h_sb->Clone("h_Rpf");
    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(2, 2);
    c1->cd(1);
    Triboson_WWZ_aphmin->SetTitle("WWZ");
    Triboson_WWZ_met->SetTitle("WWZ");
    Triboson_WWZ_aphmin->SetFillColor(KARACHA);
    Triboson_WWZ_met->SetFillColor(KARACHA);
    Triboson_WWZ_aphmin->Draw("hist");
    // Triboson_WWZ_met->Draw("hist");
    c1->cd(2);
    Triboson_WZZ_aphmin->SetTitle("WZZ");
    Triboson_WZZ_met->SetTitle("WZZ");
    Triboson_WZZ_aphmin->SetFillColor(KARACHA);
    Triboson_WZZ_met->SetFillColor(KARACHA);
    Triboson_WZZ_aphmin->Draw("hist");
    // Triboson_WZZ_met->Draw("hist");
    c1->cd(3);
    Triboson_ZZZ_aphmin->SetTitle("ZZZ");
    Triboson_ZZZ_met->SetTitle("ZZZ");
    Triboson_ZZZ_aphmin->SetFillColor(KARACHA);
    Triboson_ZZZ_met->SetFillColor(KARACHA);
    Triboson_ZZZ_aphmin->Draw("hist");
    // Triboson_ZZZ_met->Draw("hist");

    TFile *outFile = new TFile("./../../root_file/Ztoee/Triboson_All.root", "RECREATE");
    outFile->cd();

    Triboson_WWZ_aphmin->Write();
    Triboson_WWZ_met->Write();
    Triboson_WZZ_aphmin->Write();
    Triboson_WZZ_met->Write();
    Triboson_ZZZ_aphmin->Write();
    Triboson_ZZZ_met->Write();

    outFile->Close();
}