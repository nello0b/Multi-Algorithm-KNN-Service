#include "CanberraDistanceCalculator.h"

double CanberraDistanceCalculator::calculate(const vector<double> &vec1, const vector<double> &vec2)
{
    return sum(vec1, vec2);
}

void CanberraDistanceCalculator::distanceMethod(double &ret, double arg1, double arg2)
{
    // Calculate the difference between the two input values
    double tempNum1 = (double)abs(arg1 - arg2);
    // Calculate the sum of the absolute values of the two input values
    double tempNum2 = (double)abs(arg1) + abs(arg2);
    // If the sum of the absolute values is zero, return without updating the result
    if (tempNum2 == 0)
        return;
    // Otherwise, update the result by adding the ratio of the difference and the sum to it
    ret += (double)((double)(tempNum1)) / ((double)(tempNum2));
}