#include <iostream>
#include <string>
#include "ErrorReport.h"

void ErrorReport::error(int line, std::string message)
{
    report(line, "", message);
}

void ErrorReport::report(int line, std::string where, std::string message)
{
    printf("[line %d] Error %s: %s\n", line, where.c_str(), message.c_str());
    hadError = true;
}