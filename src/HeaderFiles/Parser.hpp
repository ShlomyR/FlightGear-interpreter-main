#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "Command.hpp"

class Parser
{
public:
    Parser();
    ~Parser(); 
    void parse(std::vector<std::vector<std::string>> &);
    static std::vector<std::vector<std::string>> getVecCommand();
    static std::vector<std::vector<std::string>> getVecAll();
    static std::string::size_type getIndex();
    void incrementIndex(){
        index++;
    }
    void resetIndex()
    {
        index = 0;
    }
    void setIndex()
    {
        index = 0;
    }
    void setVecCommand(std::vector<std::vector<std::string>> v)
    {
        vector_commands = v;
    }
    void resetVecCommand()
    {
        vector_commands = {};
    }
    void printVec(std::vector<std::vector<std::string>> const&);
private:
    std::unordered_map<std::string,Command*> command_map;
    static std::vector<std::vector<std::string>> vector_commands;
    static std::vector<std::vector<std::string>> vector_all_lines;
    static std::string::size_type index;
};