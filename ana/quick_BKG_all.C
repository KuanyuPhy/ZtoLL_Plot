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
void quick_BKG_all()
{
    // SetColor
    Int_t KIKYO = TColor::GetFreeColorIndex();
    TColor *KIKYO_color = new TColor(KIKYO, 0.42, 0.30, 0.61);
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

    TFile *Top_quark_bg = new TFile("./../../root_file/Ztoee/Top_All.root");
    TFile *diboson_bg = new TFile("./../../root_file/Ztoee/Diboson_All.root");
    TFile *DYHT_bg = new TFile("./../../root_file/Ztoee/DYHT_All.root");
    TFile *Triboson_bg = new TFile("./../../root_file/Ztoee/Triboson_All.root");

    TH1F *DYHT_Met = ((TH1F *)DYHT_bg->Get("h_ht0_met"));
    TH1F *DYHT_Alphamin = ((TH1F *)DYHT_bg->Get("h_ht0_aphmin"));

    TH1F *Top_Met = ((TH1F *)Top_quark_bg->Get("Top_quark_met"));
    TH1F *Top_Alphamin = ((TH1F *)Top_quark_bg->Get("Top_quark_aphmin"));

    TH1F *ggZZ_Met = ((TH1F *)diboson_bg->Get("diboson_gg_ZZ_2e2mu_met"));
    TH1F *ggZZ_Alphamin = ((TH1F *)diboson_bg->Get("diboson_gg_ZZ_2e2mu_aphmin"));

    TH1F *ggWW_Met = ((TH1F *)diboson_bg->Get("diboson_gg_WW_2L2Nu_met"));
    TH1F *ggWW_Alphamin = ((TH1F *)diboson_bg->Get("diboson_gg_WW_2L2Nu_aphmin"));
    TH1F *qqWW_Met = ((TH1F *)diboson_bg->Get("diboson_qq_WW_2L2Nu_met"));
    TH1F *qqWW_Alphamin = ((TH1F *)diboson_bg->Get("diboson_qq_WW_2L2Nu_aphmin"));
    TH1F *qqWZ_Met = ((TH1F *)diboson_bg->Get("diboson_qq_WZ_2L2Q_met"));
    TH1F *qqWZ_Alphamin = ((TH1F *)diboson_bg->Get("diboson_qq_WZ_2L2Q_aphmin"));
    TH1F *qqZZ_Met = ((TH1F *)diboson_bg->Get("diboson_qq_ZZ_2L2Nu_met"));
    TH1F *qqZZ_Alphamin = ((TH1F *)diboson_bg->Get("diboson_qq_ZZ_2L2Nu_aphmin"));

    TH1F *WWZ_Met = ((TH1F *)Triboson_bg->Get("Triboson_WWZ_met"));
    TH1F *WWZ_Alphamin = ((TH1F *)Triboson_bg->Get("Triboson_WWZ_aphmin"));
    TH1F *WZZ_Met = ((TH1F *)Triboson_bg->Get("Triboson_WZZ_met"));
    TH1F *WZZ_Alphamin = ((TH1F *)Triboson_bg->Get("Triboson_WZZ_aphmin"));
    TH1F *ZZZ_Met = ((TH1F *)Triboson_bg->Get("Triboson_ZZZ_met"));
    TH1F *ZZZ_Alphamin = ((TH1F *)Triboson_bg->Get("Triboson_ZZZ_aphmin"));

    auto c1 = new TCanvas("c", "BPRE");
    // auto c2 = new TCanvas("c", "BPRE");

    // ggZZ_Met->Add(qqWW_Met);
    // ggZZ_Met->Add(qqWZ_Met);
    // ggZZ_Met->Add(qqZZ_Met);
    cout << "ggZZ_Met = " << ggZZ_Met->Integral() << endl;
    // ggZZ_Met->Add(qqZZ_Met);

    c1->Divide(3, 4);
    c1->cd(1);
    DYHT_Alphamin->SetTitle("DYHT");
    DYHT_Met->SetTitle("DYHT");
    DYHT_Alphamin->GetYaxis()->SetTitle("Event/Normalized");
    DYHT_Met->GetYaxis()->SetTitle("Event/Normalized");
    DYHT_Met->GetXaxis()->SetTitle("Met");
    DYHT_Alphamin->SetFillColor(JINZAMOMI);
    DYHT_Met->SetFillColor(JINZAMOMI);
    // DYHT_Alphamin->DrawNormalized("hist");
    DYHT_Met->Draw("hist");
    // cout << "DYHT_Alphamin = " << DYHT_Met->Integral() << endl;
    c1->cd(2);
    Top_Alphamin->SetTitle("Top");
    Top_Met->SetTitle("Top");
    Top_Alphamin->SetFillColor(KIKYO);
    Top_Met->SetFillColor(KIKYO);
    // Top_Alphamin->DrawNormalized("hist&&same");
    Top_Met->Draw("hist&&same");
    c1->cd(3);
    ggZZ_Met->SetTitle("ggZZ");
    ggZZ_Alphamin->SetFillColor(KON);
    ggZZ_Met->SetFillColor(KON);
    // ggZZ_Alphamin->DrawNormalized("hist&&same");
    ggZZ_Met->Draw("hist&&same");
    c1->cd(4);
    ggWW_Alphamin->SetFillColor(HIWAMOEGI);
    qqWW_Met->SetFillColor(HIWAMOEGI);
    //ggWW_Alphamin->DrawNormalized("hist&&same");
    qqWW_Met->Draw("hist&&same");
    c1->cd(5);
    ggWW_Alphamin->SetFillColor(KARACHA);
    ggWW_Met->SetFillColor(KARACHA);
    // qqWW_Alphamin->DrawNormalized("hist&&same");
    ggWW_Met->Draw("hist&&same");
    c1->cd(6);
    qqWZ_Alphamin->SetFillColor(BENIUKON);
    qqWZ_Met->SetFillColor(BENIUKON);
    // qqWZ_Alphamin->DrawNormalized("hist&&same");
    qqWZ_Met->Draw("hist&&same");
    c1->cd(7);
    // qqZZ_Alphamin->SetFillColor(SHIRACHA);
    qqZZ_Met->SetFillColor(SHIRACHA);
    //// qqZZ_Alphamin->DrawNormalized("hist&&same");
    qqZZ_Met->Draw("hist&&same");
    c1->cd(8);
    WWZ_Alphamin->SetFillColor(KARIYASU);
    WWZ_Met->SetFillColor(KARIYASU);
    // WWZ_Alphamin->DrawNormalized("hist&&same");
    WWZ_Met->Draw("hist&&same");
    cout << "WWZ_Met = " << WWZ_Met->Integral() << endl;
    c1->cd(9);
    WZZ_Alphamin->SetFillColor(MIZUASAGI);
    WZZ_Met->SetFillColor(MIZUASAGI);
    // WZZ_Alphamin->DrawNormalized("hist&&same");
    WZZ_Met->Draw("hist&&same");
    cout << "WZZ_Alphamin = " << WZZ_Met->Integral() << endl;
    c1->cd(10);
    ZZZ_Alphamin->SetFillColor(MATSUBA);
    ZZZ_Met->SetFillColor(MATSUBA);
    ZZZ_Met->Draw("hist&&same");
    //  ZZZ_Alphamin->DrawNormalized("hist&&same");
    //cout << "ZZZ_Alphamin = " << ZZZ_Met->Integral() << endl;
    c1->SaveAs("2016MetBG.pdf");
    // c2->cd();
    //THStack *hs = new THStack("hs", "");
    //hs->Add(Top_Met);
    //hs->Add(DYHT_Met);
    //hs->Add(ggZZ_Met);
    //hs->Add(ggWW_Met);
    //hs->Add(qqWW_Met);
    //hs->Add(qqWZ_Met);
    //hs->Add(qqZZ_Met);
    //hs->Add(WWZ_Met);
    //hs->Add(ZZZ_Met);
    //hs->Add(ZZZ_Met);
    //hs->Draw("hist ");

    /*
    TLegend *l1 = new TLegend(0.20, 0.55, 0.70, 0.8);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(DYHT_Alphamin, "Drell-Yan", "f");
    l1->AddEntry(Top_Alphamin, "Top quark", "f");
    l1->AddEntry(ggZZ_Alphamin, "gg #rightarrow ZZ", "f");
    l1->AddEntry(ggWW_Alphamin, "gg #rightarrow WW", "f");
    l1->AddEntry(qqWW_Alphamin, "qq #rightarrow WW", "f");
    l1->AddEntry(qqWZ_Alphamin, "qq #rightarrow WZ", "f");
    l1->AddEntry(qqZZ_Alphamin, "qq #rightarrow ZZ", "f");
    l1->AddEntry(WWZ_Alphamin, "WWZ", "f");
    l1->AddEntry(WZZ_Alphamin, "WZZ", "f");
    l1->AddEntry(ZZZ_Alphamin, "ZZZ", "f");
    l1->Draw();
    */

}