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
#include <ROOT/TSeq.hxx>
#include "./../lib/Cross_section.h"
#include "./../lib/setNCUStyle.C"
using namespace std;
void ee_HT_half_test(TString inputfile = "./../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root", TString outputfile1 = "./DYHT0_1.root", TString outputfile2 = "./DYHT0_2.root")
{
    // int nthreads = 8;
    // ROOT::EnableImplicitMT(nthreads);

    TFile *DYincli = TFile::Open(inputfile);

    float_t HT, HT_1, HT_2;

    float_t f_ht0_Met, f_ht0_Met_1, f_ht0_Met_2;

    Int_t I_ht0_weight, I_ht0_weight_1, I_ht0_weight_2;

    vector<float> *v_ht0_alpha = new vector<float>();

    v_ht0_alpha->clear();

    vector<float> v_ht0_alpha_1;
    vector<float> v_ht0_alpha_2;

    vector<float> *v_ht0_JetPT = new vector<float>();

    v_ht0_JetPT->clear();

    vector<float> v_ht0_JetPT_1;
    vector<float> v_ht0_JetPT_2;

    vector<float> *v_ht0_JetEta = new vector<float>();

    v_ht0_JetEta->clear();

    vector<float> v_ht0_JetEta_1;
    vector<float> v_ht0_JetEta_2;

    vector<int> *v_ht0_Jethadronflavor = new vector<int>();

    v_ht0_Jethadronflavor->clear();

    vector<int> v_ht0_Jethadronflavor_1;
    vector<int> v_ht0_Jethadronflavor_2;

    vector<int> *v_ht0_JetnTracks = new vector<int>();

    v_ht0_JetnTracks->clear();

    vector<int> v_ht0_JetnTracks_1;
    vector<int> v_ht0_JetnTracks_2;

    TTree *T_event;
    DYincli->GetObject("T_event", T_event);
    T_event->SetBranchAddress("f_HT", &HT);
    T_event->SetBranchAddress("I_weight", &I_ht0_weight);
    T_event->SetBranchAddress("f_Met", &f_ht0_Met);
    T_event->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
    T_event->SetBranchAddress("v_fakeJetPt", &v_ht0_JetPT);
    T_event->SetBranchAddress("v_fakeJetEta", &v_ht0_JetEta);
    T_event->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    T_event->SetBranchAddress("v_N_Tracks", &v_ht0_JetnTracks);
    TFile *outfile_HT0_1 = TFile::Open(outputfile1, "RECREATE");
    TTree *h1 = new TTree("h1", "h1");
    TFile *outfile_HT0_2 = TFile::Open(outputfile2, "RECREATE");
    TTree *h2 = new TTree("h2", "h2");
    h1->Branch("f_HT", &HT_1);
    h1->Branch("I_weight", &I_ht0_weight_1);
    h1->Branch("f_Met", &f_ht0_Met_1);
    h1->Branch("v_fakeJethadronflavor", &v_ht0_Jethadronflavor_1);
    h1->Branch("v_fakeJetPt", &v_ht0_JetPT_1);
    h1->Branch("v_fakeJetEta", &v_ht0_JetEta_1);
    h1->Branch("v_fakealpha", &v_ht0_alpha_1);
    h1->Branch("v_N_Tracks", &v_ht0_JetnTracks_1);
    h2->Branch("f_HT", &HT_2);
    h2->Branch("f_Met", &f_ht0_Met_2);
    h2->Branch("I_weight", &I_ht0_weight_2);
    h2->Branch("v_fakeJethadronflavor", &v_ht0_Jethadronflavor_2);
    h2->Branch("v_fakeJetPt", &v_ht0_JetPT_2);
    h2->Branch("v_fakeJetEta", &v_ht0_JetEta_2);
    h2->Branch("v_fakealpha", &v_ht0_alpha_2);
    h2->Branch("v_N_Tracks", &v_ht0_JetnTracks_2);
    cout << T_event->GetEntries() << endl;
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    // const auto nEntries = T_event->GetEntries();
    // for (auto evt : ROOT::TSeqUL(nEntries))
    {
        v_ht0_alpha_1.clear();
        v_ht0_alpha_2.clear();

        v_ht0_JetPT_1.clear();
        v_ht0_JetPT_2.clear();

        v_ht0_JetEta_1.clear();
        v_ht0_JetEta_2.clear();

        v_ht0_Jethadronflavor_1.clear();
        v_ht0_Jethadronflavor_2.clear();

        v_ht0_JetnTracks_1.clear();
        v_ht0_JetnTracks_2.clear();

        if (evt % 100000 == 0)
        {
            cout << evt << endl;
            // fprintf(stderr, "Processing event %lli of %lli\n", T_event + 1, data.GetEntriesFast());
        }
        T_event->GetEntry(evt);
        if (evt % 2 == 1)
        {
            HT_1 = HT;
            f_ht0_Met_1 = f_ht0_Met;
            I_ht0_weight_1 = I_ht0_weight;
            for (int i = 0; i < v_ht0_JetPT->size(); i++)
            {
                v_ht0_Jethadronflavor_1.push_back((*v_ht0_Jethadronflavor)[i]);
                v_ht0_JetPT_1.push_back((*v_ht0_JetPT)[i]);
                v_ht0_JetEta_1.push_back((*v_ht0_JetEta)[i]);
                v_ht0_alpha_1.push_back((*v_ht0_alpha)[i]);
                v_ht0_JetnTracks_1.push_back((*v_ht0_JetnTracks)[i]);
                v_ht0_JetEta_1.push_back((*v_ht0_JetEta)[i]);
            }
            h1->Fill();
        }
        else
        {
            HT_2 = HT;
            f_ht0_Met_2 = f_ht0_Met;
            I_ht0_weight_2 = I_ht0_weight;
            for (int i = 0; i < v_ht0_JetPT->size(); i++)
            {
                v_ht0_Jethadronflavor_2.push_back((*v_ht0_Jethadronflavor)[i]);
                v_ht0_JetPT_2.push_back((*v_ht0_JetPT)[i]);
                v_ht0_JetEta_2.push_back((*v_ht0_JetEta)[i]);
                v_ht0_alpha_2.push_back((*v_ht0_alpha)[i]);
                v_ht0_JetnTracks_2.push_back((*v_ht0_JetnTracks)[i]);
                v_ht0_JetEta_2.push_back((*v_ht0_JetEta)[i]);
            }
            h2->Fill();
        }
    }
    outfile_HT0_1->cd();
    h1->Write();
    outfile_HT0_1->Close();
    outfile_HT0_2->cd();
    h2->Write();
    outfile_HT0_2->Close();
    DYincli->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_HT_half_test();
    }
    else if (argc == 4)
    {
        ee_HT_half_test(argv[1], argv[2], argv[3]);
    }
    else
    {
        cout << "ERROR" << endl;
    }
}