

class Expr 
{
    public:
        virtual double calc() const = 0;
        virtual ~Expr() = default;
};