#include "CLI.h"
#include <iostream>

CLI::CLI(SmartServer *socket) : m_socket(socket)
{
}

vector<Command *> CLI::getCommandsSet(DefaultIO *dio, KnnClassifier *classifer) const
{
    // This function returns a vector containing all the commands available in the CLI.
    // Each command is represented by an instance of a class that inherits from the Command class.
    // 'classifer' and 'dio' are passed as arguments to the constructors of the command classes.
    vector<Command *> commands;
    commands.push_back(new Command1(classifer, dio)); // Adding instance of Command1 to the vector.
    commands.push_back(new Command2(classifer, dio)); // Adding instance of Command2 to the vector.
    commands.push_back(new Command3(classifer, dio)); // Adding instance of Command3 to the vector.
    commands.push_back(new Command4(classifer, dio)); // Adding instance of Command4 to the vector.
    commands.push_back(new Command5(classifer, dio)); // Adding instance of Command5 to the vector.
    commands.push_back(new Command8(classifer, dio)); // Adding instance of Command8 to the vector.
    return commands;
}

void CLI::start(SocketData client) const
{
    // Create a new KnnClassifier object and a new SocketIO object
    KnnClassifier *classifier = new KnnClassifier();
    DefaultIO *dio = new SocketIO(m_socket, client);
    // Get a set of commands that are available to the user
    vector<Command *> commands = getCommandsSet(dio, classifier);

    bool isRunning = true;
    int inputtedOption;

    // Continuously run until the user exits
    while (isRunning)
    {
        try
        {
            // Display the menu of available commands
            menu(dio, commands);
            // Read the user's input

            string str = dio->read();
            try
            {
                inputtedOption = stoi(str);
            }
            catch (const exception &e)
            {
                inputtedOption = -1;
            }
            bool isExecuted = false;
            // Iterate through the set of commands to find the one that the user selected
            for (Command *c : commands)
            {
                if (c->index() == inputtedOption)
                {
                    c->execute();
                    isExecuted = true;
                    break;
                }
            }
            if (!isExecuted)
            {
                // If the user inputted an invalid option, inform the user
                dio->write("Command '" + str + "' doesn't exists");
            }
        }
        catch (const exception &e)
        {
            isRunning = false;
        }
    }

    // Clean up dynamically allocated objects
    Command *commandToDelete;
    for (int i = 0; i < commands.size(); i++)
    {
        commandToDelete = commands.back();
        commands.pop_back();
        delete commandToDelete;
    }
    delete classifier;
}

void CLI::menu(const DefaultIO *dio, const vector<Command *> commands) const
{
    dio->write("Welcome to the KNN Classifier Server. Please choose an option:");

    // Iterate through the set of available commands
    for (Command *command : commands)
    {
        // Call the menuFormat method of the command to get its string representation
        dio->write(command->menuFormat());
    }
}
