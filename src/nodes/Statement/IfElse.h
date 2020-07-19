//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_IFELSE_H
#define COMPILERS_IFELSE_H

#include "Statement.h"
#include "nodes/Expr/Expr.h"

class IfElse : public Statement {
public:
    IfElse(Expr* expr, Statement* statementTrue, Statement* statementFalse);
    ~IfElse() = default;
  Expr *GetExpr() const;
  Statement *GetStatementTrue() const;
  Statement *GetStatementFalse() const;
 private:
    Expr* expr_;
    Statement* statementTrue_;
    Statement* statementFalse_;
};


#endif //COMPILERS_IFELSE_H
