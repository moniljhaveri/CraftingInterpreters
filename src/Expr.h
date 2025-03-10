#pragma once 
#include <memory> 
#include <any>
#include "token.h"
#include "Visitor.h"
class Expr 
{
    public: 
        ~Expr() = default; 
        virtual std::any accept(Visitor<std::any>& visitor) const = 0;
};