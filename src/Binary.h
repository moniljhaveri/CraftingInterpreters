#pragma once 
#include "Expr.h"

class Binary : public Expr 
{
    public: 
        Binary(std::shared_ptr<Expr> left, Token::Token op, std::shared_ptr<Expr> right):Expr(left, op, right)
        {};
};

