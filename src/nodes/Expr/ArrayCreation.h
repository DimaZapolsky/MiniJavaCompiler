//
// Created by Dima Zapolsky on 20/05/2020.
//

#ifndef COMPILERS_ARRAYCREATION_H
#define COMPILERS_ARRAYCREATION_H

#include "Expr.h"
#include "nodes/Type/SimpleType.h"

class ArrayCreation : public Expr {
 public:
  ArrayCreation(types::SimpleType *simpleType, Expr *expr);
  ~ArrayCreation() = default;
  types::SimpleType *GetSimpleType() const;
  Expr *GetExpr() const;
  void Accept(BaseVisitor *visitor) override;

 private:
  types::SimpleType *simpleType_;
  Expr *expr_;
};

#endif //COMPILERS_ARRAYCREATION_H
