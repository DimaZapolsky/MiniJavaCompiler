//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_INTEGERLITERAL_H
#define COMPILERS_INTEGERLITERAL_H

#include "nodes/Expr/Expr.h"

class IntegerLiteral : public Expr {
 public:
  explicit IntegerLiteral(int n);
  ~IntegerLiteral() = default;
  int GetValue();
  void Accept(BaseVisitor *visitor) override;
 private:
  int value_;
};

#endif //COMPILERS_INTEGERLITERAL_H
