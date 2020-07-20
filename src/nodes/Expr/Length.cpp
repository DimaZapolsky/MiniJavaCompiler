//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Length.h"

Length::Length(Expr *expr) :
    expr_(expr) {}
Expr *Length::GetExpr() const {
  return expr_;
}
void Length::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
