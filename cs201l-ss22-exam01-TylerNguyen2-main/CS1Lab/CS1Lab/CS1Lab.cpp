#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    string category;
    // look for categorys in input file
    double item;
    // set these categorys into items
    vector<double> dvd, music, tv;   
    // the 3 categorys that will be coxmpared

  

    ifstream inputFile("input-2.txt");    
    // opens input file and makes sure it can be opened
    if (!inputFile.is_open()) {    
        cout << "The file could not be opened." << endl;
        exit(1);
    }

    // looks for each item and adds it to the end of item element
    while (inputFile >> category >> item) {
        if (category.compare("DVD") == 0)
            dvd.push_back(item);
        else if (category.compare("TV") == 0)
            tv.push_back(item);
        else if (category.compare("MUSIC") == 0)
            music.push_back(item);
    }
    inputFile.close();   
    // close input file as all elements have been added to item
  

    ofstream outputFile("output.txt");   
    // if output file cannot be open display error
    if (!outputFile.is_open()) {    
        cout << "The file could not be opened." << endl;
        exit(1);
    }

    outputFile << "\tTotal\tMedian\tMean\n";

    // DvD category and if error occurs in math, output nan
    outputFile << "DVD\t";
    outputFile << calculateTotal(dvd) << "\t";    
    try {
        outputFile << calculateMedian(dvd) << "\t";   
    }
    catch (...) {
        outputFile << "nan\t";
    }
    try {
        outputFile << calculateMean(dvd) << endl;    
    }
    catch (...) {
        outputFile << "nan" << endl;
    }

    // tv category and if error occurs in math, output nan
    outputFile << "TV\t";
    outputFile << calculateTotal(tv) << "\t";    
    try {
        outputFile << calculateMedian(tv) << "\t";    
    }
    catch (...) {
        outputFile << "nan\t";
    }
    try {
        outputFile << calculateMean(tv) << endl;    
    }
    catch (...) {
        outputFile << "nan" << endl;
    }

    // music category and if error occurs in math, output nan
    outputFile << "MUSIC\t";
    outputFile << calculateTotal(music) << "\t";   
    try {
        outputFile << calculateMedian(music) << "\t";    
    }
    catch (...) {
        outputFile << "nan\t";
    }
    try {
        outputFile << calculateMean(music) << endl;    
    }
    catch (...) {
        outputFile << "nan" << endl;
    }
    outputFile.close();    

    return 0;
}