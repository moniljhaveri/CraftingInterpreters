#pragma once 

class Binary;
class Literal; 
class Logical; 
class Assign; 
class Call; 
class Grouping; 
class Unary; 
class Var; 

template<typename T> 
class Visitor
{
    public: 
        ~Visitor() = default; 
        virtual T visitBinary(const Binary& expr) = 0; 
        virtual T visitLiteral(const Literal& expr) = 0; 
        virtual T visitLogical(const Logical& expr) = 0; 
        virtual T visitAssign(const Assign& expr) = 0; 
        virtual T visitCall(const Call& expr) = 0; 
        virtual T visitGrouping(const Grouping& expr) = 0; 
        virtual T visitUnary(const Unary& expr) = 0; 
        virtual T visitVar(const Var& expr) = 0; 
};