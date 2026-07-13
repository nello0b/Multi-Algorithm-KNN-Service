#ifndef COMMAND_4_H
#define COMMAND_4_H

#include "Command.h"
#include <sstream>

// Class that inherits from the Command class, which is responsible for executing a specific action
class Command4 : public Command
{
private:
    // No private variables declared
public:
    // Constructor that takes in a pointer to a KnnClassifier and DefaultIO object
    Command4(KnnClassifier *classifier, DefaultIO *dio);

    // Method to execute the specific action
    void execute();
};

#endif // COMMAND_4_H
