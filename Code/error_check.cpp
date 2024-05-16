#include "error_check.hpp"

/** Initilize arrays to store the mean and absolute error and corresponding total error
    arrays and nrOfkMers used for calculating the mean */
ErrorCheck::ErrorCheck(const SMerCounter &sMerCounter, int nrOfBins) : PredictKMer(sMerCounter) {
    sMerVector = sMerCounter.getSMerVector();
    meanAbs = new double[nrOfBins];
    meanSqrt = new double[nrOfBins];
    totalErrorAbs = new unsigned long long int[nrOfBins];
    totalErrorSqrt = new unsigned long long int[nrOfBins];
    nrOfkMers = new unsigned long long int[nrOfBins];
    for (int i = 0; i < nrOfBins; i++) {
        *(totalErrorSqrt + i) = 0;
        *(totalErrorAbs + i) = 0;
        *(meanAbs + i) = 0.0;
        *(meanSqrt + i) = 0.0;
        *(nrOfkMers + i) = 0;
    }
}

/** Destructor to delete all the dynamically allocated memory */
ErrorCheck::~ErrorCheck() {
    delete[] meanAbs;
    delete[] meanSqrt;
    delete[] totalErrorAbs;
    delete[] totalErrorSqrt;
    delete[] nrOfkMers;
}

/** Get the mean absolute error */
double* ErrorCheck::getMeanAbs() {
    return meanAbs;
}

/** Get the mean square error */
double* ErrorCheck::getMeanSqrt() {
    return meanSqrt;
}

/** Calculates the mean absolute/square error for simulated data. This streams the
    input file containin the real counts and compares the real abundance with the
    predicted obtained from minimum function. When total has been counted, the mean
    will be calculated. */
void ErrorCheck::meanErrorSim(string &filename, int s, int k, int nrOfBins) {
    string kMer, sMer, canonicalSMer;
    // int nrOfKmers = 0;
    int index, realCount, predMinimum;

    std::ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
    }

    while (getline(file, kMer)) {
        if (kMer[0] == '>') {
            realCount = stoi(kMer.substr(1)); //converts string to int from pos 1
            *(nrOfkMers + realCount - 1) += 1;
        } else {
            predMinimum = minimum(kMer, s, k);
            *(totalErrorSqrt + realCount - 1) += (realCount-predMinimum)*(realCount-predMinimum);
            *(totalErrorAbs + realCount - 1) += abs(realCount-predMinimum);
        }
    }
    file.close();

    for (int i = 0; i < nrOfBins; i++) {
        if (*(nrOfkMers + i) != 0) {
            *(meanAbs+i) = *(totalErrorAbs + i)/double(*(nrOfkMers + i));
            *(meanSqrt+i) = *(totalErrorSqrt + i)/double(*(nrOfkMers + i));

           // cout << i+1 << ": kMersCount: " << *(nrOfkMers + i) << ", meanAbs: " << *(meanAbs+i) << ", double: " << double(*(nrOfkMers + i)) << endl;
        }
    }
}

/** Calculates the mean absolute/square error for biological data. This function uses
    bins to store intervals of k-mer frequencies. This streams the input file containin
    the real counts and compares the real abundance with the predicted obtained from
    minimum function. When total has been counted, the mean for each bin will be calculated. */
void ErrorCheck::meanErrorBio(string &filename, int s, int k, int bins[], int nrOfBins) {
    string kMer, sMer, canonicalSMer;
    int index, binPos, realCount, predMinimum;

    std::ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
    }

    while (getline(file, kMer)) {
        if (kMer[0] == '>') {
            realCount = stoi(kMer.substr(1)); //converts string to int from pos 1

            // loop to add count in correct bin
            binPos = 0;
            while (binPos < nrOfBins-1 && realCount > bins[binPos]) {
                binPos ++;
            }
            *(nrOfkMers + binPos) += 1;

        } else {
            predMinimum = minimum(kMer, s, k);
            *(totalErrorSqrt + binPos) += (realCount-predMinimum)*(realCount-predMinimum);
            *(totalErrorAbs + binPos) += abs(realCount-predMinimum);
        }
    }
    file.close();

    for (int i = 0; i < nrOfBins; i++) {
        if (*(nrOfkMers + i) != 0) {
            *(meanAbs+i) = *(totalErrorAbs + i)/double(*(nrOfkMers + i));
            *(meanSqrt+i) = *(totalErrorSqrt + i)/double(*(nrOfkMers + i));

            //cout << "kMersCount: " << *(nrOfkMers + i) << ", totAbs: " << *(totalErrorAbs + i) << ", totSqrt: " << *(totalErrorSqrt + i) << endl;
        }
    }
}
