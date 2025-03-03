#pragma once 
#include <any>
#include <vector>
#include "Expr.h"

class Binary : public Expr 
{
    public: 
        Binary(std::shared_ptr<Expr> left, Token::Token op, std::shared_ptr<Expr> right): left(std::move(left)), op(std::move(op)), right(std::move(right))
        {};
    private: 
        std::shared_ptr<Expr> left; 
        Token::Token op; 
        std::shared_ptr<Expr> right; 
};


class Literal : public Expr 
{
    public: 
        Literal(std::any expr): expr(std::move(expr)){};
    private: 
        std::any expr; 
};


class Logical : public Expr 
{
    public: 
        Logical(std::shared_ptr<Expr> left, Token::Token op, std::shared_ptr<Expr> right): left(std::move(left)), op(std::move(op)), right(std::move(right))
        {};
    private: 
        std::shared_ptr<Expr> left; 
        Token::Token op; 
        std::shared_ptr<Expr> right; 
};

class Assign : public Expr 
{
    public: 
        Assign(Token::Token name, std::unique_ptr<Expr> value) : name(name), value(std::move(value))
        {}; 
    private: 
        Token::Token name; 
        std::unique_ptr<Expr> value;
};

class Call : public Expr 
{
    public: 
        Call(std::unique_ptr<Expr> callee, Token::Token paren, std::vector<std::unique_ptr<Expr>> arg);
    private: 
        std::unique_ptr<Expr> callee;
        Token::Token paren; 
        std::vector<std::unique_ptr<Expr>> arg; 
};

class Grouping : public Expr 
{
    public: 
        Grouping(std::unique_ptr<Expr> expr): expr(std::move(expr)) {};
    private: 
        std::unique_ptr<Expr> expr;
};

class Unary : public Expr 
{
    public: 
        Unary(Token::Token op, std::unique_ptr<Expr> right) : op(op), right(std::move(right)) {}; 
    private: 
        Token::Token op; 
        std::unique_ptr<Expr> right; 
}; 

class Var : public Expr 
{
    public: 
        Var(Token::Token name) : name(name){}; 
    private: 
        Token::Token name; 
}; 