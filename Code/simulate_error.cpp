#include "simulate_error.hpp"

void simulateErrorSimData(int nrOfBins, int minK, int maxK, int mut_rate, string filename) {

    const int s = 10;
    double* abs;
    double* sqrt;

    // Iterate over k values from minK to maxK
    for (int k = minK; k <= maxK; k+=5) {
        // Initialize arrays for absolute and square root errors
        double absValues[6][nrOfBins];
        double sqrtValues[6][nrOfBins];

        string fileRealCount = "Data/mut_" + to_string(mut_rate) + "p/" + to_string(k) + "k_refs.fa";

        // Iterate over s values from 10 to 15
        for(int i = 0; i < 6; i++) {
            SMerCounter smc(s+i);
            smc.readFile(filename, s+i);

            ErrorCheck err(smc, nrOfBins);
            err.meanErrorSim(fileRealCount, s+i, k, nrOfBins);

            abs = err.getMeanAbs();
            sqrt = err.getMeanSqrt();

            // Store the errors for this combination of s and k
            for (int j = 0; j < nrOfBins; j++) {
                absValues[i][j] = abs[j];
                sqrtValues[i][j] = sqrt[j];
            }
        }

        // Write the errors to the CSV file
        std::ofstream os("Data/mut_" + to_string(mut_rate) + "p/abs_sqrt_error_" + to_string(k) + "k.csv");
        // header
        os << "abs10,abs11,abs12,abs13,abs14,abs15,sqrt10,sqrt11,sqrt12,sqrt13,sqrt14,sqrt15" << endl;
        for(int j = 0; j < nrOfBins; j++) {
             os << absValues[0][j] << "," << absValues[1][j] << "," << absValues[2][j] << ","
             << absValues[3][j] << "," << absValues[4][j] << "," << absValues[5][j] << ","
             << sqrtValues[0][j] << "," << sqrtValues[1][j] << "," << sqrtValues[2][j] << ","
             << sqrtValues[3][j] << "," << sqrtValues[4][j] << "," << sqrtValues[5][j] << endl;
        }
        os.close();
    }
}

void simulateErrorBioData(int nrOfBins, int bins[], int minK, int maxK, string bioData, string filename) {
    const int s = 10;
    double* abs;
    double* sqrt;

    // Iterate over k values from minK to maxK
    for (int k = minK; k <= maxK; k+=5) {
        // Initialize arrays for absolute and square root errors
        double absValues[6][nrOfBins];
        double sqrtValues[6][nrOfBins];
        string fileRealCount = "Data/" + bioData + "/" + to_string(k) + "k_" + bioData + "_counts.fa";

        // Iterate over s values from 10 to 15
        for(int i = 0; i < 6; i++) {
            SMerCounter smc(s+i);
            smc.readFile(filename, s+i);

            ErrorCheck err(smc, nrOfBins);
            err.meanErrorBio(fileRealCount, s+i, k, bins, nrOfBins);

            abs = err.getMeanAbs();
            sqrt = err.getMeanSqrt();

            // Store the errors for this combination of s and k
            for (int j = 0; j < nrOfBins; j++) {
                absValues[i][j] = abs[j];
                sqrtValues[i][j] = sqrt[j];
            }
        }

        // Write the errors to the CSV file
        std::ofstream os("Data/" + bioData + "/test_abs_sqrt_error_" + to_string(k) + "k.csv");
        // header
        os << "abs10,abs11,abs12,abs13,abs14,abs15,sqrt10,sqrt11,sqrt12,sqrt13,sqrt14,sqrt15" << endl;
        for(int j = 0; j < nrOfBins; j++) {
             os << absValues[0][j] << "," << absValues[1][j] << "," << absValues[2][j] << ","
             << absValues[3][j] << "," << absValues[4][j] << "," << absValues[5][j] << ","
             << sqrtValues[0][j] << "," << sqrtValues[1][j] << "," << sqrtValues[2][j] << ","
             << sqrtValues[3][j] << "," << sqrtValues[4][j] << "," << sqrtValues[5][j] << endl;
        }
        os.close();
    }
}
