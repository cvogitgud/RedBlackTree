//-----------------------------------------------------------------------------
// Christopher Vo, cvo5
// 2022 Winter CSE 101 PA 7
// Order.cpp
// Client file for Dictionary.cpp (Dictionary ADT)
// Reads lines from input file, each line formatted to be a single (unique)
// string, and insert those strings as keys into a Dictionary. The corresponding
// values will be the line number in the input file where the string was read.
// 
// Prints out an in-order string representation of the Dictionary (alphabetical
// order), and another string representation, this time in pre-order.
//-----------------------------------------------------------------------------
#include<iostream>
#include <fstream>
#include "Dictionary.h"

using namespace std;

int main(int argc, char* argv[]) {

    ifstream in;
    ofstream out;
    string line;
    int lineCount;

    // check command line for correct number of arguments
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return(EXIT_FAILURE);
    }

    // open files for reading and writing 
    in.open(argv[1]);
    if (!in.is_open()) {
        cerr << "Unable to open file " << argv[1] << " for reading" << endl;
        return(EXIT_FAILURE);
    }

    out.open(argv[2]);
    if (!out.is_open()) {
        cerr << "Unable to open file " << argv[2] << " for writing" << endl;
        return(EXIT_FAILURE);
    }

    // line reading and processing (populate Dictionary)
    Dictionary D;
    lineCount = 0;
    while (getline(in, line)) {
        lineCount++;
        D.setValue(line, lineCount);
    }

    out << D << endl;
    out << D.pre_string() << endl;

    in.close();
    out.close();

}