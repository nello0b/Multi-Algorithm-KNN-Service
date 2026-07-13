#include "ChebyshevDistanceCalculator.h"

// Method for calculating the Chebyshev distance between two vectors
double ChebyshevDistanceCalculator::calculate(const vector<double> &vec1, const vector<double> &vec2)
{
    // Return the sum of the distances between corresponding elements of the two vectors
    return sum(vec1, vec2);
}

// Method for calculating the Chebyshev distance between two elements
void ChebyshevDistanceCalculator::distanceMethod(double &ret, double arg1, double arg2)
{
    // Update the result with the maximum absolute difference between the two elements
    ret = max((double)abs(arg1 - arg2), (double)ret);
}
