//
// Created by Dima Zapolsky on 20/05/2020.
//

#ifndef COMPILERS_ARRAYELEMENTVAL_H
#define COMPILERS_ARRAYELEMENTVAL_H

#include "Expr.h"

class ArrayElementVal : public Expr {
public:
    ArrayElementVal(Expr* expr, Expr* index);
    ~ArrayElementVal() = default;

private:
    Expr* expr_;
    Expr* index_;
};


#endif //COMPILERS_ARRAYELEMENTVAL_H