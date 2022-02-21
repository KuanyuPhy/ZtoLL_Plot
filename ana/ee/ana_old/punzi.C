#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./lib/Cross_section.h"
using namespace std;

// define punzi_eq
double punzi(double sigeff, double bg)
{
    return sigeff / (1 + TMath::Power(abs(bg), 0.5));
}

void punzi()
{

    TFile *Mx2_1 = new TFile("./../../root_file/Ztoee/Mx2_1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/Ztoee/Mx2_50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/Ztoee/Mx2_150.root");

    TFile *DYpT50 = new TFile("./../../root_file/Ztoee/test_pt50.root");
    TFile *DYpT100 = new TFile("./../../root_file/Ztoee/test_pt100.root");
    TFile *DYpT250 = new TFile("./../../root_file/Ztoee/test_pt250.root");
    TFile *DYpT400 = new TFile("./../../root_file/Ztoee/test_pt400.root");
    TFile *DYpT650 = new TFile("./../../root_file/Ztoee/test_pt650.root");

    TFile *DYincli = new TFile("./../../root_file/Ztoee/ee_DYincli.root");
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

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("h_HT_eventCout"));

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
    TH1D *Mx2_1_nT = ((TH1D *)Mx2_1->Get("h_aphmin"));
    TH1D *Mx2_50_nT = ((TH1D *)Mx2_50->Get("h_aphmin"));
    TH1D *Mx2_150_nT = ((TH1D *)Mx2_150->Get("h_aphmin"));

    TH1D *DYPT50_nT = ((TH1D *)DYpT50->Get("h_jet_n"));
    TH1D *DYPT50_sumW = ((TH1D *)DYpT50->Get("h_SumWeight"));
    TH1D *DYPT100_nT = ((TH1D *)DYpT100->Get("h_jet_n"));
    TH1D *DYPT100_sumW = ((TH1D *)DYpT100->Get("h_SumWeight"));
    TH1D *DYPT250_nT = ((TH1D *)DYpT250->Get("h_jet_n"));
    TH1D *DYPT250_sumW = ((TH1D *)DYpT250->Get("h_SumWeight"));
    TH1D *DYPT400_nT = ((TH1D *)DYpT400->Get("h_jet_n"));
    TH1D *DYPT400_sumW = ((TH1D *)DYpT400->Get("h_SumWeight"));
    TH1D *DYPT650_nT = ((TH1D *)DYpT650->Get("h_jet_n"));
    TH1D *DYPT650_sumW = ((TH1D *)DYpT650->Get("h_SumWeight"));

    int HT0_70_event = h_HT_eventCout->GetBinContent(2);
    int HT70_100_event = h_HT_eventCout->GetBinContent(3);
    int HT100_200_event = h_HT_eventCout->GetBinContent(4);
    int HT200_400_event = h_HT_eventCout->GetBinContent(5);
    int HT400_600_event = h_HT_eventCout->GetBinContent(6);
    int HT600_800_event = h_HT_eventCout->GetBinContent(7);
    int HT800_1200_event = h_HT_eventCout->GetBinContent(8);
    int HT1200_2500_event = h_HT_eventCout->GetBinContent(9);
    int HT2500_Inf_event = h_HT_eventCout->GetBinContent(10);

    int DYHT70_totevt = DYHT70_sumevt->GetEntries();
    int DYHT100_totevt = DYHT100_sumevt->GetEntries();
    int DYHT200_totevt = DYHT200_sumevt->GetEntries();
    int DYHT400_totevt = DYHT400_sumevt->GetEntries();
    int DYHT600_totevt = DYHT600_sumevt->GetEntries();
    int DYHT800_totevt = DYHT800_sumevt->GetEntries();
    int DYHT1200_totevt = DYHT1200_sumevt->GetEntries();
    int DYHT2500_totevt = DYHT2500_sumevt->GetEntries();

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

    ht0met->Scale(35.9 * ((4609.090666) / (HT0_70_event)) * 1000);
    ht70met->Scale(35.9 * ((149.9710714) / (HT70_100_event)) * 1000);
    ht100met->Scale(35.9 * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000);
    ht200met->Scale(35.9 * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000);
    ht400met->Scale(35.9 * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000);
    ht600met->Scale(35.9 * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000);
    ht800met->Scale(35.9 * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000);
    ht1200met->Scale(35.9 * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000);
    ht2500met->Scale(35.9 * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000);
    ht0met->Add(ht70met);
    ht0met->Add(ht100met);
    ht0met->Add(ht200met);
    ht0met->Add(ht400met);
    ht0met->Add(ht600met);
    ht0met->Add(ht800met);
    ht0met->Add(ht1200met);
    ht0met->Add(ht2500met);

    ht0aphmin->Scale(35.9 * ((4609.090666) / (HT0_70_event)) * 1000);
    ht70aphmin->Scale(35.9 * ((149.9710714) / (HT70_100_event)) * 1000);
    ht100aphmin->Scale(35.9 * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000);
    ht200aphmin->Scale(35.9 * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000);
    ht400aphmin->Scale(35.9 * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000);
    ht600aphmin->Scale(35.9 * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000);
    ht800aphmin->Scale(35.9 * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000);
    ht1200aphmin->Scale(35.9 * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000);
    ht2500aphmin->Scale(35.9 * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000);
    ht0aphmin->Add(ht70aphmin);
    ht0aphmin->Add(ht100aphmin);
    ht0aphmin->Add(ht200aphmin);
    ht0aphmin->Add(ht400aphmin);
    ht0aphmin->Add(ht600aphmin);
    ht0aphmin->Add(ht800aphmin);
    ht0aphmin->Add(ht1200aphmin);
    ht0aphmin->Add(ht2500aphmin);

    TH1F *punzi_met = new TH1F("punzi_met", "", 24, 0, 1.2);
    punzi_met->Sumw2();
    // DYHT70_nT->Draw();
    //============
    //   Punzi
    //============
    // Mx2_1_nT->GetXaxis()->SetRangeUser(-4,4);
    // DYPT50_nT->Draw("text");

    double nSigEvent = Mx2_1_nT->Integral();
    double nBgEvent = ht0aphmin->Integral();
    int nBin = Mx2_1_nT->GetNbinsX();
    cout << nBin << endl;
    cout << "nSigEvent = " << nSigEvent << endl;
    cout << "nBgEvent = " << nBgEvent << endl;
    vector<vector<float>> effs(2, vector<float>(nBin)); // 2-D vector
    float Teffs[100], Teffb[100];
    vector<vector<double>> effs_t(2, vector<double>(nBin)); // with total
    vector<vector<float>> effb(2, vector<float>(nBin));     // bg
    vector<vector<double>> effb_t(2, vector<double>(nBin)); // with total
    vector<vector<double>> punziList(2, vector<double>(nBin));
    // For ERROR Calculate
    float sigeffend = 0.0;
    float bgnumberend = 0.0;

    vector<float> Punfirstuncer;
    // vector<float> bgnumberend;
    // vector<float> sigefffirst;
    // vector<float> bgnumberfirst;
    Punfirstuncer.clear();
    // bgnumberend.clear();
    // sigefffirst.clear();
    // bgnumberfirst.clear();
    for (auto &vec : effs_t)
        vec.clear();
    for (auto &vec : effb_t)
        vec.clear();
    for (auto &vec : effs)
        vec.clear();
    for (auto &vec : effb)
        vec.clear();
    for (auto &vec : punziList)
        vec.clear();

    double event[2][2] = {0, 0, 0, 0};
    // Part for Error
    for (int i = nBin; i > 0; i--)
    {
        event[1][1] += Mx2_1_nT->GetBinContent(i); // from end to 0 -upper and lower
        event[1][0] += ht0met->GetBinContent(i);
        sigeffend += (event[1][1] / nSigEvent);
        bgnumberend += event[1][0];
    }
    float Sigendmean = sigeffend / nBin;
    float Bgendmean = bgnumberend / nBin;
    float Sigenddiff = 0;
    float Bgenddiff = 0;
    for (int i = nBin; i > 0; i--)
    {
        event[1][1] += Mx2_1_nT->GetBinContent(i); // from end to 0 -upper and lower
        event[1][0] += ht0met->GetBinContent(i);
        // cout<<"bin= "<<i<<" event[1][0] = "<<event[1][0]<<" event[1][1] = "<<event[1][1]<<endl;
        effs[1].push_back(event[1][1] / nSigEvent);
        effb[1].push_back(event[1][0] / nBgEvent);
        Sigenddiff += pow((event[1][1] / nSigEvent) - Sigendmean, 2);
        Bgenddiff += pow(event[1][0] - Bgendmean, 2);
        // cout << " event " << event[0][1] << endl;
        //<< ": nBgEvent " << nBgEvent << ": EFFB " << effb[0] << " : " << i << endl;
        // cout << " effs " << effs[0][i] << endl;
        // cout << " effb " << effb[0][i] << endl;
        punziList[1].push_back(punzi(event[1][1] / nSigEvent, event[1][0]));
        // cout << "bin = "<<i<< " punziList[1][i] = " <<punziList[1][i]<<endl;
    }
    float Sigenduncer = sqrt(Sigenddiff / nBin);
    float Bgenduncer = sqrt(Bgenddiff / nBin);
    cout << "Sigenduncer = " << Sigenduncer << endl;
    cout << "Bgenduncer = " << Bgenduncer << endl;

    float sigefffirst = 0.0;
    float bgnumberfirst = 0.0;
    // Part for Error
    for (int i = 0; i < nBin; i++)
    {
        event[0][0] += Mx2_1_nT->GetBinContent(i + 1); // from 0 to end for sig
        event[0][1] += ht0aphmin->GetBinContent(i + 1);
        sigefffirst += (event[0][0] / nSigEvent);
        bgnumberfirst += event[0][1];
    }
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            event[i][j] = 0;
        }
    }

    float Sigfirstmean = sigefffirst / nBin;
    float Bgfirstmean = bgnumberfirst / nBin;
    float Sigfirstdiff = 0;
    float Bgfirstdiff = 0;

    for (int i = 0; i < nBin; i++)
    {
        event[0][0] += Mx2_1_nT->GetBinContent(i + 1); // from 0 to end for sig
        event[0][1] += ht0aphmin->GetBinContent(i + 1);
        effs[0].push_back(event[0][0] / nSigEvent); //(sig/other)
        effb[0].push_back(event[0][1] / nBgEvent);
        Sigfirstdiff += pow((event[0][0] / nSigEvent) - Sigfirstmean, 2);
        Bgfirstdiff += pow(event[0][1] - Bgfirstmean, 2);
        punziList[0].push_back(punzi(event[0][0] / nSigEvent, event[0][1]));
    }
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            event[i][j] = 0;
        }
    }

    float Sigfirstuncer = sqrt(Sigfirstdiff / nBin);
    float Bgfirstuncer = sqrt(Bgfirstdiff / nBin);
    // Part for Error
    for (int i = 0; i < nBin; i++)
    {
        event[0][0] += Mx2_1_nT->GetBinContent(i + 1); // from 0 to end for sig
        event[0][1] += ht0aphmin->GetBinContent(i + 1);
        Punfirstuncer.push_back(sqrt(pow(Sigfirstuncer, 2) * pow((1 / (1 + sqrt(event[0][1]))), 2) + pow(Bgfirstuncer, 2) * pow(event[0][0] * ((-1) / pow(1 + sqrt(event[0][1]), 2)) * (1 / (2 * sqrt(event[0][1]))), 2)));
    }
    cout << Punfirstuncer[0] << endl;
    // reverse(effs[1].begin(), effs[1].end());
    // reverse(effb[1].begin(), effb[1].end());
    reverse(punziList[1].begin(), punziList[1].end());

    cout << "Sigfirstuncer = " << Sigfirstuncer << endl;
    cout << "Bgfirstuncer = " << Bgfirstuncer << endl;

    for (int i = 0; i < nBin; i++)
    {
        // Teffs[i] = effs[0][i];
        // Teffb[i] = 1 - effb[0][i];
        // cout << Teffs[i] << "  " << Teffb[i] << "  " << endl;
        // punzi_met->SetBinContent(i + 1, punziList[1][i]);
        punzi_met->SetBinContent(i + 1, punziList[0][i]);
    }
    float_t punz = 0;
    Int_t max_bin = 0;
    // punz = punzi_Net->GetMaximum();
    // max_bin = punzi_Net->GetMaximumBin();
    // cout << "punzi_maximum = "  << punz << endl;
    // cout << "punzi_max_bin = "  << max_bin-1 << endl;
    auto c1 = new TCanvas();
    for (int i = 0; i < nBin; i++)
    {
        //cout <<"Punfirstuncer = "<<Punfirstuncer[i]<<endl;
        punzi_met->SetBinError(i+1,Punfirstuncer[i]);
    }

    punzi_met->GetXaxis()->SetTitle("met");
    punzi_met->GetYaxis()->SetTitle("Punzi_significance");
    punzi_met->GetYaxis()->SetTitleOffset(1.55);
    punzi_met->SetLineColor(kRed);
    punzi_met->SetLineWidth(2);
    punzi_met->Draw("");
    // punzi_aphmin->SaveAs("PN-alphamin1.png");

    /*
        TGraph *sigEff_vs_bkgEff = new TGraph(50, Teffs, Teffb);
        //sigEff_vs_bkgEff->SetMaximum(1.2);
        //sigEff_vs_bkgEff->Draw("ap");
        sigEff_vs_bkgEff->SetTitle("");
        sigEff_vs_bkgEff->GetXaxis()->SetTitle("Sig Efficiency");
        //sigEff_vs_bkgEff->GetXaxis()->SetLimits(0, 1.0);
        //sigEff_vs_bkgEff->GetXaxis()->SetTickSize(0.03);
        sigEff_vs_bkgEff->GetXaxis()->SetTitleOffset(1.2);
        sigEff_vs_bkgEff->GetXaxis()->SetLabelOffset(0.015);
        sigEff_vs_bkgEff->GetYaxis()->SetTitle("Bkg rejection Efficiency");
        sigEff_vs_bkgEff->GetYaxis()->SetTitleOffset(1.3);
        //sigEff_vs_bkgEff->GetYaxis()->SetNdivisions(505);
        //sigEff_vs_bkgEff->GetYaxis()->SetTickSize(0.03);
        sigEff_vs_bkgEff->GetYaxis()->SetLabelOffset(0.005);
        //sigEff_vs_bkgEff->GetHistogram()->SetMaximum(1.0); // along
        //sigEff_vs_bkgEff->GetHistogram()->SetMinimum(0.);
        //sigEff_vs_bkgEff->SetLineWidth(1508);
        sigEff_vs_bkgEff->Draw("AC*");
        //sigEff_vs_bkgEff->Draw("C");
    */
}