#ifndef COMMAND_5_H
#define COMMAND_5_H

#include "Command.h"

// Class that inherits from the Command class, which is responsible for executing a specific action
class Command5 : public Command
{
private:
    // No private variables declared
public:
    // Constructor that takes in a pointer to a KnnClassifier and DefaultIO object
    Command5(KnnClassifier *classifier, DefaultIO *dio);

    // Method to execute the specific action
    void execute();
};

#endif // COMMAND_5_H
