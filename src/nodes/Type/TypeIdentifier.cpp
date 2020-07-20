//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "TypeIdentifier.h"

types::TypeIdentifier::TypeIdentifier(Identifier *identifier) :
    identifier_(identifier) {}

std::string types::TypeIdentifier::GetIdentifier() {
  return identifier_->GetIdentifier();
}
Identifier *types::TypeIdentifier::GetIdentifierPtr() {
  return identifier_;
}
void types::TypeIdentifier::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
