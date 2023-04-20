#include <iostream>
#include <cctype>

#include "Parser.hpp"


std::string::size_type Parser::m_index;

void Parser::parse(std::vector<std::vector<std::string>> const&arr)
{
    
    for (Parser::getIndex(); Parser::getIndex() < arr.size(); Parser::incrementIndex()) {
        
        if (arr[Parser::getIndex()].empty() || arr[Parser::getIndex()][0] == " ") {//.size() == 0 || arr[Parser::getIndex()].size() == 1) {
            printf("\nWhiteSpace was called+++++++++++++++++++++++++++++\n");
            continue;
        }
        if (arr[Parser::getIndex()][1] == "=") {
            
        }
        else {
           
        }
        std::vector<std::string> line = arr[Parser::getIndex()];
        //Parser::m_index += ;
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