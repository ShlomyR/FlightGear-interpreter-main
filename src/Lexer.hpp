#pragma once

#include <string>
#include <vector>
#include <fstream>


class Lexer 
{
public:
    Lexer(std::string &);
    std::vector<std::vector<std::string>> doLexer();
    
private:
    std::vector<std::string> splitByWord(std::string const &, const char Delim);
    void printVec(std::vector<std::vector<std::string>> &);

private:
    std::ifstream m_program;
};