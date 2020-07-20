//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_BOOLEAN_H
#define COMPILERS_BOOLEAN_H

#include "SimpleType.h"

namespace types {

class Boolean : public SimpleType {
 public:
  Boolean() = default;
  ~Boolean() = default;
  std::string GetIdentifier() override;
  void Accept(BaseVisitor *visitor) override;
};

}

#endif //COMPILERS_BOOLEAN_H
