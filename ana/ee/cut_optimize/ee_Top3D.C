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
void ee_Top3D(TString inputfile = "./../../../../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root", TString outputfile1 = "./ee_Top_emjet.root")
{
    TFile *TTTo2L2Nufile = TFile::Open(inputfile);

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)TTTo2L2Nufile->Get("Event_Variable/h_totevent"));

    int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();

    //---------------------
    // Define TopWeight
    //---------------------
    float TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * ((GlobalConstants::TTTo2L2Nu) / (TTTo2L2Nu_totevt)) * 1000;

    TH1F *h_Top_NemJet[24];
    TH1F *h_Top_NemJet2[24];
    TH1F *h_Top_NemJet3[24];
    TH1F *h_Top_NemJet4[24];

    for (int i = 0; i < 24; i++)
    {
        h_Top_NemJet[i] = new TH1F(Form("h_Top_NemJet_%d", i + 1), "", 10, 0, 10);
        h_Top_NemJet2[i] = new TH1F(Form("h_Top_NemJet2_%d", i + 1), "", 10, 0, 10);
        h_Top_NemJet3[i] = new TH1F(Form("h_Top_NemJet3_%d", i + 1), "", 10, 0, 10);
        h_Top_NemJet4[i] = new TH1F(Form("h_Top_NemJet4_%d", i + 1), "", 10, 0, 10);

        h_Top_NemJet[i]->Sumw2();
        h_Top_NemJet2[i]->Sumw2();
        h_Top_NemJet3[i]->Sumw2();
        h_Top_NemJet4[i]->Sumw2();
    }

    Int_t I_TTTo2L2Nu_nThinJets;

    Int_t I_TTTo2L2Nu_weight;

    float_t I_TTTo2L2Nu_met;

    vector<float> *v_TTTo2L2Nu_alpha = new vector<float>();
    vector<float> *v_TTTo2L2Nu_alpha2 = new vector<float>();
    vector<float> *v_TTTo2L2Nu_alpha3 = new vector<float>();
    vector<float> *v_TTTo2L2Nu_alpha4 = new vector<float>();

    vector<float> *v_TTTo2L2Nu_Chi3Dlog = new vector<float>();

    v_TTTo2L2Nu_alpha->clear();
    v_TTTo2L2Nu_alpha2->clear();
    v_TTTo2L2Nu_alpha3->clear();
    v_TTTo2L2Nu_alpha4->clear();

    v_TTTo2L2Nu_Chi3Dlog->clear();

    TTree *T_tree;
    TTTo2L2Nufile->GetObject("T_tree", T_tree);
    T_tree->SetBranchAddress("I_weight", &I_TTTo2L2Nu_weight);
    T_tree->SetBranchAddress("I_nThinJets", &I_TTTo2L2Nu_nThinJets);
    T_tree->SetBranchAddress("f_Met", &I_TTTo2L2Nu_met);
    T_tree->SetBranchAddress("v_Chi3Dlog", &v_TTTo2L2Nu_Chi3Dlog);
    T_tree->SetBranchAddress("v_fakealpha", &v_TTTo2L2Nu_alpha);
    T_tree->SetBranchAddress("v_fakealpha2", &v_TTTo2L2Nu_alpha2);
    T_tree->SetBranchAddress("v_fakealpha3", &v_TTTo2L2Nu_alpha3);
    T_tree->SetBranchAddress("v_fakealpha4", &v_TTTo2L2Nu_alpha4);
    for (int k = 0; k < 24; k++)
    {
        for (int evt = 0; evt < T_tree->GetEntries(); evt++)
        {
            T_tree->GetEntry(evt);
            if (I_TTTo2L2Nu_nThinJets < 2)
                continue;
            int nem1jet = 0;
            int nem2jet = 0;
            int nem3jet = 0;
            int nem4jet = 0;
            for (size_t i = 0; i < v_TTTo2L2Nu_alpha->size(); i++)
            {
                if ((*v_TTTo2L2Nu_alpha)[i] < 0.05 + k * 0.05)
                {
                    nem1jet++;
                }
            }
            for (size_t i = 0; i < v_TTTo2L2Nu_alpha2->size(); i++)
            {
                if ((*v_TTTo2L2Nu_alpha2)[i] < 0.05 + k * 0.05)
                {
                    nem2jet++;
                }
            }
            for (size_t i = 0; i < v_TTTo2L2Nu_alpha3->size(); i++)
            {
                if ((*v_TTTo2L2Nu_alpha3)[i] < 0.05 + k * 0.05)
                {
                    nem3jet++;
                }
            }
            for (size_t i = 0; i < v_TTTo2L2Nu_alpha4->size(); i++)
            {
                if ((*v_TTTo2L2Nu_alpha4)[i] < 0.05 + k * 0.05)
                {
                    nem4jet++;
                }
            }
            h_Top_NemJet[k]->Fill(nem1jet, I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_Top_NemJet2[k]->Fill(nem2jet, I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_Top_NemJet3[k]->Fill(nem3jet, I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_Top_NemJet4[k]->Fill(nem4jet, I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        }
    }
    // h_DYHT_NemJet[2]->Draw();
    TFile *outfile_HT0_1 = TFile::Open(outputfile1, "RECREATE");
    outfile_HT0_1->cd();
    for (int i = 0; i < 24; i++)
    {
        h_Top_NemJet[i]->Write();
        h_Top_NemJet2[i]->Write();
        h_Top_NemJet3[i]->Write();
        h_Top_NemJet4[i]->Write();
    }

    outfile_HT0_1->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_Top3D();
    }
    else if (argc == 3)
    {
        ee_Top3D(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}