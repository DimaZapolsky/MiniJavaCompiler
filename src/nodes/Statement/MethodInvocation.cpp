//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "MethodInvocation.h"

MethodInvocation::MethodInvocation(Expr *expr, Identifier *identifier, ExprList *exprList) :
    expr_(expr), identifier_(identifier), exprList_(exprList) {}

MethodInvocation::MethodInvocation(Expr *expr, Identifier *identifier) :
    expr_(expr), identifier_(identifier), exprList_(new ExprList()) {}
Expr *MethodInvocation::GetExpr() const {
  return expr_;
}
Identifier *MethodInvocation::GetIdentifier() const {
  return identifier_;
}
ExprList *MethodInvocation::GetExprList() const {
  return exprList_;
}
void MethodInvocation::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
