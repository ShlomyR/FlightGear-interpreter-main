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
        static std::string::size_type getIndex();
        static void incrementIndex();
        void resetIndex();
    private:
        std::unordered_map<std::string,Command*> command_map;
        static std::string::size_type index;
};