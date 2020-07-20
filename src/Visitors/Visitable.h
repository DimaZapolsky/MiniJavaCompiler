//
// Created by Dima Zapolsky on 13.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_VISITORS_VISITABLE_H_
#define NAIVEINTERPRETER_SRC_VISITORS_VISITABLE_H_

#include "BaseVisitor.h"

class BaseVisitor;

class Visitable {
 public:
  virtual void Accept(BaseVisitor *visitor) = 0;
};

#endif //NAIVEINTERPRETER_SRC_VISITORS_VISITABLE_H_
