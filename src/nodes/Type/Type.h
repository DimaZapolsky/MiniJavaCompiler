//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_TYPE_H
#define COMPILERS_TYPE_H

#include <string>
#include "Visitors/Visitable.h"

namespace types {

class Type : public Visitable {
 public:
  Type() = default;
  ~Type() = default;
  virtual std::string GetIdentifier() = 0;
  void Accept(BaseVisitor *visitor) override;
};

}

#endif //COMPILERS_TYPE_H
