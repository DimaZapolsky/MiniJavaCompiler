//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_LOGICALAND_H
#define COMPILERS_LOGICALAND_H

#include "nodes/Expr/BinaryOperation/BinaryOperation.h"

class LogicalAnd : public BinaryOperation {
 public:
  LogicalAnd(Expr *leftExpr, Expr *rightExpr);
  ~LogicalAnd() = default;
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_LOGICALAND_H
