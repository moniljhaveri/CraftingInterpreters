#pragma once 
#include <any>
#include <vector>
#include "Expr.h"
#include "Visitor.h"

class Binary : public Expr 
{
    public: 
        explicit Binary(std::shared_ptr<Expr> left, Token::Token op, std::shared_ptr<Expr> right): left(std::move(left)), op(std::move(op)), right(std::move(right))
        {};
        void accept(Visitor& visitor) const
        {
            visitor.visitBinary(*this);
        }

        std::shared_ptr<Expr> left; 
        Token::Token op; 
        std::shared_ptr<Expr> right; 
};


class Literal : public Expr 
{
    public: 
        explicit Literal(Token::Token& token): op(std::move(token)){};
        void accept(Visitor& visitor) const
        {
            visitor.visitLiteral(*this);
        }
        Token::Token op; 
};


class Logical : public Expr 
{
    public: 
        explicit Logical(std::shared_ptr<Expr> left, Token::Token op, std::shared_ptr<Expr> right): left(std::move(left)), op(std::move(op)), right(std::move(right))
        {};
        void accept(Visitor& visitor) const
        {
            visitor.visitLogical(*this);
        }
        std::shared_ptr<Expr> left; 
        Token::Token op; 
        std::shared_ptr<Expr> right; 
};

class Assign : public Expr 
{
    public: 
        explicit Assign(Token::Token name, std::shared_ptr<Expr> value) : name(name), value(std::move(value))
        {}; 
        void accept(Visitor& visitor) const
        {
            visitor.visitAssign(*this);
        }

        Token::Token name; 
        std::shared_ptr<Expr> value;
};

class Call : public Expr 
{
    public: 
        Call(std::shared_ptr<Expr> callee, Token::Token paren, std::vector<std::shared_ptr<Expr>> arg);
        void accept(Visitor& visitor) const
        {
            visitor.visitCall(*this);
        }
        std::shared_ptr<Expr> callee;
        Token::Token paren; 
        std::vector<std::shared_ptr<Expr>> arg; 
};

class Grouping : public Expr 
{
    public: 
        Grouping(std::shared_ptr<Expr> expr): expr(std::move(expr)) {};
        void accept(Visitor& visitor) const
        {
            visitor.visitGrouping(*this);
        }
        std::shared_ptr<Expr> expr;
};

class Unary : public Expr 
{
    public: 
        Unary(Token::Token op, std::shared_ptr<Expr> right) : op(op), right(std::move(right)) {}; 
        void accept(Visitor& visitor) const
        {
            visitor.visitUnary(*this);
        };
        Token::Token op; 
        std::shared_ptr<Expr> right; 
}; 

class Var : public Expr 
{
    public: 
        Var(Token::Token name) : name(name){}; 
        void accept(Visitor& visitor) const
        {
            visitor.visitVar(*this);
        }
        Token::Token name; 
}; 