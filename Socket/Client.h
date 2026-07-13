#ifndef CLIENT_H
#define CLIENT_H

#include "Socket.h"
#include <iostream>
#include <string>

class Client : public Socket
{
private:
    const char *m_ip_address; // private member variable to hold IP address

protected:
public:
    // constructor to initialize client with server port and IP address
    Client(int server_port, const char *ip_address);

    // initialize the client
    void initialize();

    // receive a message from the server
    const string receiveMessage() const;
    const string receiveMessage(const SocketData &clientData) const;

    // send a message to the server
    void sendMessage(const string &message) const;
    void sendMessage(const string &message, const SocketData &clientData) const;

    // connect to the server
    void connectToServer();
};

#endif
