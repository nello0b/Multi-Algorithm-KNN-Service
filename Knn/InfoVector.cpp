#include <iterator>
#include "InfoVector.h"
#include <iostream>

// Create a constructor for the InfoVector class
// Takes a vector of strings as an input parameter
InfoVector::InfoVector(vector<string> &v) : m_name(v.back())
{
	// Iterate over the input vector (except for the last element which is the name of the vector)
	for (vector<string>::iterator it = v.begin(); it != v.end() - 1; ++it)
	{
		// Convert the string to a double and store it in m_vector
		m_vector.push_back(std::stod(*it));
	}
}

InfoVector::InfoVector(vector<string> &v,const string& defaultName): m_name(defaultName)
	{
		// Iterate over the input vector (except for the last element which is the name of the vector)
		for (vector<string>::iterator it = v.begin(); it != v.end(); ++it)
		{
			// Convert the string to a double and store it in m_vector
			m_vector.push_back(std::stod(*it));
		}
	}

// Method for returning the size of the vector
long unsigned int InfoVector::getSize()
{
	return m_vector.size();
}

// Method for returning the name of the vector
const string InfoVector::getName() const
{
	return m_name;
}

// Method for returning the vector of double values
vector<double> InfoVector::getVector()
{
	return m_vector;
}


vector<InfoVector> InfoVector::creatClassifiedVectorInfo(vector<vector<string>> v)
{
	// Create a vector of InfoVector objects
	vector<InfoVector> vectorOfInfoVector;
	// Loop through each line of the 2D vector
	for (vector<string> &lineVector : v)
	{
		// Create an InfoVector object from the current line
		InfoVector infoVector(lineVector);

		// Add the InfoVector object to the vector of InfoVector objects
		vectorOfInfoVector.push_back(infoVector);
	}

	// Return the vector of InfoVector objects
	return vectorOfInfoVector;
}

vector<InfoVector> InfoVector::creatUnclassifiedVectorInfo(vector<vector<string>> v,const string& defaultName)
{
	// Create a vector of InfoVector objects
	vector<InfoVector> vectorOfInfoVector;

	// Loop through each line of the 2D vector
	for (vector<string> &lineVector : v)
	{
		// Create an InfoVector object from the current line
		InfoVector infoVector(lineVector,defaultName);

		// Add the InfoVector object to the vector of InfoVector objects
		vectorOfInfoVector.push_back(infoVector);
	}

	// Return the vector of InfoVector objects
	return vectorOfInfoVector;
}

// Set the name of the InfoVector object
void InfoVector::setName(const string& name){
    // Assign the "name" parameter to the "m_name" member variable
	m_name = name;
}
