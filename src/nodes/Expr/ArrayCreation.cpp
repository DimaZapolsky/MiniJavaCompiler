//
// Created by Dima Zapolsky on 20/05/2020.
//

#include "ArrayCreation.h"

ArrayCreation::ArrayCreation(types::SimpleType *simpleType, Expr *expr) :
    simpleType_(simpleType), expr_(expr) {}

types::SimpleType *ArrayCreation::GetSimpleType() const {
  return simpleType_;
}

Expr *ArrayCreation::GetExpr() const {
  return expr_;
}
void ArrayCreation::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
