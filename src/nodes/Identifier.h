//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_IDENTIFIER_H
#define COMPILERS_IDENTIFIER_H

#include <string>
#include "../Visitors/Visitable.h"

class Identifier : public Visitable {
 public:
  explicit Identifier(std::string s);
  ~Identifier() = default;
  std::string GetIdentifier();
  void Accept(BaseVisitor *visitor) override;
 private:
  std::string identifier_;
};

#endif //COMPILERS_IDENTIFIER_H
