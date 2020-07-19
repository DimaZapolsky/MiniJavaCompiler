//
// Created by Dima Zapolsky on 18.07.2020.
//

#include "Boolean.h"

#include <utility>

objects::Boolean::Boolean() {
  type_ = Types::Boolean;
}

objects::Boolean::Boolean(bool value) {
  type_ = Types::Boolean;
  value_ = std::make_shared<bool>(value);
}

objects::Boolean::Boolean(std::shared_ptr<bool> value) {
  type_ = Types::Boolean;
  value_ = std::move(value);
}

int &objects::Boolean::GetIntValue() {
  throw std::runtime_error("Can't get int from boolean");
}

bool &objects::Boolean::GetBooleanValue() {
  return *value_;
}

std::vector<int> &objects::Boolean::GetIntArray() {
  throw std::runtime_error("Can't get int array from boolean");
}

std::vector<bool> &objects::Boolean::GetBooleanArray() {
  throw std::runtime_error("Can't get boolean array from boolean");
}

bool objects::Boolean::IsInitialized() {
  return value_ != nullptr;
}

