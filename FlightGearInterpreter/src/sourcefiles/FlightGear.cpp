#include "FlightGear.hpp"

#include <iostream>
#include <cstring>

FlightGear::FlightGear()
{
    m_isOpen = false;
}

FlightGear *FlightGear::getInstance()
{
    static FlightGear instance;
    return &instance;
}

void FlightGear::open()
{
    m_isOpen = true;
    int returnValue = system("fgfs --telnet=socket,in,10,127.0.0.1,5402,tcp --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small");
    if (returnValue == -1) {
        throw std::runtime_error("The return value in 'open' didn't worked");
    }
}

void FlightGear::close()
{
    m_isOpen = false;
    int returnValue = system("\nkill $(pidof fgfs)\r\n ");
    if (returnValue == -1) {
        std::cerr << "Failed to execute command: " << strerror(errno) << std::endl;
    }
}

bool FlightGear::isOpen()
{
    return m_isOpen;
}
