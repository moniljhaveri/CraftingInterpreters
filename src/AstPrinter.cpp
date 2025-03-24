#include <string>
#include <vector>
#include <iostream>

#include "AstPrinter.h"
#include "Expr.h"


void AstPrinter::print(std::shared_ptr<Expr> expr) {
    expr->accept(*this);
}

void AstPrinter::parenthesize(const std::string& name, std::initializer_list<std::shared_ptr<Expr>> exprs)
{
    std::cout << "(" << name; 
    for(const auto expr :  exprs)
    {
        std::cout << " ";
        expr->accept(*this); 
    }
    std::cout << ")";

}

void AstPrinter::visitBinary(const Binary& expr)
{
    parenthesize(expr.op.lexeme, {expr.left, expr.right});
}

void AstPrinter::visitLiteral(const Literal& expr)
{
    std::cout << expr.op.lexeme; 
}

void AstPrinter::visitUnary(const Unary& expr)
{
    parenthesize(expr.op.lexeme, {expr.right});
}

void AstPrinter::visitAssign(const Assign& expr)
{
    std::cout << "(Assign " << expr.name.lexeme << " "; 
    print(expr.value); 
    std::cout << ")"; 
}

void AstPrinter::visitLogical(const Logical& expr)
{

}

void AstPrinter::visitGrouping(const Grouping& expr)
{
    parenthesize("group", {expr.expr});
}

void AstPrinter::visitVar(const Var& expr)
{
    std::cout << expr.name.lexeme; 
}

void AstPrinter::visitCall(const Call& expr)
{

}

