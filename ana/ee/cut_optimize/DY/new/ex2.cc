#include <iostream>

void ex2()
{
    TRandom3 rnd;
    TNtupleD *nt = new TNtupleD("nt","random data","x:y");
    for(int i=0; i<100000; i++) {
        double var[2];
        var[0] = rnd.Gaus(0.,1.);
        var[1] = rnd.Gaus(0.,1.);
        nt->Fill(var);
    }
    
    double mean_x = 0., mean_y = 0.;
    double cov_xx = 0.,cov_xy = 0.,cov_yy = 0.;
    for(int i=0; i<nt->GetEntries(); i++) {
        nt->GetEntry(i);
        double x = nt->GetArgs()[0];
        double y = nt->GetArgs()[1];
        mean_x += x;
        mean_y += y;
        cov_xx += x*x;
        cov_xy += x*y;
        cov_yy += y*y;
    }
    mean_x /= nt->GetEntries();
    mean_y /= nt->GetEntries();
    cov_xx = cov_xx/nt->GetEntries() - mean_x*mean_x;
    cov_xy = cov_xy/nt->GetEntries() - mean_x*mean_y;
    cov_yy = cov_yy/nt->GetEntries() - mean_y*mean_y;
    
    printf("Mean: (%g, %g)\n",mean_x, mean_y);
    printf("Covariance:\n%f, %f\n%f, %f\n",cov_xx, cov_xy, cov_xy, cov_yy);
}