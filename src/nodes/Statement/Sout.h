//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_SOUT_H
#define COMPILERS_SOUT_H

#include "Statement.h"
#include "nodes/Expr/Expr.h"

class Sout : public Statement {
public:
    Sout(Expr* expr);
    ~Sout() = default;

private:
    Expr* expr_;
};


#endif //COMPILERS_SOUT_H
