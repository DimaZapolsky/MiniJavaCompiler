//
// Created by Dima Zapolsky on 18.07.2020.
//

#include "IntArray.h"
#include <Objects/Uninitialized.h>

#include <utility>

objects::IntArray::IntArray() {
  type_ = Types::IntArray;
}

objects::IntArray::IntArray(size_t size) {
  for (size_t i = 0; i < size; ++i) {
    value_.push_back(std::make_shared<objects::Uninitialized>("int"));
  }
}

int &objects::IntArray::GetIntValue() {
  throw std::runtime_error("Can't get int array from int array");
}

bool &objects::IntArray::GetBooleanValue() {
  throw std::runtime_error("Can't get boolean array from int array");
}

std::vector<std::shared_ptr<objects::BaseObject>> &objects::IntArray::GetIntArray() {
  return value_;
}

std::vector<std::shared_ptr<objects::BaseObject>> &objects::IntArray::GetBooleanArray() {
  throw std::runtime_error("Can't get boolean array from int array");
}

std::string objects::IntArray::GetTypeIdentifier() {
  return "int array";
}
