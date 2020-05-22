//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_MUL_H
#define COMPILERS_MUL_H

#include "nodes/Expr/BinaryOperation/BinaryOperation.h"

class Mul : public BinaryOperation {
public:
    Mul(Expr* exprLeft, Expr* exprRight);
    ~Mul() = default;
};


#endif //COMPILERS_MUL_H
