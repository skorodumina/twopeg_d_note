void plots2(){
gStyle->SetOptStat(0);

Float_t q2_arr[3]={0.2,0.5,0.7};

TCanvas *c = new TCanvas ("c","c",0,0,900,265);
c->Divide(3,1);

TH1 *h1, *h2, *h3;
TH1 *h4, *h5, *h6;

TFile *MyFile1 = new TFile("out_rad_fin.root","READ");
//TFile *MyFile2 = new TFile("out_norad_21jul.root","READ");
TFile *MyFile2 = new TFile("out_hist_test_rad_2nd_meth.root","READ");


//for (Short_t i=0;i<3;i++){
MyFile1->cd();
gDirectory->GetObject("h_pim_miss",h1);
gDirectory->GetObject("h_fermi_bonn",h2);
gDirectory->GetObject("W",h3);

MyFile2->cd();
gDirectory->GetObject("h_pim_miss",h4);
gDirectory->GetObject("h_fermi_bonn",h5);
gDirectory->GetObject("W",h6);




c->cd(1);
c->cd(1)->SetBottomMargin(0.18);
c->cd(1)->SetLeftMargin(0.12);

h1->SetLineColor(kOrange+7);
h1->SetLineWidth(2);
//h1->GetYaxis()->SetRangeUser(0.65,1.025);
h1->GetYaxis()->SetLabelSize(0.065);
h1->GetXaxis()->SetLabelSize(0.065);
h1->GetXaxis()->SetTitle("M^{2}_{[#pi^{-}]} (GeV^{2})");
//h1->GetYaxis()->SetTitle("#varepsilon_{T}");

h1->GetXaxis()->SetTitleOffset(1.1);
h1->GetXaxis()->SetTitleSize(0.075);
h1->GetYaxis()->SetTitleSize(0.075);

h1->GetXaxis()->SetNdivisions(508);
h1->GetYaxis()->SetNdivisions(5);
h1->SetTitle(" ");
h1->Rebin();
h1->Scale(1./h1->GetMaximum());
h1->SetMinimum(0.);
h1->Draw();

//h4->SetLineColor(kMagenta);
h4->SetLineWidth(2);

h4->Scale(1./h4->GetMaximum());
h4->Draw("same");
h1->Draw("same");

TLine *line_l = new TLine(0.019479785,0,0.019479785,1.0);
line_l->SetLineColor(kBlack);
line_l->SetLineStyle(2);
line_l->Draw("same"); 


c->cd(2);
c->cd(2)->SetBottomMargin(0.18);
c->cd(2)->SetLeftMargin(0.12);



h2->SetLineColor(kOrange+7);
h2->SetLineWidth(2);
h2->GetXaxis()->SetRangeUser(-0.05,0.6);
h2->GetYaxis()->SetLabelSize(0.065);
h2->GetXaxis()->SetLabelSize(0.065);
h2->GetXaxis()->SetTitle("P_{[0]} (GeV)");
//h2->GetYaxis()->SetTitle("#varepsilon_{T}");

h2->GetXaxis()->SetTitleOffset(1.1);
h2->GetXaxis()->SetTitleSize(0.075);
h2->GetYaxis()->SetTitleSize(0.075);

h2->GetXaxis()->SetNdivisions(508);
h2->GetYaxis()->SetNdivisions(5);
h2->SetTitle(" ");
h2->Scale(1./h2->GetMaximum());
h2->SetMinimum(0);
h2->Draw();

//h5->SetLineColor(kMagenta);
h5->SetLineWidth(2);
h5->Scale(1./h5->GetMaximum());
h5->Draw("same");
h2->Draw("same");


c->cd(3);
c->cd(3)->SetBottomMargin(0.18);
c->cd(3)->SetLeftMargin(0.12);

h3->SetLineColor(kOrange+7);
h3->SetLineWidth(2);

h3->GetYaxis()->SetLabelSize(0.065);
h3->GetXaxis()->SetLabelSize(0.065);
h3->GetXaxis()->SetTitle("W (GeV)");
//h3->GetYaxis()->SetTitle("#varepsilon_{T}");

h3->GetXaxis()->SetTitleOffset(1.1);
h3->GetXaxis()->SetTitleSize(0.075);
h3->GetYaxis()->SetTitleSize(0.075);

h3->GetXaxis()->SetNdivisions(508);
h3->GetYaxis()->SetNdivisions(5);
h3->SetTitle(" ");
//h3->Scale(1./h3->GetMaximum());
h3->Rebin();
h3->GetXaxis()->SetRangeUser(1.3,1.9);
h3->GetYaxis()->SetRangeUser(0.,2000);
h3->Draw();

//h6->SetLineColor(kMagenta);
h6->SetLineWidth(2);
h6->Rebin();
//h5->Scale(1./h5->GetMaximum());
//h6->Scale(1./5.);
h6->Draw("same");

h3->Draw("same");





};

