#pragma once

#include "BinaryExpr.hpp"

class Power : public BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override;
};
