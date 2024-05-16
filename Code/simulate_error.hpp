#ifndef SIMULATE_ERROR_HPP
#define SIMULATE_ERROR_HPP

#include <iostream>
#include "error_check.hpp"
#include "s_mer_counter.hpp"
using namespace std;

void simulateErrorSimData(int nrOfBins, int minK, int maxK, int mut_rate, string filename);
void simulateErrorBioData(int nrOfBins, int bins[], int minK, int maxK, string bioData, string filename);

#endif // SIMULATE_ERROR_HPP
