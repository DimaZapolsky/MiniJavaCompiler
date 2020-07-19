//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "ArrayType.h"
#include "SimpleType.h"

types::ArrayType::ArrayType(SimpleType *simpleType) :
    simpleType_(simpleType) {}

types::SimpleType* types::ArrayType::GetSimpleType() {
    return simpleType_;
}

std::string types::ArrayType::GetIdentifier() {
    return simpleType_->GetIdentifier() + "_array";
}