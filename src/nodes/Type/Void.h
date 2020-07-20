//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_VOID_H
#define COMPILERS_VOID_H

#include "nodes/Type/SimpleType.h"
#include "SimpleType.h"

namespace types {

class Void : public types::SimpleType {
 public:
  Void() = default;
  ~Void() = default;
  std::string GetIdentifier() override;
  void Accept(BaseVisitor *visitor) override;
};

}

#endif //COMPILERS_VOID_H
