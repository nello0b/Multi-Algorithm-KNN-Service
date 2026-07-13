#ifndef INFOVECTOR_H_
#define INFOVECTOR_H_

#include <vector>
#include <string>

// Use the std namespace
using namespace std;

// Class for representing a vector with a name and a vector of double values
class InfoVector
{
    // Private member variable for the name of the vector
    string m_name;

    // Private member variable for the vector of double values
    vector<double> m_vector;

public:
    // Constructor for the InfoVector class
    // Takes a vector of strings as an input parameter
    InfoVector(vector<string> &v);

	InfoVector(vector<string> &v,const string& defaultName);

    // Method for returning the vector of double values
    const vector<string> &getVector() const;

    // Method for returning the name of the vector
    const string getName() const;

    // Method for returning the size of the vector
    long unsigned int getSize();

    // Method for returning the vector of double values
    vector<double> getVector();

   
	static vector<InfoVector> creatClassifiedVectorInfo(vector<vector<string>> v);
	
	static vector<InfoVector> creatUnclassifiedVectorInfo(vector<vector<string>> v,const string& defaultName);

	void setName(const string& name);

};

#endif // INFOVECTOR_H_
