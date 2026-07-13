#include "Command5.h"

// Constructor for the Command5 class, which inherits from the Command class
// Takes in pointers to a KnnClassifier and DefaultIO objects
Command5::Command5(KnnClassifier *classifier, DefaultIO *dio)
    : Command("download results", dio, classifier, 5){};

// Method to execute the specific action of this command
void Command5::execute()
{
    // Check if data has been uploaded
	if (!m_classifer->isTrain() || !m_classifer->isTest())
	{
		m_dio->write("please upload data");
		return;
	}
	// Check if data has been classified
	if (!m_classifer->isClassified())
	{
		m_dio->write("please classify the data");
		return;
	}
    // Get the results from the classifier and write to a file
    string output = m_classifer->getResults();
    m_dio->writeFile(output);
}

// woringing progress
string sendResult(vector<InfoVector> runOn, string path)
{
	// add start writhing into file
	int i = 1;
	string result = "";
	for (InfoVector vectorInfo : runOn)
	{
		result += to_string(i) + " " + vectorInfo.getName() + "\n";
		// send to the file the result
		i++;
	}
	// add ending wrtinng into file
	return result;
}