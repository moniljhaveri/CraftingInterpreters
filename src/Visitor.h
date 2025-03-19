#pragma once 

class Binary;
class Literal; 
class Logical; 
class Assign; 
class Call; 
class Grouping; 
class Unary; 
class Var; 

class Visitor
{
    public: 
        ~Visitor() = default; 
        virtual void visitBinary(const Binary& expr) = 0; 
        virtual void visitLiteral(const Literal& expr) = 0; 
        virtual void visitLogical(const Logical& expr) = 0; 
        virtual void visitAssign(const Assign& expr) = 0; 
        virtual void visitCall(const Call& expr) = 0; 
        virtual void visitGrouping(const Grouping& expr) = 0; 
        virtual void visitUnary(const Unary& expr) = 0; 
        virtual void visitVar(const Var& expr) = 0; 
};