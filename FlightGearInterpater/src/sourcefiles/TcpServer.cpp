#include "TcpServer.hpp"

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

TcpServer::TcpServer()
: m_serverSocket(-1)
, m_clientSocket(-1)
{

}

TcpServer *TcpServer::getInstance()
{
    static TcpServer instance;
    return &instance;
}

TcpServer::~TcpServer()
{
    close();
}

bool TcpServer::socket()
{
    m_serverSocket = ::socket(AF_INET, SOCK_STREAM, 0);
    return m_serverSocket != -1;
}

bool TcpServer::bind()
{
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(m_port);
    return ::bind(m_serverSocket, (struct sockaddr*)&address, sizeof(address)) == 0;
}

bool TcpServer::listen(int backlog)
{
    return ::listen(m_serverSocket, backlog) == 0;
}

bool TcpServer::accept()
{
    struct sockaddr_in address;
    socklen_t len = sizeof(address);
    m_clientSocket = ::accept(m_serverSocket, (struct sockaddr*)&address, &len);
    return m_clientSocket != -1;
}

bool TcpServer::close() 
{
    bool success = true;
    if (m_clientSocket != -1) {
        success &= (::close(m_clientSocket) == 0);
        m_clientSocket = -1;
    }
    if (m_serverSocket != -1) {
        success &= (::close(m_serverSocket) == 0);
        m_serverSocket = -1;
    }
    return success;
}

int TcpServer::getClientSocket()
{
    return m_clientSocket;
}

void TcpServer::setPort(int p)
{

    m_port = p;

}
int TcpServer::getPort()
{
    return m_port;
}
