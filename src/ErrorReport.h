#pragma once
#include <iostream> 
#include <string>

class ErrorReport
{
    private: 
        bool hadError = false;
    public:
        ErrorReport() = default;    
        ~ErrorReport() = default;
        void error(int line, std::string message);
        void report(int line, std::string where, std::string message);
};