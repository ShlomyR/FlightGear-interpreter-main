#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "Command.hxx"

class Parser
{
public:
    Parser();
    void parse(std::vector<std::vector<std::string>> const&);
public:
    static std::string::size_type getIndex();
    static void incrementIndex();
    void resetIndex();
private:
    Parser(const Parser&) = delete;
    Parser& operator=(const Parser&) = delete;

    void createCommandMap();
private:
    std::unordered_map<std::string,std::shared_ptr<Command>> m_command_map;
    static std::string::size_type m_index;
};
