#ifndef INDEX_AND_CANONICAL_HPP
#define INDEX_AND_CANONICAL_HPP

#include <iostream>
using namespace std;

class IndexAndCanonical {
public:
    int seqIndex(const string &seq);
    char revNuc(char c);
    string canonicalMer(const string &mer, int len);
};

#endif // INDEX_AND_CANONICAL_HPP
