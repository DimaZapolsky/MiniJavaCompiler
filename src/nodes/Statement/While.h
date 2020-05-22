//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_WHILE_H
#define COMPILERS_WHILE_H

#include "nodes/Statement/Statement.h"
#include "nodes/Expr/Expr.h"

class While : public Statement {
public:
    While(Expr* expr, Statement* statement);
    ~While() = default;

private:
    Expr* expr_;
    Statement* statement_;
};


#endif //COMPILERS_WHILE_H
