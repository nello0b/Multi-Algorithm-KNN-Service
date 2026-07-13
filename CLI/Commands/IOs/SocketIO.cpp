#include "SocketIO.h"

// constructor that sets the socket and target
SocketIO::SocketIO(SmartServer *socket, SocketData target) : m_socket(socket), m_target(target) {}

// constructor that sets only the socket
SocketIO::SocketIO(SmartServer *socket) : m_socket(socket) {}

string SocketIO::read() const
{
    // getLine function is used to read input from the user
	return m_socket->getLine(m_target);
}

void SocketIO::write(const string &message) const
{
    // sendLine function is used to write a message to the user
	m_socket->sendLine(message, m_target);
}

string SocketIO::readFile() const
{
    // receiveFile function is used to read from a file
	return m_socket->receiveFile(m_target);
}

void SocketIO::writeFile(const string &message) const
{
    // sendFile function is used to write to a file
	m_socket->sendFile(message, m_target);
}

void SocketIO::disconnect() const
{
    // disconnectMessage function is used to close any open file or connection
	m_socket->disconnectMessage(m_target);
}
