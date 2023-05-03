#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "../hederfiles/StdFileReader.hpp"

std::string StdFileReader::read_file(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}