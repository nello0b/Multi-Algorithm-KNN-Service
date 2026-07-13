#include "KnnClassifier.h"

// Default constructor
// Initializes KNN object, sets default number of nearest neighbors to 5, and sets the distance metric to AUC
KnnClassifier::KnnClassifier() : m_knn(), m_isTrain(false), m_isTest(false),m_isDataWasClassified(false), m_k(5)
{
    setDistanc("AUC");
}

// Set the number of nearest neighbors to consider
void KnnClassifier::setK(int k)
{
    m_k = k;
}

// Set the distance metric to be used
void KnnClassifier::setDistanc(string distanc)
{
    m_distanc = distanc;
    // Pass the distance metric to the KNN object
    m_knn.setStrategy(distanc);
}

// Set the training data
void KnnClassifier::setTrain(vector<InfoVector> train)
{
    m_isTrain = true;
    m_train = train;
    // Pass the training data to the KNN object
    m_knn.setVectors(train);
}

// Set the testing data
void KnnClassifier::setTest(vector<InfoVector> test)
{
    m_isTest = true;
    m_test = test;
    // Reset the flag indicating if the data has been classified
    m_isDataWasClassified=false;
}


// Perform the classification on the data
void KnnClassifier::classifyData()
{
    // Check if k is within the range of the training data size
    if (m_train.size() < m_k)
    {
        // throw an exception if k is out of range
        string str = "invalid argument, please enter k between 1 to " + to_string(m_train.size());
        throw invalid_argument(str);
    }
    // Classify each test vector
    for (InfoVector &vecInfo : m_test)
    {
        // Get the result of the k-nearest neighbors algorithm
        string result = m_knn(vecInfo.getVector(), m_k);
        // Set the classification result for the vector
        vecInfo.setName(result);
    }
    // Set flag indicating that the data has been classified
    m_isDataWasClassified = true;
}

// Get the results of the classification
string KnnClassifier::getResults()
{
    vector<InfoVector> runOn = m_test;
    int i = 1;
    string result = "";
    for (InfoVector vectorInfo : runOn)
    {
        // format the result string
        result += to_string(i) + " " + vectorInfo.getName() + "\n";
        i++;
    }
    return result;
}

// Get the number of training examples
long unsigned int KnnClassifier::getTrainSize()
{
    // Return the size of the training data if it is set, else return 0
    return (m_isTrain) ? m_train.size() : 0;
}

// Get the number of testing examples
long unsigned int KnnClassifier::getTestSize()
{
    // Return the size of the testing data if it is set, else return 0
    return (m_isTest) ? m_test.size() : 0;
}

// Get the testing data
vector<InfoVector> KnnClassifier::getTest(){
    return m_test;
}

// Check if the data has been classified
bool KnnClassifier::isClassified(){
    return m_isDataWasClassified;
}

bool KnnClassifier::isTrain(){
    return m_isTrain;
}

bool KnnClassifier::isTest(){
    return m_isTest;
}

// get the k that used to calculate
int KnnClassifier::getK()
{
	return m_k;
}

// get the distance metric that used
string KnnClassifier::getDistance()
{
	return m_distanc;
}


