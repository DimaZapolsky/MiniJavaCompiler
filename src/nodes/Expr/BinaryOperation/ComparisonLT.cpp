//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "ComparisonLT.h"

ComparisonLT::ComparisonLT(Expr *leftExpr, Expr *rightExpr) : BinaryOperation(leftExpr, rightExpr) {}
void ComparisonLT::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
