#include <TFile.h>
#include <TTree.h>
class mathfunction
{
    public:

        TFile *T_File;
        TTree *T_OBject;

        UInt_t total_n;
        Float_t sumx, sumy, sumxy, sumxsq, sumysq; 
        TBranch *h_I_nJets;
        TBranch *h_f_alphamin;
        TBranch *h_f_Met;
        float get_correlation()
        {
            
        }
    
}

