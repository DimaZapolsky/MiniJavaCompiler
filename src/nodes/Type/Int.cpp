//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Int.h"

std::string types::Int::GetIdentifier() {
  return "int";
}
void types::Int::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
