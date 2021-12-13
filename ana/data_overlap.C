#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <time.h>

using namespace std;

void data_overlap()
{
    TFile *data_DouEe = new TFile("./../../root_file/data/data_DouEG.root");

    ULong64_t I_eventID;
    TTree *T_event;

    data_DouEe->GetObject("T_event", T_event);
    T_event->SetBranchAddress("I_eventID", &I_eventID);

    vector<ULong64_t> DiEG_eventID;
    DiEG_eventID.clear();

    ofstream ofs;

    ofs.open("output.txt");

    if (!ofs.is_open())
    {
        cout << "Failed to open file.\n";
    }
    else
    {
        Int_t total_n = (Int_t)T_event->GetEntries();
        for (Int_t i = 0; i < total_n; i++)
        {

            T_event->GetEntry(i);
            //cout << I_eventID << endl;
            DiEG_eventID.push_back(I_eventID);
            ofs << I_eventID << "\n";
        }
        ofs.close();
    }
    cout << DiEG_eventID.size() << endl;

    //deal with overlap

    TFile *data_SigEe = new TFile("./../../root_file/data/data_SigE.root");

    ULong64_t SigEe_eventID;
    float_t SigEe_Met;
    Double_t SigEe_alphamin;

    TTree *SigEe_tree;

    data_SigEe->GetObject("T_event", SigEe_tree);
    SigEe_tree->SetBranchAddress("I_eventID", &SigEe_eventID);
    SigEe_tree->SetBranchAddress("f_Met", &SigEe_Met);
    SigEe_tree->SetBranchAddress("f_alphamin", &SigEe_alphamin);
    

    ULong64_t new_eventID;
    float_t new_Met ;
    Double_t new_alphamin;

    TFile *f2 = new TFile("new.root", "recreate");
    TTree *h1 = new TTree("h1", "");

    h1->Branch("new_eventID", &new_eventID, "new_eventID/l");
    h1->Branch("new_Met", &new_Met, "new_Met/f");
    h1->Branch("new_alphamin", &new_alphamin, "new_alphamin/D");

    Int_t total_n = (Int_t)SigEe_tree->GetEntries();

    clock_t start, end;
    double cpu_time;

    start = clock();

    for (Int_t k = 0; k < total_n; k++)
    {
        SigEe_tree->GetEntry(k);

        vector<ULong64_t>::iterator it = std::find(DiEG_eventID.begin(), DiEG_eventID.end(), SigEe_eventID);
        if (it != DiEG_eventID.end())
        {
            //cout << "find" << endl;
            continue;
        }
        else
        {
            new_eventID = SigEe_eventID;
            new_Met = SigEe_Met;
            new_alphamin = SigEe_alphamin;
            //if(new_eventID < 0)
            //{
            //    cout << "bug" << endl;
            //}
            //cout << "not find" << endl;
        }
        h1->Fill();
    }

    h1->Write();
    end = clock();

    cpu_time = ((double)(end -start))/CLOCKS_PER_SEC;

    cout << "# of writen events: "<<h1->GetEntries()<<endl;
    cout << "cpu time = "<<cpu_time<<endl;

    f2->Close();
/*
    TFile *new_SigEe = new TFile("./data_SigE_v2.root", "recreate");

    ULong64_t new_SigEe_eventID;
    
    TTree *new_SigEe_event;

    new_SigEe->GetObject("h1", new_SigEe_event);
    new_SigEe_event->SetBranchAddress("new_eventID", &new_SigEe_eventID);

    ofstream ofs2;

    ofs2.open("output2.txt");

    if (!ofs2.is_open())
    {
        cout << "Failed to open file.\n";
    }
    else
    {
        Int_t total_n = (Int_t)new_SigEe_event->GetEntries();
        for (Int_t i = 0; i < total_n; i++)
        {
            new_SigEe_event->GetEntry(i);
            ofs2 << new_SigEe_eventID << "\n";
        }
        ofs2.close();
    }
    */
}