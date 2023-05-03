// #include "ifCondition.hpp"
// #include "CheckCondition.hpp"
// #include "Parser.hpp"
// #include "Lexer.hpp"

#include "../hederfiles/ConditionChecker.hpp"
#include "../hederfiles/StdFileReader.hpp"
#include "../hederfiles/LinesPointer.hpp"
#include "../hederfiles/ifCondition.hpp"
#include "../hederfiles/Parse.hpp"
#include "../hederfiles/Lexer.hpp"



void ifCondition::ifCon(std::vector<std::string> const&line)
{
    size_t tmp_lines_ptr = LinesPointer::getIndex()+2;
    bool condition = true;
    Parse parser;
    ConditionChecker conditionCheck;

    std::vector<std::vector<std::string>> if_block = Lexer::get_if_blocks()[0];
    
    if ((condition = conditionCheck.check(line))) {
        parser.parse(if_block);
    }

    tmp_lines_ptr += if_block.size();
    printf("\nifCon Parser finished\n");

    if (condition) {
        while (!if_block.empty()) { // or if_block = {}
            if_block.pop_back();
        }
    }
    Lexer::get_if_blocks().erase(Lexer::get_if_blocks().begin());
    LinesPointer::setIndex(tmp_lines_ptr);

    condition = false;
}