#pragma once

#include "ISocket.hxx"

#include <iostream>

class TcpSocket : public ISocket
{
public:
    virtual void bind(int) = 0;
    virtual void listen() = 0;
    virtual int accept() = 0;
    virtual ssize_t read(int, void *, size_t) = 0;
    virtual void close(int) = 0;
};