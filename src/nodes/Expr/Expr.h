//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_EXPR_H
#define COMPILERS_EXPR_H

#include "../../Visitors/Visitable.h"

class Expr : public Visitable {
 public:
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_EXPR_H
