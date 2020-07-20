//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_SIMPLETYPE_H
#define COMPILERS_SIMPLETYPE_H

#include "Type.h"

namespace types {
class SimpleType : public Type {
 public:
  SimpleType() = default;
  ~SimpleType() = default;
  std::string GetIdentifier() override = 0;
  void Accept(BaseVisitor *visitor) override;
};
}

#endif //COMPILERS_SIMPLETYPE_H
