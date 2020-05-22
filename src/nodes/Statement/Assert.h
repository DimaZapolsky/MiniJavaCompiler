//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_ASSERT_H
#define COMPILERS_ASSERT_H

#include "Statement.h"
#include "nodes/Expr/Expr.h"

class Assert : public Statement {
public:
    Assert(Expr* expr);
    ~Assert();

private:
    Expr* expr_;
};


#endif //COMPILERS_ASSERT_H