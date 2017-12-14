void kin_lim2(){



TCanvas *c = new TCanvas ("c","c",0,0,750,400);


c->cd(1);
c->cd(1)->SetBottomMargin(0.15);
 TF1 *f1 = new TF1("f1",q2_max,1.25,2.2,2);
 f1->SetParameter(0,2.);
f1->SetParameter(1,180.);

  f1->SetLineColor(kBlack);
  f1->SetLineWidth(3);
  f1->GetYaxis()->SetRangeUser(0.,2.5);
   f1->SetMinimum(0.);
   
f1->GetYaxis()->SetLabelSize(0.055);
f1->GetXaxis()->SetLabelSize(0.055);
f1->GetXaxis()->SetTitle("W (GeV)");
f1->GetYaxis()->SetTitle("Q^{2} (GeV^{2})");


f1->GetYaxis()->SetTitleOffset(0.6);
f1->GetXaxis()->SetTitleSize(0.06);
f1->GetYaxis()->SetTitleSize(0.065);

f1->GetXaxis()->SetNdivisions(509);
f1->SetTitle("E_{beam} = 2 GeV");
 
  f1->Draw();
  
 TF1 *f2 = new TF1("f2",q2_max,1.25,2.2,2);
 f2->SetParameter(0,2.);
f2->SetParameter(1,20.);

  f2->SetLineColor(kBlue+1);
  f2->SetLineWidth(3);
 f2->SetLineStyle(9);

f2->Draw("same");


 TF1 *f3 = new TF1("f3",q2_max,1.25,2.2,2);
 f3->SetParameter(0,2.);
f3->SetParameter(1,50.);

  f3->SetLineColor(kMagenta+3);
  f3->SetLineWidth(3);
 f3->SetLineStyle(9);

f3->Draw("same");



TF1 *f4= new TF1("f4",q2_lim,1.25,2.2,2);
 f4->SetParameter(0,2.);
f4->SetParameter(1,0.46);

  f4->SetLineColor(kOrange+10);
  f4->SetLineWidth(3);
 f4->SetLineStyle(2);
f4->Draw("same");



TLegend *leg = new TLegend(0.6,0.55,0.9,0.9);


leg->AddEntry(f1,"Kinematical limit","l");
leg->AddEntry(f2,"#theta_{e'}^{min} = 20 deg","l");
leg->AddEntry(f3,"#theta_{e'}^{max} = 50 deg","l");
leg->AddEntry(f4,"E_{e'}^{min} = 0.46 GeV","l");
leg->SetTextSize(0.055);
leg->Draw();



};

double q2_max(double *x, double *par) {
   double q2max;
   double mp;
   
   mp=0.938272;
   th_e = par[1]*3.141593/180.;
   
   
   q2max= 2*par[0]*sin(th_e/2.)*sin(th_e/2.)*(2*par[0]*mp - x[0]*x[0] +mp*mp)/(mp+2*par[0]*sin(th_e/2.)*sin(th_e/2.));
         
   return q2max;
}


double q2_lim(double *x, double *par) {
   double q2max;
   double mp;
   
   mp=0.938272;
  
   
   
   q2max= mp*mp+2*mp*(par[0]-par[1])-x[0]*x[0];
         
   return q2max;
}



