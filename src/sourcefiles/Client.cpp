#include <arpa/inet.h>
#include <iostream>

#include "../hederfiles/Client.hpp"
#include "../hederfiles/Parser.hpp"
#include "../hederfiles/SymbolVar.hpp"


Client* Client::getInstance()
{
    static Client instance;
    return &instance;
}

int sock = 0, valread;
std::string Set = "set";
std::string Activate = "\r\n";

int Client::connectClient(const int port,const char* ip)
{
	struct sockaddr_in serv_addr; 
	
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        printf("\n Socket creation error \n"); 
        return 0; 
    } 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(port); 

    if(inet_pton(AF_INET, ip, &serv_addr.sin_addr)<=0) { 
        printf("\nInvalid address/ Address not supported \n"); 
        return 0; 
    } 

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
        printf("\nConnection Failed \n"); 
        return 0; 
    }
    return 0;
}

void Client::Send(std::string const& msg)
{
	send(sock , msg.c_str() , msg.length() , 0 );

    std::cout << msg << "\n"; 
}

void Client::SendVal(std::vector<std::string> const&line,double infix)
{
    std::string val = std::to_string(infix);

   Client::getInstance()->Send(Set + " " + SymbolVar::getInstance()->getMapStr().at(line[0]) + " " + val + Activate);  
}

void Client::SendVal(std::vector<std::string> const&line,std::string val)
{
   Client::getInstance()->Send(Set + " " + SymbolVar::getInstance()->getMapStr().at(line[0]) + " " + val + Activate);
}

void Client::testinClientConenction()
{ 
	Client::getInstance()->Send(Set + " controls/flight/rudder 1" + Activate);
}