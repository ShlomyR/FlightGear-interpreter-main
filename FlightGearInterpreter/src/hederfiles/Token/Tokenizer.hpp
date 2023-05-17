#pragma once

#include "Token.hxx"

#include <memory>
#include <string>
#include <vector>

class Tokenizer
{
public:
    std::vector<std::shared_ptr<Token>> tokenize(const std::string &) const;
};
