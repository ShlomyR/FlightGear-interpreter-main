#include "../hederfiles/ConditionChecker.hpp"
#include "../hederfiles/StdFileReader.hpp"
#include "../hederfiles/LinesPointer.hpp"
#include "../hederfiles/MapException.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/WhileLoop.hpp"
#include "../hederfiles/Parse.hpp"
#include "../hederfiles/Lexer.hpp"

#include <iostream>

void WhileLoop::whileLoop(std::vector<std::string> const&line)
{
    size_t tmp_lines_ptr = LinesPointer::getIndex()+2;
    bool condition = true;
    bool breakLoop = false;
    Parse parser;
    ConditionChecker conditionCheck;
    std::vector<std::vector<std::string>> while_block = Lexer::get_while_blocks()[0];
    
    while ((condition = conditionCheck.check(line))) {
        if (breakLoop) {
            break;
        }
        parser.parse(while_block);
        std::string val = "";
        try {
            if (SymbolVar::getInstance()->getMapStr().count("breakLoop")) {
                breakLoop = SymbolVar::getInstance()->getMapStr().at("breakLoop") == "true";
            } else {
                throw MapException("Error: " + std::string("breakLoop") + " not found in map_strDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
            }
        } catch (const MapException& me) {
            std::cout << me.what() << " at line " << me.where() << "\n";
        }
    }

    tmp_lines_ptr += while_block.size();
    printf("\nWhileLoop Parser finished\n");

    while (!while_block.empty()) { // or while_block = {}
        while_block.pop_back();
    }
    Lexer::get_while_blocks().erase(Lexer::get_while_blocks().begin());
    LinesPointer::setIndex(tmp_lines_ptr);

    condition = false;
}