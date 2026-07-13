#include "Strategy.h"

// constructor for the Strategy class
Strategy::Strategy() : m_strategyUse(NULL) {}

// constructor that takes the name of the strategy to use
Strategy::Strategy(string name) : m_strategyUse(NULL)
{
	// set the strategy to use based on the name
	setStrategy(name);
}

// destructor for the Strategy class
Strategy::~Strategy()
{
	// delete the objects stored in the m_strategysMap map
	for (pair<string, Calculator *const> pair : m_strategysMap)
	{
		delete get<1>(pair);
	}
}

// method to set the strategy to use based on its name
void Strategy::setStrategy(string name)
{
	// if the strategy does not exist in the map, we set it to be Euclidean Distance as defult
	if (m_strategysMap.count(name) == 0)
	{
		m_strategyUse = m_strategysMap.at(DEFAULT_DISTANCE);
		return;
	}

	// set the strategy to use to the one with the specified name
	m_strategyUse = m_strategysMap.at(name);
}

// overload the () operator to calculate the distance between two vectors using the current strategy
double Strategy::operator()(const vector<double> &vec1, const vector<double> &vec2)
{
	// use the current strategy to calculate the distance between the two vectors
	return m_strategyUse->calculate(vec1, vec2);
}
