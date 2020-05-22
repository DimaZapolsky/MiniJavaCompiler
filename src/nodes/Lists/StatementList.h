//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_STATEMENTLIST_H
#define COMPILERS_STATEMENTLIST_H

#include "nodes/Statement/Statement.h"
#include <vector>

class StatementList : public Statement {
public:
    StatementList();
    ~StatementList() = default;
    void AddStatement(Statement* statement);

private:
    std::vector<Statement*> statements_;
};


#endif //COMPILERS_STATEMENTLIST_H
