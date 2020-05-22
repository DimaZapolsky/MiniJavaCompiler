//
// Created by Dima Zapolsky on 20/05/2020.
//

#ifndef COMPILERS_EXPRLIST_H
#define COMPILERS_EXPRLIST_H

#include "nodes/Expr/Expr.h"
#include <vector>

class ExprList {
public:
    ExprList();
    ~ExprList() = default;
    void AddExpr(Expr* expr);

private:
    std::vector<Expr*> expressions_;
};


#endif //COMPILERS_EXPRLIST_H
