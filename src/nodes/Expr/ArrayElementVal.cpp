//
// Created by Dima Zapolsky on 20/05/2020.
//

#include "ArrayElementVal.h"

ArrayElementVal::ArrayElementVal(Expr *expr, Expr *index) :
    expr_(expr), index_(index) {}

Expr *ArrayElementVal::GetExpr() const {
  return expr_;
}

Expr *ArrayElementVal::GetIndex() const {
  return index_;
}
