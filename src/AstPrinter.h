#pragma once 
#include <iostream> 
#include <initializer_list> // for std::initializer_list
#include <string>
#include <memory>
#include "Visitor.h"
#include "Expr.h"
#include "NodeType.h"

class AstPrinter : public Visitor
{
    public: 
        AstPrinter() = default; 
        void print(std::shared_ptr<Expr> expr);
        void visitBinary(const Binary& expr) override; 
        void visitLiteral(const Literal& expr) override;
        void visitLogical(const Logical& expr) override;
        void visitAssign(const Assign& expr) override;
        void visitCall(const Call& expr) override;
        void visitGrouping(const Grouping& expr) override;
        void visitUnary(const Unary& expr) override; 
        void visitVar(const Var& expr) override; 
    private: 
        std::string parenthesize(const std::string& name, std::initializer_list<std::shared_ptr<Expr>>  exprs);

};