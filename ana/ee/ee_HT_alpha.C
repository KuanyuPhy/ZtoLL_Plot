#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../lib/Cross_section.h"
#include "./../lib/setNCUStyle.C"
using namespace std;
void ee_HT_alpha()
{
    TFile *Mx2_1 = new TFile("./../../../../root_file/Ztoee/Mx2_1.root");
    TFile *Mx2_50 = new TFile("./../../../../root_file/Ztoee/Mx2_50.root");
    TFile *Mx2_150 = new TFile("./../../../../root_file/Ztoee/Mx2_150.root");

    TFile *DYincli = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");
    TFile *DYHT70 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht70.root");
    TFile *DYHT100 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
    TFile *DYHT200 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
    TFile *DYHT400 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
    TFile *DYHT600 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
    TFile *DYHT800 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
    TFile *DYHT1200 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
    TFile *DYHT2500 = new TFile("./../../../../root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

    TFile *Top_TTTo2L2Nu = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
    TFile *Top_TTWJetsToLNu = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQ = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToLLNuNu = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_TTZToQQ = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_tW_antitop = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_top = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

    TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));

    TH1D *DYHT70_sumevt = ((TH1D *)DYHT70->Get("Event_Variable/h_totevent"));
    TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("Event_Variable/h_totevent"));
    TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("Event_Variable/h_totevent"));
    TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("Event_Variable/h_totevent"));
    TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("Event_Variable/h_totevent"));
    TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("Event_Variable/h_totevent"));
    TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("Event_Variable/h_totevent"));

    // TH1D *TTTo2L2Nu_sumevt = ((TH1D *)Top_TTTo2L2Nu->Get("Event_Variable/h_totevent"));
    // TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNu->Get("Event_Variable/h_totevent"));
    // TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQ->Get("Event_Variable/h_totevent"));
    // TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNu->Get("Event_Variable/h_totevent"));
    // TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQ->Get("Event_Variable/h_totevent"));
    // TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitop->Get("Event_Variable/h_totevent"));
    // TH1D *tW_top_sumevt = ((TH1D *)Top_tW_top->Get("Event_Variable/h_totevent"));

    int DYHT100_totevt = DYHT100_sumevt->Integral();
    int DYHT200_totevt = DYHT200_sumevt->Integral();
    int DYHT400_totevt = DYHT400_sumevt->Integral();
    int DYHT600_totevt = DYHT600_sumevt->Integral();
    int DYHT800_totevt = DYHT800_sumevt->Integral();
    int DYHT1200_totevt = DYHT1200_sumevt->Integral();
    int DYHT2500_totevt = DYHT2500_sumevt->Integral();

    // int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();
    // int TTWJetsToLNu_totevt = TTWJetsToLNu_sumevt->Integral();
    // int TTWJetsToQQ_totevt = TTWJetsToQQ_sumevt->Integral();
    // int TTZToLLNuNu_totevt = TTZToLLNuNu_sumevt->Integral();
    // int TTZToQQ_totevt = TTZToQQ_sumevt->Integral();
    // int tW_antitop_totevt = tW_antitop_sumevt->Integral();
    // int tW_top_totevt = tW_top_sumevt->Integral();

    int HT0_70_event = h_HT_eventCout->GetBinContent(2);
    int HT70_100_event = h_HT_eventCout->GetBinContent(3);
    int HT100_200_event = h_HT_eventCout->GetBinContent(4);
    int HT200_400_event = h_HT_eventCout->GetBinContent(5);
    int HT400_600_event = h_HT_eventCout->GetBinContent(6);
    int HT600_800_event = h_HT_eventCout->GetBinContent(7);
    int HT800_1200_event = h_HT_eventCout->GetBinContent(8);
    int HT1200_2500_event = h_HT_eventCout->GetBinContent(9);
    int HT2500_Inf_event = h_HT_eventCout->GetBinContent(10);

    //---------------------
    // Define HTWeight
    //---------------------
    float HT0Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT0CS) / (HT0_70_event)) * 1000;
    float HT70Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT70CS) / (HT70_100_event)) * 1000;
    float HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000;
    float HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000;
    float HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000;
    float HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000;
    float HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000;
    float HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000;
    float HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000;

    // float ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000;
    // float ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000;
    // float TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTTo2L2Nu / (TTTo2L2Nu_totevt)) * 1000;
    // float TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000;
    // float TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000;
    // float TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000;
    // float TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000;

    TH1F *h_ht0_alpha = new TH1F("h_ht0_alpha", "", 24, 0, 1.2);
    h_ht0_alpha->SetYTitle("N Jets");
    h_ht0_alpha->Sumw2();

    TH1F *h_ht70_alpha = new TH1F("h_ht70_alpha", "", 24, 0, 1.2);
    h_ht70_alpha->SetYTitle("N Jets");
    h_ht70_alpha->Sumw2();

    TH1F *h_ht100_alpha = new TH1F("h_ht100_alpha", "", 24, 0, 1.2);
    h_ht100_alpha->SetYTitle("N Jets");
    h_ht100_alpha->Sumw2();

    TH1F *h_ht200_alpha = new TH1F("h_ht200_alpha", "", 24, 0, 1.2);
    h_ht200_alpha->SetYTitle("N Jets");
    h_ht200_alpha->Sumw2();

    TH1F *h_ht400_alpha = new TH1F("h_ht400_alpha", "", 24, 0, 1.2);
    h_ht400_alpha->SetYTitle("N Jets");
    h_ht400_alpha->Sumw2();

    TH1F *h_ht600_alpha = new TH1F("h_ht600_alpha", "", 24, 0, 1.2);
    h_ht600_alpha->SetYTitle("N Jets");
    h_ht600_alpha->Sumw2();

    TH1F *h_ht800_alpha = new TH1F("h_ht800_alpha", "", 24, 0, 1.2);
    h_ht800_alpha->SetYTitle("N Jets");
    h_ht800_alpha->Sumw2();

    TH1F *h_ht1200_alpha = new TH1F("h_ht1200_alpha", "", 24, 0, 1.2);
    h_ht1200_alpha->SetYTitle("N Jets");
    h_ht1200_alpha->Sumw2();

    TH1F *h_ht2500_alpha = new TH1F("h_ht2500_alpha", "", 24, 0, 1.2);
    h_ht2500_alpha->SetYTitle("N Jets");
    h_ht2500_alpha->Sumw2();

    TH1F *h_ht0_Median_2DIP = new TH1F("h_ht0_Median_2DIP", "", 100, -10, 10);
    h_ht0_Median_2DIP->SetYTitle("");
    h_ht0_Median_2DIP->Sumw2();

    TH1F *h_ht70_Median_2DIP = new TH1F("h_ht70_Median_2DIP", "", 100, -10, 10);
    h_ht70_Median_2DIP->SetYTitle("");
    h_ht70_Median_2DIP->Sumw2();

    TH1F *h_ht100_Median_2DIP = new TH1F("h_ht100_Median_2DIP", "", 100, -10, 10);
    h_ht100_Median_2DIP->SetYTitle("");
    h_ht100_Median_2DIP->Sumw2();

    TH1F *h_ht200_Median_2DIP = new TH1F("h_ht200_Median_2DIP", "", 100, -10, 10);
    h_ht200_Median_2DIP->SetYTitle("");
    h_ht200_Median_2DIP->Sumw2();

    TH1F *h_ht400_Median_2DIP = new TH1F("h_ht400_Median_2DIP", "", 100, -10, 10);
    h_ht400_Median_2DIP->SetYTitle("");
    h_ht400_Median_2DIP->Sumw2();

    TH1F *h_ht600_Median_2DIP = new TH1F("h_ht600_Median_2DIP", "", 100, -10, 10);
    h_ht600_Median_2DIP->SetYTitle("");
    h_ht600_Median_2DIP->Sumw2();

    TH1F *h_ht800_Median_2DIP = new TH1F("h_ht800_Median_2DIP", "", 100, -10, 10);
    h_ht800_Median_2DIP->SetYTitle("");
    h_ht800_Median_2DIP->Sumw2();

    TH1F *h_ht1200_Median_2DIP = new TH1F("h_ht1200_Median_2DIP", "", 100, -10, 10);
    h_ht1200_Median_2DIP->SetYTitle("");
    h_ht1200_Median_2DIP->Sumw2();

    TH1F *h_ht2500_Median_2DIP = new TH1F("h_ht2500_Median_2DIP", "", 100, -10, 10);
    h_ht2500_Median_2DIP->SetYTitle("");
    h_ht2500_Median_2DIP->Sumw2();

    TH1F *h_ht0_Chi3Dlog = new TH1F("h_ht0_Chi3Dlog", "", 100, -10, 10);
    h_ht0_Chi3Dlog->SetYTitle("");
    h_ht0_Chi3Dlog->Sumw2();

    TH1F *h_ht70_Chi3Dlog = new TH1F("h_ht70_Chi3Dlog", "", 100, -10, 10);
    h_ht70_Chi3Dlog->SetYTitle("");
    h_ht70_Chi3Dlog->Sumw2();

    TH1F *h_ht100_Chi3Dlog = new TH1F("h_ht100_Chi3Dlog", "", 100, -10, 10);
    h_ht100_Chi3Dlog->SetYTitle("");
    h_ht100_Chi3Dlog->Sumw2();

    TH1F *h_ht200_Chi3Dlog = new TH1F("h_ht200_Chi3Dlog", "", 100, -10, 10);
    h_ht200_Chi3Dlog->SetYTitle("");
    h_ht200_Chi3Dlog->Sumw2();

    TH1F *h_ht400_Chi3Dlog = new TH1F("h_ht400_Chi3Dlog", "", 100, -10, 10);
    h_ht400_Chi3Dlog->SetYTitle("");
    h_ht400_Chi3Dlog->Sumw2();

    TH1F *h_ht600_Chi3Dlog = new TH1F("h_ht600_Chi3Dlog", "", 100, -10, 10);
    h_ht600_Chi3Dlog->SetYTitle("");
    h_ht600_Chi3Dlog->Sumw2();

    TH1F *h_ht800_Chi3Dlog = new TH1F("h_ht800_Chi3Dlog", "", 100, -10, 10);
    h_ht800_Chi3Dlog->SetYTitle("");
    h_ht800_Chi3Dlog->Sumw2();

    TH1F *h_ht1200_Chi3Dlog = new TH1F("h_ht1200_Chi3Dlog", "", 100, -10, 10);
    h_ht1200_Chi3Dlog->SetYTitle("");
    h_ht1200_Chi3Dlog->Sumw2();

    TH1F *h_ht2500_Chi3Dlog = new TH1F("h_ht2500_Chi3Dlog", "", 100, -10, 10);
    h_ht2500_Chi3Dlog->SetYTitle("");
    h_ht2500_Chi3Dlog->Sumw2();

    TH1F *h_ht0_Chi3DlogPaper = new TH1F("h_ht0_Chi3DlogPaper", "", 100, -10, 10);
    h_ht0_Chi3DlogPaper->SetYTitle("");
    h_ht0_Chi3DlogPaper->Sumw2();

    TH1F *h_ht70_Chi3DlogPaper = new TH1F("h_ht70_Chi3DlogPaper", "", 100, -10, 10);
    h_ht70_Chi3DlogPaper->SetYTitle("");
    h_ht70_Chi3DlogPaper->Sumw2();

    TH1F *h_ht100_Chi3DlogPaper = new TH1F("h_ht100_Chi3DlogPaper", "", 100, -10, 10);
    h_ht100_Chi3DlogPaper->SetYTitle("");
    h_ht100_Chi3DlogPaper->Sumw2();

    TH1F *h_ht200_Chi3DlogPaper = new TH1F("h_ht200_Chi3DlogPaper", "", 100, -10, 10);
    h_ht200_Chi3DlogPaper->SetYTitle("");
    h_ht200_Chi3DlogPaper->Sumw2();

    TH1F *h_ht400_Chi3DlogPaper = new TH1F("h_ht400_Chi3DlogPaper", "", 100, -10, 10);
    h_ht400_Chi3DlogPaper->SetYTitle("");
    h_ht400_Chi3DlogPaper->Sumw2();

    TH1F *h_ht600_Chi3DlogPaper = new TH1F("h_ht600_Chi3DlogPaper", "", 100, -10, 10);
    h_ht600_Chi3DlogPaper->SetYTitle("");
    h_ht600_Chi3DlogPaper->Sumw2();

    TH1F *h_ht800_Chi3DlogPaper = new TH1F("h_ht800_Chi3DlogPaper", "", 100, -10, 10);
    h_ht800_Chi3DlogPaper->SetYTitle("");
    h_ht800_Chi3DlogPaper->Sumw2();

    TH1F *h_ht1200_Chi3DlogPaper = new TH1F("h_ht1200_Chi3DlogPaper", "", 100, -10, 10);
    h_ht1200_Chi3DlogPaper->SetYTitle("");
    h_ht1200_Chi3DlogPaper->Sumw2();

    TH1F *h_ht2500_Chi3DlogPaper = new TH1F("h_ht2500_Chi3DlogPaper", "", 100, -10, 10);
    h_ht2500_Chi3DlogPaper->SetYTitle("");
    h_ht2500_Chi3DlogPaper->Sumw2();

    TH1F *h_ht0_Chi3D = new TH1F("h_ht0_Chi3D", "", 500, 0, 500);
    h_ht0_Chi3D->SetYTitle("");
    h_ht0_Chi3D->Sumw2();

    TH1F *h_ht70_Chi3D = new TH1F("h_ht70_Chi3D", "", 500, 0, 500);
    h_ht70_Chi3D->SetYTitle("");
    h_ht70_Chi3D->Sumw2();

    TH1F *h_ht100_Chi3D = new TH1F("h_ht100_Chi3D", "", 500, 0, 500);
    h_ht100_Chi3D->SetYTitle("");
    h_ht100_Chi3D->Sumw2();

    TH1F *h_ht200_Chi3D = new TH1F("h_ht200_Chi3D", "", 500, 0, 500);
    h_ht200_Chi3D->SetYTitle("");
    h_ht200_Chi3D->Sumw2();

    TH1F *h_ht400_Chi3D = new TH1F("h_ht400_Chi3D", "", 500, 0, 500);
    h_ht400_Chi3D->SetYTitle("");
    h_ht400_Chi3D->Sumw2();

    TH1F *h_ht600_Chi3D = new TH1F("h_ht600_Chi3D", "", 500, 0, 500);
    h_ht600_Chi3D->SetYTitle("");
    h_ht600_Chi3D->Sumw2();

    TH1F *h_ht800_Chi3D = new TH1F("h_ht800_Chi3D", "", 500, 0, 500);
    h_ht800_Chi3D->SetYTitle("");
    h_ht800_Chi3D->Sumw2();

    TH1F *h_ht1200_Chi3D = new TH1F("h_ht1200_Chi3D", "", 500, 0, 500);
    h_ht1200_Chi3D->SetYTitle("");
    h_ht1200_Chi3D->Sumw2();

    TH1F *h_ht2500_Chi3D = new TH1F("h_ht2500_Chi3D", "", 500, 0, 500);
    h_ht2500_Chi3D->SetYTitle("");
    h_ht2500_Chi3D->Sumw2();

    TH1F *h_Mx2_1_alpha = new TH1F("h_Mx2_1_alpha", "", 24, 0, 1.2);
    h_Mx2_1_alpha->SetYTitle("N Jets");
    h_Mx2_1_alpha->Sumw2();

    TH1F *h_Mx2_50_alpha = new TH1F("h_Mx2_50_alpha", "", 24, 0, 1.2);
    h_Mx2_50_alpha->SetYTitle("N Jets");
    h_Mx2_50_alpha->Sumw2();

    TH1F *h_Mx2_150_alpha = new TH1F("h_Mx2_150_alpha", "", 24, 0, 1.2);
    h_Mx2_150_alpha->SetYTitle("N Jets");
    h_Mx2_150_alpha->Sumw2();

    TH1F *h_Mx2_1_Median_2DIP = new TH1F("h_Mx2_1_Median_2DIP", "", 100, -10, 10);
    h_Mx2_1_Median_2DIP->SetYTitle("");
    h_Mx2_1_Median_2DIP->Sumw2();

    TH1F *h_Mx2_50_Median_2DIP = new TH1F("h_Mx2_50_Median_2DIP", "", 100, -10, 10);
    h_Mx2_50_Median_2DIP->SetYTitle("");
    h_Mx2_50_Median_2DIP->Sumw2();

    TH1F *h_Mx2_150_Median_2DIP = new TH1F("h_Mx2_150_Median_2DIP", "", 100, -10, 10);
    h_Mx2_150_Median_2DIP->SetYTitle("");
    h_Mx2_150_Median_2DIP->Sumw2();

    TH1F *h_Mx2_1_Chi3D = new TH1F("h_Mx2_1_Chi3D", "", 500,0,500);
    h_Mx2_1_Chi3D->SetYTitle("");
    h_Mx2_1_Chi3D->Sumw2();

    TH1F *h_Mx2_50_Chi3D = new TH1F("h_Mx2_50_Chi3D", "", 500,0,500);
    h_Mx2_50_Chi3D->SetYTitle("");
    h_Mx2_50_Chi3D->Sumw2();

    TH1F *h_Mx2_150_Chi3D = new TH1F("h_Mx2_150_Chi3D", "", 500,0,500);
    h_Mx2_150_Chi3D->SetYTitle("");
    h_Mx2_150_Chi3D->Sumw2();

    TH1F *h_Mx2_1_Chi3Dlog = new TH1F("h_Mx2_1_Chi3Dlog", "", 100, -10, 10);
    h_Mx2_1_Chi3Dlog->SetYTitle("");
    h_Mx2_1_Chi3Dlog->Sumw2();

    TH1F *h_Mx2_50_Chi3Dlog = new TH1F("h_Mx2_50_Chi3Dlog", "", 100, -10, 10);
    h_Mx2_50_Chi3Dlog->SetYTitle("");
    h_Mx2_50_Chi3Dlog->Sumw2();

    TH1F *h_Mx2_150_Chi3Dlog = new TH1F("h_Mx2_150_Chi3Dlog", "", 100, -10, 10);
    h_Mx2_150_Chi3Dlog->SetYTitle("");
    h_Mx2_150_Chi3Dlog->Sumw2();

    TH1F *h_Mx2_1_Chi3DlogPaper = new TH1F("h_Mx2_1_Chi3DlogPaper", "", 100, -10, 10);
    h_Mx2_1_Chi3DlogPaper->SetYTitle("");
    h_Mx2_1_Chi3DlogPaper->Sumw2();

    TH1F *h_Mx2_50_Chi3DlogPaper = new TH1F("h_Mx2_h_Mx2_50_Chi3DlogPaper50_Median_2DIP", "", 100, -10, 10);
    h_Mx2_50_Chi3DlogPaper->SetYTitle("");
    h_Mx2_50_Chi3DlogPaper->Sumw2();

    TH1F *h_Mx2_150_Chi3DlogPaper = new TH1F("h_Mx2_150_Chi3DlogPaper", "", 100, -10, 10);
    h_Mx2_150_Chi3DlogPaper->SetYTitle("");
    h_Mx2_150_Chi3DlogPaper->Sumw2();

    // ------------------
    // Valid Tree Variable
    //-------------------
    float HT;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight, I_ht800_weight,
        I_ht1200_weight, I_ht2500_weight;

    Int_t I_ht0_nThinJets, I_ht70_nThinJets, I_ht100_nThinJets, I_ht200_nThinJets, I_ht400_nThinJets, I_ht600_nThinJets, I_ht800_nThinJets,
        I_ht1200_nThinJets, I_ht2500_nThinJets;

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;

    Int_t I_Mx1_nThinJets, I_Mx50_nThinJets, I_Mx150_nThinJets;

    vector<float> *v_ht0_Median_2DIPsig = new vector<float>();
    vector<float> *v_ht70_Median_2DIPsig = new vector<float>();
    vector<float> *v_ht100_Median_2DIPsig = new vector<float>();
    vector<float> *v_ht200_Median_2DIPsig = new vector<float>();
    vector<float> *v_ht400_Median_2DIPsig = new vector<float>();
    vector<float> *v_ht600_Median_2DIPsig = new vector<float>();
    vector<float> *v_ht800_Median_2DIPsig = new vector<float>();
    vector<float> *v_ht1200_Median_2DIPsig = new vector<float>();
    vector<float> *v_ht2500_Median_2DIPsig = new vector<float>();

    vector<float> *v_ht0_alpha = new vector<float>();
    vector<float> *v_ht70_alpha = new vector<float>();
    vector<float> *v_ht100_alpha = new vector<float>();
    vector<float> *v_ht200_alpha = new vector<float>();
    vector<float> *v_ht400_alpha = new vector<float>();
    vector<float> *v_ht600_alpha = new vector<float>();
    vector<float> *v_ht800_alpha = new vector<float>();
    vector<float> *v_ht1200_alpha = new vector<float>();
    vector<float> *v_ht2500_alpha = new vector<float>();

    vector<float> *v_ht0_Chi3DlogPaper = new vector<float>();
    vector<float> *v_ht70_Chi3DlogPaper = new vector<float>();
    vector<float> *v_ht100_Chi3DlogPaper = new vector<float>();
    vector<float> *v_ht200_Chi3DlogPaper = new vector<float>();
    vector<float> *v_ht400_Chi3DlogPaper = new vector<float>();
    vector<float> *v_ht600_Chi3DlogPaper = new vector<float>();
    vector<float> *v_ht800_Chi3DlogPaper = new vector<float>();
    vector<float> *v_ht1200_Chi3DlogPaper = new vector<float>();
    vector<float> *v_ht2500_Chi3DlogPaper = new vector<float>();

    vector<float> *v_ht0_Chi3Dlog = new vector<float>();
    vector<float> *v_ht70_Chi3Dlog = new vector<float>();
    vector<float> *v_ht100_Chi3Dlog = new vector<float>();
    vector<float> *v_ht200_Chi3Dlog = new vector<float>();
    vector<float> *v_ht400_Chi3Dlog = new vector<float>();
    vector<float> *v_ht600_Chi3Dlog = new vector<float>();
    vector<float> *v_ht800_Chi3Dlog = new vector<float>();
    vector<float> *v_ht1200_Chi3Dlog = new vector<float>();
    vector<float> *v_ht2500_Chi3Dlog = new vector<float>();

    vector<float> *v_ht0_Chi3D = new vector<float>();
    vector<float> *v_ht70_Chi3D = new vector<float>();
    vector<float> *v_ht100_Chi3D = new vector<float>();
    vector<float> *v_ht200_Chi3D = new vector<float>();
    vector<float> *v_ht400_Chi3D = new vector<float>();
    vector<float> *v_ht600_Chi3D = new vector<float>();
    vector<float> *v_ht800_Chi3D = new vector<float>();
    vector<float> *v_ht1200_Chi3D = new vector<float>();
    vector<float> *v_ht2500_Chi3D = new vector<float>();

    vector<float> *v_Mx2_1_alpha = new vector<float>();
    vector<float> *v_Mx2_50_alpha = new vector<float>();
    vector<float> *v_Mx2_150_alpha = new vector<float>();

    vector<float> *v_Mx2_1_Chi3D = new vector<float>();
    vector<float> *v_Mx2_50_Chi3D = new vector<float>();
    vector<float> *v_Mx2_150_Chi3D = new vector<float>();
    vector<float> *v_Mx2_1_Chi3Dlog = new vector<float>();
    vector<float> *v_Mx2_50_Chi3Dlog = new vector<float>();
    vector<float> *v_Mx2_150_Chi3Dlog = new vector<float>();
    vector<float> *v_Mx2_1_Chi3DlogPaper = new vector<float>();
    vector<float> *v_Mx2_50_Chi3DlogPaper = new vector<float>();
    vector<float> *v_Mx2_150_Chi3DlogPaper = new vector<float>();
    vector<float> *v_Mx2_1_Median_2DIP = new vector<float>();
    vector<float> *v_Mx2_50_Median_2DIP = new vector<float>();
    vector<float> *v_Mx2_150_Median_2DIP = new vector<float>();

    TTree *T_event;
    DYincli->GetObject("T_tree", T_event);
    T_event->SetBranchAddress("I_weight", &I_ht0_weight);
    T_event->SetBranchAddress("f_HT", &HT);
    T_event->SetBranchAddress("I_nThinJets", &I_ht0_nThinJets);
    T_event->SetBranchAddress("v_Chi3D", &v_ht0_Chi3D);
    T_event->SetBranchAddress("v_Median_2DIPsig", &v_ht0_Median_2DIPsig);
    T_event->SetBranchAddress("v_Chi3DlogPaper", &v_ht0_Chi3DlogPaper);
    T_event->SetBranchAddress("v_Chi3Dlog", &v_ht0_Chi3Dlog);
    T_event->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        if (I_ht0_nThinJets < 2)
            continue;
        if (HT < 70)
        {
            for (auto i : *v_ht0_Median_2DIPsig)
            {
                h_ht0_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht0_weight * HT0Weight);
            }
            for (auto i : *v_ht0_Chi3D)
            {
                h_ht0_Chi3D->Fill(i, I_ht0_weight * HT0Weight);
            }
            for (auto i : *v_ht0_Chi3Dlog)
            {
                h_ht0_Chi3Dlog->Fill(i, I_ht0_weight * HT0Weight);
            }
            for (auto i : *v_ht0_Chi3DlogPaper)
            {
                h_ht0_Chi3DlogPaper->Fill(i, I_ht0_weight * HT0Weight);
            }
            for (auto i : *v_ht0_alpha)
            {
                h_ht0_alpha->Fill(i, I_ht0_weight * HT0Weight);
            }
        }
        else if (HT >= 70 && HT < 100)
        {
            for (auto i : *v_ht0_Median_2DIPsig)
            {
                h_ht70_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht0_weight * HT70Weight);
            }
            for (auto i : *v_ht0_Chi3D)
            {
                h_ht70_Chi3D->Fill(i, I_ht0_weight * HT70Weight);
            }
            for (auto i : *v_ht0_Chi3Dlog)
            {
                h_ht70_Chi3Dlog->Fill(i, I_ht0_weight * HT70Weight);
            }
            for (auto i : *v_ht0_Chi3DlogPaper)
            {
                h_ht70_Chi3DlogPaper->Fill(i, I_ht0_weight * HT70Weight);
            }
            for (auto i : *v_ht0_alpha)
            {
                h_ht70_alpha->Fill(i, I_ht0_weight * HT70Weight);
            }
        }
        else if (HT >= 100 && HT < 200)
        {
            for (auto i : *v_ht0_Median_2DIPsig)
            {
                h_ht100_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht0_weight * HT100Weight);
            }
            for (auto i : *v_ht0_Chi3D)
            {
                h_ht100_Chi3D->Fill(i, I_ht0_weight * HT100Weight);
            }
            for (auto i : *v_ht0_Chi3Dlog)
            {
                h_ht100_Chi3Dlog->Fill(i, I_ht0_weight * HT100Weight);
            }
            for (auto i : *v_ht0_Chi3DlogPaper)
            {
                h_ht100_Chi3DlogPaper->Fill(i, I_ht0_weight * HT100Weight);
            }
            for (auto i : *v_ht0_alpha)
            {
                h_ht100_alpha->Fill(i, I_ht0_weight * HT100Weight);
            }
        }
        else if (HT >= 200 && HT < 400)
        {
            for (auto i : *v_ht0_Median_2DIPsig)
            {
                h_ht200_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht0_weight * HT200Weight);
            }
            for (auto i : *v_ht0_Chi3D)
            {
                h_ht200_Chi3D->Fill(i, I_ht0_weight * HT200Weight);
            }
            for (auto i : *v_ht0_Chi3Dlog)
            {
                h_ht200_Chi3Dlog->Fill(i, I_ht0_weight * HT200Weight);
            }
            for (auto i : *v_ht0_Chi3DlogPaper)
            {
                h_ht200_Chi3DlogPaper->Fill(i, I_ht0_weight * HT200Weight);
            }
            for (auto i : *v_ht0_alpha)
            {
                h_ht200_alpha->Fill(i, I_ht0_weight * HT200Weight);
            }
        }
        else if (HT >= 400 && HT < 600)
        {
            for (auto i : *v_ht0_Median_2DIPsig)
            {
                h_ht400_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht0_weight * HT400Weight);
            }
            for (auto i : *v_ht0_Chi3D)
            {
                h_ht400_Chi3D->Fill(i, I_ht0_weight * HT400Weight);
            }
            for (auto i : *v_ht0_Chi3Dlog)
            {
                h_ht400_Chi3Dlog->Fill(i, I_ht0_weight * HT400Weight);
            }
            for (auto i : *v_ht0_Chi3DlogPaper)
            {
                h_ht400_Chi3DlogPaper->Fill(i, I_ht0_weight * HT400Weight);
            }
            for (auto i : *v_ht0_alpha)
            {
                h_ht400_alpha->Fill(i, I_ht0_weight * HT400Weight);
            }
        }
        else if (HT >= 600 && HT < 800)
        {
            for (auto i : *v_ht0_Median_2DIPsig)
            {
                h_ht600_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht0_weight * HT600Weight);
            }
            for (auto i : *v_ht0_Chi3D)
            {
                h_ht600_Chi3D->Fill(i, I_ht0_weight * HT600Weight);
            }
            for (auto i : *v_ht0_Chi3Dlog)
            {
                h_ht600_Chi3Dlog->Fill(i, I_ht0_weight * HT600Weight);
            }
            for (auto i : *v_ht0_Chi3DlogPaper)
            {
                h_ht600_Chi3DlogPaper->Fill(i, I_ht0_weight * HT600Weight);
            }
            for (auto i : *v_ht0_alpha)
            {
                h_ht600_alpha->Fill(i, I_ht0_weight * HT600Weight);
            }
        }
        else if (HT >= 800 && HT < 1200)
        {
            for (auto i : *v_ht0_Median_2DIPsig)
            {
                h_ht800_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht0_weight * HT800Weight);
            }
            for (auto i : *v_ht0_Chi3D)
            {
                h_ht800_Chi3D->Fill(i, I_ht0_weight * HT800Weight);
            }
            for (auto i : *v_ht0_Chi3Dlog)
            {
                h_ht800_Chi3Dlog->Fill(i, I_ht0_weight * HT800Weight);
            }
            for (auto i : *v_ht0_Chi3DlogPaper)
            {
                h_ht800_Chi3DlogPaper->Fill(i, I_ht0_weight * HT800Weight);
            }
            for (auto i : *v_ht0_alpha)
            {
                h_ht800_alpha->Fill(i, I_ht0_weight * HT800Weight);
            }
        }
        else if (HT >= 1200 && HT < 2500)
        {
            for (auto i : *v_ht0_Median_2DIPsig)
            {
                h_ht1200_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht0_weight * HT1200Weight);
            }
            for (auto i : *v_ht0_Chi3D)
            {
                h_ht1200_Chi3D->Fill(i, I_ht0_weight * HT1200Weight);
            }
            for (auto i : *v_ht0_Chi3Dlog)
            {
                h_ht1200_Chi3Dlog->Fill(i, I_ht0_weight * HT1200Weight);
            }
            for (auto i : *v_ht0_Chi3DlogPaper)
            {
                h_ht1200_Chi3DlogPaper->Fill(i, I_ht0_weight * HT1200Weight);
            }
            for (auto i : *v_ht0_alpha)
            {

                h_ht1200_alpha->Fill(i, I_ht0_weight * HT1200Weight);
            }
        }
        else if (HT >= 2500)
        {
            for (auto i : *v_ht0_Median_2DIPsig)
            {
                h_ht2500_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht0_weight * HT2500Weight);
            }
            for (auto i : *v_ht0_Chi3D)
            {
                h_ht2500_Chi3D->Fill(i, I_ht0_weight * HT2500Weight);
            }
            for (auto i : *v_ht0_Chi3Dlog)
            {
                h_ht2500_Chi3Dlog->Fill(i, I_ht0_weight * HT2500Weight);
            }
            for (auto i : *v_ht0_Chi3DlogPaper)
            {
                h_ht2500_Chi3DlogPaper->Fill(i, I_ht0_weight * HT2500Weight);
            }
            for (auto j : *v_ht0_alpha)
            {
                if (j > 1)
                {
                    cout << "bug" << endl;
                }
                h_ht2500_alpha->Fill(j, I_ht0_weight * HT2500Weight);
            }
        }
    }
    TTree *T_event1;
    DYHT100->GetObject("T_tree", T_event1);
    T_event1->SetBranchAddress("I_weight", &I_ht100_weight);
    T_event1->SetBranchAddress("I_nThinJets", &I_ht100_nThinJets);
    T_event1->SetBranchAddress("v_Chi3D", &v_ht100_Chi3D);
    T_event1->SetBranchAddress("v_Median_2DIPsig", &v_ht100_Median_2DIPsig);
    T_event1->SetBranchAddress("v_Chi3DlogPaper", &v_ht100_Chi3DlogPaper);
    T_event1->SetBranchAddress("v_Chi3Dlog", &v_ht100_Chi3Dlog);
    T_event1->SetBranchAddress("v_fakealpha", &v_ht100_alpha);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        if (I_ht100_nThinJets < 2)
            continue;
        for (auto i : *v_ht100_Median_2DIPsig)
        {
            h_ht100_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht100_weight * HT100Weight);
        }
        for (auto i : *v_ht100_Chi3D)
        {
            h_ht100_Chi3D->Fill(i, I_ht100_weight * HT100Weight);
        }
        for (auto i : *v_ht100_Chi3Dlog)
        {
            h_ht100_Chi3Dlog->Fill(i, I_ht100_weight * HT100Weight);
        }
        for (auto i : *v_ht100_Chi3DlogPaper)
        {
            h_ht100_Chi3DlogPaper->Fill(i, I_ht100_weight * HT100Weight);
        }
        for (auto i : *v_ht100_alpha)
        {
            if (i > 1)
            {
                cout << "bug" << endl;
                cout << "i = " << i << endl;
            }
            h_ht100_alpha->Fill(i, I_ht100_weight * HT100Weight);
        }
    }
    TTree *T_event2;
    DYHT200->GetObject("T_tree", T_event2);
    T_event2->SetBranchAddress("I_weight", &I_ht200_weight);
    T_event2->SetBranchAddress("I_nThinJets", &I_ht200_nThinJets);
    T_event2->SetBranchAddress("v_Chi3D", &v_ht200_Chi3D);
    T_event2->SetBranchAddress("v_Median_2DIPsig", &v_ht200_Median_2DIPsig);
    T_event2->SetBranchAddress("v_Chi3DlogPaper", &v_ht200_Chi3DlogPaper);
    T_event2->SetBranchAddress("v_Chi3Dlog", &v_ht200_Chi3Dlog);
    T_event2->SetBranchAddress("v_fakealpha", &v_ht200_alpha);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        if (I_ht200_nThinJets < 2)
            continue;
        for (auto i : *v_ht200_Median_2DIPsig)
        {
            h_ht200_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht200_weight * HT200Weight);
        }
        for (auto i : *v_ht200_Chi3D)
        {
            h_ht200_Chi3D->Fill(i, I_ht200_weight * HT200Weight);
        }
        for (auto i : *v_ht200_Chi3Dlog)
        {
            h_ht200_Chi3Dlog->Fill(i, I_ht200_weight * HT200Weight);
        }
        for (auto i : *v_ht200_Chi3DlogPaper)
        {
            h_ht200_Chi3DlogPaper->Fill(i, I_ht200_weight * HT200Weight);
        }
        for (auto i : *v_ht200_alpha)
        {
            if (i > 1)
            {
                cout << "bug" << endl;
            }
            h_ht200_alpha->Fill(i, I_ht200_weight * HT200Weight);
        }
    }
    TTree *T_event3;
    DYHT400->GetObject("T_tree", T_event3);
    T_event3->SetBranchAddress("I_weight", &I_ht400_weight);
    T_event3->SetBranchAddress("I_nThinJets", &I_ht400_nThinJets);
    T_event3->SetBranchAddress("v_Chi3D", &v_ht400_Chi3D);
    T_event3->SetBranchAddress("v_Median_2DIPsig", &v_ht400_Median_2DIPsig);
    T_event3->SetBranchAddress("v_Chi3DlogPaper", &v_ht400_Chi3DlogPaper);
    T_event3->SetBranchAddress("v_Chi3Dlog", &v_ht400_Chi3Dlog);
    T_event3->SetBranchAddress("v_fakealpha", &v_ht400_alpha);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        if (I_ht400_nThinJets < 2)
            continue;
        for (auto i : *v_ht400_Median_2DIPsig)
        {
            h_ht400_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht400_weight * HT400Weight);
        }
        for (auto i : *v_ht400_Chi3D)
        {
            h_ht400_Chi3D->Fill(i, I_ht400_weight * HT400Weight);
        }
        for (auto i : *v_ht400_Chi3Dlog)
        {
            h_ht400_Chi3Dlog->Fill(i, I_ht400_weight * HT400Weight);
        }
        for (auto i : *v_ht400_Chi3DlogPaper)
        {
            h_ht400_Chi3DlogPaper->Fill(i, I_ht400_weight * HT400Weight);
        }
        for (auto i : *v_ht400_alpha)
        {
            if (i > 1)
            {
                cout << "bug" << endl;
                cout << "i = " << i << endl;
            }
            h_ht400_alpha->Fill(i, I_ht400_weight * HT400Weight);
        }
    }
    TTree *T_event4;
    DYHT600->GetObject("T_tree", T_event4);
    T_event4->SetBranchAddress("I_weight", &I_ht600_weight);
    T_event4->SetBranchAddress("I_nThinJets", &I_ht600_nThinJets);
    T_event4->SetBranchAddress("v_Chi3D", &v_ht600_Chi3D);
    T_event4->SetBranchAddress("v_Median_2DIPsig", &v_ht600_Median_2DIPsig);
    T_event4->SetBranchAddress("v_Chi3DlogPaper", &v_ht600_Chi3DlogPaper);
    T_event4->SetBranchAddress("v_Chi3Dlog", &v_ht600_Chi3Dlog);
    T_event4->SetBranchAddress("v_fakealpha", &v_ht600_alpha);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        if (I_ht600_nThinJets < 2)
            continue;
        for (auto i : *v_ht600_Median_2DIPsig)
        {
            h_ht600_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht600_weight * HT600Weight);
        }
        for (auto i : *v_ht600_Chi3D)
        {
            h_ht600_Chi3D->Fill(i, I_ht600_weight * HT600Weight);
        }
        for (auto i : *v_ht600_Chi3Dlog)
        {
            h_ht600_Chi3Dlog->Fill(i, I_ht600_weight * HT600Weight);
        }
        for (auto i : *v_ht600_Chi3DlogPaper)
        {
            h_ht600_Chi3DlogPaper->Fill(i, I_ht600_weight * HT600Weight);
        }
        for (auto i : *v_ht600_alpha)
        {
            if (i > 1)
            {
                cout << "bug" << endl;
                cout << "i = " << i << endl;
            }
            h_ht600_alpha->Fill(i, I_ht600_weight * HT600Weight);
        }
    }
    TTree *T_event5;
    DYHT800->GetObject("T_tree", T_event5);
    T_event5->SetBranchAddress("I_weight", &I_ht800_weight);
    T_event5->SetBranchAddress("I_nThinJets", &I_ht800_nThinJets);
    T_event5->SetBranchAddress("v_Chi3D", &v_ht800_Chi3D);
    T_event5->SetBranchAddress("v_Median_2DIPsig", &v_ht800_Median_2DIPsig);
    T_event5->SetBranchAddress("v_Chi3DlogPaper", &v_ht800_Chi3DlogPaper);
    T_event5->SetBranchAddress("v_Chi3Dlog", &v_ht800_Chi3Dlog);
    T_event5->SetBranchAddress("v_fakealpha", &v_ht800_alpha);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        if (I_ht800_nThinJets < 2)
            continue;
        for (auto i : *v_ht800_Median_2DIPsig)
        {
            h_ht800_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht800_weight * HT800Weight);
        }
        for (auto i : *v_ht800_Chi3D)
        {
            h_ht800_Chi3D->Fill(i, I_ht800_weight * HT800Weight);
        }
        for (auto i : *v_ht800_Chi3Dlog)
        {
            h_ht800_Chi3Dlog->Fill(i, I_ht800_weight * HT800Weight);
        }
        for (auto i : *v_ht800_Chi3DlogPaper)
        {
            h_ht800_Chi3DlogPaper->Fill(i, I_ht800_weight * HT800Weight);
        }
        for (auto i : *v_ht800_alpha)
        {
            if (i > 1)
            {
                cout << "bug" << endl;
                cout << "i = " << i << endl;
            }
            h_ht800_alpha->Fill(i, I_ht800_weight * HT800Weight);
        }
    }
    TTree *T_event6;
    DYHT1200->GetObject("T_tree", T_event6);
    T_event6->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_event6->SetBranchAddress("I_nThinJets", &I_ht1200_nThinJets);
    T_event6->SetBranchAddress("v_Chi3D", &v_ht1200_Chi3D);
    T_event6->SetBranchAddress("v_Median_2DIPsig", &v_ht1200_Median_2DIPsig);
    T_event6->SetBranchAddress("v_Chi3DlogPaper", &v_ht1200_Chi3DlogPaper);
    T_event6->SetBranchAddress("v_Chi3Dlog", &v_ht1200_Chi3Dlog);
    T_event6->SetBranchAddress("v_fakealpha", &v_ht1200_alpha);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        if (I_ht1200_nThinJets < 2)
            continue;
        for (auto i : *v_ht1200_Median_2DIPsig)
        {
            h_ht1200_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht1200_weight * HT1200Weight);
        }
        for (auto i : *v_ht1200_Chi3D)
        {
            h_ht1200_Chi3D->Fill(i, I_ht1200_weight * HT1200Weight);
        }
        for (auto i : *v_ht1200_Chi3Dlog)
        {
            h_ht1200_Chi3Dlog->Fill(i, I_ht1200_weight * HT1200Weight);
        }
        for (auto i : *v_ht1200_Chi3DlogPaper)
        {
            h_ht1200_Chi3DlogPaper->Fill(i, I_ht1200_weight * HT1200Weight);
        }
        for (auto i : *v_ht1200_alpha)
        {
            if (i > 1)
            {
                cout << "bug" << endl;
                cout << "i = " << i << endl;
            }
            h_ht1200_alpha->Fill(i, I_ht1200_weight * HT1200Weight);
        }
    }
    TTree *T_event7;
    DYHT2500->GetObject("T_tree", T_event7);
    T_event7->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_event7->SetBranchAddress("I_nThinJets", &I_ht2500_nThinJets);
    T_event7->SetBranchAddress("v_Chi3D", &v_ht2500_Chi3D);
    T_event7->SetBranchAddress("v_Median_2DIPsig", &v_ht2500_Median_2DIPsig);
    T_event7->SetBranchAddress("v_Chi3DlogPaper", &v_ht2500_Chi3DlogPaper);
    T_event7->SetBranchAddress("v_Chi3Dlog", &v_ht2500_Chi3Dlog);
    T_event7->SetBranchAddress("v_fakealpha", &v_ht2500_alpha);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        if (I_ht2500_nThinJets < 2)
            continue;
        for (auto i : *v_ht2500_Median_2DIPsig)
        {
            h_ht2500_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_ht2500_weight * HT2500Weight);
        }
        for (auto i : *v_ht2500_Chi3D)
        {
            h_ht2500_Chi3D->Fill(i, I_ht2500_weight * HT2500Weight);
        }
        for (auto i : *v_ht2500_Chi3Dlog)
        {
            h_ht2500_Chi3Dlog->Fill(i, I_ht2500_weight * HT2500Weight);
        }
        for (auto i : *v_ht2500_Chi3DlogPaper)
        {
            h_ht2500_Chi3DlogPaper->Fill(i, I_ht2500_weight * HT2500Weight);
        }
        for (auto i : *v_ht2500_alpha)
        {
            if (i > 1)
            {
                cout << "bug" << endl;
                cout << "i = " << i << endl;
            }
            h_ht2500_alpha->Fill(i, I_ht2500_weight * HT2500Weight);
        }
    }

    TTree *Mx1_tree;
    Mx2_1->GetObject("T_tree", Mx1_tree);
    Mx1_tree->SetBranchAddress("I_weight", &I_Mx1_weight);
    Mx1_tree->SetBranchAddress("I_nThinJets", &I_Mx1_nThinJets);
    Mx1_tree->SetBranchAddress("v_Chi3D", &v_Mx2_1_Chi3D);
    Mx1_tree->SetBranchAddress("v_Median_2DIPsig", &v_Mx2_1_Median_2DIP);
    Mx1_tree->SetBranchAddress("v_Chi3DlogPaper", &v_Mx2_1_Chi3DlogPaper);
    Mx1_tree->SetBranchAddress("v_Chi3Dlog", &v_Mx2_1_Chi3Dlog);
    Mx1_tree->SetBranchAddress("v_fakealpha", &v_Mx2_1_alpha);
    for (int evt = 0; evt < Mx1_tree->GetEntries(); evt++)
    {
        Mx1_tree->GetEntry(evt);
        if (I_Mx1_nThinJets < 2)
            continue;
        for (auto i : *v_Mx2_1_Median_2DIP)
        {
            h_Mx2_1_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_Mx1_weight);
        }
        for (auto i : *v_Mx2_1_Chi3D)
        {
            h_Mx2_1_Chi3D->Fill(i, I_Mx1_weight);
        }
        for (auto i : *v_Mx2_1_Chi3Dlog)
        {
            h_Mx2_1_Chi3Dlog->Fill(i, I_Mx1_weight);
        }
        for (auto i : *v_Mx2_1_Chi3DlogPaper)
        {
            h_Mx2_1_Chi3DlogPaper->Fill(i, I_Mx1_weight);
        }
        for (auto i : *v_Mx2_1_alpha)
        {
            h_Mx2_1_alpha->Fill(i, I_Mx1_weight);
        }
    }
    TTree *Mx50_tree;
    Mx2_50->GetObject("T_tree", Mx50_tree);
    Mx50_tree->SetBranchAddress("I_weight", &I_Mx50_weight);
    Mx50_tree->SetBranchAddress("I_nThinJets", &I_Mx50_nThinJets);
    Mx50_tree->SetBranchAddress("v_Chi3D", &v_Mx2_50_Chi3D);
    Mx50_tree->SetBranchAddress("v_Median_2DIPsig", &v_Mx2_50_Median_2DIP);
    Mx50_tree->SetBranchAddress("v_Chi3DlogPaper", &v_Mx2_50_Chi3DlogPaper);
    Mx50_tree->SetBranchAddress("v_Chi3Dlog", &v_Mx2_50_Chi3Dlog);
    Mx50_tree->SetBranchAddress("v_fakealpha", &v_Mx2_50_alpha);
    for (int evt = 0; evt < Mx50_tree->GetEntries(); evt++)
    {
        Mx50_tree->GetEntry(evt);
        if (I_Mx50_nThinJets < 2)
            continue;
        for (auto i : *v_Mx2_50_Median_2DIP)
        {
            h_Mx2_50_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_Mx50_weight);
        }
        for (auto i : *v_Mx2_50_Chi3D)
        {
            h_Mx2_50_Chi3D->Fill(i, I_Mx50_weight);
        }
        for (auto i : *v_Mx2_50_Chi3Dlog)
        {
            h_Mx2_50_Chi3Dlog->Fill(i, I_Mx50_weight);
        }
        for (auto i : *v_Mx2_50_Chi3DlogPaper)
        {
            h_Mx2_50_Chi3DlogPaper->Fill(i, I_Mx50_weight);
        }
        for (auto i : *v_Mx2_50_alpha)
        {
            h_Mx2_50_alpha->Fill(i, I_Mx50_weight);
        }
    }
    TTree *Mx150_tree;
    Mx2_150->GetObject("T_tree", Mx150_tree);
    Mx150_tree->SetBranchAddress("I_weight", &I_Mx150_weight);
    Mx150_tree->SetBranchAddress("I_nThinJets", &I_Mx150_nThinJets);
    Mx150_tree->SetBranchAddress("v_Chi3D", &v_Mx2_150_Chi3D);
    Mx150_tree->SetBranchAddress("v_Median_2DIPsig", &v_Mx2_150_Median_2DIP);
    Mx150_tree->SetBranchAddress("v_Chi3DlogPaper", &v_Mx2_150_Chi3DlogPaper);
    Mx150_tree->SetBranchAddress("v_Chi3Dlog", &v_Mx2_150_Chi3Dlog);
    Mx150_tree->SetBranchAddress("v_fakealpha", &v_Mx2_150_alpha);
    for (int evt = 0; evt < Mx150_tree->GetEntries(); evt++)
    {
        Mx150_tree->GetEntry(evt);
        if (I_Mx150_nThinJets < 2)
            continue;
        for (auto i : *v_Mx2_150_Median_2DIP)
        {
            h_Mx2_150_Median_2DIP->Fill(log10(sqrt(pow(i, 2))), I_Mx150_weight);
        }
        for (auto i : *v_Mx2_150_Chi3D)
        {
            h_Mx2_150_Chi3D->Fill(i, I_Mx150_weight);
        }
        for (auto i : *v_Mx2_150_Chi3Dlog)
        {
            h_Mx2_150_Chi3Dlog->Fill(i, I_Mx150_weight);
        }
        for (auto i : *v_Mx2_150_Chi3DlogPaper)
        {
            h_Mx2_150_Chi3DlogPaper->Fill(i, I_Mx150_weight);
        }
        for (auto i : *v_Mx2_150_alpha)
        {
            h_Mx2_150_alpha->Fill(i, I_Mx150_weight);
        }
    }

    h_ht0_Median_2DIP->Add(h_ht70_Median_2DIP);
    h_ht0_Median_2DIP->Add(h_ht100_Median_2DIP);
    h_ht0_Median_2DIP->Add(h_ht200_Median_2DIP);
    h_ht0_Median_2DIP->Add(h_ht400_Median_2DIP);
    h_ht0_Median_2DIP->Add(h_ht600_Median_2DIP);
    h_ht0_Median_2DIP->Add(h_ht800_Median_2DIP);
    h_ht0_Median_2DIP->Add(h_ht1200_Median_2DIP);
    h_ht0_Median_2DIP->Add(h_ht2500_Median_2DIP);

    h_ht0_Chi3D->Add(h_ht70_Chi3D);
    h_ht0_Chi3D->Add(h_ht100_Chi3D);
    h_ht0_Chi3D->Add(h_ht200_Chi3D);
    h_ht0_Chi3D->Add(h_ht400_Chi3D);
    h_ht0_Chi3D->Add(h_ht600_Chi3D);
    h_ht0_Chi3D->Add(h_ht800_Chi3D);
    h_ht0_Chi3D->Add(h_ht1200_Chi3D);
    h_ht0_Chi3D->Add(h_ht2500_Chi3D);

    h_ht0_Chi3Dlog->Add(h_ht70_Chi3Dlog);
    h_ht0_Chi3Dlog->Add(h_ht100_Chi3Dlog);
    h_ht0_Chi3Dlog->Add(h_ht200_Chi3Dlog);
    h_ht0_Chi3Dlog->Add(h_ht400_Chi3Dlog);
    h_ht0_Chi3Dlog->Add(h_ht600_Chi3Dlog);
    h_ht0_Chi3Dlog->Add(h_ht800_Chi3Dlog);
    h_ht0_Chi3Dlog->Add(h_ht1200_Chi3Dlog);
    h_ht0_Chi3Dlog->Add(h_ht2500_Chi3Dlog);

    h_ht0_Chi3DlogPaper->Add(h_ht70_Chi3DlogPaper);
    h_ht0_Chi3DlogPaper->Add(h_ht100_Chi3DlogPaper);
    h_ht0_Chi3DlogPaper->Add(h_ht200_Chi3DlogPaper);
    h_ht0_Chi3DlogPaper->Add(h_ht400_Chi3DlogPaper);
    h_ht0_Chi3DlogPaper->Add(h_ht600_Chi3DlogPaper);
    h_ht0_Chi3DlogPaper->Add(h_ht800_Chi3DlogPaper);
    h_ht0_Chi3DlogPaper->Add(h_ht1200_Chi3DlogPaper);
    h_ht0_Chi3DlogPaper->Add(h_ht2500_Chi3DlogPaper);

    h_ht0_alpha->Add(h_ht70_alpha);
    h_ht0_alpha->Add(h_ht100_alpha);
    h_ht0_alpha->Add(h_ht200_alpha);
    h_ht0_alpha->Add(h_ht400_alpha);
    h_ht0_alpha->Add(h_ht600_alpha);
    h_ht0_alpha->Add(h_ht800_alpha);
    h_ht0_alpha->Add(h_ht1200_alpha);
    h_ht0_alpha->Add(h_ht2500_alpha);

    h_ht0_Chi3Dlog->SetLineWidth(2);
    h_ht0_Chi3D->SetLineWidth(2);
    h_ht0_Chi3DlogPaper->SetLineWidth(2);

    // TTTo2L2Nu_3Dsig->SetLineWidth(2);
    h_Mx2_1_Chi3Dlog->SetLineWidth(2);
    h_Mx2_50_Chi3Dlog->SetLineWidth(2);
    h_Mx2_150_Chi3Dlog->SetLineWidth(2);

    h_Mx2_50_Chi3D->SetLineWidth(2);

    // TTTo2L2Nu_3Dsigpaper->SetLineWidth(2);
    h_Mx2_1_Chi3DlogPaper->SetLineWidth(2);
    h_Mx2_50_Chi3DlogPaper->SetLineWidth(2);
    h_Mx2_150_Chi3DlogPaper->SetLineWidth(2);

    h_Mx2_1_Chi3Dlog->SetLineColor(kBlack);
    h_Mx2_1_Chi3DlogPaper->SetLineColor(kBlack);
    h_Mx2_50_Chi3Dlog->SetLineColor(kBlue);
    h_Mx2_50_Chi3DlogPaper->SetLineColor(kBlue);
    h_Mx2_50_Chi3D->SetLineColor(kBlue);
    h_Mx2_150_Chi3Dlog->SetLineColor(kGreen - 5);
    h_Mx2_150_Chi3DlogPaper->SetLineColor(kGreen - 5);

    h_ht0_Chi3Dlog->SetLineColor(kMagenta);
    h_ht0_Chi3DlogPaper->SetLineColor(kMagenta);
    h_ht0_Chi3D->SetLineColor(kMagenta);

    // TTTo2L2Nu_3Dsig->SetLineColor(kRed);
    // TTTo2L2Nu_3Dsigpaper->SetLineColor(kRed);

    h_ht0_Chi3Dlog->SetTitle("3Dsig");
    h_ht0_Chi3Dlog->GetYaxis()->SetTitle("N Tracks/Normalized");
    h_ht0_Chi3Dlog->GetXaxis()->SetTitle("log_{10}(3DIP_{sig})");

    h_ht0_Chi3DlogPaper->SetTitle("X");
    h_ht0_Chi3DlogPaper->GetYaxis()->SetTitle("N Tracks/Normalized");
    h_ht0_Chi3DlogPaper->GetXaxis()->SetTitle("log_{10}(X)");

    h_ht0_Chi3Dlog->DrawNormalized("hist");
    h_Mx2_50_Chi3Dlog->DrawNormalized("hist&&same");
}
