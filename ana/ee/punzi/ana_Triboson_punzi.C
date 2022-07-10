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

TFile *triboson_WWZfile = TFile::Open("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/triboson/triboson_WWZ.root");
TFile *triboson_WZZfile = TFile::Open("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/triboson/triboson_WZZ.root");
TFile *triboson_ZZZfile = TFile::Open("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/triboson/triboson_ZZZ.root");

TH1D *WWZ_sumevt = ((TH1D *)triboson_WWZfile->Get("Event_Variable/h_totevent"));
TH1D *WZZ_sumevt = ((TH1D *)triboson_WZZfile->Get("Event_Variable/h_totevent"));
TH1D *ZZZ_sumevt = ((TH1D *)triboson_ZZZfile->Get("Event_Variable/h_totevent"));

int WWZ_totevt = WWZ_sumevt->Integral();
int WZZ_totevt = WZZ_sumevt->Integral();
int ZZZ_totevt = ZZZ_sumevt->Integral();

//---------------------
// Define Triboson Weight
//---------------------
double WWZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::WWZ_TuneCUETP8M1 / (WWZ_totevt)) * 1000;
double WZZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::WZZ_TuneCUETP8M1 / (WZZ_totevt)) * 1000;
double ZZZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ZZZ_TuneCUETP8M1 / (ZZZ_totevt)) * 1000;

void ana_Triboson_punzi(const char *scanMet_step = "tmp", TString outputfile = "./output/tmp.root")
{

    //---------------------
    // Met cut
    //---------------------
    float metcut = atoi(scanMet_step) * 10;
    cout << "metcut" << metcut << endl;

    TH1D *h_pass_Bg_nMetcut = new TH1D("h_pass_Bg_nMetcut", "", 50, 0, 50);
    h_pass_Bg_nMetcut->Sumw2();

    Int_t I_WWZ_weight, I_WZZ_weight, I_ZZZ_weight;

    float_t f_WWZ_met, f_WZZ_met, f_ZZZ_met;

    vector<float> *v_WWZ_alpha = new vector<float>();
    vector<float> *v_WZZ_alpha = new vector<float>();
    vector<float> *v_ZZZ_alpha = new vector<float>();

    v_WWZ_alpha->clear();
    v_WZZ_alpha->clear();
    v_ZZZ_alpha->clear();

    TTree *T_tree;
    triboson_WWZfile->GetObject("T_tree", T_tree);
    T_tree->SetBranchAddress("I_weight", &I_WWZ_weight);
    T_tree->SetBranchAddress("f_Met", &f_WWZ_met);
    T_tree->SetBranchAddress("v_fakealpha", &v_WWZ_alpha);
    for (int evt = 0; evt < T_tree->GetEntries(); evt++)
    {
        T_tree->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_WWZ_alpha->size(); i++)
        {
            if ((*v_WWZ_alpha)[i] > 0.15)
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
        if (f_WWZ_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), I_WWZ_weight * WWZWeight);
        }
    }
    TTree *T_tree2;
    triboson_WZZfile->GetObject("T_tree", T_tree2);
    T_tree2->SetBranchAddress("I_weight", &I_WZZ_weight);
    T_tree2->SetBranchAddress("f_Met", &f_WZZ_met);
    T_tree2->SetBranchAddress("v_fakealpha", &v_WZZ_alpha);
    for (int evt = 0; evt < T_tree2->GetEntries(); evt++)
    {
        T_tree2->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_WZZ_alpha->size(); i++)
        {
            if ((*v_WZZ_alpha)[i] > 0.15)
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
        if (f_WZZ_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), I_WZZ_weight * WZZWeight);
        }
    }
    TTree *T_tree3;
    triboson_ZZZfile->GetObject("T_tree", T_tree3);
    T_tree3->SetBranchAddress("I_weight", &I_ZZZ_weight);
    T_tree3->SetBranchAddress("f_Met", &f_ZZZ_met);
    T_tree3->SetBranchAddress("v_fakealpha", &v_ZZZ_alpha);
    for (int evt = 0; evt < T_tree3->GetEntries(); evt++)
    {
        T_tree3->GetEntry(evt);
        bool alpha_cut = true;
        for (int i = 0; i < v_ZZZ_alpha->size(); i++)
        {
            if ((*v_ZZZ_alpha)[i] > 0.15)
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
        if (f_ZZZ_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), I_ZZZ_weight * ZZZWeight);
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
        ana_Triboson_punzi(argv[1], argv[2]);
    }
    else
    {
        cout << "ERROR" << endl;
    }
}