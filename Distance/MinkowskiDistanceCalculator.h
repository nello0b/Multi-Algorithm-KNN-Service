#ifndef MINKOWSHI_DISTANCE_CALCULATOR_H_
#define MINKOWSHI_DISTANCE_CALCULATOR_H_

#include "Calculator.h"

// include the vector class from the standard library
using namespace std;

// Class for calculating different distance measures between two vectors
class MinkowskiDistanceCalculator : public Calculator
{
private:
    // declare a static variable to store the value of the exponent
    static double lambada;

protected:
    // a method to calculate the distance between two elements of the vectors
    void distanceMethod(double &ret, double arg1, double arg2);

public:
    // calculate the Minkowski distance between two vectors
    double calculate(const vector<double> &vec1, const vector<double> &vec2) override;
};

#endif /* MINKOWSHI_DISTANCE_CALCULATOR_H_ */
