//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_METHODDECLARATION_H
#define COMPILERS_METHODDECLARATION_H

#include "nodes/Statement/Declaration.h"
#include "nodes/Type/Type.h"
#include "nodes/Identifier.h"
#include "nodes/Lists/Formals.h"
#include "nodes/Lists/StatementList.h"

class MethodDeclaration : public Declaration {
public:
    MethodDeclaration(types::Type* type, Identifier* identifier, Formals* formals, StatementList* statementList);
    MethodDeclaration(types::Type* type, Identifier* identifier, StatementList* statementList);
    ~MethodDeclaration() = default;
  types::Type *GetType() const;
  Identifier *GetIdentifier() const;
  Formals *GetFormals() const;
  StatementList *GetStatementList() const;

 private:
    types::Type* type_;
    Identifier* identifier_;
    Formals* formals_;
    StatementList* statementList_;
};


#endif //COMPILERS_METHODDECLARATION_H
