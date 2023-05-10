#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class FileReader
{
public:
    template <typename T>
    T read_file(const std::string &);
private:
    std::ifstream m_program;
};
