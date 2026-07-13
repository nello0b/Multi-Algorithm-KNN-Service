#ifndef SERVER_H
#define SERVER_H

#include "Socket.h"

class Server : public Socket
{
private:
protected:
public:
    // constructor for Server class
    Server(int port);

    // initialize the server socket
    void initialize();

    // receive a message through the server socket
    const string receiveMessage(const SocketData &clientData) const;

    // send a message through the server socket
    void sendMessage(const string &message, const SocketData &clientData) const;

    // accept a client connection
    SocketData acceptClient();
};

#endif
