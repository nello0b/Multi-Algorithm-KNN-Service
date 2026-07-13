#ifndef SMART_SERVER_H
#define SMART_SERVER_H

#include "Server.h"
#include "SocketData.h"
#include <sstream>
#include "../Package/MessageData.h"

using namespace std;

// Class representing a smart server that can handle sending and receiving files
class SmartServer : public Server
{
private:
    // Object for handling messages
    MessageData m_message;

protected:
public:
    // Constructor that takes in the port to listen on
    SmartServer(int port);

    // Start the server
    void start();

    // Receive data from a client
    void receive(const SocketData client);

    // Send a disconnect message to a client
    void disconnectMessage(const SocketData client);

    // Send a file to a client
    void sendFile(string output, const SocketData client);

    // Receive a file from a client
    string receiveFile(const SocketData client);

    // Send a line of text to a client
    void sendLine(string output, const SocketData client);

    // Receive a line of text from a client
    string getLine(const SocketData client);
};

#endif // SMART_SERVER_H
