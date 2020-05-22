//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_LOCALVARIABLEDECLARATION_H
#define COMPILERS_LOCALVARIABLEDECLARATION_H

#include "Statement.h"
#include "nodes/Declaration/VariableDeclaration.h"

class LocalVariableDeclaration : public Statement {
public:
    LocalVariableDeclaration(VariableDeclaration* variableDeclaration);
    ~LocalVariableDeclaration() = default;

private:
    VariableDeclaration* variableDeclaration_;
};


#endif //COMPILERS_LOCALVARIABLEDECLARATION_H
