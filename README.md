# BSc_thesis
This repository contains the source code created and two files to test run it. These are found in the Data folder. 
## Run the program
To use the minimum predictor function one can run ./pred_min.out in the terminal with desired input. Example usage:

    ./pred_min.out <input_file> [--s <value>] [--k <value>]

As for now, the input file can be either ref_mut_1p.fa or ref_mut_3p.fa. The options --s and --k are optional and have default values 10 and 20 respectively. By running this one will obtain a file named pred_min.fa, which contains the *k*-mers and their count saved in FASTA format.
