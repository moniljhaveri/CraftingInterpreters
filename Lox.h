#pragma once

#include <string_view>
#include <string> 

class Lox
{
    private: 
        bool hadError;
    public:
        Lox();
        ~Lox() = default;
        void run(std::string& source);
        void runPrompt();
        void runFile(std::string_view& path);
        void error(int line, std::string message); 
        void report(int line, std::string where, std::string message);
};