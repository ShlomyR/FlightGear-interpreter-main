#pragma once

#include <string>
#include <vector>

#include "../hederfiles/Interfaces/ISocket.hxx"

class Socket : public ClientSocket 
{
public:
    int createSocket() override;
    int connectToServer(int, const int, const char*) override;
    int sendMsg(int, std::string const&) override;
};