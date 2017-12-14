void kin_lim(){



TCanvas *c = new TCanvas ("c","c",0,0,750,400);


c->cd(1);
c->cd(1)->SetBottomMargin(0.15);
 TF1 *f1 = new TF1("f1",q2_max,1.25,2.2,1);
 f1->SetParameter(0,2.);


  f1->SetLineColor(kBlack);
  f1->SetLineWidth(2);
  f1->GetYaxis()->SetRangeUser(0.,3.);
   f1->SetMinimum(0.);
   
f1->GetYaxis()->SetLabelSize(0.055);
f1->GetXaxis()->SetLabelSize(0.055);
f1->GetXaxis()->SetTitle("W (GeV)");
f1->GetYaxis()->SetTitle("Q^{2} (GeV^{2})");


f1->GetYaxis()->SetTitleOffset(0.6);
f1->GetXaxis()->SetTitleSize(0.06);
f1->GetYaxis()->SetTitleSize(0.065);

f1->GetXaxis()->SetNdivisions(509);
f1->SetTitle(" ");
 
  f1->Draw();
  
 TF1 *f2 = new TF1("f2",q2_max,1.25,2.2,1);
 f2->SetParameter(0,1.7);
   f2->SetLineColor(kBlue);
  f2->SetLineWidth(2);
    f2->SetLineStyle(7);
 f2->Draw("same");
 
 TF1 *f3 = new TF1("f3",q2_max,1.25,2.2,1);
 f3->SetParameter(0,2.3);  
   f3->SetLineColor(kMagenta+1);
  f3->SetLineWidth(2);
     f3->SetLineStyle(7);
 f3->Draw("same");



TLegend *leg = new TLegend(0.67,0.7,0.9,0.9);


leg->AddEntry(f1,"E_{beam} = 2 GeV","l");
leg->AddEntry(f2,"E_{beam} = 1.75 GeV","l");
leg->AddEntry(f3,"E_{beam} = 2.25 GeV","l");
leg->Draw();



};

double q2_max(double *x, double *par) {
   double q2max;
   double mp;
   
   mp=0.938272;
   
   
   q2max= 2*par[0]*(2*par[0]*mp - x[0]*x[0] +mp*mp)/(mp+2*par[0]);
         
   return q2max;
}
