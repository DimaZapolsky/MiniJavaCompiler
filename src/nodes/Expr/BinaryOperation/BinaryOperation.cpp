//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(Expr *l_expr, Expr *r_expr) :
    l_expr_(l_expr), r_expr_(r_expr) {}

Expr *BinaryOperation::GetLExpr() const {
  return l_expr_;
}

Expr *BinaryOperation::GetRExpr() const {
  return r_expr_;
}
void BinaryOperation::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
