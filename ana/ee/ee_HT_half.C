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
#include "./../lib/Cross_section.h"
#include "./../lib/setNCUStyle.C"
using namespace std;
void ee_HT_half()
{
    int nthreads = 8;
    ROOT::EnableImplicitMT(nthreads);
    TFile *DYincli = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");
    TFile *DYHT70 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../../root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

    float_t HT, HT_1, HT_2;

    float_t f_ht0_Met, f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;

    float_t f_ht0_Met_1, f_ht70_Met_1, f_ht100_Met_1, f_ht200_Met_1, f_ht400_Met_1, f_ht600_Met_1, f_ht800_Met_1,
        f_ht1200_Met_1, f_ht2500_Met_1;

    float_t f_ht0_Met_2, f_ht70_Met_2, f_ht100_Met_2, f_ht200_Met_2, f_ht400_Met_2, f_ht600_Met_2, f_ht800_Met_2,
        f_ht1200_Met_2, f_ht2500_Met_2;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    Int_t I_ht0_weight_1, I_ht70_weight_1, I_ht100_weight_1, I_ht200_weight_1, I_ht400_weight_1, I_ht600_weight_1,
        I_ht800_weight_1, I_ht1200_weight_1, I_ht2500_weight_1;

    Int_t I_ht0_weight_2, I_ht70_weight_2, I_ht100_weight_2, I_ht200_weight_2, I_ht400_weight_2, I_ht600_weight_2,
        I_ht800_weight_2, I_ht1200_weight_2, I_ht2500_weight_2;

    vector<float> *v_ht0_alpha = new vector<float>();
    vector<float> *v_ht70_alpha = new vector<float>();
    vector<float> *v_ht100_alpha = new vector<float>();
    vector<float> *v_ht200_alpha = new vector<float>();
    vector<float> *v_ht400_alpha = new vector<float>();
    vector<float> *v_ht600_alpha = new vector<float>();
    vector<float> *v_ht800_alpha = new vector<float>();
    vector<float> *v_ht1200_alpha = new vector<float>();
    vector<float> *v_ht2500_alpha = new vector<float>();

    v_ht0_alpha->clear();
    v_ht70_alpha->clear();
    v_ht100_alpha->clear();
    v_ht200_alpha->clear();
    v_ht400_alpha->clear();
    v_ht600_alpha->clear();
    v_ht800_alpha->clear();
    v_ht1200_alpha->clear();
    v_ht2500_alpha->clear();

    vector<float> *v_ht0_alpha_1 = new vector<float>();
    vector<float> *v_ht70_alpha_1 = new vector<float>();
    vector<float> *v_ht100_alpha_1 = new vector<float>();
    vector<float> *v_ht200_alpha_1 = new vector<float>();
    vector<float> *v_ht400_alpha_1 = new vector<float>();
    vector<float> *v_ht600_alpha_1 = new vector<float>();
    vector<float> *v_ht800_alpha_1 = new vector<float>();
    vector<float> *v_ht1200_alpha_1 = new vector<float>();
    vector<float> *v_ht2500_alpha_1 = new vector<float>();

    v_ht0_alpha_1->clear();
    v_ht70_alpha_1->clear();
    v_ht100_alpha_1->clear();
    v_ht200_alpha_1->clear();
    v_ht400_alpha_1->clear();
    v_ht600_alpha_1->clear();
    v_ht800_alpha_1->clear();
    v_ht1200_alpha_1->clear();
    v_ht2500_alpha_1->clear();

    vector<float> *v_ht0_alpha_2 = new vector<float>();
    vector<float> *v_ht70_alpha_2 = new vector<float>();
    vector<float> *v_ht100_alpha_2 = new vector<float>();
    vector<float> *v_ht200_alpha_2 = new vector<float>();
    vector<float> *v_ht400_alpha_2 = new vector<float>();
    vector<float> *v_ht600_alpha_2 = new vector<float>();
    vector<float> *v_ht800_alpha_2 = new vector<float>();
    vector<float> *v_ht1200_alpha_2 = new vector<float>();
    vector<float> *v_ht2500_alpha_2 = new vector<float>();

    v_ht0_alpha_2->clear();
    v_ht70_alpha_2->clear();
    v_ht100_alpha_2->clear();
    v_ht200_alpha_2->clear();
    v_ht400_alpha_2->clear();
    v_ht600_alpha_2->clear();
    v_ht800_alpha_2->clear();
    v_ht1200_alpha_2->clear();
    v_ht2500_alpha_2->clear();

    vector<float> *v_ht0_JetPT = new vector<float>();
    vector<float> *v_ht70_JetPT = new vector<float>();
    vector<float> *v_ht100_JetPT = new vector<float>();
    vector<float> *v_ht200_JetPT = new vector<float>();
    vector<float> *v_ht400_JetPT = new vector<float>();
    vector<float> *v_ht600_JetPT = new vector<float>();
    vector<float> *v_ht800_JetPT = new vector<float>();
    vector<float> *v_ht1200_JetPT = new vector<float>();
    vector<float> *v_ht2500_JetPT = new vector<float>();

    v_ht0_JetPT->clear();
    v_ht70_JetPT->clear();
    v_ht100_JetPT->clear();
    v_ht200_JetPT->clear();
    v_ht400_JetPT->clear();
    v_ht600_JetPT->clear();
    v_ht800_JetPT->clear();
    v_ht1200_JetPT->clear();
    v_ht2500_JetPT->clear();

    vector<float> v_ht0_JetPT_1;
    vector<float> v_ht70_JetPT_1;
    vector<float> v_ht100_JetPT_1;
    vector<float> v_ht200_JetPT_1;
    vector<float> v_ht400_JetPT_1;
    vector<float> v_ht600_JetPT_1;
    vector<float> v_ht800_JetPT_1;
    vector<float> v_ht1200_JetPT_1;
    vector<float> v_ht2500_JetPT_1;

    v_ht0_JetPT_1.clear();
    v_ht70_JetPT_1.clear();
    v_ht100_JetPT_1.clear();
    v_ht200_JetPT_1.clear();
    v_ht400_JetPT_1.clear();
    v_ht600_JetPT_1.clear();
    v_ht800_JetPT_1.clear();
    v_ht1200_JetPT_1.clear();
    v_ht2500_JetPT_1.clear();

    vector<float> *v_ht0_JetPT_2 = new vector<float>();
    vector<float> *v_ht70_JetPT_2 = new vector<float>();
    vector<float> *v_ht100_JetPT_2 = new vector<float>();
    vector<float> *v_ht200_JetPT_2 = new vector<float>();
    vector<float> *v_ht400_JetPT_2 = new vector<float>();
    vector<float> *v_ht600_JetPT_2 = new vector<float>();
    vector<float> *v_ht800_JetPT_2 = new vector<float>();
    vector<float> *v_ht1200_JetPT_2 = new vector<float>();
    vector<float> *v_ht2500_JetPT_2 = new vector<float>();

    v_ht0_JetPT_2->clear();
    v_ht70_JetPT_2->clear();
    v_ht100_JetPT_2->clear();
    v_ht200_JetPT_2->clear();
    v_ht400_JetPT_2->clear();
    v_ht600_JetPT_2->clear();
    v_ht800_JetPT_2->clear();
    v_ht1200_JetPT_2->clear();
    v_ht2500_JetPT_2->clear();

    vector<float> *v_ht0_JetEta = new vector<float>();
    vector<float> *v_ht70_JetEta = new vector<float>();
    vector<float> *v_ht100_JetEta = new vector<float>();
    vector<float> *v_ht200_JetEta = new vector<float>();
    vector<float> *v_ht400_JetEta = new vector<float>();
    vector<float> *v_ht600_JetEta = new vector<float>();
    vector<float> *v_ht800_JetEta = new vector<float>();
    vector<float> *v_ht1200_JetEta = new vector<float>();
    vector<float> *v_ht2500_JetEta = new vector<float>();

    v_ht0_JetEta->clear();
    v_ht70_JetEta->clear();
    v_ht100_JetEta->clear();
    v_ht200_JetEta->clear();
    v_ht400_JetEta->clear();
    v_ht600_JetEta->clear();
    v_ht800_JetEta->clear();
    v_ht1200_JetEta->clear();
    v_ht2500_JetEta->clear();

    vector<float> *v_ht0_JetEta_1 = new vector<float>();
    vector<float> *v_ht70_JetEta_1 = new vector<float>();
    vector<float> *v_ht100_JetEta_1 = new vector<float>();
    vector<float> *v_ht200_JetEta_1 = new vector<float>();
    vector<float> *v_ht400_JetEta_1 = new vector<float>();
    vector<float> *v_ht600_JetEta_1 = new vector<float>();
    vector<float> *v_ht800_JetEta_1 = new vector<float>();
    vector<float> *v_ht1200_JetEta_1 = new vector<float>();
    vector<float> *v_ht2500_JetEta_1 = new vector<float>();

    v_ht0_JetEta_1->clear();
    v_ht70_JetEta_1->clear();
    v_ht100_JetEta_1->clear();
    v_ht200_JetEta_1->clear();
    v_ht400_JetEta_1->clear();
    v_ht600_JetEta_1->clear();
    v_ht800_JetEta_1->clear();
    v_ht1200_JetEta_1->clear();
    v_ht2500_JetEta_1->clear();

    vector<float> *v_ht0_JetEta_2 = new vector<float>();
    vector<float> *v_ht70_JetEta_2 = new vector<float>();
    vector<float> *v_ht100_JetEta_2 = new vector<float>();
    vector<float> *v_ht200_JetEta_2 = new vector<float>();
    vector<float> *v_ht400_JetEta_2 = new vector<float>();
    vector<float> *v_ht600_JetEta_2 = new vector<float>();
    vector<float> *v_ht800_JetEta_2 = new vector<float>();
    vector<float> *v_ht1200_JetEta_2 = new vector<float>();
    vector<float> *v_ht2500_JetEta_2 = new vector<float>();

    v_ht0_JetEta_2->clear();
    v_ht70_JetEta_2->clear();
    v_ht100_JetEta_2->clear();
    v_ht200_JetEta_2->clear();
    v_ht400_JetEta_2->clear();
    v_ht600_JetEta_2->clear();
    v_ht800_JetEta_2->clear();
    v_ht1200_JetEta_2->clear();
    v_ht2500_JetEta_2->clear();

    vector<int> *v_ht0_Jethadronflavor = new vector<int>();
    vector<int> *v_ht70_Jethadronflavor = new vector<int>();
    vector<int> *v_ht100_Jethadronflavor = new vector<int>();
    vector<int> *v_ht200_Jethadronflavor = new vector<int>();
    vector<int> *v_ht400_Jethadronflavor = new vector<int>();
    vector<int> *v_ht600_Jethadronflavor = new vector<int>();
    vector<int> *v_ht800_Jethadronflavor = new vector<int>();
    vector<int> *v_ht1200_Jethadronflavor = new vector<int>();
    vector<int> *v_ht2500_Jethadronflavor = new vector<int>();

    v_ht0_Jethadronflavor->clear();
    v_ht70_Jethadronflavor->clear();
    v_ht100_Jethadronflavor->clear();
    v_ht200_Jethadronflavor->clear();
    v_ht400_Jethadronflavor->clear();
    v_ht600_Jethadronflavor->clear();
    v_ht800_Jethadronflavor->clear();
    v_ht1200_Jethadronflavor->clear();
    v_ht2500_Jethadronflavor->clear();

    vector<int> *v_ht0_Jethadronflavor_1 = new vector<int>();
    vector<int> *v_ht70_Jethadronflavor_1 = new vector<int>();
    vector<int> *v_ht100_Jethadronflavor_1 = new vector<int>();
    vector<int> *v_ht200_Jethadronflavor_1 = new vector<int>();
    vector<int> *v_ht400_Jethadronflavor_1 = new vector<int>();
    vector<int> *v_ht600_Jethadronflavor_1 = new vector<int>();
    vector<int> *v_ht800_Jethadronflavor_1 = new vector<int>();
    vector<int> *v_ht1200_Jethadronflavor_1 = new vector<int>();
    vector<int> *v_ht2500_Jethadronflavor_1 = new vector<int>();

    v_ht0_Jethadronflavor_1->clear();
    v_ht70_Jethadronflavor_1->clear();
    v_ht100_Jethadronflavor_1->clear();
    v_ht200_Jethadronflavor_1->clear();
    v_ht400_Jethadronflavor_1->clear();
    v_ht600_Jethadronflavor_1->clear();
    v_ht800_Jethadronflavor_1->clear();
    v_ht1200_Jethadronflavor_1->clear();
    v_ht2500_Jethadronflavor_1->clear();

    vector<int> *v_ht0_Jethadronflavor_2 = new vector<int>();
    vector<int> *v_ht70_Jethadronflavor_2 = new vector<int>();
    vector<int> *v_ht100_Jethadronflavor_2 = new vector<int>();
    vector<int> *v_ht200_Jethadronflavor_2 = new vector<int>();
    vector<int> *v_ht400_Jethadronflavor_2 = new vector<int>();
    vector<int> *v_ht600_Jethadronflavor_2 = new vector<int>();
    vector<int> *v_ht800_Jethadronflavor_2 = new vector<int>();
    vector<int> *v_ht1200_Jethadronflavor_2 = new vector<int>();
    vector<int> *v_ht2500_Jethadronflavor_2 = new vector<int>();

    v_ht0_Jethadronflavor_2->clear();
    v_ht70_Jethadronflavor_2->clear();
    v_ht100_Jethadronflavor_2->clear();
    v_ht200_Jethadronflavor_2->clear();
    v_ht400_Jethadronflavor_2->clear();
    v_ht600_Jethadronflavor_2->clear();
    v_ht800_Jethadronflavor_2->clear();
    v_ht1200_Jethadronflavor_2->clear();
    v_ht2500_Jethadronflavor_2->clear();

    vector<int> *v_ht0_JetnTracks = new vector<int>();
    vector<int> *v_ht70_JetnTracks = new vector<int>();
    vector<int> *v_ht100_JetnTracks = new vector<int>();
    vector<int> *v_ht200_JetnTracks = new vector<int>();
    vector<int> *v_ht400_JetnTracks = new vector<int>();
    vector<int> *v_ht600_JetnTracks = new vector<int>();
    vector<int> *v_ht800_JetnTracks = new vector<int>();
    vector<int> *v_ht1200_JetnTracks = new vector<int>();
    vector<int> *v_ht2500_JetnTracks = new vector<int>();

    v_ht0_JetnTracks->clear();
    v_ht70_JetnTracks->clear();
    v_ht100_JetnTracks->clear();
    v_ht200_JetnTracks->clear();
    v_ht400_JetnTracks->clear();
    v_ht600_JetnTracks->clear();
    v_ht800_JetnTracks->clear();
    v_ht1200_JetnTracks->clear();
    v_ht2500_JetnTracks->clear();

    vector<int> *v_ht0_JetnTracks_1 = new vector<int>();
    vector<int> *v_ht70_JetnTracks_1 = new vector<int>();
    vector<int> *v_ht100_JetnTracks_1 = new vector<int>();
    vector<int> *v_ht200_JetnTracks_1 = new vector<int>();
    vector<int> *v_ht400_JetnTracks_1 = new vector<int>();
    vector<int> *v_ht600_JetnTracks_1 = new vector<int>();
    vector<int> *v_ht800_JetnTracks_1 = new vector<int>();
    vector<int> *v_ht1200_JetnTracks_1 = new vector<int>();
    vector<int> *v_ht2500_JetnTracks_1 = new vector<int>();

    v_ht0_JetnTracks_1->clear();
    v_ht70_JetnTracks_1->clear();
    v_ht100_JetnTracks_1->clear();
    v_ht200_JetnTracks_1->clear();
    v_ht400_JetnTracks_1->clear();
    v_ht600_JetnTracks_1->clear();
    v_ht800_JetnTracks_1->clear();
    v_ht1200_JetnTracks_1->clear();
    v_ht2500_JetnTracks_1->clear();

    vector<int> *v_ht0_JetnTracks_2 = new vector<int>();
    vector<int> *v_ht70_JetnTracks_2 = new vector<int>();
    vector<int> *v_ht100_JetnTracks_2 = new vector<int>();
    vector<int> *v_ht200_JetnTracks_2 = new vector<int>();
    vector<int> *v_ht400_JetnTracks_2 = new vector<int>();
    vector<int> *v_ht600_JetnTracks_2 = new vector<int>();
    vector<int> *v_ht800_JetnTracks_2 = new vector<int>();
    vector<int> *v_ht1200_JetnTracks_2 = new vector<int>();
    vector<int> *v_ht2500_JetnTracks_2 = new vector<int>();

    v_ht0_JetnTracks_2->clear();
    v_ht70_JetnTracks_2->clear();
    v_ht100_JetnTracks_2->clear();
    v_ht200_JetnTracks_2->clear();
    v_ht400_JetnTracks_2->clear();
    v_ht600_JetnTracks_2->clear();
    v_ht800_JetnTracks_2->clear();
    v_ht1200_JetnTracks_2->clear();
    v_ht2500_JetnTracks_2->clear();
    {
        TTree *T_event;
        DYincli->GetObject("T_event", T_event);
        T_event->SetBranchAddress("f_HT", &HT);
        T_event->SetBranchAddress("f_Met", &f_ht0_Met);
        T_event->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
        T_event->SetBranchAddress("v_fakeJetPt", &v_ht0_JetPT);
        T_event->SetBranchAddress("v_fakeJetEta", &v_ht0_JetEta);
        T_event->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
        T_event->SetBranchAddress("v_N_Tracks", &v_ht0_JetnTracks);
        TFile *outfile_HT0_1 = new TFile("DYHT0_1.root", "RECREATE");
        TTree *h1 = new TTree("h1", "h1");
        TFile *outfile_HT0_2 = new TFile("DYHT0_2.root", "RECREATE");
        TTree *h2 = new TTree("h2", "h2");
        h1->Branch("f_HT", &HT_1);
        h1->Branch("f_Met", &f_ht0_Met_1);
        h1->Branch("v_fakeJethadronflavor", &v_ht0_Jethadronflavor_1);
        h1->Branch("v_fakeJetPt", &v_ht0_JetPT_1);
        h1->Branch("v_fakeJetEta", &v_ht0_JetEta_1);
        h1->Branch("v_fakealpha", &v_ht0_alpha_1);
        h1->Branch("v_N_Tracks", &v_ht0_JetnTracks_1);
        h2->Branch("f_Met", &f_ht0_Met_2);
        h2->Branch("v_fakeJethadronflavor", &v_ht0_Jethadronflavor_2);
        h2->Branch("v_fakeJetPt", &v_ht0_JetPT_2);
        h2->Branch("v_fakeJetEta", &v_ht0_JetEta_2);
        h2->Branch("v_fakealpha", &v_ht0_alpha_2);
        h2->Branch("v_N_Tracks", &v_ht0_JetnTracks_2);
        //cout << T_event->GetEntries() << endl;
        //for (int evt = 0; evt < T_event->GetEntries(); evt++)
        const auto nEntries = T_event->GetEntries();
        for (auto evt : ROOT::TSeqUL(nEntries))
        {
            if (evt % 500 == 0)
            {
                cout << evt << endl;
                //fprintf(stderr, "Processing event %lli of %lli\n", T_event + 1, data.GetEntriesFast());
            }
            T_event->GetEntry(evt);
            if (evt % 2 == 1)
            {
                f_ht0_Met_1 = f_ht0_Met;
                for (int i = 0; i < v_ht0_Jethadronflavor->size(); i++)
                {
                    v_ht0_JetPT_1.push_back((*v_ht0_JetPT)[i]);
                    //(*v_ht0_JetEta_1)[i] = (*v_ht0_JetEta)[i];
                    //(*v_ht0_alpha_1)[i] = (*v_ht0_alpha)[i];
                    //(*v_ht0_JetnTracks_1)[i] = (*v_ht0_JetnTracks)[i];
                    //(*v_ht0_JetEta_1)[i] = (*v_ht0_JetEta)[i];
                }
                h1->Fill();
            }
            else
            {
                f_ht0_Met_2 = f_ht0_Met;
                /*
                for (int i = 0; i < v_ht0_Jethadronflavor->size(); i++)
                {
                    (*v_ht0_JetPT_2)[i] = (*v_ht0_JetPT)[i];
                    (*v_ht0_JetEta_2)[i] = (*v_ht0_JetEta)[i];
                    (*v_ht0_alpha_2)[i] = (*v_ht0_alpha)[i];
                    (*v_ht0_JetnTracks_2)[i] = (*v_ht0_JetnTracks)[i];
                    (*v_ht0_JetEta_2)[i] = (*v_ht0_JetEta)[i];
                }
                */
                h2->Fill();
            }
        }
        outfile_HT0_1->cd();
        h1->Write();
        outfile_HT0_1->Close();
        outfile_HT0_2->cd();
        h2->Write();
        outfile_HT0_2->Close();
    }
    ROOT::DisableImplicitMT();
    {
        TFile *outfile_HT70_1 = new TFile("DYHT70_1.root", "RECREATE");
        TTree *h1 = new TTree("h1", "h1");
    }
}