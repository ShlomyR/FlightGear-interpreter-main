#pragma once

#include <cmath>

#include "BinaryExpr.hpp"

class Power : public BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override;
    // void print(double val) const override;
};
