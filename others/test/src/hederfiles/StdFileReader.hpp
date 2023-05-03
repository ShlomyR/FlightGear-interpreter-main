#pragma once

#include <string>
#include <vector>

#include "FileReader.hxx"

class StdFileReader : public FileReader
{
public:
    std::string read_file(const std::string &filename) override;
};