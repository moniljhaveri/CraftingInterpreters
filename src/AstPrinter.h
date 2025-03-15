#pragma once 
#include <iostream> 
#include <string>
#include "Visitor.h"
#include "Expr.h"

class AstPrinter : public Visitor<Expr>
{
    public: 
        AstPrinter() = default; 
        std::string print(Expr expr);
    private: 

};