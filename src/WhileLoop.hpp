#pragma once

#include <string>
#include <vector>

class WhileLoop
{
private:
    static void pushToVec(std::vector<std::vector<std::string>> &arr,int i);
public:
    static int whileLoop(std::vector<std::vector<std::string>> &arr);
    static std::string infix_str;
    static std::vector<std::vector<std::string>> copy_arr;

};