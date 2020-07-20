//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "IfElse.h"

IfElse::IfElse(Expr *expr, Statement *statementTrue, Statement *statementFalse) :
    expr_(expr), statementTrue_(statementTrue), statementFalse_(statementFalse) {}
Expr *IfElse::GetExpr() const {
  return expr_;
}
Statement *IfElse::GetStatementTrue() const {
  return statementTrue_;
}
Statement *IfElse::GetStatementFalse() const {
  return statementFalse_;
}
void IfElse::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
