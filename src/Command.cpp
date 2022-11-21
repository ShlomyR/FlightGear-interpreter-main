#include<unistd.h>

#include "Server.hpp"
#include "Variable.hpp"
#include "SymbleVar.hpp"
#include "ShuntingYardToken.hpp"
#include "Command.hpp"
#include "WhileLoop.hpp"
#include "Client.hpp"


int OpenServerCommand::DoCommand(std::vector<std::string> &line)
{
    printf("Server Command\n");
    
    int port;
    
    port = stoi(line[1]);
    
    Server::getInstance()->connectServer(port);
    
    return 0;
}

int ConnectCommand::DoCommand(std::vector<std::string> &line)
{
    

    string ip;
    int port;
   
    ip = line[1];
    port = stoi(line[2]);

    printf("Connecting the client to the FS...\n");

    Client::getInstance()->connectClient(port,ip.c_str());

    return 0;
}

int VerCommand::DoCommand(std::vector<std::string> &line)
{
    
    std::vector<std::string> var_arr;
    
    for (std::string::size_type i = 1; i < line[Parser::index].size(); i++)
    {
        var_arr.push_back(line[i]);
    }
    Variable::getInstance()->createVar(var_arr);
    
    return 0;
}

int EqualMapCommand::DoCommand(std::vector<std::string> &line)
{
    if (line[Parser::index].size() == 3)
    {
        Client::getInstance()->SendVal(line,line[2]);
    }
    else
    {
        //updateFromDB(line);
    }

    return 0;
}

void EqualMapCommand::updateFromDB(std::vector<std::vector<std::string>> &arr)
{
    convertFromChToNum(arr);
    
    strToInfix(Parser::index);

    checkMinus();
    
    
    double infix = ShuntingYardToken::shuntingYardF(WhileLoop::infix_str);

    Client::getInstance()->SendVal(arr,infix);
    
    WhileLoop::infix_str.clear();
}

void EqualMapCommand::convertFromChToNum(std::vector<std::vector<std::string>> &arr)
{
    WhileLoop::copy_arr = arr;
    
    for (std::string::size_type i = 0; i < arr[Parser::index].size(); i++)
    {
        for (std::string::size_type j = 0; j < Variable::getInstance()->vec_all_vars.size(); j++)
        {
            if (arr[Parser::index][i] == Variable::getInstance()->vec_all_vars[j] && arr[Parser::index][0] != Variable::getInstance()->vec_all_vars[j])
            {
                if (arr[Parser::index][i] == "h0")
                {
                    double d = SymbolVar::getInstance()->data_base.at(WhileLoop::copy_arr[Parser::index][i]);
                    int dtoi = d;
                    std::string s = to_string(dtoi);
                    WhileLoop::copy_arr[Parser::index][i] = s;
                    
                }
                else
                {
                    double d = SymbolVar::getInstance()->data_base.at(Variable::getInstance()->base_map_DB.at(WhileLoop::copy_arr[Parser::index][i]));
                    int dtoi = d;
                    std::string s = to_string(dtoi);
                    WhileLoop::copy_arr[Parser::index][i] = s;
                    
                }
            }
        }
    }
}

void EqualMapCommand::strToInfix(string::size_type i)
{
    string str_push_to_vec;

    for (string::size_type j = 0; j < WhileLoop::copy_arr[i].size() - 2; j++)
    {
        str_push_to_vec += WhileLoop::copy_arr[i][j + 2];
    }
    WhileLoop::infix_str = str_push_to_vec;
    str_push_to_vec.clear();
}

void EqualMapCommand::checkMinus()
{
    if (WhileLoop::infix_str[0] == '-' && WhileLoop::infix_str[1] == '-' )
    {
        WhileLoop::infix_str.erase(WhileLoop::infix_str.begin()+1) ;
        WhileLoop::infix_str[0] = '+';
    }
}

int WhileCommand::DoCommand(std::vector<std::string> &line)
{
    
    int skip_row = skipRows(line,Parser::index);
    
    // WhileLoop::whileLoop(line);
    
    return skip_row;
}

int WhileCommand::skipRows(std::vector<std::string> &arr,int index)
{ 
    int i = index+1;
    
    while (arr[0] != "}")
    {
        i++;    
    }
    cout << "\nHow meany rows to skip : " << i - index -1 << "\n";
    
    return i;  
}

double WhileCommand::getVal(std::vector<std::vector<std::string>> &arr,int index)
{
    string path = Variable::getInstance()->base_map_DB.at(arr[index][1]);

    double val = SymbolVar::getInstance()->data_base.at(path);

    return val;
}

int SleepCommand::DoCommand(std::vector<std::string> &line)
{
    
    sleepFunc(line[1]);

    return 0;
}

void SleepCommand::sleepFunc(string val)
{
    cout << "\nSleeping for " << val << " seconds" << "\n"; 
    sleep(stoi(val));
}

int PrintCommand::DoCommand(std::vector<std::string> &line)
{
    if (line.size() > 2)
    {
        string val = " "; 
        for (string::size_type i = 1; i < line.size(); i++)
        {
            val+=  line[i]+" ";

        }
        cout << "\n" << val << "\n";
         
    }
    else
    {
        printFunc(line[1]);
    }
    
    return 0;
}

void PrintCommand::printFunc(string val)
{
    string val_name = val;

    for (string::size_type i = 0; i < Variable::getInstance()->vec_all_vars.size(); i++)
    {
        if (val == Variable::getInstance()->vec_all_vars[i])
        {
            double val_d = SymbolVar::getInstance()->data_base.at(Variable::getInstance()->base_map_DB.at(val));
            cout << val_name << ": " << val_d << "\n";
        }
    }
    if (val[0] == '"')
    {    
        cout << "\n" << val << "\n";   
    }

}