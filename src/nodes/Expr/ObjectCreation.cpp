//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "ObjectCreation.h"

ObjectCreation::ObjectCreation(types::TypeIdentifier *typeIdentifier) :
    typeIdentifier_(typeIdentifier) {}

types::TypeIdentifier *ObjectCreation::GetTypeIdentifier() const {
  return typeIdentifier_;
}
void ObjectCreation::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
