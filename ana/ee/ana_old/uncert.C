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

void uncert(){

    TFile *ABCD = new TFile("./../../ABCD.root");

    TH1F *h_pt50_A = ((TH1F *)ABCD->Get("h_pt50_A_alphamin"));
    TH1F *h_pt50_B = ((TH1F *)ABCD->Get("h_pt50_B_alphamin"));
    TH1F *h_pt50_C = ((TH1F *)ABCD->Get("h_pt50_C_alphamin"));
    TH1F *h_pt50_D = ((TH1F *)ABCD->Get("h_pt50_D_alphamin"));



    int AnBin = h_pt50_A->GetNbinsX();

    float ASum = 0;
    for (int i = 0; i < AnBin; i++)
    {
        ASum +=h_pt50_A->GetBinContent(i + 1);
    }
    float Amean = ASum/ AnBin;
    //cout <<"event[0] = "<<ASum<<endl;
    //cout <<"Amean = "<<Amean<<endl;

    float da_sum = 0;
    //Calculate Uncert
    for (int i = 0; i < AnBin; i++)
    {
        float di = 0;
        di = h_pt50_A->GetBinContent(i + 1)-Amean;
        da_sum += di*di; 
    }
    float Auuncer = sqrt(da_sum/AnBin);
    //cout <<"Auuncer = "<<Auuncer<<endl;

    int BnBin = h_pt50_B->GetNbinsX();

    float BSum = 0;
    for (int i = 0; i < BnBin; i++)
    {
        BSum +=h_pt50_B->GetBinContent(i + 1);
    }
    float Bmean = BSum/ BnBin;
    //cout <<"event[0] = "<<BSum<<endl;
    //cout <<"Bmean = "<<Bmean<<endl;

    float db_sum = 0;
    //Calculate Uncert
    for (int i = 0; i < BnBin; i++)
    {
        float di = 0;
        di = h_pt50_B->GetBinContent(i + 1)-Bmean;
        db_sum += di*di; 
    }
    float Buuncer = sqrt(db_sum/BnBin);
    //cout <<"Buuncer = "<<Buuncer<<endl;

    //divide uncert
    float Na = h_pt50_A->Integral();
    float Nb = h_pt50_B->Integral();
    cout <<"Na = "<<Na<< " +- " <<Auuncer<<endl;
    cout <<"Nb = "<<Nb<< " +- " <<Buuncer<<endl;
    float didunert = sqrt((Auuncer/Amean)*(Auuncer/Amean)+(Buuncer/Bmean)*(Buuncer/Bmean))*((Amean)/(Bmean));
    //cout <<"didunert = "<<didunert<<endl;
    cout <<"Na/Nb = "<<Na/Nb<< " +- " <<didunert<<endl;

    int CnBin = h_pt50_C->GetNbinsX();

    float CSum = 0;
    for (int i = 0; i < CnBin; i++)
    {
        CSum +=h_pt50_C->GetBinContent(i + 1);
    }
    float Cmean = CSum/ CnBin;
    //cout <<"event[0] = "<<ASum<<endl;
    //cout <<"Amean = "<<Amean<<endl;

    float dc_sum = 0;
    //Calculate Uncert
    for (int i = 0; i < CnBin; i++)
    {
        float di = 0;
        di = h_pt50_C->GetBinContent(i + 1)-Cmean;
        dc_sum += di*di; 
    }
    float Cuuncer = sqrt(dc_sum/CnBin);
    //cout <<"Auuncer = "<<Auuncer<<endl;

    int DnBin = h_pt50_D->GetNbinsX();

    float DSum = 0;
    for (int i = 0; i < DnBin; i++)
    {
        DSum +=h_pt50_D->GetBinContent(i + 1);
    }
    float Dmean = DSum/ DnBin;
    //cout <<"event[0] = "<<BSum<<endl;
    //cout <<"Bmean = "<<Bmean<<endl;

    float dd_sum = 0;
    //Calculate Uncert
    for (int i = 0; i < DnBin; i++)
    {
        float di = 0;
        di = h_pt50_D->GetBinContent(i + 1)-Dmean;
        dd_sum += di*di; 
    }
    float Duuncer = sqrt(dd_sum/DnBin);
   //divide uncert
    float Nc = h_pt50_C->Integral();
    float Nd = h_pt50_D->Integral();
    cout <<"Nc = "<<Nc<< " +- " <<Cuuncer<<endl;
    cout <<"Nd = "<<Nd<< " +- " <<Duuncer<<endl;
    float didcunert = sqrt((Cuuncer/Cmean)*(Cuuncer/Cmean)+(Duuncer/Dmean)*(Duuncer/Dmean))*((Cmean)/(Dmean));
    cout <<"Nc/Nd = "<<Nc/Nd<< " +- " <<didcunert<<endl;


}