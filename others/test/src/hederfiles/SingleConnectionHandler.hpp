#pragma once

#include <iostream>

#include "../hederfiles/Interfaces/ConnectionHandler.hxx"
#include "../hederfiles/FlightGear.hpp"
#include "../hederfiles/TcpServer.hpp"
#include "../hederfiles/Server.hpp"

class SingleConnectionHandler : public ConnectionHandler
{
public:
    void handleConnection() override;
};