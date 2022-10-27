#include "Header.h"
#include <vector>
using namespace std;

double calculateTotal(vector<double> category) {
    double total = 0;
    for (int i = 0; i < category.size(); i++)
        // for every item in the category, add the total 
        total += category[i];
    return total;
}


vector<double> sort(vector<double> values) {
    int i, j, size = values.size();
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (values[j] > values[j + 1]) {
                double temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
    return values;
}

double calculateMedian(vector<double> category) {
    double median = 0;
    int size = category.size();
    if (size == 0)
        throw "Empty Vector";

   
    vector<double> sorted = sort(category);
   // with the vector sorted if size is uneven pick the middle number
    if (size % 2 == 1) {
        median = sorted[size / 2];
    }
    // else pick the 2 numbers in the middle and divide by 2
    else {
        median = (sorted[size / 2] + sorted[(size / 2) - 1]) / 2.0;
    }
    return median;
}


double calculateMean(vector<double> category) {
    int size = category.size();
 
    if (size == 0)
        throw "Empty Vector";

   // use the total amount divided by its size
    return calculateTotal(category) / (double)size;
}