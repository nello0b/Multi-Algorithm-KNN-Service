#ifndef SOCKET_IO_H
#define SOCKET_IO_H

#include "DefaultIO.h"
#include "../../../Socket/SmartServer.h"
#include "../../../Socket/SocketData.h"

using namespace std;

class SocketIO : public DefaultIO
{
private:
    // pointer to SmartServer class
	SmartServer *m_socket;
    // target socket
	const SocketData m_target;

public:
    // constructor that sets the socket and target
	SocketIO(SmartServer *socket, const SocketData target);
    // constructor that sets only the socket
	SocketIO(SmartServer *socket);

    // implementation of the pure virtual functions from the base class DefaultIO
	string read() const;
	void write(const string &message) const;
	string readFile() const;
	void writeFile(const string &message) const;
	void disconnect() const;
};

#endif // SOCKET_IO_H
