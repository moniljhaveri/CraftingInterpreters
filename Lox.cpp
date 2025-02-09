#include <iostream>
#include <fstream>
#include <vector>

#include "Lox.h"

Lox::Lox() : hadError(false)
{
}

void Lox::run(std::string& source)
{
    printf("Running: %s\n", source.c_str());
}

void Lox::runPrompt()
{
    std::string line;
    while(true)
    {
        printf("> ");
        std::getline(std::cin, line);
        if(line.empty())
        {
            break;
        }
        run(line);
    }
}

void Lox::runFile(std::string_view& path)
{
    std::string line;
	std::ifstream file(std::string(path), std::ios::binary);  
	std::vector<char> vec(std::istreambuf_iterator<char>(file), {});
	std::string str(vec.begin(), vec.end());
	run(str);
}
void Lox::error(int line, std::string message)
{
    report(line, "", message);
}
void Lox::report(int line, std::string where, std::string message)
{
    printf("[line %d] Error %s: %s\n", line, where.c_str(), message.c_str());
    hadError = true;
}