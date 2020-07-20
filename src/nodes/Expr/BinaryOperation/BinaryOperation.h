//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_BINARYOPERATION_H
#define COMPILERS_BINARYOPERATION_H

#include "nodes/Expr/Expr.h"

class BinaryOperation : public Expr {
 public:
  BinaryOperation(Expr *l_expr, Expr *r_expr);
  ~BinaryOperation() = default;
  Expr *GetLExpr() const;
  Expr *GetRExpr() const;
  void Accept(BaseVisitor *visitor) override;
 private:
  Expr *l_expr_;
  Expr *r_expr_;
};

#endif //COMPILERS_BINARYOPERATION_H
