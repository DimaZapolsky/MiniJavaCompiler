//
// Created by Dima Zapolsky on 20/05/2020.
//

#include "ArrayElement.h"

ArrayElement::ArrayElement(Identifier *identifier, Expr *expr) :
    identifier_(identifier), expr_(expr) {}
Identifier *ArrayElement::GetIdentifier() const {
  return identifier_;
}
Expr *ArrayElement::GetExpr() const {
  return expr_;
}