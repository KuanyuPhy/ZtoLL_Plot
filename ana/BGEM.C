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

//#include "TRooH1D.h"
//#include "Cross_section.h"

void BGEM(){


    TFile *Mx2_1 = new TFile("./../../root_file/test/tmpMx2_1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/test/tmpMx2_50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/test/tmpMx2_150.root");
    
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

    //TH1F *h_A,*h_Bsr,*h_Ccr,*h_Dcr;
    TH1F* h_pt50_A = new TH1F("h_pt50_A","a histogram",10,0.8,1.0);
    TH1F* h_pt100_A = new TH1F("h_pt100_A","a histogram",10,0.8,1.0);
    TH1F* h_pt250_A = new TH1F("h_pt250_A","a histogram",10,0.8,1.0);
    TH1F* h_pt400_A = new TH1F("h_pt400_A","a histogram",10,0.8,1.0);
    TH1F* h_pt650_A = new TH1F("h_pt650_A","a histogram",10,0.8,1.0);

    TH1F* h_pt50_B = new TH1F("h_pt50_B","a histogram",10,0.0,0.7);
    TH1F* h_pt100_B = new TH1F("h_pt100_B","a histogram",10,0.0,0.7);
    TH1F* h_pt250_B = new TH1F("h_pt250_B","a histogram",10,0.0,0.7);
    TH1F* h_pt400_B = new TH1F("h_pt400_B","a histogram",10,0.0,0.7);
    TH1F* h_pt650_B = new TH1F("h_pt650_B","a histogram",10,0.0,0.7);

    TH1F* h_pt50_C = new TH1F("h_pt50_C","a histogram",10,0.8,1.0);
    TH1F* h_pt100_C = new TH1F("h_pt100_C","a histogram",10,0.8,1.0);
    TH1F* h_pt250_C = new TH1F("h_pt250_C","a histogram",10,0.8,1.0);
    TH1F* h_pt400_C = new TH1F("h_pt400_C","a histogram",10,0.8,1.0);
    TH1F* h_pt650_C = new TH1F("h_pt650_C","a histogram",10,0.8,1.0);

    TH1F* h_pt50_D = new TH1F("h_pt50_D","a histogram",10,0.0,0.7);
    TH1F* h_pt100_D = new TH1F("h_pt100_D","a histogram",10,0.0,0.7);
    TH1F* h_pt250_D = new TH1F("h_pt250_D","a histogram",10,0.0,0.7);
    TH1F* h_pt400_D = new TH1F("h_pt400_D","a histogram",10,0.0,0.7);
    TH1F* h_pt650_D = new TH1F("h_pt650_D","a histogram",10,0.0,0.7);


    double f_pt50_alphamin, f_pt100_alphamin, f_pt250_alphamin,f_pt400_alphamin,f_pt650_alphamin;
    float f_pt50_Met, f_pt100_Met, f_pt250_Met, f_pt400_Met, f_pt650_Met;
    int I_pt50_weight, I_pt100_weight, I_pt250_weight, I_pt400_weight, I_pt650_weight;

    TTree *T_event;
    DYpT50->GetObject("T_event",T_event);

    T_event->SetBranchAddress("f_alphamin",&f_pt50_alphamin);
    T_event->SetBranchAddress("f_Met",&f_pt50_Met);
    T_event->SetBranchAddress("I_weight",&I_pt50_weight);


    for(int evt=0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if(f_pt50_alphamin > 0.8 &&f_pt50_Met < 350)
        {
            h_pt50_A->Fill(f_pt50_alphamin,I_pt50_weight);
        }
        if(f_pt50_alphamin < 0.7 &&f_pt50_Met < 350)
        {
            h_pt50_B->Fill(f_pt50_alphamin,I_pt50_weight);
        }
        if(f_pt50_alphamin > 0.8 &&f_pt50_Met > 400)
        {
            h_pt50_C->Fill(f_pt50_alphamin,I_pt50_weight);
        }
        if(f_pt50_alphamin < 0.7 &&f_pt50_Met > 400)
        {
            h_pt50_D->Fill(f_pt50_alphamin,I_pt50_weight);
        }
    }
    h_pt50_A->Scale(344.3 / DYPT50_SW);
    h_pt50_B->Scale(344.3 / DYPT50_SW);
    h_pt50_C->Scale(344.3 / DYPT50_SW);
    h_pt50_D->Scale(344.3 / DYPT50_SW);

    TTree *T_event1;
    DYpT100->GetObject("T_event",T_event1);
    T_event1->SetBranchAddress("f_alphamin",&f_pt100_alphamin);
    T_event1->SetBranchAddress("f_Met",&f_pt100_Met);
    T_event1->SetBranchAddress("I_weight",&I_pt100_weight);
    for(int evt=0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if(f_pt100_alphamin > 0.8 &&f_pt100_Met < 350)
        {
            h_pt100_A->Fill(f_pt100_alphamin,I_pt100_weight);
        }
        if(f_pt100_alphamin < 0.7 &&f_pt100_Met < 350)
        {
            h_pt100_B->Fill(f_pt100_alphamin,I_pt100_weight);
        }
        if(f_pt100_alphamin > 0.8 &&f_pt100_Met > 400)
        {
            h_pt100_C->Fill(f_pt100_alphamin,I_pt100_weight);
        }
        if(f_pt100_alphamin < 0.7 &&f_pt100_Met > 400)
        {
            h_pt100_D->Fill(f_pt100_alphamin,I_pt100_weight);
        }
    }
    h_pt100_A->Scale(80.64 / DYPT100_SW);
    h_pt100_B->Scale(80.64 / DYPT100_SW);
    h_pt100_C->Scale(80.64 / DYPT100_SW);
    h_pt100_D->Scale(80.64 / DYPT100_SW);


    TTree *T_event2;
    DYpT250->GetObject("T_event",T_event2);
    T_event2->SetBranchAddress("f_alphamin",&f_pt250_alphamin);
    T_event2->SetBranchAddress("f_Met",&f_pt250_Met);
    T_event2->SetBranchAddress("I_weight",&I_pt250_weight);
    for(int evt=0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if(f_pt250_alphamin > 0.8 &&f_pt250_Met < 350)
        {
            h_pt250_A->Fill(f_pt250_alphamin,I_pt250_weight);
        }
        if(f_pt250_alphamin < 0.7 &&f_pt250_Met < 350)
        {
            h_pt250_B->Fill(f_pt250_alphamin,I_pt250_weight);
        }
        if(f_pt250_alphamin > 0.8 &&f_pt250_Met > 400)
        {
            h_pt250_C->Fill(f_pt250_alphamin,I_pt250_weight);
        }
        if(f_pt250_alphamin < 0.7 &&f_pt250_Met > 400)
        {
            h_pt250_D->Fill(f_pt250_alphamin,I_pt250_weight);
        }
    }
    h_pt250_A->Scale(2.955 / DYPT250_SW);
    h_pt250_B->Scale(2.955 / DYPT250_SW);
    h_pt250_C->Scale(2.955 / DYPT250_SW);
    h_pt250_D->Scale(2.955 / DYPT250_SW);

    TTree *T_event3;
    DYpT400->GetObject("T_event",T_event3);
    T_event3->SetBranchAddress("f_alphamin",&f_pt400_alphamin);
    T_event3->SetBranchAddress("f_Met",&f_pt400_Met);
    T_event3->SetBranchAddress("I_weight",&I_pt400_weight);
    for(int evt=0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if(f_pt400_alphamin > 0.8 &&f_pt400_Met < 350)
        {
            h_pt400_A->Fill(f_pt400_alphamin,I_pt400_weight);
        }
        if(f_pt400_alphamin < 0.7 &&f_pt400_Met < 350)
        {
            h_pt400_B->Fill(f_pt400_alphamin,I_pt400_weight);
        }
        if(f_pt400_alphamin > 0.8 &&f_pt400_Met > 400)
        {
            h_pt400_C->Fill(f_pt400_alphamin,I_pt400_weight);
        }
        if(f_pt400_alphamin < 0.7 &&f_pt400_Met > 400)
        {
            h_pt400_D->Fill(f_pt400_alphamin,I_pt400_weight);
        }
    }

    h_pt400_A->Scale(0.3807  / DYPT400_SW);
    h_pt400_B->Scale(0.3807  / DYPT400_SW);
    h_pt400_C->Scale(0.3807  / DYPT400_SW);
    h_pt400_D->Scale(0.3807  / DYPT400_SW);

    TTree *T_event4;
    DYpT650->GetObject("T_event",T_event4);
    T_event4->SetBranchAddress("f_alphamin",&f_pt650_alphamin);
    T_event4->SetBranchAddress("f_Met",&f_pt650_Met);
    T_event4->SetBranchAddress("I_weight",&I_pt650_weight);
    for(int evt=0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if(f_pt650_alphamin > 0.8 &&f_pt650_Met < 350)
        {
            h_pt650_A->Fill(f_pt650_alphamin,I_pt650_weight);
        }
        if(f_pt650_alphamin < 0.7 &&f_pt650_Met < 350)
        {
            h_pt650_B->Fill(f_pt650_alphamin,I_pt650_weight);
        }
        if(f_pt650_alphamin > 0.8 &&f_pt650_Met > 400)
        {
            h_pt650_C->Fill(f_pt650_alphamin,I_pt650_weight);
        }
        if(f_pt650_alphamin < 0.7 &&f_pt650_Met > 400)
        {
            h_pt650_D->Fill(f_pt650_alphamin,I_pt650_weight);
        }
    }
    h_pt650_A->Scale(0.03711 / DYPT650_SW);
    h_pt650_B->Scale(0.03711 / DYPT650_SW);
    h_pt650_C->Scale(0.03711 / DYPT650_SW);
    h_pt650_D->Scale(0.03711 / DYPT650_SW);

    h_pt50_A->Add(h_pt100_A);
    h_pt50_A->Add(h_pt250_A);
    h_pt50_A->Add(h_pt400_A);
    h_pt50_A->Add(h_pt650_A);

    h_pt50_B->Add(h_pt100_B);
    h_pt50_B->Add(h_pt250_B);
    h_pt50_B->Add(h_pt400_B);
    h_pt50_B->Add(h_pt650_B);

    h_pt50_C->Add(h_pt100_C);
    h_pt50_C->Add(h_pt250_C);
    h_pt50_C->Add(h_pt400_C);
    h_pt50_C->Add(h_pt650_C);

    h_pt50_D->Add(h_pt100_D);
    h_pt50_D->Add(h_pt250_D);
    h_pt50_D->Add(h_pt400_D);
    h_pt50_D->Add(h_pt650_D);

    //h_pt50_A->Draw();

    h_pt50_A = (TH1F*)gDirectory->Get("h_pt50_A");
    h_pt50_B = (TH1F*)gDirectory->Get("h_pt50_B");
    h_pt50_C = (TH1F*)gDirectory->Get("h_pt50_C");
    h_pt50_D = (TH1F*)gDirectory->Get("h_pt50_D");

    cout<<"Total A = "<<h_pt50_A->GetEntries()<<endl;
    cout<<"Total B = "<<h_pt50_B->GetEntries()<<endl;
    cout<<"Total C = "<<h_pt50_C->GetEntries()<<endl;
    cout<<"Total D = "<<h_pt50_D->GetEntries()<<endl;

    //h_pt50_D->Draw();
    //h_pt50_B->SaveAs("Pt50_B.jpg");
    //h_pt50_C->SaveAs("Pt50_C.jpg");
    //h_pt50_D->SaveAs("Pt50_D.jpg");
    //BDT_variables->SetBranchAddress("v_weight",&v_weight);
/*
    T_event->Draw("f_alphamin>>h_A(10,0.8,1.0)","f_alphamin > 0.8 &&f_Met < 350");
    T_event->Draw("f_alphamin>>h_Bsr(10,0.0,0.7)","f_alphamin < 0.7 &&f_Met < 350");
    T_event->Draw("f_alphamin>>h_Ccr(10,0.8,1.0)","f_alphamin > 0.8 &&f_Met > 400");
    T_event->Draw("f_alphamin>>h_Dcr(10,0.0,0.7)","f_alphamin < 0.7 &&f_Met > 400");
    //h_sr->Draw();

    h_A = (TH1F*)gDirectory->Get("h_A");
    h_Bsr = (TH1F*)gDirectory->Get("h_Bsr");
    h_Ccr = (TH1F*)gDirectory->Get("h_Ccr");
    h_Dcr = (TH1F*)gDirectory->Get("h_Dcr");

    cout<<"Total A = "<<h_A->GetEntries()<<endl;
    cout<<"Total B = "<<h_Bsr->GetEntries()<<endl;
    cout<<"Total C = "<<h_Ccr->GetEntries()<<endl;
    cout<<"Total D = "<<h_Dcr->GetEntries()<<endl;
*/
/*
    //TF1 *f1 = new TF1("f1","[0]+[1]*x+[2]*gaus(2)");
    TF1 *fpol = new TF1("f1","pol3(0)",h_A->GetXaxis()->GetXmin(),h_A->GetXaxis()->GetXmax());
    //f1->SetParameters(2.,-1.0,2.5,0.5,0.05); 

    //Roofit ABCD Method
    //h_A->Draw();
    h_A->Fit(fpol,"IMF");
    h_A->Draw();
*/
/*
    double cLeft =0; //left edge of region C
    double aLeft =0; //left edge of region A
    double aRight =800; //right edge of region A
    double cTop=1.0; //top edge of region C
    double cBottom=0.8; //bottom edge of region C
    double dBottom=0; //bottom edge of region D

    const char* regionLabels[4] = {"C","A","D","B"};
    // odd ordering is so that when we draw regions
    //we will get :
    // C | A
    // D | B

    RooRealVar x("f_alphamin","f_alphamin",cLeft,aRight);

    TH1D* b[4]; //will point to the four TRooH1D we will create

    for(int i=0; i<4; i++)
    {
        b[i] = new TH1D(Form("b_%s",regionLabels[i]),Form("Region %s bkg", regionLabels[i]),
        nBins,cLeft,aRight);

        b[i]->SetFillColor(kCyan);
        b[i]->setFloor(true);

    }

    RooCategory mcinfo("region", "region");
    for(int i =0; i<4; i++)
    {
        mcinfo.defineType(regionLabels[i]);
    }
*/
/*
    TChain *chain = new TChain("T_event");
    chain->Add("./../../root_file/test/test1.root");
    using namespace RooFit;
    RooRealVar f_alphamin("f_alphamin", "f_alphamin", 0., 1., "");
    RooRealVar f_Met("f_Met", "f_Met", 0., 800., "GeV");
    //RooRealVar masspsi("masspsi","masspsi",3.0,3.5,"GeV");
    RooCategory mcinfo("region", "region");
    RooArgSet *varset = new RooArgSet(f_alphamin, f_Met);
    RooDataSet data("data", "data", chain, *varset);
    data.Print();
    f_alphamin.setRange("alphamin_cut_range",0.,0.7);
    f_Met.setRange("Met_cut_range", 0., 350);

    //---------
    // alphamin
    //---------
    RooRealVar a0("a0", "a1",1000, -100., 100.);
    RooRealVar a1("a1", "a1",1000, -100., 100.);
    RooPolynomial  alphamin_pdf("alphamin_pdf", "alphamin pdf",f_alphamin, RooArgList(a0,a1));

    RooFitResult *alphamin_result = new RooFitResult("alphamin_result", "alphamin_result");
    alphamin_result = alphamin_pdf.fitTo(data, Timer(true), Save(true));
    TCanvas *canvas = new TCanvas("canvas", "c1");

    canvas->Clear();
    RooPlot *plot_alphamin = f_alphamin.frame(Bins(10), Name("plot_alphamin"), Range("alphamin_cut_range","Met_cut_range"), Title("plot_deltae"));
    data.plotOn(plot_alphamin, Name("data_hist"), CutRange("alphamin_cut_range"), MarkerColor(kBlack));
    alphamin_pdf.plotOn(plot_alphamin, Name("alphamin_fit_result"), ProjectionRange("alphamin_cut_range"), Components("alphamin_pdf"), LineColor(kBlue), LineStyle(kSolid));
    alphamin_pdf.paramOn(plot_alphamin, Layout(0.6));
    //cout<<plot_alphamin->GetRntries()<<endl;
    plot_alphamin->Draw("");
    */

}