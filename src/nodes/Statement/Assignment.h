//
// Created by Dima Zapolsky on 20/05/2020.
//

#ifndef COMPILERS_ASSIGNMENT_H
#define COMPILERS_ASSIGNMENT_H

#include "Statement.h"
#include "nodes/Lvalue/Lvalue.h"
#include "nodes/Expr/Expr.h"

class Assignment : public Statement {
 public:
  Assignment(Lvalue *lvalue, Expr *expr);
  ~Assignment() = default;
  Lvalue *GetLvalue() const;
  Expr *GetExpr() const;
  void Accept(BaseVisitor *visitor) override;
 private:
  Lvalue *lvalue_;
  Expr *expr_;
};

#endif //COMPILERS_ASSIGNMENT_H
