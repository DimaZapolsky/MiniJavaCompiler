//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_VARIABLEDECLARATION_H
#define COMPILERS_VARIABLEDECLARATION_H

#include "nodes/Statement/Declaration.h"
#include "nodes/Type/Type.h"
#include "nodes/Identifier.h"

class VariableDeclaration : public Declaration {
public:
    VariableDeclaration(Type* type, Identifier* identifier);
    ~VariableDeclaration() = default;

private:
    Type* type_;
    Identifier* identifier_;
};


#endif //COMPILERS_VARIABLEDECLARATION_H