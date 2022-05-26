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
void ee_half_Top_apply_fake_rate()
{
    TFile *fakeRate = new TFile("./../../../../root_file/BgEstimation/Clouse_test.root");

    TFile *Top_TTTo2L2Nu = new TFile("./../../../../root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");

    TFile *Top_TTTo2L2Nu_2 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTTo2L2Nu_2.root");

    TH1F *Top_hev_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_hev_emergjetnTrack_fakeRate"));
    TH1F *Top_light_fakerate_ntr = ((TH1F *)fakeRate->Get("Top_light_emergjetnTrack_fakeRate"));

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)Top_TTTo2L2Nu->Get("Event_Variable/h_totevent"));

    int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();
    

    //----------------------------------------------------------------------
    // Create Histrogram: PT, eta, NTracks
    //----------------------------------------------------------------------
    TH1F *h_TTTo2L2Nu_hev_exp_emergjetpt = new TH1F("h_TTTo2L2Nu_hev_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_hev_exp_emergjetpt->Sumw2();

    TH1F *h_TTTo2L2Nu_light_exp_emergjetpt = new TH1F("h_TTTo2L2Nu_light_exp_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_light_exp_emergjetpt->Sumw2();

    Double_t nbins[82] = {-4.889, -4.716, -4.538, -4.363, -4.191, -4.013, -3.839, -3.664, -3.489, -3.314, -3.139, -2.964, -2.853,
                          -2.65, -2.5, -2.322, -2.172, -2.043, -1.93, -1.83, -1.74, -1.653, -1.566, -1.479, -1.392, -1.305, -1.218, -1.131, -1.044,
                          -0.957, -0.879, -0.783, -0.696, -0.609, -0.522, -0.435, -0.348, -0.261, -0.174, -0.087, 0, 0.087, 0.174, 0.261, 0.348, 0.435,
                          0.522, 0.609, 0.696, 0.783, 0.879, 0.957, 1.044, 1.131, 1.218, 1.305, 1.392, 1.479, 1.566, 1.653, 1.74, 1.83, 1.93, 2.043, 2.172,
                          2.322, 2.5, 2.65, 2.853, 2.964, 3.139, 3.314, 3.489, 3.664, 3.839, 4.013, 4.191, 4.363, 4.538, 4.716, 4.889, 5.191};
    const Int_t nnbins = (sizeof(nbins) / sizeof(*nbins)) - 1;

    TH1F *h_TTTo2L2Nu_hev_exp_emergjetEta = new TH1F("h_TTTo2L2Nu_hev_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_TTTo2L2Nu_hev_exp_emergjetEta->Sumw2();

    TH1F *h_TTTo2L2Nu_light_exp_emergjetEta = new TH1F("h_TTTo2L2Nu_light_exp_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_TTTo2L2Nu_light_exp_emergjetEta->Sumw2();

    TH1F *h_TTTo2L2Nu_hev_exp_emergjetnTrack = new TH1F("h_TTTo2L2Nu_hev_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTTo2L2Nu_hev_exp_emergjetnTrack->Sumw2();

    TH1F *h_TTTo2L2Nu_light_exp_emergjetnTrack = new TH1F("h_TTTo2L2Nu_light_exp_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTTo2L2Nu_light_exp_emergjetnTrack->Sumw2();

    TH1F *h_TTTo2L2Nu_hev_pred_emergjetpt = new TH1F("h_TTTo2L2Nu_hev_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_hev_pred_emergjetpt->Sumw2();

    TH1F *h_TTTo2L2Nu_light_pred_emergjetpt = new TH1F("h_TTTo2L2Nu_light_pred_emergjetpt", "emerging jet pt", 50, 0, 500);
    h_TTTo2L2Nu_light_pred_emergjetpt->Sumw2();

    TH1F *h_TTTo2L2Nu_hev_pred_emergjetEta = new TH1F("h_TTTo2L2Nu_hev_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_TTTo2L2Nu_hev_pred_emergjetEta->Sumw2();

    TH1F *h_TTTo2L2Nu_light_pred_emergjetEta = new TH1F("h_TTTo2L2Nu_light_pred_emergjetEta", "emerging jet Eta", nnbins, nbins);
    h_TTTo2L2Nu_light_pred_emergjetEta->Sumw2();

    TH1F *h_TTTo2L2Nu_hev_pred_emergjetnTrack = new TH1F("h_TTTo2L2Nu_hev_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTTo2L2Nu_hev_pred_emergjetnTrack->Sumw2();

    TH1F *h_TTTo2L2Nu_light_pred_emergjetnTrack = new TH1F("h_TTTo2L2Nu_light_pred_emergjetnTrack", "emerging jet nTrack", 50, 0, 50);
    h_TTTo2L2Nu_light_pred_emergjetnTrack->Sumw2();

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
    float TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTTo2L2Nu / (TTTo2L2Nu_totevt)) * 1000 * 2;

    TTree *T_event;
    Top_TTTo2L2Nu_2->GetObject("h2", T_event);
    T_event->SetBranchAddress("I_weight", &f_TTTo2L2Nu_weight);
    T_event->SetBranchAddress("v_fakeJethadronflavor", &v_TTTo2L2Nu_Jethadronflavor);
    T_event->SetBranchAddress("v_fakeJetPt", &v_TTTo2L2Nu_fakeJetPt);
    T_event->SetBranchAddress("v_fakealpha", &v_TTTo2L2Nu_alpha);
    T_event->SetBranchAddress("v_fakeJetEta", &v_TTTo2L2Nu_fakeJetEta);
    T_event->SetBranchAddress("v_N_Tracks", &v_TTTo2L2Nu_JetnTracks);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        for (int i = 0; i < v_TTTo2L2Nu_Jethadronflavor->size(); i++)
        {
            if ((*v_TTTo2L2Nu_Jethadronflavor)[i] == 4 || (*v_TTTo2L2Nu_Jethadronflavor)[i] == 5)
            {
                if ((*v_TTTo2L2Nu_alpha)[i] <= 0.35 &&abs((*v_TTTo2L2Nu_fakeJetEta)[i]) > 1.479)
                {
                    h_TTTo2L2Nu_hev_exp_emergjetpt->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    h_TTTo2L2Nu_hev_exp_emergjetEta->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    h_TTTo2L2Nu_hev_exp_emergjetnTrack->Fill((*v_TTTo2L2Nu_JetnTracks)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                }
                if (abs((*v_TTTo2L2Nu_fakeJetEta)[i]) > 1.479)
                {
                    float ff = Top_hev_fakerate_ntr->GetBinContent((*v_TTTo2L2Nu_JetnTracks)[i] + 1);
                    h_TTTo2L2Nu_hev_pred_emergjetpt->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight * ff);
                    h_TTTo2L2Nu_hev_pred_emergjetEta->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight * ff);
                    h_TTTo2L2Nu_hev_pred_emergjetnTrack->Fill((*v_TTTo2L2Nu_JetnTracks)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight * ff);
                }
            }
            else
            {
                if ((*v_TTTo2L2Nu_alpha)[i] <= 0.35 &&abs((*v_TTTo2L2Nu_fakeJetEta)[i]) > 1.479)
                {
                    h_TTTo2L2Nu_light_exp_emergjetpt->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    h_TTTo2L2Nu_light_exp_emergjetEta->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    h_TTTo2L2Nu_light_exp_emergjetnTrack->Fill((*v_TTTo2L2Nu_JetnTracks)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                }
                if (abs((*v_TTTo2L2Nu_fakeJetEta)[i]) > 1.479)
                {
                    float ff = Top_light_fakerate_ntr->GetBinContent((*v_TTTo2L2Nu_JetnTracks)[i] + 1);
                    h_TTTo2L2Nu_light_pred_emergjetpt->Fill((*v_TTTo2L2Nu_fakeJetPt)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight * ff);
                    h_TTTo2L2Nu_light_pred_emergjetEta->Fill((*v_TTTo2L2Nu_fakeJetEta)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight * ff);
                    h_TTTo2L2Nu_light_pred_emergjetnTrack->Fill((*v_TTTo2L2Nu_JetnTracks)[i], f_TTTo2L2Nu_weight * TTTo2L2NuWeight * ff);
                }
            }
        }
    }

    
    h_TTTo2L2Nu_hev_pred_emergjetpt->SetLineWidth(2);
    h_TTTo2L2Nu_hev_exp_emergjetpt->SetLineWidth(2);
    h_TTTo2L2Nu_light_pred_emergjetpt->SetLineWidth(2);
    h_TTTo2L2Nu_light_exp_emergjetpt->SetLineWidth(2);
    h_TTTo2L2Nu_light_pred_emergjetEta->SetLineWidth(2);
    h_TTTo2L2Nu_hev_exp_emergjetEta->SetLineWidth(2);
    h_TTTo2L2Nu_hev_pred_emergjetEta->SetLineWidth(2);
    h_TTTo2L2Nu_light_exp_emergjetEta->SetLineWidth(2);
    h_TTTo2L2Nu_hev_exp_emergjetnTrack->SetLineWidth(2);
    h_TTTo2L2Nu_hev_pred_emergjetnTrack->SetLineWidth(2);
    h_TTTo2L2Nu_light_exp_emergjetnTrack->SetLineWidth(2);
    h_TTTo2L2Nu_light_pred_emergjetnTrack->SetLineWidth(2);
    Top_hev_fakerate_ntr->SetLineWidth(2);
    Top_light_fakerate_ntr->SetLineWidth(2);

    h_TTTo2L2Nu_hev_pred_emergjetpt->SetLineColor(kRed);
    h_TTTo2L2Nu_light_pred_emergjetpt->SetLineColor(kRed);
    h_TTTo2L2Nu_light_pred_emergjetEta->SetLineColor(kRed);
    h_TTTo2L2Nu_hev_pred_emergjetEta->SetLineColor(kRed);
    h_TTTo2L2Nu_hev_pred_emergjetnTrack->SetLineColor(kRed);
    h_TTTo2L2Nu_light_pred_emergjetnTrack->SetLineColor(kRed);
    Top_hev_fakerate_ntr->SetLineColor(kRed);
    //Top_light_fakerate_ntr->Draw();
    //Top_hev_fakerate_ntr->Draw("same");

    
    auto c1 = new TCanvas("c", "BPRE");
    c1->Divide(3, 2);
    c1->cd(1);
    h_TTTo2L2Nu_hev_pred_emergjetpt->SetTitle("heavy");
    h_TTTo2L2Nu_hev_pred_emergjetpt->GetXaxis()->SetTitle("Jet PT");
    h_TTTo2L2Nu_hev_pred_emergjetpt->Draw("hist  e");
    h_TTTo2L2Nu_hev_exp_emergjetpt->Draw("hist same e");
    TLegend *l0 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(h_TTTo2L2Nu_hev_pred_emergjetpt, "Predict", "l");
    l0->AddEntry(h_TTTo2L2Nu_hev_exp_emergjetpt, "expect", "l");
    l0->Draw();
    c1->cd(4);
    h_TTTo2L2Nu_light_exp_emergjetpt->SetTitle("light");
    h_TTTo2L2Nu_light_exp_emergjetpt->GetXaxis()->SetTitle("Jet PT");
    h_TTTo2L2Nu_light_exp_emergjetpt->Draw("hist  e");
    h_TTTo2L2Nu_light_pred_emergjetpt->Draw("hist same e");
    TLegend *l1 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_TTTo2L2Nu_light_pred_emergjetpt, "Predict", "l");
    l1->AddEntry(h_TTTo2L2Nu_light_exp_emergjetpt, "expect", "l");
    l1->Draw();

    c1->cd(2);
    h_TTTo2L2Nu_hev_pred_emergjetnTrack->SetTitle("heavy");
    h_TTTo2L2Nu_hev_exp_emergjetnTrack->SetTitle("heavy");
    h_TTTo2L2Nu_hev_pred_emergjetnTrack->GetXaxis()->SetTitle("Trackmultiplicity");
    h_TTTo2L2Nu_hev_exp_emergjetnTrack->GetXaxis()->SetTitle("Trackmultiplicity");
    h_TTTo2L2Nu_hev_exp_emergjetnTrack->Draw("hist  e");
    h_TTTo2L2Nu_hev_pred_emergjetnTrack->Draw("hist same e");
    TLegend *l2 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(h_TTTo2L2Nu_hev_pred_emergjetnTrack, "Predict", "l");
    l2->AddEntry(h_TTTo2L2Nu_hev_exp_emergjetnTrack, "expect", "l");
    l2->Draw();
    c1->cd(5);
    h_TTTo2L2Nu_light_exp_emergjetnTrack->SetTitle("light");
    h_TTTo2L2Nu_light_exp_emergjetnTrack->GetXaxis()->SetTitle("Trackmultiplicity");
    h_TTTo2L2Nu_light_exp_emergjetnTrack->Draw("hist  e");
    h_TTTo2L2Nu_light_pred_emergjetnTrack->Draw("hist same e");

    TLegend *l3 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.04);
    l3->AddEntry(h_TTTo2L2Nu_light_pred_emergjetnTrack, "Predict", "l");
    l3->AddEntry(h_TTTo2L2Nu_light_exp_emergjetnTrack, "expect", "l");
    l3->Draw();

    c1->cd(3);
    h_TTTo2L2Nu_hev_pred_emergjetEta->SetTitle("heavy");
    h_TTTo2L2Nu_hev_exp_emergjetEta->SetTitle("heavy");
    h_TTTo2L2Nu_hev_pred_emergjetEta->GetXaxis()->SetTitle("Jet(#eta)");
    h_TTTo2L2Nu_hev_exp_emergjetEta->GetXaxis()->SetTitle("Jet(#eta)");
    h_TTTo2L2Nu_hev_exp_emergjetEta->Draw("hist  e");
    h_TTTo2L2Nu_hev_pred_emergjetEta->Draw("hist same e");
    TLegend *l4 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.04);
    l4->AddEntry(h_TTTo2L2Nu_hev_pred_emergjetEta, "Predict", "l");
    l4->AddEntry(h_TTTo2L2Nu_hev_exp_emergjetEta, "expect", "l");
    l4->Draw();

    c1->cd(6);
    h_TTTo2L2Nu_light_exp_emergjetEta->SetTitle("light");
    h_TTTo2L2Nu_light_exp_emergjetEta->GetXaxis()->SetTitle("Jet(#eta)");
    h_TTTo2L2Nu_light_exp_emergjetEta->Draw("hist  e");
    h_TTTo2L2Nu_light_pred_emergjetEta->Draw("hist same e");

    TLegend *l5 = new TLegend(0.6, 0.65, 0.80, 0.85);
    l5->SetBorderSize(0);
    l5->SetTextSize(0.04);
    l5->AddEntry(h_TTTo2L2Nu_light_pred_emergjetEta, "Predict", "l");
    l5->AddEntry(h_TTTo2L2Nu_light_exp_emergjetEta, "expect", "l");
    l5->Draw();
    gStyle->SetOptStat(0);
    // h_ht0_hev_exp_emergjetpt->Draw("hist same");
    
}
