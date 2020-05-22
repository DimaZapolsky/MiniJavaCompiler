//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "VariableDeclaration.h"

VariableDeclaration::VariableDeclaration(Type *type, Identifier *identifier) :
    type_(type), identifier_(identifier) {}
