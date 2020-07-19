//
// Created by Dima Zapolsky on 20/05/2020.
//

#include "Variable.h"

Variable::Variable(Identifier *identifier) :
    identifier_(identifier) {}
Identifier *Variable::GetIdentifier() const {
  return identifier_;
}