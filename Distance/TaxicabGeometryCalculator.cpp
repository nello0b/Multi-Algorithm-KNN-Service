#include "TaxicabGeometryCalculator.h"

// calculate the Taxicab geometry distance between two vectors
double TaxicabGeometryCalculator::calculate(const vector<double> &vec1, const vector<double> &vec2)
{
    // return the sum of the elementwise differences between the two vectors
    return sum(vec1, vec2);
}

// a method to calculate the distance between two elements of the vectors
void TaxicabGeometryCalculator::distanceMethod(double &ret, double arg1, double arg2)
{
    // add the absolute value of the difference between the two elements to the result variable
    ret += (double)abs(arg1 - arg2);
}
