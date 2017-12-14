#include <TFile.h>
#include <TH1F.h>
#include <TPad.h>

void plot_w_ferm_noferm(){
gStyle->SetOptStat(0);

Float_t q2_arr[3]={0.2,0.5,0.7};

TCanvas *c = new TCanvas ("c","c",0,0,650,550);
c->Divide(2,2);

TLine *line_l2 = new TLine(0.,0.5,1.,0.5);
line_l2->SetLineColor(47);
line_l2->SetLineWidth(2);
line_l2->Draw();

TGaxis::SetMaxDigits(3);
TH1F *h1, *h2,*h3;
TH1F *h5, *h6,*h4;

TFile *MyFile2 = new TFile("out_hist_test_norad_noferm_q2_04_05.root","READ");
TFile *MyFile3 = new TFile("out_hist_test_norad_ferm_wini_q2_04_05.root","READ");
TFile *MyFile4 = new TFile("out_hist_test_norad_ferm_wfin_q2_04_05_narr.root","READ");
//TFile *MyFile5 = new TFile("out_hist_test_norad_noferm_wflat.root","READ");
TFile *MyFile5 = new TFile("out_hist_test_norad_ferm_winiflat_q2_04_05.root","READ");
TFile *MyFile6 = new TFile("out_hist_test_norad_ferm_wfinflat_q2_04_05_narr.root","READ");
TFile *MyFile7 = new TFile("out_hist_test_norad_ferm_wfinflat_q2_04_05.root","READ");

//TFile *MyFile2 = new TFile("out_hist_test_norad_ferm.root","READ");
//TFile *MyFile3 = new TFile("out_hist_test_norad_noferm_noflux2.root","READ");
//TFile *MyFile4 = new TFile("out_hist_test_norad_ferm_Ebeam_dep_noflux2.root","READ");

//for (Short_t i=0;i<3;i++){


MyFile2->cd();
gDirectory->GetObject("W",h1);


MyFile3->cd();
gDirectory->GetObject("W",h2);

MyFile4->cd();
gDirectory->GetObject("W",h3);
//gDirectory->GetObject("h_fermi_bonn",h6);

MyFile5->cd();
gDirectory->GetObject("W",h4);

MyFile6->cd();
gDirectory->GetObject("W",h5);

MyFile7->cd();
gDirectory->GetObject("W",h6);

c->cd(1);
c->cd(1)->SetBottomMargin(0.18);
///c->cd(1)->SetLeftMargin(0.12);

h1->SetLineColor(kGreen+2);
h1->SetLineWidth(2);

h1->GetYaxis()->SetLabelSize(0.065);
h1->GetXaxis()->SetLabelSize(0.065);
h1->GetXaxis()->SetTitle("W (GeV)");
//h1->GetYaxis()->SetTitle("#varepsilon_{T}");

h1->GetXaxis()->SetTitleOffset(1.1);
h1->GetXaxis()->SetTitleSize(0.075);
h1->GetYaxis()->SetTitleSize(0.075);

h1->GetXaxis()->SetNdivisions(508);
h1->GetYaxis()->SetNdivisions(5);
h1->SetTitle(" ");
//h1->Scale(1./h1->GetMaximum());
h1->Rebin(2);

h1->GetYaxis()->SetRangeUser(0.,1.15*h1->GetMaximum());
h1->Draw();

//h2->SetLineColor(kBlue);
h2->SetLineWidth(2);
//h4->Scale(1./h4->GetMaximum());
h2->Rebin(2);
//h2->Scale(1./20.);
h2->Draw("same");

//h3->SetLineColor(kBlack);
//h3->SetLineWidth(2);
//h4->Scale(1./h4->GetMaximum());
//h3->Rebin(2);
//h3->Draw("same");


leg = new TLegend(0.3,0.2,0.78,0.5);
leg->AddEntry(h1,"free proton","l");
leg->AddEntry(h2,"#splitline{moving proton, }{ smeared }","l");
leg->SetTextSize(0.06);
leg->Draw("same");

   
   
c->cd(3);
c->cd(3)->SetBottomMargin(0.18);
//c->cd(3)->SetLeftMargin(0.12);


h4->GetYaxis()->SetLabelSize(0.065);
h4->GetXaxis()->SetLabelSize(0.065);
h4->GetXaxis()->SetTitle("W (GeV)");
//h4->GetYaxis()->SetTitle("#varepsilon_{T}");

h4->GetXaxis()->SetTitleOffset(1.1);
h4->GetXaxis()->SetTitleSize(0.075);
h4->GetYaxis()->SetTitleSize(0.075);

h4->GetXaxis()->SetNdivisions(508);
h4->GetYaxis()->SetNdivisions(5);
h4->SetTitle(" ");
h4->SetLineWidth(2);
h4->Rebin(2);
h4->SetMinimum(50000.);
h4->SetMaximum(110000.);

h4->Draw();

h5->SetLineWidth(2);
h5->Rebin(2);
h5->SetLineColor(kPink-8);
h5->Draw("same");

leg = new TLegend(0.25,0.25,0.8,0.5);
leg->SetHeader("1.3 GeV < W_{sm} < 1.9 GeV");
leg->AddEntry(h4,"W_{sm}","l");
leg->AddEntry(h5,"W_{true}","l");
leg->SetTextSize(0.0575);
leg->Draw("same");

c->cd(2);
c->cd(2)->SetBottomMargin(0.18);
//c->cd(2)->SetLeftMargin(0.12);
h1->Draw();

h3->SetLineWidth(2);
h3->SetLineColor(kPink-8);
h3->Rebin(2);
h3->Draw("same][");

leg = new TLegend(0.3,0.2,0.78,0.5);
leg->AddEntry(h1,"free proton","l");
leg->AddEntry(h3,"#splitline{moving proton, }{ non-smeared }","l");
leg->SetTextSize(0.06);
leg->Draw("same");


c->cd(4);
c->cd(4)->SetBottomMargin(0.18);
//c->cd(4)->SetLeftMargin(0.12);

h4->Draw();

h6->SetLineWidth(2);
h6->Rebin(2);
h6->SetLineColor(kPink-8);
h6->Draw("same][");
leg = new TLegend(0.25,0.25,0.8,0.5);
leg->SetHeader("1.25 GeV < W_{sm} < 2 GeV");
leg->AddEntry(h4,"W_{sm}","l");
leg->AddEntry(h6,"W_{true}","l");
leg->SetTextSize(0.0575);
leg->Draw("same");



c->cd();
newpad = new TPad("newpad","a transparent pad",0.,0.,1.,1.);
 newpad->SetFillStyle(4000);
 newpad->Draw();
  newpad->cd();
 TLatex tex, tex2, tex3,tex4;

 tex.SetTextSize(0.035);
 tex.DrawLatex(0.25,0.95,"(a)");
 
 tex2.SetTextSize(0.035);
 tex2.DrawLatex(0.75,0.95,"(b)");
 
  tex3.SetTextSize(0.035);
 tex3.DrawLatex(0.25,0.45,"(c)");
 
   tex4.SetTextSize(0.035);
 tex4.DrawLatex(0.75,0.45,"(d)");
};

