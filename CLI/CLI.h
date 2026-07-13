#ifndef CLI_H
#define CLI_H

#include <string>
#include "../Knn/KNN.h"
#include "Commands/Command.h"
#include "Commands/Command1.h"
#include "Commands/Command2.h"
#include "Commands/Command3.h"
#include "Commands/Command4.h"
#include "Commands/Command5.h"
#include "Commands/Command8.h"
#include "Commands/IOs/SocketIO.h"
#include "Commands/IOs/DefaultIO.h"
#include "../Knn/KnnClassifier.h"
#include "../Socket/SmartServer.h"
#include "../Socket/SocketData.h"
#include <vector>

using namespace std;

class CLI
{
private:
	SmartServer *m_socket;
	// we print the menu
	void menu(const DefaultIO *dio, const vector<Command *> commands) const;
	vector<Command *> getCommandsSet(DefaultIO *dio, KnnClassifier *m_classifer) const;

public:
	// CLI constructor
	CLI(SmartServer *socket);

	//start the CLI menu 
	void start(SocketData client) const;
};

#endif // CLI_H
