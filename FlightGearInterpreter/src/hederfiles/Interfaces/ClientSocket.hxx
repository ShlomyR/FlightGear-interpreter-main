#pragma once

#include "ISocket.hxx"

#include <string>

class ClientSocket : public ISocket
{
public:
    virtual int connectToServer(int, const int, const char*) = 0;
    virtual int sendMsg(int, std::string const&) = 0;
};