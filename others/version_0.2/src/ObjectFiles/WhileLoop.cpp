#include "../HeaderFiles/WhileLoop.hpp"
#include "../HeaderFiles/Parser.hpp"
#include "../HeaderFiles/Lexer.hpp"

int WhileLoop::whileLoop(std::vector<std::string> const&line)
{ 
    Parser parser;
    std::vector<std::vector<std::string>> vec_vec_str = Lexer::getVecVecVec()[0];
    double val_from_DB;

    while ((val_from_DB = WhileCommand::getVal(line)) < stoi(line[3])) {
        parser.parse(vec_vec_str);
    }
    printf("\nWhileLoop Parser finished\n");

    while (!vec_vec_str.empty()) { // or vec_vec_str = {}
        vec_vec_str.pop_back();
    }

    Lexer::getVecVecVec().erase(Lexer::getVecVecVec().begin());

    return 0;
}