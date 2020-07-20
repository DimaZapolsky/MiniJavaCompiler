//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_RETURN_H
#define COMPILERS_RETURN_H

#include "Statement.h"
#include "nodes/Expr/Expr.h"

class Return : public Statement {
 public:
  explicit Return(Expr *expr);
  ~Return() = default;
  Expr *GetExpr() const;
  void Accept(BaseVisitor *visitor) override;
 private:
  Expr *expr_;
};

#endif //COMPILERS_RETURN_H
