#include <iostream>
#include <cctype>

#include "../hederfiles/Parser.hpp"
#include "../hederfiles/Server.hpp"

#include "../hederfiles/OpenServerCommand.hpp"
#include "../hederfiles/ConnectCommand.hpp"
#include "../hederfiles/VerCommand.hpp"
#include "../hederfiles/EqualMapCommand.hpp"
#include "../hederfiles/IfCommand.hpp"
#include "../hederfiles/WhileCommand.hpp"
#include "../hederfiles/SleepCommand.hpp"
#include "../hederfiles/PrintCommand.hpp"
#include "../hederfiles/BreakCommand.hpp"

Parser::Parser()
{
    createCommandMap();
}

std::string::size_type Parser::m_index;

void Parser::parse(std::vector<std::vector<std::string>> const&arr)
{
    Parser::resetIndex();
    for (Parser::getIndex(); Parser::getIndex() < arr.size(); Parser::incrementIndex()) {
        std::shared_ptr<Command> c;
        if (arr[Parser::getIndex()].empty() || arr[Parser::getIndex()][0] == " "|| arr[Parser::getIndex()][0] == "}" || arr[Parser::getIndex()][0] == "{") {
            continue;
        } else if (arr[Parser::getIndex()][1] == "++") {
            c = m_command_map.at(arr[Parser::getIndex()][1]);
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

void Parser::createCommandMap() {
    m_command_map["openDataServer"] = std::make_unique<OpenServerCommand>();
    m_command_map["connect"] = std::make_shared<ConnectCommand>();
    m_command_map["var"] = std::make_shared<VerCommand>();
    m_command_map["="] = std::make_shared<EqualMapCommand>();
    m_command_map["if"] = std::make_shared<IfCommand>();
    m_command_map["while"] = std::make_shared<WhileCommand>();
    m_command_map["sleep"] = std::make_shared<SleepCommand>();
    m_command_map["print"] = std::make_shared<PrintCommand>();
    m_command_map["break"] = std::make_shared<BreakCommand>();
}
