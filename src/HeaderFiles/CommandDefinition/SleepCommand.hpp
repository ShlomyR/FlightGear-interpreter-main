#include <iostream>
#include<unistd.h>

#include "../Command.hxx"

void SleepCommand::sleepFunc(std::string val)
{
    std::cout << "\nSleeping for " << val << " seconds" << "\n"; 
    sleep(stoi(val));
}