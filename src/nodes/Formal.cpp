//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Formal.h"

Formal::Formal(types::Type *type, Identifier *identifier) :
    type_(type), identifier_(identifier) {}
types::Type *Formal::GetType() const {
  return type_;
}
Identifier *Formal::GetIdentifier() const {
  return identifier_;
}