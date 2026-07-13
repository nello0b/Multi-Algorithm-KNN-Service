#include "KNN.h"
#include "TupleComparator.h"
#include <queue>
#include <map>

using namespace std;

#define DEFAULT_DISTANCE "AUC"

KNN::KNN() : m_strategy(DEFAULT_DISTANCE)
{
}
// A constructor for the KNN class
// Takes a vector of InfoVector objects and a name of a distance strategy as input parameters
KNN::KNN(vector<InfoVector> vectors, string name) : m_vectors(vectors), m_strategy(name) {}

// A constructor for the KNN class
// Takes a vector of InfoVector objects
KNN::KNN(vector<InfoVector> vectors) : m_vectors(vectors), m_strategy(DEFAULT_DISTANCE) {}

// Method for setting the distance strategy used by the KNN class
void KNN::setStrategy(string name)
{
    // Set the distance strategy using the name provided as an input parameter
    m_strategy.setStrategy(name);
}

// Overloaded () operator for calling the KNN class with a vector and a k value
// Returns the most common name among the k closest vectors to the input vector
string KNN::operator()(const vector<double> vec, int k)
{
    // Calculate the distances from the input vector to all vectors in m_vectors
    vector<tuple<double, InfoVector>> distances = distancesFrom(vec);

    // Get the k closest vectors to the input vector
    vector<tuple<double, InfoVector>> closest = getKClosestTo(k, distances);

    // Find the most common name among the k closest vectors
    return mostCommonName(closest);
}

// This function returns a list of distances and info vectors from a given vector
const vector<tuple<double, InfoVector>> KNN::distancesFrom(const vector<double> vec)
{
    // Create a list to store the distances and info vectors
    vector<tuple<double, InfoVector>> distances;
    // Iterate over the list of info vectors
    for (InfoVector infoVector : KNN::m_vectors)
    {
        // Calculate the distance using the distance algorithm and store it with the info vector
        tuple<double, InfoVector> tuple(m_strategy(infoVector.getVector(), vec), infoVector);

        // Add the distance and info vector to the list
        distances.push_back(tuple);
    }

    // Return the list of distances and info vectors
    return distances;
}

const vector<tuple<double, InfoVector>> KNN::getKClosestTo(int k, const vector<tuple<double, InfoVector>> distances)
{
    vector<tuple<double, InfoVector>> kSmallest;

    // create a priority queue to store the k smallest tuples
    // the priority queue will automatically keep the smallest elements at the top
    priority_queue<tuple<double, InfoVector>, vector<tuple<double, InfoVector>>, TupleComparator> pq;

    // add the first k elements from the distances vector to the priority queue
    for (int i = 0; i < k && i < distances.size(); i++)
    {
        pq.push(distances[i]);
    }

    // iterate through the remaining elements in the distances vector
    // if an element is smaller than the top element in the priority queue, remove the top element and add the new element
    for (int i = k; i < ((int)distances.size()); i++)
    {
        if (get<0>(distances[i]) < get<0>(pq.top()))
        {
            pq.pop();
            pq.push(distances[i]);
        }
    }

    // copy the elements in the priority queue to the kSmallest vector
    while (!pq.empty())
    {
        kSmallest.push_back(pq.top());
        pq.pop();
    }

    return kSmallest;
}

// This function finds the most common name from a list of distances and info vectors
string KNN::mostCommonName(const vector<tuple<double, InfoVector>> distances)
{
    // Create a map to store name counts
    map<string, int> nameCount;
    // Iterate over the list of distances and info vectors
    for (tuple<double, InfoVector> t : distances)
    {
        // Increment the count for the current name in the info vector
        nameCount[get<1>(t).getName()] += 1;
    }

    // Initialize variables to store the most common name and its count
    string mostCommon;
    int times = 0;

    // Iterate over the name counts map
    for (pair<string, int> p : nameCount)
    {
        // If the current name count is greater than the current maximum count,
        // update the most common name and its count
        if (get<1>(p) > times)
        {
            mostCommon = get<0>(p);
            times = get<1>(p);
        }
    }

    // Return the most common name
    return mostCommon;
}
