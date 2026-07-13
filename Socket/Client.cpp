#include "Client.h"
// constructor to initialize the client with a port and IP address
Client::Client(int port, const char *ip_address) : Socket(port),
                                                   m_ip_address(ip_address)

{
}

// initialize the client
void Client::initialize()
{
    // call the initialize function of the base class (Socket)
    Socket::initialize();

    // set up the address for the client
    addressSetUp(inet_addr(m_ip_address));
}

// connect to the server
void Client::connectToServer()
{
    // check if the client has been initialized
    checkIfinitialized();

    // connect to the server
    if (connect(m_socketData.m_sock, (struct sockaddr *)&m_socketData.m_sin, sizeof(m_socketData.m_sin)) < 0)
    {
        // throw an error if the connection fails
        throw std::runtime_error("Error connecting to server");
    }
}

// receive a message from the server
const string Client::receiveMessage() const
{
    // check if the client has been initialized
    checkIfinitialized();

    // receive the message from the server
    return receive(m_socketData.m_sock);
}

// receive a message from the server
const string Client::receiveMessage(const SocketData &clientData) const
{
    return receiveMessage();
}

// send a message to the server
void Client::sendMessage(const string &message) const
{
    // check if the client has been initialized
    checkIfinitialized();

    // send the message to the server
    transfer(message, m_socketData.m_sock);
}

// send a message to the server
void Client::sendMessage(const string &message, const SocketData &clientData) const
{
    sendMessage(message);
}