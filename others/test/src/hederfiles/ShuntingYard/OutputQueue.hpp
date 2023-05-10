#pragma once

#include <memory>
#include <queue>
#include <vector>

#include "../hederfiles/Interfaces/Token.hxx"

class OutputQueue
{
public:
    void enqueue(std::shared_ptr<Token> );
    std::shared_ptr<Token> dequeue();
    std::shared_ptr<Token> peek() const;
    bool isEmpty() const;

private:
    std::queue<std::shared_ptr<Token>> m_queue;
};
