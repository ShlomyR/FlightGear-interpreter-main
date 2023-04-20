#include "src/hederfiles/FlightGear.hpp"
#include "src/hederfiles/Parser.hpp"
#include "src/hederfiles/Lexer.hpp"

#define PATH "script/Script_test.txt"

int main(int argc, char *argv[]) 
{
    std::string file_name;
    
    if(argc > 1) {
        file_name = argv[1];
    } else {
        file_name = PATH;
    }
    
    Lexer lexer(file_name);
    std::vector<std::vector<std::string>> arr = lexer.doLexer();

    Parser parser;
    parser.parse(arr);

    if (FlightGear::getInstance()->isOpen()) {
        FlightGear::getInstance()->close();
    }
}
