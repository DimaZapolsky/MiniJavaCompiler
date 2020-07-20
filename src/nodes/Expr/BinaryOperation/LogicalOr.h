//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_LOGICALOR_H
#define COMPILERS_LOGICALOR_H

#include "nodes/Expr/BinaryOperation/BinaryOperation.h"

class LogicalOr : public BinaryOperation {
 public:
  LogicalOr(Expr *leftExpr, Expr *rightExpr);
  ~LogicalOr() = default;
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_LOGICALOR_H
