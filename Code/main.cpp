#include <iostream>
#include "Index_and_canonical.hpp"
#include "s_mer_counter.hpp"
#include "predict_k_mer.hpp"
#include "error_check.hpp"
#include "simulate_error.hpp"
#include "create_histogram.hpp"

using namespace std;

int main() {
//    const int s = 15;
//    const int k = 25;
//
////    string filename = "Data/ecoli/ecoli_20_genomes.fa";
////    string fileRealCount = "Data/ecoli/20k_ecoli_counts.fa";
//
////    string filename = "Data/chrY/chrY.fa";
////    string fileRealCount = "Data/chrY/30k_15s_min_pred.fa";
//
//    string filename = "Data/mut_1p/refs_mut_1p.fa";
//    string fileRealCount = "Data/mut_1p/25k_refs.fa";

////    string filename = "Dara/test.fa";
//
//    SMerCounter smc(s);
//    smc.readFile(filename, s);
//
////    int nrOfBins = 20;
////    int bins[] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100};
//    double* abs;
//    ErrorCheck err(smc, 50);
//    err.meanErrorSim(fileRealCount, s, k, 50);
//
//    abs = err.getMeanAbs();
//
//
////    // Write the errors to the CSV file
////    std::ofstream os("Data/ecoli/test_abs_sqrt_error_50k.csv");
////    // header
////    os << "abs15" << endl;
//    for(int i = 0; i < 50; i++) {
//         cout << *(abs+i) << endl;
//    }
////    os.close();
//
//

// When running the histogram for predicted data, one must also run the predicted function to
// receive the predicted values for the histogram. No need when running the real count since
// jellyfish has a file for us
//--- Histogram ----
//    const int s = 15;
//    const int k = 25;

//    string filename = "Data/ecoli/ecoli_20_genomes.fa";
//    string fileRealCount = "Data/ecoli/20k_ecoli_counts.fa";

//    string filename = "Data/chrY/chrY.fa";
//    string fileRealCount = "Data/chrY/30k_15s_min_pred.fa";
//
//    string filename = "Data/mut_1p/refs_mut_1p.fa";
//    string fileRealCount = "Data/mut_1p/25k_refs.fa";

//    SMerCounter smc(s);
//    smc.readFile(filename, s);
//
//    PredictKMer pred(smc);
//    string minFile = "Data/mut_1p/25k_15s_min_pred.fa"; //save predictions in FASTA
//    std::ofstream os2(minFile);
//    pred.predMin(s, k);
//    pred.savekMersMin(os2);
//
//    std::ofstream os("Data/mut_1p/25k_real_hist.csv");
//    int nrOfBins = 50;
//    int bins[nrOfBins]; //For simulerad data
//    for (int i = 1; i < nrOfBins + 1; i++) {
//        bins[i-1] = i;
//    }
//    int nrOfBins = 25; //chrY
//    int bins[] = {1,10,20,30,40,50,60,70,80,90,100,150,200,250,300,400,500,600,700,800,900,1000,1500,2000}; //chrY

//    int nrOfBins = 20;
//    int bins[] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100};
//    CreateHistogram ch(nrOfBins);
//    ch.kMerFrequency(fileRealCount); // change to minFile when checking predicted hist
//    ch.printHisto(os, bins, nrOfBins);

//--- errorckeck sim data ----
//    int nrOfBins = 50;
//    ErrorCheck err(smc, nrOfBins);
//    err.meanErrorSim(fileRealCount, s, k, nrOfBins);
//
//
//    double* meanAbs = err.getMeanAbs();
//    double* meanSqrt = err.getMeanSqrt();
//
//    for (int i = 0; i < nrOfBins; i++) {
//        cout << "nrOfBins = " << i+1 << ", Abs: " << *(meanAbs+i) << ", Sqrt: " << *(meanSqrt+i) << endl;
//    }

//---- simulate error sim data----
//    string filename = "Data/mut_5p/refs_mut_5p.fa";
//
//    int kmin = 15;
//    int kmax = 30;
//    int nrOfBins = 50;
//    int mut_rate = 5;
//    simulateErrorSimData(nrOfBins, kmin, kmax, mut_rate, filename);

//---- simulate error bio data----
//    string filename = "Data/ecoli/ecoli_20_genomes.fa";
//    int kmin = 15;
//    int kmax = 30;
//    int nrOfBins = 20;
//    int bins[] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100};
//    simulateErrorBioData(nrOfBins, bins, kmin, kmax, "ecoli", filename);


    return 0;
}
