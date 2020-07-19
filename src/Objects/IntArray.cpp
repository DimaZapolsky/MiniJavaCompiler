//
// Created by Dima Zapolsky on 18.07.2020.
//

#include "IntArray.h"

#include <utility>

objects::IntArray::IntArray() {
  type_ = Types::IntArray;
}

objects::IntArray::IntArray(std::vector<int> value) {
  type_ = Types::IntArray;
  value_ = std::make_shared<std::vector<int>>(value);
}

int &objects::IntArray::GetIntValue() {
  throw std::runtime_error("Can't get int array from int array");
}

bool &objects::IntArray::GetBooleanValue() {
  throw std::runtime_error("Can't get boolean array from int array");
}

std::vector<int> &objects::IntArray::GetIntArray() {
  return *value_;
}

std::vector<bool> &objects::IntArray::GetBooleanArray() {
  throw std::runtime_error("Can't get boolean array from int array");
}

bool objects::IntArray::IsInitialized() {
  return value_ != nullptr;
}
