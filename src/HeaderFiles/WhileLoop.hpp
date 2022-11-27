#pragma once

#include <string>
#include <vector>

class WhileLoop
{
    public:
        static int whileLoop(std::vector<std::string> &);
        static std::string infix_str;
        static std::vector<std::string> copy_line;
    private:
        static void pushToVec(std::vector<std::vector<std::string>> &arr,int i);
};