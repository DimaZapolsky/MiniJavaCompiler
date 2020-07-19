//
// Created by Dima Zapolsky on 20/05/2020.
//

#include "MethodInvocationVal.h"

MethodInvocationVal::MethodInvocationVal(MethodInvocation *methodInvocation) :
    methodInvocation_(methodInvocation) {}

MethodInvocation *MethodInvocationVal::GetMethodInvocation() const {
  return methodInvocation_;
}
