//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_OBJECTCREATION_H
#define COMPILERS_OBJECTCREATION_H

#include "nodes/Expr/Expr.h"
#include "nodes/Type/TypeIdentifier.h"

class ObjectCreation : public Expr {
 public:
  explicit ObjectCreation(types::TypeIdentifier *typeIdentifier);
  ~ObjectCreation() = default;
  types::TypeIdentifier *GetTypeIdentifier() const;
  void Accept(BaseVisitor *visitor) override;
 private:
  types::TypeIdentifier *typeIdentifier_;
};

#endif //COMPILERS_OBJECTCREATION_H
