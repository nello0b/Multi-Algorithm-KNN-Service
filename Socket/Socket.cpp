#include "Socket.h"

using namespace std;

#define TEST_MASSAGE "I_GOT_IT"

Socket::Socket(int port) : m_port(port),
                           m_isInitialize(false)
{
}

// initialize the socket
void Socket::initialize()
{
    // create a socket
    m_socketData.m_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socketData.m_sock < 0)
    {
        throw std::runtime_error("Error creating socket");
    }

    // set the flag indicating that the socket has been initialized
    m_isInitialize = true;
}

// check if the socket has been initialized
void Socket::checkIfinitialized() const
{
    if (!m_isInitialize)
    {
        throw std::runtime_error("Socket is not initialized");
    }
}

// set up address and port for the socket
void Socket::addressSetUp(in_addr_t s_addr)
{
    // check if the socket has been initialized
    checkIfinitialized();

    // clear the memory for the sockaddr_in structure and set its fields
    m_socketData.cleanSin();
    m_socketData.m_sin.sin_family = AF_INET;
    m_socketData.m_sin.sin_addr.s_addr = s_addr;
    m_socketData.m_sin.sin_port = htons(m_port);
}

// bind the socket to the address and port
void Socket::bindSocket()
{
    // check if the socket has been initialized
    checkIfinitialized();

    // bind the socket to the address and port
    if (bind(m_socketData.m_sock, (struct sockaddr *)&m_socketData.m_sin, sizeof(m_socketData.m_sin)) < 0)
    {
        throw std::runtime_error("Error binding socket");
    }
}

void Socket::listenToConnections()
{
    // check if the socket has been initialized
    checkIfinitialized();

    // listen for incoming connections on the socket
    if (listen(m_socketData.m_sock, NUMBER_OF_CLIENTS) < 0)
    {
        throw std::runtime_error("Error listening to a socket");
    }
}

// send a message through the socket
void Socket::transfer(const string &message, int destinationSocket) const
{
    // check if the socket has been initialized
    checkIfinitialized();

    // send the message through the socket
    int sent_bytes = send(destinationSocket, message.c_str(), message.size(), 0);
    if (sent_bytes < 0)
    {
        throw std::runtime_error("Error sending");
    }

    // vvvvvvvvvvvvvvvvvvvvvvvvv
    char buffer[BUFFER_SIZE];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(destinationSocket, buffer, expected_data_len, 0);
    if (read_bytes == 0)
    {
        // connection is closed
        throw std::runtime_error("Connection closed");
    }
    else if (read_bytes < 0)
    {
        // error
        throw std::runtime_error("Error reciving");
    }
    buffer[read_bytes] = '\0';
    if (string(buffer) != TEST_MASSAGE)
    {
        throw std::runtime_error("Error sending");
    }
    // ^^^^^^^^^^^^^^^^^^^^^^^^^
}

// receive a message through the socket
const string Socket::receive(int destinationSocket) const
{
    // check if the socket has been initialized
    checkIfinitialized();

    // receive the message through the socket
    char buffer[BUFFER_SIZE];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(destinationSocket, buffer, expected_data_len, 0);
    if (read_bytes == 0)
    {
        // connection is closed
        throw std::runtime_error("Connection closed");
    }
    else if (read_bytes < 0)
    {
        // error
        throw std::runtime_error("Error reciving");
    }
    buffer[read_bytes] = '\0';

    // vvvvvvvvvvvvvvvvvvvvvvvvv
    //  send the message through the socket
    int sent_bytes = send(destinationSocket, string(TEST_MASSAGE).c_str(), string(TEST_MASSAGE).size(), 0);
    if (sent_bytes < 0)
    {
        throw std::runtime_error("Error sending");
    }
    // ^^^^^^^^^^^^^^^^^^^^^^^^^

    return string(buffer);
}

// close the socket
void Socket::disconnect()
{
    // check if the socket has been initialized
    checkIfinitialized();

    // close the socket
    close(m_socketData.m_sock);
}

// destructor for the Socket class
Socket::~Socket()
{
    disconnect();
}
