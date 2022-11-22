#include "../HeaderFiles/Server.hpp"
#include "../HeaderFiles/Variable.hpp"
#include "../HeaderFiles/Command.hpp"
#include "../HeaderFiles/Parser.hpp"
#include "../HeaderFiles/Client.hpp"
#include "../HeaderFiles/CommandDefinition.hpp"


int OpenServerCommand::DoCommand(std::vector<std::string> &line)
{
    printf("Server Command\n");
    
    int port;
    
    port = stoi(line[1]);
    
    Server::getInstance()->connectServer(port);
    
    return 0;
}

int ConnectCommand::DoCommand(std::vector<std::string> &line)
{
    string ip;
    int port;
   
    ip = line[1];
    port = stoi(line[2]);

    printf("Connecting the client to the FS...\n");

    Client::getInstance()->connectClient(port,ip.c_str());

    return 0;
}

int VerCommand::DoCommand(std::vector<std::string> &line)
{
    std::vector<std::string> var_arr;
    
    for (std::string::size_type i = 1; i < line.size(); i++)
    {
        var_arr.push_back(line[i]);
    }
    Variable::getInstance()->createVar(var_arr);
    
    return 0;
}

int EqualMapCommand::DoCommand(std::vector<std::string> &line)
{
    if (line.size() == 3) {
        Client::getInstance()->SendVal(line,line[2]);
    }
    else {
       updateFromDB(line);
    }

    return 0;
}


int WhileCommand::DoCommand(std::vector<std::string> &)
{
    
    int skip_row = skipRows(Parser::vector_all_lines,Parser::index);
    
    WhileLoop::whileLoop();
    
    return skip_row;
}


int SleepCommand::DoCommand(std::vector<std::string> &line)
{
    sleepFunc(line[1]);

    return 0;
}


int PrintCommand::DoCommand(std::vector<std::string> &line)
{
    if (line.size() > 2) {
        std::string val = " "; 
        for (string::size_type i = 1; i < line.size(); i++) {
            val+=  line[i]+" ";

        }
        std::cout << "\n" << val << "\n";
         
    }
    else {
        printFunc(line[1]);
    }

    return 0;
}
