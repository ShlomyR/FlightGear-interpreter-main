#include "../HeaderFiles/WhileLoop.hpp"
#include "../HeaderFiles/Parser.hpp"
#include "../HeaderFiles/Lexer.hpp"


Parser parser;

std::string WhileLoop::infix_str;
std::vector<std::string> WhileLoop::copy_line;

int WhileLoop::whileLoop()
{ 
    std::vector<std::vector<std::string>> vec_all = parser.getVecAll();
    std::vector<std::vector<std::string>> vec_command;
    double val_from_DB;

    int temp_index = parser.getIndex();

    pushToVec(vec_all,temp_index);

 
    while ((val_from_DB = WhileCommand::getVal(vec_all,temp_index)) < stoi(vec_all[temp_index][3])) {
        vec_command = parser.getVecCommand();
        parser.parse(vec_command);
    }
    
    parser.resetIndex();
    parser.resetVecCommand();
    
    printf("\nWhileLoop Parser finished\n");

    return 0;
}

void WhileLoop::pushToVec(std::vector<std::vector<std::string>> &arr,int row)
{
    row++;
    std::vector<std::vector<std::string>> pp = parser.getVecCommand();
    while (arr[row][0] != "}") {
        pp.push_back(arr[row]);
        row++;
    }
    parser.setVecCommand(pp);
    parser.printVec(pp);
}