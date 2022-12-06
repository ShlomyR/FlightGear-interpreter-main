#include "../HeaderFiles/Parser.hpp"
#include "../HeaderFiles/Lexer.hpp"
#include "../HeaderFiles/Server.hpp"

#define PATH "script/Script.txt"

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

    Server::getInstance()->endFG();
}
