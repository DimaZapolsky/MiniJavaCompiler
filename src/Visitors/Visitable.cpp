//
// Created by Dima Zapolsky on 13.07.2020.
//

#include "Visitable.h"
#include "BaseVisitor.h"

void Visitable::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
