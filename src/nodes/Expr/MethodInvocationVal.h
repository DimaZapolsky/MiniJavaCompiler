//
// Created by Dima Zapolsky on 20/05/2020.
//

#ifndef COMPILERS_METHODINVOCATIONVAL_H
#define COMPILERS_METHODINVOCATIONVAL_H

#include "nodes/Expr/Expr.h"
#include "nodes/Statement/MethodInvocation.h"

class MethodInvocationVal : public Expr {
 public:
  explicit MethodInvocationVal(MethodInvocation *methodInvocation);
  ~MethodInvocationVal() = default;
  MethodInvocation *GetMethodInvocation() const;
  void Accept(BaseVisitor *visitor) override;
 private:
  MethodInvocation *methodInvocation_;
};

#endif //COMPILERS_METHODINVOCATIONVAL_H
