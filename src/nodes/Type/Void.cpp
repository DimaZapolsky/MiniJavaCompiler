//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Void.h"

std::string types::Void::GetIdentifier() {
  return "void";
}
void types::Void::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
