//
// Created by Dima Zapolsky on 15.07.2020.
//

#ifndef NAIVEINTERPRETER_SRC_VISITORS_INTERPRETER_H_
#define NAIVEINTERPRETER_SRC_VISITORS_INTERPRETER_H_

#include <map>

#include "nodes/NodesInclude.h"
#include "BaseVisitor.h"
#include "Objects/ObjectsInclude.h"
#include "Scopes/ScopeLayer.h"

class Interpreter : public BaseVisitor {
 public:
  Interpreter();
  ~Interpreter() = default;

  void Visit(Visitable *visitable) override;
  void Visit(ClassDeclaration *visitable) override;
  void Visit(MethodDeclaration *visitable) override;
  void Visit(VariableDeclaration *visitable) override;
  void Visit(BinaryOperation *visitable) override;
  void Visit(ComparisonGT *visitable) override;
  void Visit(ComparisonLT *visitable) override;
  void Visit(Dif *visitable) override;
  void Visit(Div *visitable) override;
  void Visit(Equal *visitable) override;
  void Visit(LogicalAnd *visitable) override;
  void Visit(LogicalOr *visitable) override;
  void Visit(Mod *visitable) override;
  void Visit(Mul *visitable) override;
  void Visit(Sum *visitable) override;
  void Visit(ArrayCreation *visitable) override;
  void Visit(ArrayElementVal *visitable) override;
  void Visit(Expr *visitable) override;
  void Visit(False *visitable) override;
  void Visit(IntegerLiteral *visitable) override;
  void Visit(Length *visitable) override;
  void Visit(MethodInvocationVal *visitable) override;
  void Visit(Not *visitable) override;
  void Visit(ObjectCreation *visitable) override;
  void Visit(This *visitable) override;
  void Visit(True *visitable) override;
  void Visit(VariableVal *visitable) override;
  void Visit(ClassDeclarationList *visitable) override;
  void Visit(DeclarationList *visitable) override;
  void Visit(ExprList *visitable) override;
  void Visit(Formals *visitable) override;
  void Visit(StatementList *visitable) override;
  void Visit(ArrayElement *visitable) override;
  void Visit(Lvalue *visitable) override;
  void Visit(Variable *visitable) override;
  void Visit(Assert *visitable) override;
  void Visit(Assignment *visitable) override;
  void Visit(Declaration *visitable) override;
  void Visit(If *visitable) override;
  void Visit(IfElse *visitable) override;
  void Visit(LocalVariableDeclaration *visitable) override;
  void Visit(MethodInvocation *visitable) override;
  void Visit(Return *visitable) override;
  void Visit(Sout *visitable) override;
  void Visit(Statement *visitable) override;
  void Visit(While *visitable) override;
  void Visit(Formal *visitable) override;
  void Visit(MainClass *visitable) override;
  void Visit(Program *visitable) override;
  void Visit(types::ArrayType *visitable) override;
  void Visit(types::Boolean *visitable) override;
  void Visit(types::Int *visitable) override;
  void Visit(types::SimpleType *visitable) override;
  void Visit(types::Type *visitable) override;
  void Visit(types::TypeIdentifier *visitable) override;
  void Visit(types::Void *visitable) override;
  void Visit(Identifier *visitable) override;

  std::shared_ptr<objects::BaseObject> Accept(Visitable *visitable);
  std::shared_ptr<objects::BaseObject>* AcceptPtr(Visitable *visitable);
  std::pair<std::unordered_map<std::string, std::string>,
            std::unordered_map<std::string, std::shared_ptr<objects::Method>>> AcceptDecl(DeclarationList* visitable);

 private:
  std::shared_ptr<objects::BaseObject> tos_value_{nullptr};
  std::shared_ptr<objects::BaseObject>* tos_value_ptr{nullptr};
  std::shared_ptr<ScopeLayer> current_layer_{nullptr};
  std::unordered_map<std::string, std::shared_ptr<objects::Class>> classes_;
  std::pair<std::unordered_map<std::string, std::string>, std::unordered_map<std::string, std::shared_ptr<objects::Method>>> tos_decl_{{}, {}};
  std::vector<std::shared_ptr<objects::BaseObject>> formals_;
  std::vector<std::shared_ptr<objects::ClassObj>> last_class_;

  void BeginScope();
  void EndScope();
};

#endif //NAIVEINTERPRETER_SRC_VISITORS_INTERPRETER_H_
