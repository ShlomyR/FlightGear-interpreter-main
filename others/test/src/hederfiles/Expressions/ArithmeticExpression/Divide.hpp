#pragma once

#include "../hederfiles/Expressions/BinaryExpr.hpp"

class Divide : public BinaryExpr
{
public:
    using BinaryExpr::BinaryExpr;
    double calc() const override;
};
