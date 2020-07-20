//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Formals.h"

Formals::Formals() : formals_() {}

void Formals::AddFormal(Formal *formal) {
  formals_.push_back(formal);
}
const std::vector<Formal *> &Formals::GetFormals() const {
  return formals_;
}
void Formals::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
