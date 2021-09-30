#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "setNCUStyle.C"
using namespace std;
void MT2quick_draw()
{

    setNCUStyle(true);
    auto c1 = new TCanvas("c", "BPRE");
    
    TFile *Mx2_1 = new TFile("./../../root_file/Ztoee/test_Mt2_1.root");
    TFile *Mx2_1_02 = new TFile("./../../root_file/Ztoee/test_Mt2_1_02.root");
    TFile *Mx2_1_05 = new TFile("./../../root_file/Ztoee/test_Mt2_1_05.root");

    TFile *Mx2_50 = new TFile("./../../root_file/Ztoee/test_Mt2_50.root");
    TFile *Mx2_50_10 = new TFile("./../../root_file/Ztoee/test_Mt2_50_10.root");
    TFile *Mx2_50_30 = new TFile("./../../root_file/Ztoee/test_Mt2_50_30.root");
    


    TFile *Mx2_150 = new TFile("./../../root_file/Ztoee/test_Mt2_150.root");
    TFile *Mx2_150_10 = new TFile("./../../root_file/Ztoee/test_Mt2_150_10.root");
    TFile *Mx2_150_30 = new TFile("./../../root_file/Ztoee/test_Mt2_150_30.root");


    //TH1F *h_Mx2_1_TM1 = new TH1F("h_Mx2_1_TM1", "", 40, 0.2, 1.2);
    TH1F *h_Mx2_1_TM1 = new TH1F("h_Mx2_1_TM1", "", 40, 0.2, 1.2);
    h_Mx2_1_TM1->SetXTitle("transverse mass square");
    h_Mx2_1_TM1->SetYTitle("N events");
    h_Mx2_1_TM1->Sumw2();
    TH1F *h_Mx2_1_TM2 = new TH1F("h_Mx2_1_TM2", "", 40, 0.2, 1.2);
    h_Mx2_1_TM2->SetXTitle("transverse mass square");
    h_Mx2_1_TM2->SetYTitle("N events");   
    h_Mx2_1_TM2->Sumw2();
    TH1F *h_Mx2_1_MT2= new TH1F("h_Mx2_1_MT2", "", 40, 0.2, 15);
    h_Mx2_1_MT2->SetXTitle("MT2");
    h_Mx2_1_MT2->SetYTitle("N events");   
    h_Mx2_1_MT2->Sumw2();

    TH1F *h_Mx2_1_02_MT2= new TH1F("h_Mx2_1_02_MT2", "", 40,  0.2, 15);
    h_Mx2_1_02_MT2->SetXTitle("MT2");
    h_Mx2_1_02_MT2->SetYTitle("N events");   
    h_Mx2_1_02_MT2->Sumw2();

    TH1F *h_Mx2_1_05_MT2= new TH1F("h_Mx2_1_05_MT2", "", 40,  0.2, 15);
    h_Mx2_1_05_MT2->SetXTitle("MT2");
    h_Mx2_1_05_MT2->SetYTitle("N events");   
    h_Mx2_1_05_MT2->Sumw2();

    TH1F *h_Mx2_50_TM1 = new TH1F("h_Mx2_50_TM1", "", 50, 0, 2550);
    h_Mx2_50_TM1->SetXTitle("transverse mass square");
    h_Mx2_50_TM1->SetYTitle("N events");   
    h_Mx2_50_TM1->Sumw2();
    TH1F *h_Mx2_50_TM2 = new TH1F("h_Mx2_50_TM2", "", 50, 0, 2550);
    h_Mx2_50_TM2->SetXTitle("transverse mass square");
    h_Mx2_50_TM2->SetYTitle("N events");   
    h_Mx2_50_TM2->Sumw2();
    TH1F *h_Mx2_50_MT2= new TH1F("h_Mx2_50_MT2", "", 50, 0, 2550);
    h_Mx2_50_MT2->SetXTitle("MT2");
    h_Mx2_50_MT2->SetYTitle("N events");   
    h_Mx2_50_MT2->Sumw2();

    TH1F *h_Mx2_50_10_MT2= new TH1F("h_Mx2_50_10_MT2", "", 50, 0, 10000);
    h_Mx2_50_10_MT2->SetXTitle("MT2");
    h_Mx2_50_10_MT2->SetYTitle("N events");   
    h_Mx2_50_10_MT2->Sumw2();

    TH1F *h_Mx2_50_30_MT2= new TH1F("h_Mx2_50_30_MT2", "",50, 0, 35000);
    h_Mx2_50_30_MT2->SetXTitle("MT2");
    h_Mx2_50_30_MT2->SetYTitle("N events");   
    h_Mx2_50_30_MT2->Sumw2();

    TH1F *h_Mx2_150_TM1 = new TH1F("h_Mx2_150_TM1", "", 50, 0, 23000);
    h_Mx2_150_TM1->SetXTitle("transverse mass square");
    h_Mx2_150_TM1->SetYTitle("N events");   
    h_Mx2_150_TM1->Sumw2();
    TH1F *h_Mx2_150_TM2 = new TH1F("h_Mx2_150_TM2", "", 50, 0, 23000);
    h_Mx2_150_TM2->SetXTitle("transverse mass square");
    h_Mx2_150_TM2->SetYTitle("N events");    
    h_Mx2_150_TM2->Sumw2();
    TH1F *h_Mx2_150_MT2 = new TH1F("h_Mx2_150_MT2", "", 50, 0, 23000);
    h_Mx2_150_MT2->SetXTitle("MT2");
    h_Mx2_150_MT2->SetYTitle("N events");   
    h_Mx2_150_MT2->Sumw2();

    TH1F *h_Mx2_150_10_MT2 = new TH1F("h_Mx2_150_10_MT2", "", 50, 0, 30000);
    h_Mx2_150_10_MT2->SetXTitle("MT2");
    h_Mx2_150_10_MT2->SetYTitle("N events");   
    h_Mx2_150_10_MT2->Sumw2();

    TH1F *h_Mx2_150_30_MT2 = new TH1F("h_Mx2_150_30_MT2", "", 50, 0, 55000);
    h_Mx2_150_30_MT2->SetXTitle("MT2");
    h_Mx2_150_30_MT2->SetYTitle("N events");   
    h_Mx2_150_30_MT2->Sumw2();


    Float_t f_Mx1_tr1, f_Mx1_tr2, f_Mx1_MT2,f_Mx1_02_MT2,f_Mx1_05_MT2, f_Mx50_tr1, f_Mx50_tr2, f_Mx50_MT2,f_Mx50_10_MT2,f_Mx50_30_MT2, f_Mx150_tr1, f_Mx150_tr2, f_Mx150_MT2,f_Mx150_10_MT2,f_Mx150_30_MT2;
    Int_t I_Mx1_weight,I_Mx1_02_weight,I_Mx1_05_weight, I_Mx50_weight,I_Mx50_10_weight,I_Mx50_30_weight, I_Mx150_weight,I_Mx150_10_weight,I_Mx150_30_weight;


    //Mx1
    TTree *T_event;
    Mx2_1->GetObject("T_event",T_event);
    T_event->SetBranchAddress("f_TranMass1",&f_Mx1_tr1);
    T_event->SetBranchAddress("f_TranMass2",&f_Mx1_tr2);
    T_event->SetBranchAddress("f_MT2",&f_Mx1_MT2);
    T_event->SetBranchAddress("I_weight",&I_Mx1_weight);
    
    for(int evt=0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        h_Mx2_1_TM1->Fill(f_Mx1_tr1,I_Mx1_weight);
        h_Mx2_1_TM2->Fill(f_Mx1_tr2,I_Mx1_weight);
        h_Mx2_1_MT2->Fill(f_Mx1_MT2,I_Mx1_weight);
    }
    //h_Mx2_1_MT2->Draw("hist");

    //Mx1
    TTree *T_event_02;
    Mx2_1_02->GetObject("T_event",T_event_02);
    T_event_02->SetBranchAddress("f_MT2",&f_Mx1_02_MT2);
    T_event_02->SetBranchAddress("I_weight",&I_Mx1_02_weight);
    
    for(int evt=0; evt < T_event_02->GetEntries(); evt++)
    {
        T_event_02->GetEntry(evt);
        h_Mx2_1_02_MT2->Fill(f_Mx1_02_MT2,I_Mx1_02_weight);
    }

    TTree *T_event_05;
    Mx2_1_05->GetObject("T_event",T_event_05);
    T_event_05->SetBranchAddress("f_MT2",&f_Mx1_05_MT2);
    T_event_05->SetBranchAddress("I_weight",&I_Mx1_05_weight);
    for(int evt=0; evt < T_event_05->GetEntries(); evt++)
    {
        T_event_05->GetEntry(evt);
        h_Mx2_1_05_MT2->Fill(f_Mx1_05_MT2,I_Mx1_05_weight);
    }

    h_Mx2_1_05_MT2->SetLineColor(kRed);
    h_Mx2_1_02_MT2->SetLineColor(kBlue);
    h_Mx2_1_MT2->SetLineColor(kGreen);
    //h_Mx2_1_MT2
    //h_Mx2_1_05_MT2
    h_Mx2_1_MT2->DrawNormalized("hist");
    h_Mx2_1_02_MT2->DrawNormalized("hist&&same");
    h_Mx2_1_05_MT2->DrawNormalized("hist&&same");

    //Mx2_50
    TTree *T_event1;
    Mx2_50->GetObject("T_event",T_event1);
    T_event1->SetBranchAddress("f_TranMass1",&f_Mx50_tr1);
    T_event1->SetBranchAddress("f_TranMass2",&f_Mx50_tr2);
    T_event1->SetBranchAddress("f_MT2",&f_Mx50_MT2);
    T_event1->SetBranchAddress("I_weight",&I_Mx50_weight);

    for(int evt=0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        h_Mx2_50_TM1->Fill(f_Mx50_tr1,I_Mx50_weight);
        h_Mx2_50_TM2->Fill(f_Mx50_tr2,I_Mx50_weight);
        h_Mx2_50_MT2->Fill(f_Mx50_MT2,I_Mx50_weight);
    }
    TTree *T_event1_10;
    Mx2_50_10->GetObject("T_event",T_event1_10);
    T_event1_10->SetBranchAddress("f_MT2",&f_Mx50_10_MT2);
    T_event1_10->SetBranchAddress("I_weight",&I_Mx50_10_weight);
    for(int evt=0; evt < T_event1_10->GetEntries(); evt++)
    {
        T_event1_10->GetEntry(evt);
        h_Mx2_50_10_MT2->Fill(f_Mx50_10_MT2,I_Mx50_10_weight);
    }
    TTree *T_event1_30;
    Mx2_50_30->GetObject("T_event",T_event1_30);
    T_event1_30->SetBranchAddress("f_MT2",&f_Mx50_30_MT2);
    T_event1_30->SetBranchAddress("I_weight",&I_Mx50_30_weight);
    for(int evt=0; evt < T_event1_30->GetEntries(); evt++)
    {
        T_event1_30->GetEntry(evt);
        h_Mx2_50_30_MT2->Fill(f_Mx50_30_MT2,I_Mx50_30_weight);
    }

    //h_Mx2_50_30_MT2->SetLineColor(kRed);
    //h_Mx2_50_10_MT2->SetLineColor(kBlue);
    //h_Mx2_50_MT2->SetLineColor(kGreen);
    //h_Mx2_1_MT2
    //h_Mx2_1_05_MT2
    //h_Mx2_50_30_MT2->DrawNormalized("hist&&same");
    //h_Mx2_50_10_MT2->DrawNormalized("hist&&same");
    //h_Mx2_50_MT2->DrawNormalized("hist&&same");

    //h_Mx2_50_MT2->Draw();

    //Mx2_150
    TTree *T_event2;
    Mx2_150->GetObject("T_event",T_event2);
    T_event2->SetBranchAddress("f_TranMass1",&f_Mx150_tr1);
    T_event2->SetBranchAddress("f_TranMass2",&f_Mx150_tr2);
    T_event2->SetBranchAddress("f_MT2",&f_Mx150_MT2);
    T_event2->SetBranchAddress("I_weight",&I_Mx150_weight);
    for(int evt=0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        h_Mx2_150_TM1->Fill(f_Mx150_tr1,I_Mx150_weight);
        h_Mx2_150_TM2->Fill(f_Mx150_tr2,I_Mx150_weight);
        h_Mx2_150_MT2->Fill(f_Mx150_MT2,I_Mx150_weight);
    }
    TTree *T_event2_10;
    Mx2_150_10->GetObject("T_event",T_event2_10);
    T_event2_10->SetBranchAddress("f_MT2",&f_Mx150_10_MT2);
    T_event2_10->SetBranchAddress("I_weight",&I_Mx150_10_weight);
    for(int evt=0; evt < T_event2_10->GetEntries(); evt++)
    {
        T_event2_10->GetEntry(evt);
        h_Mx2_150_10_MT2->Fill(f_Mx150_10_MT2,I_Mx150_10_weight);
    }
    TTree *T_event2_30;
    Mx2_150_30->GetObject("T_event",T_event2_30);
    T_event2_30->SetBranchAddress("f_MT2",&f_Mx150_30_MT2);
    T_event2_30->SetBranchAddress("I_weight",&I_Mx150_30_weight);
    for(int evt=0; evt < T_event2_30->GetEntries(); evt++)
    {
        T_event2_30->GetEntry(evt);
        h_Mx2_150_30_MT2->Fill(f_Mx150_30_MT2,I_Mx150_30_weight);
    }

    //h_Mx2_150_30_MT2->SetLineColor(kRed);
    //h_Mx2_150_10_MT2->SetLineColor(kBlue);
    //h_Mx2_150_MT2->SetLineColor(kGreen);
    ////h_Mx2_1_MT2
    //h_Mx2_1_05_MT2
    //h_Mx2_150_30_MT2->DrawNormalized("hist&&same");
    //h_Mx2_150_10_MT2->DrawNormalized("hist&&same");
    //h_Mx2_150_MT2->DrawNormalized("hist&&same");
    
    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(h_Mx2_1_MT2, "ctau=1mm m_{x_{1}}=0.1GeV", "l");
    l2->AddEntry(h_Mx2_1_02_MT2, "ctau=1mm m_{x_{1}}=0.2GeV", "l");
    l2->AddEntry(h_Mx2_1_05_MT2, "ctau=1mm m_{x_{1}}=0.5GeV", "l");
    l2->Draw();
    //h_Mx2_150_MT2->Draw();
    //c1->SaveAs("Mx2_150_MT2.png");

}