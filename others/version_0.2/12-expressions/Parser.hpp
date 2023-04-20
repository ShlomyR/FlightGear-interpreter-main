#pragma once

#include <string>
#include <vector>
#include <unordered_map>


class Parser
{
    public:
        Parser();
        ~Parser();
        void parse(std::vector<std::vector<std::string>> const&);
    public:
        static std::string::size_type getIndex();
        static void incrementIndex();
        void resetIndex();
    private:
        
        static std::string::size_type m_index;
};