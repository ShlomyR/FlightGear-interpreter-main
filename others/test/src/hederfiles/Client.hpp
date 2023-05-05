#pragma once

#include <string>
#include <vector>
#include <variant>
#include <memory>

#include "ISocket.hxx"
#include "IDataSender.hxx"

class Client {
public:
    static Client* getInstance();
    void connect(const int port, const char* ip);
    void sendData(const std::string ,  const std::variant<double, std::string>);
    void testConnection();

private:
    Client(std::unique_ptr<ClientSocket>, std::unique_ptr<IDataSender>);
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
private:
    std::unique_ptr<ClientSocket> m_socket;
    std::unique_ptr<IDataSender> m_dataSender;
    std::string m_set = "set";
    std::string m_activate = "\r\n";

    int m_sockfd;
};
