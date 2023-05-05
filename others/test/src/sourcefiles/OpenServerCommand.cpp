#include <string>
#include <vector>
#include <memory>

#include "../hederfiles/SingleConnectionHandler.hpp"
#include "../hederfiles/OpenServerCommand.hpp"
#include "../hederfiles/Server.hpp"

void OpenServerCommand::DoCommand(std::vector<std::string> const&line)
{
    printf("Server Command\n");
    std::shared_ptr<ConnectionHandler> singleConnectionHandler = std::make_shared<SingleConnectionHandler>();
    
    int port = stoi(line[1]);
    TcpServer::getInstance()->setPort(port);
    Server::getInstance()->connectServer(singleConnectionHandler);
}