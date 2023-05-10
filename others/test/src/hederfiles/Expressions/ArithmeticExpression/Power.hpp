#pragma once

#include <cmath>

#include "../hederfiles/Expressions/BinaryExpr.hpp"

class Power : public BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override;
};
