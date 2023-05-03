#pragma once

#include "BinaryExpr.hpp"

class Modulo : public BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override;
    // void print(double val) const override;
};
