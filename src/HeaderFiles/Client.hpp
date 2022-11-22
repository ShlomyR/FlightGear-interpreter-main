#pragma once

#include <string>
#include <vector>

class Client
{  
    public:
        static Client* getInstance();
        void Send(std::string msg);
        void SendVal(std::vector<std::string> &arr,double infix);
        void SendVal(std::vector<std::vector<std::string>> &arr,double infix);
        void SendVal(std::vector<std::string> &arr,std::string val);
        int connectClient(int port,const char* ip);
    private:
        static Client* instance;
        void testinClientConenction();
};

