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

void Draw_inclusive()
{

    auto c1 = new TCanvas("c", "BPRE");

    TFile *DYincli = new TFile("./../../root_file/Ztoee/ee_DYincli.root");
    TFile *DYHT70 = new TFile("./../../root_file/Ztoee/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../root_file/Ztoee/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../root_file/Ztoee/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../root_file/Ztoee/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../root_file/Ztoee/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../root_file/Ztoee/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../root_file/Ztoee/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../root_file/Ztoee/ee_ht2500.root");

    TFile *Sig1 = new TFile("./../../root_file/Ztoee/Mx2_1.root");
    TFile *Sig50 = new TFile("./../../root_file/Ztoee/Mx2_50.root");
    TFile *Sig150 = new TFile("./../../root_file/Ztoee/Mx2_150.root");    

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("h_HT_eventCout"));

    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("h_event"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("h_event"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("h_event"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("h_event"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("h_event"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("h_event"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("h_event"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("h_event"));


    TH1D *Sig1_nT = ((TH1D *)Sig1->Get("h_aphmin"));
    TH1D *Sig50_nT = ((TH1D *)Sig50->Get("h_aphmin"));
    TH1D *Sig150_nT = ((TH1D *)Sig150->Get("h_aphmin"));

    int DYHT70_totevt = DYHT70_sumevt->GetEntries();
    int DYHT100_totevt = DYHT100_sumevt->GetEntries();
    int DYHT200_totevt = DYHT200_sumevt->GetEntries();
    int DYHT400_totevt = DYHT400_sumevt->GetEntries();
    int DYHT600_totevt = DYHT600_sumevt->GetEntries();
    int DYHT800_totevt = DYHT800_sumevt->GetEntries();
    int DYHT1200_totevt = DYHT1200_sumevt->GetEntries();
    int DYHT2500_totevt = DYHT2500_sumevt->GetEntries();

    TH1F *ht0met = new TH1F("ht0met", "", 20, 0, 800);
    ht0met->Sumw2();

    TH1F *ht70met = new TH1F("ht70met", "", 20, 0, 800);
    ht70met->Sumw2();

    TH1F *ht100met = new TH1F("ht100met", "", 20, 0, 800);
    ht100met->Sumw2();

    TH1F *ht200met = new TH1F("ht200met", "", 20, 0, 800);
    ht200met->Sumw2();

    TH1F *ht400met = new TH1F("ht400met", "", 20, 0, 800);
    ht400met->Sumw2();

    TH1F *ht600met = new TH1F("ht600met", "", 20, 0, 800);
    ht600met->Sumw2();

    TH1F *ht800met = new TH1F("ht800met", "", 20, 0, 800);
    ht800met->Sumw2();

    TH1F *ht1200met = new TH1F("ht1200met", "", 20, 0, 800);
    ht1200met->Sumw2();

    TH1F *ht2500met = new TH1F("ht2500met", "", 20, 0, 800);
    ht2500met->Sumw2();

    TH1F *ht0aphmin = new TH1F("ht0aphmin", "", 24, 0, 1.2);
    ht0aphmin->Sumw2();
    TH1F *ht70aphmin = new TH1F("ht70aphmin", "", 24, 0, 1.2);
    ht70aphmin->Sumw2();
    TH1F *ht100aphmin = new TH1F("ht100aphmin", "", 24, 0, 1.2);
    ht100aphmin->Sumw2();
    TH1F *ht200aphmin = new TH1F("ht200aphmin", "", 24, 0, 1.2);
    ht200aphmin->Sumw2();
    TH1F *ht400aphmin = new TH1F("ht400aphmin", "", 24, 0, 1.2);
    ht400aphmin->Sumw2();
    TH1F *ht600aphmin = new TH1F("ht600aphmin", "", 24, 0, 1.2);
    ht600aphmin->Sumw2();
    TH1F *ht800aphmin = new TH1F("ht800aphmin", "", 24, 0, 1.2);
    ht800aphmin->Sumw2();
    TH1F *ht1200aphmin = new TH1F("ht1200aphmin", "", 24, 0, 1.2);
    ht1200aphmin->Sumw2();
    TH1F *ht2500aphmin = new TH1F("ht2500aphmin", "", 24, 0, 1.2);
    ht2500aphmin->Sumw2();

    int HT0_70_event = h_HT_eventCout->GetBinContent(2);
    int HT70_100_event = h_HT_eventCout->GetBinContent(3);
    int HT100_200_event = h_HT_eventCout->GetBinContent(4);
    int HT200_400_event = h_HT_eventCout->GetBinContent(5);
    int HT400_600_event = h_HT_eventCout->GetBinContent(6);
    int HT600_800_event = h_HT_eventCout->GetBinContent(7);
    int HT800_1200_event = h_HT_eventCout->GetBinContent(8);
    int HT1200_2500_event = h_HT_eventCout->GetBinContent(9);
    int HT2500_Inf_event = h_HT_eventCout->GetBinContent(10);

    // TH1F *h_HT_eventCout = new TH1F("h_HT_eventCout", "", 10, 0, 10);
    // h_HT_eventCout->SetYTitle("N event");
    // h_HT_eventCout->Sumw2();

    float_t HT;

    float_t HT0met, HT70met, HT100met, HT200met, HT400met, HT600met, HT800met,
        HT1200met, HT2500met;

    Double_t HT0alphamin, HT70alphamin, HT100alphamin, HT200alphamin, HT400alphamin,
        HT600alphamin, HT800alphamin, HT1200alphamin, HT2500alphamin;

    Int_t HT0eventWeight, HT70eventWeight, HT100eventWeight, HT200eventWeight, HT400eventWeight,
        HT600eventWeight, HT800eventWeight, HT1200eventWeight, HT2500eventWeight;

    TTree *T_event;
    DYincli->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &HT0eventWeight);
    T_event->SetBranchAddress("f_alphamin", &HT0alphamin);
    T_event->SetBranchAddress("f_Met", &HT0met);
    T_event->SetBranchAddress("f_HT", &HT);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (HT < 70)
        {
            ht0met->Fill(HT0met, HT0eventWeight);
            ht0aphmin->Fill(HT0alphamin, HT0eventWeight);
        }
        else if (HT > 70 && HT < 100)
        {
            ht70met->Fill(HT0met, HT0eventWeight);
            ht70aphmin->Fill(HT0alphamin, HT0eventWeight);
        }
        else if (HT > 100 && HT < 200)
        {
            ht100met->Fill(HT0met, HT0eventWeight);
            ht100aphmin->Fill(HT0alphamin, HT0eventWeight);
        }
        else if (HT > 200 && HT < 400)
        {
            ht200met->Fill(HT0met, HT0eventWeight);
            ht200aphmin->Fill(HT0alphamin, HT0eventWeight);
        }
        else if (HT > 400 && HT < 600)
        {
            ht400met->Fill(HT0met, HT0eventWeight);
            ht400aphmin->Fill(HT0alphamin, HT0eventWeight);
        }
        else if (HT > 600 && HT < 800)
        {
            ht600met->Fill(HT0met, HT0eventWeight);
            ht600aphmin->Fill(HT0alphamin, HT0eventWeight);
        }
        else if (HT > 800 && HT < 1200)
        {
            ht800met->Fill(HT0met, HT0eventWeight);
            ht800aphmin->Fill(HT0alphamin, HT0eventWeight);
        }
        else if (HT > 1200 && HT < 2500)
        {
            ht1200met->Fill(HT0met, HT0eventWeight);
            ht1200aphmin->Fill(HT0alphamin, HT0eventWeight);
        }
        else if (HT > 2500)
        {
            ht2500met->Fill(HT0met, HT0eventWeight);
            ht2500aphmin->Fill(HT0alphamin, HT0eventWeight);
        }
    }
    // ht0aphmin->DrawNormalized("text45");
    /*
    TTree *T_event1;
    DYHT70->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &HT70alphamin);
    T_event1->SetBranchAddress("f_Met", &HT70met);
    T_event1->SetBranchAddress("I_weight", &HT70eventWeight);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        ht70met->Fill(HT70met, HT70eventWeight);
        ht70aphmin->Fill(HT70alphamin, HT70eventWeight);
    }
    */
    TTree *T_event2;
    DYHT100->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &HT100alphamin);
    T_event2->SetBranchAddress("f_Met", &HT100met);
    T_event2->SetBranchAddress("I_weight", &HT100eventWeight);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        ht100met->Fill(HT100met, HT100eventWeight);
        ht100aphmin->Fill(HT100alphamin, HT100eventWeight);
    }

    TTree *T_event3;
    DYHT200->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &HT200alphamin);
    T_event3->SetBranchAddress("f_Met", &HT200met);
    T_event3->SetBranchAddress("I_weight", &HT200eventWeight);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        ht200met->Fill(HT200met, HT200eventWeight);
        ht200aphmin->Fill(HT200alphamin, HT200eventWeight);
    }

    TTree *T_event4;
    DYHT400->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &HT400alphamin);
    T_event4->SetBranchAddress("f_Met", &HT400met);
    T_event4->SetBranchAddress("I_weight", &HT400eventWeight);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        ht400met->Fill(HT400met, HT400eventWeight);
        ht400aphmin->Fill(HT400alphamin, HT400eventWeight);
    }

    TTree *T_event5;
    DYHT600->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &HT600alphamin);
    T_event5->SetBranchAddress("f_Met", &HT600met);
    T_event5->SetBranchAddress("I_weight", &HT600eventWeight);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        ht600met->Fill(HT600met, HT600eventWeight);
        ht600aphmin->Fill(HT600alphamin, HT600eventWeight);
    }

    TTree *T_event6;
    DYHT800->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &HT800alphamin);
    T_event6->SetBranchAddress("f_Met", &HT800met);
    T_event6->SetBranchAddress("I_weight", &HT800eventWeight);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        ht800met->Fill(HT800met, HT800eventWeight);
        ht800aphmin->Fill(HT800alphamin, HT800eventWeight);
    }
    TTree *T_event7;
    DYHT1200->GetObject("T_event", T_event7);
    T_event7->SetBranchAddress("f_alphamin", &HT1200alphamin);
    T_event7->SetBranchAddress("f_Met", &HT1200met);
    T_event7->SetBranchAddress("I_weight", &HT1200eventWeight);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        ht1200met->Fill(HT1200met, HT1200eventWeight);
        ht1200aphmin->Fill(HT1200alphamin, HT1200eventWeight);
    }

    TTree *T_event8;
    DYHT2500->GetObject("T_event", T_event8);
    T_event8->SetBranchAddress("f_alphamin", &HT2500alphamin);
    T_event8->SetBranchAddress("f_Met", &HT2500met);
    T_event8->SetBranchAddress("I_weight", &HT2500eventWeight);
    for (int evt = 0; evt < T_event8->GetEntries(); evt++)
    {
        T_event8->GetEntry(evt);
        ht2500met->Fill(HT2500met, HT2500eventWeight);
        ht2500aphmin->Fill(HT2500alphamin, HT2500eventWeight);
    }

    ht0met->Scale(35.9 * ((4609.090666) / (HT0_70_event)));
    ht70met->Scale(35.9 * ((149.9710714) / (HT70_100_event)));
    ht100met->Scale(35.9 * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)));
    ht200met->Scale(35.9 * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)));
    ht400met->Scale(35.9 * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)));
    ht600met->Scale(35.9 * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)));
    ht800met->Scale(35.9 * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)));
    ht1200met->Scale(35.9 * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)));
    ht2500met->Scale(35.9 * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)));

    //cout <<"GlobalConstants::HT1200CS = "<<GlobalConstants::HT1200CS<<endl;
    //cout <<"(DYHT1200_totevt + HT1200_2500_event) = "<<(DYHT1200_totevt + HT1200_2500_event)<< endl;

    c1->Divide(3, 3);
    c1->cd(1);
    ht0met->SetTitle("DTHT0-70");
    ht0met->SetXTitle("#slash{E}_{T}");
    ht0met->Draw("hist");
    c1->cd(2);
    ht70met->SetTitle("DTHT70-100");
    ht70met->SetXTitle("#slash{E}_{T}");
    ht70met->Draw("hist");
    c1->cd(3);
    ht100met->SetTitle("DTHT100-200");
    ht100met->SetXTitle("#slash{E}_{T}");
    ht100met->Draw("hist");
    c1->cd(4);
    ht200met->SetTitle("DTHT200-400");
    ht200met->SetXTitle("#slash{E}_{T}");
    ht200met->Draw("hist");
    c1->cd(5);
    ht400met->SetTitle("DTHT400-600");
    ht400met->SetXTitle("#slash{E}_{T}");
    ht400met->Draw("hist");
    c1->cd(6);
    ht600met->SetTitle("DTHT600-800");
    ht600met->SetXTitle("#slash{E}_{T}");
    ht600met->Draw("hist");
    c1->cd(7);
    ht800met->SetTitle("DTHT800-1200");
    ht800met->SetXTitle("#slash{E}_{T}");
    ht800met->Draw("hist");
    c1->cd(8);
    ht1200met->SetTitle("DTHT1200-2500");
    ht1200met->SetXTitle("#slash{E}_{T}");
    ht1200met->Draw("hist");
    c1->cd(9);
    ht2500met->SetTitle("DTHT2500-Inf");
    ht2500met->SetXTitle("#slash{E}_{T}");
    ht2500met->Draw("hist");
    // ht0met->Add(ht70met);
    // ht0met->Add(ht100met);
    // ht0met->Add(ht200met);
    // ht0met->Add(ht400met);
    // ht0met->Add(ht600met);
    // ht0met->Add(ht800met);
    // ht0met->Add(ht1200met);
    // ht0met->Add(ht2500met);
    // ht0met->DrawNormalized("hist");
    auto c2 = new TCanvas("c", "BPRE");

    c2->Divide(3, 3);

    ht0aphmin->Scale(35.9 * ((4609.090666) / (HT0_70_event))*1000);
    ht70aphmin->Scale(35.9 * ((149.9710714) / (HT70_100_event))*1000);
    ht100aphmin->Scale(35.9 * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event))*1000);
    ht200aphmin->Scale(35.9 * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event))*1000);
    ht400aphmin->Scale(35.9 * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event))*1000);
    ht600aphmin->Scale(35.9 * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event))*1000);
    ht800aphmin->Scale(35.9 * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event))*1000);
    ht1200aphmin->Scale(35.9 * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event))*1000);
    ht2500aphmin->Scale(35.9 * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event))*1000);

    c2->cd(1);
    ht0aphmin->SetTitle("DTHT0-70");
    ht0aphmin->SetXTitle("h_aphmin");
    ht0aphmin->Draw("hist");
    c2->cd(2);
    ht70aphmin->SetTitle("DTHT70-100");
    ht70aphmin->SetXTitle("h_aphmin");
    ht70aphmin->Draw("hist");
    c2->cd(3);
    ht100aphmin->SetTitle("DTHT100-200");
    ht100aphmin->SetXTitle("h_aphmin");
    ht100aphmin->Draw("hist");
    c2->cd(4);
    ht200aphmin->SetTitle("DTHT200-400");
    ht200aphmin->SetXTitle("h_aphmin");
    ht200aphmin->Draw("hist");
    c2->cd(5);
    ht400aphmin->SetTitle("DTHT400-600");
    ht400aphmin->SetXTitle("h_aphmin");
    ht400aphmin->Draw("hist");
    c2->cd(6);
    ht600aphmin->SetTitle("DTHT600-800");
    ht600aphmin->SetXTitle("h_aphmin");
    ht600aphmin->Draw("hist");
    c2->cd(7);
    ht800aphmin->SetTitle("DTHT800-1200");
    ht800aphmin->SetXTitle("h_aphmin");
    ht800aphmin->Draw("hist");
    c2->cd(8);
    ht1200aphmin->SetTitle("DTHT1200-2500");
    ht1200aphmin->SetXTitle("h_aphmin");
    ht1200aphmin->Draw("hist");
    c2->cd(9);
    ht2500aphmin->SetTitle("DTHT2500-Inf");
    ht2500aphmin->SetXTitle("h_aphmin");
    ht2500aphmin->Draw("hist");

    auto c3 = new TCanvas("c", "BPRE");
    ht0met->GetYaxis()->SetTitle("Event/Normalized");
    ht0met->SetTitle("DYHT");
    ht0met->Add(ht70met);
    ht0met->Add(ht100met);
    ht0met->Add(ht200met);
    ht0met->Add(ht400met);
    ht0met->Add(ht600met);
    ht0met->Add(ht800met);
    ht0met->Add(ht1200met);
    ht0met->Add(ht2500met);
    ht0met->SetLineColor(kViolet);
    ht0met->SetFillColor(kViolet);
    ht0met->SetFillStyle(3003);
    ht0met->SetLineWidth(2);
    ht0met->DrawNormalized("hist");

    
    auto c4 = new TCanvas("c", "BPRE");
    ht0aphmin->SetTitle("DYHT");
    ht0aphmin->Add(ht70aphmin);
    ht0aphmin->Add(ht100aphmin);
    ht0aphmin->Add(ht200aphmin);
    ht0aphmin->Add(ht400aphmin);
    ht0aphmin->Add(ht600aphmin);
    ht0aphmin->Add(ht800aphmin);
    ht0aphmin->Add(ht1200aphmin);
    ht0aphmin->Add(ht2500aphmin);
    ht0aphmin->SetLineColor(kViolet);
    ht0aphmin->SetFillColor(kViolet);
    ht0aphmin->SetFillStyle(3003);
    ht0aphmin->SetLineWidth(2);

    
    Sig1_nT->Scale(5.785);
    Sig50_nT->Scale(5.785);
    Sig150_nT->Scale(5.785);
    Sig1_nT->SetLineColor(kRed);
    Sig1_nT->SetLineWidth(2);
    Sig50_nT->SetLineColor(kBlue);
    Sig50_nT->SetLineWidth(2);
    Sig150_nT->SetLineColor(kBlack);
    Sig150_nT->SetLineWidth(2);
    Sig50_nT->SetTitle("DYHT");
    Sig50_nT->GetYaxis()->SetTitle("Event/Normalized");
    Sig50_nT->DrawNormalized("hist&&same");
    Sig150_nT->DrawNormalized("hist&&same");
    Sig1_nT->DrawNormalized("hist&&same");
    

    
    ht0aphmin->DrawNormalized("hist&&same");

    TLegend *l4 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.04);
    l4->AddEntry(ht0met, "DYJets_HTBin", "l");
    l4->AddEntry(Sig1_nT, "ctau=1mm m_{x^{2}}=1", "l");
    l4->AddEntry(Sig50_nT, "ctau=10mm m_{x^{2}}=50", "l");
    l4->AddEntry(Sig150_nT, "ctau=1mm m_{x^{2}}=150", "l");
    l4->Draw();
   
}