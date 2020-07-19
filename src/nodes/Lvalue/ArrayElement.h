//
// Created by Dima Zapolsky on 20/05/2020.
//

#ifndef COMPILERS_ARRAYELEMENT_H
#define COMPILERS_ARRAYELEMENT_H

#include "Lvalue.h"
#include "nodes/Identifier.h"
#include "nodes/Expr/Expr.h"

class ArrayElement : public Lvalue {
public:
    ArrayElement(Identifier* identifier, Expr* expr);
    ~ArrayElement() = default;
  Identifier *GetIdentifier() const;
  Expr *GetExpr() const;
 private:
    Identifier* identifier_;
    Expr* expr_;
};


#endif //COMPILERS_ARRAYELEMENT_H
