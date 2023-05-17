#pragma once

#include "ConnectionHandler.hxx"
#include "FlightGear.hpp"
#include "TcpServer.hpp"
#include "Server.hpp"

class SingleConnectionHandler : public ConnectionHandler
{
public:
    void handleConnection() override;
};