//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_DIF_H
#define COMPILERS_DIF_H

#include "nodes/Expr/BinaryOperation/BinaryOperation.h"

class Dif : public BinaryOperation {
 public:
  Dif(Expr *leftExpr, Expr *rightExpr);
  ~Dif() = default;
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_DIF_H
