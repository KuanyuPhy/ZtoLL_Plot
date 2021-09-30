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

using namespace RooFit;
//#include "TRooH1D.h"
//#include "Cross_section.h"

void BGEM(){


    TFile *Mx2_1 = new TFile("./../../root_file/Ztoee/test1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/Ztoee/test50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/Ztoee/test150.root");
    
    TFile *DYpT50 = new TFile("./../../root_file/Ztoee/test_pt50.root");
    TFile *DYpT100 = new TFile("./../../root_file/Ztoee/test_pt100.root");
    TFile *DYpT250 = new TFile("./../../root_file/Ztoee/test_pt250.root");
    TFile *DYpT400 = new TFile("./../../root_file/Ztoee/test_pt400.root");
    TFile *DYpT650 = new TFile("./../../root_file/Ztoee/test_pt650.root");

    
    TFile *DYHT70 = new TFile("./../../root_file/Ztoee/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../root_file/Ztoee/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../root_file/Ztoee/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../root_file/Ztoee/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../root_file/Ztoee/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../root_file/Ztoee/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../root_file/Ztoee/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../root_file/Ztoee/ee_ht2500.root");


    TH1D *DYPT50_sumW = ((TH1D *)DYpT50->Get("h_SumWeight"));
    TH1D *DYPT100_sumW = ((TH1D *)DYpT100->Get("h_SumWeight"));
    TH1D *DYPT250_sumW = ((TH1D *)DYpT250->Get("h_SumWeight"));
    TH1D *DYPT400_sumW = ((TH1D *)DYpT400->Get("h_SumWeight"));
    TH1D *DYPT650_sumW = ((TH1D *)DYpT650->Get("h_SumWeight")); 

    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("h_event"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("h_event"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("h_event"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("h_event"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("h_event"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("h_event"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("h_event"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("h_event"));   
    
    double DYPT50_SW = DYPT50_sumW->GetBinContent(1);
    double DYPT100_SW = DYPT100_sumW->GetBinContent(1);
    double DYPT250_SW = DYPT250_sumW->GetBinContent(1);
    double DYPT400_SW = DYPT400_sumW->GetBinContent(1);
    double DYPT650_SW = DYPT650_sumW->GetBinContent(1);

    int DYHT70_totevt = DYHT70_sumevt->GetEntries();
    int DYHT100_totevt = DYHT100_sumevt->GetEntries();
    int DYHT200_totevt = DYHT200_sumevt->GetEntries();
    int DYHT400_totevt = DYHT400_sumevt->GetEntries();
    int DYHT600_totevt = DYHT600_sumevt->GetEntries();
    int DYHT800_totevt = DYHT800_sumevt->GetEntries();
    int DYHT1200_totevt = DYHT1200_sumevt->GetEntries();
    int DYHT2500_totevt = DYHT2500_sumevt->GetEntries();  

    //TH1F *h_A,*h_Bsr,*h_Ccr,*h_Dcr;
    TH1F *h_pt50A_aphmin = new TH1F("h_pt50A_aphmin", "", 24, 0, 1.2);
    h_pt50A_aphmin->Sumw2();
    TH1F *h_pt50B_aphmin = new TH1F("h_pt50B_aphmin", "", 24, 0, 1.2);
    h_pt50B_aphmin->Sumw2();

    TH1F *h_pt100A_aphmin = new TH1F("h_pt100A_aphmin", "", 24, 0, 1.2);
    h_pt100A_aphmin->Sumw2();
    TH1F *h_pt100B_aphmin = new TH1F("h_pt100B_aphmin", "", 24, 0, 1.2);
    h_pt100B_aphmin->Sumw2();

    TH1F *h_pt250A_aphmin = new TH1F("h_pt250A_aphmin", "", 24, 0, 1.2);
    h_pt250A_aphmin->Sumw2();
    TH1F *h_pt250B_aphmin = new TH1F("h_pt250B_aphmin", "", 24, 0, 1.2);
    h_pt250B_aphmin->Sumw2();

    TH1F *h_pt400A_aphmin = new TH1F("h_pt400A_aphmin", "", 24, 0, 1.2);
    h_pt400A_aphmin->Sumw2();
    TH1F *h_pt400B_aphmin = new TH1F("h_pt400B_aphmin", "", 24, 0, 1.2);
    h_pt400B_aphmin->Sumw2();

    TH1F *h_pt650A_aphmin = new TH1F("h_pt650A_aphmin", "", 24, 0, 1.2);
    h_pt650A_aphmin->Sumw2();
    TH1F *h_pt650B_aphmin = new TH1F("h_pt650B_aphmin", "", 24, 0, 1.2);
    h_pt650B_aphmin->Sumw2();

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


    TH1F *h_pt50A_met = new TH1F("h_pt50A_met", "", 24, 0, 1000);
    h_pt50A_met->Sumw2();
    TH1F *h_pt50B_met = new TH1F("h_pt50B_met", "", 24, 0, 1000);
    h_pt50B_met->Sumw2();

    TH1F *h_pt100A_met = new TH1F("h_pt100A_met", "", 24, 0, 1000);
    h_pt100A_met->Sumw2();
    TH1F *h_pt100B_met = new TH1F("h_pt100B_met", "", 24, 0, 1000);
    h_pt100B_met->Sumw2();

    TH1F *h_pt250A_met = new TH1F("h_pt250A_met", "", 24, 0, 1000);
    h_pt250A_met->Sumw2();
    TH1F *h_pt250B_met = new TH1F("h_pt250B_met", "", 24, 0, 1000);
    h_pt250B_met->Sumw2();

    TH1F *h_pt400A_met = new TH1F("h_pt400A_met", "", 24, 0, 1000);
    h_pt400A_met->Sumw2();
    TH1F *h_pt400B_met = new TH1F("h_pt400B_met", "", 24, 0, 1000);
    h_pt400B_met->Sumw2();

    TH1F *h_pt650A_met = new TH1F("h_pt650A_met", "", 24, 0, 1000);
    h_pt650A_met->Sumw2();
    TH1F *h_pt650B_met = new TH1F("h_pt650B_met", "", 24, 0, 1000);
    h_pt650B_met->Sumw2();

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
    
    TH1F* h_pt50_A_alphamin = new TH1F("h_pt50_A_alphamin","",40,0.01,1.0);
    h_pt50_A_alphamin->Sumw2();

    TH1F* h_pt50_A_met = new TH1F("h_pt50_A_met","",40,90.,1000.);
    h_pt50_A_met->Sumw2();

    TH1F* h_pt100_A_alphamin = new TH1F("h_pt100_A_alphamin","",40,0.01,1.0);
    h_pt100_A_alphamin->Sumw2();
    
    TH1F* h_pt100_A_met = new TH1F("h_pt100_A_met","",40,90.,1000.);
    h_pt100_A_met->Sumw2();
    
    TH1F* h_pt250_A_alphamin = new TH1F("h_pt250_A_alphamin","",40,0.01,1.0);
    h_pt250_A_alphamin->Sumw2();

    TH1F* h_pt250_A_met = new TH1F("h_pt250_A_met","",40,90.,1000.);
    h_pt250_A_met->Sumw2();
    
    TH1F* h_pt400_A_alphamin = new TH1F("h_pt400_A_alphamin","",40,0.01,1.0);
    h_pt400_A_alphamin->Sumw2();

    TH1F* h_pt400_A_met = new TH1F("h_pt400_A_met","",40,90.,1000.);
    h_pt400_A_met->Sumw2();
    
    TH1F* h_pt650_A_alphamin = new TH1F("h_pt650_A_alphamin","",40,0.01,1.0);
    h_pt650_A_alphamin->Sumw2();

    TH1F* h_pt650_A_met = new TH1F("h_pt650_A_met","",40,90.,1000.);
    h_pt650_A_met->Sumw2();

    TH1F* h_pt50_B_alphamin = new TH1F("h_pt50_B_alphamin","",40,0.0,0.05);
    h_pt50_B_alphamin->Sumw2();

    TH1F* h_pt50_B_met = new TH1F("h_pt50_B_met","",40,90.,1000.);
    h_pt50_B_met->Sumw2();

    TH1F* h_pt100_B_alphamin = new TH1F("h_pt100_B_alphamin","",40,0.0,0.05);
    h_pt100_B_alphamin->Sumw2();

    TH1F* h_pt100_B_met = new TH1F("h_pt100_B_met","",40,90.,1000.);
    h_pt100_B_met->Sumw2();

    TH1F* h_pt250_B_alphamin = new TH1F("h_pt250_B_alphamin","",40,0.0,0.05);
    h_pt250_B_alphamin->Sumw2();

    TH1F* h_pt250_B_met = new TH1F("h_pt250_B_met","",40,90.,1000.);
    h_pt250_B_met->Sumw2();

    TH1F* h_pt400_B_alphamin = new TH1F("h_pt400_B_alphamin","",40,0.0,0.05);
    h_pt400_B_alphamin->Sumw2();

    TH1F* h_pt400_B_met = new TH1F("h_pt400_B_met","",40,90.,1000.);
    h_pt400_B_met->Sumw2();

    TH1F* h_pt650_B_alphamin = new TH1F("h_pt650_B_alphamin","",40,0.0,0.05);
    h_pt650_B_alphamin->Sumw2();

    TH1F* h_pt650_B_met = new TH1F("h_pt650_B_met","",40,90.,1000.);
    h_pt650_B_met->Sumw2();   

    TH1F* h_pt50_C_alphamin = new TH1F("h_pt50_C_alphamin","",40,0.01,1.0);
    h_pt50_C_alphamin->Sumw2();

    TH1F* h_pt50_C_met = new TH1F("h_pt50_C_met","",40,0.,90.);
    h_pt50_C_met->Sumw2();

    TH1F* h_pt100_C_alphamin = new TH1F("h_pt100_C_alphamin","",40,0.01,1.0);
    h_pt100_C_alphamin->Sumw2();

    TH1F* h_pt100_C_met = new TH1F("h_pt100_C_met","",40,0.,90.);
    h_pt100_C_met->Sumw2();

    TH1F* h_pt250_C_alphamin = new TH1F("h_pt250_C_alphamin","",40,0.01,1.0);
    h_pt250_C_alphamin->Sumw2();

    TH1F* h_pt250_C_met = new TH1F("h_pt250_C_met","",40,0.,90.);
    h_pt250_C_met->Sumw2();
    
    TH1F* h_pt400_C_alphamin = new TH1F("h_pt400_C_alphamin","",40,0.01,1.0);
    h_pt400_C_alphamin->Sumw2();

    TH1F* h_pt400_C_met = new TH1F("h_pt400_C_met","",40,0.,90.);
    h_pt400_C_met->Sumw2();

    TH1F* h_pt650_C_alphamin = new TH1F("h_pt650_C_alphamin","",40,0.01,1.0);
    h_pt650_C_alphamin->Sumw2();

    TH1F* h_pt650_C_met = new TH1F("h_pt650_C_met","",40,0.,90.);
    h_pt650_C_met->Sumw2();   

    TH1F* h_pt50_D_alphamin = new TH1F("h_pt50_D_alphamin","",40,0.0,0.05);
    h_pt50_D_alphamin->Sumw2();

    TH1F* h_pt50_D_met = new TH1F("h_pt50_D_met","",40,0.,90.);
    h_pt50_D_met->Sumw2();

    TH1F* h_pt100_D_alphamin = new TH1F("h_pt100_D_alphamin","",40,0.0,0.05);
    h_pt100_D_alphamin->Sumw2();

    TH1F* h_pt100_D_met = new TH1F("h_pt100_D_met","",40,0.,90.);
    h_pt100_D_met->Sumw2();

    TH1F* h_pt250_D_alphamin = new TH1F("h_pt250_D_alphamin","",40,0.0,0.05);
    h_pt250_D_alphamin->Sumw2();

    TH1F* h_pt250_D_met = new TH1F("h_pt250_D_met","",40,0.,90.);
    h_pt250_D_met->Sumw2();

    TH1F* h_pt400_D_alphamin = new TH1F("h_pt400_D_alphamin","",40,0.0,0.05);
    h_pt400_D_alphamin->Sumw2();

    TH1F* h_pt400_D_met = new TH1F("h_pt400_D_met","",40,0.,90.);
    h_pt400_D_met->Sumw2();

    TH1F* h_pt650_D_alphamin = new TH1F("h_pt650_D_alphamin","",40,0.0,0.05);
    h_pt650_D_alphamin->Sumw2();

    TH1F* h_pt650_D_met = new TH1F("h_pt650_D_met","",40,0.,90.);
    h_pt650_D_met->Sumw2();



    double f_pt50_alphamin, f_pt100_alphamin, f_pt250_alphamin,f_pt400_alphamin,f_pt650_alphamin;
    float f_pt50_Met, f_pt100_Met, f_pt250_Met, f_pt400_Met, f_pt650_Met;
    int I_pt50_weight, I_pt100_weight, I_pt250_weight, I_pt400_weight, I_pt650_weight;


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
    DYpT50->GetObject("T_event",T_event);

    T_event->SetBranchAddress("f_alphamin",&f_pt50_alphamin);
    T_event->SetBranchAddress("f_Met",&f_pt50_Met);
    T_event->SetBranchAddress("I_weight",&I_pt50_weight);


    for(int evt=0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        //h_pt50_aphmin->Fill(f_pt50_alphamin,I_pt50_weight);
        if(f_pt50_alphamin > BoxA_amin && f_pt50_Met > BoxA_Met)
        {
            
            h_pt50_A_alphamin->Fill(f_pt50_alphamin,I_pt50_weight);
            h_pt50_A_met->Fill(f_pt50_Met,I_pt50_weight);
        }
        if(f_pt50_alphamin < BoxB_amin && f_pt50_Met > BoxB_Met)
        {
            //cout<<f_pt50_alphamin<<endl;
            h_pt50_B_alphamin->Fill(f_pt50_alphamin,I_pt50_weight);
            h_pt50_B_met->Fill(f_pt50_Met,I_pt50_weight);
        }
        if(f_pt50_alphamin > BoxC_amin && f_pt50_Met < BoxC_Met)
        {
            h_pt50_C_alphamin->Fill(f_pt50_alphamin,I_pt50_weight);
            h_pt50_C_met->Fill(f_pt50_Met,I_pt50_weight);
        }
        if(f_pt50_alphamin < BoxD_amin && f_pt50_Met < BoxD_Met)
        {
            h_pt50_D_alphamin->Fill(f_pt50_alphamin,I_pt50_weight);
            h_pt50_D_met->Fill(f_pt50_Met,I_pt50_weight);
        }
        if(f_pt50_Met > 90)
        {
            h_pt50A_aphmin->Fill(f_pt50_alphamin,I_pt50_weight);
        }
        if(f_pt50_Met < 80)
        {
            
            h_pt50B_aphmin->Fill(f_pt50_alphamin,I_pt50_weight);
        }
        if(f_pt50_alphamin > 0.1)
        {
            h_pt50A_met->Fill(f_pt50_Met,I_pt50_weight);
        }
        if(f_pt50_alphamin < 0.05)
        {
            h_pt50B_met->Fill(f_pt50_Met,I_pt50_weight);
        }
        h_pt50A_aphmin->Draw();
    }
    h_pt50_A_alphamin->Scale(344.3 / DYPT50_SW);
    h_pt50_A_met->Scale(344.3 / DYPT50_SW);
    h_pt50_B_alphamin->Scale(344.3 / DYPT50_SW);
    h_pt50_B_met->Scale(344.3 / DYPT50_SW);
    h_pt50_C_alphamin->Scale(344.3 / DYPT50_SW);
    h_pt50_C_met->Scale(344.3 / DYPT50_SW);
    h_pt50_D_alphamin->Scale(344.3 / DYPT50_SW);
    h_pt50_D_met->Scale(344.3 / DYPT50_SW);

    TTree *T_event1;
    DYpT100->GetObject("T_event",T_event1);
    T_event1->SetBranchAddress("f_alphamin",&f_pt100_alphamin);
    T_event1->SetBranchAddress("f_Met",&f_pt100_Met);
    T_event1->SetBranchAddress("I_weight",&I_pt100_weight);
    for(int evt=0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        //h_pt100_aphmin->Fill(f_pt100_alphamin,I_pt100_weight);
        if(f_pt100_alphamin > BoxA_amin &&f_pt100_Met > BoxA_Met)
        {
            h_pt100_A_alphamin->Fill(f_pt100_alphamin,I_pt100_weight);
            h_pt100_A_met->Fill(f_pt100_Met,I_pt100_weight);
        }
        if(f_pt100_alphamin < BoxB_amin &&f_pt100_Met > BoxB_Met)
        {
            h_pt100_B_alphamin->Fill(f_pt100_alphamin,I_pt100_weight);
            h_pt100_B_met->Fill(f_pt100_Met,I_pt100_weight);
        }
        if(f_pt100_alphamin > BoxC_amin &&f_pt100_Met < BoxC_Met)
        {
            h_pt100_C_alphamin->Fill(f_pt100_alphamin,I_pt100_weight);
            h_pt100_C_met->Fill(f_pt100_Met,I_pt100_weight);
        }
        if(f_pt100_alphamin < BoxD_amin && f_pt100_Met < BoxD_Met)
        {
            h_pt100_D_alphamin->Fill(f_pt100_alphamin,I_pt100_weight);
            h_pt100_D_met->Fill(f_pt100_Met,I_pt100_weight);
        }
        if(f_pt100_Met > 90)
        {
            h_pt100A_aphmin->Fill(f_pt100_alphamin,I_pt100_weight);
        }
        if(f_pt100_Met < 80)
        {
            h_pt100B_aphmin->Fill(f_pt100_alphamin,I_pt100_weight);
        }
        if(f_pt100_alphamin > 0.1)
        {
            h_pt100A_met->Fill(f_pt100_Met,I_pt100_weight);
        }
        if(f_pt100_alphamin < 0.05)
        {
            h_pt100B_met->Fill(f_pt100_Met,I_pt100_weight);
        }
    }
    h_pt100_A_alphamin->Scale(80.64 / DYPT100_SW);
    h_pt100_A_met->Scale(80.64 / DYPT100_SW);
    h_pt100_B_alphamin->Scale(80.64 / DYPT100_SW);
    h_pt100_B_met->Scale(80.64 / DYPT100_SW);
    h_pt100_C_alphamin->Scale(80.64 / DYPT100_SW);
    h_pt100_C_met->Scale(80.64 / DYPT100_SW);
    h_pt100_D_alphamin->Scale(80.64 / DYPT100_SW);
    h_pt100_D_met->Scale(80.64 / DYPT100_SW);

    TTree *T_event2;
    DYpT250->GetObject("T_event",T_event2);
    T_event2->SetBranchAddress("f_alphamin",&f_pt250_alphamin);
    T_event2->SetBranchAddress("f_Met",&f_pt250_Met);
    T_event2->SetBranchAddress("I_weight",&I_pt250_weight);
    for(int evt=0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        //h_pt250_aphmin->Fill(f_pt250_alphamin,I_pt250_weight);
        if(f_pt250_alphamin > BoxA_amin && f_pt250_Met > BoxA_Met)
        {
            h_pt250_A_alphamin->Fill(f_pt250_alphamin,I_pt250_weight);
            h_pt250_A_met->Fill(f_pt250_Met,I_pt250_weight);
        }
        if(f_pt250_alphamin < BoxB_amin && f_pt250_Met > BoxB_Met)
        {
            h_pt250_B_alphamin->Fill(f_pt250_alphamin,I_pt250_weight);
            h_pt250_B_met->Fill(f_pt250_Met,I_pt250_weight);
        }
        if(f_pt250_alphamin > BoxC_amin && f_pt250_Met < BoxC_Met)
        {
            h_pt250_C_alphamin->Fill(f_pt250_alphamin,I_pt250_weight);
            h_pt250_C_met->Fill(f_pt250_Met,I_pt250_weight);
        }
        if(f_pt250_alphamin < BoxD_amin && f_pt250_Met < BoxD_Met)
        {
            h_pt250_D_alphamin->Fill(f_pt250_alphamin,I_pt250_weight);
            h_pt250_D_met->Fill(f_pt250_Met,I_pt250_weight);
        }
        if(f_pt250_Met > 90)
        {
            h_pt250A_aphmin->Fill(f_pt250_alphamin,I_pt250_weight);
        }
        if(f_pt250_Met < 80)
        {
            h_pt250B_aphmin->Fill(f_pt250_alphamin,I_pt250_weight);
        }
        if(f_pt250_alphamin > 0.1)
        {
            h_pt250A_met->Fill(f_pt250_Met,I_pt250_weight);
        }
        if(f_pt250_alphamin < 0.05)
        {
            h_pt250B_met->Fill(f_pt250_Met,I_pt250_weight);
        }
    }


    h_pt250_A_alphamin->Scale(2.955 / DYPT250_SW);
    h_pt250_A_met->Scale(2.955 / DYPT250_SW);
    h_pt250_B_alphamin->Scale(2.955 / DYPT250_SW);
    h_pt250_B_met->Scale(2.955 / DYPT250_SW);
    h_pt250_C_alphamin->Scale(2.955 / DYPT250_SW);
    h_pt250_C_met->Scale(2.955 / DYPT250_SW);
    h_pt250_D_alphamin->Scale(2.955 / DYPT250_SW);
    h_pt250_D_met->Scale(2.955 / DYPT250_SW);

    TTree *T_event3;
    DYpT400->GetObject("T_event",T_event3);
    T_event3->SetBranchAddress("f_alphamin",&f_pt400_alphamin);
    T_event3->SetBranchAddress("f_Met",&f_pt400_Met);
    T_event3->SetBranchAddress("I_weight",&I_pt400_weight);
    for(int evt=0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        //h_pt400_aphmin->Fill(f_pt400_alphamin,I_pt400_weight);
        if(f_pt400_alphamin > BoxA_amin && f_pt400_Met > BoxA_Met)
        {
            h_pt400_A_alphamin->Fill(f_pt400_alphamin,I_pt400_weight);
            h_pt400_A_met->Fill(f_pt400_Met,I_pt400_weight);
        }
        if(f_pt400_alphamin < BoxB_amin && f_pt400_Met > BoxB_Met)
        {
            h_pt400_B_alphamin->Fill(f_pt400_alphamin,I_pt400_weight);
            h_pt400_B_met->Fill(f_pt400_Met,I_pt400_weight);
        }
        if(f_pt400_alphamin > BoxC_amin && f_pt400_Met < BoxC_Met)
        {
            h_pt400_C_alphamin->Fill(f_pt400_alphamin,I_pt400_weight);
            h_pt400_C_met->Fill(f_pt400_Met,I_pt400_weight);
        }
        if(f_pt400_alphamin < BoxD_amin &&f_pt400_Met < BoxD_Met)
        {
            h_pt400_D_alphamin->Fill(f_pt400_alphamin,I_pt400_weight);
            h_pt400_D_met->Fill(f_pt400_Met,I_pt400_weight);
        }
        if(f_pt400_Met > 90)
        {
            h_pt400A_aphmin->Fill(f_pt400_alphamin,I_pt400_weight);
        }
        if(f_pt400_Met < 80)
        {
            h_pt400B_aphmin->Fill(f_pt400_alphamin,I_pt400_weight);
        }
        if(f_pt400_alphamin > 0.1)
        {
            h_pt400A_met->Fill(f_pt400_Met,I_pt400_weight);
        }
        if(f_pt400_alphamin < 0.05)
        {
            h_pt400B_met->Fill(f_pt400_Met,I_pt400_weight);
        }
    }
    //h_pt400_C_met->Draw();

    h_pt400_A_alphamin->Scale(0.3807  / DYPT400_SW);
    h_pt400_A_met->Scale(0.3807  / DYPT400_SW);
    h_pt400_B_alphamin->Scale(0.3807  / DYPT400_SW);
    h_pt400_B_met->Scale(0.3807  / DYPT400_SW);
    h_pt400_C_alphamin->Scale(0.3807  / DYPT400_SW);
    h_pt400_C_met->Scale(0.3807  / DYPT400_SW);
    h_pt400_D_alphamin->Scale(0.3807  / DYPT400_SW);
    h_pt400_D_met->Scale(0.3807  / DYPT400_SW);

    TTree *T_event4;
    DYpT650->GetObject("T_event",T_event4);
    T_event4->SetBranchAddress("f_alphamin",&f_pt650_alphamin);
    T_event4->SetBranchAddress("f_Met",&f_pt650_Met);
    T_event4->SetBranchAddress("I_weight",&I_pt650_weight);
    for(int evt=0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        //h_pt650_aphmin->Fill(f_pt650_alphamin,I_pt650_weight);
        if(f_pt650_alphamin > BoxA_amin && f_pt650_Met > BoxA_Met)
        {
            h_pt650_A_alphamin->Fill(f_pt650_alphamin,I_pt650_weight);
            h_pt650_A_met->Fill(f_pt650_Met,I_pt650_weight);
        }
        if(f_pt650_alphamin < BoxB_amin && f_pt650_Met > BoxB_Met)
        {
            h_pt650_B_alphamin->Fill(f_pt650_alphamin,I_pt650_weight);
            h_pt650_B_met->Fill(f_pt650_Met,I_pt650_weight);
        }
        if(f_pt650_alphamin > BoxC_amin && f_pt650_Met < BoxC_Met)
        {
            h_pt650_C_alphamin->Fill(f_pt650_alphamin,I_pt650_weight);
            h_pt650_C_met->Fill(f_pt650_Met,I_pt650_weight);
        }
        if(f_pt650_alphamin < BoxD_amin && f_pt650_Met < BoxD_Met)
        {
            h_pt650_D_alphamin->Fill(f_pt650_alphamin,I_pt650_weight);
            h_pt650_D_met->Fill(f_pt650_Met,I_pt650_weight);
        }
        if(f_pt650_Met > 90)
        {
            h_pt650A_aphmin->Fill(f_pt650_alphamin,I_pt650_weight);
        }
        if(f_pt650_Met < 80)
        {
            h_pt650B_aphmin->Fill(f_pt650_alphamin,I_pt650_weight);
        }
        if(f_pt650_alphamin > 0.1)
        {
            h_pt650A_met->Fill(f_pt650_Met,I_pt650_weight);
        }
        if(f_pt650_alphamin < 0.05)
        {
            h_pt650B_met->Fill(f_pt650_Met,I_pt650_weight);
        }
    }
    h_pt650_A_alphamin->Scale(0.03711 / DYPT650_SW);
    h_pt650_A_met->Scale(0.03711 / DYPT650_SW);
    h_pt650_B_alphamin->Scale(0.03711 / DYPT650_SW);
    h_pt650_B_met->Scale(0.03711 / DYPT650_SW);
    h_pt650_C_alphamin->Scale(0.03711 / DYPT650_SW);
    h_pt650_C_met->Scale(0.03711 / DYPT650_SW);
    h_pt650_D_alphamin->Scale(0.03711 / DYPT650_SW);
    h_pt650_D_met->Scale(0.03711 / DYPT650_SW);



    h_pt50A_aphmin->Scale(344.3 / DYPT50_SW);
    h_pt100A_aphmin->Scale(80.64 / DYPT100_SW);
    h_pt250A_aphmin->Scale(2.955 / DYPT250_SW);
    h_pt400A_aphmin->Scale(0.3807  / DYPT400_SW);
    h_pt650A_aphmin->Scale(0.03711 / DYPT650_SW);

    h_pt50B_aphmin->Scale(344.3 / DYPT50_SW);
    h_pt100B_aphmin->Scale(80.64 / DYPT100_SW);
    h_pt250B_aphmin->Scale(2.955 / DYPT250_SW);
    h_pt400B_aphmin->Scale(0.3807  / DYPT400_SW);
    h_pt650B_aphmin->Scale(0.03711 / DYPT650_SW);


    h_pt50A_met->Scale(344.3 / DYPT50_SW);
    h_pt100A_met->Scale(80.64 / DYPT100_SW);
    h_pt250A_met->Scale(2.955 / DYPT250_SW);
    h_pt400A_met->Scale(0.3807  / DYPT400_SW);
    h_pt650A_met->Scale(0.03711 / DYPT650_SW);

    h_pt50B_met->Scale(344.3 / DYPT50_SW);
    h_pt100B_met->Scale(80.64 / DYPT100_SW);
    h_pt250B_met->Scale(2.955 / DYPT250_SW);
    h_pt400B_met->Scale(0.3807  / DYPT400_SW);
    h_pt650B_met->Scale(0.03711 / DYPT650_SW);


    h_pt50A_aphmin->Add(h_pt100A_aphmin);
    h_pt50A_aphmin->Add(h_pt250A_aphmin);
    h_pt50A_aphmin->Add(h_pt400A_aphmin);
    h_pt50A_aphmin->Add(h_pt650A_aphmin);

    h_pt50B_aphmin->Add(h_pt100B_aphmin);
    h_pt50B_aphmin->Add(h_pt250B_aphmin);
    h_pt50B_aphmin->Add(h_pt400B_aphmin);
    h_pt50B_aphmin->Add(h_pt650B_aphmin);

    h_pt50A_met->Add(h_pt100A_met);
    //h_pt50A_met->Add(h_pt250A_met);
    //h_pt50A_met->Add(h_pt400A_met);
    //h_pt50A_met->Add(h_pt650A_met);

    h_pt50B_met->Add(h_pt100B_met);
    //h_pt50B_met->Add(h_pt250B_met);
    //h_pt50B_met->Add(h_pt400B_met);
    //h_pt50B_met->Add(h_pt650B_met);


    h_pt50_A_alphamin->Add(h_pt100_A_alphamin);
    h_pt50_A_alphamin->Add(h_pt250_A_alphamin);
    h_pt50_A_alphamin->Add(h_pt400_A_alphamin);
    h_pt50_A_alphamin->Add(h_pt650_A_alphamin);

    h_pt50_A_met->Add(h_pt100_A_met);
    h_pt50_A_met->Add(h_pt250_A_met);
    h_pt50_A_met->Add(h_pt400_A_met);
    h_pt50_A_met->Add(h_pt650_A_met);

    h_pt50_B_alphamin->Add(h_pt100_B_alphamin);
    h_pt50_B_alphamin->Add(h_pt250_B_alphamin);
    h_pt50_B_alphamin->Add(h_pt400_B_alphamin);
    h_pt50_B_alphamin->Add(h_pt650_B_alphamin);

    h_pt50_B_met->Add(h_pt100_B_met);
    h_pt50_B_met->Add(h_pt250_B_met);
    h_pt50_B_met->Add(h_pt400_B_met);
    h_pt50_B_met->Add(h_pt650_B_met);

    h_pt50_C_alphamin->Add(h_pt100_C_alphamin);
    h_pt50_C_alphamin->Add(h_pt250_C_alphamin);
    h_pt50_C_alphamin->Add(h_pt400_C_alphamin);
    h_pt50_C_alphamin->Add(h_pt650_C_alphamin);

    h_pt50_C_met->Add(h_pt100_C_met);
    h_pt50_C_met->Add(h_pt250_C_met);
    h_pt50_C_met->Add(h_pt400_C_met);
    h_pt50_C_met->Add(h_pt650_C_met);

    h_pt50_D_alphamin->Add(h_pt100_D_alphamin);
    h_pt50_D_alphamin->Add(h_pt250_D_alphamin);
    h_pt50_D_alphamin->Add(h_pt400_D_alphamin);
    h_pt50_D_alphamin->Add(h_pt650_D_alphamin);

    h_pt50_D_met->Add(h_pt100_D_met);
    h_pt50_D_met->Add(h_pt250_D_met);
    h_pt50_D_met->Add(h_pt400_D_met);
    h_pt50_D_met->Add(h_pt650_D_met);

    //h_pt50_aphmin->Scale(344.3 / DYPT50_SW);
    //h_pt100_aphmin->Scale(80.64 / DYPT100_SW);
    //h_pt250_aphmin->Scale(2.955 / DYPT250_SW);
    //h_pt400_aphmin->Scale(0.3807  / DYPT400_SW);
    //h_pt650_aphmin->Scale(0.03711 / DYPT650_SW);
    //h_pt50_aphmin->Add(h_pt100_aphmin);
    //h_pt50_aphmin->Add(h_pt250_aphmin);
    //h_pt50_aphmin->Add(h_pt400_aphmin);
    //h_pt50_aphmin->Add(h_pt650_aphmin);



    //h_pt50A_aphmin->Draw();

    h_pt50_A_alphamin = (TH1F*)gDirectory->Get("h_pt50_A_alphamin");
    h_pt50_B_alphamin = (TH1F*)gDirectory->Get("h_pt50_B_alphamin");
    h_pt50_C_alphamin = (TH1F*)gDirectory->Get("h_pt50_C_alphamin");
    h_pt50_D_alphamin = (TH1F*)gDirectory->Get("h_pt50_D_alphamin");

    h_pt50A_aphmin = (TH1F*)gDirectory->Get("h_pt50A_aphmin");
    h_pt50B_aphmin = (TH1F*)gDirectory->Get("h_pt50B_aphmin");

    h_pt50A_met = (TH1F*)gDirectory->Get("h_pt50A_met");
    h_pt50B_met = (TH1F*)gDirectory->Get("h_pt50B_met");

    h_pt50_A_met = (TH1F*)gDirectory->Get("h_pt50_A_met");
    h_pt50_B_met = (TH1F*)gDirectory->Get("h_pt50_B_met");
    h_pt50_C_met = (TH1F*)gDirectory->Get("h_pt50_C_met");
    h_pt50_D_met = (TH1F*)gDirectory->Get("h_pt50_D_met");

    auto *c1 = new TCanvas("c1","c1");
    //TCanvas *c1 = new TCanvas("", "",10, 10, 700, 700);
    //c1->Divide(2, 1);
    //c1->cd(1);
    //h_pt50A_aphmin->Draw();
    //c1->cd(2);
    //h_pt50B_aphmin->Draw();
    //h_pt50_A_alphamin->Draw();

    TFile *outFile = new TFile("./../../ABCD.root", "RECREATE");
    outFile->cd();
    h_pt50_A_alphamin->Write();
    h_pt50_B_alphamin->Write();
    h_pt50_C_alphamin->Write();
    h_pt50_D_alphamin->Write();
    h_pt50A_aphmin->Write();
    h_pt50B_aphmin->Write();
    h_pt50A_met->Write();
    h_pt100A_met->Write();
    h_pt250A_met->Write();
    h_pt400A_met->Write();
    h_pt650A_met->Write();
    h_pt50B_met->Write();
    h_pt100B_met->Write();
    h_pt250B_met->Write();
    h_pt400B_met->Write();
    h_pt650B_met->Write();
    h_pt50_A_met->Write();
    h_pt50_B_met->Write();
    h_pt50_C_met->Write();
    h_pt50_D_met->Write();

    outFile->Close();
}