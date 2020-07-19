//
// Created by Dima Zapolsky on 15.07.2020.
//

#include <iostream>
#include <cassert>

#include "Visitors/Visitable.h"
#include "Interpreter.h"

template<typename Base, typename T>
inline bool instanceof(const T*) {
  return std::is_base_of<Base, T>::value;
}

Interpreter::Interpreter() = default;

std::shared_ptr<objects::BaseObject> Interpreter::Accept(Visitable *visitable) {
  visitable->Accept(this);
  return tos_value_;
}

//void Interpreter::Visit(Visitable *visitable) {
//  std::cerr << "Interpreter in class visitable" << std::endl;
//  throw std::exception();
//}

void Interpreter::Visit(ClassDeclaration *visitable) {
  throw std::runtime_error("Interpreter::Visit(ClassDeclaration) is not implemented");
}

void Interpreter::Visit(MethodDeclaration *visitable) {
  throw std::runtime_error("Interpreter::Visit(MethodDeclaration) is not implemented");
}

void Interpreter::Visit(VariableDeclaration *visitable) {
  auto type = visitable->GetType();
  if (instanceof<types::SimpleType>(type)) {
    if (instanceof<types::Int>(type)) {
      variables_[visitable->GetIdentifier()->GetIdentifier()] = std::make_shared<objects::Int>();
    } else if (instanceof<types::Boolean>(type)) {
      variables_[visitable->GetIdentifier()->GetIdentifier()] = std::make_shared<objects::Boolean>();
    } else {
      throw std::runtime_error("Unknown type in Interpreter::Visit(VariableDeclaration)");
    }
  } else if (instanceof<types::ArrayType>(type)) {
    auto primitive_type = dynamic_cast<types::ArrayType*>(type)->GetSimpleType();
    if (!primitive_type) {
      throw std::runtime_error("Bad pointer after dynamic cast in Interpreter::Visit(VariableDeclaration");
    }
    if (instanceof<types::Int>(primitive_type)) {
      variables_[visitable->GetIdentifier()->GetIdentifier()] = std::make_shared<objects::IntArray>();
    } else if (instanceof<types::Boolean>(primitive_type)) {
      variables_[visitable->GetIdentifier()->GetIdentifier()] = std::make_shared<objects::BooleanArray>();
    } else {
      throw std::runtime_error("Bad pointer after dynamic cast in Interpreter::Visit(VariableDeclaration");;
    }
  } else {
    throw std::runtime_error("Bad pointer after dynamic cast in Interpreter::Visit(VariableDeclaration");;
  }
}

void Interpreter::Visit(BinaryOperation *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(BinaryOperation)");
}

void Interpreter::Visit(ComparisonGT *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(Accept(visitable->GetLExpr())->GetBooleanValue() > Accept(visitable->GetRExpr())->GetBooleanValue());
}

void Interpreter::Visit(ComparisonLT *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(Accept(visitable->GetLExpr())->GetBooleanValue() < Accept(visitable->GetRExpr())->GetBooleanValue());
}

void Interpreter::Visit(Dif *visitable) {
  tos_value_ = std::make_shared<objects::Int>(Accept(visitable->GetLExpr())->GetIntValue() - Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(Div *visitable) {
  tos_value_ = std::make_shared<objects::Int>(Accept(visitable->GetLExpr())->GetIntValue() / Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(Equal *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(Accept(visitable->GetLExpr())->GetIntValue() == Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(LogicalAnd *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(Accept(visitable->GetLExpr())->GetBooleanValue() && Accept(visitable->GetRExpr())->GetBooleanValue());
}

void Interpreter::Visit(LogicalOr *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(Accept(visitable->GetLExpr())->GetBooleanValue() || Accept(visitable->GetRExpr())->GetBooleanValue());
}

void Interpreter::Visit(Mod *visitable) {
  tos_value_ = std::make_shared<objects::Int>(Accept(visitable->GetLExpr())->GetIntValue() % Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(Mul *visitable) {
  tos_value_ = std::make_shared<objects::Int>(Accept(visitable->GetLExpr())->GetIntValue() * Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(Sum *visitable) {
  tos_value_ = std::make_shared<objects::Int>(Accept(visitable->GetLExpr())->GetIntValue() + Accept(visitable->GetRExpr())->GetIntValue());
}

void Interpreter::Visit(ArrayCreation *visitable) {
  auto type = visitable->GetSimpleType();
  if (instanceof<types::Int>(type)) {
    tos_value_ = std::make_shared<objects::IntArray>(std::vector<int>(Accept(visitable->GetExpr())->GetIntValue()));
  } else if (instanceof<types::Boolean>(type)) {
    tos_value_ = std::make_shared<objects::BooleanArray>(std::vector<bool>(Accept(visitable->GetExpr())->GetIntValue()));
  } else {
    throw std::runtime_error("Unknown type in array creation");
  }
}

void Interpreter::Visit(ArrayElementVal *visitable) {
  auto array = Accept(visitable->GetExpr());
  auto index = Accept(visitable->GetIndex())->GetIntValue();
  if (array->GetType() == Types::IntArray) {
    tos_value_ = std::make_shared<objects::Int>(array->GetIntArray()[index]);
  } else if (array->GetType() == Types::BooleanArray) {
    tos_value_ = std::make_shared<objects::Boolean>(array->GetBooleanArray()[index]);
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
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Expr)");
}

void Interpreter::Visit(Not *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(!Accept(visitable->GetExpr())->GetBooleanValue());
}

void Interpreter::Visit(ObjectCreation *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Expr)");
}

void Interpreter::Visit(This *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(This)");
}

void Interpreter::Visit(True *visitable) {
  tos_value_ = std::make_shared<objects::Boolean>(true);
}

void Interpreter::Visit(VariableVal *visitable) {
  tos_value_ = variables_[visitable->GetIdentifier()->GetIdentifier()];
}

void Interpreter::Visit(ClassDeclarationList *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(ClassDeclarationList)");
}

void Interpreter::Visit(DeclarationList *visitable) {
  for (auto& decl : visitable->GetDeclarations()) {
    decl->Accept(this);
  }
}

void Interpreter::Visit(ExprList *visitable) {
  for (auto& expr : visitable->GetExpressions()) {
    expr->Accept(this);
  }
}

void Interpreter::Visit(Formals *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Formals)");
}

void Interpreter::Visit(StatementList *visitable) {
  for (auto& statement : visitable->GetStatements()) {
    statement->Accept(this);
  }
}

void Interpreter::Visit(ArrayElement *visitable) {
  auto var = variables_[visitable->GetIdentifier()->GetIdentifier()];
  auto index = Accept(visitable->GetExpr())->GetIntValue();
  if (var->GetType() == Types::IntArray) {
    tos_value_ = std::make_shared<objects::Int>(var->GetIntArray()[index]);
  } else if (var->GetType() == Types::BooleanArray) {
    tos_value_ = std::make_shared<objects::Boolean>(var->GetBooleanArray()[index]);
  } else {
    throw std::runtime_error("Unknown type in Interpreter::Visit(ArrayElement)");
  }
}

void Interpreter::Visit(Lvalue *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Lvalue)");
}

void Interpreter::Visit(Variable *visitable) {
  tos_value_ = variables_[visitable->GetIdentifier()->GetIdentifier()];
}

void Interpreter::Visit(Assert *visitable) {
  assert(Accept(visitable->GetExpr())->GetBooleanValue());
}

void Interpreter::Visit(Assignment *visitable) {
  auto lvalue = Accept(visitable->GetLvalue());
  auto expr = Accept(visitable->GetExpr());
  if (lvalue->GetType() != expr->GetType()) {
    throw std::runtime_error("Types are in incompatible");
  } else {
    auto type = lvalue->GetType();
    if (type == Types::Int) {
      lvalue->GetIntValue() = expr->GetIntValue();
    } else if (type == Types::Boolean) {
      lvalue->GetBooleanValue() = expr->GetBooleanValue();
    } else if (type == Types::IntArray) {
      lvalue->GetIntArray() = expr->GetIntArray();
    } else if (type == Types::BooleanArray) {
      lvalue->GetBooleanArray() = expr->GetBooleanArray();
    } else {
      throw std::runtime_error("Unknown type in Interpreter::Visit(Assignment)");
    }
  }
}

void Interpreter::Visit(Declaration *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Declaration)");
}

void Interpreter::Visit(If *visitable) {
  auto expr = Accept(visitable->GetExpr());
  if (expr->GetBooleanValue()) {
    visitable->GetStatement()->Accept(this);
  }
}

void Interpreter::Visit(IfElse *visitable) {
  auto expr = Accept(visitable->GetExpr());
  if (expr->GetBooleanValue()) {
    visitable->GetStatementTrue()->Accept(this);
  } else {
    visitable->GetStatementFalse()->Accept(this);
  }
}

void Interpreter::Visit(LocalVariableDeclaration *visitable) {
  visitable->GetVariableDeclaration()->Accept(this);
}

void Interpreter::Visit(MethodInvocation *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(MethodInvocation)");
}

void Interpreter::Visit(Return *visitable) {

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
    auto expr = Accept(visitable->GetExpr());
    if (!expr->GetBooleanValue()) {
      break;
    }
    visitable->GetStatement()->Accept(this);
  }
}

void Interpreter::Visit(Formal *visitable) {
  throw std::runtime_error("There is no implementation for Interpreter::Visit(Formal)");
}

void Interpreter::Visit(MainClass *visitable) {
  visitable->GetStatementList()->Accept(this);
}

void Interpreter::Visit(Program *visitable) {
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
