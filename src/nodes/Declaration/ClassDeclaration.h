//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_CLASSDECLARATION_H
#define COMPILERS_CLASSDECLARATION_H

#include "nodes/Lists/Formals.h"
#include "nodes/Identifier.h"
#include "nodes/Lists/DeclarationList.h"

class ClassDeclaration : public Declaration {
public:
    ClassDeclaration(Identifier* identifier, DeclarationList* statementList);
    ClassDeclaration(Identifier* identifier, Identifier* extends, DeclarationList* statementList);
    ~ClassDeclaration() = default;
  Identifier *GetIdentifier() const;
  Identifier *GetExtends() const;
  DeclarationList *GetDeclarationList() const;

 private:
    Identifier* identifier_;
    Identifier* extends_;
    DeclarationList* declarationList_;
};


#endif //COMPILERS_CLASSDECLARATION_H
