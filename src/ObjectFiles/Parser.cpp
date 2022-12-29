#include <iostream>
#include <cctype>

#include "../HeaderFiles/Parser.hpp"
#include "../HeaderFiles/Server.hpp"

Parser::Parser()
{
    m_command_map["openDataServer"] = new OpenServerCommand();
    m_command_map["connect"] = new ConnectCommand();
    m_command_map["var"] = new VerCommand();
    m_command_map["="] = new EqualMapCommand();
    m_command_map["while"] = new WhileCommand();
    m_command_map["sleep"] = new SleepCommand();
    m_command_map["print"] = new PrintCommand();
    m_command_map["brake"] = new BreakCommand();
}

Parser::~Parser()
{
    delete m_command_map.at("openDataServer");
    delete m_command_map.at("connect");
    delete m_command_map.at("var");
    delete m_command_map.at("=");
    delete m_command_map.at("while");
    delete m_command_map.at("sleep");
    delete m_command_map.at("print");
    delete m_command_map.at("brake");
}

std::string::size_type Parser::m_index;

void Parser::parse(std::vector<std::vector<std::string>> const&arr)
{
    Parser::resetIndex();
    for (Parser::getIndex(); Parser::getIndex() < arr.size(); Parser::incrementIndex()) {
        Command *c;
        if (arr[Parser::getIndex()].empty() || arr[Parser::getIndex()][0] == " ") {
            continue;
        } else if (arr[Parser::getIndex()][1] == "=") {
            c = m_command_map.at(arr[Parser::getIndex()][1]);
        } else {
            c = m_command_map.at(arr[Parser::getIndex()][0]);
        }
        Parser::m_index += c->DoCommand(arr[Parser::getIndex()]);
    }
}

std::string::size_type Parser::getIndex()
{
    return m_index;
}

void Parser::incrementIndex()
{
    Parser::m_index++;
}

void Parser::resetIndex()
{
    Parser::m_index = 0;
}