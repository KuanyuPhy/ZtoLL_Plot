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
void ee_HT_half(TString inputfile = "./../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root", TString outputfile1 = "./DYHT0_1.root", TString outputfile2 = "./DYHT0_2.root")
{
    // int nthreads = 8;
    // ROOT::EnableImplicitMT(nthreads);

    TFile *DYincli = TFile::Open(inputfile);

    float_t HT, HT_1, HT_2;

    float_t f_ht0_Met, f_ht0_Met_1, f_ht0_Met_2;

    Int_t I_ht0_weight, I_ht0_weight_1, I_ht0_weight_2;

    Int_t I_ht0_nJets, I_ht0_nJets_1, I_ht0_nJets_2;

    vector<float> *v_ht0_alpha = new vector<float>();
    vector<float> *v_ht0_alpha2 = new vector<float>();
    vector<float> *v_ht0_alpha3 = new vector<float>();
    vector<float> *v_ht0_alpha4 = new vector<float>();

    v_ht0_alpha->clear();
    v_ht0_alpha2->clear();
    v_ht0_alpha3->clear();
    v_ht0_alpha4->clear();

    vector<float> v_ht0_alpha_1;
    vector<float> v_ht0_alpha_2;

    vector<float> v_ht0_alpha2_1;
    vector<float> v_ht0_alpha2_2;

    vector<float> v_ht0_alpha3_1;
    vector<float> v_ht0_alpha3_2;

    vector<float> v_ht0_alpha4_1;
    vector<float> v_ht0_alpha4_2;

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

    vector<int> *v_ht0_Jetpartonflavor = new vector<int>();

    vector<int> v_ht0_Jetpartonflavor_1;
    vector<int> v_ht0_Jetpartonflavor_2;

    vector<int> *v_ht0_JetnTracks = new vector<int>();

    v_ht0_JetnTracks->clear();

    vector<int> v_ht0_JetnTracks_1;
    vector<int> v_ht0_JetnTracks_2;

    vector<float> *v_ht0_2DIP = new vector<float>();
    v_ht0_2DIP->clear();

    vector<float> v_ht0_2DIP_1;
    vector<float> v_ht0_2DIP_2;

    vector<float> *v_ht0_Chi3Dlog = new vector<float>();
    v_ht0_Chi3Dlog->clear();

    vector<float> v_ht0_Chi3Dlog_1;
    vector<float> v_ht0_Chi3Dlog_2;

    vector<float> v_ht0_eventId_1;
    vector<float> v_ht0_eventId_2;

    TTree *T_tree;
    DYincli->GetObject("T_tree", T_tree);
    T_tree->SetBranchAddress("f_HT", &HT);
    T_tree->SetBranchAddress("I_weight", &I_ht0_weight);
    T_tree->SetBranchAddress("f_Met", &f_ht0_Met);
    T_tree->SetBranchAddress("I_nJets", &I_ht0_nJets);
    T_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
    T_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ht0_Jetpartonflavor);
    T_tree->SetBranchAddress("v_fakeJetPt", &v_ht0_JetPT);
    T_tree->SetBranchAddress("v_fakeJetEta", &v_ht0_JetEta);
    T_tree->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    T_tree->SetBranchAddress("v_fakealpha2", &v_ht0_alpha2);
    T_tree->SetBranchAddress("v_fakealpha3", &v_ht0_alpha3);
    T_tree->SetBranchAddress("v_fakealpha4", &v_ht0_alpha4);
    T_tree->SetBranchAddress("v_N_Tracks", &v_ht0_JetnTracks);
    T_tree->SetBranchAddress("v_IP2D", &v_ht0_2DIP);
    T_tree->SetBranchAddress("v_Chi3Dlog", &v_ht0_Chi3Dlog);
    TFile *outfile_HT0_1 = TFile::Open(outputfile1, "RECREATE");
    TTree *h1 = new TTree("h1", "h1");
    TFile *outfile_HT0_2 = TFile::Open(outputfile2, "RECREATE");
    TTree *h2 = new TTree("h2", "h2");
    h1->Branch("v_eventID", &v_ht0_eventId_1);
    h1->Branch("f_HT", &HT_1);
    h1->Branch("I_weight", &I_ht0_weight_1);
    h1->Branch("f_Met", &f_ht0_Met_1);
    h1->Branch("I_nJets", &I_ht0_nJets_1);
    h1->Branch("v_fakeJethadronflavor", &v_ht0_Jethadronflavor_1);
    h1->Branch("v_fakeJetpartonflavor", &v_ht0_Jetpartonflavor_1);
    h1->Branch("v_fakeJetPt", &v_ht0_JetPT_1);
    h1->Branch("v_fakeJetEta", &v_ht0_JetEta_1);
    h1->Branch("v_fakealpha", &v_ht0_alpha_1);
    h1->Branch("v_fakealpha2", &v_ht0_alpha2_1);
    h1->Branch("v_fakealpha3", &v_ht0_alpha3_1);
    h1->Branch("v_fakealpha4", &v_ht0_alpha4_1);
    h1->Branch("v_N_Tracks", &v_ht0_JetnTracks_1);
    h1->Branch("v_IP2D", &v_ht0_2DIP_1);
    h1->Branch("v_Chi3Dlog", &v_ht0_Chi3Dlog_1);
    h2->Branch("v_eventID", &v_ht0_eventId_2);
    h2->Branch("f_HT", &HT_2);
    h2->Branch("f_Met", &f_ht0_Met_2);
    h2->Branch("I_nJets", &I_ht0_nJets_2);
    h2->Branch("I_weight", &I_ht0_weight_2);
    h2->Branch("v_fakeJethadronflavor", &v_ht0_Jethadronflavor_2);
    h2->Branch("v_fakeJetpartonflavor", &v_ht0_Jetpartonflavor_2);
    h2->Branch("v_fakeJetPt", &v_ht0_JetPT_2);
    h2->Branch("v_fakeJetEta", &v_ht0_JetEta_2);
    h2->Branch("v_fakealpha", &v_ht0_alpha_2);
    h2->Branch("v_fakealpha2", &v_ht0_alpha2_2);
    h2->Branch("v_fakealpha3", &v_ht0_alpha3_2);
    h2->Branch("v_fakealpha4", &v_ht0_alpha4_2);
    h2->Branch("v_N_Tracks", &v_ht0_JetnTracks_2);
    h2->Branch("v_IP2D", &v_ht0_2DIP_2);
    h2->Branch("v_Chi3Dlog", &v_ht0_Chi3Dlog_2);
    cout << T_tree->GetEntries() << endl;
    for (int evt = 0; evt < T_tree->GetEntries(); evt++)
    // const auto nEntries = T_tree->GetEntries();
    // for (auto evt : ROOT::TSeqUL(nEntries))
    {
        v_ht0_eventId_1.clear();
        v_ht0_eventId_2.clear();
        v_ht0_alpha_1.clear();
        v_ht0_alpha_2.clear();

        v_ht0_alpha2_1.clear();
        v_ht0_alpha2_2.clear();

        v_ht0_alpha3_1.clear();
        v_ht0_alpha3_2.clear();

        v_ht0_alpha4_1.clear();
        v_ht0_alpha4_2.clear();

        v_ht0_JetPT_1.clear();
        v_ht0_JetPT_2.clear();

        v_ht0_JetEta_1.clear();
        v_ht0_JetEta_2.clear();

        v_ht0_Jethadronflavor_1.clear();
        v_ht0_Jethadronflavor_2.clear();

        v_ht0_Jetpartonflavor_1.clear();
        v_ht0_Jetpartonflavor_2.clear();

        v_ht0_JetnTracks_1.clear();
        v_ht0_JetnTracks_2.clear();

        v_ht0_2DIP_1.clear();
        v_ht0_2DIP_2.clear();

        v_ht0_Chi3Dlog_1.clear();
        v_ht0_Chi3Dlog_2.clear();

        if (evt % 100000 == 0)
        {
            cout << evt << endl;
            // fprintf(stderr, "Processing event %lli of %lli\n", T_tree + 1, data.GetEntriesFast());
        }
        T_tree->GetEntry(evt);
        if (evt % 2 == 1)
        {

            HT_1 = HT;
            f_ht0_Met_1 = f_ht0_Met;
            I_ht0_weight_1 = I_ht0_weight;
            I_ht0_nJets_1 = I_ht0_nJets;
            for (size_t i = 0; i < v_ht0_2DIP->size(); i++)
            {
                v_ht0_2DIP_1.push_back((*v_ht0_2DIP)[i]);
                v_ht0_Chi3Dlog_1.push_back((*v_ht0_Chi3Dlog)[i]);
            }
            for (size_t i = 0; i < v_ht0_JetPT->size(); i++)
            {
                v_ht0_eventId_1.push_back(evt);
                v_ht0_Jethadronflavor_1.push_back((*v_ht0_Jethadronflavor)[i]);
                v_ht0_Jetpartonflavor_1.push_back((*v_ht0_Jetpartonflavor)[i]);
                v_ht0_JetPT_1.push_back((*v_ht0_JetPT)[i]);
                v_ht0_JetEta_1.push_back((*v_ht0_JetEta)[i]);
                v_ht0_alpha_1.push_back((*v_ht0_alpha)[i]);
                v_ht0_alpha2_1.push_back((*v_ht0_alpha2)[i]);
                v_ht0_alpha3_1.push_back((*v_ht0_alpha3)[i]);
                v_ht0_alpha4_1.push_back((*v_ht0_alpha4)[i]);
                v_ht0_JetnTracks_1.push_back((*v_ht0_JetnTracks)[i]);
            }
            h1->Fill();
        }
        else
        {
            HT_2 = HT;
            f_ht0_Met_2 = f_ht0_Met;
            I_ht0_weight_2 = I_ht0_weight;
            I_ht0_nJets_2 = I_ht0_nJets;
            for (size_t i = 0; i < v_ht0_2DIP->size(); i++)
            {
                v_ht0_2DIP_2.push_back((*v_ht0_2DIP)[i]);
                v_ht0_Chi3Dlog_2.push_back((*v_ht0_Chi3Dlog)[i]);
            }
            for (size_t i = 0; i < v_ht0_JetPT->size(); i++)
            {
                v_ht0_eventId_2.push_back(evt);
                v_ht0_Jethadronflavor_2.push_back((*v_ht0_Jethadronflavor)[i]);
                v_ht0_Jetpartonflavor_2.push_back((*v_ht0_Jetpartonflavor)[i]);
                v_ht0_JetPT_2.push_back((*v_ht0_JetPT)[i]);
                v_ht0_JetEta_2.push_back((*v_ht0_JetEta)[i]);
                v_ht0_alpha_2.push_back((*v_ht0_alpha)[i]);
                v_ht0_alpha2_2.push_back((*v_ht0_alpha2)[i]);
                v_ht0_alpha3_2.push_back((*v_ht0_alpha3)[i]);
                v_ht0_alpha4_2.push_back((*v_ht0_alpha4)[i]);
                v_ht0_JetnTracks_2.push_back((*v_ht0_JetnTracks)[i]);
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
        ee_HT_half();
    }
    else if (argc == 4)
    {
        ee_HT_half(argv[1], argv[2], argv[3]);
    }
    else
    {
        cout << "ERROR" << endl;
    }
}