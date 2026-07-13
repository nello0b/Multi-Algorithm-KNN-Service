#include "EuclideanDistanceCalculator.h"

// Method for calculating the Euclidean distance between two vectors
double EuclideanDistanceCalculator::calculate(const vector<double> &vec1, const vector<double> &vec2)
{
    // Return the square root of the sum of the squared differences between corresponding elements of the two vectors
    return sqrt(sum(vec1, vec2));
}

// Method for calculating the Euclidean distance between two elements
void EuclideanDistanceCalculator::distanceMethod(double &ret, double arg1, double arg2)
{
    // Add the squared difference between the two elements to the result
    ret += (double)pow(arg1 - arg2, 2);
}