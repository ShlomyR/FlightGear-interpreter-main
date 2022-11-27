#include <sstream>
#include <iostream>


#include "../HeaderFiles/Lexer.hpp"

std::vector<std::vector<std::string>> Lexer::vec_vec_str;

Lexer::Lexer(std::string &src)
{
    //Lexer::vec_vec_str = new std::vector<std::vector<std::string>>();
    m_program.open(src);
}

// Lexer::~Lexer()
// {
//     delete vec_vec_str;
// }

std::vector<std::vector<std::string>>& Lexer::getVecPtr()
{
    return vec_vec_str;
}

std::vector<std::vector<std::string>> Lexer::doLexer()
{
    std::vector<std::vector<std::string>> main_vector_arr;

    if (!m_program.is_open()) {
        throw std::runtime_error("file not opened");
    }

    std::string line;
    while (getline(m_program, line)) {
        std::vector<std::string> vec_words = splitByWord(line,' ');
        main_vector_arr.push_back(vec_words);
    }
    m_program.close();

    pushLinesToQueue(main_vector_arr);

    printVec(main_vector_arr);

    // main_vector_arr = *getVecPtr();
    // printf("\nAFTER-----------------------------------------------------------------\n");
    // printVec(main_vector_arr);

    return main_vector_arr;
}


std::vector<std::string> Lexer::splitByWord(std::string const &str, const char Delim)
{
    std::string token;
    std::stringstream stream(str);
    std::vector<std::string> vec_str;

    while (getline(stream, token, Delim)) {
        //if (token.size() > 0) {
            vec_str.push_back(token);
        //}
    }
    return vec_str;
}


std::vector<std::vector<std::string>> Lexer::pushLinesToQueue(std::vector<std::vector<std::string>> const& arr)
{
    std::string q_str = "";
    std::vector<std::string> vec_str = {};
    //std::vector<std::vector<std::string>> vec_vec_str = {};

    for (std::string::size_type i = 0; i < arr.size(); i++)
    {
        for (std::string::size_type j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == "{")
            {
                // q_str += arr[i][0] + " ";
                // vec_str.push_back(q_str);
                // q_str = "";
                i++;
                while (arr[i][0] != "}")
                {
                    std::string::size_type temp = 0;
                    int jj = 0;
                    while (temp != arr[i].size())
                    {
                        if (arr[i][jj].size() > 0) {
                            q_str += arr[i][jj] + " ";
                        }
                        jj++;
                        temp++;
                    }
                    vec_str.push_back(q_str);
                    q_str = "";
                    i++;
                }
                vec_vec_str.push_back(vec_str);
                vec_str.clear();
                q_str = "";
            }
        }
    }

    printVec(vec_vec_str);
    return vec_vec_str;
}

void Lexer::printVec(std::vector<std::vector<std::string>> const& vec_arr)
{
    for (std::string::size_type i = 0; i < vec_arr.size(); i++) {
        std::cout << "[";
        for (std::string::size_type j = 0; j < vec_arr[i].size(); j++) {
            std::cout << vec_arr[i][j] << " ";
        }
        std::cout << "]" << "\n";
    }
}