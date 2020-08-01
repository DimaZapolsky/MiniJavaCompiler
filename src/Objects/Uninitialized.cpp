//
// Created by Dima Zapolsky on 01.08.2020.
//

#include "Uninitialized.h"

#include <utility>

namespace objects {

Uninitialized::Uninitialized(std::string type) : var_type_(std::move(type)) {
  type_ = Null;
}

std::string Uninitialized::GetTypeIdentifier() {
  return var_type_;
}

}