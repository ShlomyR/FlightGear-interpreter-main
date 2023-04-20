#pragma once

#include <string>
#include <vector>
#include <fstream>

class Lexer 
{
public:
    Lexer(std::string &);
    static std::vector<std::vector<std::vector<std::string>>>& get_while_blocks();
    static std::vector<std::vector<std::vector<std::string>>>& get_if_blocks();
    std::vector<std::vector<std::string>> doLexer();
private:
    Lexer(const Lexer&) = delete;
    Lexer& operator=(const Lexer&) = delete;

    std::vector<std::string> tokenize_line(std::string const &, const char Delim);
    void push_blocks_to_vec(std::vector<std::vector<std::string>> const&);
    void print_lines(std::vector<std::vector<std::string>> const&);
    void search_for_block(std::vector<std::vector<std::string>> const&,std::string const);
private:
    static std::vector<std::vector<std::vector<std::string>>> m_while_blocks;
    static std::vector<std::vector<std::vector<std::string>>> m_if_blocks;
    std::ifstream m_program;
};
