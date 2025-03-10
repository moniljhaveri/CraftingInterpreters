#pragma once 
#include <any>
#include <vector>
#include "Expr.h"
#include "Visitor.h"

class Binary : public Expr 
{
    public: 
        Binary(std::shared_ptr<Expr> left, Token::Token op, std::shared_ptr<Expr> right): left(std::move(left)), op(std::move(op)), right(std::move(right))
        {};
        std::any accept(Visitor<std::any>& visitor) const
        {
            return visitor.visitBinary(*this);
        }
    private: 
        std::shared_ptr<Expr> left; 
        Token::Token op; 
        std::shared_ptr<Expr> right; 
};


class Literal : public Expr 
{
    public: 
        Literal(std::any expr): expr(std::move(expr)){};
        std::any accept(Visitor<std::any>& visitor) const
        {
            return visitor.visitLiteral(*this);
        }
    private: 
        std::any expr; 
};


class Logical : public Expr 
{
    public: 
        Logical(std::shared_ptr<Expr> left, Token::Token op, std::shared_ptr<Expr> right): left(std::move(left)), op(std::move(op)), right(std::move(right))
        {};
        std::any accept(Visitor<std::any>& visitor) const
        {
            return visitor.visitLogical(*this);
        }
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
        std::any accept(Visitor<std::any>& visitor) const
        {
            return visitor.visitAssign(*this);
        }

    private: 
        Token::Token name; 
        std::unique_ptr<Expr> value;
};

class Call : public Expr 
{
    public: 
        Call(std::unique_ptr<Expr> callee, Token::Token paren, std::vector<std::unique_ptr<Expr>> arg);
        std::any accept(Visitor<std::any>& visitor) const
        {
            return visitor.visitCall(*this);
        }
    private: 
        std::unique_ptr<Expr> callee;
        Token::Token paren; 
        std::vector<std::unique_ptr<Expr>> arg; 
};

class Grouping : public Expr 
{
    public: 
        Grouping(std::unique_ptr<Expr> expr): expr(std::move(expr)) {};
        std::any accept(Visitor<std::any>& visitor) const
        {
            return visitor.visitGrouping(*this);
        }
    private: 
        std::unique_ptr<Expr> expr;
};

class Unary : public Expr 
{
    public: 
        Unary(Token::Token op, std::unique_ptr<Expr> right) : op(op), right(std::move(right)) {}; 
        std::any accept(Visitor<std::any>& visitor) const
        {
            return visitor.visitUnary(*this);
        };
    private: 
        Token::Token op; 
        std::unique_ptr<Expr> right; 
}; 

class Var : public Expr 
{
    public: 
        Var(Token::Token name) : name(name){}; 
        std::any accept(Visitor<std::any>& visitor) const
        {
            return visitor.visitVar(*this);
        }
    private: 
        Token::Token name; 
}; 