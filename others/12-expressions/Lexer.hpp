#pragma once

#include <string>
#include <vector>



class Lexer
{
    public:
        Lexer(std::string &);
        std::vector<std::string> doLexer();
        std::string convert(std::string infix);
        int priority(char alpha);
    private:
        std::string m_infix;
};