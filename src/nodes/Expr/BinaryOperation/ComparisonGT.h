//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_COMPARISONGT_H
#define COMPILERS_COMPARISONGT_H

#include "nodes/Expr/BinaryOperation/BinaryOperation.h"

class ComparisonGT : public BinaryOperation {
public:
    ComparisonGT(Expr* leftExpr, Expr* rightExpr);
    ~ComparisonGT() = default;
};


#endif //COMPILERS_COMPARISONGT_H
