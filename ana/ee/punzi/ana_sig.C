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

using namespace std;
void ana_sig()
{
    TFile *Mx2_1 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/Mx2_1_old_remove_0alpha.root");
    TFile *Mx2_50 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/Mx2_50_old_remove_0alpha.root");
    TFile *Mx2_150 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/Mx2_150_old_remove_0alpha.root");

    TH1D *h_pass_Mx2_1 = new TH1D("h_pass_Mx2_1", "", 50, 0, 50);
    h_pass_Mx2_1->Sumw2();

    TH1D *h_pass_Mx2_1_nMetcut = new TH1D("h_pass_Mx2_1_nMetcut", "", 50, 0, 50);
    h_pass_Mx2_1_nMetcut->Sumw2();

    TH1D *h_pass_Mx2_50 = new TH1D("h_pass_Mx2_50", "", 50, 0, 50);
    h_pass_Mx2_50->Sumw2();

    TH1D *h_pass_Mx2_50_nMetcut = new TH1D("h_pass_Mx2_50_nMetcut", "", 50, 0, 50);
    h_pass_Mx2_50_nMetcut->Sumw2();

    TH1D *h_pass_Mx2_150 = new TH1D("h_pass_Mx2_150", "", 50, 0, 50);
    h_pass_Mx2_150->Sumw2();

    TH1D *h_pass_Mx2_150_nMetcut = new TH1D("h_pass_Mx2_150_nMetcut", "", 50, 0, 50);
    h_pass_Mx2_150_nMetcut->Sumw2();

    TH1D *h_Mx2_1_Met = new TH1D("h_Mx2_1_Met", "", 50, 0, 500);
    h_Mx2_1_Met->Sumw2();

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;

    float_t f_Mx1_Met, f_Mx50_Met, f_Mx150_Met;

    Int_t I_Mx1_nThinJets, I_Mx50_nThinJets, I_Mx150_nThinJets;

    vector<float> *v_Mx1_alpha = new vector<float>();
    vector<float> *v_Mx50_alpha = new vector<float>();
    vector<float> *v_Mx150_alpha = new vector<float>();

    v_Mx1_alpha->clear();
    v_Mx50_alpha->clear();
    v_Mx150_alpha->clear();

    for (int i = 1; i <= 50; i++)
    {
        float metcut = i * 10;

        TTree *T_Mx2_1;
        Mx2_1->GetObject("T_tree", T_Mx2_1);
        T_Mx2_1->SetBranchAddress("I_weight", &I_Mx1_weight);
        T_Mx2_1->SetBranchAddress("f_Met", &f_Mx1_Met);
        T_Mx2_1->SetBranchAddress("v_fakealpha", &v_Mx1_alpha);
        for (int evt = 0; evt < T_Mx2_1->GetEntries(); evt++)
        {
            T_Mx2_1->GetEntry(evt);
            bool alpha_cut = true;
            for (int i = 0; i < v_Mx1_alpha->size(); i++)
            {
                if ((*v_Mx1_alpha)[i] > 0.15)
                {
                    alpha_cut = false;
                    break;
                }
            }
            if (!alpha_cut)
            {
                continue;
            }
            //-------------------
            // Scan Met
            //-------------------
            // h_Mx2_1_Met->Fill(f_Mx1_Met);
            h_pass_Mx2_1->Fill(i);
            // cout << "Met cut"<<i*10<<endl;
            if (f_Mx1_Met > metcut)
            {
                // cout << "metcut = " << metcut << endl;
                // cout << "Met = " << f_Mx1_Met << endl;
                h_pass_Mx2_1_nMetcut->Fill(i);
            }
            else
            {
                continue;
            }
        } // End of Mx2_1 Entries loop
        TTree *T_Mx2_50;
        Mx2_50->GetObject("T_tree", T_Mx2_50);
        T_Mx2_50->SetBranchAddress("I_weight", &I_Mx50_weight);
        T_Mx2_50->SetBranchAddress("f_Met", &f_Mx50_Met);
        T_Mx2_50->SetBranchAddress("v_fakealpha", &v_Mx50_alpha);
        for (int evt = 0; evt < T_Mx2_50->GetEntries(); evt++)
        {
            T_Mx2_50->GetEntry(evt);
            bool alpha_cut = true;
            for (int i = 0; i < v_Mx50_alpha->size(); i++)
            {
                if ((*v_Mx50_alpha)[i] > 0.15)
                {
                    alpha_cut = false;
                    break;
                }
            }
            if (!alpha_cut)
            {
                continue;
            }
            //-------------------
            // Scan Met
            //-------------------
            // h_Mx2_1_Met->Fill(f_Mx50_Met);
            h_pass_Mx2_50->Fill(i);
            // cout << "Met cut"<<i*10<<endl;
            if (f_Mx50_Met > metcut)
            {
                // cout << "metcut = " << metcut << endl;
                // cout << "Met = " << f_Mx1_Met << endl;
                h_pass_Mx2_50_nMetcut->Fill(i);
            }
            else
            {
                continue;
            }
        } // End of Mx2_50 Entries loop
        TTree *T_Mx2_150;
        Mx2_150->GetObject("T_tree", T_Mx2_150);
        T_Mx2_150->SetBranchAddress("I_weight", &I_Mx150_weight);
        T_Mx2_150->SetBranchAddress("f_Met", &f_Mx150_Met);
        T_Mx2_150->SetBranchAddress("v_fakealpha", &v_Mx150_alpha);
        for (int evt = 0; evt < T_Mx2_150->GetEntries(); evt++)
        {
            T_Mx2_150->GetEntry(evt);
            // cout << "eee"<< endl;
            bool alpha_cut = true;
            for (int i = 0; i < v_Mx150_alpha->size(); i++)
            {
                if ((*v_Mx150_alpha)[i] > 0.15)
                {
                    alpha_cut = false;
                    break;
                }
            }
            if (!alpha_cut)
            {
                continue;
            }
            //-------------------
            // Scan Met
            //-------------------
            h_Mx2_1_Met->Fill(f_Mx150_Met);
            h_pass_Mx2_150->Fill(i);
            // cout << "Met cut"<<i*10<<endl;
            if (f_Mx150_Met > metcut)
            {
                // cout << "metcut = " << metcut << endl;
                // cout << "Met = " << f_Mx1_Met << endl;
                h_pass_Mx2_150_nMetcut->Fill(i);
            }
            else
            {
                continue;
            }
        } // End of Mx2_150 Entries loop
    }     // End of 50 loops
    // h_Mx2_1_Met->Draw();

    TH1D *h_Mx2_1_eff = (TH1D *)h_pass_Mx2_1_nMetcut->Clone("h_Mx2_1_eff");
    h_Mx2_1_eff->Divide(h_pass_Mx2_1_nMetcut, h_pass_Mx2_1, 1, 1);

    TH1D *h_Mx2_50_eff = (TH1D *)h_pass_Mx2_50_nMetcut->Clone("h_Mx2_50_eff");
    h_Mx2_50_eff->Divide(h_pass_Mx2_50_nMetcut, h_pass_Mx2_50, 1, 1);

    TH1D *h_Mx2_150_eff = (TH1D *)h_pass_Mx2_150_nMetcut->Clone("h_Mx2_150_eff");
    h_Mx2_150_eff->Divide(h_pass_Mx2_150_nMetcut, h_pass_Mx2_150, 1, 1);
    
    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(3, 1);
    c1->cd(1);
    h_Mx2_1_eff->Draw("text45");
    c1->cd(2);
    h_Mx2_50_eff->Draw("text45");
    c1->cd(3);
    h_Mx2_150_eff->Draw("text45");
    
    TString outputfile1 = "./ee_Sig_punzi.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Mx2_1_eff->Write();
    h_Mx2_50_eff->Write();
    h_Mx2_150_eff->Write();
    outfile_HT0->Close();
}