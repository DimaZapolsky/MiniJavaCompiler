//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Not.h"

Not::Not(Expr *expr) :
    expr_(expr) {}
Expr *Not::GetExpr() const {
  return expr_;
}
void Not::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
