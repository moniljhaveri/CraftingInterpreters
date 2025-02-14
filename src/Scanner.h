#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <map>
#include "token.h"
#include "Lox.h"


class Scanner 
{
public:
    Scanner(std::string source) : source(std::move(source)) {
        lox = std::make_unique<Lox>();
    };
    ~Scanner() = default;
    std::vector<Token::Token> scanTokens();

private: 
    std::string source;
    int32_t start = 0;
    int32_t current = 0;
    int32_t line = 1;
    std::vector<Token::Token> tokens;
    std::unique_ptr<Lox> lox;

    bool isAtEnd();
    void scanToken();
    char advance();
    void addToken(Token::TokenType type);
    void addToken(Token::TokenType type, std::any literal);
    bool match(char expected);
    char peek();
    void string(); 
    void number(); 
    char peekNext();
    void identifier();
    void commentBlock();
};