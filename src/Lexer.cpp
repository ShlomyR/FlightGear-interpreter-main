#include <sstream>
#include <iostream>

#include "Lexer.hpp"

Lexer::Lexer(std::string& src)
{
    m_program.open(src);
}

std::vector<std::vector<std::string>> Lexer::doLexer()
{
    std::vector<std::vector<std::string>> main_vector_arr;
    std::vector<std::string> vec_str;

    if (!m_program.is_open()) {
        throw std::runtime_error("file not opened");
    }

    std::string line;
    while (getline(m_program, line)) {
        std::vector<std::string> vec_words = splitByWord(line,' ');
        main_vector_arr.push_back(vec_str);
    }
    m_program.close();

    printVec(main_vector_arr);

    return main_vector_arr;
}


std::vector<std::string> Lexer::splitByWord(std::string const &str, const char Delim)
{
    std::string token;
    std::stringstream stream(str);
    std::vector<std::string> vec_str;

    while (getline(stream, token, Delim)) {
        if (token.size() > 0) {
            vec_str.push_back(token);
        }
    }
    return vec_str;
}

void Lexer::printVec(std::vector<std::vector<std::string>> &vec_arr)
{
    for (std::string::size_type i = 0; i < vec_arr.size(); i++) {
        std::cout << "[";
        for (std::string::size_type j = 0; j < vec_arr[i].size(); j++) {
            std::cout << vec_arr[i][j] << " ";
        }
        std::cout << "]" << "\n";
    }
}