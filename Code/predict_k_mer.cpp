#include "predict_k_mer.hpp"


/** Constructor saves the s-mer vector and sequence from the SMerCounter class */
PredictKMer::PredictKMer(const SMerCounter &sMerCounter) : IndexAndCanonical() {
    sMerVector = sMerCounter.getSMerVector();
    sequences = sMerCounter.getSequences();
}

/** Function that saves the k-mer abundances in FASTA format*/
void PredictKMer::savekMersMin(ostream &os) {
    for (const auto & [key, value] : kMersMin)
        os << ">" << value << endl << key << endl;
}

/** This function iterates over the sequences in the file to extract all k-mers
    , each k-mer is then sent to the minimum function to get its abundance*/
void PredictKMer::predMin(int s, int k) {
    string canonicalkMer;

    for (const string& seq : sequences) {
        int nrOfKMers = seq.length()-k+1;
        for (int i = 0; i < nrOfKMers; i++) {
            canonicalkMer = canonicalMer(seq.substr(i,k),k);
            kMersMin[canonicalkMer] = minimum(canonicalkMer, s, k);
        }
    }
}

/** This function iterates over the k-mer to get the count of all present s-mers,
    the smallest count will be returned as the predicted value for the k-mer */
int PredictKMer::minimum(string kMer, int s, int k) {
    string canonicalsMer;
    int index;
    int minCount = INT_MAX;

    for (int j = 0; j < (k-s+1); j++) {
        canonicalsMer = canonicalMer(kMer.substr(j, s),s);
        index = seqIndex(canonicalsMer);
        minCount = min(minCount, *(sMerVector + index));
    }
    return minCount;
}
