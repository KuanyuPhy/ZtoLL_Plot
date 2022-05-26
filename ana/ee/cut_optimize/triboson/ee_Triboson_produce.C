#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <string>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../../lib/Cross_section.h"
using namespace std;
void ee_Triboson_produce(TString inputfile = "./../../../../../../root_file/Ztoee/2016BKGMC/triboson/triboson_WWZ.root", TString outputfile1 = "./ee_Triboson_emjet.root")
{
    TFile *triboson_WWZfile = TFile::Open(inputfile);
    TFile *triboson_WZZfile = TFile::Open("./../../../../../../root_file/Ztoee/2016BKGMC/triboson/triboson_WZZ.root");
    TFile *triboson_ZZZfile = TFile::Open("./../../../../../../root_file/Ztoee/2016BKGMC/triboson/triboson_ZZZ.root");

    TH1D *WWZ_sumevt = ((TH1D *)triboson_WWZfile->Get("Event_Variable/h_totevent"));
    TH1D *WZZ_sumevt = ((TH1D *)triboson_WZZfile->Get("Event_Variable/h_totevent"));
    TH1D *ZZZ_sumevt = ((TH1D *)triboson_ZZZfile->Get("Event_Variable/h_totevent"));

    int WWZ_totevt = WWZ_sumevt->Integral();
    int WZZ_totevt = WZZ_sumevt->Integral();
    int ZZZ_totevt = ZZZ_sumevt->Integral();

    //---------------------
    // Define Triboson Weight
    //---------------------
    float WWZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::WWZ_TuneCUETP8M1 / (WWZ_totevt)) * 1000;
    float WZZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::WZZ_TuneCUETP8M1 / (WZZ_totevt)) * 1000;
    float ZZZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ZZZ_TuneCUETP8M1 / (ZZZ_totevt)) * 1000;

    TH1F *h_triboson_alpha[4];
    for (int i = 0; i < 4; i++)
    {
        h_triboson_alpha[i] = new TH1F(Form("h_triboson_alpha_%d", i + 1), "", 24, 0, 1.2);
        h_triboson_alpha[i]->Sumw2();
    }

    TH1F *h_triboson_Met = new TH1F("h_triboson_Met", "", 50, 0, 500);
    h_triboson_Met->GetXaxis()->SetTitle("");
    h_triboson_Met->GetYaxis()->SetTitle("");
    h_triboson_Met->Sumw2();

    TH1F *h_triboson_Chi3Dlog = new TH1F("h_triboson_Chi3Dlog", "", 100, -10, 10);
    h_triboson_Chi3Dlog->GetXaxis()->SetTitle("");
    h_triboson_Chi3Dlog->GetYaxis()->SetTitle("");
    h_triboson_Chi3Dlog->Sumw2();

    TH1F *h_triboson_IP2D = new TH1F("h_triboson_IP2D", "", 100, -10, 10);
    h_triboson_IP2D->GetXaxis()->SetTitle("");
    h_triboson_IP2D->GetYaxis()->SetTitle("");
    h_triboson_IP2D->Sumw2();

    TH1F *h_triboson_nTracks = new TH1F("h_triboson_nTracks", "", 50, 0, 50);
    h_triboson_nTracks->GetXaxis()->SetTitle("");
    h_triboson_nTracks->GetYaxis()->SetTitle("");
    h_triboson_nTracks->Sumw2();

    Int_t I_WWZ_nThinJets, I_WZZ_nThinJets, I_ZZZ_nThinJets;

    Int_t I_WWZ_weight, I_WZZ_weight, I_ZZZ_weight;

    float_t f_WWZ_met, f_WZZ_met, f_ZZZ_met;

    vector<float> *v_WWZ_alpha = new vector<float>();
    vector<float> *v_WWZ_alpha2 = new vector<float>();
    vector<float> *v_WWZ_alpha3 = new vector<float>();
    vector<float> *v_WWZ_alpha4 = new vector<float>();

    vector<float> *v_WZZ_alpha = new vector<float>();
    vector<float> *v_WZZ_alpha2 = new vector<float>();
    vector<float> *v_WZZ_alpha3 = new vector<float>();
    vector<float> *v_WZZ_alpha4 = new vector<float>();

    vector<float> *v_ZZZ_alpha = new vector<float>();
    vector<float> *v_ZZZ_alpha2 = new vector<float>();
    vector<float> *v_ZZZ_alpha3 = new vector<float>();
    vector<float> *v_ZZZ_alpha4 = new vector<float>();

    vector<float> *v_WWZ_Chi3Dlog = new vector<float>();
    vector<float> *v_WZZ_Chi3Dlog = new vector<float>();
    vector<float> *v_ZZZ_Chi3Dlog = new vector<float>();

    vector<float> *v_WWZ_2DIP = new vector<float>();
    vector<float> *v_WZZ_2DIP = new vector<float>();
    vector<float> *v_ZZZ_2DIP = new vector<float>();

    vector<float> *v_WWZ_nTracks = new vector<float>();
    vector<float> *v_WZZ_nTracks = new vector<float>();
    vector<float> *v_ZZZ_nTracks = new vector<float>();

    vector<float> *v_WWZ_Jethadronflavor = new vector<float>();
    vector<float> *v_WZZ_Jethadronflavor = new vector<float>();
    vector<float> *v_ZZZ_Jethadronflavor = new vector<float>();

    vector<float> *v_WWZ_Jetpartonflavor = new vector<float>();
    vector<float> *v_WZZ_Jetpartonflavor = new vector<float>();
    vector<float> *v_ZZZ_Jetpartonflavor = new vector<float>();

    v_WWZ_alpha->clear();
    v_WWZ_alpha2->clear();
    v_WWZ_alpha3->clear();
    v_WWZ_alpha4->clear();
    v_WZZ_alpha->clear();
    v_WZZ_alpha2->clear();
    v_WZZ_alpha3->clear();
    v_WZZ_alpha4->clear();

    v_ZZZ_alpha->clear();
    v_ZZZ_alpha2->clear();
    v_ZZZ_alpha3->clear();
    v_ZZZ_alpha4->clear();

    v_WWZ_Chi3Dlog->clear();
    v_WZZ_Chi3Dlog->clear();
    v_ZZZ_Chi3Dlog->clear();

    v_WWZ_2DIP->clear();
    v_WZZ_2DIP->clear();
    v_ZZZ_2DIP->clear();

    v_WWZ_nTracks->clear();
    v_WZZ_nTracks->clear();
    v_ZZZ_nTracks->clear();

    v_WWZ_Jethadronflavor->clear();
    v_WZZ_Jethadronflavor->clear();
    v_ZZZ_Jethadronflavor->clear();

    v_WWZ_Jetpartonflavor->clear();
    v_WZZ_Jetpartonflavor->clear();
    v_ZZZ_Jetpartonflavor->clear();

    TTree *T_tree;
    triboson_WWZfile->GetObject("T_tree", T_tree);
    T_tree->SetBranchAddress("I_weight", &I_WWZ_weight);
    T_tree->SetBranchAddress("I_nThinJets", &I_WWZ_nThinJets);
    T_tree->SetBranchAddress("v_N_Tracks", &v_WWZ_nTracks);
    T_tree->SetBranchAddress("f_Met", &f_WWZ_met);
    T_tree->SetBranchAddress("v_IP2D", &v_WWZ_2DIP);
    T_tree->SetBranchAddress("v_Chi3Dlog", &v_WWZ_Chi3Dlog);
    T_tree->SetBranchAddress("v_fakealpha", &v_WWZ_alpha);
    T_tree->SetBranchAddress("v_fakealpha2", &v_WWZ_alpha2);
    T_tree->SetBranchAddress("v_fakealpha3", &v_WWZ_alpha3);
    T_tree->SetBranchAddress("v_fakealpha4", &v_WWZ_alpha4);
    T_tree->SetBranchAddress("v_fakeJethadronflavor", &v_WWZ_Jethadronflavor);
    T_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_WWZ_Jetpartonflavor);
    for (int evt = 0; evt < T_tree->GetEntries(); evt++)
    {
        T_tree->GetEntry(evt);
        h_triboson_Met->Fill(f_WWZ_met, I_WWZ_weight * WWZWeight);
        for (size_t i = 0; i < v_WWZ_alpha->size(); i++)
        {
            h_triboson_alpha[0]->Fill((*v_WWZ_alpha)[i], I_WWZ_weight * WWZWeight);
        }
        for (size_t i = 0; i < v_WWZ_alpha2->size(); i++)
        {
            h_triboson_alpha[1]->Fill((*v_WWZ_alpha2)[i], I_WWZ_weight * WWZWeight);
        }
        for (size_t i = 0; i < v_WWZ_alpha3->size(); i++)
        {
            h_triboson_alpha[2]->Fill((*v_WWZ_alpha3)[i], I_WWZ_weight * WWZWeight);
        }
        for (size_t i = 0; i < v_WWZ_alpha4->size(); i++)
        {
            h_triboson_alpha[3]->Fill((*v_WWZ_alpha4)[i], I_WWZ_weight * WWZWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_WWZ_Chi3Dlog->size(); i++)
        {
            h_triboson_Chi3Dlog->Fill((*v_WWZ_Chi3Dlog)[i], I_WWZ_weight * WWZWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_WWZ_2DIP->size(); i++)
        {
            h_triboson_IP2D->Fill(log10(abs((*v_WWZ_2DIP)[i])), I_WWZ_weight * WWZWeight);
        }
        for (size_t i = 0; i < v_WWZ_nTracks->size(); i++)
        {
            h_triboson_nTracks->Fill((*v_WWZ_nTracks)[i], I_WWZ_weight * WWZWeight);
        }
    }
    TTree *T_tree2;
    triboson_WZZfile->GetObject("T_tree", T_tree2);
    T_tree2->SetBranchAddress("I_weight", &I_WZZ_weight);
    T_tree2->SetBranchAddress("I_nThinJets", &I_WZZ_nThinJets);
    T_tree2->SetBranchAddress("v_N_Tracks", &v_WZZ_nTracks);
    T_tree2->SetBranchAddress("f_Met", &f_WZZ_met);
    T_tree2->SetBranchAddress("v_IP2D", &v_WZZ_2DIP);
    T_tree2->SetBranchAddress("v_Chi3Dlog", &v_WZZ_Chi3Dlog);
    T_tree2->SetBranchAddress("v_fakealpha", &v_WZZ_alpha);
    T_tree2->SetBranchAddress("v_fakealpha2", &v_WZZ_alpha2);
    T_tree2->SetBranchAddress("v_fakealpha3", &v_WZZ_alpha3);
    T_tree2->SetBranchAddress("v_fakealpha4", &v_WZZ_alpha4);
    T_tree2->SetBranchAddress("v_fakeJethadronflavor", &v_WZZ_Jethadronflavor);
    T_tree2->SetBranchAddress("v_fakeJetpartonflavor", &v_WZZ_Jetpartonflavor);
    for (int evt = 0; evt < T_tree->GetEntries(); evt++)
    {
        T_tree2->GetEntry(evt);
        h_triboson_Met->Fill(f_WZZ_met, I_WZZ_weight * WZZWeight);
        for (size_t i = 0; i < v_WZZ_alpha->size(); i++)
        {
            h_triboson_alpha[0]->Fill((*v_WZZ_alpha)[i], I_WZZ_weight * WZZWeight);
        }
        for (size_t i = 0; i < v_WZZ_alpha2->size(); i++)
        {
            h_triboson_alpha[1]->Fill((*v_WZZ_alpha2)[i], I_WZZ_weight * WZZWeight);
        }
        for (size_t i = 0; i < v_WZZ_alpha3->size(); i++)
        {
            h_triboson_alpha[2]->Fill((*v_WZZ_alpha3)[i], I_WZZ_weight * WZZWeight);
        }
        for (size_t i = 0; i < v_WZZ_alpha4->size(); i++)
        {
            h_triboson_alpha[3]->Fill((*v_WZZ_alpha4)[i], I_WZZ_weight * WZZWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_WZZ_Chi3Dlog->size(); i++)
        {
            h_triboson_Chi3Dlog->Fill((*v_WZZ_Chi3Dlog)[i], I_WZZ_weight * WZZWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_WZZ_2DIP->size(); i++)
        {
            h_triboson_IP2D->Fill(log10(abs((*v_WZZ_2DIP)[i])), I_WZZ_weight * WZZWeight);
        }
        for (size_t i = 0; i < v_WZZ_nTracks->size(); i++)
        {
            h_triboson_nTracks->Fill((*v_WZZ_nTracks)[i], I_WZZ_weight * WZZWeight);
        }
    }

    TTree *T_tree3;
    triboson_ZZZfile->GetObject("T_tree", T_tree3);
    T_tree3->SetBranchAddress("I_weight", &I_ZZZ_weight);
    T_tree3->SetBranchAddress("I_nThinJets", &I_ZZZ_nThinJets);
    T_tree3->SetBranchAddress("v_N_Tracks", &v_ZZZ_nTracks);
    T_tree3->SetBranchAddress("f_Met", &f_ZZZ_met);
    T_tree3->SetBranchAddress("v_IP2D", &v_ZZZ_2DIP);
    T_tree3->SetBranchAddress("v_Chi3Dlog", &v_ZZZ_Chi3Dlog);
    T_tree3->SetBranchAddress("v_fakealpha", &v_ZZZ_alpha);
    T_tree3->SetBranchAddress("v_fakealpha2", &v_ZZZ_alpha2);
    T_tree3->SetBranchAddress("v_fakealpha3", &v_ZZZ_alpha3);
    T_tree3->SetBranchAddress("v_fakealpha4", &v_ZZZ_alpha4);
    T_tree3->SetBranchAddress("v_fakeJethadronflavor", &v_ZZZ_Jethadronflavor);
    T_tree3->SetBranchAddress("v_fakeJetpartonflavor", &v_ZZZ_Jetpartonflavor);
    for (int evt = 0; evt < T_tree->GetEntries(); evt++)
    {
        T_tree3->GetEntry(evt);
        h_triboson_Met->Fill(f_ZZZ_met, I_ZZZ_weight * ZZZWeight);
        for (size_t i = 0; i < v_ZZZ_alpha->size(); i++)
        {
            h_triboson_alpha[0]->Fill((*v_ZZZ_alpha)[i], I_ZZZ_weight * ZZZWeight);
        }
        for (size_t i = 0; i < v_ZZZ_alpha2->size(); i++)
        {
            h_triboson_alpha[1]->Fill((*v_ZZZ_alpha2)[i], I_ZZZ_weight * ZZZWeight);
        }
        for (size_t i = 0; i < v_ZZZ_alpha3->size(); i++)
        {
            h_triboson_alpha[2]->Fill((*v_ZZZ_alpha3)[i], I_ZZZ_weight * ZZZWeight);
        }
        for (size_t i = 0; i < v_ZZZ_alpha4->size(); i++)
        {
            h_triboson_alpha[3]->Fill((*v_ZZZ_alpha4)[i], I_ZZZ_weight * ZZZWeight);
        }
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_ZZZ_Chi3Dlog->size(); i++)
        {
            h_triboson_Chi3Dlog->Fill((*v_ZZZ_Chi3Dlog)[i], I_ZZZ_weight * ZZZWeight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_ZZZ_2DIP->size(); i++)
        {
            h_triboson_IP2D->Fill(log10(abs((*v_ZZZ_2DIP)[i])), I_ZZZ_weight * ZZZWeight);
        }
        for (size_t i = 0; i < v_ZZZ_nTracks->size(); i++)
        {
            h_triboson_nTracks->Fill((*v_ZZZ_nTracks)[i], I_ZZZ_weight * ZZZWeight);
        }
    }

    h_triboson_IP2D->SetLineWidth(2);
    h_triboson_IP2D->Draw("hist");

    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_triboson_Met->Write();
    h_triboson_nTracks->Write();
    h_triboson_IP2D->Write();
    h_triboson_Chi3Dlog->Write();
    outfile_HT0->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_Triboson_produce();
    }
    else if (argc == 3)
    {
        ee_Triboson_produce(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}