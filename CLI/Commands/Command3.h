#ifndef COMMAND_3_H
#define COMMAND_3_H

#include "Command.h"

class Command3 : public Command
{
private:
    // No private member variables are defined in this class

public:
    // Constructor for Command3, takes a pointer to the classifier and a pointer to the IO object
	Command3(KnnClassifier *classifer, DefaultIO *dio);

    // Override the execute function for Command3
	void execute();
};

#endif // COMMAND_3_H
