#pragma once

#include <string>
#include <vector>

class FileReader
{
public:
    virtual std::string read_file(const std::string &filename) = 0;
};