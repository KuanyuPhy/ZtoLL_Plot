#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
using namespace std;
void quick_draw()
{
    float HT70CS = 175.3;
    float HT100CS = 147.4;
    float HT200CS = 41.04;
    float HT400CS = 5.674;
    float HT600CS = 1.358;
    float HT800CS = 0.6229;
    float HT1200CS = 0.1512;
    float HT2500CS = 0.003659;
    float PT50CS = 344.3;
    float PT100CS = 80.64;
    float PT250CS = 2.955;
    float PT400CS = 0.3807;
    float PT650CS = 0.03711;
    auto c1 = new TCanvas("c", "BPRE");
    TFile *Mx2_1 = new TFile("./../../root_file/test/test1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/test/test50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/test/test150.root");

/*
    TFile *DYHT70 = new TFile("./../../root_file/tmpHT70_100.root");
    TFile *DYHT100 = new TFile("./../../root_file/tmpHT100_200.root");
    TFile *DYHT200 = new TFile("./../../root_file/tmpHT200_400.root");
    TFile *DYHT400 = new TFile("./../../root_file/tmpHT400_600.root");
    TFile *DYHT600 = new TFile("./../../root_file/tmpHT600_800.root");
    TFile *DYHT800 = new TFile("./../../root_file/tmpHT800_1200.root");
    TFile *DYHT1200 = new TFile("./../../root_file/tmpHT1200_2500.root");
    TFile *DYHT2500 = new TFile("./../../root_file/tmpHT2500_Inf.root");
*/
    TFile *DYpT50 = new TFile("./../../root_file/test/test_pt50.root");
    TFile *DYpT100 = new TFile("./../../root_file/test/test_pt100.root");
    TFile *DYpT250 = new TFile("./../../root_file/test/test_pt250.root");
    TFile *DYpT400 = new TFile("./../../root_file/test/test_pt400.root");
    TFile *DYpT650 = new TFile("./../../root_file/test/test_pt650.root");

    TH1D *Mx2_1_nT = ((TH1D *)Mx2_1->Get("Chi3Dlog"));
    TH1D *Mx2_50_nT = ((TH1D *)Mx2_50->Get("Chi3Dlog"));
    TH1D *Mx2_150_nT = ((TH1D *)Mx2_150->Get("Chi3Dlog"));

    /*
    TH1D *HT_CS = ((TH1D *)DYHT70->Get("h_HTCS"));
    TH1D *HT70_nT = ((TH1D *)DYHT70->Get("Chi3Dlog"));
    TH1D *HT70_evt = ((TH1D *)DYHT70->Get("h_event"));

    TH1D *HT100_nT = ((TH1D *)DYHT100->Get("Chi3Dlog"));
    TH1D *HT100_evt = ((TH1D *)DYHT100->Get("h_event"));

    TH1D *HT200_nT = ((TH1D *)DYHT200->Get("Chi3Dlog"));
    TH1D *HT200_evt = ((TH1D *)DYHT200->Get("h_event"));
    TH1D *HT400_nT = ((TH1D *)DYHT400->Get("Chi3Dlog"));
    TH1D *HT400_evt = ((TH1D *)DYHT400->Get("h_event"));
    TH1D *HT600_nT = ((TH1D *)DYHT600->Get("Chi3Dlog"));
    TH1D *HT600_evt = ((TH1D *)DYHT600->Get("h_event"));
    TH1D *HT800_nT = ((TH1D *)DYHT800->Get("Chi3Dlog"));
    TH1D *HT800_evt = ((TH1D *)DYHT800->Get("h_event"));
    TH1D *HT1200_nT = ((TH1D *)DYHT1200->Get("Chi3Dlog"));
    TH1D *HT1200_evt = ((TH1D *)DYHT1200->Get("h_event"));
    TH1D *HT2500_nT = ((TH1D *)DYHT2500->Get("Chi3Dlog"));
    TH1D *HT2500_evt = ((TH1D *)DYHT2500->Get("h_event"));
    */
    //TH1D *h_PTCS = ((TH1D *)DYpT50->Get("h_PTCS"));
    
    TH1D *DYPT50_nT = ((TH1D *)DYpT50->Get("Chi3Dlog"));
    TH1D *DYPT50_sumW = ((TH1D *)DYpT50->Get("h_SumWeight"));
    TH1D *DYPT100_nT = ((TH1D *)DYpT100->Get("Chi3Dlog"));
    TH1D *DYPT100_sumW = ((TH1D *)DYpT100->Get("h_SumWeight"));
    TH1D *DYPT250_nT = ((TH1D *)DYpT250->Get("Chi3Dlog"));
    TH1D *DYPT250_sumW = ((TH1D *)DYpT250->Get("h_SumWeight"));
    TH1D *DYPT400_nT = ((TH1D *)DYpT400->Get("Chi3Dlog"));
    TH1D *DYPT400_sumW = ((TH1D *)DYpT400->Get("h_SumWeight"));
    TH1D *DYPT650_nT = ((TH1D *)DYpT650->Get("Chi3Dlog"));
    TH1D *DYPT650_sumW = ((TH1D *)DYpT650->Get("h_SumWeight"));
    
    
/*
    //double DYHT70_CS = HT_CS->GetBinContent(1);
    double HT70_event = HT70_evt->GetEntries();
    HT70_nT->Scale(HT70CS / HT70_event);
    //double DYHT100_CS = HT_CS->GetBinContent(2);
    double HT100_event = HT100_evt->GetEntries();
    HT100_nT->Scale(HT100CS / HT100_event);
    //double DYHT200_CS = HT_CS->GetBinContent(3);
    double HT200_event = HT200_evt->GetEntries();
    HT200_nT->Scale(HT200CS / HT200_event);
    //double DYHT400_CS = HT_CS->GetBinContent(4);
    double HT400_event = HT400_evt->GetEntries();
    HT400_nT->Scale(HT400CS / HT400_event);
    //double DYHT600_CS = HT_CS->GetBinContent(5);
    double HT600_event = HT600_evt->GetEntries();
    HT600_nT->Scale(HT600CS / HT600_event);
    //double DYHT800_CS = HT_CS->GetBinContent(6);
    double HT800_event = HT800_evt->GetEntries();
    HT800_nT->Scale(HT800CS / HT800_event);
    //double DYHT1200_CS = HT_CS->GetBinContent(7);
    double HT1200_event = HT1200_evt->GetEntries();
    HT1200_nT->Scale(HT1200CS / HT1200_event);
    //double DYHT2500_CS = HT_CS->GetBinContent(8);
    double HT2500_event = HT2500_evt->GetEntries();
    HT2500_nT->Scale(HT2500CS / HT2500_event);

    HT70_nT->Add(HT100_nT);
    HT70_nT->Add(HT200_nT);
    HT70_nT->Add(HT400_nT);
    HT70_nT->Add(HT600_nT);
    HT70_nT->Add(HT800_nT);
    HT70_nT->Add(HT1200_nT);
    HT70_nT->Add(HT2500_nT);
*/
    //HT70_nT->GetXaxis()->SetRangeUser(0, 50);
    //Chi3Dlog->GetXaxis()->SetRangeUser(0, 50)
    //double DYPT50_CS = h_PTCS->GetBinContent(1);

    double DYPT50_SW = DYPT50_sumW->GetBinContent(1);
    DYPT50_nT->Scale(PT50CS / DYPT50_SW);
    //double DYPT100_CS = h_PTCS->GetBinContent(2);
    double DYPT100_SW = DYPT100_sumW->GetBinContent(1);
    DYPT100_nT->Scale(PT100CS / DYPT100_SW);
    //double DYPT250_CS = h_PTCS->GetBinContent(3);
    double DYPT250_SW = DYPT250_sumW->GetBinContent(1);
    DYPT250_nT->Scale(PT250CS / DYPT250_SW);
    //double DYPT400_CS = h_PTCS->GetBinContent(4);
    double DYPT400_SW = DYPT400_sumW->GetBinContent(1);
    DYPT400_nT->Scale(PT400CS / DYPT400_SW);
    //double DYPT650_CS = h_PTCS->GetBinContent(5);
    double DYPT650_SW = DYPT650_sumW->GetBinContent(1);
    DYPT650_nT->Scale(PT650CS / DYPT650_SW);

    DYPT50_nT->Add(DYPT100_nT);
    DYPT50_nT->Add(DYPT250_nT);
    DYPT50_nT->Add(DYPT400_nT);
    DYPT50_nT->Add(DYPT650_nT);

    //int nBin = Mx2_50_nT->GetNbinsX();

    Mx2_150_nT->SetLineStyle(7);
    Mx2_1_nT->SetLineStyle(7);
    Mx2_50_nT->SetLineStyle(7);

    DYPT50_nT->SetLineStyle(7);

    DYPT50_nT->SetStats(0);
    Mx2_1_nT->SetLineWidth(2);
    Mx2_1_nT->SetLineColor(kRed);
    Mx2_50_nT->SetLineWidth(2);
    Mx2_50_nT->SetLineColor(kBlue);
    Mx2_150_nT->SetLineWidth(2);
    Mx2_150_nT->SetLineColor(kBlack);

    /*
    HT70_nT->SetLineWidth(2);
    HT70_nT->SetLineColor(kGreen);
*/
    DYPT50_nT->SetLineWidth(3);
    DYPT50_nT->SetLineColor(kViolet);

    Mx2_1_nT->SetTitle("Chi3Dlog");
    //Mx2_1_nT->SetXTitle("NTracks per Jet");
    //Mx2_1_nT->SetXTitle("Numbers of Thin Jet");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(1,"0");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(2,"1");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(3,"2");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(4,"3");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(5,"4");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(6,"5");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(7,"6");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(8,"7");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(9,"8");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(10,"9");    
    //Mx2_1_nT->GetXaxis()->SetRangeUser(0, 5);
    //Mx2_1_nT->GetXaxis()->SetRangeUser(-2, 5);
    //
    DYPT50_nT->SetXTitle("log_{10}(IP^{3D}_{sig})");
    //Mx2_150_nT->GetXaxis()->SetRangeUser(-3, 5);
   //DYPT50_nT->GetXaxis()->SetRangeUser(-1.5, 5);

    DYPT50_nT->Draw("text90");
    int nBin = Mx2_50_nT->GetNbinsX();
    cout << nBin << endl;
    double pp = DYPT50_nT->GetBinContent(75);
    cout<<pp<<endl;
    //Mx2_150_nT->DrawNormalized("hist&&same");
    //Mx2_50_nT->DrawNormalized("hist&&same");
    //Mx2_1_nT->DrawNormalized("hist&&same");
    //HT70_nT->Draw("hist&&same");
    
    //DYPT50_nT->DrawNormalized("hist&&same");

    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    //l2->AddEntry(Mx2_1_nT, "ctau=1mm m_{x^{2}}=1", "l");
    //l2->AddEntry(Mx2_150_nT, "ctau=1mm m_{x^{2}}=150", "l");
    l2->AddEntry(Mx2_50_nT, "ctau=10mm m_{x^{2}}=50", "l");

    //l2->AddEntry(HT70_nT, "DYJets_HTBin", "f");
    l2->AddEntry(DYPT50_nT, "DYJets_pTBin", "l");

    l2->Draw();
    //c1->SetLogy();
    //c1->SaveAs("Chi3Dlog.png");
}