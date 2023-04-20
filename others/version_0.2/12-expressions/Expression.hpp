#include "Exprations.hxx"
#include <cmath>



class PlusExpr : public Expr 
{
    public:
        PlusExpr(Expr* left, Expr* right)
        :   left(left),
            right(right)
        {}
        double calc() const override 
        {
            return right->calc() + left->calc();
        }
    private:
        Expr* left;
        Expr* right;
};

class MinExpr : public Expr 
{
    public:
        MinExpr(Expr* left, Expr* right)
        :   left(left),
            right(right)
        {}
        double calc() const override 
        {
            return right->calc() - left->calc();
        }
    private:
        Expr* left;
        Expr* right;
};

class MulExpr : public Expr 
{
    public:
        MulExpr(Expr* left, Expr* right)
        :   left(left),
            right(right)
        {}
        double calc() const override 
        {
            return right->calc() * left->calc();
        }
    private:
        Expr* left;
        Expr* right;
};

class DivExpr : public Expr 
{
    public:
        DivExpr(Expr* left, Expr* right)
        :   left(left),
            right(right)
        {}
        double calc() const override 
        {
            return right->calc() / left->calc();
        }
    private:
        Expr* left;
        Expr* right;
};

class PowerExpr : public Expr 
{
    public:
        PowerExpr(Expr* left, Expr* right)
        :   left(left),
            right(right)
        {}
        double calc() const override 
        {
            return pow(right->calc() , left->calc());
        }
    private:
        Expr* left;
        Expr* right;
};

class NumberExpr : public Expr 
{
    public:
        NumberExpr(double val)
        :   m_num(val)
        {}
        double calc() const override 
        {
            return m_num;
        }
    private:
        double m_num;
};