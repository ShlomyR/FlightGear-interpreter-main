#pragma once

#include <string>
#include <vector>

class WhileLoop
{
public:
    static int whileLoop(std::vector<std::string> const&);
private:
    WhileLoop(const WhileLoop&) = delete;
    WhileLoop& operator=(const WhileLoop&) = delete;
};
