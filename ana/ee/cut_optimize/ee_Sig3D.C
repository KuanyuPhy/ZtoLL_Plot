#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <string>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../lib/Cross_section.h"
#include "./../../lib/setNCUStyle.C"
using namespace std;
void ee_Sig3D(TString inputfile = "./../../../../../root_file/Ztoee/Mx2_1.root", TString outputfile1 = "./Sig1.root")
{
    TH1F *h_ht0_NemJet[5];
    for (int i = 0; i < 5; i++)
    {
        h_ht0_NemJet[i] = new TH1F(Form("h_ht0_NemJet_%d", i), "", 10, 0, 10);
        h_ht0_NemJet[i]->Sumw2();
    }

    TFile *DYincli = TFile::Open(inputfile);
    float HT;
    Int_t I_ht0_nThinJets;
    Int_t I_ht0_weight;
    vector<float> *v_ht0_Median_2DIPsig = new vector<float>();
    vector<float> *v_ht0_alpha = new vector<float>();
    vector<int> *v_ht0_nTrack = new vector<int>();
    vector<float> *v_ht0_Chi3DlogPaper = new vector<float>();
    vector<float> *v_ht0_Chi3Dlog = new vector<float>();
    vector<float> *v_Mx2_1_alpha = new vector<float>();
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
                for (int i = 0; i < v_ht0_nTrack->size(); i++)
                {
                    bool emjet = true;
                    for (int j = itrack; j < itrack + (*v_ht0_nTrack)[i]; j++)
                    {
                        // cout << "(*v_ht0_Median_2DIPsig)[i] = " << (*v_ht0_Median_2DIPsig)[j] << endl;
                        // cout << "this track = " << j << endl;
                        if ((*v_ht0_Chi3Dlog)[j] > log3Dcut)
                        {
                            // cout << "(*v_ht0_Chi3Dlog)[i] = " << (*v_ht0_Chi3Dlog)[j] << endl;
                            emjet = false;
                            break;
                        }
                    }
                    itrack += (*v_ht0_nTrack)[i];
                    // cout << emjet << endl;
                    if (!emjet)
                        continue;
                    emjetnumber++;
                }
                // cout << "emjetnumber " << emjetnumber << endl;
                h_ht0_NemJet[log3Dcut]->Fill(emjetnumber);
            }
            
        }
    }
    TFile *outfile_HT0_1 = TFile::Open(outputfile1, "RECREATE");
    outfile_HT0_1->cd();
    for (int i = 0; i < 5; i++)
    {
        h_ht0_NemJet[i]->Write();
    }
    outfile_HT0_1->Close();
    // h_ht0_NemJet_0->Draw("text");
}