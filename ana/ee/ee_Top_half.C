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
void ee_Top_half(TString inputfile = "./../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root", TString outputfile1 = "./DYTop_1.root", TString outputfile2 = "./DYTop_2.root")
{
    // int nthreads = 8;
    // ROOT::EnableImplicitMT(nthreads);

    TFile *Top_sample = TFile::Open(inputfile);

    float_t f_Top_Met, f_Top_Met_1, f_Top_Met_2;

    Int_t I_Top_weight, I_Top_weight_1, I_Top_weight_2;

    Int_t I_Top_nJets, I_Top_nJets_1, I_Top_nJets_2;

    vector<float> *v_Top_alpha = new vector<float>();
    vector<float> *v_Top_alpha2 = new vector<float>();
    vector<float> *v_Top_alpha3 = new vector<float>();
    vector<float> *v_Top_alpha4 = new vector<float>();

    v_Top_alpha->clear();
    v_Top_alpha2->clear();
    v_Top_alpha3->clear();
    v_Top_alpha4->clear();

    vector<float> v_Top_alpha_1;
    vector<float> v_Top_alpha_2;

    vector<float> v_Top_alpha2_1;
    vector<float> v_Top_alpha2_2;

    vector<float> v_Top_alpha3_1;
    vector<float> v_Top_alpha3_2;

    vector<float> v_Top_alpha4_1;
    vector<float> v_Top_alpha4_2;

    vector<float> *v_Top_JetPT = new vector<float>();

    v_Top_JetPT->clear();

    vector<float> v_Top_JetPT_1;
    vector<float> v_Top_JetPT_2;

    vector<float> *v_Top_JetEta = new vector<float>();

    v_Top_JetEta->clear();

    vector<float> v_Top_JetEta_1;
    vector<float> v_Top_JetEta_2;

    vector<int> *v_Top_Jethadronflavor = new vector<int>();

    v_Top_Jethadronflavor->clear();

    vector<int> *v_Top_Jetpartonflavor = new vector<int>();

    v_Top_Jetpartonflavor->clear();

    vector<int> v_Top_Jethadronflavor_1;
    vector<int> v_Top_Jethadronflavor_2;

    vector<int> v_Top_Jetpartonflavor_1;
    vector<int> v_Top_Jetpartonflavor_2;

    vector<int> *v_Top_JetnTracks = new vector<int>();

    v_Top_JetnTracks->clear();

    vector<int> v_Top_JetnTracks_1;
    vector<int> v_Top_JetnTracks_2;

    vector<float> *v_Top_2DIP = new vector<float>();
    v_Top_2DIP->clear();

    vector<float> v_Top_2DIP_1;
    vector<float> v_Top_2DIP_2;

    vector<float> *v_Top_Chi3Dlog = new vector<float>();
    v_Top_Chi3Dlog->clear();

    vector<float> v_Top_Chi3Dlog_1;
    vector<float> v_Top_Chi3Dlog_2;

    vector<float> v_Top_eventId_1;
    vector<float> v_Top_eventId_2;

    TTree *T_tree;
    Top_sample->GetObject("T_tree", T_tree);
    T_tree->SetBranchAddress("I_weight", &I_Top_weight);
    T_tree->SetBranchAddress("f_Met", &f_Top_Met);
    T_tree->SetBranchAddress("I_nJets", &I_Top_nJets);
    T_tree->SetBranchAddress("v_fakeJethadronflavor", &v_Top_Jethadronflavor);
    T_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_Top_Jetpartonflavor);
    T_tree->SetBranchAddress("v_fakeJetPt", &v_Top_JetPT);
    T_tree->SetBranchAddress("v_fakeJetEta", &v_Top_JetEta);
    T_tree->SetBranchAddress("v_fakealpha", &v_Top_alpha);
    T_tree->SetBranchAddress("v_fakealpha2", &v_Top_alpha2);
    T_tree->SetBranchAddress("v_fakealpha3", &v_Top_alpha3);
    T_tree->SetBranchAddress("v_fakealpha4", &v_Top_alpha4);
    T_tree->SetBranchAddress("v_N_Tracks", &v_Top_JetnTracks);
    T_tree->SetBranchAddress("v_IP2D", &v_Top_2DIP);
    T_tree->SetBranchAddress("v_Chi3Dlog", &v_Top_Chi3Dlog);
    TFile *outfile_Top_1 = TFile::Open(outputfile1, "RECREATE");
    TTree *h1 = new TTree("h1", "");
    h1->Branch("v_eventID", &v_Top_eventId_1);
    h1->Branch("I_weight", &I_Top_weight_1);
    h1->Branch("f_Met", &f_Top_Met_1);
    h1->Branch("I_nJets", &I_Top_nJets_1);
    h1->Branch("v_fakeJethadronflavor", &v_Top_Jethadronflavor_1);
    h1->Branch("v_fakeJetpartonflavor", &v_Top_Jetpartonflavor_1);
    h1->Branch("v_fakeJetPt", &v_Top_JetPT_1);
    h1->Branch("v_fakeJetEta", &v_Top_JetEta_1);
    h1->Branch("v_fakealpha", &v_Top_alpha_1);
    h1->Branch("v_fakealpha2", &v_Top_alpha2_1);
    h1->Branch("v_fakealpha3", &v_Top_alpha3_1);
    h1->Branch("v_fakealpha4", &v_Top_alpha4_1);
    h1->Branch("v_N_Tracks", &v_Top_JetnTracks_1);
    h1->Branch("v_IP2D", &v_Top_2DIP_1);
    h1->Branch("v_Chi3Dlog", &v_Top_Chi3Dlog_1);
    for (int evt = 0; evt < T_tree->GetEntries(); evt++)
    {
        T_tree->GetEntry(evt);
        // if (evt % 100000 == 0)
        //{
        //     cout << evt << endl;
        //  fprintf(stderr, "Processing event %lli of %lli\n", T_tree + 1, data.GetEntriesFast());
        //}
        if (evt % 2 == 1)
        {
            v_Top_eventId_1.clear();
            v_Top_alpha_1.clear();
            v_Top_alpha2_1.clear();
            v_Top_alpha3_1.clear();
            v_Top_alpha4_1.clear();
            v_Top_JetPT_1.clear();
            v_Top_JetEta_1.clear();
            v_Top_Jethadronflavor_1.clear();
            v_Top_Jetpartonflavor_1.clear();
            v_Top_JetnTracks_1.clear();
            v_Top_2DIP_1.clear();
            v_Top_Chi3Dlog_1.clear();
            f_Top_Met_1 = f_Top_Met;
            I_Top_weight_1 = I_Top_weight;
            I_Top_nJets_1 = I_Top_nJets;
            for (size_t i = 0; i < v_Top_2DIP->size(); i++)
            {
                v_Top_2DIP_1.push_back((*v_Top_2DIP)[i]);
                v_Top_Chi3Dlog_1.push_back((*v_Top_Chi3Dlog)[i]);
            }
            for (size_t i = 0; i < v_Top_Jethadronflavor->size(); i++)
            {
                v_Top_Jethadronflavor_1.push_back((*v_Top_Jethadronflavor)[i]);
            }
            //cout << "evt = " << evt << endl;
            for (size_t i = 0; i < v_Top_JetEta->size(); i++)
            {
                v_Top_JetEta_1.push_back((*v_Top_JetEta)[i]);
            }
            for (size_t i = 0; i < v_Top_JetPT->size(); i++)
            {
                v_Top_eventId_1.push_back(evt);
                v_Top_Jetpartonflavor_1.push_back((*v_Top_Jetpartonflavor)[i]);
                v_Top_JetPT_1.push_back((*v_Top_JetPT)[i]);
                v_Top_alpha_1.push_back((*v_Top_alpha)[i]);
                v_Top_alpha2_1.push_back((*v_Top_alpha2)[i]);
                v_Top_alpha3_1.push_back((*v_Top_alpha3)[i]);
                v_Top_alpha4_1.push_back((*v_Top_alpha4)[i]);
                v_Top_JetnTracks_1.push_back((*v_Top_JetnTracks)[i]);
            }
            h1->Fill();
        }
    }
    //outfile_Top_1->cd();
    h1->Write();
    outfile_Top_1->Close();
    TFile *outfile_Top_2 = TFile::Open(outputfile2, "RECREATE");
    TTree *h2 = new TTree("h2", "h2");
    h2->Branch("v_eventID", &v_Top_eventId_2);
    h2->Branch("f_Met", &f_Top_Met_2);
    h2->Branch("I_nJets", &I_Top_nJets_2);
    h2->Branch("I_weight", &I_Top_weight_2);
    h2->Branch("v_fakeJethadronflavor", &v_Top_Jethadronflavor_2);
    h2->Branch("v_fakeJetpartonflavor", &v_Top_Jetpartonflavor_2);
    h2->Branch("v_fakeJetPt", &v_Top_JetPT_2);
    h2->Branch("v_fakeJetEta", &v_Top_JetEta_2);
    h2->Branch("v_fakealpha", &v_Top_alpha_2);
    h2->Branch("v_fakealpha2", &v_Top_alpha2_2);
    h2->Branch("v_fakealpha3", &v_Top_alpha3_2);
    h2->Branch("v_fakealpha4", &v_Top_alpha4_2);
    h2->Branch("v_N_Tracks", &v_Top_JetnTracks_2);
    h2->Branch("v_IP2D", &v_Top_2DIP_2);
    h2->Branch("v_Chi3Dlog", &v_Top_Chi3Dlog_2);
    for (int evt = 0; evt < T_tree->GetEntries(); evt++)
    {
        T_tree->GetEntry(evt);
        v_Top_eventId_2.clear();
        v_Top_alpha_2.clear();
        v_Top_alpha2_2.clear();
        v_Top_alpha3_2.clear();
        v_Top_alpha4_2.clear();
        v_Top_JetPT_2.clear();
        v_Top_JetEta_2.clear();
        v_Top_Jethadronflavor_2.clear();
        v_Top_Jetpartonflavor_2.clear();
        v_Top_JetnTracks_2.clear();
        v_Top_2DIP_2.clear();
        v_Top_Chi3Dlog_2.clear();
        if (evt % 2 != 1)
        {
            f_Top_Met_2 = f_Top_Met;
            I_Top_weight_2 = I_Top_weight;
            I_Top_nJets_2 = I_Top_nJets;
            //cout << "evt = " << evt << endl;
            for (size_t i = 0; i < v_Top_2DIP->size(); i++)
            {
                v_Top_2DIP_2.push_back((*v_Top_2DIP)[i]);
                v_Top_Chi3Dlog_2.push_back((*v_Top_Chi3Dlog)[i]);
            }
            for (size_t i = 0; i < v_Top_JetPT->size(); i++)
            {
                v_Top_eventId_2.push_back(evt);
                v_Top_Jethadronflavor_2.push_back((*v_Top_Jethadronflavor)[i]);
                v_Top_Jetpartonflavor_2.push_back((*v_Top_Jetpartonflavor)[i]);
                v_Top_JetPT_2.push_back((*v_Top_JetPT)[i]);
                v_Top_alpha_2.push_back((*v_Top_alpha)[i]);
                v_Top_alpha2_2.push_back((*v_Top_alpha2)[i]);
                v_Top_alpha3_2.push_back((*v_Top_alpha3)[i]);
                v_Top_alpha4_2.push_back((*v_Top_alpha4)[i]);
                v_Top_JetnTracks_2.push_back((*v_Top_JetnTracks)[i]);
                v_Top_JetEta_2.push_back((*v_Top_JetEta)[i]);
            }
            h2->Fill();
        }
    }
    outfile_Top_2->cd();
    h2->Write();
    outfile_Top_2->Close();
    cout << T_tree->GetEntries() << endl;
    Top_sample->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_Top_half();
    }
    else if (argc == 4)
    {
        ee_Top_half(argv[1], argv[2], argv[3]);
    }
    else
    {
        cout << "ERROR" << endl;
    }
}