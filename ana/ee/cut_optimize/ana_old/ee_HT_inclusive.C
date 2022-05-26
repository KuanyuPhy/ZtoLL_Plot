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
void ee_HT_inclusive(TString inputfile = "./../../../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root", TString outputfile1 = "./DY_emjet.root")
{

    TFile *DYincli = TFile::Open(inputfile);
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

    bool HTflag = inputfile.Contains("DYincli");

    if (HTflag)
    {
        HTweight = HT0Weight;
    }
    else
    {
        HTweight = 0;
        cout << "ERROR" << endl;
    }

    TH1F *h_DYHT_NemJet[5];
    for (int i = 0; i < 5; i++)
    {
        h_DYHT_NemJet[i] = new TH1F(Form("h_ht0_NemJet_%d", i), "", 10, 0, 10);
        h_DYHT_NemJet[i]->Sumw2();
    }

    float HT;
    Int_t I_ht0_nThinJets;
    Int_t I_ht0_weight;
    vector<float> *v_ht0_Median_2DIPsig = new vector<float>();
    vector<float> *v_ht0_alpha = new vector<float>();
    vector<int> *v_ht0_nTrack = new vector<int>();
    vector<float> *v_ht0_Chi3DlogPaper = new vector<float>();
    vector<float> *v_ht0_Chi3Dlog = new vector<float>();
    vector<float> *v_HT_JetPT = new vector<float>();

    TTree *T_event;
    DYincli->GetObject("T_tree", T_event);
    T_event->SetBranchAddress("I_weight", &I_ht0_weight);
    T_event->SetBranchAddress("f_HT", &HT);
    T_event->SetBranchAddress("I_nThinJets", &I_ht0_nThinJets);
    T_event->SetBranchAddress("v_N_Tracks", &v_ht0_nTrack);
    T_event->SetBranchAddress("v_fakeJetPt", &v_HT_JetPT);
    T_event->SetBranchAddress("v_Median_2DIPsig", &v_ht0_Median_2DIPsig);
    T_event->SetBranchAddress("v_Chi3DlogPaper", &v_ht0_Chi3DlogPaper);
    T_event->SetBranchAddress("v_Chi3Dlog", &v_ht0_Chi3Dlog);
    T_event->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    for (int log3Dcut = 0; log3Dcut < 5; log3Dcut++)
    {
        for (int evt = 0; evt < T_event->GetEntries(); evt++)
        {
            T_event->GetEntry(evt);

            if (I_ht0_nThinJets < 2)
                continue;
            if (HT < 70)
            {
                // cout << "evt = " << evt << endl;
                int emjetnumber = 0;
                int itrack = 0;
                for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
                {
                    bool emjet = true;
                    for (int j = itrack; j < itrack + (*v_ht0_nTrack)[i]; j++)
                    {
                        // cout << "(*v_ht0_Median_2DIPsig)[i] = " << (*v_ht0_Median_2DIPsig)[j] << endl;
                        // cout << "this track = " << j << endl;
                        if (abs((*v_ht0_Chi3Dlog)[j]) > log3Dcut)
                        {
                            // cout << "(*v_ht0_Chi3Dlog)[i] = " << (*v_ht0_Chi3Dlog)[j] << endl;
                            emjet = false;
                            break;
                        }
                    }
                    itrack += (*v_ht0_nTrack)[i];
                    if (!emjet)
                        continue;
                    emjetnumber++;
                }
                h_DYHT_NemJet[log3Dcut]->Fill(emjetnumber, I_ht0_weight * HT0Weight);
            }
            else if (HT >= 70 && HT < 100)
            {
                int emjetnumber = 0;
                int itrack = 0;
                for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
                {
                    bool emjet = true;
                    for (int j = itrack; j < itrack + (*v_ht0_nTrack)[i]; j++)
                    {
                        if (abs((*v_ht0_Chi3Dlog)[j]) > log3Dcut)
                        {
                            emjet = false;
                            break;
                        }
                    }
                    itrack += (*v_ht0_nTrack)[i];
                    if (!emjet)
                        continue;
                    emjetnumber++;
                }
                h_DYHT_NemJet[log3Dcut]->Fill(emjetnumber, I_ht0_weight * HT70Weight);
            }
            else if (HT >= 100 && HT < 200)
            {
                int emjetnumber = 0;
                int itrack = 0;
                for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
                {
                    bool emjet = true;
                    for (int j = itrack; j < itrack + (*v_ht0_nTrack)[i]; j++)
                    {
                        if (abs((*v_ht0_Chi3Dlog)[j]) > log3Dcut)
                        {
                            emjet = false;
                            break;
                        }
                    }
                    itrack += (*v_ht0_nTrack)[i];
                    if (!emjet)
                        continue;
                    emjetnumber++;
                }
                h_DYHT_NemJet[log3Dcut]->Fill(emjetnumber, I_ht0_weight * HT100Weight);
            }
            else if (HT >= 200 && HT < 400)
            {
                int emjetnumber = 0;
                int itrack = 0;
                for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
                {
                    bool emjet = true;
                    for (int j = itrack; j < itrack + (*v_ht0_nTrack)[i]; j++)
                    {
                        if (abs((*v_ht0_Chi3Dlog)[j]) > log3Dcut)
                        {
                            emjet = false;
                            break;
                        }
                    }
                    itrack += (*v_ht0_nTrack)[i];
                    if (!emjet)
                        continue;
                    emjetnumber++;
                }
                h_DYHT_NemJet[log3Dcut]->Fill(emjetnumber, I_ht0_weight * HT200Weight);
            }
            else if (HT >= 400 && HT < 600)
            {
                int emjetnumber = 0;
                int itrack = 0;
                for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
                {
                    bool emjet = true;
                    for (int j = itrack; j < itrack + (*v_ht0_nTrack)[i]; j++)
                    {
                        if (abs((*v_ht0_Chi3Dlog)[j]) > log3Dcut)
                        {
                            emjet = false;
                            break;
                        }
                    }
                    itrack += (*v_ht0_nTrack)[i];
                    if (!emjet)
                        continue;
                    emjetnumber++;
                }
                h_DYHT_NemJet[log3Dcut]->Fill(emjetnumber, I_ht0_weight * HT400Weight);
            }
            else if (HT >= 600 && HT < 800)
            {
                int emjetnumber = 0;
                int itrack = 0;
                for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
                {
                    bool emjet = true;
                    for (int j = itrack; j < itrack + (*v_ht0_nTrack)[i]; j++)
                    {
                        if (abs((*v_ht0_Chi3Dlog)[j]) > log3Dcut)
                        {
                            emjet = false;
                            break;
                        }
                    }
                    itrack += (*v_ht0_nTrack)[i];
                    if (!emjet)
                        continue;
                    emjetnumber++;
                }
                h_DYHT_NemJet[log3Dcut]->Fill(emjetnumber, I_ht0_weight * HT600Weight);
            }

            else if (HT >= 800 && HT < 1200)
            {
                int emjetnumber = 0;
                int itrack = 0;
                for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
                {
                    bool emjet = true;
                    for (int j = itrack; j < itrack + (*v_ht0_nTrack)[i]; j++)
                    {
                        if (abs((*v_ht0_Chi3Dlog)[j]) > log3Dcut)
                        {
                            emjet = false;
                            break;
                        }
                    }
                    itrack += (*v_ht0_nTrack)[i];
                    if (!emjet)
                        continue;
                    emjetnumber++;
                }
                h_DYHT_NemJet[log3Dcut]->Fill(emjetnumber, I_ht0_weight * HT800Weight);
            }
            else if (HT >= 1200 && HT < 2500)
            {
                int emjetnumber = 0;
                int itrack = 0;
                for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
                {
                    bool emjet = true;
                    for (int j = itrack; j < itrack + (*v_ht0_nTrack)[i]; j++)
                    {
                        if (abs((*v_ht0_Chi3Dlog)[j]) > log3Dcut)
                        {
                            emjet = false;
                            break;
                        }
                    }
                    itrack += (*v_ht0_nTrack)[i];
                    if (!emjet)
                        continue;
                    emjetnumber++;
                }
                h_DYHT_NemJet[log3Dcut]->Fill(emjetnumber, I_ht0_weight * HT1200Weight);
            }
            else if (HT >= 2500)
            {
                int emjetnumber = 0;
                int itrack = 0;
                for (size_t i = 0; i < v_ht0_nTrack->size(); i++)
                {
                    bool emjet = true;
                    for (int j = itrack; j < itrack + (*v_ht0_nTrack)[i]; j++)
                    {
                        if (abs((*v_ht0_Chi3Dlog)[j]) > log3Dcut)
                        {
                            emjet = false;
                            break;
                        }
                    }
                    itrack += (*v_ht0_nTrack)[i];
                    if (!emjet)
                        continue;
                    emjetnumber++;
                }
                h_DYHT_NemJet[log3Dcut]->Fill(emjetnumber, I_ht0_weight * HT2500Weight);
            }
        }
    }
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
        ee_HT_inclusive();
    }
    else if (argc == 3)
    {
        ee_HT_inclusive(argv[1], argv[2]);
    }
    else
    {
        cout<<"argc"<<argc<<endl;
        cout << "ERROR" << endl;
    }
}