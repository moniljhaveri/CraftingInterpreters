#pragma once 
#include <memory> 
#include <any>
#include "token.h"
#include "Visitor.h"
class Expr 
{
    public: 
        virtual ~Expr() = default; 
        virtual void accept(Visitor& visitor) const = 0;
};