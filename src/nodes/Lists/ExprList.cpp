//
// Created by Dima Zapolsky on 20/05/2020.
//

#include "ExprList.h"

ExprList::ExprList() :
    expressions_() {}

void ExprList::AddExpr(Expr *expr) {
    expressions_.push_back(expr);
}

const std::vector<Expr *> &ExprList::GetExpressions() const {
  return expressions_;
}