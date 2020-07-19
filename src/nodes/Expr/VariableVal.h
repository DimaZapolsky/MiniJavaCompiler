//
// Created by Dima Zapolsky on 20/05/2020.
//

#ifndef COMPILERS_VARIABLEVAL_H
#define COMPILERS_VARIABLEVAL_H

#include "nodes/Expr/Expr.h"
#include "nodes/Identifier.h"

class VariableVal : public Expr {
public:
    VariableVal(Identifier* identifier);
    ~VariableVal() = default;
  Identifier *GetIdentifier() const;
 private:
    Identifier* identifier_;
};


#endif //COMPILERS_VARIABLEVAL_H
