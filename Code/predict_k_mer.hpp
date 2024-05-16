#ifndef PREDICT_K_MER_HPP
#define PREDICT_K_MER_HPP

#include <iostream>
#include "Index_and_canonical.hpp"
#include "s_mer_counter.hpp"
using namespace std;

class PredictKMer : public IndexAndCanonical{
private:
    unordered_map<string, int> kMersMin;
    int* sMerVector;
    vector<string> sequences;

public:
    PredictKMer(const SMerCounter &sMerCounter);
    void savekMersMin(ostream &os);
    void predMin(int s, int k);
    int minimum(string kMer, int s, int k);
};

#endif // PREDICT_K_MER_HPP
