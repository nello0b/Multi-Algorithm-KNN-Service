#ifndef SMART_CLIENT_H
#define SMART_CLIENT_H

#include "Client.h"
#include "../Package/MessageData.h"
#include <fstream>
#include <sstream>
#include <thread>

using namespace std;

// Class representing a smart client that can handle sending and receiving files
class SmartClient : public Client
{
private:
    // Object for handling messages
    MessageData m_message;

protected:
    // Send a line of text to the server
    void sendline();
    // Print the received message
    void print();
    // Upload a file to the server
    void uploadFile(string path);
    // Write the received data to a file
    void writeToFile(string path);
    // Open a file for writing
    void openFile();
    // Close the file
    void closeFile();
    // Write a message to a file
    void writeMessageToFile(string path, string message);

public:
    // Constructor that takes in the server port and IP address
    SmartClient(int server_port, const char *ip_address);
    // Start the client
    void start();
    // Receive data from the server
    void receive();
    // Execute actions based on the received data
    bool execute();
	// Destructor
	~SmartClient();
};
#endif // SMART_CLIENT_H
