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
#include "./../../lib/Cross_section.h"
using namespace std;
void ee_Triboson3D(TString inputfile = "./../../../../../root_file/Ztoee/2016BKGMC/triboson/triboson_WWZ.root", TString outputfile1 = "./ee_Triboson_emjet.root")
{
    TFile *triboson_WWZfile = TFile::Open(inputfile);
    TFile *triboson_WZZfile = TFile::Open("./../../../../../root_file/Ztoee/2016BKGMC/triboson/triboson_WZZ.root");
    TFile *triboson_ZZZfile = TFile::Open("./../../../../../root_file/Ztoee/2016BKGMC/triboson/triboson_ZZZ.root");

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

    TH1F *h_triboson_NemJet[24];
    TH1F *h_triboson_NemJet2[24];
    TH1F *h_triboson_NemJet3[24];
    TH1F *h_triboson_NemJet4[24];

    for (int i = 0; i < 24; i++)
    {
        h_triboson_NemJet[i] = new TH1F(Form("h_triboson_NemJet_%d", i + 1), "", 10, 0, 10);
        h_triboson_NemJet2[i] = new TH1F(Form("h_triboson_NemJet2_%d", i + 1), "", 10, 0, 10);
        h_triboson_NemJet3[i] = new TH1F(Form("h_triboson_NemJet3_%d", i + 1), "", 10, 0, 10);
        h_triboson_NemJet4[i] = new TH1F(Form("h_triboson_NemJet4_%d", i + 1), "", 10, 0, 10);

        h_triboson_NemJet[i]->Sumw2();
        h_triboson_NemJet2[i]->Sumw2();
        h_triboson_NemJet3[i]->Sumw2();
        h_triboson_NemJet4[i]->Sumw2();
    }

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

    TTree *T_tree;
    triboson_WWZfile->GetObject("T_tree", T_tree);
    T_tree->SetBranchAddress("I_weight", &I_WWZ_weight);
    T_tree->SetBranchAddress("I_nThinJets", &I_WWZ_nThinJets);
    T_tree->SetBranchAddress("f_Met", &f_WWZ_met);
    T_tree->SetBranchAddress("v_fakealpha", &v_WWZ_alpha);
    T_tree->SetBranchAddress("v_fakealpha2", &v_WWZ_alpha2);
    T_tree->SetBranchAddress("v_fakealpha3", &v_WWZ_alpha3);
    T_tree->SetBranchAddress("v_fakealpha4", &v_WWZ_alpha4);
    for (int k = 0; k < 24; k++)
    {
        for (int evt = 0; evt < T_tree->GetEntries(); evt++)
        {
            T_tree->GetEntry(evt);
            if (I_WWZ_nThinJets < 2)
                continue;
            int nem1jet = 0;
            int nem2jet = 0;
            int nem3jet = 0;
            int nem4jet = 0;
            for (size_t i = 0; i < v_WWZ_alpha->size(); i++)
            {
                if ((*v_WWZ_alpha)[i] < 0.05 + k * 0.05)
                {
                    nem1jet++;
                }
            }
            for (size_t i = 0; i < v_WWZ_alpha2->size(); i++)
            {
                if ((*v_WWZ_alpha2)[i] < 0.05 + k * 0.05)
                {
                    nem2jet++;
                }
            }
            for (size_t i = 0; i < v_WWZ_alpha3->size(); i++)
            {
                if ((*v_WWZ_alpha3)[i] < 0.05 + k * 0.05)
                {
                    nem3jet++;
                }
            }
            for (size_t i = 0; i < v_WWZ_alpha4->size(); i++)
            {
                if ((*v_WWZ_alpha4)[i] < 0.05 + k * 0.05)
                {
                    nem4jet++;
                }
            }
            h_triboson_NemJet[k]->Fill(nem1jet, I_WWZ_weight * WWZWeight);
            h_triboson_NemJet2[k]->Fill(nem2jet, I_WWZ_weight * WWZWeight);
            h_triboson_NemJet3[k]->Fill(nem3jet, I_WWZ_weight * WWZWeight);
            h_triboson_NemJet4[k]->Fill(nem4jet, I_WWZ_weight * WWZWeight);
        }
    }
    TTree *T_tree2;
    triboson_WZZfile->GetObject("T_tree", T_tree2);
    T_tree2->SetBranchAddress("I_weight", &I_WZZ_weight);
    T_tree2->SetBranchAddress("I_nThinJets", &I_WZZ_nThinJets);
    T_tree2->SetBranchAddress("f_Met", &f_WZZ_met);
    T_tree2->SetBranchAddress("v_fakealpha", &v_WZZ_alpha);
    T_tree2->SetBranchAddress("v_fakealpha2", &v_WZZ_alpha2);
    T_tree2->SetBranchAddress("v_fakealpha3", &v_WZZ_alpha3);
    T_tree2->SetBranchAddress("v_fakealpha4", &v_WZZ_alpha4);
    for (int k = 0; k < 24; k++)
    {
        for (int evt = 0; evt < T_tree2->GetEntries(); evt++)
        {
            T_tree2->GetEntry(evt);
            if (I_WZZ_nThinJets < 2)
                continue;
            int nem1jet = 0;
            int nem2jet = 0;
            int nem3jet = 0;
            int nem4jet = 0;
            for (size_t i = 0; i < v_WZZ_alpha->size(); i++)
            {
                if ((*v_WZZ_alpha)[i] < 0.05 + k * 0.05)
                {
                    nem1jet++;
                }
            }
            for (size_t i = 0; i < v_WZZ_alpha2->size(); i++)
            {
                if ((*v_WZZ_alpha2)[i] < 0.05 + k * 0.05)
                {
                    nem2jet++;
                }
            }
            for (size_t i = 0; i < v_WZZ_alpha3->size(); i++)
            {
                if ((*v_WZZ_alpha3)[i] < 0.05 + k * 0.05)
                {
                    nem3jet++;
                }
            }
            for (size_t i = 0; i < v_WZZ_alpha4->size(); i++)
            {
                if ((*v_WZZ_alpha4)[i] < 0.05 + k * 0.05)
                {
                    nem4jet++;
                }
            }
            h_triboson_NemJet[k]->Fill(nem1jet, I_WZZ_weight * WZZWeight);
            h_triboson_NemJet2[k]->Fill(nem2jet, I_WZZ_weight * WZZWeight);
            h_triboson_NemJet3[k]->Fill(nem3jet, I_WZZ_weight * WZZWeight);
            h_triboson_NemJet4[k]->Fill(nem4jet, I_WZZ_weight * WZZWeight);
        }
    }
    TTree *T_tree3;
    triboson_ZZZfile->GetObject("T_tree", T_tree3);
    T_tree3->SetBranchAddress("I_weight", &I_ZZZ_weight);
    T_tree3->SetBranchAddress("I_nThinJets", &I_ZZZ_nThinJets);
    T_tree3->SetBranchAddress("f_Met", &f_ZZZ_met);
    T_tree3->SetBranchAddress("v_fakealpha", &v_ZZZ_alpha);
    T_tree3->SetBranchAddress("v_fakealpha2", &v_ZZZ_alpha2);
    T_tree3->SetBranchAddress("v_fakealpha3", &v_ZZZ_alpha3);
    T_tree3->SetBranchAddress("v_fakealpha4", &v_ZZZ_alpha4);
    for (int k = 0; k < 24; k++)
    {
        for (int evt = 0; evt < T_tree3->GetEntries(); evt++)
        {
            T_tree3->GetEntry(evt);
            if (I_ZZZ_nThinJets < 2)
                continue;
            int nem1jet = 0;
            int nem2jet = 0;
            int nem3jet = 0;
            int nem4jet = 0;
            for (size_t i = 0; i < v_ZZZ_alpha->size(); i++)
            {
                if ((*v_ZZZ_alpha)[i] < 0.05 + k * 0.05)
                {
                    nem1jet++;
                }
            }
            for (size_t i = 0; i < v_ZZZ_alpha2->size(); i++)
            {
                if ((*v_ZZZ_alpha2)[i] < 0.05 + k * 0.05)
                {
                    nem2jet++;
                }
            }
            for (size_t i = 0; i < v_ZZZ_alpha3->size(); i++)
            {
                if ((*v_ZZZ_alpha3)[i] < 0.05 + k * 0.05)
                {
                    nem3jet++;
                }
            }
            for (size_t i = 0; i < v_ZZZ_alpha4->size(); i++)
            {
                if ((*v_ZZZ_alpha4)[i] < 0.05 + k * 0.05)
                {
                    nem4jet++;
                }
            }
            h_triboson_NemJet[k]->Fill(nem1jet, I_ZZZ_weight * ZZZWeight);
            h_triboson_NemJet2[k]->Fill(nem2jet, I_ZZZ_weight * ZZZWeight);
            h_triboson_NemJet3[k]->Fill(nem3jet, I_ZZZ_weight * ZZZWeight);
            h_triboson_NemJet4[k]->Fill(nem4jet, I_ZZZ_weight * ZZZWeight);
        }
    }
    
    TFile *outfile_HT0_1 = TFile::Open(outputfile1, "RECREATE");
    outfile_HT0_1->cd();
    for (int i = 0; i < 24; i++)
    {
        h_triboson_NemJet[i]->Write();
        h_triboson_NemJet2[i]->Write();
        h_triboson_NemJet3[i]->Write();
        h_triboson_NemJet4[i]->Write();
    }

    outfile_HT0_1->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_Triboson3D();
    }
    else if (argc == 3)
    {
        ee_Triboson3D(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}