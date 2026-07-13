#ifndef COMMAND_8_H
#define COMMAND_8_H

#include "Command.h"

// Class that inherits from the Command class, which is responsible for executing a specific action
class Command8 : public Command
{
private:
    // No private variables declared
public:
    // Constructor that takes in a pointer to a KnnClassifier and DefaultIO object
    Command8(KnnClassifier *classifier, DefaultIO *dio);

    // Method to execute the specific action
    void execute();
};

#endif // COMMAND_8_H
