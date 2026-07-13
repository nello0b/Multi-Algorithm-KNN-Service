#ifndef CHEBYSHEV_DISTANCE_CALCULATOR_H_
#define CHEBYSHEV_DISTANCE_CALCULATOR_H_

#include "Calculator.h"

using namespace std;

// Class for calculating the Chebyshev distance measure between two vectors
class ChebyshevDistanceCalculator : public Calculator
{
private:
protected:
    // Method for calculating the Chebyshev distance between two elements
    void distanceMethod(double &ret, double arg1, double arg2);

public:
    // Method for calculating the Chebyshev distance between two vectors
    double calculate(const vector<double> &vec1, const vector<double> &vec2) override;
};

#endif /* CHEBYSHEV_DISTANCE_CALCULATOR_H_ */