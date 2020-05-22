//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_METHODINVOCATION_H
#define COMPILERS_METHODINVOCATION_H

#include "Statement.h"
#include "nodes/Expr/Expr.h"
#include "nodes/Identifier.h"
#include "nodes/lists/ExprList.h"

class MethodInvocation : public Statement {
public:
    MethodInvocation(Expr* expr, Identifier* identifier, ExprList* exprList);
    MethodInvocation(Expr* expr, Identifier* identifier);
    ~MethodInvocation() = default;

private:
    Expr* expr_;
    Identifier* identifier_;
    ExprList* exprList_;
};


#endif //COMPILERS_METHODINVOCATION_H
