//
// Created by Dima Zapolsky on 18.07.2020.
//

#include "BooleanArray.h"

#include <utility>
#include <Objects/Uninitialized.h>

objects::BooleanArray::BooleanArray() {
  type_ = Types::BooleanArray;
}

int &objects::BooleanArray::GetIntValue() {
  throw std::runtime_error("Can't get int from boolean array");
}

bool &objects::BooleanArray::GetBooleanValue() {
  throw std::runtime_error("Can't get bool from int array");
}

std::vector<std::shared_ptr<objects::BaseObject>> &objects::BooleanArray::GetIntArray() {
  throw std::runtime_error("Can't get int array from boolean array");
}

std::vector<std::shared_ptr<objects::BaseObject>> &objects::BooleanArray::GetBooleanArray() {
  return value_;
}

std::string objects::BooleanArray::GetTypeIdentifier() {
  return "boolean array";
}
objects::BooleanArray::BooleanArray(size_t size) {
  for (size_t i = 0; i < size; ++i) {
    value_.push_back(std::make_shared<objects::Uninitialized>("boolean"));
  }
}
