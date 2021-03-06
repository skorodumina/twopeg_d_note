void flux_beam_en_dep(){
gStyle->SetOptStat(0);

Float_t q2_arr[3]={0.2,0.5,0.7};

TCanvas *c = new TCanvas ("c","c",0,0,750,400);
//c->Divide(3,1);


//for (Short_t i=0;i<3;i++){

c->cd(1);
c->cd(1)->SetBottomMargin(0.15);
 TF1 *f1 = new TF1("f1",epst,1.5,8,2);
 f1->SetParameter(0,1.4);
 f1->SetParameter(1,0.25);

  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
//  f1->GetYaxis()->SetRangeUser(0.002,0.0062);
  f1->GetYaxis()->SetRangeUser(0.0045,0.01);
  
f1->GetYaxis()->SetLabelSize(0.055);
f1->GetXaxis()->SetLabelSize(0.055);
f1->GetXaxis()->SetTitle("E_{beam} (GeV)");
f1->GetYaxis()->SetTitle("#Gamma_{v} (GeV^{-3})");

f1->GetYaxis()->SetTitleOffset(0.65);
f1->GetXaxis()->SetTitleSize(0.06);
f1->GetYaxis()->SetTitleSize(0.06);

f1->GetXaxis()->SetNdivisions(508);

f1->SetTitle(" ");
//f1->GetYaxis()->SetNoExponent(1); 
 TGaxis::SetMaxDigits(3);
  f1->Draw();
  

 TF1 *f2 = new TF1("f2",epst,1.5,8,2);
 f2->SetParameter(0,1.5);
 f2->SetParameter(1,0.25);

  f2->SetLineColor(kBlue);
  f2->SetLineWidth(2);
  f2->Draw("same");
  
 TF1 *f3 = new TF1("f3",epst,1.5,8,2);
 f3->SetParameter(0,1.6);
 f3->SetParameter(1,0.25);

  f3->SetLineColor(kGreen);
  f3->SetLineWidth(2);
  f3->Draw("same");
//--------------------------------------------  
  
 TF1 *f4 = new TF1("f4",epst,1.5,8,2);
 f4->SetParameter(0,1.4);
 f4->SetParameter(1,0.3);

  f4->SetLineColor(kBlack);
  f4->SetLineWidth(2);
   f4->SetLineStyle(7); 
  f4->Draw("same");
  

 TF1 *f5 = new TF1("f5",epst,1.5,8,2);
 f5->SetParameter(0,1.5);
 f5->SetParameter(1,0.3);

  f5->SetLineColor(kBlue);
  f5->SetLineWidth(2);
  f5->SetLineStyle(7); 
  f5->Draw("same");
  
 TF1 *f6 = new TF1("f6",epst,1.5,8,2);
 f6->SetParameter(0,1.6);
 f6->SetParameter(1,0.3);

  f6->SetLineColor(kGreen);
  f6->SetLineWidth(2);
  f6->SetLineStyle(7);
  f6->Draw("same");    
  


TLine *line_l = new TLine(1,1.5,8,1);
line_l->SetLineColor(kRed);
line_l->SetLineWidth(2);
//line_l->Draw("same");

//};

TLegend *leg = new TLegend(0.48,0.19,0.67,0.35);
leg->SetHeader("Q^{2} = 0.25 GeV^{2}"); 
leg->AddEntry(f1,"W = 1.4 GeV ","l");
//leg->AddEntry(f4,"W = 1.4 GeV ","l");
//leg->AddEntry(f4," ","c");
leg->AddEntry(f2,"W = 1.5 GeV","l");
leg->AddEntry(f3,"W = 1.6 GeV","l");

leg->Draw();

TLegend *leg1 = new TLegend(0.68,0.19,0.87,0.35);
leg1->SetHeader("Q^{2} = 0.3 GeV^{2}"); 
leg1->AddEntry(f4,"W = 1.4 GeV ","l");
//leg->AddEntry(f4,"W = 1.4 GeV ","l");
//leg->AddEntry(f4," ","c");
leg1->AddEntry(f5,"W = 1.5 GeV","l");
leg1->AddEntry(f6,"W = 1.6 GeV","l");

leg1->Draw();

};


double epst(double *x, double *par) {
   double eps_t, V_flux,alph_const, M_PI;
   double nu,mp;
   alph_const = 1./137.035;
   M_PI = 3.14159265;
   mp=0.938272;
   
   nu=(par[0]*par[0]+par[1]-mp*mp)/2./mp;
   
   eps_t = 1./(1.+2*(par[1]+nu*nu)/(4*x[0]*(x[0]-nu)-par[1]));

    V_flux = alph_const/4./M_PI;
V_flux = V_flux/x[0]/x[0]/mp/mp;
V_flux = V_flux/(1.-eps_t)/par[1];
V_flux = V_flux*par[0]*(par[0]*par[0]-mp*mp);
   return V_flux;
}
