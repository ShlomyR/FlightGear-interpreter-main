#include "ConnectCommand.hpp"
#include "Client.hpp"

#include <string>
#include <vector>

void ConnectCommand::DoCommand(std::vector<std::string> const&line)
{
    std::string ip;
    int port;
   
    ip = line[1];
    port = stoi(line[2]);

    printf("Connecting the client to the FS...\n");

    Client::getInstance()->connect(port,ip.c_str());
}