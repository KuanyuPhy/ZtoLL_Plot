#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./lib/Cross_section.C"
#include "setNCUStyle.C"
using namespace std;
void quick_data_draw()
{
    setNCUStyle(true);
    auto c1 = new TCanvas("c", "BPRE");
    
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

    TFile *data_DouEG = new TFile("./../../root_file/data/data_DouEG.root");
    TFile *data_DouMu = new TFile("./../../root_file/data/data_DouMu.root");
    TFile *data_SigE = new TFile("./../../root_file/data/data_SigE.root");
    TFile *data_SigE_v2 = new TFile("./../../ZtoLL_Plot/ana/new.root");
    TFile *data_SigMu = new TFile("./../../root_file/data/data_SigMu.root");



    TH1D *Mx2_1_nT = ((TH1D *)Mx2_1->Get("h_aphmin"));
    TH1D *Mx2_50_nT = ((TH1D *)Mx2_50->Get("h_aphmin"));
    TH1D *Mx2_150_nT = ((TH1D *)Mx2_150->Get("h_aphmin"));

    TH1D *DYPT50_nT = ((TH1D *)DYpT50->Get("h_aphmin"));
    TH1D *DYPT50_sumW = ((TH1D *)DYpT50->Get("h_SumWeight"));
    TH1D *DYPT100_nT = ((TH1D *)DYpT100->Get("h_aphmin"));
    TH1D *DYPT100_sumW = ((TH1D *)DYpT100->Get("h_SumWeight"));
    TH1D *DYPT250_nT = ((TH1D *)DYpT250->Get("h_aphmin"));
    TH1D *DYPT250_sumW = ((TH1D *)DYpT250->Get("h_SumWeight"));
    TH1D *DYPT400_nT = ((TH1D *)DYpT400->Get("h_aphmin"));
    TH1D *DYPT400_sumW = ((TH1D *)DYpT400->Get("h_SumWeight"));
    TH1D *DYPT650_nT = ((TH1D *)DYpT650->Get("h_aphmin"));
    TH1D *DYPT650_sumW = ((TH1D *)DYpT650->Get("h_SumWeight"));
    
    TH1D *DYHT70_nT = ((TH1D *)DYHT70->Get("h_aphmin"));
    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("h_event"));
    TH1D *DYHT100_nT = ((TH1D *)DYHT100->Get("h_aphmin"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("h_event"));
    TH1D *DYHT200_nT = ((TH1D *)DYHT200->Get("h_aphmin"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("h_event"));
    TH1D *DYHT400_nT = ((TH1D *)DYHT400->Get("h_aphmin"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("h_event"));
    TH1D *DYHT600_nT = ((TH1D *)DYHT600->Get("h_aphmin"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("h_event"));
    TH1D *DYHT800_nT = ((TH1D *)DYHT800->Get("h_aphmin"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("h_event"));
    TH1D *DYHT1200_nT = ((TH1D *)DYHT1200->Get("h_aphmin"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("h_event"));
    TH1D *DYHT2500_nT = ((TH1D *)DYHT2500->Get("h_aphmin"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("h_event"));   

    TH1D *data_DouEG_nT = ((TH1D *)data_DouEG->Get("h_aphmin"));
    TH1D *data_DouMu_nT = ((TH1D *)data_DouMu->Get("h_aphmin"));
    TH1D *data_SigE_nT = ((TH1D *)data_SigE->Get("h_aphmin"));
    TH1D *data_SigMu_nT = ((TH1D *)data_SigMu->Get("h_aphmin"));

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

    //DYPT50_nT->Scale(GlobalConstants::PT50CS / DYPT50_SW);   
    //DYPT100_nT->Scale(GlobalConstants::PT100CS / DYPT100_SW);
    //DYPT250_nT->Scale(GlobalConstants::PT250CS / DYPT250_SW);
    //DYPT400_nT->Scale(GlobalConstants::PT400CS / DYPT400_SW);
    //DYPT650_nT->Scale(GlobalConstants::PT650CS / DYPT650_SW);
    cout<<DYHT70_totevt<<endl;

    TH1F *h_aphmin_Se = new TH1F("h_aphmin_Se", "", 24, 0, 1.2);
    h_aphmin_Se->SetXTitle("aphmin");
    h_aphmin_Se->SetYTitle("Number of Events");
    h_aphmin_Se->Sumw2();

    TH1F *hmet_Se = new TH1F("hmet_Se", "", 20, 0, 800);
    hmet_Se->GetYaxis()->SetTitle("Number of Events");
    hmet_Se->SetXTitle("#slash{E}_{T}");
    hmet_Se->Sumw2();


    TTree *SigEe_tree;
    float_t SigEe_Met;
    Double_t SigEe_alphamin;

    data_SigE_v2->GetObject("h1", SigEe_tree);
    SigEe_tree->SetBranchAddress("new_Met", &SigEe_Met);
    SigEe_tree->SetBranchAddress("new_alphamin", &SigEe_alphamin);

    Int_t total_n = (Int_t)SigEe_tree->GetEntries();
    for (Int_t k = 0; k < total_n; k++)
    {
        SigEe_tree->GetEntry(k);
        h_aphmin_Se->Fill(SigEe_alphamin);
    }
    h_aphmin_Se->Draw("hist");
    //h_aphmin_Se->GetYaxis()->SetTitleSize(10);

    Mx2_1_nT->Scale(5.785);
    Mx2_50_nT->Scale(5.785);
    Mx2_150_nT->Scale(5.785);

    DYHT70_nT->Scale(35.9*(GlobalConstants::HT70CS/DYHT70_totevt));
    DYHT100_nT->Scale(35.9*(GlobalConstants::HT100CS/DYHT100_totevt));    
    DYHT200_nT->Scale(35.9*(GlobalConstants::HT200CS/DYHT200_totevt)); 
    DYHT400_nT->Scale(35.9*(GlobalConstants::HT400CS/DYHT400_totevt));
    DYHT600_nT->Scale(35.9*(GlobalConstants::HT600CS/DYHT600_totevt));
    DYHT800_nT->Scale(35.9*(GlobalConstants::HT800CS/DYHT800_totevt));
    DYHT1200_nT->Scale(35.9*(GlobalConstants::HT1200CS/DYHT1200_totevt));
    DYHT2500_nT->Scale(35.9*(GlobalConstants::HT2500CS/DYHT2500_totevt));


    DYPT50_nT->Add(DYPT100_nT);
    DYPT50_nT->Add(DYPT250_nT);
    DYPT50_nT->Add(DYPT400_nT);
    DYPT50_nT->Add(DYPT650_nT);

    DYHT70_nT->Add(DYHT100_nT);
    DYHT70_nT->Add(DYHT200_nT);
    DYHT70_nT->Add(DYHT400_nT);
    DYHT70_nT->Add(DYHT600_nT);
    DYHT70_nT->Add(DYHT800_nT);
    DYHT70_nT->Add(DYHT1200_nT);
    DYHT70_nT->Add(DYHT2500_nT);


    Mx2_150_nT->SetLineStyle(7);
    Mx2_1_nT->SetLineStyle(7);
    Mx2_50_nT->SetLineStyle(7);
    DYPT50_nT->SetLineStyle(7);

    Mx2_1_nT->SetStats(0);
    Mx2_1_nT->SetLineWidth(2);
    Mx2_1_nT->SetLineColor(kRed);
    Mx2_50_nT->SetLineWidth(2);
    Mx2_50_nT->SetLineColor(kBlue);
    Mx2_150_nT->SetLineWidth(2);
    Mx2_150_nT->SetLineColor(kBlack);


    DYHT70_nT->SetLineWidth(2);
    DYHT70_nT->SetLineColor(kViolet);
    DYHT70_nT->SetFillColor(kViolet);
    DYHT70_nT->SetFillStyle(3003);

    data_DouEG_nT->SetLineWidth(2);
    data_DouEG_nT->SetLineColor(kGreen+4);
    data_DouEG_nT->SetYTitle("Number of Events");
    //data_DouEG_nT->SetFillColor(kGreen+4);

    data_DouMu_nT->SetLineWidth(2);
    data_DouMu_nT->SetLineColor(kOrange-3);
    //data_DouMu_nT->SetFillColor(kOrange-3);
    h_aphmin_Se->SetLineWidth(2);
    h_aphmin_Se->SetLineColor(kBlue-6);
    //data_SigE_nT->SetFillColor(kBlue-6);
    data_SigMu_nT->SetLineWidth(2);
    data_SigMu_nT->SetLineColor(kOrange+4);
    //data_SigMu_nT->SetFillColor(kOrange+4);
    //data_DouEG_nT->SetFillStyle(3003);

    //Mx2_1_nT->SetTitle("Rank");
    Mx2_50_nT->SetYTitle("Events");
    Mx2_50_nT->GetYaxis()->SetTitleOffset(1);
    //DYPT50_nT->SetTitle("IP^{3D}_{sig}");
    //Mx2_1_nT->SetXTitle("pt");
    //Mx2_1_nT->SetXTitle("NTracks per Jet");
    //Mx2_1_nT->SetXTitle("Numbers of Thin Jet");
    //Mx2_1_nT->SetXTitle("Numbers of electrons");
    //for(int i=0;i<10;i++)
    //{
    //    DYPT50_nT->GetXaxis()->SetBinLabel(i+1,Form("%i"));
    //}
    //DYPT50_nT->GetXaxis()->SetBinLabel(1,"0");
    //DYPT50_nT->GetXaxis()->SetBinLabel(2,"1");
    //DYPT50_nT->GetXaxis()->SetBinLabel(3,"2");
    //DYPT50_nT->GetXaxis()->SetBinLabel(4,"3");
    //DYPT50_nT->GetXaxis()->SetBinLabel(5,"4");
    //DYPT50_nT->GetXaxis()->SetBinLabel(6,"5");
    //DYPT50_nT->GetXaxis()->SetBinLabel(7,"6");
    //DYPT50_nT->GetXaxis()->SetBinLabel(8,"7");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(9,"8");
    //Mx2_1_nT->GetXaxis()->SetBinLabel(10,"9");    
    //Mx2_1_nT->GetXaxis()->SetRangeUser(0, 5);
    //Mx2_1_nT->GetXaxis()->SetRangeUser(-2, 5);
    //
    //DYHT70_nT->SetXTitle("log_{10}(IP^{3D}_{sig})");
    //Mx2_150_nT->GetXaxis()->SetRangeUser(-3, 5);
    //DYHT70_nT->GetYaxis()->SetRangeUser(0., 0.5);

    //DYPT50_nT->DrawNormalized("hist");
    int nBin = Mx2_150_nT->GetNbinsX();
    //cout << nBin << endl;
    double pp = DYPT50_nT->Integral();
    cout<<pp<<endl;
    

    //Mx2_50_nT->DrawNormalized("hist&&same");
    //Mx2_1_nT->DrawNormalized("hist&&same");
    //Mx2_150_nT->DrawNormalized("hist&&same");
    //DYHT70_nT->DrawNormalized("hist&&same");
    //data_DouEG_nT->Draw("hist&&same");
    //data_DouMu_nT->DrawNormalized("hist&&same");
    //data_SigE_nT->DrawNormalized("hist&&same");
    //data_SigMu_nT->DrawNormalized("hist&&same");
    //DYPT50_nT->DrawNormalized("hist&&same");
    //Mx2_1_nT->DrawNormalized("hist&&same");
    //DYPT50_nT->DrawNormalized("hist&&same");

    TLegend *l2 = new TLegend(0.60, 0.55, 0.90, 0.90);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    //l2->AddEntry(Mx2_1_nT, "ctau=1mm m_{x^{2}}=1", "l");
    //l2->AddEntry(Mx2_150_nT, "ctau=1mm m_{x^{2}}=150", "l");
    //l2->AddEntry(Mx2_50_nT, "ctau=10mm m_{x^{2}}=50", "l");
    //l2->AddEntry(DYHT70_nT, "DYHT", "l");
    //l2->AddEntry(data_DouEG_nT, "data_DoubleEG", "l");
    //l2->AddEntry(data_DouMu_nT, "data_DoubleMuon", "l");
    l2->AddEntry(h_aphmin_Se, "data_SingleElectron", "l");
    //l2->AddEntry(data_SigMu_nT, "data_SingleMuon", "l");
    //l2->AddEntry(DYPT50_nT, "DYJets_pTBin", "l");


    l2->Draw();
    c1->SetLogy();
    //c1->SaveAs("h_aphmin;1.png");

}