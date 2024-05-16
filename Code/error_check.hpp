#ifndef ERROR_CHECK_HPP
#define ERROR_CHECK_HPP

#include <iostream>
#include "predict_k_mer.hpp"
#include "s_mer_counter.hpp"
using namespace std;

class ErrorCheck : public PredictKMer{
private:
    int* sMerVector;
    double* meanAbs;
    double* meanSqrt;
    unsigned long long int* totalErrorAbs;
    unsigned long long int* totalErrorSqrt;
    unsigned long long int* nrOfkMers;

public:
    ErrorCheck(const SMerCounter &sMerCounter, int nrOfBins);
    ~ErrorCheck();
    double* getMeanAbs();
    double* getMeanSqrt();
    double meanSquareError(string &filename, int s, int k);
    void meanErrorSim(string &filename, int s, int k, int nrOfBins);
    void meanErrorBio(string &filename, int s, int k, int bins[], int nrOfBins);
};

#endif // ERROR_CHECK_HPP
