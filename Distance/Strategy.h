#ifndef STRATEGY_H_
#define STRATEGY_H_

#include <map>
#include <string>
#include "EuclideanDistanceCalculator.h"
#include "EuclideanDistanceCalculator.h"
#include "CanberraDistanceCalculator.h"
#include "ChebyshevDistanceCalculator.h"
#include "MinkowskiDistanceCalculator.h"
#include "TaxicabGeometryCalculator.h"

#define DEFAULT_DISTANCE "AUC"

using namespace std;

// define the Strategy class
class Strategy
{
private:
	// define a constant map to store the different distance calculator objects
	const map<string, Calculator *const> m_strategysMap = {{"AUC", new EuclideanDistanceCalculator()},
														   {"MAN", new TaxicabGeometryCalculator()},
														   {"CHB", new ChebyshevDistanceCalculator()},
														   {"CAN", new CanberraDistanceCalculator()},
														   {"MIN", new MinkowskiDistanceCalculator()}};

	// declare a pointer to a Calculator object to store the current strategy
	Calculator *m_strategyUse;

public:
	// constructor for the Strategy class
	Strategy();

	// constructor that takes the name of the strategy to use
	Strategy(string name);

	// destructor for the Strategy class
	~Strategy();

	// method to set the strategy to use based on its name
	void setStrategy(string name);

	// overload the () operator to calculate the distance between two vectors using the current strategy
	double operator()(const vector<double> &vec1, const vector<double> &vec2);
};

#endif /* STRATEGY_H_ */
