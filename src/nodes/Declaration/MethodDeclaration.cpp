//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(types::Type *type,
                                     Identifier *identifier,
                                     Formals *formals,
                                     StatementList *statementList) :
    type_(type), identifier_(identifier), formals_(formals), statementList_(statementList) {}

MethodDeclaration::MethodDeclaration(types::Type *type, Identifier *identifier, StatementList *statementList) :
    type_(type), identifier_(identifier), formals_(new Formals()), statementList_(statementList) {}

types::Type *MethodDeclaration::GetType() const {
  return type_;
}

Identifier *MethodDeclaration::GetIdentifier() const {
  return identifier_;
}

Formals *MethodDeclaration::GetFormals() const {
  return formals_;
}

StatementList *MethodDeclaration::GetStatementList() const {
  return statementList_;
}
void MethodDeclaration::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
