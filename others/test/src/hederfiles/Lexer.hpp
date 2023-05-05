#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <fstream>


#include "BlockParser.hpp"
#include "FileReader.hpp"

class Lexer
{
public:
    Lexer(std::string &src);
    std::vector<std::vector<std::string>> tokenize_file();
    static std::vector<std::vector<std::vector<std::string>>>& get_while_blocks();
    static std::vector<std::vector<std::vector<std::string>>>& get_lines_blocks();
    static std::vector<std::vector<std::vector<std::string>>>& get_if_blocks();
private:
    std::vector<std::vector<std::string>> read_file_contents();
    void process_blocks();
    void register_block_parser(const std::string &block_type, std::shared_ptr<BlockParser> parser);
    void print_vector(const std::vector<std::vector<std::string>>& vec, const std::string &blockType);
private:
    FileReader m_fileReader;
    std::ifstream m_program;
    std::string m_src;
    std::unordered_map<std::string, std::shared_ptr<BlockParser>> m_blockParsers;
    static std::vector<std::vector<std::vector<std::string>>> m_while_blocks;
    static std::vector<std::vector<std::vector<std::string>>> m_if_blocks;
    static std::vector<std::vector<std::vector<std::string>>> m_lines_blocks;
};