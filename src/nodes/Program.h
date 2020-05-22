//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_PROGRAM_H
#define COMPILERS_PROGRAM_H

#include "MainClass.h"
#include "nodes/lists/ClassDeclarationList.h"

class Program {
public:
    Program(MainClass* mainClass, ClassDeclarationList* classDeclarationList);
    ~Program() = default;

private:
    MainClass* mainClass_;
    ClassDeclarationList* classDeclarationList_;
};


#endif //COMPILERS_PROGRAM_H
