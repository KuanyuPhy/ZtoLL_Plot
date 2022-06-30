#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <string>
#include <TCanvas.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../../lib/Cross_section.h"
//#include "./../../../lib/diff_region.C"
using namespace std;

void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, float Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, float flavor2, float hadronflavor, float tmp, float Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

void ee_Sig_produce(TString inputfile = "/home/kuanyu/Documents/root_file/Ztoee/Mx2_1.root", TString outputfile1 = "./ee_Sig_emjet.root")
{
    TFile *Sig_Mx2_1 = TFile::Open(inputfile);
    TFile *Sig_Mx2_50 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/Mx2_50.root");
    TFile *Sig_Mx2_150 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/Mx2_150.root");

    TH1D *h_Sig1_Chi3Dlog = new TH1D("h_Sig1_Chi3Dlog", "", 100, -10, 10);
    h_Sig1_Chi3Dlog->GetXaxis()->SetTitle("");
    h_Sig1_Chi3Dlog->GetYaxis()->SetTitle("");
    h_Sig1_Chi3Dlog->Sumw2();

    TH1D *h_Sig50_Chi3Dlog = new TH1D("h_Sig50_Chi3Dlog", "", 100, -10, 10);
    h_Sig50_Chi3Dlog->GetXaxis()->SetTitle("");
    h_Sig50_Chi3Dlog->GetYaxis()->SetTitle("");
    h_Sig50_Chi3Dlog->Sumw2();

    TH1D *h_Sig150_Chi3Dlog = new TH1D("h_Sig150_Chi3Dlog", "", 100, -10, 10);
    h_Sig150_Chi3Dlog->GetXaxis()->SetTitle("");
    h_Sig150_Chi3Dlog->GetYaxis()->SetTitle("");
    h_Sig150_Chi3Dlog->Sumw2();

    TH1D *h_Sig1_IP2D = new TH1D("h_Sig1_IP2D", "", 200, -20, 20);
    h_Sig1_IP2D->GetXaxis()->SetTitle("");
    h_Sig1_IP2D->GetYaxis()->SetTitle("");
    h_Sig1_IP2D->Sumw2();

    TH1D *h_Sig50_IP2D = new TH1D("h_Sig50_IP2D", "", 200, -20, 20);
    h_Sig50_IP2D->GetXaxis()->SetTitle("");
    h_Sig50_IP2D->GetYaxis()->SetTitle("");
    h_Sig50_IP2D->Sumw2();

    TH1D *h_Sig150_IP2D = new TH1D("h_Sig150_IP2D", "", 200, -20, 20);
    h_Sig150_IP2D->GetXaxis()->SetTitle("");
    h_Sig150_IP2D->GetYaxis()->SetTitle("");
    h_Sig150_IP2D->Sumw2();

    TH1D *h_Sig1_Met = new TH1D("h_Sig1_Met", "", 50, 0, 500);
    h_Sig1_Met->GetXaxis()->SetTitle("");
    h_Sig1_Met->GetYaxis()->SetTitle("");
    h_Sig1_Met->Sumw2();

    TH1D *h_Sig50_Met = new TH1D("h_Sig50_Met", "", 50, 0, 500);
    h_Sig50_Met->GetXaxis()->SetTitle("");
    h_Sig50_Met->GetYaxis()->SetTitle("");
    h_Sig50_Met->Sumw2();

    TH1D *h_Sig150_Met = new TH1D("h_Sig150_Met", "", 50, 0, 500);
    h_Sig150_Met->GetXaxis()->SetTitle("");
    h_Sig150_Met->GetYaxis()->SetTitle("");
    h_Sig150_Met->Sumw2();

    Int_t I_Mx2_1_nThinJets;
    Int_t I_Mx2_50_nThinJets;
    Int_t I_Mx2_150_nThinJets;

    Int_t I_Mx2_1_weight;
    Int_t I_Mx2_50_weight;
    Int_t I_Mx2_150_weight;

    float f_Mx2_1_met;
    float f_Mx2_50_met;
    float f_Mx2_150_met;

    vector<float> *v_Mx2_1_Chi3Dlog = new vector<float>();
    vector<float> *v_Mx2_50_Chi3Dlog = new vector<float>();
    vector<float> *v_Mx2_150_Chi3Dlog = new vector<float>();

    vector<float> *v_Mx2_1_2DIP = new vector<float>();
    vector<float> *v_Mx2_50_2DIP = new vector<float>();
    vector<float> *v_Mx2_150_2DIP = new vector<float>();

    vector<float> *v_Mx2_1_nTrack = new vector<float>();
    vector<float> *v_Mx2_50_nTrack = new vector<float>();
    vector<float> *v_Mx2_150_nTrack = new vector<float>();

    vector<float> *v_Mx2_1_Jethadronflavor = new vector<float>();
    vector<float> *v_Mx2_50_Jethadronflavor = new vector<float>();
    vector<float> *v_Mx2_150_Jethadronflavor = new vector<float>();

    vector<float> *v_Mx2_1_Jetpartonflavor = new vector<float>();
    vector<float> *v_Mx2_50_Jetpartonflavor = new vector<float>();
    vector<float> *v_Mx2_150_Jetpartonflavor = new vector<float>();

    vector<float> *v_Mx2_1_JetPT = new vector<float>();
    vector<float> *v_Mx2_50_JetPT = new vector<float>();
    vector<float> *v_Mx2_150_JetPT = new vector<float>();

    vector<float> *v_Mx2_1_JetEta = new vector<float>();
    vector<float> *v_Mx2_50_JetEta = new vector<float>();
    vector<float> *v_Mx2_150_JetEta = new vector<float>();

    v_Mx2_1_Chi3Dlog->clear();
    v_Mx2_50_Chi3Dlog->clear();
    v_Mx2_150_Chi3Dlog->clear();

    v_Mx2_1_2DIP->clear();
    v_Mx2_50_2DIP->clear();
    v_Mx2_150_2DIP->clear();

    v_Mx2_1_nTrack->clear();
    v_Mx2_50_nTrack->clear();
    v_Mx2_150_nTrack->clear();

    v_Mx2_1_Jethadronflavor->clear();
    v_Mx2_50_Jethadronflavor->clear();
    v_Mx2_150_Jethadronflavor->clear();

    v_Mx2_1_Jetpartonflavor->clear();
    v_Mx2_50_Jetpartonflavor->clear();
    v_Mx2_150_Jetpartonflavor->clear();

    v_Mx2_1_JetPT->clear();
    v_Mx2_50_JetPT->clear();
    v_Mx2_150_JetPT->clear();

    v_Mx2_1_JetEta->clear();
    v_Mx2_50_JetEta->clear();
    v_Mx2_150_JetEta->clear();

    TTree *T_Mx2_1_tree;
    Sig_Mx2_1->GetObject("T_tree", T_Mx2_1_tree);
    T_Mx2_1_tree->SetBranchAddress("I_weight", &I_Mx2_1_weight);
    T_Mx2_1_tree->SetBranchAddress("f_Met", &f_Mx2_1_met);
    T_Mx2_1_tree->SetBranchAddress("I_nThinJets", &I_Mx2_1_nThinJets);
    T_Mx2_1_tree->SetBranchAddress("v_N_Tracks", &v_Mx2_1_nTrack);
    T_Mx2_1_tree->SetBranchAddress("v_IP2D", &v_Mx2_1_2DIP);
    T_Mx2_1_tree->SetBranchAddress("v_Chi3Dlog", &v_Mx2_1_Chi3Dlog);
    T_Mx2_1_tree->SetBranchAddress("v_fakeJethadronflavor", &v_Mx2_1_Jethadronflavor);
    T_Mx2_1_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_Mx2_1_Jetpartonflavor);
    T_Mx2_1_tree->SetBranchAddress("v_fakeJetPt", &v_Mx2_1_JetPT);
    T_Mx2_1_tree->SetBranchAddress("v_fakeJetEta", &v_Mx2_1_JetEta);
    for (int evt = 0; evt < T_Mx2_1_tree->GetEntries(); evt++)
    {
        T_Mx2_1_tree->GetEntry(evt);
        h_Sig1_Met->Fill(f_Mx2_1_met, I_Mx2_1_weight);
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_Mx2_1_Chi3Dlog->size(); i++)
        {
            h_Sig1_Chi3Dlog->Fill((*v_Mx2_1_Chi3Dlog)[i], I_Mx2_1_weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_Mx2_1_2DIP->size(); i++)
        {
            h_Sig1_IP2D->Fill(log10(abs((*v_Mx2_1_2DIP)[i])), I_Mx2_1_weight);
        }
    }

    TTree *T_Mx2_50_tree;
    Sig_Mx2_50->GetObject("T_tree", T_Mx2_50_tree);
    T_Mx2_50_tree->SetBranchAddress("I_weight", &I_Mx2_50_weight);
    T_Mx2_50_tree->SetBranchAddress("f_Met", &f_Mx2_50_met);
    T_Mx2_50_tree->SetBranchAddress("I_nThinJets", &I_Mx2_50_nThinJets);
    T_Mx2_50_tree->SetBranchAddress("v_N_Tracks", &v_Mx2_50_nTrack);
    T_Mx2_50_tree->SetBranchAddress("v_IP2D", &v_Mx2_50_2DIP);
    T_Mx2_50_tree->SetBranchAddress("v_Chi3Dlog", &v_Mx2_50_Chi3Dlog);
    T_Mx2_50_tree->SetBranchAddress("v_fakeJethadronflavor", &v_Mx2_50_Jethadronflavor);
    T_Mx2_50_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_Mx2_50_Jetpartonflavor);
    T_Mx2_50_tree->SetBranchAddress("v_fakeJetPt", &v_Mx2_50_JetPT);
    T_Mx2_50_tree->SetBranchAddress("v_fakeJetEta", &v_Mx2_50_JetEta);
    for (int evt = 0; evt < T_Mx2_50_tree->GetEntries(); evt++)
    {
        T_Mx2_50_tree->GetEntry(evt);
        h_Sig50_Met->Fill(f_Mx2_50_met, I_Mx2_50_weight);
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_Mx2_50_Chi3Dlog->size(); i++)
        {
            h_Sig50_Chi3Dlog->Fill((*v_Mx2_50_Chi3Dlog)[i], I_Mx2_50_weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_Mx2_50_2DIP->size(); i++)
        {
            h_Sig50_IP2D->Fill(log10(abs((*v_Mx2_50_2DIP)[i])), I_Mx2_50_weight);
        }
    }
    TTree *T_Mx2_150_tree;
    Sig_Mx2_150->GetObject("T_tree", T_Mx2_150_tree);
    T_Mx2_150_tree->SetBranchAddress("I_weight", &I_Mx2_150_weight);
    T_Mx2_150_tree->SetBranchAddress("f_Met", &f_Mx2_150_met);
    T_Mx2_150_tree->SetBranchAddress("I_nThinJets", &I_Mx2_150_nThinJets);
    T_Mx2_150_tree->SetBranchAddress("v_N_Tracks", &v_Mx2_150_nTrack);
    T_Mx2_150_tree->SetBranchAddress("v_IP2D", &v_Mx2_150_2DIP);
    T_Mx2_150_tree->SetBranchAddress("v_Chi3Dlog", &v_Mx2_150_Chi3Dlog);
    T_Mx2_150_tree->SetBranchAddress("v_fakeJethadronflavor", &v_Mx2_150_Jethadronflavor);
    T_Mx2_150_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_Mx2_150_Jetpartonflavor);
    T_Mx2_150_tree->SetBranchAddress("v_fakeJetPt", &v_Mx2_150_JetPT);
    T_Mx2_150_tree->SetBranchAddress("v_fakeJetEta", &v_Mx2_150_JetEta);
    for (int evt = 0; evt < T_Mx2_150_tree->GetEntries(); evt++)
    {
        T_Mx2_150_tree->GetEntry(evt);
        h_Sig150_Met->Fill(f_Mx2_150_met, I_Mx2_150_weight);
        //----------
        //  3DSig
        //----------
        for (size_t i = 0; i < v_Mx2_150_Chi3Dlog->size(); i++)
        {
            h_Sig150_Chi3Dlog->Fill((*v_Mx2_150_Chi3Dlog)[i], I_Mx2_150_weight);
        }
        //-----------------
        //  2D IP
        //-----------------
        for (size_t i = 0; i < v_Mx2_150_2DIP->size(); i++)
        {
            h_Sig150_IP2D->Fill(log10(abs((*v_Mx2_150_2DIP)[i])), I_Mx2_150_weight);
        }
    }
    h_Sig150_IP2D->SetLineWidth(2);
    h_Sig150_IP2D->Draw();
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Sig1_IP2D->Write();
    h_Sig1_Chi3Dlog->Write();
    h_Sig50_IP2D->Write();
    h_Sig50_Chi3Dlog->Write();
    h_Sig150_IP2D->Write();
    h_Sig150_Chi3Dlog->Write();
    h_Sig1_Met->Write();
    h_Sig50_Met->Write();
    h_Sig150_Met->Write();
    
    outfile_HT0->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_Sig_produce();
    }
    else if (argc == 3)
    {
        ee_Sig_produce(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}