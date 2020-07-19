//
// Created by Dima Zapolsky on 18.07.2020.
//

#include "Int.h"

#include <utility>

objects::Int::Int() {
  type_ = Types::Int;
}

objects::Int::Int(int value) {
  type_ = Types::Int;
  value_ = std::make_shared<int>(value);
};

objects::Int::Int(std::shared_ptr<int> value) {
  type_ = Types::Int;
  value_ = std::move(value);
}

int &objects::Int::GetIntValue() {
  return *value_;
}

bool &objects::Int::GetBooleanValue() {
  throw std::runtime_error("Can't get boolean from int");
}

std::vector<int> &objects::Int::GetIntArray() {
  throw std::runtime_error("Can't get int array from int");
}

std::vector<bool> &objects::Int::GetBooleanArray() {
  throw std::runtime_error("Can't get boolean array from int");
}

bool objects::Int::IsInitialized() {
  return value_ != nullptr;
}
