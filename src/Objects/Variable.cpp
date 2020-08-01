//
// Created by Dima Zapolsky on 31.07.2020.
//

#include "Variable.h"

namespace objects {

Variable::Variable(Identifier *identifier, types::Type *type) : identifier_(identifier), var_type_(type) {
  type_ = Types::Variable_t;
}

Identifier *Variable::GetIdentifier() const {
  return identifier_;
}

types::Type *Variable::GetVarType() const {
  return var_type_;
}
std::string Variable::GetTypeIdentifier() {
  return var_type_->GetIdentifier() + "_var";
}

}