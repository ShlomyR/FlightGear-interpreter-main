#pragma once

#include <string>
#include <vector>
#include <fstream>



class Lexer 
{
public:
    Lexer(std::string &);
    //~Lexer();
    std::vector<std::vector<std::string>> doLexer();
    static std::vector<std::vector<std::string>>& getVecPtr();
    
private:
    std::vector<std::string> splitByWord(std::string const &, const char Delim);
    std::vector<std::vector<std::string>> pushLinesToQueue(std::vector<std::vector<std::string>> const&);
    void printVec(std::vector<std::vector<std::string>> const&);
    static std::vector<std::vector<std::string>> vec_vec_str;

private:
    std::ifstream m_program;
};