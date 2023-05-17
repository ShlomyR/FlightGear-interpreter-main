#include "SingleConnectionHandler.hpp"
#include "OpenServerCommand.hpp"
#include "Server.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

void OpenServerCommand::DoCommand(std::vector<std::string> const&line)
{
    std::cout << "Server Command\n";
    std::shared_ptr<ConnectionHandler> singleConnectionHandler = std::make_unique<SingleConnectionHandler>();
    
    int port = stoi(line[1]);
    TcpServer::getInstance()->setPort(port);
    Server::getInstance()->connectServer(singleConnectionHandler);
}