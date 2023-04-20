#include <sstream>
#include <iostream>

#include "../hederfiles/Lexer.hpp"


std::vector<std::vector<std::vector<std::string>>> Lexer::m_while_blocks;
std::vector<std::vector<std::vector<std::string>>> Lexer::m_if_blocks;

std::vector<std::vector<std::vector<std::string>>> &Lexer::get_while_blocks()
{
    return m_while_blocks;
}

std::vector<std::vector<std::vector<std::string>>> &Lexer::get_if_blocks()
{
    return m_if_blocks;
}

Lexer::Lexer(std::string &src)
{
    m_program.open(src);
}

std::vector<std::vector<std::string>> Lexer::doLexer()
{
    std::vector<std::vector<std::string>> lines;

    if (!m_program.is_open()) {
        throw std::runtime_error("file not opened in lexer\n");
    }

    std::string line;
    while (getline(m_program, line)) {
        auto tokens = tokenize_line(line, ' ');
        lines.push_back(tokens);
    }
    m_program.close();

    push_blocks_to_vec(lines);
    print_lines(lines);

    return lines;
}

std::vector<std::string> Lexer::tokenize_line(std::string const &line, const char Delim)
{
    std::vector<std::string> tokens;
    std::stringstream stream(line);
    std::string token;

    while (getline(stream, token, Delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Lexer::push_blocks_to_vec(std::vector<std::vector<std::string>> const& arr)
{
    search_for_block(arr,"while");
    search_for_block(arr,"if");
}

void Lexer::search_for_block(std::vector<std::vector<std::string>> const& arr,std::string const search)
{
    std::vector<std::vector<std::string>> block = {};
    std::vector<std::string> tokens = {};
    std::string str = "";

    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = 0; j < arr[i].size(); j++) {
            if (arr[i][0] == search) {
                i++;
                i++;
                while (arr[i][0] != "}")
                {
                    size_t temp = 0;
                    int temp_j = 0;
                    while (temp != arr[i].size()) {
                        if (arr[i][temp_j].size() > 0) {
                            str += arr[i][temp_j] + " ";
                        }
                        temp_j++;
                        temp++;
                    }
                    tokens = tokenize_line(str, ' ');
                    block.push_back(tokens);
                    tokens.clear();
                    str = "";
                    i++;
                }
                if (search == "while") {
                    m_while_blocks.push_back(block);
                } else if (search == "if") {
                    m_if_blocks.push_back(block);
                } else {
                    throw std::runtime_error("The search term do not exist!");
                }
                block.clear();
                str = "";

            }
        }
    }
}

void Lexer::print_lines(std::vector<std::vector<std::string>> const &vec_arr)
{
    for (std::string::size_type i = 0; i < vec_arr.size(); i++) {
        std::cout << "[";
        for (std::string::size_type j = 0; j < vec_arr[i].size(); j++) {
            std::cout << vec_arr[i][j] << " ";
        }
        std::cout << "]" << "\n";
    }
}