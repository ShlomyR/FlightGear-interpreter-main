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
        //std::vector<std::vector<std::string>>& operator[](std::vector<std::vector<std::string>> index);
        void parse(std::vector<std::vector<std::string>> &);
        static std::vector<std::vector<std::string>> getVecCommand();
        static std::vector<std::vector<std::string>> getVecAll();
        static std::string::size_type getIndex();
        static void incrementIndex();
        void resetIndex();
        std::string::size_type setIndex(std::string::size_type i);
        void setVecCommand(std::vector<std::vector<std::string>> v);
        void resetVecCommand();
    private:
        std::unordered_map<std::string,Command*> command_map;
        static std::vector<std::vector<std::string>> vector_commands;
        static std::vector<std::vector<std::string>> vector_all_lines;
        static std::string::size_type index;
};