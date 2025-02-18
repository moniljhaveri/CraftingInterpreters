#pragma once 
#include <memory> 
#include "token.h"
class Expr 
{
    protected: 
        std::shared_ptr<Expr> left;
        Token::Token op; 
        std::shared_ptr<Expr> right;
    public: 
        Expr(std::shared_ptr<Expr>, Token::Token op, std::shared_ptr<Expr> right) : left(std::move(left)) , op(op), right(std::move(right)){}; 

};