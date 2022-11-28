#include <sstream>
#include <iostream>

#include "../HeaderFiles/Lexer.hpp"


std::vector<std::vector<std::vector<std::string>>> Lexer::m_vec_vec_vec_str;


Lexer::Lexer(std::string &src)
{
    m_program.open(src);
}

std::vector<std::vector<std::vector<std::string>>> &Lexer::getVecVecVec()
{
    return m_vec_vec_vec_str;
}

std::vector<std::vector<std::string>> Lexer::doLexer()
{
    std::vector<std::vector<std::string>> main_vector_arr;

    if (!m_program.is_open())
    {
        throw std::runtime_error("file not opened");
    }

    std::string line;
    while (getline(m_program, line))
    {
        std::vector<std::string> vec_words = splitByWord(line, ' ');
        main_vector_arr.push_back(vec_words);
    }
    m_program.close();

    pushLinesToVec(main_vector_arr);

    printVec(main_vector_arr);

    return main_vector_arr;
}

std::vector<std::string> Lexer::splitByWord(std::string const &str, const char Delim)
{
    std::string token;
    std::stringstream stream(str);
    std::vector<std::string> vec_str;

    while (getline(stream, token, Delim))
    {
        // if (token.size() > 0) {
        vec_str.push_back(token);
        //}
    }
    return vec_str;
}

std::vector<std::vector<std::string>> Lexer::pushLinesToVec(std::vector<std::vector<std::string>> const& arr)
{
    std::string str = "";
    std::vector<std::vector<std::string>> vec_vec_str = {};
    std::vector<std::string> vec_words = {};

    for (std::string::size_type i = 0; i < arr.size(); i++)
    {
        for (std::string::size_type j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == "{")
            {
                i++;
                while (arr[i][0] != "}")
                {
                    std::string::size_type temp = 0;
                    int temp_j = 0;
                    while (temp != arr[i].size())
                    {
                        if (arr[i][temp_j].size() > 0) {
                            str += arr[i][temp_j] + " ";
                        }
                        temp_j++;
                        temp++;
                    }
                    vec_words = splitByWord(str, ' ');
                    vec_vec_str.push_back(vec_words);
                    vec_words.clear();
                    str = "";
                    i++;
                }
                m_vec_vec_vec_str.push_back(vec_vec_str);
                vec_vec_str.clear();
                str = "";
            }
        }
    }

    printVec(m_vec_vec_vec_str[0]);
    return vec_vec_str;
}



void Lexer::printVec(std::vector<std::vector<std::string>> const &vec_arr)
{
    for (std::string::size_type i = 0; i < vec_arr.size(); i++)
    {
        std::cout << "[";
        for (std::string::size_type j = 0; j < vec_arr[i].size(); j++)
        {
            std::cout << vec_arr[i][j] << " ";
        }
        std::cout << "]"
                  << "\n";
    }
}