//
// Created by Dima Zapolsky on 13.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_VISITORS_VISITABLE_H_
#define NAIVEINTERPRETER_SRC_VISITORS_VISITABLE_H_

class BaseVisitor;

class Visitable {
 public:
  Visitable() = default;
  void Accept(BaseVisitor* visitor);
};

#endif //NAIVEINTERPRETER_SRC_VISITORS_VISITABLE_H_
