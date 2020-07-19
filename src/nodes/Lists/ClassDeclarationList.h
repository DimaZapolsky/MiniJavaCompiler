//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_CLASSESDECLARATION_H
#define COMPILERS_CLASSESDECLARATION_H

#include <vector>

#include "nodes/Declaration/ClassDeclaration.h"
#include "../../Visitors/Visitable.h"

class ClassDeclarationList : public Visitable {
public:
    ClassDeclarationList();
    ~ClassDeclarationList() = default;
    void AddClassDeclaration(ClassDeclaration* classDeclaration);
  const std::vector<ClassDeclaration *> &GetClassDeclarations() const;
 private:
    std::vector <ClassDeclaration*> classDeclarations_;
};


#endif //COMPILERS_CLASSESDECLARATION_H
