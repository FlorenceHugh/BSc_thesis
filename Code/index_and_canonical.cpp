#include <random>
#include "index_and_canonical.hpp"


// Compute the index to add the sequence to the right position in vector
int IndexAndCanonical::seqIndex(const string &seq) {

    int index = 0;
    for (char c : seq) {
        // Convert nucleotide character to binary representation
        switch (c) {
            case 'A':
                index = (index << 2) | 0b00;
                break;
            case 'C':
                index = (index << 2) | 0b01;
                break;
            case 'G':
                index = (index << 2) | 0b10;
                break;
            case 'T':
                index = (index << 2) | 0b11;
                break;
            default:
                // Handle invalid characters
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<int> dist(1, 100);
                int p = dist(gen);
                if (p <= 25)
                    index = (index << 2) | 0b00;
                else if (p > 25 && p <= 50)
                    index = (index << 2) | 0b01;
                else if (p > 50 && p <= 75)
                    index = (index << 2) | 0b10;
                else
                    index = (index << 2) | 0b11;
                break;
        }
    }
    return index;
}

char IndexAndCanonical::revNuc(char c) {
    switch (c) {
        case 'A':
            return 'T';
        case 'T':
            return 'A';
        case 'C':
            return 'G';
        case 'G':
            return 'C';
        default:
            return 'N'; // Return 'N' for unknown characters
    }
}

string IndexAndCanonical::canonicalMer(const string &mer, int len) {
    string revComplement;
    for (int i = len - 1; i >= 0; i--) {
        revComplement += revNuc(mer[i]);
    }
    if (revComplement.compare(mer) < 0)
        return revComplement;
    return mer;
}
