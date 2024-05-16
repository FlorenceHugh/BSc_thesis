#ifndef S_MER_COUNTER_HPP
#define S_MER_COUNTER_HPP

#include <iostream>
#include <bits/stdc++.h>
#include "Index_and_canonical.hpp"
using namespace std;

class SMerCounter : public IndexAndCanonical {
private:
    int vectSize;
    int* sMerVector;
    vector<string> sequences;

public:
    SMerCounter(int s);
    ~SMerCounter();
    void printSMerVector();
    int* getSMerVector() const;
    vector<string> getSequences() const;
    void processSeq(string &seq, int s);
    void readFile(string &filename, int s);
};

#endif // S_MER_COUNTER_HPP
