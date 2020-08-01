//
// Created by Dima Zapolsky on 30.07.2020.
//

#include "Class.h"

#include <utility>

namespace objects {

bool Class::HasMethod(std::string method) {
  if (methods_.count(method))
    return true;
  return extends_ ? extends_->HasMethod(method) : false;
}

std::shared_ptr<Method> Class::GetMethod(std::string method) {
  if (methods_.count(method)) {
    return methods_[method];
  }
  if (!extends_) {
    throw std::runtime_error("No such method(" + method + ") in class " + identifier_->GetIdentifier());
  }
  return extends_->GetMethod(method);
}

bool Class::HasVariable(std::string variable) {
  if (variables_.count(variable))
    return true;
  return extends_ ? extends_->HasVariable(variable) : false;
}

std::string Class::GetVariableType(std::string variable) {
  if (variables_.count(variable)) {
    return variables_[variable];
  }
  if (!extends_) {
    throw std::runtime_error("No such variable(" + variable + ") in class " + identifier_->GetIdentifier());
  }
  return extends_->GetVariableType(variable);
}

void Class::SetIdentifier(Identifier *identifier) {
  identifier_ = identifier;
}

void Class::SetExtends(std::shared_ptr<Class> extends) {
  extends_ = std::move(extends);
}

void Class::SetVariables(const std::unordered_map<std::string, std::string> &variables) {
  variables_ = variables;
}

void Class::SetMethods(const std::unordered_map<std::string, std::shared_ptr<Method>> &methods) {
  methods_ = methods;
}

Identifier *Class::GetIdentifier() const {
  return identifier_;
}

Class::Class() {
  type_ = Types::Class;
}

std::string Class::GetTypeIdentifier() {
  return identifier_->GetIdentifier() + "_class";
}

}