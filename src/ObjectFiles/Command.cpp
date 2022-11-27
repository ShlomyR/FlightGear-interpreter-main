#include "../HeaderFiles/Server.hpp"
#include "../HeaderFiles/Command.hpp"
#include "../HeaderFiles/Parser.hpp"
#include "../HeaderFiles/Lexer.hpp"
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
    
    for (std::string::size_type i = 1; i < line.size(); i++) {
        var_arr.push_back(line[i]);
    }
    SymbolVar::getInstance()->createVar(var_arr);
    
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


int WhileCommand::DoCommand(std::vector<std::string> &line)
{
    //Parser parser;
    
    // int skip_row = parser.getIndex();
    // std::vector<std::vector<std::string>> p = Lexer::getVecPtr();
    // skip_row += (p[0].size());//skipRows(Parser::getVecAll(),parser.getIndex());
    WhileLoop::whileLoop(line);
    return 0;
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

// int UndefinedCommand::DoCommand(std::vector<std::string> &)
// {
//     // if (line[0] == " ") {
//     //     return Parser::incrementIndex();
//     // }
//     Parser::incrementIndex();
//     return Parser::getIndex();
// }