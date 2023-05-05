#pragma once

#include <string>
#include <vector>

#include "BlockParser.hpp"

class WhileBlockParser : public BlockParser
{
public:
    void parse(std::vector<std::vector<std::string>> &lines) override;
};