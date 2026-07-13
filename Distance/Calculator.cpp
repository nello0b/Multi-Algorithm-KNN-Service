#include <cmath>
#include "Calculator.h"

// This method calculates the sum of two vectors
double Calculator::sum(const vector<double> &vec1, const vector<double> &vec2)
{
    // Initialize the result variable to 0
    double result = 0;

    // Get the minimum size of the two vectors
    int minSize = min(vec1.size(), vec2.size());

    // Loop through the minimum number of elements in the vectors
    for (int i = 0; i < minSize; i++)
    {
        // Calculate the distance between the elements in the vectors and add it to the result
        distanceMethod(result, vec1.at(i), vec2.at(i));
    }

    // Return the result
    return result;
}

// This is the destructor for the Calculator class
Calculator::~Calculator() {}