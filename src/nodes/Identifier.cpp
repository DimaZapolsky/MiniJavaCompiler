//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Identifier.h"

#include <utility>

Identifier::Identifier(std::string s) : identifier_(std::move(s)) {}

std::string Identifier::GetIdentifier() {
  return identifier_;
}
void Identifier::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
