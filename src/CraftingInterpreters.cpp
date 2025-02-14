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
#include "Token.h"

using namespace std;


int main(int argc, char *argv[])
{
	auto lox = Lox();

	if(argc > 2)
	{
		printf("Usage: cpplox [script]");
		return 64;
	}
	else if(argc == 2)
	{
		auto path = std::string_view(argv[1]);
		lox.runFile(path);
	}
	else
	{
		lox.runPrompt();
	}
	return 0;
}
