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
void ee_Diboson_half(TString inputfile = "./../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root", TString outputfile1 = "./DYDiboson_1.root", TString outputfile2 = "./DYDiboson_2.root")
{
    // int nthreads = 8;
    // ROOT::EnableImplicitMT(nthreads);

    TFile *Diboson_sample = TFile::Open(inputfile);

    float_t f_Diboson_Met, f_Diboson_Met_1, f_Diboson_Met_2;

    Int_t I_Diboson_weight, I_Diboson_weight_1, I_Diboson_weight_2;

    Int_t I_Diboson_nJets, I_Diboson_nJets_1, I_Diboson_nJets_2;

    vector<float> *v_Diboson_alpha = new vector<float>();
    vector<float> *v_Diboson_alpha2 = new vector<float>();
    vector<float> *v_Diboson_alpha3 = new vector<float>();
    vector<float> *v_Diboson_alpha4 = new vector<float>();

    v_Diboson_alpha->clear();
    v_Diboson_alpha2->clear();
    v_Diboson_alpha3->clear();
    v_Diboson_alpha4->clear();

    vector<float> v_Diboson_alpha_1;
    vector<float> v_Diboson_alpha_2;

    vector<float> v_Diboson_alpha2_1;
    vector<float> v_Diboson_alpha2_2;

    vector<float> v_Diboson_alpha3_1;
    vector<float> v_Diboson_alpha3_2;

    vector<float> v_Diboson_alpha4_1;
    vector<float> v_Diboson_alpha4_2;

    vector<float> *v_Diboson_JetPT = new vector<float>();

    v_Diboson_JetPT->clear();

    vector<float> v_Diboson_JetPT_1;
    vector<float> v_Diboson_JetPT_2;

    vector<float> *v_Diboson_JetEta = new vector<float>();

    v_Diboson_JetEta->clear();

    vector<float> v_Diboson_JetEta_1;
    vector<float> v_Diboson_JetEta_2;

    vector<int> *v_Diboson_Jethadronflavor = new vector<int>();

    v_Diboson_Jethadronflavor->clear();

    vector<int> *v_Diboson_Jetpartonflavor = new vector<int>();

    v_Diboson_Jetpartonflavor->clear();

    vector<int> v_Diboson_Jethadronflavor_1;
    vector<int> v_Diboson_Jethadronflavor_2;

    vector<int> v_Diboson_Jetpartonflavor_1;
    vector<int> v_Diboson_Jetpartonflavor_2;

    vector<int> *v_Diboson_JetnTracks = new vector<int>();

    v_Diboson_JetnTracks->clear();

    vector<int> v_Diboson_JetnTracks_1;
    vector<int> v_Diboson_JetnTracks_2;

    vector<float> *v_Diboson_2DIP = new vector<float>();
    v_Diboson_2DIP->clear();

    vector<float> v_Diboson_2DIP_1;
    vector<float> v_Diboson_2DIP_2;

    vector<float> *v_Diboson_Chi3Dlog = new vector<float>();
    v_Diboson_Chi3Dlog->clear();

    vector<float> v_Diboson_Chi3Dlog_1;
    vector<float> v_Diboson_Chi3Dlog_2;

    vector<float> v_Diboson_eventId_1;
    vector<float> v_Diboson_eventId_2;

    TTree *T_tree;
    Diboson_sample->GetObject("T_tree", T_tree);
    T_tree->SetBranchAddress("I_weight", &I_Diboson_weight);
    T_tree->SetBranchAddress("f_Met", &f_Diboson_Met);
    T_tree->SetBranchAddress("I_nJets", &I_Diboson_nJets);
    T_tree->SetBranchAddress("v_fakeJethadronflavor", &v_Diboson_Jethadronflavor);
    T_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_Diboson_Jetpartonflavor);
    T_tree->SetBranchAddress("v_fakeJetPt", &v_Diboson_JetPT);
    T_tree->SetBranchAddress("v_fakeJetEta", &v_Diboson_JetEta);
    T_tree->SetBranchAddress("v_fakealpha", &v_Diboson_alpha);
    T_tree->SetBranchAddress("v_fakealpha2", &v_Diboson_alpha2);
    T_tree->SetBranchAddress("v_fakealpha3", &v_Diboson_alpha3);
    T_tree->SetBranchAddress("v_fakealpha4", &v_Diboson_alpha4);
    T_tree->SetBranchAddress("v_N_Tracks", &v_Diboson_JetnTracks);
    T_tree->SetBranchAddress("v_IP2D", &v_Diboson_2DIP);
    T_tree->SetBranchAddress("v_Chi3Dlog", &v_Diboson_Chi3Dlog);
    TFile *outfile_Diboson_1 = TFile::Open(outputfile1, "RECREATE");
    TTree *h1 = new TTree("h1", "");
    h1->Branch("v_eventID", &v_Diboson_eventId_1);
    h1->Branch("I_weight", &I_Diboson_weight_1);
    h1->Branch("f_Met", &f_Diboson_Met_1);
    h1->Branch("I_nJets", &I_Diboson_nJets_1);
    h1->Branch("v_fakeJethadronflavor", &v_Diboson_Jethadronflavor_1);
    h1->Branch("v_fakeJetpartonflavor", &v_Diboson_Jetpartonflavor_1);
    h1->Branch("v_fakeJetPt", &v_Diboson_JetPT_1);
    h1->Branch("v_fakeJetEta", &v_Diboson_JetEta_1);
    h1->Branch("v_fakealpha", &v_Diboson_alpha_1);
    h1->Branch("v_fakealpha2", &v_Diboson_alpha2_1);
    h1->Branch("v_fakealpha3", &v_Diboson_alpha3_1);
    h1->Branch("v_fakealpha4", &v_Diboson_alpha4_1);
    h1->Branch("v_N_Tracks", &v_Diboson_JetnTracks_1);
    h1->Branch("v_IP2D", &v_Diboson_2DIP_1);
    h1->Branch("v_Chi3Dlog", &v_Diboson_Chi3Dlog_1);
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
            v_Diboson_eventId_1.clear();
            v_Diboson_alpha_1.clear();
            v_Diboson_alpha2_1.clear();
            v_Diboson_alpha3_1.clear();
            v_Diboson_alpha4_1.clear();
            v_Diboson_JetPT_1.clear();
            v_Diboson_JetEta_1.clear();
            v_Diboson_Jethadronflavor_1.clear();
            v_Diboson_Jetpartonflavor_1.clear();
            v_Diboson_JetnTracks_1.clear();
            v_Diboson_2DIP_1.clear();
            v_Diboson_Chi3Dlog_1.clear();
            f_Diboson_Met_1 = f_Diboson_Met;
            I_Diboson_weight_1 = I_Diboson_weight;
            I_Diboson_nJets_1 = I_Diboson_nJets;
            for (size_t i = 0; i < v_Diboson_2DIP->size(); i++)
            {
                v_Diboson_2DIP_1.push_back((*v_Diboson_2DIP)[i]);
                v_Diboson_Chi3Dlog_1.push_back((*v_Diboson_Chi3Dlog)[i]);
            }
            for (size_t i = 0; i < v_Diboson_Jethadronflavor->size(); i++)
            {
                v_Diboson_Jethadronflavor_1.push_back((*v_Diboson_Jethadronflavor)[i]);
            }
            //cout << "evt = " << evt << endl;
            for (size_t i = 0; i < v_Diboson_JetEta->size(); i++)
            {
                v_Diboson_JetEta_1.push_back((*v_Diboson_JetEta)[i]);
            }
            for (size_t i = 0; i < v_Diboson_JetPT->size(); i++)
            {
                v_Diboson_eventId_1.push_back(evt);
                v_Diboson_Jetpartonflavor_1.push_back((*v_Diboson_Jetpartonflavor)[i]);
                v_Diboson_JetPT_1.push_back((*v_Diboson_JetPT)[i]);
                v_Diboson_alpha_1.push_back((*v_Diboson_alpha)[i]);
                v_Diboson_alpha2_1.push_back((*v_Diboson_alpha2)[i]);
                v_Diboson_alpha3_1.push_back((*v_Diboson_alpha3)[i]);
                v_Diboson_alpha4_1.push_back((*v_Diboson_alpha4)[i]);
                v_Diboson_JetnTracks_1.push_back((*v_Diboson_JetnTracks)[i]);
            }
            h1->Fill();
        }
    }
    //outfile_Diboson_1->cd();
    h1->Write();
    outfile_Diboson_1->Close();
    TFile *outfile_Diboson_2 = TFile::Open(outputfile2, "RECREATE");
    TTree *h2 = new TTree("h2", "h2");
    h2->Branch("v_eventID", &v_Diboson_eventId_2);
    h2->Branch("f_Met", &f_Diboson_Met_2);
    h2->Branch("I_nJets", &I_Diboson_nJets_2);
    h2->Branch("I_weight", &I_Diboson_weight_2);
    h2->Branch("v_fakeJethadronflavor", &v_Diboson_Jethadronflavor_2);
    h2->Branch("v_fakeJetpartonflavor", &v_Diboson_Jetpartonflavor_2);
    h2->Branch("v_fakeJetPt", &v_Diboson_JetPT_2);
    h2->Branch("v_fakeJetEta", &v_Diboson_JetEta_2);
    h2->Branch("v_fakealpha", &v_Diboson_alpha_2);
    h2->Branch("v_fakealpha2", &v_Diboson_alpha2_2);
    h2->Branch("v_fakealpha3", &v_Diboson_alpha3_2);
    h2->Branch("v_fakealpha4", &v_Diboson_alpha4_2);
    h2->Branch("v_N_Tracks", &v_Diboson_JetnTracks_2);
    h2->Branch("v_IP2D", &v_Diboson_2DIP_2);
    h2->Branch("v_Chi3Dlog", &v_Diboson_Chi3Dlog_2);
    for (int evt = 0; evt < T_tree->GetEntries(); evt++)
    {
        T_tree->GetEntry(evt);
        v_Diboson_eventId_2.clear();
        v_Diboson_alpha_2.clear();
        v_Diboson_alpha2_2.clear();
        v_Diboson_alpha3_2.clear();
        v_Diboson_alpha4_2.clear();
        v_Diboson_JetPT_2.clear();
        v_Diboson_JetEta_2.clear();
        v_Diboson_Jethadronflavor_2.clear();
        v_Diboson_Jetpartonflavor_2.clear();
        v_Diboson_JetnTracks_2.clear();
        v_Diboson_2DIP_2.clear();
        v_Diboson_Chi3Dlog_2.clear();
        if (evt % 2 != 1)
        {
            f_Diboson_Met_2 = f_Diboson_Met;
            I_Diboson_weight_2 = I_Diboson_weight;
            I_Diboson_nJets_2 = I_Diboson_nJets;
            //cout << "evt = " << evt << endl;
            for (size_t i = 0; i < v_Diboson_2DIP->size(); i++)
            {
                v_Diboson_2DIP_2.push_back((*v_Diboson_2DIP)[i]);
                v_Diboson_Chi3Dlog_2.push_back((*v_Diboson_Chi3Dlog)[i]);
            }
            for (size_t i = 0; i < v_Diboson_JetPT->size(); i++)
            {
                v_Diboson_eventId_2.push_back(evt);
                v_Diboson_Jethadronflavor_2.push_back((*v_Diboson_Jethadronflavor)[i]);
                v_Diboson_Jetpartonflavor_2.push_back((*v_Diboson_Jetpartonflavor)[i]);
                v_Diboson_JetPT_2.push_back((*v_Diboson_JetPT)[i]);
                v_Diboson_alpha_2.push_back((*v_Diboson_alpha)[i]);
                v_Diboson_alpha2_2.push_back((*v_Diboson_alpha2)[i]);
                v_Diboson_alpha3_2.push_back((*v_Diboson_alpha3)[i]);
                v_Diboson_alpha4_2.push_back((*v_Diboson_alpha4)[i]);
                v_Diboson_JetnTracks_2.push_back((*v_Diboson_JetnTracks)[i]);
                v_Diboson_JetEta_2.push_back((*v_Diboson_JetEta)[i]);
            }
            h2->Fill();
        }
    }
    outfile_Diboson_2->cd();
    h2->Write();
    outfile_Diboson_2->Close();
    cout << T_tree->GetEntries() << endl;
    Diboson_sample->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_Diboson_half();
    }
    else if (argc == 4)
    {
        ee_Diboson_half(argv[1], argv[2], argv[3]);
    }
    else
    {
        cout << "ERROR" << endl;
    }
}