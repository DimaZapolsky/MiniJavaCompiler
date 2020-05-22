//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "ClassDeclarationList.h"

ClassDeclarationList::ClassDeclarationList() : classDeclarations_() {}

void ClassDeclarationList::AddClassDeclaration(ClassDeclaration *classDeclaration) {
    classDeclarations_.push_back(classDeclaration);
}