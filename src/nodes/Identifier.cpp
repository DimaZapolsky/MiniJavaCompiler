//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Identifier.h"

Identifier::Identifier(const std::string &s) : identifier_(s) {}

std::string Identifier::GetIdentifier() {
    return identifier_;
}
