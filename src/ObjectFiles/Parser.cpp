#include <iostream>
#include <cctype>

#include "../HeaderFiles/Parser.hpp"
#include "../HeaderFiles/Server.hpp"

Parser::Parser()
{
    command_map["openDataServer"] = new OpenServerCommand();
    command_map["connect"] = new ConnectCommand();
    command_map["var"] = new VerCommand();
    command_map["="] = new EqualMapCommand();
    command_map["while"] = new WhileCommand();
    command_map["sleep"] = new SleepCommand();
    command_map["print"] = new PrintCommand();
}

Parser::~Parser()
{
    delete command_map.at("openDataServer");
    delete command_map.at("connect");
    delete command_map.at("var");
    delete command_map.at("=");
    delete command_map.at("while");
    delete command_map.at("sleep");
    delete command_map.at("print");
}

std::string::size_type Parser::index;

void Parser::parse(std::vector<std::vector<std::string>> &arr)
{
    //Parser::vector_all_lines = arr;
    Parser::resetIndex();
    for (Parser::getIndex(); Parser::getIndex() < arr.size(); Parser::incrementIndex()) {
        Command *c;
        if (arr[Parser::getIndex()].empty() || arr[Parser::getIndex()][0] == " ") {//.size() == 0 || arr[Parser::getIndex()].size() == 1) {
            printf("\nWhiteSpace was called+++++++++++++++++++++++++++++\n");
            continue;
        }
        if (arr[Parser::getIndex()][1] == "=") {
            c = command_map.at(arr[Parser::getIndex()][1]);
        }
        else {
            c = command_map.at(arr[Parser::getIndex()][0]);
        }
        std::vector<std::string> line = arr[Parser::getIndex()];
        Parser::index += c->DoCommand(line);
    }
}

std::string::size_type Parser::getIndex()
{
    return index;
}

void Parser::incrementIndex()
{
    Parser::index++;
}

void Parser::resetIndex()
{
    Parser::index = 0;
}