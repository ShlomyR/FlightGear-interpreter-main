#include <arpa/inet.h>

#include "../hederfiles/Socket.hpp"

int Socket::createSocket() {
    return socket(AF_INET, SOCK_STREAM, 0);
}

int Socket::connectToServer(int sockfd, const int port, const char* ip) {
    struct sockaddr_in serv_addr; 
	
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(port); 

    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) { 
        printf("\nInvalid address/ Address not supported \n"); 
        return 0; 
    } 

    return connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
}

int Socket::sendMsg(int sockfd, std::string const& msg) {
    return send(sockfd , msg.c_str() , msg.length() , 0 );
}
