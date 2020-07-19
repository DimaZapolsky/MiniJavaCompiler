//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_LENGTH_H
#define COMPILERS_LENGTH_H

#include "nodes/Expr/Expr.h"

class Length : public Expr {
public:
    Length(Expr* expr);
    ~Length() = default;
  Expr *GetExpr() const;
 private:
    Expr* expr_;
};


#endif //COMPILERS_LENGTH_H
