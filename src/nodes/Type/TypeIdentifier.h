//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_TYPEIDENTIFIER_H
#define COMPILERS_TYPEIDENTIFIER_H

#include "nodes/Type/SimpleType.h"
#include "nodes/Identifier.h"
#include "SimpleType.h"

namespace types {

class TypeIdentifier : public types::SimpleType {
 public:
  explicit TypeIdentifier(Identifier *identifier);
  ~TypeIdentifier() = default;
  std::string GetIdentifier() override;
  Identifier *GetIdentifierPtr();
  void Accept(BaseVisitor *visitor) override;
 private:
  Identifier *identifier_;
};

}

#endif //COMPILERS_TYPEIDENTIFIER_H
