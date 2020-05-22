//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "ArrayType.h"

ArrayType::ArrayType(SimpleType *simpleType) :
    simpleType_(simpleType) {}

SimpleType* ArrayType::GetSimpleType() {
    return simpleType_;
}

std::string ArrayType::GetIdentifier() {
    return simpleType_->GetIdentifier() + "_array";
}