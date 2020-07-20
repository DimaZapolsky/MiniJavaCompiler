//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_COMPARISONLT_H
#define COMPILERS_COMPARISONLT_H

#include "nodes/Expr/BinaryOperation/BinaryOperation.h"

class ComparisonLT : public BinaryOperation {
 public:
  ComparisonLT(Expr *leftExpr, Expr *rightExpr);
  ~ComparisonLT() = default;
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_COMPARISONLT_H
