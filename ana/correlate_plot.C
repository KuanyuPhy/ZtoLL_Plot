
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
#include "./lib/Cross_section.h"

/*
float Linear_Correlation(TFile *T_File, TTree *T_OBject, int x, double y, float z)
{

    T_File->GetObject("T_OBject",T_OBject);
    T_OBject->SetBranchAddress("I_nJets",&x);
    T_OBject->SetBranchAddress("f_alphamin",&y);
    T_OBject->SetBranchAddress("f_Met",&z);

    Int_t  total_n = (Int_t )T_OBject->GetEntries();
    float sumx = 0;
    float sumy = 0;
    float sumxy = 0;
    float sumxsq = 0;
    float sumysq = 0;
    for (Int_t  k = 0; k < total_n; k++)
    {
        BDT_variables->GetEntry(k);
        sumx += x;
        sumy += y;
        sumxy += x * y;
        sumxsq += x * x;
        sumysq += y * y;
    }
    float numerator = total_n * sumxy - sumx * sumy;
    float denominator = sqrt((total_n * sumxsq - sumx * sumx) * (total_n * sumysq - sumy * sumy));

    float CR = (numerator / denominator);

    cout<<CR<<endl;

    return CR;
}
*/

void correlate_plot(){

/*
    TFile *Mx2_1 = new TFile("./../../root_file/test/tmpMx2_1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/test/tmpMx2_50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/test/tmpMx2_150.root");
    
    TFile *DYpT50 = new TFile("./../../root_file/test/test_pt50.root");
    



    //Linear_Correlation(DYpT50,BDT_variables,I_nJets,f_alphamin,f_Met);


    int I_nJets;
    double f_alphamin;
    float f_Met;

    TTree *T_event;
    Mx2_150->GetObject("T_event",T_event);
    T_event->SetBranchAddress("I_nJets",&I_nJets);
    T_event->SetBranchAddress("f_alphamin",&f_alphamin);
    T_event->SetBranchAddress("f_Met",&f_Met);
    
    
    Int_t  total_n = (Int_t )T_event->GetEntries();

     double sumx = 0.;
     double sumy = 0.;
     double sumxy = 0.;
     double sumxsq = 0.;
     double sumysq = 0.;

    for (Int_t  k = 0; k < total_n; k++)
    {

        T_event->GetEntry(k);
        sumx += f_alphamin;
        sumy += f_Met;
        sumxy += f_alphamin * f_Met;
        sumxsq += f_alphamin * f_alphamin;
        sumysq += f_Met * f_Met;

    }

        double numerator = total_n * sumxy - sumx * sumy;
        double denominator = sqrt((total_n * sumxsq - sumx * sumx) * (total_n * sumysq - sumy * sumy));

        cout << "Linear Correlation for all = " << abs(numerator / denominator) << endl;
        //cout << "root Correlation for de and mbc = " << correlation(I_nJets, f_alphamin) << endl;
*/

    TFile *DYpT50 = new TFile("./../../root_file/test/test_pt50.root");
    TFile *DYpT100 = new TFile("./../../root_file/test/test_pt100.root");
    TFile *DYpT250 = new TFile("./../../root_file/test/test_pt250.root");
    TFile *DYpT400 = new TFile("./../../root_file/test/test_pt400.root");
    TFile *DYpT650 = new TFile("./../../root_file/test/test_pt650.root");

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


    //TH2F *h_A = new ;

/*
    TH2D *h_pt50 = new TH2D("h_pt50","",80,0.,1.,80,0.,1000.);
    h_pt50->Sumw2();
    h_pt50->GetXaxis()->SetTitle("alphamin");
    h_pt50->GetYaxis()->SetTitle("Met");
    TH2D *h_pt100 = new TH2D("h_pt100","",80,0.,1.,80,0.,1000.);
    h_pt100->Sumw2();
    h_pt100->GetXaxis()->SetTitle("Met");
    h_pt100->GetYaxis()->SetTitle("alphamin");
    TH2D *h_pt250 = new TH2D("h_pt250","",80,0.,1.,80,0.,1000.);
    h_pt250->Sumw2();
    h_pt250->GetXaxis()->SetTitle("Met");
    h_pt250->GetYaxis()->SetTitle("alphamin");
    TH2D *h_pt400 = new TH2D("h_pt400","",80,0.,1.,80,0.,1000.);
    h_pt400->Sumw2();
    h_pt400->GetXaxis()->SetTitle("Met");
    h_pt400->GetYaxis()->SetTitle("alphamin");
    TH2D *h_pt650 = new TH2D("h_pt650","",80,0.,1.,80,0.,1000.);
    h_pt650->Sumw2();
    h_pt650->GetXaxis()->SetTitle("Met");
    h_pt650->GetYaxis()->SetTitle("alphamin");
*/
    TH2D *h_pt50 = new TH2D("h_pt50","",24,0.,1000.,24,0.,1.);
    h_pt50->Sumw2();
    h_pt50->GetXaxis()->SetTitle("Met");
    h_pt50->GetYaxis()->SetTitle("alphamin");
    TH2D *h_pt100 = new TH2D("h_pt100","",24,0.,1000.,24,0.,1.);
    h_pt100->Sumw2();
    h_pt100->GetXaxis()->SetTitle("Met");
    h_pt100->GetYaxis()->SetTitle("alphamin");
    TH2D *h_pt250 = new TH2D("h_pt250","",24,0.,1000.,24,0.,1.);
    h_pt250->Sumw2();
    h_pt250->GetXaxis()->SetTitle("Met");
    h_pt250->GetYaxis()->SetTitle("alphamin");
    TH2D *h_pt400 = new TH2D("h_pt400","",24,0.,1000.,24,0.,1.);
    h_pt400->Sumw2();
    h_pt400->GetXaxis()->SetTitle("Met");
    h_pt400->GetYaxis()->SetTitle("alphamin");
    TH2D *h_pt650 = new TH2D("h_pt650","",24,0.,1000.,24,0.,1.);
    h_pt650->Sumw2();
    h_pt650->GetXaxis()->SetTitle("Met");
    h_pt650->GetYaxis()->SetTitle("alphamin");

    double f_pt50_alphamin, f_pt100_alphamin, f_pt250_alphamin,f_pt400_alphamin,f_pt650_alphamin;
    float f_pt50_Met, f_pt100_Met, f_pt250_Met, f_pt400_Met, f_pt650_Met;
    int I_pt50_weight, I_pt100_weight, I_pt250_weight, I_pt400_weight, I_pt650_weight;

    TTree *T_event;
    DYpT50->GetObject("T_event",T_event);

    T_event->SetBranchAddress("f_alphamin",&f_pt50_alphamin);
    T_event->SetBranchAddress("f_Met",&f_pt50_Met);
    T_event->SetBranchAddress("I_weight",&I_pt50_weight);

    TH2F *h2 = new TH2F("h2","",80,0.,800.,80,0.,1.);
    //TH2F *h2 = new TH2F("h2","",80,0.,1.,80,0.,800.);

    //T_event->Draw("f_alphamin:f_Met");

    for(int evt=0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        //h_pt50->Fill(f_pt50_alphamin,f_pt50_Met,I_pt50_weight);
        h_pt50->Fill(f_pt50_Met,f_pt50_alphamin,I_pt50_weight);
    }
    h_pt50->Scale(GlobalConstants::PT50CS / DYPT50_SW);

    TTree *T_event1;
    DYpT100->GetObject("T_event",T_event1);
    T_event1->SetBranchAddress("f_alphamin",&f_pt100_alphamin);
    T_event1->SetBranchAddress("f_Met",&f_pt100_Met);
    T_event1->SetBranchAddress("I_weight",&I_pt100_weight);
    for(int evt=0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        //h_pt100->Fill(f_pt100_alphamin,f_pt100_Met,I_pt100_weight);
        h_pt100->Fill(f_pt100_Met,f_pt100_alphamin,I_pt100_weight);
    }
    h_pt100->Scale(GlobalConstants::PT100CS / DYPT100_SW);

    TTree *T_event2;
    DYpT250->GetObject("T_event",T_event2);
    T_event2->SetBranchAddress("f_alphamin",&f_pt250_alphamin);
    T_event2->SetBranchAddress("f_Met",&f_pt250_Met);
    T_event2->SetBranchAddress("I_weight",&I_pt250_weight);

    for(int evt=0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        //h_pt250->Fill(f_pt250_alphamin,f_pt250_Met,I_pt250_weight);
        h_pt250->Fill(f_pt250_Met,f_pt250_alphamin,I_pt250_weight);
    }
    h_pt250->Scale(GlobalConstants::PT250CS / DYPT250_SW);

    TTree *T_event3;
    DYpT400->GetObject("T_event",T_event3);
    T_event3->SetBranchAddress("f_alphamin",&f_pt400_alphamin);
    T_event3->SetBranchAddress("f_Met",&f_pt400_Met);
    T_event3->SetBranchAddress("I_weight",&I_pt400_weight);
    for(int evt=0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        //h_pt400->Fill(f_pt400_alphamin,f_pt400_Met,I_pt400_weight);
        h_pt400->Fill(f_pt400_Met,f_pt400_alphamin,I_pt400_weight);
    }
    h_pt400->Scale(GlobalConstants::PT400CS  / DYPT400_SW);

    TTree *T_event4;
    DYpT650->GetObject("T_event",T_event4);
    T_event4->SetBranchAddress("f_alphamin",&f_pt650_alphamin);
    T_event4->SetBranchAddress("f_Met",&f_pt650_Met);
    T_event4->SetBranchAddress("I_weight",&I_pt650_weight);
    for(int evt=0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        //h_pt650->Fill(f_pt650_alphamin,f_pt650_Met,I_pt650_weight);
        h_pt650->Fill(f_pt650_Met,f_pt650_alphamin,I_pt650_weight);
    }
    h_pt650->Scale(GlobalConstants::PT650CS / DYPT650_SW);

    h_pt50->Add(h_pt100);
    h_pt50->Add(h_pt250);
    h_pt50->Add(h_pt400);
    h_pt50->Add(h_pt650);

    h_pt50->Draw("COLZ");
}

