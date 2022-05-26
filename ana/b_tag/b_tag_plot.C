#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <string>
#include <TAttLine.h>
#include <TStyle.h>
#include "TTreeReader.h"
#include "./../lib/untuplizer.h"
using namespace std;
void b_tag_plot()
{
    string inputtxtFilename = "/home/kuanyu/Documents/root_file/Ztoee/NCUGlobalTuples_1.root";
    // ifstream flist(inputtxtFilename.data());

    TreeReader data(inputtxtFilename.data());
    vector<float> *jetSSV;
    vector<float> *jetCSV;
    vector<float> *jetSSVHE;
    vector<float> *jetCISVV2;
    vector<float> *jetTCHP;
    vector<float> *jetTCHE;
    vector<float> *jetJP;
    vector<float> *jetJBP;

    jetSSV->clear();
    jetCSV->clear();
    jetSSVHE->clear();
    jetCISVV2->clear();
    jetTCHP->clear();
    jetTCHE->clear();
    jetJP->clear();
    jetJBP->clear();
    for (Long64_t jEntry = 0; jEntry < data.GetEntriesFast(); jEntry++)
    {   
        data.GetEntry(jEntry);
        int nTHINJets = data.GetInt("THINnJet");
        float *thinJetSSV = data.GetPtrFloat("THINjetSSV");
        float *thinJetCSV = data.GetPtrFloat("THINjetCSV");
        float *thinJetSSVHE = data.GetPtrFloat("THINjetSSVHE");
        float *thinJetCISVV2 = data.GetPtrFloat("THINjetCISVV2");
        float *thinJetTCHP = data.GetPtrFloat("THINjetTCHP");
        float *thinJetTCHE = data.GetPtrFloat("THINjetTCHE");
        float *thinJetJP = data.GetPtrFloat("THINjetJP");
        float *thinJetJBP = data.GetPtrFloat("THINjetJBP");
        cout<<nTHINJets<<endl;
        for (int i = 0; i < nTHINJets; i++)
        {
            cout <<thinJetSSVHE[i]<<endl;
        }
    }
}