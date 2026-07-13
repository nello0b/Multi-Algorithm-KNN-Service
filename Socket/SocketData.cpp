#include "SocketData.h"

SocketData::SocketData(int sock, struct sockaddr_in sin) : m_sock(sock), m_sin(sin)
{
}

SocketData::SocketData()
{
}

// copy constructor
SocketData::SocketData(const SocketData &other)
{
    m_sock = other.m_sock;
    m_sin = other.m_sin;
}

// copy assignment operator
SocketData &SocketData::operator=(const SocketData &other)
{
    if (this != &other)
    {
        m_sock = other.m_sock;
        m_sin = other.m_sin;
    }
    return *this;
}

// move constructor
SocketData::SocketData(SocketData &&other) noexcept
{
    m_sock = other.m_sock;
    m_sin = other.m_sin;

    other.m_sock = -1;
    other.m_sin = {0};
}

// move assignment operator
SocketData &SocketData::operator=(SocketData &&other) noexcept
{
    if (this != &other)
    {
        m_sock = other.m_sock;
        m_sin = other.m_sin;

        other.m_sock = -1;
        other.m_sin = {0};
    }
    return *this;
}

void SocketData::cleanSin()
{
    memset(&m_sin, 0, sizeof(m_sin));
}

// destructor
SocketData::~SocketData()
{
}
