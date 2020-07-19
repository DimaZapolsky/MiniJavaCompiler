//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_PROGRAM_H
#define COMPILERS_PROGRAM_H

#include "MainClass.h"
#include "nodes/Lists/ClassDeclarationList.h"
#include "../Visitors/Visitable.h"

class Program : public Visitable {
public:
    Program(MainClass* mainClass, ClassDeclarationList* classDeclarationList);
    ~Program() = default;
  MainClass *GetMainClass() const;
  ClassDeclarationList *GetClassDeclarationList() const;

 private:
  MainClass* mainClass_;
  ClassDeclarationList* classDeclarationList_;
};


#endif //COMPILERS_PROGRAM_H
