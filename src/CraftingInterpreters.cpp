// CraftingInterpreters.cpp : Defines the entry point for the application.
//

#include <cassert>
#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include <iterator>
#include <string_view>
#include <iostream>

#include "CraftingInterpreters.h"
#include "Lox.h"
#include "token.h"
#include "ErrorReport.h"
#include "AstPrinter.h"
#include "NodeType.h"
#include "Expr.h"

using namespace std;


int main(int argc, char *argv[])
{
	// auto lox = Lox();

	// if(argc > 2)
	// {
	// 	printf("Usage: cpplox [script]");
	// 	return 64;
	// }
	// else if(argc == 2)
	// {
	// 	auto path = std::string_view(argv[1]);
	// 	lox.runFile(path);
	// }
	// else
	// {
	// 	lox.runPrompt();
	// }
	
    std::cout << "Hello World" << std::endl; 
    Token::Token minus = Token::Token(Token::TokenType::MINUS, "-", NULL,  1);
    Token::Token star = Token::Token(Token::TokenType::STAR, "*", NULL,  1);
    Token::Token number1 = Token::Token(Token::TokenType::NUMBER, "123", NULL, 1);
    Token::Token number2 = Token::Token(Token::TokenType::NUMBER, "45.67", NULL, 1);
    Literal literal1(number1); 
    Literal literal2(number2); 
    Grouping group(std::make_shared<Literal>(literal2)); 
    Unary unary(minus, std::make_shared<Literal>(literal1)); 
    Binary binary = Binary(std::make_shared<Unary>(unary), star, std::make_shared<Grouping>(group)); 
    AstPrinter astP; 
    astP.print(std::make_shared<Binary>(binary));
    
	return 0;
}
