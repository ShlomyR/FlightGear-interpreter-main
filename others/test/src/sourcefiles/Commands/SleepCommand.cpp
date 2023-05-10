#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>

#include "../hederfiles/Commands/SleepCommand.hpp"

void SleepCommand::DoCommand(std::vector<std::string> const&line)
{
    sleepFunc(line[1]);
}

void SleepCommand::sleepFunc(std::string val)
{
    std::cout << "\nSleeping for " << val << " seconds" << "\n"; 
    sleep(stoi(val));
}