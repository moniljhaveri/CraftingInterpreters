#include <unordered_map>
#include "Scanner.h"

const std::unordered_map<std::string, Token::TokenType> keywords = {
    {"and", Token::TokenType::AND},
    {"class", Token::TokenType::CLASS},
    {"else", Token::TokenType::ELSE},
    {"false", Token::TokenType::FALSE},
    {"for", Token::TokenType::FOR},
    {"fun", Token::TokenType::FUN},
    {"if", Token::TokenType::IF},
    {"nil", Token::TokenType::NIL},
    {"or", Token::TokenType::OR},
    {"print", Token::TokenType::PRINT},
    {"return", Token::TokenType::RETURN},
    {"super", Token::TokenType::SUPER},
    {"this", Token::TokenType::THIS},
    {"true", Token::TokenType::TRUE},
    {"var", Token::TokenType::VAR},
    {"while", Token::TokenType::WHILE}
};



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
    char c = advance(); 
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
        case '!': addToken(match('=') ? Token::TokenType::BANG_EQUAL : Token::TokenType::BANG); break;
        case '=': addToken(match('=') ? Token::TokenType::EQUAL_EQUAL : Token::TokenType::EQUAL); break;
        case '<': addToken(match('=') ? Token::TokenType::LESS_EQUAL : Token::TokenType::LESS); break;
        case '>': addToken(match('=') ? Token::TokenType::GREATER_EQUAL : Token::TokenType::GREATER); break;
        case '/':
            if (match('/')) {
            // A comment goes until the end of the line.
                while (peek() != '\n' && !isAtEnd()) advance();
            } else {
                addToken(Token::TokenType::SLASH);
            }
            break;
        case ' ':
        case '\r':
        case '\t':
            // Ignore whitespace.
            break;

        case '\n':
            line++;
            break;
        case '"': string(); break;
        default:
            if(isdigit(c))
            {
                number();
            }
            else if(isalpha(c))
            {
                identifier(); 
            }
            else 
            {
                lox->error(line, "Unexpected character.");
            }
            break;
    }
}

void Scanner::identifier()
{
    while(isalnum(peek())) advance();
    auto text = source.substr(start, current - start);
    auto type = keywords.find(text);
    if(type == keywords.end())
    {
        addToken(Token::TokenType::IDENTIFIER);
    }
    else
    {
        addToken(type->second);
    }
}

inline char Scanner::advance()
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

bool Scanner::match(char expected)
{
    if(isAtEnd())
    {
        return false;
    }
    if(source[current] != expected)
    {
        return false;
    }
    current++;
    return true;
}

char Scanner::peek()
{
    if(isAtEnd()) return '\0';
    return source[current];
}

void Scanner::string()
{
  while (peek() != '"' && !isAtEnd()) {
      if (peek() == '\n') line++;
      advance();
    }

    if (isAtEnd()) {
      lox->error(line, "Unterminated string.");
      return;
    }

    // The closing ".
    advance();

    // Trim the surrounding quotes.
    std::string value = source.substr(start + 1, current - 1);
    addToken(Token::TokenType::STRING, value);
  
}

void Scanner::number()
{
    while (isdigit(peek())) advance();

    // Look for a fractional part.
    if (peek() == '.' &&isdigit(peekNext())) {
      // Consume the "."
      advance();

      while (isdigit(peek())) advance();
    }
    addToken(Token::TokenType::NUMBER,
        std::stod(source.substr(start, current)));
}

char Scanner::peekNext()
{
    if (current + 1 >= source.length()) return '\0';
    return source[current + 1];

}