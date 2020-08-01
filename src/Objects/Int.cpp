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
  value_ = value;
};

int &objects::Int::GetIntValue() {
  return value_;
}

bool &objects::Int::GetBooleanValue() {
  throw std::runtime_error("Can't get boolean from int");
}

std::vector<std::shared_ptr<objects::BaseObject>> &objects::Int::GetIntArray() {
  throw std::runtime_error("Can't get int array from int");
}

std::vector<std::shared_ptr<objects::BaseObject>> &objects::Int::GetBooleanArray() {
  throw std::runtime_error("Can't get boolean array from int");
}

std::string objects::Int::GetTypeIdentifier() {
  return "int";
}
