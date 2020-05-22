//
// Created by Dima Zapolsky on 20/05/2020.
//

#ifndef COMPILERS_EQUAL_H
#define COMPILERS_EQUAL_H

#include "nodes/Expr/BinaryOperation/BinaryOperation.h"

class Equal : public BinaryOperation {
public:
    Equal(Expr* leftExpr, Expr* rightExpr);
    ~Equal() = default;
};


#endif //COMPILERS_EQUAL_H
