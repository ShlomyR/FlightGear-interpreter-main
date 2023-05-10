#pragma once

#include "../hederfiles/Expressions/BinaryExpr.hpp"

class Multiply : public BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override;
};
