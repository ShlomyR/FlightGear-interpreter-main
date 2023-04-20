#include <string>
#include <vector>

#include "../hederfiles/ConnectCommand.hpp"
#include "../hederfiles/Client.hpp"

int ConnectCommand::DoCommand(std::vector<std::string> const&line)
{
    std::string ip;
    int port;
   
    ip = line[1];
    port = stoi(line[2]);

    printf("Connecting the client to the FS...\n");

    Client::getInstance()->connectClient(port,ip.c_str());

    return 0;
}