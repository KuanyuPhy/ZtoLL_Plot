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
#include "./../lib/Cross_section.h"
#include "./../lib/setNCUStyle.C"
using namespace RooFit;
void ee_Top_fake_rate_study()
{

    //setNCUStyle(true);
    TFile *Top_TTTo2L2Nu = new TFile("./../../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
    TFile *Top_TTWJetsToLNu = new TFile("./../../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQ = new TFile("./../../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToLLNuNu = new TFile("./../../../root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_TTZToQQ = new TFile("./../../../root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_tW_antitop = new TFile("./../../../root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_top = new TFile("./../../../root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)Top_TTTo2L2Nu->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNu->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQ->Get("Event_Variable/h_totevent"));
    TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNu->Get("Event_Variable/h_totevent"));
    TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQ->Get("Event_Variable/h_totevent"));
    TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitop->Get("Event_Variable/h_totevent"));
    TH1D *tW_top_sumevt = ((TH1D *)Top_tW_top->Get("Event_Variable/h_totevent"));

    int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();
    int TTWJetsToLNu_totevt = TTWJetsToLNu_sumevt->Integral();
    int TTWJetsToQQ_totevt = TTWJetsToQQ_sumevt->Integral();
    int TTZToLLNuNu_totevt = TTZToLLNuNu_sumevt->Integral();
    int TTZToQQ_totevt = TTZToQQ_sumevt->Integral();
    int tW_antitop_totevt = tW_antitop_sumevt->Integral();
    int tW_top_totevt = tW_top_sumevt->Integral();

    //----------------------------------------------------------------------
    // Create Histrogram: PT, eta, NTracks
    //----------------------------------------------------------------------
    TH1F *h_tW_top_hev_emergjetpt = new TH1F("h_tW_top_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_tW_top_hev_emergjetpt->Sumw2();
    TH1F *h_tW_antitop_hev_emergjetpt = new TH1F("h_tW_antitop_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_tW_antitop_hev_emergjetpt->Sumw2();
    TH1F *h_TTTo2L2Nu_hev_emergjetpt = new TH1F("h_TTTo2L2Nu_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_hev_emergjetpt->Sumw2();
    TH1F *h_TTWJetsToLNu_hev_emergjetpt = new TH1F("h_TTWJetsToLNu_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTWJetsToLNu_hev_emergjetpt->Sumw2();
    TH1F *h_TWJetsToQQ_hev_emergjetpt = new TH1F("h_TWJetsToQQ_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TWJetsToQQ_hev_emergjetpt->Sumw2();
    TH1F *h_TTZToLLNuNu_hev_emergjetpt = new TH1F("h_TTZToLLNuNu_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTZToLLNuNu_hev_emergjetpt->Sumw2();
    TH1F *h_TTZToQQ_hev_emergjetpt = new TH1F("h_TTZToQQ_hev_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTZToQQ_hev_emergjetpt->Sumw2();

    TH1F *h_tW_top_hev_emergjetpt_cutalpha = new TH1F("h_tW_top_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_tW_top_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_tW_antitop_hev_emergjetpt_cutalpha = new TH1F("h_tW_antitop_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_tW_antitop_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTTo2L2Nu_hev_emergjetpt_cutalpha = new TH1F("h_TTTo2L2Nu_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTWJetsToLNu_hev_emergjetpt_cutalpha = new TH1F("h_TTWJetsToLNu_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTWJetsToLNu_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TWJetsToQQ_hev_emergjetpt_cutalpha = new TH1F("h_TWJetsToQQ_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TWJetsToQQ_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTZToLLNuNu_hev_emergjetpt_cutalpha = new TH1F("h_TTZToLLNuNu_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTZToLLNuNu_hev_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTZToQQ_hev_emergjetpt_cutalpha = new TH1F("h_TTZToQQ_hev_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTZToQQ_hev_emergjetpt_cutalpha->Sumw2();

    TH1F *h_tW_top_light_emergjetpt = new TH1F("h_tW_top_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_tW_top_light_emergjetpt->Sumw2();
    TH1F *h_tW_antitop_light_emergjetpt = new TH1F("h_tW_antitop_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_tW_antitop_light_emergjetpt->Sumw2();
    TH1F *h_TTTo2L2Nu_light_emergjetpt = new TH1F("h_TTTo2L2Nu_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_light_emergjetpt->Sumw2();
    TH1F *h_TTWJetsToLNu_light_emergjetpt = new TH1F("h_TTWJetsToLNu_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTWJetsToLNu_light_emergjetpt->Sumw2();
    TH1F *h_TWJetsToQQ_light_emergjetpt = new TH1F("h_TWJetsToQQ_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TWJetsToQQ_light_emergjetpt->Sumw2();
    TH1F *h_TTZToLLNuNu_light_emergjetpt = new TH1F("h_TTZToLLNuNu_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTZToLLNuNu_light_emergjetpt->Sumw2();
    TH1F *h_TTZToQQ_light_emergjetpt = new TH1F("h_TTZToQQ_light_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTZToQQ_light_emergjetpt->Sumw2();

    TH1F *h_tW_top_light_emergjetpt_cutalpha = new TH1F("h_tW_top_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_tW_top_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_tW_antitop_light_emergjetpt_cutalpha = new TH1F("h_tW_antitop_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_tW_antitop_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTTo2L2Nu_light_emergjetpt_cutalpha = new TH1F("h_TTTo2L2Nu_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTWJetsToLNu_light_emergjetpt_cutalpha = new TH1F("h_TTWJetsToLNu_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTWJetsToLNu_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TWJetsToQQ_light_emergjetpt_cutalpha = new TH1F("h_TWJetsToQQ_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TWJetsToQQ_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTZToLLNuNu_light_emergjetpt_cutalpha = new TH1F("h_TTZToLLNuNu_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTZToLLNuNu_light_emergjetpt_cutalpha->Sumw2();
    TH1F *h_TTZToQQ_light_emergjetpt_cutalpha = new TH1F("h_TTZToQQ_light_emergjetpt_cutalpha", "emerging jet pt", 50, 0, 500);
    h_TTZToQQ_light_emergjetpt_cutalpha->Sumw2();

    TH1F *h_tW_top_hev_emergjetEta = new TH1F("h_tW_top_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_tW_top_hev_emergjetEta->Sumw2();
    TH1F *h_tW_antitop_hev_emergjetEta = new TH1F("h_tW_antitop_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_tW_antitop_hev_emergjetEta->Sumw2();
    TH1F *h_TTTo2L2Nu_hev_emergjetEta = new TH1F("h_TTTo2L2Nu_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTTo2L2Nu_hev_emergjetEta->Sumw2();
    TH1F *h_TTWJetsToLNu_hev_emergjetEta = new TH1F("h_TTWJetsToLNu_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTWJetsToLNu_hev_emergjetEta->Sumw2();
    TH1F *h_TWJetsToQQ_hev_emergjetEta = new TH1F("h_TWJetsToQQ_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TWJetsToQQ_hev_emergjetEta->Sumw2();
    TH1F *h_TTZToLLNuNu_hev_emergjetEta = new TH1F("h_TTZToLLNuNu_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTZToLLNuNu_hev_emergjetEta->Sumw2();
    TH1F *h_TTZToQQ_hev_emergjetEta = new TH1F("h_TTZToQQ_hev_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTZToQQ_hev_emergjetEta->Sumw2();

    TH1F *h_tW_top_hev_emergjetEta_cutalpha = new TH1F("h_tW_top_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_tW_top_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_tW_antitop_hev_emergjetEta_cutalpha = new TH1F("h_tW_antitop_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_tW_antitop_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TTTo2L2Nu_hev_emergjetEta_cutalpha = new TH1F("h_TTTo2L2Nu_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTTo2L2Nu_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TTWJetsToLNu_hev_emergjetEta_cutalpha = new TH1F("h_TTWJetsToLNu_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTWJetsToLNu_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TWJetsToQQ_hev_emergjetEta_cutalpha = new TH1F("h_TWJetsToQQ_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TWJetsToQQ_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TTZToLLNuNu_hev_emergjetEta_cutalpha = new TH1F("h_TTZToLLNuNu_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTZToLLNuNu_hev_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TTZToQQ_hev_emergjetEta_cutalpha = new TH1F("h_TTZToQQ_hev_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTZToQQ_hev_emergjetEta_cutalpha->Sumw2();

    TH1F *h_tW_top_light_emergjetEta = new TH1F("h_tW_top_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_tW_top_light_emergjetEta->Sumw2();
    TH1F *h_tW_antitop_light_emergjetEta = new TH1F("h_tW_antitop_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_tW_antitop_light_emergjetEta->Sumw2();
    TH1F *h_TTTo2L2Nu_light_emergjetEta = new TH1F("h_TTTo2L2Nu_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTTo2L2Nu_light_emergjetEta->Sumw2();
    TH1F *h_TTWJetsToLNu_light_emergjetEta = new TH1F("h_TTWJetsToLNu_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTWJetsToLNu_light_emergjetEta->Sumw2();
    TH1F *h_TWJetsToQQ_light_emergjetEta = new TH1F("h_TWJetsToQQ_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TWJetsToQQ_light_emergjetEta->Sumw2();
    TH1F *h_TTZToLLNuNu_light_emergjetEta = new TH1F("h_TTZToLLNuNu_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTZToLLNuNu_light_emergjetEta->Sumw2();
    TH1F *h_TTZToQQ_light_emergjetEta = new TH1F("h_TTZToQQ_light_emergjetEta", "emerging jet Eta", 60, -3, 3);
    h_TTZToQQ_light_emergjetEta->Sumw2();

    TH1F *h_tW_top_light_emergjetEta_cutalpha = new TH1F("h_tW_top_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_tW_top_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_tW_antitop_light_emergjetEta_cutalpha = new TH1F("h_tW_antitop_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_tW_antitop_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TTTo2L2Nu_light_emergjetEta_cutalpha = new TH1F("h_TTTo2L2Nu_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTTo2L2Nu_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TTWJetsToLNu_light_emergjetEta_cutalpha = new TH1F("h_TTWJetsToLNu_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTWJetsToLNu_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TWJetsToQQ_light_emergjetEta_cutalpha = new TH1F("h_TWJetsToQQ_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TWJetsToQQ_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TTZToLLNuNu_light_emergjetEta_cutalpha = new TH1F("h_TTZToLLNuNu_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTZToLLNuNu_light_emergjetEta_cutalpha->Sumw2();
    TH1F *h_TTZToQQ_light_emergjetEta_cutalpha = new TH1F("h_TTZToQQ_light_emergjetEta_cutalpha", "emerging jet Eta", 60, -3, 3);
    h_TTZToQQ_light_emergjetEta_cutalpha->Sumw2();

    TH1F *h_tW_top_hev_emergjetnTrack = new TH1F("h_tW_top_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_tW_top_hev_emergjetnTrack->Sumw2();
    TH1F *h_tW_antitop_hev_emergjetnTrack = new TH1F("h_tW_antitop_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_tW_antitop_hev_emergjetnTrack->Sumw2();
    TH1F *h_TTTo2L2Nu_hev_emergjetnTrack = new TH1F("h_TTTo2L2Nu_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTTo2L2Nu_hev_emergjetnTrack->Sumw2();
    TH1F *h_TTWJetsToLNu_hev_emergjetnTrack = new TH1F("h_TTWJetsToLNu_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTWJetsToLNu_hev_emergjetnTrack->Sumw2();
    TH1F *h_TWJetsToQQ_hev_emergjetnTrack = new TH1F("h_TWJetsToQQ_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TWJetsToQQ_hev_emergjetnTrack->Sumw2();
    TH1F *h_TTZToLLNuNu_hev_emergjetnTrack = new TH1F("h_TTZToLLNuNu_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTZToLLNuNu_hev_emergjetnTrack->Sumw2();
    TH1F *h_TTZToQQ_hev_emergjetnTrack = new TH1F("h_TTZToQQ_hev_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTZToQQ_hev_emergjetnTrack->Sumw2();

    TH1F *h_tW_top_hev_emergjetnTrack_cutalpha = new TH1F("h_tW_top_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_tW_top_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_tW_antitop_hev_emergjetnTrack_cutalpha = new TH1F("h_tW_antitop_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_tW_antitop_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_TTTo2L2Nu_hev_emergjetnTrack_cutalpha = new TH1F("h_TTTo2L2Nu_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_TTTo2L2Nu_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_TTWJetsToLNu_hev_emergjetnTrack_cutalpha = new TH1F("h_TTWJetsToLNu_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_TTWJetsToLNu_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_TWJetsToQQ_hev_emergjetnTrack_cutalpha = new TH1F("h_TWJetsToQQ_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_TWJetsToQQ_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_TTZToLLNuNu_hev_emergjetnTrack_cutalpha = new TH1F("h_TTZToLLNuNu_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_TTZToLLNuNu_hev_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_TTZToQQ_hev_emergjetnTrack_cutalpha = new TH1F("h_TTZToQQ_hev_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_TTZToQQ_hev_emergjetnTrack_cutalpha->Sumw2();

    TH1F *h_tW_top_light_emergjetnTrack = new TH1F("h_tW_top_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_tW_top_light_emergjetnTrack->Sumw2();
    TH1F *h_tW_antitop_light_emergjetnTrack = new TH1F("h_tW_antitop_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_tW_antitop_light_emergjetnTrack->Sumw2();
    TH1F *h_TTTo2L2Nu_light_emergjetnTrack = new TH1F("h_TTTo2L2Nu_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTTo2L2Nu_light_emergjetnTrack->Sumw2();
    TH1F *h_TTWJetsToLNu_light_emergjetnTrack = new TH1F("h_TTWJetsToLNu_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTWJetsToLNu_light_emergjetnTrack->Sumw2();
    TH1F *h_TWJetsToQQ_light_emergjetnTrack = new TH1F("h_TWJetsToQQ_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TWJetsToQQ_light_emergjetnTrack->Sumw2();
    TH1F *h_TTZToLLNuNu_light_emergjetnTrack = new TH1F("h_TTZToLLNuNu_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTZToLLNuNu_light_emergjetnTrack->Sumw2();
    TH1F *h_TTZToQQ_light_emergjetnTrack = new TH1F("h_TTZToQQ_light_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTZToQQ_light_emergjetnTrack->Sumw2();

    TH1F *h_tW_top_light_emergjetnTrack_cutalpha = new TH1F("h_tW_top_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_tW_top_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_tW_antitop_light_emergjetnTrack_cutalpha = new TH1F("h_tW_antitop_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_tW_antitop_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_TTTo2L2Nu_light_emergjetnTrack_cutalpha = new TH1F("h_TTTo2L2Nu_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_TTTo2L2Nu_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_TTWJetsToLNu_light_emergjetnTrack_cutalpha = new TH1F("h_TTWJetsToLNu_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_TTWJetsToLNu_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_TWJetsToQQ_light_emergjetnTrack_cutalpha = new TH1F("h_TWJetsToQQ_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_TWJetsToQQ_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_TTZToLLNuNu_light_emergjetnTrack_cutalpha = new TH1F("h_TTZToLLNuNu_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_TTZToLLNuNu_light_emergjetnTrack_cutalpha->Sumw2();
    TH1F *h_TTZToQQ_light_emergjetnTrack_cutalpha = new TH1F("h_TTZToQQ_light_emergjetnTrack_cutalpha", "emerging jet nTrack", 50, 0, 50);
    h_TTZToQQ_light_emergjetnTrack_cutalpha->Sumw2();

    TH1F *h_tW_top_emergjethadronflavor = new TH1F("h_tW_top_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_tW_top_emergjethadronflavor->Sumw2();
    TH1F *h_tW_antitop_emergjethadronflavor = new TH1F("h_tW_antitop_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_tW_antitop_emergjethadronflavor->Sumw2();
    TH1F *h_TTTo2L2Nu_emergjethadronflavor = new TH1F("h_TTTo2L2Nu_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_TTTo2L2Nu_emergjethadronflavor->Sumw2();
    TH1F *h_TTWJetsToLNu_emergjethadronflavor = new TH1F("h_TTWJetsToLNu_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_TTWJetsToLNu_emergjethadronflavor->Sumw2();
    TH1F *h_TWJetsToQQ_emergjethadronflavor = new TH1F("h_TWJetsToQQ_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_TWJetsToQQ_emergjethadronflavor->Sumw2();
    TH1F *h_TTZToLLNuNu_emergjethadronflavor = new TH1F("h_TTZToLLNuNu_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_TTZToLLNuNu_emergjethadronflavor->Sumw2();
    TH1F *h_TTZToQQ_emergjethadronflavor = new TH1F("h_TTZToQQ_emergjethadronflavor", "emerging Jet hadronflavor", 6, 0, 6);
    h_TTZToQQ_emergjethadronflavor->Sumw2();

    Double_t f_tW_top_alphamin, f_tW_antitop_alphamin, f_TTTo2L2Nu_alphamin, f_TTWJetsToLNu_alphamin,
        f_TTWJetsToQQ_alphamin, f_TTZToLLNuNu_alphamin, f_TTZToQQ_alphamin;

    Float_t f_tW_top_met, f_tW_antitop_met, f_TTTo2L2Nu_met, f_TTWJetsToLNu_met,
        f_TTWJetsToQQ_met, f_TTZToLLNuNu_met, f_TTZToQQ_met;

    Int_t I_tW_top_nThinJets, I_tW_antitop_nThinJets, I_TTTo2L2Nu_nThinJets, I_TTWJetsToLNu_nThinJets, I_TTWJetsToQQ_nThinJets,
        I_TTZToLLNuNu_nThinJets, I_TTZToQQ_nThinJets;

    Int_t f_tW_top_weight, f_tW_antitop_weight, f_TTTo2L2Nu_weight, f_TTWJetsToLNu_weight, f_TTWJetsToQQ_weight,
        f_TTZToLLNuNu_weight, f_TTZToQQ_weight;

    vector<float> *v_tW_top_alpha = new vector<float>();
    vector<float> *v_tW_antitop_alpha = new vector<float>();
    vector<float> *v_TTTo2L2Nu_alpha = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha = new vector<float>();
    vector<float> *v_TWJetsToQQ_alpha = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha = new vector<float>();
    vector<float> *v_TTZToQQ_alpha = new vector<float>();

    v_tW_top_alpha->clear();
    v_tW_antitop_alpha->clear();
    v_TTTo2L2Nu_alpha->clear();
    v_TTWJetsToLNu_alpha->clear();
    v_TWJetsToQQ_alpha->clear();
    v_TTZToLLNuNu_alpha->clear();
    v_TTZToQQ_alpha->clear();

    vector<float> *v_tW_top_fakeJetPt = new vector<float>();
    vector<float> *v_tW_antitop_fakeJetPt = new vector<float>();
    vector<float> *v_TTTo2L2Nu_fakeJetPt = new vector<float>();
    vector<float> *v_TTWJetsToLNu_fakeJetPt = new vector<float>();
    vector<float> *v_TWJetsToQQ_fakeJetPt = new vector<float>();
    vector<float> *v_TTZToLLNuNu_fakeJetPt = new vector<float>();
    vector<float> *v_TTZToQQ_fakeJetPt = new vector<float>();

    v_tW_top_fakeJetPt->clear();
    v_tW_antitop_fakeJetPt->clear();
    v_TTTo2L2Nu_fakeJetPt->clear();
    v_TTWJetsToLNu_fakeJetPt->clear();
    v_TWJetsToQQ_fakeJetPt->clear();
    v_TTZToLLNuNu_fakeJetPt->clear();
    v_TTZToQQ_fakeJetPt->clear();

    vector<float> *v_tW_top_fakeJetEta = new vector<float>();
    vector<float> *v_tW_antitop_fakeJetEta = new vector<float>();
    vector<float> *v_TTTo2L2Nu_fakeJetEta = new vector<float>();
    vector<float> *v_TTWJetsToLNu_fakeJetEta = new vector<float>();
    vector<float> *v_TWJetsToQQ_fakeJetEta = new vector<float>();
    vector<float> *v_TTZToLLNuNu_fakeJetEta = new vector<float>();
    vector<float> *v_TTZToQQ_fakeJetEta = new vector<float>();

    v_tW_top_fakeJetEta->clear();
    v_tW_antitop_fakeJetEta->clear();
    v_TTTo2L2Nu_fakeJetEta->clear();
    v_TTWJetsToLNu_fakeJetEta->clear();
    v_TWJetsToQQ_fakeJetEta->clear();
    v_TTZToLLNuNu_fakeJetEta->clear();
    v_TTZToQQ_fakeJetEta->clear();

    vector<float> *v_tW_top_JetnTracks = new vector<float>();
    vector<float> *v_tW_antitop_JetnTracks = new vector<float>();
    vector<float> *v_TTTo2L2Nu_JetnTracks = new vector<float>();
    vector<float> *v_TTWJetsToLNu_JetnTracks = new vector<float>();
    vector<float> *v_TWJetsToQQ_JetnTracks = new vector<float>();
    vector<float> *v_TTZToLLNuNu_JetnTracks = new vector<float>();
    vector<float> *v_TTZToQQ_JetnTracks = new vector<float>();

    v_tW_top_JetnTracks->clear();
    v_tW_antitop_JetnTracks->clear();
    v_TTTo2L2Nu_JetnTracks->clear();
    v_TTWJetsToLNu_JetnTracks->clear();
    v_TWJetsToQQ_JetnTracks->clear();
    v_TTZToLLNuNu_JetnTracks->clear();
    v_TTZToQQ_JetnTracks->clear();

    vector<int> *v_tW_top_Jethadronflavor = new vector<int>();
    vector<int> *v_tW_antitop_Jethadronflavor = new vector<int>();
    vector<int> *v_TTTo2L2Nu_Jethadronflavor = new vector<int>();
    vector<int> *v_TTWJetsToLNu_Jethadronflavor = new vector<int>();
    vector<int> *v_TWJetsToQQ_Jethadronflavor = new vector<int>();
    vector<int> *v_TTZToLLNuNu_Jethadronflavor = new vector<int>();
    vector<int> *v_TTZToQQ_Jethadronflavor = new vector<int>();

    v_tW_top_Jethadronflavor->clear();
    v_tW_antitop_Jethadronflavor->clear();
    v_TTTo2L2Nu_Jethadronflavor->clear();
    v_TTWJetsToLNu_Jethadronflavor->clear();
    v_TWJetsToQQ_Jethadronflavor->clear();
    v_TTZToLLNuNu_Jethadronflavor->clear();
    v_TTZToQQ_Jethadronflavor->clear();

    //---------------------
    // Define the HTWeight
    //---------------------
    float ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000;
    float ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000;
    float TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTTo2L2Nu / (TTTo2L2Nu_totevt)) * 1000;
    float TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000;
    float TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000;
    float TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000;
    float TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000;

    TTree *T_event;
    Top_tW_top->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &f_tW_top_weight);
    T_event->SetBranchAddress("f_alphamin", &f_tW_top_alphamin);
    T_event->SetBranchAddress("f_Met", &f_tW_top_met);
    T_event->SetBranchAddress("v_fakeJethadronflavor", &v_tW_top_Jethadronflavor);
    T_event->SetBranchAddress("v_fakeJetPt", &v_tW_top_fakeJetPt);
    T_event->SetBranchAddress("v_fakealpha", &v_tW_top_alpha);
    T_event->SetBranchAddress("v_fakeJetEta", &v_tW_top_fakeJetEta);
    T_event->SetBranchAddress("v_N_Tracks", &v_tW_top_JetnTracks);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        for (int i = 0; i < v_tW_top_Jethadronflavor->size(); i++)
        {
            h_tW_top_emergjethadronflavor->Fill((*v_tW_top_Jethadronflavor)[i], f_tW_top_weight * ST_tW_topWeight);
            if ((*v_tW_top_Jethadronflavor)[i] == 4 || (*v_tW_top_Jethadronflavor)[i] == 5)
            {
                h_tW_top_hev_emergjetpt->Fill((*v_tW_top_fakeJetPt)[i], f_tW_top_weight * ST_tW_topWeight);
                h_tW_top_hev_emergjetEta->Fill((*v_tW_top_fakeJetEta)[i], f_tW_top_weight * ST_tW_topWeight);
                h_tW_top_hev_emergjetnTrack->Fill((*v_tW_top_JetnTracks)[i], f_tW_top_weight * ST_tW_topWeight);
                if ((*v_tW_top_alpha)[i] <=0.35)
                {
                    h_tW_top_hev_emergjetpt_cutalpha->Fill((*v_tW_top_fakeJetPt)[i], f_tW_top_weight * ST_tW_topWeight);
                    h_tW_top_hev_emergjetEta_cutalpha->Fill((*v_tW_top_fakeJetEta)[i], f_tW_top_weight * ST_tW_topWeight);
                    h_tW_top_hev_emergjetnTrack_cutalpha->Fill((*v_tW_top_JetnTracks)[i], f_tW_top_weight * ST_tW_topWeight);
                }
            }
            else
            {
                h_tW_top_light_emergjetpt->Fill((*v_tW_top_fakeJetPt)[i], f_tW_top_weight * ST_tW_topWeight);
                h_tW_top_light_emergjetEta->Fill((*v_tW_top_fakeJetEta)[i], f_tW_top_weight * ST_tW_topWeight);
                h_tW_top_light_emergjetnTrack->Fill((*v_tW_top_JetnTracks)[i], f_tW_top_weight * ST_tW_topWeight);
                if ((*v_tW_top_alpha)[i] <=0.35)
                {
                    h_tW_top_light_emergjetpt_cutalpha->Fill((*v_tW_top_fakeJetPt)[i], f_tW_top_weight * ST_tW_topWeight);
                    h_tW_top_light_emergjetEta_cutalpha->Fill((*v_tW_top_fakeJetEta)[i], f_tW_top_weight * ST_tW_topWeight);
                    h_tW_top_light_emergjetnTrack_cutalpha->Fill((*v_tW_top_JetnTracks)[i], f_tW_top_weight * ST_tW_topWeight);
                }
            }
        }
    }
    TTree *T_event1;
    Top_tW_antitop->GetObject("T_event", T_event1);
    T_event1->SetBranchAddress("f_alphamin", &f_tW_antitop_alphamin);
    T_event1->SetBranchAddress("f_Met", &f_tW_antitop_met);
    T_event1->SetBranchAddress("I_weight", &f_tW_antitop_weight);
    T_event1->SetBranchAddress("I_nThinJets", &I_tW_antitop_nThinJets);
    T_event1->SetBranchAddress("v_fakeJethadronflavor", &v_tW_antitop_Jethadronflavor);
    T_event1->SetBranchAddress("v_fakeJetPt", &v_tW_antitop_fakeJetPt);
    T_event1->SetBranchAddress("v_fakealpha", &v_tW_antitop_alpha);
    T_event1->SetBranchAddress("v_fakeJetEta", &v_tW_antitop_fakeJetEta);
    T_event1->SetBranchAddress("v_N_Tracks", &v_tW_antitop_JetnTracks);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        for (int i = 0; i < v_tW_antitop_Jethadronflavor->size(); i++)
        {
            h_tW_antitop_emergjethadronflavor->Fill((*v_tW_antitop_Jethadronflavor)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
            if ((*v_tW_antitop_Jethadronflavor)[i] == 4 || (*v_tW_antitop_Jethadronflavor)[i] == 5)
            {
                h_tW_antitop_hev_emergjetpt->Fill((*v_tW_antitop_fakeJetPt)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                h_tW_antitop_hev_emergjetEta->Fill((*v_tW_antitop_fakeJetEta)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                h_tW_antitop_hev_emergjetnTrack->Fill((*v_tW_antitop_JetnTracks)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                if ((*v_tW_antitop_alpha)[i] <=0.35)
                {
                    h_tW_antitop_hev_emergjetpt_cutalpha->Fill((*v_tW_antitop_fakeJetPt)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                    h_tW_antitop_hev_emergjetEta_cutalpha->Fill((*v_tW_antitop_fakeJetEta)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                    h_tW_antitop_hev_emergjetnTrack_cutalpha->Fill((*v_tW_antitop_JetnTracks)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                }
            }
            else
            {
                h_tW_antitop_light_emergjetpt->Fill((*v_tW_antitop_fakeJetPt)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                h_tW_antitop_light_emergjetEta->Fill((*v_tW_antitop_fakeJetEta)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                h_tW_antitop_light_emergjetnTrack->Fill((*v_tW_antitop_JetnTracks)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                if ((*v_tW_antitop_alpha)[i] <=0.35)
                {
                    h_tW_antitop_light_emergjetpt_cutalpha->Fill((*v_tW_antitop_fakeJetPt)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                    h_tW_antitop_light_emergjetEta_cutalpha->Fill((*v_tW_antitop_fakeJetEta)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                    h_tW_antitop_light_emergjetnTrack_cutalpha->Fill((*v_tW_antitop_JetnTracks)[i], f_tW_antitop_weight * ST_tW_antitopWeight);
                }
            }
        }
    }

    TTree *T_event2;
    Top_TTTo2L2Nu->GetObject("T_event", T_event2);
    T_event2->SetBranchAddress("f_alphamin", &f_TTTo2L2Nu_alphamin);
    T_event2->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_event2->SetBranchAddress("I_weight", &f_TTTo2L2Nu_weight);
    T_event2->SetBranchAddress("v_fakeJethadronflavor", &v_TTTo2L2Nu_Jethadronflavor);
    T_event2->SetBranchAddress("v_fakeJetPt", &v_TTTo2L2Nu_fakeJetPt);
    T_event2->SetBranchAddress("v_fakealpha", &v_TTTo2L2Nu_alpha);
    T_event2->SetBranchAddress("v_fakeJetEta", &v_TTTo2L2Nu_fakeJetEta);
    T_event2->SetBranchAddress("v_N_Tracks", &v_TTTo2L2Nu_JetnTracks);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        for (int i = 0; i < v_TTTo2L2Nu_Jethadronflavor->size(); i++)
        {
            h_TTTo2L2Nu_emergjethadronflavor->Fill((*v_TTTo2L2Nu_Jethadronflavor)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            if ((*v_TTTo2L2Nu_Jethadronflavor)[i] == 4 || (*v_TTTo2L2Nu_Jethadronflavor)[i] == 5)
            {
                h_TTTo2L2Nu_hev_emergjetpt->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                h_TTTo2L2Nu_hev_emergjetEta->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                h_TTTo2L2Nu_hev_emergjetnTrack->Fill((*v_TTTo2L2Nu_JetnTracks)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                if ((*v_TTTo2L2Nu_alpha)[i] <=0.35)
                {
                    h_TTTo2L2Nu_hev_emergjetpt_cutalpha->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    h_TTTo2L2Nu_hev_emergjetEta_cutalpha->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    h_TTTo2L2Nu_hev_emergjetnTrack_cutalpha->Fill((*v_TTTo2L2Nu_JetnTracks)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                }
            }
            else
            {
                h_TTTo2L2Nu_light_emergjetpt->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                h_TTTo2L2Nu_light_emergjetEta->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                h_TTTo2L2Nu_light_emergjetnTrack->Fill((*v_TTTo2L2Nu_JetnTracks)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                if ((*v_TTTo2L2Nu_alpha)[i] <=0.35)
                {
                    //cout<<(*v_TTTo2L2Nu_alpha)[i]<<endl;
                    h_TTTo2L2Nu_light_emergjetpt_cutalpha->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    h_TTTo2L2Nu_light_emergjetEta_cutalpha->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    h_TTTo2L2Nu_light_emergjetnTrack_cutalpha->Fill((*v_TTTo2L2Nu_JetnTracks)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                }
            }
        }
    }
    //auto c1 = new TCanvas("c", "BPRE");
    //c1->Divide(2,1);
    //c1->cd(1);
    //h_TTTo2L2Nu_light_emergjetEta->Draw();
    //c1->cd(2);
    //h_TTTo2L2Nu_light_emergjetEta_cutalpha->Draw();

    TTree *T_event3;
    Top_TTWJetsToLNu->GetObject("T_event", T_event3);
    T_event3->SetBranchAddress("f_alphamin", &f_TTWJetsToLNu_alphamin);
    T_event3->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_event3->SetBranchAddress("I_weight", &f_TTWJetsToLNu_weight);
    T_event3->SetBranchAddress("v_fakeJethadronflavor", &v_TTWJetsToLNu_Jethadronflavor);
    T_event3->SetBranchAddress("v_fakeJetPt", &v_TTWJetsToLNu_fakeJetPt);
    T_event3->SetBranchAddress("v_fakealpha", &v_TTWJetsToLNu_alpha);
    T_event3->SetBranchAddress("v_fakeJetEta", &v_TTWJetsToLNu_fakeJetEta);
    T_event3->SetBranchAddress("v_N_Tracks", &v_TTWJetsToLNu_JetnTracks);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        for (int i = 0; i < v_TTWJetsToLNu_Jethadronflavor->size(); i++)
        {
            h_TTWJetsToLNu_emergjethadronflavor->Fill((*v_TTWJetsToLNu_Jethadronflavor)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            if ((*v_TTWJetsToLNu_Jethadronflavor)[i] == 4 || (*v_TTWJetsToLNu_Jethadronflavor)[i] == 5)
            {
                h_TTWJetsToLNu_hev_emergjetpt->Fill((*v_TTWJetsToLNu_fakeJetPt)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                h_TTWJetsToLNu_hev_emergjetEta->Fill((*v_TTWJetsToLNu_fakeJetEta)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                h_TTWJetsToLNu_hev_emergjetnTrack->Fill((*v_TTWJetsToLNu_JetnTracks)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                if ((*v_TTWJetsToLNu_alpha)[i] <=0.35)
                {
                    h_TTWJetsToLNu_hev_emergjetpt_cutalpha->Fill((*v_TTWJetsToLNu_fakeJetPt)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                    h_TTWJetsToLNu_hev_emergjetEta_cutalpha->Fill((*v_TTWJetsToLNu_fakeJetEta)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                    h_TTWJetsToLNu_hev_emergjetnTrack_cutalpha->Fill((*v_TTWJetsToLNu_JetnTracks)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                }
            }
            else
            {
                h_TTWJetsToLNu_light_emergjetpt->Fill((*v_TTWJetsToLNu_fakeJetPt)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                h_TTWJetsToLNu_light_emergjetEta->Fill((*v_TTWJetsToLNu_fakeJetEta)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                h_TTWJetsToLNu_light_emergjetnTrack->Fill((*v_TTWJetsToLNu_JetnTracks)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                if ((*v_TTWJetsToLNu_alpha)[i] <=0.35)
                {
                    h_TTWJetsToLNu_light_emergjetpt_cutalpha->Fill((*v_TTWJetsToLNu_fakeJetPt)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                    h_TTWJetsToLNu_light_emergjetEta_cutalpha->Fill((*v_TTWJetsToLNu_fakeJetEta)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                    h_TTWJetsToLNu_light_emergjetnTrack_cutalpha->Fill((*v_TTWJetsToLNu_JetnTracks)[i], f_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                }
            }
        }
    }
    TTree *T_event4;
    Top_TTWJetsToQQ->GetObject("T_event", T_event4);
    T_event4->SetBranchAddress("f_alphamin", &f_TTWJetsToQQ_alphamin);
    T_event4->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_event4->SetBranchAddress("I_weight", &f_TTWJetsToQQ_weight);
    T_event4->SetBranchAddress("v_fakeJethadronflavor", &v_TWJetsToQQ_Jethadronflavor);
    T_event4->SetBranchAddress("v_fakeJetPt", &v_TWJetsToQQ_fakeJetPt);
    T_event4->SetBranchAddress("v_fakealpha", &v_TWJetsToQQ_alpha);
    T_event4->SetBranchAddress("v_fakeJetEta", &v_TWJetsToQQ_fakeJetEta);
    T_event4->SetBranchAddress("v_N_Tracks", &v_TWJetsToQQ_JetnTracks);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        for (int i = 0; i < v_TWJetsToQQ_Jethadronflavor->size(); i++)
        {
            h_TWJetsToQQ_emergjethadronflavor->Fill((*v_TWJetsToQQ_Jethadronflavor)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            if ((*v_TWJetsToQQ_Jethadronflavor)[i] == 4 || (*v_TWJetsToQQ_Jethadronflavor)[i] == 5)
            {
                h_TWJetsToQQ_hev_emergjetpt->Fill((*v_TWJetsToQQ_fakeJetPt)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                h_TWJetsToQQ_hev_emergjetEta->Fill((*v_TWJetsToQQ_fakeJetEta)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                h_TWJetsToQQ_hev_emergjetnTrack->Fill((*v_TWJetsToQQ_JetnTracks)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                if ((*v_TWJetsToQQ_alpha)[i] <=0.35)
                {
                    h_TWJetsToQQ_hev_emergjetpt_cutalpha->Fill((*v_TWJetsToQQ_fakeJetPt)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                    h_TWJetsToQQ_hev_emergjetEta_cutalpha->Fill((*v_TWJetsToQQ_fakeJetEta)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                    h_TWJetsToQQ_hev_emergjetnTrack_cutalpha->Fill((*v_TWJetsToQQ_JetnTracks)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                }
            }
            else
            {
                h_TWJetsToQQ_light_emergjetpt->Fill((*v_TWJetsToQQ_fakeJetPt)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                h_TWJetsToQQ_light_emergjetEta->Fill((*v_TWJetsToQQ_fakeJetEta)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                h_TWJetsToQQ_light_emergjetnTrack->Fill((*v_TWJetsToQQ_JetnTracks)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                if ((*v_TWJetsToQQ_alpha)[i] <=0.35)
                {
                    h_TWJetsToQQ_light_emergjetpt_cutalpha->Fill((*v_TWJetsToQQ_fakeJetPt)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                    h_TWJetsToQQ_light_emergjetEta_cutalpha->Fill((*v_TWJetsToQQ_fakeJetEta)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                    h_TWJetsToQQ_light_emergjetnTrack_cutalpha->Fill((*v_TWJetsToQQ_JetnTracks)[i], f_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                }
            }
        }
    }

    TTree *T_event5;
    Top_TTZToLLNuNu->GetObject("T_event", T_event5);
    T_event5->SetBranchAddress("f_alphamin", &f_TTZToLLNuNu_alphamin);
    T_event5->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_event5->SetBranchAddress("I_weight", &f_TTZToLLNuNu_weight);
    T_event5->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToLLNuNu_Jethadronflavor);
    T_event5->SetBranchAddress("v_fakeJetPt", &v_TTZToLLNuNu_fakeJetPt);
    T_event5->SetBranchAddress("v_fakealpha", &v_TTZToLLNuNu_alpha);
    T_event5->SetBranchAddress("v_fakeJetEta", &v_TTZToLLNuNu_fakeJetEta);
    T_event5->SetBranchAddress("v_N_Tracks", &v_TTZToLLNuNu_JetnTracks);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        for (int i = 0; i < v_TTZToLLNuNu_Jethadronflavor->size(); i++)
        {
            h_TTZToLLNuNu_emergjethadronflavor->Fill((*v_TTZToLLNuNu_Jethadronflavor)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            if ((*v_TTZToLLNuNu_Jethadronflavor)[i] == 4 || (*v_TTZToLLNuNu_Jethadronflavor)[i] == 5)
            {
                h_TTZToLLNuNu_hev_emergjetpt->Fill((*v_TTZToLLNuNu_fakeJetPt)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                h_TTZToLLNuNu_hev_emergjetEta->Fill((*v_TTZToLLNuNu_fakeJetEta)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                h_TTZToLLNuNu_hev_emergjetnTrack->Fill((*v_TTZToLLNuNu_JetnTracks)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                if ((*v_TTZToLLNuNu_alpha)[i] <=0.35)
                {
                    h_TTZToLLNuNu_hev_emergjetpt_cutalpha->Fill((*v_TTZToLLNuNu_fakeJetPt)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    h_TTZToLLNuNu_hev_emergjetEta_cutalpha->Fill((*v_TTZToLLNuNu_fakeJetEta)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    h_TTZToLLNuNu_hev_emergjetnTrack_cutalpha->Fill((*v_TTZToLLNuNu_JetnTracks)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                }
            }
            else
            {
                h_TTZToLLNuNu_light_emergjetpt->Fill((*v_TTZToLLNuNu_fakeJetPt)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                h_TTZToLLNuNu_light_emergjetEta->Fill((*v_TTZToLLNuNu_fakeJetEta)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                h_TTZToLLNuNu_light_emergjetnTrack->Fill((*v_TTZToLLNuNu_JetnTracks)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                if ((*v_TTZToLLNuNu_alpha)[i] <=0.35)
                {
                    h_TTZToLLNuNu_light_emergjetpt_cutalpha->Fill((*v_TTZToLLNuNu_fakeJetPt)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    h_TTZToLLNuNu_light_emergjetEta_cutalpha->Fill((*v_TTZToLLNuNu_fakeJetEta)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    h_TTZToLLNuNu_light_emergjetnTrack_cutalpha->Fill((*v_TTZToLLNuNu_JetnTracks)[i], f_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                }
            }
        }
    }
    TTree *T_event6;
    Top_TTZToQQ->GetObject("T_event", T_event6);
    T_event6->SetBranchAddress("f_alphamin", &f_TTZToQQ_alphamin);
    T_event6->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_event6->SetBranchAddress("I_weight", &f_TTZToQQ_weight);
    T_event6->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToQQ_Jethadronflavor);
    T_event6->SetBranchAddress("v_fakeJetPt", &v_TTZToQQ_fakeJetPt);
    T_event6->SetBranchAddress("v_fakealpha", &v_TTZToQQ_alpha);
    T_event6->SetBranchAddress("v_fakeJetEta", &v_TTZToQQ_fakeJetEta);
    T_event6->SetBranchAddress("v_N_Tracks", &v_TTZToQQ_JetnTracks);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        for (int i = 0; i < v_TTZToQQ_Jethadronflavor->size(); i++)
        {
            h_TTZToQQ_emergjethadronflavor->Fill((*v_TTZToQQ_Jethadronflavor)[i], f_TTZToQQ_weight * TTZToQQWeight);
            if ((*v_TTZToQQ_Jethadronflavor)[i] == 4 || (*v_TTZToQQ_Jethadronflavor)[i] == 5)
            {
                h_TTZToQQ_hev_emergjetpt->Fill((*v_TTZToQQ_fakeJetPt)[i], f_TTZToQQ_weight * TTZToQQWeight);
                h_TTZToQQ_hev_emergjetEta->Fill((*v_TTZToQQ_fakeJetEta)[i], f_TTZToQQ_weight * TTZToQQWeight);
                h_TTZToQQ_hev_emergjetnTrack->Fill((*v_TTZToQQ_JetnTracks)[i], f_TTZToQQ_weight * TTZToQQWeight);
                if ((*v_TTZToQQ_alpha)[i] <=0.35)
                {
                    h_TTZToQQ_hev_emergjetpt_cutalpha->Fill((*v_TTZToQQ_fakeJetPt)[i], f_TTZToQQ_weight * TTZToQQWeight);
                    h_TTZToQQ_hev_emergjetEta_cutalpha->Fill((*v_TTZToQQ_fakeJetEta)[i], f_TTZToQQ_weight * TTZToQQWeight);
                    h_TTZToQQ_hev_emergjetnTrack_cutalpha->Fill((*v_TTZToQQ_JetnTracks)[i], f_TTZToQQ_weight * TTZToQQWeight);
                }
            }
            else
            {
                h_TTZToQQ_light_emergjetpt->Fill((*v_TTZToQQ_fakeJetPt)[i], f_TTZToQQ_weight * TTZToQQWeight);
                h_TTZToQQ_light_emergjetEta->Fill((*v_TTZToQQ_fakeJetEta)[i], f_TTZToQQ_weight * TTZToQQWeight);
                h_TTZToQQ_light_emergjetnTrack->Fill((*v_TTZToQQ_JetnTracks)[i], f_TTZToQQ_weight * TTZToQQWeight);
                if ((*v_TTZToQQ_alpha)[i] <=0.35)
                {
                    h_TTZToQQ_light_emergjetpt_cutalpha->Fill((*v_TTZToQQ_fakeJetPt)[i], f_TTZToQQ_weight * TTZToQQWeight);
                    h_TTZToQQ_light_emergjetEta_cutalpha->Fill((*v_TTZToQQ_fakeJetEta)[i], f_TTZToQQ_weight * TTZToQQWeight);
                    h_TTZToQQ_light_emergjetnTrack_cutalpha->Fill((*v_TTZToQQ_JetnTracks)[i], f_TTZToQQ_weight * TTZToQQWeight);
                }
            }
        }
    }


    //h_tW_top_emergjethadronflavor->Add(h_tW_antitop_emergjethadronflavor);
    //h_tW_top_emergjethadronflavor->Add(h_TTTo2L2Nu_emergjethadronflavor);
    //h_tW_top_emergjethadronflavor->Add(h_TTWJetsToLNu_emergjethadronflavor);
    //h_tW_top_emergjethadronflavor->Add(h_TWJetsToQQ_emergjethadronflavor);
    //h_tW_top_emergjethadronflavor->Add(h_TTZToLLNuNu_emergjethadronflavor);
    //h_tW_top_emergjethadronflavor->Add(h_TTZToQQ_emergjethadronflavor);

    //h_tW_top_hev_emergjetpt->Add(h_tW_antitop_hev_emergjetpt);
    //h_tW_top_hev_emergjetpt->Add(h_TTTo2L2Nu_hev_emergjetpt);
    //h_tW_top_hev_emergjetpt->Add(h_TTWJetsToLNu_hev_emergjetpt);
    //h_tW_top_hev_emergjetpt->Add(h_TWJetsToQQ_hev_emergjetpt);
    //h_tW_top_hev_emergjetpt->Add(h_TTZToLLNuNu_hev_emergjetpt);
    //h_tW_top_hev_emergjetpt->Add(h_TTZToQQ_hev_emergjetpt);

    //h_tW_top_light_emergjetpt->Add(h_tW_antitop_light_emergjetpt);
    //h_tW_top_light_emergjetpt->Add(h_TTTo2L2Nu_light_emergjetpt);
    //h_tW_top_light_emergjetpt->Add(h_TTWJetsToLNu_light_emergjetpt);
    //h_tW_top_light_emergjetpt->Add(h_TWJetsToQQ_light_emergjetpt);
    //h_tW_top_light_emergjetpt->Add(h_TTZToLLNuNu_light_emergjetpt);
    //h_tW_top_light_emergjetpt->Add(h_TTZToQQ_light_emergjetpt);

    //h_tW_top_hev_emergjetEta->Add(h_tW_antitop_hev_emergjetEta);
    //h_tW_top_hev_emergjetEta->Add(h_TTTo2L2Nu_hev_emergjetEta);
    //h_tW_top_hev_emergjetEta->Add(h_TTWJetsToLNu_hev_emergjetEta);
    //h_tW_top_hev_emergjetEta->Add(h_TWJetsToQQ_hev_emergjetEta);
    //h_tW_top_hev_emergjetEta->Add(h_TTZToLLNuNu_hev_emergjetEta);
    //h_tW_top_hev_emergjetEta->Add(h_TTZToQQ_hev_emergjetEta);

    //h_tW_top_light_emergjetEta->Add(h_tW_antitop_light_emergjetEta);
    //h_tW_top_light_emergjetEta->Add(h_TTTo2L2Nu_light_emergjetEta);
    //h_tW_top_light_emergjetEta->Add(h_TTWJetsToLNu_light_emergjetEta);
    //h_tW_top_light_emergjetEta->Add(h_TWJetsToQQ_light_emergjetEta);
    //h_tW_top_light_emergjetEta->Add(h_TTZToLLNuNu_light_emergjetEta);
    //h_tW_top_light_emergjetEta->Add(h_TTZToQQ_light_emergjetEta);

    //h_tW_top_hev_emergjetnTrack->Add(h_tW_antitop_hev_emergjetnTrack);
    //h_tW_top_hev_emergjetnTrack->Add(h_TTTo2L2Nu_hev_emergjetnTrack);
    //h_tW_top_hev_emergjetnTrack->Add(h_TTWJetsToLNu_hev_emergjetnTrack);
    //h_tW_top_hev_emergjetnTrack->Add(h_TWJetsToQQ_hev_emergjetnTrack);
    //h_tW_top_hev_emergjetnTrack->Add(h_TTZToLLNuNu_hev_emergjetnTrack);
    //h_tW_top_hev_emergjetnTrack->Add(h_TTZToQQ_hev_emergjetnTrack);

    //h_tW_top_light_emergjetnTrack->Add(h_tW_antitop_light_emergjetnTrack);
    //h_tW_top_light_emergjetnTrack->Add(h_TTTo2L2Nu_light_emergjetnTrack);
    //h_tW_top_light_emergjetnTrack->Add(h_TTWJetsToLNu_light_emergjetnTrack);
    //h_tW_top_light_emergjetnTrack->Add(h_TWJetsToQQ_light_emergjetnTrack);
    //h_tW_top_light_emergjetnTrack->Add(h_TTZToLLNuNu_light_emergjetnTrack);
    //h_tW_top_light_emergjetnTrack->Add(h_TTZToQQ_light_emergjetnTrack);

    //h_tW_top_hev_emergjetpt_cutalpha->Add(h_tW_antitop_hev_emergjetpt_cutalpha);
    //h_tW_top_hev_emergjetpt_cutalpha->Add(h_TTTo2L2Nu_hev_emergjetpt_cutalpha);
    //h_tW_top_hev_emergjetpt_cutalpha->Add(h_TTWJetsToLNu_hev_emergjetpt_cutalpha);
    //h_tW_top_hev_emergjetpt_cutalpha->Add(h_TWJetsToQQ_hev_emergjetpt_cutalpha);
    //h_tW_top_hev_emergjetpt_cutalpha->Add(h_TTZToLLNuNu_hev_emergjetpt_cutalpha);
    //h_tW_top_hev_emergjetpt_cutalpha->Add(h_TTZToQQ_hev_emergjetpt_cutalpha);

    //h_tW_top_light_emergjetpt_cutalpha->Add(h_tW_antitop_light_emergjetpt_cutalpha);
    //h_tW_top_light_emergjetpt_cutalpha->Add(h_TTTo2L2Nu_light_emergjetpt_cutalpha);
    //h_tW_top_light_emergjetpt_cutalpha->Add(h_TTWJetsToLNu_light_emergjetpt_cutalpha);
    //h_tW_top_light_emergjetpt_cutalpha->Add(h_TWJetsToQQ_light_emergjetpt_cutalpha);
    //h_tW_top_light_emergjetpt_cutalpha->Add(h_TTZToLLNuNu_light_emergjetpt_cutalpha);
    //h_tW_top_light_emergjetpt_cutalpha->Add(h_TTZToQQ_light_emergjetpt_cutalpha);

    //h_tW_top_hev_emergjetEta_cutalpha->Add(h_tW_antitop_hev_emergjetEta_cutalpha);
    //h_tW_top_hev_emergjetEta_cutalpha->Add(h_TTTo2L2Nu_hev_emergjetEta_cutalpha);
    //h_tW_top_hev_emergjetEta_cutalpha->Add(h_TTWJetsToLNu_hev_emergjetEta_cutalpha);
    //h_tW_top_hev_emergjetEta_cutalpha->Add(h_TWJetsToQQ_hev_emergjetEta_cutalpha);
    //h_tW_top_hev_emergjetEta_cutalpha->Add(h_TTZToLLNuNu_hev_emergjetEta_cutalpha);
    //h_tW_top_hev_emergjetEta_cutalpha->Add(h_TTZToQQ_hev_emergjetEta_cutalpha);

    //h_tW_top_light_emergjetEta_cutalpha->Add(h_tW_antitop_light_emergjetEta_cutalpha);
    //h_tW_top_light_emergjetEta_cutalpha->Add(h_TTTo2L2Nu_light_emergjetEta_cutalpha);
    //h_tW_top_light_emergjetEta_cutalpha->Add(h_TTWJetsToLNu_light_emergjetEta_cutalpha);
    //h_tW_top_light_emergjetEta_cutalpha->Add(h_TWJetsToQQ_light_emergjetEta_cutalpha);
    //h_tW_top_light_emergjetEta_cutalpha->Add(h_TTZToLLNuNu_light_emergjetEta_cutalpha);
    //h_tW_top_light_emergjetEta_cutalpha->Add(h_TTZToQQ_light_emergjetEta_cutalpha);

    //h_tW_top_hev_emergjetnTrack_cutalpha->Add(h_tW_antitop_hev_emergjetnTrack_cutalpha);
    //h_tW_top_hev_emergjetnTrack_cutalpha->Add(h_TTTo2L2Nu_hev_emergjetnTrack_cutalpha);
    //h_tW_top_hev_emergjetnTrack_cutalpha->Add(h_TTWJetsToLNu_hev_emergjetnTrack_cutalpha);
    //h_tW_top_hev_emergjetnTrack_cutalpha->Add(h_TWJetsToQQ_hev_emergjetnTrack_cutalpha);
    //h_tW_top_hev_emergjetnTrack_cutalpha->Add(h_TTZToLLNuNu_hev_emergjetnTrack_cutalpha);
    //h_tW_top_hev_emergjetnTrack_cutalpha->Add(h_TTZToQQ_hev_emergjetnTrack_cutalpha);

    //h_tW_top_light_emergjetnTrack_cutalpha->Add(h_tW_antitop_light_emergjetnTrack_cutalpha);
    //h_tW_top_light_emergjetnTrack_cutalpha->Add(h_TTTo2L2Nu_light_emergjetnTrack_cutalpha);
    //h_tW_top_light_emergjetnTrack_cutalpha->Add(h_TTWJetsToLNu_light_emergjetnTrack_cutalpha);
    //h_tW_top_light_emergjetnTrack_cutalpha->Add(h_TWJetsToQQ_light_emergjetnTrack_cutalpha);
    //h_tW_top_light_emergjetnTrack_cutalpha->Add(h_TTZToLLNuNu_light_emergjetnTrack_cutalpha);
    //h_tW_top_light_emergjetnTrack_cutalpha->Add(h_TTZToQQ_light_emergjetnTrack_cutalpha);

    h_tW_top_emergjethadronflavor->GetXaxis()->SetTitle("Jet Flavor");
    h_tW_top_emergjethadronflavor->GetYaxis()->SetTitle("N Jets");
    //h_tW_top_emergjethadronflavor->Draw();


    TFile *outFile = new TFile("./../../../root_file/BgEstimation/Top_fakerateStudy.root", "RECREATE");
    outFile->cd();
    h_TTTo2L2Nu_emergjethadronflavor->Write();
    h_TTTo2L2Nu_hev_emergjetpt->Write();
    h_TTTo2L2Nu_light_emergjetpt->Write();
    h_TTTo2L2Nu_hev_emergjetEta->Write();
    h_TTTo2L2Nu_light_emergjetEta->Write();
    h_TTTo2L2Nu_hev_emergjetnTrack->Write();
    h_TTTo2L2Nu_light_emergjetnTrack->Write();
    h_TTTo2L2Nu_hev_emergjetpt_cutalpha->Write();
    h_TTTo2L2Nu_light_emergjetpt_cutalpha->Write();
    h_TTTo2L2Nu_hev_emergjetEta_cutalpha->Write();
    h_TTTo2L2Nu_light_emergjetEta_cutalpha->Write();
    h_TTTo2L2Nu_hev_emergjetnTrack_cutalpha->Write();
    h_TTTo2L2Nu_light_emergjetnTrack_cutalpha->Write();
    outFile->Close();
}