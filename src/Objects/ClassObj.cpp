//
// Created by Dima Zapolsky on 31.07.2020.
//

#include "ClassObj.h"

#include <utility>

namespace objects {

std::string ClassObj::GetTypeIdentifier() {
  return class_->GetTypeIdentifier();
}

ClassObj::ClassObj(Identifier *identifier, std::shared_ptr<Class> a_class, std::shared_ptr<ScopeLayer> layer)
  : identifier_(identifier), class_(std::move(a_class)), layer_(std::move(layer)) {}

}