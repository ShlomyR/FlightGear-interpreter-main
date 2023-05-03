#pragma once

#include <memory>
#include <queue>
#include <vector>

#include "Token.hxx"

class OutputQueue
{
public:
    void enqueue(std::shared_ptr<Token> token);
    std::shared_ptr<Token> dequeue();
    std::shared_ptr<Token> peek() const;
    bool isEmpty() const;

private:
    std::queue<std::shared_ptr<Token>> m_queue;
};
