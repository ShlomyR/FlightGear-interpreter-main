#pragma once

#include <memory>
#include <string>
#include <vector>

#include "../hederfiles/Interfaces/Token.hxx"

class Tokenizer
{
public:
    std::vector<std::shared_ptr<Token>> tokenize(const std::string &) const;
};
