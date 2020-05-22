//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "TypeIdentifier.h"

TypeIdentifier::TypeIdentifier(Identifier* identifier) :
    identifier_(identifier) {}

std::string TypeIdentifier::GetIdentifier() {
    return identifier_->GetIdentifier();
}