//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Mul.h"

Mul::Mul(Expr *exprLeft, Expr *exprRight) : BinaryOperation(exprLeft, exprRight) {}
void Mul::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}

