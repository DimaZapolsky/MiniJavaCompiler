//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_SUM_H
#define COMPILERS_SUM_H

#include "nodes/Expr/BinaryOperation/BinaryOperation.h"

class Sum : public BinaryOperation {
 public:
  Sum(Expr *l_expr, Expr *r_expr);
  ~Sum() = default;
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_SUM_H
