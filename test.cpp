// #include <iostream>
// #include <thread>
// #include <vector>
// #include <memory>
// #include <stdexcept>
// #include <cstring>
// #include <netinet/in.h>
// #include <sys/socket.h>
// #include <unistd.h>

// // Socket interface to abstract away the details of socket creation and manipulation
// class Socket
// {
// public:
//     virtual ~Socket() = default;
//     virtual void bind(int port) = 0;
//     virtual void listen() = 0;
//     virtual int accept() = 0;
//     virtual ssize_t read(int socket, void *buf, size_t len) = 0;
//     virtual void close(int socket) = 0;
//     virtual bool isOpen() = 0;
// };

// // Concrete implementation of the Socket interface using Linux system calls
// class LinuxSocket : public Socket
// {
// public:
//     LinuxSocket()
//         : fd(-1)
//     {
//         fd = socket(AF_INET, SOCK_STREAM, 0);
//         if (fd == -1)
//         {
//             throw std::runtime_error("Failed to create socket");
//         }
//         int optval = 1;
//         if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1)
//         {
//             throw std::runtime_error("Failed to set socket options");
//         }
//     }

//     virtual ~LinuxSocket()
//     {
//         if (fd != -1)
//         {
//             close(fd);
//         }
//     }

//     void bind(int port) override
//     {
//         sockaddr_in addr = {0};
//         addr.sin_family = AF_INET;
//         addr.sin_port = htons(port);
//         addr.sin_addr.s_addr = INADDR_ANY;
//         if (::bind(fd, (sockaddr *)&addr, sizeof(addr)) == -1)
//         {
//             throw std::runtime_error("Failed to bind socket");
//         }
//     }

//     void listen() override
//     {
//         if (::listen(fd, 10) == -1)
//         {
//             throw std::runtime_error("Failed to listen on socket");
//         }
//     }

//     int accept() override
//     {
//         int clientfd = ::accept(fd, NULL, NULL);
//         if (clientfd == -1)
//         {
//             throw std::runtime_error("Failed to accept client connection");
//         }
//         return clientfd;
//     }

//     ssize_t read(int socket, void *buf, size_t len) override
//     {
//         return ::read(socket, buf, len);
//     }

//     void close(int socket) override
//     {
//         ::close(socket);
//     }

//     bool isOpen() override
//     {
//         if (fd >= 0)
//         {
//             return true;
//         }
//         return false;
//     }

// private:
//     int fd;
// };

// // Interface for server event listeners
// class ServerListener
// {
// public:
//     virtual ~ServerListener() {}
//     virtual void onClientConnected(int clientfd) = 0;
//     virtual void onClientDisconnected(int clientfd) = 0;
//     virtual void onDataReceived(int clientfd, const char *data, size_t len) = 0;
// };

// // ClientHandler class responsible for accepting client connections and reading data from the client socket
// class ClientHandler
// {
// public:
//     ClientHandler(Socket &socket, std::vector<std::unique_ptr<ServerListener>> &listeners)
//         : socket(socket), listeners(listeners)
//     {
//     }

//     void operator()()
//     {
//         while (true)
//         {
//             int clientfd = socket.accept();
//             for (auto &listener : listeners)
//             {
//                 listener->onClientConnected(clientfd);
//             }
//             char buffer[1024];
//             ssize_t numBytesRead;
//             while ((numBytesRead = socket.read(clientfd, buffer, sizeof(buffer))) > 0)
//             {
//                 for (auto &listener : listeners)
//                 {
//                     listener->onDataReceived(clientfd, buffer, numBytesRead);
//                 }
//             }
//             for (auto &listener : listeners)
//             {
//                 listener->onClientDisconnected(clientfd);
//             }
//             // Close the client socket when the data reading loop has finished
//             socket.close(clientfd);
//         }
//     }

// private:
//     Socket &socket;
//     std::vector<std::unique_ptr<ServerListener>> &listeners;
// };

// // Server class responsible for starting the server, accepting client connections, and notifying listeners of events
// class Server
// {
// public:
//     Server(int port)
//         : m_socket(std::make_unique<LinuxSocket>()), m_port(port)
//     {
//     }
//     void addListener(ServerListener *listener)
//     {
//         m_listeners.emplace_back(listener);
//     }

//     void start()
//     {
//         m_socket->bind(m_port);
//         m_socket->listen();
//         std::cout << "Server listening on port " << m_port << std::endl;

//         while (true)
//         {
//             m_clientfd = m_socket->accept();
//             std::cout << "Client connected on socket " << m_clientfd << std::endl;
//             std::thread handlerThread(ClientHandler(*m_socket, m_listeners));
//             handlerThread.detach();
//             close();
//         }
//     }

//     void close()
//     {
//         m_socket->close(m_clientfd);
//     }

//     bool isOpen()
//     {
//         return m_socket->isOpen();
//     }

// private:
//     std::unique_ptr<Socket> m_socket;
//     std::vector<std::unique_ptr<ServerListener>> m_listeners;
//     int m_port;
//     int m_clientfd;
// };

// // Example server listener implementation that simply prints messages to the console
// class ConsoleServerListener : public ServerListener
// {
// public:
//     virtual void onClientConnected(int clientfd)
//     {
//         std::cout << "Client connected on socket " << clientfd << std::endl;
//     }
//     virtual void onClientDisconnected(int clientfd)
//     {
//         std::cout << "Client disconnected from socket " << clientfd << std::endl;
//     }

//     virtual void onDataReceived(int clientfd, const char *data, size_t len)
//     {
//         std::cout << "Received " << len << " bytes from client on socket " << clientfd << ": " << data << std::endl;
//     }
// };

// // int main()
// // {
// //     // Create a server and add a console listener
// //     Server server(5050);
// //     server.addListener(new ConsoleServerListener());

// //     // Start the server
// //     server.start();

// //     if (server.isOpen()) {
// //         server.close();
// //     }

// //     return 0;
// // }

// class Server
// {
// public:
//     virtual ~Server() = default;
//     virtual void open(int port, ClientHandler &c) = 0;
//     virtual void close() = 0;
// };

// class MySerialServer : public Server
// {
// public:
//     virtual void open(int port, ClientHandler *ch) override;
//     virtual void close() override;

// private:
//     void run(int port, ClientHandler *ch);
// };

// class ClientHandler
// {
// public:
//     virtual ~ClientHandler() = default;
//     virtual void handleClient(std::istream &inputStream, std::ostream &outputStream) = 0;
// };

// class CacheManager
// {
// public:
//     virtual bool isSolutionExists(const std::string &problem) = 0;
//     virtual std::string getSolution(const std::string &problem) = 0;
//     virtual void saveSolution(const std::string &problem, const std::string &solution) = 0;
// };

// class FileCacheManager : public CacheManager
// {
// public:
//     bool isSolutionExists(const std::string &problem) override
//     {
//     }
//     std::string getSolution(const std::string &problem) override
//     {
//     }
//     void saveSolution(const std::string &problem, const std::string &solution) override
//     {
//     }
// };

// class Solver
// {
// public:
//     virtual std::string solve(Problem *problem, Solution *solution) = 0;
// };

// class Problem
// {
// public:
//     virtual ~Problem() = default;
// };

// class Solution
// {
// public:
//     virtual ~Solution() = default;
// };

// class MyTestClientHandler : public ClientHandler
// {
// public:
//     MyTestClientHandler(Solver *s, CacheManager *c)
//         : m_solver(s), m_cacheManager(c)
//     {
//     }

//     void handleClient(std::istream &inputStream, std::ostream &outputStream) override
//     {
//     }

// private:
//     Solver *m_solver;
//     CacheManager *m_cacheManager;
// };

// continue please : please implement those classes in cpp, it supose to mainaned a server and execute the incoming clientes(from the ClientHandler) one by on in the order they came in, the solver shuled handel a given problom like a matematic calcolation in the Problem class interface ang give a sulotion using the Sulotion interface, and chacheManager check if a sulotion exist in a file or not in O(1) if exist return the sulotion if not use the sulotion to calculate taht using an Expration class using shunting yard algorithem and make it to folow SOLID principle please. : class Server
// {
// public:
//     virtual ~Server() = default;
//     virtual void open(int port, ClientHandler &c) = 0;
//     virtual void close() = 0;
// };

// class MySerialServer : public Server
// {
// public:
//     virtual void open(int port, ClientHandler *ch) override;
//     virtual void close() override;

// private:
//     void run(int port, ClientHandler *ch);
// };

// class ClientHandler
// {
// public:
//     virtual ~ClientHandler() = default;
//     virtual void handleClient(std::istream &inputStream, std::ostream &outputStream) = 0;
// };

// class CacheManager
// {
// public:
//     virtual bool isSolutionExists(const std::string &problem) = 0;
//     virtual std::string getSolution(const std::string &problem) = 0;
//     virtual void saveSolution(const std::string &problem, const std::string &solution) = 0;
// };

// class FileCacheManager : public CacheManager
// {
// public:
//     bool isSolutionExists(const std::string &problem) override
//     {
//     }
//     std::string getSolution(const std::string &problem) override
//     {
//     }
//     void saveSolution(const std::string &problem, const std::string &solution) override
//     {
//     }
// };

/*


class Solver {
public:
    virtual std::string solve(Problem *problem, Solution *solution) = 0;
};

class Problem
{
public:
    virtual ~Problem() = default;
};

class Solution
{
public:
    virtual ~Solution() = default;
};


class MyTestClientHandler : public ClientHandler {
public:
    MyTestClientHandler(Solver* s, CacheManager* c)
    : m_solver(s)
    , m_cacheManager(c)
    {}

    void handleClient(std::istream& inputStream, std::ostream& outputStream) override
    {

    }
private:
    Solver* m_solver;
    CacheManager* m_cacheManager;
};
Here's an implementation of the classes you requested in C++:

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

class Problem {
public:
    virtual ~Problem() = default;
};

class Solution {
public:
    virtual ~Solution() = default;
};

class Solver {
public:
    virtual std::string solve(Problem* problem, Solution* solution) = 0;
};

class ExpressionProblem : public Problem {
public:
    explicit ExpressionProblem(const std::string& exp)
        : m_expression(exp)
    {}

    const std::string& getExpression() const {
        return m_expression;
    }
private:
    std::string m_expression;
};

class ExpressionSolution : public Solution {
public:
    explicit ExpressionSolution(const std::string& sol)
        : m_solution(sol)
    {}

    const std::string& getSolution() const {
        return m_solution;
    }
private:
    std::string m_solution;
};

class ExpressionSolver : public Solver {
public:
    std::string solve(Problem* problem, Solution* solution) override {
        auto* expProblem = dynamic_cast<ExpressionProblem*>(problem);
        auto* expSolution = dynamic_cast<ExpressionSolution*>(solution);
        if (expProblem && expSolution) {
            const std::string& expression = expProblem->getExpression();
            std::string& solutionStr = expSolution->getSolution();
            if (m_cacheManager->isSolutionExists(expression)) {
                solutionStr = m_cacheManager->getSolution(expression);
            } else {
                solutionStr = evaluate(expression);
                m_cacheManager->saveSolution(expression, solutionStr);
            }
            return solutionStr;
        }
        return "";
    }

    explicit ExpressionSolver(CacheManager* cacheManager) : m_cacheManager(cacheManager) {}

private:
    CacheManager* m_cacheManager;

    int precedence(char op) {
        switch(op) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
        }
        return 0;
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    std::string evaluate(const std::string& expression) {
        std::stringstream ss(expression);
        std::string token;
        std::stack<std::string> output;
        std::stack<char> operators;
        while (ss >> token) {
            if (token == "(") {
                operators.push('(');
            } else if (token == ")") {
                while (operators.top() != '(') {
                    char op = operators.top();
                    operators.pop();
                    std::string right = output.top();
                    output.pop();
                    std::string left = output.top();
                    output.pop();
                    std::string result = evaluateBinary(left, right, op);
                    output.push(result);
                }
                operators.pop();
            } else if (isOperator(token[0])) {
                while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(token[0])) {
                    char op = operators.top();
                    operators.pop();
                    std::string right = output.top();
                    output.pop();
                    std::string left = output.top();
                    output.pop();
                    std::string result = evaluateBinary(left, right, op);
                    output.push(result);
                }
                operators.push(token[0]);
            } else {
                output.push(token);
            }
        }
        while (!operators.empty()) {
            char op = operators.top();
            operators.pop();
            std::string right = output.top();
            output.pop();
            std
*/

// #include <iostream>
// #include <string>
// #include <stack>
// #include <unordered_map>
// #include <fstream>
// #include <sstream>

// class ClientHandler;
// class CacheManager;
// class Solver;
// class Problem;
// class Solution;
// class Expression;

// class Server
// {
// public:
//     virtual ~Server() = default;
//     virtual void open(int port, ClientHandler *c) = 0;
//     virtual void close() = 0;
// };

// class MySerialServer : public Server
// {
// public:
//     void open(int port, ClientHandler *ch) override;
//     void close() override;

// private:
//     void run(int port, ClientHandler *ch);
// };

// class ClientHandler
// {
// public:
//     virtual ~ClientHandler() = default;
//     virtual void handleClient(std::istream &inputStream, std::ostream &outputStream) = 0;
// };

// class CacheManager
// {
// public:
//     virtual bool isSolutionExists(const std::string &problem) = 0;
//     virtual std::string getSolution(const std::string &problem) = 0;
//     virtual void saveSolution(const std::string &problem, const std::string &solution) = 0;
// };

// class FileCacheManager : public CacheManager
// {
// public:
//     bool isSolutionExists(const std::string &problem) override;
//     std::string getSolution(const std::string &problem) override;
//     void saveSolution(const std::string &problem, const std::string &solution) override;

// private:
//     std::unordered_map<std::string, std::string> m_cache;
// };

// class Solver
// {
// public:
//     virtual ~Solver() = default;
//     virtual std::string solve(Problem *problem, Solution *solution) = 0;
// };

// class Problem
// {
// public:
//     virtual ~Problem() = default;
// };

// class Solution
// {
// public:
//     virtual ~Solution() = default;
// };

// class Expression : public Problem
// {
// public:
//     Expression(const std::string &expr)
//     : m_expr(expr)
//     {}
//     std::string evaluate() const;

// private:
//     static bool isOperator(const std::string &token);
//     static int getPrecedence(const std::string &op);
//     static void applyOperator(std::stack<double> &operandStack, const std::string &op);
//     static double eval(const std::string &op, double operand1, double operand2);

//     std::string m_expr;
// };

// class MyTestClientHandler : public ClientHandler
// {
// public:
//     MyTestClientHandler(Solver *s, CacheManager *c)
//     : m_solver(s)
//     , m_cacheManager(c)
//     {}

//     void handleClient(std::istream &inputStream, std::ostream &outputStream) override;

// private:
//     Solver *m_solver;
//     CacheManager *m_cacheManager;
// };

// void MySerialServer::open(int port, ClientHandler *ch)
// {
//     run(port, ch);
// }

// void MySerialServer::close()
// {
//     // TODO: Implement close
// }

// void MySerialServer::run(int port, ClientHandler *ch)
// {
//     // TODO: Implement run
// }

// bool FileCacheManager::isSolutionExists(const std::string &problem)
// {
//     return m_cache.find(problem) != m_cache.end();
// }

// std::string FileCacheManager::getSolution(const std::string &problem)
// {
//     return m_cache[problem];
// }

// void FileCacheManager::saveSolution(const std::string &problem, const std::string &solution)
// {
//     m_cache[problem] = solution;
//     std::ofstream outFile("cache.txt", std::ios::app);
//     outFile << problem << "," << solution << std::endl;
//     outFile.close();
// }

// void MyTestClientHandler::handleClient(std::istream &inputStream, std::ostream &outputStream)
// {
//     std::string problemString;
//     getline(inputStream, problemString);
//     if (m_cacheManager->isSolutionExists(problemString)) {
//         // Return cached solution
//         outputStream << m_cacheManager->getSolution(problemString) << std::endl;
//     }
//     else
//     {
//         // Solve the problem and save solution to cache
//         Problem *problem = new Expression(problemString);
//         Solution *solution = new Solution();
//         std::string solutionString = m_solver->solve(problem, solution);
//         m_cacheManager->saveSolution(problemString, solutionString);
//         outputStream << solutionString << std::endl;
//         delete problem;
//         delete solution;
//     }
// }

// std::string Expression::evaluate() const
// {
//     std::istringstream iss(m_expr);
//     std::stack<double> operandStack;
//     std::stack<std::string> operatorStack;
//     std::string token;
//     while (iss >> token) {
//         if (isdigit(token[0])) {
//             double operand = std::stod(token);
//             operandStack.push(operand);
//         } else if (isOperator(token)) {
//             while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(token)) {
//                 applyOperator(operandStack, operatorStack.top());
//                 operatorStack.pop();
//             }
//             operatorStack.push(token);
//         } else if (token == "(") {
//             operatorStack.push(token);
//         } else if (token == ")") {
//             while (operatorStack.top() != "(") {
//                 applyOperator(operandStack, operatorStack.top());
//                 operatorStack.pop();
//             }
//             operatorStack.pop();
//         }
//     }
//     while (!operatorStack.empty()) {
//         applyOperator(operandStack, operatorStack.top());
//         operatorStack.pop();
//     }
//     return std::to_string(operandStack.top());
// }

// bool Expression::isOperator(const std::string &token)
// {
//     return token == "+" || token == "-" || token == "*" || token == "/";
// }

// int Expression::getPrecedence(const std::string &op)
// {
//     if (op == "+" || op == "-") {
//         return 1;
//     } else if (op == "*" || op == "/") {
//         return 2;
//     } else {
//         return 0;
//     }
// }

// void Expression::applyOperator(std::stack<double> &operandStack, const std::string &op)
// {
//     double operand2 = operandStack.top();
//     operandStack.pop();
//     double operand1 = operandStack.top();
//     operandStack.pop();
//     double result = eval(op, operand1, operand2);
//     operandStack.push(result);
// }

// double Expression::eval(const std::string &op, double operand1, double operand2)
// {
//     if (op == "+") {
//         return operand1 + operand2;
//     } else if (op == "-") {
//         return operand1 - operand2;
//     } else if (op == "*") {
//         return operand1 * operand2;
//     } else if (op == "/") {
//         return operand1 / operand2;
//     } else {
//         return 0;
//     }
// }

// // Example usage
// int main()
// {
//     CacheManager *cacheManager = new FileCacheManager();
//     Solver *solver ;//= new ExpressionSolver();
//     ClientHandler *clientHandler = new MyTestClientHandler(solver, cacheManager);
//     Server *server = new MySerialServer();
//     server->open(1234, clientHandler);
//     server->close();
//     delete cacheManager;
//     delete solver;
//     delete clientHandler;
//     delete server;
//     return 0;
// }

// #include <iostream>
// #include <fstream>
// #include <unordered_map>
// #include <stack>
// #include <queue>
// #include <sstream>
// #include <string>
// #include <vector>
// #include <thread>
// #include <memory>
// #include <stdexcept>
// #include <cstring>
// #include <netinet/in.h>
// #include <sys/socket.h>
// #include <unistd.h>
// #include <cmath>

// class ClientHandler
// {
// public:
//     virtual ~ClientHandler() = default;
//     virtual void handleClient(std::ifstream &inputStream, std::ostream &outputStream) = 0;
// };

// class Server
// {
// public:
//     virtual ~Server() = default;
//     virtual void open(int port, ClientHandler &c) = 0;
//     virtual void close() = 0;
// };

// class MySerialServer : public Server
// {
// public:
//     virtual void open(int port, ClientHandler &ch) override;
//     virtual void close() override;

// private:
//     void run(int port, ClientHandler &ch);
// };

// class CacheManager
// {
// public:
//     virtual bool isSolutionExists(const std::string &problem) = 0;
//     virtual std::string getSolution(const std::string &problem) = 0;
//     virtual void saveSolution(const std::string &problem, const std::string &solution) = 0;
// };

// class Problem
// {
// public:
//     virtual ~Problem() = default;
// };

// class Solution
// {
// public:
//     virtual ~Solution() = default;
// };

// class FileCacheManager : public CacheManager
// {
// public:
//     bool isSolutionExists(const std::string &problem) override
//     {
//         std::ifstream file(problem + ".txt");
//         return file.good();
//     }

//     std::string getSolution(const std::string &problem) override
//     {
//         std::ifstream file(problem + ".txt");
//         std::stringstream buffer;
//         buffer << file.rdbuf();
//         return buffer.str();
//     }

//     void saveSolution(const std::string &problem, const std::string &solution) override
//     {
//         std::ofstream file(problem + ".txt");
//         file << solution;
//         file.close();
//     }
// };

// class Solver
// {
// public:
//     virtual std::string solve(Problem *problem, Solution *solution) = 0;
//     virtual void setCacheManager(CacheManager *c) = 0;
// };

// class ExpressionSolution : public Solution
// {
// public:
//     ExpressionSolution() {}

// private:
// };

// class Expression : public Problem
// {
// public:
//     Expression(const std::string &expression)
//         : m_expression(expression)
//     {
//     }

//     std::string getExpression() const
//     {
//         return m_expression;
//     }

// private:
//     std::string m_expression;
// };

// class ShuntingYardAlgorithm
// {
// public:
//     static std::queue<std::string> convertToPostfix(const std::string &expression);
//     static double evaluate(std::queue<std::string> &postfix);
// };

// std::queue<std::string> ShuntingYardAlgorithm::convertToPostfix(const std::string &expression)
// {
//     std::queue<std::string> outputQueue;
//     std::stack<std::string> operatorStack;
//     std::istringstream iss(expression);
//     std::string token;

//     while (iss >> token)
//     {
//         if (isdigit(token[0]))
//         {
//             // If the token is a number, push it to the output queue.
//             outputQueue.push(token);
//         }
//         else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^")
//         {
//             // If the token is an operator, pop operators from the stack and push them to the output queue
//             // as long as they have higher or equal precedence to the current operator.
//             while (!operatorStack.empty() && (operatorStack.top() == "^" || operatorStack.top() == "*" || operatorStack.top() == "/" || operatorStack.top() == "+" || operatorStack.top() == "-"))
//             {
//                 outputQueue.push(operatorStack.top());
//                 operatorStack.pop();
//             }
//             operatorStack.push(token);
//         }
//         else if (token == "(")
//         {
//             // If the token is a left parenthesis, push it onto the stack.
//             operatorStack.push(token);
//         }
//         else if (token == ")")
//         {
//             // If the token is a right parenthesis, pop operators from the stack and push them to the output queue
//             // until a left parenthesis is encountered. Pop and discard the left parenthesis.
//             while (!operatorStack.empty() && operatorStack.top() != "(")
//             {
//                 outputQueue.push(operatorStack.top());
//                 operatorStack.pop();
//             }
//             if (!operatorStack.empty() && operatorStack.top() == "(")
//             {
//                 operatorStack.pop();
//             }
//             else
//             {
//                 // Unbalanced parentheses, return an empty queue to signal an error.
//                 return std::queue<std::string>();
//             }
//         }
//         else
//         {
//             // Invalid token, return an empty queue to signal an error.
//             return std::queue<std::string>();
//         }
//     }

//     // Pop any remaining operators from the stack and push them to the output queue.
//     while (!operatorStack.empty())
//     {
//         if (operatorStack.top() == "(")
//         {
//             // Unbalanced parentheses, return an empty queue to signal an error.
//             return std::queue<std::string>();
//         }
//         outputQueue.push(operatorStack.top());
//         operatorStack.pop();
//     }

//     return outputQueue;
// }

// double ShuntingYardAlgorithm::evaluate(std::queue<std::string> &postfix)
// {
//     std::stack<double> operandStack;

//     while (!postfix.empty()) {
//         std::string token = postfix.front();
//         postfix.pop();

//         if (isdigit(token[0])) {
//             // If the token is a number, push its value onto the operand stack.
//             operandStack.push(std::stod(token));
//         } else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
//             // If the token is an operator, pop the top two operands from the stack, apply the operator,
//             // and push the result back onto the stack.
//             if (operandStack.size() < 2) {
//                 // Invalid expression, return NaN to signal an error.
//                 return std::nan("");
//             }
//             double operand2 = operandStack.top();
//             operandStack.pop();

//             double operand1 = operandStack.top();

//             operandStack.pop();

//             if (token == "+") {
//                 operandStack.push(operand1 + operand2);
//             } else if (token == "-") {
//                 operandStack.push(operand1 - operand2);
//             } else if (token == "*") {
//                 operandStack.push(operand1 * operand2);
//             } else if (token == "/") {
//                 if (operand2 == 0) {
//                     // Division by zero, return +/- infinity to signal an error.
//                     return operand1 < 0 ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
//                 }
//                 operandStack.push(operand1 / operand2);
//             } else if (token == "^") {
//                 operandStack.push(pow(operand1,operand2));
//             }
//         } else {
//             // Invalid token, return NaN to signal an error.
//             return std::nan("");
//         }
//     }

//     if (operandStack.size() == 1) {
//         // The final result should be on the top of the stack.
//         return operandStack.top();
//     } else {
//         // Invalid expression, return NaN to signal an error.
//         return std::nan("");
//     }
// }

// class ExpressionSolver : public Solver
// {
// public:
//     std::string solve(Problem *problem, Solution *solution) override
//     {
//         Expression *expression = dynamic_cast<Expression *>(problem);
//         if (expression == nullptr) {
//             return "";
//         }

//         std::string strExpression = expression->getExpression();
//         if (m_cacheManager->isSolutionExists(strExpression)) {
//             return m_cacheManager->getSolution(strExpression);
//         }

//         std::queue<std::string> postfix = ShuntingYardAlgorithm::convertToPostfix(strExpression);
//         double result = ShuntingYardAlgorithm::evaluate(postfix);

//         std::stringstream ss;
//         ss << result;
//         std::string strResult = ss.str();

//         m_cacheManager->saveSolution(strExpression, strResult);

//         return strResult;
//     }

//     void setCacheManager(CacheManager *cacheManager)
//     {
//         m_cacheManager = cacheManager;
//     }

// private:
//     CacheManager *m_cacheManager = nullptr;
// };

// class MyTestClientHandler : public ClientHandler
// {
// public:
//     MyTestClientHandler(Solver *s, CacheManager *c)
//         : m_solver(s), m_cacheManager(c)
//     {
//     }

//     void handleClient(std::ifstream &inputStream, std::ostream &outputStream) override
//     {
//         std::string line;
//         getline(inputStream, line);
//         while (line != "end")
//         {
//             if (m_cacheManager->isSolutionExists(line))
//             {
//                 std::string solution = m_cacheManager->getSolution(line);
//                 outputStream << solution << std::endl;
//             }
//             else
//             {
//                 Problem *problem = new Expression(line);
//                 Solution *solution = new ExpressionSolution();
//                 std::string strSolution = m_solver->solve(problem, solution);
//                 m_cacheManager->saveSolution(line, strSolution);
//                 outputStream << strSolution << std::endl;
//                 delete problem;
//                 delete solution;
//             }
//             getline(inputStream, line);
//         }
//     }

// private:
//     Solver *m_solver = nullptr;
//     CacheManager *m_cacheManager = nullptr;
// };

// void MySerialServer::open(int port, ClientHandler &ch)
// {
//     std::thread t(&MySerialServer::run, this, port, std::ref(ch));
//     t.detach();
// }

// void MySerialServer::close()
// {
//     // TODO: implement
// }

// void MySerialServer::run(int port, ClientHandler &ch)
// {
//     int sockfd, newsockfd, clilen;
//     struct sockaddr_in serv_addr, cli_addr;
//     sockfd = socket(AF_INET, SOCK_STREAM, 0);
//     if (sockfd < 0)
//     {
//         throw std::runtime_error("ERROR opening socket");
//     }
//     bzero((char *)&serv_addr, sizeof(serv_addr));
//     serv_addr.sin_family = AF_INET;
//     serv_addr.sin_addr.s_addr = INADDR_ANY;
//     serv_addr.sin_port = htons(port);
//     if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
//     {
//         throw std::runtime_error("ERROR on binding");
//     }
//     listen(sockfd, 5);
//     clilen = sizeof(cli_addr);
//     while (true)
//     {
//         newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);
//         if (newsockfd < 0)
//         {
//             throw std::runtime_error("ERROR on accept");
//         }
//         ch.handleClient(*new std::ifstream(std::to_string(newsockfd)), *new std::ofstream(std::to_string(newsockfd)));
//         ::close(newsockfd);
//     }
// }

// // int main()
// // {
// //     std::string expression = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
// //     std::queue<std::string> postfix = ShuntingYardAlgorithm::convertToPostfix(expression);

// //     if (postfix.empty()) {
// //         std::cout << "Invalid expression." << std::endl;
// //     } else {
// //         double result = ShuntingYardAlgorithm::evaluate(postfix);
// //         std::cout << expression << " = " << result << std::endl;
// //     }

// //     return 0;
// // }

// bool isNumber(char const*str) {
//     bool hasDigit = false;
//     bool hasNonDigit = false;

//     for (int i = 0; str[i] != '\0'; i++) {
//         if (isdigit(str[i])) {
//             hasDigit = true;
//         } else {
//             hasNonDigit = true;
//             break;
//         }
//     }

//     return hasDigit && !hasNonDigit;
// }

// int getLength(char const*str) {
//     int length = 0;
//     while (str[length] != '\0') {
//         length++;
//     }
//     return length;
// }


// int main(int argc, char *argv[])
// {
//     if (argc != 2 || !isNumber(argv[1]) || getLength(argv[1]) < 4) {
//         if (!isNumber(argv[1])) {
//             std::cerr << "Usage: " << argv[0] << " <port> need to be a number of 4 digits" << std::endl;
//         } else if (getLength(argv[1]) != 4) {
//             std::cerr << "Usage: " << argv[0] << " <port> need to be 4 digits" << std::endl;
//         } else {
//             std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
//         }
//         return 1;
//     }
//     int port = std::stoi(argv[1]);
//     // int port = 8080;
//     CacheManager *cacheManager = new FileCacheManager();
//     Solver *solver = new ExpressionSolver();
//     solver->setCacheManager(cacheManager);
//     ClientHandler *clientHandler = new MyTestClientHandler(solver, cacheManager);
//     Server *server = new MySerialServer();
//     server->open(port, *clientHandler);
//     delete server;
//     delete clientHandler;
//     delete solver;
//     delete cacheManager;
//     return 0;
// }

// #include <exception>
// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <iostream>
// #include <stdexcept>
// #include <sstream>

// class mapException : public std::exception {
// public:
//     mapException(std::unordered_map<std::string,std::string>& map, std::vector<std::string>& str)
//     : m_map(map)
//     , m_str(str)
//     , m_line(0)
//     , m_file(__FILE__)
//     {}

//     const char* what() const noexcept override {
//         return "Error: key does not exist in map";
//     }

//     int line_number() const noexcept {
//         return m_line;
//     }

//     const std::string& file_name() const noexcept {
//         return m_file;
//     }

//     void set_line_number(int const&m) {
//         m_line = m + 1;
//     }
// private:
//     std::unordered_map<std::string,std::string>& m_map;
//     std::vector<std::string>& m_str;
//     int m_line;
//     std::string m_file;


// public:
//     void check_key() {
//         if (m_map.count(m_str[0])) {
//             m_map.at(m_str[0]) = m_str[2];
//         } else {
//             set_line_number(__LINE__);
//             std::ostringstream oss;
//             oss << m_str[0] << " does not exist in the map";
//             throw std::out_of_range(oss.str());
//         }
//     }
// };

// class MapException : public std::exception {
// public:
//     MapException() {}
//     MapException(const std::string& message, const std::string& location);

//     const char* what() const noexcept override;
//     const char* where() const noexcept;

// private:
//     std::string m_message;
//     std::string m_location;
// };

// #include <unordered_map>
// #include <string>
// #include <vector>
// #include <sstream>

// MapException::MapException(const std::string& message, const std::string& location)
// : m_message(message)
// , m_location(location)
// {}

// const char *MapException::what() const noexcept
// {
//     return m_message.c_str();
// }

// const char* MapException::where() const noexcept
// {
//     return m_location.c_str();
// }

// #include <iostream>

// int main() 
// {
//     std::unordered_map<std::string,std::string> my_map;
//     std::vector<std::string> my_vec = {"pizza","key", "=", "value"};

//     // MapException m{};
    
//     // if (my_map.count(my_vec[0])) {
        
//     // } else {
//     //     throw MapException("Error: " + my_vec[0] + " not found in my_map.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
//     // }

//     try {
//         if (my_map.count(my_vec[0])) {
//             my_map.at(my_vec[0]);
//         } else {
//             throw MapException("Error: " + my_vec[0] + " not found in my_map.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
//         }
//     } catch (const MapException& e) {
//         std::cout << e.what() << " at line " << e.where() << "\n";
//     }

//     return 0;
// }

// #include <unordered_map>
// #include <string>
// #include <vector>
// #include <sstream>
// #include <iostream>

// class MapException {
// public:
//     MapException(const std::string& message, const std::string& location);
//     const char *what() const noexcept;
//     const char* where() const noexcept;

//     template<typename Func>
//     void tryCatch(const Func& func) const {
//         try {
//             func();
//         } catch (const MapException& me) {
//             std::cout << me.what() << " at line " << me.where() << "\n";
//         }
//     }

// private:
//     std::string m_message;
//     std::string m_location;
// };

// MapException::MapException(const std::string& message, const std::string& location)
// : m_message(message)
// , m_location(location)
// {}

// const char *MapException::what() const noexcept
// {
//     return m_message.c_str();
// }

// const char* MapException::where() const noexcept
// {
//     return m_location.c_str();
// }

// class MyClass {
// public:
//     void myMethod() {
//         MapException m("","");
//         m.tryCatch([&]() {
//             if (map_strDB.count("myVar")) {
//                 // do something
//             } else {
//                 throw MapException("Error: myVar not found in map_strDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
//             }
//         });
//     }

// private:
//     std::unordered_map<std::string, std::string> map_strDB;
// };

// int main() {
//     MyClass obj;
//     obj.myMethod();
//     return 0;
// }

#include <stack>
#include <vector>
#include <memory>

class Token {
public:
    virtual ~Token() {}
    virtual bool isNumber() const = 0;
    virtual bool isOperator() const = 0;
    virtual double getValue() const = 0;
    virtual int getPrecedence() const = 0;
    virtual char getOperator() const = 0;
};

class NumberToken : public Token {
public:
    NumberToken(double value) : m_value(value) {}
    bool isNumber() const override { return true; }
    bool isOperator() const override { return false; }
    double getValue() const override { return m_value; }
    int getPrecedence() const override { return -1; }
    char getOperator() const override { return '0'; }
private:
    double m_value;
};

class OperatorToken : public Token {
public:
    OperatorToken(char op, int precedence) : m_op(op), m_precedence(precedence) {}
    bool isNumber() const override { return false; }
    bool isOperator() const override { return true; }
    double getValue() const override { return 0; }
    int getPrecedence() const override { return m_precedence; }
    char getOperator() const override { return m_op; }
private:
    char m_op;
    int m_precedence;
};

class OutputQueue {
public:
    void enqueue(std::shared_ptr<Token> token) { m_queue.push_back(token); }
    std::shared_ptr<Token> dequeue() { auto token = m_queue.front(); m_queue.pop_back(); return token; }
    bool isEmpty() const { return m_queue.empty(); }
private:
    std::vector<std::shared_ptr<Token>> m_queue;
};

class ShuntingYard {
public:
    std::shared_ptr<OutputQueue> shunt(const std::vector<std::shared_ptr<Token>>& input) const;
private:
    void handleOperator(const OperatorToken& op, std::stack<std::shared_ptr<Token>>& operatorStack, OutputQueue& outputQueue) const;
};

std::shared_ptr<OutputQueue> ShuntingYard::shunt(const std::vector<std::shared_ptr<Token>>& input) const {
    auto outputQueue = std::make_shared<OutputQueue>();
    std::stack<std::shared_ptr<Token>> operatorStack;

    for (const auto& token : input) {
        if (token->isNumber()) {
            outputQueue->enqueue(token);
        } else if (token->isOperator()) {
            const auto& op = static_cast<const OperatorToken&>(*token);
            handleOperator(op, operatorStack, *outputQueue);
        }
    }

    while (!operatorStack.empty()) {
        outputQueue->enqueue(operatorStack.top());
        operatorStack.pop();
    }

    return outputQueue;
}

void ShuntingYard::handleOperator(const OperatorToken& op, std::stack<std::shared_ptr<Token>>& operatorStack, OutputQueue& outputQueue) const {
    while (!operatorStack.empty() && operatorStack.top()->isOperator()) {
        const auto& topOp = static_cast<const OperatorToken&>(*operatorStack.top());
        if ((op.getPrecedence() <= topOp.getPrecedence()) && (topOp.getPrecedence() > 0)) {
            outputQueue.enqueue(std::move(operatorStack.top()));
            operatorStack.pop();
        } else {
            break;
        }
    }
    operatorStack.push(std::make_shared<OperatorToken>(op));
}

#include <iostream>
#include <string>
#include <vector>
#include <memory>
// #include "ShuntingYard.h"
// #include "Token.h"
// #include "NumberToken.h"
// #include "OperatorToken.h"
// #include "OutputQueue.h"

// int main() {
//     // Create an input expression
//     std::vector<std::shared_ptr<Token>> input = {
//         std::make_shared<NumberToken>(5.0),
//         std::make_shared<OperatorToken>("+"),
//         std::make_shared<NumberToken>(3.0),
//         std::make_shared<OperatorToken>("*"),
//         std::make_shared<NumberToken>(4.0)
//     };
    
//     // Shunt the expression using the ShuntingYard class
//     ShuntingYard shuntingYard;
//     auto outputQueue = shuntingYard.shunt(input);
    
//     // Output the contents of the output queue
//     while (!outputQueue->isEmpty()) {
//         std::cout << outputQueue->dequeue()->getValue() << " ";
//     }
//     std::cout << std::endl;
    
//     return 0;
// }

int main() {
    std::vector<std::shared_ptr<Token>> input = {
        std::make_shared<NumberToken>(3),
        std::make_shared<OperatorToken>('+',1),
        std::make_shared<NumberToken>(4),
        std::make_shared<OperatorToken>('*',2),
        std::make_shared<NumberToken>(5),
        std::make_shared<OperatorToken>('-',1),
        std::make_shared<NumberToken>(6)
    };

    ShuntingYard shuntingYard;
    auto outputQueue = shuntingYard.shunt(input);

    while (!outputQueue->isEmpty()) {
        auto token = outputQueue->dequeue();
        if (token->isNumber()) {
            std::cout << token->getValue() << " ";
        } else if (token->isOperator()) {
            std::cout << token->getOperator() << " ";
        }
    }

    return 0;
}
