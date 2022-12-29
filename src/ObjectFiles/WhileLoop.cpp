#include "../HeaderFiles/WhileLoop.hpp"
#include "../HeaderFiles/Parser.hpp"
#include "../HeaderFiles/Lexer.hpp"
#include "../HeaderFiles/CheckCondition.hpp"

int WhileLoop::whileLoop(std::vector<std::string> const&line)
{ 
    bool condition = true;
    Parser parser;
    std::vector<std::vector<std::string>> vec_vec_str = Lexer::getVecVecVec()[0];
    
    while ((condition = CheckCondition(line))) {
        parser.parse(vec_vec_str);
    }
    printf("\nWhileLoop Parser finished\n");

    while (!vec_vec_str.empty()) { // or vec_vec_str = {}
        vec_vec_str.pop_back();
    }
    Lexer::getVecVecVec().erase(Lexer::getVecVecVec().begin());
    condition = false;

    return 0;
}