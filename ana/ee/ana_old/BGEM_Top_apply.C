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
#include "./lib/Cross_section.h"
using namespace RooFit;

Double_t background(Double_t x)
{
    double par0 = 3.79680e+00;
    double par1 = -8.16112e-04;
    double par2 = 2.48778e-05;
    double par3 = -4.13958e-08;

    // Double_t weight = ((TMath::Exp(par0 + par1 * x + par2 * x * x)) + par3 * x * x + par4 * x + par5);
    Double_t weight = par3 * x * x * x + par2 * x * x * +par1 * x + par0;

    return weight;
}
void BGEM_Top_apply()
{

    TFile *Top_TTTo2L2Nu = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
    TFile *Top_TTWJetsToLNu = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQ = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToLLNuNu = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_TTZToQQ = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_tW_antitop = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_top = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)Top_TTTo2L2Nu->Get("Event_Variable/h_event"));
    TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNu->Get("Event_Variable/h_event"));
    TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQ->Get("Event_Variable/h_event"));
    TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNu->Get("Event_Variable/h_event"));
    TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQ->Get("Event_Variable/h_event"));
    TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitop->Get("Event_Variable/h_event"));
    TH1D *tW_top_sumevt = ((TH1D *)Top_tW_top->Get("Event_Variable/h_event"));

    int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->GetEntries();
    int TTWJetsToLNu_totevt = TTWJetsToLNu_sumevt->GetEntries();
    int TTWJetsToQQ_totevt = TTWJetsToQQ_sumevt->GetEntries();
    int TTZToLLNuNu_totevt = TTZToLLNuNu_sumevt->GetEntries();
    int TTZToQQ_totevt = TTZToQQ_sumevt->GetEntries();
    int tW_antitop_totevt = tW_antitop_sumevt->GetEntries();
    int tW_top_totevt = tW_top_sumevt->GetEntries();

    // DYHT
    TH1F *h_tW_topA_jetpt = new TH1F("h_tW_topA_jetpt", "leading Jet PT", 10, 0, 1000);
    h_tW_topA_jetpt->Sumw2();
    TH1F *h_tW_antitopA_jetpt = new TH1F("h_tW_antitopA_jetpt", "leading Jet PT", 10, 0, 1000);
    h_tW_antitopA_jetpt->Sumw2();
    TH1F *h_TTTo2L2NuA_jetpt = new TH1F("h_TTTo2L2NuA_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTTo2L2NuA_jetpt->Sumw2();
    TH1F *h_TTWJetsToLNuA_jetpt = new TH1F("h_TTWJetsToLNuA_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTWJetsToLNuA_jetpt->Sumw2();
    TH1F *h_TTWJetsToQQA_jetpt = new TH1F("h_TTWJetsToQQA_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTWJetsToQQA_jetpt->Sumw2();
    TH1F *h_TTZToLLNuNuA_jetpt = new TH1F("h_TTZToLLNuNuA_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTZToLLNuNuA_jetpt->Sumw2();
    TH1F *h_TTZToQQA_jetpt = new TH1F("h_TTZToQQA_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTZToQQA_jetpt->Sumw2();

    TH1F *h_tW_topB_jetpt = new TH1F("h_tW_topB_jetpt", "leading Jet PT", 10, 0, 1000);
    h_tW_topB_jetpt->Sumw2();
    TH1F *h_tW_antitopB_jetpt = new TH1F("h_tW_antitopB_jetpt", "leading Jet PT", 10, 0, 1000);
    h_tW_antitopB_jetpt->Sumw2();
    TH1F *h_TTTo2L2NuB_jetpt = new TH1F("h_TTTo2L2NuB_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTTo2L2NuB_jetpt->Sumw2();
    TH1F *h_TTWJetsToLNuB_jetpt = new TH1F("h_TTWJetsToLNuB_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTWJetsToLNuB_jetpt->Sumw2();
    TH1F *h_TTWJetsToQQB_jetpt = new TH1F("h_TTWJetsToQQB_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTWJetsToQQB_jetpt->Sumw2();
    TH1F *h_TTZToLLNuNuB_jetpt = new TH1F("h_TTZToLLNuNuB_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTZToLLNuNuB_jetpt->Sumw2();
    TH1F *h_TTZToQQB_jetpt = new TH1F("h_TTZToQQB_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTZToQQB_jetpt->Sumw2();

    TH1F *h_tW_topC_jetpt = new TH1F("h_tW_topC_jetpt", "leading Jet PT", 10, 0, 1000);
    h_tW_topC_jetpt->Sumw2();
    TH1F *h_tW_antitopC_jetpt = new TH1F("h_tW_antitopC_jetpt", "leading Jet PT", 10, 0, 1000);
    h_tW_antitopC_jetpt->Sumw2();
    TH1F *h_TTTo2L2NuC_jetpt = new TH1F("h_TTTo2L2NuC_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTTo2L2NuC_jetpt->Sumw2();
    TH1F *h_TTWJetsToLNuC_jetpt = new TH1F("h_TTWJetsToLNuC_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTWJetsToLNuC_jetpt->Sumw2();
    TH1F *h_TTWJetsToQQC_jetpt = new TH1F("h_TTWJetsToQQC_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTWJetsToQQC_jetpt->Sumw2();
    TH1F *h_TTZToLLNuNuC_jetpt = new TH1F("h_TTZToLLNuNuC_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTZToLLNuNuC_jetpt->Sumw2();
    TH1F *h_TTZToQQC_jetpt = new TH1F("h_TTZToQQC_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTZToQQC_jetpt->Sumw2();

    TH1F *h_tW_topD_jetpt = new TH1F("h_tW_topD_jetpt", "leading Jet PT", 10, 0, 1000);
    h_tW_topD_jetpt->Sumw2();
    TH1F *h_tW_antitopD_jetpt = new TH1F("h_tW_antitopD_jetpt", "leading Jet PT", 10, 0, 1000);
    h_tW_antitopD_jetpt->Sumw2();
    TH1F *h_TTTo2L2NuD_jetpt = new TH1F("h_TTTo2L2NuD_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTTo2L2NuD_jetpt->Sumw2();
    TH1F *h_TTWJetsToLNuD_jetpt = new TH1F("h_TTWJetsToLNuD_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTWJetsToLNuD_jetpt->Sumw2();
    TH1F *h_TTWJetsToQQD_jetpt = new TH1F("h_TTWJetsToQQD_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTWJetsToQQD_jetpt->Sumw2();
    TH1F *h_TTZToLLNuNuD_jetpt = new TH1F("h_TTZToLLNuNuD_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTZToLLNuNuD_jetpt->Sumw2();
    TH1F *h_TTZToQQD_jetpt = new TH1F("h_TTZToQQD_jetpt", "leading Jet PT", 10, 0, 1000);
    h_TTZToQQD_jetpt->Sumw2();

    TH1F *h_tW_topA_jeteta = new TH1F("h_tW_topA_jeteta", "eta jets", 20, -5, 5);
    h_tW_topA_jeteta->Sumw2();
    TH1F *h_tW_antitopA_jeteta = new TH1F("h_tW_antitopA_jeteta", "eta jets", 20, -5, 5);
    h_tW_antitopA_jeteta->Sumw2();
    TH1F *h_TTTo2L2NuA_jeteta = new TH1F("h_TTTo2L2NuA_jeteta", "eta jets", 20, -5, 5);
    h_TTTo2L2NuA_jeteta->Sumw2();
    TH1F *h_TTWJetsToLNuA_jeteta = new TH1F("h_TTWJetsToLNuA_jeteta", "eta jets", 20, -5, 5);
    h_TTWJetsToLNuA_jeteta->Sumw2();
    TH1F *h_TTWJetsToQQA_jeteta = new TH1F("h_TTWJetsToQQA_jeteta", "eta jets", 20, -5, 5);
    h_TTWJetsToQQA_jeteta->Sumw2();
    TH1F *h_TTZToLLNuNuA_jeteta = new TH1F("h_TTZToLLNuNuA_jeteta", "eta jets", 20, -5, 5);
    h_TTZToLLNuNuA_jeteta->Sumw2();
    TH1F *h_TTZToQQA_jeteta = new TH1F("h_TTZToQQA_jeteta", "eta jets", 20, -5, 5);
    h_TTZToQQA_jeteta->Sumw2();

    TH1F *h_tW_topB_jeteta = new TH1F("h_tW_topB_jeteta", "eta jets", 20, -5, 5);
    h_tW_topB_jeteta->Sumw2();
    TH1F *h_tW_antitopB_jeteta = new TH1F("h_tW_antitopB_jeteta", "eta jets", 20, -5, 5);
    h_tW_antitopB_jeteta->Sumw2();
    TH1F *h_TTTo2L2NuB_jeteta = new TH1F("h_TTTo2L2NuB_jeteta", "eta jets", 20, -5, 5);
    h_TTTo2L2NuB_jeteta->Sumw2();
    TH1F *h_TTWJetsToLNuB_jeteta = new TH1F("h_TTWJetsToLNuB_jeteta", "eta jets", 20, -5, 5);
    h_TTWJetsToLNuB_jeteta->Sumw2();
    TH1F *h_TTWJetsToQQB_jeteta = new TH1F("h_TTWJetsToQQB_jeteta", "eta jets", 20, -5, 5);
    h_TTWJetsToQQB_jeteta->Sumw2();
    TH1F *h_TTZToLLNuNuB_jeteta = new TH1F("h_TTZToLLNuNuB_jeteta", "eta jets", 20, -5, 5);
    h_TTZToLLNuNuB_jeteta->Sumw2();
    TH1F *h_TTZToQQB_jeteta = new TH1F("h_TTZToQQB_jeteta", "eta jets", 20, -5, 5);
    h_TTZToQQB_jeteta->Sumw2();

    TH1F *h_tW_topC_jeteta = new TH1F("h_tW_topC_jeteta", "eta jets", 20, -5, 5);
    h_tW_topC_jeteta->Sumw2();
    TH1F *h_tW_antitopC_jeteta = new TH1F("h_tW_antitopC_jeteta", "eta jets", 20, -5, 5);
    h_tW_antitopC_jeteta->Sumw2();
    TH1F *h_TTTo2L2NuC_jeteta = new TH1F("h_TTTo2L2NuC_jeteta", "eta jets", 20, -5, 5);
    h_TTTo2L2NuC_jeteta->Sumw2();
    TH1F *h_TTWJetsToLNuC_jeteta = new TH1F("h_TTWJetsToLNuC_jeteta", "eta jets", 20, -5, 5);
    h_TTWJetsToLNuC_jeteta->Sumw2();
    TH1F *h_TTWJetsToQQC_jeteta = new TH1F("h_TTWJetsToQQC_jeteta", "eta jets", 20, -5, 5);
    h_TTWJetsToQQC_jeteta->Sumw2();
    TH1F *h_TTZToLLNuNuC_jeteta = new TH1F("h_TTZToLLNuNuC_jeteta", "eta jets", 20, -5, 5);
    h_TTZToLLNuNuC_jeteta->Sumw2();
    TH1F *h_TTZToQQC_jeteta = new TH1F("h_TTZToQQC_jeteta", "eta jets", 20, -5, 5);
    h_TTZToQQC_jeteta->Sumw2();

    TH1F *h_tW_topD_jeteta = new TH1F("h_tW_topD_jeteta", "eta jets", 20, -5, 5);
    h_tW_topD_jeteta->Sumw2();
    TH1F *h_tW_antitopD_jeteta = new TH1F("h_tW_antitopD_jeteta", "eta jets", 20, -5, 5);
    h_tW_antitopD_jeteta->Sumw2();
    TH1F *h_TTTo2L2NuD_jeteta = new TH1F("h_TTTo2L2NuD_jeteta", "eta jets", 20, -5, 5);
    h_TTTo2L2NuD_jeteta->Sumw2();
    TH1F *h_TTWJetsToLNuD_jeteta = new TH1F("h_TTWJetsToLNuD_jeteta", "eta jets", 20, -5, 5);
    h_TTWJetsToLNuD_jeteta->Sumw2();
    TH1F *h_TTWJetsToQQD_jeteta = new TH1F("h_TTWJetsToQQD_jeteta", "eta jets", 20, -5, 5);
    h_TTWJetsToQQD_jeteta->Sumw2();
    TH1F *h_TTZToLLNuNuD_jeteta = new TH1F("h_TTZToLLNuNuD_jeteta", "eta jets", 20, -5, 5);
    h_TTZToLLNuNuD_jeteta->Sumw2();
    TH1F *h_TTZToQQD_jeteta = new TH1F("h_TTZToQQD_jeteta", "eta jets", 20, -5, 5);
    h_TTZToQQD_jeteta->Sumw2();

    TH1F *h_tW_topA_jetmet = new TH1F("h_tW_topA_jetmet", "Met", 10, 0, 1000);
    h_tW_topA_jetmet->Sumw2();
    TH1F *h_tW_antitopA_jetmet = new TH1F("h_tW_antitopA_jetmet", "Met", 10, 0, 1000);
    h_tW_antitopA_jetmet->Sumw2();
    TH1F *h_TTTo2L2NuA_jetmet = new TH1F("h_TTTo2L2NuA_jetmet", "Met", 10, 0, 1000);
    h_TTTo2L2NuA_jetmet->Sumw2();
    TH1F *h_TTWJetsToLNuA_jetmet = new TH1F("h_TTWJetsToLNuA_jetmet", "Met", 10, 0, 1000);
    h_TTWJetsToLNuA_jetmet->Sumw2();
    TH1F *h_TTWJetsToQQA_jetmet = new TH1F("h_TTWJetsToQQA_jetmet", "Met", 10, 0, 1000);
    h_TTWJetsToQQA_jetmet->Sumw2();
    TH1F *h_TTZToLLNuNuA_jetmet = new TH1F("h_TTZToLLNuNuA_jetmet", "Met", 10, 0, 1000);
    h_TTZToLLNuNuA_jetmet->Sumw2();
    TH1F *h_TTZToQQA_jetmet = new TH1F("h_TTZToQQA_jetmet", "Met", 10, 0, 1000);
    h_TTZToQQA_jetmet->Sumw2();

    TH1F *h_tW_topB_jetmet = new TH1F("h_tW_topB_jetmet", "Met", 10, 0, 1000);
    h_tW_topB_jetmet->Sumw2();
    TH1F *h_tW_antitopB_jetmet = new TH1F("h_tW_antitopB_jetmet", "Met", 10, 0, 1000);
    h_tW_antitopB_jetmet->Sumw2();
    TH1F *h_TTTo2L2NuB_jetmet = new TH1F("h_TTTo2L2NuB_jetmet", "Met", 10, 0, 1000);
    h_TTTo2L2NuB_jetmet->Sumw2();
    TH1F *h_TTWJetsToLNuB_jetmet = new TH1F("h_TTWJetsToLNuB_jetmet", "Met", 10, 0, 1000);
    h_TTWJetsToLNuB_jetmet->Sumw2();
    TH1F *h_TTWJetsToQQB_jetmet = new TH1F("h_TTWJetsToQQB_jetmet", "Met", 10, 0, 1000);
    h_TTWJetsToQQB_jetmet->Sumw2();
    TH1F *h_TTZToLLNuNuB_jetmet = new TH1F("h_TTZToLLNuNuB_jetmet", "Met", 10, 0, 1000);
    h_TTZToLLNuNuB_jetmet->Sumw2();
    TH1F *h_TTZToQQB_jetmet = new TH1F("h_TTZToQQB_jetmet", "Met", 10, 0, 1000);
    h_TTZToQQB_jetmet->Sumw2();

    TH1F *h_tW_topC_jetmet = new TH1F("h_tW_topC_jetmet", "Met", 10, 0, 1000);
    h_tW_topC_jetmet->Sumw2();
    TH1F *h_tW_antitopC_jetmet = new TH1F("h_tW_antitopC_jetmet", "Met", 10, 0, 1000);
    h_tW_antitopC_jetmet->Sumw2();
    TH1F *h_TTTo2L2NuC_jetmet = new TH1F("h_TTTo2L2NuC_jetmet", "Met", 10, 0, 1000);
    h_TTTo2L2NuC_jetmet->Sumw2();
    TH1F *h_TTWJetsToLNuC_jetmet = new TH1F("h_TTWJetsToLNuC_jetmet", "Met", 10, 0, 1000);
    h_TTWJetsToLNuC_jetmet->Sumw2();
    TH1F *h_TTWJetsToQQC_jetmet = new TH1F("h_TTWJetsToQQC_jetmet", "Met", 10, 0, 1000);
    h_TTWJetsToQQC_jetmet->Sumw2();
    TH1F *h_TTZToLLNuNuC_jetmet = new TH1F("h_TTZToLLNuNuC_jetmet", "Met", 10, 0, 1000);
    h_TTZToLLNuNuC_jetmet->Sumw2();
    TH1F *h_TTZToQQC_jetmet = new TH1F("h_TTZToQQC_jetmet", "Met", 10, 0, 1000);
    h_TTZToQQC_jetmet->Sumw2();

    TH1F *h_tW_topD_jetmet = new TH1F("h_tW_topD_jetmet", "Met", 10, 0, 1000);
    h_tW_topD_jetmet->Sumw2();
    TH1F *h_tW_antitopD_jetmet = new TH1F("h_tW_antitopD_jetmet", "Met", 10, 0, 1000);
    h_tW_antitopD_jetmet->Sumw2();
    TH1F *h_TTTo2L2NuD_jetmet = new TH1F("h_TTTo2L2NuD_jetmet", "Met", 10, 0, 1000);
    h_TTTo2L2NuD_jetmet->Sumw2();
    TH1F *h_TTWJetsToLNuD_jetmet = new TH1F("h_TTWJetsToLNuD_jetmet", "Met", 10, 0, 1000);
    h_TTWJetsToLNuD_jetmet->Sumw2();
    TH1F *h_TTWJetsToQQD_jetmet = new TH1F("h_TTWJetsToQQD_jetmet", "Met", 10, 0, 1000);
    h_TTWJetsToQQD_jetmet->Sumw2();
    TH1F *h_TTZToLLNuNuD_jetmet = new TH1F("h_TTZToLLNuNuD_jetmet", "Met", 10, 0, 1000);
    h_TTZToLLNuNuD_jetmet->Sumw2();
    TH1F *h_TTZToQQD_jetmet = new TH1F("h_TTZToQQD_jetmet", "Met", 10, 0, 1000);
    h_TTZToQQD_jetmet->Sumw2();

    TH1F *h_tW_topA_diLp_PT = new TH1F("h_tW_topA_diLp_PT", "dilepton PT", 10, 0, 500);
    h_tW_topA_diLp_PT->Sumw2();
    TH1F *h_tW_antitopA_diLp_PT = new TH1F("h_tW_antitopA_diLp_PT", "dilepton PT", 10, 0, 500);
    h_tW_antitopA_diLp_PT->Sumw2();
    TH1F *h_TTTo2L2NuA_diLp_PT = new TH1F("h_TTTo2L2NuA_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTTo2L2NuA_diLp_PT->Sumw2();
    TH1F *h_TTWJetsToLNuA_diLp_PT = new TH1F("h_TTWJetsToLNuA_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTWJetsToLNuA_diLp_PT->Sumw2();
    TH1F *h_TTWJetsToQQA_diLp_PT = new TH1F("h_TTWJetsToQQA_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTWJetsToQQA_diLp_PT->Sumw2();
    TH1F *h_TTZToLLNuNuA_diLp_PT = new TH1F("h_TTZToLLNuNuA_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTZToLLNuNuA_diLp_PT->Sumw2();
    TH1F *h_TTZToQQA_diLp_PT = new TH1F("h_TTZToQQA_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTZToQQA_diLp_PT->Sumw2();

    TH1F *h_tW_topB_diLp_PT = new TH1F("h_tW_topB_diLp_PT", "dilepton PT", 10, 0, 500);
    h_tW_topB_diLp_PT->Sumw2();
    TH1F *h_tW_antitopB_diLp_PT = new TH1F("h_tW_antitopB_diLp_PT", "dilepton PT", 10, 0, 500);
    h_tW_antitopB_diLp_PT->Sumw2();
    TH1F *h_TTTo2L2NuB_diLp_PT = new TH1F("h_TTTo2L2NuB_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTTo2L2NuB_diLp_PT->Sumw2();
    TH1F *h_TTWJetsToLNuB_diLp_PT = new TH1F("h_TTWJetsToLNuB_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTWJetsToLNuB_diLp_PT->Sumw2();
    TH1F *h_TTWJetsToQQB_diLp_PT = new TH1F("h_TTWJetsToQQB_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTWJetsToQQB_diLp_PT->Sumw2();
    TH1F *h_TTZToLLNuNuB_diLp_PT = new TH1F("h_TTZToLLNuNuB_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTZToLLNuNuB_diLp_PT->Sumw2();
    TH1F *h_TTZToQQB_diLp_PT = new TH1F("h_TTZToQQB_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTZToQQB_diLp_PT->Sumw2();

    TH1F *h_tW_topC_diLp_PT = new TH1F("h_tW_topC_diLp_PT", "dilepton PT", 10, 0, 500);
    h_tW_topC_diLp_PT->Sumw2();
    TH1F *h_tW_antitopC_diLp_PT = new TH1F("h_tW_antitopC_diLp_PT", "dilepton PT", 10, 0, 500);
    h_tW_antitopC_diLp_PT->Sumw2();
    TH1F *h_TTTo2L2NuC_diLp_PT = new TH1F("h_TTTo2L2NuC_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTTo2L2NuC_diLp_PT->Sumw2();
    TH1F *h_TTWJetsToLNuC_diLp_PT = new TH1F("h_TTWJetsToLNuC_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTWJetsToLNuC_diLp_PT->Sumw2();
    TH1F *h_TTWJetsToQQC_diLp_PT = new TH1F("h_TTWJetsToQQC_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTWJetsToQQC_diLp_PT->Sumw2();
    TH1F *h_TTZToLLNuNuC_diLp_PT = new TH1F("h_TTZToLLNuNuC_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTZToLLNuNuC_diLp_PT->Sumw2();
    TH1F *h_TTZToQQC_diLp_PT = new TH1F("h_TTZToQQC_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTZToQQC_diLp_PT->Sumw2();

    TH1F *h_tW_topD_diLp_PT = new TH1F("h_tW_topD_diLp_PT", "dilepton PT", 10, 0, 500);
    h_tW_topD_diLp_PT->Sumw2();
    TH1F *h_tW_antitopD_diLp_PT = new TH1F("h_tW_antitopD_diLp_PT", "dilepton PT", 10, 0, 500);
    h_tW_antitopD_diLp_PT->Sumw2();
    TH1F *h_TTTo2L2NuD_diLp_PT = new TH1F("h_TTTo2L2NuD_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTTo2L2NuD_diLp_PT->Sumw2();
    TH1F *h_TTWJetsToLNuD_diLp_PT = new TH1F("h_TTWJetsToLNuD_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTWJetsToLNuD_diLp_PT->Sumw2();
    TH1F *h_TTWJetsToQQD_diLp_PT = new TH1F("h_TTWJetsToQQD_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTWJetsToQQD_diLp_PT->Sumw2();
    TH1F *h_TTZToLLNuNuD_diLp_PT = new TH1F("h_TTZToLLNuNuD_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTZToLLNuNuD_diLp_PT->Sumw2();
    TH1F *h_TTZToQQD_diLp_PT = new TH1F("h_TTZToQQD_diLp_PT", "dilepton PT", 10, 0, 500);
    h_TTZToQQD_diLp_PT->Sumw2();

    // Define the Top
    float ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000;
    float ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000;
    float TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTTo2L2Nu / (TTTo2L2Nu_totevt)) * 1000;
    float TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000;
    float TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000;
    float TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000;
    float TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000;

    Double_t f_tW_top_alphamin, f_tW_antitop_alphamin, f_TTTo2L2Nu_alphamin, f_TTWJetsToLNu_alphamin,
        f_TTWJetsToQQ_alphamin, f_TTZToLLNuNu_alphamin, f_TTZToQQ_alphamin;

    Float_t f_tW_top_met, f_tW_antitop_met, f_TTTo2L2Nu_met, f_TTWJetsToLNu_met,
        f_TTWJetsToQQ_met, f_TTZToLLNuNu_met, f_TTZToQQ_met;

    Int_t f_tW_top_weight, f_tW_antitop_weight, f_TTTo2L2Nu_weight, f_TTWJetsToLNu_weight, f_TTWJetsToQQ_weight,
        f_TTZToLLNuNu_weight, f_TTZToQQ_weight;

    Int_t I_tW_top_nThinJets, I_tW_antitop_nThinJets, I_TTTo2L2Nu_nThinJets, I_TTWJetsToLNu_nThinJets, I_TTWJetsToQQ_nThinJets,
        I_TTZToLLNuNu_nThinJets, I_TTZToQQ_nThinJets;

    float_t f_tW_top_leadJeteta, f_tW_antitop_leadJeteta, f_TTTo2L2Nu_leadJeteta, f_TTWJetsToLNu_leadJeteta, f_TTWJetsToQQ_leadJeteta,
        f_TTZToLLNuNu_leadJeteta, f_TTZToQQ_leadJeteta;

    float_t f_tW_top_leadJetpt, f_tW_antitop_leadJetpt, f_TTTo2L2Nu_leadJetpt, f_TTWJetsToLNu_leadJetpt, f_TTWJetsToQQ_leadJetpt,
        f_TTZToLLNuNu_leadJetpt, f_TTZToQQ_leadJetpt;

    float_t f_tW_top_dilpPT, f_tW_antitop_dilpPT, f_TTTo2L2Nu_dilpPT, f_TTWJetsToLNu_dilpPT, f_TTWJetsToQQ_dilpPT,
        f_TTZToLLNuNu_dilpPT, f_TTZToQQ_dilpPT;

    TTree *T_event;
    Top_tW_top->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &f_tW_top_weight);
    T_event->SetBranchAddress("f_alphamin", &f_tW_top_alphamin);
    T_event->SetBranchAddress("f_Met", &f_tW_top_met);
    T_event->SetBranchAddress("I_nThinJets", &I_tW_top_nThinJets);
    T_event->SetBranchAddress("f_leadJetpt", &f_tW_top_leadJetpt);
    T_event->SetBranchAddress("f_leadJeteta", &f_tW_top_leadJeteta);
    T_event->SetBranchAddress("f_dileptonPT", &f_tW_top_dilpPT);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (I_tW_top_nThinJets < 2)
            continue;
        if (f_tW_top_alphamin > 0.3 && f_tW_top_met > 160 && f_tW_top_met < 800)
        {
            h_tW_topA_jetmet->Fill(f_tW_top_met, f_tW_top_weight * ST_tW_topWeight / background(f_tW_top_met));
            h_tW_topA_diLp_PT->Fill(f_tW_top_dilpPT, f_tW_top_weight * ST_tW_topWeight / background(f_tW_top_met));
            h_tW_topA_jetpt->Fill(f_tW_top_leadJetpt, f_tW_top_weight * ST_tW_topWeight / background(f_tW_top_met));
            h_tW_topA_jeteta->Fill(f_tW_top_leadJeteta, f_tW_top_weight * ST_tW_topWeight / background(f_tW_top_met));
        }
        else if (f_tW_top_alphamin < 0.1 && f_tW_top_met > 160 && f_tW_top_met < 800)
        {
            h_tW_topB_jetmet->Fill(f_tW_top_met, f_tW_top_weight * ST_tW_topWeight);
            h_tW_topB_diLp_PT->Fill(f_tW_top_dilpPT, f_tW_top_weight * ST_tW_topWeight);
            h_tW_topB_jetpt->Fill(f_tW_top_leadJetpt, f_tW_top_weight * ST_tW_topWeight);
            h_tW_topB_jeteta->Fill(f_tW_top_leadJeteta, f_tW_top_weight * ST_tW_topWeight);
        }
        else if (f_tW_top_alphamin > 0.3 && f_tW_top_met < 100)
        {
            h_tW_topC_jetmet->Fill(f_tW_top_met, f_tW_top_weight * ST_tW_topWeight / background(f_tW_top_met));
            h_tW_topC_diLp_PT->Fill(f_tW_top_dilpPT, f_tW_top_weight * ST_tW_topWeight / background(f_tW_top_met));
            h_tW_topC_jetpt->Fill(f_tW_top_leadJetpt, f_tW_top_weight * ST_tW_topWeight / background(f_tW_top_met));
            h_tW_topC_jeteta->Fill(f_tW_top_leadJeteta, f_tW_top_weight * ST_tW_topWeight / background(f_tW_top_met));
        }
        else if (f_tW_top_alphamin < 0.1 && f_tW_top_met < 100)
        {
            h_tW_topD_jetmet->Fill(f_tW_top_met, f_tW_top_weight * ST_tW_topWeight);
            h_tW_topD_diLp_PT->Fill(f_tW_top_dilpPT, f_tW_top_weight * ST_tW_topWeight);
            h_tW_topD_jetpt->Fill(f_tW_top_leadJetpt, f_tW_top_weight * ST_tW_topWeight);
            h_tW_topD_jeteta->Fill(f_tW_top_leadJeteta, f_tW_top_weight * ST_tW_topWeight);
        }
    }

    TTree *T_event1;
    Top_tW_antitop->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_tW_antitop_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_tW_antitop_met);
    T_event1->SetBranchAddress("I_weight", &f_tW_antitop_weight);
    T_event1->SetBranchAddress("I_nThinJets", &I_tW_antitop_nThinJets);
    T_event1->SetBranchAddress("f_leadJetpt", &f_tW_antitop_leadJetpt);
    T_event1->SetBranchAddress("f_leadJeteta", &f_tW_antitop_leadJeteta);
    T_event1->SetBranchAddress("f_dileptonPT", &f_tW_antitop_dilpPT);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (I_tW_antitop_nThinJets < 2)
            continue;
        if (f_tW_antitop_alphamin > 0.3 && f_tW_antitop_met > 160 && f_tW_antitop_met < 800)
        {
            h_tW_antitopA_jetmet->Fill(f_tW_antitop_met, f_tW_antitop_weight * ST_tW_antitopWeight / background(f_tW_antitop_met));
            h_tW_antitopA_diLp_PT->Fill(f_tW_antitop_dilpPT, f_tW_antitop_weight * ST_tW_antitopWeight / background(f_tW_antitop_met));
            h_tW_antitopA_jetpt->Fill(f_tW_antitop_leadJetpt, f_tW_antitop_weight * ST_tW_antitopWeight / background(f_tW_antitop_met));
            h_tW_antitopA_jeteta->Fill(f_tW_antitop_leadJeteta, f_tW_antitop_weight * ST_tW_antitopWeight / background(f_tW_antitop_met));
        }
        else if (f_tW_antitop_alphamin < 0.1 && f_tW_antitop_met > 160 && f_tW_antitop_met < 800)
        {
            h_tW_antitopB_jetmet->Fill(f_tW_antitop_met, f_tW_antitop_weight * ST_tW_antitopWeight);
            h_tW_antitopB_diLp_PT->Fill(f_tW_antitop_dilpPT, f_tW_antitop_weight * ST_tW_antitopWeight);
            h_tW_antitopB_jetpt->Fill(f_tW_antitop_leadJetpt, f_tW_antitop_weight * ST_tW_antitopWeight);
            h_tW_antitopB_jeteta->Fill(f_tW_antitop_leadJeteta, f_tW_antitop_weight * ST_tW_antitopWeight);
        }
        else if (f_tW_antitop_alphamin > 0.3 && f_tW_antitop_met < 100)
        {
            h_tW_antitopC_jetmet->Fill(f_tW_antitop_met, f_tW_antitop_weight * ST_tW_antitopWeight / background(f_tW_antitop_met));
            h_tW_antitopC_diLp_PT->Fill(f_tW_antitop_dilpPT, f_tW_antitop_weight * ST_tW_antitopWeight / background(f_tW_antitop_met));
            h_tW_antitopC_jetpt->Fill(f_tW_antitop_leadJetpt, f_tW_antitop_weight * ST_tW_antitopWeight / background(f_tW_antitop_met));
            h_tW_antitopC_jeteta->Fill(f_tW_antitop_leadJeteta, f_tW_antitop_weight * ST_tW_antitopWeight / background(f_tW_antitop_met));
        }
        else if (f_tW_antitop_alphamin < 0.1 && f_tW_antitop_met < 100)
        {
            h_tW_antitopD_jetmet->Fill(f_tW_antitop_met, f_tW_antitop_weight * ST_tW_antitopWeight);
            h_tW_antitopD_diLp_PT->Fill(f_tW_antitop_dilpPT, f_tW_antitop_weight * ST_tW_antitopWeight);
            h_tW_antitopD_jetpt->Fill(f_tW_antitop_leadJetpt, f_tW_antitop_weight * ST_tW_antitopWeight);
            h_tW_antitopD_jeteta->Fill(f_tW_antitop_leadJeteta, f_tW_antitop_weight * ST_tW_antitopWeight);
        }
    }

    TTree *T_event2;
    Top_TTTo2L2Nu->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_TTTo2L2Nu_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_event2->SetBranchAddress("I_weight", &f_TTTo2L2Nu_weight);
    T_event2->SetBranchAddress("I_nThinJets", &I_TTTo2L2Nu_nThinJets);
    T_event2->SetBranchAddress("f_leadJetpt", &f_TTTo2L2Nu_leadJetpt);
    T_event2->SetBranchAddress("f_leadJeteta", &f_TTTo2L2Nu_leadJeteta);
    T_event2->SetBranchAddress("f_dileptonPT", &f_TTTo2L2Nu_dilpPT);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (I_TTTo2L2Nu_nThinJets < 2)
            continue;
        if (f_TTTo2L2Nu_alphamin > 0.3 && f_TTTo2L2Nu_met > 160 && f_TTTo2L2Nu_met < 800)
        {
            h_TTTo2L2NuA_jetmet->Fill(f_TTTo2L2Nu_met, f_TTTo2L2Nu_weight * TTTo2L2NuWeight / background(f_TTTo2L2Nu_met));
            h_TTTo2L2NuA_diLp_PT->Fill(f_TTTo2L2Nu_dilpPT, f_TTTo2L2Nu_weight * TTTo2L2NuWeight / background(f_TTTo2L2Nu_met));
            h_TTTo2L2NuA_jetpt->Fill(f_TTTo2L2Nu_leadJetpt, f_TTTo2L2Nu_weight * TTTo2L2NuWeight / background(f_TTTo2L2Nu_met));
            h_TTTo2L2NuA_jeteta->Fill(f_TTTo2L2Nu_leadJeteta, f_TTTo2L2Nu_weight * TTTo2L2NuWeight / background(f_TTTo2L2Nu_met));
        }
        else if (f_TTTo2L2Nu_alphamin < 0.1 && f_TTTo2L2Nu_met > 160 && f_TTTo2L2Nu_met < 800)
        {
            h_TTTo2L2NuB_jetmet->Fill(f_TTTo2L2Nu_met, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_TTTo2L2NuB_diLp_PT->Fill(f_TTTo2L2Nu_dilpPT, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_TTTo2L2NuB_jetpt->Fill(f_TTTo2L2Nu_leadJetpt, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_TTTo2L2NuB_jeteta->Fill(f_TTTo2L2Nu_leadJeteta, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        }
        else if (f_TTTo2L2Nu_alphamin > 0.3 && f_TTTo2L2Nu_met < 100)
        {
            h_TTTo2L2NuC_jetmet->Fill(f_TTTo2L2Nu_met, f_TTTo2L2Nu_weight * TTTo2L2NuWeight / background(f_TTTo2L2Nu_met));
            h_TTTo2L2NuC_diLp_PT->Fill(f_TTTo2L2Nu_dilpPT, f_TTTo2L2Nu_weight * TTTo2L2NuWeight / background(f_TTTo2L2Nu_met));
            h_TTTo2L2NuC_jetpt->Fill(f_TTTo2L2Nu_leadJetpt, f_TTTo2L2Nu_weight * TTTo2L2NuWeight / background(f_TTTo2L2Nu_met));
            h_TTTo2L2NuC_jeteta->Fill(f_TTTo2L2Nu_leadJeteta, f_TTTo2L2Nu_weight * TTTo2L2NuWeight / background(f_TTTo2L2Nu_met));
        }
        else if (f_TTTo2L2Nu_alphamin < 0.1 && f_TTTo2L2Nu_met < 100)
        {
            h_TTTo2L2NuD_jetmet->Fill(f_TTTo2L2Nu_met, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_TTTo2L2NuD_diLp_PT->Fill(f_TTTo2L2Nu_dilpPT, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_TTTo2L2NuD_jetpt->Fill(f_TTTo2L2Nu_leadJetpt, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_TTTo2L2NuD_jeteta->Fill(f_TTTo2L2Nu_leadJeteta, f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        }
    }

    TTree *T_event3;
    Top_TTWJetsToLNu->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &f_TTWJetsToLNu_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_event3->SetBranchAddress("I_weight", &f_TTWJetsToLNu_weight);
    T_event3->SetBranchAddress("I_nThinJets", &I_TTWJetsToLNu_nThinJets);
    T_event3->SetBranchAddress("f_leadJetpt", &f_TTWJetsToLNu_leadJetpt);
    T_event3->SetBranchAddress("f_leadJeteta", &f_TTWJetsToLNu_leadJeteta);
    T_event3->SetBranchAddress("f_dileptonPT", &f_TTWJetsToLNu_dilpPT);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (I_TTWJetsToLNu_nThinJets < 2)
            continue;
        if (f_TTWJetsToLNu_alphamin > 0.3 && f_TTWJetsToLNu_met > 160 && f_TTWJetsToLNu_met < 800)
        {
            h_TTWJetsToLNuA_jetmet->Fill(f_TTWJetsToLNu_met, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight / background(f_TTWJetsToLNu_met));
            h_TTWJetsToLNuA_diLp_PT->Fill(f_TTWJetsToLNu_dilpPT, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight / background(f_TTWJetsToLNu_met));
            h_TTWJetsToLNuA_jetpt->Fill(f_TTWJetsToLNu_leadJetpt, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight / background(f_TTWJetsToLNu_met));
            h_TTWJetsToLNuA_jeteta->Fill(f_TTWJetsToLNu_leadJeteta, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight / background(f_TTWJetsToLNu_met));
        }
        else if (f_TTWJetsToLNu_alphamin < 0.1 && f_TTWJetsToLNu_met > 160 && f_TTWJetsToLNu_met < 800)
        {
            h_TTWJetsToLNuB_jetmet->Fill(f_TTWJetsToLNu_met, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_TTWJetsToLNuB_diLp_PT->Fill(f_TTWJetsToLNu_dilpPT, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_TTWJetsToLNuB_jetpt->Fill(f_TTWJetsToLNu_leadJetpt, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_TTWJetsToLNuB_jeteta->Fill(f_TTWJetsToLNu_leadJeteta, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        }
        else if (f_TTWJetsToLNu_alphamin > 0.3 && f_TTWJetsToLNu_met < 100)
        {
            h_TTWJetsToLNuC_jetmet->Fill(f_TTWJetsToLNu_met, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight / background(f_TTWJetsToLNu_met));
            h_TTWJetsToLNuC_diLp_PT->Fill(f_TTWJetsToLNu_dilpPT, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight / background(f_TTWJetsToLNu_met));
            h_TTWJetsToLNuC_jetpt->Fill(f_TTWJetsToLNu_leadJetpt, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight / background(f_TTWJetsToLNu_met));
            h_TTWJetsToLNuC_jeteta->Fill(f_TTWJetsToLNu_leadJeteta, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight / background(f_TTWJetsToLNu_met));
        }
        else if (f_TTWJetsToLNu_alphamin < 0.1 && f_TTWJetsToLNu_met < 100)
        {
            h_TTWJetsToLNuD_jetmet->Fill(f_TTWJetsToLNu_met, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_TTWJetsToLNuD_diLp_PT->Fill(f_TTWJetsToLNu_dilpPT, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_TTWJetsToLNuD_jetpt->Fill(f_TTWJetsToLNu_leadJetpt, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_TTWJetsToLNuD_jeteta->Fill(f_TTWJetsToLNu_leadJeteta, f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        }
    }

    TTree *T_event4;
    Top_TTWJetsToQQ->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &f_TTWJetsToQQ_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_event4->SetBranchAddress("I_weight", &f_TTWJetsToQQ_weight);
    T_event4->SetBranchAddress("I_nThinJets", &I_TTWJetsToQQ_nThinJets);
    T_event4->SetBranchAddress("f_leadJetpt", &f_TTWJetsToQQ_leadJetpt);
    T_event4->SetBranchAddress("f_leadJeteta", &f_TTWJetsToQQ_leadJeteta);
    T_event4->SetBranchAddress("f_dileptonPT", &f_TTWJetsToQQ_dilpPT);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (I_TTWJetsToQQ_nThinJets < 2)
            continue;
        if (f_TTWJetsToQQ_alphamin > 0.3 && f_TTWJetsToQQ_met > 160 && f_TTWJetsToQQ_met < 800)
        {
            h_TTWJetsToQQA_jetmet->Fill(f_TTWJetsToQQ_met, f_TTWJetsToQQ_weight * TTWJetsToQQWeight / background(f_TTWJetsToQQ_met));
            h_TTWJetsToQQA_diLp_PT->Fill(f_TTWJetsToQQ_dilpPT, f_TTWJetsToQQ_weight * TTWJetsToQQWeight / background(f_TTWJetsToQQ_met));
            h_TTWJetsToQQA_jetpt->Fill(f_TTWJetsToQQ_leadJetpt, f_TTWJetsToQQ_weight * TTWJetsToQQWeight / background(f_TTWJetsToQQ_met));
            h_TTWJetsToQQA_jeteta->Fill(f_TTWJetsToQQ_leadJeteta, f_TTWJetsToQQ_weight * TTWJetsToQQWeight / background(f_TTWJetsToQQ_met));
        }
        else if (f_TTWJetsToQQ_alphamin < 0.1 && f_TTWJetsToQQ_met > 160 && f_TTWJetsToQQ_met < 800)
        {
            h_TTWJetsToQQB_jetmet->Fill(f_TTWJetsToQQ_met, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_TTWJetsToQQB_diLp_PT->Fill(f_TTWJetsToQQ_dilpPT, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_TTWJetsToQQB_jetpt->Fill(f_TTWJetsToQQ_leadJetpt, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_TTWJetsToQQB_jeteta->Fill(f_TTWJetsToQQ_leadJeteta, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        }
        else if (f_TTWJetsToQQ_alphamin > 0.3 && f_TTWJetsToQQ_met < 100)
        {
            h_TTWJetsToQQC_jetmet->Fill(f_TTWJetsToQQ_met, f_TTWJetsToQQ_weight * TTWJetsToQQWeight / background(f_TTWJetsToQQ_met));
            h_TTWJetsToQQC_diLp_PT->Fill(f_TTWJetsToQQ_dilpPT, f_TTWJetsToQQ_weight * TTWJetsToQQWeight / background(f_TTWJetsToQQ_met));
            h_TTWJetsToQQC_jetpt->Fill(f_TTWJetsToQQ_leadJetpt, f_TTWJetsToQQ_weight * TTWJetsToQQWeight / background(f_TTWJetsToQQ_met));
            h_TTWJetsToQQC_jeteta->Fill(f_TTWJetsToQQ_leadJeteta, f_TTWJetsToQQ_weight * TTWJetsToQQWeight / background(f_TTWJetsToQQ_met));
        }
        else if (f_TTWJetsToQQ_alphamin < 0.1 && f_TTWJetsToQQ_met < 100)
        {
            h_TTWJetsToQQD_jetmet->Fill(f_TTWJetsToQQ_met, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_TTWJetsToQQD_diLp_PT->Fill(f_TTWJetsToQQ_dilpPT, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_TTWJetsToQQD_jetpt->Fill(f_TTWJetsToQQ_leadJetpt, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_TTWJetsToQQD_jeteta->Fill(f_TTWJetsToQQ_leadJeteta, f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        }
    }

    TTree *T_event5;
    Top_TTZToLLNuNu->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &f_TTZToLLNuNu_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_event5->SetBranchAddress("I_weight", &f_TTZToLLNuNu_weight);
    T_event5->SetBranchAddress("I_nThinJets", &I_TTZToLLNuNu_nThinJets);
    T_event5->SetBranchAddress("f_leadJetpt", &f_TTZToLLNuNu_leadJetpt);
    T_event5->SetBranchAddress("f_leadJeteta", &f_TTZToLLNuNu_leadJeteta);
    T_event5->SetBranchAddress("f_dileptonPT", &f_TTZToLLNuNu_dilpPT);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (I_TTZToLLNuNu_nThinJets < 2)
            continue;
        if (f_TTZToLLNuNu_alphamin > 0.3 && f_TTZToLLNuNu_met > 160 && f_TTZToLLNuNu_met < 800)
        {
            h_TTZToLLNuNuA_jetmet->Fill(f_TTZToLLNuNu_met, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight / background(f_TTZToLLNuNu_met));
            h_TTZToLLNuNuA_diLp_PT->Fill(f_TTZToLLNuNu_dilpPT, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight / background(f_TTZToLLNuNu_met));
            h_TTZToLLNuNuA_jetpt->Fill(f_TTZToLLNuNu_leadJetpt, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight / background(f_TTZToLLNuNu_met));
            h_TTZToLLNuNuA_jeteta->Fill(f_TTZToLLNuNu_leadJeteta, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight / background(f_TTZToLLNuNu_met));
        }
        else if (f_TTZToLLNuNu_alphamin < 0.1 && f_TTZToLLNuNu_met > 160 && f_TTZToLLNuNu_met < 800)
        {
            h_TTZToLLNuNuB_jetmet->Fill(f_TTZToLLNuNu_met, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_TTZToLLNuNuB_diLp_PT->Fill(f_TTZToLLNuNu_dilpPT, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_TTZToLLNuNuB_jetpt->Fill(f_TTZToLLNuNu_leadJetpt, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_TTZToLLNuNuB_jeteta->Fill(f_TTZToLLNuNu_leadJeteta, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        }
        else if (f_TTZToLLNuNu_alphamin > 0.3 && f_TTZToLLNuNu_met < 100)
        {
            h_TTZToLLNuNuC_jetmet->Fill(f_TTZToLLNuNu_met, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight / background(f_TTZToLLNuNu_met));
            h_TTZToLLNuNuC_diLp_PT->Fill(f_TTZToLLNuNu_dilpPT, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight / background(f_TTZToLLNuNu_met));
            h_TTZToLLNuNuC_jetpt->Fill(f_TTZToLLNuNu_leadJetpt, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight / background(f_TTZToLLNuNu_met));
            h_TTZToLLNuNuC_jeteta->Fill(f_TTZToLLNuNu_leadJeteta, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight / background(f_TTZToLLNuNu_met));
        }
        else if (f_TTZToLLNuNu_alphamin < 0.1 && f_TTZToLLNuNu_met < 100)
        {
            h_TTZToLLNuNuD_jetmet->Fill(f_TTZToLLNuNu_met, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_TTZToLLNuNuD_diLp_PT->Fill(f_TTZToLLNuNu_dilpPT, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_TTZToLLNuNuD_jetpt->Fill(f_TTZToLLNuNu_leadJetpt, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_TTZToLLNuNuD_jeteta->Fill(f_TTZToLLNuNu_leadJeteta, f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        }
    }

    TTree *T_event6;
    Top_TTZToQQ->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &f_TTZToQQ_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_event6->SetBranchAddress("I_weight", &f_TTZToQQ_weight);
    T_event6->SetBranchAddress("I_nThinJets", &I_TTZToQQ_nThinJets);
    T_event6->SetBranchAddress("f_leadJetpt", &f_TTZToQQ_leadJetpt);
    T_event6->SetBranchAddress("f_leadJeteta", &f_TTZToQQ_leadJeteta);
    T_event6->SetBranchAddress("f_dileptonPT", &f_TTZToQQ_dilpPT);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (I_TTZToQQ_nThinJets < 2)
            continue;
        if (f_TTZToQQ_alphamin > 0.3 && f_TTZToQQ_met > 160 && f_TTZToQQ_met < 800)
        {
            h_TTZToQQA_jetmet->Fill(f_TTZToQQ_met, f_TTZToQQ_weight * TTZToQQWeight / background(f_TTZToQQ_met));
            h_TTZToQQA_diLp_PT->Fill(f_TTZToQQ_dilpPT, f_TTZToQQ_weight * TTZToQQWeight / background(f_TTZToQQ_met));
            h_TTZToQQA_jetpt->Fill(f_TTZToQQ_leadJetpt, f_TTZToQQ_weight * TTZToQQWeight / background(f_TTZToQQ_met));
            h_TTZToQQA_jeteta->Fill(f_TTZToQQ_leadJeteta, f_TTZToQQ_weight * TTZToQQWeight / background(f_TTZToQQ_met));
        }
        else if (f_TTZToQQ_alphamin < 0.1 && f_TTZToQQ_met > 160 && f_TTZToQQ_met < 800)
        {
            h_TTZToQQB_jetmet->Fill(f_TTZToQQ_met, f_TTZToQQ_weight * TTZToQQWeight);
            h_TTZToQQB_diLp_PT->Fill(f_TTZToQQ_dilpPT, f_TTZToQQ_weight * TTZToQQWeight);
            h_TTZToQQB_jetpt->Fill(f_TTZToQQ_leadJetpt, f_TTZToQQ_weight * TTZToQQWeight);
            h_TTZToQQB_jeteta->Fill(f_TTZToQQ_leadJeteta, f_TTZToQQ_weight * TTZToQQWeight);
        }
        else if (f_TTZToQQ_alphamin > 0.3 && f_TTZToQQ_met < 100)
        {
            h_TTZToQQC_jetmet->Fill(f_TTZToQQ_met, f_TTZToQQ_weight * TTZToQQWeight / background(f_TTZToQQ_met));
            h_TTZToQQC_diLp_PT->Fill(f_TTZToQQ_dilpPT, f_TTZToQQ_weight * TTZToQQWeight / background(f_TTZToQQ_met));
            h_TTZToQQC_jetpt->Fill(f_TTZToQQ_leadJetpt, f_TTZToQQ_weight * TTZToQQWeight / background(f_TTZToQQ_met));
            h_TTZToQQC_jeteta->Fill(f_TTZToQQ_leadJeteta, f_TTZToQQ_weight * TTZToQQWeight / background(f_TTZToQQ_met));
        }
        else if (f_TTZToQQ_alphamin < 0.1 && f_TTZToQQ_met < 100)
        {
            h_TTZToQQD_jetmet->Fill(f_TTZToQQ_met, f_TTZToQQ_weight * TTZToQQWeight);
            h_TTZToQQD_diLp_PT->Fill(f_TTZToQQ_dilpPT, f_TTZToQQ_weight * TTZToQQWeight);
            h_TTZToQQD_jetpt->Fill(f_TTZToQQ_leadJetpt, f_TTZToQQ_weight * TTZToQQWeight);
            h_TTZToQQD_jeteta->Fill(f_TTZToQQ_leadJeteta, f_TTZToQQ_weight * TTZToQQWeight);
        }
    }

    h_tW_topA_jetmet->Add(h_tW_antitopA_jetmet);
    h_tW_topA_jetmet->Add(h_TTTo2L2NuA_jetmet);
    h_tW_topA_jetmet->Add(h_TTWJetsToLNuA_jetmet);
    h_tW_topA_jetmet->Add(h_TTWJetsToQQA_jetmet);
    h_tW_topA_jetmet->Add(h_TTZToLLNuNuA_jetmet);
    h_tW_topA_jetmet->Add(h_TTZToQQA_jetmet);

    h_tW_topB_jetmet->Add(h_tW_antitopB_jetmet);
    h_tW_topB_jetmet->Add(h_TTTo2L2NuB_jetmet);
    h_tW_topB_jetmet->Add(h_TTWJetsToLNuB_jetmet);
    h_tW_topB_jetmet->Add(h_TTWJetsToQQB_jetmet);
    h_tW_topB_jetmet->Add(h_TTZToLLNuNuB_jetmet);
    h_tW_topB_jetmet->Add(h_TTZToQQB_jetmet);

    h_tW_topC_jetmet->Add(h_tW_antitopC_jetmet);
    h_tW_topC_jetmet->Add(h_TTTo2L2NuC_jetmet);
    h_tW_topC_jetmet->Add(h_TTWJetsToLNuC_jetmet);
    h_tW_topC_jetmet->Add(h_TTWJetsToQQC_jetmet);
    h_tW_topC_jetmet->Add(h_TTZToLLNuNuC_jetmet);
    h_tW_topC_jetmet->Add(h_TTZToQQC_jetmet);

    h_tW_topD_jetmet->Add(h_tW_antitopD_jetmet);
    h_tW_topD_jetmet->Add(h_TTTo2L2NuD_jetmet);
    h_tW_topD_jetmet->Add(h_TTWJetsToLNuD_jetmet);
    h_tW_topD_jetmet->Add(h_TTWJetsToQQD_jetmet);
    h_tW_topD_jetmet->Add(h_TTZToLLNuNuD_jetmet);
    h_tW_topD_jetmet->Add(h_TTZToQQD_jetmet);

    h_tW_topA_jeteta->Add(h_tW_antitopA_jeteta);
    h_tW_topA_jeteta->Add(h_TTTo2L2NuA_jeteta);
    h_tW_topA_jeteta->Add(h_TTWJetsToLNuA_jeteta);
    h_tW_topA_jeteta->Add(h_TTWJetsToQQA_jeteta);
    h_tW_topA_jeteta->Add(h_TTZToLLNuNuA_jeteta);
    h_tW_topA_jeteta->Add(h_TTZToQQA_jeteta);

    h_tW_topB_jeteta->Add(h_tW_antitopB_jeteta);
    h_tW_topB_jeteta->Add(h_TTTo2L2NuB_jeteta);
    h_tW_topB_jeteta->Add(h_TTWJetsToLNuB_jeteta);
    h_tW_topB_jeteta->Add(h_TTWJetsToQQB_jeteta);
    h_tW_topB_jeteta->Add(h_TTZToLLNuNuB_jeteta);
    h_tW_topB_jeteta->Add(h_TTZToQQB_jeteta);

    h_tW_topC_jeteta->Add(h_tW_antitopC_jeteta);
    h_tW_topC_jeteta->Add(h_TTTo2L2NuC_jeteta);
    h_tW_topC_jeteta->Add(h_TTWJetsToLNuC_jeteta);
    h_tW_topC_jeteta->Add(h_TTWJetsToQQC_jeteta);
    h_tW_topC_jeteta->Add(h_TTZToLLNuNuC_jeteta);
    h_tW_topC_jeteta->Add(h_TTZToQQC_jeteta);

    h_tW_topD_jeteta->Add(h_tW_antitopD_jeteta);
    h_tW_topD_jeteta->Add(h_TTTo2L2NuD_jeteta);
    h_tW_topD_jeteta->Add(h_TTWJetsToLNuD_jeteta);
    h_tW_topD_jeteta->Add(h_TTWJetsToQQD_jeteta);
    h_tW_topD_jeteta->Add(h_TTZToLLNuNuD_jeteta);
    h_tW_topD_jeteta->Add(h_TTZToQQD_jeteta);

    h_tW_topA_jetpt->Add(h_tW_antitopA_jetpt);
    h_tW_topA_jetpt->Add(h_TTTo2L2NuA_jetpt);
    h_tW_topA_jetpt->Add(h_TTWJetsToLNuA_jetpt);
    h_tW_topA_jetpt->Add(h_TTWJetsToQQA_jetpt);
    h_tW_topA_jetpt->Add(h_TTZToLLNuNuA_jetpt);
    h_tW_topA_jetpt->Add(h_TTZToQQA_jetpt);

    h_tW_topB_jetpt->Add(h_tW_antitopB_jetpt);
    h_tW_topB_jetpt->Add(h_TTTo2L2NuB_jetpt);
    h_tW_topB_jetpt->Add(h_TTWJetsToLNuB_jetpt);
    h_tW_topB_jetpt->Add(h_TTWJetsToQQB_jetpt);
    h_tW_topB_jetpt->Add(h_TTZToLLNuNuB_jetpt);
    h_tW_topB_jetpt->Add(h_TTZToQQB_jetpt);

    h_tW_topC_jetpt->Add(h_tW_antitopC_jetpt);
    h_tW_topC_jetpt->Add(h_TTTo2L2NuC_jetpt);
    h_tW_topC_jetpt->Add(h_TTWJetsToLNuC_jetpt);
    h_tW_topC_jetpt->Add(h_TTWJetsToQQC_jetpt);
    h_tW_topC_jetpt->Add(h_TTZToLLNuNuC_jetpt);
    h_tW_topC_jetpt->Add(h_TTZToQQC_jetpt);

    h_tW_topD_jetpt->Add(h_tW_antitopD_jetpt);
    h_tW_topD_jetpt->Add(h_TTTo2L2NuD_jetpt);
    h_tW_topD_jetpt->Add(h_TTWJetsToLNuD_jetpt);
    h_tW_topD_jetpt->Add(h_TTWJetsToQQD_jetpt);
    h_tW_topD_jetpt->Add(h_TTZToLLNuNuD_jetpt);
    h_tW_topD_jetpt->Add(h_TTZToQQD_jetpt);

    h_tW_topA_jetmet->Add(h_tW_antitopA_jetmet);
    h_tW_topA_jetmet->Add(h_TTTo2L2NuA_jetmet);
    h_tW_topA_jetmet->Add(h_TTWJetsToLNuA_jetmet);
    h_tW_topA_jetmet->Add(h_TTWJetsToQQA_jetmet);
    h_tW_topA_jetmet->Add(h_TTZToLLNuNuA_jetmet);
    h_tW_topA_jetmet->Add(h_TTZToQQA_jetmet);

    h_tW_topB_jetmet->Add(h_tW_antitopB_jetmet);
    h_tW_topB_jetmet->Add(h_TTTo2L2NuB_jetmet);
    h_tW_topB_jetmet->Add(h_TTWJetsToLNuB_jetmet);
    h_tW_topB_jetmet->Add(h_TTWJetsToQQB_jetmet);
    h_tW_topB_jetmet->Add(h_TTZToLLNuNuB_jetmet);
    h_tW_topB_jetmet->Add(h_TTZToQQB_jetmet);

    h_tW_topC_jetmet->Add(h_tW_antitopC_jetmet);
    h_tW_topC_jetmet->Add(h_TTTo2L2NuC_jetmet);
    h_tW_topC_jetmet->Add(h_TTWJetsToLNuC_jetmet);
    h_tW_topC_jetmet->Add(h_TTWJetsToQQC_jetmet);
    h_tW_topC_jetmet->Add(h_TTZToLLNuNuC_jetmet);
    h_tW_topC_jetmet->Add(h_TTZToQQC_jetmet);

    h_tW_topD_jetmet->Add(h_tW_antitopD_jetmet);
    h_tW_topD_jetmet->Add(h_TTTo2L2NuD_jetmet);
    h_tW_topD_jetmet->Add(h_TTWJetsToLNuD_jetmet);
    h_tW_topD_jetmet->Add(h_TTWJetsToQQD_jetmet);
    h_tW_topD_jetmet->Add(h_TTZToLLNuNuD_jetmet);
    h_tW_topD_jetmet->Add(h_TTZToQQD_jetmet);

    h_tW_topA_diLp_PT->Add(h_tW_antitopA_diLp_PT);
    h_tW_topA_diLp_PT->Add(h_TTTo2L2NuA_diLp_PT);
    h_tW_topA_diLp_PT->Add(h_TTWJetsToLNuA_diLp_PT);
    h_tW_topA_diLp_PT->Add(h_TTWJetsToQQA_diLp_PT);
    h_tW_topA_diLp_PT->Add(h_TTZToLLNuNuA_diLp_PT);
    h_tW_topA_diLp_PT->Add(h_TTZToQQA_diLp_PT);

    h_tW_topB_diLp_PT->Add(h_tW_antitopB_diLp_PT);
    h_tW_topB_diLp_PT->Add(h_TTTo2L2NuB_diLp_PT);
    h_tW_topB_diLp_PT->Add(h_TTWJetsToLNuB_diLp_PT);
    h_tW_topB_diLp_PT->Add(h_TTWJetsToQQB_diLp_PT);
    h_tW_topB_diLp_PT->Add(h_TTZToLLNuNuB_diLp_PT);
    h_tW_topB_diLp_PT->Add(h_TTZToQQB_diLp_PT);

    h_tW_topC_diLp_PT->Add(h_tW_antitopC_diLp_PT);
    h_tW_topC_diLp_PT->Add(h_TTTo2L2NuC_diLp_PT);
    h_tW_topC_diLp_PT->Add(h_TTWJetsToLNuC_diLp_PT);
    h_tW_topC_diLp_PT->Add(h_TTWJetsToQQC_diLp_PT);
    h_tW_topC_diLp_PT->Add(h_TTZToLLNuNuC_diLp_PT);
    h_tW_topC_diLp_PT->Add(h_TTZToQQC_diLp_PT);

    h_tW_topD_diLp_PT->Add(h_tW_antitopD_diLp_PT);
    h_tW_topD_diLp_PT->Add(h_TTTo2L2NuD_diLp_PT);
    h_tW_topD_diLp_PT->Add(h_TTWJetsToLNuD_diLp_PT);
    h_tW_topD_diLp_PT->Add(h_TTWJetsToQQD_diLp_PT);
    h_tW_topD_diLp_PT->Add(h_TTZToLLNuNuD_diLp_PT);
    h_tW_topD_diLp_PT->Add(h_TTZToQQD_diLp_PT);

    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(3, 2);

    c1->cd(1);
    gStyle->SetOptStat(0);
    h_tW_topA_diLp_PT->SetTitle("");
    h_tW_topA_diLp_PT->SetXTitle("dilepton PT");
    h_tW_topA_diLp_PT->SetYTitle("Normalized");
    h_tW_topA_diLp_PT->SetLineWidth(2);
    h_tW_topB_diLp_PT->SetLineWidth(2);
    h_tW_topA_diLp_PT->SetLineColor(kOrange + 7);
    h_tW_topB_diLp_PT->SetLineColor(kGray + 3);
    h_tW_topB_diLp_PT->Draw("hist&&e");
    h_tW_topA_diLp_PT->Draw("hist&&e&&same");
    TLegend *l3 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.04);
    l3->AddEntry(h_tW_topA_diLp_PT, "Region A / Ratio", "l");
    l3->AddEntry(h_tW_topB_diLp_PT, "Region B ", "l");
    l3->Draw();
    c1->cd(4);
    gStyle->SetOptStat(0);
    h_tW_topC_diLp_PT->SetTitle("");
    h_tW_topC_diLp_PT->SetXTitle("dilepton PT");
    h_tW_topC_diLp_PT->SetYTitle("Normalized");
    h_tW_topC_diLp_PT->SetLineWidth(2);
    h_tW_topD_diLp_PT->SetLineWidth(2);
    h_tW_topC_diLp_PT->SetLineColor(kOrange + 7);
    h_tW_topD_diLp_PT->SetLineColor(kGray + 3);
    h_tW_topD_diLp_PT->Draw("hist&&e");
    h_tW_topC_diLp_PT->Draw("hist&&e&&same");
    TLegend *l4 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.04);
    l4->AddEntry(h_tW_topC_diLp_PT, "Region C / Ratio", "l");
    l4->AddEntry(h_tW_topD_diLp_PT, "Region D ", "l");
    l4->Draw();
    c1->cd(2);
    gStyle->SetOptStat(0);
    h_tW_topA_jetpt->SetTitle("");
    h_tW_topA_jetpt->SetXTitle("leading Jet PT");
    h_tW_topA_jetpt->SetYTitle("Normalized");
    h_tW_topA_jetpt->SetLineWidth(2);
    h_tW_topB_jetpt->SetLineWidth(2);
    h_tW_topA_jetpt->SetLineColor(kOrange + 7);
    h_tW_topB_jetpt->SetLineColor(kGray + 3);
    h_tW_topB_jetpt->Draw("hist&&e");
    h_tW_topA_jetpt->Draw("hist&&e&&same");
    TLegend *l5 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l5->SetBorderSize(0);
    l5->SetTextSize(0.04);
    l5->AddEntry(h_tW_topA_jetpt, "Region A / Ratio", "l");
    l5->AddEntry(h_tW_topB_jetpt, "Region B ", "l");
    l5->Draw();
    c1->cd(5);
    gStyle->SetOptStat(0);
    h_tW_topC_jetpt->SetTitle("");
    h_tW_topC_jetpt->SetXTitle("leading Jet PT");
    h_tW_topC_jetpt->SetYTitle("Normalized");
    h_tW_topC_jetpt->SetLineWidth(2);
    h_tW_topD_jetpt->SetLineWidth(2);
    h_tW_topC_jetpt->SetLineColor(kOrange + 7);
    h_tW_topD_jetpt->SetLineColor(kGray + 3);
    h_tW_topD_jetpt->Draw("hist&&e");
    h_tW_topC_jetpt->Draw("hist&&e&&same");
    TLegend *l6 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l6->SetBorderSize(0);
    l6->SetTextSize(0.04);
    l6->AddEntry(h_tW_topC_jetpt, "Region C / Ratio", "l");
    l6->AddEntry(h_tW_topD_jetpt, "Region D ", "l");
    l6->Draw();
    c1->cd(3);
    gStyle->SetOptStat(0);
    h_tW_topA_jeteta->SetTitle("");
    h_tW_topA_jeteta->SetXTitle("leading Jet eta");
    h_tW_topA_jeteta->SetYTitle("Normalized");
    h_tW_topA_jeteta->SetLineWidth(2);
    h_tW_topB_jeteta->SetLineWidth(2);
    h_tW_topA_jeteta->SetLineColor(kOrange + 7);
    h_tW_topB_jeteta->SetLineColor(kGray + 3);
    h_tW_topA_jeteta->Draw("hist&&e");
    h_tW_topB_jeteta->Draw("hist&&e&&same");
    
    TLegend *l7 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l7->SetBorderSize(0);
    l7->SetTextSize(0.04);
    l7->AddEntry(h_tW_topA_jeteta, "Region A / Ratio", "l");
    l7->AddEntry(h_tW_topB_jeteta, "Region B ", "l");
    l7->Draw();
    c1->cd(6);
    gStyle->SetOptStat(0);
    h_tW_topC_jeteta->SetTitle("");
    h_tW_topC_jeteta->SetXTitle("leading Jet eta");
    h_tW_topC_jeteta->SetYTitle("Normalized");
    h_tW_topC_jeteta->SetLineWidth(2);
    h_tW_topD_jeteta->SetLineWidth(2);
    h_tW_topC_jeteta->SetLineColor(kOrange + 7);
    h_tW_topD_jeteta->SetLineColor(kGray + 3);
    h_tW_topC_jeteta->Draw("hist&&e");
    h_tW_topD_jeteta->Draw("hist&&e&&same");
    
    

    TLegend *l8 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l8->SetBorderSize(0);
    l8->SetTextSize(0.04);
    l8->AddEntry(h_tW_topC_jeteta, "Region C / Ratio", "l");
    l8->AddEntry(h_tW_topD_jeteta, "Region D ", "l");
    l8->Draw();
}
