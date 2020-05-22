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

class MethodDeclaration : public Declaration{
public:
    MethodDeclaration(Type* type, Identifier* identifier, Formals* formals, StatementList* statementList);
    MethodDeclaration(Type* type, Identifier* identifier, StatementList* statementList);
    ~MethodDeclaration() = default;

private:
    Type* type_;
    Identifier* identifier_;
    Formals* formals_;
    StatementList* statementList_;
};


#endif //COMPILERS_METHODDECLARATION_H
