#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
using namespace std;
void Top_split()
{
    TFile *Top_file = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
    //TFile *Top_TTWJetsToLNu = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    //TFile *Top_TTWJetsToQQ = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    //TFile *Top_TTZToLLNuNu = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    //TFile *Top_TTZToQQ = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    //TFile *Top_tW_antitop = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    //TFile *Top_tW_top = new TFile("./../../root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

    TTree *T_event;
    Top_file->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_weight", &f_tW_top_weight);
    T_event->SetBranchAddress("f_alphamin", &f_tW_top_alphamin);
    T_event->SetBranchAddress("f_Met", &f_tW_top_met);
    T_event->SetBranchAddress("I_nThinJets", &I_tW_top_nThinJets);
    T_event->SetBranchAddress("f_leadJetpt", &f_tW_top_leadJetpt);
    T_event->SetBranchAddress("f_leadJeteta", &f_tW_top_leadJeteta);
    T_event->SetBranchAddress("f_dileptonPT", &f_tW_top_dilpPT);

}