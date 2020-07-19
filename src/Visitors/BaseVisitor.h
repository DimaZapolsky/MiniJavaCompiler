//
// Created by Dima Zapolsky on 13.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_VISITORS_BASEVISITOR_H_
#define NAIVEINTERPRETER_SRC_VISITORS_BASEVISITOR_H_

#include "Visitable.h"
#include "nodes/NodesInclude.h"

class Visitable;

class BaseVisitor {
 public:
  virtual void Visit(Visitable *visitable) = 0;
  virtual void Visit(ClassDeclaration* visitable) = 0;
  virtual void Visit(MethodDeclaration* visitable) = 0;
  virtual void Visit(VariableDeclaration* visitable) = 0;
  virtual void Visit(BinaryOperation* visitable) = 0;
  virtual void Visit(ComparisonGT* visitable) = 0;
  virtual void Visit(ComparisonLT* visitable) = 0;
  virtual void Visit(Dif* visitable) = 0;
  virtual void Visit(Div* visitable) = 0;
  virtual void Visit(Equal* visitable) = 0;
  virtual void Visit(LogicalAnd* visitable) = 0;
  virtual void Visit(LogicalOr* visitable) = 0;
  virtual void Visit(Mod* visitable) = 0;
  virtual void Visit(Mul* visitable) = 0;
  virtual void Visit(Sum* visitable) = 0;
  virtual void Visit(ArrayCreation* visitable) = 0;
  virtual void Visit(ArrayElementVal* visitable) = 0;
  virtual void Visit(Expr* visitable) = 0;
  virtual void Visit(False* visitable) = 0;
  virtual void Visit(IntegerLiteral* visitable) = 0;
  virtual void Visit(Length* visitable) = 0;
  virtual void Visit(MethodInvocationVal* visitable) = 0;
  virtual void Visit(Not* visitable) = 0;
  virtual void Visit(ObjectCreation* visitable) = 0;
  virtual void Visit(This* visitable) = 0;
  virtual void Visit(True* visitable) = 0;
  virtual void Visit(VariableVal* visitable) = 0;
  virtual void Visit(ClassDeclarationList* visitable) = 0;
  virtual void Visit(DeclarationList* visitable) = 0;
  virtual void Visit(ExprList* visitable) = 0;
  virtual void Visit(Formals* visitable) = 0;
  virtual void Visit(StatementList* visitable) = 0;
  virtual void Visit(ArrayElement* visitable) = 0;
  virtual void Visit(Lvalue* visitable) = 0;
  virtual void Visit(Variable* visitable) = 0;
  virtual void Visit(Assert* visitable) = 0;
  virtual void Visit(Assignment* visitable) = 0;
  virtual void Visit(Declaration* visitable) = 0;
  virtual void Visit(If* visitable) = 0;
  virtual void Visit(IfElse* visitable) = 0;
  virtual void Visit(LocalVariableDeclaration* visitable) = 0;
  virtual void Visit(MethodInvocation* visitable) = 0;
  virtual void Visit(Return* visitable) = 0;
  virtual void Visit(Sout* visitable) = 0;
  virtual void Visit(Statement* visitable) = 0;
  virtual void Visit(While* visitable) = 0;
  virtual void Visit(types::ArrayType* visitable) = 0;
  virtual void Visit(types::Boolean* visitable) = 0;
  virtual void Visit(types::Int* visitable) = 0;
  virtual void Visit(types::SimpleType* visitable) = 0;
  virtual void Visit(types::Type* visitable) = 0;
  virtual void Visit(types::TypeIdentifier* visitable) = 0;
  virtual void Visit(types::Void* visitable) = 0;
  virtual void Visit(Formal* visitable) = 0;
  virtual void Visit(Identifier* visitable) = 0;
  virtual void Visit(MainClass* visitable) = 0;
  virtual void Visit(Program* visitable) = 0;
};

#endif //NAIVEINTERPRETER_SRC_VISITORS_BASEVISITOR_H_
