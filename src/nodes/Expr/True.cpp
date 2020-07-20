//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "True.h"
void True::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
