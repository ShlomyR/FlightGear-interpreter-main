#pragma once

#include <string>
#include <vector>

#include "ISocket.hxx"

class Socket : public ClientSocket {
public:
    int createSocket() override;
    int connectToServer(int sockfd, const int port, const char* ip) override;
    int sendMsg(int sockfd, std::string const& msg) override;
};