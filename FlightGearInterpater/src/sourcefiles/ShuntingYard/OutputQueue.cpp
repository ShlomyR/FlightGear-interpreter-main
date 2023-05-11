#include "OutputQueue.hpp"

#include <memory>

void OutputQueue::enqueue(std::shared_ptr<Token> token)
{
    m_queue.push(token);
}

std::shared_ptr<Token> OutputQueue::dequeue()
{
    if (isEmpty()) {
        return nullptr;
    }

    std::shared_ptr<Token> token = m_queue.front();
    m_queue.pop();
    return token;
}

std::shared_ptr<Token> OutputQueue::peek() const
{
    if (isEmpty()) {
        return nullptr;
    }

    return m_queue.front();
}

bool OutputQueue::isEmpty() const
{
    return m_queue.empty();
}
