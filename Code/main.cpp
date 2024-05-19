#include <iostream>
#include "index_and_canonical.hpp"
#include "s_mer_counter.hpp"
#include "predict_k_mer.hpp"
#include "error_check.hpp"
#include "simulate_error.hpp"
#include "create_histogram.hpp"

using namespace std;

struct Arguments {
    int s = 10;
    int k = 20;
    string input_file;
};

bool parseArguments(int argc, char* argv[], Arguments& args) {

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file> [--s <value>] [--k <value>]" << endl;
        return false;
    }

    args.input_file = argv[1];

    for (int i = 2; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--s") {
            if (i+1 < argc) {
                args.s = stoi(argv[i+1]);
                i++;
            } else {
                cerr << "--s option requires an integer argument" << endl;
                return false;
            }
        } else if (arg == "--k") {
            if (i+1 < argc) {
                args.k = stoi(argv[i+1]);
                i++;
            } else {
                cerr << "--k option requires an integer argument" << endl;
                return false;
            }
        }
    }

    return true;
}

void mainFunction(const Arguments& args) {

    char mut_rate = args.input_file[args.input_file.length() - 5] - '0'; 
    string filename = "../Data/mut_" + to_string(mut_rate) + "p/" + args.input_file;
    std::ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    SMerCounter smc(args.s);
    smc.readFile(filename, args.s);

    PredictKMer pred(smc);
    std::ofstream minFile("../Data/pred_min.fa");
    pred.predMin(args.s, args.k);
    pred.savekMersMin(minFile);

    file.close();
}

int main(int argc, char* argv[]) {
    Arguments args;
    // check if arguments are correct
    if (!parseArguments(argc, argv, args)) {
        return 1;
    }

    mainFunction(args);
    return 0;
}