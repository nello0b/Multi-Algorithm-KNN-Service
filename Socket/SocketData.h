#ifndef SOCKET_DATA_H
#define SOCKET_DATA_H

#include <netinet/in.h>
#include <string.h>

class SocketData
{
private:
public:
    int m_sock;               // socket descriptor
    struct sockaddr_in m_sin; // address and port of the socket

    // constructor
    SocketData(int sock, struct sockaddr_in sin);
    SocketData();

    // copy constructor
    SocketData(const SocketData &other);

    // copy assignment operator
    SocketData &operator=(const SocketData &other);

    // move constructor
    SocketData(SocketData &&other) noexcept;

    // move assignment operator
    SocketData &operator=(SocketData &&other) noexcept;

    // destructor
    ~SocketData();

    void cleanSin();
};

#endif // SOCKET_DATA_H
