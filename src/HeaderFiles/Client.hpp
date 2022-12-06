#pragma once

#include <string>
#include <vector>

class Client
{  
public:
    static Client* getInstance();
    int connectClient(const int port,const char* ip);
    void Send(std::string const&);
    void SendVal(std::vector<std::string> const&,double infix);
    void SendVal(std::vector<std::string> const&,std::string val);
private:
    static Client* instance;
    void testinClientConenction();
};

