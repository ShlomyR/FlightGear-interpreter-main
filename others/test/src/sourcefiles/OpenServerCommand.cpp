#include <string>
#include <vector>

#include "../hederfiles/OpenServerCommand.hpp"
#include "../hederfiles/TcpServer.hpp"
#include "../hederfiles/Server.hpp"

void OpenServerCommand::DoCommand(std::vector<std::string> const&line)
{
    printf("Server Command\n");
    
    int port = stoi(line[1]);
    TcpServer::getInstance()->setPort(port);
    Server::getInstance()->connectServer();
}