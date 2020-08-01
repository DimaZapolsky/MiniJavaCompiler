//
// Created by Dima Zapolsky on 30.07.2020.
//

#include "Method.h"

namespace objects {

types::Type *Method::GetReturnType() {
  return return_type_;
}

Formals *Method::GetFormals() {
  return formals_;
}

Method::Method(Identifier *identifier, types::Type *return_type, Formals *formals, StatementList *statement_list)
    : identifier_(identifier), return_type_(return_type), formals_(formals), statement_list_(statement_list) {
  type_ = Types::Method;
}
Identifier *Method::GetIdentifier() const {
  return identifier_;
}
std::string Method::GetTypeIdentifier() {
  return identifier_->GetIdentifier() + "_method";
}

}