#ifndef COMMAND_2_H
#define COMMAND_2_H

// Include the base Command class
#include "Command.h"
// Include the stringstream library
#include <sstream>
// Include the map library
#include <map>
// Include the standard exception library
#include <stdexcept>
// Include the tuple library
#include <tuple>

class Command2 : public Command
{
private:
    // Declare a private helper function to parse the input string and return a tuple of k and distance metric
	tuple<int, string> algorithmSettings(const string &input);

public:
    // Constructor for Command2, takes a pointer to the classifier and a pointer to the IO object
	Command2(KnnClassifier *classifer, DefaultIO *dio);

    // Override the execute function for Command2
	void execute();
};

#endif // COMMAND_2_H
