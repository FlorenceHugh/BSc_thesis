#include <iostream>
#include "index_and_canonical.hpp"
#include "s_mer_counter.hpp"
#include "predict_k_mer.hpp"
#include "error_check.hpp"
#include "simulate_error.hpp"
#include "create_histogram.hpp"

using namespace std;

int main() {

// When running the histogram for predicted data, one must also run the predicted function to
// receive the predicted values for the histogram. No need when running the real count since
// jellyfish has a file for us
//--- Create Histogram ----
   const int s = 10;
   const int k = 25;

//    // uncomment the file to be run 
//    string filename = "Data/ecoli/ecoli_20_genomes.fa";
//    string fileRealCount = "Data/ecoli/20k_ecoli_counts.fa";
//
//    string filename = "Data/chrY/chrY.fa";
//    string fileRealCount = "Data/chrY/30k_chrY_counts.fa";
//
   string filename = "../Data/mut_1p/refs_mut_1p.fa"; // in mut_-p, change to the mutation rate of interest
   string fileRealCount = "../Data/mut_1p/25k_refs.fa"; // change mutation rate and the k value to be analysed
   std::ofstream os("../Data/hist.csv");

   SMerCounter smc(s);
   smc.readFile(filename, s);

   //--- for predicted data ---
   PredictKMer pred(smc);
   string minFile = "../Data/min_pred.fa"; //save predictions in FASTA
   std::ofstream os2(minFile);
   pred.predMin(s, k);
   pred.savekMersMin(os2);
   //--------------------------

   //--- for simulated data ---
   int nrOfBins = 50;
   int bins[nrOfBins]; //For simulerad data
   for (int i = 1; i < nrOfBins + 1; i++) {
       bins[i-1] = i;
   }
   //--------------------------

//    //--- for biological data ---
//    int nrOfBins = 20;
//    int bins[] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100};
//    //--------------------------

   CreateHistogram ch(nrOfBins);
   ch.kMerFrequency(minFile); // change to "minFile" when checking predicted hist, else use the "fileRealCount" file
   ch.printHisto(os, bins, nrOfBins);

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
