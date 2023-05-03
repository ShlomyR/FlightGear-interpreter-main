#pragma once

#include <string>
#include <vector>

class Parser
{
public:
    ~Parser() = default;
    virtual void parse(std::vector<std::vector<std::string>> &lines) = 0;
};