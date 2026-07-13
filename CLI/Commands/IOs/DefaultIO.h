#ifndef DEFAULT_IO_H
#define DEFAULT_IO_H

#include <string>

using namespace std;

class DefaultIO
{

public:
    // This class defines an interface for input/output operations
    // The functions are declared as pure virtual function, meaning that any derived classes must implement them
	virtual string read() const = 0;
    // read function reads input from the user
	virtual void write(const string &message) const = 0;
    // write function writes a message to the user
	virtual string readFile() const = 0;
    // readFile function reads from a file
	virtual void writeFile(const string &message) const = 0;
    // writeFile function writes to a file
	virtual void disconnect() const = 0;
    // disconnect function is used to close any open file or connection
};

#endif // DEFAULT_IO_H
