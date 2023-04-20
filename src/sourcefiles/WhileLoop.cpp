#include "../hederfiles/ConditionChecker.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/WhileLoop.hpp"
#include "../hederfiles/Parser.hpp"
#include "../hederfiles/Lexer.hpp"

#include <iostream>

int WhileLoop::whileLoop(std::vector<std::string> const&line)
{ 
    bool condition = true;
    bool breakLoop = false;
    Parser parser;
    ConditionChecker conditionCheck;
    std::vector<std::vector<std::string>> vec_vec_str = Lexer::get_while_blocks()[0];
    
    while ((condition = conditionCheck.check(line))) {
        if (breakLoop) {
            break;
        }
        parser.parse(vec_vec_str);
        breakLoop = SymbolVar::getInstance()->getMapStr().at("breakLoop") == "true";
    }
    printf("\nWhileLoop Parser finished\n");

    while (!vec_vec_str.empty()) { // or vec_vec_str = {}
        vec_vec_str.pop_back();
    }
    Lexer::get_while_blocks().erase(Lexer::get_while_blocks().begin());
    condition = false;

    return 0;
}