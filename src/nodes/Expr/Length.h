//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_LENGTH_H
#define COMPILERS_LENGTH_H

#include "nodes/Expr/Expr.h"

class Length : public Expr {
 public:
  explicit Length(Expr *expr);
  ~Length() = default;
  Expr *GetExpr() const;
  void Accept(BaseVisitor *visitor) override;
 private:
  Expr *expr_;
};

#endif //COMPILERS_LENGTH_H
