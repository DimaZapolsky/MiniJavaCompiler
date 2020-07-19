//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "VariableDeclaration.h"

VariableDeclaration::VariableDeclaration(types::Type *type, Identifier *identifier) :
    type_(type), identifier_(identifier) {}

types::Type *VariableDeclaration::GetType() const {
  return type_;
}

Identifier *VariableDeclaration::GetIdentifier() const {
  return identifier_;
}