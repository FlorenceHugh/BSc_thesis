#include "s_mer_counter.hpp"
#include <chrono> //for timing the program
using namespace std::chrono;

/** Initilize a vector of input size s and sets it to 0 at all positions */
SMerCounter::SMerCounter(int s) : IndexAndCanonical() {
    vectSize = pow(4,s);
    sMerVector = new int[vectSize];
    for (int i = 0; i < vectSize; i++) {
        *(sMerVector+i) = 0;
    }
}

/** Destructor to deletet all created pointer arrays*/
SMerCounter::~SMerCounter() {
    delete[] sMerVector;
}

/** Function to get the s-mer vector */
int* SMerCounter::getSMerVector() const {
    return sMerVector;
}

/** Function to get the sequence */
vector<string> SMerCounter::getSequences() const {
    return sequences;
}

/** This function first transforms all letters in input sequence to uppercase.
    It will then save this sequence in a vector for further usage. Then it iterates
    over the sequence to extract all s-mers and add a count to the correct index,
    this with help of the helper functions canonicalMer() ans seqIndex() */
void SMerCounter::processSeq(string &seq, int s) {
    string sMer, canonicalSMer;
    int nrOfSMers = seq.length()-s+1;
    int index = 0;
    transform(seq.begin(), seq.end(), seq.begin(), ::toupper);
    sequences.push_back(seq);

    for (int i = 0; i < nrOfSMers; i++) {
        sMer = seq.substr(i, s);
        canonicalSMer = canonicalMer(sMer, s);
        index = seqIndex(canonicalSMer);
        *(sMerVector + index) += 1;
    }
}

/** This function streams the input file and picks out each sequence,
    these are then sent to the processSeq() function */
void SMerCounter::readFile(string &filename, int s) {

    string seq;
    string line;
    std::ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    while (getline(file, line)) {
        if (line[0] == '>') {
            if (!seq.empty()) {
                processSeq(seq, s);
                seq = "";
            }
        } else {
            // Remove both '\r' and '\n' characters
            line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            seq += line;
        }
    }
    file.close();
    processSeq(seq, s);
}
