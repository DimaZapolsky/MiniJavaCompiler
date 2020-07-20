//
// Created by Dima Zapolsky on 19/05/2020.
//

#include "This.h"
void This::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
