#include <gtest/gtest.h>
#include "Scanner.h"
#include "ErrorReport.h"


TEST(SolverTest, BasicInitialization) {
  // Expect two strings not to be equal.
  ErrorReport err;
  std::string source
      = "( ) { } , . - + ; / * ! != = == > >= < <= arg1 \"string\" 1 and class "
        "else false fun "
        "for if nil or print return super this true var while";
  Scanner scanner(source, err);

  std::vector<Token::TokenType> expected = {Token::TokenType::LEFT_PAREN,
                                            Token::TokenType::RIGHT_PAREN,
                                            Token::TokenType::LEFT_BRACE,
                                            Token::TokenType::RIGHT_BRACE,
                                            Token::TokenType::COMMA,
                                            Token::TokenType::DOT,
                                            Token::TokenType::MINUS,
                                            Token::TokenType::PLUS,
                                            Token::TokenType::SEMICOLON,
                                            Token::TokenType::SLASH,
                                            Token::TokenType::STAR,
                                            Token::TokenType::BANG,
                                            Token::TokenType::BANG_EQUAL,
                                            Token::TokenType::EQUAL,
                                            Token::TokenType::EQUAL_EQUAL,
                                            Token::TokenType::GREATER,
                                            Token::TokenType::GREATER_EQUAL,
                                            Token::TokenType::LESS,
                                            Token::TokenType::LESS_EQUAL,
                                            Token::TokenType::IDENTIFIER,
                                            Token::TokenType::STRING,
                                            Token::TokenType::NUMBER,
                                            Token::TokenType::AND,
                                            Token::TokenType::CLASS,
                                            Token::TokenType::ELSE,
                                            Token::TokenType::FALSE,
                                            Token::TokenType::FUN,
                                            Token::TokenType::FOR,
                                            Token::TokenType::IF,
                                            Token::TokenType::NIL,
                                            Token::TokenType::OR,
                                            Token::TokenType::PRINT,
                                            Token::TokenType::RETURN,
                                            Token::TokenType::SUPER,
                                            Token::TokenType::THIS,
                                            Token::TokenType::TRUE,
                                            Token::TokenType::VAR,
                                            Token::TokenType::WHILE,
                                            Token::TokenType::END_OF_FILE};
                                      
  auto expectedIter = expected.begin();
  auto tokensVec = scanner.scanTokens(); 
  for (auto &token : tokensVec) {
    ASSERT_EQ(token.getType(), *expectedIter);
    ++expectedIter;
  }
}
