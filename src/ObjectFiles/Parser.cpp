#include "../HeaderFiles/Parser.hpp"
#include "../HeaderFiles/Server.hpp"

Parser::Parser()
{
    command_map["openDataServer"] = new OpenServerCommand();
    command_map["connect"] = new ConnectCommand();
    command_map["var"] = new VerCommand();
    command_map["="] = new EqualMapCommand();
    command_map["while"] = new WhileCommand();
    command_map["print"] = new PrintCommand();
    command_map["sleep"] = new SleepCommand();
}

Parser::~Parser()
{
    delete command_map.at("openDataServer");
    delete command_map.at("connect");
    delete command_map.at("var");
    delete command_map.at("=");
    delete command_map.at("while");
    delete command_map.at("print");
    delete command_map.at("sleep");
    system(" ");
    

}

std::vector<std::vector<std::string>> Parser::vector_commands;

std::vector<std::vector<std::string>> Parser::vector_all_lines;

std::string::size_type Parser::index;

void Parser::parse(std::vector<std::vector<std::string>> &arr)
{
    Parser::vector_all_lines = arr;
    for (Parser::index = 0; Parser::index < arr.size(); Parser::index++)
    {
        Command *c;
        if (arr[Parser::index][1] == "=")
        {
            c = command_map.at(arr[Parser::index][1]);
        }
        else
        {
            c = command_map.at(arr[Parser::index][0]);
        }
        std::vector<std::string> line = arr[Parser::index];
        Parser::index += c->DoCommand(line);
    }
}