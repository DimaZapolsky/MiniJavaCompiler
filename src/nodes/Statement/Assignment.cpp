//
// Created by Dima Zapolsky on 20/05/2020.
//

#include "Assignment.h"

Assignment::Assignment(Lvalue *lvalue, Expr *expr) :
    lvalue_(lvalue), expr_(expr) {}
Lvalue *Assignment::GetLvalue() const {
  return lvalue_;
}
Expr *Assignment::GetExpr() const {
  return expr_;
}
void Assignment::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
