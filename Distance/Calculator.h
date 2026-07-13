#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <cmath>
#include <vector>

using namespace std;

class Calculator
{
protected:
    // Abstract method for calculating the distance between two elements
    virtual void distanceMethod(double &ret, double arg1, double arg2) = 0;

    // Helper function for computing the sum of a given function applied to corresponding elements of two vectors
    double sum(const vector<double> &vec1, const vector<double> &vec2);

public:
    // Abstract method for calculating the distance between two vectors
    virtual double calculate(const vector<double> &vec1, const vector<double> &vec2) = 0;

    // Abstract destructor for the Calculator class
    virtual ~Calculator() = 0;
};

#endif /* CALCULATOR_H_ */