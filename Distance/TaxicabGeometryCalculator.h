#ifndef TAXICAB_GEOMETRY_CALCULATOR_H_
#define TAXICAB_GEOMETRY_CALCULATOR_H_

#include "Calculator.h"

using namespace std;

// Class for calculating different distance measures between two vectors
class TaxicabGeometryCalculator : public Calculator
{
private:
protected:
    // a method to calculate the distance between two elements of the vectors
    void distanceMethod(double &ret, double arg1, double arg2);

public:
    // calculate the Taxicab geometry distance between two vectors
    double calculate(const vector<double> &vec1, const vector<double> &vec2) override;
};

#endif /* TAXICAB_GEOMETRY_CALCULATOR_H_ */
