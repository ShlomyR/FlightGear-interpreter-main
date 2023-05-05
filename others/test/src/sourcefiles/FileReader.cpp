#include "../hederfiles/FileReader.hpp"

template <>
std::string FileReader::read_file<std::string>(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

template <>
std::vector<std::vector<std::string>> FileReader::read_file<std::vector<std::vector<std::string>>>(const std::string &filename)
{
    std::vector<std::vector<std::string>> lines;
    m_program.open(filename);
    
    if (!m_program.is_open()) {
        throw std::runtime_error("file not opened in VvcFileReader, file:" + filename + "\n");
    }

    std::string line;
    while (std::getline(m_program, line)) {
        std::vector<std::string> tokens;
        std::istringstream iss(line);
        for (std::string token; iss >> token;) {
            if (line.size() > 0) {
                tokens.push_back(token);
            }
        }
        if (tokens.size() > 0) {
            lines.push_back(tokens);
        }
    }
    m_program.close();

    return lines;
}
