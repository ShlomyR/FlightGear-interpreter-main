#pragma once

#include "../hederfiles/Expressions/BinaryExpr.hpp"

class Pluse : public BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override;
};
