#pragma once

class TcpServer {
public:
    static TcpServer *getInstance();
    ~TcpServer();

    bool socket();
    bool bind();
    bool listen(int);
    bool accept();
    bool close();
    int getClientSocket();
    void setPort(int);
    int getPort();
private:
    TcpServer();
private:
    int m_port;
    int m_serverSocket;
    int m_clientSocket;
};
