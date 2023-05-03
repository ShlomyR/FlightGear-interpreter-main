#include <string>
#include <vector>

#include "../hederfiles/ConnectCommand.hpp"
#include "../hederfiles/Client.hpp"

void ConnectCommand::DoCommand(std::vector<std::string> const&line)
{
    std::string ip;
    int port;
   
    ip = line[1];
    port = stoi(line[2]);

    printf("Connecting the client to the FS...\n");

    Client::getInstance()->connect(port,ip.c_str());
}