#include "Command2.h"

tuple<int, string> Command2::algorithmSettings(const string &input)
{
    // Create a string stream from the input string
	istringstream iss(input);
    // Create a variable to store the distance metric
	string distance;
    // Create a variable to store the value of k
	int k;
    // Attempt to read the value of k from the input string
	if (!(iss >> k))
	{
        // If the value of k cannot be read, throw an invalid_argument exception
		throw invalid_argument("invalid value for K");
	}
    // Check if the value of k is less or equal than 0, throw an invalid_argument exception
	if(k<=0){
		throw invalid_argument("invalid value for K");
	}
    // Read the distance metric from the input string
	iss >> distance;
    // Check if the distance metric is a valid value
	if (distance != "AUC" && distance != "MAN" && distance != "CHB" && distance != "CAN" && distance != "MIN")
	{
        // If the distance metric is not valid, throw an invalid_argument exception
		throw invalid_argument("invalid value for metric");
	}
    // Create a tuple with k and distance metric
	tuple<int, string> tup(k, distance);
    // Return the tuple
	return tup;
}


Command2::Command2(KnnClassifier *classifer, DefaultIO *dio)
	: Command("algorithm settings", dio, classifer, 2){};

void Command2::execute()
{
    // Create a string to display the current algorithm settings
    string str = "";
    str += "The current KNN parameters are: K = " + to_string(m_classifer->getK());
    str += ", distance metric = " + m_classifer->getDistance();
    // Write the current settings to the user
    m_dio->write(str);
    // Create a variable to store the value of k
    int k;
    // Create a variable to store the distance metric
    string distanc;
    // Create a variable to store the input string
    string input;
    // Read the input string from the user
    input = m_dio->read();
	if(input==""){
		return;
	}
    try
    {
        // Call the algorithmSettings function to retrieve the k and distance metric values
        tuple<int, string> tup = algorithmSettings(input);
        // Extract the k value from the tuple
        k = get<0>(tup);
        // Extract the distance metric value from the tuple
        distanc = get<1>(tup);
        // Set the distance metric and k values in the classifier
        m_classifer->setDistanc(distanc);
        m_classifer->setK(k);
    }
    catch (const exception &e)
    {
        // If an exception is thrown, write the exception message to the user
        m_dio->write(e.what());
    }
}
