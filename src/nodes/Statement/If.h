//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_IF_H
#define COMPILERS_IF_H

#include "Statement.h"
#include "nodes/Expr/Expr.h"

class If : public Statement {
public:
    If(Expr* expr, Statement* statement);
    ~If() = default;
  Expr *GetExpr() const;
  Statement *GetStatement() const;
 private:
    Expr* expr_;
    Statement* statement_;
};


#endif //COMPILERS_IF_H
