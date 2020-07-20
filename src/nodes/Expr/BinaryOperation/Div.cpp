//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Div.h"

Div::Div(Expr *leftExpr, Expr *rightExpr) : BinaryOperation(leftExpr, rightExpr) {}
void Div::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
