//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_TRUE_H
#define COMPILERS_TRUE_H

#include "nodes/Expr/Expr.h"

class True : public Expr {
 public:
  True() = default;
  ~True() = default;
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_TRUE_H
