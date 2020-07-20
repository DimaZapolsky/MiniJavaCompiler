//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_MOD_H
#define COMPILERS_MOD_H

#include "nodes/Expr/BinaryOperation/BinaryOperation.h"

class Mod : public BinaryOperation {
 public:
  Mod(Expr *exprLeft, Expr *exprRight);
  ~Mod() = default;
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_MOD_H
