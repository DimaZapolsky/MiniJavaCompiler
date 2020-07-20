//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Lvalue.h"
void Lvalue::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
