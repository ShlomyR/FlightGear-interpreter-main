#include "MapException.hpp"
#include "DataSender.hpp"
#include "SymbolVar.hpp"
#include "Client.hpp"
#include "Socket.hpp"

#include <iostream>
#include <memory>


Client* Client::getInstance()
{
    std::unique_ptr<Socket> socket = std::make_unique<Socket>();
    std::unique_ptr<DataSender> dataSender = std::make_unique<DataSender>();
    static Client instance(std::move(socket),std::move(dataSender));
    return &instance;
}

Client::Client(std::unique_ptr<ClientSocket> socket, std::unique_ptr<IDataSender> dataSender)
: m_socket(std::move(socket))
, m_dataSender(std::move(dataSender))
, m_sockfd(-1)
{}

void Client::connect(const int port, const char* ip) {
    m_sockfd = m_socket->createSocket();
    if (m_sockfd < 0) {
        std::cerr << "Error: Socket creation failed.\n";
        return;
    }
    if (m_socket->connectToServer(m_sockfd, port, ip) < 0) {
        std::cerr << "Error: Connection failed.\n";
        return;
    }
}

void Client::sendData(const std::string word, const std::variant<double, std::string> data) {
    std::string message;
    const auto &varDoubleMap = SymbolVar::getInstance()->getMapDouble();
    const auto &varStringMap = SymbolVar::getInstance()->getMapStr();
    try {
        if (varStringMap.count(word)) {
            message += m_set + " " + varStringMap.at(word) + " ";
        } else if (varDoubleMap.count(word)) {
            message += m_set + " " + varDoubleMap.find(word)->first + " ";
        } else {
            throw MapException("Error: " + word + " not found in map_strDB and in map_doubleDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
        }
    } catch (const MapException& me) {
        std::cout << me.what() << " at line " << me.where() << "\n";
    }

    if (std::holds_alternative<double>(data)) {
        message += std::to_string(std::get<double>(data));
    } else {
        message += std::get<std::string>(data);
    }

    message += m_activate;
    m_socket->sendMsg(m_sockfd, message);
    m_dataSender->sendData(message);
}

void Client::testConnection() 
{
    m_socket->sendMsg(m_sockfd,m_set + " controls/flight/rudder 1" + m_activate);
}
