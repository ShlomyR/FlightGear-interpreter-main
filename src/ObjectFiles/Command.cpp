#include <iostream>

#include "../HeaderFiles/Server.hpp"
#include "../HeaderFiles/Parser.hpp"
#include "../HeaderFiles/Client.hpp"
#include "../HeaderFiles/WhileLoop.hpp"
#include "../HeaderFiles/SymbolVar.hpp"


int OpenServerCommand::DoCommand(std::vector<std::string> const&line)
{
    printf("Server Command\n");
    
    int port;
    
    port = stoi(line[1]);
    
    Server::getInstance()->connectServer(port);
    
    return 0;
}

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

int VerCommand::DoCommand(std::vector<std::string> const&line)
{
    std::vector<std::string> var_arr;
    
    for (std::string::size_type i = 1; i < line.size(); i++) {
        var_arr.push_back(line[i]);
    }
    SymbolVar::getInstance()->createVar(var_arr);
    
    return 0;
}

int EqualMapCommand::DoCommand(std::vector<std::string> const&line)
{
    if (line.size() == 3) {
        Client::getInstance()->SendVal(line,line[2]);
    } else {
       updateFromDB(line);
    }

    return 0;
}


int WhileCommand::DoCommand(std::vector<std::string> const&line)
{
    int temp_row_num = Parser::getIndex()+1;
    WhileLoop::whileLoop(line);
    return temp_row_num;
}


int SleepCommand::DoCommand(std::vector<std::string> const&line)
{
    sleepFunc(line[1]);
    return 0;
}


int PrintCommand::DoCommand(std::vector<std::string> const&line)
{
    if (line.size() > 2) {
        std::string val = " "; 
        for (std::string::size_type i = 1; i < line.size(); i++) {
            val+=  line[i]+" ";

        }
        std::cout << "\n" << val << "\n";
    } else {
        printFunc(line[1]);
    }
    return 0;
}

int BreakCommand::DoCommand(std::vector<std::string> const&line)
{
    breakFunc(line);
    return 0;
}