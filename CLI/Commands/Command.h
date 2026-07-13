#ifndef COMMAND_H
#define COMMAND_H

#include "IOs/DefaultIO.h"
#include <string>
#include "../../Knn/KnnClassifier.h"
#include "../../Knn/KnnClassifier.h"
#include <stdexcept>

using namespace std;

class Command
{
private:
    
protected:
	// m_index stores the unique index of the command
    // m_description stores the description of the command that will be displayed in the menu
    // m_dio is a pointer to the default input/output object
    // m_classifier is a pointer to the k-nearest neighbor classifier object
	const int m_index;
	const string m_description;
	DefaultIO *m_dio;
	KnnClassifier *m_classifer;

public:
    // constructor for the command class that sets the description, input/output object, classifier, and index
	Command(string description, DefaultIO *dio, KnnClassifier *classifer, int index);
    // function to return the index of the command
    int index() const;
    // function to return the description of the command in the format for display in the menu
	string menuFormat() const;
    // function to execute the command
	virtual void execute();
    // destructor for the command class
	~Command();
};

#endif // COMMAND_H
