//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "Declaration.h"
void Declaration::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
