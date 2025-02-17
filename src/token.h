#pragma once
#include <string>
#include <any>
#include <memory>
namespace Token
{
enum class TokenType
{
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,
    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,
    // Literals.
    IDENTIFIER, STRING, NUMBER,
    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,
    // End of file.
    END_OF_FILE
};

struct Token
{
    TokenType type;
    std::string lexeme;
    std::any literal;
    int line;
    Token(TokenType type, std::string lexeme, std::any literal, int line) : type(type), lexeme(std::move(lexeme)), literal(literal), line(line) {}
    std::string toString()
    {
        return std::to_string(static_cast<int>(type)) + " " + lexeme + " " + literalToString() + " " + std::to_string(line);
    }
    std::string literalToString()
    {
        switch(type)
        {
            case TokenType::STRING:
                return std::any_cast<std::string>(literal);
            case TokenType::NUMBER:
                return std::to_string(std::any_cast<double>(literal));
            default:
                return "";
        }
    }
    auto getType()
    {
        return type;
    }
};

}