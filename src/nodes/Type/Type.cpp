//
// Created by Dima Zapolsky on 20.07.2020.
//

#include "Type.h"
void types::Type::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
