#include "SingleConnectionHandler.hpp"

#include <iostream>

void SingleConnectionHandler::handleConnection()
{
    if (!TcpServer::getInstance()->socket()) {
        std::cerr << "Failed to create socket\n";
    }

    if (!TcpServer::getInstance()->bind()) {
        if (!Server::getInstance()->trySecondTime()) {
            std::cerr << "Failed to bind to port " << TcpServer::getInstance()->getPort() << "\n";
            throw std::runtime_error("There is a client already connected to the same port in this moment try again later!!!");
        } else {
            std::cout << "Successfully connected in the second time!!! \n";
        }
    }

    if (!TcpServer::getInstance()->listen(10)) {
        std::cerr << "Failed to listen on socket\n";
    }

    std::cout << "Waiting for connection\n";

    Server::getInstance()->getFlightGearThread() = std::thread([](){ FlightGear::getInstance()->open(); });
    
    if (!TcpServer::getInstance()->accept()) {
        std::cerr << "Failed to accept connection\n";
    } else {
        std::cout << "Connecting...\n";
        Server::getInstance()->getServerDataBaseThread()  = std::thread([](){ Server::getInstance()->runServerDB(); });
    }
}
