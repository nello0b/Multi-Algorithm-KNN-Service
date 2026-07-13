#include "Server.h"

// constructor for Server class
Server::Server(int port) : Socket(port)
{
}

// initialize the server socket
void Server::initialize()
{
    Socket::initialize();

    // set up address and port to listen on any available interface
    addressSetUp(INADDR_ANY);

    // bind the socket to the address and port
    bindSocket();

    // listen for incoming connections on the socket
    listenToConnections();
}

// accept a client connection
SocketData Server::acceptClient()
{
    checkIfinitialized();
    SocketData clientData;

    // accept a client connection
    unsigned int addr_len = sizeof(clientData.m_sin);
    clientData.m_sock = accept(m_socketData.m_sock, (struct sockaddr *)&clientData.m_sin, &addr_len);
    if (clientData.m_sock < 0)
    {
        throw std::runtime_error("Error accepting client");
    }

    return clientData;
}

// receive a message through the server socket
const string Server::receiveMessage(const SocketData &clientData) const
{
    checkIfinitialized();

    return receive(clientData.m_sock);
}

// send a message through the server socket
void Server::sendMessage(const string &message, const SocketData &clientData) const
{
    checkIfinitialized();

    transfer(message, clientData.m_sock);
}
