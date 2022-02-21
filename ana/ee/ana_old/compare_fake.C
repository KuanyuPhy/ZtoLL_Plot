#include "TFile.h"
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./lib/Cross_section.h"
#include "setNCUStyle.C"
using namespace std;
void compare_fake()
{

    Int_t KON = TColor::GetFreeColorIndex();
    TColor *KON_color = new TColor(KON, 0.06, 0.15, 0.25);
    Int_t HIWAMOEGI = TColor::GetFreeColorIndex();
    TColor *HIWAMOEGI_color = new TColor(HIWAMOEGI, 0.56, 0.71, 0.29);

    Int_t KARACHA = TColor::GetFreeColorIndex();
    TColor *KARACHA_color = new TColor(KARACHA, 0.71, 0.44, 0.34);

    Int_t JINZAMOMI = TColor::GetFreeColorIndex();
    TColor *JINZAMOMI_color = new TColor(JINZAMOMI, 0.92, 0.478, 0.46);

    Int_t BENIUKON = TColor::GetFreeColorIndex();
    TColor *BENIUKON_color = new TColor(BENIUKON, 0.913, 0.545, 0.16);

    Int_t SHIRACHA = TColor::GetFreeColorIndex();
    TColor *SHIRACHA_color = new TColor(SHIRACHA, 0.73, 0.623, 0.47);

    Int_t KARIYASU = TColor::GetFreeColorIndex();
    TColor *KARIYASU_color = new TColor(KARIYASU, 0.913, 0.803, 0.298);

    Int_t MIZUASAGI = TColor::GetFreeColorIndex();
    TColor *MIZUASAGI_color = new TColor(MIZUASAGI, 0.4, 0.729, 0.718);

    Int_t MATSUBA = TColor::GetFreeColorIndex();
    TColor *MATSUBA_color = new TColor(MATSUBA, 0.259, 0.376, 0.176);

    setNCUStyle(true);

    TFile *DYHT = new TFile("./../../root_file/BgEstimation/DYHT_fakerate.root");
    TFile *Top = new TFile("./../../root_file/BgEstimation/Top_fakerate.root");

    TH1F *DY_fakeRate = ((TH1F *)DYHT->Get("h_ht0_emergjetpt_fakeRate"));
    TH1F *Top_fakeRate = ((TH1F *)Top->Get("h_tW_top_emergjetpt_fakeRate"));
    TH1F *DY_barr_hev_fakeRate = ((TH1F *)DYHT->Get("h_ht0_barr_hev_emergjetpt_fakeRate"));
    TH1F *Top_barr_hev_fakeRate = ((TH1F *)Top->Get("h_TTZToLLNuNu_barr_hev_emergjetpt_fakeRate"));
    TH1F *DY_barr_light_fakeRate = ((TH1F *)DYHT->Get("h_ht0_barr_light_emergjetpt_fakeRate"));
    TH1F *Top_barr_light_fakeRate = ((TH1F *)Top->Get("h_TTZToLLNuNu_barr_light_emergjetpt_fakeRate"));
    TH1F *DY_Jeteta = ((TH1F *)DYHT->Get("h_ht0_emergjetEta"));
    TH1F *Top_Jeteta = ((TH1F *)Top->Get("h_tW_top_emergjetEta"));
    TH1F *DY_hev_Jeteta_cutalpha = ((TH1F *)DYHT->Get("h_ht0_hev_emergjetEta_cutalpha"));
    TH1F *Top_hev_Jeteta_cutalpha = ((TH1F *)Top->Get("h_TTTo2L2Nu_hev_emergjetEta_cutalpha"));
    TH1F *DY_light_Jeteta_cutalpha = ((TH1F *)DYHT->Get("h_ht0_light_emergjetEta_cutalpha"));
    TH1F *Top_light_Jeteta_cutalpha = ((TH1F *)Top->Get("h_TTTo2L2Nu_light_emergjetEta_cutalpha"));

    Top_fakeRate->SetLineColor(kRed);
    Top_Jeteta->SetLineColor(kRed);
    Top_hev_Jeteta_cutalpha->SetLineColor(kRed);
    Top_barr_hev_fakeRate->SetLineColor(kRed);
    DY_light_Jeteta_cutalpha->SetLineColor(KARIYASU);
    DY_barr_light_fakeRate->SetLineColor(KARIYASU);
    Top_light_Jeteta_cutalpha->SetLineColor(MATSUBA);
    Top_barr_light_fakeRate->SetLineColor(MATSUBA);

    Top_fakeRate->SetLineWidth(2);
    Top_Jeteta->SetLineWidth(2);
    Top_hev_Jeteta_cutalpha->SetLineWidth(2);
    DY_hev_Jeteta_cutalpha->SetLineWidth(2);
    DY_light_Jeteta_cutalpha->SetLineWidth(2);
    Top_light_Jeteta_cutalpha->SetLineWidth(2);
    DY_barr_hev_fakeRate->SetLineWidth(2);
    Top_barr_hev_fakeRate->SetLineWidth(2);
    DY_barr_light_fakeRate->SetLineWidth(2);
    Top_barr_light_fakeRate->SetLineWidth(2);

    Top_light_Jeteta_cutalpha->GetYaxis()->SetTitle("N Jets/Normalized");
    Top_light_Jeteta_cutalpha->GetXaxis()->SetTitle("Jet Eta");
    Top_fakeRate->GetXaxis()->SetTitle("Jet PT");
    Top_hev_Jeteta_cutalpha->GetXaxis()->SetTitle("Jet Eta");

    // Top_light_Jeteta_cutalpha->DrawNormalized("hist&&E");
    // Top_hev_Jeteta_cutalpha->DrawNormalized("hist&&same&&E");
    // DY_hev_Jeteta_cutalpha->DrawNormalized("hist&&same&&E");
    // DY_light_Jeteta_cutalpha->DrawNormalized("hist&&same&&E");

    Top_barr_hev_fakeRate->GetXaxis()->SetTitle("fake rate");
    Top_barr_light_fakeRate->GetXaxis()->SetTitle("fake rate");
    DY_barr_light_fakeRate->GetXaxis()->SetTitle("fake rate");
    // Top_barr_hev_fakeRate->Draw("hist&&E");
    // DY_barr_hev_fakeRate->Draw("hist&&E&&same");
    DY_barr_light_fakeRate->Draw("hist&&E");
    Top_barr_light_fakeRate->Draw("hist&&E&&same");

    TLegend *l3 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.04);
    // l3->AddEntry(Top_hev_Jeteta_cutalpha, "Top process heavy Jet", "l");
    //  l3->AddEntry(Top_light_Jeteta_cutalpha, "Top process light Jet", "l");
    // l3->AddEntry(DY_hev_Jeteta_cutalpha, "Drell-Yan process heavy Jet", "l");
    //  l3->AddEntry(DY_light_Jeteta_cutalpha, "Drell-Yan process light Jet", "l");
    l3->AddEntry(Top_barr_light_fakeRate, "Top barrel fakeRate(light)", "l");
    l3->AddEntry(DY_barr_light_fakeRate, "Drell-Yan barrel fakeRate(light)", "l");
    l3->Draw();
}
