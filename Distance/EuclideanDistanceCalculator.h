#ifndef EUCLIDEAN_DISTANCE_CALCULATOR_H_
#define EUCLIDEAN_DISTANCE_CALCULATOR_H_

#include "Calculator.h"

using namespace std;

// Class for calculating the Euclidean distance measure between two vectors
class EuclideanDistanceCalculator : public Calculator
{
private:
protected:
    // Method for calculating the Euclidean distance between two elements
    void distanceMethod(double &ret, double arg1, double arg2);

public:
    // Method for calculating the Euclidean distance between two vectors
    double calculate(const vector<double> &vec1, const vector<double> &vec2) override;
};

#endif /* EUCLIDEAN_DISTANCE_CALCULATOR_H_ */