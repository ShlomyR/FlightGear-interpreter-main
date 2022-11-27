#pragma once

#include <string>
#include <vector>
#include <fstream>



class Lexer 
{
public:
    Lexer(std::string &);
    Lexer(char* src);
    //~Lexer();
    static std::vector<std::vector<std::vector<std::string>>>& getVecVecVec();
    std::vector<std::vector<std::string>> doLexer();
    
private:
    std::vector<std::string> splitByWord(std::string const &, const char Delim);
    std::vector<std::vector<std::string>> pushLinesToVec(std::vector<std::vector<std::string>> const&);
    void printVec(std::vector<std::vector<std::string>> const&);
    static std::vector<std::vector<std::vector<std::string>>> vec_vec_vec_str;

private:
    std::ifstream m_program;
};