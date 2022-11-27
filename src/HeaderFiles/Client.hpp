#pragma once

#include <string>
#include <vector>

class Client
{  
    public:
        static Client* getInstance();
        void Send(std::string msg);
        void SendVal(std::vector<std::string> &,double infix);
        void SendVal(std::vector<std::string> &,std::string val);
        int connectClient(const int port,const char* ip);
    private:
        static Client* instance;
        void testinClientConenction();
};

