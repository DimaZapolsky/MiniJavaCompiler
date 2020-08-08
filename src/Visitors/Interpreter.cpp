//
// Created by Dima Zapolsky on 15.07.2020.
//

#include <iostream>
#include <cassert>

#include "Visitors/Visitable.h"
#include "Interpreter.h"

template<typename Base, typename T>
inline bool instanceof(T *obj) {
//  return std::is_base_of<Base, T>::value;
//  return std::is_convertible<Base, T>::value;
  auto ptr = dynamic_cast<Base *>(obj);
  return ptr != nullptr;
}

Interpreter::Interpreter() {
  current_layer_ = std::make_shared<ScopeLayer>(nullptr);
}

//Interpreter::~Interpreter() = default;

void Interpreter::BeginScope() {
  auto new_scope = std::make_shared<ScopeLayer>(current_layer_);
  current_layer_ = new_scope;
}

void Interpreter::EndScope() {
  current_layer_ = current_layer_->GetParent();
}

std::shared_ptr<objects::BaseObject> Interpreter::Accept(Visitable *visitable) {
  visitable->Accept(this);
  return tos_value_;
}

std::shared_ptr<objects::BaseObject>* Interpreter::AcceptPtr(Visitable *visitable) {
  visitable->Accept(this);
  return tos_value_ptr;
}

void Interpreter::Visit(Visitable *visitable) {
  std::cerr << "Interpreter in class visitable" << std::endl;
  throw std::exception();
}

void Interpreter::Visit(ClassDeclaration *visitable) {
  auto class_ = std::make_shared<objects::Class>();
  class_->SetIdentifier(visitable->GetIdentifier());
  auto extends = visitable->GetExtends();
  if (extends) {
    if (!classes_.count(extends->GetIdentifier())) {
      throw std::runtime_error("Parent class(" + extends->GetIdentifier() + ") is not declared");
    }
    class_->SetExtends(classes_[extends->GetIdentifier()]);
  }
  auto [variables_, methods_] = AcceptDecl(visitable->GetDeclarationList());
  class_->SetVariables(variables_);
  class_->SetMethods(methods_);
  classes_[class_->GetIdentifier()->GetIdentifier()] = class_;
}

void Interpreter::Visit(MethodDeclaration *visitable) {
  tos_value_ = std::make_shared<objects::Method>(visitable->GetIdentifier(), visitable->GetType(), visitable->GetFormals(), visitable->GetStatementList());
}

void Interpreter::Visit(VariableDeclaration *visitable) {
  auto type = visitable->GetType();
  if (instanceof<types::SimpleType>(type) || instanceof<types::ArrayType>(type)) {
    tos_value_ = std::make_shared<objects::Variable>(visitable->GetIdentifier(), type);
  } else if (instanceof<types::TypeIdentifier>(type)) {
    auto identifier = dynamic_cast<types::TypeIdentifier *>(type);
    if (!identifier || !classes_.count(identifier->GetIdentifier())) {
      throw std::runtime_error("There is no such type");
    }
    tos_value_ = std::make_shared<objects::Variable>(visitable->GetIdentifier(), type);
  } else {
    throw std::runtime_error("Unknown type in Interpreter::Visit(VariableDeclaration)");
  }
}

void Interpreter::Visit(BinaryOperation *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(BinaryOperation)");
}

void Interpreter::Visit(ComparisonGT *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(
      Accept(visitable->GetLExpr())->GetBooleanValue() > Accept(visitable->GetRExpr())->GetBooleanValue());
}

void Interpreter::Visit(ComparisonLT *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(
      Accept(visitable->GetLExpr())->GetBooleanValue() < Accept(visitable->GetRExpr())->GetBooleanValue());
}

void Interpreter::Visit(Dif *visitable) {
  tos_value_ = std::make_shared<objects::Int>(
      Accept(visitable->GetLExpr())->GetIntValue() - Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(Div *visitable) {
  tos_value_ = std::make_shared<objects::Int>(
      Accept(visitable->GetLExpr())->GetIntValue() / Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(Equal *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(
      Accept(visitable->GetLExpr())->GetIntValue() == Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(LogicalAnd *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(
      Accept(visitable->GetLExpr())->GetBooleanValue() && Accept(visitable->GetRExpr())->GetBooleanValue());
}

void Interpreter::Visit(LogicalOr *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(
      Accept(visitable->GetLExpr())->GetBooleanValue() || Accept(visitable->GetRExpr())->GetBooleanValue());
}

void Interpreter::Visit(Mod *visitable) {
  tos_value_ = std::make_shared<objects::Int>(
      Accept(visitable->GetLExpr())->GetIntValue() % Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(Mul *visitable) {
  tos_value_ = std::make_shared<objects::Int>(
      Accept(visitable->GetLExpr())->GetIntValue() * Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(Sum *visitable) {
  tos_value_ = std::make_shared<objects::Int>(
      Accept(visitable->GetLExpr())->GetIntValue() + Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(ArrayCreation *visitable) {
  auto type = visitable->GetSimpleType();
  if (instanceof<types::Int>(type)) {
    tos_value_ = std::make_shared<objects::IntArray>(Accept(visitable->GetExpr())->GetIntValue());
  } else if (instanceof<types::Boolean>(type)) {
    tos_value_ =
        std::make_shared<objects::BooleanArray>(Accept(visitable->GetExpr())->GetIntValue());
  } else {
    throw std::runtime_error("Unknown type in array creation");
  }
}

void Interpreter::Visit(ArrayElementVal *visitable) {
  auto array = Accept(visitable->GetExpr());
  auto index = Accept(visitable->GetIndex())->GetIntValue();
  if (array->GetType() == Types::IntArray) {
    tos_value_ = std::make_shared<objects::Int>(array->GetIntArray()[index]->GetIntValue());
  } else if (array->GetType() == Types::BooleanArray) {
    tos_value_ = std::make_shared<objects::Boolean>(array->GetBooleanArray()[index]->GetBooleanValue());
  } else {
    throw std::runtime_error("Unknown type in array element value");
  }
}

void Interpreter::Visit(Expr *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Expr)");
}

void Interpreter::Visit(False *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(false);
}

void Interpreter::Visit(IntegerLiteral *visitable) {
  tos_value_ = std::make_shared<objects::Int>(visitable->GetValue());
}

void Interpreter::Visit(Length *visitable) {
  auto array = Accept(visitable->GetExpr());
  if (array->GetType() == Types::IntArray) {
    tos_value_ = std::make_shared<objects::Int>(array->GetIntArray().size());
  } else if (array->GetType() == Types::BooleanArray) {
    tos_value_ = std::make_shared<objects::Int>(array->GetBooleanArray().size());
  } else {
    throw std::runtime_error("Unknown type in Length node");
  }
}

void Interpreter::Visit(MethodInvocationVal *visitable) {
  visitable->GetMethodInvocation()->Accept(this);
}

void Interpreter::Visit(Not *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(!Accept(visitable->GetExpr())->GetBooleanValue());
}

void Interpreter::Visit(ObjectCreation *visitable) {
  if (!classes_.count(visitable->GetTypeIdentifier()->GetIdentifier())) {
    throw std::runtime_error("Class " + visitable->GetTypeIdentifier()->GetIdentifier() + " is not declared");
  }
  tos_value_ = std::make_shared<objects::ClassObj>(classes_[visitable->GetTypeIdentifier()->GetIdentifier()]);
  return;
}

void Interpreter::Visit(This *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(This)");
}

void Interpreter::Visit(True *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(true);
}

void Interpreter::Visit(VariableVal *visitable) {
  tos_value_ = current_layer_->GetVariable(visitable->GetIdentifier());
  if (tos_value_->GetType() == Null) {
    throw std::runtime_error("Variable is not initialized");
  }
}

void Interpreter::Visit(ClassDeclarationList *visitable) {
  for (auto decl : visitable->GetClassDeclarations()) {
    auto class_ = Accept(decl);
//    classes_[decl->GetIdentifier()->GetIdentifier()] = std::shared_ptr<objects::Class>(dynamic_cast<objects::Class*>(class_.get()));
  }
}

void Interpreter::Visit(DeclarationList *visitable) {
  std::unordered_map<std::string, std::string> vars_;
  std::unordered_map<std::string, std::shared_ptr<objects::Method>> methods_;
  for (auto &decl : visitable->GetDeclarations()) {
    auto declared = Accept(decl);
    if (instanceof<objects::Variable>(declared.get())) {
      vars_[dynamic_cast<objects::Variable*>(declared.get())->GetIdentifier()->GetIdentifier()] = declared->GetTypeIdentifier();
    } else {
//      auto method_decl = std::shared_ptr<objects::Method>(dynamic_cast<objects::Method*>(declared.get()));
      auto method_decl = std::dynamic_pointer_cast<objects::Method>(declared);
      methods_[method_decl->GetIdentifier()->GetIdentifier()] = method_decl;
    }
  }
  tos_decl_ = std::make_pair(vars_, methods_);
}

void Interpreter::Visit(ExprList *visitable) {
  for (auto &expr : visitable->GetExpressions()) {
    formals_.push_back(Accept(expr));
  }
}

void Interpreter::Visit(Formals *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Formals)");
}

void Interpreter::Visit(StatementList *visitable) {
  BeginScope();
  for (auto &statement : visitable->GetStatements()) {
    statement->Accept(this);
    tos_value_ = nullptr;
  }
  EndScope();
}

void Interpreter::Visit(ArrayElement *visitable) {
  auto var = current_layer_->GetVariable(visitable->GetIdentifier());
  auto index = Accept(visitable->GetExpr())->GetIntValue();
  if (var->GetType() == Types::IntArray) {
    tos_value_ptr = &var->GetIntArray()[index];
  } else if (var->GetType() == Types::BooleanArray) {
    tos_value_ptr = &var->GetBooleanArray()[index];
  } else {
    throw std::runtime_error("Unknown type in Interpreter::Visit(ArrayElement)");
  }
}

void Interpreter::Visit(Lvalue *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Lvalue)");
}

void Interpreter::Visit(Variable *visitable) {
  tos_value_ptr = current_layer_->GetVariablePtr(visitable->GetIdentifier());
}

void Interpreter::Visit(Assert *visitable) {
  assert(Accept(visitable->GetExpr())->GetBooleanValue());
}

void Interpreter::Visit(Assignment *visitable) {
  auto lvalue = AcceptPtr(visitable->GetLvalue());
  auto expr = Accept(visitable->GetExpr());
  std::string name1 = (*lvalue)->GetTypeIdentifier();
  std::string name2 = expr->GetTypeIdentifier();
  if ((*lvalue)->GetTypeIdentifier() != expr->GetTypeIdentifier()) {
    throw std::runtime_error("Types are in incompatible");
  } else {

    *lvalue = expr;

  }
}

void Interpreter::Visit(Declaration *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Declaration)");
}

void Interpreter::Visit(If *visitable) {
  auto expr = Accept(visitable->GetExpr());
  if (expr->GetBooleanValue()) {
    BeginScope();
    visitable->GetStatement()->Accept(this);
    EndScope();
  }
}

void Interpreter::Visit(IfElse *visitable) {
  auto expr = Accept(visitable->GetExpr());
  BeginScope();
  if (expr->GetBooleanValue()) {
    visitable->GetStatementTrue()->Accept(this);
  } else {
    visitable->GetStatementFalse()->Accept(this);
  }
  EndScope();
}

void Interpreter::Visit(LocalVariableDeclaration *visitable) {

  auto decl = visitable->GetVariableDeclaration();
  auto type = decl->GetType();
  if (instanceof<types::SimpleType>(type) || instanceof<types::ArrayType>(type)) {
    current_layer_->DeclareVar(decl->GetIdentifier(), type->GetIdentifier());
  } else if (instanceof<types::TypeIdentifier>(type)) {
    auto identifier = dynamic_cast<types::TypeIdentifier *>(type);
    if (!identifier || !classes_.count(identifier->GetIdentifier())) {
      throw std::runtime_error("There is no such type");
    }
    current_layer_->DeclareVar(decl->GetIdentifier(), type->GetIdentifier());
  } else {
    throw std::runtime_error("Unknown type in Interpreter::Visit(VariableDeclaration)");
  }
}

void Interpreter::Visit(MethodInvocation *visitable) {
  tos_value_ = nullptr;
//  auto class_obj =
//      std::shared_ptr<objects::ClassObj>(dynamic_cast<objects::ClassObj *>(Accept(visitable->GetExpr()).get()));
  auto class_obj = std::dynamic_pointer_cast<objects::ClassObj>(Accept(visitable->GetExpr()));
  if (!class_obj) {
    throw std::runtime_error("Can't call method on not class object");
  }
  visitable->GetExprList()->Accept(this);
  auto method = class_obj->GetMethod(visitable->GetIdentifier());
  const auto& formals = method->GetFormals()->GetFormals();
  std::cout << formals.size() << std::endl;
  if (formals.size() != formals_.size()) {
    throw std::runtime_error("Wrong number of arguments");
  }
  for (int i = 0; i < formals_.size(); ++i) {
    if (formals_[i]->GetTypeIdentifier() != formals[i]->GetType()->GetIdentifier()) {
      throw std::runtime_error("formals type mismatch");
    }
  }
  last_class_.push_back(class_obj);
  BeginScope();
  for (int i = 0; i < formals.size(); ++i) {
    current_layer_->DeclareVar(formals[i]->GetIdentifier(), formals[i]->GetType()->GetIdentifier());
    current_layer_->PutVar(formals[i]->GetIdentifier(), formals_[i]);
  }
  method->GetStatementList()->Accept(this);
  EndScope();
  last_class_.pop_back();

  auto return_type = method->GetReturnType();
  if (instanceof<types::Void>(return_type) && tos_value_ == nullptr) {
    return;
  }
  if (return_type->GetIdentifier() != tos_value_->GetTypeIdentifier()) {
    throw std::runtime_error("Function return type mismatch");
  }
}

void Interpreter::Visit(Return *visitable) {
  tos_value_ = Accept(visitable->GetExpr());
}

void Interpreter::Visit(Sout *visitable) {
  auto expr = Accept(visitable->GetExpr());
  std::cout << expr->GetIntValue() << std::endl;
}

void Interpreter::Visit(Statement *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Statement)");
}

void Interpreter::Visit(While *visitable) {
  while (true) {
    BeginScope();
    auto expr = Accept(visitable->GetExpr());
    if (!expr->GetBooleanValue()) {
      break;
    }
    visitable->GetStatement()->Accept(this);
    EndScope();
  }
}

void Interpreter::Visit(Formal *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Formal)");
}

void Interpreter::Visit(MainClass *visitable) {
  visitable->GetStatementList()->Accept(this);
}

void Interpreter::Visit(Program *visitable) {
  visitable->GetClassDeclarationList()->Accept(this);

  visitable->GetMainClass()->Accept(this);
}

void Interpreter::Visit(types::ArrayType *visitable) {

}
void Interpreter::Visit(types::Boolean *visitable) {

}
void Interpreter::Visit(types::Int *visitable) {

}
void Interpreter::Visit(types::SimpleType *visitable) {

}
void Interpreter::Visit(types::Type *visitable) {

}
void Interpreter::Visit(types::TypeIdentifier *visitable) {

}
void Interpreter::Visit(types::Void *visitable) {

}
void Interpreter::Visit(Identifier *visitable) {

}
std::pair<std::unordered_map<std::string, std::string>,
          std::unordered_map<std::string, std::shared_ptr<objects::Method>>> Interpreter::AcceptDecl(DeclarationList *visitable) {
  visitable->Accept(this);
  return tos_decl_;
}
