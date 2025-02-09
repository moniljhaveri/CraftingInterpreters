#include "Scanner.h"


std::vector<Token::Token> Scanner::scanTokens()
{
    while(!isAtEnd())
    {
        start = current;
        scanToken();
    }
    tokens.push_back(Token::Token(Token::TokenType::END_OF_FILE, "", "", line));
    return tokens;
}

bool Scanner::isAtEnd()
{
    return current >= source.size();
}

void Scanner::scanToken()
{
    char c = source[current++];
    switch(c)
    {
        case '(': addToken(Token::TokenType::LEFT_PAREN); break;
        case ')': addToken(Token::TokenType::RIGHT_PAREN); break;
        case '{': addToken(Token::TokenType::LEFT_BRACE); break;
        case '}': addToken(Token::TokenType::RIGHT_BRACE); break;
        case ',': addToken(Token::TokenType::COMMA); break;
        case '.': addToken(Token::TokenType::DOT); break;
        case '-': addToken(Token::TokenType::MINUS); break;
        case '+': addToken(Token::TokenType::PLUS); break;
        case ';': addToken(Token::TokenType::SEMICOLON); break;
        case '*': addToken(Token::TokenType::STAR); break;
    }
}

char Scanner::advance()
{
    return source[current++];
}

void Scanner::addToken(Token::TokenType type)
{
    addToken(type, "");
}

void Scanner::addToken(Token::TokenType type, std::any literal)
{
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token::Token(type, text, literal, line));
}