//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_INT_H
#define COMPILERS_INT_H

#include "SimpleType.h"

namespace types {

class Int : public SimpleType {
 public:
  Int() = default;
  ~Int() = default;
  std::string GetIdentifier() override;
  void Accept(BaseVisitor *visitor) override;
};

}

#endif //COMPILERS_INT_H
