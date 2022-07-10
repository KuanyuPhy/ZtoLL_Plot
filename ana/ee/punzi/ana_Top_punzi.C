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
#include "./../../lib/Cross_section.h"
using namespace std;

TFile *TTTo2L2Nufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
TFile *Top_TTWJetsToLNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
TFile *Top_TTWJetsToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
TFile *Top_TTZToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
TFile *Top_TTZToLLNuNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
TFile *Top_tW_antitopfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
TFile *Top_tW_topfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

TH1D *TTTo2L2Nu_sumevt = ((TH1D *)TTTo2L2Nufile->Get("Event_Variable/h_totevent"));
TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNufile->Get("Event_Variable/h_totevent"));
TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQfile->Get("Event_Variable/h_totevent"));
TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQfile->Get("Event_Variable/h_totevent"));
TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNufile->Get("Event_Variable/h_totevent"));
TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitopfile->Get("Event_Variable/h_totevent"));
TH1D *tW_top_sumevt = ((TH1D *)Top_tW_topfile->Get("Event_Variable/h_totevent"));

int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();
int TTWJetsToLNu_totevt = TTWJetsToLNu_sumevt->Integral();
int TTWJetsToQQ_totevt = TTWJetsToQQ_sumevt->Integral();
int TTZToQQ_totevt = TTZToQQ_sumevt->Integral();
int TTZToLLNuNu_totevt = TTZToLLNuNu_sumevt->Integral();
int tW_antitop_totevt = tW_antitop_sumevt->Integral();
int tW_top_totevt = tW_top_sumevt->Integral();
//---------------------
// Define the Top_Weight
//---------------------
double TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * ((GlobalConstants::TTTo2L2Nu) / (TTTo2L2Nu_totevt)) * 1000;
double ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000;
double ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000;
double TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000;
double TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000;
double TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000;
double TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000;

void ana_Top_punzi(const char *scanMet_step = "tmp", TString outputfile = "./output/tmp.root")
{

    //---------------------
    // Met cut
    //---------------------
    float metcut = atoi(scanMet_step) * 10;
    cout << "metcut" << metcut << endl;

    TH1D *h_pass_Bg_nMetcut = new TH1D("h_pass_Bg_nMetcut", "", 50, 0, 50);
    h_pass_Bg_nMetcut->Sumw2();

    Int_t I_TTTo2L2Nu_weight;
    Int_t I_ST_tW_top_weight;
    Int_t I_ST_tW_antitop_weight;
    Int_t I_TTWJetsToLNu_weight;
    Int_t I_TTWJetsToQQ_weight;
    Int_t I_TTZToQQ_weight;
    Int_t I_TTZToLLNuNu_weight;

    float_t f_TTTo2L2Nu_met;
    float_t f_ST_tW_top_met;
    float_t f_ST_tW_antitop_met;
    float_t f_TTWJetsToLNu_met;
    float_t f_TTWJetsToQQ_met;
    float_t f_TTZToQQ_met;
    float_t f_TTZToLLNuNu_met;

    vector<float> *v_TTTo2L2Nu_alpha = new vector<float>();
    vector<float> *v_ST_tW_top_alpha = new vector<float>();
    vector<float> *v_ST_tW_antitop_alpha = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha = new vector<float>();
    vector<float> *v_TTWJetsToQQ_alpha = new vector<float>();
    vector<float> *v_TTZToQQ_alpha = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha = new vector<float>();

    v_TTTo2L2Nu_alpha->clear();
    v_ST_tW_top_alpha->clear();
    v_ST_tW_antitop_alpha->clear();
    v_TTWJetsToLNu_alpha->clear();
    v_TTWJetsToQQ_alpha->clear();
    v_TTZToQQ_alpha->clear();
    v_TTZToLLNuNu_alpha->clear();

    TTree *T_TTTo2L2Nu_tree;
    TTTo2L2Nufile->GetObject("T_tree", T_TTTo2L2Nu_tree);
    T_TTTo2L2Nu_tree->SetBranchAddress("I_weight", &I_TTTo2L2Nu_weight);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha", &v_TTTo2L2Nu_alpha);
    for (int evt = 0; evt < T_TTTo2L2Nu_tree->GetEntries(); evt++)
    {
        T_TTTo2L2Nu_tree->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_TTTo2L2Nu_alpha->size(); i++)
        {
            if ((*v_TTTo2L2Nu_alpha)[i] > 0.15)
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
        if (f_TTTo2L2Nu_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        }
    }
    TTree *T_ST_tW_top_tree;
    Top_tW_topfile->GetObject("T_tree", T_ST_tW_top_tree);
    T_ST_tW_top_tree->SetBranchAddress("I_weight", &I_ST_tW_top_weight);
    T_ST_tW_top_tree->SetBranchAddress("f_Met", &f_ST_tW_top_met);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_top_alpha);
    for (int evt = 0; evt < T_ST_tW_top_tree->GetEntries(); evt++)
    {
        T_ST_tW_top_tree->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_ST_tW_top_alpha->size(); i++)
        {
            if ((*v_ST_tW_top_alpha)[i] > 0.15)
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
        if (f_ST_tW_top_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), I_ST_tW_top_weight * ST_tW_topWeight);
        }
    }
    TTree *T_ST_tW_antitop_tree;
    Top_tW_antitopfile->GetObject("T_tree", T_ST_tW_antitop_tree);
    T_ST_tW_antitop_tree->SetBranchAddress("I_weight", &I_ST_tW_antitop_weight);
    T_ST_tW_antitop_tree->SetBranchAddress("f_Met", &f_ST_tW_antitop_met);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_antitop_alpha);
    for (int evt = 0; evt < T_ST_tW_antitop_tree->GetEntries(); evt++)
    {
        T_ST_tW_antitop_tree->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_ST_tW_antitop_alpha->size(); i++)
        {
            if ((*v_ST_tW_antitop_alpha)[i] > 0.15)
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
        if (f_ST_tW_antitop_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), I_ST_tW_antitop_weight * ST_tW_antitopWeight);
        }
    }
    TTree *T_TTWJetsToLNu_tree;
    Top_TTWJetsToLNufile->GetObject("T_tree", T_TTWJetsToLNu_tree);
    T_TTWJetsToLNu_tree->SetBranchAddress("I_weight", &I_TTWJetsToLNu_weight);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToLNu_alpha);
    for (int evt = 0; evt < T_TTWJetsToLNu_tree->GetEntries(); evt++)
    {
        T_TTWJetsToLNu_tree->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_TTWJetsToLNu_alpha->size(); i++)
        {
            if ((*v_TTWJetsToLNu_alpha)[i] > 0.15)
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
        if (f_TTWJetsToLNu_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        }
    }
    TTree *T_TTWJetsToQQ_tree;
    Top_TTWJetsToQQfile->GetObject("T_tree", T_TTWJetsToQQ_tree);
    T_TTWJetsToQQ_tree->SetBranchAddress("I_weight", &I_TTWJetsToQQ_weight);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToQQ_alpha);
    for (int evt = 0; evt < T_TTWJetsToQQ_tree->GetEntries(); evt++)
    {
        T_TTWJetsToQQ_tree->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_TTWJetsToQQ_alpha->size(); i++)
        {
            if ((*v_TTWJetsToQQ_alpha)[i] > 0.15)
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
        if (f_TTWJetsToQQ_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        }
    }
    TTree *T_TTZToQQ_tree;
    Top_TTZToQQfile->GetObject("T_tree", T_TTZToQQ_tree);
    T_TTZToQQ_tree->SetBranchAddress("I_weight", &I_TTZToQQ_weight);
    T_TTZToQQ_tree->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTZToQQ_alpha);
    for (int evt = 0; evt < T_TTZToQQ_tree->GetEntries(); evt++)
    {
        T_TTZToQQ_tree->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_TTZToQQ_alpha->size(); i++)
        {
            if ((*v_TTZToQQ_alpha)[i] > 0.15)
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
        if (f_TTZToQQ_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), I_TTZToQQ_weight * TTZToQQWeight);
        }
    }

    TTree *T_TTZToLLNuNu_tree;
    Top_TTZToLLNuNufile->GetObject("T_tree", T_TTZToLLNuNu_tree);
    T_TTZToLLNuNu_tree->SetBranchAddress("I_weight", &I_TTZToLLNuNu_weight);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha", &v_TTZToLLNuNu_alpha);
    for (int evt = 0; evt < T_TTZToLLNuNu_tree->GetEntries(); evt++)
    {
        T_TTZToLLNuNu_tree->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_TTZToLLNuNu_alpha->size(); i++)
        {
            if ((*v_TTZToLLNuNu_alpha)[i] > 0.15)
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
        if (f_TTZToLLNuNu_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        }
    }

    TFile *outfile_HT0 = TFile::Open(outputfile, "RECREATE");
    h_pass_Bg_nMetcut->Write();
    outfile_HT0->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        ana_Top_punzi(argv[1], argv[2]);
    }
    else
    {
        cout << "ERROR" << endl;
    }
}