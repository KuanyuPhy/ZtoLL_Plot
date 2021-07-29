
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
#include "Cross_section.h"

float Linear_Correlation(TTree *BDT_variables, float x, float y)
{
    Int_t  total_n = (Int_t )BDT_variables->GetEntries();
    float sumx = 0;
    float sumy = 0;
    float sumxy = 0;
    float sumxsq = 0;
    float sumysq = 0;
    for (Int_t  k = 0; k < total_n; k++)
    {
        BDT_variables->GetEntry(k);
        sumx += x;
        sumy += y;
        sumxy += x * y;
        sumxsq += x * x;
        sumysq += y * y;
    }
    float numerator = total_n * sumxy - sumx * sumy;
    float denominator = sqrt((total_n * sumxsq - sumx * sumx) * (total_n * sumysq - sumy * sumy));

    float CR = (numerator / denominator);

    return CR;
}


void correlate_plot(){


    TFile *Mx2_1 = new TFile("./../../root_file/test/test1.root");
    TFile *Mx2_50 = new TFile("./../../root_file/test/test50.root");
    TFile *Mx2_150 = new TFile("./../../root_file/test/test150.root");
    
    TFile *DYpT50 = new TFile("./../../root_file/test/test_pt50.root");
    

    int I_nJets;
    double f_alphamin;
    float f_Met;

    TTree *BDT_variables;
    DYpT50->GetObject("BDT_variables",BDT_variables);
    BDT_variables->SetBranchAddress("I_nJets",&I_nJets);
    BDT_variables->SetBranchAddress("f_alphamin",&f_alphamin);
    BDT_variables->SetBranchAddress("f_Met",&f_Met);
    
    
    Int_t  total_n = (Int_t )BDT_variables->GetEntries();

     double sumx = 0.;
     double sumy = 0.;
     double sumxy = 0.;
     double sumxsq = 0.;
     double sumysq = 0.;

    for (Int_t  k = 0; k < total_n; k++)
    {

        BDT_variables->GetEntry(k);
        sumx += f_alphamin;
        sumy += f_Met;
        sumxy += f_alphamin * f_Met;
        sumxsq += f_alphamin * f_alphamin;
        sumysq += f_Met * f_Met;

    }

        double numerator = total_n * sumxy - sumx * sumy;
        double denominator = sqrt((total_n * sumxsq - sumx * sumx) * (total_n * sumysq - sumy * sumy));

        cout << "Linear Correlation for all = " << abs(numerator / denominator) << endl;
        //cout << "root Correlation for de and mbc = " << correlation(I_nJets, f_alphamin) << endl;

}

