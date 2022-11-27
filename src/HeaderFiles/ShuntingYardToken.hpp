#include <string>

class ShuntingYardToken {
public:
    enum class Type {
        Unknown,
        Number,
        Operator,
        LeftParen,
        RightParen,
    };
    
    ShuntingYardToken(Type t, const std::string& s, int prec = -1, bool ra = false) 
        : type { t }, str ( s ), precedence { prec }, rightAssociative { ra }
        {}

    const Type type;
    const std::string str;
    const int precedence;
    const bool rightAssociative;
    static double shuntingYardF(std::string expr);
    static std::string infix_str;
    static std::vector<std::string> copy_line;
    static void strToInfix();
    static void checkMinus();
private:
    
};