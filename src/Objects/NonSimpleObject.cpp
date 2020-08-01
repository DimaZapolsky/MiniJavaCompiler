//
// Created by Dima Zapolsky on 31.07.2020.
//

#include "NonSimpleObject.h"

int &objects::NonSimpleObject::GetIntValue() {
  throw std::runtime_error("Type mismatch: required int, have " + GetTypeIdentifier());
}

bool &objects::NonSimpleObject::GetBooleanValue() {
  throw std::runtime_error("Type mismatch: required boolean, have " + GetTypeIdentifier());
}

std::vector<std::shared_ptr<objects::BaseObject>> &objects::NonSimpleObject::GetIntArray() {
  throw std::runtime_error("Type mismatch: required int array, have " + GetTypeIdentifier());
}

std::vector<std::shared_ptr<objects::BaseObject>> &objects::NonSimpleObject::GetBooleanArray() {
  throw std::runtime_error("Type mismatch: required boolean array, have " + GetTypeIdentifier());
}
