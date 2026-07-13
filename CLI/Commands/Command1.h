#ifndef COMMAND_1_H
#define COMMAND_1_H

#include "Command.h"
#include <sstream>

#define DEFAULT_NAME "default_name"

class Command1 : public Command
{
private:
	vector<vector<string>> ParcelInput(string input);

public:
	Command1(KnnClassifier *classifer, DefaultIO *dio);
	void execute();
};

#endif // COMMAND_1_H