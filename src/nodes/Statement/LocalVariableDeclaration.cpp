//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "LocalVariableDeclaration.h"

LocalVariableDeclaration::LocalVariableDeclaration(VariableDeclaration *variableDeclaration) :
    variableDeclaration_(variableDeclaration) {}
VariableDeclaration *LocalVariableDeclaration::GetVariableDeclaration() const {
  return variableDeclaration_;
}
void LocalVariableDeclaration::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
