//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Expr.h"
void Expr::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
