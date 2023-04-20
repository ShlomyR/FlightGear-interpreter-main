#include <string>
#include <vector>

#include "../hederfiles/OpenServerCommand.hpp"
#include "../hederfiles/Server.hpp"

int OpenServerCommand::DoCommand(std::vector<std::string> const&line)
{
    printf("Server Command\n");
    
    int port;
    
    port = stoi(line[1]);
    
    Server::getInstance()->connectServer(port);
    
    return 0;
}