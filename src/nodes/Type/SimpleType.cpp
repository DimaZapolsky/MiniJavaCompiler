//
// Created by Dima Zapolsky on 20.07.2020.
//

#include "SimpleType.h"
void types::SimpleType::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
