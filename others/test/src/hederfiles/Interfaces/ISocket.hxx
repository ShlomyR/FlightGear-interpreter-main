#pragma once

#include <string>

class ISocket 
{
public:
    virtual ~ISocket() = default;
    virtual int createSocket() = 0;
};

class ClientSocket : public ISocket
{
public:
    virtual int connectToServer(int, const int, const char*) = 0;
    virtual int sendMsg(int, std::string const&) = 0;
};

class TcpSocket : public ISocket
{
public:
    virtual void bind(int port) = 0;
    virtual void listen() = 0;
    virtual int accept() = 0;
    virtual ssize_t read(int socket, void *buf, size_t len) = 0;
    virtual void close(int socket) = 0;
};
