#pragma once

#include "ClientSocket.hxx"
#include "ISocket.hxx"

#include <string>

class Socket : public ClientSocket 
{
public:
    int createSocket() override;
    int connectToServer(int, const int, const char*) override;
    int sendMsg(int, std::string const&) override;
};