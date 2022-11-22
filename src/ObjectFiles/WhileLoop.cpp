#include "../HeaderFiles/WhileLoop.hpp"
#include "../HeaderFiles/Parser.hpp"


Parser parser;

std::string WhileLoop::infix_str;
std::vector<std::string> WhileLoop::copy_line;

int WhileLoop::whileLoop()
{ 
    double val_from_DB;

    int temp_index = Parser::index;

    pushToVec(Parser::vector_all_lines,temp_index);
 
    while ((val_from_DB = WhileCommand::getVal(Parser::vector_all_lines,temp_index)) < stoi(Parser::vector_all_lines[temp_index][3])) {
        parser.parse(parser.vector_commands);
    }
    parser.vector_commands.clear();

    parser.index = 0;
    
    printf("\nWhileLoop Parser finished\n");

    return 0;
}

void WhileLoop::pushToVec(std::vector<std::vector<std::string>> &arr,int row)
{
    row++;
    while (arr[row][0] != "}") {
        parser.vector_commands.push_back(arr[row]);
        row++;
    }
}