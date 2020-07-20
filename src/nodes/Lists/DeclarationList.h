//
// Created by Dima Zapolsky on 19/05/2020.
//

#ifndef COMPILERS_DECLARATIONLIST_H
#define COMPILERS_DECLARATIONLIST_H

#include "nodes/Statement/Declaration.h"
#include <vector>

class DeclarationList : public Declaration {
 public:
  DeclarationList();
  ~DeclarationList() = default;
  void AddDeclaration(Declaration *declaration);
  const std::vector<Declaration *> &GetDeclarations() const;
  void Accept(BaseVisitor *visitor) override;
 private:
  std::vector<Declaration *> declarations_;
};

#endif //COMPILERS_DECLARATIONLIST_H
