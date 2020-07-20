//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_ARRAYTYPE_H
#define COMPILERS_ARRAYTYPE_H

#include "Type.h"
#include "SimpleType.h"

namespace types {

class ArrayType : public Type {
 public:
  explicit ArrayType(SimpleType *simpleType);
  ~ArrayType() = default;
  SimpleType *GetSimpleType();
  std::string GetIdentifier() override;
  void Accept(BaseVisitor *visitor) override;
 private:
  SimpleType *simpleType_;
};

}

#endif //COMPILERS_ARRAYTYPE_H
