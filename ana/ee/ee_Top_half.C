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

    vector<float> *v_Top_alpha = new vector<float>();

    v_Top_alpha->clear();

    vector<float> v_Top_alpha_1;
    vector<float> v_Top_alpha_2;

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

    vector<int> v_Top_Jethadronflavor_1;
    vector<int> v_Top_Jethadronflavor_2;

    vector<int> *v_Top_JetnTracks = new vector<int>();

    v_Top_JetnTracks->clear();

    vector<int> v_Top_JetnTracks_1;
    vector<int> v_Top_JetnTracks_2;

    TTree *T_event;
    Top_sample->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &I_Top_weight);
    T_event->SetBranchAddress("f_Met", &f_Top_Met);
    T_event->SetBranchAddress("v_fakeJethadronflavor", &v_Top_Jethadronflavor);
    T_event->SetBranchAddress("v_fakeJetPt", &v_Top_JetPT);
    T_event->SetBranchAddress("v_fakeJetEta", &v_Top_JetEta);
    T_event->SetBranchAddress("v_fakealpha", &v_Top_alpha);
    T_event->SetBranchAddress("v_N_Tracks", &v_Top_JetnTracks);
    TFile *outfile_Top_1 = TFile::Open(outputfile1, "RECREATE");
    TTree *h1 = new TTree("h1", "h1");
    TFile *outfile_Top_2 = TFile::Open(outputfile2, "RECREATE");
    TTree *h2 = new TTree("h2", "h2");
    h1->Branch("I_weight", &I_Top_weight_1);
    h1->Branch("f_Met", &f_Top_Met_1);
    h1->Branch("v_fakeJethadronflavor", &v_Top_Jethadronflavor_1);
    h1->Branch("v_fakeJetPt", &v_Top_JetPT_1);
    h1->Branch("v_fakeJetEta", &v_Top_JetEta_1);
    h1->Branch("v_fakealpha", &v_Top_alpha_1);
    h1->Branch("v_N_Tracks", &v_Top_JetnTracks_1);
    h2->Branch("f_Met", &f_Top_Met_2);
    h2->Branch("I_weight", &I_Top_weight_2);
    h2->Branch("v_fakeJethadronflavor", &v_Top_Jethadronflavor_2);
    h2->Branch("v_fakeJetPt", &v_Top_JetPT_2);
    h2->Branch("v_fakeJetEta", &v_Top_JetEta_2);
    h2->Branch("v_fakealpha", &v_Top_alpha_2);
    h2->Branch("v_N_Tracks", &v_Top_JetnTracks_2);
    cout << T_event->GetEntries() << endl;
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    // const auto nEntries = T_event->GetEntries();
    // for (auto evt : ROOT::TSeqUL(nEntries))
    {
        v_Top_alpha_1.clear();
        v_Top_alpha_2.clear();

        v_Top_JetPT_1.clear();
        v_Top_JetPT_2.clear();

        v_Top_JetEta_1.clear();
        v_Top_JetEta_2.clear();

        v_Top_Jethadronflavor_1.clear();
        v_Top_Jethadronflavor_2.clear();

        v_Top_JetnTracks_1.clear();
        v_Top_JetnTracks_2.clear();

        if (evt % 100000 == 0)
        {
            cout << evt << endl;
            // fprintf(stderr, "Processing event %lli of %lli\n", T_event + 1, data.GetEntriesFast());
        }
        T_event->GetEntry(evt);
        if (evt % 2 == 1)
        {
            f_Top_Met_1 = f_Top_Met;
            I_Top_weight_1 = I_Top_weight;
            for (int i = 0; i < v_Top_JetPT->size(); i++)
            {
                v_Top_Jethadronflavor_1.push_back((*v_Top_Jethadronflavor)[i]);
                v_Top_JetPT_1.push_back((*v_Top_JetPT)[i]);
                v_Top_JetEta_1.push_back((*v_Top_JetEta)[i]);
                v_Top_alpha_1.push_back((*v_Top_alpha)[i]);
                v_Top_JetnTracks_1.push_back((*v_Top_JetnTracks)[i]);
                v_Top_JetEta_1.push_back((*v_Top_JetEta)[i]);
            }
            h1->Fill();
        }
        else
        {
            f_Top_Met_2 = f_Top_Met;
            I_Top_weight_2 = I_Top_weight;
            for (int i = 0; i < v_Top_JetPT->size(); i++)
            {
                v_Top_Jethadronflavor_2.push_back((*v_Top_Jethadronflavor)[i]);
                v_Top_JetPT_2.push_back((*v_Top_JetPT)[i]);
                v_Top_JetEta_2.push_back((*v_Top_JetEta)[i]);
                v_Top_alpha_2.push_back((*v_Top_alpha)[i]);
                v_Top_JetnTracks_2.push_back((*v_Top_JetnTracks)[i]);
                v_Top_JetEta_2.push_back((*v_Top_JetEta)[i]);
            }
            h2->Fill();
        }
    }
    outfile_Top_1->cd();
    h1->Write();
    outfile_Top_1->Close();
    outfile_Top_2->cd();
    h2->Write();
    outfile_Top_2->Close();
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