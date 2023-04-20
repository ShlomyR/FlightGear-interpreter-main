#include <iostream>
#include <vector>
#include <string>

//#include "Expression.hpp"
#include "Lexer.hpp"
//#include "Parser.hpp"


int main()
{
    //Parser parse;
    std::string s = "24 + 25 / 2 - 1 + 6 ** 3";
    Lexer lexer(s);
    std::vector<std::string>  tokens = lexer.doLexer();

    // auto rpn = makeRpn(tokens);

    // Express* tree = parse(rpn);

    // tree->value();
    // tree->print();

    return 0;
}