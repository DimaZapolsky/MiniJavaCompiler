//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_DIV_H
#define COMPILERS_DIV_H

#include "nodes/Expr/BinaryOperation/BinaryOperation.h"

class Div : public BinaryOperation {
 public:
  Div(Expr *leftExpr, Expr *rightExpr);
  ~Div() = default;
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_DIV_H
