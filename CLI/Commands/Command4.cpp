#include "Command4.h"

// Constructor for Command4, takes a pointer to the classifier and a pointer to the IO object
Command4::Command4(KnnClassifier *classifer, DefaultIO *dio)
	: Command("display results", dio, classifer, 4){};

void Command4::execute()
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
	// Get the results of the classification
	string output = m_classifer->getResults();
	// Create an input string stream from the results string
	istringstream iss(output);
	output += "Done.";
	string line;
	// Read each line from the string stream
	while (getline(iss, line))
	{
		// Write the line to the IO
		m_dio->write(line);
	}
	// Write "Done." to the IO
	m_dio->write("Done.");
}
