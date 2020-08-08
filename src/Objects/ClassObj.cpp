//
// Created by Dima Zapolsky on 31.07.2020.
//

#include "ClassObj.h"

#include <utility>

namespace objects {

std::string ClassObj::GetTypeIdentifier() {
  return class_->GetTypeIdentifier();
}

ClassObj::ClassObj(std::shared_ptr<Class> a_class)
  : class_(a_class) {
  type_ = Types::Class;
}

std::shared_ptr<Method> ClassObj::GetMethod(Identifier* identifier) {
  return class_->GetMethod(identifier->GetIdentifier());
}

}