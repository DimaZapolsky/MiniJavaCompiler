//
// Created by Dima Zapolsky on 18.07.2020.
//

#include "BooleanArray.h"

#include <utility>

objects::BooleanArray::BooleanArray() {
  type_ = Types::BooleanArray;
}

objects::BooleanArray::BooleanArray(std::vector<bool> value) {
  type_ = Types::BooleanArray;
  value_ = std::move(value);
}

int &objects::BooleanArray::GetIntValue() {
  throw std::runtime_error("Can't get int from boolean array");
}

bool &objects::BooleanArray::GetBooleanValue() {
  throw std::runtime_error("Can't get bool from int array");
}

std::vector<int> &objects::BooleanArray::GetIntArray() {
  throw std::runtime_error("Can't get int array from boolean array");
}

std::vector<bool> &objects::BooleanArray::GetBooleanArray() {
  return value_;
}
