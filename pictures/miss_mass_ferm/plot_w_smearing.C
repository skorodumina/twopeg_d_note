void plot_w_smearing(){
gStyle->SetOptStat(0);
gStyle->SetOptFit(1);

TCanvas *c = new TCanvas ("c","c",0,0,650,400);

TH1 *h1;
TFile *MyFile1 = new TFile("out_hist_w_smear_1_5.root","READ");
TGaxis::SetMaxDigits(3);
MyFile1->cd();
gDirectory->GetObject("h_e_beam_eff",h1);

c->SetBottomMargin(0.18);
c->SetLeftMargin(0.12);

h1->SetLineWidth(3);
//h1->GetYaxis()->SetRangeUser(0.65,1.025);
h1->GetYaxis()->SetLabelSize(0.065);
h1->GetXaxis()->SetLabelSize(0.065);
h1->GetXaxis()->SetTitle("W_{true} (GeV)");
//h1->GetYaxis()->SetTitle("#varepsilon_{T}");

h1->GetXaxis()->SetTitleOffset(1.1);
h1->GetXaxis()->SetTitleSize(0.07);
h1->GetYaxis()->SetTitleSize(0.05);

h1->GetXaxis()->SetNdivisions(508);
h1->GetYaxis()->SetNdivisions(5);
h1->SetTitle(" ");




h1->Draw();

h1->Fit("gaus","","",1.47,1.53);

TLine *line_l = new TLine(1.5,0,1.5,1.05*h1->GetMaximum());
line_l->SetLineColor(kBlack);
//line_l->SetLineStyle(2);
line_l->SetLineWidth(2);
line_l->Draw("same"); 

TLine *line_l = new TLine(1.5+3*2.59080e-02,0,1.5+3*2.59080e-02,1.05*h1->GetMaximum());
line_l->SetLineColor(kBlack);
line_l->SetLineStyle(2);
line_l->SetLineWidth(1);
line_l->Draw("same"); 

TLine *line_l = new TLine(1.5-3*2.59080e-02,0,1.5-3*2.59080e-02,1.05*h1->GetMaximum());
line_l->SetLineColor(kBlack);
line_l->SetLineStyle(2);
line_l->SetLineWidth(1);
line_l->Draw("same"); 
};
