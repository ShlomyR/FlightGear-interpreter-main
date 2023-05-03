#include "../hederfiles/Parse.hpp"

void Parse::parse(std::vector<std::vector<std::string>> &lines)
{
    m_lines_pointer.resetIndex();
    for (m_lines_pointer.getIndex(); m_lines_pointer.getIndex() < lines.size(); m_lines_pointer.incrementIndex()) {
        std::shared_ptr<Command> c = m_command_factory.createCommand(lines[m_lines_pointer.getIndex()]);
        if (c != nullptr) {
            c->DoCommand(lines[m_lines_pointer.getIndex()]);
        }
    }
}

// Parse::m_index +=

// size_t Parse::m_index;


// std::string::size_type Parse::getIndex()
// {
//     return m_index;
// }

// void Parse::incrementIndex()
// {
//     m_index++;
// }

// void Parse::resetIndex()
// {
//     m_index = 0;
// }

// void Parse::setIndex(int i)
// {
//     m_index = i;
// }