//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_STATEMENT_H
#define COMPILERS_STATEMENT_H

#include "Visitors/Visitable.h"

class Statement : public Visitable {
 public:
  Statement() = default;
  ~Statement() = default;
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_STATEMENT_H
