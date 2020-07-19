//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "ClassDeclaration.h"

ClassDeclaration::ClassDeclaration(Identifier *identifier, DeclarationList *declarationList) :
    identifier_(identifier), extends_(nullptr), declarationList_(declarationList) {}

ClassDeclaration::ClassDeclaration(Identifier *identifier, Identifier* extends, DeclarationList *declarationList) :
    identifier_(identifier), extends_(extends), declarationList_(declarationList) {}

Identifier *ClassDeclaration::GetIdentifier() const {
  return identifier_;
}

Identifier *ClassDeclaration::GetExtends() const {
  return extends_;
}

DeclarationList *ClassDeclaration::GetDeclarationList() const {
  return declarationList_;
}
