#pragma once

#include <string>
#include <vector>

#include "../hederfiles/Parser/BlockParser.hpp"

class IfBlockParser : public BlockParser
{
public:
    void parse(std::vector<std::vector<std::string>> &) override;
};