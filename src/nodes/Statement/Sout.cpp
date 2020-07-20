//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Sout.h"

Sout::Sout(Expr *expr) :
    expr_(expr) {}
Expr *Sout::GetExpr() const {
  return expr_;
}
void Sout::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
