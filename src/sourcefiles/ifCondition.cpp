// #include "ifCondition.hpp"
// #include "CheckCondition.hpp"
// #include "Parser.hpp"
// #include "Lexer.hpp"

#include "../hederfiles/ConditionChecker.hpp"
#include "../hederfiles/ifCondition.hpp"
#include "../hederfiles/Parser.hpp"
#include "../hederfiles/Lexer.hpp"



int ifCondition::ifCon(std::vector<std::string> const&line)
{ 
    bool condition = true;
    Parser parser;
    ConditionChecker conditionCheck;
    std::vector<std::vector<std::string>> vec_vec_str = Lexer::get_if_blocks()[0];
    
    if ((condition = conditionCheck.check(line))) {
        parser.parse(vec_vec_str);
    }
    printf("\nifCon Parser finished\n");

    if (condition) {
        while (!vec_vec_str.empty()) { // or vec_vec_str = {}
            vec_vec_str.pop_back();
        } if (line[0] != "if") {
            Lexer::get_if_blocks().erase(Lexer::get_while_blocks().begin());
        } 
        condition = false;
    }

    return 0;
}