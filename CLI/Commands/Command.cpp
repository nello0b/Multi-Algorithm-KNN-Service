#include "Command.h"

// constructor that sets the description, io, classifier and index
Command::Command(string description, DefaultIO *dio, KnnClassifier *classifer, int index) : m_classifer(classifer), m_description(description), m_dio(dio), m_index(index)
{
}

string Command::menuFormat() const
{
    // return the index and description of the command in a string format
	return to_string(m_index) + ".  " + m_description;
}

void Command::execute()
{
    // This function is intended to be overridden by derived classes to implement the specific functionality of the command
}

int Command::index() const
{
    // return the index of the command
	return m_index;
}

Command::~Command()
{
    // destructor
}
