//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "DeclarationList.h"

DeclarationList::DeclarationList() : declarations_() {}

void DeclarationList::AddDeclaration(Declaration *declaration) {
  declarations_.push_back(declaration);
}

const std::vector<Declaration *> &DeclarationList::GetDeclarations() const {
  return declarations_;
}
void DeclarationList::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
