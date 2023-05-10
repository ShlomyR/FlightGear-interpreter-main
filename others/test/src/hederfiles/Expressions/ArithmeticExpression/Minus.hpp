#pragma once

#include "../hederfiles/Expressions/BinaryExpr.hpp"

class Minus : public BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override;
};