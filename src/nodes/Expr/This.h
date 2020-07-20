//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_THIS_H
#define COMPILERS_THIS_H

#include "nodes/Expr/Expr.h"

class This : public Expr {
 public:
  This() = default;
  ~This() = default;
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_THIS_H
