//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(Type *type, Identifier *identifier, Formals *formals, StatementList* statementList) :
    type_(type), identifier_(identifier), formals_(formals), statementList_(statementList) {}

MethodDeclaration::MethodDeclaration(Type *type, Identifier *identifier, StatementList* statementList) :
        type_(type), identifier_(identifier), formals_(new Formals()), statementList_(statementList) {}