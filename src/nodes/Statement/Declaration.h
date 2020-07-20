//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_DECLARATION_H
#define COMPILERS_DECLARATION_H

#include "Statement.h"

class Declaration : public Statement {
 public:
  Declaration() = default;
  ~Declaration() = default;
  void Accept(BaseVisitor *visitor) override;
};

#endif //COMPILERS_DECLARATION_H
