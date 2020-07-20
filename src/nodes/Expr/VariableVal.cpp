//
// Created by Dima Zapolsky on 20/05/2020.
//

#include "VariableVal.h"

VariableVal::VariableVal(Identifier *identifier) :
    identifier_(identifier) {}

Identifier *VariableVal::GetIdentifier() const {
  return identifier_;
}
void VariableVal::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
