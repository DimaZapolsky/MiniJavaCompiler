//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_CLASSESDECLARATION_H
#define COMPILERS_CLASSESDECLARATION_H

#include "nodes/Declaration/ClassDeclaration.h"
#include <vector>

class ClassDeclarationList {
public:
    ClassDeclarationList();
    ~ClassDeclarationList() = default;
    void AddClassDeclaration(ClassDeclaration* classDeclaration);

private:
    std::vector <ClassDeclaration*> classDeclarations_;
};


#endif //COMPILERS_CLASSESDECLARATION_H
