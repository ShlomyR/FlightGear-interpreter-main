#include <sstream>
#include <fstream>
#include <iostream>

#include "../hederfiles/WhileBlockParser.hpp"
#include "../hederfiles/LinesBlockParser.hpp"
#include "../hederfiles/IfBlockParser.hpp"
#include "../hederfiles/Lexer.hpp"

std::vector<std::vector<std::vector<std::string>>> Lexer::m_while_blocks;
std::vector<std::vector<std::vector<std::string>>> Lexer::m_if_blocks;

std::vector<std::vector<std::vector<std::string>>> &Lexer::get_while_blocks()
{
    return m_while_blocks;
}

std::vector<std::vector<std::vector<std::string>>> &Lexer::get_if_blocks()
{
    return m_if_blocks;
}

Lexer::Lexer(FileReader &fileReader, std::string &src)
: m_fileReader(fileReader)
, m_src(src)
{
    auto while_blocks = tokenize_file("while");
    auto if_blocks = tokenize_file("if");
}

std::vector<std::vector<std::string>> Lexer::read_file_contents()
{
    std::vector<std::vector<std::string>> lines;
    m_program.open(m_src);
    
    if (!m_program.is_open()) {
        throw std::runtime_error("file not opened in lexer\n");
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

void Lexer::process_blocks(std::vector<std::vector<std::string>>& lines, const std::string blockName)
{
    for (const auto &[blockType, parser] : m_blockParsers) {
        if (blockType == blockName) {
            parser->parse(lines);
        }
        if (blockType == "while") {
            // m_while_blocks.push_back(lines);
        } else if (blockType == "if") {
            // m_if_blocks.push_back(lines);
        } else if (blockType == " ") {
            m_lines_blocks.push_back(lines);
        } else {
            throw std::runtime_error("Unknown block type: " + blockType);
        }
    }
}

std::vector<std::vector<std::string>> Lexer::tokenize_file(const std::string &blockName)
{
    register_block_parser("while", std::make_unique<WhileBlockParser>());
    register_block_parser("if", std::make_unique<IfBlockParser>());
    register_block_parser(" ", std::make_unique<LinesBlockParser>());

    std::vector<std::vector<std::string>> lines = read_file_contents();
    process_blocks(lines, blockName);
    print_vector(lines);
    return lines;
}

void Lexer::register_block_parser(const std::string &block_type, std::shared_ptr<BlockParser> parser)
{
    m_blockParsers[block_type] = std::move(parser);
}

void Lexer::print_vector(const std::vector<std::vector<std::string>>& vec) {
    std::cout << "\n" << "Print type: " << vec[0][0] << "\n" << "\n";
    for (std::string::size_type i = 0; i < vec.size(); i++) {
        std::cout << "[";
        for (std::string::size_type j = 0; j < vec[i].size(); j++) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << "]" << "\n";
    }
}