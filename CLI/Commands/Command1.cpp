#include "Command1.h"

// constructor that calls the base class constructor with the specific description, input/output object, classifier, and index for this command
 // Initialize the base class with the specified description, input/output object, classifier, and index
Command1::Command1(KnnClassifier *classifer, DefaultIO *dio)
    : Command("upload an unclassified csv data file", dio, classifer, 1){};


void Command1::execute()
{
    // Prompt the user to upload a local train CSV file
	m_dio->write("Please upload your local train CSV file.");
    // Read the input file
	string input;
    // Attempt to read the file, if an exception is caught, return
	try
	{
		input = m_dio->readFile();
	}
	catch (const exception &e)
	{
		return;
	}

    // Parse the input file into a 2D vector of strings
	vector<vector<string>> vecVecSrr = ParcelInput(input);
    // Create a vector of InfoVector objects from the 2D vector of strings
	vector<InfoVector> train;
    // Attempt to create the InfoVector objects, if an exception is caught, display an error message and return
	try
	{
		train = InfoVector::creatClassifiedVectorInfo(vecVecSrr);
	}
	catch (const exception &e)
	{
		string str = "invalid input";
		str += "\n";
		m_dio->write(str);
		return;
	}
    // Prompt the user to upload a local test CSV file
	m_dio->write("Please upload your local test CSV file.");

    // Attempt to read the file, if an exception is caught, return
	try
	{
		input = m_dio->readFile();
	}
	catch (const exception &e)
	{
		return;
	}

    // Parse the input file into a 2D vector of strings
	vecVecSrr = ParcelInput(input);
    // Create a vector of InfoVector objects from the 2D vector of strings
	vector<InfoVector> test;
    // Attempt to create the InfoVector objects, if an exception is caught, display an error message and return
    try
	{
		test = InfoVector::creatUnclassifiedVectorInfo(vecVecSrr, DEFAULT_NAME);
		if (test.at(0).getSize() != train.at(0).getSize())
		{
			throw invalid_argument("Invalid argument, please give proper file");
		}
	}
	catch (const exception &e)
	{
		string str = "invalid input";
		str += "\n";
		m_dio->write(str);
		return;
	}

    // Set the train and test sets for the classifier
	m_classifer->setTrain(train);
	m_classifer->setTest(test);
}


vector<vector<string>> Command1::ParcelInput(string input)
{
    // Create a string stream from the input string
	istringstream iss(input);
    // Create a 2D vector to store the values from the input file
	vector<vector<string>> values;
    // Create a string to store each line from the input file
	string line;
    // Create a flag to indicate if the first line of the input file has been read
	bool isfirstline = true;
    // Create a variable to store the size of the first line of values
	long unsigned int firstSize = 0;

    // Read each line of the input file
	while (getline(iss, line))
	{
		// Create a string stream from the line
		stringstream lineStream(line);

		// Read each value from the line using the ',' delimiter
		string value;
		vector<string> lineValues;
		while (getline(lineStream, value, ','))
		{
			// Add the value to the vector of values for this line
			lineValues.push_back(value);
		}
		// If this is the first line, record the size of the line values
		if (isfirstline)
		{
			firstSize = lineValues.size();
			isfirstline = false;
		}
		// Check if the size of the new line equals the size of the first line
		if (lineValues.size() != firstSize)
		{
			// Throw an exception if the sizes do not match
			throw std::invalid_argument("invalid input please send a file where every vector is the same size");
		}
		// Add the vector of values for this line to the 2D vector
		values.push_back(lineValues);
	}
    // Return the 2D vector of values
	return values;
}
