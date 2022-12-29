#include <string>
#include <vector>

class ShuntingYardToken
{
public:
    enum class Type {
        Unknown,
        Number,
        Operator,
        LeftParen,
        RightParen,
    };
    const Type type;
    const std::string str;
    const int precedence;
    const bool rightAssociative;
public:
    ShuntingYardToken(Type t, const std::string& s, int prec, bool ra);
    static double shuntingYardF(std::string const expr);
    static void strToInfix();
    static void checkMinus();
    static std::string getInfix();
    static std::vector<std::string> getCopy();
    static void setInfix(std::string);
    static void setCopy(std::vector<std::string>);
    static void setCopy(std::string v,int i);
private:
    static std::string infix_str;
    static std::vector<std::string> copy_line;
    
};