#ifndef KNN_H_
#define KNN_H_

#include <vector>
#include "InfoVector.h"
#include "../Distance/Strategy.h"

using namespace std;

// Class for implementing a k-nearest neighbor algorithm
class KNN
{
    // Private member variable for storing a vector of InfoVector objects
    vector<InfoVector> m_vectors;

    // Private member variable for storing a Strategy object for calculating distances between vectors
    Strategy m_strategy;

    // Private method for calculating the distances from a given vector to all vectors in m_vectors
    const vector<tuple<double, InfoVector>> distancesFrom(const vector<double> vec);

    // Private method for finding the k closest vectors to a given vector, based on a list of distances
    const vector<tuple<double, InfoVector>> getKClosestTo(int k, const vector<tuple<double, InfoVector>> distances);

    // Private method for finding the most common name among a list of vectors
    string mostCommonName(const vector<tuple<double, InfoVector>> distances);

public:
	KNN();
    // Constructor for the KNN class
    // Takes a vector of InfoVector objects and a name of a distance strategy as input parameters
    KNN(vector<InfoVector> vectors, string name);

    // Constructor for the KNN class
    // Takes a vector of InfoVector objects
    KNN(vector<InfoVector> vectors);

	void setVectors(vector<InfoVector> vectors){
		m_vectors = vectors;
	}

    // Method for setting the distance strategy used by the KNN class
    void setStrategy(string name);

    // Overloaded () operator for calling the KNN class with a vector and a k value
    // Returns the most common name among the k closest vectors to the input vector
    string operator()(const vector<double> vec, int k);

};

#endif /* KNN_H_ */