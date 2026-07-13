#ifndef KNN_CLASSIFIER_H_
#define KNN_CLASSIFIER_H_

#include "KNN.h"
#include "InfoVector.h"
#include <map>
#include <stdexcept>
#include <string>

// Class representing a k-nearest neighbors classifier
class KnnClassifier{
private:
  // flag indicating if the data has been classified
  bool m_isDataWasClassified;

  // KNN object for performing k-nearest neighbors algorithm
  KNN m_knn;

  // flag indicating if training data has been set
  bool m_isTrain;
  // vector of training data
  vector<InfoVector> m_train;

  // flag indicating if testing data has been set
  bool m_isTest;
  // vector of testing data
  vector<InfoVector> m_test;

  // distance metric to be used for k-nearest neighbors algorithm
  string m_distanc;
  // number of nearest neighbors to consider
  int m_k;

public:
  // Default constructor
  KnnClassifier();

  // Set the number of nearest neighbors to consider
  void setK(int k);
  
  // get the k that used to calculate
	int getK();

  // Set the distance metric to be used
  void setDistanc(string distanc);
  
  // get the distance metric that used
	string getDistance();

  // Set the training data
  void setTrain(vector<InfoVector> train);

  // Set the testing data
  void setTest(vector<InfoVector> test);

  // Get the testing data
  vector<InfoVector> getTest();

  // Perform the classification on the data
  void classifyData();

  // Get the results of the classification
  string getResults();

  // Get the number of training examples
  long unsigned int getTrainSize();

  // Get the number of testing examples
  long unsigned int getTestSize();

  // Check if the data has been classified
  bool isClassified();

  bool isTest();

  bool isTrain();
};

#endif /* KNN_CLASSIFIER_H_ */
