#ifndef CREATE_HISTOGRAM_HPP
#define CREATE_HISTOGRAM_HPP

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class CreateHistogram {
private:
    map<int, int> frequency;
    int *freqDistribution;
public:
    CreateHistogram(int len);
    ~CreateHistogram();
    void kMerFrequency(string &filename);
    void printHisto(ostream &os, int bins[], int len);
};

#endif // CREATE_HISTOGRAM_HPP
