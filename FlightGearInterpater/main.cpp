#include "FlightGear.hpp"
#include "Lexer.hpp"
#include "Parse.hpp"

#define PATH "scripts/Script.txt"

int main(int argc, char *argv[])
{
    std::string file_name;

    if(argc > 1) {
        file_name = argv[1];
    } else {
        file_name = PATH;
    }

    Lexer lexer(file_name);
    auto Lines_blocks = lexer.tokenize_file();

    Parse parse;
    parse.parse(Lines_blocks);

    if (FlightGear::getInstance()->isOpen()) {
        FlightGear::getInstance()->close();
    }

    return 0;
}
