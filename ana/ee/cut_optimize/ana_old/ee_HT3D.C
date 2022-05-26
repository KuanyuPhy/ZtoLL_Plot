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
void ee_HT3D(TString inputfile = "./../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht200.root", TString outputfile1 = "./Sig1.root")
{
    TFile *DYTmp = TFile::Open(inputfile);
    TFile *DYincli = new TFile("./../../../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");

    TFile *DYemjet = new TFile("./DY_inclus_emjet.root");

    TFile *DYHT100 = new TFile("./../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("Event_Variable/h_totevent"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("Event_Variable/h_totevent"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("Event_Variable/h_totevent"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("Event_Variable/h_totevent"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("Event_Variable/h_totevent"));

    int DYHT100_totevt = DYHT100_sumevt->Integral();
    int DYHT200_totevt = DYHT200_sumevt->Integral();
    int DYHT400_totevt = DYHT400_sumevt->Integral();
    int DYHT600_totevt = DYHT600_sumevt->Integral();
    int DYHT800_totevt = DYHT800_sumevt->Integral();
    int DYHT1200_totevt = DYHT1200_sumevt->Integral();
    int DYHT2500_totevt = DYHT2500_sumevt->Integral();

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));

    int HT0_70_event = h_HT_eventCout->GetBinContent(2);
    int HT70_100_event = h_HT_eventCout->GetBinContent(3);
    int HT100_200_event = h_HT_eventCout->GetBinContent(4);
    int HT200_400_event = h_HT_eventCout->GetBinContent(5);
    int HT400_600_event = h_HT_eventCout->GetBinContent(6);
    int HT600_800_event = h_HT_eventCout->GetBinContent(7);
    int HT800_1200_event = h_HT_eventCout->GetBinContent(8);
    int HT1200_2500_event = h_HT_eventCout->GetBinContent(9);
    int HT2500_Inf_event = h_HT_eventCout->GetBinContent(10);

    //---------------------
    // Define HTWeight
    //---------------------
    float HT0Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT0CS) / (HT0_70_event)) * 1000;
    float HT70Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT70CS) / (HT70_100_event)) * 1000;
    float HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000;
    float HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000;
    float HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000;
    float HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000;
    float HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000;
    float HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000;
    float HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000;

    float HTweight;
    bool HT100flag = inputfile.Contains("ee_ht100");
    bool HT200flag = inputfile.Contains("ee_ht200");
    bool HT400flag = inputfile.Contains("ee_ht400");
    bool HT600flag = inputfile.Contains("ee_ht600");
    bool HT800flag = inputfile.Contains("ee_ht800");
    bool HT1200flag = inputfile.Contains("ee_ht1200");
    bool HT2500flag = inputfile.Contains("ee_ht2500");
    if (HT100flag)
    {
        HTweight = HT100Weight;
    }
    else if (HT200flag)
    {
        cout << "HT200flag = " << HT200flag << endl;
        HTweight = HT200Weight;
    }
    else if (HT400flag)
    {
        HTweight = HT400Weight;
    }
    else if (HT600flag)
    {
        HTweight = HT600Weight;
    }
    else if (HT800flag)
    {
        HTweight = HT800Weight;
    }
    else if (HT1200flag)
    {
        HTweight = HT1200Weight;
    }
    else if (HT2500flag)
    {
        HTweight = HT2500Weight;
    }
    TH1F *h_DYHT_NemJet[5];
    for (int i = 0; i < 5; i++)
    {
        h_DYHT_NemJet[i] = ((TH1F *)DYemjet->Get(("h_ht0_NemJet_" + std::to_string(i)).c_str()));
    }

    Int_t I_ht_nThinJets;
    Int_t I_ht_weight;
    vector<float> *v_ht_Median_2DIPsig = new vector<float>();
    vector<float> *v_ht_alpha = new vector<float>();
    vector<float> *v_ht_alpha2 = new vector<float>();
    vector<float> *v_ht_alpha3 = new vector<float>();
    vector<float> *v_ht_alpha4 = new vector<float>();
    vector<int> *v_ht_nTrack = new vector<int>();
    vector<float> *v_ht_Chi3DlogPaper = new vector<float>();
    vector<float> *v_ht_Chi3Dlog = new vector<float>();

    TTree *T_tree;
    DYTmp->GetObject("T_tree", T_tree);
    T_tree->SetBranchAddress("I_weight", &I_ht_weight);
    T_tree->SetBranchAddress("I_nThinJets", &I_ht_nThinJets);
    T_tree->SetBranchAddress("v_Median_2DIPsig", &v_ht_Median_2DIPsig);
    T_tree->SetBranchAddress("v_Chi3DlogPaper", &v_ht_Chi3DlogPaper);
    T_tree->SetBranchAddress("v_Chi3Dlog", &v_ht_Chi3Dlog);
    T_tree->SetBranchAddress("v_fakealpha", &v_ht_alpha);
    T_tree->SetBranchAddress("v_fakealpha2", &v_ht_alpha2);
    T_tree->SetBranchAddress("v_fakealpha3", &v_ht_alpha3);
    T_tree->SetBranchAddress("v_fakealpha4", &v_ht_alpha4);
    for (int log3Dcut = 0; log3Dcut < 5; log3Dcut++)
    {
        for (int evt = 0; evt < T_tree->GetEntries(); evt++)
        {
            T_tree->GetEntry(evt);
            if (I_ht_nThinJets < 2)
                continue;
            int emjetnumber = 0;
            int itrack = 0;
            for (size_t i = 0; i < v_ht_nTrack->size(); i++)
            {
                bool emjet = true;
                for (int j = itrack; j < itrack + (*v_ht_nTrack)[i]; j++)
                {
                    // cout << "(*v_ht0_Median_2DIPsig)[i] = " << (*v_ht0_Median_2DIPsig)[j] << endl;
                    // cout << "this track = " << j << endl;
                    if (abs((*v_ht_Chi3Dlog)[j]) > log3Dcut)
                    {
                        // cout << "(*v_ht0_Chi3Dlog)[i] = " << (*v_ht0_Chi3Dlog)[j] << endl;
                        emjet = false;
                        break;
                    }
                }
                itrack += (*v_ht_nTrack)[i];
                if (!emjet)
                    continue;
                for (int k = 1; k <= 10; k++)
                {
                    if ((*v_ht_alpha)[i] < k * 0.1)
                    {
                    }
                }
                emjetnumber++;
            }
            h_DYHT_NemJet[log3Dcut]->Fill(emjetnumber, I_ht_weight * HTweight);
        }
    }
    // h_DYHT_NemJet[2]->Draw();
    TFile *outfile_HT0_1 = TFile::Open(outputfile1, "RECREATE");
    outfile_HT0_1->cd();
    for (int i = 0; i < 5; i++)
    {
        h_DYHT_NemJet[i]->Write();
    }
    outfile_HT0_1->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_HT3D();
    }
    else if (argc == 3)
    {
        ee_HT3D(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}