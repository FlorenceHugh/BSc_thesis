#include "create_histogram.hpp"

/** Initilize an empty array to store the frequency*/
CreateHistogram::CreateHistogram(int len) {
    freqDistribution = new int[len];
    for (int i = 0; i < len; i++) {
        *(freqDistribution+i) = 0;
    }
}

/** Destructor to delete dynamically allocated memory */
CreateHistogram::~CreateHistogram() {
    delete[] freqDistribution;
}

/** This function gets the frequency of each k-mer by reading the file containg
    the k-mers and their counts, real or predicted. */
void CreateHistogram::kMerFrequency(string &filename) {

    string line;
    int nr;
    std::ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
    }

    while (getline(file, line)) {
        if (line[0] == '>') {
            nr = stoi(line.substr(1));
            if (frequency.count(nr)) {
                frequency[nr]++;
            } else {
                frequency[nr] = 1;
            }
        }
    }
    file.close();
}

/**  */
void CreateHistogram::printHisto(ostream &os, int bins[], int len) {
    int index;
    for (const auto & [key, value] : frequency) {
        index = 0;
        while (index < len-1 && key > bins[index]) {
            index ++;
        }
        *(freqDistribution+index) += value;
    }

    for (int i = 0; i < len; i++)
        os << *(freqDistribution+i) << endl;
}
