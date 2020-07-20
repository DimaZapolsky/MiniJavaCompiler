//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Dif.h"

Dif::Dif(Expr *leftExpr, Expr *rightExpr) : BinaryOperation(leftExpr, rightExpr) {}
void Dif::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}

