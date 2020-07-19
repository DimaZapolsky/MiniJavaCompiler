//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Program.h"

Program::Program(MainClass *mainClass, ClassDeclarationList* classDeclarationList) :
    mainClass_(mainClass), classDeclarationList_(classDeclarationList) {}

MainClass *Program::GetMainClass() const {
  return mainClass_;
}

ClassDeclarationList *Program::GetClassDeclarationList() const {
  return classDeclarationList_;
}