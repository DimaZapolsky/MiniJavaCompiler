//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "False.h"
void False::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
