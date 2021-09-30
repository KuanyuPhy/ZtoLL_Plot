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
#include "./lib/Cross_section.C"
using namespace RooFit;
//#include "TRooH1D.h"
//#include "Cross_section.h"

void BGEM_HT(){


    TFile *Mx2_1 = new TFile("./../../root_file/Ztoee/test1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/Ztoee/test50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/Ztoee/test150.root");

    
    TFile *DYHT70 = new TFile("./../../root_file/Ztoee/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../root_file/Ztoee/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../root_file/Ztoee/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../root_file/Ztoee/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../root_file/Ztoee/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../root_file/Ztoee/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../root_file/Ztoee/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../root_file/Ztoee/ee_ht2500.root");


    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("h_event"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("h_event"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("h_event"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("h_event"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("h_event"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("h_event"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("h_event"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("h_event"));   
    

    int DYHT70_totevt = DYHT70_sumevt->GetEntries();
    int DYHT100_totevt = DYHT100_sumevt->GetEntries();
    int DYHT200_totevt = DYHT200_sumevt->GetEntries();
    int DYHT400_totevt = DYHT400_sumevt->GetEntries();
    int DYHT600_totevt = DYHT600_sumevt->GetEntries();
    int DYHT800_totevt = DYHT800_sumevt->GetEntries();
    int DYHT1200_totevt = DYHT1200_sumevt->GetEntries();
    int DYHT2500_totevt = DYHT2500_sumevt->GetEntries();  

    //DYHT
    TH1F *h_ht70A_aphmin = new TH1F("h_ht70A_aphmin", "", 24, 0, 1.2);
    h_ht70A_aphmin->Sumw2();
    TH1F *h_ht70B_aphmin = new TH1F("h_ht70B_aphmin", "", 24, 0, 1.2);
    h_ht70B_aphmin->Sumw2();

    TH1F *h_ht100A_aphmin = new TH1F("h_ht100A_aphmin", "", 24, 0, 1.2);
    h_ht100A_aphmin->Sumw2();
    TH1F *h_ht100B_aphmin = new TH1F("h_ht100B_aphmin", "", 24, 0, 1.2);
    h_ht100B_aphmin->Sumw2();

    TH1F *h_ht200A_aphmin = new TH1F("h_ht200A_aphmin", "", 24, 0, 1.2);
    h_ht200A_aphmin->Sumw2();
    TH1F *h_ht200B_aphmin = new TH1F("h_ht200B_aphmin", "", 24, 0, 1.2);
    h_ht200B_aphmin->Sumw2();

    TH1F *h_ht400A_aphmin = new TH1F("h_ht400A_aphmin", "", 24, 0, 1.2);
    h_ht400A_aphmin->Sumw2();
    TH1F *h_ht400B_aphmin = new TH1F("h_ht400B_aphmin", "", 24, 0, 1.2);
    h_ht400B_aphmin->Sumw2();

    TH1F *h_ht600A_aphmin = new TH1F("h_ht600A_aphmin", "", 24, 0, 1.2);
    h_ht600A_aphmin->Sumw2();
    TH1F *h_ht600B_aphmin = new TH1F("h_ht600B_aphmin", "", 24, 0, 1.2);
    h_ht600B_aphmin->Sumw2();

    TH1F *h_ht800A_aphmin = new TH1F("h_ht800A_aphmin", "", 24, 0, 1.2);
    h_ht800A_aphmin->Sumw2();
    TH1F *h_ht800B_aphmin = new TH1F("h_ht800B_aphmin", "", 24, 0, 1.2);
    h_ht800B_aphmin->Sumw2();

    TH1F *h_ht1200A_aphmin = new TH1F("h_ht1200A_aphmin", "", 24, 0, 1.2);
    h_ht1200A_aphmin->Sumw2();
    TH1F *h_ht1200B_aphmin = new TH1F("h_ht1200B_aphmin", "", 24, 0, 1.2);
    h_ht1200B_aphmin->Sumw2();

    TH1F *h_ht2500A_aphmin = new TH1F("h_ht2500A_aphmin", "", 24, 0, 1.2);
    h_ht2500A_aphmin->Sumw2();
    TH1F *h_ht2500B_aphmin = new TH1F("h_ht2500B_aphmin", "", 24, 0, 1.2);
    h_ht2500B_aphmin->Sumw2();

    //DYHT
    TH1F *h_ht70A_met = new TH1F("h_ht70A_met", "", 24, 0, 1000);
    h_ht70A_met->Sumw2();
    TH1F *h_ht70B_met = new TH1F("h_ht70B_met", "", 24, 0, 1000);
    h_ht70B_met->Sumw2();

    TH1F *h_ht100A_met = new TH1F("h_ht100A_met", "", 24, 0, 1000);
    h_ht100A_met->Sumw2();
    TH1F *h_ht100B_met = new TH1F("h_ht100B_met", "", 24, 0, 1000);
    h_ht100B_met->Sumw2();

    TH1F *h_ht200A_met = new TH1F("h_ht200A_met", "", 24, 0, 1000);
    h_ht200A_met->Sumw2();
    TH1F *h_ht200B_met = new TH1F("h_ht200B_met", "", 24, 0, 1000);
    h_ht200B_met->Sumw2();

    TH1F *h_ht400A_met = new TH1F("h_ht400A_met", "", 24, 0, 1000);
    h_ht400A_met->Sumw2();
    TH1F *h_ht400B_met = new TH1F("h_ht400B_met", "", 24, 0, 1000);
    h_ht400B_met->Sumw2();

    TH1F *h_ht600A_met = new TH1F("h_ht600A_met", "", 24, 0, 1000);
    h_ht600A_met->Sumw2();
    TH1F *h_ht600B_met = new TH1F("h_ht600B_met", "", 24, 0, 1000);
    h_ht600B_met->Sumw2();

    TH1F *h_ht800A_met = new TH1F("h_ht800A_met", "", 24, 0, 1000);
    h_ht800A_met->Sumw2();
    TH1F *h_ht800B_met = new TH1F("h_ht800B_met", "", 24, 0, 1000);
    h_ht800B_met->Sumw2();

    TH1F *h_ht1200A_met = new TH1F("h_ht1200A_met", "", 24, 0, 1000);
    h_ht1200A_met->Sumw2();
    TH1F *h_ht1200B_met = new TH1F("h_ht1200B_met", "", 24, 0, 1000);
    h_ht1200B_met->Sumw2();

    TH1F *h_ht2500A_met = new TH1F("h_ht2500A_met", "", 24, 0, 1000);
    h_ht2500A_met->Sumw2();
    TH1F *h_ht2500B_met = new TH1F("h_ht2500B_met", "", 24, 0, 1000);
    h_ht2500B_met->Sumw2();

    Double_t f_ht70_alphamin, f_ht100_alphamin, f_ht200_alphamin,f_ht400_alphamin,f_ht600_alphamin,f_ht800_alphamin,f_ht1200_alphamin,f_ht2500_alphamin;
    float f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met, f_ht1200_Met, f_ht2500_Met;
    int I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight, I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    //Define the variable
    float BoxA_amin = 0.1;
    float BoxA_Met = 90;
    float BoxB_amin = 0.05;
    float BoxB_Met = 90;
    float BoxC_amin = 0.1;
    float BoxC_Met = 80;
    float BoxD_amin = 0.05;
    float BoxD_Met = 80;

    TTree *T_event;
    DYHT70->GetObject("T_event",T_event);

    T_event->SetBranchAddress("f_alphamin",&f_ht70_alphamin);
    T_event->SetBranchAddress("f_Met",&f_ht70_Met);
    T_event->SetBranchAddress("I_weight",&I_ht70_weight);

    for(int evt=0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);

        if(f_ht70_Met > 90)
        {
            h_ht70A_aphmin->Fill(f_ht70_alphamin,I_ht70_weight);
        }
        if(f_ht70_Met < 80)
        {
            h_ht70B_aphmin->Fill(f_ht70_alphamin,I_ht70_weight);
        }
        if(f_ht70_alphamin > 0.1)
        {
            h_ht70A_met->Fill(f_ht70_Met,I_ht70_weight);
        }
        if(f_ht70_alphamin < 0.05)
        {
            h_ht70B_met->Fill(f_ht70_Met,I_ht70_weight);
        }
    }

    TTree *T_event1;
    DYHT100->GetObject("T_event",T_event1);
    T_event1->SetBranchAddress("f_alphamin",&f_ht100_alphamin);
    T_event1->SetBranchAddress("f_Met",&f_ht100_Met);
    T_event1->SetBranchAddress("I_weight",&I_ht100_weight);
    for(int evt=0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if(f_ht100_Met > 90)
        {
            h_ht100A_aphmin->Fill(f_ht100_alphamin,I_ht100_weight);
        }
        if(f_ht100_Met < 80)
        {
            h_ht100B_aphmin->Fill(f_ht100_alphamin,I_ht100_weight);
        }
        if(f_ht100_alphamin > 0.1)
        {
            h_ht100A_met->Fill(f_ht100_Met,I_ht100_weight);
        }
        if(f_ht100_alphamin < 0.05)
        {
            h_ht100B_met->Fill(f_ht100_Met,I_ht100_weight);
        }
    }

    TTree *T_event2;
    DYHT200->GetObject("T_event",T_event2);
    T_event2->SetBranchAddress("f_alphamin",&f_ht200_alphamin);
    T_event2->SetBranchAddress("f_Met",&f_ht200_Met);
    T_event2->SetBranchAddress("I_weight",&I_ht200_weight);
    for(int evt=0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if(f_ht200_Met > 90)
        {
            h_ht200A_aphmin->Fill(f_ht200_alphamin,I_ht200_weight);
        }
        if(f_ht200_Met < 80)
        {
            h_ht200B_aphmin->Fill(f_ht200_alphamin,I_ht200_weight);
        }
        if(f_ht200_alphamin > 0.1)
        {
            h_ht200A_met->Fill(f_ht200_Met,I_ht200_weight);
        }
        if(f_ht200_alphamin < 0.05)
        {
            h_ht200B_met->Fill(f_ht200_Met,I_ht200_weight);
        }
    }

    TTree *T_event3;
    DYHT400->GetObject("T_event",T_event3);
    T_event3->SetBranchAddress("f_alphamin",&f_ht400_alphamin);
    T_event3->SetBranchAddress("f_Met",&f_ht400_Met);
    T_event3->SetBranchAddress("I_weight",&I_ht400_weight);
    for(int evt=0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if(f_ht400_Met > 90)
        {
            h_ht400A_aphmin->Fill(f_ht400_alphamin,I_ht400_weight);
        }
        if(f_ht400_Met < 80)
        {
            h_ht400B_aphmin->Fill(f_ht400_alphamin,I_ht400_weight);
        }
        if(f_ht400_alphamin > 0.1)
        {
            h_ht400A_met->Fill(f_ht400_Met,I_ht400_weight);
        }
        if(f_ht400_alphamin < 0.05)
        {
            h_ht400B_met->Fill(f_ht400_Met,I_ht400_weight);
        }
    }

    TTree *T_event4;
    DYHT600->GetObject("T_event",T_event4);
    T_event4->SetBranchAddress("f_alphamin",&f_ht600_alphamin);
    T_event4->SetBranchAddress("f_Met",&f_ht600_Met);
    T_event4->SetBranchAddress("I_weight",&I_ht600_weight);
    for(int evt=0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if(f_ht600_Met > 90)
        {
            h_ht600A_aphmin->Fill(f_ht600_alphamin,I_ht600_weight);
        }
        if(f_ht600_Met < 80)
        {
            h_ht600B_aphmin->Fill(f_ht600_alphamin,I_ht600_weight);
        }
        if(f_ht600_alphamin > 0.1)
        {
            h_ht600A_met->Fill(f_ht600_Met,I_ht600_weight);
        }
        if(f_ht600_alphamin < 0.05)
        {
            h_ht600B_met->Fill(f_ht600_Met,I_ht600_weight);
        }
    }

    TTree *T_event5;
    DYHT800->GetObject("T_event",T_event5);
    T_event5->SetBranchAddress("f_alphamin",&f_ht800_alphamin);
    T_event5->SetBranchAddress("f_Met",&f_ht800_Met);
    T_event5->SetBranchAddress("I_weight",&I_ht800_weight);
    for(int evt=0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if(f_ht800_Met > 90)
        {
            h_ht800A_aphmin->Fill(f_ht800_alphamin,I_ht800_weight);
        }
        if(f_ht800_Met < 80)
        {
            h_ht800B_aphmin->Fill(f_ht800_alphamin,I_ht800_weight);
        }
        if(f_ht800_alphamin > 0.1)
        {
            h_ht800A_met->Fill(f_ht800_Met,I_ht800_weight);
        }
        if(f_ht800_alphamin < 0.05)
        {
            h_ht800B_met->Fill(f_ht800_Met,I_ht800_weight);
        }
    }

    TTree *T_event6;
    DYHT1200->GetObject("T_event",T_event6);
    T_event6->SetBranchAddress("f_alphamin",&f_ht1200_alphamin);
    T_event6->SetBranchAddress("f_Met",&f_ht1200_Met);
    T_event6->SetBranchAddress("I_weight",&I_ht1200_weight);
    for(int evt=0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if(f_ht1200_Met > 90)
        {
            h_ht1200A_aphmin->Fill(f_ht1200_alphamin,I_ht1200_weight);
        }
        if(f_ht1200_Met < 80)
        {
            h_ht1200B_aphmin->Fill(f_ht1200_alphamin,I_ht1200_weight);
        }
        if(f_ht1200_alphamin > 0.1)
        {
            h_ht1200A_met->Fill(f_ht1200_Met,I_ht1200_weight);
        }
        if(f_ht1200_alphamin < 0.05)
        {
            h_ht1200B_met->Fill(f_ht1200_Met,I_ht1200_weight);
        }
    }

    TTree *T_event7;
    DYHT2500->GetObject("T_event",T_event7);
    T_event7->SetBranchAddress("f_alphamin",&f_ht2500_alphamin);
    T_event7->SetBranchAddress("f_Met",&f_ht2500_Met);
    T_event7->SetBranchAddress("I_weight",&I_ht2500_weight);
    for(int evt=0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        if(f_ht2500_Met > 90)
        {
            h_ht2500A_aphmin->Fill(f_ht2500_alphamin,I_ht2500_weight);
        }
        if(f_ht2500_Met < 80)
        {
            h_ht2500B_aphmin->Fill(f_ht2500_alphamin,I_ht2500_weight);
        }
        if(f_ht2500_alphamin > 0.1)
        {
            h_ht2500A_met->Fill(f_ht2500_Met,I_ht2500_weight);
        }
        if(f_ht2500_alphamin < 0.05)
        {
            h_ht2500B_met->Fill(f_ht2500_Met,I_ht2500_weight);
        }
    }


    h_ht70A_aphmin->Scale(35.9*(GlobalConstants::HT70CS/DYHT70_totevt));
    h_ht100A_aphmin->Scale(35.9*(GlobalConstants::HT100CS/DYHT100_totevt));
    h_ht200A_aphmin->Scale(35.9*(GlobalConstants::HT200CS/DYHT200_totevt)); 
    h_ht400A_aphmin->Scale(35.9*(GlobalConstants::HT400CS/DYHT400_totevt));
    h_ht600A_aphmin->Scale(35.9*(GlobalConstants::HT600CS/DYHT600_totevt));
    h_ht800A_aphmin->Scale(35.9*(GlobalConstants::HT800CS/DYHT800_totevt));
    h_ht1200A_aphmin->Scale(35.9*(GlobalConstants::HT1200CS/DYHT1200_totevt));
    h_ht2500A_aphmin->Scale(35.9*(GlobalConstants::HT2500CS/DYHT2500_totevt));
 

    h_ht70B_aphmin->Scale(35.9*(GlobalConstants::HT70CS/DYHT70_totevt));
    h_ht100B_aphmin->Scale(35.9*(GlobalConstants::HT100CS/DYHT100_totevt));
    h_ht200B_aphmin->Scale(35.9*(GlobalConstants::HT200CS/DYHT200_totevt)); 
    h_ht400B_aphmin->Scale(35.9*(GlobalConstants::HT400CS/DYHT400_totevt));
    h_ht600B_aphmin->Scale(35.9*(GlobalConstants::HT600CS/DYHT600_totevt));
    h_ht800B_aphmin->Scale(35.9*(GlobalConstants::HT800CS/DYHT800_totevt));
    h_ht1200B_aphmin->Scale(35.9*(GlobalConstants::HT1200CS/DYHT1200_totevt));
    h_ht2500B_aphmin->Scale(35.9*(GlobalConstants::HT2500CS/DYHT2500_totevt));
    
    h_ht70A_met->Scale(35.9*(GlobalConstants::HT70CS/DYHT70_totevt));
    h_ht100A_met->Scale(35.9*(GlobalConstants::HT100CS/DYHT100_totevt));
    h_ht200A_met->Scale(35.9*(GlobalConstants::HT200CS/DYHT200_totevt)); 
    h_ht400A_met->Scale(35.9*(GlobalConstants::HT400CS/DYHT400_totevt));
    h_ht600A_met->Scale(35.9*(GlobalConstants::HT600CS/DYHT600_totevt));
    h_ht800A_met->Scale(35.9*(GlobalConstants::HT800CS/DYHT800_totevt));
    h_ht1200A_met->Scale(35.9*(GlobalConstants::HT1200CS/DYHT1200_totevt));
    h_ht2500A_met->Scale(35.9*(GlobalConstants::HT2500CS/DYHT2500_totevt));


    h_ht70B_met->Scale(35.9*(GlobalConstants::HT70CS/DYHT70_totevt));
    h_ht100B_met->Scale(35.9*(GlobalConstants::HT100CS/DYHT100_totevt));
    h_ht200B_met->Scale(35.9*(GlobalConstants::HT200CS/DYHT200_totevt)); 
    h_ht400B_met->Scale(35.9*(GlobalConstants::HT400CS/DYHT400_totevt));
    h_ht600B_met->Scale(35.9*(GlobalConstants::HT600CS/DYHT600_totevt));
    h_ht800B_met->Scale(35.9*(GlobalConstants::HT800CS/DYHT800_totevt));
    h_ht1200B_met->Scale(35.9*(GlobalConstants::HT1200CS/DYHT1200_totevt));
    h_ht2500B_met->Scale(35.9*(GlobalConstants::HT2500CS/DYHT2500_totevt));


    h_ht70A_aphmin->Add(h_ht100A_aphmin);
    h_ht70A_aphmin->Add(h_ht200A_aphmin);
    h_ht70A_aphmin->Add(h_ht400A_aphmin);
    h_ht70A_aphmin->Add(h_ht600A_aphmin);
    h_ht70A_aphmin->Add(h_ht800A_aphmin);
    h_ht70A_aphmin->Add(h_ht1200A_aphmin);
    h_ht70A_aphmin->Add(h_ht2500A_aphmin);


    h_ht70B_aphmin->Add(h_ht100B_aphmin);
    h_ht70B_aphmin->Add(h_ht200B_aphmin);
    h_ht70B_aphmin->Add(h_ht400B_aphmin);
    h_ht70B_aphmin->Add(h_ht600B_aphmin);
    h_ht70B_aphmin->Add(h_ht800B_aphmin);
    h_ht70B_aphmin->Add(h_ht1200B_aphmin);
    h_ht70B_aphmin->Add(h_ht2500B_aphmin);

    h_ht70A_met->Add(h_ht100A_met);
    //h_ht70A_met->Add(h_ht200A_met);
    //h_ht70A_met->Add(h_ht400A_met);
    //h_ht70A_met->Add(h_ht600A_met);
    //h_ht70A_met->Add(h_ht800A_met);
    //h_ht70A_met->Add(h_ht1200A_met);
    //h_ht70A_met->Add(h_ht2500A_met);

    h_ht70B_met->Add(h_ht100B_met);
    h_ht70B_met->Add(h_ht200B_met);
    h_ht70B_met->Add(h_ht400B_met);
    h_ht70B_met->Add(h_ht600B_met);
    h_ht70B_met->Add(h_ht800B_met);
    h_ht70B_met->Add(h_ht1200B_met);
    h_ht70B_met->Add(h_ht2500B_met);

    h_ht70A_aphmin = (TH1F*)gDirectory->Get("h_ht70A_aphmin");
    h_ht70B_aphmin = (TH1F*)gDirectory->Get("h_ht70B_aphmin");

    h_ht70A_met = (TH1F*)gDirectory->Get("h_ht70A_met");
    h_ht70B_met = (TH1F*)gDirectory->Get("h_ht70B_met");

    auto *c1 = new TCanvas("c1","c1");

    TFile *outFile = new TFile("./../../ABCD_HT.root", "RECREATE");
    outFile->cd();

    h_ht70A_aphmin->Write();
    h_ht70B_aphmin->Write();
    h_ht70A_met->Write();
    h_ht70B_met->Write();
    h_ht100A_met->Write();
    h_ht100B_met->Write();
    h_ht200A_met->Write();
    h_ht200B_met->Write();
    h_ht400A_met->Write();
    h_ht400B_met->Write();
    h_ht600A_met->Write();
    h_ht600B_met->Write();
    h_ht800A_met->Write();
    h_ht800B_met->Write();
    h_ht1200A_met->Write();
    h_ht1200B_met->Write();
    h_ht2500A_met->Write();
    h_ht2500B_met->Write();
    outFile->Close();
    

}