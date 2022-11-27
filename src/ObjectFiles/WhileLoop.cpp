#include "../HeaderFiles/WhileLoop.hpp"
#include "../HeaderFiles/Parser.hpp"
#include "../HeaderFiles/Lexer.hpp"



// std::string WhileLoop::infix_str;
// std::vector<std::string> WhileLoop::copy_line;

int WhileLoop::whileLoop(std::vector<std::string> &line)
{ 
    Parser parser;
    std::vector<std::vector<std::string>> gg = Lexer::getVecVecVec()[0];
    double val_from_DB;

    while ((val_from_DB = WhileCommand::getVal(line)) < stoi(line[3])) {
        parser.parse(gg);
    }
    printf("\nWhileLoop Parser finished\n");

    while (!gg.empty()) { // or gg = {}
        gg.pop_back();
    }

    Lexer::getVecVecVec().erase(Lexer::getVecVecVec().begin());

    return 0;
}