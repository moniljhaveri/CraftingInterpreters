#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <map>
#include "token.h"


class Scanner 
{
public:
    Scanner(std::string source) : source(std::move(source)) {};
    ~Scanner() = default;
    std::vector<Token::Token> scanTokens();

private: 
    std::string source;
    int32_t start = 0;
    int32_t current = 0;
    int32_t line = 1;
    std::vector<Token::Token> tokens;
    bool isAtEnd();
    void scanToken();
    char advance();
    void addToken(Token::TokenType type);
    void addToken(Token::TokenType type, std::any literal);

};