#include <iostream>

#include <stdexcept>
#include <string>
#include "Socket/SmartServer.h"
#include "Socket/SocketData.h"
#include "CLI/CLI.h"
#include <thread>

using namespace std;

/*
	./client.out 127.0.0.1 5555
	./server.out 5555

*/

// function to separate the argument passed in when running the program
int seperator(int argc, char *argv[])
{
	// if the number of arguments passed in is not 2
	if (argc != 2)
	{
		// throw an invalid argument exception with a message
		throw invalid_argument("Invalid arguments, please insert the right number of arguments when running");
	}
	// initialize a variable to hold the port number
	int num;
	// try to convert the argument passed in to an integer
	try
	{
		num = stoi(argv[1]);
	}
	// if the conversion fails, throw an invalid argument exception with a message
	catch (const exception &e)
	{
		throw invalid_argument("Invalid argument, please enter only integer as the port");
	}
	// return the port number
	return num;
}

int main(int argc, char *argv[])
{
	// a variable to hold the port number
	int portnum;
	// try to get the port number using the seperator function
	try
	{
		portnum = seperator(argc, argv);
	}
	catch (const exception &e)
	{
		cout << "invalid input" << endl;
		return 0;
	}
	// set the server port to the port number obtained
	const int server_port = portnum;
	// create a SmartServer object with the server port
	SmartServer server(server_port);
	// try to start the server
	try
	{
		server.start();
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}

	// create a CLI object with a pointer to the server
	CLI cli(&server);

	// infinite loop
	while (true)
	{
		// accept a client from the server
		SocketData client = server.acceptClient();

		// create a new thread to handle the client using the start method from the CLI object
		thread t1(&CLI::start, &cli, client);
		// detach the thread so it runs independently
		t1.detach();
	}

	// disconnect the server
	server.disconnect();
	// return 0
	return 0;
}