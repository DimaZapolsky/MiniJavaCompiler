//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_MAINCLASS_H
#define COMPILERS_MAINCLASS_H

#include "Identifier.h"
#include "nodes/lists/StatementList.h"

class MainClass {
public:
    MainClass(Identifier* identifier, StatementList* statementList);
    ~MainClass() = default;

private:
    Identifier* identifier_;
    StatementList* statementList_;
};


#endif //COMPILERS_MAINCLASS_H
