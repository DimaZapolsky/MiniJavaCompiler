//
// Created by Dima Zapolsky on 20.07.2020.
//

#include "Statement.h"
void Statement::Accept(BaseVisitor *visitor) {
  visitor->Visit(this);
}
