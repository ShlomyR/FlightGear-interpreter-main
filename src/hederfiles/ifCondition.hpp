#include <vector>
#include <string>

class ifCondition
{
public:
    static int ifCon(std::vector<std::string> const&);
private:
    ifCondition(const ifCondition&) = delete;
    ifCondition& operator=(const ifCondition&) = delete;
};
