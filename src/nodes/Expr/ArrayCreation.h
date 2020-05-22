//
// Created by Dima Zapolsky on 20/05/2020.
//

#ifndef COMPILERS_ARRAYCREATION_H
#define COMPILERS_ARRAYCREATION_H

#include "Expr.h"
#include "nodes/Type/SimpleType.h"

class ArrayCreation : public Expr {
public:
    ArrayCreation(SimpleType* simpleType, Expr* expr);
    ~ArrayCreation() = default;

private:
    SimpleType* simpleType_;
    Expr* expr_;
};


#endif //COMPILERS_ARRAYCREATION_H
