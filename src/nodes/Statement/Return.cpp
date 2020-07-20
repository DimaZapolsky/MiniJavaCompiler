//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Return.h"

Return::Return(Expr *expr) :
    expr_(expr) {}
Expr *Return::GetExpr() const {
  return expr_;
}
void Return::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
