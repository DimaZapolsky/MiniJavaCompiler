//
// Created by Dima Zapolsky on 31.08.2020.
//

#include "ScopeBuilderVisitor.h"

#include <iostream>
#include <cassert>

#include "Visitors/Visitable.h"

template<typename Base, typename T>
inline bool instanceof(T *obj) {
    auto ptr = dynamic_cast<Base *>(obj);
    return ptr != nullptr;
}

ScopeBuilderVisitor::ScopeBuilderVisitor() {
    current_layer_ = std::make_shared<ScopeLayer>(nullptr);
    root_ = current_layer_;
}

std::pair<std::unordered_map<std::string, std::string>,
          std::unordered_map<std::string, std::shared_ptr<objects::Method>>> ScopeBuilderVisitor::AcceptDecl(DeclarationList* visitable)
{
  visitable->Accept(this);
  return tos_decl_;
}

void ScopeBuilderVisitor::BeginScope() {
  auto new_scope = std::make_shared<ScopeLayer>(current_layer_);
  current_layer_->AddChild(new_scope);
  current_layer_ = new_scope;
}

void ScopeBuilderVisitor::EndScope() {
  current_layer_ = current_layer_->GetParent();
}

std::shared_ptr<ScopeLayer> ScopeBuilderVisitor::GetRoot() {
  return root_;
}
std::unordered_map<std::string, std::shared_ptr<objects::Class>> ScopeBuilderVisitor::GetClasses() {
  return classes_;
}

std::shared_ptr<objects::BaseObject> ScopeBuilderVisitor::Accept(Visitable *visitable) {
  visitable->Accept(this);
  return tos_value_;
}

void ScopeBuilderVisitor::Visit(Visitable *visitable) {
    std::cerr << "ScopeBuilderVisitor in class visitable" << std::endl;
    throw std::exception();
}

void ScopeBuilderVisitor::Visit(ClassDeclaration *visitable) {
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

void ScopeBuilderVisitor::Visit(MethodDeclaration *visitable) {
    tos_value_ = std::make_shared<objects::Method>(visitable->GetIdentifier(), visitable->GetType(), visitable->GetFormals(), visitable->GetStatementList());
}

void ScopeBuilderVisitor::Visit(VariableDeclaration *visitable) {
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
        throw std::runtime_error("Unknown type in ScopeBuilderVisitor::Visit(VariableDeclaration)");
    }
}

void ScopeBuilderVisitor::Visit(BinaryOperation *visitable) {
    throw std::runtime_error("There is no implementation for ScopeBuilderVisitor::Visit(BinaryOperation)");
}

void ScopeBuilderVisitor::Visit(ComparisonGT *visitable) {
  if (Accept(visitable->GetLExpr())->GetTypeIdentifier() != "int" || Accept(visitable->GetRExpr())->GetTypeIdentifier() != "int") {
    std::cerr << "Non int value in comparison" << std::endl;
    throw std::exception();
  }
  tos_value_ = std::make_shared<objects::Uninitialized>("boolean");
}

void ScopeBuilderVisitor::Visit(ComparisonLT *visitable) {
  if (Accept(visitable->GetLExpr())->GetTypeIdentifier() != "int" || Accept(visitable->GetRExpr())->GetTypeIdentifier() != "int") {
    std::cerr << "Non int value in comparison" << std::endl;
    throw std::exception();
  }
  tos_value_ = std::make_shared<objects::Uninitialized>("boolean");
}

void ScopeBuilderVisitor::Visit(Dif *visitable) {
  if (Accept(visitable->GetLExpr())->GetTypeIdentifier() != "int" || Accept(visitable->GetRExpr())->GetTypeIdentifier() != "int") {
    std::cerr << "Non int value in arithmetic operation" << std::endl;
    throw std::exception();
  }
  tos_value_ = std::make_shared<objects::Uninitialized>("int");
}

void ScopeBuilderVisitor::Visit(Div *visitable) {
  if (Accept(visitable->GetLExpr())->GetTypeIdentifier() != "int" || Accept(visitable->GetRExpr())->GetTypeIdentifier() != "int") {
    std::cerr << "Non int value in arithmetic operation" << std::endl;
    throw std::exception();
  }
  tos_value_ = std::make_shared<objects::Uninitialized>("int");
}

void ScopeBuilderVisitor::Visit(Equal *visitable) {
  if (Accept(visitable->GetLExpr())->GetTypeIdentifier() != "int" || Accept(visitable->GetRExpr())->GetTypeIdentifier() != "int") {
    std::cerr << "Non int value in comparison" << std::endl;
    throw std::exception();
  }
  tos_value_ = std::make_shared<objects::Uninitialized>("boolean");
}

void ScopeBuilderVisitor::Visit(LogicalAnd *visitable) {
  if (Accept(visitable->GetLExpr())->GetTypeIdentifier() != "boolean" || Accept(visitable->GetRExpr())->GetTypeIdentifier() != "boolean") {
    std::cerr << "Non boolean value in logical operation" << std::endl;
    throw std::exception();
  }
  tos_value_ = std::make_shared<objects::Uninitialized>("boolean");
}

void ScopeBuilderVisitor::Visit(LogicalOr *visitable) {
  if (Accept(visitable->GetLExpr())->GetTypeIdentifier() != "boolean" || Accept(visitable->GetRExpr())->GetTypeIdentifier() != "boolean") {
    std::cerr << "Non boolean value in logical operation" << std::endl;
    throw std::exception();
  }
  tos_value_ = std::make_shared<objects::Uninitialized>("boolean");
}

void ScopeBuilderVisitor::Visit(Mod *visitable) {
  if (Accept(visitable->GetLExpr())->GetTypeIdentifier() != "int" || Accept(visitable->GetRExpr())->GetTypeIdentifier() != "int") {
    std::cerr << "Non int value in arithmetic operation" << std::endl;
    throw std::exception();
  }
  tos_value_ = std::make_shared<objects::Uninitialized>("int");
}

void ScopeBuilderVisitor::Visit(Mul *visitable) {
  if (Accept(visitable->GetLExpr())->GetTypeIdentifier() != "int" || Accept(visitable->GetRExpr())->GetTypeIdentifier() != "int") {
    std::cerr << "Non int value in arithmetic operation" << std::endl;
    throw std::exception();
  }
  tos_value_ = std::make_shared<objects::Uninitialized>("int");
}

void ScopeBuilderVisitor::Visit(Sum *visitable) {
  if (Accept(visitable->GetLExpr())->GetTypeIdentifier() != "int" || Accept(visitable->GetRExpr())->GetTypeIdentifier() != "int") {
    std::cerr << "Non int value in arithmetic operation" << std::endl;
    throw std::exception();
  }
  tos_value_ = std::make_shared<objects::Uninitialized>("int");
}

void ScopeBuilderVisitor::Visit(ArrayCreation *visitable) {
  auto type = visitable->GetSimpleType();
  if (Accept(visitable->GetExpr())->GetTypeIdentifier() != "int") {
    throw std::runtime_error("Enexpected type in array size");
  }
  if (instanceof<types::Int>(type)) {
    tos_value_ = std::make_shared<objects::Uninitialized>("int_array");
  } else if (instanceof<types::Boolean>(type)) {
    tos_value_ = std::make_shared<objects::Uninitialized>("boolean_array");
  } else {
    throw std::runtime_error("Unknown type in array creation");
  }
}

void ScopeBuilderVisitor::Visit(ArrayElementVal *visitable) {
    auto array = Accept(visitable->GetExpr());
    if (Accept(visitable->GetIndex())->GetTypeIdentifier() != "int") {
      throw std::runtime_error("Unexpected type in array index");
    }
    if (array->GetTypeIdentifier() == "int_array") {
        tos_value_ = std::make_shared<objects::Uninitialized>("int");
    } else if (array->GetTypeIdentifier() == "boolean_array") {
        tos_value_ = std::make_shared<objects::Uninitialized>("boolean");
    } else {
        throw std::runtime_error("Unknown type in array element value");
    }
}

void ScopeBuilderVisitor::Visit(Expr *visitable) {
    throw std::runtime_error("There is no implementation for ScopeBuilderVisitor::Visit(Expr)");
}

void ScopeBuilderVisitor::Visit(False *visitable) {
    tos_value_ = std::make_shared<objects::Boolean>(false);
}

void ScopeBuilderVisitor::Visit(IntegerLiteral *visitable) {
    tos_value_ = std::make_shared<objects::Int>(visitable->GetValue());
}

void ScopeBuilderVisitor::Visit(Length *visitable) {
    auto array = Accept(visitable->GetExpr());
    if (array->GetTypeIdentifier() == "int_array" || array->GetTypeIdentifier() == "boolean_array") {
        tos_value_ = std::make_shared<objects::Uninitialized>("int");
    } else {
        throw std::runtime_error("Unknown type in Length node");
    }
}

void ScopeBuilderVisitor::Visit(MethodInvocationVal *visitable) {
    visitable->GetMethodInvocation()->Accept(this);
}

void ScopeBuilderVisitor::Visit(Not *visitable) {
  if (Accept(visitable->GetExpr())->GetTypeIdentifier() != "boolean") {
    throw std::runtime_error("unexpected type int Not node");
  }
    tos_value_ = std::make_shared<objects::Uninitialized>("boolean");
}

void ScopeBuilderVisitor::Visit(ObjectCreation *visitable) {
    if (!classes_.count(visitable->GetTypeIdentifier()->GetIdentifier())) {
        throw std::runtime_error("Class " + visitable->GetTypeIdentifier()->GetIdentifier() + " is not declared");
    }
    tos_value_ = std::make_shared<objects::Uninitialized>(visitable->GetTypeIdentifier()->GetIdentifier());
}

void ScopeBuilderVisitor::Visit(This *visitable) {
    throw std::runtime_error("There is no implementation for ScopeBuilderVisitor::Visit(This)");
}

void ScopeBuilderVisitor::Visit(True *visitable) {
    tos_value_ = std::make_shared<objects::Boolean>(true);
}

void ScopeBuilderVisitor::Visit(VariableVal *visitable) {
    tos_value_ = current_layer_->GetVariable(visitable->GetIdentifier());
}

void ScopeBuilderVisitor::Visit(ClassDeclarationList *visitable) {
    for (auto decl : visitable->GetClassDeclarations()) {
        auto class_ = Accept(decl);
    }
}

void ScopeBuilderVisitor::Visit(DeclarationList *visitable) {
    std::unordered_map<std::string, std::string> vars_;
    std::unordered_map<std::string, std::shared_ptr<objects::Method>> methods_;
    for (auto &decl : visitable->GetDeclarations()) {
        auto declared = Accept(decl);
        if (instanceof<objects::Variable>(declared.get())) {
            vars_[dynamic_cast<objects::Variable*>(declared.get())->GetIdentifier()->GetIdentifier()] = declared->GetTypeIdentifier();
        } else {
            auto method_decl = std::dynamic_pointer_cast<objects::Method>(declared);
            methods_[method_decl->GetIdentifier()->GetIdentifier()] = method_decl;
        }
    }
    tos_decl_ = std::make_pair(vars_, methods_);
}

void ScopeBuilderVisitor::Visit(ExprList *visitable) {
    for (auto &expr : visitable->GetExpressions()) {
        formals_.push_back(Accept(expr));
    }
}

void ScopeBuilderVisitor::Visit(Formals *visitable) {
    throw std::runtime_error("There is no implementation for ScopeBuilderVisitor::Visit(Formals)");
}

void ScopeBuilderVisitor::Visit(StatementList *visitable) {
    BeginScope();
    for (auto &statement : visitable->GetStatements()) {
        statement->Accept(this);
        tos_value_ = nullptr;
    }
    EndScope();
}

void ScopeBuilderVisitor::Visit(ArrayElement *visitable) {
    auto var = current_layer_->GetVariable(visitable->GetIdentifier());
    if (Accept(visitable->GetExpr())->GetTypeIdentifier() != "int") {
      throw std::runtime_error("Unexpected type in array index");
    }
    if (var->GetTypeIdentifier() == "int_array") {
        tos_value_ = std::make_shared<objects::Uninitialized>("int");
    } else if (var->GetTypeIdentifier() == "boolean_array") {
      tos_value_ = std::make_shared<objects::Uninitialized>("boolean");
    } else {
        throw std::runtime_error("Unknown type in ScopeBuilderVisitor::Visit(ArrayElement)");
    }
}

void ScopeBuilderVisitor::Visit(Lvalue *visitable) {
    throw std::runtime_error("There is no implementation for ScopeBuilderVisitor::Visit(Lvalue)");
}

void ScopeBuilderVisitor::Visit(Variable *visitable) {
    tos_value_ = current_layer_->GetVariable(visitable->GetIdentifier());
}

void ScopeBuilderVisitor::Visit(Assert *visitable) {
  if (Accept(visitable->GetExpr())->GetTypeIdentifier() != "boolean") {
    throw std::runtime_error("unexpected type in assert statement");
  }
}

void ScopeBuilderVisitor::Visit(Assignment *visitable) {
    auto lvalue = Accept(visitable->GetLvalue());
    auto expr = Accept(visitable->GetExpr());
    if (lvalue->GetTypeIdentifier() != expr->GetTypeIdentifier()) {
        throw std::runtime_error("Types are in incompatible");
    }
}

void ScopeBuilderVisitor::Visit(Declaration *visitable) {
    throw std::runtime_error("There is no implementation for ScopeBuilderVisitor::Visit(Declaration)");
}

void ScopeBuilderVisitor::Visit(If *visitable) {
    if (Accept(visitable->GetExpr())->GetTypeIdentifier() != "boolean") {
      throw std::runtime_error("unexpected type in if expression");
    }

    BeginScope();
    visitable->GetStatement()->Accept(this);
    EndScope();
}

void ScopeBuilderVisitor::Visit(IfElse *visitable) {
  if (Accept(visitable->GetExpr())->GetTypeIdentifier() != "boolean") {
    throw std::runtime_error("unexpected type in if expression");
  }

  BeginScope();
  visitable->GetStatementTrue()->Accept(this);
  EndScope();
  BeginScope();
  visitable->GetStatementFalse()->Accept(this);
  EndScope();
}

void ScopeBuilderVisitor::Visit(LocalVariableDeclaration *visitable) {

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
        throw std::runtime_error("Unknown type in ScopeBuilderVisitor::Visit(VariableDeclaration)");
    }
}

void ScopeBuilderVisitor::Visit(MethodInvocation *visitable) {
    tos_value_ = nullptr;
    auto class_obj = Accept(visitable->GetExpr());
    if (!classes_.count(class_obj->GetTypeIdentifier())) {
        throw std::runtime_error("Can't call method on not class object");
    }
    visitable->GetExprList()->Accept(this);
    auto class_ = classes_[class_obj->GetTypeIdentifier()];
    auto method = class_->GetMethod(visitable->GetIdentifier()->GetIdentifier());
    const auto& formals = method->GetFormals()->GetFormals();
    if (formals.size() != formals_.size()) {
        throw std::runtime_error("Wrong number of arguments");
    }
    for (int i = 0; i < formals_.size(); ++i) {
        if (formals_[i]->GetTypeIdentifier() != formals[i]->GetType()->GetIdentifier()) {
            throw std::runtime_error("formals type mismatch");
        }
    }
    last_class_.push_back(class_);
    BeginScope();
    for (int i = 0; i < formals.size(); ++i) {
        current_layer_->DeclareVar(formals[i]->GetIdentifier(), formals[i]->GetType()->GetIdentifier());
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

void ScopeBuilderVisitor::Visit(Return *visitable) {
    tos_value_ = Accept(visitable->GetExpr());
}

void ScopeBuilderVisitor::Visit(Sout *visitable) {
    if (Accept(visitable->GetExpr())->GetTypeIdentifier() != "int") {
      throw std::runtime_error("Unexpected type in sout statement");
    }
}

void ScopeBuilderVisitor::Visit(Statement *visitable) {
    throw std::runtime_error("There is no implementation for ScopeBuilderVisitor::Visit(Statement)");
}

void ScopeBuilderVisitor::Visit(While *visitable) {
  if (Accept(visitable->GetExpr())->GetTypeIdentifier() != "boolean") {
    throw std::runtime_error("Unexpected type in while condition");
  }
  BeginScope();
  visitable->GetStatement()->Accept(this);
  EndScope();
}

void ScopeBuilderVisitor::Visit(Formal *visitable) {
    throw std::runtime_error("There is no implementation for ScopeBuilderVisitor::Visit(Formal)");
}

void ScopeBuilderVisitor::Visit(MainClass *visitable) {
    visitable->GetStatementList()->Accept(this);
}

void ScopeBuilderVisitor::Visit(Program *visitable) {
    visitable->GetClassDeclarationList()->Accept(this);

    visitable->GetMainClass()->Accept(this);
}

void ScopeBuilderVisitor::Visit(types::ArrayType *visitable) {

}
void ScopeBuilderVisitor::Visit(types::Boolean *visitable) {

}
void ScopeBuilderVisitor::Visit(types::Int *visitable) {

}
void ScopeBuilderVisitor::Visit(types::SimpleType *visitable) {

}
void ScopeBuilderVisitor::Visit(types::Type *visitable) {

}
void ScopeBuilderVisitor::Visit(types::TypeIdentifier *visitable) {

}
void ScopeBuilderVisitor::Visit(types::Void *visitable) {

}
void ScopeBuilderVisitor::Visit(Identifier *visitable) {

}