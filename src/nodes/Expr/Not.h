//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_NOT_H
#define COMPILERS_NOT_H

#include "nodes/Expr/Expr.h"

class Not : public Expr {
public:
    Not(Expr* expr);
    ~Not() = default;
  Expr *GetExpr() const;
 private:
    Expr* expr_;
};


#endif //COMPILERS_NOT_H
