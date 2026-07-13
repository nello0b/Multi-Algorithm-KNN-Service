#include "MinkowskiDistanceCalculator.h"

// declare a static variable to store the value of the exponent
double MinkowskiDistanceCalculator::lambada = 2;

// calculate the Minkowski distance between two vectors
double MinkowskiDistanceCalculator::calculate(const vector<double> &vec1, const vector<double> &vec2)
{
    // Calculate the value of the exponent
    double tempNum = 1 / ((double)(lambada));

    // return the result of raising the sum of the elementwise differences between the two vectors to the power of the exponent
    return (double)pow(sum(vec1, vec2), tempNum);
}

// a method to calculate the distance between two elements of the vectors
void MinkowskiDistanceCalculator::distanceMethod(double &ret, double arg1, double arg2)
{
    // add the absolute value of the difference between the two elements raised to the power of the exponent to the result variable
    ret += pow(abs(arg1 - arg2), lambada);
}
