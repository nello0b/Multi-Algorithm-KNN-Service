#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdexcept>

#include <cstring>
#include "SocketData.h"

using namespace std;

#define BUFFER_SIZE 4096
#define NUMBER_OF_CLIENTS 7

class Socket
{
private:
    bool m_isInitialize; // indicates whether the socket has been initialized

protected:
    // side A socket
    const int m_port;        // port number
    SocketData m_socketData; // socket data

    // check if the socket has been initialized
    void checkIfinitialized() const;

    // constructor
    Socket(int port);

    // set up address and port for the socket
    void addressSetUp(in_addr_t s_addr);

    // bind the socket to the address and port
    void bindSocket();

    // listen for incoming connections on the socket
    void listenToConnections();

    // receive message from a destination socket
    const string receive(int destinationSocket) const;

    // send message to a destination socket
    void transfer(const string &message, int destinationSocket) const;

    // initialize the socket
    void initializeSocket();

public:
    // receive message (pure virtual function)
    virtual const string receiveMessage(const SocketData &clientData) const = 0;

    // send message (pure virtual function)
    virtual void sendMessage(const string &message, const SocketData &clientData) const = 0;

    // initialize the socket (virtual function)
    virtual void initialize();

    // close the socket
    void disconnect();

    // destructor
    ~Socket();
};

#endif
