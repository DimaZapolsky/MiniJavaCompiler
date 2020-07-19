//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Assert.h"
#include <cassert>

Assert::Assert(Expr *expr) :
    expr_(expr){}
Expr *Assert::GetExpr() const {
  return expr_;
}