//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "If.h"

If::If(Expr *expr, Statement *statement) :
    expr_(expr), statement_(statement) {}
Expr *If::GetExpr() const {
  return expr_;
}
Statement *If::GetStatement() const {
  return statement_;
}
void If::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
