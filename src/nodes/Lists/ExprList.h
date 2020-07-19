//
// Created by Dima Zapolsky on 20/05/2020.
//

#ifndef COMPILERS_EXPRLIST_H
#define COMPILERS_EXPRLIST_H

#include <vector>

#include "nodes/Expr/Expr.h"
#include "../../Visitors/Visitable.h"

class ExprList : public Visitable {
public:
    ExprList();
    ~ExprList() = default;
    void AddExpr(Expr* expr);
  const std::vector<Expr *> &GetExpressions() const;
 private:
    std::vector<Expr*> expressions_;
};


#endif //COMPILERS_EXPRLIST_H
